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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodeBiases.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_code_biases_1() {
    my $buf = decode_base64("VeEFJ1f90FoTFwlChfH+hDMEg/B4U5TR1T7k6EdCvNKANoOYgW+L8rGRLAn1z/HKlo0yn9yLJbtivxeAiKfIBtNaF/SK19GLDWUgBxIdRvptScpPkAmSRfE0FmNizAOr5rRLPpFWgh8emyUSN9Inf/JCDe2YqtQP9jtetMOdRWR3EESzr5BxUVIelxVtKeEITaSdAEkeBk5Rj3Twlze5qf4zJ0qv9yJhSmGwMOytDK5lgh6pwb7MxHtrGeFKCQo3A4P2Y4Ui48tEEmHfWcD2MkVbCpdKdm4kqPegTbONsmO/eE3AW+AB4jJXkpTuZLN949douB85Wk8VnPVRPF2qPMinDX2E");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x847d, "crc");
    
    is($msg->{'length'}, 253, "length");
    
    is($msg->{'msg_type'}, 0x5e1, "msg_type");
    
    is($msg->{'payload'}, "0FoTFwlChfH+hDMEg/B4U5TR1T7k6EdCvNKANoOYgW+L8rGRLAn1z/HKlo0yn9yLJbtivxeAiKfIBtNaF/SK19GLDWUgBxIdRvptScpPkAmSRfE0FmNizAOr5rRLPpFWgh8emyUSN9Inf/JCDe2YqtQP9jtetMOdRWR3EESzr5BxUVIelxVtKeEITaSdAEkeBk5Rj3Twlze5qf4zJ0qv9yJhSmGwMOytDK5lgh6pwb7MxHtrGeFKCQo3A4P2Y4Ui48tEEmHfWcD2MkVbCpdKdm4kqPegTbONsmO/eE3AW+AB4jJXkpTuZLN949douB85Wk8VnPVRPF2qPMinDQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x5727, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->biases()), $json->encode($json->decode(q{[{"code":51,"value":-31996},{"code":240,"value":21368},{"code":148,"value":-10799},{"code":62,"value":-5916},{"code":71,"value":-17342},{"code":210,"value":13952},{"code":131,"value":-32360},{"code":111,"value":-3445},{"code":177,"value":11409},{"code":9,"value":-12299},{"code":241,"value":-26934},{"code":141,"value":-24782},{"code":220,"value":9611},{"code":187,"value":-16542},{"code":23,"value":-30592},{"code":167,"value":1736},{"code":211,"value":5978},{"code":244,"value":-10358},{"code":209,"value":3467},{"code":101,"value":1824},{"code":18,"value":17949},{"code":250,"value":18797},{"code":202,"value":-28593},{"code":9,"value":17810},{"code":241,"value":5684},{"code":99,"value":-13214},{"code":3,"value":-6485},{"code":180,"value":15947},{"code":145,"value":-32170},{"code":31,"value":-25826},{"code":37,"value":14098},{"code":210,"value":32551},{"code":242,"value":3394},{"code":237,"value":-21864},{"code":212,"value":-2545},{"code":59,"value":-19362},{"code":195,"value":17821},{"code":100,"value":4215},{"code":68,"value":-20557},{"code":144,"value":20849},{"code":82,"value":-26850},{"code":21,"value":10605},{"code":225,"value":19720},{"code":164,"value":157},{"code":73,"value":1566},{"code":78,"value":-28847},{"code":116,"value":-26640},{"code":55,"value":-22087},{"code":254,"value":10035},{"code":74,"value":-2129},{"code":34,"value":19041},{"code":97,"value":12464},{"code":236,"value":3245},{"code":174,"value":-32155},{"code":30,"value":-15959},{"code":190,"value":-15156},{"code":123,"value":6507},{"code":225,"value":2378},{"code":10,"value":823},{"code":131,"value":25590},{"code":133,"value":-7390},{"code":203,"value":4676},{"code":97,"value":23007},{"code":192,"value":13046},{"code":69,"value":2651},{"code":151,"value":30282},{"code":110,"value":-22492},{"code":247,"value":19872},{"code":179,"value":-19827},{"code":99,"value":30911},{"code":77,"value":23488},{"code":224,"value":-7679},{"code":50,"value":-28073},{"code":148,"value":25838},{"code":179,"value":-7299},{"code":215,"value":-18328},{"code":31,"value":23097},{"code":79,"value":-25579},{"code":245,"value":15441},{"code":93,"value":15530},{"code":200,"value":3495}]})), "biases");
    
    is($msg->iod_ssr(), 132, "iod_ssr");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":241,"sat":133}})), "sid");
    
    is($json->encode($msg->time()), $json->encode($json->decode(q{{"tow":387144400,"wn":16905}})), "time");
    
    is($msg->update_interval(), 254, "update_interval");

    is($json->encode($msg), $json->encode($json->decode(q{{"biases":[{"code":51,"value":-31996},{"code":240,"value":21368},{"code":148,"value":-10799},{"code":62,"value":-5916},{"code":71,"value":-17342},{"code":210,"value":13952},{"code":131,"value":-32360},{"code":111,"value":-3445},{"code":177,"value":11409},{"code":9,"value":-12299},{"code":241,"value":-26934},{"code":141,"value":-24782},{"code":220,"value":9611},{"code":187,"value":-16542},{"code":23,"value":-30592},{"code":167,"value":1736},{"code":211,"value":5978},{"code":244,"value":-10358},{"code":209,"value":3467},{"code":101,"value":1824},{"code":18,"value":17949},{"code":250,"value":18797},{"code":202,"value":-28593},{"code":9,"value":17810},{"code":241,"value":5684},{"code":99,"value":-13214},{"code":3,"value":-6485},{"code":180,"value":15947},{"code":145,"value":-32170},{"code":31,"value":-25826},{"code":37,"value":14098},{"code":210,"value":32551},{"code":242,"value":3394},{"code":237,"value":-21864},{"code":212,"value":-2545},{"code":59,"value":-19362},{"code":195,"value":17821},{"code":100,"value":4215},{"code":68,"value":-20557},{"code":144,"value":20849},{"code":82,"value":-26850},{"code":21,"value":10605},{"code":225,"value":19720},{"code":164,"value":157},{"code":73,"value":1566},{"code":78,"value":-28847},{"code":116,"value":-26640},{"code":55,"value":-22087},{"code":254,"value":10035},{"code":74,"value":-2129},{"code":34,"value":19041},{"code":97,"value":12464},{"code":236,"value":3245},{"code":174,"value":-32155},{"code":30,"value":-15959},{"code":190,"value":-15156},{"code":123,"value":6507},{"code":225,"value":2378},{"code":10,"value":823},{"code":131,"value":25590},{"code":133,"value":-7390},{"code":203,"value":4676},{"code":97,"value":23007},{"code":192,"value":13046},{"code":69,"value":2651},{"code":151,"value":30282},{"code":110,"value":-22492},{"code":247,"value":19872},{"code":179,"value":-19827},{"code":99,"value":30911},{"code":77,"value":23488},{"code":224,"value":-7679},{"code":50,"value":-28073},{"code":148,"value":25838},{"code":179,"value":-7299},{"code":215,"value":-18328},{"code":31,"value":23097},{"code":79,"value":-25579},{"code":245,"value":15441},{"code":93,"value":15530},{"code":200,"value":3495}],"crc":33917,"iod_ssr":132,"length":253,"msg_type":1505,"payload":"0FoTFwlChfH+hDMEg/B4U5TR1T7k6EdCvNKANoOYgW+L8rGRLAn1z/HKlo0yn9yLJbtivxeAiKfIBtNaF/SK19GLDWUgBxIdRvptScpPkAmSRfE0FmNizAOr5rRLPpFWgh8emyUSN9Inf/JCDe2YqtQP9jtetMOdRWR3EESzr5BxUVIelxVtKeEITaSdAEkeBk5Rj3Twlze5qf4zJ0qv9yJhSmGwMOytDK5lgh6pwb7MxHtrGeFKCQo3A4P2Y4Ui48tEEmHfWcD2MkVbCpdKdm4kqPegTbONsmO/eE3AW+AB4jJXkpTuZLN949douB85Wk8VnPVRPF2qPMinDQ==","preamble":85,"sender":22311,"sid":{"code":241,"sat":133},"time":{"tow":387144400,"wn":16905},"update_interval":254}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_code_biases_1();

done_testing();