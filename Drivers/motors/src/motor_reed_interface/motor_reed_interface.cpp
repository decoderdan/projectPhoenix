#include <stdio.h>
#include <sys/time.h> //For timeout
#include <ctime>			//For timeout
#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <serial_port/serial_port.hpp>
#include <custom_msg/MotorConfig.h>

namespace uwe_sub {

	namespace motors {

	  class motorInterface : protected uwe_sub::io::SerialPort {
	  	//This is our motor interface. All Input and Output take place here.
	 		
	 		protected:
	 			bool reed_status;
	 			custom_msg::MotorConfig cfg;
	 			
		 		int checksum(char *s) {
					int c = 0;
					while(*s) c ^= *s++;
					return c;
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
				
				bool waitForPacket(uint64_t timeout_ms) {
					uint64_t startTime = getTimeMs64();
					while (1) {
						readPort();
						//TODO: Check for reed packet here. Don't worry until later
						if (getTimeMs64() >= (startTime + 10000)) break;
					}
					return false;
				}

	 		public:
	 			motorInterface() {
	 				reed_status = false; //Set to false
	 			}
	 		
	 			bool initialize(std::string const& port, int baudrate=115200) {
 					if (openPort(port,baudrate,true)) {
						if (waitForPacket(100)) {
							return true;
						}
					}
					//TODO: Return false when the reed stuff is implemented.
					return true;
	 			}
	 			
	 			void update(custom_msg::MotorConfig data) {
	 				cfg = data;
	 			}
	 			
	 			//Sends out the new data
	 			void move() {
	 			
	 				//TODO: Remove the printout
	 				std::cout << "Sending data: " << std::endl << 
	 											"\tBow:\t\t " << (int)cfg.bow << std::endl <<
	 											"\tStern:\t\t " << (int)cfg.stern << std::endl <<
	 											"\tStarboard Bow:\t " << (int)cfg.starboard_bow << std::endl <<
	 											"\tStarboard Stern: " << (int)cfg.starboard_stern << std::endl <<
	 											"\tPort Bow:\t " << (int)cfg.port_bow << std::endl <<
	 											"\tPort Stern:\t " << (int)cfg.port_stern << std::endl;
	 				
	 				/* Create a vector with the data packet */
	 				char value_buffer[100];
	 				char tmp_buffer[100];
	 				sprintf(value_buffer,"%d,%d,%d,%d,%d,%d", cfg.bow, cfg.stern, cfg.starboard_bow, cfg.starboard_stern, cfg.port_bow, cfg.port_stern);
	 				sprintf(tmp_buffer, "@%s*%02X\n", value_buffer, checksum(value_buffer));
	 				std::vector<uint8_t> data_out(tmp_buffer, tmp_buffer + strlen(tmp_buffer)/sizeof(*tmp_buffer));
	 				
	 				//TODO: Remove this printing too
	 				for (int i = 0; i < data_out.size(); i++) {
						if ((i != 0) && (i%10==0)) printf("\n");
						printf("[%02X] ", data_out[i]);
					}
					data_out.push_back(NULL); //TODO: This is purely for the text output. remove it :)
	 				std::cout << std::endl << &data_out[0] << std::endl;
	 				
	 				writePort(data_out);
	 			}
	 			
	 			bool reedStatus() {
	 				return reed_status;
	 			}
	 			
	  }; //End of motorInterface	
	}
}

void motorConfigCallBack(const custom_msg::MotorConfig&);

uwe_sub::motors::motorInterface motors;

/******************************************************
 * 
 *  Main; the master of functions, the definer of variables.
 * 
 * ***************************************************/
int main( int argc, char **argv )
{

	ros::init(argc, argv, "motor_interface");

	ros::NodeHandle n;

	/* Publish the status of the reed switch to "reed" */
	ros::Publisher reedStatusMsg = n.advertise<std_msgs::Bool>("reed", 100);
	std_msgs::Bool reedStatus;

	/* Test publish the motor configuration */
	ros::Publisher testMsg = n.advertise<custom_msg::MotorConfig>("motor_config", 100);
	custom_msg::MotorConfig testCfg;

	//Subscribe to
	ros::Subscriber sub1 = n.subscribe("motor_config", 100, motorConfigCallBack);

	ros::Rate r(50); //50Hz message
	
	/* Open and Configure the Serial Port. */
	//TODO: Correct serial port
	if (motors.initialize("/dev/serial/by-id/usb-FTDI_US232R_FTB3UJNB-if00-port0")) {

		while(ros::ok())
		{	
			testCfg.bow++;
			testCfg.stern+=3;
			testCfg.starboard_bow-=2;
			testCfg.starboard_stern-=3;
			testCfg.port_bow+=2;
			testCfg.port_stern+=4;
			
			testMsg.publish(testCfg);
			
			motors.move();
			reedStatus.data = motors.reedStatus();
			reedStatusMsg.publish(reedStatus);
			
			ros::spinOnce(); //Call all waiting callbacks at this point
			r.sleep(); //Sleep for a little while
		}
	}
	else {
		std::cout << "Couldn't communicate with the motors?" << std::endl;
	}

	return 0;
}

void motorConfigCallBack(const custom_msg::MotorConfig& config)
{
	motors.update(config);
	return;
}
