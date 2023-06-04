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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEFDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_1():
    buf = base64.standard_b64decode("VQIC9tcUFC4nABUw//80df//2NP+/wAACQEyiQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8932
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "FC4nABUw//80df//2NP+/wAACQE="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567700
    
    assert dictify(msg.x) == -53227
    
    assert dictify(msg.y) == -35532
    
    assert dictify(msg.z) == -76840

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 514, 'tow': 2567700, 'crc': 35122, 'length': 20, 'flags': 1, 'y': -35532, 'x': -53227, 'z': -76840, 'preamble': 85, 'payload': 'FC4nABUw//80df//2NP+/wAACQE=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_2():
    buf = base64.standard_b64decode("VQIC9tcUeC4nADox//8xdP//htP+/wAACQHjmw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9be3
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "eC4nADox//8xdP//htP+/wAACQE="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567800
    
    assert dictify(msg.x) == -52934
    
    assert dictify(msg.y) == -35791
    
    assert dictify(msg.z) == -76922

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 514, 'tow': 2567800, 'crc': 39907, 'length': 20, 'flags': 1, 'y': -35791, 'x': -52934, 'z': -76922, 'preamble': 85, 'payload': 'eC4nADox//8xdP//htP+/wAACQE=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_3():
    buf = base64.standard_b64decode("VQIC9tcU3C4nAGEy//8vc///NNP+/wAACQE9fg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7e3d
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "3C4nAGEy//8vc///NNP+/wAACQE="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567900
    
    assert dictify(msg.x) == -52639
    
    assert dictify(msg.y) == -36049
    
    assert dictify(msg.z) == -77004

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 514, 'tow': 2567900, 'crc': 32317, 'length': 20, 'flags': 1, 'y': -36049, 'x': -52639, 'z': -77004, 'preamble': 85, 'payload': '3C4nAGEy//8vc///NNP+/wAACQE=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_4():
    buf = base64.standard_b64decode("VQIC9tcUQC8nAIgz//8tcv//5NL+/wAACQHITw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4fc8
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "QC8nAIgz//8tcv//5NL+/wAACQE="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2568000
    
    assert dictify(msg.x) == -52344
    
    assert dictify(msg.y) == -36307
    
    assert dictify(msg.z) == -77084

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 514, 'tow': 2568000, 'crc': 20424, 'length': 20, 'flags': 1, 'y': -36307, 'x': -52344, 'z': -77084, 'preamble': 85, 'payload': 'QC8nAIgz//8tcv//5NL+/wAACQE=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_5():
    buf = base64.standard_b64decode("VQIC9tcUpC8nALA0//8scf//ldL+/wAACQFoGA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1868
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "pC8nALA0//8scf//ldL+/wAACQE="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2568100
    
    assert dictify(msg.x) == -52048
    
    assert dictify(msg.y) == -36564
    
    assert dictify(msg.z) == -77163

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 514, 'tow': 2568100, 'crc': 6248, 'length': 20, 'flags': 1, 'y': -36564, 'x': -52048, 'z': -77163, 'preamble': 85, 'payload': 'pC8nALA0//8scf//ldL+/wAACQE=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_6():
    buf = base64.standard_b64decode("VQICwwQUnBVFGKnn//9m0P//+xwAAAAABgCSqA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa892
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "nBVFGKnn//9m0P//+xwAAAAABgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407180700
    
    assert dictify(msg.x) == -6231
    
    assert dictify(msg.y) == -12186
    
    assert dictify(msg.z) == 7419

    assert dictify(msg) == {'n_sats': 6, 'sender': 1219, 'msg_type': 514, 'tow': 407180700, 'crc': 43154, 'length': 20, 'flags': 0, 'y': -12186, 'x': -6231, 'z': 7419, 'preamble': 85, 'payload': 'nBVFGKnn//9m0P//+xwAAAAABgA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_7():
    buf = base64.standard_b64decode("VQICwwQUABZFGKnn//9n0P///BwAAAAABgAidA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7422
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "ABZFGKnn//9n0P///BwAAAAABgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407180800
    
    assert dictify(msg.x) == -6231
    
    assert dictify(msg.y) == -12185
    
    assert dictify(msg.z) == 7420

    assert dictify(msg) == {'n_sats': 6, 'sender': 1219, 'msg_type': 514, 'tow': 407180800, 'crc': 29730, 'length': 20, 'flags': 0, 'y': -12185, 'x': -6231, 'z': 7420, 'preamble': 85, 'payload': 'ABZFGKnn//9n0P///BwAAAAABgA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_8():
    buf = base64.standard_b64decode("VQICwwQUZBZFGB7g///At///7zUAAAAABgDhDw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xfe1
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "ZBZFGB7g///At///7zUAAAAABgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407180900
    
    assert dictify(msg.x) == -8162
    
    assert dictify(msg.y) == -18496
    
    assert dictify(msg.z) == 13807

    assert dictify(msg) == {'n_sats': 6, 'sender': 1219, 'msg_type': 514, 'tow': 407180900, 'crc': 4065, 'length': 20, 'flags': 0, 'y': -18496, 'x': -8162, 'z': 13807, 'preamble': 85, 'payload': 'ZBZFGB7g///At///7zUAAAAABgA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_9():
    buf = base64.standard_b64decode("VQICwwQUyBZFGBzg//+/t///8jUAAAAABgAjZA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6423
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "yBZFGBzg//+/t///8jUAAAAABgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407181000
    
    assert dictify(msg.x) == -8164
    
    assert dictify(msg.y) == -18497
    
    assert dictify(msg.z) == 13810

    assert dictify(msg) == {'n_sats': 6, 'sender': 1219, 'msg_type': 514, 'tow': 407181000, 'crc': 25635, 'length': 20, 'flags': 0, 'y': -18497, 'x': -8164, 'z': 13810, 'preamble': 85, 'payload': 'yBZFGBzg//+/t///8jUAAAAABgA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_10():
    buf = base64.standard_b64decode("VQICwwQULBdFGBjj//8Zw///mTsAAAAABgBCQg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4242
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "LBdFGBjj//8Zw///mTsAAAAABgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407181100
    
    assert dictify(msg.x) == -7400
    
    assert dictify(msg.y) == -15591
    
    assert dictify(msg.z) == 15257

    assert dictify(msg) == {'n_sats': 6, 'sender': 1219, 'msg_type': 514, 'tow': 407181100, 'crc': 16962, 'length': 20, 'flags': 0, 'y': -15591, 'x': -7400, 'z': 15257, 'preamble': 85, 'payload': 'LBdFGBjj//8Zw///mTsAAAAABgA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_11():
    buf = base64.standard_b64decode("VQICwwQUkBdFGBfj//8Zw///mTsAAAAABgAjhw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8723
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x202
    
    assert msg.payload == "kBdFGBfj//8Zw///mTsAAAAABgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 6
    
    assert dictify(msg.tow) == 407181200
    
    assert dictify(msg.x) == -7401
    
    assert dictify(msg.y) == -15591
    
    assert dictify(msg.z) == 15257

    assert dictify(msg) == {'n_sats': 6, 'sender': 1219, 'msg_type': 514, 'tow': 407181200, 'crc': 34595, 'length': 20, 'flags': 0, 'y': -15591, 'x': -7401, 'z': 15257, 'preamble': 85, 'payload': 'kBdFGBfj//8Zw///mTsAAAAABgA=', 'accuracy': 0}