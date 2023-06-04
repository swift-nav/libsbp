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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_1():
    buf = base64.standard_b64decode("VQAC9tcgFC4nAMN6r0shmkTBpA7msOdfUMFO3Bb9/mlNQQAACQANVg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x560d
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "FC4nAMN6r0shmkTBpA7msOdfUMFO3Bb9/mlNQQAACQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567700
    
    assert dictify(msg.x) == -2700354.5912927105
    
    assert dictify(msg.y) == -4292510.764041577
    
    assert dictify(msg.z) == 3855357.977260149

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 512, 'tow': 2567700, 'crc': 22029, 'length': 32, 'flags': 0, 'y': -4292510.764041577, 'x': -2700354.5912927105, 'z': 3855357.977260149, 'preamble': 85, 'payload': 'FC4nAMN6r0shmkTBpA7msOdfUMFO3Bb9/mlNQQAACQA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_2():
    buf = base64.standard_b64decode("VQAC9tcgFC4nANTEDCoimkTBCXFwe+dfUME2YSbA/mlNQQAACQFLjw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8f4b
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "FC4nANTEDCoimkTBCXFwe+dfUME2YSbA/mlNQQAACQE="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567700
    
    assert dictify(msg.x) == -2700356.3285146747
    
    assert dictify(msg.y) == -4292509.928737887
    
    assert dictify(msg.z) == 3855357.5011712564

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 512, 'tow': 2567700, 'crc': 36683, 'length': 32, 'flags': 1, 'y': -4292509.928737887, 'x': -2700356.3285146747, 'z': 3855357.5011712564, 'preamble': 85, 'payload': 'FC4nANTEDCoimkTBCXFwe+dfUME2YSbA/mlNQQAACQE=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_3():
    buf = base64.standard_b64decode("VQAC9tcgeC4nAHBhJ74imkTB5it3c+dfUMEyx0xC/mlNQQAACQDMcQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x71cc
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "eC4nAHBhJ74imkTB5it3c+dfUMEyx0xC/mlNQQAACQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567800
    
    assert dictify(msg.x) == -2700357.485576801
    
    assert dictify(msg.y) == -4292509.80414865
    
    assert dictify(msg.z) == 3855356.517968082

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 512, 'tow': 2567800, 'crc': 29132, 'length': 32, 'flags': 0, 'y': -4292509.80414865, 'x': -2700357.485576801, 'z': 3855356.517968082, 'preamble': 85, 'payload': 'eC4nAHBhJ74imkTB5it3c+dfUMEyx0xC/mlNQQAACQA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_4():
    buf = base64.standard_b64decode("VQAC9tcgeC4nAMJSeQQimkTB37oBjOdfUMGwmJO1/mlNQQAACQFhRw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4761
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "eC4nAMJSeQQimkTB37oBjOdfUMGwmJO1/mlNQQAACQE="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567800
    
    assert dictify(msg.x) == -2700356.0349524925
    
    assert dictify(msg.y) == -4292510.187605589
    
    assert dictify(msg.z) == 3855357.4185667858

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 512, 'tow': 2567800, 'crc': 18273, 'length': 32, 'flags': 1, 'y': -4292510.187605589, 'x': -2700356.0349524925, 'z': 3855357.4185667858, 'preamble': 85, 'payload': 'eC4nAMJSeQQimkTB37oBjOdfUMGwmJO1/mlNQQAACQE=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_5():
    buf = base64.standard_b64decode("VQAC9tcg3C4nANgp4/4hmkTBCZeafOdfUMEBt9aL/2lNQQAACQAHYg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6207
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "3C4nANgp4/4hmkTBCZeafOdfUMEBt9aL/2lNQQAACQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567900
    
    assert dictify(msg.x) == -2700355.9913074784
    
    assert dictify(msg.y) == -4292509.946935424
    
    assert dictify(msg.z) == 3855359.0924900775

    assert dictify(msg) == {'n_sats': 9, 'sender': 55286, 'msg_type': 512, 'tow': 2567900, 'crc': 25095, 'length': 32, 'flags': 0, 'y': -4292509.946935424, 'x': -2700355.9913074784, 'z': 3855359.0924900775, 'preamble': 85, 'payload': '3C4nANgp4/4hmkTBCZeafOdfUMEBt9aL/2lNQQAACQA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_6():
    buf = base64.standard_b64decode("VQACwwQg1J1DGJneaQH8oUTB/vc0cEpDUMGkzy+SLKNNQQAACACRBA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x491
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "1J1DGJneaQH8oUTB/vc0cEpDUMGkzy+SLKNNQQAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084500
    
    assert dictify(msg.x) == -2704376.0110433814
    
    assert dictify(msg.y) == -4263209.753232954
    
    assert dictify(msg.z) == 3884633.142084079

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 512, 'tow': 407084500, 'crc': 1169, 'length': 32, 'flags': 0, 'y': -4263209.753232954, 'x': -2704376.0110433814, 'z': 3884633.142084079, 'preamble': 85, 'payload': '1J1DGJneaQH8oUTB/vc0cEpDUMGkzy+SLKNNQQAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_7():
    buf = base64.standard_b64decode("VQACwwQgOJ5DGNe43/b7oUTBJH4RJ0pDUMETs0ZQLKNNQQAACAD1Qg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x42f5
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "OJ5DGNe43/b7oUTBJH4RJ0pDUMETs0ZQLKNNQQAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084600
    
    assert dictify(msg.x) == -2704375.9287024545
    
    assert dictify(msg.y) == -4263208.610442672
    
    assert dictify(msg.z) == 3884632.627157578

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 512, 'tow': 407084600, 'crc': 17141, 'length': 32, 'flags': 0, 'y': -4263208.610442672, 'x': -2704375.9287024545, 'z': 3884632.627157578, 'preamble': 85, 'payload': 'OJ5DGNe43/b7oUTBJH4RJ0pDUMETs0ZQLKNNQQAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_8():
    buf = base64.standard_b64decode("VQACwwQgnJ5DGElK1pT7oUTB1Ze410lDUMFuYyakK6NNQQAACAAF3w==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xdf05
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "nJ5DGElK1pT7oUTB1Ze410lDUMFuYyakK6NNQQAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084700
    
    assert dictify(msg.x) == -2704375.162789617
    
    assert dictify(msg.y) == -4263207.370641668
    
    assert dictify(msg.z) == 3884631.282421521

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 512, 'tow': 407084700, 'crc': 57093, 'length': 32, 'flags': 0, 'y': -4263207.370641668, 'x': -2704375.162789617, 'z': 3884631.282421521, 'preamble': 85, 'payload': 'nJ5DGElK1pT7oUTB1Ze410lDUMFuYyakK6NNQQAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_9():
    buf = base64.standard_b64decode("VQACwwQgAJ9DGLFvcC38oUTB1ajG/UlDUMH1DOQMLKNNQQAACACP1A==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd48f
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "AJ9DGLFvcC38oUTB1ajG/UlDUMH1DOQMLKNNQQAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084800
    
    assert dictify(msg.x) == -2704376.3549937834
    
    assert dictify(msg.y) == -4263207.965250214
    
    assert dictify(msg.z) == 3884632.1007095524

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 512, 'tow': 407084800, 'crc': 54415, 'length': 32, 'flags': 0, 'y': -4263207.965250214, 'x': -2704376.3549937834, 'z': 3884632.1007095524, 'preamble': 85, 'payload': 'AJ9DGLFvcC38oUTB1ajG/UlDUMH1DOQMLKNNQQAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_10():
    buf = base64.standard_b64decode("VQACwwQgZJ9DGEPnSKX7oUTBltIk1ElDUMHqIRm9K6NNQQAACABG3Q==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xdd46
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "ZJ9DGEPnSKX7oUTBltIk1ElDUMHqIRm9K6NNQQAACAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084900
    
    assert dictify(msg.x) == -2704375.291287334
    
    assert dictify(msg.y) == -4263207.314747473
    
    assert dictify(msg.z) == 3884631.4773294823

    assert dictify(msg) == {'n_sats': 8, 'sender': 1219, 'msg_type': 512, 'tow': 407084900, 'crc': 56646, 'length': 32, 'flags': 0, 'y': -4263207.314747473, 'x': -2704375.291287334, 'z': 3884631.4773294823, 'preamble': 85, 'payload': 'ZJ9DGEPnSKX7oUTBltIk1ElDUMHqIRm9K6NNQQAACAA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_11():
    buf = base64.standard_b64decode("VQACwwQgLqJEGOBIg9f7oUTBtHveXkpDUMG/A4PBLaNNQQAABQAR3Q==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xdd11
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x200
    
    assert msg.payload == "LqJEGOBIg9f7oUTBtHveXkpDUMG/A4PBLaNNQQAABQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 5
    
    assert dictify(msg.tow) == 407151150
    
    assert dictify(msg.x) == -2704375.68369399
    
    assert dictify(msg.y) == -4263209.482329298
    
    assert dictify(msg.z) == 3884635.5118107493

    assert dictify(msg) == {'n_sats': 5, 'sender': 1219, 'msg_type': 512, 'tow': 407151150, 'crc': 56593, 'length': 32, 'flags': 0, 'y': -4263209.482329298, 'x': -2704375.68369399, 'z': 3884635.5118107493, 'preamble': 85, 'payload': 'LqJEGOBIg9f7oUTBtHveXkpDUMG/A4PBLaNNQQAABQA=', 'accuracy': 0}