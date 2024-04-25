// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from minirys_msgs:msg/RTTestResult.idl
// generated code does not contain a copyright notice
#include "minirys_msgs/msg/detail/rt_test_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
minirys_msgs__msg__RTTestResult__init(minirys_msgs__msg__RTTestResult * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    minirys_msgs__msg__RTTestResult__fini(msg);
    return false;
  }
  // current_latency
  // mean_latency
  // min_latency
  // max_latency
  // minor_pagefaults
  // major_pagefaults
  return true;
}

void
minirys_msgs__msg__RTTestResult__fini(minirys_msgs__msg__RTTestResult * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // current_latency
  // mean_latency
  // min_latency
  // max_latency
  // minor_pagefaults
  // major_pagefaults
}

bool
minirys_msgs__msg__RTTestResult__are_equal(const minirys_msgs__msg__RTTestResult * lhs, const minirys_msgs__msg__RTTestResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // current_latency
  if (lhs->current_latency != rhs->current_latency) {
    return false;
  }
  // mean_latency
  if (lhs->mean_latency != rhs->mean_latency) {
    return false;
  }
  // min_latency
  if (lhs->min_latency != rhs->min_latency) {
    return false;
  }
  // max_latency
  if (lhs->max_latency != rhs->max_latency) {
    return false;
  }
  // minor_pagefaults
  if (lhs->minor_pagefaults != rhs->minor_pagefaults) {
    return false;
  }
  // major_pagefaults
  if (lhs->major_pagefaults != rhs->major_pagefaults) {
    return false;
  }
  return true;
}

bool
minirys_msgs__msg__RTTestResult__copy(
  const minirys_msgs__msg__RTTestResult * input,
  minirys_msgs__msg__RTTestResult * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // current_latency
  output->current_latency = input->current_latency;
  // mean_latency
  output->mean_latency = input->mean_latency;
  // min_latency
  output->min_latency = input->min_latency;
  // max_latency
  output->max_latency = input->max_latency;
  // minor_pagefaults
  output->minor_pagefaults = input->minor_pagefaults;
  // major_pagefaults
  output->major_pagefaults = input->major_pagefaults;
  return true;
}

minirys_msgs__msg__RTTestResult *
minirys_msgs__msg__RTTestResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__RTTestResult * msg = (minirys_msgs__msg__RTTestResult *)allocator.allocate(sizeof(minirys_msgs__msg__RTTestResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(minirys_msgs__msg__RTTestResult));
  bool success = minirys_msgs__msg__RTTestResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
minirys_msgs__msg__RTTestResult__destroy(minirys_msgs__msg__RTTestResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    minirys_msgs__msg__RTTestResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
minirys_msgs__msg__RTTestResult__Sequence__init(minirys_msgs__msg__RTTestResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__RTTestResult * data = NULL;

  if (size) {
    data = (minirys_msgs__msg__RTTestResult *)allocator.zero_allocate(size, sizeof(minirys_msgs__msg__RTTestResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = minirys_msgs__msg__RTTestResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        minirys_msgs__msg__RTTestResult__fini(&data[i - 1]);
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
minirys_msgs__msg__RTTestResult__Sequence__fini(minirys_msgs__msg__RTTestResult__Sequence * array)
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
      minirys_msgs__msg__RTTestResult__fini(&array->data[i]);
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

minirys_msgs__msg__RTTestResult__Sequence *
minirys_msgs__msg__RTTestResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__RTTestResult__Sequence * array = (minirys_msgs__msg__RTTestResult__Sequence *)allocator.allocate(sizeof(minirys_msgs__msg__RTTestResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = minirys_msgs__msg__RTTestResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
minirys_msgs__msg__RTTestResult__Sequence__destroy(minirys_msgs__msg__RTTestResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    minirys_msgs__msg__RTTestResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
minirys_msgs__msg__RTTestResult__Sequence__are_equal(const minirys_msgs__msg__RTTestResult__Sequence * lhs, const minirys_msgs__msg__RTTestResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!minirys_msgs__msg__RTTestResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
minirys_msgs__msg__RTTestResult__Sequence__copy(
  const minirys_msgs__msg__RTTestResult__Sequence * input,
  minirys_msgs__msg__RTTestResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(minirys_msgs__msg__RTTestResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    minirys_msgs__msg__RTTestResult * data =
      (minirys_msgs__msg__RTTestResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!minirys_msgs__msg__RTTestResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          minirys_msgs__msg__RTTestResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!minirys_msgs__msg__RTTestResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
