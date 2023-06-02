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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgAgeCorrections.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_age_corrections_1():
    buf = base64.standard_b64decode("VRACQgAGZAAAAB4A6co=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xcae9
    assert payload.length == 6
    assert payload.msg_type == 0x210
    assert payload.payload == "ZAAAAB4A"
    assert payload.preamble == 0x55
    assert payload.sender == 0x42
    assert dictify(obj.payload.age) == snake_case_keys( 30 )
    assert dictify(obj.payload.tow) == snake_case_keys( 100 )

    assert dictify(payload) == snake_case_keys( {"sender": 66, "msg_type": 528, "age": 30, "tow": 100, "crc": 51945, "length": 6, "preamble": 85, "payload": "ZAAAAB4A"} )