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

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_protection_level_1():
    buf = base64.standard_b64decode("VRcCLQNMblQE8i4zNaBZVKcpORXZ9D2hU2iMiVr2MzMzMzOqtECamZmZGVjDQDMzMzMzw3lA5/sm3dC3p1DfGmGkLS66POvjt6C7XXTgaSggIYW8")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xbc85
    
    assert msg.length == 76
    
    assert msg.msg_type == 0x217
    
    assert msg.payload == "blQE8i4zNaBZVKcpORXZ9D2hU2iMiVr2MzMzMzOqtECamZmZGVjDQDMzMzMzw3lA5/sm3dC3p1DfGmGkLS66POvjt6C7XXTgaSggIQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x032d
    
    assert dictify(msg.atpl) == 10663
    
    assert dictify(msg.ctpl) == 5433
    
    assert dictify(msg.flags) == 555755625
    
    assert dictify(msg.heading) == -529244741
    
    assert dictify(msg.height) == 412.2
    
    assert dictify(msg.hopl) == 26707
    
    assert dictify(msg.hpl) == 41013
    
    assert dictify(msg.hvpl) == 62681
    
    assert dictify(msg.lat) == 5290.2
    
    assert dictify(msg.lon) == 9904.2
    
    assert dictify(msg.pitch) == -1598561301
    
    assert dictify(msg.popl) == 35212
    
    assert dictify(msg.roll) == 1018834477
    
    assert dictify(msg.ropl) == 63066
    
    assert dictify(msg.tow) == 4060370030
    
    assert dictify(msg.v_x) == -584647705
    
    assert dictify(msg.v_y) == 1353168848
    
    assert dictify(msg.v_z) == -1537140001
    
    assert dictify(msg.vpl) == 21593
    
    assert dictify(msg.vvpl) == 41277
    
    assert dictify(msg.wn) == 13102

    assert dictify(msg) == {'preamble': 85, 'msg_type': 535, 'sender': 813, 'length': 76, 'payload': 'blQE8i4zNaBZVKcpORXZ9D2hU2iMiVr2MzMzMzOqtECamZmZGVjDQDMzMzMzw3lA5/sm3dC3p1DfGmGkLS66POvjt6C7XXTgaSggIQ==', 'crc': 48261, 'tow': 4060370030, 'wn': 13102, 'hpl': 41013, 'vpl': 21593, 'atpl': 10663, 'ctpl': 5433, 'hvpl': 62681, 'vvpl': 41277, 'hopl': 26707, 'popl': 35212, 'ropl': 63066, 'lat': 5290.2, 'lon': 9904.2, 'height': 412.2, 'v_x': -584647705, 'v_y': 1353168848, 'v_z': -1537140001, 'roll': 1018834477, 'pitch': -1598561301, 'heading': -529244741, 'flags': 555755625}