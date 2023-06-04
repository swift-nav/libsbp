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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFGNSS.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_ecefgnss_1():
    buf = base64.standard_b64decode("VSkCABAgGOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQbYAEgSHAg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x287
    
    assert msg.length == 32
    
    assert msg.msg_type == 0x229
    
    assert msg.payload == "GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQbYAEgQ="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.accuracy) == 182
    
    assert dictify(msg.flags) == 4
    
    assert dictify(msg.n_sats) == 18
    
    assert dictify(msg.tow) == 501867800
    
    assert dictify(msg.x) == -2694229.7079770807
    
    assert dictify(msg.y) == -4264073.427345817
    
    assert dictify(msg.z) == 3890655.013186158

    assert dictify(msg) == {'tow': 501867800, 'x': -2694229.7079770807, 'y': -4264073.427345817, 'z': 3890655.013186158, 'accuracy': 182, 'n_sats': 18, 'flags': 4, 'preamble': 85, 'msg_type': 553, 'sender': 4096, 'payload': 'GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQbYAEgQ=', 'crc': 647, 'length': 32}