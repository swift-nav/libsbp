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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResult.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_acquisition_msg_acq_result_1():
    buf = base64.standard_b64decode("VS8AwwQOAABoQWZmkELNxABGCADPvQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xbdcf
    
    assert msg.length == 14
    
    assert msg.msg_type == 0x2f
    
    assert msg.payload == "AABoQWZmkELNxABGCAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.cf) == 8241.2001953125
    
    assert dictify(msg.cn0) == 14.5
    
    assert dictify(msg.cp) == 72.19999694824219
    
    assert dictify(msg.sid) == {'code': 0, 'sat': 8}

    assert dictify(msg) == {'preamble': 85, 'msg_type': 47, 'sender': 1219, 'length': 14, 'payload': 'AABoQWZmkELNxABGCAA=', 'crc': 48591, 'cn0': 14.5, 'cp': 72.19999694824219, 'cf': 8241.2001953125, 'sid': {'sat': 8, 'code': 0}}