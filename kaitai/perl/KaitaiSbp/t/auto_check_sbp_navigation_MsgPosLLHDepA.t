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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHDepA.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_1() {
    my $buf = decode_base64("VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8bec, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "FC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 69.80437675175607, "height");
    
    is($msg->lat(), 37.42906890908121, "lat");
    
    is($msg->lon(), -122.17338662202773, "lon");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567700, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":35820,"flags":0,"h_accuracy":0,"height":69.80437675175607,"lat":37.42906890908121,"length":34,"lon":-122.17338662202773,"msg_type":513,"n_sats":9,"payload":"FC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAA==","preamble":85,"sender":55286,"tow":2567700,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_2() {
    my $buf = decode_base64("VQEC9tciFC4nAKEzS5TrtkJAJCn2HhmLXsD+2jF/CmxRQAAAAAAJARl1");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7519, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "FC4nAKEzS5TrtkJAJCn2HhmLXsD+2jF/CmxRQAAAAAAJAQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 1, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 69.68814067715354, "height");
    
    is($msg->lat(), 37.42906430885274, "lat");
    
    is($msg->lon(), -122.17340826071865, "lon");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567700, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":29977,"flags":1,"h_accuracy":0,"height":69.68814067715354,"lat":37.42906430885274,"length":34,"lon":-122.17340826071865,"msg_type":513,"n_sats":9,"payload":"FC4nAKEzS5TrtkJAJCn2HhmLXsD+2jF/CmxRQAAAAAAJAQ==","preamble":85,"sender":55286,"tow":2567700,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_3() {
    my $buf = decode_base64("VQEC9tcieC4nADjW0kHrtkJADS6EUBmLXsAWjy7qv19RQAAAAAAJAK5p");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x69ae, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "eC4nADjW0kHrtkJADS6EUBmLXsAWjy7qv19RQAAAAAAJAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 69.49608854815264, "height");
    
    is($msg->lat(), 37.42905447764173, "lat");
    
    is($msg->lon(), -122.17342007549469, "lon");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567800, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":27054,"flags":0,"h_accuracy":0,"height":69.49608854815264,"lat":37.42905447764173,"length":34,"lon":-122.17342007549469,"msg_type":513,"n_sats":9,"payload":"eC4nADjW0kHrtkJADS6EUBmLXsAWjy7qv19RQAAAAAAJAA==","preamble":85,"sender":55286,"tow":2567800,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_4() {
    my $buf = decode_base64("VQEC9tcieC4nAPt1c4zrtkJAmIanDBmLXsCgFon9BGxRQAAAAAAJAXp/");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7f7a, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "eC4nAPt1c4zrtkJAmIanDBmLXsCgFon9BGxRQAAAAAAJAQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 1, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 69.68780458819901, "height");
    
    is($msg->lat(), 37.429063373925565, "lat");
    
    is($msg->lon(), -122.17340389594972, "lon");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567800, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":32634,"flags":1,"h_accuracy":0,"height":69.68780458819901,"lat":37.429063373925565,"length":34,"lon":-122.17340389594972,"msg_type":513,"n_sats":9,"payload":"eC4nAPt1c4zrtkJAmIanDBmLXsCgFon9BGxRQAAAAAAJAQ==","preamble":85,"sender":55286,"tow":2567800,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_5() {
    my $buf = decode_base64("VQEC9tci3C4nADN8WPvrtkJAmQX6EBmLXsCSPLvbmKFRQAAAAAAJAMKe");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9ec2, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "3C4nADN8WPvrtkJAmQX6EBmLXsCSPLvbmKFRQAAAAAAJAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 70.5249547317965, "height");
    
    is($msg->lat(), 37.42907659359516, "lat");
    
    is($msg->lon(), -122.17340492645452, "lon");
    
    is($msg->n_sats(), 9, "n_sats");
    
    is($msg->tow(), 2567900, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":40642,"flags":0,"h_accuracy":0,"height":70.5249547317965,"lat":37.42907659359516,"length":34,"lon":-122.17340492645452,"msg_type":513,"n_sats":9,"payload":"3C4nADN8WPvrtkJAmQX6EBmLXsCSPLvbmKFRQAAAAAAJAA==","preamble":85,"sender":55286,"tow":2567900,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_6() {
    my $buf = decode_base64("VQECwwQi1J1DGAgX5AiX4UJAnK4qwuaYXsCZF0gvxCgQQAAAAAAIAO2p");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa9ed, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "1J1DGAgX5AiX4UJAnK4qwuaYXsCZF0gvxCgQQAAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 4.039810885214956, "height");
    
    is($msg->lat(), 37.76242171418386, "lat");
    
    is($msg->lon(), -122.38908437889262, "lon");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084500, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":43501,"flags":0,"h_accuracy":0,"height":4.039810885214956,"lat":37.76242171418386,"length":34,"lon":-122.38908437889262,"msg_type":513,"n_sats":8,"payload":"1J1DGAgX5AiX4UJAnK4qwuaYXsCZF0gvxCgQQAAAAAAIAA==","preamble":85,"sender":1219,"tow":407084500,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_7() {
    my $buf = decode_base64("VQECwwQiOJ5DGNxt1BiX4UJAn+f+2+aYXsCAl0MT6WkHQAAAAAAIAJgL");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb98, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "OJ5DGNxt1BiX4UJAn+f+2+aYXsCAl0MT6WkHQAAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 2.926714087009657, "height");
    
    is($msg->lat(), 37.76242361423985, "lat");
    
    is($msg->lon(), -122.38909053700489, "lon");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084600, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":2968,"flags":0,"h_accuracy":0,"height":2.926714087009657,"lat":37.76242361423985,"length":34,"lon":-122.38909053700489,"msg_type":513,"n_sats":8,"payload":"OJ5DGNxt1BiX4UJAn+f+2+aYXsCAl0MT6WkHQAAAAAAIAA==","preamble":85,"sender":1219,"tow":407084600,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_8() {
    my $buf = decode_base64("VQECwwQinJ5DGA1b7QuX4UJAS3HS3OaYXsAlBpG8WXDuPwAAAAAIAN2b");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9bdd, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "nJ5DGA1b7QuX4UJAS3HS3OaYXsAlBpG8WXDuPwAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 0.9512146647395566, "height");
    
    is($msg->lat(), 37.762422076126406, "lat");
    
    is($msg->lon(), -122.3890907340148, "lon");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084700, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":39901,"flags":0,"h_accuracy":0,"height":0.9512146647395566,"lat":37.762422076126406,"length":34,"lon":-122.3890907340148,"msg_type":513,"n_sats":8,"payload":"nJ5DGA1b7QuX4UJAS3HS3OaYXsAlBpG8WXDuPwAAAAAIAA==","preamble":85,"sender":1219,"tow":407084700,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_9() {
    my $buf = decode_base64("VQECwwQiAJ9DGDO3BQiX4UJADeKU/eaYXsC7GwsgRdUCQAAAAAAIAFJe");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5e52, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "AJ9DGDO3BQiX4UJADeKU/eaYXsC7GwsgRdUCQAAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 2.354135752047538, "height");
    
    is($msg->lat(), 37.762421610632735, "lat");
    
    is($msg->lon(), -122.38909854449612, "lon");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084800, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":24146,"flags":0,"h_accuracy":0,"height":2.354135752047538,"lat":37.762421610632735,"length":34,"lon":-122.38909854449612,"msg_type":513,"n_sats":8,"payload":"AJ9DGDO3BQiX4UJADeKU/eaYXsC7GwsgRdUCQAAAAAAIAA==","preamble":85,"sender":1219,"tow":407084800,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_10() {
    my $buf = decode_base64("VQECwwQiZJ9DGBZNkhaX4UJAQIZp4+aYXsAlY3JIH2fxPwAAAAAIAEY8");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3c46, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "ZJ9DGBZNkhaX4UJAQIZp4+aYXsAlY3JIH2fxPwAAAAAIAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 1.0876763181642641, "height");
    
    is($msg->lat(), 37.76242334502801, "lat");
    
    is($msg->lon(), -122.38909230523223, "lon");
    
    is($msg->n_sats(), 8, "n_sats");
    
    is($msg->tow(), 407084900, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":15430,"flags":0,"h_accuracy":0,"height":1.0876763181642641,"lat":37.76242334502801,"length":34,"lon":-122.38909230523223,"msg_type":513,"n_sats":8,"payload":"ZJ9DGBZNkhaX4UJAQIZp4+aYXsAlY3JIH2fxPwAAAAAIAA==","preamble":85,"sender":1219,"tow":407084900,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_dep_a_11() {
    my $buf = decode_base64("VQECwwQiLqJEGHz1LqmX4UJAh5Xqu+aYXsDCyXORpq8UQAAAAAAFANR5");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x79d4, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x201, "msg_type");
    
    is($msg->{'payload'}, "LqJEGHz1LqmX4UJAh5Xqu+aYXsDCyXORpq8UQAAAAAAFAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 5.171533844654222, "height");
    
    is($msg->lat(), 37.76244082253376, "lat");
    
    is($msg->lon(), -122.38908288868525, "lon");
    
    is($msg->n_sats(), 5, "n_sats");
    
    is($msg->tow(), 407151150, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":31188,"flags":0,"h_accuracy":0,"height":5.171533844654222,"lat":37.76244082253376,"length":34,"lon":-122.38908288868525,"msg_type":513,"n_sats":5,"payload":"LqJEGHz1LqmX4UJAh5Xqu+aYXsDCyXORpq8UQAAAAAAFAA==","preamble":85,"sender":1219,"tow":407151150,"v_accuracy":0}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_1();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_2();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_3();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_4();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_5();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_6();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_7();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_8();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_9();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_10();
test_auto_check_sbp_navigation_msg_pos_llh_dep_a_11();

done_testing();
