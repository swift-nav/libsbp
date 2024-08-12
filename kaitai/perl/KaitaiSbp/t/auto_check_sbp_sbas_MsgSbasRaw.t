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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/sbas/test_MsgSbasRaw.yaml
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
sub test_auto_check_sbp_sbas_msg_sbas_raw_1() {
    my $buf = decode_base64("VXd3HMgigwLJ5OkdBBf/ABf/ABf/f/AC/8ADf/f/f/f/5eXuqq//8KcO");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xea7, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'payload'}, "gwLJ5OkdBBf/ABf/ABf/f/AC/8ADf/f/f/f/5eXuqq//8A==", "payload");
    
    is($msg->{'msg_type'}, 0x7777, "msg_type");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xc81c, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->data()), $json->encode($json->decode(q{[23,255,0,23,255,0,23,255,127,240,2,255,192,3,127,247,255,127,247,255,229,229,238,170,175,255,240]})), "data");
    
    is($msg->message_type(), 4, "message_type");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":2,"sat":131}})), "sid");
    
    is($msg->tow(), 501867721, "tow");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":3751,"data":[23,255,0,23,255,0,23,255,127,240,2,255,192,3,127,247,255,127,247,255,229,229,238,170,175,255,240],"length":34,"message_type":4,"msg_type":30583,"payload":"gwLJ5OkdBBf/ABf/ABf/f/AC/8ADf/f/f/f/5eXuqq//8A==","preamble":85,"sender":51228,"sid":{"code":2,"sat":131},"tow":501867721}})), "raw_json");
}
test_auto_check_sbp_sbas_msg_sbas_raw_1();

done_testing();