// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__TRAITS_HPP_
#define MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__TRAITS_HPP_

#include "minirys_sim_pkg/msg/detail/orders__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<minirys_sim_pkg::msg::Orders>()
{
  return "minirys_sim_pkg::msg::Orders";
}

template<>
inline const char * name<minirys_sim_pkg::msg::Orders>()
{
  return "minirys_sim_pkg/msg/Orders";
}

template<>
struct has_fixed_size<minirys_sim_pkg::msg::Orders>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<minirys_sim_pkg::msg::Orders>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<minirys_sim_pkg::msg::Orders>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__TRAITS_HPP_
