
 /** *********************************************** **/
 /** Name: pid_pilot.cpp                             **/
 /**                                                 **/
 /** Function: To recieve "TargetVector" values and  **/
 /**           convert them into motor values.       **/
 /**                                                 **/
 /** Author: Unknown, edited by James Killick        **/
 /**                                                 **/
 /** Last Date Modified: 02/12/2013                  **/
 /** *********************************************** **/

 #include <stdio.h>
 #include <iostream>
 #include "ros/ros.h"
 #include <std_msgs/Float32.h>
 #include <std_msgs/Bool.h>
 #include <custom_msg/IMUData.h>
 #include <custom_msg/MotorConfig.h>
 #include <custom_msg/TargetVector.h>
 #include <custom_msg/PIDValues.h>

 float constrain(float x, float min, float max); //To prevent the motor values from exceping 100%
 float map(float, float, float, float, float);   

 ros::Publisher motorMsg;	//global declaration of the publisher "motorMsg"
 custom_msg::MotorConfig motorCfg;

 static std_msgs::Float32 z; 

 float move_x = 0; 				//used to control the robot in the x and y directions
 float move_y = 0;
 bool input_stability = true; 	// bit to set input stability

 float yaw_rate = 45; 			//degrees per second
 float yaw_Kp = 0;				//3 variables for yaw PID
 float yaw_Ki = 0;
 float yaw_Kd = 0;
 float yaw_input = 0;			//values recieved from IMU
 float yaw_target_raw = 0;		
 float yaw_target = 0;			//desired yaw value
 float yaw_error = 0;			//difference between desired and actual values
 float yaw_previous_error = 0;
 float yaw_integral = 0;
 float yaw_derivative = 0;


 float pitch_rate = 3; 			//degrees per second
 float pitch_Kp = 0;			//3 variables for pitch PID
 float pitch_Ki = 0;
 float pitch_Kd = 0;
 float pitch_input = 0;			//values recieved from IMU
 float pitch_target_raw = 0;
 float pitch_target = 0;		//desired pitch value
 float pitch_error = 0;			//difference between desired and actual pitch value.
 float pitch_previous_error = 0;
 float pitch_integral = 0;
 float pitch_derivative = 0; 


 float depth_rate = 0.05; 		//m per second
 float depth_Kp = 0;			//3 variables for depth PID
 float depth_Ki = 0;
 float depth_Kd = 0;
 float depth_input = 0;			//depth value recieved from the SVP
 float depth_target_raw = 0;	
 float depth_target = 0;		//desired depth value
 float depth_error = 0;			//difference between desired and actual values.
 float depth_previous_error = 0;
 float depth_integral = 0;
 float depth_derivative = 0;

 bool emergency_stop;			//variable that stops program if an emergency message is recieved
 /** *********************************************** **/
 /** Name: emergencyCallBack                         **/
 /**                                                 **/
 /** Function: To recieve an emergency message and   **/
 /** change the value of emergency_stop if set.      **/
 /** *********************************************** **/

 void emergencyCallBack(const std_msgs::Bool& stop) 
  {
    if(stop.data == true)	//If the emergency message has been recieved
     { 
	   emergency_stop = true; 	// set a global flag for pid
	   ROS_INFO("emergency stop = true");
 	 } 
   
    else if (stop.data == false) //If the emergency message has been set to 0
     {
	   emergency_stop = false; 	// clear the flag
       ROS_INFO("emergency stop = false");
	 }	
	return;
  }


 /** *********************************************** **/
 /** Name: depthCallBack                             **/
 /**                                                 **/
 /** Function: To recieve depth data and set the     **/
 /** value of "depth_input" to this value.            **/
 /** *********************************************** **/

 void depthCallBack(const std_msgs::Float32& depth) 
  {
    depth_input = depth.data; //set the value of depth_input to the measured depth value 
  }


 /** *********************************************** **/
 /** Name: imuCallBack                               **/
 /**                                                 **/
 /** Function: To recieve yaw and pitch data and     **/
 /** set two variables to these values.              **/
 /** *********************************************** **/

 void imuCallBack(const custom_msg::IMUData& data) 
  {
	yaw_input = data.yaw;		//recieve the values for yaw and pitch and set variables to these values.
	pitch_input = data.pitch;
  }


 /** *********************************************** **/
 /** Name: pidGuiCallBack                            **/
 /**                                                 **/
 /** Function: To recieve PID values from the GUI.   **/
 /**                                                 **/
 /** *********************************************** **/

 void pidGuiCallBack(const custom_msg::PIDValues& data) 
  {
    yaw_Kp = data.yaw_Kp;	//recieves values for PID from the GUI and sets it to the values for yaw.
	yaw_Ki = data.yaw_Ki;
	yaw_Kd = data.yaw_Kd;
	
    pitch_Kp = data.pitch_Kp;  //recieves values for PID from the GUI and sets it to the values for pitch.
	pitch_Ki = data.pitch_Ki;
	pitch_Kd = data.pitch_Kd;
	
    depth_Kp = data.depth_Kp; //recieves values for PID from the GUI and sets it to the values for depth.
	depth_Ki = data.depth_Ki;
	depth_Kd = data.depth_Kd;

	std::cout << "PID values updated "  << std::endl;
	
	yaw_error = 0;	//variables for yaw PID calculation are reset.
	yaw_previous_error = 0;
	yaw_integral = 0;
	yaw_derivative = 0;

	pitch_error = 0;  //variables for pitch PID calculation are reset.
	pitch_previous_error = 0;
	pitch_integral = 0;
	pitch_derivative = 0;

	depth_error = 0;  //variables for depth PID calculation are reset.
	depth_previous_error = 0;
	depth_integral = 0;
	depth_derivative = 0;
  }


 /** *********************************************** **/
 /** Name: constrain                                 **/
 /**                                                 **/
 /** Function: To limit motor values to prevent      **/
 /** them from going over the maximum value.         **/
 /** *********************************************** **/

 float constrain(float x, float min, float max) 
  {
	if (x < min) return min;	//limits input to minimum value.
	if (x > max) return max;	//limits input to maximum value.
	return x;
  }


 /** *********************************************** **/
 /** Name: map                                       **/
 /**                                                 **/
 /** Function: Takes value X and known input range   **/
 /** and maps it to a known output range.            **/
 /** *********************************************** **/

 float map(float x, float in_min, float in_max, float out_min, float out_max)
  {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }


 /** *********************************************** **/
 /** Name: vectorCallBack                            **/
 /**                                                 **/
 /** Function: To recieve yaw, pitch and depth data  **/
 /** when the valut of the target vector changes.    **/
 /** *********************************************** **/

 void vectorCallBack(const custom_msg::TargetVector& data) 
  {
    if (data.set_yaw == true) {yaw_target_raw = data.vector_yaw;std::cout << "Yaw target updated "  << std::endl;}	//if the yaw has changed, read in the new value.
	if (data.set_pitch == true) {pitch_target_raw = data.vector_pitch;std::cout << "Pitch target updated "  << std::endl;}	////if the pitch has changed, read in the new value.
	if (data.set_z == true) {depth_target_raw = data.vector_z;std::cout << "Depth target updated "  << std::endl;} //if the depth has changed, read in the new value.
	if (data.set_x == true) {move_x = data.vector_x;} //if x axis (strafe) has been changed, read this value.
	if (data.set_y == true) {move_y = data.vector_y;} //if Y axis has been changed, read this value.
  }


 /** *********************************************** **/
 /** Name: main                                      **/
 /**                                                 **/
 /** Function: Runs the main logic for the code to   **/
 /** convert the vector values into motor values.    **/
 /** *********************************************** **/

 int main( int argc, char **argv )
  {
    ros::init(argc, argv, "pid_pilot");
	ros::NodeHandle n;

	motorMsg = n.advertise<custom_msg::MotorConfig>("motor_config", 100); 	// Publisher for the motor configuration. 

	ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack); 			//subscriber for the IMU.
	ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);	//subscriber for the depth.
	ros::Subscriber pidGuiSub = n.subscribe("pidGui", 100, pidGuiCallBack);	//subscriber for the GUI.
	ros::Subscriber vectorSub = n.subscribe("vector", 100, vectorCallBack);	//subscriber for the target vectors.
    ros::Subscriber emergencySub = n.subscribe("emergency", 100, emergencyCallBack); //subscriber for the emergency message.
	
	ros::Rate r(50);

	float yaw_output = 0; //initialise values for yaw, pitch, depth.
	float pitch_output = 0;
	float depth_output = 0;
	float dt = 0.02;

	while(ros::ok())
	 {	
   	   ros::spinOnce();  //Call all waiting callbacks at this point
			
	   if(emergency_stop == false) //if the emergency message has not been recieved.
        {

		  if(input_stability == true) //if the program is stable (this if statement limits the rate)
           {    
		     if(yaw_target_raw >= (yaw_target + (yaw_rate*dt))){yaw_target += (yaw_rate*dt);} // if the raw target yaw value is greater than the yaw target, add the target with the rate.
		     else if(yaw_target_raw <= (yaw_target - (yaw_rate*dt))){yaw_target -= (yaw_rate*dt);} // if the raw target yaw value is less than the yaw target, take the rate away from the target.
		     else{yaw_target =yaw_target_raw;}

		     if(pitch_target_raw >= (pitch_target + (pitch_rate*dt))){pitch_target += (pitch_rate*dt);} // if the raw target pitch value is greater than the pitch target, add the target with the rate.
		     else if(pitch_target_raw <= (pitch_target - (pitch_rate*dt))){pitch_target -= (pitch_rate*dt);} // if the raw target pitch value is less than the pitch target, take the rate away from the target.
		     else{pitch_target =pitch_target_raw;}

		     if(depth_target_raw >= (depth_target + (depth_rate*dt))){depth_target += (depth_rate*dt);} // if the raw target depth value is greater than the depth target, add the target with the rate.
		     else if(depth_target_raw <= (depth_target - (depth_rate*dt))){depth_target -= (depth_rate*dt);} // if the raw target depth value is less than the depth target, take the rate away from the target.
		     else{depth_target =depth_target_raw;}

		   }
		 
          else if(input_stability == false) //if the program is not stable
           { 
			 yaw_target = yaw_target_raw; //make the targets = the raw target values.
			 pitch_target = pitch_target_raw;
			 depth_target = depth_target_raw;
		   }

		  //yaw PID calculations
		  yaw_error = yaw_target - yaw_input;
		  if (yaw_error > 180) {yaw_error-=360;}	// optomise yaw to turn through shortest route
		  if (yaw_error < -180) {yaw_error+=360;}
	  	  yaw_integral = yaw_integral + (yaw_error*dt);
	  	  yaw_derivative = (yaw_error - yaw_previous_error)/dt;
	  	  yaw_previous_error = yaw_error;
	  	  yaw_output = (yaw_Kp*yaw_error) + (yaw_Ki*yaw_integral) + (yaw_Kd*yaw_derivative);
	
		  //pitch PID calculations
		  pitch_error = pitch_target - pitch_input;
	  	  pitch_integral = pitch_integral + (pitch_error*dt);
	  	  pitch_derivative = (pitch_error - pitch_previous_error)/dt;
	      pitch_previous_error = pitch_error;
	  	  pitch_output = (pitch_Kp*pitch_error) + (pitch_Ki*pitch_integral) + (pitch_Kd*pitch_derivative);
			
		  //depth PID calculations
	   	  depth_error = depth_target - depth_input;
	  	  depth_integral = depth_integral + (depth_error*dt);
	  	  depth_derivative = (depth_error - depth_previous_error)/dt;
	      depth_previous_error = depth_error;
	  	  depth_output = (depth_Kp*depth_error) + (depth_Ki*depth_integral) + (depth_Kd*depth_derivative);
		
	     //output to motors
		  motorCfg.front_right = int(constrain((move_x-move_y-yaw_output), -100, 100)); //motor values are constrained to -100 and 100.
		  motorCfg.front_left = int(constrain((move_x+move_y+yaw_output), -100, 100));
		  motorCfg.back_right = int(constrain((-move_x-move_y+yaw_output), -100, 100));
		  motorCfg.back_left = int(constrain((-move_x+move_y-yaw_output), -100, 100));		 
		  motorCfg.front = int(constrain((-depth_output+pitch_output), -100, 100));
		  motorCfg.back = int(constrain((-depth_output-pitch_output), -100, 100));	
		  motorMsg.publish(motorCfg); //publish motor values.
	    }
    
      else if (emergency_stop == true) //if the emergency message is recieved then stop the motors.
       {
	     motorCfg.front_right = 0;
	     motorCfg.front_left = 0;
	     motorCfg.back_right = 0;
	     motorCfg.back_left = 0;
	     motorCfg.front = 0;
         motorCfg.back = 0;	
	   }
			
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

