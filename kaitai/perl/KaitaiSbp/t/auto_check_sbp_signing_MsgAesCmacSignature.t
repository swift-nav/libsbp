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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgAesCmacSignature.yaml
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
sub test_auto_check_sbp_signing_msg_aes_cmac_signature_1() {
    my $buf = decode_base64("VRAMQgAaAQIBAgMEAAECAwQFBgcICQoLDA0ODwALFiHAFQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x15C0, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0xC10, "msg_type");
    
    is($msg->{'payload'}, "AQIBAgMEAAECAwQFBgcICQoLDA0ODwALFiE=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->certificate_id()), $json->encode($json->decode(q{[1,2,3,4]})), "certificate_id");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->on_demand_counter(), 2, "on_demand_counter");
    
    is($json->encode($msg->signature()), $json->encode($json->decode(q{[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]})), "signature");
    
    is($json->encode($msg->signed_messages()), $json->encode($json->decode(q{[11,22,33]})), "signed_messages");
    
    is($msg->stream_counter(), 1, "stream_counter");

    is($json->encode($msg), $json->encode($json->decode(q{{"certificate_id":[1,2,3,4],"crc":5568,"flags":0,"length":26,"msg_type":3088,"on_demand_counter":2,"payload":"AQIBAgMEAAECAwQFBgcICQoLDA0ODwALFiE=","preamble":85,"sender":66,"signature":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15],"signed_messages":[11,22,33],"stream_counter":1}})), "raw_json");
}
test_auto_check_sbp_signing_msg_aes_cmac_signature_1();

done_testing();