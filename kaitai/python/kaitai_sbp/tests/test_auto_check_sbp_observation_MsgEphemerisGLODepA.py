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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGLODepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_glo_dep_a_1():
    buf = base64.standard_b64decode("VYMAwwRwBAADAEbFBgBqCM3MzMzMzBRAYAkAAAEAAAAAAAAAcD0AAAAAMOwVvwAAgEL2OWfBAAAAIqpOIkEAAPDHVFZ1wQAAAGIG+prAAAAA2Trdo8AAAAC4ii6LQAAAAAAAQK8+AAAAAABArz4AAAAAAHDHPsru")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xeeca
    
    assert msg.length == 112
    
    assert msg.msg_type == 0x83
    
    assert msg.payload == "BAADAEbFBgBqCM3MzMzMzBRAYAkAAAEAAAAAAAAAcD0AAAAAMOwVvwAAgEL2OWfBAAAAIqpOIkEAAPDHVFZ1wQAAAGIG+prAAAAA2Trdo8AAAAC4ii6LQAAAAAAAQK8+AAAAAABArz4AAAAAAHDHPg=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.acc) == [9.313225746154785e-07, 9.313225746154785e-07, 2.7939677238464355e-06]
    
    assert dictify(msg.common) == {'fit_interval': 2400, 'health_bits': 0, 'sid': {'code': 3, 'reserved': 0, 'sat': 4}, 'toe': {'tow': 443718, 'wn': 2154}, 'ura': 5.2, 'valid': 1}
    
    assert dictify(msg.gamma) == 9.094947017729282e-13
    
    assert dictify(msg.pos) == [-12177330.078125, 599893.06640625, -22373708.49609375]
    
    assert dictify(msg.tau) == -8.36281105875969e-05
    
    assert dictify(msg.vel) == [-1726.506233215332, -2542.6149368286133, 869.8177337646484]

    assert dictify(msg) == {'preamble': 85, 'msg_type': 131, 'sender': 1219, 'length': 112, 'payload': 'BAADAEbFBgBqCM3MzMzMzBRAYAkAAAEAAAAAAAAAcD0AAAAAMOwVvwAAgEL2OWfBAAAAIqpOIkEAAPDHVFZ1wQAAAGIG+prAAAAA2Trdo8AAAAC4ii6LQAAAAAAAQK8+AAAAAABArz4AAAAAAHDHPg==', 'crc': 61130, 'common': {'sid': {'sat': 4, 'code': 3, 'reserved': 0}, 'toe': {'tow': 443718, 'wn': 2154}, 'ura': 5.2, 'fit_interval': 2400, 'valid': 1, 'health_bits': 0}, 'gamma': 9.094947017729282e-13, 'tau': -8.36281105875969e-05, 'pos': [-12177330.078125, 599893.06640625, -22373708.49609375], 'vel': [-1726.506233215332, -2542.6149368286133, 869.8177337646484], 'acc': [9.313225746154785e-07, 9.313225746154785e-07, 2.7939677238464355e-06]}