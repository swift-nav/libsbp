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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrection.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_stec_correction_1():
    buf = base64.standard_b64decode("Vf0FQgAmtAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgB3Mg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x05FD
    
    assert msg.sender == 0x0042
    
    assert msg.length == 38
    
    assert msg.payload == "tAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgA="
    
    assert msg.crc == 0x3277
    
    assert dictify(msg.header) == {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 1, 'update_interval': 10, 'sol_id': 0}
    
    assert dictify(msg.n_sats) == 2
    
    assert dictify(msg.ssr_iod_atmo) == 15
    
    assert dictify(msg.stec_sat_list) == [{'sv_id': {'sat_id': 1, 'constellation': 1}, 'stec_quality_indicator': 1, 'stec_coeff': [63, 62, 61, 60]}, {'sv_id': {'sat_id': 31, 'constellation': 15}, 'stec_quality_indicator': 5, 'stec_coeff': [63, 64, 65, 66]}]
    
    assert dictify(msg.tile_id) == 10
    
    assert dictify(msg.tile_set_id) == 1

    assert dictify(msg) == {'header': {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 1, 'update_interval': 10, 'sol_id': 0}, 'ssr_iod_atmo': 15, 'tile_set_id': 1, 'tile_id': 10, 'n_sats': 2, 'stec_sat_list': [{'sv_id': {'sat_id': 1, 'constellation': 1}, 'stec_quality_indicator': 1, 'stec_coeff': [63, 62, 61, 60]}, {'sv_id': {'sat_id': 31, 'constellation': 15}, 'stec_quality_indicator': 5, 'stec_coeff': [63, 64, 65, 66]}], 'preamble': 85, 'msg_type': 1533, 'sender': 66, 'length': 38, 'payload': 'tAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgA=', 'crc': 12919}