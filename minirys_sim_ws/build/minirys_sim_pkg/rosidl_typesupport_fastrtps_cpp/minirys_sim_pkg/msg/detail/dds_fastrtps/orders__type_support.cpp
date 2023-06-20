// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice
#include "minirys_sim_pkg/msg/detail/orders__rosidl_typesupport_fastrtps_cpp.hpp"
#include "minirys_sim_pkg/msg/detail/orders__struct.hpp"

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

namespace minirys_sim_pkg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_sim_pkg
cdr_serialize(
  const minirys_sim_pkg::msg::Orders & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: move
  cdr << ros_message.move;
  // Member: rotate
  cdr << ros_message.rotate;
  // Member: control_flag
  cdr << ros_message.control_flag;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_sim_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  minirys_sim_pkg::msg::Orders & ros_message)
{
  // Member: move
  cdr >> ros_message.move;

  // Member: rotate
  cdr >> ros_message.rotate;

  // Member: control_flag
  cdr >> ros_message.control_flag;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_sim_pkg
get_serialized_size(
  const minirys_sim_pkg::msg::Orders & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: move
  {
    size_t item_size = sizeof(ros_message.move);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rotate
  {
    size_t item_size = sizeof(ros_message.rotate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: control_flag
  {
    size_t item_size = sizeof(ros_message.control_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_minirys_sim_pkg
max_serialized_size_Orders(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: move
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rotate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: control_flag
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _Orders__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const minirys_sim_pkg::msg::Orders *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Orders__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<minirys_sim_pkg::msg::Orders *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Orders__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const minirys_sim_pkg::msg::Orders *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Orders__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Orders(full_bounded, 0);
}

static message_type_support_callbacks_t _Orders__callbacks = {
  "minirys_sim_pkg::msg",
  "Orders",
  _Orders__cdr_serialize,
  _Orders__cdr_deserialize,
  _Orders__get_serialized_size,
  _Orders__max_serialized_size
};

static rosidl_message_type_support_t _Orders__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Orders__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace minirys_sim_pkg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_minirys_sim_pkg
const rosidl_message_type_support_t *
get_message_type_support_handle<minirys_sim_pkg::msg::Orders>()
{
  return &minirys_sim_pkg::msg::typesupport_fastrtps_cpp::_Orders__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, minirys_sim_pkg, msg, Orders)() {
  return &minirys_sim_pkg::msg::typesupport_fastrtps_cpp::_Orders__handle;
}

#ifdef __cplusplus
}
#endif
