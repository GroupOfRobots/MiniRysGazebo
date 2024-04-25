// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from minirys_msgs:msg/RTTestResult.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__TRAITS_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "minirys_msgs/msg/detail/rt_test_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace minirys_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RTTestResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
    out << ", ";
  }

  // member: current_latency
  {
    out << "current_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.current_latency, out);
    out << ", ";
  }

  // member: mean_latency
  {
    out << "mean_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_latency, out);
    out << ", ";
  }

  // member: min_latency
  {
    out << "min_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.min_latency, out);
    out << ", ";
  }

  // member: max_latency
  {
    out << "max_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.max_latency, out);
    out << ", ";
  }

  // member: minor_pagefaults
  {
    out << "minor_pagefaults: ";
    rosidl_generator_traits::value_to_yaml(msg.minor_pagefaults, out);
    out << ", ";
  }

  // member: major_pagefaults
  {
    out << "major_pagefaults: ";
    rosidl_generator_traits::value_to_yaml(msg.major_pagefaults, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RTTestResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }

  // member: current_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.current_latency, out);
    out << "\n";
  }

  // member: mean_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mean_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.mean_latency, out);
    out << "\n";
  }

  // member: min_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.min_latency, out);
    out << "\n";
  }

  // member: max_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.max_latency, out);
    out << "\n";
  }

  // member: minor_pagefaults
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "minor_pagefaults: ";
    rosidl_generator_traits::value_to_yaml(msg.minor_pagefaults, out);
    out << "\n";
  }

  // member: major_pagefaults
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "major_pagefaults: ";
    rosidl_generator_traits::value_to_yaml(msg.major_pagefaults, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RTTestResult & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace minirys_msgs

namespace rosidl_generator_traits
{

[[deprecated("use minirys_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const minirys_msgs::msg::RTTestResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  minirys_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use minirys_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const minirys_msgs::msg::RTTestResult & msg)
{
  return minirys_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<minirys_msgs::msg::RTTestResult>()
{
  return "minirys_msgs::msg::RTTestResult";
}

template<>
inline const char * name<minirys_msgs::msg::RTTestResult>()
{
  return "minirys_msgs/msg/RTTestResult";
}

template<>
struct has_fixed_size<minirys_msgs::msg::RTTestResult>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<minirys_msgs::msg::RTTestResult>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<minirys_msgs::msg::RTTestResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__TRAITS_HPP_
