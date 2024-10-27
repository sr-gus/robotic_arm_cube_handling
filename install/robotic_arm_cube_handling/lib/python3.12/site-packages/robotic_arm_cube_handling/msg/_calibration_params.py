# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CalibrationParams(type):
    """Metaclass of message 'CalibrationParams'."""

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
            module = import_type_support('robotic_arm_cube_handling')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robotic_arm_cube_handling.msg.CalibrationParams')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__calibration_params
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__calibration_params
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__calibration_params
            cls._TYPE_SUPPORT = module.type_support_msg__msg__calibration_params
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__calibration_params

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CalibrationParams(metaclass=Metaclass_CalibrationParams):
    """Message class 'CalibrationParams'."""

    __slots__ = [
        '_lower_h',
        '_upper_h',
        '_lower_s',
        '_upper_s',
        '_lower_v',
        '_upper_v',
        '_canny_threshold1',
        '_canny_threshold2',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'lower_h': 'int32',
        'upper_h': 'int32',
        'lower_s': 'int32',
        'upper_s': 'int32',
        'lower_v': 'int32',
        'upper_v': 'int32',
        'canny_threshold1': 'int32',
        'canny_threshold2': 'int32',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.lower_h = kwargs.get('lower_h', int())
        self.upper_h = kwargs.get('upper_h', int())
        self.lower_s = kwargs.get('lower_s', int())
        self.upper_s = kwargs.get('upper_s', int())
        self.lower_v = kwargs.get('lower_v', int())
        self.upper_v = kwargs.get('upper_v', int())
        self.canny_threshold1 = kwargs.get('canny_threshold1', int())
        self.canny_threshold2 = kwargs.get('canny_threshold2', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
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
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.lower_h != other.lower_h:
            return False
        if self.upper_h != other.upper_h:
            return False
        if self.lower_s != other.lower_s:
            return False
        if self.upper_s != other.upper_s:
            return False
        if self.lower_v != other.lower_v:
            return False
        if self.upper_v != other.upper_v:
            return False
        if self.canny_threshold1 != other.canny_threshold1:
            return False
        if self.canny_threshold2 != other.canny_threshold2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def lower_h(self):
        """Message field 'lower_h'."""
        return self._lower_h

    @lower_h.setter
    def lower_h(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'lower_h' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lower_h' field must be an integer in [-2147483648, 2147483647]"
        self._lower_h = value

    @builtins.property
    def upper_h(self):
        """Message field 'upper_h'."""
        return self._upper_h

    @upper_h.setter
    def upper_h(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'upper_h' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'upper_h' field must be an integer in [-2147483648, 2147483647]"
        self._upper_h = value

    @builtins.property
    def lower_s(self):
        """Message field 'lower_s'."""
        return self._lower_s

    @lower_s.setter
    def lower_s(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'lower_s' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lower_s' field must be an integer in [-2147483648, 2147483647]"
        self._lower_s = value

    @builtins.property
    def upper_s(self):
        """Message field 'upper_s'."""
        return self._upper_s

    @upper_s.setter
    def upper_s(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'upper_s' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'upper_s' field must be an integer in [-2147483648, 2147483647]"
        self._upper_s = value

    @builtins.property
    def lower_v(self):
        """Message field 'lower_v'."""
        return self._lower_v

    @lower_v.setter
    def lower_v(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'lower_v' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lower_v' field must be an integer in [-2147483648, 2147483647]"
        self._lower_v = value

    @builtins.property
    def upper_v(self):
        """Message field 'upper_v'."""
        return self._upper_v

    @upper_v.setter
    def upper_v(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'upper_v' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'upper_v' field must be an integer in [-2147483648, 2147483647]"
        self._upper_v = value

    @builtins.property
    def canny_threshold1(self):
        """Message field 'canny_threshold1'."""
        return self._canny_threshold1

    @canny_threshold1.setter
    def canny_threshold1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'canny_threshold1' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'canny_threshold1' field must be an integer in [-2147483648, 2147483647]"
        self._canny_threshold1 = value

    @builtins.property
    def canny_threshold2(self):
        """Message field 'canny_threshold2'."""
        return self._canny_threshold2

    @canny_threshold2.setter
    def canny_threshold2(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'canny_threshold2' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'canny_threshold2' field must be an integer in [-2147483648, 2147483647]"
        self._canny_threshold2 = value
