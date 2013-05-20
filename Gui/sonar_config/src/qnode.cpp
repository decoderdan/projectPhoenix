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
	sonar_config_publisher = n.advertise<std_msgs::String>("sonar_config", 1000);
	start();
	return true;
}

void QNode::run() {
	ros::Rate loop_rate(1);
	while ( ros::ok() ) {
//		ros::spinOnce();
//		loop_rate.sleep();
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	emit rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::pubConfig(double threshold_val, double contrast_val, double gain_val, double resolution_val, double minDist_val, double maxDist_val, double leftLimit_val, double rightLimit_val, int angularRes_val) {
		std_msgs::String msg;
		std::stringstream ss;
		ss << "sonar_config: " << std::endl 
			<< "threshold: " << threshold_val << std::endl 
			<< "contrast: " << contrast_val << std::endl 
			<< "gain: " << gain_val << std::endl 
			<< "resolution: " << resolution_val << std::endl 
			<< "minDist: " << minDist_val << std::endl 
			<< "maxDist: " << maxDist_val << std::endl 
			<< "leftLimit: " << leftLimit_val << std::endl 
			<< "rightLimit: " << rightLimit_val << std::endl 
			<< "angularRes: " << angularRes_val << std::endl;
		msg.data = ss.str();
		sonar_config_publisher.publish(msg);
}



}  // namespace sonar_config
