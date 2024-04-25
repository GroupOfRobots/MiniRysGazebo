// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from minirys_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__minirys_msgs__msg__BatteryStatus __attribute__((deprecated))
#else
# define DEPRECATED__minirys_msgs__msg__BatteryStatus __declspec(deprecated)
#endif

namespace minirys_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BatteryStatus_
{
  using Type = BatteryStatus_<ContainerAllocator>;

  explicit BatteryStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->voltage_cell1 = 0.0f;
      this->voltage_cell2 = 0.0f;
      this->voltage_cell3 = 0.0f;
      this->undervoltage_warning = false;
      this->undervoltage_error = false;
    }
  }

  explicit BatteryStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->voltage_cell1 = 0.0f;
      this->voltage_cell2 = 0.0f;
      this->voltage_cell3 = 0.0f;
      this->undervoltage_warning = false;
      this->undervoltage_error = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _voltage_cell1_type =
    float;
  _voltage_cell1_type voltage_cell1;
  using _voltage_cell2_type =
    float;
  _voltage_cell2_type voltage_cell2;
  using _voltage_cell3_type =
    float;
  _voltage_cell3_type voltage_cell3;
  using _undervoltage_warning_type =
    bool;
  _undervoltage_warning_type undervoltage_warning;
  using _undervoltage_error_type =
    bool;
  _undervoltage_error_type undervoltage_error;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__voltage_cell1(
    const float & _arg)
  {
    this->voltage_cell1 = _arg;
    return *this;
  }
  Type & set__voltage_cell2(
    const float & _arg)
  {
    this->voltage_cell2 = _arg;
    return *this;
  }
  Type & set__voltage_cell3(
    const float & _arg)
  {
    this->voltage_cell3 = _arg;
    return *this;
  }
  Type & set__undervoltage_warning(
    const bool & _arg)
  {
    this->undervoltage_warning = _arg;
    return *this;
  }
  Type & set__undervoltage_error(
    const bool & _arg)
  {
    this->undervoltage_error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    minirys_msgs::msg::BatteryStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const minirys_msgs::msg::BatteryStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<minirys_msgs::msg::BatteryStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<minirys_msgs::msg::BatteryStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      minirys_msgs::msg::BatteryStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<minirys_msgs::msg::BatteryStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      minirys_msgs::msg::BatteryStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<minirys_msgs::msg::BatteryStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<minirys_msgs::msg::BatteryStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<minirys_msgs::msg::BatteryStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__minirys_msgs__msg__BatteryStatus
    std::shared_ptr<minirys_msgs::msg::BatteryStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__minirys_msgs__msg__BatteryStatus
    std::shared_ptr<minirys_msgs::msg::BatteryStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BatteryStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->voltage_cell1 != other.voltage_cell1) {
      return false;
    }
    if (this->voltage_cell2 != other.voltage_cell2) {
      return false;
    }
    if (this->voltage_cell3 != other.voltage_cell3) {
      return false;
    }
    if (this->undervoltage_warning != other.undervoltage_warning) {
      return false;
    }
    if (this->undervoltage_error != other.undervoltage_error) {
      return false;
    }
    return true;
  }
  bool operator!=(const BatteryStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BatteryStatus_

// alias to use template instance with default allocator
using BatteryStatus =
  minirys_msgs::msg::BatteryStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace minirys_msgs

#endif  // MINIRYS_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_HPP_
