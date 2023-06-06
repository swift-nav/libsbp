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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_1():
    buf = base64.standard_b64decode("VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8bec
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "FC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 69.80437675175607
    
    assert dictify(msg.lat) == 37.42906890908121
    
    assert dictify(msg.lon) == -122.17338662202773
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567700
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 9, 'sender': 55286, 'msg_type': 513, 'lon': -122.17338662202773, 'tow': 2567700, 'height': 69.80437675175607, 'crc': 35820, 'length': 34, 'flags': 0, 'h_accuracy': 0, 'lat': 37.42906890908121, 'preamble': 85, 'payload': 'FC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAA=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_2():
    buf = base64.standard_b64decode("VQEC9tciFC4nAKEzS5TrtkJAJCn2HhmLXsD+2jF/CmxRQAAAAAAJARl1")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7519
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "FC4nAKEzS5TrtkJAJCn2HhmLXsD+2jF/CmxRQAAAAAAJAQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 69.68814067715354
    
    assert dictify(msg.lat) == 37.42906430885274
    
    assert dictify(msg.lon) == -122.17340826071865
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567700
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 9, 'sender': 55286, 'msg_type': 513, 'lon': -122.17340826071865, 'tow': 2567700, 'height': 69.68814067715354, 'crc': 29977, 'length': 34, 'flags': 1, 'h_accuracy': 0, 'lat': 37.42906430885274, 'preamble': 85, 'payload': 'FC4nAKEzS5TrtkJAJCn2HhmLXsD+2jF/CmxRQAAAAAAJAQ=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_3():
    buf = base64.standard_b64decode("VQEC9tcieC4nADjW0kHrtkJADS6EUBmLXsAWjy7qv19RQAAAAAAJAK5p")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x69ae
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "eC4nADjW0kHrtkJADS6EUBmLXsAWjy7qv19RQAAAAAAJAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 69.49608854815264
    
    assert dictify(msg.lat) == 37.42905447764173
    
    assert dictify(msg.lon) == -122.17342007549469
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567800
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 9, 'sender': 55286, 'msg_type': 513, 'lon': -122.17342007549469, 'tow': 2567800, 'height': 69.49608854815264, 'crc': 27054, 'length': 34, 'flags': 0, 'h_accuracy': 0, 'lat': 37.42905447764173, 'preamble': 85, 'payload': 'eC4nADjW0kHrtkJADS6EUBmLXsAWjy7qv19RQAAAAAAJAA=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_4():
    buf = base64.standard_b64decode("VQEC9tcieC4nAPt1c4zrtkJAmIanDBmLXsCgFon9BGxRQAAAAAAJAXp/")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7f7a
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "eC4nAPt1c4zrtkJAmIanDBmLXsCgFon9BGxRQAAAAAAJAQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 69.68780458819901
    
    assert dictify(msg.lat) == 37.429063373925565
    
    assert dictify(msg.lon) == -122.17340389594972
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567800
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 9, 'sender': 55286, 'msg_type': 513, 'lon': -122.17340389594972, 'tow': 2567800, 'height': 69.68780458819901, 'crc': 32634, 'length': 34, 'flags': 1, 'h_accuracy': 0, 'lat': 37.429063373925565, 'preamble': 85, 'payload': 'eC4nAPt1c4zrtkJAmIanDBmLXsCgFon9BGxRQAAAAAAJAQ=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_5():
    buf = base64.standard_b64decode("VQEC9tci3C4nADN8WPvrtkJAmQX6EBmLXsCSPLvbmKFRQAAAAAAJAMKe")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9ec2
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "3C4nADN8WPvrtkJAmQX6EBmLXsCSPLvbmKFRQAAAAAAJAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 70.5249547317965
    
    assert dictify(msg.lat) == 37.42907659359516
    
    assert dictify(msg.lon) == -122.17340492645452
    
    assert dictify(msg.n_sats) == 9
    
    assert dictify(msg.tow) == 2567900
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 9, 'sender': 55286, 'msg_type': 513, 'lon': -122.17340492645452, 'tow': 2567900, 'height': 70.5249547317965, 'crc': 40642, 'length': 34, 'flags': 0, 'h_accuracy': 0, 'lat': 37.42907659359516, 'preamble': 85, 'payload': '3C4nADN8WPvrtkJAmQX6EBmLXsCSPLvbmKFRQAAAAAAJAA=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_6():
    buf = base64.standard_b64decode("VQECwwQi1J1DGAgX5AiX4UJAnK4qwuaYXsCZF0gvxCgQQAAAAAAIAO2p")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa9ed
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "1J1DGAgX5AiX4UJAnK4qwuaYXsCZF0gvxCgQQAAAAAAIAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 4.039810885214956
    
    assert dictify(msg.lat) == 37.76242171418386
    
    assert dictify(msg.lon) == -122.38908437889262
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084500
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 8, 'sender': 1219, 'msg_type': 513, 'lon': -122.38908437889262, 'tow': 407084500, 'height': 4.039810885214956, 'crc': 43501, 'length': 34, 'flags': 0, 'h_accuracy': 0, 'lat': 37.76242171418386, 'preamble': 85, 'payload': '1J1DGAgX5AiX4UJAnK4qwuaYXsCZF0gvxCgQQAAAAAAIAA=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_7():
    buf = base64.standard_b64decode("VQECwwQiOJ5DGNxt1BiX4UJAn+f+2+aYXsCAl0MT6WkHQAAAAAAIAJgL")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb98
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "OJ5DGNxt1BiX4UJAn+f+2+aYXsCAl0MT6WkHQAAAAAAIAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 2.926714087009657
    
    assert dictify(msg.lat) == 37.76242361423985
    
    assert dictify(msg.lon) == -122.38909053700489
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084600
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 8, 'sender': 1219, 'msg_type': 513, 'lon': -122.38909053700489, 'tow': 407084600, 'height': 2.926714087009657, 'crc': 2968, 'length': 34, 'flags': 0, 'h_accuracy': 0, 'lat': 37.76242361423985, 'preamble': 85, 'payload': 'OJ5DGNxt1BiX4UJAn+f+2+aYXsCAl0MT6WkHQAAAAAAIAA=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_8():
    buf = base64.standard_b64decode("VQECwwQinJ5DGA1b7QuX4UJAS3HS3OaYXsAlBpG8WXDuPwAAAAAIAN2b")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9bdd
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "nJ5DGA1b7QuX4UJAS3HS3OaYXsAlBpG8WXDuPwAAAAAIAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 0.9512146647395566
    
    assert dictify(msg.lat) == 37.762422076126406
    
    assert dictify(msg.lon) == -122.3890907340148
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084700
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 8, 'sender': 1219, 'msg_type': 513, 'lon': -122.3890907340148, 'tow': 407084700, 'height': 0.9512146647395566, 'crc': 39901, 'length': 34, 'flags': 0, 'h_accuracy': 0, 'lat': 37.762422076126406, 'preamble': 85, 'payload': 'nJ5DGA1b7QuX4UJAS3HS3OaYXsAlBpG8WXDuPwAAAAAIAA=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_9():
    buf = base64.standard_b64decode("VQECwwQiAJ9DGDO3BQiX4UJADeKU/eaYXsC7GwsgRdUCQAAAAAAIAFJe")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5e52
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "AJ9DGDO3BQiX4UJADeKU/eaYXsC7GwsgRdUCQAAAAAAIAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 2.354135752047538
    
    assert dictify(msg.lat) == 37.762421610632735
    
    assert dictify(msg.lon) == -122.38909854449612
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084800
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 8, 'sender': 1219, 'msg_type': 513, 'lon': -122.38909854449612, 'tow': 407084800, 'height': 2.354135752047538, 'crc': 24146, 'length': 34, 'flags': 0, 'h_accuracy': 0, 'lat': 37.762421610632735, 'preamble': 85, 'payload': 'AJ9DGDO3BQiX4UJADeKU/eaYXsC7GwsgRdUCQAAAAAAIAA=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_10():
    buf = base64.standard_b64decode("VQECwwQiZJ9DGBZNkhaX4UJAQIZp4+aYXsAlY3JIH2fxPwAAAAAIAEY8")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x3c46
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "ZJ9DGBZNkhaX4UJAQIZp4+aYXsAlY3JIH2fxPwAAAAAIAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 1.0876763181642641
    
    assert dictify(msg.lat) == 37.76242334502801
    
    assert dictify(msg.lon) == -122.38909230523223
    
    assert dictify(msg.n_sats) == 8
    
    assert dictify(msg.tow) == 407084900
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 8, 'sender': 1219, 'msg_type': 513, 'lon': -122.38909230523223, 'tow': 407084900, 'height': 1.0876763181642641, 'crc': 15430, 'length': 34, 'flags': 0, 'h_accuracy': 0, 'lat': 37.76242334502801, 'preamble': 85, 'payload': 'ZJ9DGBZNkhaX4UJAQIZp4+aYXsAlY3JIH2fxPwAAAAAIAA=='}

def test_auto_check_sbp_navigation_msg_pos_llh_dep_a_11():
    buf = base64.standard_b64decode("VQECwwQiLqJEGHz1LqmX4UJAh5Xqu+aYXsDCyXORpq8UQAAAAAAFANR5")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x79d4
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x201
    
    assert msg.payload == "LqJEGHz1LqmX4UJAh5Xqu+aYXsDCyXORpq8UQAAAAAAFAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.h_accuracy) == 0
    
    assert dictify(msg.height) == 5.171533844654222
    
    assert dictify(msg.lat) == 37.76244082253376
    
    assert dictify(msg.lon) == -122.38908288868525
    
    assert dictify(msg.n_sats) == 5
    
    assert dictify(msg.tow) == 407151150
    
    assert dictify(msg.v_accuracy) == 0

    assert dictify(msg) == {'v_accuracy': 0, 'n_sats': 5, 'sender': 1219, 'msg_type': 513, 'lon': -122.38908288868525, 'tow': 407151150, 'height': 5.171533844654222, 'crc': 31188, 'length': 34, 'flags': 0, 'h_accuracy': 0, 'lat': 37.76244082253376, 'preamble': 85, 'payload': 'LqJEGHz1LqmX4UJAh5Xqu+aYXsDCyXORpq8UQAAAAAAFAA=='}