#ifndef _ROS_custom_msg_SonarConfig_h
#define _ROS_custom_msg_SonarConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msg
{

  class SonarConfig : public ros::Msg
  {
    public:
      float threshold;
      float contrast;
      float min_distance;
      float max_distance;
      float resolution;
      float gain;
      float left_limit;
      float right_limit;
      bool continuous;
      bool stare;
      int8_t angular_resolution;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_threshold;
      u_threshold.real = this->threshold;
      *(outbuffer + offset + 0) = (u_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->threshold);
      union {
        float real;
        uint32_t base;
      } u_contrast;
      u_contrast.real = this->contrast;
      *(outbuffer + offset + 0) = (u_contrast.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_contrast.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_contrast.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_contrast.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contrast);
      union {
        float real;
        uint32_t base;
      } u_min_distance;
      u_min_distance.real = this->min_distance;
      *(outbuffer + offset + 0) = (u_min_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_distance);
      union {
        float real;
        uint32_t base;
      } u_max_distance;
      u_max_distance.real = this->max_distance;
      *(outbuffer + offset + 0) = (u_max_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_distance);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution);
      union {
        float real;
        uint32_t base;
      } u_gain;
      u_gain.real = this->gain;
      *(outbuffer + offset + 0) = (u_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gain.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gain);
      union {
        float real;
        uint32_t base;
      } u_left_limit;
      u_left_limit.real = this->left_limit;
      *(outbuffer + offset + 0) = (u_left_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_limit);
      union {
        float real;
        uint32_t base;
      } u_right_limit;
      u_right_limit.real = this->right_limit;
      *(outbuffer + offset + 0) = (u_right_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_limit);
      union {
        bool real;
        uint8_t base;
      } u_continuous;
      u_continuous.real = this->continuous;
      *(outbuffer + offset + 0) = (u_continuous.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->continuous);
      union {
        bool real;
        uint8_t base;
      } u_stare;
      u_stare.real = this->stare;
      *(outbuffer + offset + 0) = (u_stare.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stare);
      union {
        int8_t real;
        uint8_t base;
      } u_angular_resolution;
      u_angular_resolution.real = this->angular_resolution;
      *(outbuffer + offset + 0) = (u_angular_resolution.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->angular_resolution);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_threshold;
      u_threshold.base = 0;
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->threshold = u_threshold.real;
      offset += sizeof(this->threshold);
      union {
        float real;
        uint32_t base;
      } u_contrast;
      u_contrast.base = 0;
      u_contrast.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_contrast.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_contrast.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_contrast.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->contrast = u_contrast.real;
      offset += sizeof(this->contrast);
      union {
        float real;
        uint32_t base;
      } u_min_distance;
      u_min_distance.base = 0;
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_distance = u_min_distance.real;
      offset += sizeof(this->min_distance);
      union {
        float real;
        uint32_t base;
      } u_max_distance;
      u_max_distance.base = 0;
      u_max_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_distance = u_max_distance.real;
      offset += sizeof(this->max_distance);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
      union {
        float real;
        uint32_t base;
      } u_gain;
      u_gain.base = 0;
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gain = u_gain.real;
      offset += sizeof(this->gain);
      union {
        float real;
        uint32_t base;
      } u_left_limit;
      u_left_limit.base = 0;
      u_left_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_limit = u_left_limit.real;
      offset += sizeof(this->left_limit);
      union {
        float real;
        uint32_t base;
      } u_right_limit;
      u_right_limit.base = 0;
      u_right_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_limit = u_right_limit.real;
      offset += sizeof(this->right_limit);
      union {
        bool real;
        uint8_t base;
      } u_continuous;
      u_continuous.base = 0;
      u_continuous.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->continuous = u_continuous.real;
      offset += sizeof(this->continuous);
      union {
        bool real;
        uint8_t base;
      } u_stare;
      u_stare.base = 0;
      u_stare.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stare = u_stare.real;
      offset += sizeof(this->stare);
      union {
        int8_t real;
        uint8_t base;
      } u_angular_resolution;
      u_angular_resolution.base = 0;
      u_angular_resolution.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->angular_resolution = u_angular_resolution.real;
      offset += sizeof(this->angular_resolution);
     return offset;
    }

    const char * getType(){ return "custom_msg/SonarConfig"; };
    const char * getMD5(){ return "c5e62524de5448688c893991a0f35975"; };

  };

}
#endif