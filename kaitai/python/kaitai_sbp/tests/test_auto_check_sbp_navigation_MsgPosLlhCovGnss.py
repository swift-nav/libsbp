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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhCovGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_llh_cov_gnss_1():
    buf = base64.standard_b64decode("VTECABA2GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIECsQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc40a
    
    assert msg.length == 54
    
    assert msg.msg_type == 0x231
    
    assert msg.payload == "GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIE"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.cov_d_d) == 0.03288137540221214
    
    assert dictify(msg.cov_e_d) == -0.0008439270895905793
    
    assert dictify(msg.cov_e_e) == 0.004523798823356628
    
    assert dictify(msg.cov_n_d) == 0.0018563168123364449
    
    assert dictify(msg.cov_n_e) == -0.00036755966721102595
    
    assert dictify(msg.cov_n_n) == 0.007488971576094627
    
    assert dictify(msg.flags) == 4
    
    assert dictify(msg.height) == -17.39382124780135
    
    assert dictify(msg.lat) == 37.83123196497633
    
    assert dictify(msg.lon) == -122.28650381011681
    
    assert dictify(msg.n_sats) == 18
    
    assert dictify(msg.tow) == 501867800

    assert dictify(msg) == {'tow': 501867800, 'lat': 37.83123196497633, 'lon': -122.28650381011681, 'height': -17.39382124780135, 'cov_n_n': 0.007488971576094627, 'cov_n_e': -0.00036755966721102595, 'cov_n_d': 0.0018563168123364449, 'cov_e_e': 0.004523798823356628, 'cov_e_d': -0.0008439270895905793, 'cov_d_d': 0.03288137540221214, 'n_sats': 18, 'flags': 4, 'preamble': 85, 'msg_type': 561, 'sender': 4096, 'payload': 'GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIE', 'crc': 50186, 'length': 54}
