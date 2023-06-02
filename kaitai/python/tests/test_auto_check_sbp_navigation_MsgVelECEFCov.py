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

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ecef_cov_1():
    buf = base64.standard_b64decode("VRUCQgAqAgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAMEW/4=")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"cov_y_z": 1, "cov_y_y": 2, "n_sats": 3, "sender": 66, "msg_type": 533, "cov_x_z": 2, "cov_x_y": 2, "cov_x_x": 2, "tow": 2, "crc": 65115, "length": 42, "flags": 4, "y": 0, "x": 0, "z": 6, "preamble": 85, "payload": "AgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAME", "cov_z_z": 3}
    assert parsed_dict['crc'] == 0xfe5b
    assert parsed_dict['length'] == 42
    assert parsed_dict['msg_type'] == 0x215
    assert parsed_dict['payload'] == "AgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAME"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.cov_x_x) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.cov_x_y) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.cov_x_z) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.cov_y_y) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.cov_y_z) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.cov_z_z) == snake_case_keys( 3.0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 4 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 3 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2 )
    assert dictify(obj.payload.x) == snake_case_keys( 0 )
    assert dictify(obj.payload.y) == snake_case_keys( 0 )
    assert dictify(obj.payload.z) == snake_case_keys( 6 )

    assert parsed_dict == snake_case_keys(orig_dict)