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

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_logging_msg_print_dep_1():
    buf = base64.standard_b64decode("VRAAIiIrSU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCnRn")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x6774
    assert payload.length == 43
    assert payload.msg_type == 0x10
    assert payload.payload == "SU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x2222
    assert dictify(obj.payload.text) == snake_case_keys( 'INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n' )

    assert dictify(payload) == snake_case_keys( {"sender": 8738, "msg_type": 16, "text": "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n", "crc": 26484, "length": 43, "preamble": 85, "payload": "SU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCg=="} )

def test_auto_check_sbp_logging_msg_print_dep_2():
    buf = base64.standard_b64decode("VRAAIiIqSU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIKjCs=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x2b8c
    assert payload.length == 42
    assert payload.msg_type == 0x10
    assert payload.payload == "SU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIK"
    assert payload.preamble == 0x55
    assert payload.sender == 0x2222
    assert dictify(obj.payload.text) == snake_case_keys( 'INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n' )

    assert dictify(payload) == snake_case_keys( {"sender": 8738, "msg_type": 16, "text": "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n", "crc": 11148, "length": 42, "preamble": 85, "payload": "SU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIK"} )

def test_auto_check_sbp_logging_msg_print_dep_3():
    buf = base64.standard_b64decode("VRAAIiIjSU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQoXjw==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x8f17
    assert payload.length == 35
    assert payload.msg_type == 0x10
    assert payload.payload == "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQo="
    assert payload.preamble == 0x55
    assert payload.sender == 0x2222
    assert dictify(obj.payload.text) == snake_case_keys( 'INFO: Disabling channel 0 (PRN 11)\n' )

    assert dictify(payload) == snake_case_keys( {"sender": 8738, "msg_type": 16, "text": "INFO: Disabling channel 0 (PRN 11)\n", "crc": 36631, "length": 35, "preamble": 85, "payload": "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQo="} )

def test_auto_check_sbp_logging_msg_print_dep_4():
    buf = base64.standard_b64decode("VRAAIiIpSU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgrvMA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x30ef
    assert payload.length == 41
    assert payload.msg_type == 0x10
    assert payload.payload == "SU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgo="
    assert payload.preamble == 0x55
    assert payload.sender == 0x2222
    assert dictify(obj.payload.text) == snake_case_keys( 'INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n' )

    assert dictify(payload) == snake_case_keys( {"sender": 8738, "msg_type": 16, "text": "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n", "crc": 12527, "length": 41, "preamble": 85, "payload": "SU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgo="} )

def test_auto_check_sbp_logging_msg_print_dep_5():
    buf = base64.standard_b64decode("VRAAIiIqSU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIKL/g=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xf82f
    assert payload.length == 42
    assert payload.msg_type == 0x10
    assert payload.payload == "SU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIK"
    assert payload.preamble == 0x55
    assert payload.sender == 0x2222
    assert dictify(obj.payload.text) == snake_case_keys( 'INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n' )

    assert dictify(payload) == snake_case_keys( {"sender": 8738, "msg_type": 16, "text": "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n", "crc": 63535, "length": 42, "preamble": 85, "payload": "SU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIK"} )

def test_auto_check_sbp_logging_msg_print_dep_6():
    buf = base64.standard_b64decode("VRAAIiIjSU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQqeiw==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x8b9e
    assert payload.length == 35
    assert payload.msg_type == 0x10
    assert payload.payload == "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQo="
    assert payload.preamble == 0x55
    assert payload.sender == 0x2222
    assert dictify(obj.payload.text) == snake_case_keys( 'INFO: Disabling channel 1 (PRN 15)\n' )

    assert dictify(payload) == snake_case_keys( {"sender": 8738, "msg_type": 16, "text": "INFO: Disabling channel 1 (PRN 15)\n", "crc": 35742, "length": 35, "preamble": 85, "payload": "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQo="} )