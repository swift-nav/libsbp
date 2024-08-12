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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsWrite.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_settings_msg_settings_write_1():
    buf = base64.standard_b64decode("VaAAewAoc2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQBzZXR0aW5nLXZhbHVlAPQK")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xaf4
    
    assert msg.length == 40
    
    assert msg.msg_type == 0xa0
    
    assert msg.payload == "c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQBzZXR0aW5nLXZhbHVlAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x7b
    
    assert dictify(msg.setting) == "section-name\x00setting-name\x00setting-value\x00"

    assert dictify(msg) == {'crc': 2804, 'length': 40, 'msg_type': 160, 'payload': 'c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQBzZXR0aW5nLXZhbHVlAA==', 'preamble': 85, 'sender': 123, 'setting': 'section-name\x00setting-name\x00setting-value\x00'}