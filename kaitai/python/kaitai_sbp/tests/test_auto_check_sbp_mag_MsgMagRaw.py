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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/mag/test_MsgMagRaw.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_mag_msg_mag_raw_1():
    buf = base64.standard_b64decode("VQIJwwQLreOexs5iA+YCbuWfFw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x179f
    
    assert msg.length == 11
    
    assert msg.msg_type == 0x902
    
    assert msg.payload == "reOexs5iA+YCbuU="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.mag_x) == 866
    
    assert dictify(msg.mag_y) == 742
    
    assert dictify(msg.mag_z) == -6802
    
    assert dictify(msg.tow) == 3332301741
    
    assert dictify(msg.tow_f) == 206

    assert dictify(msg) == {'preamble': 85, 'msg_type': 2306, 'sender': 1219, 'length': 11, 'payload': 'reOexs5iA+YCbuU=', 'crc': 6047, 'tow': 3332301741, 'tow_f': 206, 'mag_x': 866, 'mag_y': 742, 'mag_z': -6802}