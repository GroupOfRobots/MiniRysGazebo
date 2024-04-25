// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from minirys_msgs:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "minirys_msgs/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace minirys_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: speed_l
  {
    out << "speed_l: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_l, out);
    out << ", ";
  }

  // member: speed_r
  {
    out << "speed_r: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_r, out);
    out << ", ";
  }

  // member: enable
  {
    out << "enable: ";
    rosidl_generator_traits::value_to_yaml(msg.enable, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: speed_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_l: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_l, out);
    out << "\n";
  }

  // member: speed_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_r: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_r, out);
    out << "\n";
  }

  // member: enable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enable: ";
    rosidl_generator_traits::value_to_yaml(msg.enable, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorCommand & msg, bool use_flow_style = false)
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
  const minirys_msgs::msg::MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  minirys_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use minirys_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const minirys_msgs::msg::MotorCommand & msg)
{
  return minirys_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<minirys_msgs::msg::MotorCommand>()
{
  return "minirys_msgs::msg::MotorCommand";
}

template<>
inline const char * name<minirys_msgs::msg::MotorCommand>()
{
  return "minirys_msgs/msg/MotorCommand";
}

template<>
struct has_fixed_size<minirys_msgs::msg::MotorCommand>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<minirys_msgs::msg::MotorCommand>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<minirys_msgs::msg::MotorCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MINIRYS_MSGS__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
