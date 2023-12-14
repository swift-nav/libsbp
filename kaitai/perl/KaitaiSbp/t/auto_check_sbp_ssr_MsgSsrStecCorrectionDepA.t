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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDepA.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_stec_correction_dep_a_1() {
    my $buf = decode_base64("VesFJwf8RlHE6Lkrk3snBH4Tb2H4gtnZajoMQearUV9WECdU5NDJUdtjyz22Qn3LA8EsZNx9PBVd2veez12Bhg7RMA7XmZSTSOG07M3JIQP2zBMDYgTCv/ZM2x+/cU+xD/shE2A2OpLSZPlIFaHTxhXub2sk4+HVA0fzP0HsXE0AqQ+2BfC0CXpW6AZnaP69UW4CMcpU2DcytQV7UDH04Lx9pOY4QnyoO4tqdjO72L+eTVw6/YSWpQmavdo90QFStcQXNbZwwM6nnfQjAb3ZPVhhyclK+9kOaLg2NEruCoEWsuJtWJ0exK8aTCJ03JroDLP0D5vEykhGcwrWcif1HO1EiJs=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9b88, "crc");
    
    is($msg->{'length'}, 252, "length");
    
    is($msg->{'msg_type'}, 0x5eb, "msg_type");
    
    is($msg->{'payload'}, "RlHE6Lkrk3snBH4Tb2H4gtnZajoMQearUV9WECdU5NDJUdtjyz22Qn3LA8EsZNx9PBVd2veez12Bhg7RMA7XmZSTSOG07M3JIQP2zBMDYgTCv/ZM2x+/cU+xD/shE2A2OpLSZPlIFaHTxhXub2sk4+HVA0fzP0HsXE0AqQ+2BfC0CXpW6AZnaP69UW4CMcpU2DcytQV7UDH04Lx9pOY4QnyoO4tqdjO72L+eTVw6/YSWpQmavdo90QFStcQXNbZwwM6nnfQjAb3ZPVhhyclK+9kOaLg2NEruCoEWsuJtWJ0exK8aTCJ03JroDLP0D5vEykhGcwrWcif1HO1E", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x0727, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"iod_atmo":4,"num_msgs":147,"seq_num":123,"time":{"tow":3905179974,"wn":11193},"update_interval":39}})), "header");
    
    is($json->encode($msg->stec_sat_list()), $json->encode($json->decode(q{[{"stec_coeff":[-1951,-9854,27353,3130],"stec_quality_indicator":111,"sv_id":{"constellation":19,"sat_id":126}},{"stec_coeff":[24401,4182,21543,-12060],"stec_quality_indicator":171,"sv_id":{"constellation":230,"sat_id":65}},{"stec_coeff":[-13469,-18883,32066,971],"stec_quality_indicator":219,"sv_id":{"constellation":81,"sat_id":201}},{"stec_coeff":[32220,5436,-9635,-24841],"stec_quality_indicator":100,"sv_id":{"constellation":44,"sat_id":193}},{"stec_coeff":[3718,12497,-10482,-27495],"stec_quality_indicator":129,"sv_id":{"constellation":93,"sat_id":207}},{"stec_coeff":[-4940,-13875,801,-13066],"stec_quality_indicator":225,"sv_id":{"constellation":72,"sat_id":147}},{"stec_coeff":[-15868,-2369,-9396,-16609],"stec_quality_indicator":98,"sv_id":{"constellation":3,"sat_id":19}},{"stec_coeff":[-1265,4897,13920,-28102],"stec_quality_indicator":177,"sv_id":{"constellation":79,"sat_id":113}},{"stec_coeff":[5448,-11359,5574,28654],"stec_quality_indicator":249,"sv_id":{"constellation":100,"sat_id":210}},{"stec_coeff":[-10783,18179,16371,-5055],"stec_quality_indicator":227,"sv_id":{"constellation":36,"sat_id":107}},{"stec_coeff":[4009,1462,-19216,31241],"stec_quality_indicator":0,"sv_id":{"constellation":77,"sat_id":92}},{"stec_coeff":[26727,-16898,28241,12546],"stec_quality_indicator":6,"sv_id":{"constellation":232,"sat_id":86}},{"stec_coeff":[12855,1461,20603,-3023],"stec_quality_indicator":216,"sv_id":{"constellation":84,"sat_id":202}},{"stec_coeff":[-6492,16952,-22404,-29893],"stec_quality_indicator":125,"sv_id":{"constellation":188,"sat_id":224}},{"stec_coeff":[-10053,-24897,23629,-710],"stec_quality_indicator":51,"sv_id":{"constellation":118,"sat_id":106}},{"stec_coeff":[-26103,-9539,-11971,20993],"stec_quality_indicator":165,"sv_id":{"constellation":150,"sat_id":132}},{"stec_coeff":[-18891,-16272,-22578,-2915],"stec_quality_indicator":23,"sv_id":{"constellation":196,"sat_id":181}},{"stec_coeff":[15833,24920,-13879,-1206],"stec_quality_indicator":189,"sv_id":{"constellation":1,"sat_id":35}},{"stec_coeff":[14008,18996,2798,5761],"stec_quality_indicator":104,"sv_id":{"constellation":14,"sat_id":217}},{"stec_coeff":[-25256,-15330,6831,8780],"stec_quality_indicator":109,"sv_id":{"constellation":226,"sat_id":178}},{"stec_coeff":[3304,-2893,-25841,-13628],"stec_quality_indicator":154,"sv_id":{"constellation":220,"sat_id":116}},{"stec_coeff":[-10742,10098,7413,17645],"stec_quality_indicator":115,"sv_id":{"constellation":70,"sat_id":72}}]})), "stec_sat_list");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":39816,"header":{"iod_atmo":4,"num_msgs":147,"seq_num":123,"time":{"tow":3905179974,"wn":11193},"update_interval":39},"length":252,"msg_type":1515,"payload":"RlHE6Lkrk3snBH4Tb2H4gtnZajoMQearUV9WECdU5NDJUdtjyz22Qn3LA8EsZNx9PBVd2veez12Bhg7RMA7XmZSTSOG07M3JIQP2zBMDYgTCv/ZM2x+/cU+xD/shE2A2OpLSZPlIFaHTxhXub2sk4+HVA0fzP0HsXE0AqQ+2BfC0CXpW6AZnaP69UW4CMcpU2DcytQV7UDH04Lx9pOY4QnyoO4tqdjO72L+eTVw6/YSWpQmavdo90QFStcQXNbZwwM6nnfQjAb3ZPVhhyclK+9kOaLg2NEruCoEWsuJtWJ0exK8aTCJ03JroDLP0D5vEykhGcwrWcif1HO1E","preamble":85,"sender":1831,"stec_sat_list":[{"stec_coeff":[-1951,-9854,27353,3130],"stec_quality_indicator":111,"sv_id":{"constellation":19,"sat_id":126}},{"stec_coeff":[24401,4182,21543,-12060],"stec_quality_indicator":171,"sv_id":{"constellation":230,"sat_id":65}},{"stec_coeff":[-13469,-18883,32066,971],"stec_quality_indicator":219,"sv_id":{"constellation":81,"sat_id":201}},{"stec_coeff":[32220,5436,-9635,-24841],"stec_quality_indicator":100,"sv_id":{"constellation":44,"sat_id":193}},{"stec_coeff":[3718,12497,-10482,-27495],"stec_quality_indicator":129,"sv_id":{"constellation":93,"sat_id":207}},{"stec_coeff":[-4940,-13875,801,-13066],"stec_quality_indicator":225,"sv_id":{"constellation":72,"sat_id":147}},{"stec_coeff":[-15868,-2369,-9396,-16609],"stec_quality_indicator":98,"sv_id":{"constellation":3,"sat_id":19}},{"stec_coeff":[-1265,4897,13920,-28102],"stec_quality_indicator":177,"sv_id":{"constellation":79,"sat_id":113}},{"stec_coeff":[5448,-11359,5574,28654],"stec_quality_indicator":249,"sv_id":{"constellation":100,"sat_id":210}},{"stec_coeff":[-10783,18179,16371,-5055],"stec_quality_indicator":227,"sv_id":{"constellation":36,"sat_id":107}},{"stec_coeff":[4009,1462,-19216,31241],"stec_quality_indicator":0,"sv_id":{"constellation":77,"sat_id":92}},{"stec_coeff":[26727,-16898,28241,12546],"stec_quality_indicator":6,"sv_id":{"constellation":232,"sat_id":86}},{"stec_coeff":[12855,1461,20603,-3023],"stec_quality_indicator":216,"sv_id":{"constellation":84,"sat_id":202}},{"stec_coeff":[-6492,16952,-22404,-29893],"stec_quality_indicator":125,"sv_id":{"constellation":188,"sat_id":224}},{"stec_coeff":[-10053,-24897,23629,-710],"stec_quality_indicator":51,"sv_id":{"constellation":118,"sat_id":106}},{"stec_coeff":[-26103,-9539,-11971,20993],"stec_quality_indicator":165,"sv_id":{"constellation":150,"sat_id":132}},{"stec_coeff":[-18891,-16272,-22578,-2915],"stec_quality_indicator":23,"sv_id":{"constellation":196,"sat_id":181}},{"stec_coeff":[15833,24920,-13879,-1206],"stec_quality_indicator":189,"sv_id":{"constellation":1,"sat_id":35}},{"stec_coeff":[14008,18996,2798,5761],"stec_quality_indicator":104,"sv_id":{"constellation":14,"sat_id":217}},{"stec_coeff":[-25256,-15330,6831,8780],"stec_quality_indicator":109,"sv_id":{"constellation":226,"sat_id":178}},{"stec_coeff":[3304,-2893,-25841,-13628],"stec_quality_indicator":154,"sv_id":{"constellation":220,"sat_id":116}},{"stec_coeff":[-10742,10098,7413,17645],"stec_quality_indicator":115,"sv_id":{"constellation":70,"sat_id":72}}]}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_stec_correction_dep_a_1();

done_testing();