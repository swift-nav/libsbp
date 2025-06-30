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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_logging_msg_fwd_1():
    buf = base64.standard_b64decode("VQIEQgASAABWUUQvUWdBRUFBQUFBRWFnfV8=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5f7d
    
    assert msg.length == 18
    
    assert msg.msg_type == 0x402
    
    assert msg.payload == "AABWUUQvUWdBRUFBQUFBRWFn"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.fwd_payload) == [86, 81, 68, 47, 81, 103, 65, 69, 65, 65, 65, 65, 65, 69, 97, 103]
    
    assert dictify(msg.protocol) == 0
    
    assert dictify(msg.source) == 0

    assert dictify(msg) == {'protocol': 0, 'sender': 66, 'msg_type': 1026, 'source': 0, 'fwd_payload': [86, 81, 68, 47, 81, 103, 65, 69, 65, 65, 65, 65, 65, 69, 97, 103], 'crc': 24445, 'length': 18, 'preamble': 85, 'payload': 'AABWUUQvUWdBRUFBQUFBRWFn'}
