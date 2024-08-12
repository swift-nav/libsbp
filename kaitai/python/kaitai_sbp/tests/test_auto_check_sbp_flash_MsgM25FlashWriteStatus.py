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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgM25FlashWriteStatus.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_flash_msg_m25_flash_write_status_1():
    buf = base64.standard_b64decode("VfMAwwQBBXDI")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc870
    
    assert msg.length == 1
    
    assert msg.msg_type == 0xf3
    
    assert msg.payload == "BQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.status) == [5]

    assert dictify(msg) == {'crc': 51312, 'length': 1, 'msg_type': 243, 'payload': 'BQ==', 'preamble': 85, 'sender': 1219, 'status': [5]}