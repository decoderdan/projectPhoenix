/**
 * @file /src/qnode.brief
 *
 * @cpp Ros communication central!
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
#include "../include/pid_config/qnode.hpp"
#include <custom_msg/PIDValues.h>
#include <custom_msg/TargetVector.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace pid_config {

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
	ros::init(init_argc,init_argv,"pid_config");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	pid_config_publisher = n.advertise<custom_msg::PIDValues>("pidGui", 1000);
	target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);

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

void QNode::pubConfig_PID(double yawKp_val, double yawKi_val, double yawKd_val, double yawTarget_val, double pitchKp_val, double pitchKi_val, double pitchKd_val, double pitchTarget_val, double depthKp_val, double depthKi_val, double depthKd_val, double depthTarget_val) {

	custom_msg::PIDValues curConfig;
	custom_msg::TargetVector curTargets;	

	curConfig.yaw_Kp = yawKp_val;
	curConfig.yaw_Ki = yawKi_val;
	curConfig.yaw_Kd = yawKd_val;
	curConfig.pitch_Kp = pitchKp_val;
	curConfig.pitch_Ki = pitchKi_val;
	curConfig.pitch_Kd = pitchKd_val;
	curConfig.depth_Kp = depthKp_val;
	curConfig.depth_Ki = depthKi_val;
	curConfig.depth_Kd = depthKd_val;

	curTargets.vector_yaw = yawTarget_val;
	curTargets.vector_pitch = pitchTarget_val;
	curTargets.vector_z = depthTarget_val;

	pid_config_publisher.publish(curConfig);
	target_publisher.publish(curTargets);


}

}  // namespace pid_config
