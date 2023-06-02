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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGloBiases.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_glo_biases_1():
    buf = base64.standard_b64decode("VXUAAAAJAAAAAAAAAAAATdM=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xd34d
    assert payload.length == 9
    assert payload.payload == "AAAAAAAAAAAA"
    assert payload.msg_type == 0x75
    assert payload.preamble == 0x55
    assert payload.sender == 0
    assert dictify(obj.payload.l1ca_bias) == snake_case_keys( 0 )
    assert dictify(obj.payload.l1p_bias) == snake_case_keys( 0 )
    assert dictify(obj.payload.l2ca_bias) == snake_case_keys( 0 )
    assert dictify(obj.payload.l2p_bias) == snake_case_keys( 0 )
    assert dictify(obj.payload.mask) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"mask":0,"l1ca_bias":0,"l1p_bias":0,"l2ca_bias":0,"l2p_bias":0,"preamble":85,"msg_type":117,"sender":0,"payload":"AAAAAAAAAAAA","crc":54093,"length":9} )