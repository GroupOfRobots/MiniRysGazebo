# generated from rosidl_generator_py/resource/_idl.py.em
# with input from minirys_msgs:msg/MotorDriverStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MotorDriverStatus(type):
    """Metaclass of message 'MotorDriverStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'DIRECTION_FWD': True,
        'DIRECTION_REV': False,
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
                'minirys_msgs.msg.MotorDriverStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor_driver_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor_driver_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor_driver_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor_driver_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor_driver_status

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'DIRECTION_FWD': cls.__constants['DIRECTION_FWD'],
            'DIRECTION_REV': cls.__constants['DIRECTION_REV'],
            'HI_Z__DEFAULT': False,
            'BUSY__DEFAULT': False,
            'DIRECTION__DEFAULT': False,
            'MOTOR_STOPPED__DEFAULT': False,
            'MOTOR_ACCELERATING__DEFAULT': False,
            'MOTOR_DECELERATING__DEFAULT': False,
            'MOTOR_CONST_SPEED__DEFAULT': False,
            'UNDERVOLTAGE__DEFAULT': False,
            'THERMAL_WARNING__DEFAULT': False,
            'THERMAL_SHUTDOWN__DEFAULT': False,
            'OVERCURRENT__DEFAULT': False,
            'STEP_LOSS_A__DEFAULT': False,
            'STEP_LOSS_B__DEFAULT': False,
        }

    @property
    def DIRECTION_FWD(self):
        """Message constant 'DIRECTION_FWD'."""
        return Metaclass_MotorDriverStatus.__constants['DIRECTION_FWD']

    @property
    def DIRECTION_REV(self):
        """Message constant 'DIRECTION_REV'."""
        return Metaclass_MotorDriverStatus.__constants['DIRECTION_REV']

    @property
    def HI_Z__DEFAULT(cls):
        """Return default value for message field 'hi_z'."""
        return False

    @property
    def BUSY__DEFAULT(cls):
        """Return default value for message field 'busy'."""
        return False

    @property
    def DIRECTION__DEFAULT(cls):
        """Return default value for message field 'direction'."""
        return False

    @property
    def MOTOR_STOPPED__DEFAULT(cls):
        """Return default value for message field 'motor_stopped'."""
        return False

    @property
    def MOTOR_ACCELERATING__DEFAULT(cls):
        """Return default value for message field 'motor_accelerating'."""
        return False

    @property
    def MOTOR_DECELERATING__DEFAULT(cls):
        """Return default value for message field 'motor_decelerating'."""
        return False

    @property
    def MOTOR_CONST_SPEED__DEFAULT(cls):
        """Return default value for message field 'motor_const_speed'."""
        return False

    @property
    def UNDERVOLTAGE__DEFAULT(cls):
        """Return default value for message field 'undervoltage'."""
        return False

    @property
    def THERMAL_WARNING__DEFAULT(cls):
        """Return default value for message field 'thermal_warning'."""
        return False

    @property
    def THERMAL_SHUTDOWN__DEFAULT(cls):
        """Return default value for message field 'thermal_shutdown'."""
        return False

    @property
    def OVERCURRENT__DEFAULT(cls):
        """Return default value for message field 'overcurrent'."""
        return False

    @property
    def STEP_LOSS_A__DEFAULT(cls):
        """Return default value for message field 'step_loss_a'."""
        return False

    @property
    def STEP_LOSS_B__DEFAULT(cls):
        """Return default value for message field 'step_loss_b'."""
        return False


class MotorDriverStatus(metaclass=Metaclass_MotorDriverStatus):
    """
    Message class 'MotorDriverStatus'.

    Constants:
      DIRECTION_FWD
      DIRECTION_REV
    """

    __slots__ = [
        '_header',
        '_hi_z',
        '_busy',
        '_direction',
        '_motor_stopped',
        '_motor_accelerating',
        '_motor_decelerating',
        '_motor_const_speed',
        '_undervoltage',
        '_thermal_warning',
        '_thermal_shutdown',
        '_overcurrent',
        '_step_loss_a',
        '_step_loss_b',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'hi_z': 'boolean',
        'busy': 'boolean',
        'direction': 'boolean',
        'motor_stopped': 'boolean',
        'motor_accelerating': 'boolean',
        'motor_decelerating': 'boolean',
        'motor_const_speed': 'boolean',
        'undervoltage': 'boolean',
        'thermal_warning': 'boolean',
        'thermal_shutdown': 'boolean',
        'overcurrent': 'boolean',
        'step_loss_a': 'boolean',
        'step_loss_b': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.hi_z = kwargs.get(
            'hi_z', MotorDriverStatus.HI_Z__DEFAULT)
        self.busy = kwargs.get(
            'busy', MotorDriverStatus.BUSY__DEFAULT)
        self.direction = kwargs.get(
            'direction', MotorDriverStatus.DIRECTION__DEFAULT)
        self.motor_stopped = kwargs.get(
            'motor_stopped', MotorDriverStatus.MOTOR_STOPPED__DEFAULT)
        self.motor_accelerating = kwargs.get(
            'motor_accelerating', MotorDriverStatus.MOTOR_ACCELERATING__DEFAULT)
        self.motor_decelerating = kwargs.get(
            'motor_decelerating', MotorDriverStatus.MOTOR_DECELERATING__DEFAULT)
        self.motor_const_speed = kwargs.get(
            'motor_const_speed', MotorDriverStatus.MOTOR_CONST_SPEED__DEFAULT)
        self.undervoltage = kwargs.get(
            'undervoltage', MotorDriverStatus.UNDERVOLTAGE__DEFAULT)
        self.thermal_warning = kwargs.get(
            'thermal_warning', MotorDriverStatus.THERMAL_WARNING__DEFAULT)
        self.thermal_shutdown = kwargs.get(
            'thermal_shutdown', MotorDriverStatus.THERMAL_SHUTDOWN__DEFAULT)
        self.overcurrent = kwargs.get(
            'overcurrent', MotorDriverStatus.OVERCURRENT__DEFAULT)
        self.step_loss_a = kwargs.get(
            'step_loss_a', MotorDriverStatus.STEP_LOSS_A__DEFAULT)
        self.step_loss_b = kwargs.get(
            'step_loss_b', MotorDriverStatus.STEP_LOSS_B__DEFAULT)

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
        if self.hi_z != other.hi_z:
            return False
        if self.busy != other.busy:
            return False
        if self.direction != other.direction:
            return False
        if self.motor_stopped != other.motor_stopped:
            return False
        if self.motor_accelerating != other.motor_accelerating:
            return False
        if self.motor_decelerating != other.motor_decelerating:
            return False
        if self.motor_const_speed != other.motor_const_speed:
            return False
        if self.undervoltage != other.undervoltage:
            return False
        if self.thermal_warning != other.thermal_warning:
            return False
        if self.thermal_shutdown != other.thermal_shutdown:
            return False
        if self.overcurrent != other.overcurrent:
            return False
        if self.step_loss_a != other.step_loss_a:
            return False
        if self.step_loss_b != other.step_loss_b:
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
    def hi_z(self):
        """Message field 'hi_z'."""
        return self._hi_z

    @hi_z.setter
    def hi_z(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hi_z' field must be of type 'bool'"
        self._hi_z = value

    @builtins.property
    def busy(self):
        """Message field 'busy'."""
        return self._busy

    @busy.setter
    def busy(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'busy' field must be of type 'bool'"
        self._busy = value

    @builtins.property
    def direction(self):
        """Message field 'direction'."""
        return self._direction

    @direction.setter
    def direction(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'direction' field must be of type 'bool'"
        self._direction = value

    @builtins.property
    def motor_stopped(self):
        """Message field 'motor_stopped'."""
        return self._motor_stopped

    @motor_stopped.setter
    def motor_stopped(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'motor_stopped' field must be of type 'bool'"
        self._motor_stopped = value

    @builtins.property
    def motor_accelerating(self):
        """Message field 'motor_accelerating'."""
        return self._motor_accelerating

    @motor_accelerating.setter
    def motor_accelerating(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'motor_accelerating' field must be of type 'bool'"
        self._motor_accelerating = value

    @builtins.property
    def motor_decelerating(self):
        """Message field 'motor_decelerating'."""
        return self._motor_decelerating

    @motor_decelerating.setter
    def motor_decelerating(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'motor_decelerating' field must be of type 'bool'"
        self._motor_decelerating = value

    @builtins.property
    def motor_const_speed(self):
        """Message field 'motor_const_speed'."""
        return self._motor_const_speed

    @motor_const_speed.setter
    def motor_const_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'motor_const_speed' field must be of type 'bool'"
        self._motor_const_speed = value

    @builtins.property
    def undervoltage(self):
        """Message field 'undervoltage'."""
        return self._undervoltage

    @undervoltage.setter
    def undervoltage(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'undervoltage' field must be of type 'bool'"
        self._undervoltage = value

    @builtins.property
    def thermal_warning(self):
        """Message field 'thermal_warning'."""
        return self._thermal_warning

    @thermal_warning.setter
    def thermal_warning(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'thermal_warning' field must be of type 'bool'"
        self._thermal_warning = value

    @builtins.property
    def thermal_shutdown(self):
        """Message field 'thermal_shutdown'."""
        return self._thermal_shutdown

    @thermal_shutdown.setter
    def thermal_shutdown(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'thermal_shutdown' field must be of type 'bool'"
        self._thermal_shutdown = value

    @builtins.property
    def overcurrent(self):
        """Message field 'overcurrent'."""
        return self._overcurrent

    @overcurrent.setter
    def overcurrent(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'overcurrent' field must be of type 'bool'"
        self._overcurrent = value

    @builtins.property
    def step_loss_a(self):
        """Message field 'step_loss_a'."""
        return self._step_loss_a

    @step_loss_a.setter
    def step_loss_a(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'step_loss_a' field must be of type 'bool'"
        self._step_loss_a = value

    @builtins.property
    def step_loss_b(self):
        """Message field 'step_loss_b'."""
        return self._step_loss_b

    @step_loss_b.setter
    def step_loss_b(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'step_loss_b' field must be of type 'bool'"
        self._step_loss_b = value
