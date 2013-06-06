#ifndef _ROS_custom_msg_IMUData_h
#define _ROS_custom_msg_IMUData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msg
{

  class IMUData : public ros::Msg
  {
    public:
      float yaw;
      float pitch;
      float roll;
      float acc_x;
      float acc_y;
      float acc_z;
      float vel_x;
      float vel_y;
      float vel_z;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_acc_x;
      u_acc_x.real = this->acc_x;
      *(outbuffer + offset + 0) = (u_acc_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc_x);
      union {
        float real;
        uint32_t base;
      } u_acc_y;
      u_acc_y.real = this->acc_y;
      *(outbuffer + offset + 0) = (u_acc_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc_y);
      union {
        float real;
        uint32_t base;
      } u_acc_z;
      u_acc_z.real = this->acc_z;
      *(outbuffer + offset + 0) = (u_acc_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc_z);
      union {
        float real;
        uint32_t base;
      } u_vel_x;
      u_vel_x.real = this->vel_x;
      *(outbuffer + offset + 0) = (u_vel_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_x);
      union {
        float real;
        uint32_t base;
      } u_vel_y;
      u_vel_y.real = this->vel_y;
      *(outbuffer + offset + 0) = (u_vel_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_y);
      union {
        float real;
        uint32_t base;
      } u_vel_z;
      u_vel_z.real = this->vel_z;
      *(outbuffer + offset + 0) = (u_vel_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_acc_x;
      u_acc_x.base = 0;
      u_acc_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acc_x = u_acc_x.real;
      offset += sizeof(this->acc_x);
      union {
        float real;
        uint32_t base;
      } u_acc_y;
      u_acc_y.base = 0;
      u_acc_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acc_y = u_acc_y.real;
      offset += sizeof(this->acc_y);
      union {
        float real;
        uint32_t base;
      } u_acc_z;
      u_acc_z.base = 0;
      u_acc_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acc_z = u_acc_z.real;
      offset += sizeof(this->acc_z);
      union {
        float real;
        uint32_t base;
      } u_vel_x;
      u_vel_x.base = 0;
      u_vel_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel_x = u_vel_x.real;
      offset += sizeof(this->vel_x);
      union {
        float real;
        uint32_t base;
      } u_vel_y;
      u_vel_y.base = 0;
      u_vel_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel_y = u_vel_y.real;
      offset += sizeof(this->vel_y);
      union {
        float real;
        uint32_t base;
      } u_vel_z;
      u_vel_z.base = 0;
      u_vel_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel_z = u_vel_z.real;
      offset += sizeof(this->vel_z);
     return offset;
    }

    const char * getType(){ return "custom_msg/IMUData"; };
    const char * getMD5(){ return "e33b22d8a8de4d1e6eaa544318f91d83"; };

  };

}
#endif