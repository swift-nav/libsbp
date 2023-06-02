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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagHighLevel.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_integrity_msg_ssr_flag_high_level_1():
    buf = base64.standard_b64decode("VbkLQgAftAAAAAMAaAEAAAYAChQAHgAoAQIDAAAAAAAABAUGB2ZD")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"obs_time": {"tow": 180, "wn": 3}, "corr_time": {"tow": 360, "wn": 6}, "ssr_sol_id": 10, "tile_set_id": 20, "tile_id": 30, "chain_id": 40, "use_gps_sat": 1, "use_gal_sat": 2, "use_bds_sat": 3, "reserved": [0,0,0,0,0,0], "use_tropo_grid_points": 4, "use_iono_grid_points": 5, "use_iono_tile_sat_los": 6, "use_iono_grid_point_sat_los": 7, "preamble": 85, "msg_type": 3001, "sender": 66, "length": 31, "payload": "tAAAAAMAaAEAAAYAChQAHgAoAQIDAAAAAAAABAUGBw==", "crc": 17254}
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['msg_type'] == 0x0BB9
    assert parsed_dict['sender'] == 0x0042
    assert parsed_dict['length'] == 31
    assert parsed_dict['payload'] == "tAAAAAMAaAEAAAYAChQAHgAoAQIDAAAAAAAABAUGBw=="
    assert parsed_dict['crc'] == 0x4366
    assert dictify(obj.payload.chain_id) == snake_case_keys( 40 )
    assert dictify(obj.payload.corr_time) == snake_case_keys( {'tow': 360, 'wn': 6} )
    assert dictify(obj.payload.obs_time) == snake_case_keys( {'tow': 180, 'wn': 3} )
    assert dictify(obj.payload.reserved) == snake_case_keys( [0, 0, 0, 0, 0, 0] )
    assert dictify(obj.payload.ssr_sol_id) == snake_case_keys( 10 )
    assert dictify(obj.payload.tile_id) == snake_case_keys( 30 )
    assert dictify(obj.payload.tile_set_id) == snake_case_keys( 20 )
    assert dictify(obj.payload.use_bds_sat) == snake_case_keys( 3 )
    assert dictify(obj.payload.use_gal_sat) == snake_case_keys( 2 )
    assert dictify(obj.payload.use_gps_sat) == snake_case_keys( 1 )
    assert dictify(obj.payload.use_iono_grid_point_sat_los) == snake_case_keys( 7 )
    assert dictify(obj.payload.use_iono_grid_points) == snake_case_keys( 5 )
    assert dictify(obj.payload.use_iono_tile_sat_los) == snake_case_keys( 6 )
    assert dictify(obj.payload.use_tropo_grid_points) == snake_case_keys( 4 )

    assert parsed_dict == snake_case_keys(orig_dict)