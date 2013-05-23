#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "sensor_msgs/Imu.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"
#include <stdio.h>
#include <unistd.h>
#include "../include/IMU/vectornav.h"
#include "../include/IMU/vNavIMU.h"


using namespace std;
#include <iostream>

#define LOOP_RATE 50

//#include <sstream>
//
//For ease of integration this node publishes to the same topics as the old compass driver
//
const char* const COM_PORT = "//dev//ttyUSB0";
const int BAUD_RATE = 115200;
float heading, pitch, roll;	/*Floats for the returned values*/

//double round_nplaces(double value, int to)
//{
// double places = pow(10.0, to);
// return round(value * places) / places;
//}
//
int main(int argc, char **argv)
{

Vn100 vn100; //custom handle for vn100 from provided vectornav library - SHOULD CHECK THESE OUT
VnYpr ypr;
VnQuaternion quat; //quaternion struct handle
VnVector3 angularRate;
VnVector3 acceleration;
VnVector3 magnetic;
VnVector3 gyroscope;

VnVector3 mag;	//Raw Voltage from the Magnetometer
VnVector3 accel;	//Raw Voltage from the Accelerometer
VnVector3 gyro; //Raw Voltage from the Gyroscope
double temp;	//Raw voltage from the Temperature sensor
int connect = 0; //
ros::init(argc, argv, "IMU"); //init the driver
ros::NodeHandle imu; //create a handle for the node - this does the init and cleans up the node on destruction

//tf setup
//tf::TransformBroadcaster broadcaster;

/*Advertises our various messages - these are purely for backwards compatibility with control*/
ros::Publisher compassHeadingMsg = imu.advertise<std_msgs::Float32>("compassHeading", 100);
ros::Publisher compassPitchMsg = imu.advertise<std_msgs::Float32>("compassPitch", 100);
ros::Publisher compassRollMsg = imu.advertise<std_msgs::Float32>("compassRoll", 100);


  // Create a publisher and name the topic.
  ros::Publisher pub_message = n.advertise<node_example::node_example_data>(topic.c_str(), 10);

/*Sets up the message structures*/
std_msgs::Float32 compassHeading;
std_msgs::Float32 compassPitch;
std_msgs::Float32 compassRoll;

ros::Publisher IMU = imu.advertise<sensor_msgs::Imu>("IMU", 0);
sensor_msgs::Imu IMU;
//sensor messages require geometry messages
geometry_msgs::Quaternion rosQuat;
geometry_msgs::Vector3 rosVec_angVel;
geometry_msgs::Vector3 rosVec_linAccel;

//ros::Time imu_time = ros::Time::now();

ros::Rate loop_rate(LOOP_RATE);

//init the vectornav IMU
connect = vn100_connect(&vn100, COM_PORT, BAUD_RATE);
printf("connect returned = %d\n", connect);
if(connect != 0){ //vn100 Functions return 0 if everything is ok
vnError(connect);
return 0; //Connection failed in some way, abort
}


ROS_INFO("IMU - Driver Online");
  
while (ros::ok())
{

ros::Time imu_time = ros::Time::now();
//vn100_getYawPitchRollTrueBodyAccelerationAngularRate
vn100_getYawPitchRollTrueInertialAcclerationAngularRate(&vn100, &ypr, &acceleration, &angularRate);
//vn100_getYawPitchRoll(&vn100, &ypr); //vectornav function
//printf("YPR: %+#7.2f %+#7.2f %+#7.2f\n", ypr.yaw, ypr.pitch, ypr.roll);
//ROS_DEBUG("H: %+#7.2f P: %+#7.2f R: %+#7.2f",ypr.yaw, ypr.pitch, ypr.roll);
compassHeading.data = ypr.yaw;	
compassPitch.data = ypr.pitch;
compassRoll.data = ypr.roll;
compassHeadingMsg.publish(compassHeading);
compassRollMsg.publish(compassRoll);
compassPitchMsg.publish(compassPitch);


//Publish the IMU data as an IMU Message
//http://www.ros.org/doc/api/sensor_msgs/html/msg/Imu.html
IMU.header.frame_id = "/auv";

IMU.header.stamp = imu_time;

vn100_getQuaternion(&vn100 , &quat);


//vn100_getKalmanFilterStateVector(&vn100, &quat, &gyroscope);
rosQuat.x = quat.x;
rosQuat.y = quat.y;
rosQuat.z = quat.z;
rosQuat.w = quat.w;

IMU.orientation = rosQuat;

//printf("gyroscope - Vna: X:%+#7.2f Y:%+#7.2f Z:%+#7.2f\n", gyroscope.c0, gyroscope.c1, gyroscope.c2);
//vn100_getCalibratedImuMeasurements(&vn100, &magnetic, &acceleration, &angularRate, &temp); //try out new settings...




//vn100_getAcceleration(&vn100, &acceleration); //check these are right
rosVec_linAccel.x = acceleration.c0;
rosVec_linAccel.y = acceleration.c1;
rosVec_linAccel.z = acceleration.c2;

IMU.linear_acceleration = rosVec_linAccel;
//printf("Lin Acc - Vna: X:%+#7.2f Y:%+#7.2f Z:%+#7.2f\n", acceleration.c0, acceleration.c1, acceleration.c2);

//vn100_getAngularRate(&vn100, &angularRate);
rosVec_angVel.x = angularRate.c0;
rosVec_angVel.y = angularRate.c1;
rosVec_angVel.z = angularRate.c2;

IMU.angular_velocity = rosVec_angVel;
//printf("Angular Rate - Vna: X:%+#7.2f Y:%+#7.2f Z:%+#7.2f\n", angularRate.c0, angularRate.c1, angularRate.c2);



vNavMsg.publish(IMU);
//printf("Quaternion: X:%+#7.2f Y:%+#7.2f Z:%+#7.2f W:%+#7.2f\n\n", quat.x , quat.y , quat.z , quat.w);



//You can use this function to get the raw voltage of each sensor, the temperature typically returns +1.34 after warm up
//vn100_getRawVoltageMeasurements(&vn100, &mag, &accel, &gyro, &temp);
//printf("Temperature = %+#7.2f\n", temp);

ros::spinOnce();

loop_rate.sleep();


}

ROS_INFO("IMU - Shutting Down");
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
