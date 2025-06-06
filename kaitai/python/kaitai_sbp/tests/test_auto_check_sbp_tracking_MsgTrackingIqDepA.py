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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msg_tracking_iq_dep_a_1():
    buf = base64.standard_b64decode("VRwAuEMdixz6DwBjWqpgR3khoTTTomUpJOJjR0sO8IZSr1MRIg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2211
    
    assert msg.length == 29
    
    assert msg.msg_type == 0x1c
    
    assert msg.payload == "ixz6DwBjWqpgR3khoTTTomUpJOJjR0sO8IZSr1M="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x43b8
    
    assert dictify(msg.channel) == 139
    
    assert dictify(msg.corrs) == [{'i': 1621776995, 'q': -1591641785}, {'i': 1705169716, 'q': 1675764777}, {'i': -267498681, 'q': 1403998854}]
    
    assert dictify(msg.sid) == {'code': 15, 'reserved': 0, 'sat': 64028}

    assert dictify(msg) == {'crc': 8721, 'length': 29, 'msg_type': 28, 'payload': 'ixz6DwBjWqpgR3khoTTTomUpJOJjR0sO8IZSr1M=', 'preamble': 85, 'sender': 17336, 'channel': 139, 'sid': {'sat': 64028, 'code': 15, 'reserved': 0}, 'corrs': [{'i': 1621776995, 'q': -1591641785}, {'i': 1705169716, 'q': 1675764777}, {'i': -267498681, 'q': 1403998854}]}
