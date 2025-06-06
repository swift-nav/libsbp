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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevelDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_protection_level_dep_a_1():
    buf = base64.standard_b64decode("VRYClBYhNH5FuS9VBIszMzMzM/S+QGZmZmZmzKhAmpmZmRknwED4UWg=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6851
    
    assert msg.length == 33
    
    assert msg.msg_type == 0x216
    
    assert msg.payload == "NH5FuS9VBIszMzMzM/S+QGZmZmZmzKhAmpmZmRknwED4"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1694
    
    assert dictify(msg.flags) == 248
    
    assert dictify(msg.height) == 8270.2
    
    assert dictify(msg.hpl) == 35588
    
    assert dictify(msg.lat) == 7924.2
    
    assert dictify(msg.lon) == 3174.2
    
    assert dictify(msg.tow) == 3108339252
    
    assert dictify(msg.vpl) == 21807

    assert dictify(msg) == {'crc': 26705, 'length': 33, 'msg_type': 534, 'payload': 'NH5FuS9VBIszMzMzM/S+QGZmZmZmzKhAmpmZmRknwED4', 'preamble': 85, 'sender': 5780, 'tow': 3108339252, 'vpl': 21807, 'hpl': 35588, 'lat': 7924.2, 'lon': 3174.2, 'height': 8270.2, 'flags': 248}
