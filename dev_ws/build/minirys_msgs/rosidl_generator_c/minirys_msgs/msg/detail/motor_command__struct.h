// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from minirys_msgs:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_
#define MINIRYS_MSGS__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_

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

/// Struct defined in msg/MotorCommand in the package minirys_msgs.
typedef struct minirys_msgs__msg__MotorCommand
{
  std_msgs__msg__Header header;
  double speed_l;
  double speed_r;
  bool enable;
} minirys_msgs__msg__MotorCommand;

// Struct for a sequence of minirys_msgs__msg__MotorCommand.
typedef struct minirys_msgs__msg__MotorCommand__Sequence
{
  minirys_msgs__msg__MotorCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_msgs__msg__MotorCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_MSGS__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_
