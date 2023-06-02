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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/vehicle/test_MsgOdometry.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_vehicle_msg_odometry_1():
    buf = base64.standard_b64decode("VQMJQgAJCAAAAAcAAAABNGM=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"sender": 66, "msg_type": 2307, "tow": 8, "crc": 25396, "length": 9, "flags": 1, "velocity": 7, "preamble": 85, "payload": "CAAAAAcAAAAB"}
    assert parsed_dict['crc'] == 0x6334
    assert parsed_dict['length'] == 9
    assert parsed_dict['msg_type'] == 0x903
    assert parsed_dict['payload'] == "CAAAAAcAAAAB"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.tow) == snake_case_keys( 8 )
    assert dictify(obj.payload.velocity) == snake_case_keys( 7 )

    assert parsed_dict == snake_case_keys(orig_dict)