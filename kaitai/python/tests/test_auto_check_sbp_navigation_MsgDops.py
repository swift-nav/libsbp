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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDops.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_dops_1():
    buf = base64.standard_b64decode("VQgCQgAPZAAAAAIABgAFAAUABQAA9AQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"gdop": 2, "tdop": 5, "vdop": 5, "sender": 66, "msg_type": 520, "pdop": 6, "tow": 100, "crc": 1268, "length": 15, "flags": 0, "preamble": 85, "payload": "ZAAAAAIABgAFAAUABQAA", "hdop": 5}
    assert parsed_dict['crc'] == 0x4f4
    assert parsed_dict['length'] == 15
    assert parsed_dict['msg_type'] == 0x208
    assert parsed_dict['payload'] == "ZAAAAAIABgAFAAUABQAA"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.gdop) == snake_case_keys( 2 )
    assert dictify(obj.payload.hdop) == snake_case_keys( 5 )
    assert dictify(obj.payload.pdop) == snake_case_keys( 6 )
    assert dictify(obj.payload.tdop) == snake_case_keys( 5 )
    assert dictify(obj.payload.tow) == snake_case_keys( 100 )
    assert dictify(obj.payload.vdop) == snake_case_keys( 5 )

    assert parsed_dict == snake_case_keys(orig_dict)