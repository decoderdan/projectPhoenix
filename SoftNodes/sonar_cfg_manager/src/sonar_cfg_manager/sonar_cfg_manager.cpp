#include <stdio.h>
#include <sys/time.h> //For timeout
#include <ctime>    //For timeout
#include "ros/ros.h"
#include <custom_msg/SonarConfig.h> //For custom sonar configuration.
#include <rosspawn/NodeAction.h> //To launch sonar interface with args

/* Sonar Config Callback */
void sonarConfigCallBack(const custom_msg::SonarConfig& config) {
	//This is where we receive new configuration settings.
	ROS_INFO("Sonar Configuration settings have changed.");
	std::cout << "Got a new sonar configuration!" << std::endl;
	std::cout << "threshold " << config.threshold << std::endl;
	std::cout << "contrast " << config.contrast << std::endl;
	std::cout << "gain " << config.gain << std::endl;
	std::cout << "resolution " << config.resolution << std::endl;
	std::cout << "min dist " << config.min_distance << std::endl;
	std::cout << "max dist " << config.max_distance << std::endl;
	std::cout << "left limit " << config.left_limit << std::endl;
	std::cout << "right limit " << config.right_limit << std::endl;
	std::cout << "continuous " << config.continuous << std::endl;
	std::cout << "stare " << config.stare << std::endl;
	std::cout << "ang resolution " << config.angular_resolution << std::endl;
}

/******************************************************
 * 
 *  Main; the master of functions, the definer of variables.
 * 
 * ***************************************************/
int main( int argc, char **argv )
{
        ros::init(argc, argv, "sonar_cfg_manager");

	ros::NodeHandle n;

        ROS_INFO("Launched with %i args", argc);

        if (argc == 12) {
            double threshold = atof(argv[1]);
            std::cout << "Threshold: " << threshold << std::endl;

            for (int i = 1; i < argc; i++) {
                ROS_INFO("Arg %i: %s", i, argv[i]);
            }

        }

	//Subscribe to sonar config changes
	ros::Subscriber sonarSub = n.subscribe("sonar_config", 1, sonarConfigCallBack);
	
        ROS_INFO("Sonar Configuration Manager Online. Waiting for Sonar Config");

        ros::spin(); //Wait for callbacks only

        return 0;
}
