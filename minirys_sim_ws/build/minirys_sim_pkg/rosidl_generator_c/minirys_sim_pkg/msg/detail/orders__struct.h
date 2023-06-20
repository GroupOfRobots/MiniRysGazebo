// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__STRUCT_H_
#define MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Orders in the package minirys_sim_pkg.
typedef struct minirys_sim_pkg__msg__Orders
{
  float move;
  float rotate;
  int8_t control_flag;
} minirys_sim_pkg__msg__Orders;

// Struct for a sequence of minirys_sim_pkg__msg__Orders.
typedef struct minirys_sim_pkg__msg__Orders__Sequence
{
  minirys_sim_pkg__msg__Orders * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_sim_pkg__msg__Orders__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__STRUCT_H_
