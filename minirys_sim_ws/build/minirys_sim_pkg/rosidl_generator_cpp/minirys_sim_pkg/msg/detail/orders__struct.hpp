// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from minirys_sim_pkg:msg/Orders.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__STRUCT_HPP_
#define MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__minirys_sim_pkg__msg__Orders __attribute__((deprecated))
#else
# define DEPRECATED__minirys_sim_pkg__msg__Orders __declspec(deprecated)
#endif

namespace minirys_sim_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Orders_
{
  using Type = Orders_<ContainerAllocator>;

  explicit Orders_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move = 0.0f;
      this->rotate = 0.0f;
      this->control_flag = 0;
    }
  }

  explicit Orders_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move = 0.0f;
      this->rotate = 0.0f;
      this->control_flag = 0;
    }
  }

  // field types and members
  using _move_type =
    float;
  _move_type move;
  using _rotate_type =
    float;
  _rotate_type rotate;
  using _control_flag_type =
    int8_t;
  _control_flag_type control_flag;

  // setters for named parameter idiom
  Type & set__move(
    const float & _arg)
  {
    this->move = _arg;
    return *this;
  }
  Type & set__rotate(
    const float & _arg)
  {
    this->rotate = _arg;
    return *this;
  }
  Type & set__control_flag(
    const int8_t & _arg)
  {
    this->control_flag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    minirys_sim_pkg::msg::Orders_<ContainerAllocator> *;
  using ConstRawPtr =
    const minirys_sim_pkg::msg::Orders_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<minirys_sim_pkg::msg::Orders_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<minirys_sim_pkg::msg::Orders_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      minirys_sim_pkg::msg::Orders_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<minirys_sim_pkg::msg::Orders_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      minirys_sim_pkg::msg::Orders_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<minirys_sim_pkg::msg::Orders_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<minirys_sim_pkg::msg::Orders_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<minirys_sim_pkg::msg::Orders_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__minirys_sim_pkg__msg__Orders
    std::shared_ptr<minirys_sim_pkg::msg::Orders_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__minirys_sim_pkg__msg__Orders
    std::shared_ptr<minirys_sim_pkg::msg::Orders_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Orders_ & other) const
  {
    if (this->move != other.move) {
      return false;
    }
    if (this->rotate != other.rotate) {
      return false;
    }
    if (this->control_flag != other.control_flag) {
      return false;
    }
    return true;
  }
  bool operator!=(const Orders_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Orders_

// alias to use template instance with default allocator
using Orders =
  minirys_sim_pkg::msg::Orders_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace minirys_sim_pkg

#endif  // MINIRYS_SIM_PKG__MSG__DETAIL__ORDERS__STRUCT_HPP_
