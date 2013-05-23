#include "ros/ros.h"
#include "std_msgs/UInt8.h"

int state_selected = 0;

void stateCallback(const std_msgs::UInt8& state)
{
  ROS_INFO("The current state is: [%d]", state.data);
  state_selected = state.data;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "mission_control");


  ros::NodeHandle n;

  ros::Publisher state_pub = n.advertise<std_msgs::UInt8>("state", 1000);

  ros::Subscriber sub = n.subscribe("select_state", 1000, stateCallback);

  ros::Rate loop_rate(10);  //loop every 10hz

  std_msgs::UInt8 current_state;

  while (ros::ok())
  {
 
    ros::spinOnce();

    switch(state_selected)
    {
	case 1 : current_state.data = 1;  //state for rising to the surface
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


    loop_rate.sleep();

    
  }


  return 0;
}

