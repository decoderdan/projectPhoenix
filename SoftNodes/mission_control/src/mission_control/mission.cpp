#include "ros/ros.h"
#include <sstream>
#include "std_msgs/UInt8.h"
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <sensor_msgs/Joy.h>

void joyCallback(const sensor_msgs::Joy::ConstPtr&);
void broadcastWPs();
void manualControl(int);
void setStartPoint();

int state_selected = 1;
int x_button = 0;
int a_button = 0;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "mission_control");
  ros::NodeHandle n;

  
  ROS_INFO("TEST PRINT");

while (1) 
{
  switch(state_selected)
  {
  	case 1 : manualControl(1);
  		   break;
  		   
  	case 2 : manualControl(0);
  		   setStartPoint();
  		   break;
  		   
  	case 3 : manualControl(0);
  		   broadcastWPs(); 
  		   break;
  }
}
  return 0;
}

void broadcastWPs()
{
  static tf::TransformBroadcaster broadcaster;

	std::cout << "broadcast the waypoints for a square" << std::endl;

	tf::Transform wp;

	wp.setOrigin( tf::Vector3(5.0, 0.0, 0.0) );
	wp.setRotation( tf::createQuaternionFromRPY(0.0, 0.0, 0.0) );
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", "/square_WP1" ));

	wp.setOrigin( tf::Vector3(5.0, 5.0, 0.0) );
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", "/square_WP2" ));

	wp.setOrigin( tf::Vector3(0.0, 5.0, 0.0) );
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", "/square_WP3" ));

	wp.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", "/square_WP4" ));

}

void manualControl(int on)
{
	if (on)
	{
		//In here needs to send a message to activate manual controls
	}
	
	else
	{
		//In here needs to send a message to deactivate manual controls
	}
}

void setStartPoint()
{
	 tf::StampedTransform transform;
	 
       try
       {
         wp.lookupTransform("/imu", "/square_origin",  //this line does not compile. I dont know what is wrong
                                  ros::Time(0), transform);
       }
       
       catch (tf::TransformException ex)
       {
         ROS_ERROR("%s",ex.what());
       }
       
       state_selected = 3;	//now origin waypoint has been saved start moving to the waypoints
}

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{

  x_button = joy->buttons[2];		//X button
  a_button = joy->buttons[1];

     if(x_button)
     {
	  if(x_button)
	  {
	  	ROS_INFO("The sub is moving in a square [%d]", x_button);
		state_selected = 2;	//first set origin waypoint then move in a square
	  }

	  if(a_button)
	  {
	  	ROS_INFO("The sub is manually controlled [%d]", x_button);
		state_selected = 1;
	  }

    }
}
