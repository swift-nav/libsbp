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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGnssTimeOffset.yaml
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
sub test_auto_check_sbp_system_msg_gnss_time_offset_1() {
    my $buf = decode_base64("VQf/Fg8JCTpSUwlnFiXdVGQ=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6454, "crc");
    
    is($msg->{'length'}, 9, "length");
    
    is($msg->{'msg_type'}, 0xff07, "msg_type");
    
    is($msg->{'payload'}, "CTpSUwlnFiXd", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x0f16, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 221, "flags");
    
    is($msg->microseconds(), 9494, "microseconds");
    
    is($msg->milliseconds(), 1728664402, "milliseconds");
    
    is($msg->weeks(), 14857, "weeks");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":25684,"flags":221,"length":9,"microseconds":9494,"milliseconds":1728664402,"msg_type":65287,"payload":"CTpSUwlnFiXd","preamble":85,"sender":3862,"weeks":14857}})), "raw_json");
}
test_auto_check_sbp_system_msg_gnss_time_offset_1();

done_testing();
