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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ext_events/test_MsgExtEvent.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ext_events_msg_ext_event_1():
    buf = base64.standard_b64decode("VQEB9QYMMAfH2DEPykEPAAMAPsw=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xcc3e
    
    assert msg.length == 12
    
    assert msg.msg_type == 0x101
    
    assert msg.payload == "MAfH2DEPykEPAAMA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x6f5
    
    assert dictify(msg.flags) == 3
    
    assert dictify(msg.ns_residual) == 999882
    
    assert dictify(msg.pin) == 0
    
    assert dictify(msg.tow) == 254924999
    
    assert dictify(msg.wn) == 1840

    assert dictify(msg) == {'sender': 1781, 'msg_type': 257, 'wn': 1840, 'tow': 254924999, 'crc': 52286, 'length': 12, 'flags': 3, 'pin': 0, 'ns_residual': 999882, 'preamble': 85, 'payload': 'MAfH2DEPykEPAAMA'}