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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineHeadingDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_baseline_heading_dep_a_1():
    buf = base64.standard_b64decode("VQcCfM4KUm1YsEQOUsu6Oq22")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb6ad
    
    assert msg.length == 10
    
    assert msg.msg_type == 0x207
    
    assert msg.payload == "Um1YsEQOUsu6Og=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xce7c
    
    assert dictify(msg.flags) == 58
    
    assert dictify(msg.heading) == 3411152452
    
    assert dictify(msg.n_sats) == 186
    
    assert dictify(msg.tow) == 2958585170

    assert dictify(msg) == {'crc': 46765, 'length': 10, 'msg_type': 519, 'payload': 'Um1YsEQOUsu6Og==', 'preamble': 85, 'sender': 52860, 'tow': 2958585170, 'heading': 3411152452, 'n_sats': 186, 'flags': 58}