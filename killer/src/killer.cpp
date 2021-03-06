#include <stdio.h>
#include <sys/time.h> //For timeout
#include <ctime>      //For timeout
#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

#define killer_timeout 300		// timeout in seconds 

float global_depth;

void depthCallBack(const std_msgs::Float32& depth);
//void joyCallback(const sensor_msgs::Joy::ConstPtr& joy) {

int main(int argc, char **argv) {

	ros::init(argc, argv, "the_killer");	

	ros::NodeHandle n;
	ros::Subscriber depthSub = n.subscribe("depth", 1, depthCallBack);

//	ros::Subscriber joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, joyCallback);

	std_msgs::Float32 svs_depth;

	bool already_dived = false;
	ros::Time dive_time;

	ros::Rate r(1);

	ROS_INFO("killer: starting the killer");

	while (ros::ok()) {

		ros::spinOnce(); //Call all waiting callbacks at this point

		if (global_depth > 3.0) {			// if under too far
			ROS_ERROR("killer: error: sub below 3 meters!, killing pid.launch");
			system("killall python /opt/ros/electric/ros/bin/roslaunch launch pid.launch");

		} else if (global_depth > 0.5) {	// if not under surface
			if (!already_dived) {			// if not already 'dived'
				// set the dive time
				ROS_INFO("killer: sub has dived - will kill in %d seconds if not surfaced", killer_timeout);
				dive_time = ros::Time::now();
				already_dived = true;
			} 

			if(ros::Time::now().toSec() > (dive_time.toSec() + killer_timeout) && already_dived == true) { 
			// if timeout && already dived
				ROS_ERROR("killer: error: has been down more than %d, killing pid.launch", killer_timeout);
				system("killall python /opt/ros/electric/ros/bin/roslaunch launch pid.launch");
			}

		} else if (already_dived) {
			already_dived = false;
			ROS_INFO("killer: sub has resurfaced");
		}
		r.sleep(); //Sleep for a little while
	}
}

void depthCallBack(const std_msgs::Float32& depth) {
	global_depth = depth.data;

	ROS_INFO("killer: got depth %f", depth.data);
}