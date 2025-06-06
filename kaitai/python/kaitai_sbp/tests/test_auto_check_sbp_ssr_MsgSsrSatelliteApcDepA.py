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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApcDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_satellite_apc_dep_a_1():
    buf = base64.standard_b64decode("VQQGOBPgy6nwTgTVq/7W1AQIIR9QFQRp4SeLfJUwD9bFjSAhh5aUezGHYSdaFKnvL5mvI5GRe8ICZkqVX6vu+Qftqn1qnlO8tcIbVOKOe03Z+EPXgXKKGfAKOEw9odgWta4hDfzs5sSA1+/qs9ws1DksrTEkifjrYXCdixpzwB9Vf+RR/Nv5bpMIodfUtBlTkPcMG8etShcE72ff3Itbf9ZWMMvkYy1Tnwv6h6oq2cfpKqpOzikrUfdjxpAChALg3JQ6VYrSyJ4HnkMuyIR28Q0lPmv9vohCCVSbVrQpxCh3ZfzfkJkyDQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x0d32
    
    assert msg.length == 224
    
    assert msg.msg_type == 0x604
    
    assert msg.payload == "y6nwTgTVq/7W1AQIIR9QFQRp4SeLfJUwD9bFjSAhh5aUezGHYSdaFKnvL5mvI5GRe8ICZkqVX6vu+Qftqn1qnlO8tcIbVOKOe03Z+EPXgXKKGfAKOEw9odgWta4hDfzs5sSA1+/qs9ws1DksrTEkifjrYXCdixpzwB9Vf+RR/Nv5bpMIodfUtBlTkPcMG8etShcE72ff3Itbf9ZWMMvkYy1Tnwv6h6oq2cfpKqpOzikrUfdjxpAChALg3JQ6VYrSyJ4HnkMuyIR28Q0lPmv9vohCCVSbVrQpxCh3ZfzfkJk="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1338
    
    assert dictify(msg.apc) == [{'pco': [-21547, -10498, 1236], 'pcv': [8, 33, 31, 80, 21, 4, 105, -31, 39, -117, 124, -107, 48, 15, -42, -59, -115, 32, 33, -121, -106], 'sat_info': 240, 'sid': {'code': 169, 'sat': 203}, 'svn': 1102}, {'pco': [23079, -22252, 12271], 'pcv': [-103, -81, 35, -111, -111, 123, -62, 2, 102, 74, -107, 95, -85, -18, -7, 7, -19, -86, 125, 106, -98], 'sat_info': 49, 'sid': {'code': 123, 'sat': 148}, 'svn': 24967}, {'pco': [-7596, 31630, -9907], 'pcv': [-8, 67, -41, -127, 114, -118, 25, -16, 10, 56, 76, 61, -95, -40, 22, -75, -82, 33, 13, -4, -20], 'sat_info': 181, 'sid': {'code': 188, 'sat': 83}, 'svn': 7106}, {'pco': [-19478, 11484, 14804], 'pcv': [44, -83, 49, 36, -119, -8, -21, 97, 112, -99, -117, 26, 115, -64, 31, 85, 127, -28, 81, -4, -37], 'sat_info': 128, 'sid': {'code': 196, 'sat': 230}, 'svn': 61399}, {'pco': [-11049, 6580, -28589], 'pcv': [-9, 12, 27, -57, -83, 74, 23, 4, -17, 103, -33, -36, -117, 91, 127, -42, 86, 48, -53, -28, 99], 'sat_info': 147, 'sid': {'code': 110, 'sat': 249}, 'svn': 41224}, {'pco': [-21881, -9942, -5689], 'pcv': [42, -86, 78, -50, 41, 43, 81, -9, 99, -58, -112, 2, -124, 2, -32, -36, -108, 58, 85, -118, -46], 'sat_info': 159, 'sid': {'code': 83, 'sat': 45}, 'svn': 64011}, {'pco': [-14290, 30340, 3569], 'pcv': [37, 62, 107, -3, -66, -120, 66, 9, 84, -101, 86, -76, 41, -60, 40, 119, 101, -4, -33, -112, -103], 'sat_info': 7, 'sid': {'code': 158, 'sat': 200}, 'svn': 17310}]

    assert dictify(msg) == {'crc': 3378, 'length': 224, 'msg_type': 1540, 'payload': 'y6nwTgTVq/7W1AQIIR9QFQRp4SeLfJUwD9bFjSAhh5aUezGHYSdaFKnvL5mvI5GRe8ICZkqVX6vu+Qftqn1qnlO8tcIbVOKOe03Z+EPXgXKKGfAKOEw9odgWta4hDfzs5sSA1+/qs9ws1DksrTEkifjrYXCdixpzwB9Vf+RR/Nv5bpMIodfUtBlTkPcMG8etShcE72ff3Itbf9ZWMMvkYy1Tnwv6h6oq2cfpKqpOzikrUfdjxpAChALg3JQ6VYrSyJ4HnkMuyIR28Q0lPmv9vohCCVSbVrQpxCh3ZfzfkJk=', 'preamble': 85, 'sender': 4920, 'apc': [{'sid': {'sat': 203, 'code': 169}, 'sat_info': 240, 'svn': 1102, 'pco': [-21547, -10498, 1236], 'pcv': [8, 33, 31, 80, 21, 4, 105, -31, 39, -117, 124, -107, 48, 15, -42, -59, -115, 32, 33, -121, -106]}, {'sid': {'sat': 148, 'code': 123}, 'sat_info': 49, 'svn': 24967, 'pco': [23079, -22252, 12271], 'pcv': [-103, -81, 35, -111, -111, 123, -62, 2, 102, 74, -107, 95, -85, -18, -7, 7, -19, -86, 125, 106, -98]}, {'sid': {'sat': 83, 'code': 188}, 'sat_info': 181, 'svn': 7106, 'pco': [-7596, 31630, -9907], 'pcv': [-8, 67, -41, -127, 114, -118, 25, -16, 10, 56, 76, 61, -95, -40, 22, -75, -82, 33, 13, -4, -20]}, {'sid': {'sat': 230, 'code': 196}, 'sat_info': 128, 'svn': 61399, 'pco': [-19478, 11484, 14804], 'pcv': [44, -83, 49, 36, -119, -8, -21, 97, 112, -99, -117, 26, 115, -64, 31, 85, 127, -28, 81, -4, -37]}, {'sid': {'sat': 249, 'code': 110}, 'sat_info': 147, 'svn': 41224, 'pco': [-11049, 6580, -28589], 'pcv': [-9, 12, 27, -57, -83, 74, 23, 4, -17, 103, -33, -36, -117, 91, 127, -42, 86, 48, -53, -28, 99]}, {'sid': {'sat': 45, 'code': 83}, 'sat_info': 159, 'svn': 64011, 'pco': [-21881, -9942, -5689], 'pcv': [42, -86, 78, -50, 41, 43, 81, -9, 99, -58, -112, 2, -124, 2, -32, -36, -108, 58, 85, -118, -46]}, {'sid': {'sat': 200, 'code': 158}, 'sat_info': 7, 'svn': 17310, 'pco': [-14290, 30340, 3569], 'pcv': [37, 62, 107, -3, -66, -120, 66, 9, 84, -101, 86, -76, 41, -60, 40, 119, 101, -4, -33, -112, -103]}]}
