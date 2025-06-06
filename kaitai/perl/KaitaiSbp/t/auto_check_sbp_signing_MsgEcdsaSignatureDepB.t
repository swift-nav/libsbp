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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepB.yaml
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
sub test_auto_check_sbp_signing_msg_ecdsa_signature_dep_b_1() {
    my $buf = decode_base64("VQcMQgBTAAECAQIDBEgAAQIDBAUGBwgJCgsMDQ4PEBESExQVFhcYGRobHB0eHyAhIiMkJSYnKCkqKywtLi8wMTIzNDU2Nzg5Ojs8PT4/QEFCQ0RFRkcKFRf+nw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9FFE, "crc");
    
    is($msg->{'length'}, 83, "length");
    
    is($msg->{'msg_type'}, 0xC07, "msg_type");
    
    is($msg->{'payload'}, "AAECAQIDBEgAAQIDBAUGBwgJCgsMDQ4PEBESExQVFhcYGRobHB0eHyAhIiMkJSYnKCkqKywtLi8wMTIzNDU2Nzg5Ojs8PT4/QEFCQ0RFRkcKFRc=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->certificate_id()), $json->encode($json->decode(q{[1,2,3,4]})), "certificate_id");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_signature_bytes(), 72, "n_signature_bytes");
    
    is($msg->on_demand_counter(), 2, "on_demand_counter");
    
    is($json->encode($msg->signature()), $json->encode($json->decode(q{[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71]})), "signature");
    
    is($json->encode($msg->signed_messages()), $json->encode($json->decode(q{[10,21,23]})), "signed_messages");
    
    is($msg->stream_counter(), 1, "stream_counter");

    is($json->encode($msg), $json->encode($json->decode(q{{"certificate_id":[1,2,3,4],"crc":40958,"flags":0,"length":83,"msg_type":3079,"n_signature_bytes":72,"on_demand_counter":2,"payload":"AAECAQIDBEgAAQIDBAUGBwgJCgsMDQ4PEBESExQVFhcYGRobHB0eHyAhIiMkJSYnKCkqKywtLi8wMTIzNDU2Nzg5Ojs8PT4/QEFCQ0RFRkcKFRc=","preamble":85,"sender":66,"signature":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71],"signed_messages":[10,21,23],"stream_counter":1}})), "raw_json");
}
test_auto_check_sbp_signing_msg_ecdsa_signature_dep_b_1();

done_testing();
