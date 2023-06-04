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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEFDepA.yaml
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
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_1() {
    my $buf = decode_base64("VQIC9tcUFC4nABUw//80df//2NP+/wAACQEyiQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8932, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "FC4nABUw//80df//2NP+/wAACQE=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567700, "tow");
    
    is($msg->x(), -53227, "x");
    
    is($msg->y(), -35532, "y");
    
    is($msg->z(), -76840, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":35122,"flags":1,"length":20,"msg_type":514,"n_sats":9,"payload":"FC4nABUw//80df//2NP+/wAACQE=","preamble":85,"sender":55286,"tow":2567700,"x":-53227,"y":-35532,"z":-76840}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_2() {
    my $buf = decode_base64("VQIC9tcUeC4nADox//8xdP//htP+/wAACQHjmw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9be3, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "eC4nADox//8xdP//htP+/wAACQE=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567800, "tow");
    
    is($msg->x(), -52934, "x");
    
    is($msg->y(), -35791, "y");
    
    is($msg->z(), -76922, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":39907,"flags":1,"length":20,"msg_type":514,"n_sats":9,"payload":"eC4nADox//8xdP//htP+/wAACQE=","preamble":85,"sender":55286,"tow":2567800,"x":-52934,"y":-35791,"z":-76922}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_3() {
    my $buf = decode_base64("VQIC9tcU3C4nAGEy//8vc///NNP+/wAACQE9fg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7e3d, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "3C4nAGEy//8vc///NNP+/wAACQE=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567900, "tow");
    
    is($msg->x(), -52639, "x");
    
    is($msg->y(), -36049, "y");
    
    is($msg->z(), -77004, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":32317,"flags":1,"length":20,"msg_type":514,"n_sats":9,"payload":"3C4nAGEy//8vc///NNP+/wAACQE=","preamble":85,"sender":55286,"tow":2567900,"x":-52639,"y":-36049,"z":-77004}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_4() {
    my $buf = decode_base64("VQIC9tcUQC8nAIgz//8tcv//5NL+/wAACQHITw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4fc8, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "QC8nAIgz//8tcv//5NL+/wAACQE=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2568000, "tow");
    
    is($msg->x(), -52344, "x");
    
    is($msg->y(), -36307, "y");
    
    is($msg->z(), -77084, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":20424,"flags":1,"length":20,"msg_type":514,"n_sats":9,"payload":"QC8nAIgz//8tcv//5NL+/wAACQE=","preamble":85,"sender":55286,"tow":2568000,"x":-52344,"y":-36307,"z":-77084}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_5() {
    my $buf = decode_base64("VQIC9tcUpC8nALA0//8scf//ldL+/wAACQFoGA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1868, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "pC8nALA0//8scf//ldL+/wAACQE=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2568100, "tow");
    
    is($msg->x(), -52048, "x");
    
    is($msg->y(), -36564, "y");
    
    is($msg->z(), -77163, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":6248,"flags":1,"length":20,"msg_type":514,"n_sats":9,"payload":"pC8nALA0//8scf//ldL+/wAACQE=","preamble":85,"sender":55286,"tow":2568100,"x":-52048,"y":-36564,"z":-77163}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_6() {
    my $buf = decode_base64("VQICwwQUnBVFGKnn//9m0P//+xwAAAAABgCSqA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa892, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "nBVFGKnn//9m0P//+xwAAAAABgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407180700, "tow");
    
    is($msg->x(), -6231, "x");
    
    is($msg->y(), -12186, "y");
    
    is($msg->z(), 7419, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":43154,"flags":0,"length":20,"msg_type":514,"n_sats":6,"payload":"nBVFGKnn//9m0P//+xwAAAAABgA=","preamble":85,"sender":1219,"tow":407180700,"x":-6231,"y":-12186,"z":7419}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_7() {
    my $buf = decode_base64("VQICwwQUABZFGKnn//9n0P///BwAAAAABgAidA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7422, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "ABZFGKnn//9n0P///BwAAAAABgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407180800, "tow");
    
    is($msg->x(), -6231, "x");
    
    is($msg->y(), -12185, "y");
    
    is($msg->z(), 7420, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":29730,"flags":0,"length":20,"msg_type":514,"n_sats":6,"payload":"ABZFGKnn//9n0P///BwAAAAABgA=","preamble":85,"sender":1219,"tow":407180800,"x":-6231,"y":-12185,"z":7420}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_8() {
    my $buf = decode_base64("VQICwwQUZBZFGB7g///At///7zUAAAAABgDhDw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xfe1, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "ZBZFGB7g///At///7zUAAAAABgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407180900, "tow");
    
    is($msg->x(), -8162, "x");
    
    is($msg->y(), -18496, "y");
    
    is($msg->z(), 13807, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":4065,"flags":0,"length":20,"msg_type":514,"n_sats":6,"payload":"ZBZFGB7g///At///7zUAAAAABgA=","preamble":85,"sender":1219,"tow":407180900,"x":-8162,"y":-18496,"z":13807}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_9() {
    my $buf = decode_base64("VQICwwQUyBZFGBzg//+/t///8jUAAAAABgAjZA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6423, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "yBZFGBzg//+/t///8jUAAAAABgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407181000, "tow");
    
    is($msg->x(), -8164, "x");
    
    is($msg->y(), -18497, "y");
    
    is($msg->z(), 13810, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":25635,"flags":0,"length":20,"msg_type":514,"n_sats":6,"payload":"yBZFGBzg//+/t///8jUAAAAABgA=","preamble":85,"sender":1219,"tow":407181000,"x":-8164,"y":-18497,"z":13810}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_10() {
    my $buf = decode_base64("VQICwwQULBdFGBjj//8Zw///mTsAAAAABgBCQg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4242, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "LBdFGBjj//8Zw///mTsAAAAABgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407181100, "tow");
    
    is($msg->x(), -7400, "x");
    
    is($msg->y(), -15591, "y");
    
    is($msg->z(), 15257, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":16962,"flags":0,"length":20,"msg_type":514,"n_sats":6,"payload":"LBdFGBjj//8Zw///mTsAAAAABgA=","preamble":85,"sender":1219,"tow":407181100,"x":-7400,"y":-15591,"z":15257}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_11() {
    my $buf = decode_base64("VQICwwQUkBdFGBfj//8Zw///mTsAAAAABgAjhw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8723, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x202, "msg_type");
    
    is($msg->{'payload'}, "kBdFGBfj//8Zw///mTsAAAAABgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 6, "n_sats");
    
    is($msg->tow(), 407181200, "tow");
    
    is($msg->x(), -7401, "x");
    
    is($msg->y(), -15591, "y");
    
    is($msg->z(), 15257, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":34595,"flags":0,"length":20,"msg_type":514,"n_sats":6,"payload":"kBdFGBfj//8Zw///mTsAAAAABgA=","preamble":85,"sender":1219,"tow":407181200,"x":-7401,"y":-15591,"z":15257}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_1();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_2();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_3();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_4();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_5();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_6();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_7();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_8();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_9();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_10();
test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a_11();

done_testing();