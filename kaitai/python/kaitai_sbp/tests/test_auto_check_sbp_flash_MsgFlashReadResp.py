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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashReadResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_flash_msg_flash_read_resp_1():
    buf = base64.standard_b64decode("VeEAwwQFiJs0rHyVhw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8795
    
    assert msg.length == 5
    
    assert msg.msg_type == 0xe1
    
    assert msg.payload == "iJs0rHw="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.addr_len) == 124
    
    assert dictify(msg.addr_start) == [155, 52, 172]
    
    assert dictify(msg.target) == 136

    assert dictify(msg) == {'crc': 34709, 'length': 5, 'msg_type': 225, 'payload': 'iJs0rHw=', 'preamble': 85, 'sender': 1219, 'target': 136, 'addr_start': [155, 52, 172], 'addr_len': 124}
