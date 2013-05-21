/**
 * @file /include/pid_config/main_window.hpp
 *
 * @brief Qt based gui for pid_config.
 *
 * @date November 2010
 **/
#ifndef pid_config_MAIN_WINDOW_H
#define pid_config_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace pid_config {

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

	void closeEvent(QCloseEvent *event); // Overloaded function

public slots:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/

	/******************************************
	** Manual connections
	*******************************************/

	void on_pushButton_applyConfig_clicked();
	void on_pushButton_saveConfig_clicked();
	void on_pushButton_loadConfig_clicked();

private:
	Ui::MainWindow ui;
	QNode qnode;
	QString m_sSettingsFile;
};

}  // namespace pid_config

#endif // pid_config_MAIN_WINDOW_H
