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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgAngularRate.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_orientation_msg_angular_rate_1():
    buf = base64.standard_b64decode("VSICQgARAgAAAAIAAAAFAAAAAgAAAABYRg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 66, "msg_type": 546, "tow": 2, "crc": 18008, "length": 17, "flags": 0, "y": 5, "x": 2, "z": 2, "preamble": 85, "payload": "AgAAAAIAAAAFAAAAAgAAAAA="}
    assert parsed_dict['crc'] == 0x4658
    assert parsed_dict['length'] == 17
    assert parsed_dict['msg_type'] == 0x222
    assert parsed_dict['payload'] == "AgAAAAIAAAAFAAAAAgAAAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2 )
    assert dictify(obj.payload.x) == snake_case_keys( 2 )
    assert dictify(obj.payload.y) == snake_case_keys( 5 )
    assert dictify(obj.payload.z) == snake_case_keys( 2 )

    assert parsed_dict == snake_case_keys(orig_dict)