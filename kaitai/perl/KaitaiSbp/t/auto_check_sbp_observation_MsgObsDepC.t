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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepC.yaml
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
sub test_auto_check_sbp_observation_msg_obs_dep_c_1() {
    my $buf = decode_base64("VUkARphXCF+3GGoHIH76SVBxXvf/56Pl5QQAAAA83GBGUZP6/8TQFBwGAAAA+D0+TRw88v9uq7SyBwAAAO1Uvk2sJQ0AKarppAoAAAAkVQlL8LwVABO2xNEMAAAAvq8=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xafbe, "crc");
    
    is($msg->{'length'}, 87, "length");
    
    is($msg->{'msg_type'}, 0x49, "msg_type");
    
    is($msg->{'payload'}, "CF+3GGoHIH76SVBxXvf/56Pl5QQAAAA83GBGUZP6/8TQFBwGAAAA+D0+TRw88v9uq7SyBwAAAO1Uvk2sJQ0AKarppAoAAAAkVQlL8LwVABO2xNEMAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x9846, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":32,"t":{"tow":414670600,"wn":1898}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":163,"l":{"f":231,"i":-565647},"lock":58853,"p":1347025534,"sid":{"code":0,"reserved":0,"sat":4}},{"cn0":208,"l":{"f":196,"i":-355503},"lock":7188,"p":1180752956,"sid":{"code":0,"reserved":0,"sat":6}},{"cn0":171,"l":{"f":110,"i":-902116},"lock":45748,"p":1295924728,"sid":{"code":0,"reserved":0,"sat":7}},{"cn0":170,"l":{"f":41,"i":861612},"lock":42217,"p":1304319213,"sid":{"code":0,"reserved":0,"sat":10}},{"cn0":182,"l":{"f":19,"i":1424624},"lock":53700,"p":1258902820,"sid":{"code":0,"reserved":0,"sat":12}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":44990,"header":{"n_obs":32,"t":{"tow":414670600,"wn":1898}},"length":87,"msg_type":73,"obs":[{"cn0":163,"l":{"f":231,"i":-565647},"lock":58853,"p":1347025534,"sid":{"code":0,"reserved":0,"sat":4}},{"cn0":208,"l":{"f":196,"i":-355503},"lock":7188,"p":1180752956,"sid":{"code":0,"reserved":0,"sat":6}},{"cn0":171,"l":{"f":110,"i":-902116},"lock":45748,"p":1295924728,"sid":{"code":0,"reserved":0,"sat":7}},{"cn0":170,"l":{"f":41,"i":861612},"lock":42217,"p":1304319213,"sid":{"code":0,"reserved":0,"sat":10}},{"cn0":182,"l":{"f":19,"i":1424624},"lock":53700,"p":1258902820,"sid":{"code":0,"reserved":0,"sat":12}}],"payload":"CF+3GGoHIH76SVBxXvf/56Pl5QQAAAA83GBGUZP6/8TQFBwGAAAA+D0+TRw88v9uq7SyBwAAAO1Uvk2sJQ0AKarppAoAAAAkVQlL8LwVABO2xNEMAAAA","preamble":85,"sender":38982}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_c_2() {
    my $buf = decode_base64("VUkARpg3CF+3GGoHIUSmS0265hgAZbqiZhAAAABX/5tFSp4FABq+zh4bAAAAQFl8RBoWAwBy2eFJHQAAACWz");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb325, "crc");
    
    is($msg->{'length'}, 55, "length");
    
    is($msg->{'msg_type'}, 0x49, "msg_type");
    
    is($msg->{'payload'}, "CF+3GGoHIUSmS0265hgAZbqiZhAAAABX/5tFSp4FABq+zh4bAAAAQFl8RBoWAwBy2eFJHQAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x9846, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":33,"t":{"tow":414670600,"wn":1898}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":186,"l":{"f":101,"i":1631930},"lock":26274,"p":1296803396,"sid":{"code":0,"reserved":0,"sat":16}},{"cn0":190,"l":{"f":26,"i":368202},"lock":7886,"p":1167851351,"sid":{"code":0,"reserved":0,"sat":27}},{"cn0":217,"l":{"f":114,"i":202266},"lock":18913,"p":1149000000,"sid":{"code":0,"reserved":0,"sat":29}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":45861,"header":{"n_obs":33,"t":{"tow":414670600,"wn":1898}},"length":55,"msg_type":73,"obs":[{"cn0":186,"l":{"f":101,"i":1631930},"lock":26274,"p":1296803396,"sid":{"code":0,"reserved":0,"sat":16}},{"cn0":190,"l":{"f":26,"i":368202},"lock":7886,"p":1167851351,"sid":{"code":0,"reserved":0,"sat":27}},{"cn0":217,"l":{"f":114,"i":202266},"lock":18913,"p":1149000000,"sid":{"code":0,"reserved":0,"sat":29}}],"payload":"CF+3GGoHIUSmS0265hgAZbqiZhAAAABX/5tFSp4FABq+zh4bAAAAQFl8RBoWAwBy2eFJHQAAAA==","preamble":85,"sender":38982}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_c_3() {
    my $buf = decode_base64("VUkAAABXCF+3GGoHINn7SVAJSPj/HqhxUQQAAADT3GBGxmv7/3PDNZAGAAAATT0+TSih8/+CsF2OBwAAAAFWvk1YTQwAdMfl1QoAAABdVQlLQIsUAHixxMIMAAAAjaE=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa18d, "crc");
    
    is($msg->{'length'}, 87, "length");
    
    is($msg->{'msg_type'}, 0x49, "msg_type");
    
    is($msg->{'payload'}, "CF+3GGoHINn7SVAJSPj/HqhxUQQAAADT3GBGxmv7/3PDNZAGAAAATT0+TSih8/+CsF2OBwAAAAFWvk1YTQwAdMfl1QoAAABdVQlLQIsUAHixxMIMAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x0, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":32,"t":{"tow":414670600,"wn":1898}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":168,"l":{"f":30,"i":-505847},"lock":20849,"p":1347025881,"sid":{"code":0,"reserved":0,"sat":4}},{"cn0":195,"l":{"f":115,"i":-300090},"lock":36917,"p":1180753107,"sid":{"code":0,"reserved":0,"sat":6}},{"cn0":176,"l":{"f":130,"i":-810712},"lock":36445,"p":1295924557,"sid":{"code":0,"reserved":0,"sat":7}},{"cn0":199,"l":{"f":116,"i":806232},"lock":54757,"p":1304319489,"sid":{"code":0,"reserved":0,"sat":10}},{"cn0":177,"l":{"f":120,"i":1346368},"lock":49860,"p":1258902877,"sid":{"code":0,"reserved":0,"sat":12}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":41357,"header":{"n_obs":32,"t":{"tow":414670600,"wn":1898}},"length":87,"msg_type":73,"obs":[{"cn0":168,"l":{"f":30,"i":-505847},"lock":20849,"p":1347025881,"sid":{"code":0,"reserved":0,"sat":4}},{"cn0":195,"l":{"f":115,"i":-300090},"lock":36917,"p":1180753107,"sid":{"code":0,"reserved":0,"sat":6}},{"cn0":176,"l":{"f":130,"i":-810712},"lock":36445,"p":1295924557,"sid":{"code":0,"reserved":0,"sat":7}},{"cn0":199,"l":{"f":116,"i":806232},"lock":54757,"p":1304319489,"sid":{"code":0,"reserved":0,"sat":10}},{"cn0":177,"l":{"f":120,"i":1346368},"lock":49860,"p":1258902877,"sid":{"code":0,"reserved":0,"sat":12}}],"payload":"CF+3GGoHINn7SVAJSPj/HqhxUQQAAADT3GBGxmv7/3PDNZAGAAAATT0+TSih8/+CsF2OBwAAAAFWvk1YTQwAdMfl1QoAAABdVQlLQIsUAHixxMIMAAAA","preamble":85,"sender":0}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_c_4() {
    my $buf = decode_base64("VUkAAAA3CF+3GGoHIUanS02MiBcAWruegRAAAADo/5tFLa8FABHQrzgbAAAAQFl8RC1gAwBLuUnOHQAAANye");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9edc, "crc");
    
    is($msg->{'length'}, 55, "length");
    
    is($msg->{'msg_type'}, 0x49, "msg_type");
    
    is($msg->{'payload'}, "CF+3GGoHIUanS02MiBcAWruegRAAAADo/5tFLa8FABHQrzgbAAAAQFl8RC1gAwBLuUnOHQAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x0, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":33,"t":{"tow":414670600,"wn":1898}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":187,"l":{"f":90,"i":1542284},"lock":33182,"p":1296803654,"sid":{"code":0,"reserved":0,"sat":16}},{"cn0":208,"l":{"f":17,"i":372525},"lock":14511,"p":1167851496,"sid":{"code":0,"reserved":0,"sat":27}},{"cn0":185,"l":{"f":75,"i":221229},"lock":52809,"p":1149000000,"sid":{"code":0,"reserved":0,"sat":29}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":40668,"header":{"n_obs":33,"t":{"tow":414670600,"wn":1898}},"length":55,"msg_type":73,"obs":[{"cn0":187,"l":{"f":90,"i":1542284},"lock":33182,"p":1296803654,"sid":{"code":0,"reserved":0,"sat":16}},{"cn0":208,"l":{"f":17,"i":372525},"lock":14511,"p":1167851496,"sid":{"code":0,"reserved":0,"sat":27}},{"cn0":185,"l":{"f":75,"i":221229},"lock":52809,"p":1149000000,"sid":{"code":0,"reserved":0,"sat":29}}],"payload":"CF+3GGoHIUanS02MiBcAWruegRAAAADo/5tFLa8FABHQrzgbAAAAQFl8RC1gAwBLuUnOHQAAAA==","preamble":85,"sender":0}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_c_5() {
    my $buf = decode_base64("VUkARphX0F+3GGoHICwISlBWXff/OZ7l5QQAAADg5WBGnJL6/93IFBwGAAAAPFI+TV068v8npLSyBwAAAN5Jvk0uJw0AyrXppAoAAACVQAlLcr8VAPm2xNEMAAAAcAg=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x870, "crc");
    
    is($msg->{'length'}, 87, "length");
    
    is($msg->{'msg_type'}, 0x49, "msg_type");
    
    is($msg->{'payload'}, "0F+3GGoHICwISlBWXff/OZ7l5QQAAADg5WBGnJL6/93IFBwGAAAAPFI+TV068v8npLSyBwAAAN5Jvk0uJw0AyrXppAoAAACVQAlLcr8VAPm2xNEMAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x9846, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":32,"t":{"tow":414670800,"wn":1898}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":158,"l":{"f":57,"i":-565930},"lock":58853,"p":1347029036,"sid":{"code":0,"reserved":0,"sat":4}},{"cn0":200,"l":{"f":221,"i":-355684},"lock":7188,"p":1180755424,"sid":{"code":0,"reserved":0,"sat":6}},{"cn0":164,"l":{"f":39,"i":-902563},"lock":45748,"p":1295929916,"sid":{"code":0,"reserved":0,"sat":7}},{"cn0":181,"l":{"f":202,"i":861998},"lock":42217,"p":1304316382,"sid":{"code":0,"reserved":0,"sat":10}},{"cn0":182,"l":{"f":249,"i":1425266},"lock":53700,"p":1258897557,"sid":{"code":0,"reserved":0,"sat":12}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":2160,"header":{"n_obs":32,"t":{"tow":414670800,"wn":1898}},"length":87,"msg_type":73,"obs":[{"cn0":158,"l":{"f":57,"i":-565930},"lock":58853,"p":1347029036,"sid":{"code":0,"reserved":0,"sat":4}},{"cn0":200,"l":{"f":221,"i":-355684},"lock":7188,"p":1180755424,"sid":{"code":0,"reserved":0,"sat":6}},{"cn0":164,"l":{"f":39,"i":-902563},"lock":45748,"p":1295929916,"sid":{"code":0,"reserved":0,"sat":7}},{"cn0":181,"l":{"f":202,"i":861998},"lock":42217,"p":1304316382,"sid":{"code":0,"reserved":0,"sat":10}},{"cn0":182,"l":{"f":249,"i":1425266},"lock":53700,"p":1258897557,"sid":{"code":0,"reserved":0,"sat":12}}],"payload":"0F+3GGoHICwISlBWXff/OZ7l5QQAAADg5WBGnJL6/93IFBwGAAAAPFI+TV068v8npLSyBwAAAN5Jvk0uJw0AyrXppAoAAACVQAlLcr8VAPm2xNEMAAAA","preamble":85,"sender":38982}})), "raw_json");
}
test_auto_check_sbp_observation_msg_obs_dep_c_1();
test_auto_check_sbp_observation_msg_obs_dep_c_2();
test_auto_check_sbp_observation_msg_obs_dep_c_3();
test_auto_check_sbp_observation_msg_obs_dep_c_4();
test_auto_check_sbp_observation_msg_obs_dep_c_5();

done_testing();