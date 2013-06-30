#include "ros/ros.h"
#include <sstream>
#include "std_msgs/UInt8.h"
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <custom_msg/TargetVector.h>
#include <sensor_msgs/Joy.h>

void broadcastWPs();
void manualControl();
void setStartPoint();
void joyCallback(const sensor_msgs::Joy::ConstPtr&);

int state_selected = 1;
int x_button = 0;
int a_button = 0;
int x_plus_axis = 5;
int x_minus_axis = 2;
int yaw_axis = 3;
int curwp = 0;

float x_val = 0;
float yaw_val = 0;
float output_yaw = 0;

tf::StampedTransform origin_tf; //Stores our origin tf
ros::Publisher target_publisher;

float constrain(float x, float min, float max)
{
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "mission_control");
  ros::NodeHandle n;

  /* Subscribe to joystick */
  ros::Subscriber joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, joyCallback);
  target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);

  ros::Rate rate(50.0);

  ROS_INFO("Mission Control Node Started - Subscribed to joystick");

	while (ros::ok()) 
	{
	  switch(state_selected)
	  {
	  	case 1 :   manualControl();
	  		   break;
	  		   
	  	case 2 :   setStartPoint();
	  		   break;
	  		   
	  	case 3 :   broadcastWPs(); 
	  		   break;
	  }
	  
	  ros::spinOnce(); //Allow joystick callback
	  rate.sleep();
	}
  return 0;
}

void broadcastWPs()
{
  static tf::TransformBroadcaster broadcaster;
	std::ostringstream oss;

	std::cout << "broadcast the waypoints for a square" << std::endl;

	//First, broadcast our final destination relative to the world (This is our current position)
	broadcaster.sendTransform( tf::StampedTransform( origin_tf, ros::Time::now(), "/world", "/square_origin" ));

	//Now post the rest of the way points
	tf::Transform wp;

	wp.setOrigin( tf::Vector3(5.0, 0.0, 0.0) );
	wp.setRotation( tf::createQuaternionFromRPY(0.0, 0.0, 0.0) );
	oss << "/wp" << ((curwp * 4) + 1);
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", oss.str() ));
	oss.str("");
	oss.clear();

	wp.setOrigin( tf::Vector3(5.0, -5.0, 0.0) );
	oss << "/wp" << ((curwp * 4) + 2);
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", oss.str() ));
	oss.str("");
	oss.clear();

	wp.setOrigin( tf::Vector3(0.0, -5.0, 0.0) );
	oss << "/wp" << ((curwp * 4) + 3);
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", oss.str() ));
	oss.str("");
	oss.clear();

	wp.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
	oss << "/wp" << ((curwp * 4) + 4);
	broadcaster.sendTransform( tf::StampedTransform( wp, ros::Time::now(), "/square_origin", oss.str() ));
}

void manualControl()
{
	output_yaw += yaw_val;
	//In here needs to send a message to activate manual controls
	custom_msg::TargetVector tv;
	tv.set_y = false;
	tv.set_z = false;
	tv.set_pitch = false;
	tv.set_roll = false;
	tv.set_x = true;
	tv.set_yaw = true;
	tv.vector_x = x_val;
	while (output_yaw > 180) output_yaw -= 360;	
	while (output_yaw < -180) output_yaw += 360;
	tv.vector_yaw = output_yaw;
	target_publisher.publish(tv);	
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
	
  x_button = joy->buttons[2];	//X Button
  a_button = joy->buttons[0];   //A Button

  x_val = ((map(joy->axes[x_plus_axis], 1.0, -1.0, 0.0, 50.0)) - (map(joy->axes[x_minus_axis], 1.0, -1.0, 0.0, 50.0)));
  yaw_val = -(2 * joy->axes[yaw_axis]);//(map(joy->axes[yaw_axis], 1.0, -1.0, -1.0, 1.0));

  //ROS_INFO("X Val: %f, Yaw: %f", x_val, yaw_val);

	if(x_button && (state_selected != 3))
	{
		curwp++;
		ROS_INFO("The sub is moving in a square [%d]", x_button);
		state_selected = 2;	//first set origin waypoint then move in a square
	}

	if(a_button)
	{
		ROS_INFO("The sub is manually controlled [%d]", x_button);
		state_selected = 1;
	}
}
