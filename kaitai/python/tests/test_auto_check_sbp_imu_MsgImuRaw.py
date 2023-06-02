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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuRaw.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_imu_msg_imu_raw_1():
    buf = base64.standard_b64decode("VQAJNBIRGgEAwM5gAN//LBA8AND+7v9Ghw==")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"tow":3221225754,"tow_f":206,"acc_x":96,"acc_y":-33,"acc_z":4140,"gyr_x":60,"gyr_y":-304,"gyr_z":-18,"preamble":85,"msg_type":2304,"sender":4660,"payload":"GgEAwM5gAN//LBA8AND+7v8=","crc":34630,"length":17}
    assert parsed_dict['crc'] == 0x8746
    assert parsed_dict['length'] == 17
    assert parsed_dict['msg_type'] == 0x900
    assert parsed_dict['payload'] == "GgEAwM5gAN//LBA8AND+7v8="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x1234
    assert dictify(obj.payload.acc_x) == snake_case_keys( 96 )
    assert dictify(obj.payload.acc_y) == snake_case_keys( -33 )
    assert dictify(obj.payload.acc_z) == snake_case_keys( 4140 )
    assert dictify(obj.payload.gyr_x) == snake_case_keys( 60 )
    assert dictify(obj.payload.gyr_y) == snake_case_keys( -304 )
    assert dictify(obj.payload.gyr_z) == snake_case_keys( -18 )
    assert dictify(obj.payload.tow) == snake_case_keys( 3221225754 )
    assert dictify(obj.payload.tow_f) == snake_case_keys( 206 )

    assert parsed_dict == snake_case_keys(orig_dict)