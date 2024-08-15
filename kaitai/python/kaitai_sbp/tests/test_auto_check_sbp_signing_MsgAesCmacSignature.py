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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgAesCmacSignature.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_signing_msg_aes_cmac_signature_1():
    buf = base64.standard_b64decode("VRAMQgAaAQIBAgMEAAECAwQFBgcICQoLDA0ODwALFiHAFQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x15C0
    
    assert msg.length == 26
    
    assert msg.msg_type == 0xC10
    
    assert msg.payload == "AQIBAgMEAAECAwQFBgcICQoLDA0ODwALFiE="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.certificate_id) == [1, 2, 3, 4]
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.on_demand_counter) == 2
    
    assert dictify(msg.signature) == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
    
    assert dictify(msg.signed_messages) == [11, 22, 33]
    
    assert dictify(msg.stream_counter) == 1

    assert dictify(msg) == {'crc': 5568, 'length': 26, 'msg_type': 3088, 'payload': 'AQIBAgMEAAECAwQFBgcICQoLDA0ODwALFiE=', 'preamble': 85, 'sender': 66, 'stream_counter': 1, 'on_demand_counter': 2, 'certificate_id': [1, 2, 3, 4], 'signature': [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15], 'flags': 0, 'signed_messages': [11, 22, 33]}