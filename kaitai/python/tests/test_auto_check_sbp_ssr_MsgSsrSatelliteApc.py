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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_satellite_apc_1():
    buf = base64.standard_b64decode("VQUGAAApfzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSmQoQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"preamble": 85, "msg_type": 1541, "sender": 0, "length": 41, "payload": "fzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSk=", "crc": 41360, "time": {"tow": 604799, "wn": 2222}, "update_interval": 1, "sol_id": 2, "iod_ssr": 3, "apc": [{"sid": {"sat": 2, "code": 0}, "sat_info": 4, "svn": 61, "pco": [1, -1, 729], "pcv": [11, 10, 8, 5, 1, -4, -8, -10, -10, -10, -7, -4, 0, 6, 12, 22, 30, 41, 41, 41, 41]}]}
    assert parsed_dict['crc'] == 0xA190
    assert parsed_dict['length'] == 41
    assert parsed_dict['msg_type'] == 0x605
    assert parsed_dict['payload'] == "fzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSk="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x0
    assert dictify(obj.payload.apc) == snake_case_keys( [{'pco': [1, -1, 729], 'pcv': [11, 10, 8, 5, 1, -4, -8, -10, -10, -10, -7, -4, 0, 6, 12, 22, 30, 41, 41, 41, 41], 'sat_info': 4, 'sid': {'code': 0, 'sat': 2}, 'svn': 61}] )
    assert dictify(obj.payload.iod_ssr) == snake_case_keys( 3 )
    assert dictify(obj.payload.sol_id) == snake_case_keys( 2 )
    assert dictify(obj.payload.time) == snake_case_keys( {'tow': 604799, 'wn': 2222} )
    assert dictify(obj.payload.update_interval) == snake_case_keys( 1 )

    assert parsed_dict == snake_case_keys(orig_dict)