// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from minirys_msgs:msg/MotorDriverStatus.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__STRUCT_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__STRUCT_HPP_

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
# define DEPRECATED__minirys_msgs__msg__MotorDriverStatus __attribute__((deprecated))
#else
# define DEPRECATED__minirys_msgs__msg__MotorDriverStatus __declspec(deprecated)
#endif

namespace minirys_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorDriverStatus_
{
  using Type = MotorDriverStatus_<ContainerAllocator>;

  explicit MotorDriverStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->hi_z = false;
      this->busy = false;
      this->direction = false;
      this->motor_stopped = false;
      this->motor_accelerating = false;
      this->motor_decelerating = false;
      this->motor_const_speed = false;
      this->undervoltage = false;
      this->thermal_warning = false;
      this->thermal_shutdown = false;
      this->overcurrent = false;
      this->step_loss_a = false;
      this->step_loss_b = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->hi_z = false;
      this->busy = false;
      this->direction = false;
      this->motor_stopped = false;
      this->motor_accelerating = false;
      this->motor_decelerating = false;
      this->motor_const_speed = false;
      this->undervoltage = false;
      this->thermal_warning = false;
      this->thermal_shutdown = false;
      this->overcurrent = false;
      this->step_loss_a = false;
      this->step_loss_b = false;
    }
  }

  explicit MotorDriverStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->hi_z = false;
      this->busy = false;
      this->direction = false;
      this->motor_stopped = false;
      this->motor_accelerating = false;
      this->motor_decelerating = false;
      this->motor_const_speed = false;
      this->undervoltage = false;
      this->thermal_warning = false;
      this->thermal_shutdown = false;
      this->overcurrent = false;
      this->step_loss_a = false;
      this->step_loss_b = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->hi_z = false;
      this->busy = false;
      this->direction = false;
      this->motor_stopped = false;
      this->motor_accelerating = false;
      this->motor_decelerating = false;
      this->motor_const_speed = false;
      this->undervoltage = false;
      this->thermal_warning = false;
      this->thermal_shutdown = false;
      this->overcurrent = false;
      this->step_loss_a = false;
      this->step_loss_b = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _hi_z_type =
    bool;
  _hi_z_type hi_z;
  using _busy_type =
    bool;
  _busy_type busy;
  using _direction_type =
    bool;
  _direction_type direction;
  using _motor_stopped_type =
    bool;
  _motor_stopped_type motor_stopped;
  using _motor_accelerating_type =
    bool;
  _motor_accelerating_type motor_accelerating;
  using _motor_decelerating_type =
    bool;
  _motor_decelerating_type motor_decelerating;
  using _motor_const_speed_type =
    bool;
  _motor_const_speed_type motor_const_speed;
  using _undervoltage_type =
    bool;
  _undervoltage_type undervoltage;
  using _thermal_warning_type =
    bool;
  _thermal_warning_type thermal_warning;
  using _thermal_shutdown_type =
    bool;
  _thermal_shutdown_type thermal_shutdown;
  using _overcurrent_type =
    bool;
  _overcurrent_type overcurrent;
  using _step_loss_a_type =
    bool;
  _step_loss_a_type step_loss_a;
  using _step_loss_b_type =
    bool;
  _step_loss_b_type step_loss_b;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__hi_z(
    const bool & _arg)
  {
    this->hi_z = _arg;
    return *this;
  }
  Type & set__busy(
    const bool & _arg)
  {
    this->busy = _arg;
    return *this;
  }
  Type & set__direction(
    const bool & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__motor_stopped(
    const bool & _arg)
  {
    this->motor_stopped = _arg;
    return *this;
  }
  Type & set__motor_accelerating(
    const bool & _arg)
  {
    this->motor_accelerating = _arg;
    return *this;
  }
  Type & set__motor_decelerating(
    const bool & _arg)
  {
    this->motor_decelerating = _arg;
    return *this;
  }
  Type & set__motor_const_speed(
    const bool & _arg)
  {
    this->motor_const_speed = _arg;
    return *this;
  }
  Type & set__undervoltage(
    const bool & _arg)
  {
    this->undervoltage = _arg;
    return *this;
  }
  Type & set__thermal_warning(
    const bool & _arg)
  {
    this->thermal_warning = _arg;
    return *this;
  }
  Type & set__thermal_shutdown(
    const bool & _arg)
  {
    this->thermal_shutdown = _arg;
    return *this;
  }
  Type & set__overcurrent(
    const bool & _arg)
  {
    this->overcurrent = _arg;
    return *this;
  }
  Type & set__step_loss_a(
    const bool & _arg)
  {
    this->step_loss_a = _arg;
    return *this;
  }
  Type & set__step_loss_b(
    const bool & _arg)
  {
    this->step_loss_b = _arg;
    return *this;
  }

  // constant declarations
  static constexpr bool DIRECTION_FWD =
    1;
  static constexpr bool DIRECTION_REV =
    0;

  // pointer types
  using RawPtr =
    minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__minirys_msgs__msg__MotorDriverStatus
    std::shared_ptr<minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__minirys_msgs__msg__MotorDriverStatus
    std::shared_ptr<minirys_msgs::msg::MotorDriverStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorDriverStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->hi_z != other.hi_z) {
      return false;
    }
    if (this->busy != other.busy) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->motor_stopped != other.motor_stopped) {
      return false;
    }
    if (this->motor_accelerating != other.motor_accelerating) {
      return false;
    }
    if (this->motor_decelerating != other.motor_decelerating) {
      return false;
    }
    if (this->motor_const_speed != other.motor_const_speed) {
      return false;
    }
    if (this->undervoltage != other.undervoltage) {
      return false;
    }
    if (this->thermal_warning != other.thermal_warning) {
      return false;
    }
    if (this->thermal_shutdown != other.thermal_shutdown) {
      return false;
    }
    if (this->overcurrent != other.overcurrent) {
      return false;
    }
    if (this->step_loss_a != other.step_loss_a) {
      return false;
    }
    if (this->step_loss_b != other.step_loss_b) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorDriverStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorDriverStatus_

// alias to use template instance with default allocator
using MotorDriverStatus =
  minirys_msgs::msg::MotorDriverStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr bool MotorDriverStatus_<ContainerAllocator>::DIRECTION_FWD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr bool MotorDriverStatus_<ContainerAllocator>::DIRECTION_REV;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace minirys_msgs

#endif  // MINIRYS_MSGS__MSG__DETAIL__MOTOR_DRIVER_STATUS__STRUCT_HPP_
