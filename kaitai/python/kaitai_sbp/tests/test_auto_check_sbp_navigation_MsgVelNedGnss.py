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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ned_gnss_1():
    buf = base64.standard_b64decode("VS4CABAWqObpHfv///8AAAAA9v///ygAWQAVAmOr")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xab63
    
    assert msg.length == 22
    
    assert msg.msg_type == 0x22e
    
    assert msg.payload == "qObpHfv///8AAAAA9v///ygAWQAVAg=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.d) == -10
    
    assert dictify(msg.e) == 0
    
    assert dictify(msg.flags) == 2
    
    assert dictify(msg.h_accuracy) == 40
    
    assert dictify(msg.n) == -5
    
    assert dictify(msg.n_sats) == 21
    
    assert dictify(msg.tow) == 501868200
    
    assert dictify(msg.v_accuracy) == 89

    assert dictify(msg) == {'tow': 501868200, 'n': -5, 'e': 0, 'd': -10, 'h_accuracy': 40, 'v_accuracy': 89, 'n_sats': 21, 'flags': 2, 'preamble': 85, 'msg_type': 558, 'sender': 4096, 'payload': 'qObpHfv///8AAAAA9v///ygAWQAVAg==', 'crc': 43875, 'length': 22}