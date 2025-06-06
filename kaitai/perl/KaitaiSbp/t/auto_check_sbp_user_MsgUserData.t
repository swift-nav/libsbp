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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/user/test_MsgUserData.yaml
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
sub test_auto_check_sbp_user_msg_user_data_1() {
    my $buf = decode_base64("VQAIfiH/NQWsijIxzuqVzHEfbLyzmpynkYsqz37ywQk6SwiHC1yD9Rha/x46H22UOLKMHp9GEaoylAFjcFjZJFQi6lKQkGFgS64627SU9zsCdNZyN4Y2d2yASbUU6RcXSXeI570aroBdHkwtbYZRAHSefyiF0IZ/jOi3uGwG5DbuO9we5NQytmEUKUzjWAxfcNG3fwSlvSzv6IQJcrj50PbC+gJhrZ3KrLSW1cGx0ZwUrhJJhNdzgK+pdIRkSC0ZDs3VkUSJ+TYorteUpr4/dgal1EpEyCaL1HAtp+z/alyEOz3pA/aeU4b2mhEABjjYE9hGR6G4BbEtJWI4lQBJ3WnvqM1VUfU=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf551, "crc");
    
    is($msg->{'length'}, 255, "length");
    
    is($msg->{'msg_type'}, 0x800, "msg_type");
    
    is($msg->{'payload'}, "NQWsijIxzuqVzHEfbLyzmpynkYsqz37ywQk6SwiHC1yD9Rha/x46H22UOLKMHp9GEaoylAFjcFjZJFQi6lKQkGFgS64627SU9zsCdNZyN4Y2d2yASbUU6RcXSXeI570aroBdHkwtbYZRAHSefyiF0IZ/jOi3uGwG5DbuO9we5NQytmEUKUzjWAxfcNG3fwSlvSzv6IQJcrj50PbC+gJhrZ3KrLSW1cGx0ZwUrhJJhNdzgK+pdIRkSC0ZDs3VkUSJ+TYorteUpr4/dgal1EpEyCaL1HAtp+z/alyEOz3pA/aeU4b2mhEABjjYE9hGR6G4BbEtJWI4lQBJ3WnvqM1V", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x217e, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->contents()), $json->encode($json->decode(q{[53,5,172,138,50,49,206,234,149,204,113,31,108,188,179,154,156,167,145,139,42,207,126,242,193,9,58,75,8,135,11,92,131,245,24,90,255,30,58,31,109,148,56,178,140,30,159,70,17,170,50,148,1,99,112,88,217,36,84,34,234,82,144,144,97,96,75,174,58,219,180,148,247,59,2,116,214,114,55,134,54,119,108,128,73,181,20,233,23,23,73,119,136,231,189,26,174,128,93,30,76,45,109,134,81,0,116,158,127,40,133,208,134,127,140,232,183,184,108,6,228,54,238,59,220,30,228,212,50,182,97,20,41,76,227,88,12,95,112,209,183,127,4,165,189,44,239,232,132,9,114,184,249,208,246,194,250,2,97,173,157,202,172,180,150,213,193,177,209,156,20,174,18,73,132,215,115,128,175,169,116,132,100,72,45,25,14,205,213,145,68,137,249,54,40,174,215,148,166,190,63,118,6,165,212,74,68,200,38,139,212,112,45,167,236,255,106,92,132,59,61,233,3,246,158,83,134,246,154,17,0,6,56,216,19,216,70,71,161,184,5,177,45,37,98,56,149,0,73,221,105,239,168,205,85]})), "contents");

    is($json->encode($msg), $json->encode($json->decode(q{{"contents":[53,5,172,138,50,49,206,234,149,204,113,31,108,188,179,154,156,167,145,139,42,207,126,242,193,9,58,75,8,135,11,92,131,245,24,90,255,30,58,31,109,148,56,178,140,30,159,70,17,170,50,148,1,99,112,88,217,36,84,34,234,82,144,144,97,96,75,174,58,219,180,148,247,59,2,116,214,114,55,134,54,119,108,128,73,181,20,233,23,23,73,119,136,231,189,26,174,128,93,30,76,45,109,134,81,0,116,158,127,40,133,208,134,127,140,232,183,184,108,6,228,54,238,59,220,30,228,212,50,182,97,20,41,76,227,88,12,95,112,209,183,127,4,165,189,44,239,232,132,9,114,184,249,208,246,194,250,2,97,173,157,202,172,180,150,213,193,177,209,156,20,174,18,73,132,215,115,128,175,169,116,132,100,72,45,25,14,205,213,145,68,137,249,54,40,174,215,148,166,190,63,118,6,165,212,74,68,200,38,139,212,112,45,167,236,255,106,92,132,59,61,233,3,246,158,83,134,246,154,17,0,6,56,216,19,216,70,71,161,184,5,177,45,37,98,56,149,0,73,221,105,239,168,205,85],"crc":62801,"length":255,"msg_type":2048,"payload":"NQWsijIxzuqVzHEfbLyzmpynkYsqz37ywQk6SwiHC1yD9Rha/x46H22UOLKMHp9GEaoylAFjcFjZJFQi6lKQkGFgS64627SU9zsCdNZyN4Y2d2yASbUU6RcXSXeI570aroBdHkwtbYZRAHSefyiF0IZ/jOi3uGwG5DbuO9we5NQytmEUKUzjWAxfcNG3fwSlvSzv6IQJcrj50PbC+gJhrZ3KrLSW1cGx0ZwUrhJJhNdzgK+pdIRkSC0ZDs3VkUSJ+TYorteUpr4/dgal1EpEyCaL1HAtp+z/alyEOz3pA/aeU4b2mhEABjjYE9hGR6G4BbEtJWI4lQBJ3WnvqM1V","preamble":85,"sender":8574}})), "raw_json");
}
test_auto_check_sbp_user_msg_user_data_1();

done_testing();
