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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStartup.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_startup_1():
    buf = base64.standard_b64decode("VQD/QgAEAAAAAEag")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa046
    
    assert msg.length == 4
    
    assert msg.msg_type == 0xff00
    
    assert msg.payload == "AAAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.cause) == 0
    
    assert dictify(msg.reserved) == 0
    
    assert dictify(msg.startup_type) == 0

    assert dictify(msg) == {'reserved': 0, 'sender': 66, 'msg_type': 65280, 'cause': 0, 'startup_type': 0, 'crc': 41030, 'length': 4, 'preamble': 85, 'payload': 'AAAAAA=='}

def test_auto_check_sbp_system_msg_startup_2():
    buf = base64.standard_b64decode("VQD/wwQEAAAAAH+1")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb57f
    
    assert msg.length == 4
    
    assert msg.msg_type == 0xff00
    
    assert msg.payload == "AAAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cause) == 0
    
    assert dictify(msg.reserved) == 0
    
    assert dictify(msg.startup_type) == 0

    assert dictify(msg) == {'reserved': 0, 'cause': 0, 'startup_type': 0, 'sender': 1219, 'msg_type': 65280, 'crc': 46463, 'length': 4, 'preamble': 85, 'payload': 'AAAAAA=='}