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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgIarState.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_iar_state_1():
    buf = base64.standard_b64decode("VRkA9tcEAQAAANiM")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 55286, "msg_type": 25, "num_hyps": 1, "crc": 36056, "length": 4, "preamble": 85, "payload": "AQAAAA=="}
    assert parsed_dict['crc'] == 0x8cd8
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0x19
    assert parsed_dict['payload'] == "AQAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.num_hyps) == snake_case_keys( 1 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_piksi_msg_iar_state_2():
    buf = base64.standard_b64decode("VRkAwwQEAAAAABKw")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 25, "num_hyps": 0, "crc": 45074, "length": 4, "preamble": 85, "payload": "AAAAAA=="}
    assert parsed_dict['crc'] == 0xb012
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0x19
    assert parsed_dict['payload'] == "AAAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.num_hyps) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_piksi_msg_iar_state_3():
    buf = base64.standard_b64decode("VRkAwwQEAQAAAKbG")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 25, "num_hyps": 1, "crc": 50854, "length": 4, "preamble": 85, "payload": "AQAAAA=="}
    assert parsed_dict['crc'] == 0xc6a6
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0x19
    assert parsed_dict['payload'] == "AQAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.num_hyps) == snake_case_keys( 1 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_piksi_msg_iar_state_4():
    buf = base64.standard_b64decode("VRkAwwQE2QIAAAaF")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 25, "num_hyps": 729, "crc": 34054, "length": 4, "preamble": 85, "payload": "2QIAAA=="}
    assert parsed_dict['crc'] == 0x8506
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0x19
    assert parsed_dict['payload'] == "2QIAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.num_hyps) == snake_case_keys( 729 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_piksi_msg_iar_state_5():
    buf = base64.standard_b64decode("VRkAwwQE2AIAALLz")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 25, "num_hyps": 728, "crc": 62386, "length": 4, "preamble": 85, "payload": "2AIAAA=="}
    assert parsed_dict['crc'] == 0xf3b2
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0x19
    assert parsed_dict['payload'] == "2AIAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.num_hyps) == snake_case_keys( 728 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_piksi_msg_iar_state_6():
    buf = base64.standard_b64decode("VRkAwwQE1wIAAFwn")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 25, "num_hyps": 727, "crc": 10076, "length": 4, "preamble": 85, "payload": "1wIAAA=="}
    assert parsed_dict['crc'] == 0x275c
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0x19
    assert parsed_dict['payload'] == "1wIAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.num_hyps) == snake_case_keys( 727 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_piksi_msg_iar_state_7():
    buf = base64.standard_b64decode("VRkAwwQE0wIAAK3t")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 25, "num_hyps": 723, "crc": 60845, "length": 4, "preamble": 85, "payload": "0wIAAA=="}
    assert parsed_dict['crc'] == 0xedad
    assert parsed_dict['length'] == 4
    assert parsed_dict['msg_type'] == 0x19
    assert parsed_dict['payload'] == "0wIAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.num_hyps) == snake_case_keys( 723 )

    assert parsed_dict == snake_case_keys(orig_dict)