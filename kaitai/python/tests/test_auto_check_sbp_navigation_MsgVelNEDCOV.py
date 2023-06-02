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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDCOV.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_nedcov_1():
    buf = base64.standard_b64decode("VRICQgAqZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoAWM0=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"cov_e_d": 1, "cov_e_e": 1, "n_sats": 10, "sender": 66, "msg_type": 530, "cov_n_n": 1, "cov_n_e": 1, "tow": 100, "n": 1, "crc": 52568, "length": 42, "cov_n_d": 1, "flags": 0, "e": 1, "cov_d_d": 1, "preamble": 85, "payload": "ZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoA", "d": 1}
    assert parsed_dict['payload'] == "ZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoA"
    assert parsed_dict['crc'] == 0xCD58
    assert parsed_dict['length'] == 42
    assert parsed_dict['msg_type'] == 0x212
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.cov_d_d) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.cov_e_d) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.cov_e_e) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.cov_n_d) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.cov_n_e) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.cov_n_n) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.d) == snake_case_keys( 1 )
    assert dictify(obj.payload.e) == snake_case_keys( 1 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 1 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 10 )
    assert dictify(obj.payload.tow) == snake_case_keys( 100 )

    assert parsed_dict == snake_case_keys(orig_dict)