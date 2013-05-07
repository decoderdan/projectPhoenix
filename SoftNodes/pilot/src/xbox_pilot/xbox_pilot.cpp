#include <stdio.h>
#include "ros/ros.h"
#include <custom_msg/MotorConfig.h>
#include <sensor_msgs/Joy.h>

void joyCallback(const sensor_msgs::Joy::ConstPtr&);

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
		distance = (distance <= 0.12 ? 0 : distance); //Bit of a dead zone
		
		//Forward
		motorCfg.front = 0;
		motorCfg.back = 0;
		motorCfg.front_right = 0;
		motorCfg.back_right = 0;
		motorCfg.front_left = 0;
		motorCfg.back_left = 0;
		
		motorMsg.publish(motorCfg);
}
