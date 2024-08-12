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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagSatellites.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_integrity_msg_ssr_flag_satellites_1():
    buf = base64.standard_b64decode("Vb0LQgAPtAAAAAMAAQIDBAUDCgsMbqU=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x0BBD
    
    assert msg.sender == 0x0042
    
    assert msg.length == 15
    
    assert msg.payload == "tAAAAAMAAQIDBAUDCgsM"
    
    assert msg.crc == 0xA56E
    
    assert dictify(msg.chain_id) == 4
    
    assert dictify(msg.const_id) == 5
    
    assert dictify(msg.faulty_sats) == [10, 11, 12]
    
    assert dictify(msg.n_faulty_sats) == 3
    
    assert dictify(msg.num_msgs) == 1
    
    assert dictify(msg.obs_time) == {'tow': 180, 'wn': 3}
    
    assert dictify(msg.seq_num) == 2
    
    assert dictify(msg.ssr_sol_id) == 3

    assert dictify(msg) == {'obs_time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'ssr_sol_id': 3, 'chain_id': 4, 'const_id': 5, 'n_faulty_sats': 3, 'faulty_sats': [10, 11, 12], 'preamble': 85, 'msg_type': 3005, 'sender': 66, 'length': 15, 'payload': 'tAAAAAMAAQIDBAUDCgsM', 'crc': 42350}