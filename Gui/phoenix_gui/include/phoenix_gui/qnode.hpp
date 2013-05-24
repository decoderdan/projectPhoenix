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
	void pubConfig_PID(double yawKp_val, double yawKi_val, double yawKd_val, double yawTarget_val, double pitchKp_val, double pitchKi_val, double pitchKd_val, double pitchTarget_val, double depthKp_val, double depthKi_val, double depthKd_val, double depthTarget_val);
	void pubConfig_sonar(double threshold_val, double contrast_val, double gain_val, double resolution_val, double minDist_val, double maxDist_val, double leftLimit_val, double rightLimit_val, bool continuous_val, bool stare_val, int angularRes_val);


signals:
	void rosShutdown();
	void noMaster();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher pid_config_publisher;
	ros::Publisher target_publisher;
	ros::Publisher sonar_config_publisher;
};

}  // namespace phoenix_gui

#endif /* phoenix_gui_QNODE_HPP_ */
