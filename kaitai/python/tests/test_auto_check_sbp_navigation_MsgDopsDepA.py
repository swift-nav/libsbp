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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDopsDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_dops_dep_a_1():
    buf = base64.standard_b64decode("VQYC9tcOCDAnALQAvgCqAKAAlgB5qg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xaa79
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x206
    
    assert msg.payload == "CDAnALQAvgCqAKAAlgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.gdop) == 180
    
    assert dictify(msg.hdop) == 160
    
    assert dictify(msg.pdop) == 190
    
    assert dictify(msg.tdop) == 170
    
    assert dictify(msg.tow) == 2568200
    
    assert dictify(msg.vdop) == 150

    assert dictify(msg) == {'gdop': 180, 'tdop': 170, 'vdop': 150, 'sender': 55286, 'msg_type': 518, 'pdop': 190, 'tow': 2568200, 'crc': 43641, 'length': 14, 'preamble': 85, 'payload': 'CDAnALQAvgCqAKAAlgA=', 'hdop': 160}

def test_auto_check_sbp_navigation_msg_dops_dep_a_2():
    buf = base64.standard_b64decode("VQYC9tcO8DMnALQAvgCqAKAAlgBOqQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa94e
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x206
    
    assert msg.payload == "8DMnALQAvgCqAKAAlgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.gdop) == 180
    
    assert dictify(msg.hdop) == 160
    
    assert dictify(msg.pdop) == 190
    
    assert dictify(msg.tdop) == 170
    
    assert dictify(msg.tow) == 2569200
    
    assert dictify(msg.vdop) == 150

    assert dictify(msg) == {'gdop': 180, 'tdop': 170, 'vdop': 150, 'sender': 55286, 'msg_type': 518, 'pdop': 190, 'tow': 2569200, 'crc': 43342, 'length': 14, 'preamble': 85, 'payload': '8DMnALQAvgCqAKAAlgA=', 'hdop': 160}

def test_auto_check_sbp_navigation_msg_dops_dep_a_3():
    buf = base64.standard_b64decode("VQYC9tcO2DcnALQAvgCqAKAAlgBH2g==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xda47
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x206
    
    assert msg.payload == "2DcnALQAvgCqAKAAlgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.gdop) == 180
    
    assert dictify(msg.hdop) == 160
    
    assert dictify(msg.pdop) == 190
    
    assert dictify(msg.tdop) == 170
    
    assert dictify(msg.tow) == 2570200
    
    assert dictify(msg.vdop) == 150

    assert dictify(msg) == {'gdop': 180, 'tdop': 170, 'vdop': 150, 'sender': 55286, 'msg_type': 518, 'pdop': 190, 'tow': 2570200, 'crc': 55879, 'length': 14, 'preamble': 85, 'payload': '2DcnALQAvgCqAKAAlgA=', 'hdop': 160}

def test_auto_check_sbp_navigation_msg_dops_dep_a_4():
    buf = base64.standard_b64decode("VQYCwwQO1J1DGPcA1wB7ABEBLADOFQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x15ce
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x206
    
    assert msg.payload == "1J1DGPcA1wB7ABEBLAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.gdop) == 247
    
    assert dictify(msg.hdop) == 273
    
    assert dictify(msg.pdop) == 215
    
    assert dictify(msg.tdop) == 123
    
    assert dictify(msg.tow) == 407084500
    
    assert dictify(msg.vdop) == 44

    assert dictify(msg) == {'gdop': 247, 'tdop': 123, 'vdop': 44, 'sender': 1219, 'msg_type': 518, 'tow': 407084500, 'pdop': 215, 'crc': 5582, 'length': 14, 'preamble': 85, 'payload': '1J1DGPcA1wB7ABEBLAA=', 'hdop': 273}

def test_auto_check_sbp_navigation_msg_dops_dep_a_5():
    buf = base64.standard_b64decode("VQYCwwQOAAAAAP////8AAAAAAACSDA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc92
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x206
    
    assert msg.payload == "AAAAAP////8AAAAAAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.gdop) == 65535
    
    assert dictify(msg.hdop) == 0
    
    assert dictify(msg.pdop) == 65535
    
    assert dictify(msg.tdop) == 0
    
    assert dictify(msg.tow) == 0
    
    assert dictify(msg.vdop) == 0

    assert dictify(msg) == {'gdop': 65535, 'tdop': 0, 'vdop': 0, 'sender': 1219, 'msg_type': 518, 'tow': 0, 'pdop': 65535, 'crc': 3218, 'length': 14, 'preamble': 85, 'payload': 'AAAAAP////8AAAAAAAA=', 'hdop': 0}

def test_auto_check_sbp_navigation_msg_dops_dep_a_6():
    buf = base64.standard_b64decode("VQYCwwQOgKVEGFwBOAGbAH0CcQCBXQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5d81
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x206
    
    assert msg.payload == "gKVEGFwBOAGbAH0CcQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.gdop) == 348
    
    assert dictify(msg.hdop) == 637
    
    assert dictify(msg.pdop) == 312
    
    assert dictify(msg.tdop) == 155
    
    assert dictify(msg.tow) == 407152000
    
    assert dictify(msg.vdop) == 113

    assert dictify(msg) == {'gdop': 348, 'tdop': 155, 'vdop': 113, 'sender': 1219, 'msg_type': 518, 'tow': 407152000, 'pdop': 312, 'crc': 23937, 'length': 14, 'preamble': 85, 'payload': 'gKVEGFwBOAGbAH0CcQA=', 'hdop': 637}

def test_auto_check_sbp_navigation_msg_dops_dep_a_7():
    buf = base64.standard_b64decode("VQYCwwQOaKlEGFwBNwGbAH0CcQDRgA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x80d1
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x206
    
    assert msg.payload == "aKlEGFwBNwGbAH0CcQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.gdop) == 348
    
    assert dictify(msg.hdop) == 637
    
    assert dictify(msg.pdop) == 311
    
    assert dictify(msg.tdop) == 155
    
    assert dictify(msg.tow) == 407153000
    
    assert dictify(msg.vdop) == 113

    assert dictify(msg) == {'gdop': 348, 'tdop': 155, 'vdop': 113, 'sender': 1219, 'msg_type': 518, 'tow': 407153000, 'pdop': 311, 'crc': 32977, 'length': 14, 'preamble': 85, 'payload': 'aKlEGFwBNwGbAH0CcQA=', 'hdop': 637}

def test_auto_check_sbp_navigation_msg_dops_dep_a_8():
    buf = base64.standard_b64decode("VQYCwwQOUK1EGFwBNwGbAH0CcAAeBg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x61e
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x206
    
    assert msg.payload == "UK1EGFwBNwGbAH0CcAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.gdop) == 348
    
    assert dictify(msg.hdop) == 637
    
    assert dictify(msg.pdop) == 311
    
    assert dictify(msg.tdop) == 155
    
    assert dictify(msg.tow) == 407154000
    
    assert dictify(msg.vdop) == 112

    assert dictify(msg) == {'gdop': 348, 'tdop': 155, 'vdop': 112, 'sender': 1219, 'msg_type': 518, 'tow': 407154000, 'pdop': 311, 'crc': 1566, 'length': 14, 'preamble': 85, 'payload': 'UK1EGFwBNwGbAH0CcAA=', 'hdop': 637}

def test_auto_check_sbp_navigation_msg_dops_dep_a_9():
    buf = base64.standard_b64decode("VQYCwwQOOLFEGFwBNwGbAH0CcABGQw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4346
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x206
    
    assert msg.payload == "OLFEGFwBNwGbAH0CcAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.gdop) == 348
    
    assert dictify(msg.hdop) == 637
    
    assert dictify(msg.pdop) == 311
    
    assert dictify(msg.tdop) == 155
    
    assert dictify(msg.tow) == 407155000
    
    assert dictify(msg.vdop) == 112

    assert dictify(msg) == {'gdop': 348, 'tdop': 155, 'vdop': 112, 'sender': 1219, 'msg_type': 518, 'tow': 407155000, 'pdop': 311, 'crc': 17222, 'length': 14, 'preamble': 85, 'payload': 'OLFEGFwBNwGbAH0CcAA=', 'hdop': 637}