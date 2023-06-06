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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartStateDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.parse_utils import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_uart_state_dep_a_1():
    buf = base64.standard_b64decode("VRgAwwQ6AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJqZOUEAAAAAAAAAAA8A/////wAAAAAAAAAA//////cF")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5f7
    
    assert msg.length == 58
    
    assert msg.msg_type == 0x18
    
    assert msg.payload == "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJqZOUEAAAAAAAAAAA8A/////wAAAAAAAAAA/////w=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.latency) == {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0}
    
    assert dictify(msg.uart_a) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.0}
    
    assert dictify(msg.uart_b) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.0}
    
    assert dictify(msg.uart_ftdi) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 15, 'tx_throughput': 11.600000381469727}

    assert dictify(msg) == {'latency': {'current': -1, 'lmax': 0, 'avg': -1, 'lmin': 0}, 'sender': 1219, 'msg_type': 24, 'crc': 1527, 'length': 58, 'uart_b': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.0}, 'uart_a': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.0}, 'preamble': 85, 'payload': 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJqZOUEAAAAAAAAAAA8A/////wAAAAAAAAAA/////w==', 'uart_ftdi': {'rx_buffer_level': 0, 'tx_buffer_level': 15, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 11.600000381469727}}

def test_auto_check_sbp_piksi_msg_uart_state_dep_a_2():
    buf = base64.standard_b64decode("VRgAwwQ6AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////0Fu")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6e41
    
    assert msg.length == 58
    
    assert msg.msg_type == 0x18
    
    assert msg.payload == "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.latency) == {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0}
    
    assert dictify(msg.uart_a) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.0}
    
    assert dictify(msg.uart_b) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.0}
    
    assert dictify(msg.uart_ftdi) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.06599999964237213}

    assert dictify(msg) == {'latency': {'current': -1, 'lmax': 0, 'avg': -1, 'lmin': 0}, 'sender': 1219, 'msg_type': 24, 'crc': 28225, 'length': 58, 'uart_b': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.0}, 'uart_a': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.0}, 'preamble': 85, 'payload': 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w==', 'uart_ftdi': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.06599999964237213}}

def test_auto_check_sbp_piksi_msg_uart_state_dep_a_3():
    buf = base64.standard_b64decode("VRgAwwQ6AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARWDj4AAAAAAAAAAAoA/////wAAAAAAAAAA/////8Yk")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x24c6
    
    assert msg.length == 58
    
    assert msg.msg_type == 0x18
    
    assert msg.payload == "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARWDj4AAAAAAAAAAAoA/////wAAAAAAAAAA/////w=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.latency) == {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0}
    
    assert dictify(msg.uart_a) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.0}
    
    assert dictify(msg.uart_b) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.0}
    
    assert dictify(msg.uart_ftdi) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 10, 'tx_throughput': 0.13899999856948853}

    assert dictify(msg) == {'latency': {'current': -1, 'lmax': 0, 'avg': -1, 'lmin': 0}, 'sender': 1219, 'msg_type': 24, 'crc': 9414, 'length': 58, 'uart_b': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.0}, 'uart_a': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.0}, 'preamble': 85, 'payload': 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARWDj4AAAAAAAAAAAoA/////wAAAAAAAAAA/////w==', 'uart_ftdi': {'rx_buffer_level': 0, 'tx_buffer_level': 10, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.13899999856948853}}

def test_auto_check_sbp_piksi_msg_uart_state_dep_a_4():
    buf = base64.standard_b64decode("VRgAwwQ6AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////0Fu")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6e41
    
    assert msg.length == 58
    
    assert msg.msg_type == 0x18
    
    assert msg.payload == "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.latency) == {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0}
    
    assert dictify(msg.uart_a) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.0}
    
    assert dictify(msg.uart_b) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.0}
    
    assert dictify(msg.uart_ftdi) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 0, 'tx_throughput': 0.06599999964237213}

    assert dictify(msg) == {'latency': {'current': -1, 'lmax': 0, 'avg': -1, 'lmin': 0}, 'sender': 1219, 'msg_type': 24, 'crc': 28225, 'length': 58, 'uart_b': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.0}, 'uart_a': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.0}, 'preamble': 85, 'payload': 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w==', 'uart_ftdi': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.06599999964237213}}

def test_auto_check_sbp_piksi_msg_uart_state_dep_a_5():
    buf = base64.standard_b64decode("VRgAwwQ6AAAAAIpLBjwAAAAAAABQcck9AAAAAAAAAAACAJHt/D4AAAAAAAAAACYA/////wAAAAAAAAAA/////3Bv")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6f70
    
    assert msg.length == 58
    
    assert msg.msg_type == 0x18
    
    assert msg.payload == "AAAAAIpLBjwAAAAAAABQcck9AAAAAAAAAAACAJHt/D4AAAAAAAAAACYA/////wAAAAAAAAAA/////w=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.latency) == {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0}
    
    assert dictify(msg.uart_a) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.008196720853447914, 'tx_buffer_level': 0, 'tx_throughput': 0.0}
    
    assert dictify(msg.uart_b) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 2, 'tx_throughput': 0.09836065769195557}
    
    assert dictify(msg.uart_ftdi) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 38, 'tx_throughput': 0.49399998784065247}

    assert dictify(msg) == {'latency': {'current': -1, 'lmax': 0, 'avg': -1, 'lmin': 0}, 'sender': 1219, 'msg_type': 24, 'crc': 28528, 'length': 58, 'uart_b': {'rx_buffer_level': 0, 'tx_buffer_level': 2, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.09836065769195557}, 'uart_a': {'rx_buffer_level': 0, 'tx_buffer_level': 0, 'rx_throughput': 0.008196720853447914, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.0}, 'preamble': 85, 'payload': 'AAAAAIpLBjwAAAAAAABQcck9AAAAAAAAAAACAJHt/D4AAAAAAAAAACYA/////wAAAAAAAAAA/////w==', 'uart_ftdi': {'rx_buffer_level': 0, 'tx_buffer_level': 38, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.49399998784065247}}

def test_auto_check_sbp_piksi_msg_uart_state_dep_a_6():
    buf = base64.standard_b64decode("VRgAwwQ6pptEPAAAAAAAAAAAAgCmm0Q8AAAAAAAAAAACAOxRqD8AAAAAAAAAADIA/////wAAAAAAAAAA/////xZI")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x4816
    
    assert msg.length == 58
    
    assert msg.msg_type == 0x18
    
    assert msg.payload == "pptEPAAAAAAAAAAAAgCmm0Q8AAAAAAAAAAACAOxRqD8AAAAAAAAAADIA/////wAAAAAAAAAA/////w=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x4c3
    
    assert dictify(msg.latency) == {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0}
    
    assert dictify(msg.uart_a) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 2, 'tx_throughput': 0.012000000104308128}
    
    assert dictify(msg.uart_b) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 2, 'tx_throughput': 0.012000000104308128}
    
    assert dictify(msg.uart_ftdi) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 50, 'tx_throughput': 1.315000057220459}

    assert dictify(msg) == {'latency': {'current': -1, 'lmax': 0, 'avg': -1, 'lmin': 0}, 'sender': 1219, 'msg_type': 24, 'crc': 18454, 'length': 58, 'uart_b': {'rx_buffer_level': 0, 'tx_buffer_level': 2, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.012000000104308128}, 'uart_a': {'rx_buffer_level': 0, 'tx_buffer_level': 2, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.012000000104308128}, 'preamble': 85, 'payload': 'pptEPAAAAAAAAAAAAgCmm0Q8AAAAAAAAAAACAOxRqD8AAAAAAAAAADIA/////wAAAAAAAAAA/////w==', 'uart_ftdi': {'rx_buffer_level': 0, 'tx_buffer_level': 50, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 1.315000057220459}}