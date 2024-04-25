// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from minirys_msgs:msg/AngularPose.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__STRUCT_H_
#define MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/AngularPose in the package minirys_msgs.
typedef struct minirys_msgs__msg__AngularPose
{
  std_msgs__msg__Header header;
  float angular_position;
  float angular_velocity;
} minirys_msgs__msg__AngularPose;

// Struct for a sequence of minirys_msgs__msg__AngularPose.
typedef struct minirys_msgs__msg__AngularPose__Sequence
{
  minirys_msgs__msg__AngularPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_msgs__msg__AngularPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__STRUCT_H_