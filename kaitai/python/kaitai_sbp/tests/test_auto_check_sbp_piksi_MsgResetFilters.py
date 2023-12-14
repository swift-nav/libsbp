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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgResetFilters.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_reset_filters_1():
    buf = base64.standard_b64decode("VSIAUcgBZIIt")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2d82
    
    assert msg.length == 1
    
    assert msg.msg_type == 0x22
    
    assert msg.payload == "ZA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xc851
    
    assert dictify(msg.filter) == 100

    assert dictify(msg) == {'crc': 11650, 'length': 1, 'msg_type': 34, 'payload': 'ZA==', 'preamble': 85, 'sender': 51281, 'filter': 100}