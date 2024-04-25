// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from minirys_sim:srv/CloseMenager.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM__SRV__DETAIL__CLOSE_MENAGER__BUILDER_HPP_
#define MINIRYS_SIM__SRV__DETAIL__CLOSE_MENAGER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "minirys_sim/srv/detail/close_menager__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace minirys_sim
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_sim::srv::CloseMenager_Request>()
{
  return ::minirys_sim::srv::CloseMenager_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace minirys_sim


namespace minirys_sim
{

namespace srv
{

namespace builder
{

class Init_CloseMenager_Response_success
{
public:
  Init_CloseMenager_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::minirys_sim::srv::CloseMenager_Response success(::minirys_sim::srv::CloseMenager_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_sim::srv::CloseMenager_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_sim::srv::CloseMenager_Response>()
{
  return minirys_sim::srv::builder::Init_CloseMenager_Response_success();
}

}  // namespace minirys_sim

#endif  // MINIRYS_SIM__SRV__DETAIL__CLOSE_MENAGER__BUILDER_HPP_
