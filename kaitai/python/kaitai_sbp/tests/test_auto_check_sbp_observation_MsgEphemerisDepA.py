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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_dep_a_1():
    buf = base64.standard_b64decode("VRoAwwSvAAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9mpmZmZmZyT/NzMzMwD4bQWoIzczMzMA+G0FqCAEAFvJU")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x54f2
    
    assert msg.length == 175
    
    assert msg.msg_type == 0x1a
    
    assert msg.payload == "AAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9mpmZmZmZyT/NzMzMwD4bQWoIzczMzMA+G0FqCAEAFg=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.af0) == -0.0006315018981695175
    
    assert dictify(msg.af1) == 8.981260180007666e-12
    
    assert dictify(msg.af2) == 0.2
    
    assert dictify(msg.c_ic) == 7.450580596923828e-09
    
    assert dictify(msg.c_is) == -1.1548399925231934e-07
    
    assert dictify(msg.c_rc) == 308.625
    
    assert dictify(msg.c_rs) == -52.3125
    
    assert dictify(msg.c_uc) == -2.7436763048171997e-06
    
    assert dictify(msg.c_us) == 3.1366944313049316e-06
    
    assert dictify(msg.dn) == 5.694522914022375e-09
    
    assert dictify(msg.ecc) == 0.007072207052260637
    
    assert dictify(msg.healthy) == 0
    
    assert dictify(msg.inc) == 0.9341514480259797
    
    assert dictify(msg.inc_dot) == -4.035882396415757e-11
    
    assert dictify(msg.m0) == -0.02200078842114688
    
    assert dictify(msg.omega0) == -1.8731818448797617
    
    assert dictify(msg.omegadot) == -8.903585155774196e-09
    
    assert dictify(msg.prn) == 22
    
    assert dictify(msg.sqrta) == 5153.550029754639
    
    assert dictify(msg.tgd) == -1.7695128917694092e-08
    
    assert dictify(msg.toc_tow) == 446384.2
    
    assert dictify(msg.toc_wn) == 2154
    
    assert dictify(msg.toe_tow) == 446384.2
    
    assert dictify(msg.toe_wn) == 2154
    
    assert dictify(msg.valid) == 1
    
    assert dictify(msg.w) == -0.9893036629599647

    assert dictify(msg) == {'preamble': 85, 'msg_type': 26, 'sender': 1219, 'length': 175, 'payload': 'AAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9mpmZmZmZyT/NzMzMwD4bQWoIzczMzMA+G0FqCAEAFg==', 'crc': 21746, 'tgd': -1.7695128917694092e-08, 'c_rs': -52.3125, 'c_rc': 308.625, 'c_uc': -2.7436763048171997e-06, 'c_us': 3.1366944313049316e-06, 'c_ic': 7.450580596923828e-09, 'c_is': -1.1548399925231934e-07, 'dn': 5.694522914022375e-09, 'm0': -0.02200078842114688, 'ecc': 0.007072207052260637, 'sqrta': 5153.550029754639, 'omega0': -1.8731818448797617, 'omegadot': -8.903585155774196e-09, 'w': -0.9893036629599647, 'inc': 0.9341514480259797, 'inc_dot': -4.035882396415757e-11, 'af0': -0.0006315018981695175, 'af1': 8.981260180007666e-12, 'af2': 0.2, 'toe_tow': 446384.2, 'toe_wn': 2154, 'toc_tow': 446384.2, 'toc_wn': 2154, 'valid': 1, 'healthy': 0, 'prn': 22}
