# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTime.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_gps_time_1():
    buf = base64.standard_b64decode("VQIB04gLgAco9HoT9IsCAAAimA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9822
    
    assert msg.length == 11
    
    assert msg.msg_type == 0x102
    
    assert msg.payload == "gAco9HoT9IsCAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.ns_residual) == 166900
    
    assert dictify(msg.tow) == 326825000
    
    assert dictify(msg.wn) == 1920

    assert dictify(msg) == {'sender': 35027, 'msg_type': 258, 'wn': 1920, 'tow': 326825000, 'crc': 38946, 'length': 11, 'flags': 0, 'ns_residual': 166900, 'preamble': 85, 'payload': 'gAco9HoT9IsCAAA='}

def test_auto_check_sbp_navigation_msg_gps_time_2():
    buf = base64.standard_b64decode("VQIB04gLgAcc9noTfuoDAABBAw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x341
    
    assert msg.length == 11
    
    assert msg.msg_type == 0x102
    
    assert msg.payload == "gAcc9noTfuoDAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.ns_residual) == 256638
    
    assert dictify(msg.tow) == 326825500
    
    assert dictify(msg.wn) == 1920

    assert dictify(msg) == {'sender': 35027, 'msg_type': 258, 'wn': 1920, 'tow': 326825500, 'crc': 833, 'length': 11, 'flags': 0, 'ns_residual': 256638, 'preamble': 85, 'payload': 'gAcc9noTfuoDAAA='}

def test_auto_check_sbp_navigation_msg_gps_time_3():
    buf = base64.standard_b64decode("VQIB04gLgAcQ+HoTgQwEAAAMVA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x540c
    
    assert msg.length == 11
    
    assert msg.msg_type == 0x102
    
    assert msg.payload == "gAcQ+HoTgQwEAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.ns_residual) == 265345
    
    assert dictify(msg.tow) == 326826000
    
    assert dictify(msg.wn) == 1920

    assert dictify(msg) == {'sender': 35027, 'msg_type': 258, 'wn': 1920, 'tow': 326826000, 'crc': 21516, 'length': 11, 'flags': 0, 'ns_residual': 265345, 'preamble': 85, 'payload': 'gAcQ+HoTgQwEAAA='}

def test_auto_check_sbp_navigation_msg_gps_time_4():
    buf = base64.standard_b64decode("VQIB04gLgAcE+noTicwEAAAypQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa532
    
    assert msg.length == 11
    
    assert msg.msg_type == 0x102
    
    assert msg.payload == "gAcE+noTicwEAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.ns_residual) == 314505
    
    assert dictify(msg.tow) == 326826500
    
    assert dictify(msg.wn) == 1920

    assert dictify(msg) == {'sender': 35027, 'msg_type': 258, 'wn': 1920, 'tow': 326826500, 'crc': 42290, 'length': 11, 'flags': 0, 'ns_residual': 314505, 'preamble': 85, 'payload': 'gAcE+noTicwEAAA='}

def test_auto_check_sbp_navigation_msg_gps_time_5():
    buf = base64.standard_b64decode("VQIB04gLgAf4+3oTtYkFAAC0IQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x21b4
    
    assert msg.length == 11
    
    assert msg.msg_type == 0x102
    
    assert msg.payload == "gAf4+3oTtYkFAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.ns_residual) == 362933
    
    assert dictify(msg.tow) == 326827000
    
    assert dictify(msg.wn) == 1920

    assert dictify(msg) == {'sender': 35027, 'msg_type': 258, 'wn': 1920, 'tow': 326827000, 'crc': 8628, 'length': 11, 'flags': 0, 'ns_residual': 362933, 'preamble': 85, 'payload': 'gAf4+3oTtYkFAAA='}
