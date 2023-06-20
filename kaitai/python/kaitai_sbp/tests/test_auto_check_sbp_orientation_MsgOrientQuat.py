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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientQuat.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_orientation_msg_orient_quat_1():
    buf = base64.standard_b64decode("VSACQgAlAAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAboG")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6ba
    
    assert msg.length == 37
    
    assert msg.msg_type == 0x220
    
    assert msg.payload == "AAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.tow) == 0
    
    assert dictify(msg.w) == 3
    
    assert dictify(msg.w_accuracy) == 3.0
    
    assert dictify(msg.x) == 7
    
    assert dictify(msg.x_accuracy) == 4.0
    
    assert dictify(msg.y) == 8
    
    assert dictify(msg.y_accuracy) == 8.0
    
    assert dictify(msg.z) == 4
    
    assert dictify(msg.z_accuracy) == 3.0

    assert dictify(msg) == {'sender': 66, 'msg_type': 544, 'tow': 0, 'z_accuracy': 3, 'w_accuracy': 3, 'crc': 1722, 'length': 37, 'flags': 1, 'w': 3, 'y': 8, 'x': 7, 'z': 4, 'preamble': 85, 'payload': 'AAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAQ==', 'y_accuracy': 8, 'x_accuracy': 4}