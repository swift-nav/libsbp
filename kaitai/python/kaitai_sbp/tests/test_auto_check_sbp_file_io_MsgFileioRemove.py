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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioRemove.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_file_io_msg_fileio_remove_1():
    buf = base64.standard_b64decode("VawAwwQOL3BhdGgvdG8vZmlsZQAu8w==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xf32e
    
    assert msg.length == 14
    
    assert msg.msg_type == 0xac
    
    assert msg.payload == "L3BhdGgvdG8vZmlsZQA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.filename) == "/path/to/file\x00"

    assert dictify(msg) == {'crc': 62254, 'length': 14, 'msg_type': 172, 'payload': 'L3BhdGgvdG8vZmlsZQA=', 'preamble': 85, 'sender': 1219, 'filename': '/path/to/file\x00'}
