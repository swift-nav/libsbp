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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_obs_1():
    buf = base64.standard_b64decode("VUoAgfD5mMriGQAAAABqCCAx4/4+efKeBpIA+qy2Cg8KAB7k/j4MvSgFO1P7rLIKDwoB182QSGpvoAfzbfN3ngoPEgAZz5BI32DxBQw09ht9CQsSASK430qWit4HNQ0L9XIJDxYAcVAGRaIpQQdGf/b2vQkPFwD3UAZF1SOnBd2Y+OeeCQsXAQiSpkAMessGcjP4Q10DCxsA3aytS9kv9Afo4QvtewUPHwD6rq1L2KMyBihGCT54AwsfAYcQBkJj2gsHB4ryYLAKDwIDlIIGOtlYNgbLFfxgqgoPAwO6bMU/fzbTBlAE8dvICg8RA6fDCDkTzBYGaTP+tpgKDxID7fg=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf8ed
    
    assert msg.length == 249
    
    assert msg.msg_type == 0x4a
    
    assert msg.payload == "mMriGQAAAABqCCAx4/4+efKeBpIA+qy2Cg8KAB7k/j4MvSgFO1P7rLIKDwoB182QSGpvoAfzbfN3ngoPEgAZz5BI32DxBQw09ht9CQsSASK430qWit4HNQ0L9XIJDxYAcVAGRaIpQQdGf/b2vQkPFwD3UAZF1SOnBd2Y+OeeCQsXAQiSpkAMessGcjP4Q10DCxsA3aytS9kv9Afo4QvtewUPHwD6rq1L2KMyBihGCT54AwsfAYcQBkJj2gsHB4ryYLAKDwIDlIIGOtlYNgbLFfxgqgoPAwO6bMU/fzbTBlAE8dvICg8RA6fDCDkTzBYGaTP+tpgKDxID"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xf081
    
    assert dictify(msg.header) == {'n_obs': 32, 't': {'tow': 434293400, 'ns_residual': 0, 'wn': 2154}}
    
    assert dictify(msg.obs) == [{'p': 1056891697, 'l': {'i': 111080057, 'f': 146}, 'd': {'i': -1536, 'f': 172}, 'cn0': 182, 'lock': 10, 'flags': 15, 'sid': {'sat': 10, 'code': 0}}, {'p': 1056891934, 'l': {'i': 86555916, 'f': 59}, 'd': {'i': -1197, 'f': 172}, 'cn0': 178, 'lock': 10, 'flags': 15, 'sid': {'sat': 10, 'code': 1}}, {'p': 1217449431, 'l': {'i': 127954794, 'f': 243}, 'd': {'i': -3219, 'f': 119}, 'cn0': 158, 'lock': 10, 'flags': 15, 'sid': {'sat': 18, 'code': 0}}, {'p': 1217449753, 'l': {'i': 99705055, 'f': 12}, 'd': {'i': -2508, 'f': 27}, 'cn0': 125, 'lock': 9, 'flags': 11, 'sid': {'sat': 18, 'code': 1}}, {'p': 1256175650, 'l': {'i': 132024982, 'f': 53}, 'd': {'i': 2829, 'f': 245}, 'cn0': 114, 'lock': 9, 'flags': 15, 'sid': {'sat': 22, 'code': 0}}, {'p': 1158041713, 'l': {'i': 121711010, 'f': 70}, 'd': {'i': -2433, 'f': 246}, 'cn0': 189, 'lock': 9, 'flags': 15, 'sid': {'sat': 23, 'code': 0}}, {'p': 1158041847, 'l': {'i': 94839765, 'f': 221}, 'd': {'i': -1896, 'f': 231}, 'cn0': 158, 'lock': 9, 'flags': 11, 'sid': {'sat': 23, 'code': 1}}, {'p': 1084658184, 'l': {'i': 113998348, 'f': 114}, 'd': {'i': -1997, 'f': 67}, 'cn0': 93, 'lock': 3, 'flags': 11, 'sid': {'sat': 27, 'code': 0}}, {'p': 1269673181, 'l': {'i': 133443545, 'f': 232}, 'd': {'i': 3041, 'f': 237}, 'cn0': 123, 'lock': 5, 'flags': 15, 'sid': {'sat': 31, 'code': 0}}, {'p': 1269673722, 'l': {'i': 103982040, 'f': 40}, 'd': {'i': 2374, 'f': 62}, 'cn0': 120, 'lock': 3, 'flags': 11, 'sid': {'sat': 31, 'code': 1}}, {'p': 1107693703, 'l': {'i': 118217315, 'f': 7}, 'd': {'i': -3446, 'f': 96}, 'cn0': 176, 'lock': 10, 'flags': 15, 'sid': {'sat': 2, 'code': 3}}, {'p': 973505172, 'l': {'i': 104224985, 'f': 203}, 'd': {'i': -1003, 'f': 96}, 'cn0': 170, 'lock': 10, 'flags': 15, 'sid': {'sat': 3, 'code': 3}}, {'p': 1069903034, 'l': {'i': 114505343, 'f': 80}, 'd': {'i': -3836, 'f': 219}, 'cn0': 200, 'lock': 10, 'flags': 15, 'sid': {'sat': 17, 'code': 3}}, {'p': 956875687, 'l': {'i': 102157331, 'f': 105}, 'd': {'i': -461, 'f': 182}, 'cn0': 152, 'lock': 10, 'flags': 15, 'sid': {'sat': 18, 'code': 3}}]

    assert dictify(msg) == {'header': {'t': {'tow': 434293400, 'ns_residual': 0, 'wn': 2154}, 'n_obs': 32}, 'obs': [{'p': 1056891697, 'l': {'i': 111080057, 'f': 146}, 'd': {'i': -1536, 'f': 172}, 'cn0': 182, 'lock': 10, 'flags': 15, 'sid': {'sat': 10, 'code': 0}}, {'p': 1056891934, 'l': {'i': 86555916, 'f': 59}, 'd': {'i': -1197, 'f': 172}, 'cn0': 178, 'lock': 10, 'flags': 15, 'sid': {'sat': 10, 'code': 1}}, {'p': 1217449431, 'l': {'i': 127954794, 'f': 243}, 'd': {'i': -3219, 'f': 119}, 'cn0': 158, 'lock': 10, 'flags': 15, 'sid': {'sat': 18, 'code': 0}}, {'p': 1217449753, 'l': {'i': 99705055, 'f': 12}, 'd': {'i': -2508, 'f': 27}, 'cn0': 125, 'lock': 9, 'flags': 11, 'sid': {'sat': 18, 'code': 1}}, {'p': 1256175650, 'l': {'i': 132024982, 'f': 53}, 'd': {'i': 2829, 'f': 245}, 'cn0': 114, 'lock': 9, 'flags': 15, 'sid': {'sat': 22, 'code': 0}}, {'p': 1158041713, 'l': {'i': 121711010, 'f': 70}, 'd': {'i': -2433, 'f': 246}, 'cn0': 189, 'lock': 9, 'flags': 15, 'sid': {'sat': 23, 'code': 0}}, {'p': 1158041847, 'l': {'i': 94839765, 'f': 221}, 'd': {'i': -1896, 'f': 231}, 'cn0': 158, 'lock': 9, 'flags': 11, 'sid': {'sat': 23, 'code': 1}}, {'p': 1084658184, 'l': {'i': 113998348, 'f': 114}, 'd': {'i': -1997, 'f': 67}, 'cn0': 93, 'lock': 3, 'flags': 11, 'sid': {'sat': 27, 'code': 0}}, {'p': 1269673181, 'l': {'i': 133443545, 'f': 232}, 'd': {'i': 3041, 'f': 237}, 'cn0': 123, 'lock': 5, 'flags': 15, 'sid': {'sat': 31, 'code': 0}}, {'p': 1269673722, 'l': {'i': 103982040, 'f': 40}, 'd': {'i': 2374, 'f': 62}, 'cn0': 120, 'lock': 3, 'flags': 11, 'sid': {'sat': 31, 'code': 1}}, {'p': 1107693703, 'l': {'i': 118217315, 'f': 7}, 'd': {'i': -3446, 'f': 96}, 'cn0': 176, 'lock': 10, 'flags': 15, 'sid': {'sat': 2, 'code': 3}}, {'p': 973505172, 'l': {'i': 104224985, 'f': 203}, 'd': {'i': -1003, 'f': 96}, 'cn0': 170, 'lock': 10, 'flags': 15, 'sid': {'sat': 3, 'code': 3}}, {'p': 1069903034, 'l': {'i': 114505343, 'f': 80}, 'd': {'i': -3836, 'f': 219}, 'cn0': 200, 'lock': 10, 'flags': 15, 'sid': {'sat': 17, 'code': 3}}, {'p': 956875687, 'l': {'i': 102157331, 'f': 105}, 'd': {'i': -461, 'f': 182}, 'cn0': 152, 'lock': 10, 'flags': 15, 'sid': {'sat': 18, 'code': 3}}], 'preamble': 85, 'msg_type': 74, 'sender': 61569, 'payload': 'mMriGQAAAABqCCAx4/4+efKeBpIA+qy2Cg8KAB7k/j4MvSgFO1P7rLIKDwoB182QSGpvoAfzbfN3ngoPEgAZz5BI32DxBQw09ht9CQsSASK430qWit4HNQ0L9XIJDxYAcVAGRaIpQQdGf/b2vQkPFwD3UAZF1SOnBd2Y+OeeCQsXAQiSpkAMessGcjP4Q10DCxsA3aytS9kv9Afo4QvtewUPHwD6rq1L2KMyBihGCT54AwsfAYcQBkJj2gsHB4ryYLAKDwIDlIIGOtlYNgbLFfxgqgoPAwO6bMU/fzbTBlAE8dvICg8RA6fDCDkTzBYGaTP+tpgKDxID', 'crc': 63725, 'length': 249}

def test_auto_check_sbp_observation_msg_obs_2():
    buf = base64.standard_b64decode("VUoAgfALmMriGQAAAABqCBDJZQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x65c9
    
    assert msg.length == 11
    
    assert msg.payload == "mMriGQAAAABqCBA="
    
    assert msg.msg_type == 0x4a
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xf081
    
    assert dictify(msg.header) == {'n_obs': 16, 't': {'tow': 434293400, 'ns_residual': 0, 'wn': 2154}}
    
    assert dictify(msg.obs) == []

    assert dictify(msg) == {'header': {'t': {'tow': 434293400, 'ns_residual': 0, 'wn': 2154}, 'n_obs': 16}, 'obs': [], 'preamble': 85, 'msg_type': 74, 'sender': 61569, 'payload': 'mMriGQAAAABqCBA=', 'crc': 26057, 'length': 11}