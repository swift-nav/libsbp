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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeGNSS.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_gps_time_gnss_1():
    buf = base64.standard_b64decode("VQQB04gLgAco9HoT9IsCAACZWA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x5899
    assert payload.length == 11
    assert payload.msg_type == 0x104
    assert payload.payload == "gAco9HoT9IsCAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 166900 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825000 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1920 )

    assert dictify(payload) == snake_case_keys( {"sender": 35027, "msg_type": 260, "wn": 1920, "tow": 326825000, "crc": 22681, "length": 11, "flags": 0, "ns_residual": 166900, "preamble": 85, "payload": "gAco9HoT9IsCAAA="} )

def test_auto_check_sbp_navigation_msg_gps_time_gnss_2():
    buf = base64.standard_b64decode("VQQB04gLgAcc9noTfuoDAAD6ww==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xc3fa
    assert payload.length == 11
    assert payload.msg_type == 0x104
    assert payload.payload == "gAcc9noTfuoDAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 256638 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825500 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1920 )

    assert dictify(payload) == snake_case_keys( {"sender": 35027, "msg_type": 260, "wn": 1920, "tow": 326825500, "crc": 50170, "length": 11, "flags": 0, "ns_residual": 256638, "preamble": 85, "payload": "gAcc9noTfuoDAAA="} )

def test_auto_check_sbp_navigation_msg_gps_time_gnss_3():
    buf = base64.standard_b64decode("VQQB04gLgAcQ+HoTgQwEAAC3lA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x94b7
    assert payload.length == 11
    assert payload.msg_type == 0x104
    assert payload.payload == "gAcQ+HoTgQwEAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 265345 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826000 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1920 )

    assert dictify(payload) == snake_case_keys( {"sender": 35027, "msg_type": 260, "wn": 1920, "tow": 326826000, "crc": 38071, "length": 11, "flags": 0, "ns_residual": 265345, "preamble": 85, "payload": "gAcQ+HoTgQwEAAA="} )

def test_auto_check_sbp_navigation_msg_gps_time_gnss_4():
    buf = base64.standard_b64decode("VQQB04gLgAcE+noTicwEAACJZQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x6589
    assert payload.length == 11
    assert payload.msg_type == 0x104
    assert payload.payload == "gAcE+noTicwEAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 314505 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826500 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1920 )

    assert dictify(payload) == snake_case_keys( {"sender": 35027, "msg_type": 260, "wn": 1920, "tow": 326826500, "crc": 25993, "length": 11, "flags": 0, "ns_residual": 314505, "preamble": 85, "payload": "gAcE+noTicwEAAA="} )

def test_auto_check_sbp_navigation_msg_gps_time_gnss_5():
    buf = base64.standard_b64decode("VQQB04gLgAf4+3oTtYkFAAAP4Q==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xe10f
    assert payload.length == 11
    assert payload.msg_type == 0x104
    assert payload.payload == "gAf4+3oTtYkFAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 362933 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326827000 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1920 )

    assert dictify(payload) == snake_case_keys( {"sender": 35027, "msg_type": 260, "wn": 1920, "tow": 326827000, "crc": 57615, "length": 11, "flags": 0, "ns_residual": 362933, "preamble": 85, "payload": "gAf4+3oTtYkFAAA="} )