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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLH.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_pos_llh_1():
    buf = base64.standard_b64decode("VQoC04giKPR6E8lqm7oqoEJAqG0a4QB4XsCCZu3mKzY8QAAAAAAOAq+i")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xa2af
    assert payload.length == 34
    assert payload.msg_type == 0x20a
    assert payload.payload == "KPR6E8lqm7oqoEJAqG0a4QB4XsCCZu3mKzY8QAAAAAAOAg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.height) == snake_case_keys( 28.21160739227208 )
    assert dictify(obj.payload.lat) == snake_case_keys( 37.25130398358085 )
    assert dictify(obj.payload.lon) == snake_case_keys( -121.87505366879361 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 14 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326825000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "n_sats": 14, "sender": 35027, "msg_type": 522, "lon": -121.87505366879361, "tow": 326825000, "height": 28.21160739227208, "crc": 41647, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.25130398358085, "preamble": 85, "payload": "KPR6E8lqm7oqoEJAqG0a4QB4XsCCZu3mKzY8QAAAAAAOAg=="} )

def test_auto_check_sbp_navigation_msg_pos_llh_2():
    buf = base64.standard_b64decode("VQoC04giEPh6EzSx+7IqoEJA7RZh4AB4XsBrvG1a9707QAAAAAAPAiax")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xb126
    assert payload.length == 34
    assert payload.msg_type == 0x20a
    assert payload.payload == "EPh6EzSx+7IqoEJA7RZh4AB4XsBrvG1a9707QAAAAAAPAg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.height) == snake_case_keys( 27.742055560866373 )
    assert dictify(obj.payload.lat) == snake_case_keys( 37.251303074738104 )
    assert dictify(obj.payload.lon) == snake_case_keys( -121.87505349618341 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326826000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "n_sats": 15, "sender": 35027, "msg_type": 522, "lon": -121.87505349618341, "tow": 326826000, "height": 27.742055560866373, "crc": 45350, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.251303074738104, "preamble": 85, "payload": "EPh6EzSx+7IqoEJA7RZh4AB4XsBrvG1a9707QAAAAAAPAg=="} )

def test_auto_check_sbp_navigation_msg_pos_llh_3():
    buf = base64.standard_b64decode("VQoC04gi+Pt6E4dCCaMqoEJAkghj4QB4XsAttY/bHJ07QAAAAAAPAjMo")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x2833
    assert payload.length == 34
    assert payload.msg_type == 0x20a
    assert payload.payload == "+Pt6E4dCCaMqoEJAkghj4QB4XsAttY/bHJ07QAAAAAAPAg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.height) == snake_case_keys( 27.613721582970516 )
    assert dictify(obj.payload.lat) == snake_case_keys( 37.25130117370741 )
    assert dictify(obj.payload.lon) == snake_case_keys( -121.87505373641241 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326827000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "n_sats": 15, "sender": 35027, "msg_type": 522, "lon": -121.87505373641241, "tow": 326827000, "height": 27.613721582970516, "crc": 10291, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.25130117370741, "preamble": 85, "payload": "+Pt6E4dCCaMqoEJAkghj4QB4XsAttY/bHJ07QAAAAAAPAg=="} )

def test_auto_check_sbp_navigation_msg_pos_llh_4():
    buf = base64.standard_b64decode("VQoC04gi4P96ExIs/XcqoEJAMG0n5wB4XsC5TDARd807QAAAAAAPAgzC")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xc20c
    assert payload.length == 34
    assert payload.msg_type == 0x20a
    assert payload.payload == "4P96ExIs/XcqoEJAMG0n5wB4XsC5TDARd807QAAAAAAPAg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.height) == snake_case_keys( 27.80259807042305 )
    assert dictify(obj.payload.lat) == snake_case_keys( 37.251296042079176 )
    assert dictify(obj.payload.lon) == snake_case_keys( -121.87505511141057 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326828000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "n_sats": 15, "sender": 35027, "msg_type": 522, "lon": -121.87505511141057, "tow": 326828000, "height": 27.80259807042305, "crc": 49676, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.251296042079176, "preamble": 85, "payload": "4P96ExIs/XcqoEJAMG0n5wB4XsC5TDARd807QAAAAAAPAg=="} )

def test_auto_check_sbp_navigation_msg_pos_llh_5():
    buf = base64.standard_b64decode("VQoC04giyAN7E+Ht7loqoEJAO49G6wB4XsBlavngg/A7QAAAAAAPAiJn")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x6722
    assert payload.length == 34
    assert payload.msg_type == 0x20a
    assert payload.payload == "yAN7E+Ht7loqoEJAO49G6wB4XsBlavngg/A7QAAAAAAPAg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x88d3
    assert dictify(obj.payload.flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.h_accuracy) == snake_case_keys( 0 )
    assert dictify(obj.payload.height) == snake_case_keys( 27.939512310879213 )
    assert dictify(obj.payload.lat) == snake_case_keys( 37.251292578377395 )
    assert dictify(obj.payload.lon) == snake_case_keys( -121.87505609407974 )
    assert dictify(obj.payload.n_sats) == snake_case_keys( 15 )
    assert dictify(obj.payload.tow) == snake_case_keys( 326829000 )
    assert dictify(obj.payload.v_accuracy) == snake_case_keys( 0 )

    assert dictify(payload) == snake_case_keys( {"v_accuracy": 0, "n_sats": 15, "sender": 35027, "msg_type": 522, "lon": -121.87505609407974, "tow": 326829000, "height": 27.939512310879213, "crc": 26402, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.251292578377395, "preamble": 85, "payload": "yAN7E+Ht7loqoEJAO49G6wB4XsBlavngg/A7QAAAAAAPAg=="} )