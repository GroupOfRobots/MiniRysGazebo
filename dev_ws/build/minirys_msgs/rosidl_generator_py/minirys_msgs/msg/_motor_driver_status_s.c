// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from minirys_msgs:msg/MotorDriverStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "minirys_msgs/msg/detail/motor_driver_status__struct.h"
#include "minirys_msgs/msg/detail/motor_driver_status__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool minirys_msgs__msg__motor_driver_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("minirys_msgs.msg._motor_driver_status.MotorDriverStatus", full_classname_dest, 55) == 0);
  }
  minirys_msgs__msg__MotorDriverStatus * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // hi_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "hi_z");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hi_z = (Py_True == field);
    Py_DECREF(field);
  }
  {  // busy
    PyObject * field = PyObject_GetAttrString(_pymsg, "busy");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->busy = (Py_True == field);
    Py_DECREF(field);
  }
  {  // direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "direction");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->direction = (Py_True == field);
    Py_DECREF(field);
  }
  {  // motor_stopped
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_stopped");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->motor_stopped = (Py_True == field);
    Py_DECREF(field);
  }
  {  // motor_accelerating
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_accelerating");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->motor_accelerating = (Py_True == field);
    Py_DECREF(field);
  }
  {  // motor_decelerating
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_decelerating");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->motor_decelerating = (Py_True == field);
    Py_DECREF(field);
  }
  {  // motor_const_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_const_speed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->motor_const_speed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // undervoltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "undervoltage");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->undervoltage = (Py_True == field);
    Py_DECREF(field);
  }
  {  // thermal_warning
    PyObject * field = PyObject_GetAttrString(_pymsg, "thermal_warning");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->thermal_warning = (Py_True == field);
    Py_DECREF(field);
  }
  {  // thermal_shutdown
    PyObject * field = PyObject_GetAttrString(_pymsg, "thermal_shutdown");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->thermal_shutdown = (Py_True == field);
    Py_DECREF(field);
  }
  {  // overcurrent
    PyObject * field = PyObject_GetAttrString(_pymsg, "overcurrent");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->overcurrent = (Py_True == field);
    Py_DECREF(field);
  }
  {  // step_loss_a
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_loss_a");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->step_loss_a = (Py_True == field);
    Py_DECREF(field);
  }
  {  // step_loss_b
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_loss_b");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->step_loss_b = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * minirys_msgs__msg__motor_driver_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MotorDriverStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("minirys_msgs.msg._motor_driver_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MotorDriverStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  minirys_msgs__msg__MotorDriverStatus * ros_message = (minirys_msgs__msg__MotorDriverStatus *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hi_z
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hi_z ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hi_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // busy
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->busy ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "busy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // direction
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->direction ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor_stopped
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->motor_stopped ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_stopped", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor_accelerating
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->motor_accelerating ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_accelerating", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor_decelerating
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->motor_decelerating ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_decelerating", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor_const_speed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->motor_const_speed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_const_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // undervoltage
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->undervoltage ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "undervoltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // thermal_warning
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->thermal_warning ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "thermal_warning", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // thermal_shutdown
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->thermal_shutdown ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "thermal_shutdown", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // overcurrent
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->overcurrent ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "overcurrent", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_loss_a
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->step_loss_a ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_loss_a", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_loss_b
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->step_loss_b ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_loss_b", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
