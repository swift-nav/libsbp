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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuAux.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_imu_msg_imu_aux_1():
    buf = base64.standard_b64decode("VQEJNBIEAfQKQsj8")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xfcc8
    assert payload.length == 4
    assert payload.msg_type == 0x901
    assert payload.payload == "AfQKQg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x1234
    assert dictify(obj.payload.imu_conf) == snake_case_keys( 66 )
    assert dictify(obj.payload.imu_type) == snake_case_keys( 1 )
    assert dictify(obj.payload.temp) == snake_case_keys( 2804 )

    assert dictify(payload) == snake_case_keys( {"imu_type":1,"temp":2804,"imu_conf":66,"preamble":85,"msg_type":2305,"sender":4660,"payload":"AfQKQg==","crc":64712,"length":4} )