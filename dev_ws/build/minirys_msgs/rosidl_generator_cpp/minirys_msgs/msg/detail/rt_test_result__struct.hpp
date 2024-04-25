// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from minirys_msgs:msg/RTTestResult.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__STRUCT_HPP_
#define MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__minirys_msgs__msg__RTTestResult __attribute__((deprecated))
#else
# define DEPRECATED__minirys_msgs__msg__RTTestResult __declspec(deprecated)
#endif

namespace minirys_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RTTestResult_
{
  using Type = RTTestResult_<ContainerAllocator>;

  explicit RTTestResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_latency = 0ull;
      this->mean_latency = 0.0;
      this->min_latency = 0ull;
      this->max_latency = 0ull;
      this->minor_pagefaults = 0ull;
      this->major_pagefaults = 0ull;
    }
  }

  explicit RTTestResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_latency = 0ull;
      this->mean_latency = 0.0;
      this->min_latency = 0ull;
      this->max_latency = 0ull;
      this->minor_pagefaults = 0ull;
      this->major_pagefaults = 0ull;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _current_latency_type =
    uint64_t;
  _current_latency_type current_latency;
  using _mean_latency_type =
    double;
  _mean_latency_type mean_latency;
  using _min_latency_type =
    uint64_t;
  _min_latency_type min_latency;
  using _max_latency_type =
    uint64_t;
  _max_latency_type max_latency;
  using _minor_pagefaults_type =
    uint64_t;
  _minor_pagefaults_type minor_pagefaults;
  using _major_pagefaults_type =
    uint64_t;
  _major_pagefaults_type major_pagefaults;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__current_latency(
    const uint64_t & _arg)
  {
    this->current_latency = _arg;
    return *this;
  }
  Type & set__mean_latency(
    const double & _arg)
  {
    this->mean_latency = _arg;
    return *this;
  }
  Type & set__min_latency(
    const uint64_t & _arg)
  {
    this->min_latency = _arg;
    return *this;
  }
  Type & set__max_latency(
    const uint64_t & _arg)
  {
    this->max_latency = _arg;
    return *this;
  }
  Type & set__minor_pagefaults(
    const uint64_t & _arg)
  {
    this->minor_pagefaults = _arg;
    return *this;
  }
  Type & set__major_pagefaults(
    const uint64_t & _arg)
  {
    this->major_pagefaults = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    minirys_msgs::msg::RTTestResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const minirys_msgs::msg::RTTestResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<minirys_msgs::msg::RTTestResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<minirys_msgs::msg::RTTestResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      minirys_msgs::msg::RTTestResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<minirys_msgs::msg::RTTestResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      minirys_msgs::msg::RTTestResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<minirys_msgs::msg::RTTestResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<minirys_msgs::msg::RTTestResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<minirys_msgs::msg::RTTestResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__minirys_msgs__msg__RTTestResult
    std::shared_ptr<minirys_msgs::msg::RTTestResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__minirys_msgs__msg__RTTestResult
    std::shared_ptr<minirys_msgs::msg::RTTestResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RTTestResult_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->current_latency != other.current_latency) {
      return false;
    }
    if (this->mean_latency != other.mean_latency) {
      return false;
    }
    if (this->min_latency != other.min_latency) {
      return false;
    }
    if (this->max_latency != other.max_latency) {
      return false;
    }
    if (this->minor_pagefaults != other.minor_pagefaults) {
      return false;
    }
    if (this->major_pagefaults != other.major_pagefaults) {
      return false;
    }
    return true;
  }
  bool operator!=(const RTTestResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RTTestResult_

// alias to use template instance with default allocator
using RTTestResult =
  minirys_msgs::msg::RTTestResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace minirys_msgs

#endif  // MINIRYS_MSGS__MSG__DETAIL__RT_TEST_RESULT__STRUCT_HPP_
