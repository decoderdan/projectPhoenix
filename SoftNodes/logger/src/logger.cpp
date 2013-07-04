/**********************************************************************************
RULES:
The format of the log file will be a comma separated ASCII file of the format:
Time, position, action, a comment between simple quotes.
(SSSSS,XXX.x,YYY.y,ZZZ.z,AA.aa). 

Logged data will be plotted by plotting routine written by the organising committee. 
This will be used to score the log file. For the
acoustic modem task the additional file of AUV heading and light on/off data and cooperative AUV heading command will need to be provided. For the ASV tracking task
the additional file of range and bearing data from the AUV to the pinger will need to be
provided.

**********************************************************************************

SSSSS   = no of seconds
XXX.x   = Position - X - Odometry
YYY.y   = Position - Y - Odometry
ZZZ.z   = Depth - SVP
AA.aa   = Angle - IMU - YAW = ??
'quote' = Action - from mission state 

**********************************************************************************
TO DO:
continuously open/close logfile 
append to file, not overwrite.
format floats when writing to file and cout
time since rosstartup, instead of 'local' file time
x + y callback functions

clarify angle and action/comment 

**********************************************************************************/

#include <ros/ros.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <sstream>
#include <custom_msg/PIDValues.h>
#include <custom_msg/TargetVector.h>
#include <custom_msg/SonarConfig.h>
#include <custom_msg/IMUData.h>
//#include "std_msgs/Bool.h"

float x_input = 0.0;
float y_input = 0.0;
float depth_input = 0.0;
float yaw_input = 0.0;
char state_input[30] = "no state";

void depthCallBack(const std_msgs::Float32& depth);
void stateCallBack(const std_msgs::String::ConstPtr& state);
void imuCallBack(const custom_msg::IMUData& imu);

using namespace std;

int main(int argc, char **argv)
{
	//Get start time, to take off from current time
	time_t startTime; 
	startTime=time(NULL);

	ros::init(argc, argv, "logger");

	ros::NodeHandle n;
	//Set up subscriptions
	ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
   	ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);
  	ros::Subscriber stateSub = n.subscribe("state", 100, stateCallBack);

	char buff[20];
	time_t now = time(NULL);
	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
	//printf("%s\n", buff);

	ofstream logFile ("/home/phoenix/projectPhoenix/Logs/log.txt");

	ros::spinOnce();

	//Set loop rate (in Hz);
	ros::Rate r(10);
	while (ros::ok())
	{

		//Check for new data:
		ros::spinOnce();

		//Print log file for debugging: (SSSSS,XXX.x,YYY.y,ZZZ.z,AA.aa,'state'). 
		//printf("%ld,%f,%f,%f,%f,%s\n", time(NULL) - startTime, x_input, y_input, depth_input, yaw_input, state_input);
		std::cout << (time(NULL) - startTime) << "," << x_input << "," << y_input << "," << depth_input << "," 
				<< yaw_input << "," << "'" << state_input << "'" << std::endl;


		//Save log to file:
		if (logFile.is_open())
		{	
			logFile << (time(NULL) - startTime) << ",";
			logFile << x_input << ",";
			logFile << y_input << ",";
			logFile << depth_input << ",";
			logFile << yaw_input << ",";
			logFile << "'" << state_input << "'" << "\n";
		}
		else 
		{
			printf("Unable to open file, logging stopped :(.\n");	
		}

		r.sleep();

	}

	logFile.close();

}

void imuCallBack(const custom_msg::IMUData& imu)
{
	yaw_input = imu.yaw;   
	return;
}

void depthCallBack(const std_msgs::Float32& depth)
{
	ROS_INFO("got depth");
	depth_input = depth.data;
     
	return;
}

void stateCallBack(const std_msgs::String::ConstPtr& state)
{
	//strcpy(state_input, state.data);
	strcpy(state_input, (state->data.c_str()));
	return;
}
