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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFCov.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ecef_cov_1():
    buf = base64.standard_b64decode("VRUCQgAqAgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAMEW/4=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xfe5b
    
    assert msg.length == 42
    
    assert msg.msg_type == 0x215
    
    assert msg.payload == "AgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAME"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.cov_x_x) == 2.0
    
    assert dictify(msg.cov_x_y) == 2.0
    
    assert dictify(msg.cov_x_z) == 2.0
    
    assert dictify(msg.cov_y_y) == 2.0
    
    assert dictify(msg.cov_y_z) == 1.0
    
    assert dictify(msg.cov_z_z) == 3.0
    
    assert dictify(msg.flags) == 4
    
    assert dictify(msg.n_sats) == 3
    
    assert dictify(msg.tow) == 2
    
    assert dictify(msg.x) == 0
    
    assert dictify(msg.y) == 0
    
    assert dictify(msg.z) == 6

    assert dictify(msg) == {'cov_y_z': 1, 'cov_y_y': 2, 'n_sats': 3, 'sender': 66, 'msg_type': 533, 'cov_x_z': 2, 'cov_x_y': 2, 'cov_x_x': 2, 'tow': 2, 'crc': 65115, 'length': 42, 'flags': 4, 'y': 0, 'x': 0, 'z': 6, 'preamble': 85, 'payload': 'AgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAME', 'cov_z_z': 3}