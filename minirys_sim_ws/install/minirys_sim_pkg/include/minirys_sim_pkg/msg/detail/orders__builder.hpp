// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__BUILDER_HPP_
#define MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__BUILDER_HPP_

#include "minirys_sim_pkg/msg/detail/orders__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace minirys_sim_pkg
{

namespace msg
{

namespace builder
{

class Init_Orders_control_flag
{
public:
  explicit Init_Orders_control_flag(::minirys_sim_pkg::msg::Orders & msg)
  : msg_(msg)
  {}
  ::minirys_sim_pkg::msg::Orders control_flag(::minirys_sim_pkg::msg::Orders::_control_flag_type arg)
  {
    msg_.control_flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_sim_pkg::msg::Orders msg_;
};

class Init_Orders_rotate
{
public:
  explicit Init_Orders_rotate(::minirys_sim_pkg::msg::Orders & msg)
  : msg_(msg)
  {}
  Init_Orders_control_flag rotate(::minirys_sim_pkg::msg::Orders::_rotate_type arg)
  {
    msg_.rotate = std::move(arg);
    return Init_Orders_control_flag(msg_);
  }

private:
  ::minirys_sim_pkg::msg::Orders msg_;
};

class Init_Orders_move
{
public:
  Init_Orders_move()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Orders_rotate move(::minirys_sim_pkg::msg::Orders::_move_type arg)
  {
    msg_.move = std::move(arg);
    return Init_Orders_rotate(msg_);
  }

private:
  ::minirys_sim_pkg::msg::Orders msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_sim_pkg::msg::Orders>()
{
  return minirys_sim_pkg::msg::builder::Init_Orders_move();
}

}  // namespace minirys_sim_pkg

#endif  // MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__BUILDER_HPP_
