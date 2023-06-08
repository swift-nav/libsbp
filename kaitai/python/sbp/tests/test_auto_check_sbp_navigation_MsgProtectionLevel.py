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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_protection_level_1():
    buf = base64.standard_b64decode("VRYCABAhiOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAUsM=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc352
    
    assert msg.length == 33
    
    assert msg.payload == "iOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    
    assert msg.msg_type == 0x216
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.height) == 0.0
    
    assert dictify(msg.hpl) == 0
    
    assert dictify(msg.lat) == 0.0
    
    assert dictify(msg.lon) == 0.0
    
    assert dictify(msg.tow) == 501867400
    
    assert dictify(msg.vpl) == 0

    assert dictify(msg) == {'tow': 501867400, 'vpl': 0, 'hpl': 0, 'lat': 0.0, 'lon': 0.0, 'height': 0.0, 'flags': 0, 'preamble': 85, 'msg_type': 534, 'sender': 4096, 'payload': 'iOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA', 'crc': 50002, 'length': 33}