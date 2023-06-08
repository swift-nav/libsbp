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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgInsUpdates.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_ins_updates_1():
    buf = base64.standard_b64decode("VQb/FQMKVOURHgAAAAAAAFE/")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x3f51
    
    assert msg.length == 10
    
    assert msg.payload == "VOURHgAAAAAAAA=="
    
    assert msg.msg_type == 0xff06
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x315
    
    assert dictify(msg.gnsspos) == 0
    
    assert dictify(msg.gnssvel) == 0
    
    assert dictify(msg.nhc) == 0
    
    assert dictify(msg.speed) == 0
    
    assert dictify(msg.tow) == 504489300
    
    assert dictify(msg.wheelticks) == 0
    
    assert dictify(msg.zerovel) == 0

    assert dictify(msg) == {'tow': 504489300, 'gnsspos': 0, 'gnssvel': 0, 'wheelticks': 0, 'speed': 0, 'nhc': 0, 'zerovel': 0, 'preamble': 85, 'msg_type': 65286, 'sender': 789, 'payload': 'VOURHgAAAAAAAA==', 'crc': 16209, 'length': 10}