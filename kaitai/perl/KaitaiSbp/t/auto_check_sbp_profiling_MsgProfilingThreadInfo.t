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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingThreadInfo.yaml
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
sub test_auto_check_sbp_profiling_msg_profiling_thread_info_1() {
    my $buf = decode_base64("VQLPABAnd1sKAAAAAABuBZsAAAAAAAEAAIAA0DUEAEZ1c2lvbiBlbmdpbmUA8qo=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xaaf2, "crc");
    
    is($msg->{'length'}, 39, "length");
    
    is($msg->{'msg_type'}, 0xcf02, "msg_type");
    
    is($msg->{'payload'}, "d1sKAAAAAABuBZsAAAAAAAEAAIAA0DUEAEZ1c2lvbiBlbmdpbmUA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->age(), 10159470, "age");
    
    is($msg->name(), "Fusion engine\x00", "name");
    
    is($msg->stack_size(), 8388608, "stack_size");
    
    is($msg->stack_usage(), 275920, "stack_usage");
    
    is($msg->state(), 1, "state");
    
    is($msg->total_cpu_time(), 678775, "total_cpu_time");

    is($json->encode($msg), $json->encode($json->decode(q{{"age":10159470,"crc":43762,"length":39,"msg_type":52994,"name":"Fusion engine\u0000","payload":"d1sKAAAAAABuBZsAAAAAAAEAAIAA0DUEAEZ1c2lvbiBlbmdpbmUA","preamble":85,"sender":4096,"stack_size":8388608,"stack_usage":275920,"state":1,"total_cpu_time":678775}})), "raw_json");
}
test_auto_check_sbp_profiling_msg_profiling_thread_info_1();

done_testing();
