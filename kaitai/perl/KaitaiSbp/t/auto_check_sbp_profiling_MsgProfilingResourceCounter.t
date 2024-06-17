#!/usr/bin/perl -w
#
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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingResourceCounter.yaml
# with generate.py.  Do not modify by hand!

use strict;

BEGIN {
    # add grandparent directory to include path
    use Cwd qw(realpath);
    use File::Basename;
    unshift @INC, realpath(dirname($0))."/../../";
}

use KaitaiSbp::Sbp;
use KaitaiSbp::ParseUtils;
use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_profiling_msg_profiling_resource_counter_1() {
    my $buf = decode_base64("VQPPABD4AQNGdXNpb24gZW5naW5lAAAAAAAAAAABAgIA+CYOAAAAAAAAAAAAAAAAAE5UUklQIGNsaWVudAAAAAAAAAAAAAEBAQHmSQEAAAAAAG8DAABATAAAU1NSMk9TUgAAAAAAAAAAAAAAAAAAAQEBAEgNQgAAAAAAAAAAAAAAAABQZXJpb2RpYwAAAAAAAAAAAAAAAAABAgEASMUDAAAAAAAAAAAAAAAAAElNVQAAAAAAAAAAAAAAAAAAAAAAAAEBAQGBRwAAAAAAAAAAAABfZgAAc2JwAAAAAAAAAAAAAAAAAAAAAAAABQICAvOpAAAAAAAAu5cDAPIBAAC1mQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x99b5, "crc");
    
    is($msg->{'length'}, 248, "length");
    
    is($msg->{'msg_type'}, 0xcf03, "msg_type");
    
    is($msg->{'payload'}, "AQNGdXNpb24gZW5naW5lAAAAAAAAAAABAgIA+CYOAAAAAAAAAAAAAAAAAE5UUklQIGNsaWVudAAAAAAAAAAAAAEBAQHmSQEAAAAAAG8DAABATAAAU1NSMk9TUgAAAAAAAAAAAAAAAAAAAQEBAEgNQgAAAAAAAAAAAAAAAABQZXJpb2RpYwAAAAAAAAAAAAAAAAABAgEASMUDAAAAAAAAAAAAAAAAAElNVQAAAAAAAAAAAAAAAAAAAAAAAAEBAQGBRwAAAAAAAAAAAABfZgAAc2JwAAAAAAAAAAAAAAAAAAAAAAAABQICAvOpAAAAAAAAu5cDAPIBAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->buckets()), $json->encode($json->decode(q{[{"cv":2,"heap_bytes_alloc":927480,"heap_bytes_free":0,"io":0,"io_read":0,"io_write":0,"mutex":2,"name":"Fusion engine\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":1,"heap_bytes_alloc":84454,"heap_bytes_free":0,"io":1,"io_read":19520,"io_write":879,"mutex":1,"name":"NTRIP client\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":1,"heap_bytes_alloc":4328776,"heap_bytes_free":0,"io":0,"io_read":0,"io_write":0,"mutex":1,"name":"SSR2OSR\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":1,"heap_bytes_alloc":247112,"heap_bytes_free":0,"io":0,"io_read":0,"io_write":0,"mutex":2,"name":"Periodic\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":1,"heap_bytes_alloc":18305,"heap_bytes_free":0,"io":1,"io_read":26207,"io_write":0,"mutex":1,"name":"IMU\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":2,"heap_bytes_alloc":43507,"heap_bytes_free":0,"io":2,"io_read":498,"io_write":235451,"mutex":2,"name":"sbp\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":5}]})), "buckets");
    
    is($msg->seq_len(), 3, "seq_len");
    
    is($msg->seq_no(), 1, "seq_no");

    is($json->encode($msg), $json->encode($json->decode(q{{"buckets":[{"cv":2,"heap_bytes_alloc":927480,"heap_bytes_free":0,"io":0,"io_read":0,"io_write":0,"mutex":2,"name":"Fusion engine\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":1,"heap_bytes_alloc":84454,"heap_bytes_free":0,"io":1,"io_read":19520,"io_write":879,"mutex":1,"name":"NTRIP client\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":1,"heap_bytes_alloc":4328776,"heap_bytes_free":0,"io":0,"io_read":0,"io_write":0,"mutex":1,"name":"SSR2OSR\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":1,"heap_bytes_alloc":247112,"heap_bytes_free":0,"io":0,"io_read":0,"io_write":0,"mutex":2,"name":"Periodic\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":1,"heap_bytes_alloc":18305,"heap_bytes_free":0,"io":1,"io_read":26207,"io_write":0,"mutex":1,"name":"IMU\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":1},{"cv":2,"heap_bytes_alloc":43507,"heap_bytes_free":0,"io":2,"io_read":498,"io_write":235451,"mutex":2,"name":"sbp\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","thread":5}],"crc":39349,"length":248,"msg_type":52995,"payload":"AQNGdXNpb24gZW5naW5lAAAAAAAAAAABAgIA+CYOAAAAAAAAAAAAAAAAAE5UUklQIGNsaWVudAAAAAAAAAAAAAEBAQHmSQEAAAAAAG8DAABATAAAU1NSMk9TUgAAAAAAAAAAAAAAAAAAAQEBAEgNQgAAAAAAAAAAAAAAAABQZXJpb2RpYwAAAAAAAAAAAAAAAAABAgEASMUDAAAAAAAAAAAAAAAAAElNVQAAAAAAAAAAAAAAAAAAAAAAAAEBAQGBRwAAAAAAAAAAAABfZgAAc2JwAAAAAAAAAAAAAAAAAAAAAAAABQICAvOpAAAAAAAAu5cDAPIBAAA=","preamble":85,"sender":4096,"seq_len":3,"seq_no":1}})), "raw_json");
}
test_auto_check_sbp_profiling_msg_profiling_resource_counter_1();

done_testing();