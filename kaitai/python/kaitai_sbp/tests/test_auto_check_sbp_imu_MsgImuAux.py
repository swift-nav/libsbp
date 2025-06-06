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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuAux.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_imu_msg_imu_aux_1():
    buf = base64.standard_b64decode("VQEJNBIEAfQKQsj8")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xfcc8
    
    assert msg.length == 4
    
    assert msg.msg_type == 0x901
    
    assert msg.payload == "AfQKQg=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1234
    
    assert dictify(msg.imu_conf) == 66
    
    assert dictify(msg.imu_type) == 1
    
    assert dictify(msg.temp) == 2804

    assert dictify(msg) == {'imu_type': 1, 'temp': 2804, 'imu_conf': 66, 'preamble': 85, 'msg_type': 2305, 'sender': 4660, 'payload': 'AfQKQg==', 'crc': 64712, 'length': 4}
