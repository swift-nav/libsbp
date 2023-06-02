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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_ecef_1():
    buf = base64.standard_b64decode("VQkC04ggEPh6E0kdLoS2ekTB28AdsHl3UMFTC9JaT0tNQQAADwJUBg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"n_sats": 15, "sender": 35027, "msg_type": 521, "tow": 326826000, "crc": 1620, "length": 32, "flags": 2, "y": -4316646.751816, "x": -2684269.0326572997, "z": 3839646.7095350414, "preamble": 85, "payload": "EPh6E0kdLoS2ekTB28AdsHl3UMFTC9JaT0tNQQAADwI=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x654
    assert parsed_dict['length'] == 32
    assert parsed_dict['msg_type'] == 0x209
    assert parsed_dict['payload'] == "EPh6E0kdLoS2ekTB28AdsHl3UMFTC9JaT0tNQQAADwI="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826000 )
    assert dictify(obj.payload.x) == snake_case_keys( -2684269.0326572997 )
    assert dictify(obj.payload.y) == snake_case_keys( -4316646.751816 )
    assert dictify(obj.payload.z) == snake_case_keys( 3839646.7095350414 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_pos_ecef_2():
    buf = base64.standard_b64decode("VQkC04gg+Pt6E2dqOYi2ekTBsPLIsHl3UMH0h2E7T0tNQQAADwKT2A==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"n_sats": 15, "sender": 35027, "msg_type": 521, "tow": 326827000, "crc": 55443, "length": 32, "flags": 2, "y": -4316646.762264892, "x": -2684269.064252186, "z": 3839646.463913912, "preamble": 85, "payload": "+Pt6E2dqOYi2ekTBsPLIsHl3UMH0h2E7T0tNQQAADwI=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xd893
    assert parsed_dict['length'] == 32
    assert parsed_dict['msg_type'] == 0x209
    assert parsed_dict['payload'] == "+Pt6E2dqOYi2ekTBsPLIsHl3UMH0h2E7T0tNQQAADwI="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326827000 )
    assert dictify(obj.payload.x) == snake_case_keys( -2684269.064252186 )
    assert dictify(obj.payload.y) == snake_case_keys( -4316646.762264892 )
    assert dictify(obj.payload.z) == snake_case_keys( 3839646.463913912 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_pos_ecef_3():
    buf = base64.standard_b64decode("VQkC04gg4P96E2Wz8ra2ekTBgsSRx3l3UMHUCv0PT0tNQQAADwIoyQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"n_sats": 15, "sender": 35027, "msg_type": 521, "tow": 326828000, "crc": 51496, "length": 32, "flags": 2, "y": -4316647.118271949, "x": -2684269.4292816394, "z": 3839646.124909738, "preamble": 85, "payload": "4P96E2Wz8ra2ekTBgsSRx3l3UMHUCv0PT0tNQQAADwI=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xc928
    assert parsed_dict['length'] == 32
    assert parsed_dict['msg_type'] == 0x209
    assert parsed_dict['payload'] == "4P96E2Wz8ra2ekTBgsSRx3l3UMHUCv0PT0tNQQAADwI="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326828000 )
    assert dictify(obj.payload.x) == snake_case_keys( -2684269.4292816394 )
    assert dictify(obj.payload.y) == snake_case_keys( -4316647.118271949 )
    assert dictify(obj.payload.z) == snake_case_keys( 3839646.124909738 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_pos_ecef_4():
    buf = base64.standard_b64decode("VQkC04ggyAN7E5LWhNe2ekTB1UQx13l3UMFHIm7zTktNQQAADwK7Vg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"n_sats": 15, "sender": 35027, "msg_type": 521, "tow": 326829000, "crc": 22203, "length": 32, "flags": 2, "y": -4316647.3623821335, "x": -2684269.683741399, "z": 3839645.90179852, "preamble": 85, "payload": "yAN7E5LWhNe2ekTB1UQx13l3UMFHIm7zTktNQQAADwI=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x56bb
    assert parsed_dict['length'] == 32
    assert parsed_dict['msg_type'] == 0x209
    assert parsed_dict['payload'] == "yAN7E5LWhNe2ekTB1UQx13l3UMFHIm7zTktNQQAADwI="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326829000 )
    assert dictify(obj.payload.x) == snake_case_keys( -2684269.683741399 )
    assert dictify(obj.payload.y) == snake_case_keys( -4316647.3623821335 )
    assert dictify(obj.payload.z) == snake_case_keys( 3839645.90179852 )

    assert parsed_dict == snake_case_keys(orig_dict)