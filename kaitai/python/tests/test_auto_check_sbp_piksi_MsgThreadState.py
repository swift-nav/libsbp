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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgThreadState.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_thread_state_1():
    buf = base64.standard_b64decode("VRcA9tcabWFpbgAAAAAAAAAAAAAAAAAAAAAAAJwJAABJig==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x8a49
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJwJAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.cpu) == snake_case_keys( 0 )
    assert dictify(obj.payload.name) == snake_case_keys( 'main\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 2460 )

    assert dictify(payload) == snake_case_keys( {"sender": 55286, "msg_type": 23, "cpu": 0, "crc": 35401, "length": 26, "stack_free": 2460, "preamble": 85, "payload": "bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJwJAAA=", "name": "main\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_2():
    buf = base64.standard_b64decode("VRcA9tcaaWRsZQAAAAAAAAAAAAAAAAAAAABTAiQAAACXFA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x1497
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "aWRsZQAAAAAAAAAAAAAAAAAAAABTAiQAAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.cpu) == snake_case_keys( 595 )
    assert dictify(obj.payload.name) == snake_case_keys( 'idle\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 36 )

    assert dictify(payload) == snake_case_keys( {"sender": 55286, "msg_type": 23, "cpu": 595, "crc": 5271, "length": 26, "stack_free": 36, "preamble": 85, "payload": "aWRsZQAAAAAAAAAAAAAAAAAAAABTAiQAAAA=", "name": "idle\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_3():
    buf = base64.standard_b64decode("VRcA9tcaTkFQIElTUgAAAAAAAAAAAAAAAAAOAHQEAADiPA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x3ce2
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "TkFQIElTUgAAAAAAAAAAAAAAAAAOAHQEAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.cpu) == snake_case_keys( 14 )
    assert dictify(obj.payload.name) == snake_case_keys( 'NAP ISR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 1140 )

    assert dictify(payload) == snake_case_keys( {"sender": 55286, "msg_type": 23, "cpu": 14, "crc": 15586, "length": 26, "stack_free": 1140, "preamble": 85, "payload": "TkFQIElTUgAAAAAAAAAAAAAAAAAOAHQEAAA=", "name": "NAP ISR\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_4():
    buf = base64.standard_b64decode("VRcA9tcaU0JQAAAAAAAAAAAAAAAAAAAAAAABAMQTAABaqQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xa95a
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "U0JQAAAAAAAAAAAAAAAAAAAAAAABAMQTAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.cpu) == snake_case_keys( 1 )
    assert dictify(obj.payload.name) == snake_case_keys( 'SBP\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 5060 )

    assert dictify(payload) == snake_case_keys( {"sender": 55286, "msg_type": 23, "cpu": 1, "crc": 43354, "length": 26, "stack_free": 5060, "preamble": 85, "payload": "U0JQAAAAAAAAAAAAAAAAAAAAAAABAMQTAAA=", "name": "SBP\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_5():
    buf = base64.standard_b64decode("VRcA9tcabWFuYWdlIGFjcQAAAAAAAAAAAAAHABQJAAAvSw==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x4b2f
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "bWFuYWdlIGFjcQAAAAAAAAAAAAAHABQJAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0xd7f6
    assert dictify(obj.payload.cpu) == snake_case_keys( 7 )
    assert dictify(obj.payload.name) == snake_case_keys( 'manage acq\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 2324 )

    assert dictify(payload) == snake_case_keys( {"sender": 55286, "msg_type": 23, "cpu": 7, "crc": 19247, "length": 26, "stack_free": 2324, "preamble": 85, "payload": "bWFuYWdlIGFjcQAAAAAAAAAAAAAHABQJAAA=", "name": "manage acq\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_6():
    buf = base64.standard_b64decode("VRcAwwQabWFpbgAAAAAAAAAAAAAAAAAAAAAAAJQJAADD1A==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xd4c3
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJQJAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.cpu) == snake_case_keys( 0 )
    assert dictify(obj.payload.name) == snake_case_keys( 'main\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 2452 )

    assert dictify(payload) == snake_case_keys( {"sender": 1219, "msg_type": 23, "cpu": 0, "crc": 54467, "length": 26, "stack_free": 2452, "preamble": 85, "payload": "bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJQJAAA=", "name": "main\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_7():
    buf = base64.standard_b64decode("VRcAwwQaaWRsZQAAAAAAAAAAAAAAAAAAAADkASQAAADhEg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x12e1
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "aWRsZQAAAAAAAAAAAAAAAAAAAADkASQAAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.cpu) == snake_case_keys( 484 )
    assert dictify(obj.payload.name) == snake_case_keys( 'idle\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 36 )

    assert dictify(payload) == snake_case_keys( {"sender": 1219, "msg_type": 23, "cpu": 484, "crc": 4833, "length": 26, "stack_free": 36, "preamble": 85, "payload": "aWRsZQAAAAAAAAAAAAAAAAAAAADkASQAAAA=", "name": "idle\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_8():
    buf = base64.standard_b64decode("VRcAwwQaTkFQIElTUgAAAAAAAAAAAAAAAACKAVwHAACmdA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x74a6
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "TkFQIElTUgAAAAAAAAAAAAAAAACKAVwHAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.cpu) == snake_case_keys( 394 )
    assert dictify(obj.payload.name) == snake_case_keys( 'NAP ISR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 1884 )

    assert dictify(payload) == snake_case_keys( {"sender": 1219, "msg_type": 23, "cpu": 394, "crc": 29862, "length": 26, "stack_free": 1884, "preamble": 85, "payload": "TkFQIElTUgAAAAAAAAAAAAAAAACKAVwHAAA=", "name": "NAP ISR\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_9():
    buf = base64.standard_b64decode("VRcAwwQaU0JQAAAAAAAAAAAAAAAAAAAAAAABAAQMAADlrg==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xaee5
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "U0JQAAAAAAAAAAAAAAAAAAAAAAABAAQMAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.cpu) == snake_case_keys( 1 )
    assert dictify(obj.payload.name) == snake_case_keys( 'SBP\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 3076 )

    assert dictify(payload) == snake_case_keys( {"sender": 1219, "msg_type": 23, "cpu": 1, "crc": 44773, "length": 26, "stack_free": 3076, "preamble": 85, "payload": "U0JQAAAAAAAAAAAAAAAAAAAAAAABAAQMAAA=", "name": "SBP\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_10():
    buf = base64.standard_b64decode("VRcAwwQabWFuYWdlIGFjcQAAAAAAAAAAAAAKAHwJAAA0Ag==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x234
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "bWFuYWdlIGFjcQAAAAAAAAAAAAAKAHwJAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.cpu) == snake_case_keys( 10 )
    assert dictify(obj.payload.name) == snake_case_keys( 'manage acq\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 2428 )

    assert dictify(payload) == snake_case_keys( {"sender": 1219, "msg_type": 23, "cpu": 10, "crc": 564, "length": 26, "stack_free": 2428, "preamble": 85, "payload": "bWFuYWdlIGFjcQAAAAAAAAAAAAAKAHwJAAA=", "name": "manage acq\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )

def test_auto_check_sbp_piksi_msg_thread_state_11():
    buf = base64.standard_b64decode("VRcAwwQabWFuYWdlIHRyYWNrAAAAAAAAAAAAABwJAAB6Ng==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0x367a
    assert payload.length == 26
    assert payload.msg_type == 0x17
    assert payload.payload == "bWFuYWdlIHRyYWNrAAAAAAAAAAAAABwJAAA="
    assert payload.preamble == 0x55
    assert payload.sender == 0x4c3
    assert dictify(obj.payload.cpu) == snake_case_keys( 0 )
    assert dictify(obj.payload.name) == snake_case_keys( 'manage track\x00\x00\x00\x00\x00\x00\x00\x00' )
    assert dictify(obj.payload.stack_free) == snake_case_keys( 2332 )

    assert dictify(payload) == snake_case_keys( {"sender": 1219, "msg_type": 23, "cpu": 0, "crc": 13946, "length": 26, "stack_free": 2332, "preamble": 85, "payload": "bWFuYWdlIHRyYWNrAAAAAAAAAAAAABwJAAA=", "name": "manage track\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"} )