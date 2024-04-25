// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from minirys_msgs:msg/AngularPose.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__FUNCTIONS_H_
#define MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "minirys_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "minirys_msgs/msg/detail/angular_pose__struct.h"

/// Initialize msg/AngularPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * minirys_msgs__msg__AngularPose
 * )) before or use
 * minirys_msgs__msg__AngularPose__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
bool
minirys_msgs__msg__AngularPose__init(minirys_msgs__msg__AngularPose * msg);

/// Finalize msg/AngularPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
void
minirys_msgs__msg__AngularPose__fini(minirys_msgs__msg__AngularPose * msg);

/// Create msg/AngularPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * minirys_msgs__msg__AngularPose__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
minirys_msgs__msg__AngularPose *
minirys_msgs__msg__AngularPose__create();

/// Destroy msg/AngularPose message.
/**
 * It calls
 * minirys_msgs__msg__AngularPose__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
void
minirys_msgs__msg__AngularPose__destroy(minirys_msgs__msg__AngularPose * msg);

/// Check for msg/AngularPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
bool
minirys_msgs__msg__AngularPose__are_equal(const minirys_msgs__msg__AngularPose * lhs, const minirys_msgs__msg__AngularPose * rhs);

/// Copy a msg/AngularPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
bool
minirys_msgs__msg__AngularPose__copy(
  const minirys_msgs__msg__AngularPose * input,
  minirys_msgs__msg__AngularPose * output);

/// Initialize array of msg/AngularPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * minirys_msgs__msg__AngularPose__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
bool
minirys_msgs__msg__AngularPose__Sequence__init(minirys_msgs__msg__AngularPose__Sequence * array, size_t size);

/// Finalize array of msg/AngularPose messages.
/**
 * It calls
 * minirys_msgs__msg__AngularPose__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
void
minirys_msgs__msg__AngularPose__Sequence__fini(minirys_msgs__msg__AngularPose__Sequence * array);

/// Create array of msg/AngularPose messages.
/**
 * It allocates the memory for the array and calls
 * minirys_msgs__msg__AngularPose__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
minirys_msgs__msg__AngularPose__Sequence *
minirys_msgs__msg__AngularPose__Sequence__create(size_t size);

/// Destroy array of msg/AngularPose messages.
/**
 * It calls
 * minirys_msgs__msg__AngularPose__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
void
minirys_msgs__msg__AngularPose__Sequence__destroy(minirys_msgs__msg__AngularPose__Sequence * array);

/// Check for msg/AngularPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
bool
minirys_msgs__msg__AngularPose__Sequence__are_equal(const minirys_msgs__msg__AngularPose__Sequence * lhs, const minirys_msgs__msg__AngularPose__Sequence * rhs);

/// Copy an array of msg/AngularPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_msgs
bool
minirys_msgs__msg__AngularPose__Sequence__copy(
  const minirys_msgs__msg__AngularPose__Sequence * input,
  minirys_msgs__msg__AngularPose__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_MSGS__MSG__DETAIL__ANGULAR_POSE__FUNCTIONS_H_
