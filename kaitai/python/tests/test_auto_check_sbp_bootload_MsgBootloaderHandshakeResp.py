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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgBootloaderHandshakeResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_bootload_msg_bootloader_handshake_resp_1():
    buf = base64.standard_b64decode("VbQAAAAJAAAAAHYxLjIKyQE=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1c9
    
    assert msg.length == 9
    
    assert msg.msg_type == 0xb4
    
    assert msg.payload == "AAAAAHYxLjIK"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.version) == "v1.2\n"

    assert dictify(msg) == {'sender': 0, 'msg_type': 180, 'crc': 457, 'length': 9, 'version': 'v1.2\n', 'flags': 0, 'preamble': 85, 'payload': 'AAAAAHYxLjIK'}

def test_auto_check_sbp_bootload_msg_bootloader_handshake_resp_2():
    buf = base64.standard_b64decode("VbAAwwQEdjEuMgHO")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xce01
    
    assert msg.length == 4
    
    assert msg.msg_type == 0xb0
    
    assert msg.payload == "djEuMg=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.handshake) == [118, 49, 46, 50]

    assert dictify(msg) == {'handshake': [118, 49, 46, 50], 'crc': 52737, 'length': 4, 'msg_type': 176, 'payload': 'djEuMg==', 'preamble': 85, 'sender': 1219}