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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgBaselineHeading.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_orientation_msg_baseline_heading_1():
    buf = base64.standard_b64decode("VQ8C010KnC0NxCxUxT1bW+D+")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xfee0
    
    assert msg.length == 10
    
    assert msg.msg_type == 0x20f
    
    assert msg.payload == "nC0NxCxUxT1bWw=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x5dd3
    
    assert dictify(msg.flags) == 91
    
    assert dictify(msg.heading) == 1036342316
    
    assert dictify(msg.n_sats) == 91
    
    assert dictify(msg.tow) == 3289197980

    assert dictify(msg) == {'crc': 65248, 'length': 10, 'msg_type': 527, 'payload': 'nC0NxCxUxT1bWw==', 'preamble': 85, 'sender': 24019, 'tow': 3289197980, 'heading': 1036342316, 'n_sats': 91, 'flags': 91}
