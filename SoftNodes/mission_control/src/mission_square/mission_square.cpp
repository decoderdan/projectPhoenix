#include "ros/ros.h"
#include "std_msgs/UInt8.h"
#include <sensor_msgs/Joy.h>

void joyCallback(const sensor_msgs::Joy::ConstPtr&);
void finishedCallback(const std_msgs::UInt8& finished_task);

int x_button = 0, last_x_button = 0;
int square_stage = 0;		//0 = surface, 1 = go straight, 2 = turn right 90 degrees
int square_number = 0;
int square_count = 0;
int number_squares = 0;
int state_changed = 0;

ros::Publisher square_task_pub;

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{

  x_button = joy->buttons[2];		//X button

     if(x_button != last_x_button)
     {
	  if(x_button)
	  {
	  	ROS_INFO("The sub is moving in a square [%d]", x_button);
		state_changed = 1;	//tell the state machine to change state
		square_stage = 1;	//tell the state machine to start the square
		square_count = 0;	//start the square count again
	  }

	  else
	  {
	  	ROS_INFO("The sub is manually controled [%d]", x_button);
		state_changed = 1;	//tell the state machine to change state
		square_stage = 0;		// return manual control 
	  }
	  last_x_button = x_button;
    }
}

void finishedCallback(const std_msgs::UInt8& finished_task)
{
	if(x_button && finished_task.data)		//continue only if the X button is pressed down and the  
	{						//navigator has finished previous task.
		state_changed = 1;	//tell the state machine to change state

		if(square_stage == 1)
			square_stage = 2;	//if the completed task was go straight, next task is to turn

		else if(square_stage == 2)
			square_stage = 1;	//if the completed task was to turn, next task is to go straight
	}
	
}
/***********************************************************************/


int main(int argc, char **argv)
{
  
  
  ros::init(argc, argv, "mission_square");


  ros::NodeHandle n;


  /*subscribe to the controller*/
  ros::Subscriber joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, joyCallback);	//message from controller
  
  /*publish the instructions for a square to the navigator*/
  ros::Publisher square_task_pub = n.advertise<std_msgs::UInt8>("square_task", 1000);	//tell navigator what to do
  /*subscribe to the navagator to check if it has finished its current task*/
  ros::Subscriber sub = n.subscribe("task_complete", 1000, finishedCallback);	//message from navigator asking for next task

  //..ros::Rate loop_rate(10);  //loop every 10hz

  std_msgs::UInt8 square_task;		//define std message

  while(ros::ok())
  {
 
	ros::spinOnce();				//check for subscribed messages

	if(state_changed)
	{	
		switch(square_stage)
		{	

			case 1 : 
				 ROS_INFO("The sub is moving forward");
				 break;
			case 2 : 
				 square_count++;	 	//keep track of how many corners has been made
				 ROS_INFO("The sub is turning. side %d complete", square_count);
				 break;


			default : 
				 ROS_INFO("The sub is stoping");
				 square_stage = 0; break;	//stop movment
		}

		square_task.data = square_stage;	//put the current task into the message structure 
		square_task_pub.publish(square_task);		//tell the navagator about the new state.

		if(square_count>=4)		//if the end of the square has been reached...
		{
			square_count = 0;	//reset the number of corners count	
			number_squares++;	//count how many squares have been completed
			ROS_INFO("The sub has finished square number: %d", number_squares);
		}
		
		state_changed = 0;
	}

  }
  return 0;
}


