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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefCovGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ecef_cov_gnss_1():
    buf = base64.standard_b64decode("VTUCABAq4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUCFuY=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe616
    
    assert msg.length == 42
    
    assert msg.msg_type == 0x235
    
    assert msg.payload == "4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUC"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.cov_x_x) == 0.0024547684006392956
    
    assert dictify(msg.cov_x_y) == 0.0021795108914375305
    
    assert dictify(msg.cov_x_z) == -0.0016828652005642653
    
    assert dictify(msg.cov_y_y) == 0.004218944814056158
    
    assert dictify(msg.cov_y_z) == -0.0024961293675005436
    
    assert dictify(msg.cov_z_z) == 0.0037804271560162306
    
    assert dictify(msg.flags) == 2
    
    assert dictify(msg.n_sats) == 21
    
    assert dictify(msg.tow) == 501868000
    
    assert dictify(msg.x) == -3
    
    assert dictify(msg.y) == 1
    
    assert dictify(msg.z) == 4

    assert dictify(msg) == {'tow': 501868000, 'x': -3, 'y': 1, 'z': 4, 'cov_x_x': 0.0024547684006392956, 'cov_x_y': 0.0021795108914375305, 'cov_x_z': -0.0016828652005642653, 'cov_y_y': 0.004218944814056158, 'cov_y_z': -0.0024961293675005436, 'cov_z_z': 0.0037804271560162306, 'n_sats': 21, 'flags': 2, 'preamble': 85, 'msg_type': 565, 'sender': 4096, 'payload': '4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUC', 'crc': 58902, 'length': 42}