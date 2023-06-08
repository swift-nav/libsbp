# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgPrintDep.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_logging_msg_print_dep_1():
    buf = base64.standard_b64decode("VRAAIiIrSU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCnRn")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6774
    
    assert msg.length == 43
    
    assert msg.msg_type == 0x10
    
    assert msg.payload == "SU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCg=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x2222
    
    assert dictify(msg.text) == "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n"

    assert dictify(msg) == {'sender': 8738, 'msg_type': 16, 'text': 'INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n', 'crc': 26484, 'length': 43, 'preamble': 85, 'payload': 'SU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCg=='}

def test_auto_check_sbp_logging_msg_print_dep_2():
    buf = base64.standard_b64decode("VRAAIiIqSU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIKjCs=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2b8c
    
    assert msg.length == 42
    
    assert msg.msg_type == 0x10
    
    assert msg.payload == "SU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIK"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x2222
    
    assert dictify(msg.text) == "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n"

    assert dictify(msg) == {'sender': 8738, 'msg_type': 16, 'text': 'INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n', 'crc': 11148, 'length': 42, 'preamble': 85, 'payload': 'SU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIK'}

def test_auto_check_sbp_logging_msg_print_dep_3():
    buf = base64.standard_b64decode("VRAAIiIjSU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQoXjw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8f17
    
    assert msg.length == 35
    
    assert msg.msg_type == 0x10
    
    assert msg.payload == "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQo="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x2222
    
    assert dictify(msg.text) == "INFO: Disabling channel 0 (PRN 11)\n"

    assert dictify(msg) == {'sender': 8738, 'msg_type': 16, 'text': 'INFO: Disabling channel 0 (PRN 11)\n', 'crc': 36631, 'length': 35, 'preamble': 85, 'payload': 'SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQo='}

def test_auto_check_sbp_logging_msg_print_dep_4():
    buf = base64.standard_b64decode("VRAAIiIpSU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgrvMA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x30ef
    
    assert msg.length == 41
    
    assert msg.msg_type == 0x10
    
    assert msg.payload == "SU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgo="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x2222
    
    assert dictify(msg.text) == "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n"

    assert dictify(msg) == {'sender': 8738, 'msg_type': 16, 'text': 'INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n', 'crc': 12527, 'length': 41, 'preamble': 85, 'payload': 'SU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgo='}

def test_auto_check_sbp_logging_msg_print_dep_5():
    buf = base64.standard_b64decode("VRAAIiIqSU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIKL/g=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf82f
    
    assert msg.length == 42
    
    assert msg.msg_type == 0x10
    
    assert msg.payload == "SU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIK"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x2222
    
    assert dictify(msg.text) == "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n"

    assert dictify(msg) == {'sender': 8738, 'msg_type': 16, 'text': 'INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n', 'crc': 63535, 'length': 42, 'preamble': 85, 'payload': 'SU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIK'}

def test_auto_check_sbp_logging_msg_print_dep_6():
    buf = base64.standard_b64decode("VRAAIiIjSU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQqeiw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8b9e
    
    assert msg.length == 35
    
    assert msg.msg_type == 0x10
    
    assert msg.payload == "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQo="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x2222
    
    assert dictify(msg.text) == "INFO: Disabling channel 1 (PRN 15)\n"

    assert dictify(msg) == {'sender': 8738, 'msg_type': 16, 'text': 'INFO: Disabling channel 1 (PRN 15)\n', 'crc': 35742, 'length': 35, 'preamble': 85, 'payload': 'SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQo='}