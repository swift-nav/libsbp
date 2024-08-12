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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSysStateDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_linux_msg_linux_sys_state_dep_a_1():
    buf = base64.standard_b64decode("VQJ/VDgKvKPTwnNHZWd8yd/f")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xdfdf
    
    assert msg.length == 10
    
    assert msg.msg_type == 0x7f02
    
    assert msg.payload == "vKPTwnNHZWd8yQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x3854
    
    assert dictify(msg.mem_total) == 41916
    
    assert dictify(msg.pcpu) == 211
    
    assert dictify(msg.pid_count) == 51580
    
    assert dictify(msg.pmem) == 194
    
    assert dictify(msg.procs_starting) == 18291
    
    assert dictify(msg.procs_stopping) == 26469

    assert dictify(msg) == {'crc': 57311, 'length': 10, 'msg_type': 32514, 'payload': 'vKPTwnNHZWd8yQ==', 'preamble': 85, 'sender': 14420, 'mem_total': 41916, 'pcpu': 211, 'pmem': 194, 'procs_starting': 18291, 'procs_stopping': 26469, 'pid_count': 51580}