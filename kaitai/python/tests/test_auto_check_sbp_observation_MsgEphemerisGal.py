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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGal.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_gal_1():
    buf = base64.standard_b64decode("VY0AgPCZGw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAAR9A=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd047
    
    assert msg.length == 153
    
    assert msg.msg_type == 0x8d
    
    assert msg.payload == "Gw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xf080
    
    assert dictify(msg.af0) == -1.7088896129280325e-05
    
    assert dictify(msg.af1) == -8.185452315956353e-12
    
    assert dictify(msg.af2) == 0.0
    
    assert dictify(msg.bgd_e1e5a) == 2.0954757928848267e-09
    
    assert dictify(msg.bgd_e1e5b) == 2.0954757928848267e-09
    
    assert dictify(msg.c_ic) == -3.166496753692627e-08
    
    assert dictify(msg.c_is) == -3.166496753692627e-08
    
    assert dictify(msg.c_rc) == 265.4375
    
    assert dictify(msg.c_rs) == 10.125
    
    assert dictify(msg.c_uc) == 5.364418029785156e-07
    
    assert dictify(msg.c_us) == 3.993511199951172e-06
    
    assert dictify(msg.common) == {'sid': {'sat': 27, 'code': 14}, 'toe': {'tow': 448800, 'wn': 2154}, 'ura': 3.119999885559082, 'fit_interval': 14400, 'valid': 1, 'health_bits': 0}
    
    assert dictify(msg.dn) == 3.2262058129932258e-09
    
    assert dictify(msg.ecc) == 0.00017060607206076384
    
    assert dictify(msg.inc) == 0.9777456094977858
    
    assert dictify(msg.inc_dot) == -3.1787038343451465e-10
    
    assert dictify(msg.iodc) == 108
    
    assert dictify(msg.iode) == 108
    
    assert dictify(msg.m0) == -1.8457115744155868
    
    assert dictify(msg.omega0) == 1.16967730598334
    
    assert dictify(msg.omegadot) == -5.757382675240872e-09
    
    assert dictify(msg.source) == 0
    
    assert dictify(msg.sqrta) == 5440.602401733398
    
    assert dictify(msg.toc) == {'tow': 448800, 'wn': 2154}
    
    assert dictify(msg.w) == 0.12250912091662625

    assert dictify(msg) == {'common': {'sid': {'sat': 27, 'code': 14}, 'toe': {'tow': 448800, 'wn': 2154}, 'ura': 3.119999885559082, 'fit_interval': 14400, 'valid': 1, 'health_bits': 0}, 'bgd_e1e5a': 2.0954757928848267e-09, 'bgd_e1e5b': 2.0954757928848267e-09, 'c_rs': 10.125, 'c_rc': 265.4375, 'c_uc': 5.364418029785156e-07, 'c_us': 3.993511199951172e-06, 'c_ic': -3.166496753692627e-08, 'c_is': -3.166496753692627e-08, 'dn': 3.2262058129932258e-09, 'm0': -1.8457115744155868, 'ecc': 0.00017060607206076384, 'sqrta': 5440.602401733398, 'omega0': 1.16967730598334, 'omegadot': -5.757382675240872e-09, 'w': 0.12250912091662625, 'inc': 0.9777456094977858, 'inc_dot': -3.1787038343451465e-10, 'af0': -1.7088896129280325e-05, 'af1': -8.185452315956353e-12, 'af2': 0.0, 'toc': {'tow': 448800, 'wn': 2154}, 'iode': 108, 'iodc': 108, 'source': 0, 'preamble': 85, 'msg_type': 141, 'sender': 61568, 'payload': 'Gw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAA', 'crc': 53319, 'length': 153}