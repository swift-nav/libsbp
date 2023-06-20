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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgSensorAidEvent.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_sensor_aid_event_1():
    buf = base64.standard_b64decode("VQn/04gPMPZ6EwAAAAAAAAAAAAAAIew=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xEC21
    
    assert msg.length == 15
    
    assert msg.msg_type == 0xFF09
    
    assert msg.payload == "MPZ6EwAAAAAAAAAAAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88D3
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_accepted_meas) == 0
    
    assert dictify(msg.n_attempted_meas) == 0
    
    assert dictify(msg.n_available_meas) == 0
    
    assert dictify(msg.sensor_id) == 0
    
    assert dictify(msg.sensor_state) == 0
    
    assert dictify(msg.sensor_type) == 0
    
    assert dictify(msg.time) == 326825520

    assert dictify(msg) == {'preamble': 85, 'msg_type': 65289, 'sender': 35027, 'length': 15, 'payload': 'MPZ6EwAAAAAAAAAAAAAA', 'crc': 60449, 'time': 326825520, 'sensor_type': 0, 'sensor_id': 0, 'sensor_state': 0, 'n_available_meas': 0, 'n_attempted_meas': 0, 'n_accepted_meas': 0, 'flags': 0}