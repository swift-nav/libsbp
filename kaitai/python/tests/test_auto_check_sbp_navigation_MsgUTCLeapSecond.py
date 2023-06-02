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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCLeapSecond.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_utc_leap_second_1():
    buf = base64.standard_b64decode("VToCQgAOAQACAAMEBQAGAAcACAky6A==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"reserved_0": 1, "reserved_1": 2, "reserved_2": 3, "count_before": 4, "reserved_3": 5, "reserved_4": 6, "ref_wn": 7, "ref_dn": 8, "count_after": 9, "preamble": 85, "msg_type": 570, "sender": 66, "length": 14, "payload": "AQACAAMEBQAGAAcACAk=", "crc": 59442}
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['msg_type'] == 0x023A
    assert parsed_dict['sender'] == 0x0042
    assert parsed_dict['length'] == 14
    assert parsed_dict['payload'] == "AQACAAMEBQAGAAcACAk="
    assert parsed_dict['crc'] == 0xE832
    assert dictify(obj.payload.count_after) == snake_case_keys( 9 )
    assert dictify(obj.payload.count_before) == snake_case_keys( 4 )
    assert dictify(obj.payload.ref_dn) == snake_case_keys( 8 )
    assert dictify(obj.payload.ref_wn) == snake_case_keys( 7 )
    assert dictify(obj.payload.reserved_0) == snake_case_keys( 1 )
    assert dictify(obj.payload.reserved_1) == snake_case_keys( 2 )
    assert dictify(obj.payload.reserved_2) == snake_case_keys( 3 )
    assert dictify(obj.payload.reserved_3) == snake_case_keys( 5 )
    assert dictify(obj.payload.reserved_4) == snake_case_keys( 6 )

    assert parsed_dict == snake_case_keys(orig_dict)