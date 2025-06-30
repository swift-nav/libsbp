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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_satellite_apc_1():
    buf = base64.standard_b64decode("VQUGAAApfzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSmQoQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xA190
    
    assert msg.length == 41
    
    assert msg.msg_type == 0x605
    
    assert msg.payload == "fzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSk="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x0
    
    assert dictify(msg.apc) == [{'pco': [1, -1, 729], 'pcv': [11, 10, 8, 5, 1, -4, -8, -10, -10, -10, -7, -4, 0, 6, 12, 22, 30, 41, 41, 41, 41], 'sat_info': 4, 'sid': {'code': 0, 'sat': 2}, 'svn': 61}]
    
    assert dictify(msg.iod_ssr) == 3
    
    assert dictify(msg.sol_id) == 2
    
    assert dictify(msg.time) == {'tow': 604799, 'wn': 2222}
    
    assert dictify(msg.update_interval) == 1

    assert dictify(msg) == {'preamble': 85, 'msg_type': 1541, 'sender': 0, 'length': 41, 'payload': 'fzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSk=', 'crc': 41360, 'time': {'tow': 604799, 'wn': 2222}, 'update_interval': 1, 'sol_id': 2, 'iod_ssr': 3, 'apc': [{'sid': {'sat': 2, 'code': 0}, 'sat_info': 4, 'svn': 61, 'pco': [1, -1, 729], 'pcv': [11, 10, 8, 5, 1, -4, -8, -10, -10, -10, -7, -4, 0, 6, 12, 22, 30, 41, 41, 41, 41]}]}
