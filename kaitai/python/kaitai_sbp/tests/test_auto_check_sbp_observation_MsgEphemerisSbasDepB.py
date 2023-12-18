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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisSbasDepB.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_sbas_dep_b_1():
    buf = base64.standard_b64decode("VYQAewBuFgawzwYAaggAAAAAAAAAQAAAAAABAAAAgEL2OWfBAAAAIqpOIkEAAPDHVFZ1wQAAAGIG+prAAAAA2Trdo8AAAAC4ii6LQAAAAAAAQK8+AAAAAABArz4AAAAAAHDHPgAAAABssUS/AAAAAADAoz2RaA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6891
    
    assert msg.length == 110
    
    assert msg.msg_type == 0x84
    
    assert msg.payload == "FgawzwYAaggAAAAAAAAAQAAAAAABAAAAgEL2OWfBAAAAIqpOIkEAAPDHVFZ1wQAAAGIG+prAAAAA2Trdo8AAAAC4ii6LQAAAAAAAQK8+AAAAAABArz4AAAAAAHDHPgAAAABssUS/AAAAAADAoz0="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x007b
    
    assert dictify(msg.a_gf0) == -0.0006315018981695175
    
    assert dictify(msg.a_gf1) == 8.981260180007666e-12
    
    assert dictify(msg.acc) == [9.313225746154785e-07, 9.313225746154785e-07, 2.7939677238464355e-06]
    
    assert dictify(msg.common) == {'fit_interval': 0, 'health_bits': 0, 'sid': {'code': 6, 'sat': 22}, 'toe': {'tow': 446384, 'wn': 2154}, 'ura': 2.0, 'valid': 1}
    
    assert dictify(msg.pos) == [-12177330.078125, 599893.06640625, -22373708.49609375]
    
    assert dictify(msg.vel) == [-1726.506233215332, -2542.6149368286133, 869.8177337646484]

    assert dictify(msg) == {'crc': 26769, 'length': 110, 'msg_type': 132, 'payload': 'FgawzwYAaggAAAAAAAAAQAAAAAABAAAAgEL2OWfBAAAAIqpOIkEAAPDHVFZ1wQAAAGIG+prAAAAA2Trdo8AAAAC4ii6LQAAAAAAAQK8+AAAAAABArz4AAAAAAHDHPgAAAABssUS/AAAAAADAoz0=', 'preamble': 85, 'sender': 123, 'common': {'sid': {'sat': 22, 'code': 6}, 'toe': {'tow': 446384, 'wn': 2154}, 'ura': 2, 'fit_interval': 0, 'valid': 1, 'health_bits': 0}, 'pos': [-12177330.078125, 599893.06640625, -22373708.49609375], 'vel': [-1726.506233215332, -2542.6149368286133, 869.8177337646484], 'acc': [9.313225746154785e-07, 9.313225746154785e-07, 2.7939677238464355e-06], 'a_gf0': -0.0006315018981695175, 'a_gf1': 8.981260180007666e-12}