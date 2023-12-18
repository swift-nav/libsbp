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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_a_1():
    buf = base64.standard_b64decode("VSEAm245Lh+0JtsAAACFZEdewAKgz9T/h4s+PrNT4/WGoMxOX/8mO6EP/1a9+B+/iMJ8Fw9b+XWOWttDGVM+emQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x647a
    
    assert msg.length == 57
    
    assert msg.msg_type == 0x21
    
    assert msg.payload == "Lh+0JtsAAACFZEdewAKgz9T/h4s+PrNT4/WGoMxOX/8mO6EP/1a9+B+/iMJ8Fw9b+XWOWttDGVM+"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x6e9b
    
    assert dictify(msg.l) == {'f': 204, 'i': -1601767965}
    
    assert dictify(msg.p) == 1044286343
    
    assert dictify(msg.p_std) == 21427
    
    assert dictify(msg.acceleration) == -114
    
    assert dictify(msg.clock_drift) == 23311
    
    assert dictify(msg.clock_offset) == 6012
    
    assert dictify(msg.cn0) == 78
    
    assert dictify(msg.corr_spacing) == 30201
    
    assert dictify(msg.doppler) == 1459556257
    
    assert dictify(msg.doppler_std) == 63677
    
    assert dictify(msg.lock) == 65375
    
    assert dictify(msg.misc_flags) == 62
    
    assert dictify(msg.nav_flags) == 25
    
    assert dictify(msg.pset_flags) == 83
    
    assert dictify(msg.recv_time) == 941247176494
    
    assert dictify(msg.sid) == {'code': 59, 'sat': 38}
    
    assert dictify(msg.sync_flags) == 90
    
    assert dictify(msg.tot) == {'ns_residual': -811597120, 'tow': 1581737093, 'wn': 65492}
    
    assert dictify(msg.tow_flags) == 219
    
    assert dictify(msg.track_flags) == 67
    
    assert dictify(msg.uptime) == 3263741727

    assert dictify(msg) == {'crc': 25722, 'length': 57, 'msg_type': 33, 'payload': 'Lh+0JtsAAACFZEdewAKgz9T/h4s+PrNT4/WGoMxOX/8mO6EP/1a9+B+/iMJ8Fw9b+XWOWttDGVM+', 'preamble': 85, 'sender': 28315, 'recv_time': 941247176494, 'tot': {'tow': 1581737093, 'ns_residual': -811597120, 'wn': 65492}, 'p': 1044286343, 'p_std': 21427, 'l': {'i': -1601767965, 'f': 204}, 'cn0': 78, 'lock': 65375, 'sid': {'sat': 38, 'code': 59}, 'doppler': 1459556257, 'doppler_std': 63677, 'uptime': 3263741727, 'clock_offset': 6012, 'clock_drift': 23311, 'corr_spacing': 30201, 'acceleration': -114, 'sync_flags': 90, 'tow_flags': 219, 'track_flags': 67, 'nav_flags': 25, 'pset_flags': 83, 'misc_flags': 62}