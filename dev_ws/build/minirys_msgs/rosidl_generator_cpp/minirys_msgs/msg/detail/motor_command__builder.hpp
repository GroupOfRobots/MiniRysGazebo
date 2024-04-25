// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from minirys_msgs:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "minirys_msgs/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace minirys_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorCommand_enable
{
public:
  explicit Init_MotorCommand_enable(::minirys_msgs::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  ::minirys_msgs::msg::MotorCommand enable(::minirys_msgs::msg::MotorCommand::_enable_type arg)
  {
    msg_.enable = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_msgs::msg::MotorCommand msg_;
};

class Init_MotorCommand_speed_r
{
public:
  explicit Init_MotorCommand_speed_r(::minirys_msgs::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_enable speed_r(::minirys_msgs::msg::MotorCommand::_speed_r_type arg)
  {
    msg_.speed_r = std::move(arg);
    return Init_MotorCommand_enable(msg_);
  }

private:
  ::minirys_msgs::msg::MotorCommand msg_;
};

class Init_MotorCommand_speed_l
{
public:
  explicit Init_MotorCommand_speed_l(::minirys_msgs::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_speed_r speed_l(::minirys_msgs::msg::MotorCommand::_speed_l_type arg)
  {
    msg_.speed_l = std::move(arg);
    return Init_MotorCommand_speed_r(msg_);
  }

private:
  ::minirys_msgs::msg::MotorCommand msg_;
};

class Init_MotorCommand_header
{
public:
  Init_MotorCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorCommand_speed_l header(::minirys_msgs::msg::MotorCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorCommand_speed_l(msg_);
  }

private:
  ::minirys_msgs::msg::MotorCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_msgs::msg::MotorCommand>()
{
  return minirys_msgs::msg::builder::Init_MotorCommand_header();
}

}  // namespace minirys_msgs

#endif  // MINIRYS_MSGS__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
