#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <std_msgs/Float32.h>
#include <custom_msg/IMUData.h>
#include <custom_msg/MotorConfig.h>

static std_msgs::Float32 z;
static float fr_rot = 0;

void depthCallBack(const std_msgs::Float32& depth) {
	z.data = -(depth.data-10.0);
}

void motorConfigCallBack(const custom_msg::MotorConfig& config)
{
	fr_rot = config.front_right;
	return;
}

void imuCallBack(const custom_msg::IMUData& data) {
  ROS_INFO("Got IMU Message");
  
  static tf::TransformBroadcaster br;
  static float imu_x, imu_y;
	static float fr_roll;
	
  tf::Transform imu_tr;
  tf::Transform front_right_tr; //Front Right Motor
  tf::Transform back_right_tr; //Back Right Motor
  tf::Transform front_left_tr; //Front Left Motor
  tf::Transform back_left_tr; //Back Left Motor
  
  imu_x += (1.0/50.0)*(data.vel_x+data.acc_x);
  imu_y += (1.0/50.0)*(data.vel_y+data.acc_y);
	
	//imu_tr.setOrigin( tf::Vector3(0.1,0.5,0) );
	//imu_tr.setRotation( tf::createQuaternionFromRPY(0,0,0) );
	
	imu_tr.setOrigin( tf::Vector3(imu_x, imu_y, z.data) );
	imu_tr.setRotation( tf::createQuaternionFromRPY(data.roll*(M_PI/180), data.pitch*(M_PI/180), data.yaw*(M_PI/180)) );
	
	/* Configure the front right motor transform */
	front_right_tr.setOrigin( tf::Vector3(0.20, 0.10, -0.20) );
	fr_roll+=(fr_rot/100);
	front_right_tr.setRotation(  tf::createQuaternionFromRPY(fr_roll, 0, 0) );
	/* Configure the back right motor transform */
	back_right_tr.setOrigin( tf::Vector3(0.20, -0.40, -0.20) );
	back_right_tr.setRotation(  tf::createQuaternionFromRPY(0, 0, 0) );
	/* Configure the front left motor transform */
	front_left_tr.setOrigin( tf::Vector3(-0.20, 0.10, -0.20) );
	front_left_tr.setRotation(  tf::createQuaternionFromRPY(0, 0, 0) );
	/* Configure the back left motor transform */
	back_left_tr.setOrigin( tf::Vector3(-0.20, -0.40, -0.20) );
	back_left_tr.setRotation(  tf::createQuaternionFromRPY(0, 0, 0) );
	
	//IMU relative to the world.
	br.sendTransform(tf::StampedTransform(imu_tr, ros::Time::now(), "/world", "/imu"));
	br.sendTransform(tf::StampedTransform(front_right_tr, ros::Time::now(), "/imu", "/front_right_thruster"));
	br.sendTransform(tf::StampedTransform(back_right_tr, ros::Time::now(), "/imu", "/back_right_thruster"));
	br.sendTransform(tf::StampedTransform(front_left_tr, ros::Time::now(), "/imu", "/front_left_thruster"));
	br.sendTransform(tf::StampedTransform(back_left_tr, ros::Time::now(), "/imu", "/back_left_thruster"));
}

int main(int argc, char** argv){
  ros::init(argc, argv, "sub_transform_broadcaster");
  
  ros::NodeHandle n;
  
	ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
	ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);
	ros::Subscriber motorSub = n.subscribe("motor_config", 100, motorConfigCallBack);
  
  ros::spin();
  
  /*while (ros::ok) {  
		ros::spinOnce(); //Call all waiting callbacks at this point
		r.sleep(); //Sleep for a little while
  }*/
  
  return 0;
};
