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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagIonoGridPoints.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_integrity_msg_ssr_flag_iono_grid_points_1():
    buf = base64.standard_b64decode("VccLQgAVtAAAAAMAAQIDBAAFAAYDCgALAAwANQc=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x0BC7
    
    assert msg.sender == 0x0042
    
    assert msg.length == 21
    
    assert msg.payload == "tAAAAAMAAQIDBAAFAAYDCgALAAwA"
    
    assert msg.crc == 0x0735
    
    assert dictify(msg.faulty_points) == [10, 11, 12]
    
    assert dictify(msg.header) == {'obs_time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'ssr_sol_id': 3, 'tile_set_id': 4, 'tile_id': 5, 'chain_id': 6}
    
    assert dictify(msg.n_faulty_points) == 3

    assert dictify(msg) == {'header': {'obs_time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'ssr_sol_id': 3, 'tile_set_id': 4, 'tile_id': 5, 'chain_id': 6}, 'n_faulty_points': 3, 'faulty_points': [10, 11, 12], 'preamble': 85, 'msg_type': 3015, 'sender': 66, 'length': 21, 'payload': 'tAAAAAMAAQIDBAAFAAYDCgALAAwA', 'crc': 1845}