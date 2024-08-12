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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashReadReq.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_flash_msg_flash_read_req_1():
    buf = base64.standard_b64decode("VecAwwQF8RxL9EfSOQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x39d2
    
    assert msg.length == 5
    
    assert msg.msg_type == 0xe7
    
    assert msg.payload == "8RxL9Ec="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.addr_len) == 71
    
    assert dictify(msg.addr_start) == [28, 75, 244]
    
    assert dictify(msg.target) == 241

    assert dictify(msg) == {'crc': 14802, 'length': 5, 'msg_type': 231, 'payload': '8RxL9Ec=', 'preamble': 85, 'sender': 1219, 'target': 241, 'addr_start': [28, 75, 244], 'addr_len': 71}