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
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_body_1():
    buf = base64.standard_b64decode("VRMCQgAqAQAAAAQAAAACAAAAAQAAAAAAAAAAAKBAAADgQAAA4EAAAEBAAAAAQAMIeJA=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"cov_y_z": 3, "cov_y_y": 7, "n_sats": 3, "sender": 66, "msg_type": 531, "cov_x_z": 7, "cov_x_y": 5, "cov_x_x": 0, "tow": 1, "crc": 36984, "length": 42, "flags": 8, "y": 2, "x": 4, "z": 1, "preamble": 85, "payload": "AQAAAAQAAAACAAAAAQAAAAAAAAAAAKBAAADgQAAA4EAAAEBAAAAAQAMI", "cov_z_z": 2}
    assert parsed_dict['crc'] == 0x9078
    assert parsed_dict['length'] == 42
    assert parsed_dict['msg_type'] == 0x213
    assert parsed_dict['payload'] == "AQAAAAQAAAACAAAAAQAAAAAAAAAAAKBAAADgQAAA4EAAAEBAAAAAQAMI"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.cov_x_x) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.cov_x_y) == snake_case_keys( 5.0 )
    assert dictify(obj.payload.cov_x_z) == snake_case_keys( 7.0 )
    assert dictify(obj.payload.cov_y_y) == snake_case_keys( 7.0 )
    assert dictify(obj.payload.cov_y_z) == snake_case_keys( 3.0 )
    assert dictify(obj.payload.cov_z_z) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 8 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 3 )
    assert dictify(obj.payload.tow) == snake_case_keys( 1 )
    assert dictify(obj.payload.x) == snake_case_keys( 4 )
    assert dictify(obj.payload.y) == snake_case_keys( 2 )
    assert dictify(obj.payload.z) == snake_case_keys( 1 )

    assert parsed_dict == snake_case_keys(orig_dict)