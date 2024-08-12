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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepB.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msg_tracking_iq_dep_b_1():
    buf = base64.standard_b64decode("VSwAJ2UbLby3SLmdD7v5ZRiHkrTge+uO0GZwGRWxYHRE9pk=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x99f6
    
    assert msg.length == 27
    
    assert msg.msg_type == 0x2c
    
    assert msg.payload == "Lby3SLmdD7v5ZRiHkrTge+uO0GZwGRWxYHRE"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x6527
    
    assert dictify(msg.channel) == 45
    
    assert dictify(msg.corrs) == [{'i': 261994824, 'q': 409336251}, {'i': -525036921, 'q': -795939973}, {'i': 353988710, 'q': 1148477617}]
    
    assert dictify(msg.sid) == {'code': 183, 'sat': 188}

    assert dictify(msg) == {'crc': 39414, 'length': 27, 'msg_type': 44, 'payload': 'Lby3SLmdD7v5ZRiHkrTge+uO0GZwGRWxYHRE', 'preamble': 85, 'sender': 25895, 'channel': 45, 'sid': {'sat': 188, 'code': 183}, 'corrs': [{'i': 261994824, 'q': 409336251}, {'i': -525036921, 'q': -795939973}, {'i': 353988710, 'q': 1148477617}]}