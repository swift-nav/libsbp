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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessSocketCounts.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_linux_msg_linux_process_socket_counts_1():
    buf = base64.standard_b64decode("VQN/bAk3M4lvT3YDjHJzL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNLSD")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x83b4
    
    assert msg.length == 55
    
    assert msg.msg_type == 0x7f03
    
    assert msg.payload == "M4lvT3YDjHJzL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x096c
    
    assert dictify(msg.cmdline) == "/path/to/process-name arg0 arg1 arg2 arg3 arg4"
    
    assert dictify(msg.index) == 51
    
    assert dictify(msg.pid) == 28553
    
    assert dictify(msg.socket_count) == 30287
    
    assert dictify(msg.socket_states) == 29554
    
    assert dictify(msg.socket_types) == 35843

    assert dictify(msg) == {'crc': 33716, 'length': 55, 'msg_type': 32515, 'payload': 'M4lvT3YDjHJzL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==', 'preamble': 85, 'sender': 2412, 'index': 51, 'pid': 28553, 'socket_count': 30287, 'socket_types': 35843, 'socket_states': 29554, 'cmdline': '/path/to/process-name arg0 arg1 arg2 arg3 arg4'}
