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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgBootloaderHandshakeResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_bootload_msg_bootloader_handshake_resp_1():
    buf = base64.standard_b64decode("VbQAAAAJAAAAAHYxLjIKyQE=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"sender": 0, "msg_type": 180, "crc": 457, "length": 9, "version": "v1.2\n", "flags": 0, "preamble": 85, "payload": "AAAAAHYxLjIK"}
    assert parsed_dict['crc'] == 0x1c9
    assert parsed_dict['length'] == 9
    assert parsed_dict['msg_type'] == 0xb4
    assert parsed_dict['payload'] == "AAAAAHYxLjIK"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x0
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.version) == snake_case_keys( 'v1.2\n' )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_bootload_msg_bootloader_handshake_resp_2():
    buf = base64.standard_b64decode("VbAAwwQEdjEuMgHO")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = { "handshake": [118, 49, 46, 50], "crc": 52737, "length": 4, "msg_type": 176, "payload": "djEuMg==", "preamble": 85, "sender": 1219 }
    assert parsed_dict['crc'] == 0xce01
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0xb0
    assert parsed_dict['payload'] == "djEuMg=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.handshake) == snake_case_keys( [118, 49, 46, 50] )

    assert parsed_dict == snake_case_keys(orig_dict)