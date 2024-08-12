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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgCsacTelemetryLabels.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_csac_telemetry_labels_1():
    buf = base64.standard_b64decode("VQX/W8gMunNvbWUgbGFiZWxzVuw=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xec56
    
    assert msg.length == 12
    
    assert msg.msg_type == 0xff05
    
    assert msg.payload == "unNvbWUgbGFiZWxz"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xc85b
    
    assert dictify(msg.id) == 186
    
    assert dictify(msg.telemetry_labels) == "some labels"

    assert dictify(msg) == {'preamble': 85, 'msg_type': 65285, 'sender': 51291, 'length': 12, 'payload': 'unNvbWUgbGFiZWxz', 'crc': 60502, 'id': 186, 'telemetry_labels': 'some labels'}