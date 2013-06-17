#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void cmdvelCallback(const geometry_msgs::TwistConstPtr& cmd_vel)
{
    ROS_INFO( "Velocity_Recieved_by_OdomNode");
  float vx = cmd_vel->linear.x;
  float vy = cmd_vel->linear.y;
  float vth = cmd_vel->angular.z;

}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "base_controller");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("cmd_vel", 1000, cmdvelCallback);

  ros::spin();

  return 0;
}
