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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkStateResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_network_state_resp_1():
    buf = base64.standard_b64decode("VbsAKA8yj/FUtJjCiSAscpNE3lzATus/0HI1txj05xppGYgDaWYwAAAAAAAAAAAAAAAAAMPlUJN2wQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc176
    
    assert msg.length == 50
    
    assert msg.msg_type == 0xbb
    
    assert msg.payload == "j/FUtJjCiSAscpNE3lzATus/0HI1txj05xppGYgDaWYwAAAAAAAAAAAAAAAAAMPlUJM="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x0f28
    
    assert dictify(msg.flags) == 2471552451
    
    assert dictify(msg.interface_name) == "if0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.ipv4_address) == [143, 241, 84, 180]
    
    assert dictify(msg.ipv4_mask_size) == 152
    
    assert dictify(msg.ipv6_address) == [194, 137, 32, 44, 114, 147, 68, 222, 92, 192, 78, 235, 63, 208, 114, 53]
    
    assert dictify(msg.ipv6_mask_size) == 183
    
    assert dictify(msg.rx_bytes) == 451408920
    
    assert dictify(msg.tx_bytes) == 59251049

    assert dictify(msg) == {'crc': 49526, 'length': 50, 'msg_type': 187, 'payload': 'j/FUtJjCiSAscpNE3lzATus/0HI1txj05xppGYgDaWYwAAAAAAAAAAAAAAAAAMPlUJM=', 'preamble': 85, 'sender': 3880, 'ipv4_address': [143, 241, 84, 180], 'ipv4_mask_size': 152, 'ipv6_address': [194, 137, 32, 44, 114, 147, 68, 222, 92, 192, 78, 235, 63, 208, 114, 53], 'ipv6_mask_size': 183, 'rx_bytes': 451408920, 'tx_bytes': 59251049, 'interface_name': 'if0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'flags': 2471552451}