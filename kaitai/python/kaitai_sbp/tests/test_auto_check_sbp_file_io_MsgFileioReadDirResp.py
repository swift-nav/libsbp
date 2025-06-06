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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadDirResp.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_file_io_msg_fileio_read_dir_resp_1():
    buf = base64.standard_b64decode("VaoAwwQtTv3g62ZpbGUxAGFub3RoZXIgZmlsZQBkZWZpbml0ZWx5IG5vdCBhIGZpbGUAuok=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x89ba
    
    assert msg.length == 45
    
    assert msg.msg_type == 0xaa
    
    assert msg.payload == "Tv3g62ZpbGUxAGFub3RoZXIgZmlsZQBkZWZpbml0ZWx5IG5vdCBhIGZpbGUA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.contents) == "file1\x00another file\x00definitely not a file\x00"
    
    assert dictify(msg.sequence) == 3957390670

    assert dictify(msg) == {'preamble': 85, 'msg_type': 170, 'sender': 1219, 'length': 45, 'payload': 'Tv3g62ZpbGUxAGFub3RoZXIgZmlsZQBkZWZpbml0ZWx5IG5vdCBhIGZpbGUA', 'crc': 35258, 'sequence': 3957390670, 'contents': 'file1\x00another file\x00definitely not a file\x00'}
