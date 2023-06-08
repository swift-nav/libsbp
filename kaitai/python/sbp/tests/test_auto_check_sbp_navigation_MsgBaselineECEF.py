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

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_baseline_ecef_1():
    buf = base64.standard_b64decode("VQsC04gUKPR6E5Zi7v++QBQA9qMJAAAADgDbvw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xbfdb
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x20b
    
    assert msg.payload == "KPR6E5Zi7v++QBQA9qMJAAAADgA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 14
    
    assert dictify(msg.tow) == 326825000
    
    assert dictify(msg.x) == -1154410
    
    assert dictify(msg.y) == 1327294
    
    assert dictify(msg.z) == 631798

    assert dictify(msg) == {'n_sats': 14, 'sender': 35027, 'msg_type': 523, 'tow': 326825000, 'crc': 49115, 'length': 20, 'flags': 0, 'y': 1327294, 'x': -1154410, 'z': 631798, 'preamble': 85, 'payload': 'KPR6E5Zi7v++QBQA9qMJAAAADgA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_2():
    buf = base64.standard_b64decode("VQsC04gUEPh6E0hj7v+/QRQAiqIJAAAADwDwTg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4ef0
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x20b
    
    assert msg.payload == "EPh6E0hj7v+/QRQAiqIJAAAADwA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326826000
    
    assert dictify(msg.x) == -1154232
    
    assert dictify(msg.y) == 1327551
    
    assert dictify(msg.z) == 631434

    assert dictify(msg) == {'n_sats': 15, 'sender': 35027, 'msg_type': 523, 'tow': 326826000, 'crc': 20208, 'length': 20, 'flags': 0, 'y': 1327551, 'x': -1154232, 'z': 631434, 'preamble': 85, 'payload': 'EPh6E0hj7v+/QRQAiqIJAAAADwA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_3():
    buf = base64.standard_b64decode("VQsC04gU+Pt6Eylj7v+1QRQAlKEJAAAADwAEhA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8404
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x20b
    
    assert msg.payload == "+Pt6Eylj7v+1QRQAlKEJAAAADwA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326827000
    
    assert dictify(msg.x) == -1154263
    
    assert dictify(msg.y) == 1327541
    
    assert dictify(msg.z) == 631188

    assert dictify(msg) == {'n_sats': 15, 'sender': 35027, 'msg_type': 523, 'tow': 326827000, 'crc': 33796, 'length': 20, 'flags': 0, 'y': 1327541, 'x': -1154263, 'z': 631188, 'preamble': 85, 'payload': '+Pt6Eylj7v+1QRQAlKEJAAAADwA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_4():
    buf = base64.standard_b64decode("VQsC04gU4P96E7xh7v9RQBQAQaAJAAAADwBDXg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5e43
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x20b
    
    assert msg.payload == "4P96E7xh7v9RQBQAQaAJAAAADwA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326828000
    
    assert dictify(msg.x) == -1154628
    
    assert dictify(msg.y) == 1327185
    
    assert dictify(msg.z) == 630849

    assert dictify(msg) == {'n_sats': 15, 'sender': 35027, 'msg_type': 523, 'tow': 326828000, 'crc': 24131, 'length': 20, 'flags': 0, 'y': 1327185, 'x': -1154628, 'z': 630849, 'preamble': 85, 'payload': '4P96E7xh7v9RQBQAQaAJAAAADwA=', 'accuracy': 0}

def test_auto_check_sbp_navigation_msg_baseline_ecef_5():
    buf = base64.standard_b64decode("VQsC04gUyAN7E71g7v9dPxQAYp8JAAAADwBqXg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5e6a
    
    assert msg.length == 20
    
    assert msg.msg_type == 0x20b
    
    assert msg.payload == "yAN7E71g7v9dPxQAYp8JAAAADwA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88d3
    
    assert dictify(msg.accuracy) == 0
    
    assert dictify(msg.flags) == 0
    
    assert dictify(msg.n_sats) == 15
    
    assert dictify(msg.tow) == 326829000
    
    assert dictify(msg.x) == -1154883
    
    assert dictify(msg.y) == 1326941
    
    assert dictify(msg.z) == 630626

    assert dictify(msg) == {'n_sats': 15, 'sender': 35027, 'msg_type': 523, 'tow': 326829000, 'crc': 24170, 'length': 20, 'flags': 0, 'y': 1326941, 'x': -1154883, 'z': 630626, 'preamble': 85, 'payload': 'yAN7E71g7v9dPxQAYp8JAAAADwA=', 'accuracy': 0}