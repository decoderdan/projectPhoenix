#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <std_msgs/Float32.h>
#include <custom_msg/IMUData.h>

float z;      //Z axes storage

void depthCallBack(const std_msgs::Float32& depth) {
  z = depth.data; //depth data onto z
}

void imuCallBack(const custom_msg::IMUData& data) {

  /* Get the time since the last imu call back (determine dt) */
  static ros::Time last_time =  ros::Time::now();
  ros::Time current_time =  ros::Time::now();
  double dt = (current_time - last_time).toSec();
  last_time =  ros::Time::now(); //Store for next time

  /* Create a transform broadcaster */
  static tf::TransformBroadcaster br;
  
  /* Transformation declarations */
  tf::Transform imu_tr;
  tf::Transform sonar_tr;

  /* For integration - 
	dt( (pev_x_val + new_x_val) / 2 )  */
  static float prev_x_val = 0;
  static float prev_y_val = 0;
  static float prev_vel_x = 0;
  static float prev_vel_y = 0;

  /* Velocity and Position storage */
  static float vel_x = 0;
  static float vel_y = 0;
  static float pos_x = 0;
  static float pos_y = 0;
  
  /* TODO: Decouple gravity using YPR */
 
  /* Integrate velocities on x/y
   * TODO: X/Y Velocities should take YPR into account */
  //vel_x += data.acc_x * dt;
  //vel_y += data.acc_y * dt;
  vel_x += ((prev_x_val + data.acc_x) /2 ) * dt;
  vel_y += ((prev_y_val + data.acc_y) /2 ) * dt;

  /* Integrate position */
  //pos_x += vel_x * dt;
  //pos_y -= vel_y * dt;
  pos_x += ((prev_vel_x * vel_x) /2) * dt;
  pos_y -= ((prev_vel_y * vel_y) /2) * dt;

  /*set prev values for integration*/
  prev_x_val = data.acc_x;
  prev_x_val = data.acc_y;
  prev_vel_x = vel_x;
  prev_vel_y = vel_y;

  /* Set the imu's pose */
  imu_tr.setOrigin( tf::Vector3(0.0, 0.0, -z) );
  imu_tr.setRotation( tf::createQuaternionFromRPY(data.pitch*(M_PI/180),data.roll*(M_PI/180),-data.yaw*(M_PI/180)) ); 

	/* Broadcast the imu position relative to the world */
  br.sendTransform(tf::StampedTransform(imu_tr, ros::Time::now(), "/world", "/imu"));

  /* Set the sonar relative to imu pose */
  sonar_tr.setOrigin( tf::Vector3(0.0, 0.5, -0.3) );
  sonar_tr.setRotation( tf::createQuaternionFromRPY(0,0,0) ); 

	/* Broadcast the sonar position relative to the imu*/
  br.sendTransform(tf::StampedTransform(sonar_tr, ros::Time::now(), "/imu", "/base_laser"));
  
}

int main(int argc, char** argv){
  ros::init(argc, argv, "imu_transform_broadcaster");

  ros::NodeHandle n;

  ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
  ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);
  
  ros::spin();

  return 0;
};
