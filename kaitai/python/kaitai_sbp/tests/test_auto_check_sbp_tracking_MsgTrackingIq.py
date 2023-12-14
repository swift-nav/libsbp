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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIq.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msg_tracking_iq_1():
    buf = base64.standard_b64decode("VS0AAlAPkXnLL9nvNy0mvVifE9AMYac=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa761
    
    assert msg.length == 15
    
    assert msg.msg_type == 0x2d
    
    assert msg.payload == "kXnLL9nvNy0mvVifE9AM"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x5002
    
    assert dictify(msg.channel) == 145
    
    assert dictify(msg.corrs) == [{'i': -9937, 'q': 14319}, {'i': 9773, 'q': 22717}, {'i': 5023, 'q': 3280}]
    
    assert dictify(msg.sid) == {'code': 203, 'sat': 121}

    assert dictify(msg) == {'crc': 42849, 'length': 15, 'msg_type': 45, 'payload': 'kXnLL9nvNy0mvVifE9AM', 'preamble': 85, 'sender': 20482, 'channel': 145, 'sid': {'sat': 121, 'code': 203}, 'corrs': [{'i': -9937, 'q': 14319}, {'i': 9773, 'q': 22717}, {'i': 5023, 'q': 3280}]}