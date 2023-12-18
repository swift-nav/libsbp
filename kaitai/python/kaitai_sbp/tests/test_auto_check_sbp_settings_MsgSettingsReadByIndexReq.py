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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexReq.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_settings_msg_settings_read_by_index_req_1():
    buf = base64.standard_b64decode("VaIAensC9CLrFw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x17eb
    
    assert msg.length == 2
    
    assert msg.msg_type == 0xa2
    
    assert msg.payload == "9CI="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x7b7a
    
    assert dictify(msg.index) == 8948

    assert dictify(msg) == {'crc': 6123, 'length': 2, 'msg_type': 162, 'payload': '9CI=', 'preamble': 85, 'sender': 31610, 'index': 8948}