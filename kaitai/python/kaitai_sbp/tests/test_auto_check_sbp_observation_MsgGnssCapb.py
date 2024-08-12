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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGnssCapb.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_gnss_capb_1():
    buf = base64.standard_b64decode("VZYAewBusM8GAGoIGqtQQAAAAABRrZAuAAAAANGLXWwAAAAA/MzIAM1cHjHwyxUY1F22IAAAAABpIMAbAAAAAChL+nIAAAAAd5N7UQAAAABVWQQCAAAAAOl0iRYAAAAAx23bC92r+FIAAAAA/D7dHAAAAACjWg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5aa3
    
    assert msg.length == 110
    
    assert msg.msg_type == 0x96
    
    assert msg.payload == "sM8GAGoIGqtQQAAAAABRrZAuAAAAANGLXWwAAAAA/MzIAM1cHjHwyxUY1F22IAAAAABpIMAbAAAAAChL+nIAAAAAd5N7UQAAAABVWQQCAAAAAOl0iRYAAAAAx23bC92r+FIAAAAA/D7dHAAAAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x007b
    
    assert dictify(msg.gc) == {'bds_active': 1929005864, 'bds_b2': 33839445, 'bds_b2a': 378107113, 'bds_d2nav': 1367053175, 'gal_active': 1392028637, 'gal_e5': 484261628, 'glo_active': 13159676, 'glo_l2of': 824073421, 'glo_l3': 404081648, 'gps_active': 1079028506, 'gps_l2c': 781233489, 'gps_l5': 1818069969, 'qzss_active': 198929863, 'sbas_active': 548822484, 'sbas_l5': 465576041}
    
    assert dictify(msg.t_nmct) == {'tow': 446384, 'wn': 2154}

    assert dictify(msg) == {'crc': 23203, 'length': 110, 'msg_type': 150, 'payload': 'sM8GAGoIGqtQQAAAAABRrZAuAAAAANGLXWwAAAAA/MzIAM1cHjHwyxUY1F22IAAAAABpIMAbAAAAAChL+nIAAAAAd5N7UQAAAABVWQQCAAAAAOl0iRYAAAAAx23bC92r+FIAAAAA/D7dHAAAAAA=', 'preamble': 85, 'sender': 123, 't_nmct': {'tow': 446384, 'wn': 2154}, 'gc': {'gps_active': 1079028506, 'gps_l2c': 781233489, 'gps_l5': 1818069969, 'glo_active': 13159676, 'glo_l2of': 824073421, 'glo_l3': 404081648, 'sbas_active': 548822484, 'sbas_l5': 465576041, 'bds_active': 1929005864, 'bds_d2nav': 1367053175, 'bds_b2': 33839445, 'bds_b2a': 378107113, 'qzss_active': 198929863, 'gal_active': 1392028637, 'gal_e5': 484261628}}