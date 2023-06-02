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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_baseline_ecef_1():
    buf = base64.standard_b64decode("VQsC04gUKPR6E5Zi7v++QBQA9qMJAAAADgDbvw==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xbfdb
    assert payload.length == 20
    assert payload.msg_type == 0x20b
    assert payload.payload == "KPR6E5Zi7v++QBQA9qMJAAAADgA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 14 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825000 )
    assert dictify(obj.payload.x) == snake_case_keys( -1154410 )
    assert dictify(obj.payload.y) == snake_case_keys( 1327294 )
    assert dictify(obj.payload.z) == snake_case_keys( 631798 )

    assert dictify(payload) == snake_case_keys( {"n_sats": 14, "sender": 35027, "msg_type": 523, "tow": 326825000, "crc": 49115, "length": 20, "flags": 0, "y": 1327294, "x": -1154410, "z": 631798, "preamble": 85, "payload": "KPR6E5Zi7v++QBQA9qMJAAAADgA=", "accuracy": 0} )

def test_auto_check_sbp_navigation_msg_baseline_ecef_2():
    buf = base64.standard_b64decode("VQsC04gUEPh6E0hj7v+/QRQAiqIJAAAADwDwTg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x4ef0
    assert payload.length == 20
    assert payload.msg_type == 0x20b
    assert payload.payload == "EPh6E0hj7v+/QRQAiqIJAAAADwA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826000 )
    assert dictify(obj.payload.x) == snake_case_keys( -1154232 )
    assert dictify(obj.payload.y) == snake_case_keys( 1327551 )
    assert dictify(obj.payload.z) == snake_case_keys( 631434 )

    assert dictify(payload) == snake_case_keys( {"n_sats": 15, "sender": 35027, "msg_type": 523, "tow": 326826000, "crc": 20208, "length": 20, "flags": 0, "y": 1327551, "x": -1154232, "z": 631434, "preamble": 85, "payload": "EPh6E0hj7v+/QRQAiqIJAAAADwA=", "accuracy": 0} )

def test_auto_check_sbp_navigation_msg_baseline_ecef_3():
    buf = base64.standard_b64decode("VQsC04gU+Pt6Eylj7v+1QRQAlKEJAAAADwAEhA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x8404
    assert payload.length == 20
    assert payload.msg_type == 0x20b
    assert payload.payload == "+Pt6Eylj7v+1QRQAlKEJAAAADwA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326827000 )
    assert dictify(obj.payload.x) == snake_case_keys( -1154263 )
    assert dictify(obj.payload.y) == snake_case_keys( 1327541 )
    assert dictify(obj.payload.z) == snake_case_keys( 631188 )

    assert dictify(payload) == snake_case_keys( {"n_sats": 15, "sender": 35027, "msg_type": 523, "tow": 326827000, "crc": 33796, "length": 20, "flags": 0, "y": 1327541, "x": -1154263, "z": 631188, "preamble": 85, "payload": "+Pt6Eylj7v+1QRQAlKEJAAAADwA=", "accuracy": 0} )

def test_auto_check_sbp_navigation_msg_baseline_ecef_4():
    buf = base64.standard_b64decode("VQsC04gU4P96E7xh7v9RQBQAQaAJAAAADwBDXg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x5e43
    assert payload.length == 20
    assert payload.msg_type == 0x20b
    assert payload.payload == "4P96E7xh7v9RQBQAQaAJAAAADwA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326828000 )
    assert dictify(obj.payload.x) == snake_case_keys( -1154628 )
    assert dictify(obj.payload.y) == snake_case_keys( 1327185 )
    assert dictify(obj.payload.z) == snake_case_keys( 630849 )

    assert dictify(payload) == snake_case_keys( {"n_sats": 15, "sender": 35027, "msg_type": 523, "tow": 326828000, "crc": 24131, "length": 20, "flags": 0, "y": 1327185, "x": -1154628, "z": 630849, "preamble": 85, "payload": "4P96E7xh7v9RQBQAQaAJAAAADwA=", "accuracy": 0} )

def test_auto_check_sbp_navigation_msg_baseline_ecef_5():
    buf = base64.standard_b64decode("VQsC04gUyAN7E71g7v9dPxQAYp8JAAAADwBqXg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x5e6a
    assert payload.length == 20
    assert payload.msg_type == 0x20b
    assert payload.payload == "yAN7E71g7v9dPxQAYp8JAAAADwA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326829000 )
    assert dictify(obj.payload.x) == snake_case_keys( -1154883 )
    assert dictify(obj.payload.y) == snake_case_keys( 1326941 )
    assert dictify(obj.payload.z) == snake_case_keys( 630626 )

    assert dictify(payload) == snake_case_keys( {"n_sats": 15, "sender": 35027, "msg_type": 523, "tow": 326829000, "crc": 24170, "length": 20, "flags": 0, "y": 1326941, "x": -1154883, "z": 630626, "preamble": 85, "payload": "yAN7E71g7v9dPxQAYp8JAAAADwA=", "accuracy": 0} )