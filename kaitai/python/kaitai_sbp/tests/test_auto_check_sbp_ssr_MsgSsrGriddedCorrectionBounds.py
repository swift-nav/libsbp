# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionBounds.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds_1():
    buf = base64.standard_b64decode("Vf4FQgAttAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob7LY=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x05FE
    
    assert msg.sender == 0x0042
    
    assert msg.length == 45
    
    assert msg.payload == "tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob"
    
    assert msg.crc == 0xB6EC
    
    assert dictify(msg.grid_point_id) == 1000
    
    assert dictify(msg.header) == {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 0, 'update_interval': 10, 'sol_id': 0}
    
    assert dictify(msg.n_sats) == 2
    
    assert dictify(msg.ssr_iod_atmo) == 15
    
    assert dictify(msg.stec_sat_list) == [{'stec_residual': {'sv_id': {'sat_id': 5, 'constellation': 10}, 'residual': 16, 'stddev': 17}, 'stec_bound_mu': 18, 'stec_bound_sig': 19, 'stec_bound_mu_dot': 20, 'stec_bound_sig_dot': 21}, {'stec_residual': {'sv_id': {'sat_id': 6, 'constellation': 10}, 'residual': 22, 'stddev': 23}, 'stec_bound_mu': 24, 'stec_bound_sig': 25, 'stec_bound_mu_dot': 26, 'stec_bound_sig_dot': 27}]
    
    assert dictify(msg.tile_id) == 10
    
    assert dictify(msg.tile_set_id) == 1
    
    assert dictify(msg.tropo_delay_correction) == {'hydro': 500, 'wet': 100, 'stddev': 200}
    
    assert dictify(msg.tropo_qi) == 39
    
    assert dictify(msg.tropo_v_hydro_bound_mu) == 150
    
    assert dictify(msg.tropo_v_hydro_bound_sig) == 100
    
    assert dictify(msg.tropo_v_wet_bound_mu) == 150
    
    assert dictify(msg.tropo_v_wet_bound_sig) == 100

    assert dictify(msg) == {'header': {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 0, 'update_interval': 10, 'sol_id': 0}, 'ssr_iod_atmo': 15, 'tile_set_id': 1, 'tile_id': 10, 'tropo_qi': 39, 'grid_point_id': 1000, 'tropo_delay_correction': {'hydro': 500, 'wet': 100, 'stddev': 200}, 'tropo_v_hydro_bound_mu': 150, 'tropo_v_hydro_bound_sig': 100, 'tropo_v_wet_bound_mu': 150, 'tropo_v_wet_bound_sig': 100, 'n_sats': 2, 'stec_sat_list': [{'stec_residual': {'sv_id': {'sat_id': 5, 'constellation': 10}, 'residual': 16, 'stddev': 17}, 'stec_bound_mu': 18, 'stec_bound_sig': 19, 'stec_bound_mu_dot': 20, 'stec_bound_sig_dot': 21}, {'stec_residual': {'sv_id': {'sat_id': 6, 'constellation': 10}, 'residual': 22, 'stddev': 23}, 'stec_bound_mu': 24, 'stec_bound_sig': 25, 'stec_bound_mu_dot': 26, 'stec_bound_sig_dot': 27}], 'preamble': 85, 'msg_type': 1534, 'sender': 66, 'length': 45, 'payload': 'tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob', 'crc': 46828}

def test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds_2():
    buf = base64.standard_b64decode("Vf4FQgAbtAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQAmyQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x05FE
    
    assert msg.sender == 0x0042
    
    assert msg.length == 27
    
    assert msg.payload == "tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQA"
    
    assert msg.crc == 0x249B
    
    assert dictify(msg.grid_point_id) == 1000
    
    assert dictify(msg.header) == {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 0, 'update_interval': 10, 'sol_id': 0}
    
    assert dictify(msg.n_sats) == 0
    
    assert dictify(msg.ssr_iod_atmo) == 15
    
    assert dictify(msg.stec_sat_list) == []
    
    assert dictify(msg.tile_id) == 10
    
    assert dictify(msg.tile_set_id) == 1
    
    assert dictify(msg.tropo_delay_correction) == {'hydro': 500, 'wet': 100, 'stddev': 200}
    
    assert dictify(msg.tropo_qi) == 39
    
    assert dictify(msg.tropo_v_hydro_bound_mu) == 150
    
    assert dictify(msg.tropo_v_hydro_bound_sig) == 100
    
    assert dictify(msg.tropo_v_wet_bound_mu) == 150
    
    assert dictify(msg.tropo_v_wet_bound_sig) == 100

    assert dictify(msg) == {'header': {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 0, 'update_interval': 10, 'sol_id': 0}, 'ssr_iod_atmo': 15, 'tile_set_id': 1, 'tile_id': 10, 'tropo_qi': 39, 'grid_point_id': 1000, 'tropo_delay_correction': {'hydro': 500, 'wet': 100, 'stddev': 200}, 'tropo_v_hydro_bound_mu': 150, 'tropo_v_hydro_bound_sig': 100, 'tropo_v_wet_bound_mu': 150, 'tropo_v_wet_bound_sig': 100, 'n_sats': 0, 'stec_sat_list': [], 'preamble': 85, 'msg_type': 1534, 'sender': 66, 'length': 27, 'payload': 'tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQA', 'crc': 9371}