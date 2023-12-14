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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGPSDepE.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_gps_dep_e_1():
    buf = base64.standard_b64decode("VYEAewC5FgAAALDPBgBqCAAAAAAAAABAQDgAAAEAAAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9AAAAAAAAAACwzwYAaggtLQAG7g==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xee06
    
    assert msg.length == 185
    
    assert msg.msg_type == 0x81
    
    assert msg.payload == "FgAAALDPBgBqCAAAAAAAAABAQDgAAAEAAAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9AAAAAAAAAACwzwYAaggtLQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x007b
    
    assert dictify(msg.af0) == -0.0006315018981695175
    
    assert dictify(msg.af1) == 8.981260180007666e-12
    
    assert dictify(msg.af2) == 0.0
    
    assert dictify(msg.c_ic) == 7.450580596923828e-09
    
    assert dictify(msg.c_is) == -1.1548399925231934e-07
    
    assert dictify(msg.c_rc) == 308.625
    
    assert dictify(msg.c_rs) == -52.3125
    
    assert dictify(msg.c_uc) == -2.7436763048171997e-06
    
    assert dictify(msg.c_us) == 3.1366944313049316e-06
    
    assert dictify(msg.common) == {'fit_interval': 14400, 'health_bits': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 22}, 'toe': {'tow': 446384, 'wn': 2154}, 'ura': 2.0, 'valid': 1}
    
    assert dictify(msg.dn) == 5.694522914022375e-09
    
    assert dictify(msg.ecc) == 0.007072207052260637
    
    assert dictify(msg.inc) == 0.9341514480259797
    
    assert dictify(msg.inc_dot) == -4.035882396415757e-11
    
    assert dictify(msg.iodc) == 45
    
    assert dictify(msg.iode) == 45
    
    assert dictify(msg.m0) == -0.02200078842114688
    
    assert dictify(msg.omega0) == -1.8731818448797617
    
    assert dictify(msg.omegadot) == -8.903585155774196e-09
    
    assert dictify(msg.sqrta) == 5153.550029754639
    
    assert dictify(msg.tgd) == -1.7695128917694092e-08
    
    assert dictify(msg.toc) == {'tow': 446384, 'wn': 2154}
    
    assert dictify(msg.w) == -0.9893036629599647

    assert dictify(msg) == {'crc': 60934, 'length': 185, 'msg_type': 129, 'payload': 'FgAAALDPBgBqCAAAAAAAAABAQDgAAAEAAAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9AAAAAAAAAACwzwYAaggtLQA=', 'preamble': 85, 'sender': 123, 'common': {'sid': {'sat': 22, 'code': 0, 'reserved': 0}, 'toe': {'tow': 446384, 'wn': 2154}, 'ura': 2, 'fit_interval': 14400, 'valid': 1, 'health_bits': 0}, 'tgd': -1.7695128917694092e-08, 'c_rs': -52.3125, 'c_rc': 308.625, 'c_uc': -2.7436763048171997e-06, 'c_us': 3.1366944313049316e-06, 'c_ic': 7.450580596923828e-09, 'c_is': -1.1548399925231934e-07, 'dn': 5.694522914022375e-09, 'm0': -0.02200078842114688, 'ecc': 0.007072207052260637, 'sqrta': 5153.550029754639, 'omega0': -1.8731818448797617, 'omegadot': -8.903585155774196e-09, 'w': -0.9893036629599647, 'inc': 0.9341514480259797, 'inc_dot': -4.035882396415757e-11, 'af0': -0.0006315018981695175, 'af1': 8.981260180007666e-12, 'af2': 0, 'toc': {'tow': 446384, 'wn': 2154}, 'iode': 45, 'iodc': 45}