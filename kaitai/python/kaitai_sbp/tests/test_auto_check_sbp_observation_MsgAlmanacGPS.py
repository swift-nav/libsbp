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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGPS.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_almanac_gps_1():
    buf = base64.standard_b64decode("VXIAwwReFgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/AAAAAGyxRL8AAAAAAMCjPb4t")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2dbe
    
    assert msg.length == 94
    
    assert msg.msg_type == 0x72
    
    assert msg.payload == "FgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/AAAAAGyxRL8AAAAAAMCjPQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.af0) == -0.0006315018981695175
    
    assert dictify(msg.af1) == 8.981260180007666e-12
    
    assert dictify(msg.common) == {'fit_interval': 14400, 'health_bits': 0, 'sid': {'code': 0, 'sat': 22}, 'toa': {'tow': 446384, 'wn': 2154}, 'ura': 2.2, 'valid': 1}
    
    assert dictify(msg.ecc) == 0.007072207052260637
    
    assert dictify(msg.inc) == 0.9341514480259797
    
    assert dictify(msg.m0) == -0.02200078842114688
    
    assert dictify(msg.omega0) == -1.8731818448797617
    
    assert dictify(msg.omegadot) == -8.903585155774196e-09
    
    assert dictify(msg.sqrta) == 5153.550029754639
    
    assert dictify(msg.w) == -0.9893036629599647

    assert dictify(msg) == {'preamble': 85, 'msg_type': 114, 'sender': 1219, 'length': 94, 'payload': 'FgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/AAAAAGyxRL8AAAAAAMCjPQ==', 'crc': 11710, 'common': {'sid': {'sat': 22, 'code': 0}, 'toa': {'tow': 446384, 'wn': 2154}, 'ura': 2.2, 'fit_interval': 14400, 'valid': 1, 'health_bits': 0}, 'm0': -0.02200078842114688, 'ecc': 0.007072207052260637, 'sqrta': 5153.550029754639, 'omega0': -1.8731818448797617, 'omegadot': -8.903585155774196e-09, 'w': -0.9893036629599647, 'inc': 0.9341514480259797, 'af0': -0.0006315018981695175, 'af1': 8.981260180007666e-12}
