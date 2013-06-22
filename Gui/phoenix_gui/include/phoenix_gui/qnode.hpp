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
#include <std_msgs/Int8.h>
#include <std_msgs/String.h>
#include "std_msgs/Bool.h"
#include <custom_msg/IMUData.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

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
	
        QImage cvtCvMat2QImage(const cv::Mat & image);

	void emergencyStop(bool stop);
	void resurface();
	
	void pubConfig_PID(double yawKp_val, double yawKi_val, double yawKd_val, double yawTarget_val, bool yawTarget_set, double pitchKp_val, double pitchKi_val, double pitchKd_val, double pitchTarget_val, bool pitchTarget_set, double depthKp_val, double depthKi_val, double depthKd_val, double depthTarget_val, bool depthTarget_set);
	void pubConfig_sonar(double threshold_val, double contrast_val, double gain_val, double resolution_val, double minDist_val, double maxDist_val, double leftLimit_val, double rightLimit_val, bool continuous_val, bool stare_val, int angularRes_val);
	
    void motorBatteryCallBack(const std_msgs::Float32& voltage);
    void systemBatteryCallBack(const std_msgs::Float32& voltage);
	void depthCallBack(const std_msgs::Float32& depth);
	void imuCallBack(const custom_msg::IMUData& data);
    void rawImgReceivedCallback(const sensor_msgs::ImageConstPtr & img);

	void startCalibration();
	void pubEstVelocity(float dist);
	
signals:
	void rosShutdown();
	void noMaster();
	
    void motorBattUpdated(float);
    void systemBattUpdated(float);
	void yawActualUpdated(float);
	void pitchActualUpdated(float);
	void depthActualUpdated(float);

    void rawImageUpdated(QPixmap);

private:
	int init_argc;
	char** init_argv;
	
	ros::Publisher emergency_publisher;
	ros::Publisher pid_config_publisher;
	ros::Publisher target_publisher;
	ros::Publisher sonar_config_publisher;
	ros::Publisher dead_reckoning_vel_publisher;

        ros::Subscriber systemBattSub;
        ros::Subscriber motorBattSub;
	ros::Subscriber depthSub;
	ros::Subscriber imuSub;
        ros::Subscriber rawImgSub;

};

}  // namespace phoenix_gui

#endif /* phoenix_gui_QNODE_HPP_ */
