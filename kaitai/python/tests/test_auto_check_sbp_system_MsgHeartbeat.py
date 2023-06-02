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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgHeartbeat.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_heartbeat_1():
    buf = base64.standard_b64decode("Vf//9tcEADIAAPnY")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"sender": 55286, "msg_type": 65535, "crc": 55545, "length": 4, "flags": 12800, "preamble": 85, "payload": "ADIAAA=="}
    assert parsed_dict['crc'] == 0xd8f9
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0xffff
    assert parsed_dict['payload'] == "ADIAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.flags) == snake_case_keys( 12800 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_system_msg_heartbeat_2():
    buf = base64.standard_b64decode("Vf//wwQEAAAAAEI5")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"sender": 1219, "msg_type": 65535, "crc": 14658, "length": 4, "flags": 0, "preamble": 85, "payload": "AAAAAA=="}
    assert parsed_dict['crc'] == 0x3942
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0xffff
    assert parsed_dict['payload'] == "AAAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)