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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgLog.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_logging_msg_log_1():
    buf = base64.standard_b64decode("VQEECgksBkZpbHRlcmVkIGFsbCBvYnMgZnJvbSAyMzE0IGF0IHRvdyA4My41MzkwMTmxow==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"level":6,"text":"Filtered all obs from 2314 at tow 83.539019","preamble":85,"msg_type":1025,"sender":2314,"payload":"BkZpbHRlcmVkIGFsbCBvYnMgZnJvbSAyMzE0IGF0IHRvdyA4My41MzkwMTk=","crc":41905,"length":44}
    assert parsed_dict['crc'] == 0xa3b1
    assert parsed_dict['length'] == 44
    assert parsed_dict['msg_type'] == 0x0401
    assert parsed_dict['payload'] == "BkZpbHRlcmVkIGFsbCBvYnMgZnJvbSAyMzE0IGF0IHRvdyA4My41MzkwMTk="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x90a
    assert dictify(obj.payload.level) == snake_case_keys( 6 )
    assert dictify(obj.payload.text) == snake_case_keys( 'Filtered all obs from 2314 at tow 83.539019' )

    assert parsed_dict == snake_case_keys(orig_dict)