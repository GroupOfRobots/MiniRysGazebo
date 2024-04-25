// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from minirys_msgs:msg/AngularPose.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__TRAITS_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "minirys_msgs/msg/detail/angular_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace minirys_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AngularPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: angular_position
  {
    out << "angular_position: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_position, out);
    out << ", ";
  }

  // member: angular_velocity
  {
    out << "angular_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AngularPose & msg,
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

  // member: angular_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_position: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_position, out);
    out << "\n";
  }

  // member: angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AngularPose & msg, bool use_flow_style = false)
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
  const minirys_msgs::msg::AngularPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  minirys_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use minirys_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const minirys_msgs::msg::AngularPose & msg)
{
  return minirys_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<minirys_msgs::msg::AngularPose>()
{
  return "minirys_msgs::msg::AngularPose";
}

template<>
inline const char * name<minirys_msgs::msg::AngularPose>()
{
  return "minirys_msgs/msg/AngularPose";
}

template<>
struct has_fixed_size<minirys_msgs::msg::AngularPose>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<minirys_msgs::msg::AngularPose>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<minirys_msgs::msg::AngularPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__TRAITS_HPP_
