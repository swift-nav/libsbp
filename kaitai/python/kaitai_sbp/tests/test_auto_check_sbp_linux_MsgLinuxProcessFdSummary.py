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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdSummary.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_linux_msg_linux_process_fd_summary_1():
    buf = base64.standard_b64decode("VQd/Z/gdE4PITWZkMQBmZDIAZmQzAGZkNABmZDUAZmQ2AACBUA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5081
    
    assert msg.length == 29
    
    assert msg.msg_type == 0x7f07
    
    assert msg.payload == "E4PITWZkMQBmZDIAZmQzAGZkNABmZDUAZmQ2AAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xf867
    
    assert dictify(msg.most_opened) == "fd1\x00fd2\x00fd3\x00fd4\x00fd5\x00fd6\x00\x00"
    
    assert dictify(msg.sys_fd_count) == 1304986387

    assert dictify(msg) == {'crc': 20609, 'length': 29, 'msg_type': 32519, 'payload': 'E4PITWZkMQBmZDIAZmQzAGZkNABmZDUAZmQ2AAA=', 'preamble': 85, 'sender': 63591, 'sys_fd_count': 1304986387, 'most_opened': 'fd1\x00fd2\x00fd3\x00fd4\x00fd5\x00fd6\x00\x00'}