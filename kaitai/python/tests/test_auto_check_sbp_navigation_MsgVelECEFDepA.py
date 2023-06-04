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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_1():
    buf = base64.standard_b64decode("VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xec50
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "FC4nANoLAACG9f//o/z//wAACQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567700
    
    assert dictify(msg.x) == 3034
    
    assert dictify(msg.y) == -2682
    
    assert dictify(msg.z) == -861

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 516, 'tow': 2567700, 'crc': 60496, 'length': 20, 'flags': 0, 'y': -2682, 'x': 3034, 'z': -861, 'preamble': 85, 'payload': 'FC4nANoLAACG9f//o/z//wAACQA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_2():
    buf = base64.standard_b64decode("VQQC9tcUeC4nAEQLAAAY9v//3Pz//wAACQD4ig==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8af8
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "eC4nAEQLAAAY9v//3Pz//wAACQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567800
    
    assert dictify(msg.x) == 2884
    
    assert dictify(msg.y) == -2536
    
    assert dictify(msg.z) == -804

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 516, 'tow': 2567800, 'crc': 35576, 'length': 20, 'flags': 0, 'y': -2536, 'x': 2884, 'z': -804, 'preamble': 85, 'payload': 'eC4nAEQLAAAY9v//3Pz//wAACQA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_3():
    buf = base64.standard_b64decode("VQQC9tcU3C4nABULAABN9v//9/z//wAACQAZrg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xae19
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "3C4nABULAABN9v//9/z//wAACQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567900
    
    assert dictify(msg.x) == 2837
    
    assert dictify(msg.y) == -2483
    
    assert dictify(msg.z) == -777

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 516, 'tow': 2567900, 'crc': 44569, 'length': 20, 'flags': 0, 'y': -2483, 'x': 2837, 'z': -777, 'preamble': 85, 'payload': '3C4nABULAABN9v//9/z//wAACQA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_4():
    buf = base64.standard_b64decode("VQQC9tcUQC8nAHkLAAAC9v//6vz//wAACQDD5A==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe4c3
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "QC8nAHkLAAAC9v//6vz//wAACQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2568000
    
    assert dictify(msg.x) == 2937
    
    assert dictify(msg.y) == -2558
    
    assert dictify(msg.z) == -790

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 516, 'tow': 2568000, 'crc': 58563, 'length': 20, 'flags': 0, 'y': -2558, 'x': 2937, 'z': -790, 'preamble': 85, 'payload': 'QC8nAHkLAAAC9v//6vz//wAACQA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_5():
    buf = base64.standard_b64decode("VQQC9tcUpC8nAB8LAABd9v//EP3//wAACQDbpA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa4db
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "pC8nAB8LAABd9v//EP3//wAACQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2568100
    
    assert dictify(msg.x) == 2847
    
    assert dictify(msg.y) == -2467
    
    assert dictify(msg.z) == -752

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 516, 'tow': 2568100, 'crc': 42203, 'length': 20, 'flags': 0, 'y': -2467, 'x': 2847, 'z': -752, 'preamble': 85, 'payload': 'pC8nAB8LAABd9v//EP3//wAACQA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_6():
    buf = base64.standard_b64decode("VQQCwwQU1J1DGBgAAAD1////2////wAACABE/w==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xff44
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "1J1DGBgAAAD1////2////wAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084500
    
    assert dictify(msg.x) == 24
    
    assert dictify(msg.y) == -11
    
    assert dictify(msg.z) == -37

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 516, 'tow': 407084500, 'crc': 65348, 'length': 20, 'flags': 0, 'y': -11, 'x': 24, 'z': -37, 'preamble': 85, 'payload': '1J1DGBgAAAD1////2////wAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_7():
    buf = base64.standard_b64decode("VQQCwwQUOJ5DGAQAAADq////EgAAAAAACADWiA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x88d6
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "OJ5DGAQAAADq////EgAAAAAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084600
    
    assert dictify(msg.x) == 4
    
    assert dictify(msg.y) == -22
    
    assert dictify(msg.z) == 18

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 516, 'tow': 407084600, 'crc': 35030, 'length': 20, 'flags': 0, 'y': -22, 'x': 4, 'z': 18, 'preamble': 85, 'payload': 'OJ5DGAQAAADq////EgAAAAAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_8():
    buf = base64.standard_b64decode("VQQCwwQUnJ5DGOb///8EAAAAAQAAAAAACAB6nw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9f7a
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "nJ5DGOb///8EAAAAAQAAAAAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084700
    
    assert dictify(msg.x) == -26
    
    assert dictify(msg.y) == 4
    
    assert dictify(msg.z) == 1

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 516, 'tow': 407084700, 'crc': 40826, 'length': 20, 'flags': 0, 'y': 4, 'x': -26, 'z': 1, 'preamble': 85, 'payload': 'nJ5DGOb///8EAAAAAQAAAAAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_9():
    buf = base64.standard_b64decode("VQQCwwQUAJ9DGPf////t////HAAAAAAACADokg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x92e8
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "AJ9DGPf////t////HAAAAAAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084800
    
    assert dictify(msg.x) == -9
    
    assert dictify(msg.y) == -19
    
    assert dictify(msg.z) == 28

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 516, 'tow': 407084800, 'crc': 37608, 'length': 20, 'flags': 0, 'y': -19, 'x': -9, 'z': 28, 'preamble': 85, 'payload': 'AJ9DGPf////t////HAAAAAAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_10():
    buf = base64.standard_b64decode("VQQCwwQUZJ9DGP////8CAAAA9f///wAACACr7g==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xeeab
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "ZJ9DGP////8CAAAA9f///wAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084900
    
    assert dictify(msg.x) == -1
    
    assert dictify(msg.y) == 2
    
    assert dictify(msg.z) == -11

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 516, 'tow': 407084900, 'crc': 61099, 'length': 20, 'flags': 0, 'y': 2, 'x': -1, 'z': -11, 'preamble': 85, 'payload': 'ZJ9DGP////8CAAAA9f///wAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_11():
    buf = base64.standard_b64decode("VQQCwwQULqJEGM////+5////QQAAAAAABQBSmg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9a52
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x204
    
    assert msg.payload == "LqJEGM////+5////QQAAAAAABQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 5
    
    assert dictify(msg.tow) == 407151150
    
    assert dictify(msg.x) == -49
    
    assert dictify(msg.y) == -71
    
    assert dictify(msg.z) == 65

    assert dictify(msg) == {'n_sats': 5, 'sender': 1219, 'msg_type': 516, 'tow': 407151150, 'crc': 39506, 'length': 20, 'flags': 0, 'y': -71, 'x': -49, 'z': 65, 'preamble': 85, 'payload': 'LqJEGM////+5////QQAAAAAABQA=', 'accuracy': 0}