// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from minirys_msgs:msg/MotorDriverStatus.idl
// generated code does not contain a copyright notice
#include "minirys_msgs/msg/detail/motor_driver_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
minirys_msgs__msg__MotorDriverStatus__init(minirys_msgs__msg__MotorDriverStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    minirys_msgs__msg__MotorDriverStatus__fini(msg);
    return false;
  }
  // hi_z
  msg->hi_z = false;
  // busy
  msg->busy = false;
  // direction
  msg->direction = false;
  // motor_stopped
  msg->motor_stopped = false;
  // motor_accelerating
  msg->motor_accelerating = false;
  // motor_decelerating
  msg->motor_decelerating = false;
  // motor_const_speed
  msg->motor_const_speed = false;
  // undervoltage
  msg->undervoltage = false;
  // thermal_warning
  msg->thermal_warning = false;
  // thermal_shutdown
  msg->thermal_shutdown = false;
  // overcurrent
  msg->overcurrent = false;
  // step_loss_a
  msg->step_loss_a = false;
  // step_loss_b
  msg->step_loss_b = false;
  return true;
}

void
minirys_msgs__msg__MotorDriverStatus__fini(minirys_msgs__msg__MotorDriverStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // hi_z
  // busy
  // direction
  // motor_stopped
  // motor_accelerating
  // motor_decelerating
  // motor_const_speed
  // undervoltage
  // thermal_warning
  // thermal_shutdown
  // overcurrent
  // step_loss_a
  // step_loss_b
}

bool
minirys_msgs__msg__MotorDriverStatus__are_equal(const minirys_msgs__msg__MotorDriverStatus * lhs, const minirys_msgs__msg__MotorDriverStatus * rhs)
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
  // hi_z
  if (lhs->hi_z != rhs->hi_z) {
    return false;
  }
  // busy
  if (lhs->busy != rhs->busy) {
    return false;
  }
  // direction
  if (lhs->direction != rhs->direction) {
    return false;
  }
  // motor_stopped
  if (lhs->motor_stopped != rhs->motor_stopped) {
    return false;
  }
  // motor_accelerating
  if (lhs->motor_accelerating != rhs->motor_accelerating) {
    return false;
  }
  // motor_decelerating
  if (lhs->motor_decelerating != rhs->motor_decelerating) {
    return false;
  }
  // motor_const_speed
  if (lhs->motor_const_speed != rhs->motor_const_speed) {
    return false;
  }
  // undervoltage
  if (lhs->undervoltage != rhs->undervoltage) {
    return false;
  }
  // thermal_warning
  if (lhs->thermal_warning != rhs->thermal_warning) {
    return false;
  }
  // thermal_shutdown
  if (lhs->thermal_shutdown != rhs->thermal_shutdown) {
    return false;
  }
  // overcurrent
  if (lhs->overcurrent != rhs->overcurrent) {
    return false;
  }
  // step_loss_a
  if (lhs->step_loss_a != rhs->step_loss_a) {
    return false;
  }
  // step_loss_b
  if (lhs->step_loss_b != rhs->step_loss_b) {
    return false;
  }
  return true;
}

bool
minirys_msgs__msg__MotorDriverStatus__copy(
  const minirys_msgs__msg__MotorDriverStatus * input,
  minirys_msgs__msg__MotorDriverStatus * output)
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
  // hi_z
  output->hi_z = input->hi_z;
  // busy
  output->busy = input->busy;
  // direction
  output->direction = input->direction;
  // motor_stopped
  output->motor_stopped = input->motor_stopped;
  // motor_accelerating
  output->motor_accelerating = input->motor_accelerating;
  // motor_decelerating
  output->motor_decelerating = input->motor_decelerating;
  // motor_const_speed
  output->motor_const_speed = input->motor_const_speed;
  // undervoltage
  output->undervoltage = input->undervoltage;
  // thermal_warning
  output->thermal_warning = input->thermal_warning;
  // thermal_shutdown
  output->thermal_shutdown = input->thermal_shutdown;
  // overcurrent
  output->overcurrent = input->overcurrent;
  // step_loss_a
  output->step_loss_a = input->step_loss_a;
  // step_loss_b
  output->step_loss_b = input->step_loss_b;
  return true;
}

minirys_msgs__msg__MotorDriverStatus *
minirys_msgs__msg__MotorDriverStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__MotorDriverStatus * msg = (minirys_msgs__msg__MotorDriverStatus *)allocator.allocate(sizeof(minirys_msgs__msg__MotorDriverStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(minirys_msgs__msg__MotorDriverStatus));
  bool success = minirys_msgs__msg__MotorDriverStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
minirys_msgs__msg__MotorDriverStatus__destroy(minirys_msgs__msg__MotorDriverStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    minirys_msgs__msg__MotorDriverStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
minirys_msgs__msg__MotorDriverStatus__Sequence__init(minirys_msgs__msg__MotorDriverStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__MotorDriverStatus * data = NULL;

  if (size) {
    data = (minirys_msgs__msg__MotorDriverStatus *)allocator.zero_allocate(size, sizeof(minirys_msgs__msg__MotorDriverStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = minirys_msgs__msg__MotorDriverStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        minirys_msgs__msg__MotorDriverStatus__fini(&data[i - 1]);
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
minirys_msgs__msg__MotorDriverStatus__Sequence__fini(minirys_msgs__msg__MotorDriverStatus__Sequence * array)
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
      minirys_msgs__msg__MotorDriverStatus__fini(&array->data[i]);
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

minirys_msgs__msg__MotorDriverStatus__Sequence *
minirys_msgs__msg__MotorDriverStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  minirys_msgs__msg__MotorDriverStatus__Sequence * array = (minirys_msgs__msg__MotorDriverStatus__Sequence *)allocator.allocate(sizeof(minirys_msgs__msg__MotorDriverStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = minirys_msgs__msg__MotorDriverStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
minirys_msgs__msg__MotorDriverStatus__Sequence__destroy(minirys_msgs__msg__MotorDriverStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    minirys_msgs__msg__MotorDriverStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
minirys_msgs__msg__MotorDriverStatus__Sequence__are_equal(const minirys_msgs__msg__MotorDriverStatus__Sequence * lhs, const minirys_msgs__msg__MotorDriverStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!minirys_msgs__msg__MotorDriverStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
minirys_msgs__msg__MotorDriverStatus__Sequence__copy(
  const minirys_msgs__msg__MotorDriverStatus__Sequence * input,
  minirys_msgs__msg__MotorDriverStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(minirys_msgs__msg__MotorDriverStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    minirys_msgs__msg__MotorDriverStatus * data =
      (minirys_msgs__msg__MotorDriverStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!minirys_msgs__msg__MotorDriverStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          minirys_msgs__msg__MotorDriverStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!minirys_msgs__msg__MotorDriverStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
