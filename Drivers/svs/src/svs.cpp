#include <stdio.h>
#include <sys/time.h> //For timeout
#include <ctime>      //For timeout
#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <serial_port/serial_port.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <boost/lexical_cast.hpp> // for converting strings to ...


//#define svsDeviceID "//dev//serial//by-id//usb-Prolific_Technology_Inc._USB-Serial_Controller_D-if00-port0" // cannot do by-dev-id at the moment ... needs a solution
#define svsDeviceID "//dev//ttyUSB1"

#define TIMEOUT_PACKET 500
#define TIMEOUT_REPLY 500
#define TIMEOUT_EMERCENCY 1000

namespace uwe_sub {

	namespace svs {

		class svsInterface : protected uwe_sub::io::SerialPort {
			protected:
				void sendData(std::string const& data) {
					std::vector<unsigned char> vector_data(data.begin(), data.end());	// convert to string
					std::stringstream ss;		// print the data
					ss << "Sending - " << data;
					ROS_INFO(ss.str().c_str());
					writePort(vector_data);		// send the data
				}

				bool waitForData(std::string const& data, uint64_t timeout_ms) {
					uint64_t start_time = getTimeMs64();
					
					std::stringstream ss;		// print the data
					ss << "Waiting for - \"" << data << "\"";
					ROS_INFO(ss.str().c_str());

					while(1) {
						readPort();

						if(getTimeMs64() >= (start_time + timeout_ms)) return false;
						
						// make sure there's something in the buffer before trying to read it
						if(buffer.size() > 0) {
							//std::string buffer_str(buffer.begin(), buffer.end());
						
							std::stringstream buf_ss;
							for(size_t i = 0; i < buffer.size(); ++i)
							{
							  buf_ss << buffer[i];
							}
							std::string buf_s = buf_ss.str();

							std::size_t found = buf_s.find(data);

  							if (found!=std::string::npos) {
    							std::stringstream ss;		// print the reply
								ss << "SVP replied with - " << data;
								ROS_INFO(ss.str().c_str());
								buffer.erase(buffer.begin(), buffer.end()); //Delete some
								return true;
							} 
						}
					}				
				}

				uint64_t getTimeMs64() {
					 struct timeval tv;

					 gettimeofday(&tv, NULL);

					 uint64_t ret = tv.tv_usec;
					 /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
					 ret /= 1000;

					 /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
					 ret += (tv.tv_sec * 1000);

					 return ret;
				}

			public:
				int initialize() {
					
					if(openPort(svsDeviceID,19200,true)) {  // start serial
						
						// write config over serial
						
						sendData("M32\x0A");	// ensure the device isn't  already paused, by bringing it up
						
						// wait for '>'						
						if(waitForData("\n", TIMEOUT_REPLY) == true) {
							ROS_INFO("SVP ONLINE");
						} else { 
							ROS_ERROR("Expected SVP to reply with a packet, not recieved");
							return -1;
						}

						sendData("#");		// send a stop command 
						
						// wait for '>'						
						if(waitForData(">", TIMEOUT_REPLY) == true) {
							ROS_INFO("SVP ONLINE");
						} else { 
							ROS_ERROR("Expected SVP to reply with '>', not recieved");
							return -1;
						}

						sendData("#082;off\x0A"); // SETS DATA FORMAT TO STANDARD VALEPORT MODE

						// wait for "OFF/n"
						if(waitForData("OFF", TIMEOUT_REPLY) == true) {
							ROS_INFO("DATA FORMAT TO STANDARD VALEPORT MODE");
						} else { 
							ROS_ERROR("Expected SVP to reply with \"OFF/n\", not recieved");
							return -1;
						}

						sendData("#018;1\x0A"); // SETS UNITS TO METRES - PRESSURE FORMAT

						// wait for "Metres/n"
						if(waitForData("Metres", TIMEOUT_REPLY) == true) {
							ROS_INFO("PRESSURE UNITS SET TO METERS");
						} else { 
							ROS_ERROR("Expected SVP to reply with \"Meters/n\", not recieved");
							return -1;
						}

						sendData("#083;3\x0A"); // SETS UNITS TO 3.D.P - PRESSURE FORMAT

						// wait for "3/n"
						if(waitForData("3", TIMEOUT_REPLY) == true) {
							ROS_INFO("PRESSURE UNITS TO 3.D.P");
						} else { 
							ROS_ERROR("Expected SVP to reply with \"3/n\", not recieved");
							return -1;
						}

						sendData("M32\x0A");	// configure for 32Hz 
						// dont wait for anything ... svp now starts 'spitting out data' (e.g. 09.951 0000000/n)
						
						return 0;
						
					} else {
						ROS_ERROR("Cannot connect to svp!!!");
						closePort();
						return -1;
					}
				}

				
				std::string waitForPacket(uint64_t timeout_ms) {
					uint64_t start_time = getTimeMs64();		
				
					ROS_INFO("Waiting for svp packet");

					while(1) {
						readPort();

						if(getTimeMs64() >= (start_time + timeout_ms)) return "-1";
					
						// make sure there's something in the buffer before trying to read it
						if(buffer.size() > 0) {
							std::string buffer_str(buffer.begin(), buffer.end());
						
							std::size_t found = buffer_str.find("\n");

							if (found!=std::string::npos) {
								buffer.erase(buffer.begin(), buffer.end()); //Delete some
								return buffer_str;
							} else {
								
							}
						} else {
							ROS_ERROR("buffer empty");
						}
					}				
				}
		}; // class svsInterface

	} // namespace svs
	
} // namespace uwe_sub

uwe_sub::svs::svsInterface svs;
	
int main(int argc, char **argv) 
{ // main (ros stuff)

	bool no_data = true;
	std::string svs_packet;
	std::stringstream ss;

	ros::init(argc, argv, "svs");	

	ros::NodeHandle n;		
	// setup publisher for depth
	// setup publisher for sos
	ros::Publisher svs_depth_msg = n.advertise<std_msgs::Float32>("depth", 100); 
	ros::Publisher svs_sos_msg = n.advertise<std_msgs::Float32>("speed_of_sound", 100);

	std_msgs::Float32 svs_depth;
	std_msgs::Float32 svs_sos;

	ros::Rate r(32);

	while(ros::ok())
		{
			if(no_data == true) {
				while(svs.initialize() != 0) {
					ROS_ERROR("SVS not ready yet.");
					r.sleep();
				}
				no_data = false;
			}
		
			
			// wait for packet... set no_data if timed out
			
			svs_packet = svs.waitForPacket(TIMEOUT_PACKET);

			if(svs_packet != "-1") { 	
				std::stringstream ss;		// print the data
				ss << "SVS packet found - \"" << svs_packet << "\"";
				ROS_INFO(ss.str().c_str());	

				//expecting: "<space>{pressure}<space>123456<cr><lf>" - e.g. " 09.981 0000000"
				
				if(svs_packet.size() == 16) {
					std::string depth_str = svs_packet.substr(1,6);
					std::string speed_of_sound_str = svs_packet.substr(8,7);

					//convert to numbers
					long speed_of_sound = std::atol(speed_of_sound_str.c_str());
					float depth = std::atof(depth_str.c_str());

					//print values
					std::stringstream sos_ss;	// print the s_o_s
					sos_ss << "speed_of_sound = " << speed_of_sound;
					ROS_INFO(sos_ss.str().c_str());
					
					std::stringstream d_ss;		// print the depth
					d_ss << "depth = " << depth;
					ROS_INFO(d_ss.str().c_str());

					// publish values
					svs_sos.data = speed_of_sound / 1000.0;	// svs outputs in mm/s we want m/s
					svs_depth.data = depth - 10.0;	// svs adds 10 to actual value

					svs_depth_msg.publish(svs_depth);
					svs_sos_msg.publish(svs_sos);


				
				} else {
					std::stringstream ss;		// print the reply
					ss << "SVS PACKET INVALID (EXPECTED LEN = 16 - IS " << svs_packet.size() << "- \"" << svs_packet << "\"";
					ROS_WARN(ss.str().c_str());
				}
				
			} else {
				ROS_ERROR("SVS packet timed out!");
				no_data = true;
			}

			ros::spinOnce();
		}
		
	return 0;
}
