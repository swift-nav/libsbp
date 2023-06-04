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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ecef_gnss_1():
    buf = base64.standard_b64decode("VS0CABAU4OXpHf3///8BAAAABAAAAFkAFQLNEA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x10cd
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x22d
    
    assert msg.payload == "4OXpHf3///8BAAAABAAAAFkAFQI="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.accuracy) == 89
    
    assert dictify(msg.flags) == 2
    
    assert dictify(msg.n_sats) == 21
    
    assert dictify(msg.tow) == 501868000
    
    assert dictify(msg.x) == -3
    
    assert dictify(msg.y) == 1
    
    assert dictify(msg.z) == 4

    assert dictify(msg) == {'tow': 501868000, 'x': -3, 'y': 1, 'z': 4, 'accuracy': 89, 'n_sats': 21, 'flags': 2, 'preamble': 85, 'msg_type': 557, 'sender': 4096, 'payload': '4OXpHf3///8BAAAABAAAAFkAFQI=', 'crc': 4301, 'length': 20}