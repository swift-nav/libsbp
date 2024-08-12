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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfileDep.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_acquisition_msg_acq_sv_profile_dep_1():
    buf = base64.standard_b64decode("VR4AwwRpQ2eXAAwWAAAAuwBbAAAASwAAAIQAAAAkAAAAPAAAAPEAAADuJm8AsxcAAQCwAKYAAADqAAAAmwAAABgAAADUAAAA9wAAAI7VRAA1GAAAADQAMQAAAPUAAABMAAAA+AAAANQAAABlAAAAQ4Q=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x8443
    
    assert msg.length == 105
    
    assert msg.msg_type == 0x1e
    
    assert msg.payload == "Q2eXAAwWAAAAuwBbAAAASwAAAIQAAAAkAAAAPAAAAPEAAADuJm8AsxcAAQCwAKYAAADqAAAAmwAAABgAAADUAAAA9wAAAI7VRAA1GAAAADQAMQAAAPUAAABMAAAA+AAAANQAAABlAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.acq_sv_profile) == [{'bin_width': 187, 'cf': 60, 'cf_max': 36, 'cf_min': 132, 'cn0': 151, 'cp': 241, 'int_time': 12, 'job_type': 67, 'sid': {'code': 0, 'reserved': 0, 'sat': 22}, 'status': 103, 'time_spent': 75, 'timestamp': 91}, {'bin_width': 176, 'cf': 212, 'cf_max': 24, 'cf_min': 155, 'cn0': 111, 'cp': 247, 'int_time': 179, 'job_type': 238, 'sid': {'code': 1, 'reserved': 0, 'sat': 23}, 'status': 38, 'time_spent': 234, 'timestamp': 166}, {'bin_width': 52, 'cf': 212, 'cf_max': 248, 'cf_min': 76, 'cn0': 68, 'cp': 101, 'int_time': 53, 'job_type': 142, 'sid': {'code': 0, 'reserved': 0, 'sat': 24}, 'status': 213, 'time_spent': 245, 'timestamp': 49}]

    assert dictify(msg) == {'crc': 33859, 'length': 105, 'msg_type': 30, 'payload': 'Q2eXAAwWAAAAuwBbAAAASwAAAIQAAAAkAAAAPAAAAPEAAADuJm8AsxcAAQCwAKYAAADqAAAAmwAAABgAAADUAAAA9wAAAI7VRAA1GAAAADQAMQAAAPUAAABMAAAA+AAAANQAAABlAAAA', 'preamble': 85, 'sender': 1219, 'acq_sv_profile': [{'job_type': 67, 'status': 103, 'cn0': 151, 'int_time': 12, 'sid': {'sat': 22, 'code': 0, 'reserved': 0}, 'bin_width': 187, 'timestamp': 91, 'time_spent': 75, 'cf_min': 132, 'cf_max': 36, 'cf': 60, 'cp': 241}, {'job_type': 238, 'status': 38, 'cn0': 111, 'int_time': 179, 'sid': {'sat': 23, 'code': 1, 'reserved': 0}, 'bin_width': 176, 'timestamp': 166, 'time_spent': 234, 'cf_min': 155, 'cf_max': 24, 'cf': 212, 'cp': 247}, {'job_type': 142, 'status': 213, 'cn0': 68, 'int_time': 53, 'sid': {'sat': 24, 'code': 0, 'reserved': 0}, 'bin_width': 52, 'timestamp': 49, 'time_spent': 245, 'cf_min': 76, 'cf_max': 248, 'cf': 212, 'cp': 101}]}