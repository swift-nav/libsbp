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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # load all modules from SBP_PATH
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_observation_msg_obs_1() {
    my $buf = decode_base64("VUoAgfD5mMriGQAAAABqCCAx4/4+efKeBpIA+qy2Cg8KAB7k/j4MvSgFO1P7rLIKDwoB182QSGpvoAfzbfN3ngoPEgAZz5BI32DxBQw09ht9CQsSASK430qWit4HNQ0L9XIJDxYAcVAGRaIpQQdGf/b2vQkPFwD3UAZF1SOnBd2Y+OeeCQsXAQiSpkAMessGcjP4Q10DCxsA3aytS9kv9Afo4QvtewUPHwD6rq1L2KMyBihGCT54AwsfAYcQBkJj2gsHB4ryYLAKDwIDlIIGOtlYNgbLFfxgqgoPAwO6bMU/fzbTBlAE8dvICg8RA6fDCDkTzBYGaTP+tpgKDxID7fg=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf8ed, "crc");
    
    is($msg->{'length'}, 249, "length");
    
    is($msg->{'msg_type'}, 0x4a, "msg_type");
    
    is($msg->{'payload'}, "mMriGQAAAABqCCAx4/4+efKeBpIA+qy2Cg8KAB7k/j4MvSgFO1P7rLIKDwoB182QSGpvoAfzbfN3ngoPEgAZz5BI32DxBQw09ht9CQsSASK430qWit4HNQ0L9XIJDxYAcVAGRaIpQQdGf/b2vQkPFwD3UAZF1SOnBd2Y+OeeCQsXAQiSpkAMessGcjP4Q10DCxsA3aytS9kv9Afo4QvtewUPHwD6rq1L2KMyBihGCT54AwsfAYcQBkJj2gsHB4ryYLAKDwIDlIIGOtlYNgbLFfxgqgoPAwO6bMU/fzbTBlAE8dvICg8RA6fDCDkTzBYGaTP+tpgKDxID", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf081, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":32,"t":{"ns_residual":0,"tow":434293400,"wn":2154}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"cn0":182,"d":{"f":172,"i":-1536},"flags":15,"l":{"f":146,"i":111080057},"lock":10,"p":1056891697,"sid":{"code":0,"sat":10}},{"cn0":178,"d":{"f":172,"i":-1197},"flags":15,"l":{"f":59,"i":86555916},"lock":10,"p":1056891934,"sid":{"code":1,"sat":10}},{"cn0":158,"d":{"f":119,"i":-3219},"flags":15,"l":{"f":243,"i":127954794},"lock":10,"p":1217449431,"sid":{"code":0,"sat":18}},{"cn0":125,"d":{"f":27,"i":-2508},"flags":11,"l":{"f":12,"i":99705055},"lock":9,"p":1217449753,"sid":{"code":1,"sat":18}},{"cn0":114,"d":{"f":245,"i":2829},"flags":15,"l":{"f":53,"i":132024982},"lock":9,"p":1256175650,"sid":{"code":0,"sat":22}},{"cn0":189,"d":{"f":246,"i":-2433},"flags":15,"l":{"f":70,"i":121711010},"lock":9,"p":1158041713,"sid":{"code":0,"sat":23}},{"cn0":158,"d":{"f":231,"i":-1896},"flags":11,"l":{"f":221,"i":94839765},"lock":9,"p":1158041847,"sid":{"code":1,"sat":23}},{"cn0":93,"d":{"f":67,"i":-1997},"flags":11,"l":{"f":114,"i":113998348},"lock":3,"p":1084658184,"sid":{"code":0,"sat":27}},{"cn0":123,"d":{"f":237,"i":3041},"flags":15,"l":{"f":232,"i":133443545},"lock":5,"p":1269673181,"sid":{"code":0,"sat":31}},{"cn0":120,"d":{"f":62,"i":2374},"flags":11,"l":{"f":40,"i":103982040},"lock":3,"p":1269673722,"sid":{"code":1,"sat":31}},{"cn0":176,"d":{"f":96,"i":-3446},"flags":15,"l":{"f":7,"i":118217315},"lock":10,"p":1107693703,"sid":{"code":3,"sat":2}},{"cn0":170,"d":{"f":96,"i":-1003},"flags":15,"l":{"f":203,"i":104224985},"lock":10,"p":973505172,"sid":{"code":3,"sat":3}},{"cn0":200,"d":{"f":219,"i":-3836},"flags":15,"l":{"f":80,"i":114505343},"lock":10,"p":1069903034,"sid":{"code":3,"sat":17}},{"cn0":152,"d":{"f":182,"i":-461},"flags":15,"l":{"f":105,"i":102157331},"lock":10,"p":956875687,"sid":{"code":3,"sat":18}}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":63725,"header":{"n_obs":32,"t":{"ns_residual":0,"tow":434293400,"wn":2154}},"length":249,"msg_type":74,"obs":[{"cn0":182,"d":{"f":172,"i":-1536},"flags":15,"l":{"f":146,"i":111080057},"lock":10,"p":1056891697,"sid":{"code":0,"sat":10}},{"cn0":178,"d":{"f":172,"i":-1197},"flags":15,"l":{"f":59,"i":86555916},"lock":10,"p":1056891934,"sid":{"code":1,"sat":10}},{"cn0":158,"d":{"f":119,"i":-3219},"flags":15,"l":{"f":243,"i":127954794},"lock":10,"p":1217449431,"sid":{"code":0,"sat":18}},{"cn0":125,"d":{"f":27,"i":-2508},"flags":11,"l":{"f":12,"i":99705055},"lock":9,"p":1217449753,"sid":{"code":1,"sat":18}},{"cn0":114,"d":{"f":245,"i":2829},"flags":15,"l":{"f":53,"i":132024982},"lock":9,"p":1256175650,"sid":{"code":0,"sat":22}},{"cn0":189,"d":{"f":246,"i":-2433},"flags":15,"l":{"f":70,"i":121711010},"lock":9,"p":1158041713,"sid":{"code":0,"sat":23}},{"cn0":158,"d":{"f":231,"i":-1896},"flags":11,"l":{"f":221,"i":94839765},"lock":9,"p":1158041847,"sid":{"code":1,"sat":23}},{"cn0":93,"d":{"f":67,"i":-1997},"flags":11,"l":{"f":114,"i":113998348},"lock":3,"p":1084658184,"sid":{"code":0,"sat":27}},{"cn0":123,"d":{"f":237,"i":3041},"flags":15,"l":{"f":232,"i":133443545},"lock":5,"p":1269673181,"sid":{"code":0,"sat":31}},{"cn0":120,"d":{"f":62,"i":2374},"flags":11,"l":{"f":40,"i":103982040},"lock":3,"p":1269673722,"sid":{"code":1,"sat":31}},{"cn0":176,"d":{"f":96,"i":-3446},"flags":15,"l":{"f":7,"i":118217315},"lock":10,"p":1107693703,"sid":{"code":3,"sat":2}},{"cn0":170,"d":{"f":96,"i":-1003},"flags":15,"l":{"f":203,"i":104224985},"lock":10,"p":973505172,"sid":{"code":3,"sat":3}},{"cn0":200,"d":{"f":219,"i":-3836},"flags":15,"l":{"f":80,"i":114505343},"lock":10,"p":1069903034,"sid":{"code":3,"sat":17}},{"cn0":152,"d":{"f":182,"i":-461},"flags":15,"l":{"f":105,"i":102157331},"lock":10,"p":956875687,"sid":{"code":3,"sat":18}}],"payload":"mMriGQAAAABqCCAx4/4+efKeBpIA+qy2Cg8KAB7k/j4MvSgFO1P7rLIKDwoB182QSGpvoAfzbfN3ngoPEgAZz5BI32DxBQw09ht9CQsSASK430qWit4HNQ0L9XIJDxYAcVAGRaIpQQdGf/b2vQkPFwD3UAZF1SOnBd2Y+OeeCQsXAQiSpkAMessGcjP4Q10DCxsA3aytS9kv9Afo4QvtewUPHwD6rq1L2KMyBihGCT54AwsfAYcQBkJj2gsHB4ryYLAKDwIDlIIGOtlYNgbLFfxgqgoPAwO6bMU/fzbTBlAE8dvICg8RA6fDCDkTzBYGaTP+tpgKDxID","preamble":85,"sender":61569}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_obs_2() {
    my $buf = decode_base64("VUoAgfALmMriGQAAAABqCBDJZQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x65c9, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'payload'}, "mMriGQAAAABqCBA=", "payload");
    
    is($msg->{'msg_type'}, 0x4a, "msg_type");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf081, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":16,"t":{"ns_residual":0,"tow":434293400,"wn":2154}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":26057,"header":{"n_obs":16,"t":{"ns_residual":0,"tow":434293400,"wn":2154}},"length":11,"msg_type":74,"obs":[],"payload":"mMriGQAAAABqCBA=","preamble":85,"sender":61569}})), "raw_json");
}
test_auto_check_sbp_observation_msg_obs_1();
test_auto_check_sbp_observation_msg_obs_2();

done_testing();