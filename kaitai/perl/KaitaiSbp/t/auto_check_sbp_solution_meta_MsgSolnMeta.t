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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMeta.yaml
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
sub test_auto_check_sbp_solution_meta_msg_soln_meta_1() {
    my $buf = decode_base64("VQ7/ADz+MNBB2HotxKCQ5AhTWVcD1V9tVoNHRlRJgxpS94xhc252/QJ6upR6lLTnRC6+ZvMwwA/QWTgK9QL+yXggfgJToe57ZuZMvuG2z+QH2nVZHb84+Ln/LhJIjlJxGgSs/rKIcXM6wVnjtvZMTWz1KR9GfPmRD07kJvGBCLD7SPhQc/Tnkb++sqhZ6UWwroy2jVFSXE9l32RAuNd8JRXjh2ZIJNs4klrbaONmUwwpeq1eAa6GgmjtdPlr5oJ7GaI538GuksHvLPbF1lBTZEJIhYmMUgICYAlgnoZhK4GNGbfI1jn4Z95Bww/0FbQujIIkEcLRQf5zZ5iB6uvC6qrJ0pqW9w==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf796, "crc");
    
    is($msg->{'length'}, 254, "length");
    
    is($msg->{'msg_type'}, 0xff0e, "msg_type");
    
    is($msg->{'payload'}, "MNBB2HotxKCQ5AhTWVcD1V9tVoNHRlRJgxpS94xhc252/QJ6upR6lLTnRC6+ZvMwwA/QWTgK9QL+yXggfgJToe57ZuZMvuG2z+QH2nVZHb84+Ln/LhJIjlJxGgSs/rKIcXM6wVnjtvZMTWz1KR9GfPmRD07kJvGBCLD7SPhQc/Tnkb++sqhZ6UWwroy2jVFSXE9l32RAuNd8JRXjh2ZIJNs4klrbaONmUwwpeq1eAa6GgmjtdPlr5oJ7GaI538GuksHvLPbF1lBTZEJIhYmMUgICYAlgnoZhK4GNGbfI1jn4Z95Bww/0FbQujIIkEcLRQf5zZ5iB6uvC6qrJ0po=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x3c00, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->age_corrections(), 21256, "age_corrections");
    
    is($msg->age_gnss(), 3573765977, "age_gnss");
    
    is($msg->hdop(), 41156, "hdop");
    
    is($msg->pdop(), 11642, "pdop");
    
    is($json->encode($msg->sol_in()), $json->encode($json->decode(q{[{"flags":109,"sensor_type":95},{"flags":131,"sensor_type":86},{"flags":70,"sensor_type":71},{"flags":73,"sensor_type":84},{"flags":26,"sensor_type":131},{"flags":247,"sensor_type":82},{"flags":97,"sensor_type":140},{"flags":110,"sensor_type":115},{"flags":253,"sensor_type":118},{"flags":122,"sensor_type":2},{"flags":148,"sensor_type":186},{"flags":148,"sensor_type":122},{"flags":231,"sensor_type":180},{"flags":46,"sensor_type":68},{"flags":102,"sensor_type":190},{"flags":48,"sensor_type":243},{"flags":15,"sensor_type":192},{"flags":89,"sensor_type":208},{"flags":10,"sensor_type":56},{"flags":2,"sensor_type":245},{"flags":201,"sensor_type":254},{"flags":32,"sensor_type":120},{"flags":2,"sensor_type":126},{"flags":161,"sensor_type":83},{"flags":123,"sensor_type":238},{"flags":230,"sensor_type":102},{"flags":190,"sensor_type":76},{"flags":182,"sensor_type":225},{"flags":228,"sensor_type":207},{"flags":218,"sensor_type":7},{"flags":89,"sensor_type":117},{"flags":191,"sensor_type":29},{"flags":248,"sensor_type":56},{"flags":255,"sensor_type":185},{"flags":18,"sensor_type":46},{"flags":142,"sensor_type":72},{"flags":113,"sensor_type":82},{"flags":4,"sensor_type":26},{"flags":254,"sensor_type":172},{"flags":136,"sensor_type":178},{"flags":115,"sensor_type":113},{"flags":193,"sensor_type":58},{"flags":227,"sensor_type":89},{"flags":246,"sensor_type":182},{"flags":77,"sensor_type":76},{"flags":245,"sensor_type":108},{"flags":31,"sensor_type":41},{"flags":124,"sensor_type":70},{"flags":145,"sensor_type":249},{"flags":78,"sensor_type":15},{"flags":38,"sensor_type":228},{"flags":129,"sensor_type":241},{"flags":176,"sensor_type":8},{"flags":72,"sensor_type":251},{"flags":80,"sensor_type":248},{"flags":244,"sensor_type":115},{"flags":145,"sensor_type":231},{"flags":190,"sensor_type":191},{"flags":168,"sensor_type":178},{"flags":233,"sensor_type":89},{"flags":176,"sensor_type":69},{"flags":140,"sensor_type":174},{"flags":141,"sensor_type":182},{"flags":82,"sensor_type":81},{"flags":79,"sensor_type":92},{"flags":223,"sensor_type":101},{"flags":64,"sensor_type":100},{"flags":215,"sensor_type":184},{"flags":37,"sensor_type":124},{"flags":227,"sensor_type":21},{"flags":102,"sensor_type":135},{"flags":36,"sensor_type":72},{"flags":56,"sensor_type":219},{"flags":90,"sensor_type":146},{"flags":104,"sensor_type":219},{"flags":102,"sensor_type":227},{"flags":12,"sensor_type":83},{"flags":122,"sensor_type":41},{"flags":94,"sensor_type":173},{"flags":174,"sensor_type":1},{"flags":130,"sensor_type":134},{"flags":237,"sensor_type":104},{"flags":249,"sensor_type":116},{"flags":230,"sensor_type":107},{"flags":123,"sensor_type":130},{"flags":162,"sensor_type":25},{"flags":223,"sensor_type":57},{"flags":174,"sensor_type":193},{"flags":193,"sensor_type":146},{"flags":44,"sensor_type":239},{"flags":197,"sensor_type":246},{"flags":80,"sensor_type":214},{"flags":100,"sensor_type":83},{"flags":72,"sensor_type":66},{"flags":137,"sensor_type":133},{"flags":82,"sensor_type":140},{"flags":2,"sensor_type":2},{"flags":9,"sensor_type":96},{"flags":158,"sensor_type":96},{"flags":97,"sensor_type":134},{"flags":129,"sensor_type":43},{"flags":25,"sensor_type":141},{"flags":200,"sensor_type":183},{"flags":57,"sensor_type":214},{"flags":103,"sensor_type":248},{"flags":65,"sensor_type":222},{"flags":15,"sensor_type":195},{"flags":21,"sensor_type":244},{"flags":46,"sensor_type":180},{"flags":130,"sensor_type":140},{"flags":17,"sensor_type":36},{"flags":209,"sensor_type":194},{"flags":254,"sensor_type":65},{"flags":103,"sensor_type":115},{"flags":129,"sensor_type":152},{"flags":235,"sensor_type":234},{"flags":234,"sensor_type":194},{"flags":201,"sensor_type":170},{"flags":154,"sensor_type":210}]})), "sol_in");
    
    is($msg->tow(), 3628191792, "tow");
    
    is($msg->vdop(), 58512, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"age_corrections":21256,"age_gnss":3573765977,"crc":63382,"hdop":41156,"length":254,"msg_type":65294,"payload":"MNBB2HotxKCQ5AhTWVcD1V9tVoNHRlRJgxpS94xhc252/QJ6upR6lLTnRC6+ZvMwwA/QWTgK9QL+yXggfgJToe57ZuZMvuG2z+QH2nVZHb84+Ln/LhJIjlJxGgSs/rKIcXM6wVnjtvZMTWz1KR9GfPmRD07kJvGBCLD7SPhQc/Tnkb++sqhZ6UWwroy2jVFSXE9l32RAuNd8JRXjh2ZIJNs4klrbaONmUwwpeq1eAa6GgmjtdPlr5oJ7GaI538GuksHvLPbF1lBTZEJIhYmMUgICYAlgnoZhK4GNGbfI1jn4Z95Bww/0FbQujIIkEcLRQf5zZ5iB6uvC6qrJ0po=","pdop":11642,"preamble":85,"sender":15360,"sol_in":[{"flags":109,"sensor_type":95},{"flags":131,"sensor_type":86},{"flags":70,"sensor_type":71},{"flags":73,"sensor_type":84},{"flags":26,"sensor_type":131},{"flags":247,"sensor_type":82},{"flags":97,"sensor_type":140},{"flags":110,"sensor_type":115},{"flags":253,"sensor_type":118},{"flags":122,"sensor_type":2},{"flags":148,"sensor_type":186},{"flags":148,"sensor_type":122},{"flags":231,"sensor_type":180},{"flags":46,"sensor_type":68},{"flags":102,"sensor_type":190},{"flags":48,"sensor_type":243},{"flags":15,"sensor_type":192},{"flags":89,"sensor_type":208},{"flags":10,"sensor_type":56},{"flags":2,"sensor_type":245},{"flags":201,"sensor_type":254},{"flags":32,"sensor_type":120},{"flags":2,"sensor_type":126},{"flags":161,"sensor_type":83},{"flags":123,"sensor_type":238},{"flags":230,"sensor_type":102},{"flags":190,"sensor_type":76},{"flags":182,"sensor_type":225},{"flags":228,"sensor_type":207},{"flags":218,"sensor_type":7},{"flags":89,"sensor_type":117},{"flags":191,"sensor_type":29},{"flags":248,"sensor_type":56},{"flags":255,"sensor_type":185},{"flags":18,"sensor_type":46},{"flags":142,"sensor_type":72},{"flags":113,"sensor_type":82},{"flags":4,"sensor_type":26},{"flags":254,"sensor_type":172},{"flags":136,"sensor_type":178},{"flags":115,"sensor_type":113},{"flags":193,"sensor_type":58},{"flags":227,"sensor_type":89},{"flags":246,"sensor_type":182},{"flags":77,"sensor_type":76},{"flags":245,"sensor_type":108},{"flags":31,"sensor_type":41},{"flags":124,"sensor_type":70},{"flags":145,"sensor_type":249},{"flags":78,"sensor_type":15},{"flags":38,"sensor_type":228},{"flags":129,"sensor_type":241},{"flags":176,"sensor_type":8},{"flags":72,"sensor_type":251},{"flags":80,"sensor_type":248},{"flags":244,"sensor_type":115},{"flags":145,"sensor_type":231},{"flags":190,"sensor_type":191},{"flags":168,"sensor_type":178},{"flags":233,"sensor_type":89},{"flags":176,"sensor_type":69},{"flags":140,"sensor_type":174},{"flags":141,"sensor_type":182},{"flags":82,"sensor_type":81},{"flags":79,"sensor_type":92},{"flags":223,"sensor_type":101},{"flags":64,"sensor_type":100},{"flags":215,"sensor_type":184},{"flags":37,"sensor_type":124},{"flags":227,"sensor_type":21},{"flags":102,"sensor_type":135},{"flags":36,"sensor_type":72},{"flags":56,"sensor_type":219},{"flags":90,"sensor_type":146},{"flags":104,"sensor_type":219},{"flags":102,"sensor_type":227},{"flags":12,"sensor_type":83},{"flags":122,"sensor_type":41},{"flags":94,"sensor_type":173},{"flags":174,"sensor_type":1},{"flags":130,"sensor_type":134},{"flags":237,"sensor_type":104},{"flags":249,"sensor_type":116},{"flags":230,"sensor_type":107},{"flags":123,"sensor_type":130},{"flags":162,"sensor_type":25},{"flags":223,"sensor_type":57},{"flags":174,"sensor_type":193},{"flags":193,"sensor_type":146},{"flags":44,"sensor_type":239},{"flags":197,"sensor_type":246},{"flags":80,"sensor_type":214},{"flags":100,"sensor_type":83},{"flags":72,"sensor_type":66},{"flags":137,"sensor_type":133},{"flags":82,"sensor_type":140},{"flags":2,"sensor_type":2},{"flags":9,"sensor_type":96},{"flags":158,"sensor_type":96},{"flags":97,"sensor_type":134},{"flags":129,"sensor_type":43},{"flags":25,"sensor_type":141},{"flags":200,"sensor_type":183},{"flags":57,"sensor_type":214},{"flags":103,"sensor_type":248},{"flags":65,"sensor_type":222},{"flags":15,"sensor_type":195},{"flags":21,"sensor_type":244},{"flags":46,"sensor_type":180},{"flags":130,"sensor_type":140},{"flags":17,"sensor_type":36},{"flags":209,"sensor_type":194},{"flags":254,"sensor_type":65},{"flags":103,"sensor_type":115},{"flags":129,"sensor_type":152},{"flags":235,"sensor_type":234},{"flags":234,"sensor_type":194},{"flags":201,"sensor_type":170},{"flags":154,"sensor_type":210}],"tow":3628191792,"vdop":58512}})), "raw_json");
}
test_auto_check_sbp_solution_meta_msg_soln_meta_1();

done_testing();