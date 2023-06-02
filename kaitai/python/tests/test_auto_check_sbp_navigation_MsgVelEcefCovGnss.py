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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefCovGnss.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_vel_ecef_cov_gnss_1():
    buf = base64.standard_b64decode("VTUCABAq4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUCFuY=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xe616
    assert payload.length == 42
    assert payload.msg_type == 0x235
    assert payload.payload == "4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUC"
    assert payload.preamble == 0x55
    assert payload.sender == 0x1000
    assert dictify(obj.payload.cov_x_x) == snake_case_keys( 0.0024547684006392956 )
    assert dictify(obj.payload.cov_x_y) == snake_case_keys( 0.0021795108914375305 )
    assert dictify(obj.payload.cov_x_z) == snake_case_keys( -0.0016828652005642653 )
    assert dictify(obj.payload.cov_y_y) == snake_case_keys( 0.004218944814056158 )
    assert dictify(obj.payload.cov_y_z) == snake_case_keys( -0.0024961293675005436 )
    assert dictify(obj.payload.cov_z_z) == snake_case_keys( 0.0037804271560162306 )
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 21 )
    assert dictify(obj.payload.tow) == snake_case_keys( 501868000 )
    assert dictify(obj.payload.x) == snake_case_keys( -3 )
    assert dictify(obj.payload.y) == snake_case_keys( 1 )
    assert dictify(obj.payload.z) == snake_case_keys( 4 )

    assert dictify(payload) == snake_case_keys( {"tow":501868000,"x":-3,"y":1,"z":4,"cov_x_x":0.0024547684006392956,"cov_x_y":0.0021795108914375305,"cov_x_z":-0.0016828652005642653,"cov_y_y":0.004218944814056158,"cov_y_z":-0.0024961293675005436,"cov_z_z":0.0037804271560162306,"n_sats":21,"flags":2,"preamble":85,"msg_type":565,"sender":4096,"payload":"4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUC","crc":58902,"length":42} )