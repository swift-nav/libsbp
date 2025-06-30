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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosLLH.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_base_pos_llh_1():
    buf = base64.standard_b64decode("VUQAewAY4e3uWiqgQkA7j0brAHhewDO1fPBB+EJAUuY=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe652
    
    assert msg.length == 24
    
    assert msg.msg_type == 0x44
    
    assert msg.payload == "4e3uWiqgQkA7j0brAHhewDO1fPBB+EJA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x007b
    
    assert dictify(msg.height) == 37.939512310879216
    
    assert dictify(msg.lat) == 37.251292578377395
    
    assert dictify(msg.lon) == -121.87505609407974

    assert dictify(msg) == {'crc': 58962, 'length': 24, 'msg_type': 68, 'payload': '4e3uWiqgQkA7j0brAHhewDO1fPBB+EJA', 'preamble': 85, 'sender': 123, 'lat': 37.251292578377395, 'lon': -121.87505609407974, 'height': 37.939512310879216}
