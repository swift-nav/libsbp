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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagIonoGridPointSatLos.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_integrity_msg_ssr_flag_iono_grid_point_sat_los_1():
    buf = base64.standard_b64decode("VdELQgAVtAAAAAMAAQIDBAAFAAYeAAIKCw8OYpQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.preamble == 0x55
    assert payload.msg_type == 0x0BD1
    assert payload.sender == 0x0042
    assert payload.length == 21
    assert payload.payload == "tAAAAAMAAQIDBAAFAAYeAAIKCw8O"
    assert payload.crc == 0x9462
    assert dictify(obj.payload.faulty_los) == snake_case_keys( [{'satId': 10, 'constellation': 11}, {'satId': 15, 'constellation': 14}] )
    assert dictify(obj.payload.grid_point_id) == snake_case_keys( 30 )
    assert dictify(obj.payload.header) == snake_case_keys( {'obs_time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'ssr_sol_id': 3, 'tile_set_id': 4, 'tile_id': 5, 'chain_id': 6} )
    assert dictify(obj.payload.n_faulty_los) == snake_case_keys( 2 )

    assert dictify(payload) == snake_case_keys( {"header": {"obs_time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 2, "ssr_sol_id": 3, "tile_set_id": 4, "tile_id": 5, "chain_id": 6}, "grid_point_id": 30, "n_faulty_los": 2, "faulty_los": [{"satId": 10, "constellation": 11}, {"satId": 15, "constellation": 14}], "preamble": 85, "msg_type": 3025, "sender": 66, "length": 21, "payload": "tAAAAAMAAQIDBAAFAAYeAAIKCw8O", "crc": 37986} )