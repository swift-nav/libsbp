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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisQzss.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_qzss_1():
    buf = base64.standard_b64decode("VY4AgPCLwR/Q3QYAaggAAABAQDgAAAAAAADAsQDo5MMAoBPCAOCHtwBgCjcAwJ21AAAuNKdIa2mzASc+D+Ce0/Gk0z8AAAAY+1OzPwAAACIsXblAjz7O6MG18r/P2EVqYv8nvkGEXxYwD/m/+VJDXh5k5z91p7vpu/21PaCBwbkAAKisAAAAANDdBgBqCDExA34X")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x177e
    
    assert msg.length == 139
    
    assert msg.msg_type == 0x8e
    
    assert msg.payload == "wR/Q3QYAaggAAABAQDgAAAAAAADAsQDo5MMAoBPCAOCHtwBgCjcAwJ21AAAuNKdIa2mzASc+D+Ce0/Gk0z8AAAAY+1OzPwAAACIsXblAjz7O6MG18r/P2EVqYv8nvkGEXxYwD/m/+VJDXh5k5z91p7vpu/21PaCBwbkAAKisAAAAANDdBgBqCDExAw=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xf080
    
    assert dictify(msg.af0) == -0.00036908406764268875
    
    assert dictify(msg.af1) == -4.774847184307873e-12
    
    assert dictify(msg.af2) == 0.0
    
    assert dictify(msg.c_ic) == -1.1753290891647339e-06
    
    assert dictify(msg.c_is) == 1.6205012798309326e-07
    
    assert dictify(msg.c_rc) == -36.90625
    
    assert dictify(msg.c_rs) == -457.8125
    
    assert dictify(msg.c_uc) == -1.6197562217712402e-05
    
    assert dictify(msg.c_us) == 8.247792720794678e-06
    
    assert dictify(msg.common) == {'sid': {'sat': 193, 'code': 31}, 'toe': {'tow': 450000, 'wn': 2154}, 'ura': 2.0, 'fit_interval': 14400, 'valid': 0, 'health_bits': 0}
    
    assert dictify(msg.dn) == 2.678325848736433e-09
    
    assert dictify(msg.ecc) == 0.07550019584596157
    
    assert dictify(msg.inc) == 0.7309715119432375
    
    assert dictify(msg.inc_dot) == 2.0000833114980698e-11
    
    assert dictify(msg.iodc) == 817
    
    assert dictify(msg.iode) == 49
    
    assert dictify(msg.m0) == 0.30694242158961144
    
    assert dictify(msg.omega0) == -1.1693743795366662
    
    assert dictify(msg.omegadot) == -2.7936877968817684e-09
    
    assert dictify(msg.sqrta) == 6493.172393798828
    
    assert dictify(msg.tgd) == -5.587935447692871e-09
    
    assert dictify(msg.toc) == {'tow': 450000, 'wn': 2154}
    
    assert dictify(msg.w) == -1.5662079690885238

    assert dictify(msg) == {'common': {'sid': {'sat': 193, 'code': 31}, 'toe': {'tow': 450000, 'wn': 2154}, 'ura': 2.0, 'fit_interval': 14400, 'valid': 0, 'health_bits': 0}, 'tgd': -5.587935447692871e-09, 'c_rs': -457.8125, 'c_rc': -36.90625, 'c_uc': -1.6197562217712402e-05, 'c_us': 8.247792720794678e-06, 'c_ic': -1.1753290891647339e-06, 'c_is': 1.6205012798309326e-07, 'dn': 2.678325848736433e-09, 'm0': 0.30694242158961144, 'ecc': 0.07550019584596157, 'sqrta': 6493.172393798828, 'omega0': -1.1693743795366662, 'omegadot': -2.7936877968817684e-09, 'w': -1.5662079690885238, 'inc': 0.7309715119432375, 'inc_dot': 2.0000833114980698e-11, 'af0': -0.00036908406764268875, 'af1': -4.774847184307873e-12, 'af2': 0.0, 'toc': {'tow': 450000, 'wn': 2154}, 'iode': 49, 'iodc': 817, 'preamble': 85, 'msg_type': 142, 'sender': 61568, 'payload': 'wR/Q3QYAaggAAABAQDgAAAAAAADAsQDo5MMAoBPCAOCHtwBgCjcAwJ21AAAuNKdIa2mzASc+D+Ce0/Gk0z8AAAAY+1OzPwAAACIsXblAjz7O6MG18r/P2EVqYv8nvkGEXxYwD/m/+VJDXh5k5z91p7vpu/21PaCBwbkAAKisAAAAANDdBgBqCDExAw==', 'crc': 6014, 'length': 139}
