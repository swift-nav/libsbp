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
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_base_pos_ecef_1():
    buf = base64.standard_b64decode("VUgAAAAY5IOe9VfNRMFCPujRIHZQwdXnavs/FE1Bwn0=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"x":-2726575.9189,"y":-4315267.2798,"z":3811455.9642,"preamble":85,"msg_type":72,"sender":0,"payload":"5IOe9VfNRMFCPujRIHZQwdXnavs/FE1B","crc":32194,"length":24}
    assert parsed_dict['crc'] == 0x7dc2
    assert parsed_dict['length'] == 24
    assert parsed_dict['payload'] == "5IOe9VfNRMFCPujRIHZQwdXnavs/FE1B"
    assert parsed_dict['msg_type'] == 0x48
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0
    assert dictify(obj.payload.x) == snake_case_keys( -2726575.9189 )
    assert dictify(obj.payload.y) == snake_case_keys( -4315267.2798 )
    assert dictify(obj.payload.z) == snake_case_keys( 3811455.9642 )

    assert parsed_dict == snake_case_keys(orig_dict)