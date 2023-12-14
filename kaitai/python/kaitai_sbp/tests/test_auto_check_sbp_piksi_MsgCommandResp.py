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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCommandResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_command_resp_1():
    buf = base64.standard_b64decode("VbkAOc4IdteDoNJulmek8A==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf0a4
    
    assert msg.length == 8
    
    assert msg.msg_type == 0xb9
    
    assert msg.payload == "dteDoNJulmc="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xce39
    
    assert dictify(msg.code) == 1737912018
    
    assert dictify(msg.sequence) == 2692994934

    assert dictify(msg) == {'crc': 61604, 'length': 8, 'msg_type': 185, 'payload': 'dteDoNJulmc=', 'preamble': 85, 'sender': 52793, 'sequence': 2692994934, 'code': 1737912018}