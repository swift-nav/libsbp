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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGLO.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_glo_1():
    buf = base64.standard_b64decode("VYsACglcBANGxQYAaggAAKBAYAkAAAEAAACAK4Bhr7gAAECxAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBAAAAYgb6msAAAADZOt2jwAAAALiKLotAAAB6NQAAejUAgDs2DmRZlQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"common":{"sid":{"sat":4,"code":3},"toe":{"tow":443718,"wn":2154},"ura":5.0,"fit_interval":2400,"valid":1,"health_bits":0},"gamma":9.094947017729282e-13,"tau":-8.36281105875969e-05,"d_tau":-2.7939677238464355e-09,"pos":[-12177330.078125,599893.06640625,-22373708.49609375],"vel":[-1726.506233215332,-2542.6149368286133,869.8177337646484],"acc":[9.313225746154785e-07,9.313225746154785e-07,2.7939677238464355e-06],"fcn":14,"iod":100,"preamble":85,"msg_type":139,"sender":2314,"payload":"BANGxQYAaggAAKBAYAkAAAEAAACAK4Bhr7gAAECxAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBAAAAYgb6msAAAADZOt2jwAAAALiKLotAAAB6NQAAejUAgDs2DmQ=","crc":38233,"length":92}
    assert parsed_dict['crc'] == 0x9559
    assert parsed_dict['length'] == 92
    assert parsed_dict['msg_type'] == 0x8b
    assert parsed_dict['payload'] == "BANGxQYAaggAAKBAYAkAAAEAAACAK4Bhr7gAAECxAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBAAAAYgb6msAAAADZOt2jwAAAALiKLotAAAB6NQAAejUAgDs2DmQ="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x90a
    assert dictify(obj.payload.acc) == snake_case_keys( [9.313225746154785e-07, 9.313225746154785e-07, 2.7939677238464355e-06] )
    assert dictify(obj.payload.common) == snake_case_keys( {'sid': {'sat': 4, 'code': 3}, 'toe': {'tow': 443718, 'wn': 2154}, 'ura': 5.0, 'fit_interval': 2400, 'valid': 1, 'health_bits': 0} )
    assert dictify(obj.payload.d_tau) == snake_case_keys( -2.7939677238464355e-09 )
    assert dictify(obj.payload.fcn) == snake_case_keys( 14 )
    assert dictify(obj.payload.gamma) == snake_case_keys( 9.094947017729282e-13 )
    assert dictify(obj.payload.iod) == snake_case_keys( 100 )
    assert dictify(obj.payload.pos) == snake_case_keys( [-12177330.078125, 599893.06640625, -22373708.49609375] )
    assert dictify(obj.payload.tau) == snake_case_keys( -8.36281105875969e-05 )
    assert dictify(obj.payload.vel) == snake_case_keys( [-1726.506233215332, -2542.6149368286133, 869.8177337646484] )

    assert parsed_dict == snake_case_keys(orig_dict)