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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_1():
    buf = base64.standard_b64decode("VQUC9tcWFC4nAMb7//+cDwAAAAAAAAAAAAAJAKFc")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x5ca1
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "FC4nAMb7//+cDwAAAAAAAAAAAAAJAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( 3996 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -1082 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567700 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": 3996, "sender": 55286, "msg_type": 517, "tow": 2567700, "n": -1082, "crc": 23713, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "FC4nAMb7//+cDwAAAAAAAAAAAAAJAA==", "d": 0} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_2():
    buf = base64.standard_b64decode("VQUC9tcWeC4nAA78///PDgAAAAAAAAAAAAAJAH2g")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xa07d
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "eC4nAA78///PDgAAAAAAAAAAAAAJAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( 3791 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -1010 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567800 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": 3791, "sender": 55286, "msg_type": 517, "tow": 2567800, "n": -1010, "crc": 41085, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "eC4nAA78///PDgAAAAAAAAAAAAAJAA==", "d": 0} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_3():
    buf = base64.standard_b64decode("VQUC9tcW3C4nADD8//+MDgAAAAAAAAAAAAAJALOH")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x87b3
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "3C4nADD8//+MDgAAAAAAAAAAAAAJAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( 3724 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -976 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567900 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": 3724, "sender": 55286, "msg_type": 517, "tow": 2567900, "n": -976, "crc": 34739, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "3C4nADD8//+MDgAAAAAAAAAAAAAJAA==", "d": 0} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_4():
    buf = base64.standard_b64decode("VQUC9tcWQC8nACD8//8IDwAAAAAAAAAAAAAJADOx")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xb133
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "QC8nACD8//8IDwAAAAAAAAAAAAAJAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( 3848 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -992 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2568000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": 3848, "sender": 55286, "msg_type": 517, "tow": 2568000, "n": -992, "crc": 45363, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "QC8nACD8//8IDwAAAAAAAAAAAAAJAA==", "d": 0} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_5():
    buf = base64.standard_b64decode("VQUC9tcWpC8nAFD8//+MDgAAAAAAAAAAAAAJABcA")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x17
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "pC8nAFD8//+MDgAAAAAAAAAAAAAJAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( 3724 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -944 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2568100 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": 3724, "sender": 55286, "msg_type": 517, "tow": 2568100, "n": -944, "crc": 23, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "pC8nAFD8//+MDgAAAAAAAAAAAAAJAA==", "d": 0} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_6():
    buf = base64.standard_b64decode("VQUCwwQW1J1DGOX///8aAAAAGQAAAAAAAAAIAIQZ")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x1984
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "1J1DGOX///8aAAAAGQAAAAAAAAAIAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( 25 )
    assert dictify(obj.payload.e) == snake_case_keys( 26 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -27 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084500 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": 26, "sender": 1219, "msg_type": 517, "tow": 407084500, "n": -27, "crc": 6532, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 8, "preamble": 85, "payload": "1J1DGOX///8aAAAAGQAAAAAAAAAIAA==", "d": 25} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_7():
    buf = base64.standard_b64decode("VQUCwwQWOJ5DGAQAAAAPAAAA6P///wAAAAAIACoO")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xe2a
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "OJ5DGAQAAAAPAAAA6P///wAAAAAIAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -24 )
    assert dictify(obj.payload.e) == snake_case_keys( 15 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 4 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084600 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": 15, "sender": 1219, "msg_type": 517, "tow": 407084600, "n": 4, "crc": 3626, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 8, "preamble": 85, "payload": "OJ5DGAQAAAAPAAAA6P///wAAAAAIAA==", "d": -24} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_8():
    buf = base64.standard_b64decode("VQUCwwQWnJ5DGPv////o////9////wAAAAAIANqU")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x94da
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "nJ5DGPv////o////9////wAAAAAIAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -9 )
    assert dictify(obj.payload.e) == snake_case_keys( -24 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -5 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084700 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": -24, "sender": 1219, "msg_type": 517, "tow": 407084700, "n": -5, "crc": 38106, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 8, "preamble": 85, "payload": "nJ5DGPv////o////9////wAAAAAIAA==", "d": -9} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_9():
    buf = base64.standard_b64decode("VQUCwwQWAJ9DGAoAAAACAAAA3v///wAAAAAIAJQQ")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x1094
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "AJ9DGAoAAAACAAAA3v///wAAAAAIAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -34 )
    assert dictify(obj.payload.e) == snake_case_keys( 2 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 10 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084800 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": 2, "sender": 1219, "msg_type": 517, "tow": 407084800, "n": 10, "crc": 4244, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 8, "preamble": 85, "payload": "AJ9DGAoAAAACAAAA3v///wAAAAAIAA==", "d": -34} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_10():
    buf = base64.standard_b64decode("VQUCwwQWZJ9DGPj////+////BwAAAAAAAAAIAP/s")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xecff
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "ZJ9DGPj////+////BwAAAAAAAAAIAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( 7 )
    assert dictify(obj.payload.e) == snake_case_keys( -2 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -8 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 8 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084900 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": -2, "sender": 1219, "msg_type": 517, "tow": 407084900, "n": -8, "crc": 60671, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 8, "preamble": 85, "payload": "ZJ9DGPj////+////BwAAAAAAAAAIAA==", "d": 7} )

def test_auto_check_sbp_navigation_msg_vel_ned_dep_a_11():
    buf = base64.standard_b64decode("VQUCwwQWLqJEGP/////9////lP///wAAAAAFAKa9")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xbda6
    assert payload.length == 22
    assert payload.msg_type == 0x205
    assert payload.payload == "LqJEGP/////9////lP///wAAAAAFAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -108 )
    assert dictify(obj.payload.e) == snake_case_keys( -3 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -1 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 5 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407151150 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "e": -3, "sender": 1219, "msg_type": 517, "tow": 407151150, "n": -1, "crc": 48550, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 5, "preamble": 85, "payload": "LqJEGP/////9////lP///wAAAAAFAA==", "d": -108} )