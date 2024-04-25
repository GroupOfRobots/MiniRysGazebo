// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from minirys_sim:srv/OdomService.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__BUILDER_HPP_
#define MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "minirys_sim/srv/detail/odom_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace minirys_sim
{

namespace srv
{

namespace builder
{

class Init_OdomService_Request_robot_namespace
{
public:
  Init_OdomService_Request_robot_namespace()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::minirys_sim::srv::OdomService_Request robot_namespace(::minirys_sim::srv::OdomService_Request::_robot_namespace_type arg)
  {
    msg_.robot_namespace = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_sim::srv::OdomService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_sim::srv::OdomService_Request>()
{
  return minirys_sim::srv::builder::Init_OdomService_Request_robot_namespace();
}

}  // namespace minirys_sim


namespace minirys_sim
{

namespace srv
{

namespace builder
{

class Init_OdomService_Response_success
{
public:
  explicit Init_OdomService_Response_success(::minirys_sim::srv::OdomService_Response & msg)
  : msg_(msg)
  {}
  ::minirys_sim::srv::OdomService_Response success(::minirys_sim::srv::OdomService_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_sim::srv::OdomService_Response msg_;
};

class Init_OdomService_Response_yaw
{
public:
  explicit Init_OdomService_Response_yaw(::minirys_sim::srv::OdomService_Response & msg)
  : msg_(msg)
  {}
  Init_OdomService_Response_success yaw(::minirys_sim::srv::OdomService_Response::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_OdomService_Response_success(msg_);
  }

private:
  ::minirys_sim::srv::OdomService_Response msg_;
};

class Init_OdomService_Response_pitch
{
public:
  explicit Init_OdomService_Response_pitch(::minirys_sim::srv::OdomService_Response & msg)
  : msg_(msg)
  {}
  Init_OdomService_Response_yaw pitch(::minirys_sim::srv::OdomService_Response::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_OdomService_Response_yaw(msg_);
  }

private:
  ::minirys_sim::srv::OdomService_Response msg_;
};

class Init_OdomService_Response_roll
{
public:
  explicit Init_OdomService_Response_roll(::minirys_sim::srv::OdomService_Response & msg)
  : msg_(msg)
  {}
  Init_OdomService_Response_pitch roll(::minirys_sim::srv::OdomService_Response::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_OdomService_Response_pitch(msg_);
  }

private:
  ::minirys_sim::srv::OdomService_Response msg_;
};

class Init_OdomService_Response_z
{
public:
  explicit Init_OdomService_Response_z(::minirys_sim::srv::OdomService_Response & msg)
  : msg_(msg)
  {}
  Init_OdomService_Response_roll z(::minirys_sim::srv::OdomService_Response::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_OdomService_Response_roll(msg_);
  }

private:
  ::minirys_sim::srv::OdomService_Response msg_;
};

class Init_OdomService_Response_y
{
public:
  explicit Init_OdomService_Response_y(::minirys_sim::srv::OdomService_Response & msg)
  : msg_(msg)
  {}
  Init_OdomService_Response_z y(::minirys_sim::srv::OdomService_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_OdomService_Response_z(msg_);
  }

private:
  ::minirys_sim::srv::OdomService_Response msg_;
};

class Init_OdomService_Response_x
{
public:
  Init_OdomService_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OdomService_Response_y x(::minirys_sim::srv::OdomService_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_OdomService_Response_y(msg_);
  }

private:
  ::minirys_sim::srv::OdomService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_sim::srv::OdomService_Response>()
{
  return minirys_sim::srv::builder::Init_OdomService_Response_x();
}

}  // namespace minirys_sim

#endif  // MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__BUILDER_HPP_
