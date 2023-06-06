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
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_iar_state_1():
    buf = base64.standard_b64decode("VRkA9tcEAQAAANiM")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8cd8
    
    assert msg.length == 4
    
    assert msg.msg_type == 0x19
    
    assert msg.payload == "AQAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.num_hyps) == 1

    assert dictify(msg) == {'sender': 55286, 'msg_type': 25, 'num_hyps': 1, 'crc': 36056, 'length': 4, 'preamble': 85, 'payload': 'AQAAAA=='}

def test_auto_check_sbp_piksi_msg_iar_state_2():
    buf = base64.standard_b64decode("VRkAwwQEAAAAABKw")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb012
    
    assert msg.length == 4
    
    assert msg.msg_type == 0x19
    
    assert msg.payload == "AAAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.num_hyps) == 0

    assert dictify(msg) == {'sender': 1219, 'msg_type': 25, 'num_hyps': 0, 'crc': 45074, 'length': 4, 'preamble': 85, 'payload': 'AAAAAA=='}

def test_auto_check_sbp_piksi_msg_iar_state_3():
    buf = base64.standard_b64decode("VRkAwwQEAQAAAKbG")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc6a6
    
    assert msg.length == 4
    
    assert msg.msg_type == 0x19
    
    assert msg.payload == "AQAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.num_hyps) == 1

    assert dictify(msg) == {'sender': 1219, 'msg_type': 25, 'num_hyps': 1, 'crc': 50854, 'length': 4, 'preamble': 85, 'payload': 'AQAAAA=='}

def test_auto_check_sbp_piksi_msg_iar_state_4():
    buf = base64.standard_b64decode("VRkAwwQE2QIAAAaF")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8506
    
    assert msg.length == 4
    
    assert msg.msg_type == 0x19
    
    assert msg.payload == "2QIAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.num_hyps) == 729

    assert dictify(msg) == {'sender': 1219, 'msg_type': 25, 'num_hyps': 729, 'crc': 34054, 'length': 4, 'preamble': 85, 'payload': '2QIAAA=='}

def test_auto_check_sbp_piksi_msg_iar_state_5():
    buf = base64.standard_b64decode("VRkAwwQE2AIAALLz")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf3b2
    
    assert msg.length == 4
    
    assert msg.msg_type == 0x19
    
    assert msg.payload == "2AIAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.num_hyps) == 728

    assert dictify(msg) == {'sender': 1219, 'msg_type': 25, 'num_hyps': 728, 'crc': 62386, 'length': 4, 'preamble': 85, 'payload': '2AIAAA=='}

def test_auto_check_sbp_piksi_msg_iar_state_6():
    buf = base64.standard_b64decode("VRkAwwQE1wIAAFwn")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x275c
    
    assert msg.length == 4
    
    assert msg.msg_type == 0x19
    
    assert msg.payload == "1wIAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.num_hyps) == 727

    assert dictify(msg) == {'sender': 1219, 'msg_type': 25, 'num_hyps': 727, 'crc': 10076, 'length': 4, 'preamble': 85, 'payload': '1wIAAA=='}

def test_auto_check_sbp_piksi_msg_iar_state_7():
    buf = base64.standard_b64decode("VRkAwwQE0wIAAK3t")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xedad
    
    assert msg.length == 4
    
    assert msg.msg_type == 0x19
    
    assert msg.payload == "0wIAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.num_hyps) == 723

    assert dictify(msg) == {'sender': 1219, 'msg_type': 25, 'num_hyps': 723, 'crc': 60845, 'length': 4, 'preamble': 85, 'payload': '0wIAAA=='}