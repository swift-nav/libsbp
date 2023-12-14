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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgStmUniqueIdResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_flash_msg_stm_unique_id_resp_1():
    buf = base64.standard_b64decode("VeUAwwQMxBAPo1Xdd2YgwjiQ3cQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc4dd
    
    assert msg.length == 12
    
    assert msg.msg_type == 0xe5
    
    assert msg.payload == "xBAPo1Xdd2YgwjiQ"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.stm_id) == [196, 16, 15, 163, 85, 221, 119, 102, 32, 194, 56, 144]

    assert dictify(msg) == {'crc': 50397, 'length': 12, 'msg_type': 229, 'payload': 'xBAPo1Xdd2YgwjiQ', 'preamble': 85, 'sender': 1219, 'stm_id': [196, 16, 15, 163, 85, 221, 119, 102, 32, 194, 56, 144]}