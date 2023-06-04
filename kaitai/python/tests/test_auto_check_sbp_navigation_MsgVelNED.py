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
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ned_1():
    buf = base64.standard_b64decode("VQ4C04gWKPR6EwMAAAD8////8////wAAAAAOAFbR")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd156
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20e
    
    assert msg.payload == "KPR6EwMAAAD8////8////wAAAAAOAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == -13
    
    assert dictify(msg.e) == -4
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 3
    
    assert dictify(msg.n_sats) == 14
    
    assert dictify(msg.tow) == 326825000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -4, 'sender': 35027, 'msg_type': 526, 'tow': 326825000, 'n': 3, 'crc': 53590, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 14, 'preamble': 85, 'payload': 'KPR6EwMAAAD8////8////wAAAAAOAA==', 'd': -13}

def test_auto_check_sbp_navigation_msg_vel_ned_2():
    buf = base64.standard_b64decode("VQ4C04gWHPZ6E/z/////////6P///wAAAAAPABDk")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe410
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20e
    
    assert msg.payload == "HPZ6E/z/////////6P///wAAAAAPAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == -24
    
    assert dictify(msg.e) == -1
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -4
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326825500
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -1, 'sender': 35027, 'msg_type': 526, 'tow': 326825500, 'n': -4, 'crc': 58384, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 15, 'preamble': 85, 'payload': 'HPZ6E/z/////////6P///wAAAAAPAA==', 'd': -24}

def test_auto_check_sbp_navigation_msg_vel_ned_3():
    buf = base64.standard_b64decode("VQ4C04gWEPh6EwAAAAD9////9P///wAAAAAPAAuk")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa40b
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20e
    
    assert msg.payload == "EPh6EwAAAAD9////9P///wAAAAAPAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == -12
    
    assert dictify(msg.e) == -3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 0
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326826000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -3, 'sender': 35027, 'msg_type': 526, 'tow': 326826000, 'n': 0, 'crc': 41995, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 15, 'preamble': 85, 'payload': 'EPh6EwAAAAD9////9P///wAAAAAPAA==', 'd': -12}

def test_auto_check_sbp_navigation_msg_vel_ned_4():
    buf = base64.standard_b64decode("VQ4C04gWBPp6EwIAAAADAAAA6P///wAAAAAPAJjQ")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd098
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20e
    
    assert msg.payload == "BPp6EwIAAAADAAAA6P///wAAAAAPAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == -24
    
    assert dictify(msg.e) == 3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 2
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326826500
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': 3, 'sender': 35027, 'msg_type': 526, 'tow': 326826500, 'n': 2, 'crc': 53400, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 15, 'preamble': 85, 'payload': 'BPp6EwIAAAADAAAA6P///wAAAAAPAA==', 'd': -24}

def test_auto_check_sbp_navigation_msg_vel_ned_5():
    buf = base64.standard_b64decode("VQ4C04gW+Pt6EwEAAAAAAAAA6////wAAAAAPALZ4")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x78b6
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20e
    
    assert msg.payload == "+Pt6EwEAAAAAAAAA6////wAAAAAPAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == -21
    
    assert dictify(msg.e) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 1
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326827000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': 0, 'sender': 35027, 'msg_type': 526, 'tow': 326827000, 'n': 1, 'crc': 30902, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 15, 'preamble': 85, 'payload': '+Pt6EwEAAAAAAAAA6////wAAAAAPAA==', 'd': -21}