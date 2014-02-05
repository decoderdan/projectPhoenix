
/** *********************************************** **/
/** Name: publisher.cpp                             **/
/**                                                 **/
/** Function: To send a "heart beat" signal every   **/
/**           second from the submarine to prove    **/
/**           it is still working correctly.        **/
/**                                                 **/
/** Author: James Killick                           **/
/**                                                 **/
/** Last Date Modified: 29/01/2014                  **/
/**                                                 **/
/**  ********************************************** **/

#include "ros/ros.h"
#include "std_msgs/Bool.h"

/** *********************************************** **/
/** Name: main                                      **/
/**                                                 **/
/** Function: To set up the publisher, and send     **/
/**           a "heart_beat" signal every second    **/
/**                                                 **/
/** *********************************************** **/

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "publisher");

  ros::NodeHandle n;

  ros::Publisher heart_Beat = n.advertise<std_msgs::Bool>("heart_Beat", 1000); //sets up the publisher for the heart_beat

  ros::Rate loop_rate(2); //sets the loop rate to 0.5 second

  std::cout << "THUMP" << std::endl;

  while (ros::ok())
  {

    std_msgs::Bool msg; //sets the message type to boolean

    std::cout << "THUMP" << std::endl;

    msg.data = 1; //sets the heart_beat message to true

    heart_Beat.publish(msg); //publishes the heart_beat message

    ros::spinOnce(); 

    loop_rate.sleep(); //delays to ensure the 1 second loop time.
  }


  return 0;
}