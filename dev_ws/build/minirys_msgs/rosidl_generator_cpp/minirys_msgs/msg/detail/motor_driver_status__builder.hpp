// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from minirys_msgs:msg/MotorDriverStatus.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__BUILDER_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "minirys_msgs/msg/detail/motor_driver_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace minirys_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorDriverStatus_step_loss_b
{
public:
  explicit Init_MotorDriverStatus_step_loss_b(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  ::minirys_msgs::msg::MotorDriverStatus step_loss_b(::minirys_msgs::msg::MotorDriverStatus::_step_loss_b_type arg)
  {
    msg_.step_loss_b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_step_loss_a
{
public:
  explicit Init_MotorDriverStatus_step_loss_a(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_step_loss_b step_loss_a(::minirys_msgs::msg::MotorDriverStatus::_step_loss_a_type arg)
  {
    msg_.step_loss_a = std::move(arg);
    return Init_MotorDriverStatus_step_loss_b(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_overcurrent
{
public:
  explicit Init_MotorDriverStatus_overcurrent(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_step_loss_a overcurrent(::minirys_msgs::msg::MotorDriverStatus::_overcurrent_type arg)
  {
    msg_.overcurrent = std::move(arg);
    return Init_MotorDriverStatus_step_loss_a(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_thermal_shutdown
{
public:
  explicit Init_MotorDriverStatus_thermal_shutdown(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_overcurrent thermal_shutdown(::minirys_msgs::msg::MotorDriverStatus::_thermal_shutdown_type arg)
  {
    msg_.thermal_shutdown = std::move(arg);
    return Init_MotorDriverStatus_overcurrent(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_thermal_warning
{
public:
  explicit Init_MotorDriverStatus_thermal_warning(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_thermal_shutdown thermal_warning(::minirys_msgs::msg::MotorDriverStatus::_thermal_warning_type arg)
  {
    msg_.thermal_warning = std::move(arg);
    return Init_MotorDriverStatus_thermal_shutdown(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_undervoltage
{
public:
  explicit Init_MotorDriverStatus_undervoltage(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_thermal_warning undervoltage(::minirys_msgs::msg::MotorDriverStatus::_undervoltage_type arg)
  {
    msg_.undervoltage = std::move(arg);
    return Init_MotorDriverStatus_thermal_warning(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_motor_const_speed
{
public:
  explicit Init_MotorDriverStatus_motor_const_speed(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_undervoltage motor_const_speed(::minirys_msgs::msg::MotorDriverStatus::_motor_const_speed_type arg)
  {
    msg_.motor_const_speed = std::move(arg);
    return Init_MotorDriverStatus_undervoltage(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_motor_decelerating
{
public:
  explicit Init_MotorDriverStatus_motor_decelerating(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_motor_const_speed motor_decelerating(::minirys_msgs::msg::MotorDriverStatus::_motor_decelerating_type arg)
  {
    msg_.motor_decelerating = std::move(arg);
    return Init_MotorDriverStatus_motor_const_speed(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_motor_accelerating
{
public:
  explicit Init_MotorDriverStatus_motor_accelerating(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_motor_decelerating motor_accelerating(::minirys_msgs::msg::MotorDriverStatus::_motor_accelerating_type arg)
  {
    msg_.motor_accelerating = std::move(arg);
    return Init_MotorDriverStatus_motor_decelerating(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_motor_stopped
{
public:
  explicit Init_MotorDriverStatus_motor_stopped(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_motor_accelerating motor_stopped(::minirys_msgs::msg::MotorDriverStatus::_motor_stopped_type arg)
  {
    msg_.motor_stopped = std::move(arg);
    return Init_MotorDriverStatus_motor_accelerating(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_direction
{
public:
  explicit Init_MotorDriverStatus_direction(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_motor_stopped direction(::minirys_msgs::msg::MotorDriverStatus::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_MotorDriverStatus_motor_stopped(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_busy
{
public:
  explicit Init_MotorDriverStatus_busy(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_direction busy(::minirys_msgs::msg::MotorDriverStatus::_busy_type arg)
  {
    msg_.busy = std::move(arg);
    return Init_MotorDriverStatus_direction(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_hi_z
{
public:
  explicit Init_MotorDriverStatus_hi_z(::minirys_msgs::msg::MotorDriverStatus & msg)
  : msg_(msg)
  {}
  Init_MotorDriverStatus_busy hi_z(::minirys_msgs::msg::MotorDriverStatus::_hi_z_type arg)
  {
    msg_.hi_z = std::move(arg);
    return Init_MotorDriverStatus_busy(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

class Init_MotorDriverStatus_header
{
public:
  Init_MotorDriverStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorDriverStatus_hi_z header(::minirys_msgs::msg::MotorDriverStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorDriverStatus_hi_z(msg_);
  }

private:
  ::minirys_msgs::msg::MotorDriverStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_msgs::msg::MotorDriverStatus>()
{
  return minirys_msgs::msg::builder::Init_MotorDriverStatus_header();
}

}  // namespace minirys_msgs

#endif  // MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__BUILDER_HPP_
