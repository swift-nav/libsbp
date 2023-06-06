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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgHeartbeat.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_heartbeat_1():
    buf = base64.standard_b64decode("Vf//9tcEADIAAPnY")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd8f9
    
    assert msg.length == 4
    
    assert msg.msg_type == 0xffff
    
    assert msg.payload == "ADIAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.flags) == 12800

    assert dictify(msg) == {'sender': 55286, 'msg_type': 65535, 'crc': 55545, 'length': 4, 'flags': 12800, 'preamble': 85, 'payload': 'ADIAAA=='}

def test_auto_check_sbp_system_msg_heartbeat_2():
    buf = base64.standard_b64decode("Vf//wwQEAAAAAEI5")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x3942
    
    assert msg.length == 4
    
    assert msg.msg_type == 0xffff
    
    assert msg.payload == "AAAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.flags) == 0

    assert dictify(msg) == {'sender': 1219, 'msg_type': 65535, 'crc': 14658, 'length': 4, 'flags': 0, 'preamble': 85, 'payload': 'AAAAAA=='}