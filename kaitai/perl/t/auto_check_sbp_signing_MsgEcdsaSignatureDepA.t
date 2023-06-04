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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepA.yaml
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
sub test_auto_check_sbp_signing_msg_ecdsa_signature_dep_a_1() {
    my $buf = decode_base64("VQYMQgD/AAECAQIDBAABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcKFRc/jCWCahwopbNJsjx+ck5xG18DPmiRYBNcew5ambcJSFF2cHwQtkySczqQEWlCH4c2ZFS1ZwtYhZunrY9WnhSohI1mMjBHkzVXAWyKJIaLo1IrNJYMHm6ca3hbekWkqnQZXgUWGKKvJp1iLKAvYY4ISg2xD4Aag5pBqTeIfauhHYGXRKYzRi04T5VjKmWYJ1m0QDEGUKwgbQJ3XbAAITkiElV5iVNvOwdNBHWflCM9KUMuf0uuYaw=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xAC61, "crc");
    
    is($msg->{'length'}, 255, "length");
    
    is($msg->{'msg_type'}, 0xC06, "msg_type");
    
    is($msg->{'payload'}, "AAECAQIDBAABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcKFRc/jCWCahwopbNJsjx+ck5xG18DPmiRYBNcew5ambcJSFF2cHwQtkySczqQEWlCH4c2ZFS1ZwtYhZunrY9WnhSohI1mMjBHkzVXAWyKJIaLo1IrNJYMHm6ca3hbekWkqnQZXgUWGKKvJp1iLKAvYY4ISg2xD4Aag5pBqTeIfauhHYGXRKYzRi04T5VjKmWYJ1m0QDEGUKwgbQJ3XbAAITkiElV5iVNvOwdNBHWflCM9KUMuf0uu", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->certificate_id()), $json->encode($json->decode(q{[1,2,3,4]})), "certificate_id");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->on_demand_counter(), 2, "on_demand_counter");
    
    is($json->encode($msg->signature()), $json->encode($json->decode(q{[0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7]})), "signature");
    
    is($json->encode($msg->signed_messages()), $json->encode($json->decode(q{[10,21,23,63,140,37,130,106,28,40,165,179,73,178,60,126,114,78,113,27,95,3,62,104,145,96,19,92,123,14,90,153,183,9,72,81,118,112,124,16,182,76,146,115,58,144,17,105,66,31,135,54,100,84,181,103,11,88,133,155,167,173,143,86,158,20,168,132,141,102,50,48,71,147,53,87,1,108,138,36,134,139,163,82,43,52,150,12,30,110,156,107,120,91,122,69,164,170,116,25,94,5,22,24,162,175,38,157,98,44,160,47,97,142,8,74,13,177,15,128,26,131,154,65,169,55,136,125,171,161,29,129,151,68,166,51,70,45,56,79,149,99,42,101,152,39,89,180,64,49,6,80,172,32,109,2,119,93,176,0,33,57,34,18,85,121,137,83,111,59,7,77,4,117,159,148,35,61,41,67,46,127,75,174]})), "signed_messages");
    
    is($msg->stream_counter(), 1, "stream_counter");

    is($json->encode($msg), $json->encode($json->decode(q{{"certificate_id":[1,2,3,4],"crc":44129,"flags":0,"length":255,"msg_type":3078,"on_demand_counter":2,"payload":"AAECAQIDBAABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcKFRc/jCWCahwopbNJsjx+ck5xG18DPmiRYBNcew5ambcJSFF2cHwQtkySczqQEWlCH4c2ZFS1ZwtYhZunrY9WnhSohI1mMjBHkzVXAWyKJIaLo1IrNJYMHm6ca3hbekWkqnQZXgUWGKKvJp1iLKAvYY4ISg2xD4Aag5pBqTeIfauhHYGXRKYzRi04T5VjKmWYJ1m0QDEGUKwgbQJ3XbAAITkiElV5iVNvOwdNBHWflCM9KUMuf0uu","preamble":85,"sender":66,"signature":[0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7],"signed_messages":[10,21,23,63,140,37,130,106,28,40,165,179,73,178,60,126,114,78,113,27,95,3,62,104,145,96,19,92,123,14,90,153,183,9,72,81,118,112,124,16,182,76,146,115,58,144,17,105,66,31,135,54,100,84,181,103,11,88,133,155,167,173,143,86,158,20,168,132,141,102,50,48,71,147,53,87,1,108,138,36,134,139,163,82,43,52,150,12,30,110,156,107,120,91,122,69,164,170,116,25,94,5,22,24,162,175,38,157,98,44,160,47,97,142,8,74,13,177,15,128,26,131,154,65,169,55,136,125,171,161,29,129,151,68,166,51,70,45,56,79,149,99,42,101,152,39,89,180,64,49,6,80,172,32,109,2,119,93,176,0,33,57,34,18,85,121,137,83,111,59,7,77,4,117,159,148,35,61,41,67,46,127,75,174],"stream_counter":1}})), "raw_json");
}
test_auto_check_sbp_signing_msg_ecdsa_signature_dep_a_1();

done_testing();