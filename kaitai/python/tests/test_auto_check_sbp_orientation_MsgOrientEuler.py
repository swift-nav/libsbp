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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientEuler.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_orientation_msg_orient_euler_1():
    buf = base64.standard_b64decode("VSECQgAdAQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAMs4g==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe22c
    
    assert msg.length == 29
    
    assert msg.msg_type == 0x221
    
    assert msg.payload == "AQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAM="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.flags) == 3
    
    assert dictify(msg.pitch) == 2
    
    assert dictify(msg.pitch_accuracy) == 3.0
    
    assert dictify(msg.roll) == 1
    
    assert dictify(msg.roll_accuracy) == 7.0
    
    assert dictify(msg.tow) == 1
    
    assert dictify(msg.yaw) == 8
    
    assert dictify(msg.yaw_accuracy) == 7.0

    assert dictify(msg) == {'pitch': 2, 'sender': 66, 'msg_type': 545, 'roll': 1, 'yaw': 8, 'tow': 1, 'roll_accuracy': 7, 'crc': 57900, 'length': 29, 'flags': 3, 'pitch_accuracy': 3, 'yaw_accuracy': 7, 'preamble': 85, 'payload': 'AQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAM='}