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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStartup.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_startup_1():
    buf = base64.standard_b64decode("VQD/QgAEAAAAAEag")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"reserved": 0, "sender": 66, "msg_type": 65280, "cause": 0, "startup_type": 0, "crc": 41030, "length": 4, "preamble": 85, "payload": "AAAAAA=="}
    assert parsed_dict['crc'] == 0xa046
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0xff00
    assert parsed_dict['payload'] == "AAAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.cause) == snake_case_keys( 0 )
    assert dictify(obj.payload.reserved) == snake_case_keys( 0 )
    assert dictify(obj.payload.startup_type) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_system_msg_startup_2():
    buf = base64.standard_b64decode("VQD/wwQEAAAAAH+1")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"reserved": 0, "cause":0, "startup_type":0, "sender": 1219, "msg_type": 65280, "crc": 46463, "length": 4, "preamble": 85, "payload": "AAAAAA=="}
    assert parsed_dict['crc'] == 0xb57f
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0xff00
    assert parsed_dict['payload'] == "AAAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.cause) == snake_case_keys( 0 )
    assert dictify(obj.payload.reserved) == snake_case_keys( 0 )
    assert dictify(obj.payload.startup_type) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)