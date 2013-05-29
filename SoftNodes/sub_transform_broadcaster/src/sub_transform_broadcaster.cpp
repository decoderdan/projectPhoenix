#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <std_msgs/Float32.h>
#include <custom_msg/IMUData.h>
#include <custom_msg/MotorConfig.h>

std_msgs::Float32 z;      //Z axes storage
bool first_run = true;    //Is this the first time the callback has run?
bool motors_on_x = false; //Are the motors moving the sub forward? (X Axes)
bool motors_on_y = false; //Are the motors strafing the sub? (Y Axes)

void depthCallBack(const std_msgs::Float32& depth) {
  z.data = 0; //Ignore this for now - it needs to be fixed
}


void motorConfigCallBack(const custom_msg::MotorConfig& config)
{

	/* determine at what axes we should be moving in.
	   Moving forward = x axes
	   Sidewards (Strafing) = y axes
	   
	   This will change with the new configuration */

	motors_on_x = ((config.front_right == (-config.back_right)) && (config.front_left == (-config.back_left)));
	motors_on_y = ((config.front_right == (-config.front_left)) && (config.back_right == (-config.back_left)));
	return;
}

void imuCallBack(const custom_msg::IMUData& data) {

	/* Store last roll pitch and yaw */
	static float last_y = 0;
	static float last_r = 0;
	static float last_p = 0;

	/* Integrated velocity storage */
  static float vel_x = 0;
  static float vel_y = 0;

	/* Get the time since the last imu call back (determine dt) */
  static ros::Time last_time =  ros::Time::now();
  ros::Time current_time =  ros::Time::now();
  double dt = (current_time - last_time).toSec();
  last_time =  ros::Time::now(); //Store for next time

	/* Create a transform broadcaster and listener */
  static tf::TransformBroadcaster br;
  static tf::TransformListener listener;

	/* Here are our minimal transforms. IMU, SVP and Sonar */
  tf::Transform imu_tr;
  tf::Transform svp_tr;
  tf::Transform sonar_tr;

  /* Sonar transformation */
  sonar_tr.setOrigin(tf::Vector3(-0.32, 0.12, -0.30));
  sonar_tr.setRotation( tf::createQuaternionFromRPY(0,0,M_PI) );

  /* SVP transformation */
  float svp_distance_from_imu = -0.06;
  svp_tr.setOrigin(tf::Vector3(0.0, -0.10, svp_distance_from_imu));
  svp_tr.setRotation( tf::createQuaternionFromRPY(0,0,0) );

	/* Integrate velocities on x/y */ 
  vel_x += data.acc_x * dt;
  vel_y += data.acc_y * dt;

	/* Attenuate if we're not supposed to be moving */  
  if (!motors_on_x) vel_x *= 0.95;
	if (!motors_on_y) vel_y *= 0.95;
	
  if (first_run) {
    /* If it's the first run, set the imu's initial pose by integrating velocity */
    /* Note: use -y value since the y on the imu is inverted (I think) */
    imu_tr.setOrigin( tf::Vector3(vel_x*dt, -vel_y*dt, 0.0) );
    imu_tr.setRotation( tf::createQuaternionFromRPY(0.0,0.0, -data.yaw*(M_PI/180)) ); //Removed pitch and roll for now

		/* Broadcast the imu position relative to the world */
    br.sendTransform(tf::StampedTransform(imu_tr, ros::Time::now(), "/world", "/imu"));
    
    first_run = false; //First run is over!
  }
  else {
    /* This is not the first run. Use the imu's previous pose */
    tf::StampedTransform last_imu;
 
    try {
    	/* Grab the last transform for the imu relative to the world */
      listener.lookupTransform("/world", "/imu", ros::Time(0), last_imu);
      
      /* Set the imu relative to the last imu by integrating velocity */
      /* Note: use -y value since the y on the imu is inverted (I think) */
      imu_tr.setOrigin( tf::Vector3(vel_x*dt, -vel_y*dt, 0.0) );
      
      /* Work out the yaw based on the difference between the last yaw and the current yaw */
      imu_tr.setRotation( tf::createQuaternionFromRPY(0.0,0.0, (-data.yaw*(M_PI/180))-(-last_y*(M_PI/180))));

			/* Broadcast the old tf under a different name, and the new tf relative to the old one */
      br.sendTransform(tf::StampedTransform(last_imu, ros::Time::now(), "/world", "/l_imu"));
      br.sendTransform(tf::StampedTransform(imu_tr, ros::Time::now(), "/l_imu", "/imu"));
    }
    catch (tf::TransformException ex) {
      ROS_ERROR("%s",ex.what()); //Log the error
    }
  }

	/* Store the current pitch roll and yaw for next time */
	last_y = data.yaw;
	last_p = data.pitch;
	last_r = data.roll;

  /* Publish our other transformations */
  /* SVP relative to IMU */
  br.sendTransform(tf::StampedTransform(svp_tr, ros::Time::now(), "/imu", "/svp"));
  /* Sonar relative to the IMU */
  br.sendTransform(tf::StampedTransform(sonar_tr, ros::Time::now(), "/imu", "/sonar"));
}

int main(int argc, char** argv){
  ros::init(argc, argv, "sub_transform_broadcaster");

  ros::NodeHandle n;

  ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
  ros::Subscriber depthSub = n.subscribe("depth", 100, depthCallBack);
  ros::Subscriber motorSub = n.subscribe("motor_config", 100, motorConfigCallBack);

  ros::spin();

  return 0;
};
