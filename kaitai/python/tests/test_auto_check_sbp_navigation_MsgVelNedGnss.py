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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ned_gnss_1():
    buf = base64.standard_b64decode("VS4CABAWqObpHfv///8AAAAA9v///ygAWQAVAmOr")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"tow":501868200,"n":-5,"e":0,"d":-10,"h_accuracy":40,"v_accuracy":89,"n_sats":21,"flags":2,"preamble":85,"msg_type":558,"sender":4096,"payload":"qObpHfv///8AAAAA9v///ygAWQAVAg==","crc":43875,"length":22}
    assert parsed_dict['crc'] == 0xab63
    assert parsed_dict['length'] == 22
    assert parsed_dict['msg_type'] == 0x22e
    assert parsed_dict['payload'] == "qObpHfv///8AAAAA9v///ygAWQAVAg=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x1000
    assert dictify(obj.payload.d) == snake_case_keys( -10 )
    assert dictify(obj.payload.e) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 40 )
    assert dictify(obj.payload.n) == snake_case_keys( -5 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 21 )
    assert dictify(obj.payload.tow) == snake_case_keys( 501868200 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 89 )

    assert parsed_dict == snake_case_keys(orig_dict)