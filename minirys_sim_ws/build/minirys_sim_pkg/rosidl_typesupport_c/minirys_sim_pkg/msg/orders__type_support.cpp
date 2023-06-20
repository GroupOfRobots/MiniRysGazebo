// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "minirys_sim_pkg/msg/rosidl_typesupport_c__visibility_control.h"
#include "minirys_sim_pkg/msg/detail/orders__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace minirys_sim_pkg
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _Orders_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Orders_type_support_ids_t;

static const _Orders_type_support_ids_t _Orders_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Orders_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Orders_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Orders_type_support_symbol_names_t _Orders_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, minirys_sim_pkg, msg, Orders)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, minirys_sim_pkg, msg, Orders)),
  }
};

typedef struct _Orders_type_support_data_t
{
  void * data[2];
} _Orders_type_support_data_t;

static _Orders_type_support_data_t _Orders_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Orders_message_typesupport_map = {
  2,
  "minirys_sim_pkg",
  &_Orders_message_typesupport_ids.typesupport_identifier[0],
  &_Orders_message_typesupport_symbol_names.symbol_name[0],
  &_Orders_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Orders_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Orders_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace minirys_sim_pkg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_minirys_sim_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, minirys_sim_pkg, msg, Orders)() {
  return &::minirys_sim_pkg::msg::rosidl_typesupport_c::Orders_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
