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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgFrontEndGain.yaml
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
sub test_auto_check_sbp_piksi_msg_front_end_gain_1() {
    my $buf = decode_base64("Vb8Ar/UQKYWGCmkUJib26dhQu9VVAuuH");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x87eb, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0xbf, "msg_type");
    
    is($msg->{'payload'}, "KYWGCmkUJib26dhQu9VVAg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf5af, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->if_gain()), $json->encode($json->decode(q{[-10,-23,-40,80,-69,-43,85,2]})), "if_gain");
    
    is($json->encode($msg->rf_gain()), $json->encode($json->decode(q{[41,-123,-122,10,105,20,38,38]})), "rf_gain");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":34795,"if_gain":[-10,-23,-40,80,-69,-43,85,2],"length":16,"msg_type":191,"payload":"KYWGCmkUJib26dhQu9VVAg==","preamble":85,"rf_gain":[41,-123,-122,10,105,20,38,38],"sender":62895}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_front_end_gain_1();

done_testing();