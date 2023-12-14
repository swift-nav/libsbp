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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgFrontEndGain.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_front_end_gain_1():
    buf = base64.standard_b64decode("Vb8Ar/UQKYWGCmkUJib26dhQu9VVAuuH")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x87eb
    
    assert msg.length == 16
    
    assert msg.msg_type == 0xbf
    
    assert msg.payload == "KYWGCmkUJib26dhQu9VVAg=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xf5af
    
    assert dictify(msg.if_gain) == [-10, -23, -40, 80, -69, -43, 85, 2]
    
    assert dictify(msg.rf_gain) == [41, -123, -122, 10, 105, 20, 38, 38]

    assert dictify(msg) == {'crc': 34795, 'length': 16, 'msg_type': 191, 'payload': 'KYWGCmkUJib26dhQu9VVAg==', 'preamble': 85, 'sender': 62895, 'rf_gain': [41, -123, -122, 10, 105, 20, 38, 38], 'if_gain': [-10, -23, -40, 80, -69, -43, 85, 2]}