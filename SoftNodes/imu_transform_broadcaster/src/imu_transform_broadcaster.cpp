#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <std_msgs/Float32.h>
#include <custom_msg/IMUData.h>

std_msgs::Float32 z;      //Z axes storage

void depthCallBack(const std_msgs::Float32& depth) {
  z.data = 0; //Ignore this for now - it needs to be fixed
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
  
  /* Velocity and Position storage */
  static float vel_x = 0;
  static float vel_y = 0;
  
  static float pos_x = 0;
  static float pos_y = 0;
  
  /* TODO: Decouple gravity using YPR */
 
  /* Integrate velocities on x/y
   * TODO: X/Y Velocities should take YPR into account */
  vel_x += data.acc_x * dt;
  vel_y += data.acc_y * dt;
  
  /* Integrate position */
  pos_x += vel_x * dt;
  pos_y -= vel_y * dt;

  /* Set the imu's pose */
  imu_tr.setOrigin( tf::Vector3(pos_x, pos_y, 0.0) );
  imu_tr.setRotation( tf::createQuaternionFromRPY(0.0,0.0,-data.yaw*(M_PI/180)) ); //Removed pitch and roll for now

	/* Broadcast the imu position relative to the world */
  br.sendTransform(tf::StampedTransform(imu_tr, ros::Time::now(), "/world", "/imu"));
  
}

int main(int argc, char** argv){
  ros::init(argc, argv, "imu_transform_broadcaster");

  ros::NodeHandle n;

  ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
  ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);
  
  ros::spin();

  return 0;
};
