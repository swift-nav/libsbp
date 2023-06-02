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

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_sensor_aid_event_1():
    buf = base64.standard_b64decode("VQn/04gPMPZ6EwAAAAAAAAAAAAAAIew=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"preamble": 85, "msg_type": 65289, "sender": 35027, "length": 15, "payload": "MPZ6EwAAAAAAAAAAAAAA", "crc": 60449, "time": 326825520, "sensor_type": 0, "sensor_id": 0, "sensor_state": 0, "n_available_meas": 0, "n_attempted_meas": 0, "n_accepted_meas": 0, "flags": 0}
    assert parsed_dict['crc'] == 0xEC21
    assert parsed_dict['length'] == 15
    assert parsed_dict['msg_type'] == 0xFF09
    assert parsed_dict['payload'] == "MPZ6EwAAAAAAAAAAAAAA"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88D3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_accepted_meas) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_attempted_meas) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_available_meas) == snake_case_keys( 0 )
    assert dictify(obj.payload.sensor_id) == snake_case_keys( 0 )
    assert dictify(obj.payload.sensor_state) == snake_case_keys( 0 )
    assert dictify(obj.payload.sensor_type) == snake_case_keys( 0 )
    assert dictify(obj.payload.time) == snake_case_keys( 326825520 )

    assert parsed_dict == snake_case_keys(orig_dict)