// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from minirys_msgs:msg/MotorDriverStatus.idl
// generated code does not contain a copyright notice
#include "minirys_msgs/msg/detail/motor_driver_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "minirys_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "minirys_msgs/msg/detail/motor_driver_status__struct.h"
#include "minirys_msgs/msg/detail/motor_driver_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_minirys_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_minirys_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_minirys_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _MotorDriverStatus__ros_msg_type = minirys_msgs__msg__MotorDriverStatus;

static bool _MotorDriverStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MotorDriverStatus__ros_msg_type * ros_message = static_cast<const _MotorDriverStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: hi_z
  {
    cdr << (ros_message->hi_z ? true : false);
  }

  // Field name: busy
  {
    cdr << (ros_message->busy ? true : false);
  }

  // Field name: direction
  {
    cdr << (ros_message->direction ? true : false);
  }

  // Field name: motor_stopped
  {
    cdr << (ros_message->motor_stopped ? true : false);
  }

  // Field name: motor_accelerating
  {
    cdr << (ros_message->motor_accelerating ? true : false);
  }

  // Field name: motor_decelerating
  {
    cdr << (ros_message->motor_decelerating ? true : false);
  }

  // Field name: motor_const_speed
  {
    cdr << (ros_message->motor_const_speed ? true : false);
  }

  // Field name: undervoltage
  {
    cdr << (ros_message->undervoltage ? true : false);
  }

  // Field name: thermal_warning
  {
    cdr << (ros_message->thermal_warning ? true : false);
  }

  // Field name: thermal_shutdown
  {
    cdr << (ros_message->thermal_shutdown ? true : false);
  }

  // Field name: overcurrent
  {
    cdr << (ros_message->overcurrent ? true : false);
  }

  // Field name: step_loss_a
  {
    cdr << (ros_message->step_loss_a ? true : false);
  }

  // Field name: step_loss_b
  {
    cdr << (ros_message->step_loss_b ? true : false);
  }

  return true;
}

static bool _MotorDriverStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MotorDriverStatus__ros_msg_type * ros_message = static_cast<_MotorDriverStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: hi_z
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hi_z = tmp ? true : false;
  }

  // Field name: busy
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->busy = tmp ? true : false;
  }

  // Field name: direction
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->direction = tmp ? true : false;
  }

  // Field name: motor_stopped
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->motor_stopped = tmp ? true : false;
  }

  // Field name: motor_accelerating
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->motor_accelerating = tmp ? true : false;
  }

  // Field name: motor_decelerating
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->motor_decelerating = tmp ? true : false;
  }

  // Field name: motor_const_speed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->motor_const_speed = tmp ? true : false;
  }

  // Field name: undervoltage
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->undervoltage = tmp ? true : false;
  }

  // Field name: thermal_warning
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->thermal_warning = tmp ? true : false;
  }

  // Field name: thermal_shutdown
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->thermal_shutdown = tmp ? true : false;
  }

  // Field name: overcurrent
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->overcurrent = tmp ? true : false;
  }

  // Field name: step_loss_a
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->step_loss_a = tmp ? true : false;
  }

  // Field name: step_loss_b
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->step_loss_b = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_minirys_msgs
size_t get_serialized_size_minirys_msgs__msg__MotorDriverStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MotorDriverStatus__ros_msg_type * ros_message = static_cast<const _MotorDriverStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name hi_z
  {
    size_t item_size = sizeof(ros_message->hi_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name busy
  {
    size_t item_size = sizeof(ros_message->busy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name direction
  {
    size_t item_size = sizeof(ros_message->direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_stopped
  {
    size_t item_size = sizeof(ros_message->motor_stopped);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_accelerating
  {
    size_t item_size = sizeof(ros_message->motor_accelerating);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_decelerating
  {
    size_t item_size = sizeof(ros_message->motor_decelerating);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_const_speed
  {
    size_t item_size = sizeof(ros_message->motor_const_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name undervoltage
  {
    size_t item_size = sizeof(ros_message->undervoltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name thermal_warning
  {
    size_t item_size = sizeof(ros_message->thermal_warning);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name thermal_shutdown
  {
    size_t item_size = sizeof(ros_message->thermal_shutdown);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name overcurrent
  {
    size_t item_size = sizeof(ros_message->overcurrent);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name step_loss_a
  {
    size_t item_size = sizeof(ros_message->step_loss_a);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name step_loss_b
  {
    size_t item_size = sizeof(ros_message->step_loss_b);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MotorDriverStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_minirys_msgs__msg__MotorDriverStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_minirys_msgs
size_t max_serialized_size_minirys_msgs__msg__MotorDriverStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: hi_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: busy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: direction
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_stopped
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_accelerating
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_decelerating
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_const_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: undervoltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: thermal_warning
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: thermal_shutdown
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: overcurrent
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: step_loss_a
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: step_loss_b
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = minirys_msgs__msg__MotorDriverStatus;
    is_plain =
      (
      offsetof(DataType, step_loss_b) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MotorDriverStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_minirys_msgs__msg__MotorDriverStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MotorDriverStatus = {
  "minirys_msgs::msg",
  "MotorDriverStatus",
  _MotorDriverStatus__cdr_serialize,
  _MotorDriverStatus__cdr_deserialize,
  _MotorDriverStatus__get_serialized_size,
  _MotorDriverStatus__max_serialized_size
};

static rosidl_message_type_support_t _MotorDriverStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MotorDriverStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, minirys_msgs, msg, MotorDriverStatus)() {
  return &_MotorDriverStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
