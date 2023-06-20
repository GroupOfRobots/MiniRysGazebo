// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "minirys_sim_pkg/msg/detail/orders__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace minirys_sim_pkg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Orders_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) minirys_sim_pkg::msg::Orders(_init);
}

void Orders_fini_function(void * message_memory)
{
  auto typed_message = static_cast<minirys_sim_pkg::msg::Orders *>(message_memory);
  typed_message->~Orders();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Orders_message_member_array[3] = {
  {
    "move",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim_pkg::msg::Orders, move),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rotate",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim_pkg::msg::Orders, rotate),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "control_flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim_pkg::msg::Orders, control_flag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Orders_message_members = {
  "minirys_sim_pkg::msg",  // message namespace
  "Orders",  // message name
  3,  // number of fields
  sizeof(minirys_sim_pkg::msg::Orders),
  Orders_message_member_array,  // message members
  Orders_init_function,  // function to initialize message memory (memory has to be allocated)
  Orders_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Orders_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Orders_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace minirys_sim_pkg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<minirys_sim_pkg::msg::Orders>()
{
  return &::minirys_sim_pkg::msg::rosidl_typesupport_introspection_cpp::Orders_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, minirys_sim_pkg, msg, Orders)() {
  return &::minirys_sim_pkg::msg::rosidl_typesupport_introspection_cpp::Orders_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
