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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGLO.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_almanac_glo_1():
    buf = base64.standard_b64decode("VXMAwwROFgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/m1c=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x579b
    
    assert msg.length == 78
    
    assert msg.msg_type == 0x73
    
    assert msg.payload == "FgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.common) == {'fit_interval': 14400, 'health_bits': 0, 'sid': {'code': 0, 'sat': 22}, 'toa': {'tow': 446384, 'wn': 2154}, 'ura': 2.2, 'valid': 1}
    
    assert dictify(msg.epsilon) == -0.9893036629599647
    
    assert dictify(msg.i) == 5153.550029754639
    
    assert dictify(msg.lambda_na) == -0.02200078842114688
    
    assert dictify(msg.omega) == 0.9341514480259797
    
    assert dictify(msg.t) == -1.8731818448797617
    
    assert dictify(msg.t_dot) == -8.903585155774196e-09
    
    assert dictify(msg.t_lambda_na) == 0.007072207052260637

    assert dictify(msg) == {'preamble': 85, 'msg_type': 115, 'sender': 1219, 'length': 78, 'payload': 'FgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/', 'crc': 22427, 'common': {'sid': {'sat': 22, 'code': 0}, 'toa': {'tow': 446384, 'wn': 2154}, 'ura': 2.2, 'fit_interval': 14400, 'valid': 1, 'health_bits': 0}, 'lambda_na': -0.02200078842114688, 't_lambda_na': 0.007072207052260637, 'i': 5153.550029754639, 't': -1.8731818448797617, 't_dot': -8.903585155774196e-09, 'epsilon': -0.9893036629599647, 'omega': 0.9341514480259797}