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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelCog.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_cog_1():
    buf = base64.standard_b64decode("VRwC04geMPZ6E+gDAADQBwAAuAsAAKAPAACIEwAAcBcAAD4A1ME=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xC1D4
    
    assert msg.length == 30
    
    assert msg.msg_type == 0x21C
    
    assert msg.payload == "MPZ6E+gDAADQBwAAuAsAAKAPAACIEwAAcBcAAD4A"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88D3
    
    assert dictify(msg.cog) == 1000
    
    assert dictify(msg.cog_accuracy) == 4000
    
    assert dictify(msg.flags) == 62
    
    assert dictify(msg.sog) == 2000
    
    assert dictify(msg.sog_accuracy) == 5000
    
    assert dictify(msg.tow) == 326825520
    
    assert dictify(msg.v_up) == 3000
    
    assert dictify(msg.v_up_accuracy) == 6000

    assert dictify(msg) == {'crc': 49620, 'length': 30, 'msg_type': 540, 'payload': 'MPZ6E+gDAADQBwAAuAsAAKAPAACIEwAAcBcAAD4A', 'preamble': 85, 'sender': 35027, 'tow': 326825520, 'cog': 1000, 'sog': 2000, 'v_up': 3000, 'cog_accuracy': 4000, 'sog_accuracy': 5000, 'v_up_accuracy': 6000, 'flags': 62}

def test_auto_check_sbp_navigation_msg_vel_cog_2():
    buf = base64.standard_b64decode("VRwC04geMPZ6E3sAAADIAQAAGPz//wCVugpkAAAAZAAAAAAAWnI=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x725A
    
    assert msg.length == 30
    
    assert msg.msg_type == 0x21C
    
    assert msg.payload == "MPZ6E3sAAADIAQAAGPz//wCVugpkAAAAZAAAAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88D3
    
    assert dictify(msg.cog) == 123
    
    assert dictify(msg.cog_accuracy) == 180000000
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.sog) == 456
    
    assert dictify(msg.sog_accuracy) == 100
    
    assert dictify(msg.tow) == 326825520
    
    assert dictify(msg.v_up) == -1000
    
    assert dictify(msg.v_up_accuracy) == 100

    assert dictify(msg) == {'crc': 29274, 'length': 30, 'msg_type': 540, 'payload': 'MPZ6E3sAAADIAQAAGPz//wCVugpkAAAAZAAAAAAA', 'preamble': 85, 'sender': 35027, 'tow': 326825520, 'cog': 123, 'sog': 456, 'v_up': -1000, 'cog_accuracy': 180000000, 'sog_accuracy': 100, 'v_up_accuracy': 100, 'flags': 0}

def test_auto_check_sbp_navigation_msg_vel_cog_3():
    buf = base64.standard_b64decode("VRwC04geMPZ6EwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAKtI=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xD22A
    
    assert msg.length == 30
    
    assert msg.msg_type == 0x21C
    
    assert msg.payload == "MPZ6EwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88D3
    
    assert dictify(msg.cog) == 0
    
    assert dictify(msg.cog_accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.sog) == 0
    
    assert dictify(msg.sog_accuracy) == 0
    
    assert dictify(msg.tow) == 326825520
    
    assert dictify(msg.v_up) == 0
    
    assert dictify(msg.v_up_accuracy) == 0

    assert dictify(msg) == {'crc': 53802, 'length': 30, 'msg_type': 540, 'payload': 'MPZ6EwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA', 'preamble': 85, 'sender': 35027, 'tow': 326825520, 'cog': 0, 'sog': 0, 'v_up': 0, 'cog_accuracy': 0, 'sog_accuracy': 0, 'v_up_accuracy': 0, 'flags': 0}