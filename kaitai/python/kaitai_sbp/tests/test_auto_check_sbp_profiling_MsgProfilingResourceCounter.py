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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingResourceCounter.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_profiling_msg_profiling_resource_counter_1():
    buf = base64.standard_b64decode("VQPPABD4AQNGdXNpb24gZW5naW5lAAAAAAAAAAABAgIA+CYOAAAAAAAAAAAAAAAAAE5UUklQIGNsaWVudAAAAAAAAAAAAAEBAQHmSQEAAAAAAG8DAABATAAAU1NSMk9TUgAAAAAAAAAAAAAAAAAAAQEBAEgNQgAAAAAAAAAAAAAAAABQZXJpb2RpYwAAAAAAAAAAAAAAAAABAgEASMUDAAAAAAAAAAAAAAAAAElNVQAAAAAAAAAAAAAAAAAAAAAAAAEBAQGBRwAAAAAAAAAAAABfZgAAc2JwAAAAAAAAAAAAAAAAAAAAAAAABQICAvOpAAAAAAAAu5cDAPIBAAC1mQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x99b5
    
    assert msg.length == 248
    
    assert msg.msg_type == 0xcf03
    
    assert msg.payload == "AQNGdXNpb24gZW5naW5lAAAAAAAAAAABAgIA+CYOAAAAAAAAAAAAAAAAAE5UUklQIGNsaWVudAAAAAAAAAAAAAEBAQHmSQEAAAAAAG8DAABATAAAU1NSMk9TUgAAAAAAAAAAAAAAAAAAAQEBAEgNQgAAAAAAAAAAAAAAAABQZXJpb2RpYwAAAAAAAAAAAAAAAAABAgEASMUDAAAAAAAAAAAAAAAAAElNVQAAAAAAAAAAAAAAAAAAAAAAAAEBAQGBRwAAAAAAAAAAAABfZgAAc2JwAAAAAAAAAAAAAAAAAAAAAAAABQICAvOpAAAAAAAAu5cDAPIBAAA="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x1000
    
    assert dictify(msg.buckets) == [{'name': 'Fusion engine\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 2, 'cv': 2, 'io': 0, 'heap_bytes_alloc': 927480, 'heap_bytes_free': 0, 'io_write': 0, 'io_read': 0}, {'name': 'NTRIP client\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 1, 'cv': 1, 'io': 1, 'heap_bytes_alloc': 84454, 'heap_bytes_free': 0, 'io_write': 879, 'io_read': 19520}, {'name': 'SSR2OSR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 1, 'cv': 1, 'io': 0, 'heap_bytes_alloc': 4328776, 'heap_bytes_free': 0, 'io_write': 0, 'io_read': 0}, {'name': 'Periodic\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 2, 'cv': 1, 'io': 0, 'heap_bytes_alloc': 247112, 'heap_bytes_free': 0, 'io_write': 0, 'io_read': 0}, {'name': 'IMU\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 1, 'cv': 1, 'io': 1, 'heap_bytes_alloc': 18305, 'heap_bytes_free': 0, 'io_write': 0, 'io_read': 26207}, {'name': 'sbp\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 5, 'mutex': 2, 'cv': 2, 'io': 2, 'heap_bytes_alloc': 43507, 'heap_bytes_free': 0, 'io_write': 235451, 'io_read': 498}]
    
    assert dictify(msg.seq_len) == 3
    
    assert dictify(msg.seq_no) == 1

    assert dictify(msg) == {'crc': 39349, 'preamble': 85, 'sender': 4096, 'length': 248, 'msg_type': 52995, 'seq_no': 1, 'seq_len': 3, 'buckets': [{'name': 'Fusion engine\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 2, 'cv': 2, 'io': 0, 'heap_bytes_alloc': 927480, 'heap_bytes_free': 0, 'io_write': 0, 'io_read': 0}, {'name': 'NTRIP client\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 1, 'cv': 1, 'io': 1, 'heap_bytes_alloc': 84454, 'heap_bytes_free': 0, 'io_write': 879, 'io_read': 19520}, {'name': 'SSR2OSR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 1, 'cv': 1, 'io': 0, 'heap_bytes_alloc': 4328776, 'heap_bytes_free': 0, 'io_write': 0, 'io_read': 0}, {'name': 'Periodic\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 2, 'cv': 1, 'io': 0, 'heap_bytes_alloc': 247112, 'heap_bytes_free': 0, 'io_write': 0, 'io_read': 0}, {'name': 'IMU\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 1, 'mutex': 1, 'cv': 1, 'io': 1, 'heap_bytes_alloc': 18305, 'heap_bytes_free': 0, 'io_write': 0, 'io_read': 26207}, {'name': 'sbp\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00', 'thread': 5, 'mutex': 2, 'cv': 2, 'io': 2, 'heap_bytes_alloc': 43507, 'heap_bytes_free': 0, 'io_write': 235451, 'io_read': 498}], 'payload': 'AQNGdXNpb24gZW5naW5lAAAAAAAAAAABAgIA+CYOAAAAAAAAAAAAAAAAAE5UUklQIGNsaWVudAAAAAAAAAAAAAEBAQHmSQEAAAAAAG8DAABATAAAU1NSMk9TUgAAAAAAAAAAAAAAAAAAAQEBAEgNQgAAAAAAAAAAAAAAAABQZXJpb2RpYwAAAAAAAAAAAAAAAAABAgEASMUDAAAAAAAAAAAAAAAAAElNVQAAAAAAAAAAAAAAAAAAAAAAAAEBAQGBRwAAAAAAAAAAAABfZgAAc2JwAAAAAAAAAAAAAAAAAAAAAAAABQICAvOpAAAAAAAAu5cDAPIBAAA='}