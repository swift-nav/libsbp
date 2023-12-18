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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxMemState.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_linux_msg_linux_mem_state_1():
    buf = base64.standard_b64decode("VQl/X/1Gmr/fE/c1GrtMcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNAO1")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb503
    
    assert msg.length == 70
    
    assert msg.msg_type == 0x7f09
    
    assert msg.payload == "mr/fE/c1GrtMcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xfd5f
    
    assert dictify(msg.cmdline) == "/path/to/process-name arg0 arg1 arg2 arg3 arg4"
    
    assert dictify(msg.flags) == 76
    
    assert dictify(msg.index) == 154
    
    assert dictify(msg.pid) == 57279
    
    assert dictify(msg.pmem) == 19
    
    assert dictify(msg.time) == 3139057143
    
    assert dictify(msg.tname) == "process-name\x00\x00\x00"

    assert dictify(msg) == {'crc': 46339, 'length': 70, 'msg_type': 32521, 'payload': 'mr/fE/c1GrtMcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==', 'preamble': 85, 'sender': 64863, 'index': 154, 'pid': 57279, 'pmem': 19, 'time': 3139057143, 'flags': 76, 'tname': 'process-name\x00\x00\x00', 'cmdline': '/path/to/process-name arg0 arg1 arg2 arg3 arg4'}