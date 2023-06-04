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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_llh_gnss_1():
    buf = base64.standard_b64decode("VSoCABAiGOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwFcAtQASBGk3")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x3769
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x22a
    
    assert msg.payload == "GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwFcAtQASBA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.flags) == 4
    
    assert dictify(msg.h_accuracy) == 87
    
    assert dictify(msg.height) == -17.39382124780135
    
    assert dictify(msg.lat) == 37.83123196497633
    
    assert dictify(msg.lon) == -122.28650381011681
    
    assert dictify(msg.n_sats) == 18
    
    assert dictify(msg.tow) == 501867800
    
    assert dictify(msg.v_accuracy) == 181

    assert dictify(msg) == {'tow': 501867800, 'lat': 37.83123196497633, 'lon': -122.28650381011681, 'height': -17.39382124780135, 'h_accuracy': 87, 'v_accuracy': 181, 'n_sats': 18, 'flags': 4, 'preamble': 85, 'msg_type': 554, 'sender': 4096, 'payload': 'GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwFcAtQASBA==', 'crc': 14185, 'length': 34}