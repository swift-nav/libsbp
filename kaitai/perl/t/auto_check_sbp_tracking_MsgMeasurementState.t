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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgMeasurementState.yaml
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
sub test_auto_check_sbp_tracking_msg_measurement_state_1() {
    my $buf = decode_base64("VWEAz3ntHQCiAAAAAAAAGwDJFACoIAC4DwC7AAAAEgDSEACnAAAAFwDVCgDfAAAAAAAAAAAAAAAAgwLKGwHADwGlHQGSIAGqEgHJAAAAAAAAAAAAFwHUCgHNAAAAYAPmAAAAZQPWZwPUaAPRagOdZgPmAAAAAAAAZQS9YATPagSkaATBAAAAZgTQAAAAGwzUHQyhIAzYHgzYFAyyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJA7LAAAABQ6eBA7CCw7ACQ7PAAAAAAAAAAAACRTaBRSwJBTZCxTIBBTNAAAAAAAAIzY=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3623, "crc");
    
    is($msg->{'length'}, 237, "length");
    
    is($msg->{'msg_type'}, 0x61, "msg_type");
    
    is($msg->{'payload'}, "HQCiAAAAAAAAGwDJFACoIAC4DwC7AAAAEgDSEACnAAAAFwDVCgDfAAAAAAAAAAAAAAAAgwLKGwHADwGlHQGSIAGqEgHJAAAAAAAAAAAAFwHUCgHNAAAAYAPmAAAAZQPWZwPUaAPRagOdZgPmAAAAAAAAZQS9YATPagSkaATBAAAAZgTQAAAAGwzUHQyhIAzYHgzYFAyyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJA7LAAAABQ6eBA7CCw7ACQ7PAAAAAAAAAAAACRTaBRSwJBTZCxTIBBTNAAAAAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x79CF, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":162,"mesid":{"code":0,"sat":29}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":201,"mesid":{"code":0,"sat":27}},{"cn0":168,"mesid":{"code":0,"sat":20}},{"cn0":184,"mesid":{"code":0,"sat":32}},{"cn0":187,"mesid":{"code":0,"sat":15}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":210,"mesid":{"code":0,"sat":18}},{"cn0":167,"mesid":{"code":0,"sat":16}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":213,"mesid":{"code":0,"sat":23}},{"cn0":223,"mesid":{"code":0,"sat":10}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":202,"mesid":{"code":2,"sat":131}},{"cn0":192,"mesid":{"code":1,"sat":27}},{"cn0":165,"mesid":{"code":1,"sat":15}},{"cn0":146,"mesid":{"code":1,"sat":29}},{"cn0":170,"mesid":{"code":1,"sat":32}},{"cn0":201,"mesid":{"code":1,"sat":18}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":212,"mesid":{"code":1,"sat":23}},{"cn0":205,"mesid":{"code":1,"sat":10}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":230,"mesid":{"code":3,"sat":96}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":214,"mesid":{"code":3,"sat":101}},{"cn0":212,"mesid":{"code":3,"sat":103}},{"cn0":209,"mesid":{"code":3,"sat":104}},{"cn0":157,"mesid":{"code":3,"sat":106}},{"cn0":230,"mesid":{"code":3,"sat":102}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":189,"mesid":{"code":4,"sat":101}},{"cn0":207,"mesid":{"code":4,"sat":96}},{"cn0":164,"mesid":{"code":4,"sat":106}},{"cn0":193,"mesid":{"code":4,"sat":104}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":208,"mesid":{"code":4,"sat":102}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":212,"mesid":{"code":12,"sat":27}},{"cn0":161,"mesid":{"code":12,"sat":29}},{"cn0":216,"mesid":{"code":12,"sat":32}},{"cn0":216,"mesid":{"code":12,"sat":30}},{"cn0":178,"mesid":{"code":12,"sat":20}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":203,"mesid":{"code":14,"sat":36}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":158,"mesid":{"code":14,"sat":5}},{"cn0":194,"mesid":{"code":14,"sat":4}},{"cn0":192,"mesid":{"code":14,"sat":11}},{"cn0":207,"mesid":{"code":14,"sat":9}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":218,"mesid":{"code":20,"sat":9}},{"cn0":176,"mesid":{"code":20,"sat":5}},{"cn0":217,"mesid":{"code":20,"sat":36}},{"cn0":200,"mesid":{"code":20,"sat":11}},{"cn0":205,"mesid":{"code":20,"sat":4}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":13859,"length":237,"msg_type":97,"payload":"HQCiAAAAAAAAGwDJFACoIAC4DwC7AAAAEgDSEACnAAAAFwDVCgDfAAAAAAAAAAAAAAAAgwLKGwHADwGlHQGSIAGqEgHJAAAAAAAAAAAAFwHUCgHNAAAAYAPmAAAAZQPWZwPUaAPRagOdZgPmAAAAAAAAZQS9YATPagSkaATBAAAAZgTQAAAAGwzUHQyhIAzYHgzYFAyyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJA7LAAAABQ6eBA7CCw7ACQ7PAAAAAAAAAAAACRTaBRSwJBTZCxTIBBTNAAAAAAAA","preamble":85,"sender":31183,"states":[{"cn0":162,"mesid":{"code":0,"sat":29}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":201,"mesid":{"code":0,"sat":27}},{"cn0":168,"mesid":{"code":0,"sat":20}},{"cn0":184,"mesid":{"code":0,"sat":32}},{"cn0":187,"mesid":{"code":0,"sat":15}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":210,"mesid":{"code":0,"sat":18}},{"cn0":167,"mesid":{"code":0,"sat":16}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":213,"mesid":{"code":0,"sat":23}},{"cn0":223,"mesid":{"code":0,"sat":10}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":202,"mesid":{"code":2,"sat":131}},{"cn0":192,"mesid":{"code":1,"sat":27}},{"cn0":165,"mesid":{"code":1,"sat":15}},{"cn0":146,"mesid":{"code":1,"sat":29}},{"cn0":170,"mesid":{"code":1,"sat":32}},{"cn0":201,"mesid":{"code":1,"sat":18}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":212,"mesid":{"code":1,"sat":23}},{"cn0":205,"mesid":{"code":1,"sat":10}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":230,"mesid":{"code":3,"sat":96}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":214,"mesid":{"code":3,"sat":101}},{"cn0":212,"mesid":{"code":3,"sat":103}},{"cn0":209,"mesid":{"code":3,"sat":104}},{"cn0":157,"mesid":{"code":3,"sat":106}},{"cn0":230,"mesid":{"code":3,"sat":102}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":189,"mesid":{"code":4,"sat":101}},{"cn0":207,"mesid":{"code":4,"sat":96}},{"cn0":164,"mesid":{"code":4,"sat":106}},{"cn0":193,"mesid":{"code":4,"sat":104}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":208,"mesid":{"code":4,"sat":102}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":212,"mesid":{"code":12,"sat":27}},{"cn0":161,"mesid":{"code":12,"sat":29}},{"cn0":216,"mesid":{"code":12,"sat":32}},{"cn0":216,"mesid":{"code":12,"sat":30}},{"cn0":178,"mesid":{"code":12,"sat":20}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":203,"mesid":{"code":14,"sat":36}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":158,"mesid":{"code":14,"sat":5}},{"cn0":194,"mesid":{"code":14,"sat":4}},{"cn0":192,"mesid":{"code":14,"sat":11}},{"cn0":207,"mesid":{"code":14,"sat":9}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":218,"mesid":{"code":20,"sat":9}},{"cn0":176,"mesid":{"code":20,"sat":5}},{"cn0":217,"mesid":{"code":20,"sat":36}},{"cn0":200,"mesid":{"code":20,"sat":11}},{"cn0":205,"mesid":{"code":20,"sat":4}},{"cn0":0,"mesid":{"code":0,"sat":0}},{"cn0":0,"mesid":{"code":0,"sat":0}}]}})), "raw_json");
}
test_auto_check_sbp_tracking_msg_measurement_state_1();

done_testing();