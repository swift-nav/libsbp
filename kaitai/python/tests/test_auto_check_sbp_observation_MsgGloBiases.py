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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGloBiases.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_glo_biases_1():
    buf = base64.standard_b64decode("VXUAAAAJAAAAAAAAAAAATdM=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd34d
    
    assert msg.length == 9
    
    assert msg.payload == "AAAAAAAAAAAA"
    
    assert msg.msg_type == 0x75
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0
    
    assert dictify(msg.l1ca_bias) == 0
    
    assert dictify(msg.l1p_bias) == 0
    
    assert dictify(msg.l2ca_bias) == 0
    
    assert dictify(msg.l2p_bias) == 0
    
    assert dictify(msg.mask) == 0

    assert dictify(msg) == {'mask': 0, 'l1ca_bias': 0, 'l1p_bias': 0, 'l2ca_bias': 0, 'l2p_bias': 0, 'preamble': 85, 'msg_type': 117, 'sender': 0, 'payload': 'AAAAAAAAAAAA', 'crc': 54093, 'length': 9}