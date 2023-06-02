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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCovGNSS.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_ecef_cov_gnss_1():
    buf = base64.standard_b64decode("VTQCABA2GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQZ7oHjza3RQ8gYjGu814pjwFpiO8erFzPBIEn2Y=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"tow":501867800,"x":-2694229.7079770807,"y":-4264073.427345817,"z":3890655.013186158,"cov_x_x":0.009699014946818352,"cov_x_y":0.009086096659302711,"cov_x_z":-0.006058753002434969,"cov_y_y":0.020321274176239967,"cov_y_z":-0.009988312609493732,"cov_z_z":0.01487385667860508,"n_sats":18,"flags":4,"preamble":85,"msg_type":564,"sender":4096,"payload":"GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQZ7oHjza3RQ8gYjGu814pjwFpiO8erFzPBIE","crc":26271,"length":54}
    assert parsed_dict['crc'] == 0x669f
    assert parsed_dict['length'] == 54
    assert parsed_dict['msg_type'] == 0x234
    assert parsed_dict['payload'] == "GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQZ7oHjza3RQ8gYjGu814pjwFpiO8erFzPBIE"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x1000
    assert dictify(obj.payload.cov_x_x) == snake_case_keys( 0.009699014946818352 )
    assert dictify(obj.payload.cov_x_y) == snake_case_keys( 0.009086096659302711 )
    assert dictify(obj.payload.cov_x_z) == snake_case_keys( -0.006058753002434969 )
    assert dictify(obj.payload.cov_y_y) == snake_case_keys( 0.020321274176239967 )
    assert dictify(obj.payload.cov_y_z) == snake_case_keys( -0.009988312609493732 )
    assert dictify(obj.payload.cov_z_z) == snake_case_keys( 0.01487385667860508 )
    assert dictify(obj.payload.flags) == snake_case_keys( 4 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 18 )
    assert dictify(obj.payload.tow) == snake_case_keys( 501867800 )
    assert dictify(obj.payload.x) == snake_case_keys( -2694229.7079770807 )
    assert dictify(obj.payload.y) == snake_case_keys( -4264073.427345817 )
    assert dictify(obj.payload.z) == snake_case_keys( 3890655.013186158 )

    assert parsed_dict == snake_case_keys(orig_dict)