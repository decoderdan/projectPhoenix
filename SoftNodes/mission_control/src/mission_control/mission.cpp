#include "ros/ros.h"
#include <sstream>
#include "std_msgs/UInt8.h"
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>

void broadcastWPs();

int state_selected = 1;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "mission_control");
  ros::NodeHandle n;

  
  ROS_INFO("TEST PRINT");

while (1) {
  broadcastWPs();
};
  return 0;
}

void broadcastWPs()
{
  static tf::TransformBroadcaster broadcaster;

	std::cout << "broadcast the waypoints for a square" << std::endl;

	tf::Transform wp;

	wp.setOrigin( tf::Vector3(5.0, 0.0, 0.0) );
	wp.setRotation( tf::createQuaternionFromRPY(0.0, 0.0, 0.0) );
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/world", "/square_WP1" ));

	wp.setOrigin( tf::Vector3(5.0, 5.0, 0.0) );
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/world", "/square_WP2" ));

	wp.setOrigin( tf::Vector3(0.0, 5.0, 0.0) );
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/world", "/square_WP3" ));

	wp.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/world", "/square_WP4" ));

}

