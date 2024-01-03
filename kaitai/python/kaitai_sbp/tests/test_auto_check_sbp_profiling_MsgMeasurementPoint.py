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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgMeasurementPoint.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_profiling_msg_measurement_point_1():
    buf = base64.standard_b64decode("VQDPABAw+gcAALQAAgAAACgAAACCyZSNYVUAABKCyZQAAAAAQkCdDwAAAAASAHJvdXRlKCkA1KU=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa5d4
    
    assert msg.length == 48
    
    assert msg.msg_type == 0xCF00
    
    assert msg.payload == "+gcAALQAAgAAACgAAACCyZSNYVUAABKCyZQAAAAAQkCdDwAAAAASAHJvdXRlKCkA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.func) == "route()\x00"
    
    assert dictify(msg.id) == 2496234002
    
    assert dictify(msg.line) == 18
    
    assert dictify(msg.max) == 40
    
    assert dictify(msg.min) == 2
    
    assert dictify(msg.num_executions) == 180
    
    assert dictify(msg.return_addr) == 93877475527042
    
    assert dictify(msg.slice_time) == 261963842
    
    assert dictify(msg.total_time) == 2042

    assert dictify(msg) == {'crc': 42452, 'preamble': 85, 'sender': 4096, 'length': 48, 'msg_type': 52992, 'total_time': 2042, 'num_executions': 180, 'min': 2, 'max': 40, 'return_addr': 93877475527042, 'id': 2496234002, 'slice_time': 261963842, 'line': 18, 'func': 'route()\x00', 'payload': '+gcAALQAAgAAACgAAACCyZSNYVUAABKCyZQAAAAAQkCdDwAAAAASAHJvdXRlKCkA'}