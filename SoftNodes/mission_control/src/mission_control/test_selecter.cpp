#include "ros/ros.h"
#include "std_msgs/UInt8.h"


int main(int argc, char **argv)
{

  ros::init(argc, argv, "test_selecter");


  ros::NodeHandle n;

  ros::Publisher select_state_pub = n.advertise<std_msgs::UInt8>("select_state", 1000);

  ros::Rate loop_rate(10);  //loop every 10hz


  while (ros::ok())
  {
    
    std_msgs::UInt8 selected_state;

    selected_state.data = 3;

    select_state_pub.publish(selected_state);

    loop_rate.sleep();
  }


  return 0;
}

