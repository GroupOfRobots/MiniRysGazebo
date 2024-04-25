// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from minirys_sim:srv/OdomService.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__TRAITS_HPP_
#define MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "minirys_sim/srv/detail/odom_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace minirys_sim
{

namespace srv
{

inline void to_flow_style_yaml(
  const OdomService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_namespace
  {
    out << "robot_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_namespace, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OdomService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_namespace
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_namespace, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OdomService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace minirys_sim

namespace rosidl_generator_traits
{

[[deprecated("use minirys_sim::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const minirys_sim::srv::OdomService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  minirys_sim::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use minirys_sim::srv::to_yaml() instead")]]
inline std::string to_yaml(const minirys_sim::srv::OdomService_Request & msg)
{
  return minirys_sim::srv::to_yaml(msg);
}

template<>
inline const char * data_type<minirys_sim::srv::OdomService_Request>()
{
  return "minirys_sim::srv::OdomService_Request";
}

template<>
inline const char * name<minirys_sim::srv::OdomService_Request>()
{
  return "minirys_sim/srv/OdomService_Request";
}

template<>
struct has_fixed_size<minirys_sim::srv::OdomService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<minirys_sim::srv::OdomService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<minirys_sim::srv::OdomService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace minirys_sim
{

namespace srv
{

inline void to_flow_style_yaml(
  const OdomService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OdomService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OdomService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace minirys_sim

namespace rosidl_generator_traits
{

[[deprecated("use minirys_sim::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const minirys_sim::srv::OdomService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  minirys_sim::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use minirys_sim::srv::to_yaml() instead")]]
inline std::string to_yaml(const minirys_sim::srv::OdomService_Response & msg)
{
  return minirys_sim::srv::to_yaml(msg);
}

template<>
inline const char * data_type<minirys_sim::srv::OdomService_Response>()
{
  return "minirys_sim::srv::OdomService_Response";
}

template<>
inline const char * name<minirys_sim::srv::OdomService_Response>()
{
  return "minirys_sim/srv/OdomService_Response";
}

template<>
struct has_fixed_size<minirys_sim::srv::OdomService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<minirys_sim::srv::OdomService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<minirys_sim::srv::OdomService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<minirys_sim::srv::OdomService>()
{
  return "minirys_sim::srv::OdomService";
}

template<>
inline const char * name<minirys_sim::srv::OdomService>()
{
  return "minirys_sim/srv/OdomService";
}

template<>
struct has_fixed_size<minirys_sim::srv::OdomService>
  : std::integral_constant<
    bool,
    has_fixed_size<minirys_sim::srv::OdomService_Request>::value &&
    has_fixed_size<minirys_sim::srv::OdomService_Response>::value
  >
{
};

template<>
struct has_bounded_size<minirys_sim::srv::OdomService>
  : std::integral_constant<
    bool,
    has_bounded_size<minirys_sim::srv::OdomService_Request>::value &&
    has_bounded_size<minirys_sim::srv::OdomService_Response>::value
  >
{
};

template<>
struct is_service<minirys_sim::srv::OdomService>
  : std::true_type
{
};

template<>
struct is_service_request<minirys_sim::srv::OdomService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<minirys_sim::srv::OdomService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__TRAITS_HPP_
