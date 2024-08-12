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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDDepA.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_1() {
    my $buf = decode_base64("VQUC9tcWFC4nAMb7//+cDwAAAAAAAAAAAAAJAKFc");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5ca1, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "FC4nAMb7//+cDwAAAAAAAAAAAAAJAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), 3996, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -1082, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567700, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":23713,"d":0,"e":3996,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":-1082,"n_sats":9,"payload":"FC4nAMb7//+cDwAAAAAAAAAAAAAJAA==","preamble":85,"sender":55286,"tow":2567700,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_2() {
    my $buf = decode_base64("VQUC9tcWeC4nAA78///PDgAAAAAAAAAAAAAJAH2g");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa07d, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "eC4nAA78///PDgAAAAAAAAAAAAAJAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), 3791, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -1010, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567800, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":41085,"d":0,"e":3791,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":-1010,"n_sats":9,"payload":"eC4nAA78///PDgAAAAAAAAAAAAAJAA==","preamble":85,"sender":55286,"tow":2567800,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_3() {
    my $buf = decode_base64("VQUC9tcW3C4nADD8//+MDgAAAAAAAAAAAAAJALOH");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x87b3, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "3C4nADD8//+MDgAAAAAAAAAAAAAJAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), 3724, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -976, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567900, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":34739,"d":0,"e":3724,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":-976,"n_sats":9,"payload":"3C4nADD8//+MDgAAAAAAAAAAAAAJAA==","preamble":85,"sender":55286,"tow":2567900,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_4() {
    my $buf = decode_base64("VQUC9tcWQC8nACD8//8IDwAAAAAAAAAAAAAJADOx");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb133, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "QC8nACD8//8IDwAAAAAAAAAAAAAJAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), 3848, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -992, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2568000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":45363,"d":0,"e":3848,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":-992,"n_sats":9,"payload":"QC8nACD8//8IDwAAAAAAAAAAAAAJAA==","preamble":85,"sender":55286,"tow":2568000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_5() {
    my $buf = decode_base64("VQUC9tcWpC8nAFD8//+MDgAAAAAAAAAAAAAJABcA");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x17, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "pC8nAFD8//+MDgAAAAAAAAAAAAAJAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), 3724, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -944, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2568100, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":23,"d":0,"e":3724,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":-944,"n_sats":9,"payload":"pC8nAFD8//+MDgAAAAAAAAAAAAAJAA==","preamble":85,"sender":55286,"tow":2568100,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_6() {
    my $buf = decode_base64("VQUCwwQW1J1DGOX///8aAAAAGQAAAAAAAAAIAIQZ");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1984, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "1J1DGOX///8aAAAAGQAAAAAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 25, "d");
    
    is($msg->e(), 26, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -27, "n");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084500, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":6532,"d":25,"e":26,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":-27,"n_sats":8,"payload":"1J1DGOX///8aAAAAGQAAAAAAAAAIAA==","preamble":85,"sender":1219,"tow":407084500,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_7() {
    my $buf = decode_base64("VQUCwwQWOJ5DGAQAAAAPAAAA6P///wAAAAAIACoO");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe2a, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "OJ5DGAQAAAAPAAAA6P///wAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -24, "d");
    
    is($msg->e(), 15, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 4, "n");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084600, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":3626,"d":-24,"e":15,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":4,"n_sats":8,"payload":"OJ5DGAQAAAAPAAAA6P///wAAAAAIAA==","preamble":85,"sender":1219,"tow":407084600,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_8() {
    my $buf = decode_base64("VQUCwwQWnJ5DGPv////o////9////wAAAAAIANqU");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x94da, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "nJ5DGPv////o////9////wAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -9, "d");
    
    is($msg->e(), -24, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -5, "n");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084700, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":38106,"d":-9,"e":-24,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":-5,"n_sats":8,"payload":"nJ5DGPv////o////9////wAAAAAIAA==","preamble":85,"sender":1219,"tow":407084700,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_9() {
    my $buf = decode_base64("VQUCwwQWAJ9DGAoAAAACAAAA3v///wAAAAAIAJQQ");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1094, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "AJ9DGAoAAAACAAAA3v///wAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -34, "d");
    
    is($msg->e(), 2, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 10, "n");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084800, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":4244,"d":-34,"e":2,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":10,"n_sats":8,"payload":"AJ9DGAoAAAACAAAA3v///wAAAAAIAA==","preamble":85,"sender":1219,"tow":407084800,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_10() {
    my $buf = decode_base64("VQUCwwQWZJ9DGPj////+////BwAAAAAAAAAIAP/s");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xecff, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "ZJ9DGPj////+////BwAAAAAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 7, "d");
    
    is($msg->e(), -2, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -8, "n");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084900, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":60671,"d":7,"e":-2,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":-8,"n_sats":8,"payload":"ZJ9DGPj////+////BwAAAAAAAAAIAA==","preamble":85,"sender":1219,"tow":407084900,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ned_dep_a_11() {
    my $buf = decode_base64("VQUCwwQWLqJEGP/////9////lP///wAAAAAFAKa9");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xbda6, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x205, "msg_type");
    
    is($msg->{'payload'}, "LqJEGP/////9////lP///wAAAAAFAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -108, "d");
    
    is($msg->e(), -3, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -1, "n");
    
    is($msg->n_sats(), 5, "n_sats");
    
    is($msg->tow(), 407151150, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":48550,"d":-108,"e":-3,"flags":0,"h_accuracy":0,"length":22,"msg_type":517,"n":-1,"n_sats":5,"payload":"LqJEGP/////9////lP///wAAAAAFAA==","preamble":85,"sender":1219,"tow":407151150,"v_accuracy":0}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_1();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_2();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_3();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_4();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_5();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_6();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_7();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_8();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_9();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_10();
test_auto_check_sbp_navigation_msg_vel_ned_dep_a_11();

done_testing();