# generated from rosidl_generator_py/resource/_idl.py.em
# with input from minirys_msgs:msg/BatteryStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BatteryStatus(type):
    """Metaclass of message 'BatteryStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('minirys_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'minirys_msgs.msg.BatteryStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__battery_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__battery_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__battery_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__battery_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__battery_status

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BatteryStatus(metaclass=Metaclass_BatteryStatus):
    """Message class 'BatteryStatus'."""

    __slots__ = [
        '_header',
        '_voltage_cell1',
        '_voltage_cell2',
        '_voltage_cell3',
        '_undervoltage_warning',
        '_undervoltage_error',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'voltage_cell1': 'float',
        'voltage_cell2': 'float',
        'voltage_cell3': 'float',
        'undervoltage_warning': 'boolean',
        'undervoltage_error': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.voltage_cell1 = kwargs.get('voltage_cell1', float())
        self.voltage_cell2 = kwargs.get('voltage_cell2', float())
        self.voltage_cell3 = kwargs.get('voltage_cell3', float())
        self.undervoltage_warning = kwargs.get('undervoltage_warning', bool())
        self.undervoltage_error = kwargs.get('undervoltage_error', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.voltage_cell1 != other.voltage_cell1:
            return False
        if self.voltage_cell2 != other.voltage_cell2:
            return False
        if self.voltage_cell3 != other.voltage_cell3:
            return False
        if self.undervoltage_warning != other.undervoltage_warning:
            return False
        if self.undervoltage_error != other.undervoltage_error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def voltage_cell1(self):
        """Message field 'voltage_cell1'."""
        return self._voltage_cell1

    @voltage_cell1.setter
    def voltage_cell1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'voltage_cell1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'voltage_cell1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._voltage_cell1 = value

    @builtins.property
    def voltage_cell2(self):
        """Message field 'voltage_cell2'."""
        return self._voltage_cell2

    @voltage_cell2.setter
    def voltage_cell2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'voltage_cell2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'voltage_cell2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._voltage_cell2 = value

    @builtins.property
    def voltage_cell3(self):
        """Message field 'voltage_cell3'."""
        return self._voltage_cell3

    @voltage_cell3.setter
    def voltage_cell3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'voltage_cell3' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'voltage_cell3' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._voltage_cell3 = value

    @builtins.property
    def undervoltage_warning(self):
        """Message field 'undervoltage_warning'."""
        return self._undervoltage_warning

    @undervoltage_warning.setter
    def undervoltage_warning(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'undervoltage_warning' field must be of type 'bool'"
        self._undervoltage_warning = value

    @builtins.property
    def undervoltage_error(self):
        """Message field 'undervoltage_error'."""
        return self._undervoltage_error

    @undervoltage_error.setter
    def undervoltage_error(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'undervoltage_error' field must be of type 'bool'"
        self._undervoltage_error = value
