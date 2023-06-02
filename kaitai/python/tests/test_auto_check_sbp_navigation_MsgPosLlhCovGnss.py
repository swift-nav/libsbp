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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhCovGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_llh_cov_gnss_1():
    buf = base64.standard_b64decode("VTECABA2GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIECsQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xc40a
    assert payload.length == 54
    assert payload.msg_type == 0x231
    assert payload.payload == "GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIE"
    assert payload.preamble == 0x55
    assert payload.sender == 0x1000
    assert dictify(obj.payload.cov_d_d) == snake_case_keys( 0.03288137540221214 )
    assert dictify(obj.payload.cov_e_d) == snake_case_keys( -0.0008439270895905793 )
    assert dictify(obj.payload.cov_e_e) == snake_case_keys( 0.004523798823356628 )
    assert dictify(obj.payload.cov_n_d) == snake_case_keys( 0.0018563168123364449 )
    assert dictify(obj.payload.cov_n_e) == snake_case_keys( -0.00036755966721102595 )
    assert dictify(obj.payload.cov_n_n) == snake_case_keys( 0.007488971576094627 )
    assert dictify(obj.payload.flags) == snake_case_keys( 4 )
    assert dictify(obj.payload.height) == snake_case_keys( -17.39382124780135 )
    assert dictify(obj.payload.lat) == snake_case_keys( 37.83123196497633 )
    assert dictify(obj.payload.lon) == snake_case_keys( -122.28650381011681 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 18 )
    assert dictify(obj.payload.tow) == snake_case_keys( 501867800 )

    assert dictify(payload) == snake_case_keys( {"tow":501867800,"lat":37.83123196497633,"lon":-122.28650381011681,"height":-17.39382124780135,"cov_n_n":0.007488971576094627,"cov_n_e":-0.00036755966721102595,"cov_n_d":0.0018563168123364449,"cov_e_e":0.004523798823356628,"cov_e_d":-0.0008439270895905793,"cov_d_d":0.03288137540221214,"n_sats":18,"flags":4,"preamble":85,"msg_type":561,"sender":4096,"payload":"GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIE","crc":50186,"length":54} )