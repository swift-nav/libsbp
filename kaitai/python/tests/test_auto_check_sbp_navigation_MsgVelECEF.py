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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEF.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ecef_1():
    buf = base64.standard_b64decode("VQ0C04gUKPR6E/j////7////CgAAAAAADgC1Yw==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"n_sats": 14, "sender": 35027, "msg_type": 525, "tow": 326825000, "crc": 25525, "length": 20, "flags": 0, "y": -5, "x": -8, "z": 10, "preamble": 85, "payload": "KPR6E/j////7////CgAAAAAADgA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x63b5
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x20d
    assert parsed_dict['payload'] == "KPR6E/j////7////CgAAAAAADgA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 14 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825000 )
    assert dictify(obj.payload.x) == snake_case_keys( -8 )
    assert dictify(obj.payload.y) == snake_case_keys( -5 )
    assert dictify(obj.payload.z) == snake_case_keys( 10 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_2():
    buf = base64.standard_b64decode("VQ0C04gUHPZ6E/T////u////CwAAAAAADwDXeA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"n_sats": 15, "sender": 35027, "msg_type": 525, "tow": 326825500, "crc": 30935, "length": 20, "flags": 0, "y": -18, "x": -12, "z": 11, "preamble": 85, "payload": "HPZ6E/T////u////CwAAAAAADwA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x78d7
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x20d
    assert parsed_dict['payload'] == "HPZ6E/T////u////CwAAAAAADwA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825500 )
    assert dictify(obj.payload.x) == snake_case_keys( -12 )
    assert dictify(obj.payload.y) == snake_case_keys( -18 )
    assert dictify(obj.payload.z) == snake_case_keys( 11 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_3():
    buf = base64.standard_b64decode("VQ0C04gUEPh6E/j////6////BwAAAAAADwD43Q==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"n_sats": 15, "sender": 35027, "msg_type": 525, "tow": 326826000, "crc": 56824, "length": 20, "flags": 0, "y": -6, "x": -8, "z": 7, "preamble": 85, "payload": "EPh6E/j////6////BwAAAAAADwA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xddf8
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x20d
    assert parsed_dict['payload'] == "EPh6E/j////6////BwAAAAAADwA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826000 )
    assert dictify(obj.payload.x) == snake_case_keys( -8 )
    assert dictify(obj.payload.y) == snake_case_keys( -6 )
    assert dictify(obj.payload.z) == snake_case_keys( 7 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_4():
    buf = base64.standard_b64decode("VQ0C04gUBPp6E/n////v////EAAAAAAADwABpw==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"n_sats": 15, "sender": 35027, "msg_type": 525, "tow": 326826500, "crc": 42753, "length": 20, "flags": 0, "y": -17, "x": -7, "z": 16, "preamble": 85, "payload": "BPp6E/n////v////EAAAAAAADwA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xa701
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x20d
    assert parsed_dict['payload'] == "BPp6E/n////v////EAAAAAAADwA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826500 )
    assert dictify(obj.payload.x) == snake_case_keys( -7 )
    assert dictify(obj.payload.y) == snake_case_keys( -17 )
    assert dictify(obj.payload.z) == snake_case_keys( 16 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_5():
    buf = base64.standard_b64decode("VQ0C04gU+Pt6E/f////z////DgAAAAAADwC/Kw==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"n_sats": 15, "sender": 35027, "msg_type": 525, "tow": 326827000, "crc": 11199, "length": 20, "flags": 0, "y": -13, "x": -9, "z": 14, "preamble": 85, "payload": "+Pt6E/f////z////DgAAAAAADwA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x2bbf
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x20d
    assert parsed_dict['payload'] == "+Pt6E/f////z////DgAAAAAADwA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326827000 )
    assert dictify(obj.payload.x) == snake_case_keys( -9 )
    assert dictify(obj.payload.y) == snake_case_keys( -13 )
    assert dictify(obj.payload.z) == snake_case_keys( 14 )

    assert parsed_dict == snake_case_keys(orig_dict)