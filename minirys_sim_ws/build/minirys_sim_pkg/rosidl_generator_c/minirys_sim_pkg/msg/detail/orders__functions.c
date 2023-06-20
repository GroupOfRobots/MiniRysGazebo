// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice
#include "minirys_sim_pkg/msg/detail/orders__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
minirys_sim_pkg__msg__Orders__init(minirys_sim_pkg__msg__Orders * msg)
{
  if (!msg) {
    return false;
  }
  // move
  // rotate
  // control_flag
  return true;
}

void
minirys_sim_pkg__msg__Orders__fini(minirys_sim_pkg__msg__Orders * msg)
{
  if (!msg) {
    return;
  }
  // move
  // rotate
  // control_flag
}

bool
minirys_sim_pkg__msg__Orders__are_equal(const minirys_sim_pkg__msg__Orders * lhs, const minirys_sim_pkg__msg__Orders * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // move
  if (lhs->move != rhs->move) {
    return false;
  }
  // rotate
  if (lhs->rotate != rhs->rotate) {
    return false;
  }
  // control_flag
  if (lhs->control_flag != rhs->control_flag) {
    return false;
  }
  return true;
}

bool
minirys_sim_pkg__msg__Orders__copy(
  const minirys_sim_pkg__msg__Orders * input,
  minirys_sim_pkg__msg__Orders * output)
{
  if (!input || !output) {
    return false;
  }
  // move
  output->move = input->move;
  // rotate
  output->rotate = input->rotate;
  // control_flag
  output->control_flag = input->control_flag;
  return true;
}

minirys_sim_pkg__msg__Orders *
minirys_sim_pkg__msg__Orders__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_sim_pkg__msg__Orders * msg = (minirys_sim_pkg__msg__Orders *)allocator.allocate(sizeof(minirys_sim_pkg__msg__Orders), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(minirys_sim_pkg__msg__Orders));
  bool success = minirys_sim_pkg__msg__Orders__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
minirys_sim_pkg__msg__Orders__destroy(minirys_sim_pkg__msg__Orders * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    minirys_sim_pkg__msg__Orders__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
minirys_sim_pkg__msg__Orders__Sequence__init(minirys_sim_pkg__msg__Orders__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_sim_pkg__msg__Orders * data = NULL;

  if (size) {
    data = (minirys_sim_pkg__msg__Orders *)allocator.zero_allocate(size, sizeof(minirys_sim_pkg__msg__Orders), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = minirys_sim_pkg__msg__Orders__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        minirys_sim_pkg__msg__Orders__fini(&data[i - 1]);
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
minirys_sim_pkg__msg__Orders__Sequence__fini(minirys_sim_pkg__msg__Orders__Sequence * array)
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
      minirys_sim_pkg__msg__Orders__fini(&array->data[i]);
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

minirys_sim_pkg__msg__Orders__Sequence *
minirys_sim_pkg__msg__Orders__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_sim_pkg__msg__Orders__Sequence * array = (minirys_sim_pkg__msg__Orders__Sequence *)allocator.allocate(sizeof(minirys_sim_pkg__msg__Orders__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = minirys_sim_pkg__msg__Orders__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
minirys_sim_pkg__msg__Orders__Sequence__destroy(minirys_sim_pkg__msg__Orders__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    minirys_sim_pkg__msg__Orders__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
minirys_sim_pkg__msg__Orders__Sequence__are_equal(const minirys_sim_pkg__msg__Orders__Sequence * lhs, const minirys_sim_pkg__msg__Orders__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!minirys_sim_pkg__msg__Orders__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
minirys_sim_pkg__msg__Orders__Sequence__copy(
  const minirys_sim_pkg__msg__Orders__Sequence * input,
  minirys_sim_pkg__msg__Orders__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(minirys_sim_pkg__msg__Orders);
    minirys_sim_pkg__msg__Orders * data =
      (minirys_sim_pkg__msg__Orders *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!minirys_sim_pkg__msg__Orders__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          minirys_sim_pkg__msg__Orders__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!minirys_sim_pkg__msg__Orders__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
