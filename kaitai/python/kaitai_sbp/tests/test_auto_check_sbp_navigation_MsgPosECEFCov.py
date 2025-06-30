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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCov.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_ecef_cov_1():
    buf = base64.standard_b64decode("VRQCQgA2BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF+ac=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa7f9
    
    assert msg.length == 54
    
    assert msg.msg_type == 0x214
    
    assert msg.payload == "BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.cov_x_x) == 8.0
    
    assert dictify(msg.cov_x_y) == 7.0
    
    assert dictify(msg.cov_x_z) == 2.0
    
    assert dictify(msg.cov_y_y) == 6.0
    
    assert dictify(msg.cov_y_z) == 8.0
    
    assert dictify(msg.cov_z_z) == 5.0
    
    assert dictify(msg.flags) == 5
    
    assert dictify(msg.n_sats) == 4
    
    assert dictify(msg.tow) == 7
    
    assert dictify(msg.x) == 6.0
    
    assert dictify(msg.y) == 1.0
    
    assert dictify(msg.z) == 4.0

    assert dictify(msg) == {'cov_y_z': 8, 'cov_y_y': 6, 'n_sats': 4, 'sender': 66, 'msg_type': 532, 'cov_x_z': 2, 'cov_x_y': 7, 'cov_x_x': 8, 'tow': 7, 'crc': 43001, 'length': 54, 'flags': 5, 'y': 1, 'x': 6, 'z': 4, 'preamble': 85, 'payload': 'BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF', 'cov_z_z': 5}
