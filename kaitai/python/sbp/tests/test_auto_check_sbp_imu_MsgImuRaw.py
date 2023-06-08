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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuRaw.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_imu_msg_imu_raw_1():
    buf = base64.standard_b64decode("VQAJNBIRGgEAwM5gAN//LBA8AND+7v9Ghw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8746
    
    assert msg.length == 17
    
    assert msg.msg_type == 0x900
    
    assert msg.payload == "GgEAwM5gAN//LBA8AND+7v8="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1234
    
    assert dictify(msg.acc_x) == 96
    
    assert dictify(msg.acc_y) == -33
    
    assert dictify(msg.acc_z) == 4140
    
    assert dictify(msg.gyr_x) == 60
    
    assert dictify(msg.gyr_y) == -304
    
    assert dictify(msg.gyr_z) == -18
    
    assert dictify(msg.tow) == 3221225754
    
    assert dictify(msg.tow_f) == 206

    assert dictify(msg) == {'tow': 3221225754, 'tow_f': 206, 'acc_x': 96, 'acc_y': -33, 'acc_z': 4140, 'gyr_x': 60, 'gyr_y': -304, 'gyr_z': -18, 'preamble': 85, 'msg_type': 2304, 'sender': 4660, 'payload': 'GgEAwM5gAN//LBA8AND+7v8=', 'crc': 34630, 'length': 17}