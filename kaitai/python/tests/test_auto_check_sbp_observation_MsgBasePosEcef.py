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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosEcef.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_base_pos_ecef_1():
    buf = base64.standard_b64decode("VUgAAAAY5IOe9VfNRMFCPujRIHZQwdXnavs/FE1Bwn0=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7dc2
    
    assert msg.length == 24
    
    assert msg.payload == "5IOe9VfNRMFCPujRIHZQwdXnavs/FE1B"
    
    assert msg.msg_type == 0x48
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0
    
    assert dictify(msg.x) == -2726575.9189
    
    assert dictify(msg.y) == -4315267.2798
    
    assert dictify(msg.z) == 3811455.9642

    assert dictify(msg) == {'x': -2726575.9189, 'y': -4315267.2798, 'z': 3811455.9642, 'preamble': 85, 'msg_type': 72, 'sender': 0, 'payload': '5IOe9VfNRMFCPujRIHZQwdXnavs/FE1B', 'crc': 32194, 'length': 24}