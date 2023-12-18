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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGroupDelayDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_group_delay_dep_a_1():
    buf = base64.standard_b64decode("VZIAewAOsM8GAGoIFgH+/aX/7ReiWw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5ba2
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x92
    
    assert msg.payload == "sM8GAGoIFgH+/aX/7Rc="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x007b
    
    assert dictify(msg.isc_l1ca) == -91
    
    assert dictify(msg.isc_l2c) == 6125
    
    assert dictify(msg.prn) == 22
    
    assert dictify(msg.t_op) == {'tow': 446384, 'wn': 2154}
    
    assert dictify(msg.tgd) == -514
    
    assert dictify(msg.valid) == 1

    assert dictify(msg) == {'crc': 23458, 'length': 14, 'msg_type': 146, 'payload': 'sM8GAGoIFgH+/aX/7Rc=', 'preamble': 85, 'sender': 123, 't_op': {'tow': 446384, 'wn': 2154}, 'prn': 22, 'valid': 1, 'tgd': -514, 'isc_l1ca': -91, 'isc_l2c': 6125}