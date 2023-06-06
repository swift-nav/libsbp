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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_msgObsDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_obs_dep_a_1():
    buf = base64.standard_b64decode("VUUAwwRiOJ5DGC4HIDjr+Xn0cv//IS5D2gDuy0Z8FhkDAGIruJ0CsIXFfX5H/f+5J0Q3AzytooNi5/3/ix4hEAqAsviIKnH9/ygUKkcN9vYRh/8zAwBAG2z5FtIpcnaDMP//HzTiOh4X2Q==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd917
    
    assert msg.length == 98
    
    assert msg.msg_type == 0x45
    
    assert msg.payload == "OJ5DGC4HIDjr+Xn0cv//IS5D2gDuy0Z8FhkDAGIruJ0CsIXFfX5H/f+5J0Q3AzytooNi5/3/ix4hEAqAsviIKnH9/ygUKkcN9vYRh/8zAwBAG2z5FtIpcnaDMP//HzTiOh4="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.header) == {'n_obs': 32, 't': {'tow': 407084600, 'wn': 1838}}
    
    assert dictify(msg.obs) == [{'l': {'f': 33, 'i': -36108}, 'p': 2046421816, 'cn0': 46, 'lock': 55875, 'prn': 0}, {'l': {'f': 98, 'i': 203030}, 'p': 2085014510, 'cn0': 43, 'lock': 40376, 'prn': 2}, {'l': {'f': 185, 'i': -178306}, 'p': 2110096816, 'cn0': 39, 'lock': 14148, 'prn': 3}, {'l': {'f': 139, 'i': -137374}, 'p': 2208476476, 'cn0': 30, 'lock': 4129, 'prn': 10}, {'l': {'f': 40, 'i': -167638}, 'p': 2298000000, 'cn0': 20, 'lock': 18218, 'prn': 13}, {'l': {'f': 64, 'i': 209919}, 'p': 2266101494, 'cn0': 27, 'lock': 63852, 'prn': 22}, {'l': {'f': 31, 'i': -53117}, 'p': 1987193298, 'cn0': 52, 'lock': 15074, 'prn': 30}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 69, 'header': {'n_obs': 32, 't': {'wn': 1838, 'tow': 407084600}}, 'obs': [{'p': 2046421816, 'prn': 0, 'l': {'i': -36108, 'f': 33}, 'cn0': 46, 'lock': 55875}, {'p': 2085014510, 'prn': 2, 'l': {'i': 203030, 'f': 98}, 'cn0': 43, 'lock': 40376}, {'p': 2110096816, 'prn': 3, 'l': {'i': -178306, 'f': 185}, 'cn0': 39, 'lock': 14148}, {'p': 2208476476, 'prn': 10, 'l': {'i': -137374, 'f': 139}, 'cn0': 30, 'lock': 4129}, {'p': 2298000000, 'prn': 13, 'l': {'i': -167638, 'f': 40}, 'cn0': 20, 'lock': 18218}, {'p': 2266101494, 'prn': 22, 'l': {'i': 209919, 'f': 64}, 'cn0': 27, 'lock': 63852}, {'p': 1987193298, 'prn': 30, 'l': {'i': -53117, 'f': 31}, 'cn0': 52, 'lock': 15074}], 'crc': 55575, 'length': 98, 'preamble': 85, 'payload': 'OJ5DGC4HIDjr+Xn0cv//IS5D2gDuy0Z8FhkDAGIruJ0CsIXFfX5H/f+5J0Q3AzytooNi5/3/ix4hEAqAsviIKnH9/ygUKkcN9vYRh/8zAwBAG2z5FtIpcnaDMP//HzTiOh4='}

def test_auto_check_sbp_observation_msg_obs_dep_a_2():
    buf = base64.standard_b64decode("VUUAwwQUOJ5DGC4HIVQ0pHVmIAAAkz4++h/qDg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xeea
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x45
    
    assert msg.payload == "OJ5DGC4HIVQ0pHVmIAAAkz4++h8="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.header) == {'n_obs': 33, 't': {'tow': 407084600, 'wn': 1838}}
    
    assert dictify(msg.obs) == [{'l': {'f': 147, 'i': 8294}, 'p': 1973695572, 'cn0': 62, 'lock': 64062, 'prn': 31}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 69, 'header': {'n_obs': 33, 't': {'wn': 1838, 'tow': 407084600}}, 'obs': [{'p': 1973695572, 'prn': 31, 'l': {'i': 8294, 'f': 147}, 'cn0': 62, 'lock': 64062}], 'crc': 3818, 'length': 20, 'preamble': 85, 'payload': 'OJ5DGC4HIVQ0pHVmIAAAkz4++h8='}

def test_auto_check_sbp_observation_msg_obs_dep_a_3():
    buf = base64.standard_b64decode("VUUAwwRiAJ9DGC4HICDR+XmRcv//jS1D2gCxgEZ8TxsDAJ8suJ0CO4fFfa9F/f9NKEQ3A9OsooOx5f3/FB8hEAqAsviIdG/9/14VKkcNtq0RhyU2AwDWG2z5FlsUcnbwL///gTTiOh7Idw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x77c8
    
    assert msg.length == 98
    
    assert msg.msg_type == 0x45
    
    assert msg.payload == "AJ9DGC4HICDR+XmRcv//jS1D2gCxgEZ8TxsDAJ8suJ0CO4fFfa9F/f9NKEQ3A9OsooOx5f3/FB8hEAqAsviIdG/9/14VKkcNtq0RhyU2AwDWG2z5FlsUcnbwL///gTTiOh4="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.header) == {'n_obs': 32, 't': {'tow': 407084800, 'wn': 1838}}
    
    assert dictify(msg.obs) == [{'l': {'f': 141, 'i': -36207}, 'p': 2046415136, 'cn0': 45, 'lock': 55875, 'prn': 0}, {'l': {'f': 159, 'i': 203599}, 'p': 2084995249, 'cn0': 44, 'lock': 40376, 'prn': 2}, {'l': {'f': 77, 'i': -178769}, 'p': 2110097211, 'cn0': 40, 'lock': 14148, 'prn': 3}, {'l': {'f': 20, 'i': -137807}, 'p': 2208476371, 'cn0': 31, 'lock': 4129, 'prn': 10}, {'l': {'f': 94, 'i': -168076}, 'p': 2298000000, 'cn0': 21, 'lock': 18218, 'prn': 13}, {'l': {'f': 214, 'i': 210469}, 'p': 2266082742, 'cn0': 27, 'lock': 63852, 'prn': 22}, {'l': {'f': 129, 'i': -53264}, 'p': 1987187803, 'cn0': 52, 'lock': 15074, 'prn': 30}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 69, 'header': {'n_obs': 32, 't': {'wn': 1838, 'tow': 407084800}}, 'obs': [{'p': 2046415136, 'prn': 0, 'l': {'i': -36207, 'f': 141}, 'cn0': 45, 'lock': 55875}, {'p': 2084995249, 'prn': 2, 'l': {'i': 203599, 'f': 159}, 'cn0': 44, 'lock': 40376}, {'p': 2110097211, 'prn': 3, 'l': {'i': -178769, 'f': 77}, 'cn0': 40, 'lock': 14148}, {'p': 2208476371, 'prn': 10, 'l': {'i': -137807, 'f': 20}, 'cn0': 31, 'lock': 4129}, {'p': 2298000000, 'prn': 13, 'l': {'i': -168076, 'f': 94}, 'cn0': 21, 'lock': 18218}, {'p': 2266082742, 'prn': 22, 'l': {'i': 210469, 'f': 214}, 'cn0': 27, 'lock': 63852}, {'p': 1987187803, 'prn': 30, 'l': {'i': -53264, 'f': 129}, 'cn0': 52, 'lock': 15074}], 'crc': 30664, 'length': 98, 'preamble': 85, 'payload': 'AJ9DGC4HICDR+XmRcv//jS1D2gCxgEZ8TxsDAJ8suJ0CO4fFfa9F/f9NKEQ3A9OsooOx5f3/FB8hEAqAsviIdG/9/14VKkcNtq0RhyU2AwDWG2z5FlsUcnbwL///gTTiOh4='}

def test_auto_check_sbp_observation_msg_obs_dep_a_4():
    buf = base64.standard_b64decode("VUUAwwQUAJ9DGC4HITETpHV4IAAA3j8++h8L5w==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe70b
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x45
    
    assert msg.payload == "AJ9DGC4HITETpHV4IAAA3j8++h8="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.header) == {'n_obs': 33, 't': {'tow': 407084800, 'wn': 1838}}
    
    assert dictify(msg.obs) == [{'l': {'f': 222, 'i': 8312}, 'p': 1973687089, 'cn0': 63, 'lock': 64062, 'prn': 31}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 69, 'header': {'n_obs': 33, 't': {'wn': 1838, 'tow': 407084800}}, 'obs': [{'p': 1973687089, 'prn': 31, 'l': {'i': 8312, 'f': 222}, 'cn0': 63, 'lock': 64062}], 'crc': 59147, 'length': 20, 'preamble': 85, 'payload': 'AJ9DGC4HITETpHV4IAAA3j8++h8='}

def test_auto_check_sbp_observation_msg_obs_dep_a_5():
    buf = base64.standard_b64decode("VUUAwwRIYKJEGC4HEFeE2Xl5lP//vSuvkwCEQMh9ah/+/wEpDrEDgLL4iEZE/v+mEriFDRh/soYGGQIA+RwhYBaqaFZ2Q3D//8s40FgeK2s=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6b2b
    
    assert msg.length == 72
    
    assert msg.msg_type == 0x45
    
    assert msg.payload == "YKJEGC4HEFeE2Xl5lP//vSuvkwCEQMh9ah/+/wEpDrEDgLL4iEZE/v+mEriFDRh/soYGGQIA+RwhYBaqaFZ2Q3D//8s40Fge"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.header) == {'n_obs': 16, 't': {'tow': 407151200, 'wn': 1838}}
    
    assert dictify(msg.obs) == [{'l': {'f': 189, 'i': -27527}, 'p': 2044298327, 'cn0': 43, 'lock': 37807, 'prn': 0}, {'l': {'f': 1, 'i': -123030}, 'p': 2110275716, 'cn0': 41, 'lock': 45326, 'prn': 3}, {'l': {'f': 166, 'i': -113594}, 'p': 2298000000, 'cn0': 18, 'lock': 34232, 'prn': 13}, {'l': {'f': 249, 'i': 137478}, 'p': 2259844888, 'cn0': 28, 'lock': 24609, 'prn': 22}, {'l': {'f': 203, 'i': -36797}, 'p': 1985374378, 'cn0': 56, 'lock': 22736, 'prn': 30}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 69, 'header': {'n_obs': 16, 't': {'wn': 1838, 'tow': 407151200}}, 'obs': [{'p': 2044298327, 'prn': 0, 'l': {'i': -27527, 'f': 189}, 'cn0': 43, 'lock': 37807}, {'p': 2110275716, 'prn': 3, 'l': {'i': -123030, 'f': 1}, 'cn0': 41, 'lock': 45326}, {'p': 2298000000, 'prn': 13, 'l': {'i': -113594, 'f': 166}, 'cn0': 18, 'lock': 34232}, {'p': 2259844888, 'prn': 22, 'l': {'i': 137478, 'f': 249}, 'cn0': 28, 'lock': 24609}, {'p': 1985374378, 'prn': 30, 'l': {'i': -36797, 'f': 203}, 'cn0': 56, 'lock': 22736}], 'crc': 27435, 'length': 72, 'preamble': 85, 'payload': 'YKJEGC4HEFeE2Xl5lP//vSuvkwCEQMh9ah/+/wEpDrEDgLL4iEZE/v+mEriFDRh/soYGGQIA+RwhYBaqaFZ2Q3D//8s40Fge'}

def test_auto_check_sbp_observation_msg_obs_dep_a_6():
    buf = base64.standard_b64decode("VUUAwwRIKKNEGC4HEIRr2XkOlP//ASyvkwCBQsh9lB3+/5kpDrEDgLL4iI9C/v/eEriFDZ41soYqGwIA7R4hYBYmU1Z2qG///y040FgeAa8=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xaf01
    
    assert msg.length == 72
    
    assert msg.msg_type == 0x45
    
    assert msg.payload == "KKNEGC4HEIRr2XkOlP//ASyvkwCBQsh9lB3+/5kpDrEDgLL4iI9C/v/eEriFDZ41soYqGwIA7R4hYBYmU1Z2qG///y040Fge"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.header) == {'n_obs': 16, 't': {'tow': 407151400, 'wn': 1838}}
    
    assert dictify(msg.obs) == [{'l': {'f': 1, 'i': -27634}, 'p': 2044291972, 'cn0': 44, 'lock': 37807, 'prn': 0}, {'l': {'f': 153, 'i': -123500}, 'p': 2110276225, 'cn0': 41, 'lock': 45326, 'prn': 3}, {'l': {'f': 222, 'i': -114033}, 'p': 2298000000, 'cn0': 18, 'lock': 34232, 'prn': 13}, {'l': {'f': 237, 'i': 138026}, 'p': 2259826078, 'cn0': 30, 'lock': 24609, 'prn': 22}, {'l': {'f': 45, 'i': -36952}, 'p': 1985368870, 'cn0': 56, 'lock': 22736, 'prn': 30}]

    assert dictify(msg) == {'sender': 1219, 'msg_type': 69, 'header': {'n_obs': 16, 't': {'wn': 1838, 'tow': 407151400}}, 'obs': [{'p': 2044291972, 'prn': 0, 'l': {'i': -27634, 'f': 1}, 'cn0': 44, 'lock': 37807}, {'p': 2110276225, 'prn': 3, 'l': {'i': -123500, 'f': 153}, 'cn0': 41, 'lock': 45326}, {'p': 2298000000, 'prn': 13, 'l': {'i': -114033, 'f': 222}, 'cn0': 18, 'lock': 34232}, {'p': 2259826078, 'prn': 22, 'l': {'i': 138026, 'f': 237}, 'cn0': 30, 'lock': 24609}, {'p': 1985368870, 'prn': 30, 'l': {'i': -36952, 'f': 45}, 'cn0': 56, 'lock': 22736}], 'crc': 44801, 'length': 72, 'preamble': 85, 'payload': 'KKNEGC4HEIRr2XkOlP//ASyvkwCBQsh9lB3+/5kpDrEDgLL4iI9C/v/eEriFDZ41soYqGwIA7R4hYBYmU1Z2qG///y040Fge'}