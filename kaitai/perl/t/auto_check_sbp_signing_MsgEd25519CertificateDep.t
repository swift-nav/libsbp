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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519CertificateDep.yaml
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
sub test_auto_check_sbp_signing_msg_ed25519_certificate_dep_1() {
    my $buf = decode_base64("VQIMQgBqEGRlZmdoaWprbG1ub3BxcnN0dXZ3AAMGCQwPEhUYGx4hJCcqLTAzNjk8P0JFSEtOUVRXWl1gY2ZpbG9ydXh7foGEh4qNkJOWmZyfoqWoq66xtLe6vcDDxsnMz9LV2Nve4eTn6u3w8/b5/NqU");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x94DA, "crc");
    
    is($msg->{'length'}, 106, "length");
    
    is($msg->{'msg_type'}, 0xC02, "msg_type");
    
    is($msg->{'payload'}, "EGRlZmdoaWprbG1ub3BxcnN0dXZ3AAMGCQwPEhUYGx4hJCcqLTAzNjk8P0JFSEtOUVRXWl1gY2ZpbG9ydXh7foGEh4qNkJOWmZyfoqWoq66xtLe6vcDDxsnMz9LV2Nve4eTn6u3w8/b5/A==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->certificate_bytes()), $json->encode($json->decode(q{[0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,63,66,69,72,75,78,81,84,87,90,93,96,99,102,105,108,111,114,117,120,123,126,129,132,135,138,141,144,147,150,153,156,159,162,165,168,171,174,177,180,183,186,189,192,195,198,201,204,207,210,213,216,219,222,225,228,231,234,237,240,243,246,249,252]})), "certificate_bytes");
    
    is($json->encode($msg->fingerprint()), $json->encode($json->decode(q{[100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119]})), "fingerprint");
    
    is($msg->n_msg(), 16, "n_msg");

    is($json->encode($msg), $json->encode($json->decode(q{{"certificate_bytes":[0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,63,66,69,72,75,78,81,84,87,90,93,96,99,102,105,108,111,114,117,120,123,126,129,132,135,138,141,144,147,150,153,156,159,162,165,168,171,174,177,180,183,186,189,192,195,198,201,204,207,210,213,216,219,222,225,228,231,234,237,240,243,246,249,252],"crc":38106,"fingerprint":[100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119],"length":106,"msg_type":3074,"n_msg":16,"payload":"EGRlZmdoaWprbG1ub3BxcnN0dXZ3AAMGCQwPEhUYGx4hJCcqLTAzNjk8P0JFSEtOUVRXWl1gY2ZpbG9ydXh7foGEh4qNkJOWmZyfoqWoq66xtLe6vcDDxsnMz9LV2Nve4eTn6u3w8/b5/A==","preamble":85,"sender":66}})), "raw_json");
}
test_auto_check_sbp_signing_msg_ed25519_certificate_dep_1();

done_testing();