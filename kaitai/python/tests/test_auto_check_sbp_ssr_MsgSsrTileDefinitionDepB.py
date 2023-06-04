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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinitionDepB.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_tile_definition_dep_b_1():
    buf = base64.standard_b64decode("VfcFQgAZHwABAAIABAAIABAAIABAAIDSApZJAAAAANZH")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x05F7
    
    assert msg.sender == 0x0042
    
    assert msg.length == 25
    
    assert msg.payload == "HwABAAIABAAIABAAIABAAIDSApZJAAAAAA=="
    
    assert msg.crc == 0x47D6
    
    assert dictify(msg.bitmask) == 1234567890
    
    assert dictify(msg.cols) == 32768
    
    assert dictify(msg.corner_nw_lat) == 1024
    
    assert dictify(msg.corner_nw_lon) == 2048
    
    assert dictify(msg.rows) == 16384
    
    assert dictify(msg.spacing_lat) == 4096
    
    assert dictify(msg.spacing_lon) == 8192
    
    assert dictify(msg.ssr_sol_id) == 31
    
    assert dictify(msg.tile_id) == 512
    
    assert dictify(msg.tile_set_id) == 256

    assert dictify(msg) == {'ssr_sol_id': 31, 'tile_set_id': 256, 'tile_id': 512, 'corner_nw_lat': 1024, 'corner_nw_lon': 2048, 'spacing_lat': 4096, 'spacing_lon': 8192, 'rows': 16384, 'cols': 32768, 'bitmask': 1234567890, 'preamble': 85, 'msg_type': 1527, 'sender': 66, 'length': 25, 'payload': 'HwABAAIABAAIABAAIABAAIDSApZJAAAAAA==', 'crc': 18390}