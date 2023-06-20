// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from minirys_sim_pkg:msg/Orders.idl
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
#include "minirys_sim_pkg/msg/detail/orders__struct.h"
#include "minirys_sim_pkg/msg/detail/orders__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool minirys_sim_pkg__msg__orders__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[35];
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
    assert(strncmp("minirys_sim_pkg.msg._orders.Orders", full_classname_dest, 34) == 0);
  }
  minirys_sim_pkg__msg__Orders * ros_message = _ros_message;
  {  // move
    PyObject * field = PyObject_GetAttrString(_pymsg, "move");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->move = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rotate
    PyObject * field = PyObject_GetAttrString(_pymsg, "rotate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rotate = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // control_flag
    PyObject * field = PyObject_GetAttrString(_pymsg, "control_flag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->control_flag = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * minirys_sim_pkg__msg__orders__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Orders */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("minirys_sim_pkg.msg._orders");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Orders");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  minirys_sim_pkg__msg__Orders * ros_message = (minirys_sim_pkg__msg__Orders *)raw_ros_message;
  {  // move
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->move);
    {
      int rc = PyObject_SetAttrString(_pymessage, "move", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rotate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rotate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rotate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // control_flag
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->control_flag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "control_flag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
