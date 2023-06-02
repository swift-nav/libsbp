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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/telemetry/test_MsgTelSv.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_telemetry_msg_tel_sv_1():
    buf = base64.standard_b64decode("VSABlCYUrwjQ3T4YEAEoMgXi/wEAAQEBIQwnaQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"preamble": 85, "msg_type": 288, "sender": 9876, "length": 20, "payload": "rwjQ3T4YEAEoMgXi/wEAAQEBIQw=", "crc": 26919, "wn": 2223, "tow": 406773200, "n_obs": 16, "origin_flags": 1, "sv_tel": [{"az": 40, "el": 50, "availability_flags": 5, "pseudorange_residual": -30, "phase_residual": 1, "outlier_flags": 1, "ephemeris_flags": 1, "correction_flags": 1, "sid": {"sat": 33, "code": 12}}]}
    assert parsed_dict['crc'] == 0x6927
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x120
    assert parsed_dict['payload'] == "rwjQ3T4YEAEoMgXi/wEAAQEBIQw="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x2694
    assert dictify(obj.payload.n_obs) == snake_case_keys( 16 )
    assert dictify(obj.payload.origin_flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.sv_tel) == snake_case_keys( [{'availability_flags': 5, 'az': 40, 'correction_flags': 1, 'el': 50, 'ephemeris_flags': 1, 'outlier_flags': 1, 'phase_residual': 1, 'pseudorange_residual': -30, 'sid': {'code': 12, 'sat': 33}}] )
    assert dictify(obj.payload.tow) == snake_case_keys( 406773200 )
    assert dictify(obj.payload.wn) == snake_case_keys( 2223 )

    assert parsed_dict == snake_case_keys(orig_dict)