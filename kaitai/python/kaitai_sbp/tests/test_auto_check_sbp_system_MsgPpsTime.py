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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgPpsTime.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_pps_time_1():
    buf = base64.standard_b64decode("VQj/3tEJjJKFxaAAAAD/fZU=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x957d
    
    assert msg.length == 9
    
    assert msg.msg_type == 0xff08
    
    assert msg.payload == "jJKFxaAAAAD/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd1de
    
    assert dictify(msg.flags) == 255
    
    assert dictify(msg.time) == 690508632716

    assert dictify(msg) == {'preamble': 85, 'msg_type': 65288, 'sender': 53726, 'length': 9, 'payload': 'jJKFxaAAAAD/', 'crc': 38269, 'time': 690508632716, 'flags': 255}
