// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from minirys_sim:srv/OdomService.idl
// generated code does not contain a copyright notice

#ifndef MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__STRUCT_HPP_
#define MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__minirys_sim__srv__OdomService_Request __attribute__((deprecated))
#else
# define DEPRECATED__minirys_sim__srv__OdomService_Request __declspec(deprecated)
#endif

namespace minirys_sim
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct OdomService_Request_
{
  using Type = OdomService_Request_<ContainerAllocator>;

  explicit OdomService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_namespace = "";
    }
  }

  explicit OdomService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_namespace(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_namespace = "";
    }
  }

  // field types and members
  using _robot_namespace_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_namespace_type robot_namespace;

  // setters for named parameter idiom
  Type & set__robot_namespace(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_namespace = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    minirys_sim::srv::OdomService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const minirys_sim::srv::OdomService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<minirys_sim::srv::OdomService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<minirys_sim::srv::OdomService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      minirys_sim::srv::OdomService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<minirys_sim::srv::OdomService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      minirys_sim::srv::OdomService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<minirys_sim::srv::OdomService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<minirys_sim::srv::OdomService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<minirys_sim::srv::OdomService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__minirys_sim__srv__OdomService_Request
    std::shared_ptr<minirys_sim::srv::OdomService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__minirys_sim__srv__OdomService_Request
    std::shared_ptr<minirys_sim::srv::OdomService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OdomService_Request_ & other) const
  {
    if (this->robot_namespace != other.robot_namespace) {
      return false;
    }
    return true;
  }
  bool operator!=(const OdomService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OdomService_Request_

// alias to use template instance with default allocator
using OdomService_Request =
  minirys_sim::srv::OdomService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace minirys_sim


#ifndef _WIN32
# define DEPRECATED__minirys_sim__srv__OdomService_Response __attribute__((deprecated))
#else
# define DEPRECATED__minirys_sim__srv__OdomService_Response __declspec(deprecated)
#endif

namespace minirys_sim
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct OdomService_Response_
{
  using Type = OdomService_Response_<ContainerAllocator>;

  explicit OdomService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      this->success = false;
    }
  }

  explicit OdomService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      this->success = false;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    minirys_sim::srv::OdomService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const minirys_sim::srv::OdomService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<minirys_sim::srv::OdomService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<minirys_sim::srv::OdomService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      minirys_sim::srv::OdomService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<minirys_sim::srv::OdomService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      minirys_sim::srv::OdomService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<minirys_sim::srv::OdomService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<minirys_sim::srv::OdomService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<minirys_sim::srv::OdomService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__minirys_sim__srv__OdomService_Response
    std::shared_ptr<minirys_sim::srv::OdomService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__minirys_sim__srv__OdomService_Response
    std::shared_ptr<minirys_sim::srv::OdomService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OdomService_Response_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const OdomService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OdomService_Response_

// alias to use template instance with default allocator
using OdomService_Response =
  minirys_sim::srv::OdomService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace minirys_sim

namespace minirys_sim
{

namespace srv
{

struct OdomService
{
  using Request = minirys_sim::srv::OdomService_Request;
  using Response = minirys_sim::srv::OdomService_Response;
};

}  // namespace srv

}  // namespace minirys_sim

#endif  // MINIRYS_SIM__SRV__DETAIL__ODOM_SERVICE__STRUCT_HPP_
