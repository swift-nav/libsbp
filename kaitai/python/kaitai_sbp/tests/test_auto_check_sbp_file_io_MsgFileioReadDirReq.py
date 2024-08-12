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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadDirReq.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_file_io_msg_fileio_read_dir_req_1():
    buf = base64.standard_b64decode("VakAwwQaguf/WsSGL4Yvc29tZS9yYW5kb20vcGF0aAAaug==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xba1a
    
    assert msg.length == 26
    
    assert msg.msg_type == 0xa9
    
    assert msg.payload == "guf/WsSGL4Yvc29tZS9yYW5kb20vcGF0aAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.dirname) == "/some/random/path\x00"
    
    assert dictify(msg.offset) == 2251261636
    
    assert dictify(msg.sequence) == 1526720386

    assert dictify(msg) == {'preamble': 85, 'msg_type': 169, 'sender': 1219, 'length': 26, 'payload': 'guf/WsSGL4Yvc29tZS9yYW5kb20vcGF0aAA=', 'crc': 47642, 'sequence': 1526720386, 'offset': 2251261636, 'dirname': '/some/random/path\x00'}