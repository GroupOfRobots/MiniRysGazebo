// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__FUNCTIONS_H_
#define MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "minirys_sim_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "minirys_sim_pkg/msg/detail/orders__struct.h"

/// Initialize msg/Orders message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * minirys_sim_pkg__msg__Orders
 * )) before or use
 * minirys_sim_pkg__msg__Orders__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
bool
minirys_sim_pkg__msg__Orders__init(minirys_sim_pkg__msg__Orders * msg);

/// Finalize msg/Orders message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
void
minirys_sim_pkg__msg__Orders__fini(minirys_sim_pkg__msg__Orders * msg);

/// Create msg/Orders message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * minirys_sim_pkg__msg__Orders__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
minirys_sim_pkg__msg__Orders *
minirys_sim_pkg__msg__Orders__create();

/// Destroy msg/Orders message.
/**
 * It calls
 * minirys_sim_pkg__msg__Orders__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
void
minirys_sim_pkg__msg__Orders__destroy(minirys_sim_pkg__msg__Orders * msg);

/// Check for msg/Orders message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
bool
minirys_sim_pkg__msg__Orders__are_equal(const minirys_sim_pkg__msg__Orders * lhs, const minirys_sim_pkg__msg__Orders * rhs);

/// Copy a msg/Orders message.
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
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
bool
minirys_sim_pkg__msg__Orders__copy(
  const minirys_sim_pkg__msg__Orders * input,
  minirys_sim_pkg__msg__Orders * output);

/// Initialize array of msg/Orders messages.
/**
 * It allocates the memory for the number of elements and calls
 * minirys_sim_pkg__msg__Orders__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
bool
minirys_sim_pkg__msg__Orders__Sequence__init(minirys_sim_pkg__msg__Orders__Sequence * array, size_t size);

/// Finalize array of msg/Orders messages.
/**
 * It calls
 * minirys_sim_pkg__msg__Orders__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
void
minirys_sim_pkg__msg__Orders__Sequence__fini(minirys_sim_pkg__msg__Orders__Sequence * array);

/// Create array of msg/Orders messages.
/**
 * It allocates the memory for the array and calls
 * minirys_sim_pkg__msg__Orders__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
minirys_sim_pkg__msg__Orders__Sequence *
minirys_sim_pkg__msg__Orders__Sequence__create(size_t size);

/// Destroy array of msg/Orders messages.
/**
 * It calls
 * minirys_sim_pkg__msg__Orders__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
void
minirys_sim_pkg__msg__Orders__Sequence__destroy(minirys_sim_pkg__msg__Orders__Sequence * array);

/// Check for msg/Orders message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
bool
minirys_sim_pkg__msg__Orders__Sequence__are_equal(const minirys_sim_pkg__msg__Orders__Sequence * lhs, const minirys_sim_pkg__msg__Orders__Sequence * rhs);

/// Copy an array of msg/Orders messages.
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
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim_pkg
bool
minirys_sim_pkg__msg__Orders__Sequence__copy(
  const minirys_sim_pkg__msg__Orders__Sequence * input,
  minirys_sim_pkg__msg__Orders__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__FUNCTIONS_H_
