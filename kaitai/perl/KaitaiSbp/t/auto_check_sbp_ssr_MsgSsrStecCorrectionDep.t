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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDep.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_stec_correction_dep_1() {
    my $buf = decode_base64("VfsFzJf1nuRydTKenCp3nJ1wLzyEKEZX61OxxgMOCEYMLDW1Wq73ljqs97N3sH0EseVxDk2ZuRc13ruS+lvU1w5r+l5rIVvqANWLX7MyFUquqT1WW44zbAkm4ZJlSYs4dVIl1WzNXRITwyHKV86yfbx3OEWWlkwDgxJJ0EjoCPrLsqqj/FYx97KmOB8Kd9Xx1KQBoioSfKl5nho4F459KHhDLX7rbhcM8VhF7/w5XSzJ2K3yshEF36nAA01rApDpDlgg0QERe5spt/SeUjVnDsq5I7UVdv76MrgyHy04o7F+2U+r7+287nDJdo0So2cjPxVSgRJ1Vb5P0tfjsQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb1e3, "crc");
    
    is($msg->{'length'}, 245, "length");
    
    is($msg->{'msg_type'}, 0x5fb, "msg_type");
    
    is($msg->{'payload'}, "nuRydTKenCp3nJ1wLzyEKEZX61OxxgMOCEYMLDW1Wq73ljqs97N3sH0EseVxDk2ZuRc13ruS+lvU1w5r+l5rIVvqANWLX7MyFUquqT1WW44zbAkm4ZJlSYs4dVIl1WzNXRITwyHKV86yfbx3OEWWlkwDgxJJ0EjoCPrLsqqj/FYx97KmOB8Kd9Xx1KQBoioSfKl5nho4F459KHhDLX7rbhcM8VhF7/w5XSzJ2K3yshEF36nAA01rApDpDlgg0QERe5spt/SeUjVnDsq5I7UVdv76MrgyHy04o7F+2U+r7+287nDJdo0So2cjPxVSgRJ1Vb5P0tc=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x97cc, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"iod_atmo":60,"num_msgs":157,"seq_num":112,"tile_id":30066,"tile_set_id":58526,"time":{"tow":714907186,"wn":40055},"update_interval":47}})), "header");
    
    is($json->encode($msg->stec_sat_list()), $json->encode($json->decode(q{[{"stec_coeff":[-5289,-20141,966,2062],"stec_quality_indicator":70,"sv_id":{"constellation":40,"sat_id":132}},{"stec_coeff":[-19147,-20902,-26889,-21446],"stec_quality_indicator":44,"sv_id":{"constellation":12,"sat_id":70}},{"stec_coeff":[32176,-20220,29157,19726],"stec_quality_indicator":119,"sv_id":{"constellation":179,"sat_id":247}},{"stec_coeff":[-8651,-27973,23546,-10284],"stec_quality_indicator":23,"sv_id":{"constellation":185,"sat_id":153}},{"stec_coeff":[27486,23329,234,-29739],"stec_quality_indicator":250,"sv_id":{"constellation":107,"sat_id":14}},{"stec_coeff":[18965,-22098,22077,-29093],"stec_quality_indicator":50,"sv_id":{"constellation":179,"sat_id":95}},{"stec_coeff":[-7898,26002,-29879,30008],"stec_quality_indicator":9,"sv_id":{"constellation":108,"sat_id":51}},{"stec_coeff":[-12948,4701,-15597,-13791],"stec_quality_indicator":213,"sv_id":{"constellation":37,"sat_id":82}},{"stec_coeff":[-17283,14455,-27067,19606],"stec_quality_indicator":178,"sv_id":{"constellation":206,"sat_id":87}},{"stec_coeff":[-12215,-6072,-1528,-19765],"stec_quality_indicator":18,"sv_id":{"constellation":131,"sat_id":3}},{"stec_coeff":[12630,-19721,14502,2591],"stec_quality_indicator":252,"sv_id":{"constellation":163,"sat_id":170}},{"stec_coeff":[-23340,-24063,4650,-22148],"stec_quality_indicator":241,"sv_id":{"constellation":213,"sat_id":119}},{"stec_coeff":[5944,32142,30760,11587],"stec_quality_indicator":26,"sv_id":{"constellation":158,"sat_id":121}},{"stec_coeff":[3095,22769,-4283,14844],"stec_quality_indicator":110,"sv_id":{"constellation":235,"sat_id":126}},{"stec_coeff":[-21032,-19726,1297,-22049],"stec_quality_indicator":201,"sv_id":{"constellation":44,"sat_id":93}},{"stec_coeff":[619,-5744,22542,-12000],"stec_quality_indicator":77,"sv_id":{"constellation":3,"sat_id":192}},{"stec_coeff":[10651,-2889,21150,26421],"stec_quality_indicator":123,"sv_id":{"constellation":17,"sat_id":1}},{"stec_coeff":[-19165,30229,-1282,-18382],"stec_quality_indicator":185,"sv_id":{"constellation":202,"sat_id":14}},{"stec_coeff":[-23752,32433,20441,-4181],"stec_quality_indicator":45,"sv_id":{"constellation":31,"sat_id":50}},{"stec_coeff":[-13968,-29322,-23790,9063],"stec_quality_indicator":238,"sv_id":{"constellation":188,"sat_id":237}},{"stec_coeff":[4737,21877,20414,-10286],"stec_quality_indicator":82,"sv_id":{"constellation":21,"sat_id":63}}]})), "stec_sat_list");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":45539,"header":{"iod_atmo":60,"num_msgs":157,"seq_num":112,"tile_id":30066,"tile_set_id":58526,"time":{"tow":714907186,"wn":40055},"update_interval":47},"length":245,"msg_type":1531,"payload":"nuRydTKenCp3nJ1wLzyEKEZX61OxxgMOCEYMLDW1Wq73ljqs97N3sH0EseVxDk2ZuRc13ruS+lvU1w5r+l5rIVvqANWLX7MyFUquqT1WW44zbAkm4ZJlSYs4dVIl1WzNXRITwyHKV86yfbx3OEWWlkwDgxJJ0EjoCPrLsqqj/FYx97KmOB8Kd9Xx1KQBoioSfKl5nho4F459KHhDLX7rbhcM8VhF7/w5XSzJ2K3yshEF36nAA01rApDpDlgg0QERe5spt/SeUjVnDsq5I7UVdv76MrgyHy04o7F+2U+r7+287nDJdo0So2cjPxVSgRJ1Vb5P0tc=","preamble":85,"sender":38860,"stec_sat_list":[{"stec_coeff":[-5289,-20141,966,2062],"stec_quality_indicator":70,"sv_id":{"constellation":40,"sat_id":132}},{"stec_coeff":[-19147,-20902,-26889,-21446],"stec_quality_indicator":44,"sv_id":{"constellation":12,"sat_id":70}},{"stec_coeff":[32176,-20220,29157,19726],"stec_quality_indicator":119,"sv_id":{"constellation":179,"sat_id":247}},{"stec_coeff":[-8651,-27973,23546,-10284],"stec_quality_indicator":23,"sv_id":{"constellation":185,"sat_id":153}},{"stec_coeff":[27486,23329,234,-29739],"stec_quality_indicator":250,"sv_id":{"constellation":107,"sat_id":14}},{"stec_coeff":[18965,-22098,22077,-29093],"stec_quality_indicator":50,"sv_id":{"constellation":179,"sat_id":95}},{"stec_coeff":[-7898,26002,-29879,30008],"stec_quality_indicator":9,"sv_id":{"constellation":108,"sat_id":51}},{"stec_coeff":[-12948,4701,-15597,-13791],"stec_quality_indicator":213,"sv_id":{"constellation":37,"sat_id":82}},{"stec_coeff":[-17283,14455,-27067,19606],"stec_quality_indicator":178,"sv_id":{"constellation":206,"sat_id":87}},{"stec_coeff":[-12215,-6072,-1528,-19765],"stec_quality_indicator":18,"sv_id":{"constellation":131,"sat_id":3}},{"stec_coeff":[12630,-19721,14502,2591],"stec_quality_indicator":252,"sv_id":{"constellation":163,"sat_id":170}},{"stec_coeff":[-23340,-24063,4650,-22148],"stec_quality_indicator":241,"sv_id":{"constellation":213,"sat_id":119}},{"stec_coeff":[5944,32142,30760,11587],"stec_quality_indicator":26,"sv_id":{"constellation":158,"sat_id":121}},{"stec_coeff":[3095,22769,-4283,14844],"stec_quality_indicator":110,"sv_id":{"constellation":235,"sat_id":126}},{"stec_coeff":[-21032,-19726,1297,-22049],"stec_quality_indicator":201,"sv_id":{"constellation":44,"sat_id":93}},{"stec_coeff":[619,-5744,22542,-12000],"stec_quality_indicator":77,"sv_id":{"constellation":3,"sat_id":192}},{"stec_coeff":[10651,-2889,21150,26421],"stec_quality_indicator":123,"sv_id":{"constellation":17,"sat_id":1}},{"stec_coeff":[-19165,30229,-1282,-18382],"stec_quality_indicator":185,"sv_id":{"constellation":202,"sat_id":14}},{"stec_coeff":[-23752,32433,20441,-4181],"stec_quality_indicator":45,"sv_id":{"constellation":31,"sat_id":50}},{"stec_coeff":[-13968,-29322,-23790,9063],"stec_quality_indicator":238,"sv_id":{"constellation":188,"sat_id":237}},{"stec_coeff":[4737,21877,20414,-10286],"stec_quality_indicator":82,"sv_id":{"constellation":21,"sat_id":63}}]}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_stec_correction_dep_1();

done_testing();
