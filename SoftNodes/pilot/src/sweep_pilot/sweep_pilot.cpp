#include <stdio.h>
#include "ros/ros.h"
#include <custom_msg/MotorConfig.h>

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

	ros::Rate r(25); //10Hz message

	int whichdir = 0;

	while(ros::ok())
	{
		if (whichdir == 0) {
			motorCfg.front_right++;
			motorCfg.front_left++;
			motorCfg.back_left--;
			motorCfg.back_right--;
			if (motorCfg.front_right == 100) {
				whichdir = 1;
			}
		}
		else {
			motorCfg.front_right--;
			motorCfg.front_left--;
			motorCfg.back_left++;
			motorCfg.back_right++;
			if (motorCfg.front_right == -100) {
				whichdir = 0;
			}
		}
		//Leave out depth for now
		motorCfg.front = 0;
		motorCfg.back = 0;	

		motorMsg.publish(motorCfg);

		r.sleep();
	}
	return 0;
}
