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

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"index": 0, "sender": 55286, "msg_type": 167, "crc": 59896, "length": 78, "setting": "telemetry_radio\u0000configuration_string\u0000AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ\u0000", "preamble": 85, "payload": "AAB0ZWxlbWV0cnlfcmFkaW8AY29uZmlndXJhdGlvbl9zdHJpbmcAQVQmRixBVFMxPTExNSxBVFMyPTEyOCxBVFM1PTAsQVQmVyxBVFoA"}
    assert parsed_dict['crc'] == 0xe9f8
    assert parsed_dict['length'] == 78
    assert parsed_dict['msg_type'] == 0xa7
    assert parsed_dict['payload'] == "AAB0ZWxlbWV0cnlfcmFkaW8AY29uZmlndXJhdGlvbl9zdHJpbmcAQVQmRixBVFMxPTExNSxBVFMyPTEyOCxBVFM1PTAsQVQmVyxBVFoA"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 0 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'telemetry_radio\x00configuration_string\x00AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ\x00' )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_settings_msg_settings_read_by_index_resp_2():
    buf = base64.standard_b64decode("VacA9tcjAQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQCn8w==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"index": 1, "sender": 55286, "msg_type": 167, "crc": 62375, "length": 35, "setting": "uart_ftdi\u0000mode\u0000SBP\u0000enum:SBP,NMEA\u0000", "preamble": 85, "payload": "AQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQA="}
    assert parsed_dict['crc'] == 0xf3a7
    assert parsed_dict['length'] == 35
    assert parsed_dict['msg_type'] == 0xa7
    assert parsed_dict['payload'] == "AQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 1 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'uart_ftdi\x00mode\x00SBP\x00enum:SBP,NMEA\x00' )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_settings_msg_settings_read_by_index_resp_3():
    buf = base64.standard_b64decode("VacA9tcjAgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQAEOA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"index": 2, "sender": 55286, "msg_type": 167, "crc": 14340, "length": 35, "setting": "uart_ftdi\u0000sbp_message_mask\u000065535\u0000", "preamble": 85, "payload": "AgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQA="}
    assert parsed_dict['crc'] == 0x3804
    assert parsed_dict['length'] == 35
    assert parsed_dict['msg_type'] == 0xa7
    assert parsed_dict['payload'] == "AgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 2 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'uart_ftdi\x00sbp_message_mask\x0065535\x00' )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_settings_msg_settings_read_by_index_resp_4():
    buf = base64.standard_b64decode("VacA9tcdAwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMADykg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"index": 3, "sender": 55286, "msg_type": 167, "crc": 37618, "length": 29, "setting": "uart_ftdi\u0000baudrate\u00001000000\u0000", "preamble": 85, "payload": "AwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMAA="}
    assert parsed_dict['crc'] == 0x92f2
    assert parsed_dict['length'] == 29
    assert parsed_dict['msg_type'] == 0xa7
    assert parsed_dict['payload'] == "AwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 3 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'uart_ftdi\x00baudrate\x001000000\x00' )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_settings_msg_settings_read_by_index_resp_5():
    buf = base64.standard_b64decode("VacA9tckBAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEAFgQ=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"index": 4, "sender": 55286, "msg_type": 167, "crc": 1046, "length": 36, "setting": "uart_uarta\u0000mode\u0000SBP\u0000enum:SBP,NMEA\u0000", "preamble": 85, "payload": "BAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEA"}
    assert parsed_dict['crc'] == 0x416
    assert parsed_dict['length'] == 36
    assert parsed_dict['msg_type'] == 0xa7
    assert parsed_dict['payload'] == "BAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEA"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.index) == snake_case_keys( 4 )
    assert dictify(obj.payload.setting) == snake_case_keys( 'uart_uarta\x00mode\x00SBP\x00enum:SBP,NMEA\x00' )

    assert parsed_dict == snake_case_keys(orig_dict)