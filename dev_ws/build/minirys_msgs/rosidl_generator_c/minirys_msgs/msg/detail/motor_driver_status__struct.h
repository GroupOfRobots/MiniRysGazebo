// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from minirys_msgs:msg/MotorDriverStatus.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__STRUCT_H_
#define MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DIRECTION_FWD'.
static const bool minirys_msgs__msg__MotorDriverStatus__DIRECTION_FWD = true;

/// Constant 'DIRECTION_REV'.
static const bool minirys_msgs__msg__MotorDriverStatus__DIRECTION_REV = false;

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/MotorDriverStatus in the package minirys_msgs.
typedef struct minirys_msgs__msg__MotorDriverStatus
{
  std_msgs__msg__Header header;
  /// For an explanation on the fields' meanings, see https://mjbogusz.gitlab.io/l6470-linux/
  bool hi_z;
  bool busy;
  bool direction;
  bool motor_stopped;
  bool motor_accelerating;
  bool motor_decelerating;
  bool motor_const_speed;
  bool undervoltage;
  bool thermal_warning;
  bool thermal_shutdown;
  bool overcurrent;
  bool step_loss_a;
  bool step_loss_b;
} minirys_msgs__msg__MotorDriverStatus;

// Struct for a sequence of minirys_msgs__msg__MotorDriverStatus.
typedef struct minirys_msgs__msg__MotorDriverStatus__Sequence
{
  minirys_msgs__msg__MotorDriverStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_msgs__msg__MotorDriverStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__STRUCT_H_
