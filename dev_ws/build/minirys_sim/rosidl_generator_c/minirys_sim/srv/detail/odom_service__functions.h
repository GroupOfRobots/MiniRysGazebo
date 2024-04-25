// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from minirys_sim:srv/OdomService.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__FUNCTIONS_H_
#define MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "minirys_sim/msg/rosidl_generator_c__visibility_control.h"

#include "minirys_sim/srv/detail/odom_service__struct.h"

/// Initialize srv/OdomService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * minirys_sim__srv__OdomService_Request
 * )) before or use
 * minirys_sim__srv__OdomService_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Request__init(minirys_sim__srv__OdomService_Request * msg);

/// Finalize srv/OdomService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
void
minirys_sim__srv__OdomService_Request__fini(minirys_sim__srv__OdomService_Request * msg);

/// Create srv/OdomService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * minirys_sim__srv__OdomService_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
minirys_sim__srv__OdomService_Request *
minirys_sim__srv__OdomService_Request__create();

/// Destroy srv/OdomService message.
/**
 * It calls
 * minirys_sim__srv__OdomService_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
void
minirys_sim__srv__OdomService_Request__destroy(minirys_sim__srv__OdomService_Request * msg);

/// Check for srv/OdomService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Request__are_equal(const minirys_sim__srv__OdomService_Request * lhs, const minirys_sim__srv__OdomService_Request * rhs);

/// Copy a srv/OdomService message.
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
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Request__copy(
  const minirys_sim__srv__OdomService_Request * input,
  minirys_sim__srv__OdomService_Request * output);

/// Initialize array of srv/OdomService messages.
/**
 * It allocates the memory for the number of elements and calls
 * minirys_sim__srv__OdomService_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Request__Sequence__init(minirys_sim__srv__OdomService_Request__Sequence * array, size_t size);

/// Finalize array of srv/OdomService messages.
/**
 * It calls
 * minirys_sim__srv__OdomService_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
void
minirys_sim__srv__OdomService_Request__Sequence__fini(minirys_sim__srv__OdomService_Request__Sequence * array);

/// Create array of srv/OdomService messages.
/**
 * It allocates the memory for the array and calls
 * minirys_sim__srv__OdomService_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
minirys_sim__srv__OdomService_Request__Sequence *
minirys_sim__srv__OdomService_Request__Sequence__create(size_t size);

/// Destroy array of srv/OdomService messages.
/**
 * It calls
 * minirys_sim__srv__OdomService_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
void
minirys_sim__srv__OdomService_Request__Sequence__destroy(minirys_sim__srv__OdomService_Request__Sequence * array);

/// Check for srv/OdomService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Request__Sequence__are_equal(const minirys_sim__srv__OdomService_Request__Sequence * lhs, const minirys_sim__srv__OdomService_Request__Sequence * rhs);

/// Copy an array of srv/OdomService messages.
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
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Request__Sequence__copy(
  const minirys_sim__srv__OdomService_Request__Sequence * input,
  minirys_sim__srv__OdomService_Request__Sequence * output);

/// Initialize srv/OdomService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * minirys_sim__srv__OdomService_Response
 * )) before or use
 * minirys_sim__srv__OdomService_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Response__init(minirys_sim__srv__OdomService_Response * msg);

/// Finalize srv/OdomService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
void
minirys_sim__srv__OdomService_Response__fini(minirys_sim__srv__OdomService_Response * msg);

/// Create srv/OdomService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * minirys_sim__srv__OdomService_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
minirys_sim__srv__OdomService_Response *
minirys_sim__srv__OdomService_Response__create();

/// Destroy srv/OdomService message.
/**
 * It calls
 * minirys_sim__srv__OdomService_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
void
minirys_sim__srv__OdomService_Response__destroy(minirys_sim__srv__OdomService_Response * msg);

/// Check for srv/OdomService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Response__are_equal(const minirys_sim__srv__OdomService_Response * lhs, const minirys_sim__srv__OdomService_Response * rhs);

/// Copy a srv/OdomService message.
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
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Response__copy(
  const minirys_sim__srv__OdomService_Response * input,
  minirys_sim__srv__OdomService_Response * output);

/// Initialize array of srv/OdomService messages.
/**
 * It allocates the memory for the number of elements and calls
 * minirys_sim__srv__OdomService_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Response__Sequence__init(minirys_sim__srv__OdomService_Response__Sequence * array, size_t size);

/// Finalize array of srv/OdomService messages.
/**
 * It calls
 * minirys_sim__srv__OdomService_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
void
minirys_sim__srv__OdomService_Response__Sequence__fini(minirys_sim__srv__OdomService_Response__Sequence * array);

/// Create array of srv/OdomService messages.
/**
 * It allocates the memory for the array and calls
 * minirys_sim__srv__OdomService_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
minirys_sim__srv__OdomService_Response__Sequence *
minirys_sim__srv__OdomService_Response__Sequence__create(size_t size);

/// Destroy array of srv/OdomService messages.
/**
 * It calls
 * minirys_sim__srv__OdomService_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
void
minirys_sim__srv__OdomService_Response__Sequence__destroy(minirys_sim__srv__OdomService_Response__Sequence * array);

/// Check for srv/OdomService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Response__Sequence__are_equal(const minirys_sim__srv__OdomService_Response__Sequence * lhs, const minirys_sim__srv__OdomService_Response__Sequence * rhs);

/// Copy an array of srv/OdomService messages.
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
ROSIDL_GENERATOR_C_PUBLIC_minirys_sim
bool
minirys_sim__srv__OdomService_Response__Sequence__copy(
  const minirys_sim__srv__OdomService_Response__Sequence * input,
  minirys_sim__srv__OdomService_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__FUNCTIONS_H_
