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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ecef_gnss_1():
    buf = base64.standard_b64decode("VS0CABAU4OXpHf3///8BAAAABAAAAFkAFQLNEA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x10cd
    assert payload.length == 20
    assert payload.msg_type == 0x22d
    assert payload.payload == "4OXpHf3///8BAAAABAAAAFkAFQI="
    assert payload.preamble == 0x55
    assert payload.sender == 0x1000
    assert dictify(obj.payload.accuracy) == snake_case_keys( 89 )
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 21 )
    assert dictify(obj.payload.tow) == snake_case_keys( 501868000 )
    assert dictify(obj.payload.x) == snake_case_keys( -3 )
    assert dictify(obj.payload.y) == snake_case_keys( 1 )
    assert dictify(obj.payload.z) == snake_case_keys( 4 )

    assert dictify(payload) == snake_case_keys( {"tow":501868000,"x":-3,"y":1,"z":4,"accuracy":89,"n_sats":21,"flags":2,"preamble":85,"msg_type":557,"sender":4096,"payload":"4OXpHf3///8BAAAABAAAAFkAFQI=","crc":4301,"length":20} )