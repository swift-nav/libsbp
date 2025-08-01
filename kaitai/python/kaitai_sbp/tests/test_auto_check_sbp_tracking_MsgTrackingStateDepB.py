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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDepB.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msg_tracking_state_dep_b_1():
    buf = base64.standard_b64decode("VRMA8vH8c7fjP0SaAbdF/695K94zQyNFTvAFNRQz0zZFmYLtQpsz40dFNfKIob7NvAZGmX3/jpWa2bhF+GZfH0yaIalFg3ONGwya4chF0CyTJxczA0JF7Z/7McszY2ZFRtZXgM6aebpFDs5v2hOaealF2GLRNgKaGdtDyIVjByJmxuhEmytVhy6asapFmwNTq8ma8ehFeSvFEBOa8d5FgPU1P7Azc0JFJBQ9mTOaSYZFLlJ0jBYzkyVFsUOSYI/NTGtE3DOgyftmZsBEqMICodxmZrRERQgJfbJmRoZEuRSHuqszowRFEnybVarN0A1GOfTO/7qaaZVFpcddta8zQ0BFBhw=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1c06
    
    assert msg.length == 252
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "c7fjP0SaAbdF/695K94zQyNFTvAFNRQz0zZFmYLtQpsz40dFNfKIob7NvAZGmX3/jpWa2bhF+GZfH0yaIalFg3ONGwya4chF0CyTJxczA0JF7Z/7McszY2ZFRtZXgM6aebpFDs5v2hOaealF2GLRNgKaGdtDyIVjByJmxuhEmytVhy6asapFmwNTq8ma8ehFeSvFEBOa8d5FgPU1P7Azc0JFJBQ9mTOaSYZFLlJ0jBYzkyVFsUOSYI/NTGtE3DOgyftmZsBEqMICodxmZrRERQgJfbJmRoZEuRSHuqszowRFEnybVarN0A1GOfTO/7qaaZVFpcddta8zQ0BF"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xf1f2
    
    assert dictify(msg.states) == [{'cn0': 5856.2001953125, 'sid': {'code': 63, 'reserved': 68, 'sat': 58295}, 'state': 115}, {'cn0': 2612.199951171875, 'sid': {'code': 43, 'reserved': 222, 'sat': 31151}, 'state': 255}, {'cn0': 2925.199951171875, 'sid': {'code': 53, 'reserved': 20, 'sat': 1520}, 'state': 78}, {'cn0': 3198.199951171875, 'sid': {'code': 66, 'reserved': 155, 'sat': 60802}, 'state': 153}, {'cn0': 8623.2001953125, 'sid': {'code': 161, 'reserved': 190, 'sat': 35058}, 'state': 53}, {'cn0': 5915.2001953125, 'sid': {'code': 142, 'reserved': 149, 'sat': 65405}, 'state': 153}, {'cn0': 5412.2001953125, 'sid': {'code': 31, 'reserved': 76, 'sat': 24422}, 'state': 248}, {'cn0': 6428.2001953125, 'sid': {'code': 27, 'reserved': 12, 'sat': 36211}, 'state': 131}, {'cn0': 3104.199951171875, 'sid': {'code': 39, 'reserved': 23, 'sat': 37676}, 'state': 208}, {'cn0': 3686.199951171875, 'sid': {'code': 49, 'reserved': 203, 'sat': 64415}, 'state': 237}, {'cn0': 5967.2001953125, 'sid': {'code': 128, 'reserved': 206, 'sat': 22486}, 'state': 70}, {'cn0': 5423.2001953125, 'sid': {'code': 218, 'reserved': 19, 'sat': 28622}, 'state': 14}, {'cn0': 438.20001220703125, 'sid': {'code': 54, 'reserved': 2, 'sat': 53602}, 'state': 216}, {'cn0': 1862.199951171875, 'sid': {'code': 7, 'reserved': 34, 'sat': 25477}, 'state': 200}, {'cn0': 5462.2001953125, 'sid': {'code': 135, 'reserved': 46, 'sat': 21803}, 'state': 155}, {'cn0': 7454.2001953125, 'sid': {'code': 171, 'reserved': 201, 'sat': 21251}, 'state': 155}, {'cn0': 7134.2001953125, 'sid': {'code': 16, 'reserved': 19, 'sat': 50475}, 'state': 121}, {'cn0': 3111.199951171875, 'sid': {'code': 63, 'reserved': 176, 'sat': 13813}, 'state': 128}, {'cn0': 4297.2001953125, 'sid': {'code': 153, 'reserved': 51, 'sat': 15636}, 'state': 36}, {'cn0': 2649.199951171875, 'sid': {'code': 140, 'reserved': 22, 'sat': 29778}, 'state': 46}, {'cn0': 941.2000122070312, 'sid': {'code': 96, 'reserved': 143, 'sat': 37443}, 'state': 177}, {'cn0': 1539.199951171875, 'sid': {'code': 201, 'reserved': 251, 'sat': 41011}, 'state': 220}, {'cn0': 1443.199951171875, 'sid': {'code': 161, 'reserved': 220, 'sat': 706}, 'state': 168}, {'cn0': 1074.199951171875, 'sid': {'code': 125, 'reserved': 178, 'sat': 2312}, 'state': 69}, {'cn0': 2122.199951171875, 'sid': {'code': 186, 'reserved': 171, 'sat': 34580}, 'state': 185}, {'cn0': 9076.2001953125, 'sid': {'code': 85, 'reserved': 170, 'sat': 39804}, 'state': 18}, {'cn0': 4781.2001953125, 'sid': {'code': 255, 'reserved': 186, 'sat': 52980}, 'state': 57}, {'cn0': 3076.199951171875, 'sid': {'code': 181, 'reserved': 175, 'sat': 24007}, 'state': 165}]

    assert dictify(msg) == {'preamble': 85, 'msg_type': 19, 'sender': 61938, 'length': 252, 'payload': 'c7fjP0SaAbdF/695K94zQyNFTvAFNRQz0zZFmYLtQpsz40dFNfKIob7NvAZGmX3/jpWa2bhF+GZfH0yaIalFg3ONGwya4chF0CyTJxczA0JF7Z/7McszY2ZFRtZXgM6aebpFDs5v2hOaealF2GLRNgKaGdtDyIVjByJmxuhEmytVhy6asapFmwNTq8ma8ehFeSvFEBOa8d5FgPU1P7Azc0JFJBQ9mTOaSYZFLlJ0jBYzkyVFsUOSYI/NTGtE3DOgyftmZsBEqMICodxmZrRERQgJfbJmRoZEuRSHuqszowRFEnybVarN0A1GOfTO/7qaaZVFpcddta8zQ0BF', 'crc': 7174, 'states': [{'state': 115, 'sid': {'sat': 58295, 'code': 63, 'reserved': 68}, 'cn0': 5856.2001953125}, {'state': 255, 'sid': {'sat': 31151, 'code': 43, 'reserved': 222}, 'cn0': 2612.199951171875}, {'state': 78, 'sid': {'sat': 1520, 'code': 53, 'reserved': 20}, 'cn0': 2925.199951171875}, {'state': 153, 'sid': {'sat': 60802, 'code': 66, 'reserved': 155}, 'cn0': 3198.199951171875}, {'state': 53, 'sid': {'sat': 35058, 'code': 161, 'reserved': 190}, 'cn0': 8623.2001953125}, {'state': 153, 'sid': {'sat': 65405, 'code': 142, 'reserved': 149}, 'cn0': 5915.2001953125}, {'state': 248, 'sid': {'sat': 24422, 'code': 31, 'reserved': 76}, 'cn0': 5412.2001953125}, {'state': 131, 'sid': {'sat': 36211, 'code': 27, 'reserved': 12}, 'cn0': 6428.2001953125}, {'state': 208, 'sid': {'sat': 37676, 'code': 39, 'reserved': 23}, 'cn0': 3104.199951171875}, {'state': 237, 'sid': {'sat': 64415, 'code': 49, 'reserved': 203}, 'cn0': 3686.199951171875}, {'state': 70, 'sid': {'sat': 22486, 'code': 128, 'reserved': 206}, 'cn0': 5967.2001953125}, {'state': 14, 'sid': {'sat': 28622, 'code': 218, 'reserved': 19}, 'cn0': 5423.2001953125}, {'state': 216, 'sid': {'sat': 53602, 'code': 54, 'reserved': 2}, 'cn0': 438.20001220703125}, {'state': 200, 'sid': {'sat': 25477, 'code': 7, 'reserved': 34}, 'cn0': 1862.199951171875}, {'state': 155, 'sid': {'sat': 21803, 'code': 135, 'reserved': 46}, 'cn0': 5462.2001953125}, {'state': 155, 'sid': {'sat': 21251, 'code': 171, 'reserved': 201}, 'cn0': 7454.2001953125}, {'state': 121, 'sid': {'sat': 50475, 'code': 16, 'reserved': 19}, 'cn0': 7134.2001953125}, {'state': 128, 'sid': {'sat': 13813, 'code': 63, 'reserved': 176}, 'cn0': 3111.199951171875}, {'state': 36, 'sid': {'sat': 15636, 'code': 153, 'reserved': 51}, 'cn0': 4297.2001953125}, {'state': 46, 'sid': {'sat': 29778, 'code': 140, 'reserved': 22}, 'cn0': 2649.199951171875}, {'state': 177, 'sid': {'sat': 37443, 'code': 96, 'reserved': 143}, 'cn0': 941.2000122070312}, {'state': 220, 'sid': {'sat': 41011, 'code': 201, 'reserved': 251}, 'cn0': 1539.199951171875}, {'state': 168, 'sid': {'sat': 706, 'code': 161, 'reserved': 220}, 'cn0': 1443.199951171875}, {'state': 69, 'sid': {'sat': 2312, 'code': 125, 'reserved': 178}, 'cn0': 1074.199951171875}, {'state': 185, 'sid': {'sat': 34580, 'code': 186, 'reserved': 171}, 'cn0': 2122.199951171875}, {'state': 18, 'sid': {'sat': 39804, 'code': 85, 'reserved': 170}, 'cn0': 9076.2001953125}, {'state': 57, 'sid': {'sat': 52980, 'code': 255, 'reserved': 186}, 'cn0': 4781.2001953125}, {'state': 165, 'sid': {'sat': 24007, 'code': 181, 'reserved': 175}, 'cn0': 3076.199951171875}]}
