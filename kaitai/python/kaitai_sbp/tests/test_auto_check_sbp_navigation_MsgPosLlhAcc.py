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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhAcc.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_llh_acc_1():
    buf = base64.standard_b64decode("VRgCAhxDJ3huEjMzMzMzi71AmpmZmRmXwEAzMzMzM6GwQDMzMzMzZbNAM6MWRZoZrUVmhvNEmsnERc3gAEYzI0hFM2MfRV8bSNyx")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb1dc
    
    assert msg.length == 67
    
    assert msg.msg_type == 0x218
    
    assert msg.payload == "J3huEjMzMzMzi71AmpmZmRmXwEAzMzMzM6GwQDMzMzMzZbNAM6MWRZoZrUVmhvNEmsnERc3gAEYzI0hFM2MfRV8bSA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1c02
    
    assert dictify(msg.at_accuracy) == 6297.2001953125
    
    assert dictify(msg.confidence_and_geoid) == 95
    
    assert dictify(msg.ct_accuracy) == 1948.199951171875
    
    assert dictify(msg.flags) == 72
    
    assert dictify(msg.h_accuracy) == 2410.199951171875
    
    assert dictify(msg.h_ellipse) == {'orientation': 2550.199951171875, 'semi_major': 8248.2001953125, 'semi_minor': 3202.199951171875}
    
    assert dictify(msg.height) == 4257.2
    
    assert dictify(msg.lat) == 7563.2
    
    assert dictify(msg.lon) == 8494.2
    
    assert dictify(msg.n_sats) == 27
    
    assert dictify(msg.orthometric_height) == 4965.2
    
    assert dictify(msg.tow) == 309229607
    
    assert dictify(msg.v_accuracy) == 5539.2001953125

    assert dictify(msg) == {'preamble': 85, 'msg_type': 536, 'sender': 7170, 'length': 67, 'payload': 'J3huEjMzMzMzi71AmpmZmRmXwEAzMzMzM6GwQDMzMzMzZbNAM6MWRZoZrUVmhvNEmsnERc3gAEYzI0hFM2MfRV8bSA==', 'crc': 45532, 'tow': 309229607, 'lat': 7563.2, 'lon': 8494.2, 'height': 4257.2, 'orthometric_height': 4965.2, 'h_accuracy': 2410.199951171875, 'v_accuracy': 5539.2001953125, 'ct_accuracy': 1948.199951171875, 'at_accuracy': 6297.2001953125, 'h_ellipse': {'semi_major': 8248.2001953125, 'semi_minor': 3202.199951171875, 'orientation': 2550.199951171875}, 'confidence_and_geoid': 95, 'n_sats': 27, 'flags': 72}