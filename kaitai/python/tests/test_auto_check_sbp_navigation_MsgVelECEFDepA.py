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
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_1():
    buf = base64.standard_b64decode("VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2567700, "crc": 60496, "length": 20, "flags": 0, "y": -2682, "x": 3034, "z": -861, "preamble": 85, "payload": "FC4nANoLAACG9f//o/z//wAACQA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xec50
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "FC4nANoLAACG9f//o/z//wAACQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567700 )
    assert dictify(obj.payload.x) == snake_case_keys( 3034 )
    assert dictify(obj.payload.y) == snake_case_keys( -2682 )
    assert dictify(obj.payload.z) == snake_case_keys( -861 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_2():
    buf = base64.standard_b64decode("VQQC9tcUeC4nAEQLAAAY9v//3Pz//wAACQD4ig==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2567800, "crc": 35576, "length": 20, "flags": 0, "y": -2536, "x": 2884, "z": -804, "preamble": 85, "payload": "eC4nAEQLAAAY9v//3Pz//wAACQA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x8af8
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "eC4nAEQLAAAY9v//3Pz//wAACQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567800 )
    assert dictify(obj.payload.x) == snake_case_keys( 2884 )
    assert dictify(obj.payload.y) == snake_case_keys( -2536 )
    assert dictify(obj.payload.z) == snake_case_keys( -804 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_3():
    buf = base64.standard_b64decode("VQQC9tcU3C4nABULAABN9v//9/z//wAACQAZrg==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2567900, "crc": 44569, "length": 20, "flags": 0, "y": -2483, "x": 2837, "z": -777, "preamble": 85, "payload": "3C4nABULAABN9v//9/z//wAACQA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xae19
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "3C4nABULAABN9v//9/z//wAACQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567900 )
    assert dictify(obj.payload.x) == snake_case_keys( 2837 )
    assert dictify(obj.payload.y) == snake_case_keys( -2483 )
    assert dictify(obj.payload.z) == snake_case_keys( -777 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_4():
    buf = base64.standard_b64decode("VQQC9tcUQC8nAHkLAAAC9v//6vz//wAACQDD5A==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2568000, "crc": 58563, "length": 20, "flags": 0, "y": -2558, "x": 2937, "z": -790, "preamble": 85, "payload": "QC8nAHkLAAAC9v//6vz//wAACQA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xe4c3
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "QC8nAHkLAAAC9v//6vz//wAACQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2568000 )
    assert dictify(obj.payload.x) == snake_case_keys( 2937 )
    assert dictify(obj.payload.y) == snake_case_keys( -2558 )
    assert dictify(obj.payload.z) == snake_case_keys( -790 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_5():
    buf = base64.standard_b64decode("VQQC9tcUpC8nAB8LAABd9v//EP3//wAACQDbpA==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2568100, "crc": 42203, "length": 20, "flags": 0, "y": -2467, "x": 2847, "z": -752, "preamble": 85, "payload": "pC8nAB8LAABd9v//EP3//wAACQA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xa4db
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "pC8nAB8LAABd9v//EP3//wAACQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2568100 )
    assert dictify(obj.payload.x) == snake_case_keys( 2847 )
    assert dictify(obj.payload.y) == snake_case_keys( -2467 )
    assert dictify(obj.payload.z) == snake_case_keys( -752 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_6():
    buf = base64.standard_b64decode("VQQCwwQU1J1DGBgAAAD1////2////wAACABE/w==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084500, "crc": 65348, "length": 20, "flags": 0, "y": -11, "x": 24, "z": -37, "preamble": 85, "payload": "1J1DGBgAAAD1////2////wAACAA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xff44
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "1J1DGBgAAAD1////2////wAACAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084500 )
    assert dictify(obj.payload.x) == snake_case_keys( 24 )
    assert dictify(obj.payload.y) == snake_case_keys( -11 )
    assert dictify(obj.payload.z) == snake_case_keys( -37 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_7():
    buf = base64.standard_b64decode("VQQCwwQUOJ5DGAQAAADq////EgAAAAAACADWiA==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084600, "crc": 35030, "length": 20, "flags": 0, "y": -22, "x": 4, "z": 18, "preamble": 85, "payload": "OJ5DGAQAAADq////EgAAAAAACAA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x88d6
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "OJ5DGAQAAADq////EgAAAAAACAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084600 )
    assert dictify(obj.payload.x) == snake_case_keys( 4 )
    assert dictify(obj.payload.y) == snake_case_keys( -22 )
    assert dictify(obj.payload.z) == snake_case_keys( 18 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_8():
    buf = base64.standard_b64decode("VQQCwwQUnJ5DGOb///8EAAAAAQAAAAAACAB6nw==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084700, "crc": 40826, "length": 20, "flags": 0, "y": 4, "x": -26, "z": 1, "preamble": 85, "payload": "nJ5DGOb///8EAAAAAQAAAAAACAA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x9f7a
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "nJ5DGOb///8EAAAAAQAAAAAACAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084700 )
    assert dictify(obj.payload.x) == snake_case_keys( -26 )
    assert dictify(obj.payload.y) == snake_case_keys( 4 )
    assert dictify(obj.payload.z) == snake_case_keys( 1 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_9():
    buf = base64.standard_b64decode("VQQCwwQUAJ9DGPf////t////HAAAAAAACADokg==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084800, "crc": 37608, "length": 20, "flags": 0, "y": -19, "x": -9, "z": 28, "preamble": 85, "payload": "AJ9DGPf////t////HAAAAAAACAA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x92e8
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "AJ9DGPf////t////HAAAAAAACAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084800 )
    assert dictify(obj.payload.x) == snake_case_keys( -9 )
    assert dictify(obj.payload.y) == snake_case_keys( -19 )
    assert dictify(obj.payload.z) == snake_case_keys( 28 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_10():
    buf = base64.standard_b64decode("VQQCwwQUZJ9DGP////8CAAAA9f///wAACACr7g==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084900, "crc": 61099, "length": 20, "flags": 0, "y": 2, "x": -1, "z": -11, "preamble": 85, "payload": "ZJ9DGP////8CAAAA9f///wAACAA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0xeeab
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "ZJ9DGP////8CAAAA9f///wAACAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084900 )
    assert dictify(obj.payload.x) == snake_case_keys( -1 )
    assert dictify(obj.payload.y) == snake_case_keys( 2 )
    assert dictify(obj.payload.z) == snake_case_keys( -11 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_11():
    buf = base64.standard_b64decode("VQQCwwQULqJEGM////+5////QQAAAAAABQBSmg==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"n_sats": 5, "sender": 1219, "msg_type": 516, "tow": 407151150, "crc": 39506, "length": 20, "flags": 0, "y": -71, "x": -49, "z": 65, "preamble": 85, "payload": "LqJEGM////+5////QQAAAAAABQA=", "accuracy": 0}
    assert parsed_dict['crc'] == 0x9a52
    assert parsed_dict['length'] == 20
    assert parsed_dict['msg_type'] == 0x204
    assert parsed_dict['payload'] == "LqJEGM////+5////QQAAAAAABQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 5 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407151150 )
    assert dictify(obj.payload.x) == snake_case_keys( -49 )
    assert dictify(obj.payload.y) == snake_case_keys( -71 )
    assert dictify(obj.payload.z) == snake_case_keys( 65 )

    assert parsed_dict == snake_case_keys(orig_dict)