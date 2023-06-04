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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinition.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_tile_definition_1():
    buf = base64.standard_b64decode("VfgFAAAhfzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAAzF4=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5ECC
    
    assert msg.length == 33
    
    assert msg.msg_type == 0x5F8
    
    assert msg.payload == "fzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x0
    
    assert dictify(msg.bitmask) == 1234567890
    
    assert dictify(msg.cols) == 6
    
    assert dictify(msg.corner_nw_lat) == 7354
    
    assert dictify(msg.corner_nw_lon) == -22725
    
    assert dictify(msg.iod_atmo) == 3
    
    assert dictify(msg.rows) == 6
    
    assert dictify(msg.sol_id) == 2
    
    assert dictify(msg.spacing_lat) == 100
    
    assert dictify(msg.spacing_lon) == 100
    
    assert dictify(msg.tile_id) == 5
    
    assert dictify(msg.tile_set_id) == 4
    
    assert dictify(msg.time) == {'tow': 604799, 'wn': 2222}
    
    assert dictify(msg.update_interval) == 1

    assert dictify(msg) == {'preamble': 85, 'msg_type': 1528, 'sender': 0, 'length': 33, 'payload': 'fzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAA', 'crc': 24268, 'time': {'tow': 604799, 'wn': 2222}, 'update_interval': 1, 'sol_id': 2, 'iod_atmo': 3, 'tile_set_id': 4, 'tile_id': 5, 'corner_nw_lat': 7354, 'corner_nw_lon': -22725, 'spacing_lat': 100, 'spacing_lon': 100, 'rows': 6, 'cols': 6, 'bitmask': 1234567890}