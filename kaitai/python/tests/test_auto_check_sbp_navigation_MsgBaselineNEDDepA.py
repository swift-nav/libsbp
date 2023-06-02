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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNEDDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_1():
    buf = base64.standard_b64decode("VQMC9tcWFC4nAPOG/v/qmf//AAAAAAAAAAAJAV3B")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -26134, "sender": 55286, "msg_type": 515, "tow": 2567700, "n": -96525, "crc": 49501, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "FC4nAPOG/v/qmf//AAAAAAAAAAAJAQ==", "d": 0}
    assert parsed_dict['crc'] == 0xc15d
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "FC4nAPOG/v/qmf//AAAAAAAAAAAJAQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( -26134 )
    assert dictify(obj.payload.flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -96525 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567700 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_2():
    buf = base64.standard_b64decode("VQMC9tcWeC4nAIuG/v9tm///AAAAAAAAAAAJASYn")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -25747, "sender": 55286, "msg_type": 515, "tow": 2567800, "n": -96629, "crc": 10022, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "eC4nAIuG/v9tm///AAAAAAAAAAAJAQ==", "d": 0}
    assert parsed_dict['crc'] == 0x2726
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "eC4nAIuG/v9tm///AAAAAAAAAAAJAQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( -25747 )
    assert dictify(obj.payload.flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -96629 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567800 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_3():
    buf = base64.standard_b64decode("VQMC9tcW3C4nACWG/v/wnP//AAAAAAAAAAAJATqF")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -25360, "sender": 55286, "msg_type": 515, "tow": 2567900, "n": -96731, "crc": 34106, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "3C4nACWG/v/wnP//AAAAAAAAAAAJAQ==", "d": 0}
    assert parsed_dict['crc'] == 0x853a
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "3C4nACWG/v/wnP//AAAAAAAAAAAJAQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( -25360 )
    assert dictify(obj.payload.flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -96731 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567900 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_4():
    buf = base64.standard_b64decode("VQMC9tcWQC8nAMGF/v9znv//AAAAAAAAAAAJATjW")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -24973, "sender": 55286, "msg_type": 515, "tow": 2568000, "n": -96831, "crc": 54840, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "QC8nAMGF/v9znv//AAAAAAAAAAAJAQ==", "d": 0}
    assert parsed_dict['crc'] == 0xd638
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "QC8nAMGF/v9znv//AAAAAAAAAAAJAQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( -24973 )
    assert dictify(obj.payload.flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -96831 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2568000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_5():
    buf = base64.standard_b64decode("VQMC9tcWpC8nAF2F/v/2n///AAAAAAAAAAAJAer0")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": -24586, "sender": 55286, "msg_type": 515, "tow": 2568100, "n": -96931, "crc": 62698, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "pC8nAF2F/v/2n///AAAAAAAAAAAJAQ==", "d": 0}
    assert parsed_dict['crc'] == 0xf4ea
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "pC8nAF2F/v/2n///AAAAAAAAAAAJAQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.d) == snake_case_keys( 0 )
    assert dictify(obj.payload.e) == snake_case_keys( -24586 )
    assert dictify(obj.payload.flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -96931 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2568100 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_6():
    buf = base64.standard_b64decode("VQMCwwQWnBVFGIL2///xBAAAI8T//wAAAAAGAPoV")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": 1265, "sender": 1219, "msg_type": 515, "tow": 407180700, "n": -2430, "crc": 5626, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "nBVFGIL2///xBAAAI8T//wAAAAAGAA==", "d": -15325}
    assert parsed_dict['crc'] == 0x15fa
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "nBVFGIL2///xBAAAI8T//wAAAAAGAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -15325 )
    assert dictify(obj.payload.e) == snake_case_keys( 1265 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -2430 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 6 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407180700 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_7():
    buf = base64.standard_b64decode("VQMCwwQWABZFGIL2///xBAAAI8T//wAAAAAGAPCF")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": 1265, "sender": 1219, "msg_type": 515, "tow": 407180800, "n": -2430, "crc": 34288, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "ABZFGIL2///xBAAAI8T//wAAAAAGAA==", "d": -15325}
    assert parsed_dict['crc'] == 0x85f0
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "ABZFGIL2///xBAAAI8T//wAAAAAGAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -15325 )
    assert dictify(obj.payload.e) == snake_case_keys( 1265 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -2430 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 6 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407180800 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_8():
    buf = base64.standard_b64decode("VQMCwwQWZBZFGCD7///HCwAAOaH//wAAAAAGAAy1")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": 3015, "sender": 1219, "msg_type": 515, "tow": 407180900, "n": -1248, "crc": 46348, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "ZBZFGCD7///HCwAAOaH//wAAAAAGAA==", "d": -24263}
    assert parsed_dict['crc'] == 0xb50c
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "ZBZFGCD7///HCwAAOaH//wAAAAAGAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -24263 )
    assert dictify(obj.payload.e) == snake_case_keys( 3015 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -1248 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 6 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407180900 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_9():
    buf = base64.standard_b64decode("VQMCwwQWyBZFGCH7///HCwAANqH//wAAAAAGAFY6")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": 3015, "sender": 1219, "msg_type": 515, "tow": 407181000, "n": -1247, "crc": 14934, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "yBZFGCH7///HCwAANqH//wAAAAAGAA==", "d": -24266}
    assert parsed_dict['crc'] == 0x3a56
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "yBZFGCH7///HCwAANqH//wAAAAAGAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -24266 )
    assert dictify(obj.payload.e) == snake_case_keys( 3015 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( -1247 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 6 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407181000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_10():
    buf = base64.standard_b64decode("VQMCwwQWLBdFGG4GAAA3CAAAoKb//wAAAAAGADP5")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": 2103, "sender": 1219, "msg_type": 515, "tow": 407181100, "n": 1646, "crc": 63795, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "LBdFGG4GAAA3CAAAoKb//wAAAAAGAA==", "d": -22880}
    assert parsed_dict['crc'] == 0xf933
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "LBdFGG4GAAA3CAAAoKb//wAAAAAGAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -22880 )
    assert dictify(obj.payload.e) == snake_case_keys( 2103 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 1646 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 6 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407181100 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_11():
    buf = base64.standard_b64decode("VQMCwwQWkBdFGG4GAAA2CAAAoKb//wAAAAAGAM4W")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"v_accuracy": 0, "e": 2102, "sender": 1219, "msg_type": 515, "tow": 407181200, "n": 1646, "crc": 5838, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "kBdFGG4GAAA2CAAAoKb//wAAAAAGAA==", "d": -22880}
    assert parsed_dict['crc'] == 0x16ce
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x203
    assert parsed_dict['payload'] == "kBdFGG4GAAA2CAAAoKb//wAAAAAGAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.d) == snake_case_keys( -22880 )
    assert dictify(obj.payload.e) == snake_case_keys( 2102 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.n) == snake_case_keys( 1646 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 6 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407181200 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)