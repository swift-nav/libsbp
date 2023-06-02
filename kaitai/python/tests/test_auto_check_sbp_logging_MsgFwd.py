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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_logging_msg_fwd_1():
    buf = base64.standard_b64decode("VQIEQgASAABWUUQvUWdBRUFBQUFBRWFnfV8=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"protocol": 0, "sender": 66, "msg_type": 1026, "source": 0, "fwd_payload": [ 86, 81, 68, 47, 81, 103, 65, 69, 65, 65, 65, 65, 65, 69, 97, 103 ], "crc": 24445, "length": 18, "preamble": 85, "payload": "AABWUUQvUWdBRUFBQUFBRWFn"}
    assert parsed_dict['crc'] == 0x5f7d
    assert parsed_dict['length'] == 18
    assert parsed_dict['msg_type'] == 0x402
    assert parsed_dict['payload'] == "AABWUUQvUWdBRUFBQUFBRWFn"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.fwd_payload) == snake_case_keys( [86, 81, 68, 47, 81, 103, 65, 69, 65, 65, 65, 65, 65, 69, 97, 103] )
    assert dictify(obj.payload.protocol) == snake_case_keys( 0 )
    assert dictify(obj.payload.source) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)