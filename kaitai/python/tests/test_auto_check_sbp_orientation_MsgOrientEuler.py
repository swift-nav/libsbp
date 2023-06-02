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
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_orientation_msg_orient_euler_1():
    buf = base64.standard_b64decode("VSECQgAdAQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAMs4g==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"pitch": 2, "sender": 66, "msg_type": 545, "roll": 1, "yaw": 8, "tow": 1, "roll_accuracy": 7, "crc": 57900, "length": 29, "flags": 3, "pitch_accuracy": 3, "yaw_accuracy": 7, "preamble": 85, "payload": "AQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAM="}
    assert parsed_dict['crc'] == 0xe22c
    assert parsed_dict['length'] == 29
    assert parsed_dict['msg_type'] == 0x221
    assert parsed_dict['payload'] == "AQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAM="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.flags) == snake_case_keys( 3 )
    assert dictify(obj.payload.pitch) == snake_case_keys( 2 )
    assert dictify(obj.payload.pitch_accuracy) == snake_case_keys( 3.0 )
    assert dictify(obj.payload.roll) == snake_case_keys( 1 )
    assert dictify(obj.payload.roll_accuracy) == snake_case_keys( 7.0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 1 )
    assert dictify(obj.payload.yaw) == snake_case_keys( 8 )
    assert dictify(obj.payload.yaw_accuracy) == snake_case_keys( 7.0 )

    assert parsed_dict == snake_case_keys(orig_dict)