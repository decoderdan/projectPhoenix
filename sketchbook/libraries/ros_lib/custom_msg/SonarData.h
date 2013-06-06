#ifndef _ROS_custom_msg_SonarData_h
#define _ROS_custom_msg_SonarData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Int32MultiArray.h"

namespace custom_msg
{

  class SonarData : public ros::Msg
  {
    public:
      float bearing;
      float threshold;
      float contrast;
      float min_distance;
      float max_distance;
      float resolution;
      std_msgs::Int32MultiArray bins;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_bearing;
      u_bearing.real = this->bearing;
      *(outbuffer + offset + 0) = (u_bearing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bearing.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bearing.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bearing.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bearing);
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
      offset += this->bins.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_bearing;
      u_bearing.base = 0;
      u_bearing.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bearing.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bearing.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bearing.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bearing = u_bearing.real;
      offset += sizeof(this->bearing);
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
      offset += this->bins.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "custom_msg/SonarData"; };
    const char * getMD5(){ return "309be5194d79c53268060b45eeee6151"; };

  };

}
#endif