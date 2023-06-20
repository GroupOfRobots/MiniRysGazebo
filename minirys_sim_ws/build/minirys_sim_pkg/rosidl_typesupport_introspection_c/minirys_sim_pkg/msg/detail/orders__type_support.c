// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "minirys_sim_pkg/msg/detail/orders__rosidl_typesupport_introspection_c.h"
#include "minirys_sim_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "minirys_sim_pkg/msg/detail/orders__functions.h"
#include "minirys_sim_pkg/msg/detail/orders__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Orders__rosidl_typesupport_introspection_c__Orders_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  minirys_sim_pkg__msg__Orders__init(message_memory);
}

void Orders__rosidl_typesupport_introspection_c__Orders_fini_function(void * message_memory)
{
  minirys_sim_pkg__msg__Orders__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Orders__rosidl_typesupport_introspection_c__Orders_message_member_array[3] = {
  {
    "move",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim_pkg__msg__Orders, move),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rotate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim_pkg__msg__Orders, rotate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "control_flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim_pkg__msg__Orders, control_flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Orders__rosidl_typesupport_introspection_c__Orders_message_members = {
  "minirys_sim_pkg__msg",  // message namespace
  "Orders",  // message name
  3,  // number of fields
  sizeof(minirys_sim_pkg__msg__Orders),
  Orders__rosidl_typesupport_introspection_c__Orders_message_member_array,  // message members
  Orders__rosidl_typesupport_introspection_c__Orders_init_function,  // function to initialize message memory (memory has to be allocated)
  Orders__rosidl_typesupport_introspection_c__Orders_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Orders__rosidl_typesupport_introspection_c__Orders_message_type_support_handle = {
  0,
  &Orders__rosidl_typesupport_introspection_c__Orders_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_minirys_sim_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_sim_pkg, msg, Orders)() {
  if (!Orders__rosidl_typesupport_introspection_c__Orders_message_type_support_handle.typesupport_identifier) {
    Orders__rosidl_typesupport_introspection_c__Orders_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Orders__rosidl_typesupport_introspection_c__Orders_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
