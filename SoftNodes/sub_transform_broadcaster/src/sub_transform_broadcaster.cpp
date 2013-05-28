#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <std_msgs/Float32.h>
#include <custom_msg/IMUData.h>
//#include <custom_msg/MotorConfig.h>

static std_msgs::Float32 z;
//static float fr_rot, fl_rot, br_rot, bl_rot = 0;

void depthCallBack(const std_msgs::Float32& depth) {
	z.data = 0;//-(depth.data-10.0);
}

/*
void motorConfigCallBack(const custom_msg::MotorConfig& config)
{
	fr_rot = config.front_right;
	fl_rot = config.front_left;
	br_rot = config.back_right;
	bl_rot = config.back_left;
	return;
}*/

void imuCallBack(const custom_msg::IMUData& data) {
	static ros::Time last_time =  ros::Time::now();
	ros::Time current_time =  ros::Time::now();
	double dt = (current_time - last_time).toSec();
	last_time =  ros::Time::now();

float avg_x, avg_y = 0;
static double total_x, total_y = 0;
  static int count = 0;

  static tf::TransformBroadcaster br;
	//static float fr_roll, fl_roll, br_roll, bl_roll = 0;

	static float cur_x, cur_y;

  tf::Transform imu_tr;
  tf::Transform svp_tr;
  tf::Transform sonar_tr;
  //tf::Transform front_right_tr; //Front Right Motor
  //tf::Transform back_right_tr; //Back Right Motor
  //tf::Transform front_left_tr; //Front Left Motor
  //tf::Transform back_left_tr; //Back Left Motor

  /* Sonar transformation */
  sonar_tr.setOrigin(tf::Vector3(-0.12, -0.32, -0.30));
  sonar_tr.setRotation( tf::createQuaternionFromRPY(0,0,M_PI) );

  /* SVP transformation */
  float svp_distance_from_imu = -0.06;
  svp_tr.setOrigin(tf::Vector3(0.10, -0.15, svp_distance_from_imu));
  svp_tr.setRotation( tf::createQuaternionFromRPY(0,0,0) );

/* avg stuff */
count++;
total_x += data.acc_x;
total_y += data.acc_y;
avg_x = total_x/count;
avg_y = total_y/count;

  /* IMU transformation */
  static float vel_x = 0; 
  vel_x += (data.acc_x - avg_x) * dt;
  vel_x *= 0.97;

  static float vel_y = 0; 
  vel_y += (data.acc_y - avg_y) * dt;
  vel_y *= 0.97;

  static float imu_x = 0; imu_x += vel_x * dt;
  static float imu_y = 0; imu_y -= vel_y * dt;

	std::cout << imu_x << ", " << imu_y << std::endl;

  imu_tr.setOrigin( tf::Vector3(imu_x, imu_y, z.data-svp_distance_from_imu) );
  imu_tr.setRotation( tf::createQuaternionFromRPY(data.pitch*(M_PI/180), data.roll*(M_PI/180), -data.yaw*(M_PI/180)) );
  /* Motors */

/*front_right_tr.setOrigin( tf::Vector3(0.20, 0.15, -0.10) );
  front_right_tr.setRotation(  tf::createQuaternionFromRPY(0, fr_roll, M_PI/6) );
  front_left_tr.setOrigin( tf::Vector3(-0.20, 0.15, -0.10) );
  front_left_tr.setRotation(  tf::createQuaternionFromRPY(0, fl_roll, -M_PI/6) );
  back_right_tr.setOrigin( tf::Vector3(0.20, -0.40, -0.10) );
  back_right_tr.setRotation(  tf::createQuaternionFromRPY(0, br_roll, 5*M_PI/6) );
  back_left_tr.setOrigin( tf::Vector3(-0.20, -0.40, -0.10) );
  back_left_tr.setRotation(  tf::createQuaternionFromRPY(0, bl_roll, 7*M_PI/6) ); */
	
  /* Publish our transformations */
  //IMU relative to the world.
  br.sendTransform(tf::StampedTransform(imu_tr, ros::Time::now(), "/world", "/imu"));
  //SVP relative to IMU
  br.sendTransform(tf::StampedTransform(svp_tr, ros::Time::now(), "/imu", "/svp"));
  //SVP relative to the IMU
  br.sendTransform(tf::StampedTransform(sonar_tr, ros::Time::now(), "/imu", "/sonar"));
 //Thrusters relative to IMU
/*  br.sendTransform(tf::StampedTransform(front_right_tr, ros::Time::now(), "/imu", "/front_right_thruster"));
  br.sendTransform(tf::StampedTransform(front_left_tr, ros::Time::now(), "/imu", "/front_left_thruster"));
  br.sendTransform(tf::StampedTransform(back_right_tr, ros::Time::now(), "/imu", "/back_right_thruster"));
  br.sendTransform(tf::StampedTransform(back_left_tr, ros::Time::now(), "/imu", "/back_left_thruster"));*/
}

int main(int argc, char** argv){
  ros::init(argc, argv, "sub_transform_broadcaster");
  
  ros::NodeHandle n;
  
	ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
	ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);
	//ros::Subscriber motorSub = n.subscribe("motor_config", 100, motorConfigCallBack);
  
  ros::spin();
  
  /*while (ros::ok) {  
		ros::spinOnce(); //Call all waiting callbacks at this point
		r.sleep(); //Sleep for a little while
  }*/
  
  return 0;
};
