// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from minirys_sim:srv/CloseMenager.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM__SRV__DETAIL__CLOSE_MENAGER__STRUCT_H_
#define MINIRYS_SIM__SRV__DETAIL__CLOSE_MENAGER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CloseMenager in the package minirys_sim.
typedef struct minirys_sim__srv__CloseMenager_Request
{
  uint8_t structure_needs_at_least_one_member;
} minirys_sim__srv__CloseMenager_Request;

// Struct for a sequence of minirys_sim__srv__CloseMenager_Request.
typedef struct minirys_sim__srv__CloseMenager_Request__Sequence
{
  minirys_sim__srv__CloseMenager_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_sim__srv__CloseMenager_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CloseMenager in the package minirys_sim.
typedef struct minirys_sim__srv__CloseMenager_Response
{
  bool success;
} minirys_sim__srv__CloseMenager_Response;

// Struct for a sequence of minirys_sim__srv__CloseMenager_Response.
typedef struct minirys_sim__srv__CloseMenager_Response__Sequence
{
  minirys_sim__srv__CloseMenager_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} minirys_sim__srv__CloseMenager_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_SIM__SRV__DETAIL__CLOSE_MENAGER__STRUCT_H_
