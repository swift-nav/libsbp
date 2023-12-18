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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMetaDepA.yaml
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
sub test_auto_check_sbp_solution_meta_msg_soln_meta_dep_a_1() {
    my $buf = decode_base64("VQ//VPH+t96deQWk7h++c107ZyRToZwu/UNXyCf69fLkSBLeC1jP2ucN4uAWxBXyDFlH27ZVkcySKMwzFZnjLA8c/yfN2PC+XdtnKim2TN4RF30fEuUcL9YZZFRqSDAK3ujrSW2jM5iF61dGAmxbZcg3GJzpSSdCYYz84+bth/H1zUYA27xriLI6AR0s1eGTvmDAbOQPyxID3rREZeXfy/OkXKXcn655cKfwKDsD5jSVlNqO1G2wR7OsTQHBRpOVF5CU78O6Vh4ij5zPPzd1/97e25Hgv9JtVpkVIOIKPD9q7F1gHqNq7pOFhGuY1t25yhX8M4I7psp/qjrB130WOocvWI5N0w==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd34d, "crc");
    
    is($msg->{'length'}, 254, "length");
    
    is($msg->{'msg_type'}, 0xff0f, "msg_type");
    
    is($msg->{'payload'}, "t96deQWk7h++c107ZyRToZwu/UNXyCf69fLkSBLeC1jP2ucN4uAWxBXyDFlH27ZVkcySKMwzFZnjLA8c/yfN2PC+XdtnKim2TN4RF30fEuUcL9YZZFRqSDAK3ujrSW2jM5iF61dGAmxbZcg3GJzpSSdCYYz84+bth/H1zUYA27xriLI6AR0s1eGTvmDAbOQPyxID3rREZeXfy/OkXKXcn655cKfwKDsD5jSVlNqO1G2wR7OsTQHBRpOVF5CU78O6Vh4ij5zPPzd1/97e25Hgv9JtVpkVIOIKPD9q7F1gHqNq7pOFhGuY1t25yhX8M4I7psp/qjrB130WOocvWI4=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf154, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->age_corrections(), 48671, "age_corrections");
    
    is($msg->alignment_status(), 115, "alignment_status");
    
    is($msg->hdop(), 31133, "hdop");
    
    is($msg->last_used_gnss_pos_tow(), 610745181, "last_used_gnss_pos_tow");
    
    is($msg->last_used_gnss_vel_tow(), 782016851, "last_used_gnss_vel_tow");
    
    is($msg->n_sats(), 238, "n_sats");
    
    is($msg->pdop(), 57015, "pdop");
    
    is($json->encode($msg->sol_in()), $json->encode($json->decode(q{[{"flags":67,"sensor_type":253},{"flags":200,"sensor_type":87},{"flags":250,"sensor_type":39},{"flags":242,"sensor_type":245},{"flags":72,"sensor_type":228},{"flags":222,"sensor_type":18},{"flags":88,"sensor_type":11},{"flags":218,"sensor_type":207},{"flags":13,"sensor_type":231},{"flags":224,"sensor_type":226},{"flags":196,"sensor_type":22},{"flags":242,"sensor_type":21},{"flags":89,"sensor_type":12},{"flags":219,"sensor_type":71},{"flags":85,"sensor_type":182},{"flags":204,"sensor_type":145},{"flags":40,"sensor_type":146},{"flags":51,"sensor_type":204},{"flags":153,"sensor_type":21},{"flags":44,"sensor_type":227},{"flags":28,"sensor_type":15},{"flags":39,"sensor_type":255},{"flags":216,"sensor_type":205},{"flags":190,"sensor_type":240},{"flags":219,"sensor_type":93},{"flags":42,"sensor_type":103},{"flags":182,"sensor_type":41},{"flags":222,"sensor_type":76},{"flags":23,"sensor_type":17},{"flags":31,"sensor_type":125},{"flags":229,"sensor_type":18},{"flags":47,"sensor_type":28},{"flags":25,"sensor_type":214},{"flags":84,"sensor_type":100},{"flags":72,"sensor_type":106},{"flags":10,"sensor_type":48},{"flags":232,"sensor_type":222},{"flags":73,"sensor_type":235},{"flags":163,"sensor_type":109},{"flags":152,"sensor_type":51},{"flags":235,"sensor_type":133},{"flags":70,"sensor_type":87},{"flags":108,"sensor_type":2},{"flags":101,"sensor_type":91},{"flags":55,"sensor_type":200},{"flags":156,"sensor_type":24},{"flags":73,"sensor_type":233},{"flags":66,"sensor_type":39},{"flags":140,"sensor_type":97},{"flags":227,"sensor_type":252},{"flags":237,"sensor_type":230},{"flags":241,"sensor_type":135},{"flags":205,"sensor_type":245},{"flags":0,"sensor_type":70},{"flags":188,"sensor_type":219},{"flags":136,"sensor_type":107},{"flags":58,"sensor_type":178},{"flags":29,"sensor_type":1},{"flags":213,"sensor_type":44},{"flags":147,"sensor_type":225},{"flags":96,"sensor_type":190},{"flags":108,"sensor_type":192},{"flags":15,"sensor_type":228},{"flags":18,"sensor_type":203},{"flags":222,"sensor_type":3},{"flags":68,"sensor_type":180},{"flags":229,"sensor_type":101},{"flags":203,"sensor_type":223},{"flags":164,"sensor_type":243},{"flags":165,"sensor_type":92},{"flags":159,"sensor_type":220},{"flags":121,"sensor_type":174},{"flags":167,"sensor_type":112},{"flags":40,"sensor_type":240},{"flags":3,"sensor_type":59},{"flags":52,"sensor_type":230},{"flags":148,"sensor_type":149},{"flags":142,"sensor_type":218},{"flags":109,"sensor_type":212},{"flags":71,"sensor_type":176},{"flags":172,"sensor_type":179},{"flags":1,"sensor_type":77},{"flags":70,"sensor_type":193},{"flags":149,"sensor_type":147},{"flags":144,"sensor_type":23},{"flags":239,"sensor_type":148},{"flags":186,"sensor_type":195},{"flags":30,"sensor_type":86},{"flags":143,"sensor_type":34},{"flags":207,"sensor_type":156},{"flags":55,"sensor_type":63},{"flags":255,"sensor_type":117},{"flags":222,"sensor_type":222},{"flags":145,"sensor_type":219},{"flags":191,"sensor_type":224},{"flags":109,"sensor_type":210},{"flags":153,"sensor_type":86},{"flags":32,"sensor_type":21},{"flags":10,"sensor_type":226},{"flags":63,"sensor_type":60},{"flags":236,"sensor_type":106},{"flags":96,"sensor_type":93},{"flags":163,"sensor_type":30},{"flags":238,"sensor_type":106},{"flags":133,"sensor_type":147},{"flags":107,"sensor_type":132},{"flags":214,"sensor_type":152},{"flags":185,"sensor_type":221},{"flags":21,"sensor_type":202},{"flags":51,"sensor_type":252},{"flags":59,"sensor_type":130},{"flags":202,"sensor_type":166},{"flags":170,"sensor_type":127},{"flags":193,"sensor_type":58},{"flags":125,"sensor_type":215},{"flags":58,"sensor_type":22},{"flags":47,"sensor_type":135},{"flags":142,"sensor_type":88}]})), "sol_in");
    
    is($msg->vdop(), 41989, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"age_corrections":48671,"alignment_status":115,"crc":54093,"hdop":31133,"last_used_gnss_pos_tow":610745181,"last_used_gnss_vel_tow":782016851,"length":254,"msg_type":65295,"n_sats":238,"payload":"t96deQWk7h++c107ZyRToZwu/UNXyCf69fLkSBLeC1jP2ucN4uAWxBXyDFlH27ZVkcySKMwzFZnjLA8c/yfN2PC+XdtnKim2TN4RF30fEuUcL9YZZFRqSDAK3ujrSW2jM5iF61dGAmxbZcg3GJzpSSdCYYz84+bth/H1zUYA27xriLI6AR0s1eGTvmDAbOQPyxID3rREZeXfy/OkXKXcn655cKfwKDsD5jSVlNqO1G2wR7OsTQHBRpOVF5CU78O6Vh4ij5zPPzd1/97e25Hgv9JtVpkVIOIKPD9q7F1gHqNq7pOFhGuY1t25yhX8M4I7psp/qjrB130WOocvWI4=","pdop":57015,"preamble":85,"sender":61780,"sol_in":[{"flags":67,"sensor_type":253},{"flags":200,"sensor_type":87},{"flags":250,"sensor_type":39},{"flags":242,"sensor_type":245},{"flags":72,"sensor_type":228},{"flags":222,"sensor_type":18},{"flags":88,"sensor_type":11},{"flags":218,"sensor_type":207},{"flags":13,"sensor_type":231},{"flags":224,"sensor_type":226},{"flags":196,"sensor_type":22},{"flags":242,"sensor_type":21},{"flags":89,"sensor_type":12},{"flags":219,"sensor_type":71},{"flags":85,"sensor_type":182},{"flags":204,"sensor_type":145},{"flags":40,"sensor_type":146},{"flags":51,"sensor_type":204},{"flags":153,"sensor_type":21},{"flags":44,"sensor_type":227},{"flags":28,"sensor_type":15},{"flags":39,"sensor_type":255},{"flags":216,"sensor_type":205},{"flags":190,"sensor_type":240},{"flags":219,"sensor_type":93},{"flags":42,"sensor_type":103},{"flags":182,"sensor_type":41},{"flags":222,"sensor_type":76},{"flags":23,"sensor_type":17},{"flags":31,"sensor_type":125},{"flags":229,"sensor_type":18},{"flags":47,"sensor_type":28},{"flags":25,"sensor_type":214},{"flags":84,"sensor_type":100},{"flags":72,"sensor_type":106},{"flags":10,"sensor_type":48},{"flags":232,"sensor_type":222},{"flags":73,"sensor_type":235},{"flags":163,"sensor_type":109},{"flags":152,"sensor_type":51},{"flags":235,"sensor_type":133},{"flags":70,"sensor_type":87},{"flags":108,"sensor_type":2},{"flags":101,"sensor_type":91},{"flags":55,"sensor_type":200},{"flags":156,"sensor_type":24},{"flags":73,"sensor_type":233},{"flags":66,"sensor_type":39},{"flags":140,"sensor_type":97},{"flags":227,"sensor_type":252},{"flags":237,"sensor_type":230},{"flags":241,"sensor_type":135},{"flags":205,"sensor_type":245},{"flags":0,"sensor_type":70},{"flags":188,"sensor_type":219},{"flags":136,"sensor_type":107},{"flags":58,"sensor_type":178},{"flags":29,"sensor_type":1},{"flags":213,"sensor_type":44},{"flags":147,"sensor_type":225},{"flags":96,"sensor_type":190},{"flags":108,"sensor_type":192},{"flags":15,"sensor_type":228},{"flags":18,"sensor_type":203},{"flags":222,"sensor_type":3},{"flags":68,"sensor_type":180},{"flags":229,"sensor_type":101},{"flags":203,"sensor_type":223},{"flags":164,"sensor_type":243},{"flags":165,"sensor_type":92},{"flags":159,"sensor_type":220},{"flags":121,"sensor_type":174},{"flags":167,"sensor_type":112},{"flags":40,"sensor_type":240},{"flags":3,"sensor_type":59},{"flags":52,"sensor_type":230},{"flags":148,"sensor_type":149},{"flags":142,"sensor_type":218},{"flags":109,"sensor_type":212},{"flags":71,"sensor_type":176},{"flags":172,"sensor_type":179},{"flags":1,"sensor_type":77},{"flags":70,"sensor_type":193},{"flags":149,"sensor_type":147},{"flags":144,"sensor_type":23},{"flags":239,"sensor_type":148},{"flags":186,"sensor_type":195},{"flags":30,"sensor_type":86},{"flags":143,"sensor_type":34},{"flags":207,"sensor_type":156},{"flags":55,"sensor_type":63},{"flags":255,"sensor_type":117},{"flags":222,"sensor_type":222},{"flags":145,"sensor_type":219},{"flags":191,"sensor_type":224},{"flags":109,"sensor_type":210},{"flags":153,"sensor_type":86},{"flags":32,"sensor_type":21},{"flags":10,"sensor_type":226},{"flags":63,"sensor_type":60},{"flags":236,"sensor_type":106},{"flags":96,"sensor_type":93},{"flags":163,"sensor_type":30},{"flags":238,"sensor_type":106},{"flags":133,"sensor_type":147},{"flags":107,"sensor_type":132},{"flags":214,"sensor_type":152},{"flags":185,"sensor_type":221},{"flags":21,"sensor_type":202},{"flags":51,"sensor_type":252},{"flags":59,"sensor_type":130},{"flags":202,"sensor_type":166},{"flags":170,"sensor_type":127},{"flags":193,"sensor_type":58},{"flags":125,"sensor_type":215},{"flags":58,"sensor_type":22},{"flags":47,"sensor_type":135},{"flags":142,"sensor_type":88}],"vdop":41989}})), "raw_json");
}
test_auto_check_sbp_solution_meta_msg_soln_meta_dep_a_1();

done_testing();