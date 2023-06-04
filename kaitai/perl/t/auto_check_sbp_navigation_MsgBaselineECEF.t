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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # add SBP_PATH to include path and load all modules
    unshift @INC, &SBP_PATH;
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
use t::Utils;
sub test_auto_check_sbp_navigation_msg_baseline_ecef_1() {
    my $buf = decode_base64("VQsC04gUKPR6E5Zi7v++QBQA9qMJAAAADgDbvw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xbfdb, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20b, "msg_type");
    
    is($msg->{'payload'}, "KPR6E5Zi7v++QBQA9qMJAAAADgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 14, "n_sats");
    
    is($msg->tow(), 326825000, "tow");
    
    is($msg->x(), -1154410, "x");
    
    is($msg->y(), 1327294, "y");
    
    is($msg->z(), 631798, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":49115,"flags":0,"length":20,"msg_type":523,"n_sats":14,"payload":"KPR6E5Zi7v++QBQA9qMJAAAADgA=","preamble":85,"sender":35027,"tow":326825000,"x":-1154410,"y":1327294,"z":631798}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_2() {
    my $buf = decode_base64("VQsC04gUEPh6E0hj7v+/QRQAiqIJAAAADwDwTg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4ef0, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20b, "msg_type");
    
    is($msg->{'payload'}, "EPh6E0hj7v+/QRQAiqIJAAAADwA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326826000, "tow");
    
    is($msg->x(), -1154232, "x");
    
    is($msg->y(), 1327551, "y");
    
    is($msg->z(), 631434, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":20208,"flags":0,"length":20,"msg_type":523,"n_sats":15,"payload":"EPh6E0hj7v+/QRQAiqIJAAAADwA=","preamble":85,"sender":35027,"tow":326826000,"x":-1154232,"y":1327551,"z":631434}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_3() {
    my $buf = decode_base64("VQsC04gU+Pt6Eylj7v+1QRQAlKEJAAAADwAEhA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8404, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20b, "msg_type");
    
    is($msg->{'payload'}, "+Pt6Eylj7v+1QRQAlKEJAAAADwA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326827000, "tow");
    
    is($msg->x(), -1154263, "x");
    
    is($msg->y(), 1327541, "y");
    
    is($msg->z(), 631188, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":33796,"flags":0,"length":20,"msg_type":523,"n_sats":15,"payload":"+Pt6Eylj7v+1QRQAlKEJAAAADwA=","preamble":85,"sender":35027,"tow":326827000,"x":-1154263,"y":1327541,"z":631188}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_4() {
    my $buf = decode_base64("VQsC04gU4P96E7xh7v9RQBQAQaAJAAAADwBDXg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5e43, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20b, "msg_type");
    
    is($msg->{'payload'}, "4P96E7xh7v9RQBQAQaAJAAAADwA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326828000, "tow");
    
    is($msg->x(), -1154628, "x");
    
    is($msg->y(), 1327185, "y");
    
    is($msg->z(), 630849, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":24131,"flags":0,"length":20,"msg_type":523,"n_sats":15,"payload":"4P96E7xh7v9RQBQAQaAJAAAADwA=","preamble":85,"sender":35027,"tow":326828000,"x":-1154628,"y":1327185,"z":630849}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_5() {
    my $buf = decode_base64("VQsC04gUyAN7E71g7v9dPxQAYp8JAAAADwBqXg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5e6a, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20b, "msg_type");
    
    is($msg->{'payload'}, "yAN7E71g7v9dPxQAYp8JAAAADwA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326829000, "tow");
    
    is($msg->x(), -1154883, "x");
    
    is($msg->y(), 1326941, "y");
    
    is($msg->z(), 630626, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":24170,"flags":0,"length":20,"msg_type":523,"n_sats":15,"payload":"yAN7E71g7v9dPxQAYp8JAAAADwA=","preamble":85,"sender":35027,"tow":326829000,"x":-1154883,"y":1326941,"z":630626}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_baseline_ecef_1();
test_auto_check_sbp_navigation_msg_baseline_ecef_2();
test_auto_check_sbp_navigation_msg_baseline_ecef_3();
test_auto_check_sbp_navigation_msg_baseline_ecef_4();
test_auto_check_sbp_navigation_msg_baseline_ecef_5();

done_testing();