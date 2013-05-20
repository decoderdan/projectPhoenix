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
#include "../include/sonar_config/qnode.hpp"
#include <custom_msg/SonarConfig.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sonar_config {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"sonar_config");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	sonar_config_publisher = n.advertise<custom_msg::SonarConfig>("sonar_config", 1000);
	start();
	return true;
}

void QNode::run() {
//	ros::Rate loop_rate(1);
	while ( ros::ok() ) {
//		ros::spinOnce();
//		loop_rate.sleep();
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	emit rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::pubConfig(double threshold_val, double contrast_val, double gain_val, double resolution_val, double minDist_val, double maxDist_val, double leftLimit_val, double rightLimit_val, bool continuous_val, bool stare_val, int angularRes_val) {
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

	custom_msg::SonarConfig curConfig;
	curConfig.threshold = threshold_val;
	curConfig.contrast = contrast_val;
	curConfig.gain = gain_val;
	curConfig.resolution = resolution_val;
	curConfig.min_distance = minDist_val;
	curConfig.max_distance = maxDist_val;
	curConfig.left_limit = leftLimit_val;
	curConfig.right_limit = rightLimit_val;
	curConfig.continuous = continuous_val;
	curConfig.stare = stare_val;
	curConfig.angular_resolution = angularRes_val;

	sonar_config_publisher.publish(curConfig);
}



}  // namespace sonar_config
