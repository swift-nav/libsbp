# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioConfigResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_file_io_msg_fileio_config_resp_1():
    buf = base64.standard_b64decode("VQIQwwQQqkw0W5W6LAPYl/89DGFCkO9z")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x73ef
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x1002
    
    assert msg.payload == "qkw0W5W6LAPYl/89DGFCkA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.batch_size) == 1040160728
    
    assert dictify(msg.fileio_version) == 2420269324
    
    assert dictify(msg.sequence) == 1530154154
    
    assert dictify(msg.window_size) == 53262997

    assert dictify(msg) == {'preamble': 85, 'msg_type': 4098, 'sender': 1219, 'length': 16, 'payload': 'qkw0W5W6LAPYl/89DGFCkA==', 'crc': 29679, 'sequence': 1530154154, 'window_size': 53262997, 'batch_size': 1040160728, 'fileio_version': 2420269324}