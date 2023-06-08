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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientEuler.yaml
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
sub test_auto_check_sbp_orientation_msg_orient_euler_1() {
    my $buf = decode_base64("VSECQgAdAQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAMs4g==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe22c, "crc");
    
    is($msg->{'length'}, 29, "length");
    
    is($msg->{'msg_type'}, 0x221, "msg_type");
    
    is($msg->{'payload'}, "AQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAM=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 3, "flags");
    
    is($msg->pitch(), 2, "pitch");
    
    is($msg->pitch_accuracy(), 3.0, "pitch_accuracy");
    
    is($msg->roll(), 1, "roll");
    
    is($msg->roll_accuracy(), 7.0, "roll_accuracy");
    
    is($msg->tow(), 1, "tow");
    
    is($msg->yaw(), 8, "yaw");
    
    is($msg->yaw_accuracy(), 7.0, "yaw_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":57900,"flags":3,"length":29,"msg_type":545,"payload":"AQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAM=","pitch":2,"pitch_accuracy":3,"preamble":85,"roll":1,"roll_accuracy":7,"sender":66,"tow":1,"yaw":8,"yaw_accuracy":7}})), "raw_json");
}
test_auto_check_sbp_orientation_msg_orient_euler_1();

done_testing();