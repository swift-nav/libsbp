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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdCount.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_linux_msg_linux_process_fd_count_1():
    buf = base64.standard_b64decode("VQZ/HsMzpL2lBYsvcGF0aC90by9wcm9jZXNzLW5hbWUgYXJnMCBhcmcxIGFyZzIgYXJnMyBhcmc0Al4=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5e02
    
    assert msg.length == 51
    
    assert msg.msg_type == 0x7f06
    
    assert msg.payload == "pL2lBYsvcGF0aC90by9wcm9jZXNzLW5hbWUgYXJnMCBhcmcxIGFyZzIgYXJnMyBhcmc0"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xc31e
    
    assert dictify(msg.cmdline) == "/path/to/process-name arg0 arg1 arg2 arg3 arg4"
    
    assert dictify(msg.fd_count) == 35589
    
    assert dictify(msg.index) == 164
    
    assert dictify(msg.pid) == 42429

    assert dictify(msg) == {'crc': 24066, 'length': 51, 'msg_type': 32518, 'payload': 'pL2lBYsvcGF0aC90by9wcm9jZXNzLW5hbWUgYXJnMCBhcmcxIGFyZzIgYXJnMyBhcmc0', 'preamble': 85, 'sender': 49950, 'index': 164, 'pid': 42429, 'fd_count': 35589, 'cmdline': '/path/to/process-name arg0 arg1 arg2 arg3 arg4'}