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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ext_events/test_MsgExtEvent.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ext_events_msg_ext_event_1():
    buf = base64.standard_b64decode("VQEB9QYMMAfH2DEPykEPAAMAPsw=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xcc3e
    assert payload.length == 12
    assert payload.msg_type == 0x101
    assert payload.payload == "MAfH2DEPykEPAAMA"
    assert payload.preamble == 0x55
    assert payload.sender == 0x6f5
    assert dictify(obj.payload.flags) == snake_case_keys( 3 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 999882 )
    assert dictify(obj.payload.pin) == snake_case_keys( 0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 254924999 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1840 )

    assert dictify(payload) == snake_case_keys( {"sender": 1781, "msg_type": 257, "wn": 1840, "tow": 254924999, "crc": 52286, "length": 12, "flags": 3, "pin": 0, "ns_residual": 999882, "preamble": 85, "payload": "MAfH2DEPykEPAAMA"} )