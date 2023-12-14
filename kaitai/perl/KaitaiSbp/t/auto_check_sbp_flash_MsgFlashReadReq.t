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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashReadReq.yaml
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
sub test_auto_check_sbp_flash_msg_flash_read_req_1() {
    my $buf = decode_base64("VecAwwQF8RxL9EfSOQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x39d2, "crc");
    
    is($msg->{'length'}, 5, "length");
    
    is($msg->{'msg_type'}, 0xe7, "msg_type");
    
    is($msg->{'payload'}, "8RxL9Ec=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->addr_len(), 71, "addr_len");
    
    is($json->encode($msg->addr_start()), $json->encode($json->decode(q{[28,75,244]})), "addr_start");
    
    is($msg->target(), 241, "target");

    is($json->encode($msg), $json->encode($json->decode(q{{"addr_len":71,"addr_start":[28,75,244],"crc":14802,"length":5,"msg_type":231,"payload":"8RxL9Ec=","preamble":85,"sender":1219,"target":241}})), "raw_json");
}
test_auto_check_sbp_flash_msg_flash_read_req_1();

done_testing();