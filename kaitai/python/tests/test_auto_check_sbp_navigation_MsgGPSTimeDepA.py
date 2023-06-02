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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_1():
    buf = base64.standard_b64decode("VQAB9tcL+wZ4LicAAAAAAACFJA==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 55286, "msg_type": 256, "wn": 1787, "tow": 2567800, "crc": 9349, "length": 11, "flags": 0, "ns_residual": 0, "preamble": 85, "payload": "+wZ4LicAAAAAAAA="}
    assert parsed_dict['crc'] == 0x2485
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "+wZ4LicAAAAAAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567800 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1787 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_2():
    buf = base64.standard_b64decode("VQAB9tcL+wbcLicAAAAAAAAkoA==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 55286, "msg_type": 256, "wn": 1787, "tow": 2567900, "crc": 40996, "length": 11, "flags": 0, "ns_residual": 0, "preamble": 85, "payload": "+wbcLicAAAAAAAA="}
    assert parsed_dict['crc'] == 0xa024
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "+wbcLicAAAAAAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2567900 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1787 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_3():
    buf = base64.standard_b64decode("VQAB9tcL+wZALycAAAAAAACrvg==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 55286, "msg_type": 256, "wn": 1787, "tow": 2568000, "crc": 48811, "length": 11, "flags": 0, "ns_residual": 0, "preamble": 85, "payload": "+wZALycAAAAAAAA="}
    assert parsed_dict['crc'] == 0xbeab
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "+wZALycAAAAAAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2568000 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1787 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_4():
    buf = base64.standard_b64decode("VQAB9tcL+wakLycAAAAAAADTZQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 55286, "msg_type": 256, "wn": 1787, "tow": 2568100, "crc": 26067, "length": 11, "flags": 0, "ns_residual": 0, "preamble": 85, "payload": "+wakLycAAAAAAAA="}
    assert parsed_dict['crc'] == 0x65d3
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "+wakLycAAAAAAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2568100 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1787 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_5():
    buf = base64.standard_b64decode("VQAB9tcL+wYIMCcAAAAAAAD7LA==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 55286, "msg_type": 256, "wn": 1787, "tow": 2568200, "crc": 11515, "length": 11, "flags": 0, "ns_residual": 0, "preamble": 85, "payload": "+wYIMCcAAAAAAAA="}
    assert parsed_dict['crc'] == 0x2cfb
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "+wYIMCcAAAAAAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 2568200 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1787 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_6():
    buf = base64.standard_b64decode("VQABwwQLLgfUnUMYb5P8/wDXvg==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 256, "wn": 1838, "tow": 407084500, "crc": 48855, "length": 11, "flags": 0, "ns_residual": -224401, "preamble": 85, "payload": "LgfUnUMYb5P8/wA="}
    assert parsed_dict['crc'] == 0xbed7
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "LgfUnUMYb5P8/wA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( -224401 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084500 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1838 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_7():
    buf = base64.standard_b64decode("VQABwwQLLgc4nkMYbWcDAACGWQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 256, "wn": 1838, "tow": 407084600, "crc": 22918, "length": 11, "flags": 0, "ns_residual": 223085, "preamble": 85, "payload": "Lgc4nkMYbWcDAAA="}
    assert parsed_dict['crc'] == 0x5986
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "Lgc4nkMYbWcDAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 223085 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084600 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1838 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_8():
    buf = base64.standard_b64decode("VQABwwQLLgecnkMY6Zj8/wDO8Q==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 256, "wn": 1838, "tow": 407084700, "crc": 61902, "length": 11, "flags": 0, "ns_residual": -222999, "preamble": 85, "payload": "LgecnkMY6Zj8/wA="}
    assert parsed_dict['crc'] == 0xf1ce
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "LgecnkMY6Zj8/wA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( -222999 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084700 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1838 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_9():
    buf = base64.standard_b64decode("VQABwwQLLgcAn0MY8JoDAACTYg==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 256, "wn": 1838, "tow": 407084800, "crc": 25235, "length": 11, "flags": 0, "ns_residual": 236272, "preamble": 85, "payload": "LgcAn0MY8JoDAAA="}
    assert parsed_dict['crc'] == 0x6293
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "LgcAn0MY8JoDAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( 236272 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084800 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1838 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_10():
    buf = base64.standard_b64decode("VQABwwQLLgdkn0MYkGX8/wC6mA==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 256, "wn": 1838, "tow": 407084900, "crc": 39098, "length": 11, "flags": 0, "ns_residual": -236144, "preamble": 85, "payload": "Lgdkn0MYkGX8/wA="}
    assert parsed_dict['crc'] == 0x98ba
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "Lgdkn0MYkGX8/wA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( -236144 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407084900 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1838 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_navigation_msg_gps_time_dep_a_11():
    buf = base64.standard_b64decode("VQABwwQLLgcuokQYzeb6/wAL4Q==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"sender": 1219, "msg_type": 256, "wn": 1838, "tow": 407151150, "crc": 57611, "length": 11, "flags": 0, "ns_residual": -334131, "preamble": 85, "payload": "LgcuokQYzeb6/wA="}
    assert parsed_dict['crc'] == 0xe10b
    assert parsed_dict['length'] == 11
    assert parsed_dict['msg_type'] == 0x100
    assert parsed_dict['payload'] == "LgcuokQYzeb6/wA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.ns_residual) == snake_case_keys( -334131 )
    assert dictify(obj.payload.tow) == snake_case_keys( 407151150 )
    assert dictify(obj.payload.wn) == snake_case_keys( 1838 )

    assert parsed_dict == snake_case_keys(orig_dict)