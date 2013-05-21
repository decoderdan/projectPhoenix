#include <stdio.h>
#include <iostream>
#include "ros/ros.h"
#include <std_msgs/Float32.h>
#include <custom_msg/IMUData.h>
#include <custom_msg/MotorConfig.h>
#include <custom_msg/TargetVector.h>
#include <custom_msg/PIDValues.h>

float constrain(float x, float min, float max);
float map(float, float, float, float, float);

ros::Publisher motorMsg;
custom_msg::MotorConfig motorCfg;

static std_msgs::Float32 z;


float yaw_Kp = 1;
float yaw_Ki = 0;
float yaw_Kd = 0;
float yaw_input = 0;
float yaw_target = 0;
float yaw_error = 0;
float yaw_previous_error = 0;
float yaw_integral = 0;
float yaw_derivative = 0;

float pitch_Kp = 1;
float pitch_Ki = 0;
float pitch_Kd = 0;
float pitch_input = 0;
float pitch_target = 0;
float pitch_error = 0;
float pitch_previous_error = 0;
float pitch_integral = 0;
float pitch_derivative = 0;

float depth_Kp = 1;
float depth_Ki = 0;
float depth_Kd = 0;
float depth_input = 0;
float depth_target = 0;
float depth_error = 0;
float depth_previous_error = 0;
float depth_integral = 0;
float depth_derivative = 0;
/******************************************************
 * 
 *  callbacks; 
 * 
 * ***************************************************/

void depthCallBack(const std_msgs::Float32& depth) {
	z.data = -(depth.data-10.0);
	depth_input = z.data;
}

void imuCallBack(const custom_msg::IMUData& data) {
	yaw_input = data.yaw;
	pitch_input = data.pitch;
}

void pidGuiCallBack(const custom_msg::PIDValues& data) {
	yaw_Kp = data.yaw_Kp;
	yaw_Ki = data.yaw_Ki;
	yaw_Kd = data.yaw_Kd;
	pitch_Kp = data.pitch_Kp;
	pitch_Ki = data.pitch_Ki;
	pitch_Kd = data.pitch_Kd;
	depth_Kp = data.depth_Kp;
	depth_Ki = data.depth_Ki;
	depth_Kd = data.depth_Kd;

	std::cout << "PID values updated "  << std::endl;
	//std::cout << "yaw Kp set to = " << yaw_Kp  << std::endl;
	//std::cout << "yaw Ki set to = " << yaw_Ki  << std::endl;
	//std::cout << "yaw Kd set to = " << yaw_Kd  << std::endl;
	
	yaw_error = 0;
	yaw_previous_error = 0;
	yaw_integral = 0;
	yaw_derivative = 0;
	pitch_error = 0;
	pitch_previous_error = 0;
	pitch_integral = 0;
	pitch_derivative = 0;
	depth_error = 0;
	depth_previous_error = 0;
	depth_integral = 0;
	depth_derivative = 0;
}

void vectorCallBack(const custom_msg::TargetVector& data) {
	yaw_target = data.vector_yaw;
	pitch_target = data.vector_pitch;
	depth_target = data.vector_z;
	std::cout << "Target values updated "  << std::endl;
	//std::cout << "yaw target set to = " << yaw_target  << std::endl;
}
/******************************************************
 * 
 *  Main; the master of functions, the definer of variables.
 * 
 * ***************************************************/
int main( int argc, char **argv )
{
	ros::init(argc, argv, "pid_pilot");
	ros::NodeHandle n;

	/* Publisher for the motor configuration */
	motorMsg = n.advertise<custom_msg::MotorConfig>("motor_config", 100);
	ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
	ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);
	ros::Subscriber pidGuiSub = n.subscribe("pidGui", 100, pidGuiCallBack);
	ros::Subscriber vectorSub = n.subscribe("vector", 100, vectorCallBack);	
	
	ros::Rate r(50);

	
	float yaw_output = 0;
	float pitch_output = 0;
	float depth_output = 0;
	float dt = 0.02;

	while(ros::ok())
		{	
			ros::spinOnce(); //Call all waiting callbacks at this point
			/***********/
			/* yaw pid */
			/***********/
			yaw_error = yaw_target - yaw_input;
  			yaw_integral = yaw_integral + (yaw_error*dt);
  			yaw_derivative = (yaw_error - yaw_previous_error)/dt;
  			yaw_previous_error = yaw_error;
  			yaw_output = (yaw_Kp*yaw_error) + (yaw_Ki*yaw_integral) + (yaw_Kd*yaw_derivative);
			/***********/
			/* pitch pid */
			/***********/
			pitch_error = pitch_target - pitch_input;
  			pitch_integral = pitch_integral + (pitch_error*dt);
  			pitch_derivative = (pitch_error - pitch_previous_error)/dt;
  			pitch_previous_error = pitch_error;
  			pitch_output = (pitch_Kp*pitch_error) + (pitch_Ki*pitch_integral) + (pitch_Kd*pitch_derivative);
			/***********/
			/* depth pid */
			/***********/
			depth_error = depth_target - depth_input;
  			depth_integral = depth_integral + (depth_error*dt);
  			depth_derivative = (depth_error - depth_previous_error)/dt;
  			depth_previous_error = depth_error;
  			depth_output = (depth_Kp*depth_error) + (depth_Ki*depth_integral) + (depth_Kd*depth_derivative);
			
			//output to motors
			motorCfg.front_right = int(constrain(yaw_output, -100, 100));
			motorCfg.front_left = int(constrain(-yaw_output, -100, 100));
			motorCfg.back_right = int(constrain(-yaw_output, -100, 100));
			motorCfg.back_left = int(constrain(yaw_output, -100, 100));
			motorCfg.front = int(constrain((depth_output+pitch_output), -100, 100));
			motorCfg.back = int(constrain((depth_output-pitch_output), -100, 100));	
			motorMsg.publish(motorCfg);
			
			r.sleep(); //Sleep for a little while
		}

	//when ros no longer ok stop all motors
	motorCfg.front_right = 0;
	motorCfg.front_left = 0;
	motorCfg.back_right = 0;
	motorCfg.back_left = 0;
	motorCfg.front = 0;
	motorCfg.back = 0;	
	motorMsg.publish(motorCfg);

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



/* OLD MOTOR STUFF FOR REFRENCE
void joyCallback(const sensor_msgs::Joy::ConstPtr& joy) {

	// 0 = Left X Axis
	//	 1 = Left Y Axis
	
	
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
	motorCfg.front_right += (100 * joy->axes[3]);
	motorCfg.front_left += (-100 * joy->axes[3]);
	motorCfg.back_left += (100 * joy->axes[3]);
	motorCfg.back_right += (-100 * joy->axes[3]);

	motorCfg.front_right = constrain(motorCfg.front_right, -100, 100);
	motorCfg.front_left = constrain(motorCfg.front_left, -100, 100);
	motorCfg.back_right = constrain(motorCfg.back_right, -100, 100);
	motorCfg.back_left = constrain(motorCfg.back_left, -100, 100);

	//Leave out depth for now
	motorCfg.front = 0;
	motorCfg.back = 0;	

	motorMsg.publish(motorCfg);

}*/
