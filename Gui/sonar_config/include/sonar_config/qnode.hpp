/**
 * @file /include/sonar_config/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef sonar_config_QNODE_HPP_
#define sonar_config_QNODE_HPP_

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

namespace sonar_config {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	void run();
	void pubConfig(double threshold_val, double contrast_val, double gain_val, double resolution_val, double minDist_val, double maxDist_val, double leftLimit_val, double rightLimit_val, int angularRes_val);

signals:
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher sonar_config_publisher;
};

}  // namespace sonar_config

#endif /* sonar_config_QNODE_HPP_ */
