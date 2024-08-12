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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedGnss.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_ned_gnss_1() {
    my $buf = decode_base64("VS4CABAWqObpHfv///8AAAAA9v///ygAWQAVAmOr");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xab63, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x22e, "msg_type");
    
    is($msg->{'payload'}, "qObpHfv///8AAAAA9v///ygAWQAVAg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -10, "d");
    
    is($msg->e(), 0, "e");
    
    is($msg->flags(), 2, "flags");
    
    is($msg->h_accuracy(), 40, "h_accuracy");
    
    is($msg->n(), -5, "n");
    
    is($msg->n_sats(), 21, "n_sats");
    
    is($msg->tow(), 501868200, "tow");
    
    is($msg->v_accuracy(), 89, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":43875,"d":-10,"e":0,"flags":2,"h_accuracy":40,"length":22,"msg_type":558,"n":-5,"n_sats":21,"payload":"qObpHfv///8AAAAA9v///ygAWQAVAg==","preamble":85,"sender":4096,"tow":501868200,"v_accuracy":89}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_ned_gnss_1();

done_testing();