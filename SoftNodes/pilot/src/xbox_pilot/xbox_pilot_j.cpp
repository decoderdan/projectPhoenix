
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
 /**  *********************************************** **/

 #include <stdio.h>
 #include "ros/ros.h"
 #include <custom_msg/MotorConfig.h>
 #include <sensor_msgs/Joy.h>
 #include <custom_msg/TargetVector.h>
 #include <std_msgs/Float32.h>
 #include <custom_msg/PIDValues.h>
 #include <custom_msg/IMUData.h>

 void joyCallback(const sensor_msgs::Joy::ConstPtr&); //declaration of call back functions
 float map(float, float, float, float, float);
 
 ros::Publisher motorMsg;	//global declaration of the publisher "motorMsg"
 custom_msg::MotorConfig motorCfg;
 
 ros::Publisher targetMsg;
 custom_msg::TargetVector TargetVector;

 static std_msgs::Float32 z; 

 bool strafe_test = false; // used to activate experimental code
 int button_a = 0; //used to toggle the button

////

    float yaw_output = 0; //initialise values for yaw, pitch, depth.
	float pitch_output = 0;
	float depth_output = 0;
	float dt = 0.02;

 float depth_rate = 0.05; 		//m per second
 float depth_Kp = 400;			//3 variables for depth PID
 float depth_Ki = 1;
 float depth_Kd = 0;
 float depth_input = 0;			//depth value recieved from the SVP
 float depth_target_raw = 0;	
 float depth_target = 0;		//desired depth value
 float depth_error = 0;			//difference between desired and actual values.
 float depth_previous_error = 0;
 float depth_integral = 0;
 float depth_derivative = 0;
////


 /** *********************************************** **/
 /** Name: vectorCallBack                            **/
 /**                                                 **/
 /** Function: To recieve yaw, pitch and depth data  **/
 /** when the valut of the target vector changes.    **/
 /** *********************************************** **/
/*
 void vectorCallBack(const custom_msg::TargetVector& data) 
  {
    if (data.set_z == true) //if depth value has changed.
	 {
	   depth_target_raw = data.vector_z; //depth variable = new input value.
	   std::cout << "Depth target updated "  << std::endl;
	 } 
	
  }
*/
////
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
////

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
	//targetMsg = n.advertise<custom_msg::TargetVector>("vector",100); // publish new target vector

   	//ros::Subscriber vectorSub = n.subscribe("vector", 100, vectorCallBack); // subscriber for depth target vector 		
	ros::Subscriber joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, joyCallback); // Subscribe to joystick
    ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);	//subscriber for the depth.

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
       strafe_test = ~strafe_test;  //toggle strafe test
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
		  std::cout << "Rise"  << std::endl;
  	      rise = (1 * ((joy->axes[5] + 1.0)/2.0)); //sets the right trigger to control rise
          depthChange = (rise * 1); //sets the maximum velocity to 0.1 m/s
        }

       else if((joy->axes[5] == 1) && (joy->axes[2] < 1)) //if right trigger is up and left trigger is down
        { 	
		  std::cout << "Dive"  << std::endl;
	      dive = (-1 * ((joy->axes[2] + 1.0)/2.0)); //sets the left trigger to control dive
          depthChange = (dive * 1); //sets maximum velocity to 0.1 m/s		
        }

       else //if none or both of the trigers are held down do not change the depth.
        {
		  std::cout << "no trigger"  << std::endl;
	      depthChange = 0;
        }   

	   depth_target_raw = (depth_target_raw + depthChange); //depth target vector = the input target value + change in depth
	   
/* ************************************ new PID calculations and setup ********************************** */

       if(depth_target_raw >= (depth_target + (depth_rate*dt))){depth_target += (depth_rate*dt);} // if the raw target depth value is 																				greater than the depth target, add the target with the rate.
	   else if(depth_target_raw <= (depth_target - (depth_rate*dt))){depth_target -= (depth_rate*dt);} // if the raw target depth value is 																				less than the depth target, take the rate away from the target.
	   else{depth_target =depth_target_raw;}

//depth PID calculations
	   depth_error = depth_target - depth_input;
	   depth_integral = depth_integral + (depth_error*dt);
	   depth_derivative = (depth_error - depth_previous_error)/dt;
	   depth_previous_error = depth_error;
	   depth_output = (depth_Kp*depth_error) + (depth_Ki*depth_integral) + (depth_Kd*depth_derivative);

       motorCfg.front = (int8_t)(constrain((depth_output), -25, 25));
	   motorCfg.back = (int8_t)(constrain((depth_output), -25, 25));	
	
if(depth_output > 0)
{
std::cout << "move"  << std::endl;
}
if(depth_output == 0)
{
std::cout << "no signal"  << std::endl;
}
if(depth_output < 0)
{
std::cout << "reverse"  << std::endl;
}

	   motorMsg.publish(motorCfg); //publish motor values.
	   
/* ****************************************************************************************************** */


/*
	   TargetVector.set_z = true; // PID_pilot will only look for a change in depth.
       TargetVector.set_y = false;
	   TargetVector.set_x = false;
       TargetVector.set_yaw = false;
       TargetVector.set_pitch = false;
       TargetVector.set_roll = false;
*/
     //targetMsg.publish(TargetVector); //publish the target vector.
	 //motorMsg.publish(motorCfg); //publish the motor values.
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

       if(joy->axes[0] > 0) //if the x axis is posative (right)
        {
          motorCfg.front_right = (joy->axes[0] * -50);	//-  strafe right
          motorCfg.front_left  = (joy->axes[0] * 50);  //+  multiplied by 2x y value cos of thruster orientation not being 45 degrees
          motorCfg.back_right  = (joy->axes[0] * -50); //-
          motorCfg.back_left   = (joy->axes[0] * 50);  //+
        }

       if(joy->axes[0] < 0) //if the x axis is negative (left)
        {
          motorCfg.front_right = (joy->axes[0] * -50);	//+ strafe left
          motorCfg.front_left  = (joy->axes[0] * 50); //- orientation is reversed because joy->axes[0] is negative
          motorCfg.back_right  = (joy->axes[0] * -50);  //+
          motorCfg.back_left   = (joy->axes[0] * 50); //-
        }

       if(joy->axes[1] > 0) //if the y axis is posative (up)
        {
          motorCfg.front_right += (joy->axes[1] * 25);	 //+ move forward (also adding this to the x motor values)
          motorCfg.front_left  += (joy->axes[1] * 25);  //+
          motorCfg.back_right  += (joy->axes[1] * -25); //-
          motorCfg.back_left   += (joy->axes[1] * -25); //-
        }

       if(joy->axes[1] < 0) //if the y axis is negative (down)
        {
          motorCfg.front_right += (joy->axes[1] * 25); //- move backwards (also adding this to the x motor values)
          motorCfg.front_left  += (joy->axes[1] * 25); //- orientation is reversed because joy->axes[1] is negative
          motorCfg.back_right  += (joy->axes[1] * -25);  //+
          motorCfg.back_left   += (joy->axes[1] * -25);  //+
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
