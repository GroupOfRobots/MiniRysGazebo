// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from minirys_msgs:msg/RTTestResult.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__STRUCT_H_
#define MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/RTTestResult in the package minirys_msgs.
/**
  * Based on the RttestResult from the demos/pendulum_msgs package:
  * https://github.com/ros2/demos/blob/master/pendulum_msgs/msg/RttestResults.msg
 */
typedef struct minirys_msgs__msg__RTTestResult
{
  builtin_interfaces__msg__Time stamp;
  uint64_t current_latency;
  double mean_latency;
  uint64_t min_latency;
  uint64_t max_latency;
  uint64_t minor_pagefaults;
  uint64_t major_pagefaults;
} minirys_msgs__msg__RTTestResult;

// Struct for a sequence of minirys_msgs__msg__RTTestResult.
typedef struct minirys_msgs__msg__RTTestResult__Sequence
{
  minirys_msgs__msg__RTTestResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_msgs__msg__RTTestResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__STRUCT_H_
