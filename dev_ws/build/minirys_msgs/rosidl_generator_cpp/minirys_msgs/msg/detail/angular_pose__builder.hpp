// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from minirys_msgs:msg/AngularPose.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__BUILDER_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "minirys_msgs/msg/detail/angular_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace minirys_msgs
{

namespace msg
{

namespace builder
{

class Init_AngularPose_angular_velocity
{
public:
  explicit Init_AngularPose_angular_velocity(::minirys_msgs::msg::AngularPose & msg)
  : msg_(msg)
  {}
  ::minirys_msgs::msg::AngularPose angular_velocity(::minirys_msgs::msg::AngularPose::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_msgs::msg::AngularPose msg_;
};

class Init_AngularPose_angular_position
{
public:
  explicit Init_AngularPose_angular_position(::minirys_msgs::msg::AngularPose & msg)
  : msg_(msg)
  {}
  Init_AngularPose_angular_velocity angular_position(::minirys_msgs::msg::AngularPose::_angular_position_type arg)
  {
    msg_.angular_position = std::move(arg);
    return Init_AngularPose_angular_velocity(msg_);
  }

private:
  ::minirys_msgs::msg::AngularPose msg_;
};

class Init_AngularPose_header
{
public:
  Init_AngularPose_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AngularPose_angular_position header(::minirys_msgs::msg::AngularPose::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_AngularPose_angular_position(msg_);
  }

private:
  ::minirys_msgs::msg::AngularPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_msgs::msg::AngularPose>()
{
  return minirys_msgs::msg::builder::Init_AngularPose_header();
}

}  // namespace minirys_msgs

#endif  // MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__BUILDER_HPP_
