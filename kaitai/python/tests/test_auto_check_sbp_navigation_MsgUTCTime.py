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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCTime.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_utc_time_1():
    buf = base64.standard_b64decode("VQMBFQMQARjl6R3lBwQJExgJAAivL8f9")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xfdc7
    assert payload.length == 16
    assert payload.msg_type == 0x103
    assert payload.payload == "ARjl6R3lBwQJExgJAAivLw=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x315
    assert dictify(obj.payload.day) == snake_case_keys( 9 )
    assert dictify(obj.payload.flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.hours) == snake_case_keys( 19 )
    assert dictify(obj.payload.minutes) == snake_case_keys( 24 )
    assert dictify(obj.payload.month) == snake_case_keys( 4 )
    assert dictify(obj.payload.ns) == snake_case_keys( 800000000 )
    assert dictify(obj.payload.seconds) == snake_case_keys( 9 )
    assert dictify(obj.payload.tow) == snake_case_keys( 501867800 )
    assert dictify(obj.payload.year) == snake_case_keys( 2021 )

    assert dictify(payload) == snake_case_keys( {"flags":1,"tow":501867800,"year":2021,"month":4,"day":9,"hours":19,"minutes":24,"seconds":9,"ns":800000000,"preamble":85,"msg_type":259,"sender":789,"payload":"ARjl6R3lBwQJExgJAAivLw==","crc":64967,"length":16} )