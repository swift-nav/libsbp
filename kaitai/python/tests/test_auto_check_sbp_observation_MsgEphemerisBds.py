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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisBds.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_bds_1():
    buf = base64.standard_b64decode("VYkAgPCTCAyuswYAaggAAABAMCoAAAEAfWM0Ms8ul7AAcGBDAKRqQwA8/zYA4C81AACPswDAvjSSZaLEbWgTPv1XVso+HPs/AAAAYJc8dT8AAICaf125QJfBQAAKpgTAoEuuYgjJI77NHQxHvZYFwLBI+b3BrPA/SPm8tKDLCT4AAAAAXDNNvwCArisAAFihrrMGAGoIBgUAnfk=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf99d
    
    assert msg.length == 147
    
    assert msg.msg_type == 0x89
    
    assert msg.payload == "CAyuswYAaggAAABAMCoAAAEAfWM0Ms8ul7AAcGBDAKRqQwA8/zYA4C81AACPswDAvjSSZaLEbWgTPv1XVso+HPs/AAAAYJc8dT8AAICaf125QJfBQAAKpgTAoEuuYgjJI77NHQxHvZYFwLBI+b3BrPA/SPm8tKDLCT4AAAAAXDNNvwCArisAAFihrrMGAGoIBgUA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xf080
    
    assert dictify(msg.af0) == -0.0008911322802305222
    
    assert dictify(msg.af1) == 1.2398970739013748e-12
    
    assert dictify(msg.af2) == -7.318364664277155e-19
    
    assert dictify(msg.c_ic) == -6.658956408500671e-08
    
    assert dictify(msg.c_is) == 3.5529956221580505e-07
    
    assert dictify(msg.c_rc) == 234.640625
    
    assert dictify(msg.c_rs) == 224.4375
    
    assert dictify(msg.c_uc) == 7.606577128171921e-06
    
    assert dictify(msg.c_us) == 6.551854312419891e-07
    
    assert dictify(msg.common) == {'sid': {'sat': 8, 'code': 12}, 'toe': {'tow': 439214, 'wn': 2154}, 'ura': 2.0, 'fit_interval': 10800, 'valid': 1, 'health_bits': 0}
    
    assert dictify(msg.dn) == 1.1296899132622133e-09
    
    assert dictify(msg.ecc) == 0.005184737499803305
    
    assert dictify(msg.inc) == 1.0421769543504915
    
    assert dictify(msg.inc_dot) == 7.507455572801683e-10
    
    assert dictify(msg.iodc) == 5
    
    assert dictify(msg.iode) == 6
    
    assert dictify(msg.m0) == 1.6943958190727237
    
    assert dictify(msg.omega0) == -2.581073762870982
    
    assert dictify(msg.omegadot) == -2.303310227830545e-09
    
    assert dictify(msg.sqrta) == 6493.49845123291
    
    assert dictify(msg.tgd1) == 1.0499999980595476e-08
    
    assert dictify(msg.tgd2) == -1.0999999799921056e-09
    
    assert dictify(msg.toc) == {'tow': 439214, 'wn': 2154}
    
    assert dictify(msg.w) == -2.698603205735458

    assert dictify(msg) == {'common': {'sid': {'sat': 8, 'code': 12}, 'toe': {'tow': 439214, 'wn': 2154}, 'ura': 2.0, 'fit_interval': 10800, 'valid': 1, 'health_bits': 0}, 'tgd1': 1.0499999980595476e-08, 'tgd2': -1.0999999799921056e-09, 'c_rs': 224.4375, 'c_rc': 234.640625, 'c_uc': 7.606577128171921e-06, 'c_us': 6.551854312419891e-07, 'c_ic': -6.658956408500671e-08, 'c_is': 3.5529956221580505e-07, 'dn': 1.1296899132622133e-09, 'm0': 1.6943958190727237, 'ecc': 0.005184737499803305, 'sqrta': 6493.49845123291, 'omega0': -2.581073762870982, 'omegadot': -2.303310227830545e-09, 'w': -2.698603205735458, 'inc': 1.0421769543504915, 'inc_dot': 7.507455572801683e-10, 'af0': -0.0008911322802305222, 'af1': 1.2398970739013748e-12, 'af2': -7.318364664277155e-19, 'toc': {'tow': 439214, 'wn': 2154}, 'iode': 6, 'iodc': 5, 'preamble': 85, 'msg_type': 137, 'sender': 61568, 'payload': 'CAyuswYAaggAAABAMCoAAAEAfWM0Ms8ul7AAcGBDAKRqQwA8/zYA4C81AACPswDAvjSSZaLEbWgTPv1XVso+HPs/AAAAYJc8dT8AAICaf125QJfBQAAKpgTAoEuuYgjJI77NHQxHvZYFwLBI+b3BrPA/SPm8tKDLCT4AAAAAXDNNvwCArisAAFihrrMGAGoIBgUA', 'crc': 63901, 'length': 147}