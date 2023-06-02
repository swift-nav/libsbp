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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosEcef.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_base_pos_ecef_1():
    buf = base64.standard_b64decode("VUgAAAAY5IOe9VfNRMFCPujRIHZQwdXnavs/FE1Bwn0=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x7dc2
    assert payload.length == 24
    assert payload.payload == "5IOe9VfNRMFCPujRIHZQwdXnavs/FE1B"
    assert payload.msg_type == 0x48
    assert payload.preamble == 0x55
    assert payload.sender == 0
    assert dictify(obj.payload.x) == snake_case_keys( -2726575.9189 )
    assert dictify(obj.payload.y) == snake_case_keys( -4315267.2798 )
    assert dictify(obj.payload.z) == snake_case_keys( 3811455.9642 )

    assert dictify(payload) == snake_case_keys( {"x":-2726575.9189,"y":-4315267.2798,"z":3811455.9642,"preamble":85,"msg_type":72,"sender":0,"payload":"5IOe9VfNRMFCPujRIHZQwdXnavs/FE1B","crc":32194,"length":24} )