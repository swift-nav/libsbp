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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_reference_frame_param_1():
    buf = base64.standard_b64decode("VUQCQgB8AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAAah")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"ssr_iod": 1, "sn": "foo\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "tn": "bar\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "sin": 4, "utn": 5, "re_t0": 6, "delta_X0": 7, "delta_Y0": 8, "delta_Z0": 9, "theta_01": 10, "theta_02": 11, "theta_03": 12, "scale": 13, "dot_delta_X0": 14, "dot_delta_Y0": 15, "dot_delta_Z0": 16, "dot_theta_01": 17, "dot_theta_02": 18, "dot_theta_03": 19, "dot_scale": 20, "preamble": 85, "msg_type": 580, "sender": 66, "length": 124, "payload": "AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAA==", "crc": 41222}
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['msg_type'] == 0x0244
    assert parsed_dict['sender'] == 0x0042
    assert parsed_dict['length'] == 124
    assert parsed_dict['payload'] == "AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAA=="
    assert parsed_dict['crc'] == 0xA106
    assert dictify(obj.payload.delta_x0) == snake_case_keys( 7 )
    assert dictify(obj.payload.delta_y0) == snake_case_keys( 8 )
    assert dictify(obj.payload.delta_z0) == snake_case_keys( 9 )
    assert dictify(obj.payload.dot_delta_x0) == snake_case_keys( 14 )
    assert dictify(obj.payload.dot_delta_y0) == snake_case_keys( 15 )
    assert dictify(obj.payload.dot_delta_z0) == snake_case_keys( 16 )
    assert dictify(obj.payload.dot_scale) == snake_case_keys( 20 )
    assert dictify(obj.payload.dot_theta_01) == snake_case_keys( 17 )
    assert dictify(obj.payload.dot_theta_02) == snake_case_keys( 18 )
    assert dictify(obj.payload.dot_theta_03) == snake_case_keys( 19 )
    assert dictify(obj.payload.re_t0) == snake_case_keys( 6 )
    assert dictify(obj.payload.scale) == snake_case_keys( 13 )
    assert dictify(obj.payload.sin) == snake_case_keys( 4 )
    assert dictify(obj.payload.sn) == snake_case_keys( 'foo\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.ssr_iod) == snake_case_keys( 1 )
    assert dictify(obj.payload.theta_01) == snake_case_keys( 10 )
    assert dictify(obj.payload.theta_02) == snake_case_keys( 11 )
    assert dictify(obj.payload.theta_03) == snake_case_keys( 12 )
    assert dictify(obj.payload.tn) == snake_case_keys( 'bar\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.utn) == snake_case_keys( 5 )

    assert parsed_dict == snake_case_keys(orig_dict)