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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHCov.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_llh_cov_1():
    buf = base64.standard_b64decode("VRECQgA2BwAAAAAAAAAAAAAAAAAAAAAAHEAAAAAAAAAAAAAA4EAAAKBAAAAAQQAAwEAAAIA/AAAAQAUFl2I=")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"cov_e_d": 1, "cov_e_e": 6, "n_sats": 5, "sender": 66, "msg_type": 529, "cov_n_n": 7, "lon": 7, "cov_n_e": 5, "tow": 7, "height": 0, "crc": 25239, "length": 54, "cov_n_d": 8, "lat": 0, "flags": 5, "cov_d_d": 2, "preamble": 85, "payload": "BwAAAAAAAAAAAAAAAAAAAAAAHEAAAAAAAAAAAAAA4EAAAKBAAAAAQQAAwEAAAIA/AAAAQAUF"}
    assert parsed_dict['crc'] == 0x6297
    assert parsed_dict['length'] == 54
    assert parsed_dict['msg_type'] == 0x211
    assert parsed_dict['payload'] == "BwAAAAAAAAAAAAAAAAAAAAAAHEAAAAAAAAAAAAAA4EAAAKBAAAAAQQAAwEAAAIA/AAAAQAUF"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.cov_d_d) == snake_case_keys( 2.0 )
    assert dictify(obj.payload.cov_e_d) == snake_case_keys( 1.0 )
    assert dictify(obj.payload.cov_e_e) == snake_case_keys( 6.0 )
    assert dictify(obj.payload.cov_n_d) == snake_case_keys( 8.0 )
    assert dictify(obj.payload.cov_n_e) == snake_case_keys( 5.0 )
    assert dictify(obj.payload.cov_n_n) == snake_case_keys( 7.0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 5 )
    assert dictify(obj.payload.height) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.lat) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.lon) == snake_case_keys( 7.0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 5 )
    assert dictify(obj.payload.tow) == snake_case_keys( 7 )

    assert parsed_dict == snake_case_keys(orig_dict)