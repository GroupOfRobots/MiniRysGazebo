// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from minirys_sim:srv/OdomService.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__STRUCT_H_
#define MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_namespace'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/OdomService in the package minirys_sim.
typedef struct minirys_sim__srv__OdomService_Request
{
  rosidl_runtime_c__String robot_namespace;
} minirys_sim__srv__OdomService_Request;

// Struct for a sequence of minirys_sim__srv__OdomService_Request.
typedef struct minirys_sim__srv__OdomService_Request__Sequence
{
  minirys_sim__srv__OdomService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_sim__srv__OdomService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/OdomService in the package minirys_sim.
typedef struct minirys_sim__srv__OdomService_Response
{
  double x;
  double y;
  double z;
  double roll;
  double pitch;
  double yaw;
  bool success;
} minirys_sim__srv__OdomService_Response;

// Struct for a sequence of minirys_sim__srv__OdomService_Response.
typedef struct minirys_sim__srv__OdomService_Response__Sequence
{
  minirys_sim__srv__OdomService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_sim__srv__OdomService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__STRUCT_H_
