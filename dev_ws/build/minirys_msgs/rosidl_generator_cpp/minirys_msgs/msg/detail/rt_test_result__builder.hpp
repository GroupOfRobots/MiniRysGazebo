// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from minirys_msgs:msg/RTTestResult.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__BUILDER_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "minirys_msgs/msg/detail/rt_test_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace minirys_msgs
{

namespace msg
{

namespace builder
{

class Init_RTTestResult_major_pagefaults
{
public:
  explicit Init_RTTestResult_major_pagefaults(::minirys_msgs::msg::RTTestResult & msg)
  : msg_(msg)
  {}
  ::minirys_msgs::msg::RTTestResult major_pagefaults(::minirys_msgs::msg::RTTestResult::_major_pagefaults_type arg)
  {
    msg_.major_pagefaults = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_msgs::msg::RTTestResult msg_;
};

class Init_RTTestResult_minor_pagefaults
{
public:
  explicit Init_RTTestResult_minor_pagefaults(::minirys_msgs::msg::RTTestResult & msg)
  : msg_(msg)
  {}
  Init_RTTestResult_major_pagefaults minor_pagefaults(::minirys_msgs::msg::RTTestResult::_minor_pagefaults_type arg)
  {
    msg_.minor_pagefaults = std::move(arg);
    return Init_RTTestResult_major_pagefaults(msg_);
  }

private:
  ::minirys_msgs::msg::RTTestResult msg_;
};

class Init_RTTestResult_max_latency
{
public:
  explicit Init_RTTestResult_max_latency(::minirys_msgs::msg::RTTestResult & msg)
  : msg_(msg)
  {}
  Init_RTTestResult_minor_pagefaults max_latency(::minirys_msgs::msg::RTTestResult::_max_latency_type arg)
  {
    msg_.max_latency = std::move(arg);
    return Init_RTTestResult_minor_pagefaults(msg_);
  }

private:
  ::minirys_msgs::msg::RTTestResult msg_;
};

class Init_RTTestResult_min_latency
{
public:
  explicit Init_RTTestResult_min_latency(::minirys_msgs::msg::RTTestResult & msg)
  : msg_(msg)
  {}
  Init_RTTestResult_max_latency min_latency(::minirys_msgs::msg::RTTestResult::_min_latency_type arg)
  {
    msg_.min_latency = std::move(arg);
    return Init_RTTestResult_max_latency(msg_);
  }

private:
  ::minirys_msgs::msg::RTTestResult msg_;
};

class Init_RTTestResult_mean_latency
{
public:
  explicit Init_RTTestResult_mean_latency(::minirys_msgs::msg::RTTestResult & msg)
  : msg_(msg)
  {}
  Init_RTTestResult_min_latency mean_latency(::minirys_msgs::msg::RTTestResult::_mean_latency_type arg)
  {
    msg_.mean_latency = std::move(arg);
    return Init_RTTestResult_min_latency(msg_);
  }

private:
  ::minirys_msgs::msg::RTTestResult msg_;
};

class Init_RTTestResult_current_latency
{
public:
  explicit Init_RTTestResult_current_latency(::minirys_msgs::msg::RTTestResult & msg)
  : msg_(msg)
  {}
  Init_RTTestResult_mean_latency current_latency(::minirys_msgs::msg::RTTestResult::_current_latency_type arg)
  {
    msg_.current_latency = std::move(arg);
    return Init_RTTestResult_mean_latency(msg_);
  }

private:
  ::minirys_msgs::msg::RTTestResult msg_;
};

class Init_RTTestResult_stamp
{
public:
  Init_RTTestResult_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RTTestResult_current_latency stamp(::minirys_msgs::msg::RTTestResult::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_RTTestResult_current_latency(msg_);
  }

private:
  ::minirys_msgs::msg::RTTestResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_msgs::msg::RTTestResult>()
{
  return minirys_msgs::msg::builder::Init_RTTestResult_stamp();
}

}  // namespace minirys_msgs

#endif  // MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__BUILDER_HPP_
