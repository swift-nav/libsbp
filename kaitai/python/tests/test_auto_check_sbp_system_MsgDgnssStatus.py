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

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_dgnss_status_1():
    buf = base64.standard_b64decode("VQL/QgALADIADFNreWxhcmvKAQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x1ca
    assert payload.length == 11
    assert payload.msg_type == 0xff02
    assert payload.payload == "ADIADFNreWxhcms="
    assert payload.preamble == 0x55
    assert payload.sender == 0x42
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.latency) == snake_case_keys( 50 )
    assert dictify(obj.payload.num_signals) == snake_case_keys( 12 )
    assert dictify(obj.payload.source) == snake_case_keys( 'Skylark' )

    assert dictify(payload) == snake_case_keys( {"latency": 50, "sender": 66, "msg_type": 65282, "source": "Skylark", "num_signals": 12, "crc": 458, "length": 11, "flags": 0, "preamble": 85, "payload": "ADIADFNreWxhcms="} )