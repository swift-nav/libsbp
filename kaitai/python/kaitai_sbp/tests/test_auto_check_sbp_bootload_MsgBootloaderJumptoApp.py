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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgBootloaderJumptoApp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_bootload_msg_bootloader_jumpto_app_1():
    buf = base64.standard_b64decode("VbEAzRIB2Glg")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6069
    
    assert msg.length == 1
    
    assert msg.msg_type == 0xb1
    
    assert msg.payload == "2A=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x12cd
    
    assert dictify(msg.jump) == 216

    assert dictify(msg) == {'crc': 24681, 'length': 1, 'msg_type': 177, 'payload': '2A==', 'preamble': 85, 'sender': 4813, 'jump': 216}
