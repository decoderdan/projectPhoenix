#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <iostream>

#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/ByteMultiArray.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include <custom_msg/SonarData.h>
#include "sensor_msgs/LaserScan.h"

void sonarCallback(const custom_msg::SonarData& sonarData);

/************************************************
 * 
 * The maximum length of the sonar reading needs to be at most half
 * the diameter of the displayed circle.
 * 
 * *********************************************/
uint32_t id = 0;
ros::Publisher laserpub;

int main(int argc, char **argv)
{

	ros::init(argc, argv, "sonar_to_laser");
	
	/* Messages and services */
	ros::NodeHandle n;	

  laserpub = n.advertise<sensor_msgs::LaserScan>("scan", 100);
	ros::Subscriber sonarSub = n.subscribe("sonar", 100, sonarCallback);

	ros::spin();

}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void sonarCallback(const custom_msg::SonarData& sonarData) {
	ROS_INFO("Spitting");
	float bearing = -(sonarData.bearing/6399.0*2.0*M_PI)+M_PI * (180.0/M_PI);
  float min_dB = sonarData.threshold*3.1875; 
	float max_dB = (sonarData.threshold + sonarData.contrast)*3.1875;
			
  sensor_msgs::LaserScanPtr output(new sensor_msgs::LaserScan());

	output->header.stamp = ros::Time::now();
	output->header.seq = id++;
  output->header.frame_id = "/sonar"; //associated with sonar
  output->angle_min = bearing-0.0523598776;//-1.04719755; //-60 degrees
  output->angle_max = bearing+0.0523598776;//1.04719755; //+60 degrees
  output->angle_increment = 0.0523598776;//0.0872664626; //5 Degrees
  output->time_increment = 0.0; //tbc
  output->scan_time = 0.01; //tbc
  output->range_min = sonarData.min_distance; //1cm
  output->range_max = sonarData.max_distance; //3m

	uint32_t ranges_size = std::ceil((output->angle_max - output->angle_min) / output->angle_increment);
    output->ranges.assign(ranges_size, output->range_max + 1.0);
	//float32[] ranges;

	//Get the bins	
	int i=0;
	output->ranges[0] = 100;
	output->ranges[2] = 100;
  for(std::vector<int>::const_iterator it = sonarData.bins.data.begin(); it != sonarData.bins.data.end(); ++it)
  {
  	//Take bin, and scale it between min and max contrast
		float val_in_dB = map(*it, min_dB, max_dB, 1.0, 0);
		if (val_in_dB < 0) val_in_dB = 0.0;
		if (val_in_dB > 1) val_in_dB = 1.0;
		
		if ((val_in_dB < 0.2) && ((i * sonarData.resolution) > 1.0)) { //Threshold
			//std::cout << "Matched : " << (i * sonarData.resolution) << " Resolution: " << sonarData.resolution << std::endl;
			output->ranges[1] = (i * sonarData.resolution);//i * sonarData.resolution;
			output->header.seq = id++;
			laserpub.publish(output);
		}
    i++;
  }
  
}
