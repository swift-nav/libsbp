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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgDgnssStatus.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_dgnss_status_1():
    buf = base64.standard_b64decode("VQL/QgALADIADFNreWxhcmvKAQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1ca
    
    assert msg.length == 11
    
    assert msg.msg_type == 0xff02
    
    assert msg.payload == "ADIADFNreWxhcms="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.latency) == 50
    
    assert dictify(msg.num_signals) == 12
    
    assert dictify(msg.source) == "Skylark"

    assert dictify(msg) == {'latency': 50, 'sender': 66, 'msg_type': 65282, 'source': 'Skylark', 'num_signals': 12, 'crc': 458, 'length': 11, 'flags': 0, 'preamble': 85, 'payload': 'ADIADFNreWxhcms='}