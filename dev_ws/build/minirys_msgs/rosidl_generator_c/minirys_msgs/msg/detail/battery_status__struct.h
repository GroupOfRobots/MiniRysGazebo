// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from minirys_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_H_
#define MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_H_

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

/// Struct defined in msg/BatteryStatus in the package minirys_msgs.
typedef struct minirys_msgs__msg__BatteryStatus
{
  std_msgs__msg__Header header;
  float voltage_cell1;
  float voltage_cell2;
  float voltage_cell3;
  bool undervoltage_warning;
  bool undervoltage_error;
} minirys_msgs__msg__BatteryStatus;

// Struct for a sequence of minirys_msgs__msg__BatteryStatus.
typedef struct minirys_msgs__msg__BatteryStatus__Sequence
{
  minirys_msgs__msg__BatteryStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_msgs__msg__BatteryStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_H_
