#ifndef _SEA_NET_PACKET_HPP_
#define _SEA_NET_PACKET_HPP_

#include <vector>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

namespace uwe_sub {

	namespace sonar {

		static const char PACKET_START = '@';
		static const char PACKET_END = 0x0A;

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
				std::vector<uint8_t> createPacket(uwe_sub::sonar::PacketType packet_type);
				std::vector<uint8_t> createPacket(uwe_sub::sonar::PacketType packet_type, uint8_t* payload, size_t payload_size);
				int extractPacket(uint8_t const *buffer, size_t buffer_size);
				int isValidPacket(uint8_t const *buffer, size_t buffer_size);
		};
	}
}
#endif
