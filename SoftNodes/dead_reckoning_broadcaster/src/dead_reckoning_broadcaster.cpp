#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <std_msgs/Float32.h>
#include <custom_msg/IMUData.h>
#include <custom_msg/MotorConfig.h>
#include <custom_msg/TargetVector.h>

std_msgs::Float32 z;      //Z axes storage
bool first_run = true;    //Is this the first time the callback has run?
bool motors_on_x = false; //Are the motors moving the sub forward? (X Axes)
bool motors_on_y = false; //Are the motors strafing the sub? (Y Axes)
double est_vel_x = 1.0;   // ?!? 1.0 what ?
float vector_x;

void depthCallBack(const std_msgs::Float32& depth) {
  z.data = 0; //Ignore this for now - it needs to be fixed
}

void vectorCallBack(const custom_msg::TargetVector& vector)
{
  vector_x = vector.vector_x;  //Just save the last target vector.x to a global vector_x for use elsewhere
  ROS_INFO("Got new x vector %f", vector_x);
}

void motorConfigCallBack(const custom_msg::MotorConfig& config)
{

  /* determine at what axes we should be moving in.
     Moving forward = x axes
     Sidewards (Strafing) = y axes

     This will change with the new configuration */

  motors_on_x = ((config.front_right == (-config.back_right)) && (config.front_left == (-config.back_left)));
  motors_on_y = ((config.front_right == (-config.front_left)) && (config.back_right == (-config.back_left)));
  
  
  /*************************************
  **  ADD THE thruster tf calcs here ??
  *************************************/
  
  return;
}

void imuCallBack(const custom_msg::IMUData& data) {

  /* Store last roll pitch and yaw */
  static float last_y = 0;
  static float last_r = 0;
  static float last_p = 0;

  /* Get the time since the last imu call back (determine dt) */
  static ros::Time last_time =  ros::Time::now();
  ros::Time current_time =  ros::Time::now();
  double dt = (current_time - last_time).toSec();
  last_time =  ros::Time::now(); //Store for next time

  /* Create a transform broadcaster and listener */
  static tf::TransformBroadcaster br;
  
  /* Here are our minimal transforms. IMU */
  tf::Transform imu_tr;
  
  static float pos_x = 0;
  static float pos_y = 0;
  
/** only track the position in x if vector_x != 0 **/

  if (vector_x != 0) {
  	/* integrate position */
  	float new_y = est_vel_x * dt * sin((-data.yaw) * (M_PI/180.0));
    float new_x = est_vel_x * dt * cos((-data.yaw) * (M_PI/180.0));
    
    pos_x += new_x;
    pos_y += new_y;
  	//pos_x += est_vel_x *dt;
  }
  	 
  /* Set the imu's pose */
  imu_tr.setOrigin( tf::Vector3(pos_x, pos_y, 0.0) );
  imu_tr.setRotation( tf::createQuaternionFromRPY(0.0,0.0,-data.yaw*(M_PI/180)) ); //Removed pitch and roll for now

	/* Broadcast the imu position relative to the world */
  br.sendTransform(tf::StampedTransform(imu_tr, ros::Time::now(), "/world", "/imu"));

	/* Store the current pitch roll and yaw for next time */
	last_y = data.yaw;
	last_p = data.pitch;
	last_r = data.roll;

  /* Publish our other transformations */
  /* SVP relative to IMU */
  //br.sendTransform(tf::StampedTransform(svp_tr, ros::Time::now(), "/imu", "/svp"));
  /* Sonar relative to the IMU */
  //br.sendTransform(tf::StampedTransform(sonar_tr, ros::Time::now(), "/imu", "/sonar"));
}

int main(int argc, char** argv){
  ros::init(argc, argv, "dead_reckoning_broadcaster");

  ros::NodeHandle n;

  ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
  ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);
  ros::Subscriber motorSub = n.subscribe("motor_config", 100, motorConfigCallBack);
  ros::Subscriber vectorSub = n.subscribe("vector", 100, vectorCallBack);
  

  ros::spin();

  return 0;
};
