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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGPS.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_gps_1():
    buf = base64.standard_b64decode("VYoACgmLFgCwzwYAaggAAABAQDgAAAEAAACYsgBAUcIAUJpDACA4tgCAUjYAAAAyAAD4s3LYYLQxdTg+jikF61+Hlr8AAAAgv/d8PwAAwM6MIbRAKYOzho34/b/jhVE2zB5Dvtg7xydgqO+/RwvZk5Hk7T/dL2Tg/y/GvWCLJboAAB4tAAAAALDPBgBqCC0tAKoE")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x4aa
    assert payload.length == 139
    assert payload.msg_type == 0x8a
    assert payload.payload == "FgCwzwYAaggAAABAQDgAAAEAAACYsgBAUcIAUJpDACA4tgCAUjYAAAAyAAD4s3LYYLQxdTg+jikF61+Hlr8AAAAgv/d8PwAAwM6MIbRAKYOzho34/b/jhVE2zB5Dvtg7xydgqO+/RwvZk5Hk7T/dL2Tg/y/GvWCLJboAAB4tAAAAALDPBgBqCC0tAA=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x90a
    assert dictify(obj.payload.af0) == snake_case_keys( -0.0006315018981695175 )
    assert dictify(obj.payload.af1) == snake_case_keys( 8.981260180007666e-12 )
    assert dictify(obj.payload.af2) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.c_ic) == snake_case_keys( 7.450580596923828e-09 )
    assert dictify(obj.payload.c_is) == snake_case_keys( -1.1548399925231934e-07 )
    assert dictify(obj.payload.c_rc) == snake_case_keys( 308.625 )
    assert dictify(obj.payload.c_rs) == snake_case_keys( -52.3125 )
    assert dictify(obj.payload.c_uc) == snake_case_keys( -2.7436763048171997e-06 )
    assert dictify(obj.payload.c_us) == snake_case_keys( 3.1366944313049316e-06 )
    assert dictify(obj.payload.common) == snake_case_keys( {'sid': {'sat': 22, 'code': 0}, 'toe': {'tow': 446384, 'wn': 2154}, 'ura': 2.0, 'fit_interval': 14400, 'valid': 1, 'health_bits': 0} )
    assert dictify(obj.payload.dn) == snake_case_keys( 5.694522914022375e-09 )
    assert dictify(obj.payload.ecc) == snake_case_keys( 0.007072207052260637 )
    assert dictify(obj.payload.inc) == snake_case_keys( 0.9341514480259797 )
    assert dictify(obj.payload.inc_dot) == snake_case_keys( -4.035882396415757e-11 )
    assert dictify(obj.payload.iodc) == snake_case_keys( 45 )
    assert dictify(obj.payload.iode) == snake_case_keys( 45 )
    assert dictify(obj.payload.m0) == snake_case_keys( -0.02200078842114688 )
    assert dictify(obj.payload.omega0) == snake_case_keys( -1.8731818448797617 )
    assert dictify(obj.payload.omegadot) == snake_case_keys( -8.903585155774196e-09 )
    assert dictify(obj.payload.sqrta) == snake_case_keys( 5153.550029754639 )
    assert dictify(obj.payload.tgd) == snake_case_keys( -1.7695128917694092e-08 )
    assert dictify(obj.payload.toc) == snake_case_keys( {'tow': 446384, 'wn': 2154} )
    assert dictify(obj.payload.w) == snake_case_keys( -0.9893036629599647 )

    assert dictify(payload) == snake_case_keys( {"common":{"sid":{"sat":22,"code":0},"toe":{"tow":446384,"wn":2154},"ura":2.0,"fit_interval":14400,"valid":1,"health_bits":0},"tgd":-1.7695128917694092e-08,"c_rs":-52.3125,"c_rc":308.625,"c_uc":-2.7436763048171997e-06,"c_us":3.1366944313049316e-06,"c_ic":7.450580596923828e-09,"c_is":-1.1548399925231934e-07,"dn":5.694522914022375e-09,"m0":-0.02200078842114688,"ecc":0.007072207052260637,"sqrta":5153.550029754639,"omega0":-1.8731818448797617,"omegadot":-8.903585155774196e-09,"w":-0.9893036629599647,"inc":0.9341514480259797,"inc_dot":-4.035882396415757e-11,"af0":-0.0006315018981695175,"af1":8.981260180007666e-12,"af2":0.0,"toc":{"tow":446384,"wn":2154},"iode":45,"iodc":45,"preamble":85,"msg_type":138,"sender":2314,"payload":"FgCwzwYAaggAAABAQDgAAAEAAACYsgBAUcIAUJpDACA4tgCAUjYAAAAyAAD4s3LYYLQxdTg+jikF61+Hlr8AAAAgv/d8PwAAwM6MIbRAKYOzho34/b/jhVE2zB5Dvtg7xydgqO+/RwvZk5Hk7T/dL2Tg/y/GvWCLJboAAB4tAAAAALDPBgBqCC0tAA==","crc":1194,"length":139} )