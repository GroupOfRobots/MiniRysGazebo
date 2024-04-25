// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from minirys_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "minirys_msgs/msg/detail/battery_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace minirys_msgs
{

namespace msg
{

namespace builder
{

class Init_BatteryStatus_undervoltage_error
{
public:
  explicit Init_BatteryStatus_undervoltage_error(::minirys_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  ::minirys_msgs::msg::BatteryStatus undervoltage_error(::minirys_msgs::msg::BatteryStatus::_undervoltage_error_type arg)
  {
    msg_.undervoltage_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_undervoltage_warning
{
public:
  explicit Init_BatteryStatus_undervoltage_warning(::minirys_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_undervoltage_error undervoltage_warning(::minirys_msgs::msg::BatteryStatus::_undervoltage_warning_type arg)
  {
    msg_.undervoltage_warning = std::move(arg);
    return Init_BatteryStatus_undervoltage_error(msg_);
  }

private:
  ::minirys_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_voltage_cell3
{
public:
  explicit Init_BatteryStatus_voltage_cell3(::minirys_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_undervoltage_warning voltage_cell3(::minirys_msgs::msg::BatteryStatus::_voltage_cell3_type arg)
  {
    msg_.voltage_cell3 = std::move(arg);
    return Init_BatteryStatus_undervoltage_warning(msg_);
  }

private:
  ::minirys_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_voltage_cell2
{
public:
  explicit Init_BatteryStatus_voltage_cell2(::minirys_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_voltage_cell3 voltage_cell2(::minirys_msgs::msg::BatteryStatus::_voltage_cell2_type arg)
  {
    msg_.voltage_cell2 = std::move(arg);
    return Init_BatteryStatus_voltage_cell3(msg_);
  }

private:
  ::minirys_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_voltage_cell1
{
public:
  explicit Init_BatteryStatus_voltage_cell1(::minirys_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_voltage_cell2 voltage_cell1(::minirys_msgs::msg::BatteryStatus::_voltage_cell1_type arg)
  {
    msg_.voltage_cell1 = std::move(arg);
    return Init_BatteryStatus_voltage_cell2(msg_);
  }

private:
  ::minirys_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_header
{
public:
  Init_BatteryStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BatteryStatus_voltage_cell1 header(::minirys_msgs::msg::BatteryStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BatteryStatus_voltage_cell1(msg_);
  }

private:
  ::minirys_msgs::msg::BatteryStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_msgs::msg::BatteryStatus>()
{
  return minirys_msgs::msg::builder::Init_BatteryStatus_header();
}

}  // namespace minirys_msgs

#endif  // MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_
