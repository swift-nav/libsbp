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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgBootloaderJumptoApp.yaml
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
sub test_auto_check_sbp_bootload_msg_bootloader_jumpto_app_1() {
    my $buf = decode_base64("VbEAzRIB2Glg");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6069, "crc");
    
    is($msg->{'length'}, 1, "length");
    
    is($msg->{'msg_type'}, 0xb1, "msg_type");
    
    is($msg->{'payload'}, "2A==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x12cd, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->jump(), 216, "jump");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":24681,"jump":216,"length":1,"msg_type":177,"payload":"2A==","preamble":85,"sender":4813}})), "raw_json");
}
test_auto_check_sbp_bootload_msg_bootloader_jumpto_app_1();

done_testing();
