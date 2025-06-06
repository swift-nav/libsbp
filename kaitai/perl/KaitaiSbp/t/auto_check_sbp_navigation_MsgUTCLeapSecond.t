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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCLeapSecond.yaml
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
sub test_auto_check_sbp_navigation_msg_utc_leap_second_1() {
    my $buf = decode_base64("VToCQgAOAQACAAMEBQAGAAcACAky6A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x023A, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'payload'}, "AQACAAMEBQAGAAcACAk=", "payload");
    
    is($msg->{'crc'}, 0xE832, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->count_after(), 9, "count_after");
    
    is($msg->count_before(), 4, "count_before");
    
    is($msg->ref_dn(), 8, "ref_dn");
    
    is($msg->ref_wn(), 7, "ref_wn");
    
    is($msg->reserved_0(), 1, "reserved_0");
    
    is($msg->reserved_1(), 2, "reserved_1");
    
    is($msg->reserved_2(), 3, "reserved_2");
    
    is($msg->reserved_3(), 5, "reserved_3");
    
    is($msg->reserved_4(), 6, "reserved_4");

    is($json->encode($msg), $json->encode($json->decode(q{{"count_after":9,"count_before":4,"crc":59442,"length":14,"msg_type":570,"payload":"AQACAAMEBQAGAAcACAk=","preamble":85,"ref_dn":8,"ref_wn":7,"reserved_0":1,"reserved_1":2,"reserved_2":3,"reserved_3":5,"reserved_4":6,"sender":66}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_utc_leap_second_1();

done_testing();
