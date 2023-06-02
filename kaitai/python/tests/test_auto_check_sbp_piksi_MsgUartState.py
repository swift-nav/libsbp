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

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_uart_state_1():
    buf = base64.standard_b64decode("VRgA9tc6Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////0d8")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 55286, "msg_type": 24, "crc": 31815, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 40, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 2.9718310832977295}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 24, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.8661972284317017}, "preamble": 85, "payload": "Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 1, "tx_buffer_level": 81, "rx_throughput": 0.035211268812417984, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 5.063380241394043}}
    assert parsed_dict['crc'] == 0x7c47
    assert parsed_dict['length'] == 58
    assert parsed_dict['msg_type'] == 0x18
    assert parsed_dict['payload'] == "Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////w=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.latency) == snake_case_keys( {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0} )
    assert dictify(obj.payload.uart_a) == snake_case_keys( {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 24, 'tx_throughput': 0.8661972284317017} )
    assert dictify(obj.payload.uart_b) == snake_case_keys( {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 40, 'tx_throughput': 2.9718310832977295} )
    assert dictify(obj.payload.uart_ftdi) == snake_case_keys( {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 1, 'rx_throughput': 0.035211268812417984, 'tx_buffer_level': 81, 'tx_throughput': 5.063380241394043} )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_piksi_msg_uart_state_2():
    buf = base64.standard_b64decode("VRgA9tc67ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////5n4")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 55286, "msg_type": 24, "crc": 63641, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 40, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 2.995774745941162}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 24, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.8746479153633118}, "preamble": 85, "payload": "7ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 1, "tx_buffer_level": 85, "rx_throughput": 0.35211268067359924, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 6.7901411056518555}}
    assert parsed_dict['crc'] == 0xf899
    assert parsed_dict['length'] == 58
    assert parsed_dict['msg_type'] == 0x18
    assert parsed_dict['payload'] == "7ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////w=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.latency) == snake_case_keys( {'avg': -1, 'current': -1, 'lmax': 0, 'lmin': 0} )
    assert dictify(obj.payload.uart_a) == snake_case_keys( {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 24, 'tx_throughput': 0.8746479153633118} )
    assert dictify(obj.payload.uart_b) == snake_case_keys( {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 0, 'rx_throughput': 0.0, 'tx_buffer_level': 40, 'tx_throughput': 2.995774745941162} )
    assert dictify(obj.payload.uart_ftdi) == snake_case_keys( {'crc_error_count': 0, 'io_error_count': 0, 'rx_buffer_level': 1, 'rx_throughput': 0.35211268067359924, 'tx_buffer_level': 85, 'tx_throughput': 6.7901411056518555} )

    assert parsed_dict == snake_case_keys(orig_dict)