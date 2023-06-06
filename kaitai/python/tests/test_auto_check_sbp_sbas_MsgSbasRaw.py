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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/sbas/test_MsgSbasRaw.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_sbas_msg_sbas_raw_1():
    buf = base64.standard_b64decode("VXd3HMgigwLJ5OkdBBf/ABf/ABf/f/AC/8ADf/f/f/f/5eXuqq//8KcO")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xea7
    
    assert msg.length == 34
    
    assert msg.payload == "gwLJ5OkdBBf/ABf/ABf/f/AC/8ADf/f/f/f/5eXuqq//8A=="
    
    assert msg.msg_type == 0x7777
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xc81c
    
    assert dictify(msg.data) == [23, 255, 0, 23, 255, 0, 23, 255, 127, 240, 2, 255, 192, 3, 127, 247, 255, 127, 247, 255, 229, 229, 238, 170, 175, 255, 240]
    
    assert dictify(msg.message_type) == 4
    
    assert dictify(msg.sid) == {'sat': 131, 'code': 2}
    
    assert dictify(msg.tow) == 501867721

    assert dictify(msg) == {'sid': {'sat': 131, 'code': 2}, 'tow': 501867721, 'message_type': 4, 'data': [23, 255, 0, 23, 255, 0, 23, 255, 127, 240, 2, 255, 192, 3, 127, 247, 255, 127, 247, 255, 229, 229, 238, 170, 175, 255, 240], 'preamble': 85, 'msg_type': 30583, 'sender': 51228, 'payload': 'gwLJ5OkdBBf/ABf/ABf/f/AC/8ADf/f/f/f/5eXuqq//8A==', 'crc': 3751, 'length': 34}