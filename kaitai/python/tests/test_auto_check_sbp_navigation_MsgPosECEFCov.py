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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCov.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_ecef_cov_1():
    buf = base64.standard_b64decode("VRQCQgA2BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF+ac=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"cov_y_z": 8, "cov_y_y": 6, "n_sats": 4, "sender": 66, "msg_type": 532, "cov_x_z": 2, "cov_x_y": 7, "cov_x_x": 8, "tow": 7, "crc": 43001, "length": 54, "flags": 5, "y": 1, "x": 6, "z": 4, "preamble": 85, "payload": "BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF", "cov_z_z": 5}
    assert parsed_dict['crc'] == 0xa7f9
    assert parsed_dict['length'] == 54
    assert parsed_dict['msg_type'] == 0x214
    assert parsed_dict['payload'] == "BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.cov_x_x) == snake_case_keys( 8.0 )
    assert dictify(obj.payload.cov_x_y) == snake_case_keys( 7.0 )
    assert dictify(obj.payload.cov_x_z) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.cov_y_y) == snake_case_keys( 6.0 )
    assert dictify(obj.payload.cov_y_z) == snake_case_keys( 8.0 )
    assert dictify(obj.payload.cov_z_z) == snake_case_keys( 5.0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 5 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 4 )
    assert dictify(obj.payload.tow) == snake_case_keys( 7 )
    assert dictify(obj.payload.x) == snake_case_keys( 6.0 )
    assert dictify(obj.payload.y) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.z) == snake_case_keys( 4.0 )

    assert parsed_dict == snake_case_keys(orig_dict)