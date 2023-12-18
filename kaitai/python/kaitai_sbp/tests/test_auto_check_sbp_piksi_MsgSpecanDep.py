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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecanDep.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_specan_dep_1():
    buf = base64.standard_b64decode("VVAAcNn/9hbdOCU7LRuaYcZFmgGQRc0UEkYz01lF8A6zuuP0rfC2R6Z1xA0sGyEcQ/4D+VwseqlNukSHP6iiWSS6Yz9pdNgsQ9ScS1E1+uEXzRoidzJlQAfnfLfLZupUU9AXRDazYmB09PZeaF4NONISvxaFUZmfods7FaR5kcurhDm0ZmUL5a+RSUh8BLjkPeraPuLZwQdtLFPJFGUJjLqiUVse56FR2HI856OjMe30ufBZj66l0/ENED2NZVkldb1WdrDkDA53h4HzMh3PxnVk4QaLbifSRMcrhEARM621DIwQ91S3aSedTR7NwjtA8bfuabWqLQimpO5TlK1s5ENZvUMaJ9g=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd827
    
    assert msg.length == 255
    
    assert msg.msg_type == 0x50
    
    assert msg.payload == "9hbdOCU7LRuaYcZFmgGQRc0UEkYz01lF8A6zuuP0rfC2R6Z1xA0sGyEcQ/4D+VwseqlNukSHP6iiWSS6Yz9pdNgsQ9ScS1E1+uEXzRoidzJlQAfnfLfLZupUU9AXRDazYmB09PZeaF4NONISvxaFUZmfods7FaR5kcurhDm0ZmUL5a+RSUh8BLjkPeraPuLZwQdtLFPJFGUJjLqiUVse56FR2HI856OjMe30ufBZj66l0/ENED2NZVkldb1WdrDkDA53h4HzMh3PxnVk4QaLbifSRMcrhEARM621DIwQ91S3aSedTR7NwjtA8bfuabWqLQimpO5TlK1s5ENZvUMa"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd970
    
    assert dictify(msg.amplitude_ref) == 9349.2001953125
    
    assert dictify(msg.amplitude_unit) == 3485.199951171875
    
    assert dictify(msg.amplitude_value) == [240, 14, 179, 186, 227, 244, 173, 240, 182, 71, 166, 117, 196, 13, 44, 27, 33, 28, 67, 254, 3, 249, 92, 44, 122, 169, 77, 186, 68, 135, 63, 168, 162, 89, 36, 186, 99, 63, 105, 116, 216, 44, 67, 212, 156, 75, 81, 53, 250, 225, 23, 205, 26, 34, 119, 50, 101, 64, 7, 231, 124, 183, 203, 102, 234, 84, 83, 208, 23, 68, 54, 179, 98, 96, 116, 244, 246, 94, 104, 94, 13, 56, 210, 18, 191, 22, 133, 81, 153, 159, 161, 219, 59, 21, 164, 121, 145, 203, 171, 132, 57, 180, 102, 101, 11, 229, 175, 145, 73, 72, 124, 4, 184, 228, 61, 234, 218, 62, 226, 217, 193, 7, 109, 44, 83, 201, 20, 101, 9, 140, 186, 162, 81, 91, 30, 231, 161, 81, 216, 114, 60, 231, 163, 163, 49, 237, 244, 185, 240, 89, 143, 174, 165, 211, 241, 13, 16, 61, 141, 101, 89, 37, 117, 189, 86, 118, 176, 228, 12, 14, 119, 135, 129, 243, 50, 29, 207, 198, 117, 100, 225, 6, 139, 110, 39, 210, 68, 199, 43, 132, 64, 17, 51, 173, 181, 12, 140, 16, 247, 84, 183, 105, 39, 157, 77, 30, 205, 194, 59, 64, 241, 183, 238, 105, 181, 170, 45, 8, 166, 164, 238, 83, 148, 173, 108, 228, 67, 89, 189, 67, 26]
    
    assert dictify(msg.channel_tag) == 5878
    
    assert dictify(msg.freq_ref) == 6348.2001953125
    
    assert dictify(msg.freq_step) == 4608.2001953125
    
    assert dictify(msg.t) == {'tow': 992295133, 'wn': 6957}

    assert dictify(msg) == {'preamble': 85, 'msg_type': 80, 'sender': 55664, 'length': 255, 'payload': '9hbdOCU7LRuaYcZFmgGQRc0UEkYz01lF8A6zuuP0rfC2R6Z1xA0sGyEcQ/4D+VwseqlNukSHP6iiWSS6Yz9pdNgsQ9ScS1E1+uEXzRoidzJlQAfnfLfLZupUU9AXRDazYmB09PZeaF4NONISvxaFUZmfods7FaR5kcurhDm0ZmUL5a+RSUh8BLjkPeraPuLZwQdtLFPJFGUJjLqiUVse56FR2HI856OjMe30ufBZj66l0/ENED2NZVkldb1WdrDkDA53h4HzMh3PxnVk4QaLbifSRMcrhEARM621DIwQ91S3aSedTR7NwjtA8bfuabWqLQimpO5TlK1s5ENZvUMa', 'crc': 55335, 'channel_tag': 5878, 't': {'tow': 992295133, 'wn': 6957}, 'freq_ref': 6348.2001953125, 'freq_step': 4608.2001953125, 'amplitude_ref': 9349.2001953125, 'amplitude_unit': 3485.199951171875, 'amplitude_value': [240, 14, 179, 186, 227, 244, 173, 240, 182, 71, 166, 117, 196, 13, 44, 27, 33, 28, 67, 254, 3, 249, 92, 44, 122, 169, 77, 186, 68, 135, 63, 168, 162, 89, 36, 186, 99, 63, 105, 116, 216, 44, 67, 212, 156, 75, 81, 53, 250, 225, 23, 205, 26, 34, 119, 50, 101, 64, 7, 231, 124, 183, 203, 102, 234, 84, 83, 208, 23, 68, 54, 179, 98, 96, 116, 244, 246, 94, 104, 94, 13, 56, 210, 18, 191, 22, 133, 81, 153, 159, 161, 219, 59, 21, 164, 121, 145, 203, 171, 132, 57, 180, 102, 101, 11, 229, 175, 145, 73, 72, 124, 4, 184, 228, 61, 234, 218, 62, 226, 217, 193, 7, 109, 44, 83, 201, 20, 101, 9, 140, 186, 162, 81, 91, 30, 231, 161, 81, 216, 114, 60, 231, 163, 163, 49, 237, 244, 185, 240, 89, 143, 174, 165, 211, 241, 13, 16, 61, 141, 101, 89, 37, 117, 189, 86, 118, 176, 228, 12, 14, 119, 135, 129, 243, 50, 29, 207, 198, 117, 100, 225, 6, 139, 110, 39, 210, 68, 199, 43, 132, 64, 17, 51, 173, 181, 12, 140, 16, 247, 84, 183, 105, 39, 157, 77, 30, 205, 194, 59, 64, 241, 183, 238, 105, 181, 170, 45, 8, 166, 164, 238, 83, 148, 173, 108, 228, 67, 89, 189, 67, 26]}