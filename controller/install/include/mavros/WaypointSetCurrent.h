/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by gensrv_cpp from file /home/lintang-sutawika/krai/trui-bot-prj/controller/src/mavros/srv/WaypointSetCurrent.srv
 *
 */


#ifndef MAVROS_MESSAGE_WAYPOINTSETCURRENT_H
#define MAVROS_MESSAGE_WAYPOINTSETCURRENT_H

#include <ros/service_traits.h>


#include <mavros/WaypointSetCurrentRequest.h>
#include <mavros/WaypointSetCurrentResponse.h>


namespace mavros
{

struct WaypointSetCurrent
{

typedef WaypointSetCurrentRequest Request;
typedef WaypointSetCurrentResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct WaypointSetCurrent
} // namespace mavros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::mavros::WaypointSetCurrent > {
  static const char* value()
  {
    return "f99aa1a911a80ab546ea470f4e90c807";
  }

  static const char* value(const ::mavros::WaypointSetCurrent&) { return value(); }
};

template<>
struct DataType< ::mavros::WaypointSetCurrent > {
  static const char* value()
  {
    return "mavros/WaypointSetCurrent";
  }

  static const char* value(const ::mavros::WaypointSetCurrent&) { return value(); }
};


// service_traits::MD5Sum< ::mavros::WaypointSetCurrentRequest> should match 
// service_traits::MD5Sum< ::mavros::WaypointSetCurrent > 
template<>
struct MD5Sum< ::mavros::WaypointSetCurrentRequest>
{
  static const char* value()
  {
    return MD5Sum< ::mavros::WaypointSetCurrent >::value();
  }
  static const char* value(const ::mavros::WaypointSetCurrentRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros::WaypointSetCurrentRequest> should match 
// service_traits::DataType< ::mavros::WaypointSetCurrent > 
template<>
struct DataType< ::mavros::WaypointSetCurrentRequest>
{
  static const char* value()
  {
    return DataType< ::mavros::WaypointSetCurrent >::value();
  }
  static const char* value(const ::mavros::WaypointSetCurrentRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::mavros::WaypointSetCurrentResponse> should match 
// service_traits::MD5Sum< ::mavros::WaypointSetCurrent > 
template<>
struct MD5Sum< ::mavros::WaypointSetCurrentResponse>
{
  static const char* value()
  {
    return MD5Sum< ::mavros::WaypointSetCurrent >::value();
  }
  static const char* value(const ::mavros::WaypointSetCurrentResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros::WaypointSetCurrentResponse> should match 
// service_traits::DataType< ::mavros::WaypointSetCurrent > 
template<>
struct DataType< ::mavros::WaypointSetCurrentResponse>
{
  static const char* value()
  {
    return DataType< ::mavros::WaypointSetCurrent >::value();
  }
  static const char* value(const ::mavros::WaypointSetCurrentResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MAVROS_MESSAGE_WAYPOINTSETCURRENT_H
