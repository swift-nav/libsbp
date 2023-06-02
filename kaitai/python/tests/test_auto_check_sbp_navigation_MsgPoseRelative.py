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
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pose_relative_1():
    buf = base64.standard_b64decode("VUUCQgBaVgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAFq7s=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"preamble": 85, "msg_type": 581, "sender": 66, "length": 90, "payload": "VgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAF", "crc": 48043, "tow": 1110, "sensor_id": 0, "timestamp_1": 1110, "timestamp_2": 2220, "trans": [1100, 550, 100], "w": -859307164, "x": -6444804, "y": -1866844813, "z": 622997694, "cov_r_x_x": 1.0, "cov_r_x_y": 0.0, "cov_r_x_z": 0.0, "cov_r_y_y": 1.0, "cov_r_y_z": 0.0, "cov_r_z_z": 1.0, "cov_c_x_x": 2.0, "cov_c_x_y": 0.0, "cov_c_x_z": 0.0, "cov_c_y_y": 2.0, "cov_c_y_z": 0.0, "cov_c_z_z": 2.0, "flags": 5}
    assert parsed_dict['crc'] == 0xBBAB
    assert parsed_dict['length'] == 90
    assert parsed_dict['msg_type'] == 0x245
    assert parsed_dict['payload'] == "VgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAF"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.cov_c_x_x) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.cov_c_x_y) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.cov_c_x_z) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.cov_c_y_y) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.cov_c_y_z) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.cov_c_z_z) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.cov_r_x_x) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.cov_r_x_y) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.cov_r_x_z) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.cov_r_y_y) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.cov_r_y_z) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.cov_r_z_z) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 5 )
    assert dictify(obj.payload.sensor_id) == snake_case_keys( 0 )
    assert dictify(obj.payload.timestamp_1) == snake_case_keys( 1110 )
    assert dictify(obj.payload.timestamp_2) == snake_case_keys( 2220 )
    assert dictify(obj.payload.tow) == snake_case_keys( 1110 )
    assert dictify(obj.payload.trans) == snake_case_keys( [1100, 550, 100] )
    assert dictify(obj.payload.w) == snake_case_keys( -859307164 )
    assert dictify(obj.payload.x) == snake_case_keys( -6444804 )
    assert dictify(obj.payload.y) == snake_case_keys( -1866844813 )
    assert dictify(obj.payload.z) == snake_case_keys( 622997694 )

    assert parsed_dict == snake_case_keys(orig_dict)