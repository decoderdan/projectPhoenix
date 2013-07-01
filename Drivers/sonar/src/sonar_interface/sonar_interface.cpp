#include <stdio.h>
#include <inttypes.h> //For string to uint16_T
#include <sys/time.h> //For timeout
#include <ctime>			//For timeout
#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32MultiArray.h"
#include <serial_port/serial_port.hpp>
#include <custom_msg/SonarData.h>
#include <custom_msg/SonarConfig.h> //For custom sonar configuration.

namespace uwe_sub {

	namespace sonar {
	
		static const char PACKET_START = '@';
		static const char PACKET_END = 0x0A;

		class sonarInterface;

		struct VersionData
		{
		  uint8_t softwareVersion; //Might expand on this later
		  uint8_t infoBits;	   //Same for this...
		  uint8_t serialNr;
		  uint8_t nodeID;
		  uint32_t programmLength;
		  uint16_t programmChecksum;	
		};

		enum StepAngleSize
		{
				LOW = 32, MEDIUM = 16, HIGH = 8
		};

		enum HeadConfigFlags
		{
			ADC8ON = 1, CONT = 2, SCANRIGHT = 4, INVERT = 8,
			MOTOFF = 16, TXOFF = 32, SPARE = 64, CHAN2 = 128,
			RAW = 256, HASMOT = 512, APPLYOFFSET = 1024, PINGPONG = 2048,
			STARELLIM = 4096, REPLYASL = 8192, REPLYTHR = 16384,
			IGNORESENSOR = 32768
		};

		struct ImagingHeadData
		{
		  uint8_t node_type; 
		  uint8_t type;
		  uint16_t packed_size;
		  uint8_t device_type;
		  uint8_t head_status;
		  uint8_t sweep_code;
		  uint16_t head_control;
		  uint16_t range;
		  uint32_t txn;
		  uint8_t gain;
		  uint16_t slope;
		  uint8_t ad_span;
		  uint8_t ad_low;
		  uint16_t heading_offset;
		  uint16_t ad_interval;
		  uint16_t left_limit;
		  uint16_t right_limit;
		  uint8_t motor_step_angle_size;
		  uint16_t bearing;
		  uint16_t data_bytes;
		  const uint8_t *scan_data;
		};

		struct SonarData
		{
			float bearing;
			std::vector<uint8_t> bins;
		};

		struct AliveData 
		{
		   bool ready;
		   bool motor_on;
		   bool scanning;
		   bool no_config;
		   bool config_send;
		   AliveData():
			   ready(false),motor_on(false),scanning(false),
			   no_config(true),config_send(false){};
		};

		struct HeadCommand
		{
		  uint8_t V3B_params; uint16_t head_control; uint8_t head_type;
		  uint32_t txn_ch1; uint32_t txn_ch2; uint32_t rxn_ch1; uint32_t rxn_ch2;
		  uint16_t pulse_length; uint16_t range_scale; uint16_t left_limit;
		  uint16_t right_limit; uint8_t ad_span; uint8_t ad_low; uint8_t initial_gain_ch1;
		  uint8_t initial_gain_ch2; uint16_t slope_ch1; uint16_t slope_ch2; uint8_t motor_step_delay_time;
		  uint8_t motor_step_angle_size; uint16_t ad_interval; uint16_t number_of_bins;
		  uint16_t max_ad_buff; uint16_t lockout_time; uint16_t minor_axis_dir;
		  uint8_t major_axis_pan; uint8_t crtl2; uint16_t scan_z; uint8_t ad_span_ch1;
		  uint8_t ad_span_ch2; uint8_t ad_low_ch1; uint8_t ad_low_ch2; uint8_t igain_ch1;
		  uint8_t igain_ch2; uint8_t adc_set_point_ch1; uint8_t adc_set_point_ch2;
		  uint16_t advanced_slope_ch1; uint16_t advanced_slope_ch2; uint16_t advanced_slope_delay_ch1;
		  uint16_t advanced_slope_delay_ch2;

		  HeadCommand()
		  {
			//clear everything 
			memset(this,0,sizeof(*this));
		  }
		} __attribute__ ((packed)) __attribute__((__may_alias__)); //remove padding (makes it easier to process in code)

		class Angle
		{
		public:
			/** 
			 * angle in radians.
			 * this value will always be PI < rad <= PI
			 *
			 * @note don't use this value directly. It's only public to allow this class
			 * to be used as an interface type.
			 */
			double rad;

			/** 
			 * default constructor, which will leave the angle uninitialized.
			 */
			Angle() {}
		
		protected:
			explicit Angle( double rad ) : rad(rad) 
			{ 
			canonize(); 
			}

			void canonize()
			{
			if( rad > M_PI || rad <= -M_PI )
			{
				double intp;
				const double side = copysign(M_PI,rad);
				rad = -side + 2*M_PI * modf( (rad-side) / (2*M_PI), &intp ); 
			}
			}

		public:
			/**
			 * static conversion from radians to degree
			 * @param rad angle in radians
			 * @result angle in degree
			 */
			static inline double rad2Deg( double rad )
			{
			return rad / M_PI * 180.0;
			}

			/**
			 * static conversion from degree to radians
			 * @param deg angle in degree
			 * @result angle in radians
			 */
			static inline double deg2Rad( double deg )
			{
			return deg / 180.0 * M_PI;
			}

			/** Normalize an angular value in [-pi; pi] and returns it as double
			 */
			static inline double normalizeRad( double rad )
			{
				return Angle(rad).rad;
			}

			/** 
			 * use this method to get an angle from radians.
			 * @return representation of the given angle.
			 * @param rad - angle in radians.
			 */
			static inline Angle fromRad( double rad )
			{
			return Angle( rad );
			}

			/** 
			 * use this method to get an angle from degrees.
			 * @return representation of the given angle.
			 * @param deg - angle in degrees.
			 */
			static inline Angle fromDeg( double deg )
			{
			return Angle( deg / 180.0 * M_PI );
			}

			/**
			 * @return canonical value of the angle in radians
			 */
			double inline getRad() const 
			{
			return rad;
			}

			/**
			 * @return canonical value of the angle in degrees
			 */
			double inline getDeg() const
			{
			return rad / M_PI * 180;
			}

			/**
			 * @return true if the angle is insight the given interval
			 */
			bool inline isInRange(const Angle &left_limit,const Angle &right_limit) const;
			/**
			 * compare two angles for approximate equality
			 * @param other - angle to compare
			 * @param prec - precision interval in deg
			 * @return true if angle is approximately equal 
			 */
			bool inline isApprox( Angle other, double prec = 1e-5 ) const
			{
			return fabs( other.rad - rad ) < prec;
			}

			void operator=(const Angle &other)
			{
				rad = other.rad;
			}
		
			inline bool operator==(const Angle &other ) const
			{
				return this->rad == other.rad;
			}
		
			inline bool operator<(const Angle &other ) const
			{
				return this->rad < other.rad;
			}
		
			inline bool operator>(const Angle &other ) const
			{
				return this->rad > other.rad;
			}
		};

		struct MicronConfig
		{
		  Angle left_limit;
		  Angle right_limit;

		  uint16_t angular_resolution; 

		  double max_distance;
		  double min_distance;
		  double resolution;
		  double speed_of_sound;
		  double gain;

			double threshold;
			double contrast;

		  bool low_resolution;
		  bool continuous;
		  bool stare;

		  MicronConfig():
			left_limit(Angle::fromRad(M_PI)),
			right_limit(Angle::fromRad(-M_PI)),
			angular_resolution(LOW),
			max_distance(15.0),
			min_distance(1.0),
			resolution(0.1),
			speed_of_sound(1500.0),
			gain(0.4),
				threshold(13),
			  contrast(24),
			low_resolution(false),
			continuous(true)
		  {};

		  bool operator==(const MicronConfig &other) const
		  {
			return (other.left_limit == left_limit &&
							other.right_limit == right_limit &&
							other.angular_resolution == angular_resolution &&
							other.max_distance == max_distance && 
							other.min_distance == min_distance && 
							other.resolution == resolution &&
							other.speed_of_sound== speed_of_sound &&
							other.gain == gain &&
							other.low_resolution == low_resolution &&
				other.continuous == continuous);
		  };
		  bool operator!=(const MicronConfig &other) const
		  {
			return !(other == *this);
		  };
		};

		enum PacketType {
		  mtNull = 0, mtVersionData, mtHeadData, mtSpectData, mtAlive, 
		  mtPrgAck, mtBBUserData, mtTestData, mtAuxData, mtAdcData,
		  mtLdcReq, na11, na12, mtLanStatus, mtSetTime, mtTimeout,
		  mtReBoot, mtPerformanceData, na18, mtHeadCommand, mtEraseSector,
		  mtProgBlock, mtCopyBootBlk, mtSendVersion, mtSendBBUser, mtSendData,
		  mtSendPreferenceData
		};

		class SeaNetPacket {
			public:
				std::vector<uint8_t> Packet;
				std::vector<uint8_t> createPacket(PacketType packet_type) {
					//Test for now.
					return createPacket(packet_type, NULL, 0);
				}

			protected:
				std::vector<uint8_t> createPacket(PacketType packet_type, uint8_t* payload, size_t payload_size) {

					std::vector<uint8_t> packet;

				  //calculate packet size
				  size_t size = payload_size + 14;    //14 Bytes is the size of a packet without user payload
				  packet.resize(size,0);
				  size_t size2 = size - 6;            //first 5 Bytes and the last one are not included 
				  //in the packet size encoded into the package
				  //Header
				  packet[0] = PACKET_START;
				  sprintf((char*)&packet[1],"%04X",size2);

				  packet[5] = (size2) & 255;
				  packet[6] = ((size2)>>8) & 255;
				  packet[7] = 255;                        //this is always 255 for a PC
				  packet[8] = (uint8_t)0x02;       //receiver type
				  packet[9] = payload_size+3;              
				  packet[10] = (uint8_t)packet_type;  //this is part of the packet payload but
																						  //each packet must have Byte 10-12 therefore
																						  //we consider it as part of the header
				  packet[11] = 0x80;                         //Sequence end
				  packet[12] = (uint8_t)0x02;         //receiver type

				  //user payload, packet payload without Byte 10,11,12
				  if(payload_size && payload)
					  memcpy(&packet[13],payload,payload_size);

				  packet[size-1] = PACKET_END;

				  return packet;
				}
	
				int extractPacket(uint8_t const *buffer, size_t buffer_size) {
					if (buffer_size == 0) {
						return 0; //Empty buffer. Nothing to do.
					}

					//Packets starts with a @, so search for it and
				  //discard all data before
				  size_t readPos=0;
				  while (buffer[readPos] != PACKET_START && readPos < buffer_size) {
					  readPos++;
				  }
				  if(readPos>0){
					  return -readPos;
				  }

				  //decode packet len which is stored twice in two different formats
				  //this len is the size of the packet from byte 6 onwards
				  size_t len;
				  size_t hexlen = 0;
				  sscanf((const char*)&buffer[1],"%4X",&hexlen);
				  len = (buffer[5] | (buffer[6]<<8 ));

				  //check if both lengths are equal (simple check)
				  if(len != hexlen) {
					  return -1; //Corrupt
				  }

					//Ensure the buffer contains the full packet
					if (buffer_size < (readPos + len + 6)) {
						return 0; //Not enough data yet
					}

					//Validate and return
					if (isValidPacket(&buffer[readPos], len + 6)) {
						Packet.resize(len+6,0);
						memcpy(&Packet[0],&buffer[readPos],len+6);
						return len+6;
					}

					return 0;
				}

				int isValidPacket(uint8_t const *buffer, size_t buffer_size)
				{
				  //Packet is too small to be valid
				  if(buffer_size<14) 
					  return 0;

				  //Packets starts with a @, so search for it and
				  //discard all data before
				  size_t readPos=0;
				  while (buffer[readPos] != PACKET_START && readPos < buffer_size) {
					  readPos++;
				  }
				  if(readPos>0){
					  std::cout << "Corrupted packet: Skipping " << readPos << " bytes because no start was found." << std::endl;
					  return -readPos;
				  }

				  //decode packet len which is stored twice in two different formats
				  //this len is the size of the packet from byte 6 onwards
				  size_t len;
				  size_t hexlen = 0;
				  sscanf((const char*)&buffer[1],"%4X",&hexlen);
				  len = (buffer[5] | (buffer[6]<<8 ));

				  //check if both lengths are equal (simple check)
				  if(len != hexlen)
				  {
					  //LOG_WARN_S << "Corrupted packet: Binary packet size differs from hexadecimal: bin:"
						//         << len << " hex: "<< hexlen ;
					  return -1;      
				  }

				  //the first 5 bytes and the PACKED_END are not included in the len therefore 
				  //add them to get the total size of the message
				  len += 6;
				  if(len > buffer_size)
					  return 0;               //packet is to small wait for more data
				  //checking for the end of the packet 
				  if (buffer[len-1] == PACKET_END) 
				  {
				//DeviceType device_type = (DeviceType) buffer[8];
				PacketType type = (PacketType) buffer[10];
				std::cout << "Found packet of type "<< type << " and size "<< len << std::endl;

				//check packet size
				switch(type)
				{
				case mtHeadCommand:
				    if(len == 82)
				        return len;
				    break;
				case mtSendData:
				    if(len == 18)
				        return len;
				    break;
				case mtSendVersion:
				    if(len == 14)
				        return len;
				    break;
				case mtHeadData:
				    if(len > 45)
				    {
				        //read number of data bytes
				        uint16_t total = buffer[13]|(((uint16_t)buffer[14])<<8);
				        uint16_t data_bytes = buffer[42]|(((uint16_t)buffer[43])<<8);
				        if((uint16_t)len == data_bytes+45 && (uint16_t)len == total+14 )
				            return len;
				        //LOG_WARN_S << "Corrupted mtHeadData: Size miss match" ;
				    }
				    break;
				case mtAuxData:
				    if(len > 16)
				    {
				        uint16_t payload_size = buffer[13] | (buffer[14]<<8);
				        if((uint16_t)len == payload_size+16)
				            return len;
				        //LOG_WARN_S << "Corrupted mtAuxData: Size miss match" ;
				    }
				    break;
				case mtVersionData:
				    if(len == 25)
				        return len;
				    break;
				case mtReBoot:
				    if(len == 14)
				        return len;
				    break;
				case mtAlive:
				    if(len == 22)
				        return len;
				    break;
				case mtSendBBUser:
				    if(len == 14)
				        return len;
				    break;
				case mtBBUserData:
				    if(len == 175 || len == 264)  //dst sonars have a bigger packet 
				        return len;
				    break;
				default:
				    return len;
				}
		//        LOG_WARN_S << "Corrupted packet: Wrong packet size for packet type:"<< type <<" . size:" 
		//                   << len ;
				return -1;
			}
			//LOG_WARN_S << "Corrupted packet: No Message end was found" ;
			return -1; 
			}
		
		};

		class sonarInterface : protected uwe_sub::io::SerialPort, protected SeaNetPacket {
			protected:
				HeadCommand head_config;
				double speed_of_sound;

				bool waitForPacket(PacketType packet_type, uint64_t timeout_ms) {
					uint64_t startTime = getTimeMs64();
					while (1) {
						readPort();
						int sz = extractPacket(&buffer[0], buffer.size());
						while (sz != 0) {
							if (sz < 0) {
								buffer.erase(buffer.begin(), buffer.begin() - sz); //Delete some
								sz = extractPacket(&buffer[0], buffer.size());
							}
							else {
								buffer.erase(buffer.begin(), buffer.begin() + sz); //Delete some

						PacketType type = (PacketType)Packet[10];
								if (type == packet_type) return true;

								sz = extractPacket(&buffer[0], buffer.size());
							}
						}
						if (getTimeMs64() >= (startTime + timeout_ms)) break;
					}
					return false;
				}

				VersionData decodeVersionData()	{
					VersionData version;
					//if(getPacketType() != mtVersionData) return null;
					version.softwareVersion = Packet[13];
					version.infoBits = Packet[14];
					version.serialNr = Packet[15] | (Packet[16] <<8);
					version.programmLength = Packet[17] | (Packet[18] <<8) | (Packet[19] <<16) | (Packet[20] <<24);
					version.programmChecksum = Packet[21] | (Packet[22] << 8);
					version.nodeID = Packet[23];
					return version;
				}

				VersionData getVersionData() {
					//Request version data
					writePort(createPacket(mtSendVersion));

					if (waitForPacket(mtVersionData, 10000)) {
						return decodeVersionData();
					}
					VersionData v;
					v.nodeID = NULL;
					return v;
				}

				AliveData decodeAliveData()
				{
					AliveData data;
					//extract alive data data
					data.ready = Packet[20]&2;
					data.motor_on = Packet[20]&8;
					data.scanning = Packet[20]&32;
					data.no_config = Packet[20]&64;
					data.config_send = Packet[20]&128;
					return data;
				}

				ImagingHeadData decodeHeadData()
				{
						ImagingHeadData data;

						//extract alive data data
						data.node_type = Packet[12];
						data.type = Packet[10];
						data.packed_size    = Packet[13] | (Packet[14]<<8);
						data.device_type     = Packet[15];
						data.head_status     = Packet[16];
						data.sweep_code      = Packet[17];
						data.head_control   = Packet[18] | (Packet[19]<<8);
						data.range         = Packet[20] | (Packet[21]<<8);
						data.txn           = Packet[22] | (Packet[23]<<8) | (Packet[24]<<16) | (Packet[25]<<24);
						data.gain           = Packet[26];
						data.slope         = Packet[27] | (Packet[28]<<8);
						data.ad_span        = Packet[29];
						data.ad_low          = Packet[30];
						data.heading_offset = Packet[31] | (Packet[32]<<8);
						data.ad_interval    = Packet[33] | (Packet[34]<<8);
						data.left_limit     = Packet[35] | (Packet[36]<<8);
						data.right_limit    = Packet[37] | (Packet[38]<<8);
						data.motor_step_angle_size          = Packet[39];
						data.bearing       = Packet[40] | (Packet[41]<<8);
						data.data_bytes     = Packet[42] | (Packet[43]<<8);
						data.scan_data      = &Packet[44];
						return data;
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

				void sendDataPacket() {
					uint8_t time[4];
				memset(&time,0,4);
				writePort(createPacket(mtSendData,&time[0],4));
				}

				void writeHeadCommand(HeadCommand &head_config, int timeout)
				{
					AliveData alive_data;

					std::vector<uint8_t> packet = createPacket(mtHeadCommand,
							                                   (uint8_t*)&head_config, sizeof(head_config));
					//stop();
					//we have to wait until the device is no longer sending HeadData
					try
					{
						//while(waitForPacket(mtHeadData,300)); 
					}
					catch(std::runtime_error e)
					{}

					//LOG_DEBUG_S <<"Sent mtHeadCommand packet" ;
					writePort(packet);
				}

			public:
				int foundCount;

				void reset() {
					writePort(createPacket(mtReBoot,NULL,0));
				}

				int initialize(std::string const& port, int baudrate=115200) {
					foundCount = 0;
					if (openPort(port,baudrate,true)) {
						ROS_INFO("Sonar Connected");
                                                flushPort();
						if (waitForPacket(mtAlive, 10000)) {
							ROS_INFO("received mtAlive");
							VersionData v = getVersionData();
							if (v.nodeID != NULL) {
								std::cout << "Sonar Online: Software Version:" << (int)v.softwareVersion << std::endl;
								std::cout << "                     Info Bits:" << (int)v.infoBits << std::endl;
								std::cout << "                        Serial:" << (int)v.serialNr << std::endl;
								std::cout << "                       Node ID:" << (int)v.nodeID << std::endl;
								std::cout << "                Program Length:" << (int)v.programmLength << std::endl;
								std::cout << "              Program Checksum:" << (int)v.programmChecksum << std::endl;
	
								if (waitForPacket(mtAlive, 10000)) {
									AliveData d = decodeAliveData();
									std::cout << "mtAlive: Ready: " << (bool)d.ready << std::endl;
									std::cout << "      Motor On: " << (bool)d.motor_on << std::endl;
									std::cout << "      Scanning: " << (bool)d.scanning << std::endl;
									std::cout << "     No Config: " << (bool)d.no_config << std::endl;
									std::cout << "   Config Send: " << (bool)d.config_send << std::endl;

									return (int)d.ready;
								}
							}
						}
						else {
							ROS_INFO("No MtAlive Received... Resetting");
							reset();
						}
					}
					return 0;
				}

				void configure(const MicronConfig &config,uint32_t timeout)
				{
					//some conversions
					int ad_interval = (((config.resolution/config.speed_of_sound)*2.0)*1e9)/640.0; //FIXED
					int number_of_bins = config.max_distance/config.resolution; //FIXED

					uint16_t left_limit = (((M_PI-(-config.left_limit.rad))/(M_PI*2.0))*6399.0); //FIXED
					uint16_t right_limit = (((M_PI-(-config.right_limit.rad))/(M_PI*2.0))*6399.0); //FIXED

			
					uint16_t motor_step_angle_size = config.angular_resolution; //FIXED

					uint8_t initial_gain = config.gain*210; //FIXED
					uint16_t lockout_time = 2.0*config.min_distance/config.speed_of_sound*10e6; //FIXED

					speed_of_sound = config.speed_of_sound;

					//generate head data
					head_config.V3B_params = 0x1D; //Micron is dual channel. Indicate V3B params are appended
					head_config.head_type = 0x02;  //Sonar

					//Range Scale ******************************************
					//This isn't used by the sonar. But for our use later...
					//range_scale should be 10 * Desired Range In Meters.
					//IE: 75 Meter range should set range_scale to 750
					head_config.range_scale  = config.max_distance * 10; //Assume max distance is in meters
			
					head_config.left_limit   =left_limit; 
					head_config.right_limit  =right_limit;
	
					//ADSpan **********************************************
					//Controls the mapping of the bins received.
					//0 = 0dB, 255 = 80dB. Typically it should be 12dB
					//to 24dB (38 to 77).
					//Note: Min of 9dB in Tritech sofware (Unless ADLow is
					//			more than 70dB. IE: ADLow = 72dB, ADSpan = 8dB
					head_config.ad_span = (((int)(config.contrast*3.1875))<=255)?((int)(config.contrast*3.1875)):255;
					std::cout << "ad_span = " << (int)head_config.ad_span << " contrast = " << config.contrast << std::endl;
					//ADLow ***********************************************
					//Controls the base position of the bins received.
					//Essentially, this controls the sensitivity of the sonar
					//0 = 0dB, 255 = 80dB.
					//Typically should be 40 (13dB)
					//Note: Max of 78dB in Tritech software.
					//ADLow and ADSpan combined shouldn't be more than 80dB
					head_config.ad_low = (((int)(config.threshold*3.1875))<=255)?((int)(config.threshold*3.1875)):255;
					std::cout << "ad_low = " << (int)head_config.ad_low << " threshold = " << config.threshold << std::endl;

					//IGain ************************************************
					//0-255 = 0dB-80dB = 0-100%
					//Typically 40% (84)
					head_config.initial_gain_ch1 = initial_gain;
					head_config.initial_gain_ch2 = initial_gain;

					//MoTime ***********************************************
					//High speed limit of the motor in units of 10 microsecs
					//Default = 25 (250 microseconds)
					head_config.motor_step_delay_time = 25;

					//Step Angle Size **************************************
					//Motor steps between pings in 1/16 gradians units
					//Defaults: Low = 32 (1.8 degrees)
					//          Medium = 16 (0.9 degrees)
					//					High = 8 (0.45 degrees)
					//					Ultimate = 4 (0.225 degrees)
					head_config.motor_step_angle_size = motor_step_angle_size;

					//ADInterval and NBins **********************************
					//Probably the most important bit.
					head_config.ad_interval = ad_interval;
					head_config.number_of_bins = number_of_bins;

					//MAXADbuf **********************************************
					//System setting. Default should be used (500) but can
					//go up to 1000.
					head_config.max_ad_buff = (0xF4) | (1<<8); //500

					//Lockout ***************************************************
					//Time the sonar will start sampling after it has transmitted.
					//Default is 100;
					head_config.lockout_time = lockout_time;

					//IGNORE - Single axis sonar. 1600 & 1 should be used.
					head_config.minor_axis_dir = (0x40) | (0x06<<8); //1600
					head_config.major_axis_pan = (0x01); //1

					//Use channel 2. Raw & ReplyASL should always be on // ?!? OR'd with 8 to 'invert'
					head_config.head_control = (((!config.low_resolution)?ADC8ON:0)|(config.continuous?CONT:0)|(config.stare?STARELLIM:0)|8|RAW|HASMOT|REPLYASL|CHAN2 );
			
					//Using slope settings from old sonar driver... Don't know where
					//The values came from originally. Makes a HELL of a difference though!
					head_config.slope_ch1 = (0x5A) | (0x00<<8); //90
					head_config.slope_ch2 = (0x7D) | (0x00<<8); //125

					//TxPulseLength ****************************************
					//Length of the sonar transmit pulse in microseconds
					//Should be (Range(m)+10)*25/10
					head_config.pulse_length = (config.max_distance+10)*25/10;

					//TODO: Wait to stop receiving head data
					while (waitForPacket(mtHeadData, 500));
					writeHeadCommand(head_config,timeout);

					if (waitForPacket(mtAlive, 10000)) {
						AliveData d = decodeAliveData();
						std::cout << "mtAlive: Ready: " << (bool)d.ready << std::endl;
						std::cout << "      Motor On: " << (bool)d.motor_on << std::endl;
						std::cout << "      Scanning: " << (bool)d.scanning << std::endl;
						std::cout << "     No Config: " << (bool)d.no_config << std::endl;
						std::cout << "   Config Send: " << (bool)d.config_send << std::endl;
					}

				}

				int scan(SonarData &data) {
					sendDataPacket();
					if (waitForPacket(mtHeadData, 400)) {
						ImagingHeadData h = decodeHeadData();
						data.bearing = (float)h.bearing;
						std::cout << "Got head data... Bearing: " << (float)Angle::fromRad(-(h.bearing/6399.0*2.0*M_PI)+M_PI).getDeg() << std::endl;
						std::cout << "       Sampling Interval: " << ((640.0*h.ad_interval)*1e-9) << std::endl;
						size_t lockouts = head_config.lockout_time/(10e6*((640.0*h.ad_interval)*1e-9));
						std::cout << "Lockouts: " << lockouts;
						if ((h.head_control & ADC8ON) == 1) { //Full resolution
							std::cout << " Full resolution" << std::endl;
							data.bins.resize(h.data_bytes,0);
							memcpy(&data.bins[0]+lockouts, h.scan_data+lockouts, h.data_bytes-lockouts);
							std::cout << "Size of bins array: " << data.bins.size() << std::endl;
						}
						return 1;
					}
					return 0;
				}
			
				void close() {
					closePort();
				}
		};
	}
}
bool config_received = false;
uwe_sub::sonar::MicronConfig conf;

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

	conf.threshold = (double)config.threshold;  //0dB
	conf.contrast = (double)config.contrast; //12dB
	conf.gain = (double)config.gain/100.0; //40% Initial Gain
	conf.resolution = (double)config.resolution; //10cm sampling
	conf.max_distance = (double)config.max_distance; //10 meter range
	conf.min_distance = (double)config.min_distance; //Ignore the first 0.75 meters
	conf.left_limit = uwe_sub::sonar::Angle::fromDeg((double)config.left_limit);
	conf.right_limit = uwe_sub::sonar::Angle::fromDeg((double)config.right_limit);
	conf.continuous = config.continuous;
	conf.stare = config.stare;
	conf.angular_resolution = config.angular_resolution; //LOW, MEDIUM, HIGH
        //sonar.configure(conf,3000);

	//print conf. stuff
	std::cout << "conf." << std::endl;
	std::cout << "conf.threshold " << conf.threshold << std::endl;
	std::cout << "conf.contrast " << conf.contrast << std::endl;
	std::cout << "conf.gain " << conf.gain << std::endl;
	std::cout << "conf.resolution " << conf.resolution << std::endl;
	std::cout << "conf.min dist " << conf.min_distance << std::endl;
	std::cout << "conf.max dist " << conf.max_distance << std::endl;
	//problem printing left & right limits :(
	std::cout << "conf.continuous " << conf.continuous << std::endl;
	std::cout << "conf.stare " << conf.stare << std::endl;
	std::cout << "conf.ang resolution " << conf.angular_resolution << std::endl;
	config_received = true;
}

/******************************************************
 * 
 *  Main; the master of functions, the definer of variables.
 * 
 * ***************************************************/
int main( int argc, char **argv )
{

	ros::init(argc, argv, "sonar_interface");

	ros::NodeHandle n;

	ros::Publisher sonarMsg = n.advertise<custom_msg::SonarData>("sonar", 100);

	//Subscribe to sonar config changes
	ros::Subscriber sonarSub = n.subscribe("sonar_config", 1, sonarConfigCallBack);
	
	custom_msg::SonarData sonarDataOut;

	//Setup defaults
	/* Verify there have been some arguments */
	if (argc == 12) {
	    conf.threshold = atof(argv[1]); //Read the configuration
	    conf.contrast = atof(argv[2]); //Read the configuration
	    conf.gain = atof(argv[3]); //Read the configuration
	    conf.resolution = atof(argv[4]); //Read the configuration
	    conf.min_distance = atof(argv[5]); //Read the configuration
	    conf.max_distance = atof(argv[6]); //Read the configuration
	    conf.left_limit = uwe_sub::sonar::Angle::fromDeg(atof(argv[7])); //Read the configuration
	    conf.right_limit = uwe_sub::sonar::Angle::fromDeg(atof(argv[8])); //Read the configuration
	    conf.continuous = (atoi(argv[9]) == 1);
	    conf.stare = (atoi(argv[10]) == 1);
	    sscanf(argv[11], "%u", &conf.angular_resolution);
	    std::cout << "Running with args: " << std::endl <<
			 "Threshold: " << conf.threshold << std::endl <<
			 "Contrast:  " << conf.contrast << std::endl;
	}
	else {
       	    conf.threshold = 10;  //0dB
	    conf.contrast = 15; //12dB
	    conf.gain = 0.3; //40% Initial Gain
	    conf.resolution = 0.8; //10cm sampling
	    conf.max_distance = 75.0; //10 meter range
	    conf.min_distance = 0; //Ignore the first 0.75 meters
	    conf.left_limit = uwe_sub::sonar::Angle::fromDeg(-45.0);
	    conf.right_limit = uwe_sub::sonar::Angle::fromDeg(45.0);
	    conf.continuous = true;
	    conf.stare = false;
	    conf.angular_resolution = uwe_sub::sonar::LOW; //LOW, MEDIUM, HIGH
	}

	int offline_count = 0;

	ros::Rate loop_rate(100);
	while (ros::ok()) {
		config_received = false;
		//Create a new sonar interface
		uwe_sub::sonar::sonarInterface sonar;
		/* Open and Configure the Serial Port. */
		if (sonar.initialize("/dev/ttyS0")) {
			offline_count = 0;
			std::cout << "Port open" << std::endl;
			//uwe_sub::sonar::MicronConfig conf;

			/*NOTES ON CONFIGURATION:
				gain:	Gain represented as a percentage. 0.0 to 1.0 (0% to 100%)
				angular_resolution: uwe_sub::sonar::LOW, MEDIUM, or HIGH 
													(1.8, 0.9, 0.45 degrees per step)
				resolution: Distance between each bin in meters
				max_distance: Max range of a scan in meters
				min_distance: Min range of a scan in meters
				left_limit: in radians
				right_limit: in radians
				continous: 360 degree scanning. If you want sector scanning, set
						   to false and set left/right limits.
				stare: Causes the head to stare at it's left_limit when
					   it reaches it.
			*/

		        sonar.configure(conf,3000);
			while(ros::ok() && (!config_received))
			{
				uwe_sub::sonar::SonarData data;
				if (sonar.scan(data)) {
					//Store all the data in the new sonar message
					static int last_bearing = data.bearing;
					static int jump_diff = 0;
					static bool first_run = true;
					static int last_resolution = conf.resolution;

					if (conf.continuous) {
						//ROS_INFO("Data: %i, Last: %i", data.bearing, last_bearing);
						int bearing_diff = (data.bearing+6400) - (last_bearing+6400);
						if ((bearing_diff < 6399) && (!first_run) && (last_resolution != conf.resolution)) {
						   	if ((bearing_diff > 500) || (bearing_diff < -500)) {
								//Probably jumped a few degrees.
								ROS_WARN("JUMPED... correcting");
								data.bearing = last_bearing + jump_diff;
							}
							else { jump_diff = bearing_diff; }
						}
					}
					first_run = false;
					last_resolution = conf.resolution;
					sonarDataOut.bearing = data.bearing;
					while (sonarDataOut.bearing > 6399) { sonarDataOut.bearing -= 6400; }
					sonarDataOut.threshold = conf.threshold;
					sonarDataOut.contrast = conf.contrast;
					sonarDataOut.min_distance = conf.min_distance;
					sonarDataOut.max_distance = conf.max_distance;
					sonarDataOut.resolution = conf.resolution;
					sonarDataOut.bins.data.clear();
					for (int k = 0; k < data.bins.size(); k++)
					{
						sonarDataOut.bins.data.push_back(data.bins[k]);
					}
					//publish the data
					sonarMsg.publish(sonarDataOut);

					//Store the last bearing.
					last_bearing = data.bearing;

					//Print to the screen
					for (int i = 0; i < data.bins.size(); i++) {
						if ((i != 0) && (i%10==0)) printf("\n");
						printf("[%02X] ", data.bins[i]);
					}
					printf("\n");
				}
	
				ros::spinOnce();	
			}
			sonar.close();
			ROS_INFO("Closed Sonar - New sonar config");
		}
		else {
			offline_count++;
			if (offline_count >= 2) 
			{
				std::cout << "Resetting sonar..." << std::endl;
				sonar.reset();
				offline_count = 0;
			}
			else {
				std::cout << "Sonar not ready yet." << std::endl;
			}
		}
	}
	return 0;
}
