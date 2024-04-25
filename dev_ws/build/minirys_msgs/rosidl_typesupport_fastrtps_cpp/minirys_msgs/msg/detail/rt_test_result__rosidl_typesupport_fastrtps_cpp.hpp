// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from minirys_msgs:msg/RTTestResult.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "minirys_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "minirys_msgs/msg/detail/rt_test_result__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace minirys_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_msgs
cdr_serialize(
  const minirys_msgs::msg::RTTestResult & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  minirys_msgs::msg::RTTestResult & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_msgs
get_serialized_size(
  const minirys_msgs::msg::RTTestResult & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_msgs
max_serialized_size_RTTestResult(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace minirys_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, minirys_msgs, msg, RTTestResult)();

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
