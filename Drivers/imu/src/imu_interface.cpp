#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
//#include "sensor_msgs/Imu.h"
//#include "geometry_msgs/Quaternion.h"
//#include "geometry_msgs/Vector3.h"
#include <stdio.h>
#include <unistd.h>
#include "../include/vNavIMU/vectornav.h"
#include "../include/vNavIMU/vNavIMU.h"
#include <custom_msg/IMUData.h>

using namespace std;
#include <iostream>

//#include <sstream>
//
//For ease of integration this node publishes to the same topics as the old compass driver
//
const char* const COM_PORT = "//dev//serial//by-id//usb-FTDI_USB-RS232_Cable_FTUBIHSO-if00-port0";
const int BAUD_RATE = 115200;
float heading, pitch, roll;		/*Floats for the returned values*/

//double round_nplaces(double value, int to)
//{
//    double places = pow(10.0, to);
//    return round(value * places) / places;
//}
//
int main(int argc, char **argv)
{
	
	Vn100 vn100; //custom handle for vn100 from provided vectornav library - SHOULD CHECK THESE OUT	
	VnYpr ypr; 
	VnVector3 angularRate;
	VnVector3 acceleration;
	
	int connect = 0; 
	ros::init(argc, argv, "imu_interface"); //init the driver 
	ros::NodeHandle imu; //create a handle for the node - this does the init and cleans up the node on destruction

	/*Advertises our various messages - these are purely for backwards compatibility with control*/
	ros::Publisher imuMsg = imu.advertise<custom_msg::IMUData>("imu", 100);

	/*Sets up the message structures*/
	custom_msg::IMUData imuData;

	//init the vectornav IMU
	connect = vn100_connect(&vn100, COM_PORT, BAUD_RATE);
	printf("connect returned = %d\n", connect);
	if(connect != 0){ //vn100 Functions return 0 if everything is ok
		vnError(connect);
		return 0; //Connection failed in some way, abort
	}

	ROS_INFO("vNavIMU - Driver Online");
	
	ros::Rate loop_rate(50); //50 Hz

	while (ros::ok())
	{

		ros::Time imu_time = ros::Time::now();
		
		//vn100_getYawPitchRollTrueBodyAccelerationAngularRate
		vn100_getYawPitchRollTrueInertialAcclerationAngularRate(&vn100, &ypr, &acceleration, &angularRate);		
		
		imuData.yaw = ypr.yaw;	
		imuData.pitch = ypr.pitch;
		imuData.roll = ypr.roll;
		imuData.acc_x = acceleration.c0;
		imuData.acc_y = acceleration.c1;
		imuData.acc_z = acceleration.c2;
		imuData.vel_x = angularRate.c0;
		imuData.vel_y = angularRate.c1;
		imuData.vel_z = angularRate.c2;
		
		imuMsg.publish(imuData);
		
		ros::spinOnce();

		loop_rate.sleep();
	}

	ROS_INFO("vNavIMU - Shutting Down");
	vn100_disconnect(&vn100);
	return 0;
}

int vnError(int con)
{
	if (con == 1){
			ROS_ERROR("vNavIMU - Unknown Error");
		}
		else if (con == 2){
			ROS_ERROR("vNavIMU - Not Implemented");
		}
		else if (con == 3){
			ROS_ERROR("vNavIMU - Timeout");
		}
		else if (con == 4){
			ROS_ERROR("vNavIMU - Invalid Value");
		}
		else if (con == 5){
			ROS_ERROR("vNavIMU - File Not Found");
		}
		else if (con == 6){
			ROS_ERROR("vNavIMU - Not Connected");
		}
		else {
			ROS_ERROR("vNavIMU - An attempt to connect returned the unknown error code - %d", con);
		}
		return 0;	//we failed to open the port so end
}
