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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNEDDepA.yaml
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
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_1() {
    my $buf = decode_base64("VQMC9tcWFC4nAPOG/v/qmf//AAAAAAAAAAAJAV3B");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc15d, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "FC4nAPOG/v/qmf//AAAAAAAAAAAJAQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), -26134, "e");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -96525, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567700, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":49501,"d":0,"e":-26134,"flags":1,"h_accuracy":0,"length":22,"msg_type":515,"n":-96525,"n_sats":9,"payload":"FC4nAPOG/v/qmf//AAAAAAAAAAAJAQ==","preamble":85,"sender":55286,"tow":2567700,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_2() {
    my $buf = decode_base64("VQMC9tcWeC4nAIuG/v9tm///AAAAAAAAAAAJASYn");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2726, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "eC4nAIuG/v9tm///AAAAAAAAAAAJAQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), -25747, "e");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -96629, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567800, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":10022,"d":0,"e":-25747,"flags":1,"h_accuracy":0,"length":22,"msg_type":515,"n":-96629,"n_sats":9,"payload":"eC4nAIuG/v9tm///AAAAAAAAAAAJAQ==","preamble":85,"sender":55286,"tow":2567800,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_3() {
    my $buf = decode_base64("VQMC9tcW3C4nACWG/v/wnP//AAAAAAAAAAAJATqF");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x853a, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "3C4nACWG/v/wnP//AAAAAAAAAAAJAQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), -25360, "e");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -96731, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567900, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":34106,"d":0,"e":-25360,"flags":1,"h_accuracy":0,"length":22,"msg_type":515,"n":-96731,"n_sats":9,"payload":"3C4nACWG/v/wnP//AAAAAAAAAAAJAQ==","preamble":85,"sender":55286,"tow":2567900,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_4() {
    my $buf = decode_base64("VQMC9tcWQC8nAMGF/v9znv//AAAAAAAAAAAJATjW");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd638, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "QC8nAMGF/v9znv//AAAAAAAAAAAJAQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), -24973, "e");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -96831, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2568000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":54840,"d":0,"e":-24973,"flags":1,"h_accuracy":0,"length":22,"msg_type":515,"n":-96831,"n_sats":9,"payload":"QC8nAMGF/v9znv//AAAAAAAAAAAJAQ==","preamble":85,"sender":55286,"tow":2568000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_5() {
    my $buf = decode_base64("VQMC9tcWpC8nAF2F/v/2n///AAAAAAAAAAAJAer0");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf4ea, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "pC8nAF2F/v/2n///AAAAAAAAAAAJAQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), 0, "d");
    
    is($msg->e(), -24586, "e");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -96931, "n");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2568100, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":62698,"d":0,"e":-24586,"flags":1,"h_accuracy":0,"length":22,"msg_type":515,"n":-96931,"n_sats":9,"payload":"pC8nAF2F/v/2n///AAAAAAAAAAAJAQ==","preamble":85,"sender":55286,"tow":2568100,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_6() {
    my $buf = decode_base64("VQMCwwQWnBVFGIL2///xBAAAI8T//wAAAAAGAPoV");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x15fa, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "nBVFGIL2///xBAAAI8T//wAAAAAGAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -15325, "d");
    
    is($msg->e(), 1265, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -2430, "n");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407180700, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":5626,"d":-15325,"e":1265,"flags":0,"h_accuracy":0,"length":22,"msg_type":515,"n":-2430,"n_sats":6,"payload":"nBVFGIL2///xBAAAI8T//wAAAAAGAA==","preamble":85,"sender":1219,"tow":407180700,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_7() {
    my $buf = decode_base64("VQMCwwQWABZFGIL2///xBAAAI8T//wAAAAAGAPCF");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x85f0, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "ABZFGIL2///xBAAAI8T//wAAAAAGAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -15325, "d");
    
    is($msg->e(), 1265, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -2430, "n");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407180800, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":34288,"d":-15325,"e":1265,"flags":0,"h_accuracy":0,"length":22,"msg_type":515,"n":-2430,"n_sats":6,"payload":"ABZFGIL2///xBAAAI8T//wAAAAAGAA==","preamble":85,"sender":1219,"tow":407180800,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_8() {
    my $buf = decode_base64("VQMCwwQWZBZFGCD7///HCwAAOaH//wAAAAAGAAy1");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb50c, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "ZBZFGCD7///HCwAAOaH//wAAAAAGAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -24263, "d");
    
    is($msg->e(), 3015, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -1248, "n");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407180900, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":46348,"d":-24263,"e":3015,"flags":0,"h_accuracy":0,"length":22,"msg_type":515,"n":-1248,"n_sats":6,"payload":"ZBZFGCD7///HCwAAOaH//wAAAAAGAA==","preamble":85,"sender":1219,"tow":407180900,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_9() {
    my $buf = decode_base64("VQMCwwQWyBZFGCH7///HCwAANqH//wAAAAAGAFY6");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3a56, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "yBZFGCH7///HCwAANqH//wAAAAAGAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -24266, "d");
    
    is($msg->e(), 3015, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), -1247, "n");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407181000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":14934,"d":-24266,"e":3015,"flags":0,"h_accuracy":0,"length":22,"msg_type":515,"n":-1247,"n_sats":6,"payload":"yBZFGCH7///HCwAANqH//wAAAAAGAA==","preamble":85,"sender":1219,"tow":407181000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_10() {
    my $buf = decode_base64("VQMCwwQWLBdFGG4GAAA3CAAAoKb//wAAAAAGADP5");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf933, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "LBdFGG4GAAA3CAAAoKb//wAAAAAGAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -22880, "d");
    
    is($msg->e(), 2103, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 1646, "n");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407181100, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":63795,"d":-22880,"e":2103,"flags":0,"h_accuracy":0,"length":22,"msg_type":515,"n":1646,"n_sats":6,"payload":"LBdFGG4GAAA3CAAAoKb//wAAAAAGAA==","preamble":85,"sender":1219,"tow":407181100,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_11() {
    my $buf = decode_base64("VQMCwwQWkBdFGG4GAAA2CAAAoKb//wAAAAAGAM4W");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x16ce, "crc");
    
    is($msg->{'length'}, 22, "length");
    
    is($msg->{'msg_type'}, 0x203, "msg_type");
    
    is($msg->{'payload'}, "kBdFGG4GAAA2CAAAoKb//wAAAAAGAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->d(), -22880, "d");
    
    is($msg->e(), 2102, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->n(), 1646, "n");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407181200, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":5838,"d":-22880,"e":2102,"flags":0,"h_accuracy":0,"length":22,"msg_type":515,"n":1646,"n_sats":6,"payload":"kBdFGG4GAAA2CAAAoKb//wAAAAAGAA==","preamble":85,"sender":1219,"tow":407181200,"v_accuracy":0}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_1();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_2();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_3();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_4();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_5();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_6();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_7();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_8();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_9();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_10();
test_auto_check_sbp_navigation_msg_baseline_ned_dep_a_11();

done_testing();