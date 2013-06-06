#ifndef _ROS_custom_msg_MotorConfig_h
#define _ROS_custom_msg_MotorConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msg
{

  class MotorConfig : public ros::Msg
  {
    public:
      int8_t front;
      int8_t back;
      int8_t front_right;
      int8_t back_right;
      int8_t front_left;
      int8_t back_left;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_front;
      u_front.real = this->front;
      *(outbuffer + offset + 0) = (u_front.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front);
      union {
        int8_t real;
        uint8_t base;
      } u_back;
      u_back.real = this->back;
      *(outbuffer + offset + 0) = (u_back.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->back);
      union {
        int8_t real;
        uint8_t base;
      } u_front_right;
      u_front_right.real = this->front_right;
      *(outbuffer + offset + 0) = (u_front_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_right);
      union {
        int8_t real;
        uint8_t base;
      } u_back_right;
      u_back_right.real = this->back_right;
      *(outbuffer + offset + 0) = (u_back_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->back_right);
      union {
        int8_t real;
        uint8_t base;
      } u_front_left;
      u_front_left.real = this->front_left;
      *(outbuffer + offset + 0) = (u_front_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_left);
      union {
        int8_t real;
        uint8_t base;
      } u_back_left;
      u_back_left.real = this->back_left;
      *(outbuffer + offset + 0) = (u_back_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->back_left);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_front;
      u_front.base = 0;
      u_front.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front = u_front.real;
      offset += sizeof(this->front);
      union {
        int8_t real;
        uint8_t base;
      } u_back;
      u_back.base = 0;
      u_back.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->back = u_back.real;
      offset += sizeof(this->back);
      union {
        int8_t real;
        uint8_t base;
      } u_front_right;
      u_front_right.base = 0;
      u_front_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_right = u_front_right.real;
      offset += sizeof(this->front_right);
      union {
        int8_t real;
        uint8_t base;
      } u_back_right;
      u_back_right.base = 0;
      u_back_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->back_right = u_back_right.real;
      offset += sizeof(this->back_right);
      union {
        int8_t real;
        uint8_t base;
      } u_front_left;
      u_front_left.base = 0;
      u_front_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_left = u_front_left.real;
      offset += sizeof(this->front_left);
      union {
        int8_t real;
        uint8_t base;
      } u_back_left;
      u_back_left.base = 0;
      u_back_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->back_left = u_back_left.real;
      offset += sizeof(this->back_left);
     return offset;
    }

    const char * getType(){ return "custom_msg/MotorConfig"; };
    const char * getMD5(){ return "0d2bdd7715a3b4f9c71fa4aa5bd10a18"; };

  };

}
#endif