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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/vehicle/test_MsgWheeltick.yaml
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
sub test_auto_check_sbp_vehicle_msg_wheeltick_1() {
    my $buf = decode_base64("VQQJa0UO/htyLBoAAAABkuEzCdIkOA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3824, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x904, "msg_type");
    
    is($msg->{'payload'}, "/htyLBoAAAABkuEzCdI=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x456b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 1, "flags");
    
    is($msg->source(), 146, "source");
    
    is($msg->ticks(), -771148831, "ticks");
    
    is($msg->time(), 112414825470, "time");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":14372,"flags":1,"length":14,"msg_type":2308,"payload":"/htyLBoAAAABkuEzCdI=","preamble":85,"sender":17771,"source":146,"ticks":-771148831,"time":112414825470}})), "raw_json");
}
test_auto_check_sbp_vehicle_msg_wheeltick_1();

done_testing();