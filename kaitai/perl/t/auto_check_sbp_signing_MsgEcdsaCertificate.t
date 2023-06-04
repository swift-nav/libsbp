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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaCertificate.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # add SBP_PATH to include path and load all modules
    unshift @INC, &SBP_PATH;
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
use t::Utils;
sub test_auto_check_sbp_signing_msg_ecdsa_certificate_1() {
    my $buf = decode_base64("VQQMQgD9MAoLDA0CtKB0TfMcrSRWIQgfeElAqZTgOV8RKNVcw5Lr5LFlUrYZrKr67Ad3BMkKDtAvfjHSrkvdyxhCNCMaHoxv9ifizcayxAVRCSyko9aKe0xK7XkNibphwb3IfEVz5p+5njMM4UHAaTgpVYUT2aYwi4Ng2GKThOqn+Pcg78K8/nJ1Uxn7v2jwdkQqXRIQJehjsxdaXogGfVv/D0crLhn85VCPOvELPrWbNZmVmOOWV3ClAoDnGZ30zGz9f3qRcaLFq8c2uN7OQ5BOu888042HatxPt/UVoagigTKwAdoUgjv5bdsAZGc3HfJumr7pji0918ruWNFGP5cbZtse");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1EDB, "crc");
    
    is($msg->{'length'}, 253, "length");
    
    is($msg->{'msg_type'}, 0xC04, "msg_type");
    
    is($msg->{'payload'}, "MAoLDA0CtKB0TfMcrSRWIQgfeElAqZTgOV8RKNVcw5Lr5LFlUrYZrKr67Ad3BMkKDtAvfjHSrkvdyxhCNCMaHoxv9ifizcayxAVRCSyko9aKe0xK7XkNibphwb3IfEVz5p+5njMM4UHAaTgpVYUT2aYwi4Ng2GKThOqn+Pcg78K8/nJ1Uxn7v2jwdkQqXRIQJehjsxdaXogGfVv/D0crLhn85VCPOvELPrWbNZmVmOOWV3ClAoDnGZ30zGz9f3qRcaLFq8c2uN7OQ5BOu888042HatxPt/UVoagigTKwAdoUgjv5bdsAZGc3HfJumr7pji0918ruWNFGP5cbZg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->certificate_bytes()), $json->encode($json->decode(q{[180,160,116,77,243,28,173,36,86,33,8,31,120,73,64,169,148,224,57,95,17,40,213,92,195,146,235,228,177,101,82,182,25,172,170,250,236,7,119,4,201,10,14,208,47,126,49,210,174,75,221,203,24,66,52,35,26,30,140,111,246,39,226,205,198,178,196,5,81,9,44,164,163,214,138,123,76,74,237,121,13,137,186,97,193,189,200,124,69,115,230,159,185,158,51,12,225,65,192,105,56,41,85,133,19,217,166,48,139,131,96,216,98,147,132,234,167,248,247,32,239,194,188,254,114,117,83,25,251,191,104,240,118,68,42,93,18,16,37,232,99,179,23,90,94,136,6,125,91,255,15,71,43,46,25,252,229,80,143,58,241,11,62,181,155,53,153,149,152,227,150,87,112,165,2,128,231,25,157,244,204,108,253,127,122,145,113,162,197,171,199,54,184,222,206,67,144,78,187,207,60,211,141,135,106,220,79,183,245,21,161,168,34,129,50,176,1,218,20,130,59,249,109,219,0,100,103,55,29,242,110,154,190,233,142,45,61,215,202,238,88,209,70,63,151,27,102]})), "certificate_bytes");
    
    is($json->encode($msg->certificate_id()), $json->encode($json->decode(q{[10,11,12,13]})), "certificate_id");
    
    is($msg->flags(), 2, "flags");
    
    is($msg->n_msg(), 48, "n_msg");

    is($json->encode($msg), $json->encode($json->decode(q{{"certificate_bytes":[180,160,116,77,243,28,173,36,86,33,8,31,120,73,64,169,148,224,57,95,17,40,213,92,195,146,235,228,177,101,82,182,25,172,170,250,236,7,119,4,201,10,14,208,47,126,49,210,174,75,221,203,24,66,52,35,26,30,140,111,246,39,226,205,198,178,196,5,81,9,44,164,163,214,138,123,76,74,237,121,13,137,186,97,193,189,200,124,69,115,230,159,185,158,51,12,225,65,192,105,56,41,85,133,19,217,166,48,139,131,96,216,98,147,132,234,167,248,247,32,239,194,188,254,114,117,83,25,251,191,104,240,118,68,42,93,18,16,37,232,99,179,23,90,94,136,6,125,91,255,15,71,43,46,25,252,229,80,143,58,241,11,62,181,155,53,153,149,152,227,150,87,112,165,2,128,231,25,157,244,204,108,253,127,122,145,113,162,197,171,199,54,184,222,206,67,144,78,187,207,60,211,141,135,106,220,79,183,245,21,161,168,34,129,50,176,1,218,20,130,59,249,109,219,0,100,103,55,29,242,110,154,190,233,142,45,61,215,202,238,88,209,70,63,151,27,102],"certificate_id":[10,11,12,13],"crc":7899,"flags":2,"length":253,"msg_type":3076,"n_msg":48,"payload":"MAoLDA0CtKB0TfMcrSRWIQgfeElAqZTgOV8RKNVcw5Lr5LFlUrYZrKr67Ad3BMkKDtAvfjHSrkvdyxhCNCMaHoxv9ifizcayxAVRCSyko9aKe0xK7XkNibphwb3IfEVz5p+5njMM4UHAaTgpVYUT2aYwi4Ng2GKThOqn+Pcg78K8/nJ1Uxn7v2jwdkQqXRIQJehjsxdaXogGfVv/D0crLhn85VCPOvELPrWbNZmVmOOWV3ClAoDnGZ30zGz9f3qRcaLFq8c2uN7OQ5BOu888042HatxPt/UVoagigTKwAdoUgjv5bdsAZGc3HfJumr7pji0918ruWNFGP5cbZg==","preamble":85,"sender":66}})), "raw_json");
}
test_auto_check_sbp_signing_msg_ecdsa_certificate_1();

done_testing();