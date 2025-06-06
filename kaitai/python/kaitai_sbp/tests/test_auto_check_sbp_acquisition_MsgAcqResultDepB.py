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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepB.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_acquisition_msg_acq_result_dep_b_1():
    buf = base64.standard_b64decode("VRQA9tcQiacSQgAAoUPwGJxFCQAAAFDD")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc350
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x14
    
    assert msg.payload == "iacSQgAAoUPwGJxFCQAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cf) == 4995.1171875
    
    assert dictify(msg.cp) == 322.0
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 9}
    
    assert dictify(msg.snr) == 36.66360855102539

    assert dictify(msg) == {'sender': 55286, 'msg_type': 20, 'cf': 4995.1171875, 'crc': 50000, 'length': 16, 'snr': 36.66360855102539, 'sid': {'code': 0, 'reserved': 0, 'sat': 9}, 'cp': 322.0, 'preamble': 85, 'payload': 'iacSQgAAoUPwGJxFCQAAAA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_b_2():
    buf = base64.standard_b64decode("VRQA9tcQzqwQQgDAUkTGxwDGAwAAAJWP")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8f95
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x14
    
    assert msg.payload == "zqwQQgDAUkTGxwDGAwAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cf) == -8241.943359375
    
    assert dictify(msg.cp) == 843.0
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 3}
    
    assert dictify(msg.snr) == 36.16875457763672

    assert dictify(msg) == {'sender': 55286, 'msg_type': 20, 'cf': -8241.943359375, 'crc': 36757, 'length': 16, 'snr': 36.16875457763672, 'sid': {'code': 0, 'reserved': 0, 'sat': 3}, 'cp': 843.0, 'preamble': 85, 'payload': 'zqwQQgDAUkTGxwDGAwAAAA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_b_3():
    buf = base64.standard_b64decode("VRQA9tcQ5BsPQgCARkTkSpRFEgAAALOb")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9bb3
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x14
    
    assert msg.payload == "5BsPQgCARkTkSpRFEgAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cf) == 4745.361328125
    
    assert dictify(msg.cp) == 794.0
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 18}
    
    assert dictify(msg.snr) == 35.77723693847656

    assert dictify(msg) == {'sender': 55286, 'msg_type': 20, 'cf': 4745.361328125, 'crc': 39859, 'length': 16, 'snr': 35.77723693847656, 'sid': {'code': 0, 'reserved': 0, 'sat': 18}, 'cp': 794.0, 'preamble': 85, 'payload': '5BsPQgCARkTkSpRFEgAAAA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_b_4():
    buf = base64.standard_b64decode("VRQA9tcQLscOQgBAgUPwGBxFEQAAABK1")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb512
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x14
    
    assert msg.payload == "LscOQgBAgUPwGBxFEQAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cf) == 2497.55859375
    
    assert dictify(msg.cp) == 258.5
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 17}
    
    assert dictify(msg.snr) == 35.69451141357422

    assert dictify(msg) == {'sender': 55286, 'msg_type': 20, 'cf': 2497.55859375, 'crc': 46354, 'length': 16, 'snr': 35.69451141357422, 'sid': {'code': 0, 'reserved': 0, 'sat': 17}, 'cp': 258.5, 'preamble': 85, 'payload': 'LscOQgBAgUPwGBxFEQAAAA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_b_5():
    buf = base64.standard_b64decode("VRQA9tcQwhgOQgCAAkSBwfnDBQAAACPL")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xcb23
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x14
    
    assert msg.payload == "whgOQgCAAkSBwfnDBQAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cf) == -499.5117492675781
    
    assert dictify(msg.cp) == 522.0
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 5}
    
    assert dictify(msg.snr) == 35.52417755126953

    assert dictify(msg) == {'sender': 55286, 'msg_type': 20, 'cf': -499.5117492675781, 'crc': 52003, 'length': 16, 'snr': 35.52417755126953, 'sid': {'code': 0, 'reserved': 0, 'sat': 5}, 'cp': 522.0, 'preamble': 85, 'payload': 'whgOQgCAAkSBwfnDBQAAAA=='}
