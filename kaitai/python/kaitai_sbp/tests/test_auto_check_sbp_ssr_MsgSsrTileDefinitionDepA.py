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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinitionDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_tile_definition_dep_a_1():
    buf = base64.standard_b64decode("VfYFyIUYOb6y9wi5CbWi8EET/48Vv+/NqwAAAAAAQZo=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9a41
    
    assert msg.length == 24
    
    assert msg.msg_type == 0x5f6
    
    assert msg.payload == "Ob6y9wi5CbWi8EET/48Vv+/NqwAAAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x85c8
    
    assert dictify(msg.bitmask) == 11259375
    
    assert dictify(msg.cols) == 48917
    
    assert dictify(msg.corner_nw_lat) == -18168
    
    assert dictify(msg.corner_nw_lon) == -19191
    
    assert dictify(msg.rows) == 36863
    
    assert dictify(msg.spacing_lat) == 61602
    
    assert dictify(msg.spacing_lon) == 4929
    
    assert dictify(msg.tile_id) == 63410
    
    assert dictify(msg.tile_set_id) == 48697

    assert dictify(msg) == {'crc': 39489, 'length': 24, 'msg_type': 1526, 'payload': 'Ob6y9wi5CbWi8EET/48Vv+/NqwAAAAAA', 'preamble': 85, 'sender': 34248, 'tile_set_id': 48697, 'tile_id': 63410, 'corner_nw_lat': -18168, 'corner_nw_lon': -19191, 'spacing_lat': 61602, 'spacing_lon': 4929, 'rows': 36863, 'cols': 48917, 'bitmask': 11259375}