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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCTimeGNSS.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_utc_time_gnss_1():
    buf = base64.standard_b64decode("VQUBFQMQARjl6R3lBwQJExgJAAivL7Eh")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x21b1
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x105
    
    assert msg.payload == "ARjl6R3lBwQJExgJAAivLw=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x315
    
    assert dictify(msg.day) == 9
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.hours) == 19
    
    assert dictify(msg.minutes) == 24
    
    assert dictify(msg.month) == 4
    
    assert dictify(msg.ns) == 800000000
    
    assert dictify(msg.seconds) == 9
    
    assert dictify(msg.tow) == 501867800
    
    assert dictify(msg.year) == 2021

    assert dictify(msg) == {'flags': 1, 'tow': 501867800, 'year': 2021, 'month': 4, 'day': 9, 'hours': 19, 'minutes': 24, 'seconds': 9, 'ns': 800000000, 'preamble': 85, 'msg_type': 261, 'sender': 789, 'payload': 'ARjl6R3lBwQJExgJAAivLw==', 'crc': 8625, 'length': 16}