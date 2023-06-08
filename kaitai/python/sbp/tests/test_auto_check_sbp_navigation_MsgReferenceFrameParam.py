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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_reference_frame_param_1():
    buf = base64.standard_b64decode("VUQCQgB8AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAAah")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x0244
    
    assert msg.sender == 0x0042
    
    assert msg.length == 124
    
    assert msg.payload == "AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAA=="
    
    assert msg.crc == 0xA106
    
    assert dictify(msg.delta_x0) == 7
    
    assert dictify(msg.delta_y0) == 8
    
    assert dictify(msg.delta_z0) == 9
    
    assert dictify(msg.dot_delta_x0) == 14
    
    assert dictify(msg.dot_delta_y0) == 15
    
    assert dictify(msg.dot_delta_z0) == 16
    
    assert dictify(msg.dot_scale) == 20
    
    assert dictify(msg.dot_theta_01) == 17
    
    assert dictify(msg.dot_theta_02) == 18
    
    assert dictify(msg.dot_theta_03) == 19
    
    assert dictify(msg.re_t0) == 6
    
    assert dictify(msg.scale) == 13
    
    assert dictify(msg.sin) == 4
    
    assert dictify(msg.sn) == "foo\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.ssr_iod) == 1
    
    assert dictify(msg.theta_01) == 10
    
    assert dictify(msg.theta_02) == 11
    
    assert dictify(msg.theta_03) == 12
    
    assert dictify(msg.tn) == "bar\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.utn) == 5

    assert dictify(msg) == {'ssr_iod': 1, 'sn': 'foo\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'tn': 'bar\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'sin': 4, 'utn': 5, 're_t0': 6, 'delta_x0': 7, 'delta_y0': 8, 'delta_z0': 9, 'theta_01': 10, 'theta_02': 11, 'theta_03': 12, 'scale': 13, 'dot_delta_x0': 14, 'dot_delta_y0': 15, 'dot_delta_z0': 16, 'dot_theta_01': 17, 'dot_theta_02': 18, 'dot_theta_03': 19, 'dot_scale': 20, 'preamble': 85, 'msg_type': 580, 'sender': 66, 'length': 124, 'payload': 'AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAA==', 'crc': 41222}