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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepB.yaml
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
sub test_auto_check_sbp_observation_msg_obs_dep_b_1() {
    my $buf = decode_base64("VUMA9tdneC4nAPsGILSvu4XfNQcHG50AAMoAAAA6jFWTWBy+B6+QAADLAAAA3Iz4itCsTQeHlwAA0AAAAK3CSIdzEhwH8pwAANQAAACkkGl8EsSJBnioAADZAAAAHujki9IHWgdXlgAA2gAAAKlV");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x55a9, "crc");
    
    is($msg->{'length'}, 103, "length");
    
    is($msg->{'msg_type'}, 0x43, "msg_type");
    
    is($msg->{'payload'}, "eC4nAPsGILSvu4XfNQcHG50AAMoAAAA6jFWTWBy+B6+QAADLAAAA3Iz4itCsTQeHlwAA0AAAAK3CSIdzEhwH8pwAANQAAACkkGl8EsSJBnioAADZAAAAHujki9IHWgdXlgAA2gAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":32,"t":{"tow":2567800,"wn":1787}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":157,"l":{"f":27,"i":117913055},"lock":0,"p":2243669940,"sid":{"code":0,"reserved":0,"sat":202}},{"cn0":144,"l":{"f":175,"i":129899608},"lock":0,"p":2471857210,"sid":{"code":0,"reserved":0,"sat":203}},{"cn0":151,"l":{"f":135,"i":122531024},"lock":0,"p":2331544796,"sid":{"code":0,"reserved":0,"sat":208}},{"cn0":156,"l":{"f":242,"i":119280243},"lock":0,"p":2269692589,"sid":{"code":0,"reserved":0,"sat":212}},{"cn0":168,"l":{"f":120,"i":109691922},"lock":0,"p":2087293092,"sid":{"code":0,"reserved":0,"sat":217}},{"cn0":150,"l":{"f":87,"i":123340754},"lock":0,"p":2347034654,"sid":{"code":0,"reserved":0,"sat":218}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":21929,"header":{"n_obs":32,"t":{"tow":2567800,"wn":1787}},"length":103,"msg_type":67,"obs":[{"cn0":157,"l":{"f":27,"i":117913055},"lock":0,"p":2243669940,"sid":{"code":0,"reserved":0,"sat":202}},{"cn0":144,"l":{"f":175,"i":129899608},"lock":0,"p":2471857210,"sid":{"code":0,"reserved":0,"sat":203}},{"cn0":151,"l":{"f":135,"i":122531024},"lock":0,"p":2331544796,"sid":{"code":0,"reserved":0,"sat":208}},{"cn0":156,"l":{"f":242,"i":119280243},"lock":0,"p":2269692589,"sid":{"code":0,"reserved":0,"sat":212}},{"cn0":168,"l":{"f":120,"i":109691922},"lock":0,"p":2087293092,"sid":{"code":0,"reserved":0,"sat":217}},{"cn0":150,"l":{"f":87,"i":123340754},"lock":0,"p":2347034654,"sid":{"code":0,"reserved":0,"sat":218}}],"payload":"eC4nAPsGILSvu4XfNQcHG50AAMoAAAA6jFWTWBy+B6+QAADLAAAA3Iz4itCsTQeHlwAA0AAAAK3CSIdzEhwH8pwAANQAAACkkGl8EsSJBnioAADZAAAAHujki9IHWgdXlgAA2gAAAA==","preamble":85,"sender":55286}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_b_2() {
    my $buf = decode_base64("VUMA9tc3eC4nAPsGIUTHZYiF9yoH25oAANwAAADbDnuFYNcDB+ucAADeAAAAV6ZRegWtbQauqgAA4QAAAAvp");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe90b, "crc");
    
    is($msg->{'length'}, 55, "length");
    
    is($msg->{'msg_type'}, 0x43, "msg_type");
    
    is($msg->{'payload'}, "eC4nAPsGIUTHZYiF9yoH25oAANwAAADbDnuFYNcDB+ucAADeAAAAV6ZRegWtbQauqgAA4QAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":33,"t":{"tow":2567800,"wn":1787}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":154,"l":{"f":219,"i":120256389},"lock":0,"p":2288371524,"sid":{"code":0,"reserved":0,"sat":220}},{"cn0":156,"l":{"f":235,"i":117692256},"lock":0,"p":2239434459,"sid":{"code":0,"reserved":0,"sat":222}},{"cn0":170,"l":{"f":174,"i":107851013},"lock":0,"p":2052171351,"sid":{"code":0,"reserved":0,"sat":225}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":59659,"header":{"n_obs":33,"t":{"tow":2567800,"wn":1787}},"length":55,"msg_type":67,"obs":[{"cn0":154,"l":{"f":219,"i":120256389},"lock":0,"p":2288371524,"sid":{"code":0,"reserved":0,"sat":220}},{"cn0":156,"l":{"f":235,"i":117692256},"lock":0,"p":2239434459,"sid":{"code":0,"reserved":0,"sat":222}},{"cn0":170,"l":{"f":174,"i":107851013},"lock":0,"p":2052171351,"sid":{"code":0,"reserved":0,"sat":225}}],"payload":"eC4nAPsGIUTHZYiF9yoH25oAANwAAADbDnuFYNcDB+ucAADeAAAAV6ZRegWtbQauqgAA4QAAAA==","preamble":85,"sender":55286}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_b_3() {
    my $buf = decode_base64("VUMA9tdnQC8nAPsGIGSEu4XsMwcHXpwAAMoAAABhuFWTsh6+ByiMAADLAAAAh2/4ilqrTQcClgAA0AAAALTuSIe+FBwH8ZsAANQAAAAPmWl8XMSJBpmoAADZAAAAMbnki5AFWgcplgAA2gAAAPFi");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x62f1, "crc");
    
    is($msg->{'length'}, 103, "length");
    
    is($msg->{'msg_type'}, 0x43, "msg_type");
    
    is($msg->{'payload'}, "QC8nAPsGIGSEu4XsMwcHXpwAAMoAAABhuFWTsh6+ByiMAADLAAAAh2/4ilqrTQcClgAA0AAAALTuSIe+FBwH8ZsAANQAAAAPmWl8XMSJBpmoAADZAAAAMbnki5AFWgcplgAA2gAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":32,"t":{"tow":2568000,"wn":1787}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":156,"l":{"f":94,"i":117912556},"lock":0,"p":2243658852,"sid":{"code":0,"reserved":0,"sat":202}},{"cn0":140,"l":{"f":40,"i":129900210},"lock":0,"p":2471868513,"sid":{"code":0,"reserved":0,"sat":203}},{"cn0":150,"l":{"f":2,"i":122530650},"lock":0,"p":2331537287,"sid":{"code":0,"reserved":0,"sat":208}},{"cn0":155,"l":{"f":241,"i":119280830},"lock":0,"p":2269703860,"sid":{"code":0,"reserved":0,"sat":212}},{"cn0":168,"l":{"f":153,"i":109691996},"lock":0,"p":2087295247,"sid":{"code":0,"reserved":0,"sat":217}},{"cn0":150,"l":{"f":41,"i":123340176},"lock":0,"p":2347022641,"sid":{"code":0,"reserved":0,"sat":218}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":25329,"header":{"n_obs":32,"t":{"tow":2568000,"wn":1787}},"length":103,"msg_type":67,"obs":[{"cn0":156,"l":{"f":94,"i":117912556},"lock":0,"p":2243658852,"sid":{"code":0,"reserved":0,"sat":202}},{"cn0":140,"l":{"f":40,"i":129900210},"lock":0,"p":2471868513,"sid":{"code":0,"reserved":0,"sat":203}},{"cn0":150,"l":{"f":2,"i":122530650},"lock":0,"p":2331537287,"sid":{"code":0,"reserved":0,"sat":208}},{"cn0":155,"l":{"f":241,"i":119280830},"lock":0,"p":2269703860,"sid":{"code":0,"reserved":0,"sat":212}},{"cn0":168,"l":{"f":153,"i":109691996},"lock":0,"p":2087295247,"sid":{"code":0,"reserved":0,"sat":217}},{"cn0":150,"l":{"f":41,"i":123340176},"lock":0,"p":2347022641,"sid":{"code":0,"reserved":0,"sat":218}}],"payload":"QC8nAPsGIGSEu4XsMwcHXpwAAMoAAABhuFWTsh6+ByiMAADLAAAAh2/4ilqrTQcClgAA0AAAALTuSIe+FBwH8ZsAANQAAAAPmWl8XMSJBpmoAADZAAAAMbnki5AFWgcplgAA2gAAAA==","preamble":85,"sender":55286}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_b_4() {
    my $buf = decode_base64("VUMA9tc3QC8nAPsGIeqUZYgP9SoHFJoAANwAAADQ93qFENYDByacAADeAAAAD5ZRehasbQYHrAAA4QAAAMkN");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xdc9, "crc");
    
    is($msg->{'length'}, 55, "length");
    
    is($msg->{'msg_type'}, 0x43, "msg_type");
    
    is($msg->{'payload'}, "QC8nAPsGIeqUZYgP9SoHFJoAANwAAADQ93qFENYDByacAADeAAAAD5ZRehasbQYHrAAA4QAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":33,"t":{"tow":2568000,"wn":1787}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":154,"l":{"f":20,"i":120255759},"lock":0,"p":2288358634,"sid":{"code":0,"reserved":0,"sat":220}},{"cn0":156,"l":{"f":38,"i":117691920},"lock":0,"p":2239428560,"sid":{"code":0,"reserved":0,"sat":222}},{"cn0":172,"l":{"f":7,"i":107850774},"lock":0,"p":2052167183,"sid":{"code":0,"reserved":0,"sat":225}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":3529,"header":{"n_obs":33,"t":{"tow":2568000,"wn":1787}},"length":55,"msg_type":67,"obs":[{"cn0":154,"l":{"f":20,"i":120255759},"lock":0,"p":2288358634,"sid":{"code":0,"reserved":0,"sat":220}},{"cn0":156,"l":{"f":38,"i":117691920},"lock":0,"p":2239428560,"sid":{"code":0,"reserved":0,"sat":222}},{"cn0":172,"l":{"f":7,"i":107850774},"lock":0,"p":2052167183,"sid":{"code":0,"reserved":0,"sat":225}}],"payload":"QC8nAPsGIeqUZYgP9SoHFJoAANwAAADQ93qFENYDByacAADeAAAAD5ZRehasbQYHrAAA4QAAAA==","preamble":85,"sender":55286}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_dep_b_5() {
    my $buf = decode_base64("VUMA9tdnCDAnAPsGIP5gu4X5MQcHpZwAAMoAAABx5VWTCyG+B2qPAADLAAAAtlX4iuOpTQeflgAA0AAAABEYSYcKFxwHB5wAANQAAABsm2l8psSJBrqqAADZAAAA1o7ki00DWgfslwAA2gAAADt2");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x763b, "crc");
    
    is($msg->{'length'}, 103, "length");
    
    is($msg->{'msg_type'}, 0x43, "msg_type");
    
    is($msg->{'payload'}, "CDAnAPsGIP5gu4X5MQcHpZwAAMoAAABx5VWTCyG+B2qPAADLAAAAtlX4iuOpTQeflgAA0AAAABEYSYcKFxwHB5wAANQAAABsm2l8psSJBrqqAADZAAAA1o7ki00DWgfslwAA2gAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":32,"t":{"tow":2568200,"wn":1787}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":156,"l":{"f":165,"i":117912057},"lock":0,"p":2243649790,"sid":{"code":0,"reserved":0,"sat":202}},{"cn0":143,"l":{"f":106,"i":129900811},"lock":0,"p":2471880049,"sid":{"code":0,"reserved":0,"sat":203}},{"cn0":150,"l":{"f":159,"i":122530275},"lock":0,"p":2331530678,"sid":{"code":0,"reserved":0,"sat":208}},{"cn0":156,"l":{"f":7,"i":119281418},"lock":0,"p":2269714449,"sid":{"code":0,"reserved":0,"sat":212}},{"cn0":170,"l":{"f":186,"i":109692070},"lock":0,"p":2087295852,"sid":{"code":0,"reserved":0,"sat":217}},{"cn0":151,"l":{"f":236,"i":123339597},"lock":0,"p":2347011798,"sid":{"code":0,"reserved":0,"sat":218}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":30267,"header":{"n_obs":32,"t":{"tow":2568200,"wn":1787}},"length":103,"msg_type":67,"obs":[{"cn0":156,"l":{"f":165,"i":117912057},"lock":0,"p":2243649790,"sid":{"code":0,"reserved":0,"sat":202}},{"cn0":143,"l":{"f":106,"i":129900811},"lock":0,"p":2471880049,"sid":{"code":0,"reserved":0,"sat":203}},{"cn0":150,"l":{"f":159,"i":122530275},"lock":0,"p":2331530678,"sid":{"code":0,"reserved":0,"sat":208}},{"cn0":156,"l":{"f":7,"i":119281418},"lock":0,"p":2269714449,"sid":{"code":0,"reserved":0,"sat":212}},{"cn0":170,"l":{"f":186,"i":109692070},"lock":0,"p":2087295852,"sid":{"code":0,"reserved":0,"sat":217}},{"cn0":151,"l":{"f":236,"i":123339597},"lock":0,"p":2347011798,"sid":{"code":0,"reserved":0,"sat":218}}],"payload":"CDAnAPsGIP5gu4X5MQcHpZwAAMoAAABx5VWTCyG+B2qPAADLAAAAtlX4iuOpTQeflgAA0AAAABEYSYcKFxwHB5wAANQAAABsm2l8psSJBrqqAADZAAAA1o7ki00DWgfslwAA2gAAAA==","preamble":85,"sender":55286}})), "raw_json");
}
test_auto_check_sbp_observation_msg_obs_dep_b_1();
test_auto_check_sbp_observation_msg_obs_dep_b_2();
test_auto_check_sbp_observation_msg_obs_dep_b_3();
test_auto_check_sbp_observation_msg_obs_dep_b_4();
test_auto_check_sbp_observation_msg_obs_dep_b_5();

done_testing();