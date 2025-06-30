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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgCsacTelemetry.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_csac_telemetry_1():
    buf = base64.standard_b64decode("VQT/9KkKaXNvbWUgZGF0YeVe")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5ee5
    
    assert msg.length == 10
    
    assert msg.msg_type == 0xff04
    
    assert msg.payload == "aXNvbWUgZGF0YQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xa9f4
    
    assert dictify(msg.id) == 105
    
    assert dictify(msg.telemetry) == "some data"

    assert dictify(msg) == {'preamble': 85, 'msg_type': 65284, 'sender': 43508, 'length': 10, 'payload': 'aXNvbWUgZGF0YQ==', 'crc': 24293, 'id': 105, 'telemetry': 'some data'}
