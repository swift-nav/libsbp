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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgtrackingStateDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msgtracking_state_dep_a_1():
    buf = base64.standard_b64decode("VRYAwwRCAQDMsTNBAQLGBCdBAQPbthtBAQeEeGVBAQpbW/tAAQ0qJaNAARaCuNdAAR5zNUtBAR8QSn5BARmExIdAAQZkO99AEeE=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe111
    
    assert msg.length == 66
    
    assert msg.msg_type == 0x16
    
    assert msg.payload == "AQDMsTNBAQLGBCdBAQPbthtBAQeEeGVBAQpbW/tAAQ0qJaNAARaCuNdAAR5zNUtBAR8QSn5BARmExIdAAQZkO99A"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.states) == [{'cn0': 11.230907440185547, 'prn': 0, 'state': 1}, {'cn0': 10.438665390014648, 'prn': 2, 'state': 1}, {'cn0': 9.732142448425293, 'prn': 3, 'state': 1}, {'cn0': 14.341922760009766, 'prn': 7, 'state': 1}, {'cn0': 7.8549017906188965, 'prn': 10, 'state': 1}, {'cn0': 5.0982866287231445, 'prn': 13, 'state': 1}, {'cn0': 6.741272926330566, 'prn': 22, 'state': 1}, {'cn0': 12.700549125671387, 'prn': 30, 'state': 1}, {'cn0': 15.893081665039062, 'prn': 31, 'state': 1}, {'cn0': 4.242738723754883, 'prn': 25, 'state': 1}, {'cn0': 6.97599983215332, 'prn': 6, 'state': 1}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 22, 'states': [{'state': 1, 'prn': 0, 'cn0': 11.230907440185547}, {'state': 1, 'prn': 2, 'cn0': 10.438665390014648}, {'state': 1, 'prn': 3, 'cn0': 9.732142448425293}, {'state': 1, 'prn': 7, 'cn0': 14.341922760009766}, {'state': 1, 'prn': 10, 'cn0': 7.8549017906188965}, {'state': 1, 'prn': 13, 'cn0': 5.0982866287231445}, {'state': 1, 'prn': 22, 'cn0': 6.741272926330566}, {'state': 1, 'prn': 30, 'cn0': 12.700549125671387}, {'state': 1, 'prn': 31, 'cn0': 15.893081665039062}, {'state': 1, 'prn': 25, 'cn0': 4.242738723754883}, {'state': 1, 'prn': 6, 'cn0': 6.97599983215332}], 'crc': 57617, 'length': 66, 'preamble': 85, 'payload': 'AQDMsTNBAQLGBCdBAQPbthtBAQeEeGVBAQpbW/tAAQ0qJaNAARaCuNdAAR5zNUtBAR8QSn5BARmExIdAAQZkO99A'}

def test_auto_check_sbp_tracking_msgtracking_state_dep_a_2():
    buf = base64.standard_b64decode("VRYAwwRCAQDYOTBBAQKRKS5BAQMEGiJBAQexQ21BAQo9UPlAAQ36x5tAARY3E9dAAR6Kik9BAR/Ws3dBARk1inhAAQa394FAqK0=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xada8
    
    assert msg.length == 66
    
    assert msg.msg_type == 0x16
    
    assert msg.payload == "AQDYOTBBAQKRKS5BAQMEGiJBAQexQ21BAQo9UPlAAQ36x5tAARY3E9dAAR6Kik9BAR/Ws3dBARk1inhAAQa394FA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.states) == [{'cn0': 11.014122009277344, 'prn': 0, 'state': 1}, {'cn0': 10.885148048400879, 'prn': 2, 'state': 1}, {'cn0': 10.131351470947266, 'prn': 3, 'state': 1}, {'cn0': 14.829026222229004, 'prn': 7, 'state': 1}, {'cn0': 7.79104471206665, 'prn': 10, 'state': 1}, {'cn0': 4.868161201477051, 'prn': 13, 'state': 1}, {'cn0': 6.721095561981201, 'prn': 22, 'state': 1}, {'cn0': 12.971323013305664, 'prn': 30, 'state': 1}, {'cn0': 15.481405258178711, 'prn': 31, 'state': 1}, {'cn0': 3.8834354877471924, 'prn': 25, 'state': 1}, {'cn0': 4.061488628387451, 'prn': 6, 'state': 1}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 22, 'states': [{'state': 1, 'prn': 0, 'cn0': 11.014122009277344}, {'state': 1, 'prn': 2, 'cn0': 10.885148048400879}, {'state': 1, 'prn': 3, 'cn0': 10.131351470947266}, {'state': 1, 'prn': 7, 'cn0': 14.829026222229004}, {'state': 1, 'prn': 10, 'cn0': 7.79104471206665}, {'state': 1, 'prn': 13, 'cn0': 4.868161201477051}, {'state': 1, 'prn': 22, 'cn0': 6.721095561981201}, {'state': 1, 'prn': 30, 'cn0': 12.971323013305664}, {'state': 1, 'prn': 31, 'cn0': 15.481405258178711}, {'state': 1, 'prn': 25, 'cn0': 3.8834354877471924}, {'state': 1, 'prn': 6, 'cn0': 4.061488628387451}], 'crc': 44456, 'length': 66, 'preamble': 85, 'payload': 'AQDYOTBBAQKRKS5BAQMEGiJBAQexQ21BAQo9UPlAAQ36x5tAARY3E9dAAR6Kik9BAR/Ws3dBARk1inhAAQa394FA'}

def test_auto_check_sbp_tracking_msgtracking_state_dep_a_3():
    buf = base64.standard_b64decode("VRYAwwRCAQCNTDxBAQJFiy5BAQOSGx5BAQfrOGFBAQqN1fNAAQ36qqZAARYRZclAAR6st1NBAR/uwXhBARncMIRAAQYx1jZAbrM=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb36e
    
    assert msg.length == 66
    
    assert msg.msg_type == 0x16
    
    assert msg.payload == "AQCNTDxBAQJFiy5BAQOSGx5BAQfrOGFBAQqN1fNAAQ36qqZAARYRZclAAR6st1NBAR/uwXhBARncMIRAAQYx1jZA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.states) == [{'cn0': 11.768689155578613, 'prn': 0, 'state': 1}, {'cn0': 10.909001350402832, 'prn': 2, 'state': 1}, {'cn0': 9.881731033325195, 'prn': 3, 'state': 1}, {'cn0': 14.076395988464355, 'prn': 7, 'state': 1}, {'cn0': 7.619818210601807, 'prn': 10, 'state': 1}, {'cn0': 5.208371162414551, 'prn': 13, 'state': 1}, {'cn0': 6.2935872077941895, 'prn': 22, 'state': 1}, {'cn0': 13.232341766357422, 'prn': 30, 'state': 1}, {'cn0': 15.547346115112305, 'prn': 31, 'state': 1}, {'cn0': 4.130964279174805, 'prn': 25, 'state': 1}, {'cn0': 2.856823205947876, 'prn': 6, 'state': 1}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 22, 'states': [{'state': 1, 'prn': 0, 'cn0': 11.768689155578613}, {'state': 1, 'prn': 2, 'cn0': 10.909001350402832}, {'state': 1, 'prn': 3, 'cn0': 9.881731033325195}, {'state': 1, 'prn': 7, 'cn0': 14.076395988464355}, {'state': 1, 'prn': 10, 'cn0': 7.619818210601807}, {'state': 1, 'prn': 13, 'cn0': 5.208371162414551}, {'state': 1, 'prn': 22, 'cn0': 6.2935872077941895}, {'state': 1, 'prn': 30, 'cn0': 13.232341766357422}, {'state': 1, 'prn': 31, 'cn0': 15.547346115112305}, {'state': 1, 'prn': 25, 'cn0': 4.130964279174805}, {'state': 1, 'prn': 6, 'cn0': 2.856823205947876}], 'crc': 45934, 'length': 66, 'preamble': 85, 'payload': 'AQCNTDxBAQJFiy5BAQOSGx5BAQfrOGFBAQqN1fNAAQ36qqZAARYRZclAAR6st1NBAR/uwXhBARncMIRAAQYx1jZA'}

def test_auto_check_sbp_tracking_msgtracking_state_dep_a_4():
    buf = base64.standard_b64decode("VRYAwwRCAQA3j3hCAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/+Fk=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x59f8
    
    assert msg.length == 66
    
    assert msg.msg_type == 0x16
    
    assert msg.payload == "AQA3j3hCAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.states) == [{'cn0': 62.13985824584961, 'prn': 0, 'state': 1}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 22, 'states': [{'state': 1, 'prn': 0, 'cn0': 62.13985824584961}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}], 'crc': 23032, 'length': 66, 'preamble': 85, 'payload': 'AQA3j3hCAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/'}

def test_auto_check_sbp_tracking_msgtracking_state_dep_a_5():
    buf = base64.standard_b64decode("VRYAwwRCAQDaDhNCAQLSAxVBAQPq1oZBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/VGU=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6554
    
    assert msg.length == 66
    
    assert msg.msg_type == 0x16
    
    assert msg.payload == "AQDaDhNCAQLSAxVBAQPq1oZBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.states) == [{'cn0': 36.764503479003906, 'prn': 0, 'state': 1}, {'cn0': 9.313432693481445, 'prn': 2, 'state': 1}, {'cn0': 16.854938507080078, 'prn': 3, 'state': 1}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 22, 'states': [{'state': 1, 'prn': 0, 'cn0': 36.764503479003906}, {'state': 1, 'prn': 2, 'cn0': 9.313432693481445}, {'state': 1, 'prn': 3, 'cn0': 16.854938507080078}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}], 'crc': 25940, 'length': 66, 'preamble': 85, 'payload': 'AQDaDhNCAQLSAxVBAQPq1oZBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/'}

def test_auto_check_sbp_tracking_msgtracking_state_dep_a_6():
    buf = base64.standard_b64decode("VRYAwwRCAQBiJ9tBAQIAADhAAQN5ewdBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/JXs=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7b25
    
    assert msg.length == 66
    
    assert msg.msg_type == 0x16
    
    assert msg.payload == "AQBiJ9tBAQIAADhAAQN5ewdBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.states) == [{'cn0': 27.394229888916016, 'prn': 0, 'state': 1}, {'cn0': 2.875, 'prn': 2, 'state': 1}, {'cn0': 8.467644691467285, 'prn': 3, 'state': 1}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}, {'cn0': -1.0, 'prn': 0, 'state': 0}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 22, 'states': [{'state': 1, 'prn': 0, 'cn0': 27.394229888916016}, {'state': 1, 'prn': 2, 'cn0': 2.875}, {'state': 1, 'prn': 3, 'cn0': 8.467644691467285}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}, {'state': 0, 'prn': 0, 'cn0': -1.0}], 'crc': 31525, 'length': 66, 'preamble': 85, 'payload': 'AQBiJ9tBAQIAADhAAQN5ewdBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/'}