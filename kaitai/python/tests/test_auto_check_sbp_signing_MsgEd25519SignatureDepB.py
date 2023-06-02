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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519SignatureDepB.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_signing_msg_ed25519_signature_dep_b_1():
    buf = base64.standard_b64decode("VQMMQgC6AQAAAQIDBAUGBwgJCgsMDQ4PEBESExQVFhcYGRobHB0eHyAhIiMkJSYnKCkqKywtLi8wMTIzNDU2Nzg5Ojs8PT4/ZGVmZ2hpamtsbW5vcHFyc3R1dneIEwAAchQAAFwVAABGFgAAMBcAABoYAAAEGQAA7hkAANgaAADCGwAArBwAAJYdAACAHgAAah8AAFQgAAA+IQAAKCIAABIjAAD8IwAA5iQAANAlAAC6JgAApCcAAI4oAAB4KQAA7pE=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"preamble": 85, "msg_type": 3075, "sender": 66, "length": 186, "payload": "AQAAAQIDBAUGBwgJCgsMDQ4PEBESExQVFhcYGRobHB0eHyAhIiMkJSYnKCkqKywtLi8wMTIzNDU2Nzg5Ojs8PT4/ZGVmZ2hpamtsbW5vcHFyc3R1dneIEwAAchQAAFwVAABGFgAAMBcAABoYAAAEGQAA7hkAANgaAADCGwAArBwAAJYdAACAHgAAah8AAFQgAAA+IQAAKCIAABIjAAD8IwAA5iQAANAlAAC6JgAApCcAAI4oAAB4KQAA", "crc": 37358, "stream_counter": 1, "on_demand_counter": 0, "signature": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63], "fingerprint": [100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119], "signed_messages": [5000, 5234, 5468, 5702, 5936, 6170, 6404, 6638, 6872, 7106, 7340, 7574, 7808, 8042, 8276, 8510, 8744, 8978, 9212, 9446, 9680, 9914, 10148, 10382, 10616]}
    assert parsed_dict['crc'] == 0x91EE
    assert parsed_dict['length'] == 186
    assert parsed_dict['msg_type'] == 0xC03
    assert parsed_dict['payload'] == "AQAAAQIDBAUGBwgJCgsMDQ4PEBESExQVFhcYGRobHB0eHyAhIiMkJSYnKCkqKywtLi8wMTIzNDU2Nzg5Ojs8PT4/ZGVmZ2hpamtsbW5vcHFyc3R1dneIEwAAchQAAFwVAABGFgAAMBcAABoYAAAEGQAA7hkAANgaAADCGwAArBwAAJYdAACAHgAAah8AAFQgAAA+IQAAKCIAABIjAAD8IwAA5iQAANAlAAC6JgAApCcAAI4oAAB4KQAA"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x42
    assert dictify(obj.payload.fingerprint) == snake_case_keys( [100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119] )
    assert dictify(obj.payload.on_demand_counter) == snake_case_keys( 0 )
    assert dictify(obj.payload.signature) == snake_case_keys( [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63] )
    assert dictify(obj.payload.signed_messages) == snake_case_keys( [5000, 5234, 5468, 5702, 5936, 6170, 6404, 6638, 6872, 7106, 7340, 7574, 7808, 8042, 8276, 8510, 8744, 8978, 9212, 9446, 9680, 9914, 10148, 10382, 10616] )
    assert dictify(obj.payload.stream_counter) == snake_case_keys( 1 )

    assert parsed_dict == snake_case_keys(orig_dict)