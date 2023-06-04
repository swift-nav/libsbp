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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFDepA.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_1() {
    my $buf = decode_base64("VQAC9tcgFC4nAMN6r0shmkTBpA7msOdfUMFO3Bb9/mlNQQAACQANVg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x560d, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "FC4nAMN6r0shmkTBpA7msOdfUMFO3Bb9/mlNQQAACQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567700, "tow");
    
    is($msg->x(), -2700354.5912927105, "x");
    
    is($msg->y(), -4292510.764041577, "y");
    
    is($msg->z(), 3855357.977260149, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":22029,"flags":0,"length":32,"msg_type":512,"n_sats":9,"payload":"FC4nAMN6r0shmkTBpA7msOdfUMFO3Bb9/mlNQQAACQA=","preamble":85,"sender":55286,"tow":2567700,"x":-2700354.5912927105,"y":-4292510.764041577,"z":3855357.977260149}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_2() {
    my $buf = decode_base64("VQAC9tcgFC4nANTEDCoimkTBCXFwe+dfUME2YSbA/mlNQQAACQFLjw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8f4b, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "FC4nANTEDCoimkTBCXFwe+dfUME2YSbA/mlNQQAACQE=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567700, "tow");
    
    is($msg->x(), -2700356.3285146747, "x");
    
    is($msg->y(), -4292509.928737887, "y");
    
    is($msg->z(), 3855357.5011712564, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":36683,"flags":1,"length":32,"msg_type":512,"n_sats":9,"payload":"FC4nANTEDCoimkTBCXFwe+dfUME2YSbA/mlNQQAACQE=","preamble":85,"sender":55286,"tow":2567700,"x":-2700356.3285146747,"y":-4292509.928737887,"z":3855357.5011712564}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_3() {
    my $buf = decode_base64("VQAC9tcgeC4nAHBhJ74imkTB5it3c+dfUMEyx0xC/mlNQQAACQDMcQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x71cc, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "eC4nAHBhJ74imkTB5it3c+dfUMEyx0xC/mlNQQAACQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567800, "tow");
    
    is($msg->x(), -2700357.485576801, "x");
    
    is($msg->y(), -4292509.80414865, "y");
    
    is($msg->z(), 3855356.517968082, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":29132,"flags":0,"length":32,"msg_type":512,"n_sats":9,"payload":"eC4nAHBhJ74imkTB5it3c+dfUMEyx0xC/mlNQQAACQA=","preamble":85,"sender":55286,"tow":2567800,"x":-2700357.485576801,"y":-4292509.80414865,"z":3855356.517968082}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_4() {
    my $buf = decode_base64("VQAC9tcgeC4nAMJSeQQimkTB37oBjOdfUMGwmJO1/mlNQQAACQFhRw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4761, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "eC4nAMJSeQQimkTB37oBjOdfUMGwmJO1/mlNQQAACQE=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567800, "tow");
    
    is($msg->x(), -2700356.0349524925, "x");
    
    is($msg->y(), -4292510.187605589, "y");
    
    is($msg->z(), 3855357.4185667858, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":18273,"flags":1,"length":32,"msg_type":512,"n_sats":9,"payload":"eC4nAMJSeQQimkTB37oBjOdfUMGwmJO1/mlNQQAACQE=","preamble":85,"sender":55286,"tow":2567800,"x":-2700356.0349524925,"y":-4292510.187605589,"z":3855357.4185667858}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_5() {
    my $buf = decode_base64("VQAC9tcg3C4nANgp4/4hmkTBCZeafOdfUMEBt9aL/2lNQQAACQAHYg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6207, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "3C4nANgp4/4hmkTBCZeafOdfUMEBt9aL/2lNQQAACQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567900, "tow");
    
    is($msg->x(), -2700355.9913074784, "x");
    
    is($msg->y(), -4292509.946935424, "y");
    
    is($msg->z(), 3855359.0924900775, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":25095,"flags":0,"length":32,"msg_type":512,"n_sats":9,"payload":"3C4nANgp4/4hmkTBCZeafOdfUMEBt9aL/2lNQQAACQA=","preamble":85,"sender":55286,"tow":2567900,"x":-2700355.9913074784,"y":-4292509.946935424,"z":3855359.0924900775}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_6() {
    my $buf = decode_base64("VQACwwQg1J1DGJneaQH8oUTB/vc0cEpDUMGkzy+SLKNNQQAACACRBA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x491, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "1J1DGJneaQH8oUTB/vc0cEpDUMGkzy+SLKNNQQAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084500, "tow");
    
    is($msg->x(), -2704376.0110433814, "x");
    
    is($msg->y(), -4263209.753232954, "y");
    
    is($msg->z(), 3884633.142084079, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":1169,"flags":0,"length":32,"msg_type":512,"n_sats":8,"payload":"1J1DGJneaQH8oUTB/vc0cEpDUMGkzy+SLKNNQQAACAA=","preamble":85,"sender":1219,"tow":407084500,"x":-2704376.0110433814,"y":-4263209.753232954,"z":3884633.142084079}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_7() {
    my $buf = decode_base64("VQACwwQgOJ5DGNe43/b7oUTBJH4RJ0pDUMETs0ZQLKNNQQAACAD1Qg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x42f5, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "OJ5DGNe43/b7oUTBJH4RJ0pDUMETs0ZQLKNNQQAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084600, "tow");
    
    is($msg->x(), -2704375.9287024545, "x");
    
    is($msg->y(), -4263208.610442672, "y");
    
    is($msg->z(), 3884632.627157578, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":17141,"flags":0,"length":32,"msg_type":512,"n_sats":8,"payload":"OJ5DGNe43/b7oUTBJH4RJ0pDUMETs0ZQLKNNQQAACAA=","preamble":85,"sender":1219,"tow":407084600,"x":-2704375.9287024545,"y":-4263208.610442672,"z":3884632.627157578}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_8() {
    my $buf = decode_base64("VQACwwQgnJ5DGElK1pT7oUTB1Ze410lDUMFuYyakK6NNQQAACAAF3w==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xdf05, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "nJ5DGElK1pT7oUTB1Ze410lDUMFuYyakK6NNQQAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084700, "tow");
    
    is($msg->x(), -2704375.162789617, "x");
    
    is($msg->y(), -4263207.370641668, "y");
    
    is($msg->z(), 3884631.282421521, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":57093,"flags":0,"length":32,"msg_type":512,"n_sats":8,"payload":"nJ5DGElK1pT7oUTB1Ze410lDUMFuYyakK6NNQQAACAA=","preamble":85,"sender":1219,"tow":407084700,"x":-2704375.162789617,"y":-4263207.370641668,"z":3884631.282421521}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_9() {
    my $buf = decode_base64("VQACwwQgAJ9DGLFvcC38oUTB1ajG/UlDUMH1DOQMLKNNQQAACACP1A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd48f, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "AJ9DGLFvcC38oUTB1ajG/UlDUMH1DOQMLKNNQQAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084800, "tow");
    
    is($msg->x(), -2704376.3549937834, "x");
    
    is($msg->y(), -4263207.965250214, "y");
    
    is($msg->z(), 3884632.1007095524, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":54415,"flags":0,"length":32,"msg_type":512,"n_sats":8,"payload":"AJ9DGLFvcC38oUTB1ajG/UlDUMH1DOQMLKNNQQAACAA=","preamble":85,"sender":1219,"tow":407084800,"x":-2704376.3549937834,"y":-4263207.965250214,"z":3884632.1007095524}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_10() {
    my $buf = decode_base64("VQACwwQgZJ9DGEPnSKX7oUTBltIk1ElDUMHqIRm9K6NNQQAACABG3Q==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xdd46, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "ZJ9DGEPnSKX7oUTBltIk1ElDUMHqIRm9K6NNQQAACAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084900, "tow");
    
    is($msg->x(), -2704375.291287334, "x");
    
    is($msg->y(), -4263207.314747473, "y");
    
    is($msg->z(), 3884631.4773294823, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":56646,"flags":0,"length":32,"msg_type":512,"n_sats":8,"payload":"ZJ9DGEPnSKX7oUTBltIk1ElDUMHqIRm9K6NNQQAACAA=","preamble":85,"sender":1219,"tow":407084900,"x":-2704375.291287334,"y":-4263207.314747473,"z":3884631.4773294823}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_11() {
    my $buf = decode_base64("VQACwwQgLqJEGOBIg9f7oUTBtHveXkpDUMG/A4PBLaNNQQAABQAR3Q==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xdd11, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x200, "msg_type");
    
    is($msg->{'payload'}, "LqJEGOBIg9f7oUTBtHveXkpDUMG/A4PBLaNNQQAABQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 5, "n_sats");
    
    is($msg->tow(), 407151150, "tow");
    
    is($msg->x(), -2704375.68369399, "x");
    
    is($msg->y(), -4263209.482329298, "y");
    
    is($msg->z(), 3884635.5118107493, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":56593,"flags":0,"length":32,"msg_type":512,"n_sats":5,"payload":"LqJEGOBIg9f7oUTBtHveXkpDUMG/A4PBLaNNQQAABQA=","preamble":85,"sender":1219,"tow":407151150,"x":-2704375.68369399,"y":-4263209.482329298,"z":3884635.5118107493}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_1();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_2();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_3();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_4();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_5();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_6();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_7();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_8();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_9();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_10();
test_auto_check_sbp_navigation_msg_pos_ecef_dep_a_11();

done_testing();