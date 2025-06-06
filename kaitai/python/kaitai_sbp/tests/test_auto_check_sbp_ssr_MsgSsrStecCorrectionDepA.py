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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_stec_correction_dep_a_1():
    buf = base64.standard_b64decode("VesFJwf8RlHE6Lkrk3snBH4Tb2H4gtnZajoMQearUV9WECdU5NDJUdtjyz22Qn3LA8EsZNx9PBVd2veez12Bhg7RMA7XmZSTSOG07M3JIQP2zBMDYgTCv/ZM2x+/cU+xD/shE2A2OpLSZPlIFaHTxhXub2sk4+HVA0fzP0HsXE0AqQ+2BfC0CXpW6AZnaP69UW4CMcpU2DcytQV7UDH04Lx9pOY4QnyoO4tqdjO72L+eTVw6/YSWpQmavdo90QFStcQXNbZwwM6nnfQjAb3ZPVhhyclK+9kOaLg2NEruCoEWsuJtWJ0exK8aTCJ03JroDLP0D5vEykhGcwrWcif1HO1EiJs=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9b88
    
    assert msg.length == 252
    
    assert msg.msg_type == 0x5eb
    
    assert msg.payload == "RlHE6Lkrk3snBH4Tb2H4gtnZajoMQearUV9WECdU5NDJUdtjyz22Qn3LA8EsZNx9PBVd2veez12Bhg7RMA7XmZSTSOG07M3JIQP2zBMDYgTCv/ZM2x+/cU+xD/shE2A2OpLSZPlIFaHTxhXub2sk4+HVA0fzP0HsXE0AqQ+2BfC0CXpW6AZnaP69UW4CMcpU2DcytQV7UDH04Lx9pOY4QnyoO4tqdjO72L+eTVw6/YSWpQmavdo90QFStcQXNbZwwM6nnfQjAb3ZPVhhyclK+9kOaLg2NEruCoEWsuJtWJ0exK8aTCJ03JroDLP0D5vEykhGcwrWcif1HO1E"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x0727
    
    assert dictify(msg.header) == {'iod_atmo': 4, 'num_msgs': 147, 'seq_num': 123, 'time': {'tow': 3905179974, 'wn': 11193}, 'update_interval': 39}
    
    assert dictify(msg.stec_sat_list) == [{'stec_coeff': [-1951, -9854, 27353, 3130], 'stec_quality_indicator': 111, 'sv_id': {'constellation': 19, 'sat_id': 126}}, {'stec_coeff': [24401, 4182, 21543, -12060], 'stec_quality_indicator': 171, 'sv_id': {'constellation': 230, 'sat_id': 65}}, {'stec_coeff': [-13469, -18883, 32066, 971], 'stec_quality_indicator': 219, 'sv_id': {'constellation': 81, 'sat_id': 201}}, {'stec_coeff': [32220, 5436, -9635, -24841], 'stec_quality_indicator': 100, 'sv_id': {'constellation': 44, 'sat_id': 193}}, {'stec_coeff': [3718, 12497, -10482, -27495], 'stec_quality_indicator': 129, 'sv_id': {'constellation': 93, 'sat_id': 207}}, {'stec_coeff': [-4940, -13875, 801, -13066], 'stec_quality_indicator': 225, 'sv_id': {'constellation': 72, 'sat_id': 147}}, {'stec_coeff': [-15868, -2369, -9396, -16609], 'stec_quality_indicator': 98, 'sv_id': {'constellation': 3, 'sat_id': 19}}, {'stec_coeff': [-1265, 4897, 13920, -28102], 'stec_quality_indicator': 177, 'sv_id': {'constellation': 79, 'sat_id': 113}}, {'stec_coeff': [5448, -11359, 5574, 28654], 'stec_quality_indicator': 249, 'sv_id': {'constellation': 100, 'sat_id': 210}}, {'stec_coeff': [-10783, 18179, 16371, -5055], 'stec_quality_indicator': 227, 'sv_id': {'constellation': 36, 'sat_id': 107}}, {'stec_coeff': [4009, 1462, -19216, 31241], 'stec_quality_indicator': 0, 'sv_id': {'constellation': 77, 'sat_id': 92}}, {'stec_coeff': [26727, -16898, 28241, 12546], 'stec_quality_indicator': 6, 'sv_id': {'constellation': 232, 'sat_id': 86}}, {'stec_coeff': [12855, 1461, 20603, -3023], 'stec_quality_indicator': 216, 'sv_id': {'constellation': 84, 'sat_id': 202}}, {'stec_coeff': [-6492, 16952, -22404, -29893], 'stec_quality_indicator': 125, 'sv_id': {'constellation': 188, 'sat_id': 224}}, {'stec_coeff': [-10053, -24897, 23629, -710], 'stec_quality_indicator': 51, 'sv_id': {'constellation': 118, 'sat_id': 106}}, {'stec_coeff': [-26103, -9539, -11971, 20993], 'stec_quality_indicator': 165, 'sv_id': {'constellation': 150, 'sat_id': 132}}, {'stec_coeff': [-18891, -16272, -22578, -2915], 'stec_quality_indicator': 23, 'sv_id': {'constellation': 196, 'sat_id': 181}}, {'stec_coeff': [15833, 24920, -13879, -1206], 'stec_quality_indicator': 189, 'sv_id': {'constellation': 1, 'sat_id': 35}}, {'stec_coeff': [14008, 18996, 2798, 5761], 'stec_quality_indicator': 104, 'sv_id': {'constellation': 14, 'sat_id': 217}}, {'stec_coeff': [-25256, -15330, 6831, 8780], 'stec_quality_indicator': 109, 'sv_id': {'constellation': 226, 'sat_id': 178}}, {'stec_coeff': [3304, -2893, -25841, -13628], 'stec_quality_indicator': 154, 'sv_id': {'constellation': 220, 'sat_id': 116}}, {'stec_coeff': [-10742, 10098, 7413, 17645], 'stec_quality_indicator': 115, 'sv_id': {'constellation': 70, 'sat_id': 72}}]

    assert dictify(msg) == {'crc': 39816, 'length': 252, 'msg_type': 1515, 'payload': 'RlHE6Lkrk3snBH4Tb2H4gtnZajoMQearUV9WECdU5NDJUdtjyz22Qn3LA8EsZNx9PBVd2veez12Bhg7RMA7XmZSTSOG07M3JIQP2zBMDYgTCv/ZM2x+/cU+xD/shE2A2OpLSZPlIFaHTxhXub2sk4+HVA0fzP0HsXE0AqQ+2BfC0CXpW6AZnaP69UW4CMcpU2DcytQV7UDH04Lx9pOY4QnyoO4tqdjO72L+eTVw6/YSWpQmavdo90QFStcQXNbZwwM6nnfQjAb3ZPVhhyclK+9kOaLg2NEruCoEWsuJtWJ0exK8aTCJ03JroDLP0D5vEykhGcwrWcif1HO1E', 'preamble': 85, 'sender': 1831, 'header': {'time': {'tow': 3905179974, 'wn': 11193}, 'num_msgs': 147, 'seq_num': 123, 'update_interval': 39, 'iod_atmo': 4}, 'stec_sat_list': [{'sv_id': {'sat_id': 126, 'constellation': 19}, 'stec_quality_indicator': 111, 'stec_coeff': [-1951, -9854, 27353, 3130]}, {'sv_id': {'sat_id': 65, 'constellation': 230}, 'stec_quality_indicator': 171, 'stec_coeff': [24401, 4182, 21543, -12060]}, {'sv_id': {'sat_id': 201, 'constellation': 81}, 'stec_quality_indicator': 219, 'stec_coeff': [-13469, -18883, 32066, 971]}, {'sv_id': {'sat_id': 193, 'constellation': 44}, 'stec_quality_indicator': 100, 'stec_coeff': [32220, 5436, -9635, -24841]}, {'sv_id': {'sat_id': 207, 'constellation': 93}, 'stec_quality_indicator': 129, 'stec_coeff': [3718, 12497, -10482, -27495]}, {'sv_id': {'sat_id': 147, 'constellation': 72}, 'stec_quality_indicator': 225, 'stec_coeff': [-4940, -13875, 801, -13066]}, {'sv_id': {'sat_id': 19, 'constellation': 3}, 'stec_quality_indicator': 98, 'stec_coeff': [-15868, -2369, -9396, -16609]}, {'sv_id': {'sat_id': 113, 'constellation': 79}, 'stec_quality_indicator': 177, 'stec_coeff': [-1265, 4897, 13920, -28102]}, {'sv_id': {'sat_id': 210, 'constellation': 100}, 'stec_quality_indicator': 249, 'stec_coeff': [5448, -11359, 5574, 28654]}, {'sv_id': {'sat_id': 107, 'constellation': 36}, 'stec_quality_indicator': 227, 'stec_coeff': [-10783, 18179, 16371, -5055]}, {'sv_id': {'sat_id': 92, 'constellation': 77}, 'stec_quality_indicator': 0, 'stec_coeff': [4009, 1462, -19216, 31241]}, {'sv_id': {'sat_id': 86, 'constellation': 232}, 'stec_quality_indicator': 6, 'stec_coeff': [26727, -16898, 28241, 12546]}, {'sv_id': {'sat_id': 202, 'constellation': 84}, 'stec_quality_indicator': 216, 'stec_coeff': [12855, 1461, 20603, -3023]}, {'sv_id': {'sat_id': 224, 'constellation': 188}, 'stec_quality_indicator': 125, 'stec_coeff': [-6492, 16952, -22404, -29893]}, {'sv_id': {'sat_id': 106, 'constellation': 118}, 'stec_quality_indicator': 51, 'stec_coeff': [-10053, -24897, 23629, -710]}, {'sv_id': {'sat_id': 132, 'constellation': 150}, 'stec_quality_indicator': 165, 'stec_coeff': [-26103, -9539, -11971, 20993]}, {'sv_id': {'sat_id': 181, 'constellation': 196}, 'stec_quality_indicator': 23, 'stec_coeff': [-18891, -16272, -22578, -2915]}, {'sv_id': {'sat_id': 35, 'constellation': 1}, 'stec_quality_indicator': 189, 'stec_coeff': [15833, 24920, -13879, -1206]}, {'sv_id': {'sat_id': 217, 'constellation': 14}, 'stec_quality_indicator': 104, 'stec_coeff': [14008, 18996, 2798, 5761]}, {'sv_id': {'sat_id': 178, 'constellation': 226}, 'stec_quality_indicator': 109, 'stec_coeff': [-25256, -15330, 6831, 8780]}, {'sv_id': {'sat_id': 116, 'constellation': 220}, 'stec_quality_indicator': 154, 'stec_coeff': [3304, -2893, -25841, -13628]}, {'sv_id': {'sat_id': 72, 'constellation': 70}, 'stec_quality_indicator': 115, 'stec_coeff': [-10742, 10098, 7413, 17645]}]}
