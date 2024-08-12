# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_group_meta_1():
    buf = base64.standard_b64decode("VQr/7u4JAQIDCv8KAgL/Ag4=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe02
    
    assert msg.length == 9
    
    assert msg.msg_type == 0xFF0A
    
    assert msg.payload == "AQIDCv8KAgL/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xEEEE
    
    assert dictify(msg.flags) == 2
    
    assert dictify(msg.group_id) == 1
    
    assert dictify(msg.group_msgs) == [65290, 522, 65282]
    
    assert dictify(msg.n_group_msgs) == 3

    assert dictify(msg) == {'crc': 3586, 'flags': 2, 'group_id': 1, 'sender': 61166, 'msg_type': 65290, 'length': 9, 'n_group_msgs': 3, 'group_msgs': [65290, 522, 65282], 'preamble': 85, 'payload': 'AQIDCv8KAgL/'}

def test_auto_check_sbp_system_msg_group_meta_2():
    buf = base64.standard_b64decode("VQr/FQMfAQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/1Ka")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9a52
    
    assert msg.length == 31
    
    assert msg.payload == "AQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/w=="
    
    assert msg.msg_type == 0xFF0A
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x315
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.group_id) == 1
    
    assert dictify(msg.group_msgs) == [258, 259, 522, 529, 521, 532, 526, 530, 525, 533, 545, 65283, 65286, 65294]
    
    assert dictify(msg.n_group_msgs) == 14

    assert dictify(msg) == {'group_id': 1, 'flags': 1, 'n_group_msgs': 14, 'group_msgs': [258, 259, 522, 529, 521, 532, 526, 530, 525, 533, 545, 65283, 65286, 65294], 'preamble': 85, 'msg_type': 65290, 'sender': 789, 'payload': 'AQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/w==', 'crc': 39506, 'length': 31}