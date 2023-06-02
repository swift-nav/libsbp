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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_settings_msg_settings_read_by_index_resp_1():
    buf = base64.standard_b64decode("VacA9tdOAAB0ZWxlbWV0cnlfcmFkaW8AY29uZmlndXJhdGlvbl9zdHJpbmcAQVQmRixBVFMxPTExNSxBVFMyPTEyOCxBVFM1PTAsQVQmVyxBVFoA+Ok=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xe9f8
    assert payload.length == 78
    assert payload.msg_type == 0xa7
    assert payload.payload == "AAB0ZWxlbWV0cnlfcmFkaW8AY29uZmlndXJhdGlvbl9zdHJpbmcAQVQmRixBVFMxPTExNSxBVFMyPTEyOCxBVFM1PTAsQVQmVyxBVFoA"
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 0 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'telemetry_radio\x00configuration_string\x00AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ\x00' )

    assert dictify(payload) == snake_case_keys( {"index": 0, "sender": 55286, "msg_type": 167, "crc": 59896, "length": 78, "setting": "telemetry_radio\u0000configuration_string\u0000AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ\u0000", "preamble": 85, "payload": "AAB0ZWxlbWV0cnlfcmFkaW8AY29uZmlndXJhdGlvbl9zdHJpbmcAQVQmRixBVFMxPTExNSxBVFMyPTEyOCxBVFM1PTAsQVQmVyxBVFoA"} )

def test_auto_check_sbp_settings_msg_settings_read_by_index_resp_2():
    buf = base64.standard_b64decode("VacA9tcjAQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQCn8w==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xf3a7
    assert payload.length == 35
    assert payload.msg_type == 0xa7
    assert payload.payload == "AQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQA="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 1 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'uart_ftdi\x00mode\x00SBP\x00enum:SBP,NMEA\x00' )

    assert dictify(payload) == snake_case_keys( {"index": 1, "sender": 55286, "msg_type": 167, "crc": 62375, "length": 35, "setting": "uart_ftdi\u0000mode\u0000SBP\u0000enum:SBP,NMEA\u0000", "preamble": 85, "payload": "AQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQA="} )

def test_auto_check_sbp_settings_msg_settings_read_by_index_resp_3():
    buf = base64.standard_b64decode("VacA9tcjAgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQAEOA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x3804
    assert payload.length == 35
    assert payload.msg_type == 0xa7
    assert payload.payload == "AgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQA="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 2 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'uart_ftdi\x00sbp_message_mask\x0065535\x00' )

    assert dictify(payload) == snake_case_keys( {"index": 2, "sender": 55286, "msg_type": 167, "crc": 14340, "length": 35, "setting": "uart_ftdi\u0000sbp_message_mask\u000065535\u0000", "preamble": 85, "payload": "AgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQA="} )

def test_auto_check_sbp_settings_msg_settings_read_by_index_resp_4():
    buf = base64.standard_b64decode("VacA9tcdAwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMADykg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x92f2
    assert payload.length == 29
    assert payload.msg_type == 0xa7
    assert payload.payload == "AwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 3 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'uart_ftdi\x00baudrate\x001000000\x00' )

    assert dictify(payload) == snake_case_keys( {"index": 3, "sender": 55286, "msg_type": 167, "crc": 37618, "length": 29, "setting": "uart_ftdi\u0000baudrate\u00001000000\u0000", "preamble": 85, "payload": "AwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMAA="} )

def test_auto_check_sbp_settings_msg_settings_read_by_index_resp_5():
    buf = base64.standard_b64decode("VacA9tckBAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEAFgQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x416
    assert payload.length == 36
    assert payload.msg_type == 0xa7
    assert payload.payload == "BAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEA"
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 4 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'uart_uarta\x00mode\x00SBP\x00enum:SBP,NMEA\x00' )

    assert dictify(payload) == snake_case_keys( {"index": 4, "sender": 55286, "msg_type": 167, "crc": 1046, "length": 36, "setting": "uart_uarta\u0000mode\u0000SBP\u0000enum:SBP,NMEA\u0000", "preamble": 85, "payload": "BAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEA"} )