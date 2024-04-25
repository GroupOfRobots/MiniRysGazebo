// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from minirys_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__SRV__DETAIL__SET_POSE__STRUCT_H_
#define MINIRYS_MSGS__SRV__DETAIL__SET_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/SetPose in the package minirys_msgs.
typedef struct minirys_msgs__srv__SetPose_Request
{
  geometry_msgs__msg__Pose pose;
} minirys_msgs__srv__SetPose_Request;

// Struct for a sequence of minirys_msgs__srv__SetPose_Request.
typedef struct minirys_msgs__srv__SetPose_Request__Sequence
{
  minirys_msgs__srv__SetPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_msgs__srv__SetPose_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetPose in the package minirys_msgs.
typedef struct minirys_msgs__srv__SetPose_Response
{
  uint8_t structure_needs_at_least_one_member;
} minirys_msgs__srv__SetPose_Response;

// Struct for a sequence of minirys_msgs__srv__SetPose_Response.
typedef struct minirys_msgs__srv__SetPose_Response__Sequence
{
  minirys_msgs__srv__SetPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_msgs__srv__SetPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_MSGS__SRV__DETAIL__SET_POSE__STRUCT_H_
