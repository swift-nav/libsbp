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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgDeviceMonitor.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_device_monitor_1():
    buf = base64.standard_b64decode("VbUAX0IK8djbA/0GFRioEs/p")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xe9cf
    assert payload.length == 10
    assert payload.msg_type == 0xb5
    assert payload.payload == "8djbA/0GFRioEg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x425f
    assert dictify(obj.payload.cpu_temperature) == snake_case_keys( 6165 )
    assert dictify(obj.payload.cpu_vaux) == snake_case_keys( 1789 )
    assert dictify(obj.payload.cpu_vint) == snake_case_keys( 987 )
    assert dictify(obj.payload.dev_vin) == snake_case_keys( -9999 )
    assert dictify(obj.payload.fe_temperature) == snake_case_keys( 4776 )

    assert dictify(payload) == snake_case_keys( {"cpu_vint": 987, "sender": 16991, "msg_type": 181, "cpu_vaux": 1789, "fe_temperature": 4776, "dev_vin": -9999, "crc": 59855, "length": 10, "cpu_temperature": 6165, "preamble": 85, "payload": "8djbA/0GFRioEg=="} )

def test_auto_check_sbp_piksi_msg_device_monitor_2():
    buf = base64.standard_b64decode("VbUAX0IK8djbA/4GGBioEqke")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x1ea9
    assert payload.length == 10
    assert payload.msg_type == 0xb5
    assert payload.payload == "8djbA/4GGBioEg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x425f
    assert dictify(obj.payload.cpu_temperature) == snake_case_keys( 6168 )
    assert dictify(obj.payload.cpu_vaux) == snake_case_keys( 1790 )
    assert dictify(obj.payload.cpu_vint) == snake_case_keys( 987 )
    assert dictify(obj.payload.dev_vin) == snake_case_keys( -9999 )
    assert dictify(obj.payload.fe_temperature) == snake_case_keys( 4776 )

    assert dictify(payload) == snake_case_keys( {"cpu_vint": 987, "sender": 16991, "msg_type": 181, "cpu_vaux": 1790, "fe_temperature": 4776, "dev_vin": -9999, "crc": 7849, "length": 10, "cpu_temperature": 6168, "preamble": 85, "payload": "8djbA/4GGBioEg=="} )

def test_auto_check_sbp_piksi_msg_device_monitor_3():
    buf = base64.standard_b64decode("VbUAX0IK8djbA/0GFhioEhNy")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x7213
    assert payload.length == 10
    assert payload.msg_type == 0xb5
    assert payload.payload == "8djbA/0GFhioEg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x425f
    assert dictify(obj.payload.cpu_temperature) == snake_case_keys( 6166 )
    assert dictify(obj.payload.cpu_vaux) == snake_case_keys( 1789 )
    assert dictify(obj.payload.cpu_vint) == snake_case_keys( 987 )
    assert dictify(obj.payload.dev_vin) == snake_case_keys( -9999 )
    assert dictify(obj.payload.fe_temperature) == snake_case_keys( 4776 )

    assert dictify(payload) == snake_case_keys( {"cpu_vint": 987, "sender": 16991, "msg_type": 181, "cpu_vaux": 1789, "fe_temperature": 4776, "dev_vin": -9999, "crc": 29203, "length": 10, "cpu_temperature": 6166, "preamble": 85, "payload": "8djbA/0GFhioEg=="} )

def test_auto_check_sbp_piksi_msg_device_monitor_4():
    buf = base64.standard_b64decode("VbUAX0IK8djaA/wGBhioEsdr")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x6bc7
    assert payload.length == 10
    assert payload.msg_type == 0xb5
    assert payload.payload == "8djaA/wGBhioEg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x425f
    assert dictify(obj.payload.cpu_temperature) == snake_case_keys( 6150 )
    assert dictify(obj.payload.cpu_vaux) == snake_case_keys( 1788 )
    assert dictify(obj.payload.cpu_vint) == snake_case_keys( 986 )
    assert dictify(obj.payload.dev_vin) == snake_case_keys( -9999 )
    assert dictify(obj.payload.fe_temperature) == snake_case_keys( 4776 )

    assert dictify(payload) == snake_case_keys( {"cpu_vint": 986, "sender": 16991, "msg_type": 181, "cpu_vaux": 1788, "fe_temperature": 4776, "dev_vin": -9999, "crc": 27591, "length": 10, "cpu_temperature": 6150, "preamble": 85, "payload": "8djaA/wGBhioEg=="} )

def test_auto_check_sbp_piksi_msg_device_monitor_5():
    buf = base64.standard_b64decode("VbUAX0IK8djcA/0G6xeoEvE/")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x3ff1
    assert payload.length == 10
    assert payload.msg_type == 0xb5
    assert payload.payload == "8djcA/0G6xeoEg=="
    assert payload.preamble == 0x55
    assert payload.sender == 0x425f
    assert dictify(obj.payload.cpu_temperature) == snake_case_keys( 6123 )
    assert dictify(obj.payload.cpu_vaux) == snake_case_keys( 1789 )
    assert dictify(obj.payload.cpu_vint) == snake_case_keys( 988 )
    assert dictify(obj.payload.dev_vin) == snake_case_keys( -9999 )
    assert dictify(obj.payload.fe_temperature) == snake_case_keys( 4776 )

    assert dictify(payload) == snake_case_keys( {"cpu_vint": 988, "sender": 16991, "msg_type": 181, "cpu_vaux": 1789, "fe_temperature": 4776, "dev_vin": -9999, "crc": 16369, "length": 10, "cpu_temperature": 6123, "preamble": 85, "payload": "8djcA/0G6xeoEg=="} )