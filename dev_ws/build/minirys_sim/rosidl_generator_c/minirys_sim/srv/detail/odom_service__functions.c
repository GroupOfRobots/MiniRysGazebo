// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from minirys_sim:srv/OdomService.idl
// generated code does not contain a copyright notice
#include "minirys_sim/srv/detail/odom_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `robot_namespace`
#include "rosidl_runtime_c/string_functions.h"

bool
minirys_sim__srv__OdomService_Request__init(minirys_sim__srv__OdomService_Request * msg)
{
  if (!msg) {
    return false;
  }
  // robot_namespace
  if (!rosidl_runtime_c__String__init(&msg->robot_namespace)) {
    minirys_sim__srv__OdomService_Request__fini(msg);
    return false;
  }
  return true;
}

void
minirys_sim__srv__OdomService_Request__fini(minirys_sim__srv__OdomService_Request * msg)
{
  if (!msg) {
    return;
  }
  // robot_namespace
  rosidl_runtime_c__String__fini(&msg->robot_namespace);
}

bool
minirys_sim__srv__OdomService_Request__are_equal(const minirys_sim__srv__OdomService_Request * lhs, const minirys_sim__srv__OdomService_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_namespace
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_namespace), &(rhs->robot_namespace)))
  {
    return false;
  }
  return true;
}

bool
minirys_sim__srv__OdomService_Request__copy(
  const minirys_sim__srv__OdomService_Request * input,
  minirys_sim__srv__OdomService_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_namespace
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_namespace), &(output->robot_namespace)))
  {
    return false;
  }
  return true;
}

minirys_sim__srv__OdomService_Request *
minirys_sim__srv__OdomService_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_sim__srv__OdomService_Request * msg = (minirys_sim__srv__OdomService_Request *)allocator.allocate(sizeof(minirys_sim__srv__OdomService_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(minirys_sim__srv__OdomService_Request));
  bool success = minirys_sim__srv__OdomService_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
minirys_sim__srv__OdomService_Request__destroy(minirys_sim__srv__OdomService_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    minirys_sim__srv__OdomService_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
minirys_sim__srv__OdomService_Request__Sequence__init(minirys_sim__srv__OdomService_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_sim__srv__OdomService_Request * data = NULL;

  if (size) {
    data = (minirys_sim__srv__OdomService_Request *)allocator.zero_allocate(size, sizeof(minirys_sim__srv__OdomService_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = minirys_sim__srv__OdomService_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        minirys_sim__srv__OdomService_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
minirys_sim__srv__OdomService_Request__Sequence__fini(minirys_sim__srv__OdomService_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      minirys_sim__srv__OdomService_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

minirys_sim__srv__OdomService_Request__Sequence *
minirys_sim__srv__OdomService_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_sim__srv__OdomService_Request__Sequence * array = (minirys_sim__srv__OdomService_Request__Sequence *)allocator.allocate(sizeof(minirys_sim__srv__OdomService_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = minirys_sim__srv__OdomService_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
minirys_sim__srv__OdomService_Request__Sequence__destroy(minirys_sim__srv__OdomService_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    minirys_sim__srv__OdomService_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
minirys_sim__srv__OdomService_Request__Sequence__are_equal(const minirys_sim__srv__OdomService_Request__Sequence * lhs, const minirys_sim__srv__OdomService_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!minirys_sim__srv__OdomService_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
minirys_sim__srv__OdomService_Request__Sequence__copy(
  const minirys_sim__srv__OdomService_Request__Sequence * input,
  minirys_sim__srv__OdomService_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(minirys_sim__srv__OdomService_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    minirys_sim__srv__OdomService_Request * data =
      (minirys_sim__srv__OdomService_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!minirys_sim__srv__OdomService_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          minirys_sim__srv__OdomService_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!minirys_sim__srv__OdomService_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
minirys_sim__srv__OdomService_Response__init(minirys_sim__srv__OdomService_Response * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // roll
  // pitch
  // yaw
  // success
  return true;
}

void
minirys_sim__srv__OdomService_Response__fini(minirys_sim__srv__OdomService_Response * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // roll
  // pitch
  // yaw
  // success
}

bool
minirys_sim__srv__OdomService_Response__are_equal(const minirys_sim__srv__OdomService_Response * lhs, const minirys_sim__srv__OdomService_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
minirys_sim__srv__OdomService_Response__copy(
  const minirys_sim__srv__OdomService_Response * input,
  minirys_sim__srv__OdomService_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  // success
  output->success = input->success;
  return true;
}

minirys_sim__srv__OdomService_Response *
minirys_sim__srv__OdomService_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_sim__srv__OdomService_Response * msg = (minirys_sim__srv__OdomService_Response *)allocator.allocate(sizeof(minirys_sim__srv__OdomService_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(minirys_sim__srv__OdomService_Response));
  bool success = minirys_sim__srv__OdomService_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
minirys_sim__srv__OdomService_Response__destroy(minirys_sim__srv__OdomService_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    minirys_sim__srv__OdomService_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
minirys_sim__srv__OdomService_Response__Sequence__init(minirys_sim__srv__OdomService_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_sim__srv__OdomService_Response * data = NULL;

  if (size) {
    data = (minirys_sim__srv__OdomService_Response *)allocator.zero_allocate(size, sizeof(minirys_sim__srv__OdomService_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = minirys_sim__srv__OdomService_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        minirys_sim__srv__OdomService_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
minirys_sim__srv__OdomService_Response__Sequence__fini(minirys_sim__srv__OdomService_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      minirys_sim__srv__OdomService_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

minirys_sim__srv__OdomService_Response__Sequence *
minirys_sim__srv__OdomService_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_sim__srv__OdomService_Response__Sequence * array = (minirys_sim__srv__OdomService_Response__Sequence *)allocator.allocate(sizeof(minirys_sim__srv__OdomService_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = minirys_sim__srv__OdomService_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
minirys_sim__srv__OdomService_Response__Sequence__destroy(minirys_sim__srv__OdomService_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    minirys_sim__srv__OdomService_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
minirys_sim__srv__OdomService_Response__Sequence__are_equal(const minirys_sim__srv__OdomService_Response__Sequence * lhs, const minirys_sim__srv__OdomService_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!minirys_sim__srv__OdomService_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
minirys_sim__srv__OdomService_Response__Sequence__copy(
  const minirys_sim__srv__OdomService_Response__Sequence * input,
  minirys_sim__srv__OdomService_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(minirys_sim__srv__OdomService_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    minirys_sim__srv__OdomService_Response * data =
      (minirys_sim__srv__OdomService_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!minirys_sim__srv__OdomService_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          minirys_sim__srv__OdomService_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!minirys_sim__srv__OdomService_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
