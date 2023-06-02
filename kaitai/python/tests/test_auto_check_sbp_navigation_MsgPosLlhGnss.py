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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_llh_gnss_1():
    buf = base64.standard_b64decode("VSoCABAiGOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwFcAtQASBGk3")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"tow":501867800,"lat":37.83123196497633,"lon":-122.28650381011681,"height":-17.39382124780135,"h_accuracy":87,"v_accuracy":181,"n_sats":18,"flags":4,"preamble":85,"msg_type":554,"sender":4096,"payload":"GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwFcAtQASBA==","crc":14185,"length":34}
    assert parsed_dict['crc'] == 0x3769
    assert parsed_dict['length'] == 34
    assert parsed_dict['msg_type'] == 0x22a
    assert parsed_dict['payload'] == "GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwFcAtQASBA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x1000
    assert dictify(obj.payload.flags) == snake_case_keys( 4 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 87 )
    assert dictify(obj.payload.height) == snake_case_keys( -17.39382124780135 )
    assert dictify(obj.payload.lat) == snake_case_keys( 37.83123196497633 )
    assert dictify(obj.payload.lon) == snake_case_keys( -122.28650381011681 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 18 )
    assert dictify(obj.payload.tow) == snake_case_keys( 501867800 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 181 )

    assert parsed_dict == snake_case_keys(orig_dict)