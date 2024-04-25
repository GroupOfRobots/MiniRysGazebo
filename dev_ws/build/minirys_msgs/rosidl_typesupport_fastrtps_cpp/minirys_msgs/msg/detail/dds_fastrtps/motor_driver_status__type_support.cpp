// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from minirys_msgs:msg/MotorDriverStatus.idl
// generated code does not contain a copyright notice
#include "minirys_msgs/msg/detail/motor_driver_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "minirys_msgs/msg/detail/motor_driver_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace minirys_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_msgs
cdr_serialize(
  const minirys_msgs::msg::MotorDriverStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: hi_z
  cdr << (ros_message.hi_z ? true : false);
  // Member: busy
  cdr << (ros_message.busy ? true : false);
  // Member: direction
  cdr << (ros_message.direction ? true : false);
  // Member: motor_stopped
  cdr << (ros_message.motor_stopped ? true : false);
  // Member: motor_accelerating
  cdr << (ros_message.motor_accelerating ? true : false);
  // Member: motor_decelerating
  cdr << (ros_message.motor_decelerating ? true : false);
  // Member: motor_const_speed
  cdr << (ros_message.motor_const_speed ? true : false);
  // Member: undervoltage
  cdr << (ros_message.undervoltage ? true : false);
  // Member: thermal_warning
  cdr << (ros_message.thermal_warning ? true : false);
  // Member: thermal_shutdown
  cdr << (ros_message.thermal_shutdown ? true : false);
  // Member: overcurrent
  cdr << (ros_message.overcurrent ? true : false);
  // Member: step_loss_a
  cdr << (ros_message.step_loss_a ? true : false);
  // Member: step_loss_b
  cdr << (ros_message.step_loss_b ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  minirys_msgs::msg::MotorDriverStatus & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: hi_z
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hi_z = tmp ? true : false;
  }

  // Member: busy
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.busy = tmp ? true : false;
  }

  // Member: direction
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.direction = tmp ? true : false;
  }

  // Member: motor_stopped
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.motor_stopped = tmp ? true : false;
  }

  // Member: motor_accelerating
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.motor_accelerating = tmp ? true : false;
  }

  // Member: motor_decelerating
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.motor_decelerating = tmp ? true : false;
  }

  // Member: motor_const_speed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.motor_const_speed = tmp ? true : false;
  }

  // Member: undervoltage
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.undervoltage = tmp ? true : false;
  }

  // Member: thermal_warning
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.thermal_warning = tmp ? true : false;
  }

  // Member: thermal_shutdown
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.thermal_shutdown = tmp ? true : false;
  }

  // Member: overcurrent
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.overcurrent = tmp ? true : false;
  }

  // Member: step_loss_a
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.step_loss_a = tmp ? true : false;
  }

  // Member: step_loss_b
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.step_loss_b = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_msgs
get_serialized_size(
  const minirys_msgs::msg::MotorDriverStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: hi_z
  {
    size_t item_size = sizeof(ros_message.hi_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: busy
  {
    size_t item_size = sizeof(ros_message.busy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: direction
  {
    size_t item_size = sizeof(ros_message.direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_stopped
  {
    size_t item_size = sizeof(ros_message.motor_stopped);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_accelerating
  {
    size_t item_size = sizeof(ros_message.motor_accelerating);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_decelerating
  {
    size_t item_size = sizeof(ros_message.motor_decelerating);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_const_speed
  {
    size_t item_size = sizeof(ros_message.motor_const_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: undervoltage
  {
    size_t item_size = sizeof(ros_message.undervoltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: thermal_warning
  {
    size_t item_size = sizeof(ros_message.thermal_warning);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: thermal_shutdown
  {
    size_t item_size = sizeof(ros_message.thermal_shutdown);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: overcurrent
  {
    size_t item_size = sizeof(ros_message.overcurrent);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: step_loss_a
  {
    size_t item_size = sizeof(ros_message.step_loss_a);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: step_loss_b
  {
    size_t item_size = sizeof(ros_message.step_loss_b);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_msgs
max_serialized_size_MotorDriverStatus(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: hi_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: busy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: direction
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: motor_stopped
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: motor_accelerating
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: motor_decelerating
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: motor_const_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: undervoltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: thermal_warning
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: thermal_shutdown
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: overcurrent
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: step_loss_a
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: step_loss_b
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
    using DataType = minirys_msgs::msg::MotorDriverStatus;
    is_plain =
      (
      offsetof(DataType, step_loss_b) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _MotorDriverStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const minirys_msgs::msg::MotorDriverStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MotorDriverStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<minirys_msgs::msg::MotorDriverStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MotorDriverStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const minirys_msgs::msg::MotorDriverStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MotorDriverStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MotorDriverStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MotorDriverStatus__callbacks = {
  "minirys_msgs::msg",
  "MotorDriverStatus",
  _MotorDriverStatus__cdr_serialize,
  _MotorDriverStatus__cdr_deserialize,
  _MotorDriverStatus__get_serialized_size,
  _MotorDriverStatus__max_serialized_size
};

static rosidl_message_type_support_t _MotorDriverStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MotorDriverStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace minirys_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_minirys_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<minirys_msgs::msg::MotorDriverStatus>()
{
  return &minirys_msgs::msg::typesupport_fastrtps_cpp::_MotorDriverStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, minirys_msgs, msg, MotorDriverStatus)() {
  return &minirys_msgs::msg::typesupport_fastrtps_cpp::_MotorDriverStatus__handle;
}

#ifdef __cplusplus
}
#endif
