#include "ros/ros.h"
#include <sstream>
#include "std_msgs/UInt8.h"
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>

void stateCallback(const std_msgs::UInt8& finished_task);
void broadcastWPs();

int state_selected = 1;

ros::Publisher state_pub;


/* Create a transform broadcaster and listener */
static tf::TransformBroadcaster br;
  
/* Here are our minimal transforms. IMU, SVP and Sonar */
static tf::TransformBroadcaster broadcaster;
//tf::Transform imu_tr;
//tf::Transform svp_tr;
//tf::Transform sonar_tr;


int main(int argc, char **argv)
{

  ros::init(argc, argv, "mission_control");


  ros::NodeHandle n;

  ros::Publisher state_pub = n.advertise<std_msgs::UInt8>("state", 1000);

  ros::Subscriber sub = n.subscribe("select_state", 1000, stateCallback);

  ROS_INFO("TEST PRINT");

  std_msgs::UInt8 current_state;

  //while (ros::ok())
  //{


    	//ros::spinOnce();

    switch(state_selected)
    {
	case 1 : broadcastWPs();
	     break;

	case 2 : current_state.data = 2;
	     break;
	case 3 : current_state.data = 3;
	     break;
	case 4 : current_state.data = 4;
	     break;
	case 5 : current_state.data = 5;
	     break;
	default : current_state.data = 0;
	     break;
    }
	
    state_pub.publish(current_state);
    
 // }


  return 0;
}

void broadcastWPs()
{

	std::cout << "broadcast the waypoints for a square" << std::endl;

	broadcaster.sendTransform(
    		tf::StampedTransform(
 			tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(5.0, 0.0, 0.0)), //(x,y,z)
    		ros::Time::now(),"/world", "/squareWP1")); 
	
	broadcaster.sendTransform(
    		tf::StampedTransform(
 			tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(5.0, 5.0, 0.0)), //(x,y,z)
    		ros::Time::now(),"/world", "/squareWP2")); 

	broadcaster.sendTransform(
    		tf::StampedTransform(
 			tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 5.0, 0.0)), //(x,y,z)
    		ros::Time::now(),"/world", "/squareWP3")); 

	broadcaster.sendTransform(
    		tf::StampedTransform(
 			tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.0, 0.0)), //(x,y,z)
    		ros::Time::now(),"/world", "/squareWP4"));  
}
void stateCallback(const std_msgs::UInt8& finished_task)
{

}

