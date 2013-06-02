/**
 * @file /include/phoenix_gui/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef phoenix_gui_QNODE_HPP_
#define phoenix_gui_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include <std_msgs/Float32.h>
#include <custom_msg/IMUData.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace phoenix_gui {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();
	
	void emergencyStop();
	void resurface();
	
	void pubConfig_PID(double yawKp_val, double yawKi_val, double yawKd_val, double yawTarget_val, bool yawTarget_set, double pitchKp_val, double pitchKi_val, double pitchKd_val, double pitchTarget_val, bool pitchTarget_set, double depthKp_val, double depthKi_val, double depthKd_val, double depthTarget_val, bool depthTarget_set);
	void pubConfig_sonar(double threshold_val, double contrast_val, double gain_val, double resolution_val, double minDist_val, double maxDist_val, double leftLimit_val, double rightLimit_val, bool continuous_val, bool stare_val, int angularRes_val);
	
	void depthCallBack(const std_msgs::Float32& depth);
	void imuCallBack(const custom_msg::IMUData& data);
	
	void startCalibration();
	void pubEstVelocity(float dist);
	
signals:
	void rosShutdown();
	void noMaster();
	
	void yawActualUpdated(float);
	void pitchActualUpdated(float);
	void depthActualUpdated(float);

private:
	int init_argc;
	char** init_argv;
	
	ros::Publisher emergency_publisher;
	ros::Publisher pid_config_publisher;
	ros::Publisher target_publisher;
	ros::Publisher sonar_config_publisher;
	ros::Publisher dead_reckoning_vel_publisher;
	
	ros::Subscriber depthSub;
	ros::Subscriber imuSub;
};

}  // namespace phoenix_gui

#endif /* phoenix_gui_QNODE_HPP_ */
