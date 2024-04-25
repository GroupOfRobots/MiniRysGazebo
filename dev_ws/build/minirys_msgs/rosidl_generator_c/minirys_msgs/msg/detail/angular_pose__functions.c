// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from minirys_msgs:msg/AngularPose.idl
// generated code does not contain a copyright notice
#include "minirys_msgs/msg/detail/angular_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
minirys_msgs__msg__AngularPose__init(minirys_msgs__msg__AngularPose * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    minirys_msgs__msg__AngularPose__fini(msg);
    return false;
  }
  // angular_position
  msg->angular_position = 0.0f;
  // angular_velocity
  msg->angular_velocity = 0.0f;
  return true;
}

void
minirys_msgs__msg__AngularPose__fini(minirys_msgs__msg__AngularPose * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // angular_position
  // angular_velocity
}

bool
minirys_msgs__msg__AngularPose__are_equal(const minirys_msgs__msg__AngularPose * lhs, const minirys_msgs__msg__AngularPose * rhs)
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
  // angular_position
  if (lhs->angular_position != rhs->angular_position) {
    return false;
  }
  // angular_velocity
  if (lhs->angular_velocity != rhs->angular_velocity) {
    return false;
  }
  return true;
}

bool
minirys_msgs__msg__AngularPose__copy(
  const minirys_msgs__msg__AngularPose * input,
  minirys_msgs__msg__AngularPose * output)
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
  // angular_position
  output->angular_position = input->angular_position;
  // angular_velocity
  output->angular_velocity = input->angular_velocity;
  return true;
}

minirys_msgs__msg__AngularPose *
minirys_msgs__msg__AngularPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__AngularPose * msg = (minirys_msgs__msg__AngularPose *)allocator.allocate(sizeof(minirys_msgs__msg__AngularPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(minirys_msgs__msg__AngularPose));
  bool success = minirys_msgs__msg__AngularPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
minirys_msgs__msg__AngularPose__destroy(minirys_msgs__msg__AngularPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    minirys_msgs__msg__AngularPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
minirys_msgs__msg__AngularPose__Sequence__init(minirys_msgs__msg__AngularPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__AngularPose * data = NULL;

  if (size) {
    data = (minirys_msgs__msg__AngularPose *)allocator.zero_allocate(size, sizeof(minirys_msgs__msg__AngularPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = minirys_msgs__msg__AngularPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        minirys_msgs__msg__AngularPose__fini(&data[i - 1]);
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
minirys_msgs__msg__AngularPose__Sequence__fini(minirys_msgs__msg__AngularPose__Sequence * array)
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
      minirys_msgs__msg__AngularPose__fini(&array->data[i]);
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

minirys_msgs__msg__AngularPose__Sequence *
minirys_msgs__msg__AngularPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__AngularPose__Sequence * array = (minirys_msgs__msg__AngularPose__Sequence *)allocator.allocate(sizeof(minirys_msgs__msg__AngularPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = minirys_msgs__msg__AngularPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
minirys_msgs__msg__AngularPose__Sequence__destroy(minirys_msgs__msg__AngularPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    minirys_msgs__msg__AngularPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
minirys_msgs__msg__AngularPose__Sequence__are_equal(const minirys_msgs__msg__AngularPose__Sequence * lhs, const minirys_msgs__msg__AngularPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!minirys_msgs__msg__AngularPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
minirys_msgs__msg__AngularPose__Sequence__copy(
  const minirys_msgs__msg__AngularPose__Sequence * input,
  minirys_msgs__msg__AngularPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(minirys_msgs__msg__AngularPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    minirys_msgs__msg__AngularPose * data =
      (minirys_msgs__msg__AngularPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!minirys_msgs__msg__AngularPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          minirys_msgs__msg__AngularPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!minirys_msgs__msg__AngularPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
