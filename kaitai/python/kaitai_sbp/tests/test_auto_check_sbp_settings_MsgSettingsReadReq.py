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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadReq.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_settings_msg_settings_read_req_1():
    buf = base64.standard_b64decode("VaQAmNYac2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQC15A==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe4b5
    
    assert msg.length == 26
    
    assert msg.msg_type == 0xa4
    
    assert msg.payload == "c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd698
    
    assert dictify(msg.setting) == "section-name\x00setting-name\x00"

    assert dictify(msg) == {'crc': 58549, 'length': 26, 'msg_type': 164, 'payload': 'c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQA=', 'preamble': 85, 'sender': 54936, 'setting': 'section-name\x00setting-name\x00'}