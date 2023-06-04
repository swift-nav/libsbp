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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFDepA.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # load all modules from SBP_PATH
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_1() {
    my $buf = decode_base64("VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xec50, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "FC4nANoLAACG9f//o/z//wAACQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567700, "tow");
    
    is($msg->x(), 3034, "x");
    
    is($msg->y(), -2682, "y");
    
    is($msg->z(), -861, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":60496,"flags":0,"length":20,"msg_type":516,"n_sats":9,"payload":"FC4nANoLAACG9f//o/z//wAACQA=","preamble":85,"sender":55286,"tow":2567700,"x":3034,"y":-2682,"z":-861}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_2() {
    my $buf = decode_base64("VQQC9tcUeC4nAEQLAAAY9v//3Pz//wAACQD4ig==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8af8, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "eC4nAEQLAAAY9v//3Pz//wAACQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567800, "tow");
    
    is($msg->x(), 2884, "x");
    
    is($msg->y(), -2536, "y");
    
    is($msg->z(), -804, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":35576,"flags":0,"length":20,"msg_type":516,"n_sats":9,"payload":"eC4nAEQLAAAY9v//3Pz//wAACQA=","preamble":85,"sender":55286,"tow":2567800,"x":2884,"y":-2536,"z":-804}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_3() {
    my $buf = decode_base64("VQQC9tcU3C4nABULAABN9v//9/z//wAACQAZrg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xae19, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "3C4nABULAABN9v//9/z//wAACQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567900, "tow");
    
    is($msg->x(), 2837, "x");
    
    is($msg->y(), -2483, "y");
    
    is($msg->z(), -777, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":44569,"flags":0,"length":20,"msg_type":516,"n_sats":9,"payload":"3C4nABULAABN9v//9/z//wAACQA=","preamble":85,"sender":55286,"tow":2567900,"x":2837,"y":-2483,"z":-777}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_4() {
    my $buf = decode_base64("VQQC9tcUQC8nAHkLAAAC9v//6vz//wAACQDD5A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe4c3, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "QC8nAHkLAAAC9v//6vz//wAACQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2568000, "tow");
    
    is($msg->x(), 2937, "x");
    
    is($msg->y(), -2558, "y");
    
    is($msg->z(), -790, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":58563,"flags":0,"length":20,"msg_type":516,"n_sats":9,"payload":"QC8nAHkLAAAC9v//6vz//wAACQA=","preamble":85,"sender":55286,"tow":2568000,"x":2937,"y":-2558,"z":-790}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_5() {
    my $buf = decode_base64("VQQC9tcUpC8nAB8LAABd9v//EP3//wAACQDbpA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa4db, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "pC8nAB8LAABd9v//EP3//wAACQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2568100, "tow");
    
    is($msg->x(), 2847, "x");
    
    is($msg->y(), -2467, "y");
    
    is($msg->z(), -752, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":42203,"flags":0,"length":20,"msg_type":516,"n_sats":9,"payload":"pC8nAB8LAABd9v//EP3//wAACQA=","preamble":85,"sender":55286,"tow":2568100,"x":2847,"y":-2467,"z":-752}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_6() {
    my $buf = decode_base64("VQQCwwQU1J1DGBgAAAD1////2////wAACABE/w==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xff44, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "1J1DGBgAAAD1////2////wAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084500, "tow");
    
    is($msg->x(), 24, "x");
    
    is($msg->y(), -11, "y");
    
    is($msg->z(), -37, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":65348,"flags":0,"length":20,"msg_type":516,"n_sats":8,"payload":"1J1DGBgAAAD1////2////wAACAA=","preamble":85,"sender":1219,"tow":407084500,"x":24,"y":-11,"z":-37}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_7() {
    my $buf = decode_base64("VQQCwwQUOJ5DGAQAAADq////EgAAAAAACADWiA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x88d6, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "OJ5DGAQAAADq////EgAAAAAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084600, "tow");
    
    is($msg->x(), 4, "x");
    
    is($msg->y(), -22, "y");
    
    is($msg->z(), 18, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":35030,"flags":0,"length":20,"msg_type":516,"n_sats":8,"payload":"OJ5DGAQAAADq////EgAAAAAACAA=","preamble":85,"sender":1219,"tow":407084600,"x":4,"y":-22,"z":18}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_8() {
    my $buf = decode_base64("VQQCwwQUnJ5DGOb///8EAAAAAQAAAAAACAB6nw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9f7a, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "nJ5DGOb///8EAAAAAQAAAAAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084700, "tow");
    
    is($msg->x(), -26, "x");
    
    is($msg->y(), 4, "y");
    
    is($msg->z(), 1, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":40826,"flags":0,"length":20,"msg_type":516,"n_sats":8,"payload":"nJ5DGOb///8EAAAAAQAAAAAACAA=","preamble":85,"sender":1219,"tow":407084700,"x":-26,"y":4,"z":1}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_9() {
    my $buf = decode_base64("VQQCwwQUAJ9DGPf////t////HAAAAAAACADokg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x92e8, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "AJ9DGPf////t////HAAAAAAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084800, "tow");
    
    is($msg->x(), -9, "x");
    
    is($msg->y(), -19, "y");
    
    is($msg->z(), 28, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":37608,"flags":0,"length":20,"msg_type":516,"n_sats":8,"payload":"AJ9DGPf////t////HAAAAAAACAA=","preamble":85,"sender":1219,"tow":407084800,"x":-9,"y":-19,"z":28}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_10() {
    my $buf = decode_base64("VQQCwwQUZJ9DGP////8CAAAA9f///wAACACr7g==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xeeab, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "ZJ9DGP////8CAAAA9f///wAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084900, "tow");
    
    is($msg->x(), -1, "x");
    
    is($msg->y(), 2, "y");
    
    is($msg->z(), -11, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":61099,"flags":0,"length":20,"msg_type":516,"n_sats":8,"payload":"ZJ9DGP////8CAAAA9f///wAACAA=","preamble":85,"sender":1219,"tow":407084900,"x":-1,"y":2,"z":-11}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_11() {
    my $buf = decode_base64("VQQCwwQULqJEGM////+5////QQAAAAAABQBSmg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9a52, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x204, "msg_type");
    
    is($msg->{'payload'}, "LqJEGM////+5////QQAAAAAABQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 5, "n_sats");
    
    is($msg->tow(), 407151150, "tow");
    
    is($msg->x(), -49, "x");
    
    is($msg->y(), -71, "y");
    
    is($msg->z(), 65, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":39506,"flags":0,"length":20,"msg_type":516,"n_sats":5,"payload":"LqJEGM////+5////QQAAAAAABQA=","preamble":85,"sender":1219,"tow":407151150,"x":-49,"y":-71,"z":65}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_1();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_2();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_3();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_4();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_5();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_6();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_7();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_8();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_9();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_10();
test_auto_check_sbp_navigation_msg_vel_ecef_dep_a_11();

done_testing();