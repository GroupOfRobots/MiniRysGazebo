// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from minirys_msgs:msg/AngularPose.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "minirys_msgs/msg/detail/angular_pose__struct.h"
#include "minirys_msgs/msg/detail/angular_pose__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace minirys_msgs
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _AngularPose_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AngularPose_type_support_ids_t;

static const _AngularPose_type_support_ids_t _AngularPose_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _AngularPose_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _AngularPose_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _AngularPose_type_support_symbol_names_t _AngularPose_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, minirys_msgs, msg, AngularPose)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_msgs, msg, AngularPose)),
  }
};

typedef struct _AngularPose_type_support_data_t
{
  void * data[2];
} _AngularPose_type_support_data_t;

static _AngularPose_type_support_data_t _AngularPose_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _AngularPose_message_typesupport_map = {
  2,
  "minirys_msgs",
  &_AngularPose_message_typesupport_ids.typesupport_identifier[0],
  &_AngularPose_message_typesupport_symbol_names.symbol_name[0],
  &_AngularPose_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t AngularPose_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AngularPose_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace minirys_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, minirys_msgs, msg, AngularPose)() {
  return &::minirys_msgs::msg::rosidl_typesupport_c::AngularPose_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
