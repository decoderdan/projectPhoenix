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
#include "../include/sonar_config/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sonar_config {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

	ReadSettings();

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
	double threshold_val;
	double contrast_val;
	double gain_val;
	double resolution_val;
	double minDist_val;
	double maxDist_val;
	double leftLimit_val;
	double rightLimit_val;
	int angularRes_val;

	threshold_val = ui.spinBox_threshold->value();
	contrast_val = ui.spinBox_contrast->value();
	gain_val = ui.spinBox_gain->value();
	resolution_val = ui.spinBox_resolution->value();
	minDist_val = ui.spinBox_minDist->value();
	maxDist_val = ui.spinBox_maxDist->value();
	leftLimit_val = ui.spinBox_leftLimit->value();
	rightLimit_val = ui.spinBox_rightLimit->value();
	if(ui.radioButton_angularResHigh->isChecked()) {
		angularRes_val = 8;
	} else if(ui.radioButton_angularResMedium->isChecked()) {
		angularRes_val = 16;
	} else if(ui.radioButton_angularResLow->isChecked()) {
		angularRes_val = 32;
	}

	qnode.pubConfig(threshold_val, contrast_val, gain_val, resolution_val, minDist_val, maxDist_val, leftLimit_val, rightLimit_val, angularRes_val);

}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

void MainWindow::on_spinBox_minDist_valueChanged(double arg1)
{
    // must be LESS than maxDist value
    if(arg1 >= ui.spinBox_maxDist->value()) {
        ui.spinBox_maxDist->setValue(arg1 + 1);
    }
}

void MainWindow::on_spinBox_maxDist_valueChanged(double arg1)
{
    // must be MORE than minDist value
    if(arg1 <= ui.spinBox_minDist->value()) {
        ui.spinBox_minDist->setValue(arg1 - 1);
    }
}

void MainWindow::on_spinBox_leftLimit_valueChanged(double arg1)
{
    // must be LESS than rightLimit value
    if(arg1 >= ui.spinBox_rightLimit->value()) {
        ui.spinBox_rightLimit->setValue(arg1 + 1);
    }
}

void MainWindow::on_spinBox_rightLimit_valueChanged(double arg1)
{
    // must be MORE than leftLimit value
    if(arg1 <= ui.spinBox_leftLimit->value()) {
        ui.spinBox_leftLimit->setValue(arg1 - 1);
    }
}


void MainWindow::on_spinBox_contrast_valueChanged(double arg1)
{
    // must be LESS ??? than threshold ??? value
    if(arg1 >= ui.spinBox_threshold->value()) {
        ui.spinBox_threshold->setValue(arg1 + 1);
    }
}

void MainWindow::on_spinBox_threshold_valueChanged(double arg1)
{
    // must be MORE ??? than contrast ??? value
    if(arg1 <= ui.spinBox_contrast->value()) {
        ui.spinBox_contrast->setValue(arg1 - 1);
    }
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
	/* not sure if this will be useful to save values - presume would be local only */
}

void MainWindow::WriteSettings() {

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}


}  // namespace sonar_config

