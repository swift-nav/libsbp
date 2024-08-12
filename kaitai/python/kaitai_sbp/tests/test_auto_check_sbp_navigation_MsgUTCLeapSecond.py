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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCLeapSecond.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_utc_leap_second_1():
    buf = base64.standard_b64decode("VToCQgAOAQACAAMEBQAGAAcACAky6A==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x023A
    
    assert msg.sender == 0x0042
    
    assert msg.length == 14
    
    assert msg.payload == "AQACAAMEBQAGAAcACAk="
    
    assert msg.crc == 0xE832
    
    assert dictify(msg.count_after) == 9
    
    assert dictify(msg.count_before) == 4
    
    assert dictify(msg.ref_dn) == 8
    
    assert dictify(msg.ref_wn) == 7
    
    assert dictify(msg.reserved_0) == 1
    
    assert dictify(msg.reserved_1) == 2
    
    assert dictify(msg.reserved_2) == 3
    
    assert dictify(msg.reserved_3) == 5
    
    assert dictify(msg.reserved_4) == 6

    assert dictify(msg) == {'reserved_0': 1, 'reserved_1': 2, 'reserved_2': 3, 'count_before': 4, 'reserved_3': 5, 'reserved_4': 6, 'ref_wn': 7, 'ref_dn': 8, 'count_after': 9, 'preamble': 85, 'msg_type': 570, 'sender': 66, 'length': 14, 'payload': 'AQACAAMEBQAGAAcACAk=', 'crc': 59442}