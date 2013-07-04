#include <stdio.h>
#include <sys/time.h> //For timeout
#include <ctime>      //For timeout
#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

#define killer_timeout 240		// timeout in seconds 

float global_depth;

void depthCallback(const std_msgs::Float32& depth);

int main(int argc, char **argv) {

	ros::init(argc, argv, "the_killer");	

	ros::NodeHandle n;
	ros::Publisher svs_depth_msg = n.advertise<std_msgs::Float32>("depth", 100); 

	std_msgs::Float32 svs_depth;

	bool already_dived = false;
	ros::Time dive_time;

	ros::Rate r(1);

	while (ros::ok()) {

		if (global_depth > 3.0) {			// if under too far
			ROS_ERROR("ERROR: SUB BELOW 3 METERS!, killing pid.launch");
			system("killall python /opt/ros/electric/ros/bin/roslaunch launch pid.launch");

		} else if (global_depth > 0.5) {	// if not under surface
			if (!already_dived) {			// if not already 'dived'
				// set the dive time
				dive_time = ros::Time::now();
				already_dived = true;
			} 

			if(ros::Time::now().toSec() < (dive_time.toSec() + killer_timeout)) { 
			// if timeout && no depth callback recieved
				ROS_ERROR("ERROR: HAS BEEN DOWN MORE THAN %d, killing pid.launch", killer_timeout);
				system("killall python /opt/ros/electric/ros/bin/roslaunch launch pid.launch");
			}

		} else if (already_dived) {
			already_dived = false;
		}
	}
}

void depthCallBack(const std_msgs::Float32& depth) {
	std_msgs::Float32 z;

	global_depth = z.data;
}