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
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_logging_msg_log_1():
    buf = base64.standard_b64decode("VQEECgksBkZpbHRlcmVkIGFsbCBvYnMgZnJvbSAyMzE0IGF0IHRvdyA4My41MzkwMTmxow==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa3b1
    
    assert msg.length == 44
    
    assert msg.msg_type == 0x0401
    
    assert msg.payload == "BkZpbHRlcmVkIGFsbCBvYnMgZnJvbSAyMzE0IGF0IHRvdyA4My41MzkwMTk="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x90a
    
    assert dictify(msg.level) == 6
    
    assert dictify(msg.text) == "Filtered all obs from 2314 at tow 83.539019"

    assert dictify(msg) == {'level': 6, 'text': 'Filtered all obs from 2314 at tow 83.539019', 'preamble': 85, 'msg_type': 1025, 'sender': 2314, 'payload': 'BkZpbHRlcmVkIGFsbCBvYnMgZnJvbSAyMzE0IGF0IHRvdyA4My41MzkwMTk=', 'crc': 41905, 'length': 44}