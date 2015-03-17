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
 * Auto-generated by gensrv_cpp from file /home/lintang-sutawika/krai/trui-bot-prj/controller/src/mavros/srv/FileOpen.srv
 *
 */


#ifndef MAVROS_MESSAGE_FILEOPEN_H
#define MAVROS_MESSAGE_FILEOPEN_H

#include <ros/service_traits.h>


#include <mavros/FileOpenRequest.h>
#include <mavros/FileOpenResponse.h>


namespace mavros
{

struct FileOpen
{

typedef FileOpenRequest Request;
typedef FileOpenResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct FileOpen
} // namespace mavros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::mavros::FileOpen > {
  static const char* value()
  {
    return "99a3f49cc67b91477cf49ff15c42af0e";
  }

  static const char* value(const ::mavros::FileOpen&) { return value(); }
};

template<>
struct DataType< ::mavros::FileOpen > {
  static const char* value()
  {
    return "mavros/FileOpen";
  }

  static const char* value(const ::mavros::FileOpen&) { return value(); }
};


// service_traits::MD5Sum< ::mavros::FileOpenRequest> should match 
// service_traits::MD5Sum< ::mavros::FileOpen > 
template<>
struct MD5Sum< ::mavros::FileOpenRequest>
{
  static const char* value()
  {
    return MD5Sum< ::mavros::FileOpen >::value();
  }
  static const char* value(const ::mavros::FileOpenRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros::FileOpenRequest> should match 
// service_traits::DataType< ::mavros::FileOpen > 
template<>
struct DataType< ::mavros::FileOpenRequest>
{
  static const char* value()
  {
    return DataType< ::mavros::FileOpen >::value();
  }
  static const char* value(const ::mavros::FileOpenRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::mavros::FileOpenResponse> should match 
// service_traits::MD5Sum< ::mavros::FileOpen > 
template<>
struct MD5Sum< ::mavros::FileOpenResponse>
{
  static const char* value()
  {
    return MD5Sum< ::mavros::FileOpen >::value();
  }
  static const char* value(const ::mavros::FileOpenResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros::FileOpenResponse> should match 
// service_traits::DataType< ::mavros::FileOpen > 
template<>
struct DataType< ::mavros::FileOpenResponse>
{
  static const char* value()
  {
    return DataType< ::mavros::FileOpen >::value();
  }
  static const char* value(const ::mavros::FileOpenResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MAVROS_MESSAGE_FILEOPEN_H
