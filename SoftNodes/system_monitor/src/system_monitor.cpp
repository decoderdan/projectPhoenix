#include "ros/ros.h"
#include <std_msgs/String.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

/* this program/node is going to send some messages over the ros system, which will be recieved by another node */

int main(int argc, char **argv) {
	ros::init(argc, argv, "system_monitor");

	ros::NodeHandle sysMon;

	ros::Publisher sysMsg = sysMon.advertise<std_msgs::String>("sysMsg", 1000);

	ros::Rate loop_rate(10); //10Hz

	while(ros::ok()) {

		/* read and publish memory info / load */
		ifstream meminfo ("//proc//meminfo");
		if(meminfo.is_open()) {
			while(meminfo.good()) {
				string line;
				getline(meminfo,line);
				if(std::string::npos != line.find("MemFree:")) {
					
					std::string mem_free_str = line.substr(1,6);

					std::cout << "free line =" << mem_free_str << '\n';
					std::istringstream iss (line);
					int val;
					iss >> val;
					std::cout << "free " << (int) val << '\n';

//					line.erase(0,12);
//					line.erase(line.length()-3, line.length);
//					ss << line << endl;
//					mem.data = ss.str();

//					sysMsg.publish(mem);

				}
			}
			meminfo.close();
		} else {
			ROS_ERROR("sysMonitor - Cannot open /proc/meminfo for reading");
		}
		
		ros::spinOnce();

		loop_rate.sleep();

	}

	return 0;
}