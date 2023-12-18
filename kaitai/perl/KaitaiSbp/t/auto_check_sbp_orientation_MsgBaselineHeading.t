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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgBaselineHeading.yaml
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
sub test_auto_check_sbp_orientation_msg_baseline_heading_1() {
    my $buf = decode_base64("VQ8C010KnC0NxCxUxT1bW+D+");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xfee0, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'msg_type'}, 0x20f, "msg_type");
    
    is($msg->{'payload'}, "nC0NxCxUxT1bWw==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x5dd3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 91, "flags");
    
    is($msg->heading(), 1036342316, "heading");
    
    is($msg->n_sats(), 91, "n_sats");
    
    is($msg->tow(), 3289197980, "tow");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":65248,"flags":91,"heading":1036342316,"length":10,"msg_type":527,"n_sats":91,"payload":"nC0NxCxUxT1bWw==","preamble":85,"sender":24019,"tow":3289197980}})), "raw_json");
}
test_auto_check_sbp_orientation_msg_baseline_heading_1();

done_testing();