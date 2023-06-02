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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_group_meta_1():
    buf = base64.standard_b64decode("VQr/7u4JAQIDCv8KAgL/Ag4=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"crc": 3586, "flags": 2, "group_id": 1, "sender": 61166, "msg_type": 65290, "length": 9, "n_group_msgs": 3 ,"group_msgs": [65290, 522, 65282], "preamble": 85, "payload": "AQIDCv8KAgL/"}
    assert parsed_dict['crc'] == 0xe02
    assert parsed_dict['length'] == 9
    assert parsed_dict['msg_type'] == 0xFF0A
    assert parsed_dict['payload'] == "AQIDCv8KAgL/"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xEEEE
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.group_id) == snake_case_keys( 1 )
    assert dictify(obj.payload.group_msgs) == snake_case_keys( [65290, 522, 65282] )
    assert dictify(obj.payload.n_group_msgs) == snake_case_keys( 3 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_system_msg_group_meta_2():
    buf = base64.standard_b64decode("VQr/FQMfAQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/1Ka")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"group_id":1,"flags":1,"n_group_msgs":14,"group_msgs":[258,259,522,529,521,532,526,530,525,533,545,65283,65286,65294],"preamble":85,"msg_type":65290,"sender":789,"payload":"AQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/w==","crc":39506,"length":31}
    assert parsed_dict['crc'] == 0x9a52
    assert parsed_dict['length'] == 31
    assert parsed_dict['payload'] == "AQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/w=="
    assert parsed_dict['msg_type'] == 0xFF0A
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x315
    assert dictify(obj.payload.flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.group_id) == snake_case_keys( 1 )
    assert dictify(obj.payload.group_msgs) == snake_case_keys( [258, 259, 522, 529, 521, 532, 526, 530, 525, 533, 545, 65283, 65286, 65294] )
    assert dictify(obj.payload.n_group_msgs) == snake_case_keys( 14 )

    assert parsed_dict == snake_case_keys(orig_dict)