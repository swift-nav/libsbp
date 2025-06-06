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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingSystemInfo.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_profiling_msg_profiling_system_info_1():
    buf = base64.standard_b64decode("VQHPABAVYig0AAAAAAByDJ0AAAAAABtIw+IA/EE=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x41fc
    
    assert msg.length == 21
    
    assert msg.msg_type == 0xcf01
    
    assert msg.payload == "Yig0AAAAAAByDJ0AAAAAABtIw+IA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.age) == 10292338
    
    assert dictify(msg.heap_usage) == 14861128
    
    assert dictify(msg.n_threads) == 27
    
    assert dictify(msg.total_cpu_time) == 3418210

    assert dictify(msg) == {'crc': 16892, 'preamble': 85, 'sender': 4096, 'length': 21, 'msg_type': 52993, 'total_cpu_time': 3418210, 'age': 10292338, 'n_threads': 27, 'heap_usage': 14861128, 'payload': 'Yig0AAAAAAByDJ0AAAAAABtIw+IA'}
