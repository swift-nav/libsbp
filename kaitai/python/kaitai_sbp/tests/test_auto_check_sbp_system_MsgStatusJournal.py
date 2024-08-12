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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusJournal.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_status_journal_1():
    buf = base64.standard_b64decode("Vf3/04ghAQABBGQAAAAQkhAAAAYAAQ26EwAABgABDrgiAAAGAAEPcXc=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7771
    
    assert msg.length == 33
    
    assert msg.msg_type == 0xFFFD
    
    assert msg.payload == "AQABBGQAAAAQkhAAAAYAAQ26EwAABgABDrgiAAAGAAEP"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88D3
    
    assert dictify(msg.journal) == [{'uptime': 4242, 'report': {'component': 6, 'generic': 1, 'specific': 13}}, {'uptime': 5050, 'report': {'component': 6, 'generic': 1, 'specific': 14}}, {'uptime': 8888, 'report': {'component': 6, 'generic': 1, 'specific': 15}}]
    
    assert dictify(msg.reporting_system) == 1
    
    assert dictify(msg.sbp_version) == 1025
    
    assert dictify(msg.sequence_descriptor) == 16
    
    assert dictify(msg.total_status_reports) == 100

    assert dictify(msg) == {'preamble': 85, 'msg_type': 65533, 'sender': 35027, 'length': 33, 'payload': 'AQABBGQAAAAQkhAAAAYAAQ26EwAABgABDrgiAAAGAAEP', 'crc': 30577, 'reporting_system': 1, 'sbp_version': 1025, 'total_status_reports': 100, 'sequence_descriptor': 16, 'journal': [{'uptime': 4242, 'report': {'component': 6, 'generic': 1, 'specific': 13}}, {'uptime': 5050, 'report': {'component': 6, 'generic': 1, 'specific': 14}}, {'uptime': 8888, 'report': {'component': 6, 'generic': 1, 'specific': 15}}]}

def test_auto_check_sbp_system_msg_status_journal_2():
    buf = base64.standard_b64decode("Vf3/04gRAQABBGQAAAAQkhAAAAYAAQ2QeQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x7990
    
    assert msg.length == 17
    
    assert msg.msg_type == 0xFFFD
    
    assert msg.payload == "AQABBGQAAAAQkhAAAAYAAQ0="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x88D3
    
    assert dictify(msg.journal) == [{'report': {'component': 6, 'generic': 1, 'specific': 13}, 'uptime': 4242}]
    
    assert dictify(msg.reporting_system) == 1
    
    assert dictify(msg.sbp_version) == 1025
    
    assert dictify(msg.sequence_descriptor) == 16
    
    assert dictify(msg.total_status_reports) == 100

    assert dictify(msg) == {'preamble': 85, 'msg_type': 65533, 'sender': 35027, 'length': 17, 'payload': 'AQABBGQAAAAQkhAAAAYAAQ0=', 'crc': 31120, 'reporting_system': 1, 'sbp_version': 1025, 'total_status_reports': 100, 'sequence_descriptor': 16, 'journal': [{'uptime': 4242, 'report': {'component': 6, 'generic': 1, 'specific': 13}}]}