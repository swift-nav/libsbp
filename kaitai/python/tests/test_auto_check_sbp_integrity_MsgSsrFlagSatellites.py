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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagSatellites.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_integrity_msg_ssr_flag_satellites_1():
    buf = base64.standard_b64decode("Vb0LQgAPtAAAAAMAAQIDBAUDCgsMbqU=")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"obs_time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 2, "ssr_sol_id": 3, "chain_id": 4, "const_id": 5, "n_faulty_sats": 3, "faulty_sats": [10, 11, 12], "preamble": 85, "msg_type": 3005, "sender": 66, "length": 15, "payload": "tAAAAAMAAQIDBAUDCgsM", "crc": 42350}
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['msg_type'] == 0x0BBD
    assert parsed_dict['sender'] == 0x0042
    assert parsed_dict['length'] == 15
    assert parsed_dict['payload'] == "tAAAAAMAAQIDBAUDCgsM"
    assert parsed_dict['crc'] == 0xA56E
    assert dictify(obj.payload.chain_id) == snake_case_keys( 4 )
    assert dictify(obj.payload.const_id) == snake_case_keys( 5 )
    assert dictify(obj.payload.faulty_sats) == snake_case_keys( [10, 11, 12] )
    assert dictify(obj.payload.n_faulty_sats) == snake_case_keys( 3 )
    assert dictify(obj.payload.num_msgs) == snake_case_keys( 1 )
    assert dictify(obj.payload.obs_time) == snake_case_keys( {'tow': 180, 'wn': 3} )
    assert dictify(obj.payload.seq_num) == snake_case_keys( 2 )
    assert dictify(obj.payload.ssr_sol_id) == snake_case_keys( 3 )

    assert parsed_dict == snake_case_keys(orig_dict)