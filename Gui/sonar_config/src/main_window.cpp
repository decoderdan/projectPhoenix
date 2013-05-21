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
	bool continuous_val;
	bool stare_val;
	int angularRes_val;

	threshold_val = ui.spinBox_threshold->value();
	contrast_val = ui.spinBox_contrast->value();
	gain_val = ui.spinBox_gain->value();
	resolution_val = ui.spinBox_resolution->value();
	minDist_val = ui.spinBox_minDist->value();
	maxDist_val = ui.spinBox_maxDist->value();
	leftLimit_val = ui.spinBox_leftLimit->value();
	rightLimit_val = ui.spinBox_rightLimit->value();
	if(ui.checkBox_continuous->isChecked()) {
		continuous_val = true;
	} else {
		continuous_val = false;
	}
	if(ui.checkBox_stare->isChecked()) {
		stare_val = true;
	} else {
		stare_val = false;
	} 
	if(ui.radioButton_angularResHigh->isChecked()) {
		angularRes_val = 8;
	} else if(ui.radioButton_angularResMedium->isChecked()) {
		angularRes_val = 16;
	} else if(ui.radioButton_angularResLow->isChecked()) {
		angularRes_val = 32;
	}

	qnode.pubConfig(threshold_val, contrast_val, gain_val, resolution_val, minDist_val, maxDist_val, leftLimit_val, rightLimit_val, continuous_val, stare_val, angularRes_val);

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

/*
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
*/

// ?!? thresh + cont MAX 80dB

void MainWindow::on_spinBox_contrast_valueChanged(double arg1) 
{
    // if contrast + thresh > 80 ... thresh -= 1;
    if((arg1 + ui.spinBox_threshold->value()) > 80) {
        ui.spinBox_threshold->setValue(ui.spinBox_threshold->value() - 1);
    }
}

void MainWindow::on_spinBox_threshold_valueChanged(double arg1)
{
    // if thresh + contrast > 80 ... contrast -= 1;
    if((arg1 + ui.spinBox_contrast->value()) > 80) {
        ui.spinBox_contrast->setValue(ui.spinBox_contrast->value() - 1);
    }
}

void MainWindow::on_pushButton_saveConfig_clicked() {
	double threshold_val;
	double contrast_val;
	double gain_val;
	double resolution_val;
	double minDist_val;
	double maxDist_val;
	double leftLimit_val;
	double rightLimit_val;
	bool continuous_val;
	bool stare_val;
	int angularRes_val;

	threshold_val = ui.spinBox_threshold->value();
	contrast_val = ui.spinBox_contrast->value();
	gain_val = ui.spinBox_gain->value();
	resolution_val = ui.spinBox_resolution->value();
	minDist_val = ui.spinBox_minDist->value();
	maxDist_val = ui.spinBox_maxDist->value();
	leftLimit_val = ui.spinBox_leftLimit->value();
	rightLimit_val = ui.spinBox_rightLimit->value();
	if(ui.checkBox_continuous->isChecked()) {
		continuous_val = true;
	} else {
		continuous_val = false;
	}
	if(ui.checkBox_stare->isChecked()) {
		stare_val = true;
	} else {
		stare_val = false;
	} 
	if(ui.radioButton_angularResHigh->isChecked()) {
		angularRes_val = 8;
	} else if(ui.radioButton_angularResMedium->isChecked()) {
		angularRes_val = 16;
	} else if(ui.radioButton_angularResLow->isChecked()) {
		angularRes_val = 32;
	}

    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    QApplication::applicationDirPath(),
                                                    tr("(*.ini)"));
    m_sSettingsFile = filename;
    QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
    settings.setValue("threshold", threshold_val);
    settings.setValue("contrast", contrast_val);
    settings.setValue("gain", gain_val);
    settings.setValue("resolution", resolution_val);
    settings.setValue("minDist", minDist_val);
    settings.setValue("maxDist", maxDist_val);
    settings.setValue("leftLimit", leftLimit_val);
    settings.setValue("rightLimit", rightLimit_val);
    settings.setValue("continuous", continuous_val);
    settings.setValue("stare", stare_val);
    settings.setValue("angularRes", angularRes_val);


}

void MainWindow::on_pushButton_loadConfig_clicked() {

	double threshold_val;
	double contrast_val;
	double gain_val;
	double resolution_val;
	double minDist_val;
	double maxDist_val;
	double leftLimit_val;
	double rightLimit_val;
	bool continuous_val;
	bool stare_val;
	int angularRes_val;


	QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    QApplication::applicationDirPath(),
                                                    tr("(*.ini)"));
	m_sSettingsFile = filename;
	QSettings settings(m_sSettingsFile, QSettings::NativeFormat);

	threshold_val = settings.value("threshold", "").toDouble();
	contrast_val = settings.value("contrast", "").toDouble();
	gain_val = settings.value("gain", "").toDouble();
	resolution_val = settings.value("resolution", "").toDouble();
	minDist_val = settings.value("minDist", "").toDouble();
	maxDist_val = settings.value("maxDist", "").toDouble();
	leftLimit_val = settings.value("leftLimit", "").toDouble();
	rightLimit_val = settings.value("rightLimit", "").toDouble();
	continuous_val = settings.value("continuous", "").toBool();
	stare_val = settings.value("stare", "").toBool();
	angularRes_val = settings.value("angularRes", "").toInt();

	ui.spinBox_threshold->setValue(threshold_val);
	ui.spinBox_contrast->setValue(contrast_val);
	ui.spinBox_gain->setValue(gain_val);
	ui.spinBox_resolution->setValue(resolution_val);
	ui.spinBox_minDist->setValue(minDist_val);
	ui.spinBox_maxDist->setValue(maxDist_val);
	ui.spinBox_leftLimit->setValue(leftLimit_val);
	ui.spinBox_rightLimit->setValue(rightLimit_val);
	if(continuous_val == true) {	
		ui.checkBox_continuous->setChecked(true);
	} else if(continuous_val == false)  {
		ui.checkBox_continuous->setChecked(false);
	}
	if(stare_val == true) {	
		ui.checkBox_stare->setChecked(true);
	} else if(stare_val == false)  {
		ui.checkBox_stare->setChecked(false);
	}
	if(angularRes_val == 8) {	
		ui.radioButton_angularResHigh->setChecked(true);
	} else if(angularRes_val == 16) {	
		ui.radioButton_angularResMedium->setChecked(true);
	} else if(angularRes_val == 32) {	
		ui.radioButton_angularResLow->setChecked(true);
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

