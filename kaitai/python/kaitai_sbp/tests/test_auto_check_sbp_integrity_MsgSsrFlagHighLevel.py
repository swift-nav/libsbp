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

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_integrity_msg_ssr_flag_high_level_1():
    buf = base64.standard_b64decode("VbkLQgAftAAAAAMAaAEAAAYAChQAHgAoAQIDAAAAAAAABAUGB2ZD")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x0BB9
    
    assert msg.sender == 0x0042
    
    assert msg.length == 31
    
    assert msg.payload == "tAAAAAMAaAEAAAYAChQAHgAoAQIDAAAAAAAABAUGBw=="
    
    assert msg.crc == 0x4366
    
    assert dictify(msg.chain_id) == 40
    
    assert dictify(msg.corr_time) == {'tow': 360, 'wn': 6}
    
    assert dictify(msg.obs_time) == {'tow': 180, 'wn': 3}
    
    assert dictify(msg.reserved) == [0, 0, 0, 0, 0, 0]
    
    assert dictify(msg.ssr_sol_id) == 10
    
    assert dictify(msg.tile_id) == 30
    
    assert dictify(msg.tile_set_id) == 20
    
    assert dictify(msg.use_bds_sat) == 3
    
    assert dictify(msg.use_gal_sat) == 2
    
    assert dictify(msg.use_gps_sat) == 1
    
    assert dictify(msg.use_iono_grid_point_sat_los) == 7
    
    assert dictify(msg.use_iono_grid_points) == 5
    
    assert dictify(msg.use_iono_tile_sat_los) == 6
    
    assert dictify(msg.use_tropo_grid_points) == 4

    assert dictify(msg) == {'obs_time': {'tow': 180, 'wn': 3}, 'corr_time': {'tow': 360, 'wn': 6}, 'ssr_sol_id': 10, 'tile_set_id': 20, 'tile_id': 30, 'chain_id': 40, 'use_gps_sat': 1, 'use_gal_sat': 2, 'use_bds_sat': 3, 'reserved': [0, 0, 0, 0, 0, 0], 'use_tropo_grid_points': 4, 'use_iono_grid_points': 5, 'use_iono_tile_sat_los': 6, 'use_iono_grid_point_sat_los': 7, 'preamble': 85, 'msg_type': 3001, 'sender': 66, 'length': 31, 'payload': 'tAAAAAMAaAEAAAYAChQAHgAoAQIDAAAAAAAABAUGBw==', 'crc': 17254}