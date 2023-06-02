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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNED.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ned_1():
    buf = base64.standard_b64decode("VQ4C04gWKPR6EwMAAAD8////8////wAAAAAOAFbR")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -4, "sender": 35027, "msg_type": 526, "tow": 326825000, "n": 3, "crc": 53590, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 14, "preamble": 85, "payload": "KPR6EwMAAAD8////8////wAAAAAOAA==", "d": -13}
    assert parsed_dict['crc'] == 0xd156
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20e
    assert parsed_dict['payload'] == "KPR6EwMAAAD8////8////wAAAAAOAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( -13 )
    assert dictify(obj.payload.e) == snake_case_keys( -4 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 3 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 14 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ned_2():
    buf = base64.standard_b64decode("VQ4C04gWHPZ6E/z/////////6P///wAAAAAPABDk")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -1, "sender": 35027, "msg_type": 526, "tow": 326825500, "n": -4, "crc": 58384, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 15, "preamble": 85, "payload": "HPZ6E/z/////////6P///wAAAAAPAA==", "d": -24}
    assert parsed_dict['crc'] == 0xe410
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20e
    assert parsed_dict['payload'] == "HPZ6E/z/////////6P///wAAAAAPAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( -24 )
    assert dictify(obj.payload.e) == snake_case_keys( -1 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -4 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825500 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ned_3():
    buf = base64.standard_b64decode("VQ4C04gWEPh6EwAAAAD9////9P///wAAAAAPAAuk")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -3, "sender": 35027, "msg_type": 526, "tow": 326826000, "n": 0, "crc": 41995, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 15, "preamble": 85, "payload": "EPh6EwAAAAD9////9P///wAAAAAPAA==", "d": -12}
    assert parsed_dict['crc'] == 0xa40b
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20e
    assert parsed_dict['payload'] == "EPh6EwAAAAD9////9P///wAAAAAPAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( -12 )
    assert dictify(obj.payload.e) == snake_case_keys( -3 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ned_4():
    buf = base64.standard_b64decode("VQ4C04gWBPp6EwIAAAADAAAA6P///wAAAAAPAJjQ")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": 3, "sender": 35027, "msg_type": 526, "tow": 326826500, "n": 2, "crc": 53400, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 15, "preamble": 85, "payload": "BPp6EwIAAAADAAAA6P///wAAAAAPAA==", "d": -24}
    assert parsed_dict['crc'] == 0xd098
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20e
    assert parsed_dict['payload'] == "BPp6EwIAAAADAAAA6P///wAAAAAPAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( -24 )
    assert dictify(obj.payload.e) == snake_case_keys( 3 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 2 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826500 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ned_5():
    buf = base64.standard_b64decode("VQ4C04gW+Pt6EwEAAAAAAAAA6////wAAAAAPALZ4")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": 0, "sender": 35027, "msg_type": 526, "tow": 326827000, "n": 1, "crc": 30902, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 15, "preamble": 85, "payload": "+Pt6EwEAAAAAAAAA6////wAAAAAPAA==", "d": -21}
    assert parsed_dict['crc'] == 0x78b6
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20e
    assert parsed_dict['payload'] == "+Pt6EwEAAAAAAAAA6////wAAAAAPAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( -21 )
    assert dictify(obj.payload.e) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 1 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326827000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)