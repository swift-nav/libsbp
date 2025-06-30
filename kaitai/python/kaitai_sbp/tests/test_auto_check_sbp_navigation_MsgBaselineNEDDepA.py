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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNEDDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_1():
    buf = base64.standard_b64decode("VQMC9tcWFC4nAPOG/v/qmf//AAAAAAAAAAAJAV3B")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc15d
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "FC4nAPOG/v/qmf//AAAAAAAAAAAJAQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.d) == 0
    
    assert dictify(msg.e) == -26134
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -96525
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567700
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -26134, 'sender': 55286, 'msg_type': 515, 'tow': 2567700, 'n': -96525, 'crc': 49501, 'length': 22, 'flags': 1, 'h_accuracy': 0, 'n_sats': 9, 'preamble': 85, 'payload': 'FC4nAPOG/v/qmf//AAAAAAAAAAAJAQ==', 'd': 0}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_2():
    buf = base64.standard_b64decode("VQMC9tcWeC4nAIuG/v9tm///AAAAAAAAAAAJASYn")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2726
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "eC4nAIuG/v9tm///AAAAAAAAAAAJAQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.d) == 0
    
    assert dictify(msg.e) == -25747
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -96629
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567800
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -25747, 'sender': 55286, 'msg_type': 515, 'tow': 2567800, 'n': -96629, 'crc': 10022, 'length': 22, 'flags': 1, 'h_accuracy': 0, 'n_sats': 9, 'preamble': 85, 'payload': 'eC4nAIuG/v9tm///AAAAAAAAAAAJAQ==', 'd': 0}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_3():
    buf = base64.standard_b64decode("VQMC9tcW3C4nACWG/v/wnP//AAAAAAAAAAAJATqF")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x853a
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "3C4nACWG/v/wnP//AAAAAAAAAAAJAQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.d) == 0
    
    assert dictify(msg.e) == -25360
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -96731
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567900
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -25360, 'sender': 55286, 'msg_type': 515, 'tow': 2567900, 'n': -96731, 'crc': 34106, 'length': 22, 'flags': 1, 'h_accuracy': 0, 'n_sats': 9, 'preamble': 85, 'payload': '3C4nACWG/v/wnP//AAAAAAAAAAAJAQ==', 'd': 0}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_4():
    buf = base64.standard_b64decode("VQMC9tcWQC8nAMGF/v9znv//AAAAAAAAAAAJATjW")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd638
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "QC8nAMGF/v9znv//AAAAAAAAAAAJAQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.d) == 0
    
    assert dictify(msg.e) == -24973
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -96831
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2568000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -24973, 'sender': 55286, 'msg_type': 515, 'tow': 2568000, 'n': -96831, 'crc': 54840, 'length': 22, 'flags': 1, 'h_accuracy': 0, 'n_sats': 9, 'preamble': 85, 'payload': 'QC8nAMGF/v9znv//AAAAAAAAAAAJAQ==', 'd': 0}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_5():
    buf = base64.standard_b64decode("VQMC9tcWpC8nAF2F/v/2n///AAAAAAAAAAAJAer0")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf4ea
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "pC8nAF2F/v/2n///AAAAAAAAAAAJAQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.d) == 0
    
    assert dictify(msg.e) == -24586
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -96931
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2568100
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': -24586, 'sender': 55286, 'msg_type': 515, 'tow': 2568100, 'n': -96931, 'crc': 62698, 'length': 22, 'flags': 1, 'h_accuracy': 0, 'n_sats': 9, 'preamble': 85, 'payload': 'pC8nAF2F/v/2n///AAAAAAAAAAAJAQ==', 'd': 0}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_6():
    buf = base64.standard_b64decode("VQMCwwQWnBVFGIL2///xBAAAI8T//wAAAAAGAPoV")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x15fa
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "nBVFGIL2///xBAAAI8T//wAAAAAGAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.d) == -15325
    
    assert dictify(msg.e) == 1265
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -2430
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407180700
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': 1265, 'sender': 1219, 'msg_type': 515, 'tow': 407180700, 'n': -2430, 'crc': 5626, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 6, 'preamble': 85, 'payload': 'nBVFGIL2///xBAAAI8T//wAAAAAGAA==', 'd': -15325}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_7():
    buf = base64.standard_b64decode("VQMCwwQWABZFGIL2///xBAAAI8T//wAAAAAGAPCF")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x85f0
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "ABZFGIL2///xBAAAI8T//wAAAAAGAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.d) == -15325
    
    assert dictify(msg.e) == 1265
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -2430
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407180800
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': 1265, 'sender': 1219, 'msg_type': 515, 'tow': 407180800, 'n': -2430, 'crc': 34288, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 6, 'preamble': 85, 'payload': 'ABZFGIL2///xBAAAI8T//wAAAAAGAA==', 'd': -15325}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_8():
    buf = base64.standard_b64decode("VQMCwwQWZBZFGCD7///HCwAAOaH//wAAAAAGAAy1")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb50c
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "ZBZFGCD7///HCwAAOaH//wAAAAAGAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.d) == -24263
    
    assert dictify(msg.e) == 3015
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -1248
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407180900
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': 3015, 'sender': 1219, 'msg_type': 515, 'tow': 407180900, 'n': -1248, 'crc': 46348, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 6, 'preamble': 85, 'payload': 'ZBZFGCD7///HCwAAOaH//wAAAAAGAA==', 'd': -24263}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_9():
    buf = base64.standard_b64decode("VQMCwwQWyBZFGCH7///HCwAANqH//wAAAAAGAFY6")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x3a56
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "yBZFGCH7///HCwAANqH//wAAAAAGAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.d) == -24266
    
    assert dictify(msg.e) == 3015
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == -1247
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407181000
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': 3015, 'sender': 1219, 'msg_type': 515, 'tow': 407181000, 'n': -1247, 'crc': 14934, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 6, 'preamble': 85, 'payload': 'yBZFGCH7///HCwAANqH//wAAAAAGAA==', 'd': -24266}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_10():
    buf = base64.standard_b64decode("VQMCwwQWLBdFGG4GAAA3CAAAoKb//wAAAAAGADP5")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf933
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "LBdFGG4GAAA3CAAAoKb//wAAAAAGAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.d) == -22880
    
    assert dictify(msg.e) == 2103
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 1646
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407181100
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': 2103, 'sender': 1219, 'msg_type': 515, 'tow': 407181100, 'n': 1646, 'crc': 63795, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 6, 'preamble': 85, 'payload': 'LBdFGG4GAAA3CAAAoKb//wAAAAAGAA==', 'd': -22880}

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_11():
    buf = base64.standard_b64decode("VQMCwwQWkBdFGG4GAAA2CAAAoKb//wAAAAAGAM4W")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x16ce
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x203
    
    assert msg.payload == "kBdFGG4GAAA2CAAAoKb//wAAAAAGAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.d) == -22880
    
    assert dictify(msg.e) == 2102
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.n) == 1646
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407181200
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'e': 2102, 'sender': 1219, 'msg_type': 515, 'tow': 407181200, 'n': 1646, 'crc': 5838, 'length': 22, 'flags': 0, 'h_accuracy': 0, 'n_sats': 6, 'preamble': 85, 'payload': 'kBdFGG4GAAA2CAAAoKb//wAAAAAGAA==', 'd': -22880}
