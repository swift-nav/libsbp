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
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_tile_definition_1():
    buf = base64.standard_b64decode("VfgFAAAhfzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAAzF4=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x5ECC
    assert payload.length == 33
    assert payload.msg_type == 0x5F8
    assert payload.payload == "fzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAA"
    assert payload.preamble == 0x55
    assert payload.sender == 0x0
    assert dictify(obj.payload.bitmask) == snake_case_keys( 1234567890 )
    assert dictify(obj.payload.cols) == snake_case_keys( 6 )
    assert dictify(obj.payload.corner_nw_lat) == snake_case_keys( 7354 )
    assert dictify(obj.payload.corner_nw_lon) == snake_case_keys( -22725 )
    assert dictify(obj.payload.iod_atmo) == snake_case_keys( 3 )
    assert dictify(obj.payload.rows) == snake_case_keys( 6 )
    assert dictify(obj.payload.sol_id) == snake_case_keys( 2 )
    assert dictify(obj.payload.spacing_lat) == snake_case_keys( 100 )
    assert dictify(obj.payload.spacing_lon) == snake_case_keys( 100 )
    assert dictify(obj.payload.tile_id) == snake_case_keys( 5 )
    assert dictify(obj.payload.tile_set_id) == snake_case_keys( 4 )
    assert dictify(obj.payload.time) == snake_case_keys( {'tow': 604799, 'wn': 2222} )
    assert dictify(obj.payload.update_interval) == snake_case_keys( 1 )

    assert dictify(payload) == snake_case_keys( {"preamble": 85, "msg_type": 1528, "sender": 0, "length": 33, "payload": "fzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAA", "crc": 24268, "time": {"tow": 604799, "wn": 2222}, "update_interval": 1, "sol_id": 2, "iod_atmo": 3, "tile_set_id": 4, "tile_id": 5, "corner_nw_lat": 7354, "corner_nw_lon": -22725, "spacing_lat": 100, "spacing_lon": 100, "rows": 6, "cols": 6, "bitmask": 1234567890} )