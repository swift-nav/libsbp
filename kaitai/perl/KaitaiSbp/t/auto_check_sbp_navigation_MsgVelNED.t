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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNED.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_ned_1() {
    my $buf = decode_base64("VQ4C04gWKPR6EwMAAAD8////8////wAAAAAOAFbR");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd156, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20e, "msg_type");
    
    is($msg->{'payload'}, "KPR6EwMAAAD8////8////wAAAAAOAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -13, "d");
    
    is($msg->e(), -4, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 3, "n");
    
    is($msg->n_sats(), 14, "n_sats");
    
    is($msg->tow(), 326825000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":53590,"d":-13,"e":-4,"flags":0,"h_accuracy":0,"length":22,"msg_type":526,"n":3,"n_sats":14,"payload":"KPR6EwMAAAD8////8////wAAAAAOAA==","preamble":85,"sender":35027,"tow":326825000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_2() {
    my $buf = decode_base64("VQ4C04gWHPZ6E/z/////////6P///wAAAAAPABDk");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe410, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20e, "msg_type");
    
    is($msg->{'payload'}, "HPZ6E/z/////////6P///wAAAAAPAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -24, "d");
    
    is($msg->e(), -1, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -4, "n");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326825500, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":58384,"d":-24,"e":-1,"flags":0,"h_accuracy":0,"length":22,"msg_type":526,"n":-4,"n_sats":15,"payload":"HPZ6E/z/////////6P///wAAAAAPAA==","preamble":85,"sender":35027,"tow":326825500,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_3() {
    my $buf = decode_base64("VQ4C04gWEPh6EwAAAAD9////9P///wAAAAAPAAuk");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa40b, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20e, "msg_type");
    
    is($msg->{'payload'}, "EPh6EwAAAAD9////9P///wAAAAAPAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -12, "d");
    
    is($msg->e(), -3, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 0, "n");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326826000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":41995,"d":-12,"e":-3,"flags":0,"h_accuracy":0,"length":22,"msg_type":526,"n":0,"n_sats":15,"payload":"EPh6EwAAAAD9////9P///wAAAAAPAA==","preamble":85,"sender":35027,"tow":326826000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_4() {
    my $buf = decode_base64("VQ4C04gWBPp6EwIAAAADAAAA6P///wAAAAAPAJjQ");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd098, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20e, "msg_type");
    
    is($msg->{'payload'}, "BPp6EwIAAAADAAAA6P///wAAAAAPAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -24, "d");
    
    is($msg->e(), 3, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 2, "n");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326826500, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":53400,"d":-24,"e":3,"flags":0,"h_accuracy":0,"length":22,"msg_type":526,"n":2,"n_sats":15,"payload":"BPp6EwIAAAADAAAA6P///wAAAAAPAA==","preamble":85,"sender":35027,"tow":326826500,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_5() {
    my $buf = decode_base64("VQ4C04gW+Pt6EwEAAAAAAAAA6////wAAAAAPALZ4");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x78b6, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x20e, "msg_type");
    
    is($msg->{'payload'}, "+Pt6EwEAAAAAAAAA6////wAAAAAPAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -21, "d");
    
    is($msg->e(), 0, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 1, "n");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326827000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":30902,"d":-21,"e":0,"flags":0,"h_accuracy":0,"length":22,"msg_type":526,"n":1,"n_sats":15,"payload":"+Pt6EwEAAAAAAAAA6////wAAAAAPAA==","preamble":85,"sender":35027,"tow":326827000,"v_accuracy":0}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_ned_1();
test_auto_check_sbp_navigation_msg_vel_ned_2();
test_auto_check_sbp_navigation_msg_vel_ned_3();
test_auto_check_sbp_navigation_msg_vel_ned_4();
test_auto_check_sbp_navigation_msg_vel_ned_5();

done_testing();