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

import glob
import ntpath
import os
import shutil
import importlib
import time

import numpy as np
import numba as nb

from numba.pycc import CC

from sbp.constants import SENDER_ID as _SENDER_ID
from sbp.constants import SBP_PREAMBLE as _SBP_PREAMBLE
from sbp.constants import crc16_tab

from distutils.ccompiler import CCompiler
from numpy.distutils.misc_util import get_num_build_jobs
from numpy.distutils.ccompiler import _global_lock, _processing_files
from numpy.distutils import log

import sys
import types

# monkeypatch numpy.distutils.ccompiler. Parallel build hangs with py27
def replace_method(klass, method_name, func):
    if sys.version_info[0] < 3:
        m = types.MethodType(func, None, klass)
        setattr(klass, method_name, m)

# Original https://github.com/numpy/numpy/blob/v1.16.2/numpy/distutils/ccompiler.py#L223
def CCompiler_compile(self, sources, output_dir=None, macros=None,
                      include_dirs=None, debug=0, extra_preargs=None,
                      extra_postargs=None, depends=None):
    global _job_semaphore

    if not sources:
        return []

    ccomp = self.compiler_so
    display = "C compiler: %s\n" % (' '.join(ccomp),)
    log.info(display)
    macros, objects, extra_postargs, pp_opts, build = \
            self._setup_compile(output_dir, macros, include_dirs, sources,
                                depends, extra_postargs)
    cc_args = self._get_cc_args(pp_opts, debug, extra_preargs)
    #cc_args += ['-g']
    display = "compile options: '%s'" % (' '.join(cc_args))
    if extra_postargs:
        display += "\nextra options: '%s'" % (' '.join(extra_postargs))
    log.info(display)

    def single_compile(args):
        obj, (src, ext) = args

        # check if we are currently already processing the same object
        # happens when using the same source in multiple extensions
        while True:
            # need explicit lock as there is no atomic check and add with GIL
            with _global_lock:
                # file not being worked on, start working
                if obj not in _processing_files:
                    _processing_files.add(obj)
                    break
            # wait for the processing to end
            time.sleep(0.1)

        try:
            self._compile(obj, src, ext, cc_args, extra_postargs, pp_opts)
        finally:
            # register being done processing
            with _global_lock:
                _processing_files.remove(obj)

    for o in build.items():
        single_compile(o)

    # Return *all* object filenames, not just the ones we just built.
    return objects

replace_method(CCompiler, 'compile', CCompiler_compile)
# monkeypatch end

module_name = "parse_jit_py{}".format(str(sys.version_info[0]) + str(sys.version_info[1]))
cc = CC(module_name)
cc.verbose = True

np_crc16_tab = np.array(crc16_tab, dtype=np.uint16)

SENDER_ID = _SENDER_ID
SBP_PREAMBLE = _SBP_PREAMBLE


@nb.jit('u2(u1[:], u4, u2, u4)', nopython=True, nogil=True)
@cc.export('crc16jit', 'u2(u1[:], u4, u2, u4)')
def crc16jit(buf, offset, crc, length):
  """CRC16 implementation acording to CCITT standards."""
  for index in range(offset, offset + length):
    data = buf[index]
    lookup = np_crc16_tab[((nb.u2(crc) >> 8) & nb.u2(0xFF)) ^ (data & nb.u2(0xFF))]
    crc = ((nb.u2(crc) << nb.u2(8)) & nb.u2(0xFFFF)) ^ lookup
    crc = nb.u2(crc) & nb.u2(0xFFFF)
  return crc


@nb.jit('Tuple((u1,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
@cc.export('get_u8', 'Tuple((u1,u4,u4))(u1[:],u4,u4)')
def get_u8(buf, offset, length):
    if length < 1:
        return (0, offset, length)
    return buf[offset], offset + 1, length - 1


@nb.jit('Tuple((u2,u4,u4))(u1[:],u4,u4)', nopython=True, nogil=True)
@cc.export('get_u16', 'Tuple((u2,u4,u4))(u1[:],u4,u4)')
def get_u16(buf, offset, length):
    if length < 2:
        return (0, offset, length)
    msb = nb.u2(buf[offset + 1]) << 8
    lsb = nb.u2(buf[offset + 0]) << 0
    return msb | lsb, offset + 2, length - 2


@cc.export('get_u32', 'Tuple((u4,u4,u4))(u1[:],u4,u4)')
def get_u32(buf, offset, length):
    if length < 4:
        return (0, offset, length)
    a = nb.u4(buf[offset + 3]) << 24
    b = nb.u4(buf[offset + 2]) << 16
    c = nb.u4(buf[offset + 1]) << 8
    d = nb.u4(buf[offset + 0]) << 0
    return a | b | c | d, offset + 4, length - 4


@cc.export('get_u64', 'Tuple((u8,u4,u4))(u1[:],u4,u4)')
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


@cc.export('get_s8', 'Tuple((i1,u4,u4))(u1[:],u4,u4)')
def get_s8(buf, offset, length):
    if length < 1:
        return (0, offset, length)
    return buf[offset], offset + 1, length - 1


@cc.export('get_s16', 'Tuple((i2,u4,u4))(u1[:],u4,u4)')
def get_s16(buf, offset, length):
    if length < 2:
        return (0, offset, length)
    msb = nb.i2(buf[offset + 1]) << 8
    lsb = nb.i2(buf[offset + 0]) << 0
    return msb | lsb, offset + 2, length - 2


@cc.export('get_s32', 'Tuple((i4,u4,u4))(u1[:],u4,u4)')
def get_s32(buf, offset, length):
    if length < 4:
        return (0, offset, length)
    a = nb.i4(buf[offset + 3]) << 24
    b = nb.i4(buf[offset + 2]) << 16
    c = nb.i4(buf[offset + 1]) << 8
    d = nb.i4(buf[offset + 0]) << 0
    return a | b | c | d, offset + 4, length - 4


@cc.export('get_s64', 'Tuple((i8,u4,u4))(u1[:],u4,u4)')
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


@cc.export('_get_string', 'Tuple((u1[:],u4,u4))(u1[:],u4,u4,b1)')
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


@cc.export('unpack_payload', 'Tuple((u4, u2, u2, u2, u2, b1))(u1[:], u4, u4)')
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


def compile():
    cc.compile()

    # Move deliverables to same dir as the script
    dest_dir = os.path.dirname(os.path.realpath(__file__))
    for f in glob.glob(os.path.join(os.getcwd(), module_name + '.*')):
        shutil.move(f, os.path.join(dest_dir, ntpath.basename(f)))


if __name__ == "__main__":    # not when running with setuptools
    compile()
