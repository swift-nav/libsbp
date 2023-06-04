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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgInsStatus.yaml
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
sub test_auto_check_sbp_system_msg_ins_status_1() {
    my $buf = decode_base64("VQP/FQMECQAAICRn");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6724, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'payload'}, "CQAAIA==", "payload");
    
    is($msg->{'msg_type'}, 0xff03, "msg_type");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x315, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 536870921, "flags");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":26404,"flags":536870921,"length":4,"msg_type":65283,"payload":"CQAAIA==","preamble":85,"sender":789}})), "raw_json");
}
test_auto_check_sbp_system_msg_ins_status_1();

done_testing();