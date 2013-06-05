#include "ros/ros.h"
#include <sstream>
#include "std_msgs/UInt8.h"
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <sensor_msgs/Joy.h>
#include <custom_msg/TargetVector.h>

void broadcastWPs();
void manualControl(int);
void setStartPoint();
void joyCallback(const sensor_msgs::Joy::ConstPtr&);
float map(float x, float in_min, float in_max, float out_min, float out_max);

int state_selected = 1;
int x_button = 0;
int a_button = 0;
bool got_vals = false;

//int cur_wp = 1;

float x_analog = 0;
float l_analog = 0;
float r_analog = 0;

tf::StampedTransform origin_tf; //Stores our origin tf
ros::Publisher target_publisher;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "mission_control");
  ros::NodeHandle n;

	/* Subscribe to joystick */
	ros::Subscriber joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, joyCallback);
  target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
	
  ROS_INFO("Mission Control Node Started - Subscribed to joystick");


setStartPoint();
while (ros::ok()) 
{
//  ros::spinOnce(); //Allow joystick callback
broadcastWPs();
/*  switch(state_selected)
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
  
*/}
  return 0;
}

void broadcastWPs()
{
  static tf::TransformBroadcaster broadcaster;
	//std::ostringstream oss;
	
	std::cout << "broadcast the waypoints for a square" << std::endl;

	//First, broadcast our final destination relative to the world (This is our current position)
	broadcaster.sendTransform( tf::StampedTransform( origin_tf, ros::Time::now(), "/world", "/square_origin" ));

	//Now post the rest of the way points
	tf::Transform wp;
	
	wp.setOrigin( tf::Vector3(5.0, 0.0, 0.0) );
	wp.setRotation( tf::createQuaternionFromRPY(0.0, 0.0, 0.0) );
//	oss << "/wp" << cur_wp++;
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", "/wp1" ));
	//oss.str("");
	//oss.clear();
	
	wp.setOrigin( tf::Vector3(5.0, -5.0, 0.0) );
	//oss << "/wp" << cur_wp++;
  broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", "wp2" ));
	//oss.str("");
	//oss.clear();
	
	wp.setOrigin( tf::Vector3(0.0, -5.0, 0.0) );
	//oss << "/wp" << cur_wp++;
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", "wp3" ));
	//oss.str("");
	//oss.clear();
	
	wp.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
	//oss << "/wp" << cur_wp++;
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", "wp4" ));
	//oss.str("");
	//oss.clear();
}

void manualControl(int on)
{
	if (on)
	{
		//In here needs to send a message to activate manual controls
		//Spit out motor controls based on xbox controller
    custom_msg::TargetVector tv;
    tv.set_y = false;
		tv.set_z = false;
    tv.set_pitch = false;
    tv.set_roll = false;
 		tv.vector_yaw = map(x_analog, 1.0, -1.0, -180.0, 180.0);
 		tv.vector_x = (map(r_analog, 1.0, -1.0, 0.0, 100.0));   
 		std::cout << "Yaw: " << tv.vector_yaw << " X: " << tv.vector_x << std::endl;
		//Publish
		target_publisher.publish(tv);
	}
	
	else
	{
		//In here needs to send a message to deactivate manual controls
	}
}

void setStartPoint()
{
	 static tf::TransformListener listener; //FIXED: Added the listener
       try
       {
         //wp.lookupTransform("/imu", "/square_origin",  //this line does not compile. I dont know what is wrong
         //                         ros::Time(0), transform);
       	 //Rename wp to listener, and add listener as above
       	 
       	 //Lookup the IMU relative to the world and store it in origin_tf. This will act as our base point.
       	 listener.lookupTransform("/world", "/imu", ros::Time(0), origin_tf);
       	 
       	 state_selected = 3;	//now origin_tf has been saved start moving to the waypoints
       }
       
       catch (tf::TransformException ex)
       {
         ROS_ERROR("%s",ex.what());
       }
}

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy) {
	
  x_button = joy->buttons[2];		//X Button
  a_button = joy->buttons[0];   //A Button

	x_analog = joy->axes[0];
	l_analog = joy->axes[2];
	r_analog = joy->axes[5];
	
	if(x_button && (state_selected != 3))
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

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
