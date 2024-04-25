// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from minirys_msgs:msg/RTTestResult.idl
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
#include "minirys_msgs/msg/detail/rt_test_result__struct.h"
#include "minirys_msgs/msg/detail/rt_test_result__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool minirys_msgs__msg__rt_test_result__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("minirys_msgs.msg._rt_test_result.RTTestResult", full_classname_dest, 45) == 0);
  }
  minirys_msgs__msg__RTTestResult * ros_message = _ros_message;
  {  // stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "stamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->stamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // current_latency
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_latency");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current_latency = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // mean_latency
    PyObject * field = PyObject_GetAttrString(_pymsg, "mean_latency");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mean_latency = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // min_latency
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_latency");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->min_latency = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // max_latency
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_latency");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_latency = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // minor_pagefaults
    PyObject * field = PyObject_GetAttrString(_pymsg, "minor_pagefaults");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->minor_pagefaults = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // major_pagefaults
    PyObject * field = PyObject_GetAttrString(_pymsg, "major_pagefaults");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->major_pagefaults = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * minirys_msgs__msg__rt_test_result__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RTTestResult */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("minirys_msgs.msg._rt_test_result");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RTTestResult");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  minirys_msgs__msg__RTTestResult * ros_message = (minirys_msgs__msg__RTTestResult *)raw_ros_message;
  {  // stamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->stamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "stamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_latency
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->current_latency);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_latency", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mean_latency
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mean_latency);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mean_latency", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_latency
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->min_latency);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_latency", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_latency
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->max_latency);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_latency", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // minor_pagefaults
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->minor_pagefaults);
    {
      int rc = PyObject_SetAttrString(_pymessage, "minor_pagefaults", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // major_pagefaults
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->major_pagefaults);
    {
      int rc = PyObject_SetAttrString(_pymessage, "major_pagefaults", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
