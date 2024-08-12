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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgNapDeviceDnaResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_bootload_msg_nap_device_dna_resp_1():
    buf = base64.standard_b64decode("Vd0AqTgIArsBgq30Q3pGWw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5b46
    
    assert msg.length == 8
    
    assert msg.msg_type == 0xdd
    
    assert msg.payload == "ArsBgq30Q3o="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x38a9
    
    assert dictify(msg.dna) == [2, 187, 1, 130, 173, 244, 67, 122]

    assert dictify(msg) == {'crc': 23366, 'length': 8, 'msg_type': 221, 'payload': 'ArsBgq30Q3o=', 'preamble': 85, 'sender': 14505, 'dna': [2, 187, 1, 130, 173, 244, 67, 122]}