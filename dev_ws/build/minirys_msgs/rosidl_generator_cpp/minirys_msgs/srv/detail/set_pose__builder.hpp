// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from minirys_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__SRV__DETAIL__SET_POSE__BUILDER_HPP_
#define MINIRYS_MSGS__SRV__DETAIL__SET_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "minirys_msgs/srv/detail/set_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace minirys_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPose_Request_pose
{
public:
  Init_SetPose_Request_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::minirys_msgs::srv::SetPose_Request pose(::minirys_msgs::srv::SetPose_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::minirys_msgs::srv::SetPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_msgs::srv::SetPose_Request>()
{
  return minirys_msgs::srv::builder::Init_SetPose_Request_pose();
}

}  // namespace minirys_msgs


namespace minirys_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::minirys_msgs::srv::SetPose_Response>()
{
  return ::minirys_msgs::srv::SetPose_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace minirys_msgs

#endif  // MINIRYS_MSGS__SRV__DETAIL__SET_POSE__BUILDER_HPP_
