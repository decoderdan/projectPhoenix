/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/phoenix_gui/qnode.hpp"
#include <custom_msg/PIDValues.h>
#include <custom_msg/TargetVector.h>
#include <custom_msg/SonarConfig.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace phoenix_gui {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
	std::cout << "Gui closed!" << std::endl;
	if(ros::isStarted()) {
	ros::shutdown(); // explicitly needed since we use ros::start();
	ros::waitForShutdown();
	}
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"phoenix_gui");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::master::setRetryTimeout(ros::WallDuration(10,0));
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	pid_config_publisher = n.advertise<custom_msg::PIDValues>("pidGui", 1000);
	target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
	sonar_config_publisher = n.advertise<custom_msg::SonarConfig>("sonar_config", 1000);	
	dead_reckoning_vel_publisher = n.advertise<std_msgs::Float32>("estimated_velocity", 1000);
	target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
	
	imuSub = n.subscribe("imu", 100, &QNode::imuCallBack, this);
   	depthSub = n.subscribe("depth", 100, &QNode::depthCallBack, this);
   	
	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"phoenix_gui");
	ros::master::setRetryTimeout(ros::WallDuration(10,0));
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	pid_config_publisher = n.advertise<custom_msg::PIDValues>("pidGui", 1000);
	target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
	sonar_config_publisher = n.advertise<custom_msg::SonarConfig>("sonar_config", 1000);
	dead_reckoning_vel_publisher = n.advertise<std_msgs::Float32>("estimated_velocity", 1000);
	target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
	

	imuSub = n.subscribe("imu", 100, &QNode::imuCallBack, this);
   	depthSub = n.subscribe("depth", 100, &QNode::depthCallBack, this);

	start();
	return true;
}

void QNode::run() {
	ros::Rate loop_rate(50);
	while ( ros::ok() ) {
		ros::spinOnce();
		loop_rate.sleep();
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	emit rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::emergencyStop(){
	std::cout << "Emergency stop received from gui !!!" << std::endl;
	
}

void QNode::resurface(){
	std::cout << "Resurface command received from gui !!!" << std::endl;
	
}

void QNode::pubConfig_PID(double yawKp_val, double yawKi_val, double yawKd_val, double yawTarget_val, double pitchKp_val, double pitchKi_val, double pitchKd_val, double pitchTarget_val, double depthKp_val, double depthKi_val, double depthKd_val, double depthTarget_val) {

	custom_msg::PIDValues curPIDConfig;
	custom_msg::TargetVector curTargets;	

	curPIDConfig.yaw_Kp = yawKp_val;
	curPIDConfig.yaw_Ki = yawKi_val;
	curPIDConfig.yaw_Kd = yawKd_val;
	curPIDConfig.pitch_Kp = pitchKp_val;
	curPIDConfig.pitch_Ki = pitchKi_val;
	curPIDConfig.pitch_Kd = pitchKd_val;
	curPIDConfig.depth_Kp = depthKp_val;
	curPIDConfig.depth_Ki = depthKi_val;
	curPIDConfig.depth_Kd = depthKd_val;

	curTargets.vector_yaw = yawTarget_val;
	curTargets.vector_pitch = pitchTarget_val;
	curTargets.vector_z = depthTarget_val;

	curTargets.set_yaw = true;
	curTargets.set_pitch = true;
	curTargets.set_roll = false;
	curTargets.set_x = false;
	curTargets.set_y = false;
	curTargets.set_z = true;

	pid_config_publisher.publish(curPIDConfig);
	target_publisher.publish(curTargets);

}

void QNode::pubConfig_sonar(double threshold_val, double contrast_val, double gain_val, double resolution_val, double minDist_val, double maxDist_val, double leftLimit_val, double rightLimit_val, bool continuous_val, bool stare_val, int angularRes_val) {
/*		std_msgs::String msg;
		std::stringstream ss;
		ss << "sonar_config: " << std::endl 
			<< "threshold: " << threshold_val << std::endl 
			<< "contrast: " << contrast_val << std::endl 
			<< "gain: " << gain_val << std::endl 
			<< "resolution: " << resolution_val << std::endl 
			<< "minDist: " << minDist_val << std::endl 
			<< "maxDist: " << maxDist_val << std::endl 
			<< "leftLimit: " << leftLimit_val << std::endl		  // ?!? add continuous default = true , stare = default false
			<< "rightLimit: " << rightLimit_val << std::endl 	
			<< "angularRes: " << angularRes_val << std::endl;
		msg.data = ss.str();
*/

	custom_msg::SonarConfig curSonarConfig;
	curSonarConfig.threshold = threshold_val;
	curSonarConfig.contrast = contrast_val;
	curSonarConfig.gain = gain_val;
	curSonarConfig.resolution = resolution_val;
	curSonarConfig.min_distance = minDist_val;
	curSonarConfig.max_distance = maxDist_val;
	curSonarConfig.left_limit = leftLimit_val;
	curSonarConfig.right_limit = rightLimit_val;
	curSonarConfig.continuous = continuous_val;
	curSonarConfig.stare = stare_val;
	curSonarConfig.angular_resolution = angularRes_val;

	sonar_config_publisher.publish(curSonarConfig);
}

void QNode::depthCallBack(const std_msgs::Float32& depth) {
	std_msgs::Float32 z;
   //     z.data = -(depth.data-10.0);
	emit depthActualUpdated((float)depth.data);
}


void QNode::imuCallBack(const custom_msg::IMUData& data) {
	std::cout << "imu callback" << std::endl;
	
        float yaw_input = data.yaw;
        
        std::cout << "yaw = " << yaw_input << std::endl;
        
        float pitch_input = data.pitch;
        
        std::cout << "pitch = " << pitch_input << std::endl;
        
        emit yawActualUpdated(yaw_input);
        emit pitchActualUpdated(pitch_input);
}

/********************************************
**		Dead reckoning              *
********************************************/

void QNode::startCalibration() {
	// std::cout << "stating the 5 second velocity calibration run" << std::endl;
	ROS_INFO("Starting the 5 second velocity calibration run");
	custom_msg::TargetVector tv;
	
	// set only the x target
	tv.set_x = true;
	tv.set_y = false;
	tv.set_z = false;
	tv.set_yaw = false;
        tv.set_pitch = false;
        tv.set_roll = false;
	
	// send a forward 20% command
	tv.vector_x = 20; //20% speed
	target_publisher.publish(tv);
	ROS_INFO("Motors to 20");
	
	// wait 5 seconds
	ros::Time start_time = ros::Time::now();
	while(ros::Time::now().toSec() < (start_time.toSec() + 5.00)) {}
	

	// send a stop command
	tv.vector_x = 0; //0% speed
	target_publisher.publish(tv);
	ROS_INFO("Motors to 0");
}

void QNode::pubEstVelocity(float vel) {

    std_msgs::Float32 velocity;
        
    velocity.data = vel;

    dead_reckoning_vel_publisher.publish(velocity);
}

}  // namespace phoenix_gui
