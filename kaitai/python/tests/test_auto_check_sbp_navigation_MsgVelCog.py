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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelCog.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_cog_1():
    buf = base64.standard_b64decode("VRwC04geMPZ6E+gDAADQBwAAuAsAAKAPAACIEwAAcBcAAD4A1ME=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"crc":49620,"length":30,"msg_type":540,"payload": "MPZ6E+gDAADQBwAAuAsAAKAPAACIEwAAcBcAAD4A","preamble":85,"sender":35027, "tow":326825520,"cog":1000,"sog":2000,"v_up":3000,"cog_accuracy":4000, "sog_accuracy":5000,"v_up_accuracy":6000,"flags":62}
    assert parsed_dict['crc'] == 0xC1D4
    assert parsed_dict['length'] == 30
    assert parsed_dict['msg_type'] == 0x21C
    assert parsed_dict['payload'] == "MPZ6E+gDAADQBwAAuAsAAKAPAACIEwAAcBcAAD4A"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88D3
    assert dictify(obj.payload.cog) == snake_case_keys( 1000 )
    assert dictify(obj.payload.cog_accuracy) == snake_case_keys( 4000 )
    assert dictify(obj.payload.flags) == snake_case_keys( 62 )
    assert dictify(obj.payload.sog) == snake_case_keys( 2000 )
    assert dictify(obj.payload.sog_accuracy) == snake_case_keys( 5000 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825520 )
    assert dictify(obj.payload.v_up) == snake_case_keys( 3000 )
    assert dictify(obj.payload.v_up_accuracy) == snake_case_keys( 6000 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_cog_2():
    buf = base64.standard_b64decode("VRwC04geMPZ6E3sAAADIAQAAGPz//wCVugpkAAAAZAAAAAAAWnI=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"crc":29274,"length":30,"msg_type":540,"payload": "MPZ6E3sAAADIAQAAGPz//wCVugpkAAAAZAAAAAAA","preamble":85,"sender":35027, "tow":326825520,"cog":123,"sog":456,"v_up":-1000,"cog_accuracy":180000000, "sog_accuracy":100,"v_up_accuracy":100,"flags":0}
    assert parsed_dict['crc'] == 0x725A
    assert parsed_dict['length'] == 30
    assert parsed_dict['msg_type'] == 0x21C
    assert parsed_dict['payload'] == "MPZ6E3sAAADIAQAAGPz//wCVugpkAAAAZAAAAAAA"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88D3
    assert dictify(obj.payload.cog) == snake_case_keys( 123 )
    assert dictify(obj.payload.cog_accuracy) == snake_case_keys( 180000000 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.sog) == snake_case_keys( 456 )
    assert dictify(obj.payload.sog_accuracy) == snake_case_keys( 100 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825520 )
    assert dictify(obj.payload.v_up) == snake_case_keys( -1000 )
    assert dictify(obj.payload.v_up_accuracy) == snake_case_keys( 100 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_cog_3():
    buf = base64.standard_b64decode("VRwC04geMPZ6EwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAKtI=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"crc":53802,"length":30,"msg_type":540,"payload": "MPZ6EwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","preamble":85,"sender":35027, "tow":326825520,"cog":0,"sog":0,"v_up":0,"cog_accuracy":0,"sog_accuracy":0, "v_up_accuracy":0,"flags":0}
    assert parsed_dict['crc'] == 0xD22A
    assert parsed_dict['length'] == 30
    assert parsed_dict['msg_type'] == 0x21C
    assert parsed_dict['payload'] == "MPZ6EwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88D3
    assert dictify(obj.payload.cog) == snake_case_keys( 0 )
    assert dictify(obj.payload.cog_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.sog) == snake_case_keys( 0 )
    assert dictify(obj.payload.sog_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825520 )
    assert dictify(obj.payload.v_up) == snake_case_keys( 0 )
    assert dictify(obj.payload.v_up_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)