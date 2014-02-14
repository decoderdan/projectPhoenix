
/** *********************************************** **/
/** Name: subscriber.cpp                            **/
/**                                                 **/
/** Function: To recieve a "heart beat" from        **/
/**           the submarine to ensure it is         **/
/**           still working correctly.              **/
/**                                                 **/
/** Author: James Killick                           **/
/**                                                 **/
/** Last Date Modified: 29/01/2014                  **/
/**                                                 **/
/**  ********************************************** **/

#include "ros/ros.h"
#include "std_msgs/Bool.h"

int no_signal = 0;  //used to send the emergency signal if delay between beats is too long.
double current_time = 0.0; //used to store the current time in seconds.
double previous_time = 0.0; //used to store the time of the last beat.
double difference = 0.0; //difference between current_time and previous_time.

/** *********************************************** **/
/** Name: pulseCallBack                             **/
/**                                                 **/
/** Function: To recieve the heart beat every       **/
/**           half a second and set the previous    **/
/**           time variable.                        **/
/** *********************************************** **/

void pulseCallback(const std_msgs::Bool& pulse)
{
 previous_time = current_time; //Make the previous time = the current time.  
}

/** *********************************************** **/
/** Name: main                                      **/
/**                                                 **/
/** Function: To set up the subscribers/publishers, **/
/**           get the current time and send the     **/
/**           emergency signal if needed.           **/
/** *********************************************** **/

int main(int argc, char **argv)
  {
    ros::init(argc, argv, "subscriber");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("heart_Beat", 1000, pulseCallback); //Sets up subscriber for the 1 second beat.
    ros::Publisher emergency = n.advertise<std_msgs::Bool>("emergency", 1000);  //Sets up publisher for emergency signal.
  
    ros::Rate loop_rate(2); //Sets the loop rate to 0.5 second per loop.

    while (ros::ok())
      {
        std_msgs::Bool msg; //Sets the message type to Boolean
        
        current_time =ros::Time::now().toSec();//Gets the time in seconds and saves it into "current_time"

        difference = (current_time - previous_time);  //calculates the time between signals.
        std::cout << "Difference: " << difference  << std::endl;  
  
        if((current_time > 0) && (previous_time > 0)) //Compensates for the first few cycles where time = 0;
          {
            if(difference >= 2.0) //Delay is greater than 3 seconds allow the emergency signal to be sent.
              {  
                no_signal = 1;
              }
          }

        std::cout << "signal: " << no_signal  << std::endl;
  
        if(no_signal != 0) //If the delay has been greater than 3 seconds
          {
            msg.data = true; //set emergency data to true
            emergency.publish(msg); //publish emergency message
            std::cout << "no signal " << std::endl;
          }
        
        ros::spinOnce(); //check call back functions.
        loop_rate.sleep(); //delay to ensure the loop rate.
      }


  return 0;
}