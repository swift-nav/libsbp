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

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_orientation_msg_orient_quat_1():
    buf = base64.standard_b64decode("VSACQgAlAAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAboG")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 66, "msg_type": 544, "tow": 0, "z_accuracy": 3, "w_accuracy": 3, "crc": 1722, "length": 37, "flags": 1, "w": 3, "y": 8, "x": 7, "z": 4, "preamble": 85, "payload": "AAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAQ==", "y_accuracy": 8, "x_accuracy": 4}
    assert parsed_dict['crc'] == 0x6ba
    assert parsed_dict['length'] == 37
    assert parsed_dict['msg_type'] == 0x220
    assert parsed_dict['payload'] == "AAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.tow) == snake_case_keys( 0 )
    assert dictify(obj.payload.w) == snake_case_keys( 3 )
    assert dictify(obj.payload.w_accuracy) == snake_case_keys( 3.0 )
    assert dictify(obj.payload.x) == snake_case_keys( 7 )
    assert dictify(obj.payload.x_accuracy) == snake_case_keys( 4.0 )
    assert dictify(obj.payload.y) == snake_case_keys( 8 )
    assert dictify(obj.payload.y_accuracy) == snake_case_keys( 8.0 )
    assert dictify(obj.payload.z) == snake_case_keys( 4 )
    assert dictify(obj.payload.z_accuracy) == snake_case_keys( 3.0 )

    assert parsed_dict == snake_case_keys(orig_dict)