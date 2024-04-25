// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from minirys_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "minirys_msgs/msg/detail/battery_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace minirys_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BatteryStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: voltage_cell1
  {
    out << "voltage_cell1: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_cell1, out);
    out << ", ";
  }

  // member: voltage_cell2
  {
    out << "voltage_cell2: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_cell2, out);
    out << ", ";
  }

  // member: voltage_cell3
  {
    out << "voltage_cell3: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_cell3, out);
    out << ", ";
  }

  // member: undervoltage_warning
  {
    out << "undervoltage_warning: ";
    rosidl_generator_traits::value_to_yaml(msg.undervoltage_warning, out);
    out << ", ";
  }

  // member: undervoltage_error
  {
    out << "undervoltage_error: ";
    rosidl_generator_traits::value_to_yaml(msg.undervoltage_error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BatteryStatus & msg,
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

  // member: voltage_cell1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage_cell1: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_cell1, out);
    out << "\n";
  }

  // member: voltage_cell2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage_cell2: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_cell2, out);
    out << "\n";
  }

  // member: voltage_cell3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage_cell3: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_cell3, out);
    out << "\n";
  }

  // member: undervoltage_warning
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "undervoltage_warning: ";
    rosidl_generator_traits::value_to_yaml(msg.undervoltage_warning, out);
    out << "\n";
  }

  // member: undervoltage_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "undervoltage_error: ";
    rosidl_generator_traits::value_to_yaml(msg.undervoltage_error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BatteryStatus & msg, bool use_flow_style = false)
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
  const minirys_msgs::msg::BatteryStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  minirys_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use minirys_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const minirys_msgs::msg::BatteryStatus & msg)
{
  return minirys_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<minirys_msgs::msg::BatteryStatus>()
{
  return "minirys_msgs::msg::BatteryStatus";
}

template<>
inline const char * name<minirys_msgs::msg::BatteryStatus>()
{
  return "minirys_msgs/msg/BatteryStatus";
}

template<>
struct has_fixed_size<minirys_msgs::msg::BatteryStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<minirys_msgs::msg::BatteryStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<minirys_msgs::msg::BatteryStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_
