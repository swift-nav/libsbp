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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDops.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_dops_1():
    buf = base64.standard_b64decode("VQgCQgAPZAAAAAIABgAFAAUABQAA9AQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4f4
    
    assert msg.length == 15
    
    assert msg.msg_type == 0x208
    
    assert msg.payload == "ZAAAAAIABgAFAAUABQAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.gdop) == 2
    
    assert dictify(msg.hdop) == 5
    
    assert dictify(msg.pdop) == 6
    
    assert dictify(msg.tdop) == 5
    
    assert dictify(msg.tow) == 100
    
    assert dictify(msg.vdop) == 5

    assert dictify(msg) == {'gdop': 2, 'tdop': 5, 'vdop': 5, 'sender': 66, 'msg_type': 520, 'pdop': 6, 'tow': 100, 'crc': 1268, 'length': 15, 'flags': 0, 'preamble': 85, 'payload': 'ZAAAAAIABgAFAAUABQAA', 'hdop': 5}