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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrPhaseBiases.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_phase_biases_1() {
    my $buf = decode_base64("VeYF287/0ZqQDNWkqVKx5mLR+RYRHfr1wdse1LHPuyGSOsykQXIx+DQIoSz8pqjofIZWrfGuLI6bgY+4odMPJL3Qwt2YEMtXIryNaL1mnPwW+4gxvJ3e9TGEECKO5FWL3cXrYkprRiQm7/twvHz2jaSWaAfVLBX0wASPGCoVVIgHKnYtF66vgTapDtUCxWI8Dc9pZIFIiPCMgQlyrJeWEdJ/c5cD8v7XDgUifgLXQSawF9LJYSTPXOAadJvTpS9mJkPHN3UkqSEB5sm3FSo+k62tm2KS56eKUqd/5QECf+3PdFpznwMqQpH6yQf7AkvmGtW1OEBhWP8GkxBZyxtE8+Y38qep2/A=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf0db, "crc");
    
    is($msg->{'length'}, 255, "length");
    
    is($msg->{'msg_type'}, 0x5e6, "msg_type");
    
    is($msg->{'payload'}, "0ZqQDNWkqVKx5mLR+RYRHfr1wdse1LHPuyGSOsykQXIx+DQIoSz8pqjofIZWrfGuLI6bgY+4odMPJL3Qwt2YEMtXIryNaL1mnPwW+4gxvJ3e9TGEECKO5FWL3cXrYkprRiQm7/twvHz2jaSWaAfVLBX0wASPGCoVVIgHKnYtF66vgTapDtUCxWI8Dc9pZIFIiPCMgQlyrJeWEdJ/c5cD8v7XDgUifgLXQSawF9LJYSTPXOAadJvTpS9mJkPHN3UkqSEB5sm3FSo+k62tm2KS56eKUqd/5QECf+3PdFpznwMqQpH6yQf7AkvmGtW1OEBhWP8GkxBZyxtE8+Y38qep", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xcedb, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->biases()), $json->encode($json->decode(q{[{"bias":-1311498533,"code":29,"discontinuity_counter":193,"integer_indicator":250,"widelane_integer_indicator":245},{"bias":1101319226,"code":207,"discontinuity_counter":146,"integer_indicator":187,"widelane_integer_indicator":33},{"bias":-64184056,"code":114,"discontinuity_counter":52,"integer_indicator":49,"widelane_integer_indicator":248},{"bias":-240298362,"code":166,"discontinuity_counter":124,"integer_indicator":168,"widelane_integer_indicator":232},{"bias":-1581740159,"code":174,"discontinuity_counter":155,"integer_indicator":44,"widelane_integer_indicator":142},{"bias":-1730297136,"code":211,"discontinuity_counter":189,"integer_indicator":15,"widelane_integer_indicator":36},{"bias":-1117221444,"code":16,"discontinuity_counter":34,"integer_indicator":203,"widelane_integer_indicator":87},{"bias":-1137604357,"code":102,"discontinuity_counter":22,"integer_indicator":156,"widelane_integer_indicator":252},{"bias":-1910370172,"code":157,"discontinuity_counter":49,"integer_indicator":222,"widelane_integer_indicator":245},{"bias":1247996869,"code":228,"discontinuity_counter":221,"integer_indicator":85,"widelane_integer_indicator":139},{"bias":-1133446161,"code":107,"discontinuity_counter":38,"integer_indicator":70,"widelane_integer_indicator":36},{"bias":-720934762,"code":124,"discontinuity_counter":164,"integer_indicator":246,"widelane_integer_indicator":141},{"bias":706252548,"code":44,"discontinuity_counter":192,"integer_indicator":21,"widelane_integer_indicator":244},{"bias":388855338,"code":21,"discontinuity_counter":7,"integer_indicator":84,"widelane_integer_indicator":136},{"bias":47517353,"code":174,"discontinuity_counter":54,"integer_indicator":175,"widelane_integer_indicator":129},{"bias":-2124125745,"code":197,"discontinuity_counter":13,"integer_indicator":98,"widelane_integer_indicator":60},{"bias":-1401812607,"code":72,"discontinuity_counter":140,"integer_indicator":136,"widelane_integer_indicator":240},{"bias":60257151,"code":151,"discontinuity_counter":210,"integer_indicator":150,"widelane_integer_indicator":17},{"bias":41820677,"code":242,"discontinuity_counter":14,"integer_indicator":254,"widelane_integer_indicator":215},{"bias":1640616471,"code":215,"discontinuity_counter":176,"integer_indicator":65,"widelane_integer_indicator":38},{"bias":-744786918,"code":36,"discontinuity_counter":224,"integer_indicator":207,"widelane_integer_indicator":92},{"bias":1966589763,"code":165,"discontinuity_counter":38,"integer_indicator":47,"widelane_integer_indicator":102},{"bias":364366310,"code":36,"discontinuity_counter":1,"integer_indicator":169,"widelane_integer_indicator":33},{"bias":-1839031379,"code":42,"discontinuity_counter":173,"integer_indicator":62,"widelane_integer_indicator":147},{"bias":31817639,"code":231,"discontinuity_counter":82,"integer_indicator":167,"widelane_integer_indicator":138},{"bias":-1619830156,"code":2,"discontinuity_counter":207,"integer_indicator":127,"widelane_integer_indicator":237},{"bias":-83375622,"code":3,"discontinuity_counter":145,"integer_indicator":42,"widelane_integer_indicator":66},{"bias":1077458389,"code":2,"discontinuity_counter":26,"integer_indicator":75,"widelane_integer_indicator":230},{"bias":-883355501,"code":97,"discontinuity_counter":6,"integer_indicator":88,"widelane_integer_indicator":255},{"bias":-1448611273,"code":27,"discontinuity_counter":230,"integer_indicator":68,"widelane_integer_indicator":243}]})), "biases");
    
    is($msg->dispersive_bias(), 98, "dispersive_bias");
    
    is($msg->iod_ssr(), 230, "iod_ssr");
    
    is($msg->mw_consistency(), 209, "mw_consistency");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":82,"sat":169}})), "sid");
    
    is($json->encode($msg->time()), $json->encode($json->decode(q{{"tow":210803409,"wn":42197}})), "time");
    
    is($msg->update_interval(), 177, "update_interval");
    
    is($msg->yaw(), 5881, "yaw");
    
    is($msg->yaw_rate(), 17, "yaw_rate");

    is($json->encode($msg), $json->encode($json->decode(q{{"biases":[{"bias":-1311498533,"code":29,"discontinuity_counter":193,"integer_indicator":250,"widelane_integer_indicator":245},{"bias":1101319226,"code":207,"discontinuity_counter":146,"integer_indicator":187,"widelane_integer_indicator":33},{"bias":-64184056,"code":114,"discontinuity_counter":52,"integer_indicator":49,"widelane_integer_indicator":248},{"bias":-240298362,"code":166,"discontinuity_counter":124,"integer_indicator":168,"widelane_integer_indicator":232},{"bias":-1581740159,"code":174,"discontinuity_counter":155,"integer_indicator":44,"widelane_integer_indicator":142},{"bias":-1730297136,"code":211,"discontinuity_counter":189,"integer_indicator":15,"widelane_integer_indicator":36},{"bias":-1117221444,"code":16,"discontinuity_counter":34,"integer_indicator":203,"widelane_integer_indicator":87},{"bias":-1137604357,"code":102,"discontinuity_counter":22,"integer_indicator":156,"widelane_integer_indicator":252},{"bias":-1910370172,"code":157,"discontinuity_counter":49,"integer_indicator":222,"widelane_integer_indicator":245},{"bias":1247996869,"code":228,"discontinuity_counter":221,"integer_indicator":85,"widelane_integer_indicator":139},{"bias":-1133446161,"code":107,"discontinuity_counter":38,"integer_indicator":70,"widelane_integer_indicator":36},{"bias":-720934762,"code":124,"discontinuity_counter":164,"integer_indicator":246,"widelane_integer_indicator":141},{"bias":706252548,"code":44,"discontinuity_counter":192,"integer_indicator":21,"widelane_integer_indicator":244},{"bias":388855338,"code":21,"discontinuity_counter":7,"integer_indicator":84,"widelane_integer_indicator":136},{"bias":47517353,"code":174,"discontinuity_counter":54,"integer_indicator":175,"widelane_integer_indicator":129},{"bias":-2124125745,"code":197,"discontinuity_counter":13,"integer_indicator":98,"widelane_integer_indicator":60},{"bias":-1401812607,"code":72,"discontinuity_counter":140,"integer_indicator":136,"widelane_integer_indicator":240},{"bias":60257151,"code":151,"discontinuity_counter":210,"integer_indicator":150,"widelane_integer_indicator":17},{"bias":41820677,"code":242,"discontinuity_counter":14,"integer_indicator":254,"widelane_integer_indicator":215},{"bias":1640616471,"code":215,"discontinuity_counter":176,"integer_indicator":65,"widelane_integer_indicator":38},{"bias":-744786918,"code":36,"discontinuity_counter":224,"integer_indicator":207,"widelane_integer_indicator":92},{"bias":1966589763,"code":165,"discontinuity_counter":38,"integer_indicator":47,"widelane_integer_indicator":102},{"bias":364366310,"code":36,"discontinuity_counter":1,"integer_indicator":169,"widelane_integer_indicator":33},{"bias":-1839031379,"code":42,"discontinuity_counter":173,"integer_indicator":62,"widelane_integer_indicator":147},{"bias":31817639,"code":231,"discontinuity_counter":82,"integer_indicator":167,"widelane_integer_indicator":138},{"bias":-1619830156,"code":2,"discontinuity_counter":207,"integer_indicator":127,"widelane_integer_indicator":237},{"bias":-83375622,"code":3,"discontinuity_counter":145,"integer_indicator":42,"widelane_integer_indicator":66},{"bias":1077458389,"code":2,"discontinuity_counter":26,"integer_indicator":75,"widelane_integer_indicator":230},{"bias":-883355501,"code":97,"discontinuity_counter":6,"integer_indicator":88,"widelane_integer_indicator":255},{"bias":-1448611273,"code":27,"discontinuity_counter":230,"integer_indicator":68,"widelane_integer_indicator":243}],"crc":61659,"dispersive_bias":98,"iod_ssr":230,"length":255,"msg_type":1510,"mw_consistency":209,"payload":"0ZqQDNWkqVKx5mLR+RYRHfr1wdse1LHPuyGSOsykQXIx+DQIoSz8pqjofIZWrfGuLI6bgY+4odMPJL3Qwt2YEMtXIryNaL1mnPwW+4gxvJ3e9TGEECKO5FWL3cXrYkprRiQm7/twvHz2jaSWaAfVLBX0wASPGCoVVIgHKnYtF66vgTapDtUCxWI8Dc9pZIFIiPCMgQlyrJeWEdJ/c5cD8v7XDgUifgLXQSawF9LJYSTPXOAadJvTpS9mJkPHN3UkqSEB5sm3FSo+k62tm2KS56eKUqd/5QECf+3PdFpznwMqQpH6yQf7AkvmGtW1OEBhWP8GkxBZyxtE8+Y38qep","preamble":85,"sender":52955,"sid":{"code":82,"sat":169},"time":{"tow":210803409,"wn":42197},"update_interval":177,"yaw":5881,"yaw_rate":17}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_phase_biases_1();

done_testing();
