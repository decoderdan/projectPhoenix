#include <stdio.h>
#include "ros/ros.h"
#include <custom_msg/MotorConfig.h>
#include <sensor_msgs/Joy.h>

void joyCallback(const sensor_msgs::Joy::ConstPtr&);
float map(float, float, float, float, float);

ros::Publisher motorMsg;
custom_msg::MotorConfig motorCfg;

/******************************************************
 * 
 *  Main; the master of functions, the definer of variables.
 * 
 * ***************************************************/
int main( int argc, char **argv )
{

	ros::init(argc, argv, "xbox_pilot");
	ros::NodeHandle n;

	/* Publisher for the motor configuration */
	motorMsg = n.advertise<custom_msg::MotorConfig>("motor_config", 100);
	
	/* Subscribe to joystick */
	ros::Subscriber joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, joyCallback);

	ros::spin();

	return 0;
}

float constrain(float x, float min, float max) {
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy) {

	/* 0 = Left X Axis
		 1 = Left Y Axis
	*/
	
	float rads = atan2(joy->axes[1], -joy->axes[0]); //X & Y to rads
	float distance = constrain(sqrt(pow(-joy->axes[0],2)+pow(joy->axes[1],2)),0,1); //Get distance
	distance = (distance < 0.12 ? 0 : distance); //Bit of a dead zone
	distance = constrain(map(distance, 0.12, 1, 0, 1), 0, 1); //Re-map so it's smooth from deadzone outwards

	//Direction Control	
	motorCfg.front_right = -(int8_t)(constrain(140 * cos(rads+M_PI/4), -100, 100) * distance);
	motorCfg.front_left = -(int8_t)(constrain(-140 * cos(M_PI/4-rads), -100, 100) * distance);
	motorCfg.back_left = -(int8_t)(constrain(-140 * cos(rads+M_PI/4), -100, 100) * distance);
	motorCfg.back_right = -(int8_t)(constrain(140 * cos(M_PI/4-rads), -100, 100) * distance);

	//Yaw control...
	motorCfg.front_right += (20 * joy->axes[3]);
	motorCfg.front_left += (-20 * joy->axes[3]);
	motorCfg.back_left += (20 * joy->axes[3]);
	motorCfg.back_right += (-20 * joy->axes[3]);

	motorCfg.front_right = constrain(motorCfg.front_right, -100, 100);
	motorCfg.front_left = constrain(motorCfg.front_left, -100, 100);
	motorCfg.back_right = constrain(motorCfg.back_right, -100, 100);
	motorCfg.back_left = constrain(motorCfg.back_left, -100, 100);

	//Leave out depth for now
	motorCfg.front = 0;
	motorCfg.back = 0;	

	motorMsg.publish(motorCfg);

}
