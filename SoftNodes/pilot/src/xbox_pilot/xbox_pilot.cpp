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

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy) {



		/* Need to map it here... */
		/* 0 = Left X Axis
			 1 = Left Y Axis
		*/
		
		/* Convert x/y to angle and distance */
		float angle = atan2(-joy->axes[0],joy->axes[1]); //Switch X and Y to offset by 90 degrees
		angle = (angle >= 0 ? angle : (2*M_PI + angle)) * 360 / (2*M_PI); //From PI->0->-PI To degrees
		float distance = sqrt(pow(-joy->axes[0],2)+pow(joy->axes[1],2));
		distance = (distance >= 1 ? 1 : distance);
		distance = (distance < 0.12 ? 0 : distance); //Bit of a dead zone
		distance = map(distance, 0.12, 1, 0, 1); //Re-map
		distance = (distance < 0 ? 0 : distance);
		
		if ((angle >= 0) && (angle <= 45)) {
			//Forward to Right-Forward
			motorCfg.front_right = map(angle, 0, 45, -100, 0);
			motorCfg.back_right = 100;
			motorCfg.back_left = map(angle, 0, 45, 100, 0);
			motorCfg.front_left = -100;
		}
		else if (angle <= 90) {
			//Right-Forward to Strafe-Right
			motorCfg.front_right = map(angle, 45, 90, 0, 100);
			motorCfg.back_right = 100;
			motorCfg.back_left = map(angle, 45, 90, 0, -100);
			motorCfg.front_left = -100;
		}
		else if (angle <= 135) {
			//Strafe-Right to Backwards-Right
			motorCfg.front_right = 100;
			motorCfg.back_right = map(angle, 90, 135, 100, 0);
			motorCfg.back_left = -100;
			motorCfg.front_left = map(angle, 90, 135, -100, 0);
		}
		else if (angle <= 180) {
			//Backwards-Right to Backwards
			motorCfg.front_right = 100;
			motorCfg.back_right = map(angle, 135, 180, 0, -100);
			motorCfg.back_left = -100;
			motorCfg.front_left = map(angle, 135, 180, 0, 100);
		}
		else if (angle <= 225) {
			//Backwards to Backwards-Left
			motorCfg.front_right = map(angle, 180, 225, 100, 0);
			motorCfg.back_right = -100;
			motorCfg.back_left = map(angle, 180, 225, -100, 0);
			motorCfg.front_left = 100;
		}
		else if (angle <= 270) {
			//Backwards-Left to Strafe-Left
			motorCfg.front_right = map(angle, 225, 270, 0, -100);
			motorCfg.back_right = -100;
			motorCfg.back_left = map(angle, 225, 270, 0, 100);
			motorCfg.front_left = 100;
		}
		else if (angle <= 315) {
			//Strafe-Left to Forward-Left
			motorCfg.front_right = -100;
			motorCfg.back_right = map(angle, 270, 315, -100, 0);
			motorCfg.back_left = 100;
			motorCfg.front_left = map(angle, 270, 315, 100, 0);
		}
		else {
			//Forward-Left to Forward
			motorCfg.front_right = -100;
			motorCfg.back_right = map(angle, 315, 360, 0, 100);
			motorCfg.back_left = 100;
			motorCfg.front_left = map(angle, 315, 360, 0, -100);
		}
	
		//Multiply by distances for speed
		motorCfg.front_right*=distance;
		motorCfg.back_right*=distance;
		motorCfg.front_left*=distance;
		motorCfg.back_left*=distance;
	
		//Leave out depth for now
		motorCfg.front = 0;
		motorCfg.back = 0;	
		motorMsg.publish(motorCfg);
}
