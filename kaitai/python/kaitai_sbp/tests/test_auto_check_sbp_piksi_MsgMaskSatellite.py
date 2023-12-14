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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgMaskSatellite.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_mask_satellite_1():
    buf = base64.standard_b64decode("VSsArZcDt1c5E5M=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9313
    
    assert msg.length == 3
    
    assert msg.msg_type == 0x2b
    
    assert msg.payload == "t1c5"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x97ad
    
    assert dictify(msg.mask) == 183
    
    assert dictify(msg.sid) == {'code': 57, 'sat': 87}

    assert dictify(msg) == {'crc': 37651, 'length': 3, 'msg_type': 43, 'payload': 't1c5', 'preamble': 85, 'sender': 38829, 'mask': 183, 'sid': {'sat': 87, 'code': 57}}