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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519SignatureDepA.yaml
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
sub test_auto_check_sbp_signing_msg_ed25519_signature_dep_a_1() {
    my $buf = decode_base64("VQEMQgC4AAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc4OTo7PD0+P2RlZmdoaWprbG1ub3BxcnN0dXZ3iBMAAHIUAABcFQAARhYAADAXAAAaGAAABBkAAO4ZAADYGgAAwhsAAKwcAACWHQAAgB4AAGofAABUIAAAPiEAACgiAAASIwAA/CMAAOYkAADQJQAAuiYAAKQnAACOKAAAeCkAAKlv");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6FA9, "crc");
    
    is($msg->{'length'}, 184, "length");
    
    is($msg->{'msg_type'}, 0xC01, "msg_type");
    
    is($msg->{'payload'}, "AAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc4OTo7PD0+P2RlZmdoaWprbG1ub3BxcnN0dXZ3iBMAAHIUAABcFQAARhYAADAXAAAaGAAABBkAAO4ZAADYGgAAwhsAAKwcAACWHQAAgB4AAGofAABUIAAAPiEAACgiAAASIwAA/CMAAOYkAADQJQAAuiYAAKQnAACOKAAAeCkAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->fingerprint()), $json->encode($json->decode(q{[100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119]})), "fingerprint");
    
    is($json->encode($msg->signature()), $json->encode($json->decode(q{[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63]})), "signature");
    
    is($json->encode($msg->signed_messages()), $json->encode($json->decode(q{[5000,5234,5468,5702,5936,6170,6404,6638,6872,7106,7340,7574,7808,8042,8276,8510,8744,8978,9212,9446,9680,9914,10148,10382,10616]})), "signed_messages");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":28585,"fingerprint":[100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119],"length":184,"msg_type":3073,"payload":"AAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc4OTo7PD0+P2RlZmdoaWprbG1ub3BxcnN0dXZ3iBMAAHIUAABcFQAARhYAADAXAAAaGAAABBkAAO4ZAADYGgAAwhsAAKwcAACWHQAAgB4AAGofAABUIAAAPiEAACgiAAASIwAA/CMAAOYkAADQJQAAuiYAAKQnAACOKAAAeCkAAA==","preamble":85,"sender":66,"signature":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63],"signed_messages":[5000,5234,5468,5702,5936,6170,6404,6638,6872,7106,7340,7574,7808,8042,8276,8510,8744,8978,9212,9446,9680,9914,10148,10382,10616]}})), "raw_json");
}
test_auto_check_sbp_signing_msg_ed25519_signature_dep_a_1();

done_testing();