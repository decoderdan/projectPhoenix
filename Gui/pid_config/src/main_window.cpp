/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/pid_config/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace pid_config {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    
	setWindowIcon(QIcon(":/images/icon.png"));

	QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

	/*********************
	** Logging
	**********************/

	/*********************
	** Auto Start
	**********************/
	if ( !qnode.init() ) {
		std::cout << "ERROR: Unable to communcate with master!" << std::endl ;
		exit(EXIT_FAILURE);
	}
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::on_pushButton_applyConfig_clicked() {
	double yawKp_val;
	double yawKi_val;
	double yawKd_val;
	double yawTarget_val;

	double pitchKp_val;
	double pitchKi_val;
	double pitchKd_val;
	double pitchTarget_val;

	double depthKp_val;
	double depthKi_val;
	double depthKd_val;
	double depthTarget_val;

	yawKp_val = ui.spinBox_yawKp->value();
	yawKi_val = ui.spinBox_yawKi->value();
	yawKd_val = ui.spinBox_yawKd->value();

	pitchKp_val = ui.spinBox_pitchKp->value();
	pitchKi_val = ui.spinBox_pitchKi->value();
	pitchKd_val = ui.spinBox_pitchKd->value();

	depthKp_val = ui.spinBox_depthKp->value();
	depthKi_val = ui.spinBox_depthKi->value();
	depthKd_val = ui.spinBox_depthKd->value();

	yawTarget_val = ui.spinBox_yawTarget->value();
	pitchTarget_val = ui.spinBox_pitchTarget->value();
	depthTarget_val = ui.spinBox_depthTarget->value();
	
	qnode.pubConfig(yawKp_val, yawKi_val, yawKd_val, yawTarget_val, pitchKp_val, pitchKi_val, pitchKd_val, pitchTarget_val, depthKp_val, depthKi_val, depthKd_val, depthTarget_val);
}

void MainWindow::on_pushButton_saveConfig_clicked() {

}

void MainWindow::on_pushButton_loadConfig_clicked() {

}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::closeEvent(QCloseEvent *event)
{
	QMainWindow::closeEvent(event);
}

}  // namespace pid_config

