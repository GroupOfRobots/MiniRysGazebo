// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from minirys_sim:srv/CloseMenager.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM__SRV__DETAIL__CLOSE_MENAGER__TRAITS_HPP_
#define MINIRYS_SIM__SRV__DETAIL__CLOSE_MENAGER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "minirys_sim/srv/detail/close_menager__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace minirys_sim
{

namespace srv
{

inline void to_flow_style_yaml(
  const CloseMenager_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CloseMenager_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CloseMenager_Request & msg, bool use_flow_style = false)
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
  const minirys_sim::srv::CloseMenager_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  minirys_sim::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use minirys_sim::srv::to_yaml() instead")]]
inline std::string to_yaml(const minirys_sim::srv::CloseMenager_Request & msg)
{
  return minirys_sim::srv::to_yaml(msg);
}

template<>
inline const char * data_type<minirys_sim::srv::CloseMenager_Request>()
{
  return "minirys_sim::srv::CloseMenager_Request";
}

template<>
inline const char * name<minirys_sim::srv::CloseMenager_Request>()
{
  return "minirys_sim/srv/CloseMenager_Request";
}

template<>
struct has_fixed_size<minirys_sim::srv::CloseMenager_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<minirys_sim::srv::CloseMenager_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<minirys_sim::srv::CloseMenager_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace minirys_sim
{

namespace srv
{

inline void to_flow_style_yaml(
  const CloseMenager_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CloseMenager_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const CloseMenager_Response & msg, bool use_flow_style = false)
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
  const minirys_sim::srv::CloseMenager_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  minirys_sim::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use minirys_sim::srv::to_yaml() instead")]]
inline std::string to_yaml(const minirys_sim::srv::CloseMenager_Response & msg)
{
  return minirys_sim::srv::to_yaml(msg);
}

template<>
inline const char * data_type<minirys_sim::srv::CloseMenager_Response>()
{
  return "minirys_sim::srv::CloseMenager_Response";
}

template<>
inline const char * name<minirys_sim::srv::CloseMenager_Response>()
{
  return "minirys_sim/srv/CloseMenager_Response";
}

template<>
struct has_fixed_size<minirys_sim::srv::CloseMenager_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<minirys_sim::srv::CloseMenager_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<minirys_sim::srv::CloseMenager_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<minirys_sim::srv::CloseMenager>()
{
  return "minirys_sim::srv::CloseMenager";
}

template<>
inline const char * name<minirys_sim::srv::CloseMenager>()
{
  return "minirys_sim/srv/CloseMenager";
}

template<>
struct has_fixed_size<minirys_sim::srv::CloseMenager>
  : std::integral_constant<
    bool,
    has_fixed_size<minirys_sim::srv::CloseMenager_Request>::value &&
    has_fixed_size<minirys_sim::srv::CloseMenager_Response>::value
  >
{
};

template<>
struct has_bounded_size<minirys_sim::srv::CloseMenager>
  : std::integral_constant<
    bool,
    has_bounded_size<minirys_sim::srv::CloseMenager_Request>::value &&
    has_bounded_size<minirys_sim::srv::CloseMenager_Response>::value
  >
{
};

template<>
struct is_service<minirys_sim::srv::CloseMenager>
  : std::true_type
{
};

template<>
struct is_service_request<minirys_sim::srv::CloseMenager_Request>
  : std::true_type
{
};

template<>
struct is_service_response<minirys_sim::srv::CloseMenager_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MINIRYS_SIM__SRV__DETAIL__CLOSE_MENAGER__TRAITS_HPP_
