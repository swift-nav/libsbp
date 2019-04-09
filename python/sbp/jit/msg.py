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

from pybase64 import standard_b64encode

import numpy as np
import numba as nb

import numba.cffi_support

from sbp.msg import crc16jit
from sbp.msg import SENDER_ID as _SENDER_ID
from sbp.msg import SBP_PREAMBLE as _SBP_PREAMBLE

from sbp.jit import parse_float_c


numba.cffi_support.register_module(parse_float_c)

_get_f32 = parse_float_c.lib.get_f32
_get_f64 = parse_float_c.lib.get_f64

SENDER_ID = _SENDER_ID
SBP_PREAMBLE = _SBP_PREAMBLE


@nb.jit('Tuple((u1,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_u8(buf, offset, length):
    if length < 1:
        return (0, offset, length)
    return buf[offset], offset + 1, length - 1


@nb.jit('Tuple((u2,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_u16(buf, offset, length):
    if length < 2:
        return (0, offset, length)
    msb = nb.u2(buf[offset + 1]) << 8
    lsb = nb.u2(buf[offset + 0]) << 0
    return msb | lsb, offset + 2, length - 2


@nb.jit('Tuple((u4,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_u32(buf, offset, length):
    if length < 4:
        return (0, offset, length)
    a = nb.u4(buf[offset + 3]) << 24
    b = nb.u4(buf[offset + 2]) << 16
    c = nb.u4(buf[offset + 1]) << 8
    d = nb.u4(buf[offset + 0]) << 0
    return a | b | c | d, offset + 4, length - 4


@nb.jit('Tuple((u8,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_u64(buf, offset, length):
    if length < 8:
        return (0, offset, length)
    a = nb.u8(buf[offset + 7]) << 54
    b = nb.u8(buf[offset + 6]) << 48
    c = nb.u8(buf[offset + 5]) << 40
    d = nb.u8(buf[offset + 4]) << 32
    e = nb.u8(buf[offset + 3]) << 24
    f = nb.u8(buf[offset + 2]) << 16
    g = nb.u8(buf[offset + 1]) << 8
    h = nb.u8(buf[offset + 0]) << 0
    return a | b | c | d | e | f | g | h, offset + 8, length - 8


@nb.jit('Tuple((i1,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_s8(buf, offset, length):
    if length < 1:
        return (0, offset, length)
    return buf[offset], offset + 1, length - 1


@nb.jit('Tuple((i2,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_s16(buf, offset, length):
    if length < 2:
        return (0, offset, length)
    msb = nb.i2(buf[offset + 1]) << 8
    lsb = nb.i2(buf[offset + 0]) << 0
    return msb | lsb, offset + 2, length - 2


@nb.jit('Tuple((i4,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_s32(buf, offset, length):
    if length < 4:
        return (0, offset, length)
    a = nb.i4(buf[offset + 3]) << 24
    b = nb.i4(buf[offset + 2]) << 16
    c = nb.i4(buf[offset + 1]) << 8
    d = nb.i4(buf[offset + 0]) << 0
    return a | b | c | d, offset + 4, length - 4


@nb.jit('Tuple((i8,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_s64(buf, offset, length):
    if length < 8:
        return (0, offset, length)
    a = nb.i8(buf[offset + 7]) << 54
    b = nb.i8(buf[offset + 6]) << 48
    c = nb.i8(buf[offset + 5]) << 40
    d = nb.i8(buf[offset + 4]) << 32
    e = nb.i8(buf[offset + 3]) << 24
    f = nb.i8(buf[offset + 2]) << 16
    g = nb.i8(buf[offset + 1]) << 8
    h = nb.i8(buf[offset + 0]) << 0
    return a | b | c | d | e | f | g | h, offset + 8, length - 8


@nb.jit('Tuple((f4,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_f32(buf, offset, length):
    if length < 4:
        return (0, offset, length)
    res = _get_f32(buf[offset + 0],
                   buf[offset + 1],
                   buf[offset + 2],
                   buf[offset + 3])
    return res, offset + 4, length - 4


@nb.jit('Tuple((f8,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
def get_f64(buf, offset, length):
    if length < 8:
        return (0, offset, length)
    res = _get_f64(buf[offset + 0],
                   buf[offset + 1],
                   buf[offset + 2],
                   buf[offset + 3],
                   buf[offset + 4],
                   buf[offset + 5],
                   buf[offset + 6],
                   buf[offset + 7])
    return res, offset + 8, length - 8


@nb.jit('Tuple((u1[:],u4,u4))(u1[:],u4,u4,b1)', nopython=True, nogil=True)
def _get_string(buf_in, offset, length, check_null):
    buf_out = np.zeros(256, dtype=np.uint8)
    i = nb.u4(0)
    null_term = False
    while i < length:
        if check_null and buf_in[offset + i] == 0:
            null_term = True
            break
        buf_out[i] = buf_in[offset + i]
        i = nb.u4(i + nb.u4(1))
    if null_term:
        return buf_out[:i], offset + i + 1, i + 1
    else:
        return buf_out[:i], offset + i, i


def get_string(buf, offset, length):
    buf, offset, length = _get_string(buf, offset, length, True)
    return buf.tobytes(), offset, length


def get_fixed_string(size):
    def func(buf, offset_in, length):
        if length < size:
            return '', offset_in, length
        buf, offset, length = _get_string(buf, offset_in, size, False)
        return buf.tobytes(), offset_in + size, length
    return func


def get_setting(buf, offset, length):
    buf, offset, length = _get_string(buf, offset, length, False)
    return buf.tobytes(), offset, length


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
            arr.append(nb_type(res) if nb_type else res)
            total_size -= el_size
        return arr, offset, length
    return func


class SBP(object):
    """Swift Binary Protocol container.  """

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

    @staticmethod
    @nb.jit('Tuple((u4, u2, u2, u2, u2, b1))(u1[:], u4, u4)',
            nopython=True, nogil=True)
    def unpack_payload(buf, offset, length):
        crc_fail = False
        crc = 0
        payload_len = 0
        msg_type = 0
        sender = 0
        offset_start = offset
        pkt_len = 0

        preamble_len = 1
        if length < preamble_len:
            return (pkt_len, payload_len, msg_type, sender, crc, crc_fail)

        preamble, offset, length = get_u8(buf, offset, length)
        if preamble != SBP_PREAMBLE:
            return (preamble_len, payload_len, msg_type, sender, crc, crc_fail)

        header_len = 5
        if length < header_len:
            return (pkt_len, payload_len, msg_type, sender, crc, crc_fail)

        typ, offset, length = get_u16(buf, offset, length)
        sender, offset, length = get_u16(buf, offset, length)
        payload_len, offset, length = get_u8(buf, offset, length)

        if length < payload_len:
            return (pkt_len, payload_len, msg_type, sender, crc, crc_fail)

        # Consume payload
        offset += payload_len
        length -= payload_len

        crc_len = 2
        if length < crc_len:
            return (pkt_len, payload_len, msg_type, sender, crc, crc_fail)

        msg_type = typ

        crc, offset, length = get_u16(buf, offset, length)
        buf_start = offset_start + 1
        buf_end = offset_start + 1 + (preamble_len + header_len - 1) + payload_len

        calc_crc = crc16jit(buf, buf_start, 0, buf_end - buf_start)
        if calc_crc != crc:
            crc_fail = True

        pkt_len = preamble_len + header_len + payload_len + crc_len
        return (pkt_len, payload_len, msg_type, sender, crc, crc_fail)

    @classmethod
    def parse_members(cls, buf, offset, length):
        raise NotImplementedError()

    def _unpack_members(self, buf, offset, length):
        raise NotImplementedError(self.msg_type)

    def unpack(self, payload, offset, length):
        # res, offset, length = {}, offset+length, 0
        res, offset, length = self._unpack_members(payload, offset, length)

        if not res:
            return res, offset, length

        res['preamble'] = self.preamble
        res['msg_type'] = self.msg_type
        res['sender'] = self.sender
        if self.payload is not None:
            res['payload'] = standard_b64encode(self.payload.tobytes()).decode('ascii')
        res['crc'] = self.crc
        res['length'] = self.length
        return res, offset, length
