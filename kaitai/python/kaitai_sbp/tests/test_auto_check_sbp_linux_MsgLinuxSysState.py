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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSysState.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_linux_msg_linux_sys_state_1():
    buf = base64.standard_b64decode("VQp/VacPFM9918RHoeX6umweagUJ5fI=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf2e5
    
    assert msg.length == 15
    
    assert msg.msg_type == 0x7f0a
    
    assert msg.payload == "FM9918RHoeX6umweagUJ"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xa755
    
    assert dictify(msg.flags) == 9
    
    assert dictify(msg.mem_total) == 53012
    
    assert dictify(msg.pcpu) == 125
    
    assert dictify(msg.pid_count) == 47866
    
    assert dictify(msg.pmem) == 215
    
    assert dictify(msg.procs_starting) == 18372
    
    assert dictify(msg.procs_stopping) == 58785
    
    assert dictify(msg.time) == 90840684

    assert dictify(msg) == {'crc': 62181, 'length': 15, 'msg_type': 32522, 'payload': 'FM9918RHoeX6umweagUJ', 'preamble': 85, 'sender': 42837, 'mem_total': 53012, 'pcpu': 125, 'pmem': 215, 'procs_starting': 18372, 'procs_stopping': 58785, 'pid_count': 47866, 'time': 90840684, 'flags': 9}
