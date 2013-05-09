#ifndef _SERIAL_PORT_HPP_
#define _SERIAL_PORT_HPP_

#include <termios.h>
#include <fcntl.h>
#include <vector>
#include <string>
#include <stdint.h>

/*! A class to manage IO of a Serial Port */

namespace uwe_sub {

	namespace io {

		class SerialPort 
		{
			protected:
				struct termios orig_terimos; //!< Termios configuration options
				int fd; //!< File descriptor for the port
				const static int WRITEDEL = 10000; //!< Delay period in microseconds after a write operation
				size_t MAX_BUFFER_SIZE; //!< Maximum buffer storage
			public:
				std::vector<uint8_t> buffer; //!< FIFO buffer of MAX_BUFFER_SIZE containing data read from the serial port
		
				/**
				 * Initializes a new SerialPort instance with the defined buffer size
				 * @param maxBuffer Defines the maximum size of the buffer
				 */
				SerialPort(size_t maxBuffer = 2000);
		
				/**
				 * Destructor
				 * Closes the port
				 */
				~SerialPort(void);
		
				/**
				 * Opens a serial connection
				 * @param port string indicating the port to open.
				 * @param baudrate BAUD rate at which to communicate at
				 * @param flush Indicates if the port should be flushed as soon as it's opened
				 * @return -1 if unsuccessful.
				 * @return otherwise: File descriptor
				 */
				int openPort(std::string const& port, int baudrate=115200, bool flush = true);

				/**
				 * Reads data from the port
				 * @return -1 if unsuccessful.
				 * @return Number of bytes read.
				 */
				int readPort(void);
		
				/**
				 * Writes data to the port
				 * @param data Data to be written
				 * @return -1 if unsuccessful.
				 * @return Number of bytes written.
				 */
				int writePort(std::vector<uint8_t> data);
		
				/**
				 * Flushes the input queue.
				 */
				void flushPort(void);
		
				/**
				 * Closes the port
				 */
				void closePort(void);			
		};
	}
}

#endif
