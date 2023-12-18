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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ndb/test_MsgNdbEvent.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ndb_msg_ndb_event_1():
    buf = base64.standard_b64decode("VQAEpK4S/rxGuUUAAAD5Sc1z7kpiQraUEKY=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa610
    
    assert msg.length == 18
    
    assert msg.msg_type == 0x400
    
    assert msg.payload == "/rxGuUUAAAD5Sc1z7kpiQraU"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xaea4
    
    assert dictify(msg.data_source) == 115
    
    assert dictify(msg.event) == 249
    
    assert dictify(msg.object_sid) == {'code': 74, 'sat': 238}
    
    assert dictify(msg.object_type) == 73
    
    assert dictify(msg.original_sender) == 38070
    
    assert dictify(msg.recv_time) == 299461164286
    
    assert dictify(msg.result) == 205
    
    assert dictify(msg.src_sid) == {'code': 66, 'sat': 98}

    assert dictify(msg) == {'preamble': 85, 'msg_type': 1024, 'sender': 44708, 'length': 18, 'payload': '/rxGuUUAAAD5Sc1z7kpiQraU', 'crc': 42512, 'recv_time': 299461164286, 'event': 249, 'object_type': 73, 'result': 205, 'data_source': 115, 'object_sid': {'sat': 238, 'code': 74}, 'src_sid': {'sat': 98, 'code': 66}, 'original_sender': 38070}