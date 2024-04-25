// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from minirys_sim:srv/OdomService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "minirys_sim/srv/detail/odom_service__rosidl_typesupport_introspection_c.h"
#include "minirys_sim/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "minirys_sim/srv/detail/odom_service__functions.h"
#include "minirys_sim/srv/detail/odom_service__struct.h"


// Include directives for member types
// Member `robot_namespace`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  minirys_sim__srv__OdomService_Request__init(message_memory);
}

void minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_fini_function(void * message_memory)
{
  minirys_sim__srv__OdomService_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_message_member_array[1] = {
  {
    "robot_namespace",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim__srv__OdomService_Request, robot_namespace),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_message_members = {
  "minirys_sim__srv",  // message namespace
  "OdomService_Request",  // message name
  1,  // number of fields
  sizeof(minirys_sim__srv__OdomService_Request),
  minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_message_member_array,  // message members
  minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_message_type_support_handle = {
  0,
  &minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_minirys_sim
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_sim, srv, OdomService_Request)() {
  if (!minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_message_type_support_handle.typesupport_identifier) {
    minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &minirys_sim__srv__OdomService_Request__rosidl_typesupport_introspection_c__OdomService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "minirys_sim/srv/detail/odom_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "minirys_sim/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "minirys_sim/srv/detail/odom_service__functions.h"
// already included above
// #include "minirys_sim/srv/detail/odom_service__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  minirys_sim__srv__OdomService_Response__init(message_memory);
}

void minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_fini_function(void * message_memory)
{
  minirys_sim__srv__OdomService_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_message_member_array[7] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim__srv__OdomService_Response, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim__srv__OdomService_Response, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim__srv__OdomService_Response, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim__srv__OdomService_Response, roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim__srv__OdomService_Response, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim__srv__OdomService_Response, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(minirys_sim__srv__OdomService_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_message_members = {
  "minirys_sim__srv",  // message namespace
  "OdomService_Response",  // message name
  7,  // number of fields
  sizeof(minirys_sim__srv__OdomService_Response),
  minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_message_member_array,  // message members
  minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_message_type_support_handle = {
  0,
  &minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_minirys_sim
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_sim, srv, OdomService_Response)() {
  if (!minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_message_type_support_handle.typesupport_identifier) {
    minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &minirys_sim__srv__OdomService_Response__rosidl_typesupport_introspection_c__OdomService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "minirys_sim/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "minirys_sim/srv/detail/odom_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers minirys_sim__srv__detail__odom_service__rosidl_typesupport_introspection_c__OdomService_service_members = {
  "minirys_sim__srv",  // service namespace
  "OdomService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // minirys_sim__srv__detail__odom_service__rosidl_typesupport_introspection_c__OdomService_Request_message_type_support_handle,
  NULL  // response message
  // minirys_sim__srv__detail__odom_service__rosidl_typesupport_introspection_c__OdomService_Response_message_type_support_handle
};

static rosidl_service_type_support_t minirys_sim__srv__detail__odom_service__rosidl_typesupport_introspection_c__OdomService_service_type_support_handle = {
  0,
  &minirys_sim__srv__detail__odom_service__rosidl_typesupport_introspection_c__OdomService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_sim, srv, OdomService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_sim, srv, OdomService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_minirys_sim
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_sim, srv, OdomService)() {
  if (!minirys_sim__srv__detail__odom_service__rosidl_typesupport_introspection_c__OdomService_service_type_support_handle.typesupport_identifier) {
    minirys_sim__srv__detail__odom_service__rosidl_typesupport_introspection_c__OdomService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)minirys_sim__srv__detail__odom_service__rosidl_typesupport_introspection_c__OdomService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_sim, srv, OdomService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_sim, srv, OdomService_Response)()->data;
  }

  return &minirys_sim__srv__detail__odom_service__rosidl_typesupport_introspection_c__OdomService_service_type_support_handle;
}
