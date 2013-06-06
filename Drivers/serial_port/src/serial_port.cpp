#include "serial_port/serial_port.hpp"

namespace uwe_sub {

	namespace io {
	
		SerialPort::SerialPort(size_t maxBuffer) {
			MAX_BUFFER_SIZE = maxBuffer;
		}

		SerialPort::~SerialPort(void) {
			//std::vector will clean up the buffer by itself. So let's just close the port!
			closePort();
		}

		int SerialPort::openPort(std::string const& port, int baudrate, bool flush) {
			struct termios options;

			// Open Serial Port with Read/Write, 
			fd = open(port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);

			// Set up options
			tcgetattr(fd, &options);              		// Get the current options for the port...
			options.c_iflag |= (IGNBRK | IGNPAR);
			options.c_iflag &= ~(IXON | IXOFF);
			options.c_cflag  = (CLOCAL | CREAD | CS8);  	// Enable the receiver and set local mode (81N)
			options.c_cflag |= (HUPCL);
			options.c_lflag  = 0; 				// Raw Binary, no echo
			cfsetspeed(&options, baudrate);			// Set the baud rate
	
			tcsetattr(fd, TCSANOW, &options);     		// Set the new options for the port
			fcntl(fd, F_SETFL, FNDELAY);			// non-blocking low level read
			tcsetattr(fd, TCSANOW, &options);

			if (fd == -1) {
				return -1; //Failed to open the port
			}
			else {
	
				fcntl(fd, F_SETLK, 0); //Set the file lock
		
				if( tcgetattr(fd, &orig_terimos) < 0) {
					return -1;
				}

				//Flush the port if told to
				if (flush) {
					flushPort();
				}
			}
			return (fd);

		}

		void SerialPort::flushPort(void) {
			tcflush(fd, TCIFLUSH); //Flush existing data	
		}

		int SerialPort::readPort(void) {
			int            n;
			int            sock;
			int            max_fd;
			unsigned char  returnBuffer[500]; 	/*Buffer which stores read data*/
			fd_set         input;
			struct timeval timeout;

			/* Initialize the input set */
			FD_ZERO(&input);
			FD_SET(fd, &input);

			max_fd = (sock > fd ? sock : fd) + 1;

			/* Initialize the timeout structure */
			timeout.tv_sec  = 1;
			timeout.tv_usec = 50;
			n = select(max_fd, &input, NULL, NULL, &timeout);

			int p = 0;
			if (n < 0) {
				return -1;
			}
			else if (n != 0) {

				if (FD_ISSET(fd, &input)) {
					p = read(fd, returnBuffer,sizeof(returnBuffer));
			
					//Store this new data
					std::vector<uint8_t> newData(returnBuffer, returnBuffer + p);

					if ((buffer.size() + p) > MAX_BUFFER_SIZE) {
						//remove the elements at start of the buffer to match the buffer size
						buffer.erase(buffer.begin(), buffer.begin() + ((newData.size() + buffer.size() - MAX_BUFFER_SIZE)));
					}
			
					//Append our buffer
					buffer.insert(buffer.end(), newData.begin(), newData.end());
				}

			}

			return p;
		}

		int SerialPort::writePort(std::vector<uint8_t> data) {
			int n = write(fd, &data[0], data.size());

			if (n < 0) {
				return -1; //Nope
			}
			else {
				//usleep(WRITEDEL);
			}

			return (n);
		}

		void SerialPort::closePort() {
			tcflush(fd, TCIFLUSH);
			close(fd);
		}
	}
}
