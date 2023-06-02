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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgInsStatus.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_ins_status_1():
    buf = base64.standard_b64decode("VQP/FQMECQAAICRn")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"flags":536870921,"preamble":85,"msg_type":65283,"sender":789,"payload":"CQAAIA==","crc":26404,"length":4}
    assert parsed_dict['crc'] == 0x6724
    assert parsed_dict['length'] == 4
    assert parsed_dict['payload'] == "CQAAIA=="
    assert parsed_dict['msg_type'] == 0xff03
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x315
    assert dictify(obj.payload.flags) == snake_case_keys( 536870921 )

    assert parsed_dict == snake_case_keys(orig_dict)