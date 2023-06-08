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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNED.yaml
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
sub test_auto_check_sbp_navigation_msg_baseline_ned_1() {
    my $buf = decode_base64("VQwC04gWKPR6E8lzDACzWOb/mX0AAAAAAAAOAOJG");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x46e2, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20c, "msg_type");
    
    is($msg->{'payload'}, "KPR6E8lzDACzWOb/mX0AAAAAAAAOAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 32153, "d");
    
    is($msg->e(), -1681229, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 816073, "n");
    
    is($msg->n_sats(), 14, "n_sats");
    
    is($msg->tow(), 326825000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":18146,"d":32153,"e":-1681229,"flags":0,"h_accuracy":0,"length":22,"msg_type":524,"n":816073,"n_sats":14,"payload":"KPR6E8lzDACzWOb/mX0AAAAAAAAOAA==","preamble":85,"sender":35027,"tow":326825000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_2() {
    my $buf = decode_base64("VQwC04gWEPh6E2JzDADCWOb/bn8AAAAAAAAPAEVd");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5d45, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20c, "msg_type");
    
    is($msg->{'payload'}, "EPh6E2JzDADCWOb/bn8AAAAAAAAPAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 32622, "d");
    
    is($msg->e(), -1681214, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 815970, "n");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326826000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":23877,"d":32622,"e":-1681214,"flags":0,"h_accuracy":0,"length":22,"msg_type":524,"n":815970,"n_sats":15,"payload":"EPh6E2JzDADCWOb/bn8AAAAAAAAPAA==","preamble":85,"sender":35027,"tow":326826000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_3() {
    my $buf = decode_base64("VQwC04gW+Pt6E49yDACtWOb/7n8AAAAAAAAPANKp");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa9d2, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20c, "msg_type");
    
    is($msg->{'payload'}, "+Pt6E49yDACtWOb/7n8AAAAAAAAPAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 32750, "d");
    
    is($msg->e(), -1681235, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 815759, "n");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326827000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":43474,"d":32750,"e":-1681235,"flags":0,"h_accuracy":0,"length":22,"msg_type":524,"n":815759,"n_sats":15,"payload":"+Pt6E49yDACtWOb/7n8AAAAAAAAPAA==","preamble":85,"sender":35027,"tow":326827000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_4() {
    my $buf = decode_base64("VQwC04gW4P96E1ZwDAAzWOb/L38AAAAAAAAPAIdr");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6b87, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20c, "msg_type");
    
    is($msg->{'payload'}, "4P96E1ZwDAAzWOb/L38AAAAAAAAPAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 32559, "d");
    
    is($msg->e(), -1681357, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 815190, "n");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326828000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":27527,"d":32559,"e":-1681357,"flags":0,"h_accuracy":0,"length":22,"msg_type":524,"n":815190,"n_sats":15,"payload":"4P96E1ZwDAAzWOb/L38AAAAAAAAPAA==","preamble":85,"sender":35027,"tow":326828000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_5() {
    my $buf = decode_base64("VQwC04gWyAN7E9ZuDADcV+b/pX4AAAAAAAAPAL5Q");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x50be, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20c, "msg_type");
    
    is($msg->{'payload'}, "yAN7E9ZuDADcV+b/pX4AAAAAAAAPAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 32421, "d");
    
    is($msg->e(), -1681444, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 814806, "n");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326829000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":20670,"d":32421,"e":-1681444,"flags":0,"h_accuracy":0,"length":22,"msg_type":524,"n":814806,"n_sats":15,"payload":"yAN7E9ZuDADcV+b/pX4AAAAAAAAPAA==","preamble":85,"sender":35027,"tow":326829000,"v_accuracy":0}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_baseline_ned_1();
test_auto_check_sbp_navigation_msg_baseline_ned_2();
test_auto_check_sbp_navigation_msg_baseline_ned_3();
test_auto_check_sbp_navigation_msg_baseline_ned_4();
test_auto_check_sbp_navigation_msg_baseline_ned_5();

done_testing();