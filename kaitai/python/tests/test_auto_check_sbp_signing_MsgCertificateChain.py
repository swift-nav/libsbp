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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgCertificateChain.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_signing_msg_certificate_chain_1():
    buf = base64.standard_b64decode("VQkMQgCQAAECAwQFBgcICQoLDA0ODxAREhMKCwwNDg8QERITAAECAwQFBgcICRQVFhcYGRobHB0KCwwNDg8QERIT6AcDHgwiOxXNWwdIAAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc4OTo7PD0+P0BBQkNERUZH4+A=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.crc == 0xE0E3
    assert payload.length == 144
    assert payload.msg_type == 0xC09
    assert payload.payload == "AAECAwQFBgcICQoLDA0ODxAREhMKCwwNDg8QERITAAECAwQFBgcICRQVFhcYGRobHB0KCwwNDg8QERIT6AcDHgwiOxXNWwdIAAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc4OTo7PD0+P0BBQkNERUZH"
    assert payload.preamble == 0x55
    assert payload.sender == 0x42
    assert dictify(obj.payload.corrections_certificate) == snake_case_keys( [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19] )
    assert dictify(obj.payload.expiration) == snake_case_keys( {'day': 30, 'hours': 12, 'minutes': 34, 'month': 3, 'ns': 123456789, 'seconds': 59, 'year': 2024} )
    assert dictify(obj.payload.intermediate_certificate) == snake_case_keys( [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9] )
    assert dictify(obj.payload.root_certificate) == snake_case_keys( [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19] )
    assert dictify(obj.payload.signature) == snake_case_keys( {'data': [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71], 'len': 72} )

    assert dictify(payload) == snake_case_keys( {"preamble": 85, "msg_type": 3081, "sender": 66, "length": 144, "payload": "AAECAwQFBgcICQoLDA0ODxAREhMKCwwNDg8QERITAAECAwQFBgcICRQVFhcYGRobHB0KCwwNDg8QERIT6AcDHgwiOxXNWwdIAAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc4OTo7PD0+P0BBQkNERUZH", "crc": 57571, "root_certificate": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19], "intermediate_certificate": [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9], "corrections_certificate": [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19], "expiration": {"year": 2024, "month": 3, "day": 30, "hours": 12, "minutes": 34, "seconds": 59, "ns": 123456789}, "signature": {"len": 72, "data": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71]}} )