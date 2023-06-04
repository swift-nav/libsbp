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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgtrackingStateDepA.yaml
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
sub test_auto_check_sbp_tracking_msgtracking_state_dep_a_1() {
    my $buf = decode_base64("VRYAwwRCAQDMsTNBAQLGBCdBAQPbthtBAQeEeGVBAQpbW/tAAQ0qJaNAARaCuNdAAR5zNUtBAR8QSn5BARmExIdAAQZkO99AEeE=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe111, "crc");
    
    is($msg->{'length'}, 66, "length");
    
    is($msg->{'msg_type'}, 0x16, "msg_type");
    
    is($msg->{'payload'}, "AQDMsTNBAQLGBCdBAQPbthtBAQeEeGVBAQpbW/tAAQ0qJaNAARaCuNdAAR5zNUtBAR8QSn5BARmExIdAAQZkO99A", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":11.230907440185547,"prn":0,"state":1},{"cn0":10.438665390014648,"prn":2,"state":1},{"cn0":9.732142448425293,"prn":3,"state":1},{"cn0":14.341922760009766,"prn":7,"state":1},{"cn0":7.8549017906188965,"prn":10,"state":1},{"cn0":5.0982866287231445,"prn":13,"state":1},{"cn0":6.741272926330566,"prn":22,"state":1},{"cn0":12.700549125671387,"prn":30,"state":1},{"cn0":15.893081665039062,"prn":31,"state":1},{"cn0":4.242738723754883,"prn":25,"state":1},{"cn0":6.97599983215332,"prn":6,"state":1}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":57617,"length":66,"msg_type":22,"payload":"AQDMsTNBAQLGBCdBAQPbthtBAQeEeGVBAQpbW/tAAQ0qJaNAARaCuNdAAR5zNUtBAR8QSn5BARmExIdAAQZkO99A","preamble":85,"sender":1219,"states":[{"cn0":11.230907440185547,"prn":0,"state":1},{"cn0":10.438665390014648,"prn":2,"state":1},{"cn0":9.732142448425293,"prn":3,"state":1},{"cn0":14.341922760009766,"prn":7,"state":1},{"cn0":7.8549017906188965,"prn":10,"state":1},{"cn0":5.0982866287231445,"prn":13,"state":1},{"cn0":6.741272926330566,"prn":22,"state":1},{"cn0":12.700549125671387,"prn":30,"state":1},{"cn0":15.893081665039062,"prn":31,"state":1},{"cn0":4.242738723754883,"prn":25,"state":1},{"cn0":6.97599983215332,"prn":6,"state":1}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msgtracking_state_dep_a_2() {
    my $buf = decode_base64("VRYAwwRCAQDYOTBBAQKRKS5BAQMEGiJBAQexQ21BAQo9UPlAAQ36x5tAARY3E9dAAR6Kik9BAR/Ws3dBARk1inhAAQa394FAqK0=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xada8, "crc");
    
    is($msg->{'length'}, 66, "length");
    
    is($msg->{'msg_type'}, 0x16, "msg_type");
    
    is($msg->{'payload'}, "AQDYOTBBAQKRKS5BAQMEGiJBAQexQ21BAQo9UPlAAQ36x5tAARY3E9dAAR6Kik9BAR/Ws3dBARk1inhAAQa394FA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":11.014122009277344,"prn":0,"state":1},{"cn0":10.885148048400879,"prn":2,"state":1},{"cn0":10.131351470947266,"prn":3,"state":1},{"cn0":14.829026222229004,"prn":7,"state":1},{"cn0":7.79104471206665,"prn":10,"state":1},{"cn0":4.868161201477051,"prn":13,"state":1},{"cn0":6.721095561981201,"prn":22,"state":1},{"cn0":12.971323013305664,"prn":30,"state":1},{"cn0":15.481405258178711,"prn":31,"state":1},{"cn0":3.8834354877471924,"prn":25,"state":1},{"cn0":4.061488628387451,"prn":6,"state":1}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":44456,"length":66,"msg_type":22,"payload":"AQDYOTBBAQKRKS5BAQMEGiJBAQexQ21BAQo9UPlAAQ36x5tAARY3E9dAAR6Kik9BAR/Ws3dBARk1inhAAQa394FA","preamble":85,"sender":1219,"states":[{"cn0":11.014122009277344,"prn":0,"state":1},{"cn0":10.885148048400879,"prn":2,"state":1},{"cn0":10.131351470947266,"prn":3,"state":1},{"cn0":14.829026222229004,"prn":7,"state":1},{"cn0":7.79104471206665,"prn":10,"state":1},{"cn0":4.868161201477051,"prn":13,"state":1},{"cn0":6.721095561981201,"prn":22,"state":1},{"cn0":12.971323013305664,"prn":30,"state":1},{"cn0":15.481405258178711,"prn":31,"state":1},{"cn0":3.8834354877471924,"prn":25,"state":1},{"cn0":4.061488628387451,"prn":6,"state":1}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msgtracking_state_dep_a_3() {
    my $buf = decode_base64("VRYAwwRCAQCNTDxBAQJFiy5BAQOSGx5BAQfrOGFBAQqN1fNAAQ36qqZAARYRZclAAR6st1NBAR/uwXhBARncMIRAAQYx1jZAbrM=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb36e, "crc");
    
    is($msg->{'length'}, 66, "length");
    
    is($msg->{'msg_type'}, 0x16, "msg_type");
    
    is($msg->{'payload'}, "AQCNTDxBAQJFiy5BAQOSGx5BAQfrOGFBAQqN1fNAAQ36qqZAARYRZclAAR6st1NBAR/uwXhBARncMIRAAQYx1jZA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":11.768689155578613,"prn":0,"state":1},{"cn0":10.909001350402832,"prn":2,"state":1},{"cn0":9.881731033325195,"prn":3,"state":1},{"cn0":14.076395988464355,"prn":7,"state":1},{"cn0":7.619818210601807,"prn":10,"state":1},{"cn0":5.208371162414551,"prn":13,"state":1},{"cn0":6.2935872077941895,"prn":22,"state":1},{"cn0":13.232341766357422,"prn":30,"state":1},{"cn0":15.547346115112305,"prn":31,"state":1},{"cn0":4.130964279174805,"prn":25,"state":1},{"cn0":2.856823205947876,"prn":6,"state":1}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":45934,"length":66,"msg_type":22,"payload":"AQCNTDxBAQJFiy5BAQOSGx5BAQfrOGFBAQqN1fNAAQ36qqZAARYRZclAAR6st1NBAR/uwXhBARncMIRAAQYx1jZA","preamble":85,"sender":1219,"states":[{"cn0":11.768689155578613,"prn":0,"state":1},{"cn0":10.909001350402832,"prn":2,"state":1},{"cn0":9.881731033325195,"prn":3,"state":1},{"cn0":14.076395988464355,"prn":7,"state":1},{"cn0":7.619818210601807,"prn":10,"state":1},{"cn0":5.208371162414551,"prn":13,"state":1},{"cn0":6.2935872077941895,"prn":22,"state":1},{"cn0":13.232341766357422,"prn":30,"state":1},{"cn0":15.547346115112305,"prn":31,"state":1},{"cn0":4.130964279174805,"prn":25,"state":1},{"cn0":2.856823205947876,"prn":6,"state":1}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msgtracking_state_dep_a_4() {
    my $buf = decode_base64("VRYAwwRCAQA3j3hCAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/+Fk=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x59f8, "crc");
    
    is($msg->{'length'}, 66, "length");
    
    is($msg->{'msg_type'}, 0x16, "msg_type");
    
    is($msg->{'payload'}, "AQA3j3hCAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":62.13985824584961,"prn":0,"state":1},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":23032,"length":66,"msg_type":22,"payload":"AQA3j3hCAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/","preamble":85,"sender":1219,"states":[{"cn0":62.13985824584961,"prn":0,"state":1},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msgtracking_state_dep_a_5() {
    my $buf = decode_base64("VRYAwwRCAQDaDhNCAQLSAxVBAQPq1oZBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/VGU=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6554, "crc");
    
    is($msg->{'length'}, 66, "length");
    
    is($msg->{'msg_type'}, 0x16, "msg_type");
    
    is($msg->{'payload'}, "AQDaDhNCAQLSAxVBAQPq1oZBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":36.764503479003906,"prn":0,"state":1},{"cn0":9.313432693481445,"prn":2,"state":1},{"cn0":16.854938507080078,"prn":3,"state":1},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":25940,"length":66,"msg_type":22,"payload":"AQDaDhNCAQLSAxVBAQPq1oZBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/","preamble":85,"sender":1219,"states":[{"cn0":36.764503479003906,"prn":0,"state":1},{"cn0":9.313432693481445,"prn":2,"state":1},{"cn0":16.854938507080078,"prn":3,"state":1},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msgtracking_state_dep_a_6() {
    my $buf = decode_base64("VRYAwwRCAQBiJ9tBAQIAADhAAQN5ewdBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/JXs=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7b25, "crc");
    
    is($msg->{'length'}, 66, "length");
    
    is($msg->{'msg_type'}, 0x16, "msg_type");
    
    is($msg->{'payload'}, "AQBiJ9tBAQIAADhAAQN5ewdBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":27.394229888916016,"prn":0,"state":1},{"cn0":2.875,"prn":2,"state":1},{"cn0":8.467644691467285,"prn":3,"state":1},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":31525,"length":66,"msg_type":22,"payload":"AQBiJ9tBAQIAADhAAQN5ewdBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/","preamble":85,"sender":1219,"states":[{"cn0":27.394229888916016,"prn":0,"state":1},{"cn0":2.875,"prn":2,"state":1},{"cn0":8.467644691467285,"prn":3,"state":1},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0},{"cn0":-1.0,"prn":0,"state":0}]}})), "raw_json");
}
test_auto_check_sbp_tracking_msgtracking_state_dep_a_1();
test_auto_check_sbp_tracking_msgtracking_state_dep_a_2();
test_auto_check_sbp_tracking_msgtracking_state_dep_a_3();
test_auto_check_sbp_tracking_msgtracking_state_dep_a_4();
test_auto_check_sbp_tracking_msgtracking_state_dep_a_5();
test_auto_check_sbp_tracking_msgtracking_state_dep_a_6();

done_testing();