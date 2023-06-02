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

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_obs_1():
    buf = base64.standard_b64decode("VUoAgfD5mMriGQAAAABqCCAx4/4+efKeBpIA+qy2Cg8KAB7k/j4MvSgFO1P7rLIKDwoB182QSGpvoAfzbfN3ngoPEgAZz5BI32DxBQw09ht9CQsSASK430qWit4HNQ0L9XIJDxYAcVAGRaIpQQdGf/b2vQkPFwD3UAZF1SOnBd2Y+OeeCQsXAQiSpkAMessGcjP4Q10DCxsA3aytS9kv9Afo4QvtewUPHwD6rq1L2KMyBihGCT54AwsfAYcQBkJj2gsHB4ryYLAKDwIDlIIGOtlYNgbLFfxgqgoPAwO6bMU/fzbTBlAE8dvICg8RA6fDCDkTzBYGaTP+tpgKDxID7fg=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xf8ed
    assert payload.length == 249
    assert payload.msg_type == 0x4a
    assert payload.payload == "mMriGQAAAABqCCAx4/4+efKeBpIA+qy2Cg8KAB7k/j4MvSgFO1P7rLIKDwoB182QSGpvoAfzbfN3ngoPEgAZz5BI32DxBQw09ht9CQsSASK430qWit4HNQ0L9XIJDxYAcVAGRaIpQQdGf/b2vQkPFwD3UAZF1SOnBd2Y+OeeCQsXAQiSpkAMessGcjP4Q10DCxsA3aytS9kv9Afo4QvtewUPHwD6rq1L2KMyBihGCT54AwsfAYcQBkJj2gsHB4ryYLAKDwIDlIIGOtlYNgbLFfxgqgoPAwO6bMU/fzbTBlAE8dvICg8RA6fDCDkTzBYGaTP+tpgKDxID"
    assert payload.preamble == 0x55
    assert payload.sender == 0xf081
    assert dictify(obj.payload.header) == snake_case_keys( {'n_obs': 32, 't': {'tow': 434293400, 'ns_residual': 0, 'wn': 2154}} )
    assert dictify(obj.payload.obs) == snake_case_keys( [{'P': 1056891697, 'L': {'i': 111080057, 'f': 146}, 'D': {'i': -1536, 'f': 172}, 'cn0': 182, 'lock': 10, 'flags': 15, 'sid': {'sat': 10, 'code': 0}}, {'P': 1056891934, 'L': {'i': 86555916, 'f': 59}, 'D': {'i': -1197, 'f': 172}, 'cn0': 178, 'lock': 10, 'flags': 15, 'sid': {'sat': 10, 'code': 1}}, {'P': 1217449431, 'L': {'i': 127954794, 'f': 243}, 'D': {'i': -3219, 'f': 119}, 'cn0': 158, 'lock': 10, 'flags': 15, 'sid': {'sat': 18, 'code': 0}}, {'P': 1217449753, 'L': {'i': 99705055, 'f': 12}, 'D': {'i': -2508, 'f': 27}, 'cn0': 125, 'lock': 9, 'flags': 11, 'sid': {'sat': 18, 'code': 1}}, {'P': 1256175650, 'L': {'i': 132024982, 'f': 53}, 'D': {'i': 2829, 'f': 245}, 'cn0': 114, 'lock': 9, 'flags': 15, 'sid': {'sat': 22, 'code': 0}}, {'P': 1158041713, 'L': {'i': 121711010, 'f': 70}, 'D': {'i': -2433, 'f': 246}, 'cn0': 189, 'lock': 9, 'flags': 15, 'sid': {'sat': 23, 'code': 0}}, {'P': 1158041847, 'L': {'i': 94839765, 'f': 221}, 'D': {'i': -1896, 'f': 231}, 'cn0': 158, 'lock': 9, 'flags': 11, 'sid': {'sat': 23, 'code': 1}}, {'P': 1084658184, 'L': {'i': 113998348, 'f': 114}, 'D': {'i': -1997, 'f': 67}, 'cn0': 93, 'lock': 3, 'flags': 11, 'sid': {'sat': 27, 'code': 0}}, {'P': 1269673181, 'L': {'i': 133443545, 'f': 232}, 'D': {'i': 3041, 'f': 237}, 'cn0': 123, 'lock': 5, 'flags': 15, 'sid': {'sat': 31, 'code': 0}}, {'P': 1269673722, 'L': {'i': 103982040, 'f': 40}, 'D': {'i': 2374, 'f': 62}, 'cn0': 120, 'lock': 3, 'flags': 11, 'sid': {'sat': 31, 'code': 1}}, {'P': 1107693703, 'L': {'i': 118217315, 'f': 7}, 'D': {'i': -3446, 'f': 96}, 'cn0': 176, 'lock': 10, 'flags': 15, 'sid': {'sat': 2, 'code': 3}}, {'P': 973505172, 'L': {'i': 104224985, 'f': 203}, 'D': {'i': -1003, 'f': 96}, 'cn0': 170, 'lock': 10, 'flags': 15, 'sid': {'sat': 3, 'code': 3}}, {'P': 1069903034, 'L': {'i': 114505343, 'f': 80}, 'D': {'i': -3836, 'f': 219}, 'cn0': 200, 'lock': 10, 'flags': 15, 'sid': {'sat': 17, 'code': 3}}, {'P': 956875687, 'L': {'i': 102157331, 'f': 105}, 'D': {'i': -461, 'f': 182}, 'cn0': 152, 'lock': 10, 'flags': 15, 'sid': {'sat': 18, 'code': 3}}] )

    assert dictify(payload) == snake_case_keys( {"header":{"t":{"tow":434293400,"ns_residual":0,"wn":2154},"n_obs":32},"obs":[{"P":1056891697,"L":{"i":111080057,"f":146},"D":{"i":-1536,"f":172},"cn0":182,"lock":10,"flags":15,"sid":{"sat":10,"code":0}},{"P":1056891934,"L":{"i":86555916,"f":59},"D":{"i":-1197,"f":172},"cn0":178,"lock":10,"flags":15,"sid":{"sat":10,"code":1}},{"P":1217449431,"L":{"i":127954794,"f":243},"D":{"i":-3219,"f":119},"cn0":158,"lock":10,"flags":15,"sid":{"sat":18,"code":0}},{"P":1217449753,"L":{"i":99705055,"f":12},"D":{"i":-2508,"f":27},"cn0":125,"lock":9,"flags":11,"sid":{"sat":18,"code":1}},{"P":1256175650,"L":{"i":132024982,"f":53},"D":{"i":2829,"f":245},"cn0":114,"lock":9,"flags":15,"sid":{"sat":22,"code":0}},{"P":1158041713,"L":{"i":121711010,"f":70},"D":{"i":-2433,"f":246},"cn0":189,"lock":9,"flags":15,"sid":{"sat":23,"code":0}},{"P":1158041847,"L":{"i":94839765,"f":221},"D":{"i":-1896,"f":231},"cn0":158,"lock":9,"flags":11,"sid":{"sat":23,"code":1}},{"P":1084658184,"L":{"i":113998348,"f":114},"D":{"i":-1997,"f":67},"cn0":93,"lock":3,"flags":11,"sid":{"sat":27,"code":0}},{"P":1269673181,"L":{"i":133443545,"f":232},"D":{"i":3041,"f":237},"cn0":123,"lock":5,"flags":15,"sid":{"sat":31,"code":0}},{"P":1269673722,"L":{"i":103982040,"f":40},"D":{"i":2374,"f":62},"cn0":120,"lock":3,"flags":11,"sid":{"sat":31,"code":1}},{"P":1107693703,"L":{"i":118217315,"f":7},"D":{"i":-3446,"f":96},"cn0":176,"lock":10,"flags":15,"sid":{"sat":2,"code":3}},{"P":973505172,"L":{"i":104224985,"f":203},"D":{"i":-1003,"f":96},"cn0":170,"lock":10,"flags":15,"sid":{"sat":3,"code":3}},{"P":1069903034,"L":{"i":114505343,"f":80},"D":{"i":-3836,"f":219},"cn0":200,"lock":10,"flags":15,"sid":{"sat":17,"code":3}},{"P":956875687,"L":{"i":102157331,"f":105},"D":{"i":-461,"f":182},"cn0":152,"lock":10,"flags":15,"sid":{"sat":18,"code":3}}],"preamble":85,"msg_type":74,"sender":61569,"payload":"mMriGQAAAABqCCAx4/4+efKeBpIA+qy2Cg8KAB7k/j4MvSgFO1P7rLIKDwoB182QSGpvoAfzbfN3ngoPEgAZz5BI32DxBQw09ht9CQsSASK430qWit4HNQ0L9XIJDxYAcVAGRaIpQQdGf/b2vQkPFwD3UAZF1SOnBd2Y+OeeCQsXAQiSpkAMessGcjP4Q10DCxsA3aytS9kv9Afo4QvtewUPHwD6rq1L2KMyBihGCT54AwsfAYcQBkJj2gsHB4ryYLAKDwIDlIIGOtlYNgbLFfxgqgoPAwO6bMU/fzbTBlAE8dvICg8RA6fDCDkTzBYGaTP+tpgKDxID","crc":63725,"length":249} )

def test_auto_check_sbp_observation_msg_obs_2():
    buf = base64.standard_b64decode("VUoAgfALmMriGQAAAABqCBDJZQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x65c9
    assert payload.length == 11
    assert payload.payload == "mMriGQAAAABqCBA="
    assert payload.msg_type == 0x4a
    assert payload.preamble == 0x55
    assert payload.sender == 0xf081
    assert dictify(obj.payload.header) == snake_case_keys( {'n_obs': 16, 't': {'tow': 434293400, 'ns_residual': 0, 'wn': 2154}} )
    assert dictify(obj.payload.obs) == snake_case_keys( [] )

    assert dictify(payload) == snake_case_keys( {"header":{"t":{"tow":434293400,"ns_residual":0,"wn":2154},"n_obs":16},"obs":[],"preamble":85,"msg_type":74,"sender":61569,"payload":"mMriGQAAAABqCBA=","crc":26057,"length":11} )