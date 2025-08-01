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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/vehicle/test_MsgWheeltick.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_vehicle_msg_wheeltick_1():
    buf = base64.standard_b64decode("VQQJa0UO/htyLBoAAAABkuEzCdIkOA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x3824
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x904
    
    assert msg.payload == "/htyLBoAAAABkuEzCdI="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x456b
    
    assert dictify(msg.flags) == 1
    
    assert dictify(msg.source) == 146
    
    assert dictify(msg.ticks) == -771148831
    
    assert dictify(msg.time) == 112414825470

    assert dictify(msg) == {'preamble': 85, 'msg_type': 2308, 'sender': 17771, 'length': 14, 'payload': '/htyLBoAAAABkuEzCdI=', 'crc': 14372, 'time': 112414825470, 'flags': 1, 'source': 146, 'ticks': -771148831}
