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
#include <sstream>
#include "../include/phoenix_gui/qnode.hpp"
#include <custom_msg/PIDValues.h>
#include <custom_msg/TargetVector.h>
#include <custom_msg/SonarConfig.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <phonon/phonon>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace phoenix_gui {

// some globals for auto reconnect

std::string global_master_url;
std::string global_host_url;

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
	emergency_publisher = n.advertise<std_msgs::Bool>("emergency", 1000);
	pid_config_publisher = n.advertise<custom_msg::PIDValues>("pidGui", 1000);
	target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
	sonar_config_publisher = n.advertise<custom_msg::SonarConfig>("sonar_config", 1000);	
    dead_reckoning_vel_publisher = n.advertise<std_msgs::Float32>("estimated_velocity", 1000);

    systemBattSub = n.subscribe("batteryStatusSystem", 100, &QNode::systemBatteryCallBack, this);
    motorBattSub  = n.subscribe("batteryStatusMotor", 100, &QNode::motorBatteryCallBack, this);
	imuSub = n.subscribe("imu", 100, &QNode::imuCallBack, this);
   	depthSub = n.subscribe("depth", 100, &QNode::depthCallBack, this);
    rawImgSub = n.subscribe("raw_image", 10, &QNode::rawImgReceivedCallback, this);

	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;

	std::string ip = host_url.substr(11,1);
	int unique_num = std::atoi(ip.c_str());
	char unique_ident_char = 'a';
	unique_ident_char = unique_ident_char + unique_num;

	std::ostringstream ss;		// print the data
	ss << "phoenix_gui_" << unique_ident_char;

	std::cout << "unique_num = " << unique_num << ", unique_ident = " << unique_ident_char << ", " << ss.str() << std::endl;

	ros::init(remappings, ss.str());
	ros::master::setRetryTimeout(ros::WallDuration(10,0));
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;

	global_master_url = master_url;
	global_host_url = host_url;

	// Add your ros communications here.
    emergency_publisher = n.advertise<std_msgs::Bool>("emergency", 1000);
    pid_config_publisher = n.advertise<custom_msg::PIDValues>("pidGui", 1000);
    target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
    sonar_config_publisher = n.advertise<custom_msg::SonarConfig>("sonar_config", 1000);
    dead_reckoning_vel_publisher = n.advertise<std_msgs::Float32>("estimated_velocity", 1000);

    systemBattSub = n.subscribe("batteryStatusSystem", 100, &QNode::systemBatteryCallBack, this);
    motorBattSub  = n.subscribe("batteryStatusMotor", 100, &QNode::motorBatteryCallBack, this);
    imuSub = n.subscribe("imu", 100, &QNode::imuCallBack, this);
    depthSub = n.subscribe("depth", 100, &QNode::depthCallBack, this);
    rawImgSub = n.subscribe("raw_image", 10, &QNode::rawImgReceivedCallback, this);

	start();
	return true;
}

void QNode::run() {
	ros::Rate loop_rate(50);
	while ( ros::ok() ) {
		ros::spinOnce();
		loop_rate.sleep();
		if( ! ros::master::check()) {
			emit noMaster();
			init(global_master_url, global_host_url);
		}
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	emit rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::emergencyStop(bool stop){
	std_msgs::Bool emergency_stop;
	
	if(stop == true) {
		ROS_WARN("Emergency stop received from gui !!!");
		emergency_stop.data = true;
		emergency_publisher.publish(emergency_stop);
	} else if (stop == false) {
		ROS_WARN("Emergency stop reset received from gui !!!");
		emergency_stop.data = false;
		emergency_publisher.publish(emergency_stop);
	}
}

void QNode::resurface(){
	custom_msg::TargetVector tv;
	
	ROS_WARN("Resurface command received from gui !!!");
	
	// set only the z target
	tv.set_x = false;
	tv.set_y = false;
	tv.set_z = true;
	tv.set_yaw = false;
        tv.set_pitch = false;
        tv.set_roll = false;
	
	// set z (depth) to 0 meters
	tv.vector_z = 0;
	target_publisher.publish(tv);
	ROS_INFO("Target depth set to 0 meters");
}

void QNode::pubConfig_PID(double yawKp_val, double yawKi_val, double yawKd_val, double yawTarget_val, bool yawTarget_set, double pitchKp_val, double pitchKi_val, double pitchKd_val, double pitchTarget_val, bool pitchTarget_set, double depthKp_val, double depthKi_val, double depthKd_val, double depthTarget_val, bool depthTarget_set) {

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

	if(yawTarget_set) {
		curTargets.set_yaw = true;
	} else {
		curTargets.set_yaw = false;
	}
	if(pitchTarget_set) {
		curTargets.set_pitch = true;
	} else {
		curTargets.set_pitch = false;
	}
	if(depthTarget_set) {
		curTargets.set_z = true;
	} else {
		curTargets.set_z = false;
	}
	curTargets.set_roll = false;
	curTargets.set_x = false;
	curTargets.set_y = false;
		

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

void QNode::systemBatteryCallBack(const std_msgs::Float32& voltage) {
        emit systemBattUpdated(voltage.data);
}

void QNode::motorBatteryCallBack(const std_msgs::Float32& voltage) {
        emit motorBattUpdated(voltage.data);
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


/*****************************************************************************************************
**                                       Camera                                                      *
** http://rtabmap.googlecode.com/svn-history/r513/branches/audio/ros-pkg/rtabmap/src/ImageViewQt.cpp *
*****************************************************************************************************/

void QNode::rawImgReceivedCallback(const sensor_msgs::ImageConstPtr & img)
{
        if(img->data.size())
        {
                cv_bridge::CvImageConstPtr ptr = cv_bridge::toCvShare(img);

                //ROS_INFO("Received an image size=(%d,%d)", ptr->image.cols, ptr->image.rows);

  /*              if(imagesSaved)
                {
                        std::string path = "./imagesSaved";
                        if(!UDirectory::exists(path))
                        {
                                if(!UDirectory::makeDir(path))
                                {
                                        ROS_ERROR("Cannot make dir %s", path.c_str());
                                }
                        }
                        path.append("/");
                        path.append(uNumber2Str(i++));
                        path.append(".bmp");
                        if(!cv::imwrite(path.c_str(), ptr->image))
                        {
                                ROS_ERROR("Cannot save image to %s", path.c_str());
                        }
                        else
                        {
                                ROS_INFO("Saved image %s", path.c_str());
                        }
                }
                else if(view && view->isVisible())
                {
                        view->setPixmap(QPixmap::fromImage(cvtCvMat2QImage(ptr->image)));
                }

*/
                emit rawImageUpdated(QPixmap::fromImage(cvtCvMat2QImage(ptr->image)));
        }
}

QImage QNode::cvtCvMat2QImage(const cv::Mat & image)
{
        QImage qtemp;
        if(!image.empty() && image.depth() == CV_8U)
        {
                const unsigned char * data = image.data;
                qtemp = QImage(image.cols, image.rows, QImage::Format_RGB32);
                for(int y = 0; y < image.rows; ++y, data += image.cols*image.elemSize())
                {
                        for(int x = 0; x < image.cols; ++x)
                        {
                                QRgb * p = ((QRgb*)qtemp.scanLine (y)) + x;
                                *p = qRgb(data[x * image.channels()+2], data[x * image.channels()+1], data[x * image.channels()]);
                        }
                }
        }
        else if(!image.empty() && image.depth() != CV_8U)
        {
                printf("Wrong image format, must be 8_bits\n");
        }
        return qtemp;
}

}  // namespace phoenix_gui
