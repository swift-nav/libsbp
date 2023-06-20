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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_1():
    buf = base64.standard_b64decode("VRUAwwQNAABoQQDANUTGxwBGCAJE")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4402
    
    assert msg.length == 13
    
    assert msg.msg_type == 0x15
    
    assert msg.payload == "AABoQQDANUTGxwBGCA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cf) == 8241.943359375
    
    assert dictify(msg.cp) == 727.0
    
    assert dictify(msg.prn) == 8
    
    assert dictify(msg.snr) == 14.5

    assert dictify(msg) == {'sender': 1219, 'msg_type': 21, 'prn': 8, 'cf': 8241.943359375, 'crc': 17410, 'length': 13, 'snr': 14.5, 'cp': 727.0, 'preamble': 85, 'payload': 'AABoQQDANUTGxwBGCA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_2():
    buf = base64.standard_b64decode("VRUAwwQNzcx0QQDAs0MhUTtECdsb")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1bdb
    
    assert msg.length == 13
    
    assert msg.msg_type == 0x15
    
    assert msg.payload == "zcx0QQDAs0MhUTtECQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cf) == 749.2676391601562
    
    assert dictify(msg.cp) == 359.5
    
    assert dictify(msg.prn) == 9
    
    assert dictify(msg.snr) == 15.300000190734863

    assert dictify(msg) == {'sender': 1219, 'msg_type': 21, 'prn': 9, 'cf': 749.2676391601562, 'crc': 7131, 'length': 13, 'snr': 15.300000190734863, 'cp': 359.5, 'preamble': 85, 'payload': 'zcx0QQDAs0MhUTtECQ=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_3():
    buf = base64.standard_b64decode("VRUAwwQNzcyQQQAAIkI57crFC5Yj")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2396
    
    assert msg.length == 13
    
    assert msg.msg_type == 0x15
    
    assert msg.payload == "zcyQQQAAIkI57crFCw=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cf) == -6493.65283203125
    
    assert dictify(msg.cp) == 40.5
    
    assert dictify(msg.prn) == 11
    
    assert dictify(msg.snr) == 18.100000381469727

    assert dictify(msg) == {'sender': 1219, 'msg_type': 21, 'prn': 11, 'cf': -6493.65283203125, 'crc': 9110, 'length': 13, 'snr': 18.100000381469727, 'cp': 40.5, 'preamble': 85, 'payload': 'zcyQQQAAIkI57crFCw=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_4():
    buf = base64.standard_b64decode("VRUAwwQNzcx0QQAgCUSBwXnEDJJ2")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7692
    
    assert msg.length == 13
    
    assert msg.msg_type == 0x15
    
    assert msg.payload == "zcx0QQAgCUSBwXnEDA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cf) == -999.0234985351562
    
    assert dictify(msg.cp) == 548.5
    
    assert dictify(msg.prn) == 12
    
    assert dictify(msg.snr) == 15.300000190734863

    assert dictify(msg) == {'sender': 1219, 'msg_type': 21, 'prn': 12, 'cf': -999.0234985351562, 'crc': 30354, 'length': 13, 'snr': 15.300000190734863, 'cp': 548.5, 'preamble': 85, 'payload': 'zcx0QQAgCUSBwXnEDA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_5():
    buf = base64.standard_b64decode("VRUAwwQNzcx0QQAgQ0TkSpRFDhdL")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4b17
    
    assert msg.length == 13
    
    assert msg.msg_type == 0x15
    
    assert msg.payload == "zcx0QQAgQ0TkSpRFDg=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cf) == 4745.361328125
    
    assert dictify(msg.cp) == 780.5
    
    assert dictify(msg.prn) == 14
    
    assert dictify(msg.snr) == 15.300000190734863

    assert dictify(msg) == {'sender': 1219, 'msg_type': 21, 'prn': 14, 'cf': 4745.361328125, 'crc': 19223, 'length': 13, 'snr': 15.300000190734863, 'cp': 780.5, 'preamble': 85, 'payload': 'zcx0QQAgQ0TkSpRFDg=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_6():
    buf = base64.standard_b64decode("VRUAwwQN5DgjQwAgEkSBwfnDAMzP")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xcfcc
    
    assert msg.length == 13
    
    assert msg.msg_type == 0x15
    
    assert msg.payload == "5DgjQwAgEkSBwfnDAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cf) == -499.5117492675781
    
    assert dictify(msg.cp) == 584.5
    
    assert dictify(msg.prn) == 0
    
    assert dictify(msg.snr) == 163.22222900390625

    assert dictify(msg) == {'sender': 1219, 'msg_type': 21, 'prn': 0, 'cf': -499.5117492675781, 'crc': 53196, 'length': 13, 'snr': 163.22222900390625, 'cp': 584.5, 'preamble': 85, 'payload': '5DgjQwAgEkSBwfnDAA=='}