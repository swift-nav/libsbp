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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrection.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_stec_correction_1():
    buf = base64.standard_b64decode("Vf0FQgAmtAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgB3Mg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"header": {"time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 1, "update_interval": 10, "sol_id": 0}, "ssr_iod_atmo": 15, "tile_set_id": 1, "tile_id": 10, "n_sats": 2, "stec_sat_list": [{"sv_id": {"satId": 1, "constellation": 1}, "stec_quality_indicator": 1, "stec_coeff": [63, 62, 61, 60]}, {"sv_id": {"satId": 31, "constellation": 15}, "stec_quality_indicator": 5, "stec_coeff": [63, 64, 65, 66]}], "preamble": 85, "msg_type": 1533, "sender": 66, "length": 38, "payload": "tAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgA=", "crc": 12919}
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['msg_type'] == 0x05FD
    assert parsed_dict['sender'] == 0x0042
    assert parsed_dict['length'] == 38
    assert parsed_dict['payload'] == "tAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgA="
    assert parsed_dict['crc'] == 0x3277
    assert dictify(obj.payload.header) == snake_case_keys( {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 1, 'update_interval': 10, 'sol_id': 0} )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 2 )
    assert dictify(obj.payload.ssr_iod_atmo) == snake_case_keys( 15 )
    assert dictify(obj.payload.stec_sat_list) == snake_case_keys( [{'sv_id': {'satId': 1, 'constellation': 1}, 'stec_quality_indicator': 1, 'stec_coeff': [63, 62, 61, 60]}, {'sv_id': {'satId': 31, 'constellation': 15}, 'stec_quality_indicator': 5, 'stec_coeff': [63, 64, 65, 66]}] )
    assert dictify(obj.payload.tile_id) == snake_case_keys( 10 )
    assert dictify(obj.payload.tile_set_id) == snake_case_keys( 1 )

    assert parsed_dict == snake_case_keys(orig_dict)