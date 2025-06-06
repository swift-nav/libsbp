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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineHeadingDepA.yaml
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
sub test_auto_check_sbp_navigation_msg_baseline_heading_dep_a_1() {
    my $buf = decode_base64("VQcCfM4KUm1YsEQOUsu6Oq22");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb6ad, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'msg_type'}, 0x207, "msg_type");
    
    is($msg->{'payload'}, "Um1YsEQOUsu6Og==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xce7c, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 58, "flags");
    
    is($msg->heading(), 3411152452, "heading");
    
    is($msg->n_sats(), 186, "n_sats");
    
    is($msg->tow(), 2958585170, "tow");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":46765,"flags":58,"heading":3411152452,"length":10,"msg_type":519,"n_sats":186,"payload":"Um1YsEQOUsu6Og==","preamble":85,"sender":52860,"tow":2958585170}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_baseline_heading_dep_a_1();

done_testing();
