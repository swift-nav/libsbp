#!/usr/bin/perl -w
#
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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingSystemInfo.yaml
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
sub test_auto_check_sbp_profiling_msg_profiling_system_info_1() {
    my $buf = decode_base64("VQHPABAVYig0AAAAAAByDJ0AAAAAABtIw+IA/EE=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x41fc, "crc");
    
    is($msg->{'length'}, 21, "length");
    
    is($msg->{'msg_type'}, 0xcf01, "msg_type");
    
    is($msg->{'payload'}, "Yig0AAAAAAByDJ0AAAAAABtIw+IA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->age(), 10292338, "age");
    
    is($msg->heap_usage(), 14861128, "heap_usage");
    
    is($msg->n_threads(), 27, "n_threads");
    
    is($msg->total_cpu_time(), 3418210, "total_cpu_time");

    is($json->encode($msg), $json->encode($json->decode(q{{"age":10292338,"crc":16892,"heap_usage":14861128,"length":21,"msg_type":52993,"n_threads":27,"payload":"Yig0AAAAAAByDJ0AAAAAABtIw+IA","preamble":85,"sender":4096,"total_cpu_time":3418210}})), "raw_json");
}
test_auto_check_sbp_profiling_msg_profiling_system_info_1();

done_testing();