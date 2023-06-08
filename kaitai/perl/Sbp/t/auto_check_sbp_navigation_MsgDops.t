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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDops.yaml
# with generate.py.  Do not modify by hand!

use strict;

BEGIN {
    # add grandparent directory to include path
    use Cwd qw(realpath);
    use File::Basename;
    unshift @INC, realpath(dirname($0))."/../../";
}

use Sbp::Sbp;
use Sbp::ParseUtils;
use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_navigation_msg_dops_1() {
    my $buf = decode_base64("VQgCQgAPZAAAAAIABgAFAAUABQAA9AQ=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4f4, "crc");
    
    is($msg->{'length'}, 15, "length");
    
    is($msg->{'msg_type'}, 0x208, "msg_type");
    
    is($msg->{'payload'}, "ZAAAAAIABgAFAAUABQAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->gdop(), 2, "gdop");
    
    is($msg->hdop(), 5, "hdop");
    
    is($msg->pdop(), 6, "pdop");
    
    is($msg->tdop(), 5, "tdop");
    
    is($msg->tow(), 100, "tow");
    
    is($msg->vdop(), 5, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":1268,"flags":0,"gdop":2,"hdop":5,"length":15,"msg_type":520,"payload":"ZAAAAAIABgAFAAUABQAA","pdop":6,"preamble":85,"sender":66,"tdop":5,"tow":100,"vdop":5}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_dops_1();

done_testing();