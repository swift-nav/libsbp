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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuComp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_imu_msg_imu_comp_1():
    buf = base64.standard_b64decode("VQUJNBIiGgEAwAAAAADOAGAAAADf////LBAAADwAAADQ/v//7v///09W")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x564f
    
    assert msg.length == 34
    
    assert msg.msg_type == 0x905
    
    assert msg.payload == "GgEAwAAAAADOAGAAAADf////LBAAADwAAADQ/v//7v///w=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1234
    
    assert dictify(msg.acc_comp_x) == 96
    
    assert dictify(msg.acc_comp_y) == -33
    
    assert dictify(msg.acc_comp_z) == 4140
    
    assert dictify(msg.flags) == 206
    
    assert dictify(msg.gyr_comp_x) == 60
    
    assert dictify(msg.gyr_comp_y) == -304
    
    assert dictify(msg.gyr_comp_z) == -18
    
    assert dictify(msg.time) == 3221225754

    assert dictify(msg) == {'time': 3221225754, 'flags': 206, 'acc_comp_x': 96, 'acc_comp_y': -33, 'acc_comp_z': 4140, 'gyr_comp_x': 60, 'gyr_comp_y': -304, 'gyr_comp_z': -18, 'preamble': 85, 'msg_type': 2309, 'sender': 4660, 'payload': 'GgEAwAAAAADOAGAAAADf////LBAAADwAAADQ/v//7v///w==', 'crc': 22095, 'length': 34}
