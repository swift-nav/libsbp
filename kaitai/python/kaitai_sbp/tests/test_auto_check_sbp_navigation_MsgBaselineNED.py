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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNED.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_baseline_ned_1():
    buf = base64.standard_b64decode("VQwC04gWKPR6E8lzDACzWOb/mX0AAAAAAAAOAOJG")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x46e2
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20c
    
    assert msg.payload == "KPR6E8lzDACzWOb/mX0AAAAAAAAOAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == 32153
    
    assert dictify(msg.e) == -1681229
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 816073
    
    assert dictify(msg.n_sats) == 14
    
    assert dictify(msg.tow) == 326825000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -1681229, 'sender': 35027, 'msg_type': 524, 'tow': 326825000, 'n': 816073, 'crc': 18146, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 14, 'preamble': 85, 'payload': 'KPR6E8lzDACzWOb/mX0AAAAAAAAOAA==', 'd': 32153}

def test_auto_check_sbp_navigation_msg_baseline_ned_2():
    buf = base64.standard_b64decode("VQwC04gWEPh6E2JzDADCWOb/bn8AAAAAAAAPAEVd")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5d45
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20c
    
    assert msg.payload == "EPh6E2JzDADCWOb/bn8AAAAAAAAPAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == 32622
    
    assert dictify(msg.e) == -1681214
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 815970
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326826000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -1681214, 'sender': 35027, 'msg_type': 524, 'tow': 326826000, 'n': 815970, 'crc': 23877, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 15, 'preamble': 85, 'payload': 'EPh6E2JzDADCWOb/bn8AAAAAAAAPAA==', 'd': 32622}

def test_auto_check_sbp_navigation_msg_baseline_ned_3():
    buf = base64.standard_b64decode("VQwC04gW+Pt6E49yDACtWOb/7n8AAAAAAAAPANKp")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa9d2
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20c
    
    assert msg.payload == "+Pt6E49yDACtWOb/7n8AAAAAAAAPAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == 32750
    
    assert dictify(msg.e) == -1681235
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 815759
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326827000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -1681235, 'sender': 35027, 'msg_type': 524, 'tow': 326827000, 'n': 815759, 'crc': 43474, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 15, 'preamble': 85, 'payload': '+Pt6E49yDACtWOb/7n8AAAAAAAAPAA==', 'd': 32750}

def test_auto_check_sbp_navigation_msg_baseline_ned_4():
    buf = base64.standard_b64decode("VQwC04gW4P96E1ZwDAAzWOb/L38AAAAAAAAPAIdr")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6b87
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20c
    
    assert msg.payload == "4P96E1ZwDAAzWOb/L38AAAAAAAAPAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == 32559
    
    assert dictify(msg.e) == -1681357
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 815190
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326828000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -1681357, 'sender': 35027, 'msg_type': 524, 'tow': 326828000, 'n': 815190, 'crc': 27527, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 15, 'preamble': 85, 'payload': '4P96E1ZwDAAzWOb/L38AAAAAAAAPAA==', 'd': 32559}

def test_auto_check_sbp_navigation_msg_baseline_ned_5():
    buf = base64.standard_b64decode("VQwC04gWyAN7E9ZuDADcV+b/pX4AAAAAAAAPAL5Q")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x50be
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x20c
    
    assert msg.payload == "yAN7E9ZuDADcV+b/pX4AAAAAAAAPAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.d) == 32421
    
    assert dictify(msg.e) == -1681444
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 814806
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326829000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -1681444, 'sender': 35027, 'msg_type': 524, 'tow': 326829000, 'n': 814806, 'crc': 20670, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 15, 'preamble': 85, 'payload': 'yAN7E9ZuDADcV+b/pX4AAAAAAAAPAA==', 'd': 32421}