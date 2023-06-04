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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgSvAzEl.yaml
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
sub test_auto_check_sbp_observation_msg_sv_az_el_1() {
    my $buf = decode_base64("VZcAz3mECACgDAoAi0INABABDwAYGRAAfxISACo1FAAfEBcADEMYAC8KGgB0CBsAmSsdAE0KIABeGgEDEDoCA2w1CAMRDREDpSgXAz8jGAMpSRQMchobDEg2HAxFAx0Mng4eDJhEIAx4UgIOgwYEDhssBQ5lFQkOUUELDjE4DA47Bh4OmgQkDqU+qCQ=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x24A8, "crc");
    
    is($msg->{'length'}, 132, "length");
    
    is($msg->{'msg_type'}, 0x97, "msg_type");
    
    is($msg->{'payload'}, "CACgDAoAi0INABABDwAYGRAAfxISACo1FAAfEBcADEMYAC8KGgB0CBsAmSsdAE0KIABeGgEDEDoCA2w1CAMRDREDpSgXAz8jGAMpSRQMchobDEg2HAxFAx0Mng4eDJhEIAx4UgIOgwYEDhssBQ5lFQkOUUELDjE4DA47Bh4OmgQkDqU+", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x79CF, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->azel()), $json->encode($json->decode(q{[{"az":160,"el":12,"sid":{"code":0,"sat":8}},{"az":139,"el":66,"sid":{"code":0,"sat":10}},{"az":16,"el":1,"sid":{"code":0,"sat":13}},{"az":24,"el":25,"sid":{"code":0,"sat":15}},{"az":127,"el":18,"sid":{"code":0,"sat":16}},{"az":42,"el":53,"sid":{"code":0,"sat":18}},{"az":31,"el":16,"sid":{"code":0,"sat":20}},{"az":12,"el":67,"sid":{"code":0,"sat":23}},{"az":47,"el":10,"sid":{"code":0,"sat":24}},{"az":116,"el":8,"sid":{"code":0,"sat":26}},{"az":153,"el":43,"sid":{"code":0,"sat":27}},{"az":77,"el":10,"sid":{"code":0,"sat":29}},{"az":94,"el":26,"sid":{"code":0,"sat":32}},{"az":16,"el":58,"sid":{"code":3,"sat":1}},{"az":108,"el":53,"sid":{"code":3,"sat":2}},{"az":17,"el":13,"sid":{"code":3,"sat":8}},{"az":165,"el":40,"sid":{"code":3,"sat":17}},{"az":63,"el":35,"sid":{"code":3,"sat":23}},{"az":41,"el":73,"sid":{"code":3,"sat":24}},{"az":114,"el":26,"sid":{"code":12,"sat":20}},{"az":72,"el":54,"sid":{"code":12,"sat":27}},{"az":69,"el":3,"sid":{"code":12,"sat":28}},{"az":158,"el":14,"sid":{"code":12,"sat":29}},{"az":152,"el":68,"sid":{"code":12,"sat":30}},{"az":120,"el":82,"sid":{"code":12,"sat":32}},{"az":131,"el":6,"sid":{"code":14,"sat":2}},{"az":27,"el":44,"sid":{"code":14,"sat":4}},{"az":101,"el":21,"sid":{"code":14,"sat":5}},{"az":81,"el":65,"sid":{"code":14,"sat":9}},{"az":49,"el":56,"sid":{"code":14,"sat":11}},{"az":59,"el":6,"sid":{"code":14,"sat":12}},{"az":154,"el":4,"sid":{"code":14,"sat":30}},{"az":165,"el":62,"sid":{"code":14,"sat":36}}]})), "azel");

    is($json->encode($msg), $json->encode($json->decode(q{{"azel":[{"az":160,"el":12,"sid":{"code":0,"sat":8}},{"az":139,"el":66,"sid":{"code":0,"sat":10}},{"az":16,"el":1,"sid":{"code":0,"sat":13}},{"az":24,"el":25,"sid":{"code":0,"sat":15}},{"az":127,"el":18,"sid":{"code":0,"sat":16}},{"az":42,"el":53,"sid":{"code":0,"sat":18}},{"az":31,"el":16,"sid":{"code":0,"sat":20}},{"az":12,"el":67,"sid":{"code":0,"sat":23}},{"az":47,"el":10,"sid":{"code":0,"sat":24}},{"az":116,"el":8,"sid":{"code":0,"sat":26}},{"az":153,"el":43,"sid":{"code":0,"sat":27}},{"az":77,"el":10,"sid":{"code":0,"sat":29}},{"az":94,"el":26,"sid":{"code":0,"sat":32}},{"az":16,"el":58,"sid":{"code":3,"sat":1}},{"az":108,"el":53,"sid":{"code":3,"sat":2}},{"az":17,"el":13,"sid":{"code":3,"sat":8}},{"az":165,"el":40,"sid":{"code":3,"sat":17}},{"az":63,"el":35,"sid":{"code":3,"sat":23}},{"az":41,"el":73,"sid":{"code":3,"sat":24}},{"az":114,"el":26,"sid":{"code":12,"sat":20}},{"az":72,"el":54,"sid":{"code":12,"sat":27}},{"az":69,"el":3,"sid":{"code":12,"sat":28}},{"az":158,"el":14,"sid":{"code":12,"sat":29}},{"az":152,"el":68,"sid":{"code":12,"sat":30}},{"az":120,"el":82,"sid":{"code":12,"sat":32}},{"az":131,"el":6,"sid":{"code":14,"sat":2}},{"az":27,"el":44,"sid":{"code":14,"sat":4}},{"az":101,"el":21,"sid":{"code":14,"sat":5}},{"az":81,"el":65,"sid":{"code":14,"sat":9}},{"az":49,"el":56,"sid":{"code":14,"sat":11}},{"az":59,"el":6,"sid":{"code":14,"sat":12}},{"az":154,"el":4,"sid":{"code":14,"sat":30}},{"az":165,"el":62,"sid":{"code":14,"sat":36}}],"crc":9384,"length":132,"msg_type":151,"payload":"CACgDAoAi0INABABDwAYGRAAfxISACo1FAAfEBcADEMYAC8KGgB0CBsAmSsdAE0KIABeGgEDEDoCA2w1CAMRDREDpSgXAz8jGAMpSRQMchobDEg2HAxFAx0Mng4eDJhEIAx4UgIOgwYEDhssBQ5lFQkOUUELDjE4DA47Bh4OmgQkDqU+","preamble":85,"sender":31183}})), "raw_json");
}
test_auto_check_sbp_observation_msg_sv_az_el_1();

done_testing();