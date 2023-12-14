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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusReport.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_status_report_1():
    buf = base64.standard_b64decode("Vf7/BlT8Uv2xXwM8j1rpFdBi98vdxpzP2e6iiJoLcuyG6wyFCR6vkRpy1xSS+TY2hcFqutK3AIEF+OGVh38CGlhcCmdJA2dETLghzsKjex6XsJWsuOd25sioZG0K6QQ891LXphyKbi1i2vSzfmtcfF6dKrt8BmH3oLxueP7WbjPwpJMSSrJDBBtJvkCzkn2ZwC7KQvguKKGt8tYDCwF2RqI9shucKL9x5shICNf1Tjve+nMgIR7TqpFcnUsYqQY3PghrUowxs3paRxxYZzOxSF0nlAvKKiJczGYdYvlbhl8X+MAUU8NftDYkuktAFJ2FDJUcDrmBZe9K+PUe5FiO1DXgnqY=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa69e
    
    assert msg.length == 252
    
    assert msg.msg_type == 0xfffe
    
    assert msg.payload == "Uv2xXwM8j1rpFdBi98vdxpzP2e6iiJoLcuyG6wyFCR6vkRpy1xSS+TY2hcFqutK3AIEF+OGVh38CGlhcCmdJA2dETLghzsKjex6XsJWsuOd25sioZG0K6QQ891LXphyKbi1i2vSzfmtcfF6dKrt8BmH3oLxueP7WbjPwpJMSSrJDBBtJvkCzkn2ZwC7KQvguKKGt8tYDCwF2RqI9shucKL9x5shICNf1Tjve+nMgIR7TqpFcnUsYqQY3PghrUowxs3paRxxYZzOxSF0nlAvKKiJczGYdYvlbhl8X+MAUU8NftDYkuktAFJ2FDJUcDrmBZe9K+PUe5FiO1DXg"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x5406
    
    assert dictify(msg.reporting_system) == 64850
    
    assert dictify(msg.sbp_version) == 24497
    
    assert dictify(msg.sequence) == 1519336451
    
    assert dictify(msg.status) == [{'component': 52215, 'generic': 221, 'specific': 198}, {'component': 53148, 'generic': 217, 'specific': 238}, {'component': 34978, 'generic': 154, 'specific': 11}, {'component': 60530, 'generic': 134, 'specific': 235}, {'component': 34060, 'generic': 9, 'specific': 30}, {'component': 37295, 'generic': 26, 'specific': 114}, {'component': 5335, 'generic': 146, 'specific': 249}, {'component': 13878, 'generic': 133, 'specific': 193}, {'component': 47722, 'generic': 210, 'specific': 183}, {'component': 33024, 'generic': 5, 'specific': 248}, {'component': 38369, 'generic': 135, 'specific': 127}, {'component': 6658, 'generic': 88, 'specific': 92}, {'component': 26378, 'generic': 73, 'specific': 3}, {'component': 17511, 'generic': 76, 'specific': 184}, {'component': 52769, 'generic': 194, 'specific': 163}, {'component': 7803, 'generic': 151, 'specific': 176}, {'component': 44181, 'generic': 184, 'specific': 231}, {'component': 58998, 'generic': 200, 'specific': 168}, {'component': 28004, 'generic': 10, 'specific': 233}, {'component': 15364, 'generic': 247, 'specific': 82}, {'component': 42711, 'generic': 28, 'specific': 138}, {'component': 11630, 'generic': 98, 'specific': 218}, {'component': 46068, 'generic': 126, 'specific': 107}, {'component': 31836, 'generic': 94, 'specific': 157}, {'component': 47914, 'generic': 124, 'specific': 6}, {'component': 63329, 'generic': 160, 'specific': 188}, {'component': 30830, 'generic': 254, 'specific': 214}, {'component': 13166, 'generic': 240, 'specific': 164}, {'component': 4755, 'generic': 74, 'specific': 178}, {'component': 1091, 'generic': 27, 'specific': 73}, {'component': 16574, 'generic': 179, 'specific': 146}, {'component': 39293, 'generic': 192, 'specific': 46}, {'component': 17098, 'generic': 248, 'specific': 46}, {'component': 41256, 'generic': 173, 'specific': 242}, {'component': 982, 'generic': 11, 'specific': 1}, {'component': 18038, 'generic': 162, 'specific': 61}, {'component': 7090, 'generic': 156, 'specific': 40}, {'component': 29119, 'generic': 230, 'specific': 200}, {'component': 2120, 'generic': 215, 'specific': 245}, {'component': 15182, 'generic': 222, 'specific': 250}, {'component': 8307, 'generic': 33, 'specific': 30}, {'component': 43731, 'generic': 145, 'specific': 92}, {'component': 19357, 'generic': 24, 'specific': 169}, {'component': 14086, 'generic': 62, 'specific': 8}, {'component': 21099, 'generic': 140, 'specific': 49}, {'component': 31411, 'generic': 90, 'specific': 71}, {'component': 22556, 'generic': 103, 'specific': 51}, {'component': 18609, 'generic': 93, 'specific': 39}, {'component': 2964, 'generic': 202, 'specific': 42}, {'component': 23586, 'generic': 204, 'specific': 102}, {'component': 25117, 'generic': 249, 'specific': 91}, {'component': 24454, 'generic': 23, 'specific': 248}, {'component': 5312, 'generic': 83, 'specific': 195}, {'component': 46175, 'generic': 54, 'specific': 36}, {'component': 19386, 'generic': 64, 'specific': 20}, {'component': 34205, 'generic': 12, 'specific': 149}, {'component': 3612, 'generic': 185, 'specific': 129}, {'component': 61285, 'generic': 74, 'specific': 248}, {'component': 7925, 'generic': 228, 'specific': 88}, {'component': 54414, 'generic': 53, 'specific': 224}]
    
    assert dictify(msg.uptime) == 1657804265

    assert dictify(msg) == {'preamble': 85, 'msg_type': 65534, 'sender': 21510, 'length': 252, 'payload': 'Uv2xXwM8j1rpFdBi98vdxpzP2e6iiJoLcuyG6wyFCR6vkRpy1xSS+TY2hcFqutK3AIEF+OGVh38CGlhcCmdJA2dETLghzsKjex6XsJWsuOd25sioZG0K6QQ891LXphyKbi1i2vSzfmtcfF6dKrt8BmH3oLxueP7WbjPwpJMSSrJDBBtJvkCzkn2ZwC7KQvguKKGt8tYDCwF2RqI9shucKL9x5shICNf1Tjve+nMgIR7TqpFcnUsYqQY3PghrUowxs3paRxxYZzOxSF0nlAvKKiJczGYdYvlbhl8X+MAUU8NftDYkuktAFJ2FDJUcDrmBZe9K+PUe5FiO1DXg', 'crc': 42654, 'reporting_system': 64850, 'sbp_version': 24497, 'sequence': 1519336451, 'uptime': 1657804265, 'status': [{'component': 52215, 'generic': 221, 'specific': 198}, {'component': 53148, 'generic': 217, 'specific': 238}, {'component': 34978, 'generic': 154, 'specific': 11}, {'component': 60530, 'generic': 134, 'specific': 235}, {'component': 34060, 'generic': 9, 'specific': 30}, {'component': 37295, 'generic': 26, 'specific': 114}, {'component': 5335, 'generic': 146, 'specific': 249}, {'component': 13878, 'generic': 133, 'specific': 193}, {'component': 47722, 'generic': 210, 'specific': 183}, {'component': 33024, 'generic': 5, 'specific': 248}, {'component': 38369, 'generic': 135, 'specific': 127}, {'component': 6658, 'generic': 88, 'specific': 92}, {'component': 26378, 'generic': 73, 'specific': 3}, {'component': 17511, 'generic': 76, 'specific': 184}, {'component': 52769, 'generic': 194, 'specific': 163}, {'component': 7803, 'generic': 151, 'specific': 176}, {'component': 44181, 'generic': 184, 'specific': 231}, {'component': 58998, 'generic': 200, 'specific': 168}, {'component': 28004, 'generic': 10, 'specific': 233}, {'component': 15364, 'generic': 247, 'specific': 82}, {'component': 42711, 'generic': 28, 'specific': 138}, {'component': 11630, 'generic': 98, 'specific': 218}, {'component': 46068, 'generic': 126, 'specific': 107}, {'component': 31836, 'generic': 94, 'specific': 157}, {'component': 47914, 'generic': 124, 'specific': 6}, {'component': 63329, 'generic': 160, 'specific': 188}, {'component': 30830, 'generic': 254, 'specific': 214}, {'component': 13166, 'generic': 240, 'specific': 164}, {'component': 4755, 'generic': 74, 'specific': 178}, {'component': 1091, 'generic': 27, 'specific': 73}, {'component': 16574, 'generic': 179, 'specific': 146}, {'component': 39293, 'generic': 192, 'specific': 46}, {'component': 17098, 'generic': 248, 'specific': 46}, {'component': 41256, 'generic': 173, 'specific': 242}, {'component': 982, 'generic': 11, 'specific': 1}, {'component': 18038, 'generic': 162, 'specific': 61}, {'component': 7090, 'generic': 156, 'specific': 40}, {'component': 29119, 'generic': 230, 'specific': 200}, {'component': 2120, 'generic': 215, 'specific': 245}, {'component': 15182, 'generic': 222, 'specific': 250}, {'component': 8307, 'generic': 33, 'specific': 30}, {'component': 43731, 'generic': 145, 'specific': 92}, {'component': 19357, 'generic': 24, 'specific': 169}, {'component': 14086, 'generic': 62, 'specific': 8}, {'component': 21099, 'generic': 140, 'specific': 49}, {'component': 31411, 'generic': 90, 'specific': 71}, {'component': 22556, 'generic': 103, 'specific': 51}, {'component': 18609, 'generic': 93, 'specific': 39}, {'component': 2964, 'generic': 202, 'specific': 42}, {'component': 23586, 'generic': 204, 'specific': 102}, {'component': 25117, 'generic': 249, 'specific': 91}, {'component': 24454, 'generic': 23, 'specific': 248}, {'component': 5312, 'generic': 83, 'specific': 195}, {'component': 46175, 'generic': 54, 'specific': 36}, {'component': 19386, 'generic': 64, 'specific': 20}, {'component': 34205, 'generic': 12, 'specific': 149}, {'component': 3612, 'generic': 185, 'specific': 129}, {'component': 61285, 'generic': 74, 'specific': 248}, {'component': 7925, 'generic': 228, 'specific': 88}, {'component': 54414, 'generic': 53, 'specific': 224}]}