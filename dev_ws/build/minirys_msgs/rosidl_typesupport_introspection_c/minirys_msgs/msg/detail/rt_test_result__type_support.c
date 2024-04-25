// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from minirys_msgs:msg/RTTestResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "minirys_msgs/msg/detail/rt_test_result__rosidl_typesupport_introspection_c.h"
#include "minirys_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "minirys_msgs/msg/detail/rt_test_result__functions.h"
#include "minirys_msgs/msg/detail/rt_test_result__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  minirys_msgs__msg__RTTestResult__init(message_memory);
}

void minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_fini_function(void * message_memory)
{
  minirys_msgs__msg__RTTestResult__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_message_member_array[7] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_msgs__msg__RTTestResult, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_msgs__msg__RTTestResult, current_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mean_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_msgs__msg__RTTestResult, mean_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "min_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_msgs__msg__RTTestResult, min_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_msgs__msg__RTTestResult, max_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "minor_pagefaults",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_msgs__msg__RTTestResult, minor_pagefaults),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "major_pagefaults",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_msgs__msg__RTTestResult, major_pagefaults),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_message_members = {
  "minirys_msgs__msg",  // message namespace
  "RTTestResult",  // message name
  7,  // number of fields
  sizeof(minirys_msgs__msg__RTTestResult),
  minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_message_member_array,  // message members
  minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_init_function,  // function to initialize message memory (memory has to be allocated)
  minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_message_type_support_handle = {
  0,
  &minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_minirys_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_msgs, msg, RTTestResult)() {
  minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_message_type_support_handle.typesupport_identifier) {
    minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &minirys_msgs__msg__RTTestResult__rosidl_typesupport_introspection_c__RTTestResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
