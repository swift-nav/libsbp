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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepC.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_obs_dep_c_1():
    buf = base64.standard_b64decode("VUkARphXCF+3GGoHIH76SVBxXvf/56Pl5QQAAAA83GBGUZP6/8TQFBwGAAAA+D0+TRw88v9uq7SyBwAAAO1Uvk2sJQ0AKarppAoAAAAkVQlL8LwVABO2xNEMAAAAvq8=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xafbe
    
    assert msg.length == 87
    
    assert msg.msg_type == 0x49
    
    assert msg.payload == "CF+3GGoHIH76SVBxXvf/56Pl5QQAAAA83GBGUZP6/8TQFBwGAAAA+D0+TRw88v9uq7SyBwAAAO1Uvk2sJQ0AKarppAoAAAAkVQlL8LwVABO2xNEMAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x9846
    
    assert dictify(msg.header) == {'n_obs': 32, 't': {'tow': 414670600, 'wn': 1898}}
    
    assert dictify(msg.obs) == [{'l': {'f': 231, 'i': -565647}, 'p': 1347025534, 'cn0': 163, 'lock': 58853, 'sid': {'code': 0, 'reserved': 0, 'sat': 4}}, {'l': {'f': 196, 'i': -355503}, 'p': 1180752956, 'cn0': 208, 'lock': 7188, 'sid': {'code': 0, 'reserved': 0, 'sat': 6}}, {'l': {'f': 110, 'i': -902116}, 'p': 1295924728, 'cn0': 171, 'lock': 45748, 'sid': {'code': 0, 'reserved': 0, 'sat': 7}}, {'l': {'f': 41, 'i': 861612}, 'p': 1304319213, 'cn0': 170, 'lock': 42217, 'sid': {'code': 0, 'reserved': 0, 'sat': 10}}, {'l': {'f': 19, 'i': 1424624}, 'p': 1258902820, 'cn0': 182, 'lock': 53700, 'sid': {'code': 0, 'reserved': 0, 'sat': 12}}]

    assert dictify(msg) == {'sender': 38982, 'msg_type': 73, 'header': {'n_obs': 32, 't': {'wn': 1898, 'tow': 414670600}}, 'obs': [{'lock': 58853, 'sid': {'code': 0, 'reserved': 0, 'sat': 4}, 'l': {'i': -565647, 'f': 231}, 'cn0': 163, 'p': 1347025534}, {'lock': 7188, 'sid': {'code': 0, 'reserved': 0, 'sat': 6}, 'l': {'i': -355503, 'f': 196}, 'cn0': 208, 'p': 1180752956}, {'lock': 45748, 'sid': {'code': 0, 'reserved': 0, 'sat': 7}, 'l': {'i': -902116, 'f': 110}, 'cn0': 171, 'p': 1295924728}, {'lock': 42217, 'sid': {'code': 0, 'reserved': 0, 'sat': 10}, 'l': {'i': 861612, 'f': 41}, 'cn0': 170, 'p': 1304319213}, {'lock': 53700, 'sid': {'code': 0, 'reserved': 0, 'sat': 12}, 'l': {'i': 1424624, 'f': 19}, 'cn0': 182, 'p': 1258902820}], 'crc': 44990, 'length': 87, 'preamble': 85, 'payload': 'CF+3GGoHIH76SVBxXvf/56Pl5QQAAAA83GBGUZP6/8TQFBwGAAAA+D0+TRw88v9uq7SyBwAAAO1Uvk2sJQ0AKarppAoAAAAkVQlL8LwVABO2xNEMAAAA'}

def test_auto_check_sbp_observation_msg_obs_dep_c_2():
    buf = base64.standard_b64decode("VUkARpg3CF+3GGoHIUSmS0265hgAZbqiZhAAAABX/5tFSp4FABq+zh4bAAAAQFl8RBoWAwBy2eFJHQAAACWz")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb325
    
    assert msg.length == 55
    
    assert msg.msg_type == 0x49
    
    assert msg.payload == "CF+3GGoHIUSmS0265hgAZbqiZhAAAABX/5tFSp4FABq+zh4bAAAAQFl8RBoWAwBy2eFJHQAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x9846
    
    assert dictify(msg.header) == {'n_obs': 33, 't': {'tow': 414670600, 'wn': 1898}}
    
    assert dictify(msg.obs) == [{'l': {'f': 101, 'i': 1631930}, 'p': 1296803396, 'cn0': 186, 'lock': 26274, 'sid': {'code': 0, 'reserved': 0, 'sat': 16}}, {'l': {'f': 26, 'i': 368202}, 'p': 1167851351, 'cn0': 190, 'lock': 7886, 'sid': {'code': 0, 'reserved': 0, 'sat': 27}}, {'l': {'f': 114, 'i': 202266}, 'p': 1149000000, 'cn0': 217, 'lock': 18913, 'sid': {'code': 0, 'reserved': 0, 'sat': 29}}]

    assert dictify(msg) == {'sender': 38982, 'msg_type': 73, 'header': {'n_obs': 33, 't': {'wn': 1898, 'tow': 414670600}}, 'obs': [{'lock': 26274, 'sid': {'code': 0, 'reserved': 0, 'sat': 16}, 'l': {'i': 1631930, 'f': 101}, 'cn0': 186, 'p': 1296803396}, {'lock': 7886, 'sid': {'code': 0, 'reserved': 0, 'sat': 27}, 'l': {'i': 368202, 'f': 26}, 'cn0': 190, 'p': 1167851351}, {'lock': 18913, 'sid': {'code': 0, 'reserved': 0, 'sat': 29}, 'l': {'i': 202266, 'f': 114}, 'cn0': 217, 'p': 1149000000}], 'crc': 45861, 'length': 55, 'preamble': 85, 'payload': 'CF+3GGoHIUSmS0265hgAZbqiZhAAAABX/5tFSp4FABq+zh4bAAAAQFl8RBoWAwBy2eFJHQAAAA=='}

def test_auto_check_sbp_observation_msg_obs_dep_c_3():
    buf = base64.standard_b64decode("VUkAAABXCF+3GGoHINn7SVAJSPj/HqhxUQQAAADT3GBGxmv7/3PDNZAGAAAATT0+TSih8/+CsF2OBwAAAAFWvk1YTQwAdMfl1QoAAABdVQlLQIsUAHixxMIMAAAAjaE=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa18d
    
    assert msg.length == 87
    
    assert msg.msg_type == 0x49
    
    assert msg.payload == "CF+3GGoHINn7SVAJSPj/HqhxUQQAAADT3GBGxmv7/3PDNZAGAAAATT0+TSih8/+CsF2OBwAAAAFWvk1YTQwAdMfl1QoAAABdVQlLQIsUAHixxMIMAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x0
    
    assert dictify(msg.header) == {'n_obs': 32, 't': {'tow': 414670600, 'wn': 1898}}
    
    assert dictify(msg.obs) == [{'l': {'f': 30, 'i': -505847}, 'p': 1347025881, 'cn0': 168, 'lock': 20849, 'sid': {'code': 0, 'reserved': 0, 'sat': 4}}, {'l': {'f': 115, 'i': -300090}, 'p': 1180753107, 'cn0': 195, 'lock': 36917, 'sid': {'code': 0, 'reserved': 0, 'sat': 6}}, {'l': {'f': 130, 'i': -810712}, 'p': 1295924557, 'cn0': 176, 'lock': 36445, 'sid': {'code': 0, 'reserved': 0, 'sat': 7}}, {'l': {'f': 116, 'i': 806232}, 'p': 1304319489, 'cn0': 199, 'lock': 54757, 'sid': {'code': 0, 'reserved': 0, 'sat': 10}}, {'l': {'f': 120, 'i': 1346368}, 'p': 1258902877, 'cn0': 177, 'lock': 49860, 'sid': {'code': 0, 'reserved': 0, 'sat': 12}}]

    assert dictify(msg) == {'sender': 0, 'msg_type': 73, 'header': {'n_obs': 32, 't': {'wn': 1898, 'tow': 414670600}}, 'obs': [{'lock': 20849, 'sid': {'code': 0, 'reserved': 0, 'sat': 4}, 'l': {'i': -505847, 'f': 30}, 'cn0': 168, 'p': 1347025881}, {'lock': 36917, 'sid': {'code': 0, 'reserved': 0, 'sat': 6}, 'l': {'i': -300090, 'f': 115}, 'cn0': 195, 'p': 1180753107}, {'lock': 36445, 'sid': {'code': 0, 'reserved': 0, 'sat': 7}, 'l': {'i': -810712, 'f': 130}, 'cn0': 176, 'p': 1295924557}, {'lock': 54757, 'sid': {'code': 0, 'reserved': 0, 'sat': 10}, 'l': {'i': 806232, 'f': 116}, 'cn0': 199, 'p': 1304319489}, {'lock': 49860, 'sid': {'code': 0, 'reserved': 0, 'sat': 12}, 'l': {'i': 1346368, 'f': 120}, 'cn0': 177, 'p': 1258902877}], 'crc': 41357, 'length': 87, 'preamble': 85, 'payload': 'CF+3GGoHINn7SVAJSPj/HqhxUQQAAADT3GBGxmv7/3PDNZAGAAAATT0+TSih8/+CsF2OBwAAAAFWvk1YTQwAdMfl1QoAAABdVQlLQIsUAHixxMIMAAAA'}

def test_auto_check_sbp_observation_msg_obs_dep_c_4():
    buf = base64.standard_b64decode("VUkAAAA3CF+3GGoHIUanS02MiBcAWruegRAAAADo/5tFLa8FABHQrzgbAAAAQFl8RC1gAwBLuUnOHQAAANye")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9edc
    
    assert msg.length == 55
    
    assert msg.msg_type == 0x49
    
    assert msg.payload == "CF+3GGoHIUanS02MiBcAWruegRAAAADo/5tFLa8FABHQrzgbAAAAQFl8RC1gAwBLuUnOHQAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x0
    
    assert dictify(msg.header) == {'n_obs': 33, 't': {'tow': 414670600, 'wn': 1898}}
    
    assert dictify(msg.obs) == [{'l': {'f': 90, 'i': 1542284}, 'p': 1296803654, 'cn0': 187, 'lock': 33182, 'sid': {'code': 0, 'reserved': 0, 'sat': 16}}, {'l': {'f': 17, 'i': 372525}, 'p': 1167851496, 'cn0': 208, 'lock': 14511, 'sid': {'code': 0, 'reserved': 0, 'sat': 27}}, {'l': {'f': 75, 'i': 221229}, 'p': 1149000000, 'cn0': 185, 'lock': 52809, 'sid': {'code': 0, 'reserved': 0, 'sat': 29}}]

    assert dictify(msg) == {'sender': 0, 'msg_type': 73, 'header': {'n_obs': 33, 't': {'wn': 1898, 'tow': 414670600}}, 'obs': [{'lock': 33182, 'sid': {'code': 0, 'reserved': 0, 'sat': 16}, 'l': {'i': 1542284, 'f': 90}, 'cn0': 187, 'p': 1296803654}, {'lock': 14511, 'sid': {'code': 0, 'reserved': 0, 'sat': 27}, 'l': {'i': 372525, 'f': 17}, 'cn0': 208, 'p': 1167851496}, {'lock': 52809, 'sid': {'code': 0, 'reserved': 0, 'sat': 29}, 'l': {'i': 221229, 'f': 75}, 'cn0': 185, 'p': 1149000000}], 'crc': 40668, 'length': 55, 'preamble': 85, 'payload': 'CF+3GGoHIUanS02MiBcAWruegRAAAADo/5tFLa8FABHQrzgbAAAAQFl8RC1gAwBLuUnOHQAAAA=='}

def test_auto_check_sbp_observation_msg_obs_dep_c_5():
    buf = base64.standard_b64decode("VUkARphX0F+3GGoHICwISlBWXff/OZ7l5QQAAADg5WBGnJL6/93IFBwGAAAAPFI+TV068v8npLSyBwAAAN5Jvk0uJw0AyrXppAoAAACVQAlLcr8VAPm2xNEMAAAAcAg=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x870
    
    assert msg.length == 87
    
    assert msg.msg_type == 0x49
    
    assert msg.payload == "0F+3GGoHICwISlBWXff/OZ7l5QQAAADg5WBGnJL6/93IFBwGAAAAPFI+TV068v8npLSyBwAAAN5Jvk0uJw0AyrXppAoAAACVQAlLcr8VAPm2xNEMAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x9846
    
    assert dictify(msg.header) == {'n_obs': 32, 't': {'tow': 414670800, 'wn': 1898}}
    
    assert dictify(msg.obs) == [{'l': {'f': 57, 'i': -565930}, 'p': 1347029036, 'cn0': 158, 'lock': 58853, 'sid': {'code': 0, 'reserved': 0, 'sat': 4}}, {'l': {'f': 221, 'i': -355684}, 'p': 1180755424, 'cn0': 200, 'lock': 7188, 'sid': {'code': 0, 'reserved': 0, 'sat': 6}}, {'l': {'f': 39, 'i': -902563}, 'p': 1295929916, 'cn0': 164, 'lock': 45748, 'sid': {'code': 0, 'reserved': 0, 'sat': 7}}, {'l': {'f': 202, 'i': 861998}, 'p': 1304316382, 'cn0': 181, 'lock': 42217, 'sid': {'code': 0, 'reserved': 0, 'sat': 10}}, {'l': {'f': 249, 'i': 1425266}, 'p': 1258897557, 'cn0': 182, 'lock': 53700, 'sid': {'code': 0, 'reserved': 0, 'sat': 12}}]

    assert dictify(msg) == {'sender': 38982, 'msg_type': 73, 'header': {'n_obs': 32, 't': {'wn': 1898, 'tow': 414670800}}, 'obs': [{'lock': 58853, 'sid': {'code': 0, 'reserved': 0, 'sat': 4}, 'l': {'i': -565930, 'f': 57}, 'cn0': 158, 'p': 1347029036}, {'lock': 7188, 'sid': {'code': 0, 'reserved': 0, 'sat': 6}, 'l': {'i': -355684, 'f': 221}, 'cn0': 200, 'p': 1180755424}, {'lock': 45748, 'sid': {'code': 0, 'reserved': 0, 'sat': 7}, 'l': {'i': -902563, 'f': 39}, 'cn0': 164, 'p': 1295929916}, {'lock': 42217, 'sid': {'code': 0, 'reserved': 0, 'sat': 10}, 'l': {'i': 861998, 'f': 202}, 'cn0': 181, 'p': 1304316382}, {'lock': 53700, 'sid': {'code': 0, 'reserved': 0, 'sat': 12}, 'l': {'i': 1425266, 'f': 249}, 'cn0': 182, 'p': 1258897557}], 'crc': 2160, 'length': 87, 'preamble': 85, 'payload': '0F+3GGoHICwISlBWXff/OZ7l5QQAAADg5WBGnJL6/93IFBwGAAAAPFI+TV068v8npLSyBwAAAN5Jvk0uJw0AyrXppAoAAACVQAlLcr8VAPm2xNEMAAAA'}
