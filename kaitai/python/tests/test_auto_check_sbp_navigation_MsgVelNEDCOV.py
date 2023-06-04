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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDCOV.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_nedcov_1():
    buf = base64.standard_b64decode("VRICQgAqZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoAWM0=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.payload == "ZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoA"
    
    assert msg.crc == 0xCD58
    
    assert msg.length == 42
    
    assert msg.msg_type == 0x212
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.cov_d_d) == 1.0
    
    assert dictify(msg.cov_e_d) == 1.0
    
    assert dictify(msg.cov_e_e) == 1.0
    
    assert dictify(msg.cov_n_d) == 1.0
    
    assert dictify(msg.cov_n_e) == 1.0
    
    assert dictify(msg.cov_n_n) == 1.0
    
    assert dictify(msg.d) == 1
    
    assert dictify(msg.e) == 1
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n) == 1
    
    assert dictify(msg.n_sats) == 10
    
    assert dictify(msg.tow) == 100

    assert dictify(msg) == {'cov_e_d': 1, 'cov_e_e': 1, 'n_sats': 10, 'sender': 66, 'msg_type': 530, 'cov_n_n': 1, 'cov_n_e': 1, 'tow': 100, 'n': 1, 'crc': 52568, 'length': 42, 'cov_n_d': 1, 'flags': 0, 'e': 1, 'cov_d_d': 1, 'preamble': 85, 'payload': 'ZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoA', 'd': 1}