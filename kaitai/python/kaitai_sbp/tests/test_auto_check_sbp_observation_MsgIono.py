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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgIono.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_iono_1():
    buf = base64.standard_b64decode("VZAAewBGAAAAAAAAAAAAAAAAND4AAAAAAABQPgAAAAAAAHC+AAAAAAAAcL4AAAAAAADzQAAAAAAAAOhAAAAAAAAA8MAAAAAAAAAUwWUf")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1f65
    
    assert msg.length == 70
    
    assert msg.msg_type == 0x90
    
    assert msg.payload == "AAAAAAAAAAAAAAAAND4AAAAAAABQPgAAAAAAAHC+AAAAAAAAcL4AAAAAAADzQAAAAAAAAOhAAAAAAAAA8MAAAAAAAAAUwQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x007b
    
    assert dictify(msg.a0) == 4.6566128730773926e-09
    
    assert dictify(msg.a1) == 1.4901161193847656e-08
    
    assert dictify(msg.a2) == -5.960464477539063e-08
    
    assert dictify(msg.a3) == -5.960464477539063e-08
    
    assert dictify(msg.b0) == 77824.0
    
    assert dictify(msg.b1) == 49152.0
    
    assert dictify(msg.b2) == -65536.0
    
    assert dictify(msg.b3) == -327680.0
    
    assert dictify(msg.t_nmct) == {'tow': 0, 'wn': 0}

    assert dictify(msg) == {'crc': 8037, 'length': 70, 'msg_type': 144, 'payload': 'AAAAAAAAAAAAAAAAND4AAAAAAABQPgAAAAAAAHC+AAAAAAAAcL4AAAAAAADzQAAAAAAAAOhAAAAAAAAA8MAAAAAAAAAUwQ==', 'preamble': 85, 'sender': 123, 't_nmct': {'tow': 0, 'wn': 0}, 'a0': 4.6566128730773926e-09, 'a1': 1.4901161193847656e-08, 'a2': -5.960464477539063e-08, 'a3': -5.960464477539063e-08, 'b0': 77824, 'b1': 49152, 'b2': -65536, 'b3': -327680}