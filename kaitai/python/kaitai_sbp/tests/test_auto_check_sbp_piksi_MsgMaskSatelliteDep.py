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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgMaskSatelliteDep.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_mask_satellite_dep_1():
    buf = base64.standard_b64decode("VRsAu4YFIQKZXwQdvA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xbc1d
    
    assert msg.length == 5
    
    assert msg.msg_type == 0x1b
    
    assert msg.payload == "IQKZXwQ="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x86bb
    
    assert dictify(msg.mask) == 33
    
    assert dictify(msg.sid) == {'code': 95, 'reserved': 4, 'sat': 39170}

    assert dictify(msg) == {'crc': 48157, 'length': 5, 'msg_type': 27, 'payload': 'IQKZXwQ=', 'preamble': 85, 'sender': 34491, 'mask': 33, 'sid': {'sat': 39170, 'code': 95, 'reserved': 4}}