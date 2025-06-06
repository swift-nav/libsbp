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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgSvConfigurationGpsDep.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_sv_configuration_gps_dep_1():
    buf = base64.standard_b64decode("VZEAewAKAAAAAAAAQrxlpxIq")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2a12
    
    assert msg.length == 10
    
    assert msg.msg_type == 0x91
    
    assert msg.payload == "AAAAAAAAQrxlpw=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x007b
    
    assert dictify(msg.l2c_mask) == 2808462402
    
    assert dictify(msg.t_nmct) == {'tow': 0, 'wn': 0}

    assert dictify(msg) == {'crc': 10770, 'length': 10, 'msg_type': 145, 'payload': 'AAAAAAAAQrxlpw==', 'preamble': 85, 'sender': 123, 't_nmct': {'tow': 0, 'wn': 0}, 'l2c_mask': 2808462402}
