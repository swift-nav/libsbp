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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkBandwidthUsage.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_piksi_msg_network_bandwidth_usage_1():
    buf = base64.standard_b64decode("Vb0Az3nIXmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAY2FuMAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAGNhbjEAAAAAAAAAAAAAAABeabKAAAAAAKXrXssAAAAA7Q6U8LjcytpldGgwAAAAAAAAAAAAAAAAXmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAbG8AAAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAHNpdDAAAAAAAAAAAAAAAAAbhQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"preamble": 85, "msg_type": 189, "sender": 31183, "length": 200, "payload": "XmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAY2FuMAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAGNhbjEAAAAAAAAAAAAAAABeabKAAAAAAKXrXssAAAAA7Q6U8LjcytpldGgwAAAAAAAAAAAAAAAAXmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAbG8AAAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAHNpdDAAAAAAAAAAAAAAAAA=", "crc": 34075, "interfaces": [{"duration": 2159176030, "total_bytes": 0, "rx_bytes": 0, "tx_bytes": 0, "interface_name": "can0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}, {"duration": 2159176030, "total_bytes": 0, "rx_bytes": 0, "tx_bytes": 0, "interface_name": "can1\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}, {"duration": 2159176030, "total_bytes": 3411995557, "rx_bytes": 4036234989, "tx_bytes": 3670727864, "interface_name": "eth0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}, {"duration": 2159176030, "total_bytes": 0, "rx_bytes": 0, "tx_bytes": 0, "interface_name": "lo\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}, {"duration": 2159176030, "total_bytes": 0, "rx_bytes": 0, "tx_bytes": 0, "interface_name": "sit0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}]}
    assert parsed_dict['crc'] == 0x851B
    assert parsed_dict['length'] == 200
    assert parsed_dict['msg_type'] == 0xBD
    assert parsed_dict['payload'] == "XmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAY2FuMAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAGNhbjEAAAAAAAAAAAAAAABeabKAAAAAAKXrXssAAAAA7Q6U8LjcytpldGgwAAAAAAAAAAAAAAAAXmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAbG8AAAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAHNpdDAAAAAAAAAAAAAAAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x79CF
    assert dictify(obj.payload.interfaces) == snake_case_keys( [{'duration': 2159176030, 'interface_name': 'can0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'rx_bytes': 0, 'total_bytes': 0, 'tx_bytes': 0}, {'duration': 2159176030, 'interface_name': 'can1\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'rx_bytes': 0, 'total_bytes': 0, 'tx_bytes': 0}, {'duration': 2159176030, 'interface_name': 'eth0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'rx_bytes': 4036234989, 'total_bytes': 3411995557, 'tx_bytes': 3670727864}, {'duration': 2159176030, 'interface_name': 'lo\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'rx_bytes': 0, 'total_bytes': 0, 'tx_bytes': 0}, {'duration': 2159176030, 'interface_name': 'sit0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'rx_bytes': 0, 'total_bytes': 0, 'tx_bytes': 0}] )

    assert parsed_dict == snake_case_keys(orig_dict)