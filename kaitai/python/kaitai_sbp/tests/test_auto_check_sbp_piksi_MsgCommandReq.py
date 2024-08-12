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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCommandReq.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_command_req_1():
    buf = base64.standard_b64decode("VbgAqrgfM02jaC9wYXRoL3RvL2NvbW1hbmQgd2l0aCBhcmdzACYY")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1826
    
    assert msg.length == 31
    
    assert msg.msg_type == 0xb8
    
    assert msg.payload == "M02jaC9wYXRoL3RvL2NvbW1hbmQgd2l0aCBhcmdzAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xb8aa
    
    assert dictify(msg.command) == "/path/to/command with args\x00"
    
    assert dictify(msg.sequence) == 1755532595

    assert dictify(msg) == {'crc': 6182, 'length': 31, 'msg_type': 184, 'payload': 'M02jaC9wYXRoL3RvL2NvbW1hbmQgd2l0aCBhcmdzAA==', 'preamble': 85, 'sender': 47274, 'sequence': 1755532595, 'command': '/path/to/command with args\x00'}