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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgLog.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # load all modules from SBP_PATH
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_logging_msg_log_1() {
    my $buf = decode_base64("VQEECgksBkZpbHRlcmVkIGFsbCBvYnMgZnJvbSAyMzE0IGF0IHRvdyA4My41MzkwMTmxow==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa3b1, "crc");
    
    is($msg->{'length'}, 44, "length");
    
    is($msg->{'msg_type'}, 0x0401, "msg_type");
    
    is($msg->{'payload'}, "BkZpbHRlcmVkIGFsbCBvYnMgZnJvbSAyMzE0IGF0IHRvdyA4My41MzkwMTk=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x90a, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->level(), 6, "level");
    
    is($msg->text(), "Filtered all obs from 2314 at tow 83.539019", "text");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":41905,"length":44,"level":6,"msg_type":1025,"payload":"BkZpbHRlcmVkIGFsbCBvYnMgZnJvbSAyMzE0IGF0IHRvdyA4My41MzkwMTk=","preamble":85,"sender":2314,"text":"Filtered all obs from 2314 at tow 83.539019"}})), "raw_json");
}
test_auto_check_sbp_logging_msg_log_1();

done_testing();