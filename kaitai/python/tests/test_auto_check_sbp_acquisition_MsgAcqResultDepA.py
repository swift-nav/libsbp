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

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_1():
    buf = base64.standard_b64decode("VRUAwwQNAABoQQDANUTGxwBGCAJE")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 1219, "msg_type": 21, "prn": 8, "cf": 8241.943359375, "crc": 17410, "length": 13, "snr": 14.5, "cp": 727.0, "preamble": 85, "payload": "AABoQQDANUTGxwBGCA=="}
    assert parsed_dict['crc'] == 0x4402
    assert parsed_dict['length'] == 13
    assert parsed_dict['msg_type'] == 0x15
    assert parsed_dict['payload'] == "AABoQQDANUTGxwBGCA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.cf) == snake_case_keys( 8241.943359375 )
    assert dictify(obj.payload.cp) == snake_case_keys( 727.0 )
    assert dictify(obj.payload.prn) == snake_case_keys( 8 )
    assert dictify(obj.payload.snr) == snake_case_keys( 14.5 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_2():
    buf = base64.standard_b64decode("VRUAwwQNzcx0QQDAs0MhUTtECdsb")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 1219, "msg_type": 21, "prn": 9, "cf": 749.2676391601562, "crc": 7131, "length": 13, "snr": 15.300000190734863, "cp": 359.5, "preamble": 85, "payload": "zcx0QQDAs0MhUTtECQ=="}
    assert parsed_dict['crc'] == 0x1bdb
    assert parsed_dict['length'] == 13
    assert parsed_dict['msg_type'] == 0x15
    assert parsed_dict['payload'] == "zcx0QQDAs0MhUTtECQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.cf) == snake_case_keys( 749.2676391601562 )
    assert dictify(obj.payload.cp) == snake_case_keys( 359.5 )
    assert dictify(obj.payload.prn) == snake_case_keys( 9 )
    assert dictify(obj.payload.snr) == snake_case_keys( 15.300000190734863 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_3():
    buf = base64.standard_b64decode("VRUAwwQNzcyQQQAAIkI57crFC5Yj")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 1219, "msg_type": 21, "prn": 11, "cf": -6493.65283203125, "crc": 9110, "length": 13, "snr": 18.100000381469727, "cp": 40.5, "preamble": 85, "payload": "zcyQQQAAIkI57crFCw=="}
    assert parsed_dict['crc'] == 0x2396
    assert parsed_dict['length'] == 13
    assert parsed_dict['msg_type'] == 0x15
    assert parsed_dict['payload'] == "zcyQQQAAIkI57crFCw=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.cf) == snake_case_keys( -6493.65283203125 )
    assert dictify(obj.payload.cp) == snake_case_keys( 40.5 )
    assert dictify(obj.payload.prn) == snake_case_keys( 11 )
    assert dictify(obj.payload.snr) == snake_case_keys( 18.100000381469727 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_4():
    buf = base64.standard_b64decode("VRUAwwQNzcx0QQAgCUSBwXnEDJJ2")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 1219, "msg_type": 21, "prn": 12, "cf": -999.0234985351562, "crc": 30354, "length": 13, "snr": 15.300000190734863, "cp": 548.5, "preamble": 85, "payload": "zcx0QQAgCUSBwXnEDA=="}
    assert parsed_dict['crc'] == 0x7692
    assert parsed_dict['length'] == 13
    assert parsed_dict['msg_type'] == 0x15
    assert parsed_dict['payload'] == "zcx0QQAgCUSBwXnEDA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.cf) == snake_case_keys( -999.0234985351562 )
    assert dictify(obj.payload.cp) == snake_case_keys( 548.5 )
    assert dictify(obj.payload.prn) == snake_case_keys( 12 )
    assert dictify(obj.payload.snr) == snake_case_keys( 15.300000190734863 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_5():
    buf = base64.standard_b64decode("VRUAwwQNzcx0QQAgQ0TkSpRFDhdL")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 1219, "msg_type": 21, "prn": 14, "cf": 4745.361328125, "crc": 19223, "length": 13, "snr": 15.300000190734863, "cp": 780.5, "preamble": 85, "payload": "zcx0QQAgQ0TkSpRFDg=="}
    assert parsed_dict['crc'] == 0x4b17
    assert parsed_dict['length'] == 13
    assert parsed_dict['msg_type'] == 0x15
    assert parsed_dict['payload'] == "zcx0QQAgQ0TkSpRFDg=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.cf) == snake_case_keys( 4745.361328125 )
    assert dictify(obj.payload.cp) == snake_case_keys( 780.5 )
    assert dictify(obj.payload.prn) == snake_case_keys( 14 )
    assert dictify(obj.payload.snr) == snake_case_keys( 15.300000190734863 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_acquisition_msg_acq_result_dep_a_6():
    buf = base64.standard_b64decode("VRUAwwQN5DgjQwAgEkSBwfnDAMzP")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 1219, "msg_type": 21, "prn": 0, "cf": -499.5117492675781, "crc": 53196, "length": 13, "snr": 163.22222900390625, "cp": 584.5, "preamble": 85, "payload": "5DgjQwAgEkSBwfnDAA=="}
    assert parsed_dict['crc'] == 0xcfcc
    assert parsed_dict['length'] == 13
    assert parsed_dict['msg_type'] == 0x15
    assert parsed_dict['payload'] == "5DgjQwAgEkSBwfnDAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.cf) == snake_case_keys( -499.5117492675781 )
    assert dictify(obj.payload.cp) == snake_case_keys( 584.5 )
    assert dictify(obj.payload.prn) == snake_case_keys( 0 )
    assert dictify(obj.payload.snr) == snake_case_keys( 163.22222900390625 )

    assert parsed_dict == snake_case_keys(orig_dict)