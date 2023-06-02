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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_protection_level_1():
    buf = base64.standard_b64decode("VRYCABAhiOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAUsM=")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"tow":501867400,"vpl":0,"hpl":0,"lat":0.0,"lon":0.0,"height":0.0,"flags":0,"preamble":85,"msg_type":534,"sender":4096,"payload":"iOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","crc":50002,"length":33}
    assert parsed_dict['crc'] == 0xc352
    assert parsed_dict['length'] == 33
    assert parsed_dict['payload'] == "iOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    assert parsed_dict['msg_type'] == 0x216
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x1000
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.height) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.hpl) == snake_case_keys( 0 )
    assert dictify(obj.payload.lat) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.lon) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 501867400 )
    assert dictify(obj.payload.vpl) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)