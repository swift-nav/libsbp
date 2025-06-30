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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLH.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_llh_1() {
    my $buf = decode_base64("VQoC04giKPR6E8lqm7oqoEJAqG0a4QB4XsCCZu3mKzY8QAAAAAAOAq+i");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa2af, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x20a, "msg_type");
    
    is($msg->{'payload'}, "KPR6E8lqm7oqoEJAqG0a4QB4XsCCZu3mKzY8QAAAAAAOAg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 2, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 28.21160739227208, "height");
    
    is($msg->lat(), 37.25130398358085, "lat");
    
    is($msg->lon(), -121.87505366879361, "lon");
    
    is($msg->n_sats(), 14, "n_sats");
    
    is($msg->tow(), 326825000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":41647,"flags":2,"h_accuracy":0,"height":28.21160739227208,"lat":37.25130398358085,"length":34,"lon":-121.87505366879361,"msg_type":522,"n_sats":14,"payload":"KPR6E8lqm7oqoEJAqG0a4QB4XsCCZu3mKzY8QAAAAAAOAg==","preamble":85,"sender":35027,"tow":326825000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_2() {
    my $buf = decode_base64("VQoC04giEPh6EzSx+7IqoEJA7RZh4AB4XsBrvG1a9707QAAAAAAPAiax");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb126, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x20a, "msg_type");
    
    is($msg->{'payload'}, "EPh6EzSx+7IqoEJA7RZh4AB4XsBrvG1a9707QAAAAAAPAg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 2, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 27.742055560866373, "height");
    
    is($msg->lat(), 37.251303074738104, "lat");
    
    is($msg->lon(), -121.87505349618341, "lon");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326826000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":45350,"flags":2,"h_accuracy":0,"height":27.742055560866373,"lat":37.251303074738104,"length":34,"lon":-121.87505349618341,"msg_type":522,"n_sats":15,"payload":"EPh6EzSx+7IqoEJA7RZh4AB4XsBrvG1a9707QAAAAAAPAg==","preamble":85,"sender":35027,"tow":326826000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_3() {
    my $buf = decode_base64("VQoC04gi+Pt6E4dCCaMqoEJAkghj4QB4XsAttY/bHJ07QAAAAAAPAjMo");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2833, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x20a, "msg_type");
    
    is($msg->{'payload'}, "+Pt6E4dCCaMqoEJAkghj4QB4XsAttY/bHJ07QAAAAAAPAg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 2, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 27.613721582970516, "height");
    
    is($msg->lat(), 37.25130117370741, "lat");
    
    is($msg->lon(), -121.87505373641241, "lon");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326827000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":10291,"flags":2,"h_accuracy":0,"height":27.613721582970516,"lat":37.25130117370741,"length":34,"lon":-121.87505373641241,"msg_type":522,"n_sats":15,"payload":"+Pt6E4dCCaMqoEJAkghj4QB4XsAttY/bHJ07QAAAAAAPAg==","preamble":85,"sender":35027,"tow":326827000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_4() {
    my $buf = decode_base64("VQoC04gi4P96ExIs/XcqoEJAMG0n5wB4XsC5TDARd807QAAAAAAPAgzC");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc20c, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x20a, "msg_type");
    
    is($msg->{'payload'}, "4P96ExIs/XcqoEJAMG0n5wB4XsC5TDARd807QAAAAAAPAg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 2, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 27.80259807042305, "height");
    
    is($msg->lat(), 37.251296042079176, "lat");
    
    is($msg->lon(), -121.87505511141057, "lon");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326828000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":49676,"flags":2,"h_accuracy":0,"height":27.80259807042305,"lat":37.251296042079176,"length":34,"lon":-121.87505511141057,"msg_type":522,"n_sats":15,"payload":"4P96ExIs/XcqoEJAMG0n5wB4XsC5TDARd807QAAAAAAPAg==","preamble":85,"sender":35027,"tow":326828000,"v_accuracy":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_llh_5() {
    my $buf = decode_base64("VQoC04giyAN7E+Ht7loqoEJAO49G6wB4XsBlavngg/A7QAAAAAAPAiJn");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6722, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x20a, "msg_type");
    
    is($msg->{'payload'}, "yAN7E+Ht7loqoEJAO49G6wB4XsBlavngg/A7QAAAAAAPAg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 2, "flags");
    
    is($msg->h_accuracy(), 0, "h_accuracy");
    
    is($msg->height(), 27.939512310879213, "height");
    
    is($msg->lat(), 37.251292578377395, "lat");
    
    is($msg->lon(), -121.87505609407974, "lon");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326829000, "tow");
    
    is($msg->v_accuracy(), 0, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":26402,"flags":2,"h_accuracy":0,"height":27.939512310879213,"lat":37.251292578377395,"length":34,"lon":-121.87505609407974,"msg_type":522,"n_sats":15,"payload":"yAN7E+Ht7loqoEJAO49G6wB4XsBlavngg/A7QAAAAAAPAg==","preamble":85,"sender":35027,"tow":326829000,"v_accuracy":0}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_llh_1();
test_auto_check_sbp_navigation_msg_pos_llh_2();
test_auto_check_sbp_navigation_msg_pos_llh_3();
test_auto_check_sbp_navigation_msg_pos_llh_4();
test_auto_check_sbp_navigation_msg_pos_llh_5();

done_testing();
