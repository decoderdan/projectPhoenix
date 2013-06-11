/* 
 * rosserial Time and TF Example
 * Publishes a transform at current time
 */

#include <ros.h>
#include <ros/time.h>
#include <tf/transform_broadcaster.h>

#include <sensor_msgs/Range.h>

ros::NodeHandle  nh;

geometry_msgs::TransformStamped t;
tf::TransformBroadcaster broadcaster;
//sensor_msgs::Range range_msg;
//ros::Publisher pub_range( "range_data", &range_msg);

const int analog_pin = 0;
char base_link[] = "/base_link";
char odom[] = "/odom";
char frameid[] = "/odom";

float getRange(int pin_num){
    float volts = analogRead(pin_num)*0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
    float distance = (65*pow(volts, -1.10))/1000; 
    if (distance < 0.2){distance = 0.2;}
    if (distance > 1.5){distance = 1.5;}
    return (distance); //convert to meters
}

void setup()
{
  nh.initNode();
  broadcaster.init(nh);
  //nh.advertise(pub_range);
  
  //range_msg.radiation_type = sensor_msgs::Range::INFRARED;
  //range_msg.header.frame_id =  frameid;
  //range_msg.field_of_view = 0.1;
  //range_msg.min_range = 0.2;
  //range_msg.max_range = 1.5;
}

void loop()
{  
  t.header.frame_id = odom;
  t.header.stamp = nh.now();
  //range_msg.header.stamp = nh.now();
  t.child_frame_id = base_link;
  t.transform.translation.x = 1.0; 
  t.transform.rotation.x = 0.0;
  t.transform.rotation.y = 0.0; 
  t.transform.rotation.z = 0.0; 
  t.transform.rotation.w = 1.0;  
  t.header.stamp = nh.now();
  broadcaster.sendTransform(t);
  
  //range_msg.range = getRange(analog_pin);
  //pub_range.publish(&range_msg);
  nh.spinOnce();
  delay(100);
  
}
