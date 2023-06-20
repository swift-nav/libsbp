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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgAngularRate.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_orientation_msg_angular_rate_1():
    buf = base64.standard_b64decode("VSICQgARAgAAAAIAAAAFAAAAAgAAAABYRg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4658
    
    assert msg.length == 17
    
    assert msg.msg_type == 0x222
    
    assert msg.payload == "AgAAAAIAAAAFAAAAAgAAAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.tow) == 2
    
    assert dictify(msg.x) == 2
    
    assert dictify(msg.y) == 5
    
    assert dictify(msg.z) == 2

    assert dictify(msg) == {'sender': 66, 'msg_type': 546, 'tow': 2, 'crc': 18008, 'length': 17, 'flags': 0, 'y': 5, 'x': 2, 'z': 2, 'preamble': 85, 'payload': 'AgAAAAIAAAAFAAAAAgAAAAA='}