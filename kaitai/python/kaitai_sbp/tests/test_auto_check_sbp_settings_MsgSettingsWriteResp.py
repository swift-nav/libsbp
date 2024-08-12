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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsWriteResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_settings_msg_settings_write_resp_1():
    buf = base64.standard_b64decode("Va8AWzdDmHNlY3Rpb24tbmFtZQBzZXR0aW5nLW5hbWUAc2V0dGluZy12YWx1ZQBlbnVtO3ZhbHVlMSx2YWx1ZTIsdmFsdWUzADYA")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x0036
    
    assert msg.length == 67
    
    assert msg.msg_type == 0xaf
    
    assert msg.payload == "mHNlY3Rpb24tbmFtZQBzZXR0aW5nLW5hbWUAc2V0dGluZy12YWx1ZQBlbnVtO3ZhbHVlMSx2YWx1ZTIsdmFsdWUzAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x375b
    
    assert dictify(msg.setting) == "section-name\x00setting-name\x00setting-value\x00enum;value1,value2,value3\x00"
    
    assert dictify(msg.status) == 152

    assert dictify(msg) == {'crc': 54, 'length': 67, 'msg_type': 175, 'payload': 'mHNlY3Rpb24tbmFtZQBzZXR0aW5nLW5hbWUAc2V0dGluZy12YWx1ZQBlbnVtO3ZhbHVlMSx2YWx1ZTIsdmFsdWUzAA==', 'preamble': 85, 'sender': 14171, 'status': 152, 'setting': 'section-name\x00setting-name\x00setting-value\x00enum;value1,value2,value3\x00'}