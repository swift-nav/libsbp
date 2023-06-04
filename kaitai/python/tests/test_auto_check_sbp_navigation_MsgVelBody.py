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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelBody.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_body_1():
    buf = base64.standard_b64decode("VRMCQgAqAQAAAAQAAAACAAAAAQAAAAAAAAAAAKBAAADgQAAA4EAAAEBAAAAAQAMIeJA=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9078
    
    assert msg.length == 42
    
    assert msg.msg_type == 0x213
    
    assert msg.payload == "AQAAAAQAAAACAAAAAQAAAAAAAAAAAKBAAADgQAAA4EAAAEBAAAAAQAMI"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.cov_x_x) == 0.0
    
    assert dictify(msg.cov_x_y) == 5.0
    
    assert dictify(msg.cov_x_z) == 7.0
    
    assert dictify(msg.cov_y_y) == 7.0
    
    assert dictify(msg.cov_y_z) == 3.0
    
    assert dictify(msg.cov_z_z) == 2.0
    
    assert dictify(msg.flags) == 8
    
    assert dictify(msg.n_sats) == 3
    
    assert dictify(msg.tow) == 1
    
    assert dictify(msg.x) == 4
    
    assert dictify(msg.y) == 2
    
    assert dictify(msg.z) == 1

    assert dictify(msg) == {'cov_y_z': 3, 'cov_y_y': 7, 'n_sats': 3, 'sender': 66, 'msg_type': 531, 'cov_x_z': 7, 'cov_x_y': 5, 'cov_x_x': 0, 'tow': 1, 'crc': 36984, 'length': 42, 'flags': 8, 'y': 2, 'x': 4, 'z': 1, 'preamble': 85, 'payload': 'AQAAAAQAAAACAAAAAQAAAAAAAAAAAKBAAADgQAAA4EAAAEBAAAAAQAMI', 'cov_z_z': 2}