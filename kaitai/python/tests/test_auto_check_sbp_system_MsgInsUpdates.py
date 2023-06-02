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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgInsUpdates.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_ins_updates_1():
    buf = base64.standard_b64decode("VQb/FQMKVOURHgAAAAAAAFE/")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = dictify(get_payload(obj))
    orig_dict = {"tow":504489300,"gnsspos":0,"gnssvel":0,"wheelticks":0,"speed":0,"nhc":0,"zerovel":0,"preamble":85,"msg_type":65286,"sender":789,"payload":"VOURHgAAAAAAAA==","crc":16209,"length":10}
    assert parsed_dict['crc'] == 0x3f51
    assert parsed_dict['length'] == 10
    assert parsed_dict['payload'] == "VOURHgAAAAAAAA=="
    assert parsed_dict['msg_type'] == 0xff06
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x315
    assert dictify(obj.payload.gnsspos) == snake_case_keys( 0 )
    assert dictify(obj.payload.gnssvel) == snake_case_keys( 0 )
    assert dictify(obj.payload.nhc) == snake_case_keys( 0 )
    assert dictify(obj.payload.speed) == snake_case_keys( 0 )
    assert dictify(obj.payload.tow) == snake_case_keys( 504489300 )
    assert dictify(obj.payload.wheelticks) == snake_case_keys( 0 )
    assert dictify(obj.payload.zerovel) == snake_case_keys( 0 )

    assert parsed_dict == snake_case_keys(orig_dict)