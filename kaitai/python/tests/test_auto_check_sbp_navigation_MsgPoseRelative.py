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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPoseRelative.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pose_relative_1():
    buf = base64.standard_b64decode("VUUCQgBaVgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAFq7s=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xBBAB
    
    assert msg.length == 90
    
    assert msg.msg_type == 0x245
    
    assert msg.payload == "VgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAF"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.cov_c_x_x) == 2.0
    
    assert dictify(msg.cov_c_x_y) == 0.0
    
    assert dictify(msg.cov_c_x_z) == 0.0
    
    assert dictify(msg.cov_c_y_y) == 2.0
    
    assert dictify(msg.cov_c_y_z) == 0.0
    
    assert dictify(msg.cov_c_z_z) == 2.0
    
    assert dictify(msg.cov_r_x_x) == 1.0
    
    assert dictify(msg.cov_r_x_y) == 0.0
    
    assert dictify(msg.cov_r_x_z) == 0.0
    
    assert dictify(msg.cov_r_y_y) == 1.0
    
    assert dictify(msg.cov_r_y_z) == 0.0
    
    assert dictify(msg.cov_r_z_z) == 1.0
    
    assert dictify(msg.flags) == 5
    
    assert dictify(msg.sensor_id) == 0
    
    assert dictify(msg.timestamp_1) == 1110
    
    assert dictify(msg.timestamp_2) == 2220
    
    assert dictify(msg.tow) == 1110
    
    assert dictify(msg.trans) == [1100, 550, 100]
    
    assert dictify(msg.w) == -859307164
    
    assert dictify(msg.x) == -6444804
    
    assert dictify(msg.y) == -1866844813
    
    assert dictify(msg.z) == 622997694

    assert dictify(msg) == {'preamble': 85, 'msg_type': 581, 'sender': 66, 'length': 90, 'payload': 'VgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAF', 'crc': 48043, 'tow': 1110, 'sensor_id': 0, 'timestamp_1': 1110, 'timestamp_2': 2220, 'trans': [1100, 550, 100], 'w': -859307164, 'x': -6444804, 'y': -1866844813, 'z': 622997694, 'cov_r_x_x': 1.0, 'cov_r_x_y': 0.0, 'cov_r_x_z': 0.0, 'cov_r_y_y': 1.0, 'cov_r_y_z': 0.0, 'cov_r_z_z': 1.0, 'cov_c_x_x': 2.0, 'cov_c_x_y': 0.0, 'cov_c_x_z': 0.0, 'cov_c_y_y': 2.0, 'cov_c_y_z': 0.0, 'cov_c_z_z': 2.0, 'flags': 5}