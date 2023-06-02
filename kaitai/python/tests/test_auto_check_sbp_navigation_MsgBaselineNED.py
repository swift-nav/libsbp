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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNED.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_baseline_ned_1():
    buf = base64.standard_b64decode("VQwC04gWKPR6E8lzDACzWOb/mX0AAAAAAAAOAOJG")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -1681229, "sender": 35027, "msg_type": 524, "tow": 326825000, "n": 816073, "crc": 18146, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 14, "preamble": 85, "payload": "KPR6E8lzDACzWOb/mX0AAAAAAAAOAA==", "d": 32153}
    assert parsed_dict['crc'] == 0x46e2
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20c
    assert parsed_dict['payload'] == "KPR6E8lzDACzWOb/mX0AAAAAAAAOAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( 32153 )
    assert dictify(obj.payload.e) == snake_case_keys( -1681229 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 816073 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 14 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_2():
    buf = base64.standard_b64decode("VQwC04gWEPh6E2JzDADCWOb/bn8AAAAAAAAPAEVd")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -1681214, "sender": 35027, "msg_type": 524, "tow": 326826000, "n": 815970, "crc": 23877, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 15, "preamble": 85, "payload": "EPh6E2JzDADCWOb/bn8AAAAAAAAPAA==", "d": 32622}
    assert parsed_dict['crc'] == 0x5d45
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20c
    assert parsed_dict['payload'] == "EPh6E2JzDADCWOb/bn8AAAAAAAAPAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( 32622 )
    assert dictify(obj.payload.e) == snake_case_keys( -1681214 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 815970 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_3():
    buf = base64.standard_b64decode("VQwC04gW+Pt6E49yDACtWOb/7n8AAAAAAAAPANKp")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -1681235, "sender": 35027, "msg_type": 524, "tow": 326827000, "n": 815759, "crc": 43474, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 15, "preamble": 85, "payload": "+Pt6E49yDACtWOb/7n8AAAAAAAAPAA==", "d": 32750}
    assert parsed_dict['crc'] == 0xa9d2
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20c
    assert parsed_dict['payload'] == "+Pt6E49yDACtWOb/7n8AAAAAAAAPAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( 32750 )
    assert dictify(obj.payload.e) == snake_case_keys( -1681235 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 815759 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326827000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_4():
    buf = base64.standard_b64decode("VQwC04gW4P96E1ZwDAAzWOb/L38AAAAAAAAPAIdr")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -1681357, "sender": 35027, "msg_type": 524, "tow": 326828000, "n": 815190, "crc": 27527, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 15, "preamble": 85, "payload": "4P96E1ZwDAAzWOb/L38AAAAAAAAPAA==", "d": 32559}
    assert parsed_dict['crc'] == 0x6b87
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20c
    assert parsed_dict['payload'] == "4P96E1ZwDAAzWOb/L38AAAAAAAAPAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( 32559 )
    assert dictify(obj.payload.e) == snake_case_keys( -1681357 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 815190 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326828000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_5():
    buf = base64.standard_b64decode("VQwC04gWyAN7E9ZuDADcV+b/pX4AAAAAAAAPAL5Q")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -1681444, "sender": 35027, "msg_type": 524, "tow": 326829000, "n": 814806, "crc": 20670, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 15, "preamble": 85, "payload": "yAN7E9ZuDADcV+b/pX4AAAAAAAAPAA==", "d": 32421}
    assert parsed_dict['crc'] == 0x50be
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x20c
    assert parsed_dict['payload'] == "yAN7E9ZuDADcV+b/pX4AAAAAAAAPAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.d) == snake_case_keys( 32421 )
    assert dictify(obj.payload.e) == snake_case_keys( -1681444 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 814806 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326829000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)