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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCTime.yaml
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
sub test_auto_check_sbp_navigation_msg_utc_time_1() {
    my $buf = decode_base64("VQMBFQMQARjl6R3lBwQJExgJAAivL8f9");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xfdc7, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x103, "msg_type");
    
    is($msg->{'payload'}, "ARjl6R3lBwQJExgJAAivLw==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x315, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->day(), 9, "day");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->hours(), 19, "hours");
    
    is($msg->minutes(), 24, "minutes");
    
    is($msg->month(), 4, "month");
    
    is($msg->ns(), 800000000, "ns");
    
    is($msg->seconds(), 9, "seconds");
    
    is($msg->tow(), 501867800, "tow");
    
    is($msg->year(), 2021, "year");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":64967,"day":9,"flags":1,"hours":19,"length":16,"minutes":24,"month":4,"msg_type":259,"ns":800000000,"payload":"ARjl6R3lBwQJExgJAAivLw==","preamble":85,"seconds":9,"sender":789,"tow":501867800,"year":2021}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_utc_time_1();

done_testing();