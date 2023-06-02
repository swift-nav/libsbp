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
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_gal_1():
    buf = base64.standard_b64decode("VY0AgPCZGw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAAR9A=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"common":{"sid":{"sat":27,"code":14},"toe":{"tow":448800,"wn":2154},"ura":3.119999885559082,"fit_interval":14400,"valid":1,"health_bits":0},"bgd_e1e5a":2.0954757928848267e-09,"bgd_e1e5b":2.0954757928848267e-09,"c_rs":10.125,"c_rc":265.4375,"c_uc":5.364418029785156e-07,"c_us":3.993511199951172e-06,"c_ic":-3.166496753692627e-08,"c_is":-3.166496753692627e-08,"dn":3.2262058129932258e-09,"m0":-1.8457115744155868,"ecc":0.00017060607206076384,"sqrta":5440.602401733398,"omega0":1.16967730598334,"omegadot":-5.757382675240872e-09,"w":0.12250912091662625,"inc":0.9777456094977858,"inc_dot":-3.1787038343451465e-10,"af0":-1.7088896129280325e-05,"af1":-8.185452315956353e-12,"af2":0.0,"toc":{"tow":448800,"wn":2154},"iode":108,"iodc":108,"source":0,"preamble":85,"msg_type":141,"sender":61568,"payload":"Gw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAA","crc":53319,"length":153}
    assert parsed_dict['crc'] == 0xd047
    assert parsed_dict['length'] == 153
    assert parsed_dict['msg_type'] == 0x8d
    assert parsed_dict['payload'] == "Gw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAA"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xf080
    assert dictify(obj.payload.af0) == snake_case_keys( -1.7088896129280325e-05 )
    assert dictify(obj.payload.af1) == snake_case_keys( -8.185452315956353e-12 )
    assert dictify(obj.payload.af2) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.bgd_e1e5a) == snake_case_keys( 2.0954757928848267e-09 )
    assert dictify(obj.payload.bgd_e1e5b) == snake_case_keys( 2.0954757928848267e-09 )
    assert dictify(obj.payload.c_ic) == snake_case_keys( -3.166496753692627e-08 )
    assert dictify(obj.payload.c_is) == snake_case_keys( -3.166496753692627e-08 )
    assert dictify(obj.payload.c_rc) == snake_case_keys( 265.4375 )
    assert dictify(obj.payload.c_rs) == snake_case_keys( 10.125 )
    assert dictify(obj.payload.c_uc) == snake_case_keys( 5.364418029785156e-07 )
    assert dictify(obj.payload.c_us) == snake_case_keys( 3.993511199951172e-06 )
    assert dictify(obj.payload.common) == snake_case_keys( {'sid': {'sat': 27, 'code': 14}, 'toe': {'tow': 448800, 'wn': 2154}, 'ura': 3.119999885559082, 'fit_interval': 14400, 'valid': 1, 'health_bits': 0} )
    assert dictify(obj.payload.dn) == snake_case_keys( 3.2262058129932258e-09 )
    assert dictify(obj.payload.ecc) == snake_case_keys( 0.00017060607206076384 )
    assert dictify(obj.payload.inc) == snake_case_keys( 0.9777456094977858 )
    assert dictify(obj.payload.inc_dot) == snake_case_keys( -3.1787038343451465e-10 )
    assert dictify(obj.payload.iodc) == snake_case_keys( 108 )
    assert dictify(obj.payload.iode) == snake_case_keys( 108 )
    assert dictify(obj.payload.m0) == snake_case_keys( -1.8457115744155868 )
    assert dictify(obj.payload.omega0) == snake_case_keys( 1.16967730598334 )
    assert dictify(obj.payload.omegadot) == snake_case_keys( -5.757382675240872e-09 )
    assert dictify(obj.payload.source) == snake_case_keys( 0 )
    assert dictify(obj.payload.sqrta) == snake_case_keys( 5440.602401733398 )
    assert dictify(obj.payload.toc) == snake_case_keys( {'tow': 448800, 'wn': 2154} )
    assert dictify(obj.payload.w) == snake_case_keys( 0.12250912091662625 )

    assert parsed_dict == snake_case_keys(orig_dict)