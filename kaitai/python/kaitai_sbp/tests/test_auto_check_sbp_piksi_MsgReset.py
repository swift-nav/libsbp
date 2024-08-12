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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgReset.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_reset_1():
    buf = base64.standard_b64decode("VbYAP9IEWPjuE0rP")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xcf4a
    
    assert msg.length == 4
    
    assert msg.msg_type == 0xb6
    
    assert msg.payload == "WPjuEw=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd23f
    
    assert dictify(msg.flags) == 334428248

    assert dictify(msg) == {'crc': 53066, 'length': 4, 'msg_type': 182, 'payload': 'WPjuEw==', 'preamble': 85, 'sender': 53823, 'flags': 334428248}