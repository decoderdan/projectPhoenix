/**
 * @file /include/sonar_config/main_window.hpp
 *
 * @brief Qt based gui for sonar_config.
 *
 * @date November 2010
 **/
#ifndef sonar_config_MAIN_WINDOW_H
#define sonar_config_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace sonar_config {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function

public slots:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_pushButton_applyConfig_clicked();

    /******************************************
    ** Manual connections
    *******************************************/

	void on_spinBox_minDist_valueChanged(double arg1);
	void on_spinBox_maxDist_valueChanged(double arg1);

//	void on_spinBox_leftLimit_valueChanged(double arg1);
//	void on_spinBox_rightLimit_valueChanged(double arg1);

	void on_spinBox_threshold_valueChanged(double arg1);
	void on_spinBox_contrast_valueChanged(double arg1);

	void on_pushButton_saveConfig_clicked();

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
	QString m_sSettingsFile;

};

}  // namespace sonar_config

#endif // sonar_config_MAIN_WINDOW_H
