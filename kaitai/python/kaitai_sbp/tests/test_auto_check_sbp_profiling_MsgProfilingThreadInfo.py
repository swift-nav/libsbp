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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingThreadInfo.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_profiling_msg_profiling_thread_info_1():
    buf = base64.standard_b64decode("VQLPABAnd1sKAAAAAABuBZsAAAAAAAEAAIAA0DUEAEZ1c2lvbiBlbmdpbmUA8qo=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xaaf2
    
    assert msg.length == 39
    
    assert msg.msg_type == 0xcf02
    
    assert msg.payload == "d1sKAAAAAABuBZsAAAAAAAEAAIAA0DUEAEZ1c2lvbiBlbmdpbmUA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.age) == 10159470
    
    assert dictify(msg.name) == "Fusion engine\x00"
    
    assert dictify(msg.stack_size) == 8388608
    
    assert dictify(msg.stack_usage) == 275920
    
    assert dictify(msg.state) == 1
    
    assert dictify(msg.total_cpu_time) == 678775

    assert dictify(msg) == {'crc': 43762, 'preamble': 85, 'sender': 4096, 'length': 39, 'msg_type': 52994, 'total_cpu_time': 678775, 'age': 10159470, 'state': 1, 'stack_size': 8388608, 'stack_usage': 275920, 'name': 'Fusion engine\x00', 'payload': 'd1sKAAAAAABuBZsAAAAAAAEAAIAA0DUEAEZ1c2lvbiBlbmdpbmUA'}