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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxMemStateDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_linux_msg_linux_mem_state_dep_a_1():
    buf = base64.standard_b64decode("VQF/uW1B910wwXByb2Nlc3MtbmFtZQAAAC9wYXRoL3RvL3Byb2Nlc3MtbmFtZSBhcmcwIGFyZzEgYXJnMiBhcmczIGFyZzQRiQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8911
    
    assert msg.length == 65
    
    assert msg.msg_type == 0x7f01
    
    assert msg.payload == "910wwXByb2Nlc3MtbmFtZQAAAC9wYXRoL3RvL3Byb2Nlc3MtbmFtZSBhcmcwIGFyZzEgYXJnMiBhcmczIGFyZzQ="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x6db9
    
    assert dictify(msg.cmdline) == "/path/to/process-name arg0 arg1 arg2 arg3 arg4"
    
    assert dictify(msg.index) == 247
    
    assert dictify(msg.pid) == 12381
    
    assert dictify(msg.pmem) == 193
    
    assert dictify(msg.tname) == "process-name\x00\x00\x00"

    assert dictify(msg) == {'crc': 35089, 'length': 65, 'msg_type': 32513, 'payload': '910wwXByb2Nlc3MtbmFtZQAAAC9wYXRoL3RvL3Byb2Nlc3MtbmFtZSBhcmcwIGFyZzEgYXJnMiBhcmczIGFyZzQ=', 'preamble': 85, 'sender': 28089, 'index': 247, 'pid': 12381, 'pmem': 193, 'tname': 'process-name\x00\x00\x00', 'cmdline': '/path/to/process-name arg0 arg1 arg2 arg3 arg4'}
