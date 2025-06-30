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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_orbit_clock_dep_a_1():
    buf = base64.standard_b64decode("VdwFIaYv4XIfvSseAR7C08GvoY/+OD/oB9hFAW6lfMS9G3RYBD0DlxKrky7GVfP14et7tdKd/A==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xfc9d
    
    assert msg.length == 47
    
    assert msg.msg_type == 0x5dc
    
    assert msg.payload == "4XIfvSseAR7C08GvoY/+OD/oB9hFAW6lfMS9G3RYBD0DlxKrky7GVfP14et7tdI="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xa621
    
    assert dictify(msg.along) == 132661048
    
    assert dictify(msg.c0) == -970026069
    
    assert dictify(msg.c1) == -503975083
    
    assert dictify(msg.c2) == -759858197
    
    assert dictify(msg.cross) == 1845577176
    
    assert dictify(msg.dot_along) == 72905755
    
    assert dictify(msg.dot_cross) == 311886653
    
    assert dictify(msg.dot_radial) == -1111196507
    
    assert dictify(msg.iod) == 193
    
    assert dictify(msg.iod_ssr) == 211
    
    assert dictify(msg.radial) == -24141393
    
    assert dictify(msg.sid) == {'code': 30, 'sat': 1}
    
    assert dictify(msg.time) == {'tow': 3172954849, 'wn': 7723}
    
    assert dictify(msg.update_interval) == 194

    assert dictify(msg) == {'crc': 64669, 'length': 47, 'msg_type': 1500, 'payload': '4XIfvSseAR7C08GvoY/+OD/oB9hFAW6lfMS9G3RYBD0DlxKrky7GVfP14et7tdI=', 'preamble': 85, 'sender': 42529, 'time': {'tow': 3172954849, 'wn': 7723}, 'sid': {'sat': 1, 'code': 30}, 'update_interval': 194, 'iod_ssr': 211, 'iod': 193, 'radial': -24141393, 'along': 132661048, 'cross': 1845577176, 'dot_radial': -1111196507, 'dot_along': 72905755, 'dot_cross': 311886653, 'c0': -970026069, 'c1': -503975083, 'c2': -759858197}
