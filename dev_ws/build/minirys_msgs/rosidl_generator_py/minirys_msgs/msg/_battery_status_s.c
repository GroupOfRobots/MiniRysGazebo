// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from minirys_msgs:msg/BatteryStatus.idl
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
#include "minirys_msgs/msg/detail/battery_status__struct.h"
#include "minirys_msgs/msg/detail/battery_status__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool minirys_msgs__msg__battery_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[47];
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
    assert(strncmp("minirys_msgs.msg._battery_status.BatteryStatus", full_classname_dest, 46) == 0);
  }
  minirys_msgs__msg__BatteryStatus * ros_message = _ros_message;
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
  {  // voltage_cell1
    PyObject * field = PyObject_GetAttrString(_pymsg, "voltage_cell1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->voltage_cell1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // voltage_cell2
    PyObject * field = PyObject_GetAttrString(_pymsg, "voltage_cell2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->voltage_cell2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // voltage_cell3
    PyObject * field = PyObject_GetAttrString(_pymsg, "voltage_cell3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->voltage_cell3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // undervoltage_warning
    PyObject * field = PyObject_GetAttrString(_pymsg, "undervoltage_warning");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->undervoltage_warning = (Py_True == field);
    Py_DECREF(field);
  }
  {  // undervoltage_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "undervoltage_error");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->undervoltage_error = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * minirys_msgs__msg__battery_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BatteryStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("minirys_msgs.msg._battery_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BatteryStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  minirys_msgs__msg__BatteryStatus * ros_message = (minirys_msgs__msg__BatteryStatus *)raw_ros_message;
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
  {  // voltage_cell1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->voltage_cell1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "voltage_cell1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // voltage_cell2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->voltage_cell2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "voltage_cell2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // voltage_cell3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->voltage_cell3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "voltage_cell3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // undervoltage_warning
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->undervoltage_warning ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "undervoltage_warning", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // undervoltage_error
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->undervoltage_error ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "undervoltage_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
