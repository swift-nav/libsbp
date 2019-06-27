#!/usr/bin/env python

# Copyright (C) 2019 Swift Navigation Inc.
# Contact: Swift Navigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import importlib

from pybase64 import standard_b64encode

import decimal as dec

import numpy as np
import ctypes as ct

from sbp.constants import SENDER_ID as _SENDER_ID
from sbp.constants import SBP_PREAMBLE as _SBP_PREAMBLE

from pkgutil import iter_modules

import sys

parse_jit_name = "parse_jit_py{}".format(str(sys.version_info[0]) + str(sys.version_info[1]))

if parse_jit_name in (name for loader, name, ispkg in iter_modules()):
    # found in sys.path
    parse_jit = importlib.import_module(parse_jit_name)
elif parse_jit_name in (name for loader, name, ispkg in iter_modules(['sbp/jit'])):
    # found in sbp.jit
    parse_jit = importlib.import_module('sbp.jit.' + parse_jit_name)
else:
    # not found -> compile
    from sbp.jit import parse
    parse.compile()
    parse_jit = importlib.import_module('sbp.jit.' + parse_jit_name)

get_u8 = parse_jit.get_u8
get_u16 = parse_jit.get_u16
get_u32 = parse_jit.get_u32
get_u64 = parse_jit.get_u64
get_s8 = parse_jit.get_s8
get_s16 = parse_jit.get_s16
get_s32 = parse_jit.get_s32
get_s64 = parse_jit.get_s64
get_f32 = lambda buf, offset, length: (float(np.frombuffer(buf, dtype=np.float32, count=1, offset=offset)), offset + 4, length - 4)
get_f64 = lambda buf, offset, length: (float(np.frombuffer(buf, dtype=np.float64, count=1, offset=offset)), offset + 8, length - 8)
_get_string = parse_jit._get_string
unpack_payload = parse_jit.unpack_payload

SENDER_ID = _SENDER_ID
SBP_PREAMBLE = _SBP_PREAMBLE


def judicious_round(f):
    # Let numpy's judicious rounding tell us the amount of digits we
    # want as it seems to align with Haskell's output
    d = dec.Decimal(np.format_float_positional(f, precision=None, unique=True, trim='0'))
    # Round it using correct rounding strategy and return it as native float
    # NOTE: Can't this be done already on libsbp side?
    return float(round(dec.Decimal(float(f)), abs(d.as_tuple().exponent)))


def get_string(buf, offset, length):
    buf, offset, length = _get_string(buf, offset, length, True)
    return buf.tobytes().decode('ascii'), offset, length


def get_fixed_string(size):
    def func(buf, offset_in, length):
        if length < size:
            return '', offset_in, length
        buf, offset, length = _get_string(buf, offset_in, size, False)
        return buf.tobytes().decode('ascii'), offset_in + size, length
    return func


def get_setting(buf, offset, length):
    buf, offset, length = _get_string(buf, offset, length, False)
    return buf.tobytes().decode('ascii'), offset, length


def get_array(getter):
    def func(buf, offset, length):
        # TODO verify this function
        arr = []
        while length > 0:
            o_1, (res, offset, length) = offset, getter(buf, offset, length)
            if o_1 == offset:
                return arr, offset, length
            arr.append(res)
        return arr, offset, length
    return func


def get_fixed_array(getter, count, el_size, nb_type=None):
    def func(buf, offset, length):
        offset_start = offset
        total_size = count * el_size
        if length < total_size:
            return [], offset_start, length
        arr = []
        while total_size > 0:
            o_1, (res, offset, length) = offset, getter(buf, offset, length)
            if o_1 == offset:
                return [], offset_start, length
            arr.append(judicious_round(nb_type(res)) if nb_type else res)
            total_size -= el_size
        return arr, offset, length
    return func


class SBP(object):
    """Swift Binary Protocol container.  """

    # Class variable for controlling the rounding.
    # False: Only Python native float context will be used, this is faster
    #        but does not distuingish 32 and 64 bit floats. In practise this
    #        means that 32 bit float value reprentations will have higher
    #        precision than they actually have.
    # True:  Floating point values are handled internally as numpy.float32 and
    #        numpy.float64. This is slower but doesn't add arbitrary precision
    #        to the 32 bit values. In practise only 32 bit values are rounded
    #        as the effect of rounding 64 bit values is lost immediately when
    #        stored back to Python native float.
    judicious_rounding = False

    __slots__ = ['preamble',
                 'msg_type',
                 'sender',
                 'length',
                 'payload',
                 'crc']

    def __init__(self,
                 msg_type=None,
                 sender=SENDER_ID,
                 length=None,
                 payload=None,
                 crc=None):
        self.preamble = SBP_PREAMBLE
        self.msg_type = msg_type
        self.sender = sender
        self.length = length
        self.payload = payload
        self.crc = crc

    def __eq__(self, other):
        try:
            if self is other:
                return True
            elif not isinstance(self, type(other)):
                return False
            elif self.__slots__ != other.__slots__:
                return False
            else:
                return all(getattr(self, s) == getattr(other, s)
                           for s in self.__slots__)
        except AttributeError:
            return False

    @classmethod
    def parse_members(cls, buf, offset, length):
        raise NotImplementedError()

    def _unpack_members(self, buf, offset, length):
        raise NotImplementedError(self.msg_type)

    def unpack(self, payload, offset, length):
        res, offset, length = self._unpack_members(payload, offset, length)

        res['preamble'] = self.preamble
        res['msg_type'] = self.msg_type
        res['sender'] = self.sender
        if self.payload is not None:
            res['payload'] = standard_b64encode(self.payload.tobytes()).decode('ascii')
        res['crc'] = self.crc
        res['length'] = self.length
        return res, offset, length
