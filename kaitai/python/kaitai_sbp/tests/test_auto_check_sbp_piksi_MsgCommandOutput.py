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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCommandOutput.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_command_output_1():
    buf = base64.standard_b64decode("VbwAMlQUfqR0lVNvbWUgb3V0cHV0IHRleHQLbQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6d0b
    
    assert msg.length == 20
    
    assert msg.msg_type == 0xbc
    
    assert msg.payload == "fqR0lVNvbWUgb3V0cHV0IHRleHQ="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x5432
    
    assert dictify(msg.line) == "Some output text"
    
    assert dictify(msg.sequence) == 2507449470

    assert dictify(msg) == {'crc': 27915, 'length': 20, 'msg_type': 188, 'payload': 'fqR0lVNvbWUgb3V0cHV0IHRleHQ=', 'preamble': 85, 'sender': 21554, 'sequence': 2507449470, 'line': 'Some output text'}