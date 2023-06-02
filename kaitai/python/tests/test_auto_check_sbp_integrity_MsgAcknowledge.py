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
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_integrity_msg_acknowledge_1():
    buf = base64.standard_b64decode("VdILKgALHkDiAQAAAQABAAJWsg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xB256
    assert payload.length == 11
    assert payload.msg_type == 0xBD2
    assert payload.payload == "HkDiAQAAAQABAAI="
    assert payload.preamble == 0x55
    assert payload.sender == 0x2A
    assert dictify(obj.payload.area_id) == snake_case_keys( 123456 )
    assert dictify(obj.payload.correction_mask_on_demand) == snake_case_keys( 1 )
    assert dictify(obj.payload.correction_mask_stream) == snake_case_keys( 1 )
    assert dictify(obj.payload.request_id) == snake_case_keys( 30 )
    assert dictify(obj.payload.response_code) == snake_case_keys( 0 )
    assert dictify(obj.payload.solution_id) == snake_case_keys( 2 )

    assert dictify(payload) == snake_case_keys( {"preamble": 85, "msg_type": 3026, "sender": 42, "length": 11, "payload": "HkDiAQAAAQABAAI=", "crc": 45654, "request_id": 30, "area_id": 123456, "response_code": 0, "correction_mask_on_demand": 1, "correction_mask_stream": 1, "solution_id": 2} )