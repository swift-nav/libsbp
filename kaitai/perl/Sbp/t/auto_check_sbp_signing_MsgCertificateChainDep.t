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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgCertificateChainDep.yaml
# with generate.py.  Do not modify by hand!

use strict;

BEGIN {
    # add grandparent directory to include path
    use Cwd qw(realpath);
    use File::Basename;
    unshift @INC, realpath(dirname($0))."/../../";
}

use Sbp::Sbp;
use Sbp::ParseUtils;
use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_signing_msg_certificate_chain_dep_1() {
    my $buf = decode_base64("VQUMQgCHAAECAwQFBgcICQoLDA0ODxAREhMKCwwNDg8QERITAAECAwQFBgcICRQVFhcYGRobHB0KCwwNDg8QERIT6AcDHgwiOxXNWwcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHcGQ=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6470, "crc");
    
    is($msg->{'length'}, 135, "length");
    
    is($msg->{'msg_type'}, 0xC05, "msg_type");
    
    is($msg->{'payload'}, "AAECAwQFBgcICQoLDA0ODxAREhMKCwwNDg8QERITAAECAwQFBgcICRQVFhcYGRobHB0KCwwNDg8QERIT6AcDHgwiOxXNWwcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYH", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->corrections_certificate()), $json->encode($json->decode(q{[20,21,22,23,24,25,26,27,28,29,10,11,12,13,14,15,16,17,18,19]})), "corrections_certificate");
    
    is($json->encode($msg->expiration()), $json->encode($json->decode(q{{"day":30,"hours":12,"minutes":34,"month":3,"ns":123456789,"seconds":59,"year":2024}})), "expiration");
    
    is($json->encode($msg->intermediate_certificate()), $json->encode($json->decode(q{[10,11,12,13,14,15,16,17,18,19,0,1,2,3,4,5,6,7,8,9]})), "intermediate_certificate");
    
    is($json->encode($msg->root_certificate()), $json->encode($json->decode(q{[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19]})), "root_certificate");
    
    is($json->encode($msg->signature()), $json->encode($json->decode(q{[0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7]})), "signature");

    is($json->encode($msg), $json->encode($json->decode(q{{"corrections_certificate":[20,21,22,23,24,25,26,27,28,29,10,11,12,13,14,15,16,17,18,19],"crc":25712,"expiration":{"day":30,"hours":12,"minutes":34,"month":3,"ns":123456789,"seconds":59,"year":2024},"intermediate_certificate":[10,11,12,13,14,15,16,17,18,19,0,1,2,3,4,5,6,7,8,9],"length":135,"msg_type":3077,"payload":"AAECAwQFBgcICQoLDA0ODxAREhMKCwwNDg8QERITAAECAwQFBgcICRQVFhcYGRobHB0KCwwNDg8QERIT6AcDHgwiOxXNWwcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYH","preamble":85,"root_certificate":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19],"sender":66,"signature":[0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7]}})), "raw_json");
}
test_auto_check_sbp_signing_msg_certificate_chain_dep_1();

done_testing();