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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagIonoTileSatLos.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_integrity_msg_ssr_flag_iono_tile_sat_los_1():
    buf = base64.standard_b64decode("Vc0LQgATtAAAAAMAAQIDBAAFAAYCCgsPDu/r")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"header": {"obs_time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 2, "ssr_sol_id": 3, "tile_set_id": 4, "tile_id": 5, "chain_id": 6}, "n_faulty_los": 2, "faulty_los": [{"satId": 10, "constellation": 11}, {"satId": 15, "constellation": 14}], "preamble": 85, "msg_type": 3021, "sender": 66, "length": 19, "payload": "tAAAAAMAAQIDBAAFAAYCCgsPDg==", "crc": 60399}
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['msg_type'] == 0x0BCD
    assert parsed_dict['sender'] == 0x0042
    assert parsed_dict['length'] == 19
    assert parsed_dict['payload'] == "tAAAAAMAAQIDBAAFAAYCCgsPDg=="
    assert parsed_dict['crc'] == 0xEBEF
    assert dictify(obj.payload.faulty_los) == snake_case_keys( [{'satId': 10, 'constellation': 11}, {'satId': 15, 'constellation': 14}] )
    assert dictify(obj.payload.header) == snake_case_keys( {'obs_time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'ssr_sol_id': 3, 'tile_set_id': 4, 'tile_id': 5, 'chain_id': 6} )
    assert dictify(obj.payload.n_faulty_los) == snake_case_keys( 2 )

    assert parsed_dict == snake_case_keys(orig_dict)