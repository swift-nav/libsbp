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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_msgObsDepA.yaml
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
sub test_auto_check_sbp_observation_msg_obs_dep_a_1() {
    my $buf = decode_base64("VUUAwwRiOJ5DGC4HIDjr+Xn0cv//IS5D2gDuy0Z8FhkDAGIruJ0CsIXFfX5H/f+5J0Q3AzytooNi5/3/ix4hEAqAsviIKnH9/ygUKkcN9vYRh/8zAwBAG2z5FtIpcnaDMP//HzTiOh4X2Q==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd917, "crc");
    
    is($msg->{'length'}, 98, "length");
    
    is($msg->{'msg_type'}, 0x45, "msg_type");
    
    is($msg->{'payload'}, "OJ5DGC4HIDjr+Xn0cv//IS5D2gDuy0Z8FhkDAGIruJ0CsIXFfX5H/f+5J0Q3AzytooNi5/3/ix4hEAqAsviIKnH9/ygUKkcN9vYRh/8zAwBAG2z5FtIpcnaDMP//HzTiOh4=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":32,"t":{"tow":407084600,"wn":1838}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":46,"l":{"f":33,"i":-36108},"lock":55875,"p":2046421816,"prn":0},{"cn0":43,"l":{"f":98,"i":203030},"lock":40376,"p":2085014510,"prn":2},{"cn0":39,"l":{"f":185,"i":-178306},"lock":14148,"p":2110096816,"prn":3},{"cn0":30,"l":{"f":139,"i":-137374},"lock":4129,"p":2208476476,"prn":10},{"cn0":20,"l":{"f":40,"i":-167638},"lock":18218,"p":2298000000,"prn":13},{"cn0":27,"l":{"f":64,"i":209919},"lock":63852,"p":2266101494,"prn":22},{"cn0":52,"l":{"f":31,"i":-53117},"lock":15074,"p":1987193298,"prn":30}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":55575,"header":{"n_obs":32,"t":{"tow":407084600,"wn":1838}},"length":98,"msg_type":69,"obs":[{"cn0":46,"l":{"f":33,"i":-36108},"lock":55875,"p":2046421816,"prn":0},{"cn0":43,"l":{"f":98,"i":203030},"lock":40376,"p":2085014510,"prn":2},{"cn0":39,"l":{"f":185,"i":-178306},"lock":14148,"p":2110096816,"prn":3},{"cn0":30,"l":{"f":139,"i":-137374},"lock":4129,"p":2208476476,"prn":10},{"cn0":20,"l":{"f":40,"i":-167638},"lock":18218,"p":2298000000,"prn":13},{"cn0":27,"l":{"f":64,"i":209919},"lock":63852,"p":2266101494,"prn":22},{"cn0":52,"l":{"f":31,"i":-53117},"lock":15074,"p":1987193298,"prn":30}],"payload":"OJ5DGC4HIDjr+Xn0cv//IS5D2gDuy0Z8FhkDAGIruJ0CsIXFfX5H/f+5J0Q3AzytooNi5/3/ix4hEAqAsviIKnH9/ygUKkcN9vYRh/8zAwBAG2z5FtIpcnaDMP//HzTiOh4=","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_a_2() {
    my $buf = decode_base64("VUUAwwQUOJ5DGC4HIVQ0pHVmIAAAkz4++h/qDg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xeea, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x45, "msg_type");
    
    is($msg->{'payload'}, "OJ5DGC4HIVQ0pHVmIAAAkz4++h8=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":33,"t":{"tow":407084600,"wn":1838}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":62,"l":{"f":147,"i":8294},"lock":64062,"p":1973695572,"prn":31}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":3818,"header":{"n_obs":33,"t":{"tow":407084600,"wn":1838}},"length":20,"msg_type":69,"obs":[{"cn0":62,"l":{"f":147,"i":8294},"lock":64062,"p":1973695572,"prn":31}],"payload":"OJ5DGC4HIVQ0pHVmIAAAkz4++h8=","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_a_3() {
    my $buf = decode_base64("VUUAwwRiAJ9DGC4HICDR+XmRcv//jS1D2gCxgEZ8TxsDAJ8suJ0CO4fFfa9F/f9NKEQ3A9OsooOx5f3/FB8hEAqAsviIdG/9/14VKkcNtq0RhyU2AwDWG2z5FlsUcnbwL///gTTiOh7Idw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x77c8, "crc");
    
    is($msg->{'length'}, 98, "length");
    
    is($msg->{'msg_type'}, 0x45, "msg_type");
    
    is($msg->{'payload'}, "AJ9DGC4HICDR+XmRcv//jS1D2gCxgEZ8TxsDAJ8suJ0CO4fFfa9F/f9NKEQ3A9OsooOx5f3/FB8hEAqAsviIdG/9/14VKkcNtq0RhyU2AwDWG2z5FlsUcnbwL///gTTiOh4=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":32,"t":{"tow":407084800,"wn":1838}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":45,"l":{"f":141,"i":-36207},"lock":55875,"p":2046415136,"prn":0},{"cn0":44,"l":{"f":159,"i":203599},"lock":40376,"p":2084995249,"prn":2},{"cn0":40,"l":{"f":77,"i":-178769},"lock":14148,"p":2110097211,"prn":3},{"cn0":31,"l":{"f":20,"i":-137807},"lock":4129,"p":2208476371,"prn":10},{"cn0":21,"l":{"f":94,"i":-168076},"lock":18218,"p":2298000000,"prn":13},{"cn0":27,"l":{"f":214,"i":210469},"lock":63852,"p":2266082742,"prn":22},{"cn0":52,"l":{"f":129,"i":-53264},"lock":15074,"p":1987187803,"prn":30}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":30664,"header":{"n_obs":32,"t":{"tow":407084800,"wn":1838}},"length":98,"msg_type":69,"obs":[{"cn0":45,"l":{"f":141,"i":-36207},"lock":55875,"p":2046415136,"prn":0},{"cn0":44,"l":{"f":159,"i":203599},"lock":40376,"p":2084995249,"prn":2},{"cn0":40,"l":{"f":77,"i":-178769},"lock":14148,"p":2110097211,"prn":3},{"cn0":31,"l":{"f":20,"i":-137807},"lock":4129,"p":2208476371,"prn":10},{"cn0":21,"l":{"f":94,"i":-168076},"lock":18218,"p":2298000000,"prn":13},{"cn0":27,"l":{"f":214,"i":210469},"lock":63852,"p":2266082742,"prn":22},{"cn0":52,"l":{"f":129,"i":-53264},"lock":15074,"p":1987187803,"prn":30}],"payload":"AJ9DGC4HICDR+XmRcv//jS1D2gCxgEZ8TxsDAJ8suJ0CO4fFfa9F/f9NKEQ3A9OsooOx5f3/FB8hEAqAsviIdG/9/14VKkcNtq0RhyU2AwDWG2z5FlsUcnbwL///gTTiOh4=","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_a_4() {
    my $buf = decode_base64("VUUAwwQUAJ9DGC4HITETpHV4IAAA3j8++h8L5w==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe70b, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x45, "msg_type");
    
    is($msg->{'payload'}, "AJ9DGC4HITETpHV4IAAA3j8++h8=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":33,"t":{"tow":407084800,"wn":1838}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":63,"l":{"f":222,"i":8312},"lock":64062,"p":1973687089,"prn":31}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":59147,"header":{"n_obs":33,"t":{"tow":407084800,"wn":1838}},"length":20,"msg_type":69,"obs":[{"cn0":63,"l":{"f":222,"i":8312},"lock":64062,"p":1973687089,"prn":31}],"payload":"AJ9DGC4HITETpHV4IAAA3j8++h8=","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_a_5() {
    my $buf = decode_base64("VUUAwwRIYKJEGC4HEFeE2Xl5lP//vSuvkwCEQMh9ah/+/wEpDrEDgLL4iEZE/v+mEriFDRh/soYGGQIA+RwhYBaqaFZ2Q3D//8s40FgeK2s=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6b2b, "crc");
    
    is($msg->{'length'}, 72, "length");
    
    is($msg->{'msg_type'}, 0x45, "msg_type");
    
    is($msg->{'payload'}, "YKJEGC4HEFeE2Xl5lP//vSuvkwCEQMh9ah/+/wEpDrEDgLL4iEZE/v+mEriFDRh/soYGGQIA+RwhYBaqaFZ2Q3D//8s40Fge", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":16,"t":{"tow":407151200,"wn":1838}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":43,"l":{"f":189,"i":-27527},"lock":37807,"p":2044298327,"prn":0},{"cn0":41,"l":{"f":1,"i":-123030},"lock":45326,"p":2110275716,"prn":3},{"cn0":18,"l":{"f":166,"i":-113594},"lock":34232,"p":2298000000,"prn":13},{"cn0":28,"l":{"f":249,"i":137478},"lock":24609,"p":2259844888,"prn":22},{"cn0":56,"l":{"f":203,"i":-36797},"lock":22736,"p":1985374378,"prn":30}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":27435,"header":{"n_obs":16,"t":{"tow":407151200,"wn":1838}},"length":72,"msg_type":69,"obs":[{"cn0":43,"l":{"f":189,"i":-27527},"lock":37807,"p":2044298327,"prn":0},{"cn0":41,"l":{"f":1,"i":-123030},"lock":45326,"p":2110275716,"prn":3},{"cn0":18,"l":{"f":166,"i":-113594},"lock":34232,"p":2298000000,"prn":13},{"cn0":28,"l":{"f":249,"i":137478},"lock":24609,"p":2259844888,"prn":22},{"cn0":56,"l":{"f":203,"i":-36797},"lock":22736,"p":1985374378,"prn":30}],"payload":"YKJEGC4HEFeE2Xl5lP//vSuvkwCEQMh9ah/+/wEpDrEDgLL4iEZE/v+mEriFDRh/soYGGQIA+RwhYBaqaFZ2Q3D//8s40Fge","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_a_6() {
    my $buf = decode_base64("VUUAwwRIKKNEGC4HEIRr2XkOlP//ASyvkwCBQsh9lB3+/5kpDrEDgLL4iI9C/v/eEriFDZ41soYqGwIA7R4hYBYmU1Z2qG///y040FgeAa8=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xaf01, "crc");
    
    is($msg->{'length'}, 72, "length");
    
    is($msg->{'msg_type'}, 0x45, "msg_type");
    
    is($msg->{'payload'}, "KKNEGC4HEIRr2XkOlP//ASyvkwCBQsh9lB3+/5kpDrEDgLL4iI9C/v/eEriFDZ41soYqGwIA7R4hYBYmU1Z2qG///y040Fge", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":16,"t":{"tow":407151400,"wn":1838}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":44,"l":{"f":1,"i":-27634},"lock":37807,"p":2044291972,"prn":0},{"cn0":41,"l":{"f":153,"i":-123500},"lock":45326,"p":2110276225,"prn":3},{"cn0":18,"l":{"f":222,"i":-114033},"lock":34232,"p":2298000000,"prn":13},{"cn0":30,"l":{"f":237,"i":138026},"lock":24609,"p":2259826078,"prn":22},{"cn0":56,"l":{"f":45,"i":-36952},"lock":22736,"p":1985368870,"prn":30}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":44801,"header":{"n_obs":16,"t":{"tow":407151400,"wn":1838}},"length":72,"msg_type":69,"obs":[{"cn0":44,"l":{"f":1,"i":-27634},"lock":37807,"p":2044291972,"prn":0},{"cn0":41,"l":{"f":153,"i":-123500},"lock":45326,"p":2110276225,"prn":3},{"cn0":18,"l":{"f":222,"i":-114033},"lock":34232,"p":2298000000,"prn":13},{"cn0":30,"l":{"f":237,"i":138026},"lock":24609,"p":2259826078,"prn":22},{"cn0":56,"l":{"f":45,"i":-36952},"lock":22736,"p":1985368870,"prn":30}],"payload":"KKNEGC4HEIRr2XkOlP//ASyvkwCBQsh9lB3+/5kpDrEDgLL4iI9C/v/eEriFDZ41soYqGwIA7R4hYBYmU1Z2qG///y040Fge","preamble":85,"sender":1219}})), "raw_json");
}
test_auto_check_sbp_observation_msg_obs_dep_a_1();
test_auto_check_sbp_observation_msg_obs_dep_a_2();
test_auto_check_sbp_observation_msg_obs_dep_a_3();
test_auto_check_sbp_observation_msg_obs_dep_a_4();
test_auto_check_sbp_observation_msg_obs_dep_a_5();
test_auto_check_sbp_observation_msg_obs_dep_a_6();

done_testing();