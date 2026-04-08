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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingQueueInfo.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_profiling_msg_profiling_queue_info_1():
    buf = base64.standard_b64decode("VQTPABA6AAGIEwAAAAAAAENvaGVzaXZlU2JwTXNnAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABkAAoAMgAAAIoq")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2a8a
    
    assert msg.length == 58
    
    assert msg.msg_type == 0xcf04
    
    assert msg.payload == "AAGIEwAAAAAAAENvaGVzaXZlU2JwTXNnAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABkAAoAMgAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.queues) == [{'timestamp': 5000, 'name': 'CohesiveSbpMsg\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'size': 100, 'current_fill': 10, 'peak_fill': 50, 'drop_count': 0}]
    
    assert dictify(msg.seq_len) == 1
    
    assert dictify(msg.seq_no) == 0

    assert dictify(msg) == {'crc': 10890, 'preamble': 85, 'sender': 4096, 'length': 58, 'msg_type': 52996, 'seq_no': 0, 'seq_len': 1, 'queues': [{'timestamp': 5000, 'name': 'CohesiveSbpMsg\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'size': 100, 'current_fill': 10, 'peak_fill': 50, 'drop_count': 0}], 'payload': 'AAGIEwAAAAAAAENvaGVzaXZlU2JwTXNnAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABkAAoAMgAAAA=='}
