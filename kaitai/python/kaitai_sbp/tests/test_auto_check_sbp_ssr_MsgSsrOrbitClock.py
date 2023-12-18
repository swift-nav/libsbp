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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClock.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_orbit_clock_1():
    buf = base64.standard_b64decode("Vd0FNeUyU9Bmz6Qdy9Ts/5jpzzdeNjqARBt1sG77PfR6Ml80kOgYCiV/o0KxaZz1Cvlr2hG6OEgOFg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x160e
    
    assert msg.length == 50
    
    assert msg.msg_type == 0x5dd
    
    assert msg.payload == "U9Bmz6Qdy9Ts/5jpzzdeNjqARBt1sG77PfR6Ml80kOgYCiV/o0KxaZz1Cvlr2hG6OEg="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xe535
    
    assert dictify(msg.along) == -1334502588
    
    assert dictify(msg.c0) == -174298703
    
    assert dictify(msg.c1) == -630458102
    
    assert dictify(msg.c2) == 1211677201
    
    assert dictify(msg.cross) == -197264530
    
    assert dictify(msg.dot_along) == 169404560
    
    assert dictify(msg.dot_cross) == 1118011173
    
    assert dictify(msg.dot_radial) == 878654074
    
    assert dictify(msg.iod) == 936372632
    
    assert dictify(msg.iod_ssr) == 255
    
    assert dictify(msg.radial) == -2143668642
    
    assert dictify(msg.sid) == {'code': 212, 'sat': 203}
    
    assert dictify(msg.time) == {'tow': 3479621715, 'wn': 7588}
    
    assert dictify(msg.update_interval) == 236

    assert dictify(msg) == {'crc': 5646, 'length': 50, 'msg_type': 1501, 'payload': 'U9Bmz6Qdy9Ts/5jpzzdeNjqARBt1sG77PfR6Ml80kOgYCiV/o0KxaZz1Cvlr2hG6OEg=', 'preamble': 85, 'sender': 58677, 'time': {'tow': 3479621715, 'wn': 7588}, 'sid': {'sat': 203, 'code': 212}, 'update_interval': 236, 'iod_ssr': 255, 'iod': 936372632, 'radial': -2143668642, 'along': -1334502588, 'cross': -197264530, 'dot_radial': 878654074, 'dot_along': 169404560, 'dot_cross': 1118011173, 'c0': -174298703, 'c1': -630458102, 'c2': 1211677201}