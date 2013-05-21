/**
 * @file /include/pid_config/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef pid_config_QNODE_HPP_
#define pid_config_QNODE_HPP_

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

namespace pid_config {

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
	void pubConfig(double yawKp_val, double yawKi_val, double yawKd_val, double yawTarget_val, double pitchKp_val, double pitchKi_val, double pitchKd_val, double pitchTarget_val, double depthKp_val, double depthKi_val, double depthKd_val, double depthTarget_val);

	
signals:
	void rosShutdown();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher pid_config_publisher;
	ros::Publisher target_publisher;
};

}  // namespace pid_config

#endif /* pid_config_QNODE_HPP_ */
