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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisSbas.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_sbas_1():
    buf = base64.standard_b64decode("VYwAwwRKFgawzwYAaggAAECxAAAAAAEAAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBM9DXxNfpHsVWdFlEAAB6NQAAejUAgDs2YIslugAAHi3Akw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x93c0
    
    assert msg.length == 74
    
    assert msg.msg_type == 0x8c
    
    assert msg.payload == "FgawzwYAaggAAECxAAAAAAEAAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBM9DXxNfpHsVWdFlEAAB6NQAAejUAgDs2YIslugAAHi0="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.a_gf0) == -0.0006315018981695175
    
    assert dictify(msg.a_gf1) == 8.981260180007666e-12
    
    assert dictify(msg.acc) == [9.313225746154785e-07, 9.313225746154785e-07, 2.7939677238464355e-06]
    
    assert dictify(msg.common) == {'fit_interval': 0, 'health_bits': 0, 'sid': {'code': 6, 'sat': 22}, 'toe': {'tow': 446384, 'wn': 2154}, 'ura': -2.7939677238464355e-09, 'valid': 1}
    
    assert dictify(msg.pos) == [-12177330.078125, 599893.06640625, -22373708.49609375]
    
    assert dictify(msg.vel) == [-1726.5062255859375, -2542.614990234375, 869.8177490234375]

    assert dictify(msg) == {'crc': 37824, 'length': 74, 'msg_type': 140, 'payload': 'FgawzwYAaggAAECxAAAAAAEAAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBM9DXxNfpHsVWdFlEAAB6NQAAejUAgDs2YIslugAAHi0=', 'preamble': 85, 'sender': 1219, 'common': {'sid': {'sat': 22, 'code': 6}, 'toe': {'tow': 446384, 'wn': 2154}, 'ura': -2.7939677238464355e-09, 'fit_interval': 0, 'valid': 1, 'health_bits': 0}, 'pos': [-12177330.078125, 599893.06640625, -22373708.49609375], 'vel': [-1726.5062255859375, -2542.614990234375, 869.8177490234375], 'acc': [9.313225746154785e-07, 9.313225746154785e-07, 2.7939677238464355e-06], 'a_gf0': -0.0006315018981695175, 'a_gf1': 8.981260180007666e-12}