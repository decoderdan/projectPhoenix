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
						if (getTimeMs64() >= (startTime + timeout_ms)) break;
					}
					return false;
				}

	 		public:
	 			motorInterface() {
	 				reed_status = false; //Set to false
	 			}
	 		
	 			bool initialize(std::string const& port, int baudrate=115200) {
 					if (openPort(port,baudrate,true)) {
						//if (waitForPacket(100)) {
							flushPort();
							return true;
						//}
					}
					//TODO: Return false when the reed stuff is implemented.
					return false;
	 			}
	 			
	 			void update(custom_msg::MotorConfig data) {
	 				cfg = data;
	 			}
	 			
	 			//Sends out the new data
	 			void move() {
	 			
	 				//TODO: Remove the printout
	 				std::cout << "Sending data:" << std::endl << 
	 											"\tFront:\t\t" << (int)cfg.front << std::endl <<
	 											"\tBack:\t\t" << (int)cfg.back << std::endl <<
	 											"\tFront Right:\t" << (int)cfg.front_right << std::endl <<
	 											"\tBack Right:\t" << (int)cfg.back_right << std::endl <<
	 											"\tFront Left:\t" << (int)cfg.front_left << std::endl <<
	 											"\tBack Left:\t" << (int)cfg.back_left << std::endl;
	 				
	 				
	 				/* Create a vector with the data packet */
	 				char value_buffer[100];
	 				char tmp_buffer[100];
	 				sprintf(value_buffer,"%d,%d,%d,%d,%d,%d", cfg.front, cfg.back, cfg.front_right, cfg.back_right, cfg.front_left, cfg.back_left);
	 				sprintf(tmp_buffer, "@%s*%02X\n", value_buffer, checksum(value_buffer));
	 				std::vector<uint8_t> data_out(tmp_buffer, tmp_buffer + strlen(tmp_buffer)/sizeof(*tmp_buffer));
	 				
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

	//Subscribe to
	ros::Subscriber motorSub = n.subscribe("motor_config", 100, motorConfigCallBack);

	ros::Rate r(50); //50Hz message
	
	/* Open and Configure the Serial Port. */
	//TODO: Correct serial port
	if (motors.initialize("/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_A8008FpQ-if00-port0")) {

		while(ros::ok())
		{				
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
