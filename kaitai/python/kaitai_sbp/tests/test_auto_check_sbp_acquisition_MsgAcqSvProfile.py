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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfile.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_acquisition_msg_acq_sv_profile_1():
    buf = base64.standard_b64decode("VS4AwwRjBw0mAGEWAK4ANAAAADEAAAA9AAAAkwAAAC8AAACMAAAAptI7AP0XAXkAvgAAAK8AAACvAAAAjgAAAO0AAAAMAAAAflgVAJkYAAgAggAAAKwAAABbAAAAvwAAAFQAAABSAAAAqLE=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb1a8
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x2e
    
    assert msg.payload == "Bw0mAGEWAK4ANAAAADEAAAA9AAAAkwAAAC8AAACMAAAAptI7AP0XAXkAvgAAAK8AAACvAAAAjgAAAO0AAAAMAAAAflgVAJkYAAgAggAAAKwAAABbAAAAvwAAAFQAAABSAAAA"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.acq_sv_profile) == [{'bin_width': 174, 'cf': 47, 'cf_max': 147, 'cf_min': 61, 'cn0': 38, 'cp': 140, 'int_time': 97, 'job_type': 7, 'sid': {'code': 0, 'sat': 22}, 'status': 13, 'time_spent': 49, 'timestamp': 52}, {'bin_width': 121, 'cf': 237, 'cf_max': 142, 'cf_min': 175, 'cn0': 59, 'cp': 12, 'int_time': 253, 'job_type': 166, 'sid': {'code': 1, 'sat': 23}, 'status': 210, 'time_spent': 175, 'timestamp': 190}, {'bin_width': 8, 'cf': 84, 'cf_max': 191, 'cf_min': 91, 'cn0': 21, 'cp': 82, 'int_time': 153, 'job_type': 126, 'sid': {'code': 0, 'sat': 24}, 'status': 88, 'time_spent': 172, 'timestamp': 130}]

    assert dictify(msg) == {'crc': 45480, 'length': 99, 'msg_type': 46, 'payload': 'Bw0mAGEWAK4ANAAAADEAAAA9AAAAkwAAAC8AAACMAAAAptI7AP0XAXkAvgAAAK8AAACvAAAAjgAAAO0AAAAMAAAAflgVAJkYAAgAggAAAKwAAABbAAAAvwAAAFQAAABSAAAA', 'preamble': 85, 'sender': 1219, 'acq_sv_profile': [{'job_type': 7, 'status': 13, 'cn0': 38, 'int_time': 97, 'sid': {'sat': 22, 'code': 0}, 'bin_width': 174, 'timestamp': 52, 'time_spent': 49, 'cf_min': 61, 'cf_max': 147, 'cf': 47, 'cp': 140}, {'job_type': 166, 'status': 210, 'cn0': 59, 'int_time': 253, 'sid': {'sat': 23, 'code': 1}, 'bin_width': 121, 'timestamp': 190, 'time_spent': 175, 'cf_min': 175, 'cf_max': 142, 'cf': 237, 'cp': 12}, {'job_type': 126, 'status': 88, 'cn0': 21, 'int_time': 153, 'sid': {'sat': 24, 'code': 0}, 'bin_width': 8, 'timestamp': 130, 'time_spent': 172, 'cf_min': 91, 'cf_max': 191, 'cf': 84, 'cp': 82}]}