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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSocketUsage.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_linux_msg_linux_socket_usage_1():
    buf = base64.standard_b64decode("VQV/copIDcRFrUPeurX2mvsR4LMaqbFaldXWBn5AeLlUg8hvII3Z0TQOvpOf9o161HeDHngvGW2aQYSkJx4erwgsHG/s8LBKn4GamaLlgpo=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9a82
    
    assert msg.length == 72
    
    assert msg.msg_type == 0x7f05
    
    assert msg.payload == "DcRFrUPeurX2mvsR4LMaqbFaldXWBn5AeLlUg8hvII3Z0TQOvpOf9o161HeDHngvGW2aQYSkJx4erwgsHG/s8LBKn4GamaLl"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x8a72
    
    assert dictify(msg.avg_queue_depth) == 2907030541
    
    assert dictify(msg.max_queue_depth) == 3048922691
    
    assert dictify(msg.socket_state_counts) == [39670, 4603, 46048, 43290, 23217, 54677, 1750, 16510, 47480, 33620, 28616, 36128, 53721, 3636, 37822, 63135]
    
    assert dictify(msg.socket_type_counts) == [31373, 30676, 7811, 12152, 27929, 16794, 42116, 7719, 44830, 11272, 28444, 61676, 19120, 33183, 39322, 58786]

    assert dictify(msg) == {'crc': 39554, 'length': 72, 'msg_type': 32517, 'payload': 'DcRFrUPeurX2mvsR4LMaqbFaldXWBn5AeLlUg8hvII3Z0TQOvpOf9o161HeDHngvGW2aQYSkJx4erwgsHG/s8LBKn4GamaLl', 'preamble': 85, 'sender': 35442, 'avg_queue_depth': 2907030541, 'max_queue_depth': 3048922691, 'socket_state_counts': [39670, 4603, 46048, 43290, 23217, 54677, 1750, 16510, 47480, 33620, 28616, 36128, 53721, 3636, 37822, 63135], 'socket_type_counts': [31373, 30676, 7811, 12152, 27929, 16794, 42116, 7719, 44830, 11272, 28444, 61676, 19120, 33183, 39322, 58786]}
