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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_uart_state_1():
    buf = base64.standard_b64decode("VR0AyOBKmqnyRWam50RZYk+4ivSaSclFmkHTRckQZ/mPoZoRukUz0wdF15X9GdoYHcMQE5+ORxEKcYnbhxK2FSa+O8Spm2tv/aj0nnAT+4Nk4Q==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe164
    
    assert msg.length == 74
    
    assert msg.msg_type == 0x1d
    
    assert msg.payload == "mqnyRWam50RZYk+4ivSaSclFmkHTRckQZ/mPoZoRukUz0wdF15X9GdoYHcMQE5+ORxEKcYnbhxK2FSa+O8Spm2tv/aj0nnAT+4M="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xe0c8
    
    assert dictify(msg.latency) == {'avg': 319865629, 'current': 364253831, 'lmax': -611749622, 'lmin': 289902239}
    
    assert dictify(msg.obs_period) == {'avg': -1002717658, 'current': -2080697488, 'pmax': -1628133123, 'pmin': 1869323177}
    
    assert dictify(msg.uart_a) == {'crc_error_count': 25177, 'io_error_count': 47183, 'rx_buffer_level': 244, 'rx_throughput': 1853.199951171875, 'tx_buffer_level': 138, 'tx_throughput': 7765.2001953125}
    
    assert dictify(msg.uart_b) == {'crc_error_count': 4297, 'io_error_count': 63847, 'rx_buffer_level': 161, 'rx_throughput': 6760.2001953125, 'tx_buffer_level': 143, 'tx_throughput': 6441.2001953125}
    
    assert dictify(msg.uart_ftdi) == {'crc_error_count': 38359, 'io_error_count': 6653, 'rx_buffer_level': 24, 'rx_throughput': 2173.199951171875, 'tx_buffer_level': 218, 'tx_throughput': 5954.2001953125}

    assert dictify(msg) == {'preamble': 85, 'msg_type': 29, 'sender': 57544, 'length': 74, 'payload': 'mqnyRWam50RZYk+4ivSaSclFmkHTRckQZ/mPoZoRukUz0wdF15X9GdoYHcMQE5+ORxEKcYnbhxK2FSa+O8Spm2tv/aj0nnAT+4M=', 'crc': 57700, 'uart_a': {'tx_throughput': 7765.2001953125, 'rx_throughput': 1853.199951171875, 'crc_error_count': 25177, 'io_error_count': 47183, 'tx_buffer_level': 138, 'rx_buffer_level': 244}, 'uart_b': {'tx_throughput': 6441.2001953125, 'rx_throughput': 6760.2001953125, 'crc_error_count': 4297, 'io_error_count': 63847, 'tx_buffer_level': 143, 'rx_buffer_level': 161}, 'uart_ftdi': {'tx_throughput': 5954.2001953125, 'rx_throughput': 2173.199951171875, 'crc_error_count': 38359, 'io_error_count': 6653, 'tx_buffer_level': 218, 'rx_buffer_level': 24}, 'latency': {'avg': 319865629, 'lmin': 289902239, 'lmax': -611749622, 'current': 364253831}, 'obs_period': {'avg': -1002717658, 'pmin': 1869323177, 'pmax': -1628133123, 'current': -2080697488}}

def test_auto_check_sbp_piksi_msg_uart_state_2():
    buf = base64.standard_b64decode("VRgA9tc6Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////0d8")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7c47
    
    assert msg.length == 58
    
    assert msg.msg_type == 0x18
    
    assert msg.payload == "Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////w=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.latency) == {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0}
    
    assert dictify(msg.uart_a) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 24, 'tx_throughput': 0.8661972284317017}
    
    assert dictify(msg.uart_b) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 40, 'tx_throughput': 2.9718310832977295}
    
    assert dictify(msg.uart_ftdi) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 1, 'rx_throughput': 0.035211268812417984, 'tx_buffer_level': 81, 'tx_throughput': 5.063380241394043}

    assert dictify(msg) == {'latency': {'current': -1, 'lmax': 0, 'avg': -1, 'lmin': 0}, 'sender': 55286, 'msg_type': 24, 'crc': 31815, 'length': 58, 'uart_b': {'rx_buffer_level': 0, 'tx_buffer_level': 40, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 2.9718310832977295}, 'uart_a': {'rx_buffer_level': 0, 'tx_buffer_level': 24, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.8661972284317017}, 'preamble': 85, 'payload': 'Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////w==', 'uart_ftdi': {'rx_buffer_level': 1, 'tx_buffer_level': 81, 'rx_throughput': 0.035211268812417984, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 5.063380241394043}}

def test_auto_check_sbp_piksi_msg_uart_state_3():
    buf = base64.standard_b64decode("VRgA9tc67ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////5n4")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf899
    
    assert msg.length == 58
    
    assert msg.msg_type == 0x18
    
    assert msg.payload == "7ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////w=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.latency) == {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0}
    
    assert dictify(msg.uart_a) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 24, 'tx_throughput': 0.8746479153633118}
    
    assert dictify(msg.uart_b) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 40, 'tx_throughput': 2.995774745941162}
    
    assert dictify(msg.uart_ftdi) == {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 1, 'rx_throughput': 0.35211268067359924, 'tx_buffer_level': 85, 'tx_throughput': 6.7901411056518555}

    assert dictify(msg) == {'latency': {'current': -1, 'lmax': 0, 'avg': -1, 'lmin': 0}, 'sender': 55286, 'msg_type': 24, 'crc': 63641, 'length': 58, 'uart_b': {'rx_buffer_level': 0, 'tx_buffer_level': 40, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 2.995774745941162}, 'uart_a': {'rx_buffer_level': 0, 'tx_buffer_level': 24, 'rx_throughput': 0.0, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 0.8746479153633118}, 'preamble': 85, 'payload': '7ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////w==', 'uart_ftdi': {'rx_buffer_level': 1, 'tx_buffer_level': 85, 'rx_throughput': 0.35211268067359924, 'crc_error_count': 0, 'io_error_count': 0, 'tx_throughput': 6.7901411056518555}}