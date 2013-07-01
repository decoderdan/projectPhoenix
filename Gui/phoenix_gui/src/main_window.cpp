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
#include "../include/phoenix_gui/main_window.hpp"
#include <custom_msg/IMUData.h>
#include <stdlib.h>

int system_alarm_delay_counter = 0;
int motor_alarm_delay_counter = 0;

/*****************************************************************************
** Namespaces
*****************************************************************************/


namespace phoenix_gui {

using namespace Qt;
//using namespace Phonon;

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
	QObject::connect(&qnode, SIGNAL(noMaster()), this, SLOT(noMaster()));	
    QObject::connect(&qnode, SIGNAL(motorBattUpdated(float)), this, SLOT(showMotorBatt(float)));
    QObject::connect(&qnode, SIGNAL(systemBattUpdated(float)), this, SLOT(showSystemBatt(float)));
	QObject::connect(&qnode, SIGNAL(depthActualUpdated(float)), this, SLOT(showDepthActual(float)));
	QObject::connect(&qnode, SIGNAL(yawActualUpdated(float)), this, SLOT(showYawActual(float)));
	QObject::connect(&qnode, SIGNAL(pitchActualUpdated(float)), this, SLOT(showPitchActual(float)));
    QObject::connect(&qnode, SIGNAL(rawImageUpdated(QPixmap)), this, SLOT(showRawImage(QPixmap)));		

	/* disable some gui things... until connected */
	
	ui.toolBar->setEnabled(false);
	ui.tabConfig->setEnabled(false);
	
	ui.mainTabs->setCurrentIndex(0);


	/* test an image */

	QPixmap mypix ("/home/chris/Pictures/img.jpg");
        ui.raw_image_container->setPixmap(mypix.scaled(480,320,Qt::KeepAspectRatio)); //p.scaled(w,h,Qt::KeepAspectRatio

    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();

}
/******************
** toolbar slots **
******************/

void MainWindow::on_actionExit_triggered() {
	WriteSettings();
	close();
}

void MainWindow::on_actionEmergency_Stop_triggered() {
	QMessageBox msgBox;
	
	if(ui.actionEmergency_Stop->text()=="Emergency Stop") {
		qnode.emergencyStop(true);
		msgBox.setText("Emergency stop!");
		msgBox.exec();
        	ui.actionEmergency_Stop->setText("Emergency Reset");
	} else if (ui.actionEmergency_Stop->text()=="Emergency Reset") {
		qnode.emergencyStop(false);
		msgBox.setText("Emergency stop reset");
		msgBox.exec();
        	ui.actionEmergency_Stop->setText("Emergency Stop");
	}
	
}

void MainWindow::on_actionResurface_triggered() {
	QMessageBox msgBox;
	
	qnode.resurface();
	
	msgBox.setText("Sub will now resurface (hopefully)");
	msgBox.exec();
}

void MainWindow::on_button_connect_clicked(bool check ) {
	if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
			showNoMasterMessage();
			QSound::play("/home/chris/projectPhoenix/Gui/AIR_RAID.WAV");
		} else {
			ui.button_connect->setEnabled(false);
			
			// re-enable disabled gui items
			ui.toolBar->setEnabled(true);
			ui.tabConfig->setEnabled(true);
        		ui.mainTabs->setCurrentIndex(1);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			
			// re-enable disabled gui items
			ui.toolBar->setEnabled(true);
			ui.tabConfig->setEnabled(true);
			
			// set which tabs to display
        		ui.mainTabs->setCurrentIndex(1);
        		ui.configTabs->setCurrentIndex(0);
		}
	}
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
}

/*********************************************************
**			PID Slots			**
*********************************************************/

void MainWindow::on_pushButton_applyConfig_PID_clicked() {
	bool sendPID;

	double yawKp_val;
	double yawKi_val;
	double yawKd_val;
	double yawTarget_val;
	bool yawTarget_set;

	double pitchKp_val;
	double pitchKi_val;
	double pitchKd_val;
	double pitchTarget_val;
	bool pitchTarget_set;
	
	double depthKp_val;
	double depthKi_val;
	double depthKd_val;
	double depthTarget_val;
	bool depthTarget_set;

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
	
	if(ui.checkBox_sendPID->isChecked()) {
		sendPID = true; 
	} else {
		sendPID = false; 
	}

	if(ui.checkBox_yaw->isChecked()) {
		yawTarget_set = true; 
	} else {
		yawTarget_set = false; 
	}
	if(ui.checkBox_pitch->isChecked()) {
		pitchTarget_set = true; 
	} else {
		pitchTarget_set = false; 
	}
	if(ui.checkBox_depth->isChecked()) {
		depthTarget_set = true; 
	} else {
		depthTarget_set = false; 
	}
	
	qnode.pubConfig_PID(sendPID, yawKp_val, yawKi_val, yawKd_val, yawTarget_val, yawTarget_set, pitchKp_val, pitchKi_val, pitchKd_val, pitchTarget_val, pitchTarget_set, depthKp_val, depthKi_val, depthKd_val, depthTarget_val, depthTarget_set);
}

void MainWindow::on_pushButton_saveConfig_PID_clicked() {
	double yawKp_val;
	double yawKi_val;
	double yawKd_val;
	double yawTarget_val;
	bool yawTarget_set;
	
	double pitchKp_val;
	double pitchKi_val;
	double pitchKd_val;
	double pitchTarget_val;
	bool pitchTarget_set;
	
	double depthKp_val;
	double depthKi_val;
	double depthKd_val;
	double depthTarget_val;
	bool depthTarget_set;
	
	yawKp_val = ui.spinBox_yawKp->value();
	yawKi_val = ui.spinBox_yawKi->value();
	yawKd_val = ui.spinBox_yawKd->value();
	yawTarget_val = ui.spinBox_yawTarget->value();
	if(ui.checkBox_yaw->isChecked()) {
		yawTarget_set = true;
	} else {
		yawTarget_set = false;
	}
	
	pitchKp_val = ui.spinBox_pitchKp->value();
	pitchKi_val = ui.spinBox_pitchKi->value();
	pitchKd_val = ui.spinBox_pitchKd->value();
	pitchTarget_val = ui.spinBox_pitchTarget->value();
	if(ui.checkBox_pitch->isChecked()) {
		pitchTarget_set = true;
	} else {
		pitchTarget_set = false;
	}
	
	depthKp_val = ui.spinBox_depthKp->value();
	depthKi_val = ui.spinBox_depthKi->value();
	depthKd_val = ui.spinBox_depthKd->value();
	depthTarget_val = ui.spinBox_depthTarget->value();
	if(ui.checkBox_depth->isChecked()) {
		depthTarget_set = true;
	} else {
		depthTarget_set = false;
	}
	
	QString filename = QFileDialog::getSaveFileName(this, tr("Save PID Config"),
		                            QApplication::applicationDirPath(),
		                            tr("(*.ini)"));
	m_sSettingsFile = filename;
	QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
	settings.setValue("yawKp", yawKp_val);
	settings.setValue("yawKi", yawKi_val);
	settings.setValue("yawKd", yawKd_val);
	settings.setValue("yawTarget", yawTarget_val);
	settings.setValue("yawTargetSet", yawTarget_set);
	settings.setValue("pitchKp", pitchKp_val);
	settings.setValue("pitchKi", pitchKi_val);
	settings.setValue("pitchKd", pitchKd_val);
	settings.setValue("pitchTarget", pitchTarget_val);
	settings.setValue("pitchTargetSet", pitchTarget_set);
	settings.setValue("depthKp", depthKp_val);
	settings.setValue("depthKi", depthKi_val);
	settings.setValue("depthKd", depthKd_val);
	settings.setValue("depthTarget", depthTarget_val);
	settings.setValue("depthTargetSet", depthTarget_set);
}

void MainWindow::on_pushButton_loadConfig_PID_clicked() {
	double yawKp_val;
	double yawKi_val;
	double yawKd_val;
	double yawTarget_val;
	bool yawTarget_set;
	
	double pitchKp_val;
	double pitchKi_val;
	double pitchKd_val;
	double pitchTarget_val;
	bool pitchTarget_set;
	
	double depthKp_val;
	double depthKi_val;
	double depthKd_val;
	double depthTarget_val;
	bool depthTarget_set;

	QString filename = QFileDialog::getOpenFileName(this, tr("Open PID Config"),
		                            QApplication::applicationDirPath(),
		                            tr("(*.ini)"));
	m_sSettingsFile = filename;
	QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
	
	yawKp_val = settings.value("yawKp", "").toDouble();
	yawKi_val = settings.value("yawKi", "").toDouble();
	yawKd_val = settings.value("yawKd", "").toDouble();
	yawTarget_val = settings.value("yawTarget", "").toDouble();
	yawTarget_set = settings.value("yawTargetSet", "").toBool();
	
	pitchKp_val = settings.value("pitchKp", "").toDouble();
	pitchKi_val = settings.value("pitchKi", "").toDouble();
	pitchKd_val = settings.value("pitchKd", "").toDouble();
	pitchTarget_val = settings.value("pitchTarget", "").toDouble();
	pitchTarget_set = settings.value("pitchTargetSet", "").toBool();
	
	depthKp_val = settings.value("depthKp", "").toDouble();
	depthKi_val = settings.value("depthKi", "").toDouble();
	depthKd_val = settings.value("depthKd", "").toDouble();
	depthTarget_val = settings.value("depthTarget", "").toDouble();
	depthTarget_set = settings.value("depthTargetSet", "").toBool();
	
	ui.spinBox_yawKp->setValue(yawKp_val);
	ui.spinBox_yawKi->setValue(yawKi_val);
	ui.spinBox_yawKd->setValue(yawKd_val);
	ui.spinBox_yawTarget->setValue(yawTarget_val);
	if(yawTarget_set == true) {	
		ui.checkBox_yaw->setChecked(true);
	} else {
		ui.checkBox_yaw->setChecked(false);
	}

	ui.spinBox_pitchKp->setValue(pitchKp_val);
	ui.spinBox_pitchKi->setValue(pitchKi_val);
	ui.spinBox_pitchKd->setValue(pitchKd_val);
	ui.spinBox_pitchTarget->setValue(pitchTarget_val);
	if(pitchTarget_set == true) {	
		ui.checkBox_pitch->setChecked(true);
	} else {
		ui.checkBox_pitch->setChecked(false);
	}

	ui.spinBox_depthKp->setValue(depthKp_val);
	ui.spinBox_depthKi->setValue(depthKi_val);
	ui.spinBox_depthKd->setValue(depthKd_val);
	ui.spinBox_depthTarget->setValue(depthTarget_val);
	if(depthTarget_set == true) {	
		ui.checkBox_depth->setChecked(true);
	} else {
		ui.checkBox_depth->setChecked(false);
	}
}

/*********************************************************
**			Sonar Slots			**
*********************************************************/

void MainWindow::on_pushButton_applyConfig_sonar_clicked() {
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
	uint16_t angularRes_val;

	threshold_val = ui.spinBox_threshold_sonar->value();
	contrast_val = ui.spinBox_contrast_sonar->value();
	gain_val = ui.spinBox_gain_sonar->value();
	resolution_val = ui.spinBox_resolution_sonar->value();
	minDist_val = ui.spinBox_minDist_sonar->value();
	maxDist_val = ui.spinBox_maxDist_sonar->value();
	leftLimit_val = ui.spinBox_leftLimit_sonar->value();
	rightLimit_val = ui.spinBox_rightLimit_sonar->value();
	if(ui.checkBox_continuous_sonar->isChecked()) {
		continuous_val = true;
	} else {
		continuous_val = false;
	}
	if(ui.checkBox_stare_sonar->isChecked()) {
		stare_val = true;
	} else {
		stare_val = false;
	} 
	
	// 0.05625 * gui val =  deg per 'step'
	// gui val = step / 0.05625
		
	if(ui.radioButton_angularResHigh_sonar->isChecked()) {
		angularRes_val = 8;
	} else if(ui.radioButton_angularResMedium_sonar->isChecked()) {
		angularRes_val = 16;
	} else if(ui.radioButton_angularResLow_sonar->isChecked()) {
		angularRes_val = 32;
	} else if(ui.radioButton_angularResUltraLow_sonar->isChecked()) { // 100 'steps'
		angularRes_val = 64;
	} else if(ui.radioButton_angularRes50_sonar->isChecked()) { // 50 'steps'
		angularRes_val = 128;
	} else if(ui.radioButton_angularRes25_sonar->isChecked()) { // 25 'steps'
		angularRes_val = 255;
	} else if(ui.radioButton_angularRes12_5_sonar->isChecked()) {  // 12.5 'steps'
		angularRes_val = 512;
	}
	
	qnode.pubConfig_sonar(threshold_val, contrast_val, gain_val, resolution_val, minDist_val, maxDist_val, leftLimit_val, rightLimit_val, continuous_val, stare_val, angularRes_val);

}

void MainWindow::on_pushButton_saveConfig_sonar_clicked() {
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
	uint16_t angularRes_val;

	threshold_val = ui.spinBox_threshold_sonar->value();
	contrast_val = ui.spinBox_contrast_sonar->value();
	gain_val = ui.spinBox_gain_sonar->value();
	resolution_val = ui.spinBox_resolution_sonar->value();
	minDist_val = ui.spinBox_minDist_sonar->value();
	maxDist_val = ui.spinBox_maxDist_sonar->value();
	leftLimit_val = ui.spinBox_leftLimit_sonar->value();
	rightLimit_val = ui.spinBox_rightLimit_sonar->value();
	if(ui.checkBox_continuous_sonar->isChecked()) {
		continuous_val = true;
	} else {
		continuous_val = false;
	}
	if(ui.checkBox_stare_sonar->isChecked()) {
		stare_val = true;
	} else {
		stare_val = false;
	} 
	if(ui.radioButton_angularResHigh_sonar->isChecked()) {
		angularRes_val = 8;
	} else if(ui.radioButton_angularResMedium_sonar->isChecked()) {
		angularRes_val = 16;
	} else if(ui.radioButton_angularResLow_sonar->isChecked()) {
		angularRes_val = 32;
	}

    QString filename = QFileDialog::getSaveFileName(this, tr("Save Sonar Config"),
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

void MainWindow::on_pushButton_loadConfig_sonar_clicked() {

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
	uint16_t angularRes_val;


	QString filename = QFileDialog::getOpenFileName(this, tr("Open Sonar Config"),
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

	ui.spinBox_threshold_sonar->setValue(threshold_val);
	ui.spinBox_contrast_sonar->setValue(contrast_val);
	ui.spinBox_gain_sonar->setValue(gain_val);
	ui.spinBox_resolution_sonar->setValue(resolution_val);
	ui.spinBox_minDist_sonar->setValue(minDist_val);
	ui.spinBox_maxDist_sonar->setValue(maxDist_val);
	ui.spinBox_leftLimit_sonar->setValue(leftLimit_val);
	ui.spinBox_rightLimit_sonar->setValue(rightLimit_val);
	if(continuous_val == true) {	
		ui.checkBox_continuous_sonar->setChecked(true);
	} else if(continuous_val == false)  {
		ui.checkBox_continuous_sonar->setChecked(false);
	}
	if(stare_val == true) {	
		ui.checkBox_stare_sonar->setChecked(true);
	} else if(stare_val == false)  {
		ui.checkBox_stare_sonar->setChecked(false);
	}
	if(angularRes_val == 8) {	
		ui.radioButton_angularResHigh_sonar->setChecked(true);
	} else if(angularRes_val == 16) {	
		ui.radioButton_angularResMedium_sonar->setChecked(true);
	} else if(angularRes_val == 32) {	
		ui.radioButton_angularResLow_sonar->setChecked(true);
	}
		
}

void MainWindow::on_spinBox_minDist_sonar_valueChanged(double arg1)
{
    // must be LESS than maxDist value
    if(arg1 >= ui.spinBox_maxDist_sonar->value()) {
        ui.spinBox_maxDist_sonar->setValue(arg1 + 1);
    }
}

void MainWindow::on_spinBox_maxDist_sonar_valueChanged(double arg1)
{
    // must be MORE than minDist value
    if(arg1 <= ui.spinBox_minDist_sonar->value()) {
        ui.spinBox_minDist_sonar->setValue(arg1 - 1);
    }
}


void MainWindow::on_spinBox_leftLimit_sonar_valueChanged(double arg1)
{
    // must be LESS than rightLimit value
    if(arg1 >= ui.spinBox_rightLimit_sonar->value()) {
        ui.spinBox_rightLimit_sonar->setValue(arg1 + 1);
    }
}

void MainWindow::on_spinBox_rightLimit_sonar_valueChanged(double arg1)
{
    // must be MORE than leftLimit value
    if(arg1 <= ui.spinBox_leftLimit_sonar->value()) {
        ui.spinBox_leftLimit_sonar->setValue(arg1 - 1);
    }
} 


// thresh + contrast = MAX 80dB

void MainWindow::on_spinBox_contrast_sonar_valueChanged(double arg1) 
{
    // if contrast + thresh > 80 ... thresh -= 1;
    if((arg1 + ui.spinBox_threshold_sonar->value()) > 80) {
        ui.spinBox_threshold_sonar->setValue(ui.spinBox_threshold_sonar->value() - 1);
    }
}

void MainWindow::on_spinBox_threshold_sonar_valueChanged(double arg1)
{
    // if thresh + contrast > 80 ... contrast -= 1;
    if((arg1 + ui.spinBox_contrast_sonar->value()) > 80) {
        ui.spinBox_contrast_sonar->setValue(ui.spinBox_contrast_sonar->value() - 1);
    }
}

/************************************************************************
** 		Dead Reckoning Slots
************************************************************************/

void MainWindow::on_pushButton_setDist_deadReckoning_clicked()
{
	float estDist;
	float velocity;
	
	// get estimated distance from spinbox
	estDist = ui.spinBox_distance_deadReckoning->value();

	// calculate the velocity
	velocity = estDist / 5.0;
	
	//publish the velocity
	qnode.pubEstVelocity(velocity);
}

void MainWindow::on_pushButton_runCalibration_deadReckoning_clicked()
{
	// run the 'calibration' run
	qnode.startCalibration();
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

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "phoenix_gui");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "phoenix_gui");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::noMaster()
{
	std::cout << "Ros Master cannot be reached!" << std::endl;
	QSound::play("AIR_RAID.WAV");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

void MainWindow::showDepthActual(float value)
{
	ui.lcdNumber_depthActual->display((double)value);
}

void MainWindow::showYawActual(float value)
{
	ui.lcdNumber_yawActual->display((double)value);
}

void MainWindow::showPitchActual(float value)
{
	ui.lcdNumber_pitchActual->display((double)value);
}

void MainWindow::showRawImage(QPixmap raw_image)
{
        ui.raw_image_container->setPixmap(raw_image.scaled(480,320,Qt::KeepAspectRatio));
}

void MainWindow::showSystemBatt(float value)
{
        QPalette pal;
        // first calculate the percentage from the voltage (value)
        // max voltage should be about 25.00v
        // min voltage for 6s should be 19.2 (3.2v per cell)
        // so map 
        int percentage = map(value, 19.2, 25.0, 0, 100);
        ui.progressBar_systemBatt->setValue(percentage);
		ui.progressBar_systemBatt->setFormat(QString::number(value)+"v");

		if(percentage <= 5) {
			if(system_alarm_delay_counter >= 30) {
				system("aplay -q projectPhoenix/Gui/phoenix_gui/AIR_RAID.WAV ");
				QMessageBox msgBox;
				msgBox.setText("Warning, system battery below 5%");
				system_alarm_delay_counter = 0;
			} else {
				system_alarm_delay_counter ++;
			}
		} else if(percentage <= 10) {
			if(system_alarm_delay_counter >= 120) {
				system("aplay -q projectPhoenix/Gui/phoenix_gui/AIR_RAID.WAV ");
				QMessageBox msgBox;
				msgBox.setText("Warning, system battery below 10%");
				system_alarm_delay_counter = 0;
			} else {
				system_alarm_delay_counter ++;
			}
		}
}

void MainWindow::showMotorBatt(float value)
{
        QPalette pal;
		
		int percentage = map(value, 19.2, 25.0, 0, 100);
        ui.progressBar_motorBatt->setValue(percentage);
		ui.progressBar_motorBatt->setFormat(QString::number(value)+"v");

		// if (not reed_cutoff) {
		if(percentage < 10) {
			if(motor_alarm_delay_counter >= 120) {
				system("aplay -q projectPhoenix/Gui/phoenix_gui/AIR_RAID.WAV ");
				QMessageBox msgBox;
				msgBox.setText("Warning, motor battery below 10%");
				motor_alarm_delay_counter = 0;
			} else {
				motor_alarm_delay_counter ++;
			}
		}
}

float MainWindow::map(float x, float in_min, float in_max, float out_min, float out_max)
{
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

}  // namespace phoenix_gui

