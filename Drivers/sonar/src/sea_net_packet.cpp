#include <sonar/sea_net_packet.hpp>

namespace uwe_sub {
	
	namespace sonar {

		std::vector<uint8_t> SeaNetPacket::createPacket(uwe_sub::sonar::PacketType packet_type) {
			//Test for now.
			return createPacket(packet_type, NULL, 0);
		}

		std::vector<uint8_t> SeaNetPacket::createPacket(uwe_sub::sonar::PacketType packet_type, uint8_t* payload, size_t payload_size) {

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
			if(payload_size && payload) {
				memcpy(&packet[13],payload,payload_size);
			}

			packet[size-1] = PACKET_END;

			return packet;
		}

		int SeaNetPacket::extractPacket(uint8_t const *buffer, size_t buffer_size) {
			if (buffer_size == 0) {
				return 0; //Empty buffer. Nothing to do.
			}

			//Packets starts with a @, so search for it and
			//discard all data before
			size_t readPos=0;
			while (buffer[readPos] != PACKET_START && readPos < buffer_size) {
				readPos++;
			}

			if (readPos>0) {
				return -readPos; //Packet not at start of buffer
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

		int SeaNetPacket::isValidPacket(uint8_t const *buffer, size_t buffer_size)
		{
			//Packet is too small to be valid
			if (buffer_size < 14) return 0;

			//Packets starts with a @, so search for it and
			//discard all data before
			size_t readPos = 0;
			while (buffer[readPos] != PACKET_START && readPos < buffer_size) {
				readPos++;
			}
	
			if (readPos > 0) {
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
				return -1;      
			}

			//the first 5 bytes and the PACKED_END are not included in the len therefore 
			//add them to get the total size of the message
			len += 6;
			if(len > buffer_size) return 0; //packet is to small wait for more data

			//checking for the end of the packet 
			if (buffer[len-1] == PACKET_END) {
				PacketType type = (PacketType) buffer[10];

				//check packet size
				switch(type)
				{
					case mtHeadCommand:
						if(len == 82) return len;
						break;
					case mtSendData:
						if(len == 18) return len;
						break;
					case mtSendVersion:
						if(len == 14) return len;
						break;
					case mtHeadData:
						if(len > 45) {
							//read number of data bytes
							uint16_t total = buffer[13]|(((uint16_t)buffer[14])<<8);
							uint16_t data_bytes = buffer[42]|(((uint16_t)buffer[43])<<8);
							if((uint16_t)len == data_bytes+45 && (uint16_t)len == total+14 ) return len;
						}
						break;
					case mtAuxData:
						if(len > 16) {
							uint16_t payload_size = buffer[13] | (buffer[14]<<8);
							if((uint16_t)len == payload_size+16) return len;
						}
					break;
					case mtVersionData:
						if(len == 25) return len;
						break;
					case mtReBoot:
						if(len == 14) return len;
						break;
					case mtAlive:
						if(len == 22) return len;
						break;
					case mtSendBBUser:
						if(len == 14) return len;
						break;
					case mtBBUserData:
						if(len == 175 || len == 264) return len;
						break;
					default:
						return len;
				}
			
				return -1;
			}
			
			return -1;
		}

	}
}
