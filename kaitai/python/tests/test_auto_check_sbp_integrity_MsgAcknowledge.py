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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgAcknowledge.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_integrity_msg_acknowledge_1():
    buf = base64.standard_b64decode("VdILKgALHkDiAQAAAQABAAJWsg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xB256
    
    assert msg.length == 11
    
    assert msg.msg_type == 0xBD2
    
    assert msg.payload == "HkDiAQAAAQABAAI="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x2A
    
    assert dictify(msg.area_id) == 123456
    
    assert dictify(msg.correction_mask_on_demand) == 1
    
    assert dictify(msg.correction_mask_stream) == 1
    
    assert dictify(msg.request_id) == 30
    
    assert dictify(msg.response_code) == 0
    
    assert dictify(msg.solution_id) == 2

    assert dictify(msg) == {'preamble': 85, 'msg_type': 3026, 'sender': 42, 'length': 11, 'payload': 'HkDiAQAAAQABAAI=', 'crc': 45654, 'request_id': 30, 'area_id': 123456, 'response_code': 0, 'correction_mask_on_demand': 1, 'correction_mask_stream': 1, 'solution_id': 2}