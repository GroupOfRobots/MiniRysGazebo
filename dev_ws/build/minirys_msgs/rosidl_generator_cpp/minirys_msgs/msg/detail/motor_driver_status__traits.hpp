// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from minirys_msgs:msg/MotorDriverStatus.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__TRAITS_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "minirys_msgs/msg/detail/motor_driver_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace minirys_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorDriverStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: hi_z
  {
    out << "hi_z: ";
    rosidl_generator_traits::value_to_yaml(msg.hi_z, out);
    out << ", ";
  }

  // member: busy
  {
    out << "busy: ";
    rosidl_generator_traits::value_to_yaml(msg.busy, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << ", ";
  }

  // member: motor_stopped
  {
    out << "motor_stopped: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_stopped, out);
    out << ", ";
  }

  // member: motor_accelerating
  {
    out << "motor_accelerating: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_accelerating, out);
    out << ", ";
  }

  // member: motor_decelerating
  {
    out << "motor_decelerating: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_decelerating, out);
    out << ", ";
  }

  // member: motor_const_speed
  {
    out << "motor_const_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_const_speed, out);
    out << ", ";
  }

  // member: undervoltage
  {
    out << "undervoltage: ";
    rosidl_generator_traits::value_to_yaml(msg.undervoltage, out);
    out << ", ";
  }

  // member: thermal_warning
  {
    out << "thermal_warning: ";
    rosidl_generator_traits::value_to_yaml(msg.thermal_warning, out);
    out << ", ";
  }

  // member: thermal_shutdown
  {
    out << "thermal_shutdown: ";
    rosidl_generator_traits::value_to_yaml(msg.thermal_shutdown, out);
    out << ", ";
  }

  // member: overcurrent
  {
    out << "overcurrent: ";
    rosidl_generator_traits::value_to_yaml(msg.overcurrent, out);
    out << ", ";
  }

  // member: step_loss_a
  {
    out << "step_loss_a: ";
    rosidl_generator_traits::value_to_yaml(msg.step_loss_a, out);
    out << ", ";
  }

  // member: step_loss_b
  {
    out << "step_loss_b: ";
    rosidl_generator_traits::value_to_yaml(msg.step_loss_b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorDriverStatus & msg,
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

  // member: hi_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hi_z: ";
    rosidl_generator_traits::value_to_yaml(msg.hi_z, out);
    out << "\n";
  }

  // member: busy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "busy: ";
    rosidl_generator_traits::value_to_yaml(msg.busy, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }

  // member: motor_stopped
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_stopped: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_stopped, out);
    out << "\n";
  }

  // member: motor_accelerating
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_accelerating: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_accelerating, out);
    out << "\n";
  }

  // member: motor_decelerating
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_decelerating: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_decelerating, out);
    out << "\n";
  }

  // member: motor_const_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_const_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_const_speed, out);
    out << "\n";
  }

  // member: undervoltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "undervoltage: ";
    rosidl_generator_traits::value_to_yaml(msg.undervoltage, out);
    out << "\n";
  }

  // member: thermal_warning
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "thermal_warning: ";
    rosidl_generator_traits::value_to_yaml(msg.thermal_warning, out);
    out << "\n";
  }

  // member: thermal_shutdown
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "thermal_shutdown: ";
    rosidl_generator_traits::value_to_yaml(msg.thermal_shutdown, out);
    out << "\n";
  }

  // member: overcurrent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "overcurrent: ";
    rosidl_generator_traits::value_to_yaml(msg.overcurrent, out);
    out << "\n";
  }

  // member: step_loss_a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step_loss_a: ";
    rosidl_generator_traits::value_to_yaml(msg.step_loss_a, out);
    out << "\n";
  }

  // member: step_loss_b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step_loss_b: ";
    rosidl_generator_traits::value_to_yaml(msg.step_loss_b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorDriverStatus & msg, bool use_flow_style = false)
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
  const minirys_msgs::msg::MotorDriverStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  minirys_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use minirys_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const minirys_msgs::msg::MotorDriverStatus & msg)
{
  return minirys_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<minirys_msgs::msg::MotorDriverStatus>()
{
  return "minirys_msgs::msg::MotorDriverStatus";
}

template<>
inline const char * name<minirys_msgs::msg::MotorDriverStatus>()
{
  return "minirys_msgs/msg/MotorDriverStatus";
}

template<>
struct has_fixed_size<minirys_msgs::msg::MotorDriverStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<minirys_msgs::msg::MotorDriverStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<minirys_msgs::msg::MotorDriverStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__TRAITS_HPP_
