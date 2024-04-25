// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from minirys_msgs:msg/MotorCommand.idl
// generated code does not contain a copyright notice
#include "minirys_msgs/msg/detail/motor_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
minirys_msgs__msg__MotorCommand__init(minirys_msgs__msg__MotorCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    minirys_msgs__msg__MotorCommand__fini(msg);
    return false;
  }
  // speed_l
  // speed_r
  // enable
  return true;
}

void
minirys_msgs__msg__MotorCommand__fini(minirys_msgs__msg__MotorCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // speed_l
  // speed_r
  // enable
}

bool
minirys_msgs__msg__MotorCommand__are_equal(const minirys_msgs__msg__MotorCommand * lhs, const minirys_msgs__msg__MotorCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // speed_l
  if (lhs->speed_l != rhs->speed_l) {
    return false;
  }
  // speed_r
  if (lhs->speed_r != rhs->speed_r) {
    return false;
  }
  // enable
  if (lhs->enable != rhs->enable) {
    return false;
  }
  return true;
}

bool
minirys_msgs__msg__MotorCommand__copy(
  const minirys_msgs__msg__MotorCommand * input,
  minirys_msgs__msg__MotorCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // speed_l
  output->speed_l = input->speed_l;
  // speed_r
  output->speed_r = input->speed_r;
  // enable
  output->enable = input->enable;
  return true;
}

minirys_msgs__msg__MotorCommand *
minirys_msgs__msg__MotorCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__MotorCommand * msg = (minirys_msgs__msg__MotorCommand *)allocator.allocate(sizeof(minirys_msgs__msg__MotorCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(minirys_msgs__msg__MotorCommand));
  bool success = minirys_msgs__msg__MotorCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
minirys_msgs__msg__MotorCommand__destroy(minirys_msgs__msg__MotorCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    minirys_msgs__msg__MotorCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
minirys_msgs__msg__MotorCommand__Sequence__init(minirys_msgs__msg__MotorCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__MotorCommand * data = NULL;

  if (size) {
    data = (minirys_msgs__msg__MotorCommand *)allocator.zero_allocate(size, sizeof(minirys_msgs__msg__MotorCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = minirys_msgs__msg__MotorCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        minirys_msgs__msg__MotorCommand__fini(&data[i - 1]);
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
minirys_msgs__msg__MotorCommand__Sequence__fini(minirys_msgs__msg__MotorCommand__Sequence * array)
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
      minirys_msgs__msg__MotorCommand__fini(&array->data[i]);
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

minirys_msgs__msg__MotorCommand__Sequence *
minirys_msgs__msg__MotorCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__MotorCommand__Sequence * array = (minirys_msgs__msg__MotorCommand__Sequence *)allocator.allocate(sizeof(minirys_msgs__msg__MotorCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = minirys_msgs__msg__MotorCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
minirys_msgs__msg__MotorCommand__Sequence__destroy(minirys_msgs__msg__MotorCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    minirys_msgs__msg__MotorCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
minirys_msgs__msg__MotorCommand__Sequence__are_equal(const minirys_msgs__msg__MotorCommand__Sequence * lhs, const minirys_msgs__msg__MotorCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!minirys_msgs__msg__MotorCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
minirys_msgs__msg__MotorCommand__Sequence__copy(
  const minirys_msgs__msg__MotorCommand__Sequence * input,
  minirys_msgs__msg__MotorCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(minirys_msgs__msg__MotorCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    minirys_msgs__msg__MotorCommand * data =
      (minirys_msgs__msg__MotorCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!minirys_msgs__msg__MotorCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          minirys_msgs__msg__MotorCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!minirys_msgs__msg__MotorCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
