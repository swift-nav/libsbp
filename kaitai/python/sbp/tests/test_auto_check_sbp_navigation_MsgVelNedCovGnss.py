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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedCovGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ned_cov_gnss_1():
    buf = base64.standard_b64decode("VTICABAqqObpHfv///8AAAAA9v///w86zzr4i3Q3Z8U5Ocu6gTptqyw5hycBPBUCmwM=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x39b
    
    assert msg.length == 42
    
    assert msg.msg_type == 0x232
    
    assert msg.payload == "qObpHfv///8AAAAA9v///w86zzr4i3Q3Z8U5Ocu6gTptqyw5hycBPBUC"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.cov_d_d) == 0.007882959209382534
    
    assert dictify(msg.cov_e_d) == 0.00016467059322167188
    
    assert dictify(msg.cov_e_e) == 0.0009897587588056922
    
    assert dictify(msg.cov_n_d) == 0.00017716512957122177
    
    assert dictify(msg.cov_n_e) == 1.457612233934924e-05
    
    assert dictify(msg.cov_n_n) == 0.0015810149488970637
    
    assert dictify(msg.d) == -10
    
    assert dictify(msg.e) == 0
    
    assert dictify(msg.flags) == 2
    
    assert dictify(msg.n) == -5
    
    assert dictify(msg.n_sats) == 21
    
    assert dictify(msg.tow) == 501868200

    assert dictify(msg) == {'tow': 501868200, 'n': -5, 'e': 0, 'd': -10, 'cov_n_n': 0.0015810149488970637, 'cov_n_e': 1.457612233934924e-05, 'cov_n_d': 0.00017716512957122177, 'cov_e_e': 0.0009897587588056922, 'cov_e_d': 0.00016467059322167188, 'cov_d_d': 0.007882959209382534, 'n_sats': 21, 'flags': 2, 'preamble': 85, 'msg_type': 562, 'sender': 4096, 'payload': 'qObpHfv///8AAAAA9v///w86zzr4i3Q3Z8U5Ocu6gTptqyw5hycBPBUC', 'crc': 923, 'length': 42}