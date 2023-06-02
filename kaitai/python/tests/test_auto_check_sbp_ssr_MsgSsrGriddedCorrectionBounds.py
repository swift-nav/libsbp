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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionBounds.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds_1():
    buf = base64.standard_b64decode("Vf4FQgAttAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob7LY=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"header": {"time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 0, "update_interval": 10, "sol_id": 0}, "ssr_iod_atmo": 15, "tile_set_id": 1, "tile_id": 10, "tropo_qi": 39, "grid_point_id": 1000, "tropo_delay_correction": {"hydro": 500, "wet": 100, "stddev": 200}, "tropo_v_hydro_bound_mu": 150, "tropo_v_hydro_bound_sig": 100, "tropo_v_wet_bound_mu": 150, "tropo_v_wet_bound_sig": 100, "n_sats": 2, "stec_sat_list": [{"stec_residual": {"sv_id": {"satId": 5, "constellation": 10}, "residual": 16, "stddev": 17}, "stec_bound_mu": 18, "stec_bound_sig": 19, "stec_bound_mu_dot": 20, "stec_bound_sig_dot": 21}, {"stec_residual": {"sv_id": {"satId": 6, "constellation": 10}, "residual": 22, "stddev": 23}, "stec_bound_mu": 24, "stec_bound_sig": 25, "stec_bound_mu_dot": 26, "stec_bound_sig_dot": 27}], "preamble": 85, "msg_type": 1534, "sender": 66, "length": 45, "payload": "tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob", "crc": 46828}
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['msg_type'] == 0x05FE
    assert parsed_dict['sender'] == 0x0042
    assert parsed_dict['length'] == 45
    assert parsed_dict['payload'] == "tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob"
    assert parsed_dict['crc'] == 0xB6EC
    assert dictify(obj.payload.grid_point_id) == snake_case_keys( 1000 )
    assert dictify(obj.payload.header) == snake_case_keys( {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 0, 'update_interval': 10, 'sol_id': 0} )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 2 )
    assert dictify(obj.payload.ssr_iod_atmo) == snake_case_keys( 15 )
    assert dictify(obj.payload.stec_sat_list) == snake_case_keys( [{'stec_residual': {'sv_id': {'satId': 5, 'constellation': 10}, 'residual': 16, 'stddev': 17}, 'stec_bound_mu': 18, 'stec_bound_sig': 19, 'stec_bound_mu_dot': 20, 'stec_bound_sig_dot': 21}, {'stec_residual': {'sv_id': {'satId': 6, 'constellation': 10}, 'residual': 22, 'stddev': 23}, 'stec_bound_mu': 24, 'stec_bound_sig': 25, 'stec_bound_mu_dot': 26, 'stec_bound_sig_dot': 27}] )
    assert dictify(obj.payload.tile_id) == snake_case_keys( 10 )
    assert dictify(obj.payload.tile_set_id) == snake_case_keys( 1 )
    assert dictify(obj.payload.tropo_delay_correction) == snake_case_keys( {'hydro': 500, 'wet': 100, 'stddev': 200} )
    assert dictify(obj.payload.tropo_qi) == snake_case_keys( 39 )
    assert dictify(obj.payload.tropo_v_hydro_bound_mu) == snake_case_keys( 150 )
    assert dictify(obj.payload.tropo_v_hydro_bound_sig) == snake_case_keys( 100 )
    assert dictify(obj.payload.tropo_v_wet_bound_mu) == snake_case_keys( 150 )
    assert dictify(obj.payload.tropo_v_wet_bound_sig) == snake_case_keys( 100 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds_2():
    buf = base64.standard_b64decode("Vf4FQgAbtAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQAmyQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"header": {"time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 0, "update_interval": 10, "sol_id": 0}, "ssr_iod_atmo": 15, "tile_set_id": 1, "tile_id": 10, "tropo_qi": 39, "grid_point_id": 1000, "tropo_delay_correction": {"hydro": 500, "wet": 100, "stddev": 200}, "tropo_v_hydro_bound_mu": 150, "tropo_v_hydro_bound_sig": 100, "tropo_v_wet_bound_mu": 150, "tropo_v_wet_bound_sig": 100, "n_sats": 0, "stec_sat_list": [], "preamble": 85, "msg_type": 1534, "sender": 66, "length": 27, "payload": "tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQA", "crc": 9371}
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['msg_type'] == 0x05FE
    assert parsed_dict['sender'] == 0x0042
    assert parsed_dict['length'] == 27
    assert parsed_dict['payload'] == "tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQA"
    assert parsed_dict['crc'] == 0x249B
    assert dictify(obj.payload.grid_point_id) == snake_case_keys( 1000 )
    assert dictify(obj.payload.header) == snake_case_keys( {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 0, 'update_interval': 10, 'sol_id': 0} )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 0 )
    assert dictify(obj.payload.ssr_iod_atmo) == snake_case_keys( 15 )
    assert dictify(obj.payload.stec_sat_list) == snake_case_keys( [] )
    assert dictify(obj.payload.tile_id) == snake_case_keys( 10 )
    assert dictify(obj.payload.tile_set_id) == snake_case_keys( 1 )
    assert dictify(obj.payload.tropo_delay_correction) == snake_case_keys( {'hydro': 500, 'wet': 100, 'stddev': 200} )
    assert dictify(obj.payload.tropo_qi) == snake_case_keys( 39 )
    assert dictify(obj.payload.tropo_v_hydro_bound_mu) == snake_case_keys( 150 )
    assert dictify(obj.payload.tropo_v_hydro_bound_sig) == snake_case_keys( 100 )
    assert dictify(obj.payload.tropo_v_wet_bound_mu) == snake_case_keys( 150 )
    assert dictify(obj.payload.tropo_v_wet_bound_sig) == snake_case_keys( 100 )

    assert parsed_dict == snake_case_keys(orig_dict)