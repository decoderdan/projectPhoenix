
 /** *********************************************** **/
 /** Name: xbox_pilot.cpp                            **/
 /**                                                 **/
 /** Function: To recieve values from the xbox       **/
 /** 		   controller and convert it into motor  **/
 /**           values and target vector values.      **/
 /**                                                 **/
 /** Author: Unknown, edited by James Killick        **/
 /**                                                 **/
 /** Last Date Modified: 02/12/2013                  **/
 /** *********************************************** **/

 #include <stdio.h>
 #include "ros/ros.h"
 #include <custom_msg/MotorConfig.h>
 #include <sensor_msgs/Joy.h>
 #include <custom_msg/TargetVector.h>

 void joyCallback(const sensor_msgs::Joy::ConstPtr&); //declaration of call back functions
 float map(float, float, float, float, float);
 float depth_target_raw;
 
 ros::Publisher motorMsg;	//global declaration of the publisher "motorMsg"
 custom_msg::MotorConfig motorCfg;
 
 ros::Publisher targetMsg;
 custom_msg::TargetVector TargetVector;

 int strafe_test = 0; // used to activate experimental code
 int button_a = 0; //used to toggle the button

 /** *********************************************** **/
 /** Name: vectorCallBack                            **/
 /**                                                 **/
 /** Function: To recieve yaw, pitch and depth data  **/
 /** when the valut of the target vector changes.    **/
 /** *********************************************** **/

 void vectorCallBack(const custom_msg::TargetVector& data) 
  {
    if (data.set_z == true) //if depth value has changed.
	 {
	   depth_target_raw = data.vector_z; //depth variable = new input value.
	   std::cout << "Depth target updated "  << std::endl;
	 } 
	
  }

 /** *********************************************** **/
 /** Name: main                                      **/
 /**                                                 **/
 /** Function: Runs the main logic for the code to   **/
 /** publish the values to the pid_pilot program.    **/
 /** *********************************************** **/

 int main( int argc, char **argv )
  {
	ros::init(argc, argv, "xbox_pilot");
	ros::NodeHandle n;

	motorMsg = n.advertise<custom_msg::MotorConfig>("motor_config", 100); //Publisher for the motor configuration
	targetMsg = n.advertise<custom_msg::TargetVector>("vector",100); // publish new target vector

	ros::Subscriber vectorSub = n.subscribe("vector", 100, vectorCallBack); // subscriber for depth target vector 		
	ros::Subscriber joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, joyCallback); // Subscribe to joystick

	ros::spin();

	return 0;
  }

 /** *********************************************** **/
 /** Name: constrain                                 **/
 /**                                                 **/
 /** Function: To limit motor values to prevent      **/
 /** them from going over the maximum value.         **/
 /** *********************************************** **/

 float constrain(float x, float min, float max) 
  {
	if (x < min) return min; //limits the minimum value to -100
	if (x > max) return max; //limits the maximum value to 100
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
 /** Name: joyCallback                               **/
 /**                                                 **/
 /** Function: Takes values from the xbox controller **/
 /** converts it to motor values and target vectors. **/
 /** *********************************************** **/

 void joyCallback(const sensor_msgs::Joy::ConstPtr& joy) 
  {
 	float rise = 0.0;	//initialise variables for depth.
	float dive = 0.0;
	float depthChange = 0.0; 
    
 if((joy->buttons[0] == 1)&&(button_a == 0)) //if button A has been pressed and released.
  {
    strafe_test ~= strafe_test;  //toggle strafe test
    button_a = 1;				 //prevent the program from toggling strafe_test until the button is released
  }
 
 if((joy->buttons[0] == 0)&&(button_a == 1)) //if the button is released and has been pressed before
  {
    button_a = 0;	//reset the button
  }
   
 if(strafe_test == 0) //if the button has not been pressed, run the normal program
  {
	// 0 = Left X Axis 
    // 1 = Left Y Axis
	
	float rads = atan2(joy->axes[1], -joy->axes[0]); // converts x & y values from left joystick
	float distance = constrain(sqrt(pow(-joy->axes[0],2)+pow(joy->axes[1],2)),0,1); //Get distance 
	distance = (distance < 0.12 ? 0 : distance); //Bit of a dead zone
	distance = constrain(map(distance, 0.12, 1, 0, 1), 0, 1); //Re-map so it's smooth from deadzone outwards

	//Direction Control, uses radian values to produce motor values butconstrains them from -100 to 100.	
	motorCfg.front_right = -(int8_t)(constrain(140 * cos(rads+M_PI/4), -100, 100) * distance); 
	motorCfg.front_left = -(int8_t)(constrain(-140 * cos(M_PI/4-rads), -100, 100) * distance);
	motorCfg.back_left = -(int8_t)(constrain(-140 * cos(rads+M_PI/4), -100, 100) * distance);
	motorCfg.back_right = -(int8_t)(constrain(140 * cos(M_PI/4-rads), -100, 100) * distance);

	//Yaw control, converts right joy stick x values into motor values.
	motorCfg.front_right += (20 * joy->axes[3]);
	motorCfg.front_left += (-20 * joy->axes[3]);
	motorCfg.back_left += (20 * joy->axes[3]);
	motorCfg.back_right += (-20 * joy->axes[3]);

	motorCfg.front_right = constrain(motorCfg.front_right, -100, 100); //constrain front right motor, min = -100, max = +100
	motorCfg.front_left = constrain(motorCfg.front_left, -100, 100);
	motorCfg.back_right = constrain(motorCfg.back_right, -100, 100);
	motorCfg.back_left = constrain(motorCfg.back_left, -100, 100);


	//Depth control, reads from the right ([5]) and left ([2]) triggers and outputs target vector values.

    if((joy->axes[5] < 1) && (joy->axes[2] == 1)) //if right trigger is down and left trigger is up.
     {
	   
	   rise = (1 * ((joy->axes[5] + 1.0)/2.0)); //sets the right trigger to control rise
       depthChange = (rise / 10); //sets the maximum velocity to 0.1 m/s
     }

    else if((joy->axes[5] == 1) && (joy->axes[2] < 1)) //if right trigger is up and left trigger is down
     {	
	   dive = (-1 * ((joy->axes[2] + 1.0)/2.0)); //sets the left trigger to control dive
       depthChange = (dive / 10); //sets maximum velocity to 0.1 m/s		
     }

    else //if none or both of the trigers are held down do not change the depth.
     {
	   depthChange = 0;
     }   

	TargetVector.vector_z = (depth_target_raw + depthChange); //depth target vector = the input target value + change in depth form controller.

	set_z = true; // PID_pilot will only look for a change in depth.
    set_y = false;
	set_x = false;
    set_yaw = false;
    set_pitch = false;
   // set_roll = false;

	targetMsg.publish(TargetVector); //publish the target vector.
	motorMsg.publish(motorCfg); //publish the motor values.
  }

/* *********************************************************************************************************************** */
/* *********************************************************************************************************************** */
/* 													NEW STRAFING CODE													   */
/* *********************************************************************************************************************** */
/* *********************************************************************************************************************** */

 if(strafe_test == 1) //if the button has been pressed run experimental strafe section
  {

    //x = joy->axes[0]
    //y = joy->axes[1]

    if((joy->axes[0] == 0)&&(joy->axes[1] == 0)) //if no direction is indicated.
     {
       motorCfg.front_right = 0; 	//turn off motors
       motorCfg.front_left  = 0;
       motorCfg.back_left   = 0;
       motorCfg.back_right  = 0;
     }

    if(joy->axes[0] >= 0) //if the x axis is posative (right)
     {
       motorCfg.front_right = (joy->axes[0] * -25);	//-  strafe right
       motorCfg.front_left  = (joy->axes[0] * 25);  //+
       motorCfg.back_right  = (joy->axes[0] * -25); //-
       motorCfg.back_left   = (joy->axes[0] * 25);  //+
     }

    if(joy->axes[0] < 0) //if the x axis is negative (left)
     {
       motorCfg.front_right = (joy->axes[0] * 25);	//+ strafe left
       motorCfg.front_left  = (joy->axes[0] * -25); //-
       motorCfg.back_right  = (joy->axes[0] * 25);  //+
       motorCfg.back_left   = (joy->axes[0] * -25); //-
     }

    if(joy->axes[1] >= 0) //if the y axis is posative (up)
     {
       motorCfg.front_right += (joy->axes[1] * 25);	 //+ move forward (also adding this to the x motor values)
       motorCfg.front_left  += (joy->axes[1] * 25);  //+
       motorCfg.back_right  += (joy->axes[1] * -25); //-
       motorCfg.back_left   += (joy->axes[1] * -25); //-
     }

    if(joy->axes[1] < 0) //if the y axis is negative (down)
     {
       motorCfg.front_right += (joy->axes[1] * -25); //- move backwards (also adding this to the x motor values)
       motorCfg.front_left  += (joy->axes[1] * -25); //-
       motorCfg.back_right  += (joy->axes[1] * 25);  //+
       motorCfg.back_left   += (joy->axes[1] * 25);  //+
     }

    motorCfg.front_right = constrain(motorCfg.front_right, -100, 100); //constrain front right motor, min = -100, max = +100
    motorCfg.front_left = constrain(motorCfg.front_left, -100, 100);
    motorCfg.back_right = constrain(motorCfg.back_right, -100, 100);
    motorCfg.back_left = constrain(motorCfg.back_left, -100, 100);

    motorMsg.publish(motorCfg); //publish the motor values.

  }
/* *********************************************************************************************************************** */
/* *********************************************************************************************************************** */
/* *********************************************************************************************************************** */
/* *********************************************************************************************************************** */

  }
