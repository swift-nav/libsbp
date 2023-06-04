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
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_thread_state_1():
    buf = base64.standard_b64decode("VRcA9tcabWFpbgAAAAAAAAAAAAAAAAAAAAAAAJwJAABJig==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8a49
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJwJAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cpu) == 0
    
    assert dictify(msg.name) == "main\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 2460

    assert dictify(msg) == {'sender': 55286, 'msg_type': 23, 'cpu': 0, 'crc': 35401, 'length': 26, 'stack_free': 2460, 'preamble': 85, 'payload': 'bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJwJAAA=', 'name': 'main\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_2():
    buf = base64.standard_b64decode("VRcA9tcaaWRsZQAAAAAAAAAAAAAAAAAAAABTAiQAAACXFA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1497
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "aWRsZQAAAAAAAAAAAAAAAAAAAABTAiQAAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cpu) == 595
    
    assert dictify(msg.name) == "idle\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 36

    assert dictify(msg) == {'sender': 55286, 'msg_type': 23, 'cpu': 595, 'crc': 5271, 'length': 26, 'stack_free': 36, 'preamble': 85, 'payload': 'aWRsZQAAAAAAAAAAAAAAAAAAAABTAiQAAAA=', 'name': 'idle\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_3():
    buf = base64.standard_b64decode("VRcA9tcaTkFQIElTUgAAAAAAAAAAAAAAAAAOAHQEAADiPA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x3ce2
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "TkFQIElTUgAAAAAAAAAAAAAAAAAOAHQEAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cpu) == 14
    
    assert dictify(msg.name) == "NAP ISR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 1140

    assert dictify(msg) == {'sender': 55286, 'msg_type': 23, 'cpu': 14, 'crc': 15586, 'length': 26, 'stack_free': 1140, 'preamble': 85, 'payload': 'TkFQIElTUgAAAAAAAAAAAAAAAAAOAHQEAAA=', 'name': 'NAP ISR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_4():
    buf = base64.standard_b64decode("VRcA9tcaU0JQAAAAAAAAAAAAAAAAAAAAAAABAMQTAABaqQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa95a
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "U0JQAAAAAAAAAAAAAAAAAAAAAAABAMQTAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cpu) == 1
    
    assert dictify(msg.name) == "SBP\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 5060

    assert dictify(msg) == {'sender': 55286, 'msg_type': 23, 'cpu': 1, 'crc': 43354, 'length': 26, 'stack_free': 5060, 'preamble': 85, 'payload': 'U0JQAAAAAAAAAAAAAAAAAAAAAAABAMQTAAA=', 'name': 'SBP\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_5():
    buf = base64.standard_b64decode("VRcA9tcabWFuYWdlIGFjcQAAAAAAAAAAAAAHABQJAAAvSw==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4b2f
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "bWFuYWdlIGFjcQAAAAAAAAAAAAAHABQJAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.cpu) == 7
    
    assert dictify(msg.name) == "manage acq\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 2324

    assert dictify(msg) == {'sender': 55286, 'msg_type': 23, 'cpu': 7, 'crc': 19247, 'length': 26, 'stack_free': 2324, 'preamble': 85, 'payload': 'bWFuYWdlIGFjcQAAAAAAAAAAAAAHABQJAAA=', 'name': 'manage acq\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_6():
    buf = base64.standard_b64decode("VRcAwwQabWFpbgAAAAAAAAAAAAAAAAAAAAAAAJQJAADD1A==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd4c3
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJQJAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cpu) == 0
    
    assert dictify(msg.name) == "main\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 2452

    assert dictify(msg) == {'sender': 1219, 'msg_type': 23, 'cpu': 0, 'crc': 54467, 'length': 26, 'stack_free': 2452, 'preamble': 85, 'payload': 'bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJQJAAA=', 'name': 'main\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_7():
    buf = base64.standard_b64decode("VRcAwwQaaWRsZQAAAAAAAAAAAAAAAAAAAADkASQAAADhEg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x12e1
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "aWRsZQAAAAAAAAAAAAAAAAAAAADkASQAAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cpu) == 484
    
    assert dictify(msg.name) == "idle\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 36

    assert dictify(msg) == {'sender': 1219, 'msg_type': 23, 'cpu': 484, 'crc': 4833, 'length': 26, 'stack_free': 36, 'preamble': 85, 'payload': 'aWRsZQAAAAAAAAAAAAAAAAAAAADkASQAAAA=', 'name': 'idle\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_8():
    buf = base64.standard_b64decode("VRcAwwQaTkFQIElTUgAAAAAAAAAAAAAAAACKAVwHAACmdA==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x74a6
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "TkFQIElTUgAAAAAAAAAAAAAAAACKAVwHAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cpu) == 394
    
    assert dictify(msg.name) == "NAP ISR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 1884

    assert dictify(msg) == {'sender': 1219, 'msg_type': 23, 'cpu': 394, 'crc': 29862, 'length': 26, 'stack_free': 1884, 'preamble': 85, 'payload': 'TkFQIElTUgAAAAAAAAAAAAAAAACKAVwHAAA=', 'name': 'NAP ISR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_9():
    buf = base64.standard_b64decode("VRcAwwQaU0JQAAAAAAAAAAAAAAAAAAAAAAABAAQMAADlrg==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xaee5
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "U0JQAAAAAAAAAAAAAAAAAAAAAAABAAQMAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cpu) == 1
    
    assert dictify(msg.name) == "SBP\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 3076

    assert dictify(msg) == {'sender': 1219, 'msg_type': 23, 'cpu': 1, 'crc': 44773, 'length': 26, 'stack_free': 3076, 'preamble': 85, 'payload': 'U0JQAAAAAAAAAAAAAAAAAAAAAAABAAQMAAA=', 'name': 'SBP\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_10():
    buf = base64.standard_b64decode("VRcAwwQabWFuYWdlIGFjcQAAAAAAAAAAAAAKAHwJAAA0Ag==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x234
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "bWFuYWdlIGFjcQAAAAAAAAAAAAAKAHwJAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cpu) == 10
    
    assert dictify(msg.name) == "manage acq\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 2428

    assert dictify(msg) == {'sender': 1219, 'msg_type': 23, 'cpu': 10, 'crc': 564, 'length': 26, 'stack_free': 2428, 'preamble': 85, 'payload': 'bWFuYWdlIGFjcQAAAAAAAAAAAAAKAHwJAAA=', 'name': 'manage acq\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'}

def test_auto_check_sbp_piksi_msg_thread_state_11():
    buf = base64.standard_b64decode("VRcAwwQabWFuYWdlIHRyYWNrAAAAAAAAAAAAABwJAAB6Ng==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x367a
    
    assert msg.length == 26
    
    assert msg.msg_type == 0x17
    
    assert msg.payload == "bWFuYWdlIHRyYWNrAAAAAAAAAAAAABwJAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.cpu) == 0
    
    assert dictify(msg.name) == "manage track\x00\x00\x00\x00\x00\x00\x00\x00"
    
    assert dictify(msg.stack_free) == 2332

    assert dictify(msg) == {'sender': 1219, 'msg_type': 23, 'cpu': 0, 'crc': 13946, 'length': 26, 'stack_free': 2332, 'preamble': 85, 'payload': 'bWFuYWdlIHRyYWNrAAAAAAAAAAAAABwJAAA=', 'name': 'manage track\x00\x00\x00\x00\x00\x00\x00\x00'}