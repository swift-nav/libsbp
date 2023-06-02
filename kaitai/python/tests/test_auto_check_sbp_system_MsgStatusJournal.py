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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusJournal.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_system_msg_status_journal_1():
    buf = base64.standard_b64decode("Vf3/04ghAQABBGQAAAAQkhAAAAYAAQ26EwAABgABDrgiAAAGAAEPcXc=")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"preamble": 85, "msg_type": 65533, "sender": 35027, "length": 33, "payload": "AQABBGQAAAAQkhAAAAYAAQ26EwAABgABDrgiAAAGAAEP", "crc": 30577, "reporting_system": 1, "sbp_version": 1025, "total_status_reports": 100, "sequence_descriptor": 16, "journal": [{"uptime": 4242, "report": {"component": 6, "generic": 1, "specific": 13}}, {"uptime": 5050, "report": {"component": 6, "generic": 1, "specific": 14}}, {"uptime": 8888, "report": {"component": 6, "generic": 1, "specific": 15}}]}
    assert parsed_dict['crc'] == 0x7771
    assert parsed_dict['length'] == 33
    assert parsed_dict['msg_type'] == 0xFFFD
    assert parsed_dict['payload'] == "AQABBGQAAAAQkhAAAAYAAQ26EwAABgABDrgiAAAGAAEP"
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88D3
    assert dictify(obj.payload.journal) == snake_case_keys( [{'uptime': 4242, 'report': {'component': 6, 'generic': 1, 'specific': 13}}, {'uptime': 5050, 'report': {'component': 6, 'generic': 1, 'specific': 14}}, {'uptime': 8888, 'report': {'component': 6, 'generic': 1, 'specific': 15}}] )
    assert dictify(obj.payload.reporting_system) == snake_case_keys( 1 )
    assert dictify(obj.payload.sbp_version) == snake_case_keys( 1025 )
    assert dictify(obj.payload.sequence_descriptor) == snake_case_keys( 16 )
    assert dictify(obj.payload.total_status_reports) == snake_case_keys( 100 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_system_msg_status_journal_2():
    buf = base64.standard_b64decode("Vf3/04gRAQABBGQAAAAQkhAAAAYAAQ2QeQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"preamble": 85, "msg_type": 65533, "sender": 35027, "length": 17, "payload": "AQABBGQAAAAQkhAAAAYAAQ0=", "crc": 31120, "reporting_system": 1, "sbp_version": 1025, "total_status_reports": 100, "sequence_descriptor": 16, "journal": [{"uptime": 4242, "report": {"component": 6, "generic": 1, "specific": 13}}]}
    assert parsed_dict['crc'] == 0x7990
    assert parsed_dict['length'] == 17
    assert parsed_dict['msg_type'] == 0xFFFD
    assert parsed_dict['payload'] == "AQABBGQAAAAQkhAAAAYAAQ0="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x88D3
    assert dictify(obj.payload.journal) == snake_case_keys( [{'report': {'component': 6, 'generic': 1, 'specific': 13}, 'uptime': 4242}] )
    assert dictify(obj.payload.reporting_system) == snake_case_keys( 1 )
    assert dictify(obj.payload.sbp_version) == snake_case_keys( 1025 )
    assert dictify(obj.payload.sequence_descriptor) == snake_case_keys( 16 )
    assert dictify(obj.payload.total_status_reports) == snake_case_keys( 100 )

    assert parsed_dict == snake_case_keys(orig_dict)