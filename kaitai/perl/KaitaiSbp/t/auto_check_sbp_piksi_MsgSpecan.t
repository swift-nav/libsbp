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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecan.yaml
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
sub test_auto_check_sbp_piksi_msg_specan_1() {
    my $buf = decode_base64("VVEAHNT/SolH9SJJDN3Xp9MTmsnxRc2IAEYzQ2xFZiamRGSzuRGvMcHk5C8hGI2xEmP2eT0oW5Hfp64JdAv3VDGZzQLmwtrxZWstiV1y5ivgF0rRx9OCWdyjRBT9B84ygXTCFx/i2Z3N3QXgXFJt38PppQFSjZ2xqfSDYG1v/ZUc4eFInp7SxM5GP+G4lq7wLZI7UsIEs5RC/nNNHi4EzCXIeRIRq2ajrzJCZUUN36yg6dxl7Zw+dS+PXocWm3FuD/ON4y6P49H5Apmog/mgWCZ1gTkobdGxJi8MDxAJr0VGtu91hwZHY+ZzAkel5HvSqFp8FAfckKhFFkiiRW9b+0jcHHeWXwI=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x025f, "crc");
    
    is($msg->{'length'}, 255, "length");
    
    is($msg->{'msg_type'}, 0x51, "msg_type");
    
    is($msg->{'payload'}, "SolH9SJJDN3Xp9MTmsnxRc2IAEYzQ2xFZiamRGSzuRGvMcHk5C8hGI2xEmP2eT0oW5Hfp64JdAv3VDGZzQLmwtrxZWstiV1y5ivgF0rRx9OCWdyjRBT9B84ygXTCFx/i2Z3N3QXgXFJt38PppQFSjZ2xqfSDYG1v/ZUc4eFInp7SxM5GP+G4lq7wLZI7UsIEs5RC/nNNHi4EzCXIeRIRq2ajrzJCZUUN36yg6dxl7Zw+dS+PXocWm3FuD/ON4y6P49H5Apmog/mgWCZ1gTkobdGxJi8MDxAJr0VGtu91hwZHY+ZzAkel5HvSqFp8FAfckKhFFkiiRW9b+0jcHHeW", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd41c, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->amplitude_ref(), 3780.199951171875, "amplitude_ref");
    
    is($msg->amplitude_unit(), 1329.199951171875, "amplitude_unit");
    
    is($json->encode($msg->amplitude_value()), $json->encode($json->decode(q{[100,179,185,17,175,49,193,228,228,47,33,24,141,177,18,99,246,121,61,40,91,145,223,167,174,9,116,11,247,84,49,153,205,2,230,194,218,241,101,107,45,137,93,114,230,43,224,23,74,209,199,211,130,89,220,163,68,20,253,7,206,50,129,116,194,23,31,226,217,157,205,221,5,224,92,82,109,223,195,233,165,1,82,141,157,177,169,244,131,96,109,111,253,149,28,225,225,72,158,158,210,196,206,70,63,225,184,150,174,240,45,146,59,82,194,4,179,148,66,254,115,77,30,46,4,204,37,200,121,18,17,171,102,163,175,50,66,101,69,13,223,172,160,233,220,101,237,156,62,117,47,143,94,135,22,155,113,110,15,243,141,227,46,143,227,209,249,2,153,168,131,249,160,88,38,117,129,57,40,109,209,177,38,47,12,15,16,9,175,69,70,182,239,117,135,6,71,99,230,115,2,71,165,228,123,210,168,90,124,20,7,220,144,168,69,22,72,162,69,111,91,251,72,220,28,119,150]})), "amplitude_value");
    
    is($msg->channel_tag(), 35146, "channel_tag");
    
    is($msg->freq_ref(), 7737.2001953125, "freq_ref");
    
    is($msg->freq_step(), 8226.2001953125, "freq_step");
    
    is($json->encode($msg->t()), $json->encode($json->decode(q{{"ns_residual":-1479025396,"tow":1227027783,"wn":5075}})), "t");

    is($json->encode($msg), $json->encode($json->decode(q{{"amplitude_ref":3780.199951171875,"amplitude_unit":1329.199951171875,"amplitude_value":[100,179,185,17,175,49,193,228,228,47,33,24,141,177,18,99,246,121,61,40,91,145,223,167,174,9,116,11,247,84,49,153,205,2,230,194,218,241,101,107,45,137,93,114,230,43,224,23,74,209,199,211,130,89,220,163,68,20,253,7,206,50,129,116,194,23,31,226,217,157,205,221,5,224,92,82,109,223,195,233,165,1,82,141,157,177,169,244,131,96,109,111,253,149,28,225,225,72,158,158,210,196,206,70,63,225,184,150,174,240,45,146,59,82,194,4,179,148,66,254,115,77,30,46,4,204,37,200,121,18,17,171,102,163,175,50,66,101,69,13,223,172,160,233,220,101,237,156,62,117,47,143,94,135,22,155,113,110,15,243,141,227,46,143,227,209,249,2,153,168,131,249,160,88,38,117,129,57,40,109,209,177,38,47,12,15,16,9,175,69,70,182,239,117,135,6,71,99,230,115,2,71,165,228,123,210,168,90,124,20,7,220,144,168,69,22,72,162,69,111,91,251,72,220,28,119,150],"channel_tag":35146,"crc":607,"freq_ref":7737.2001953125,"freq_step":8226.2001953125,"length":255,"msg_type":81,"payload":"SolH9SJJDN3Xp9MTmsnxRc2IAEYzQ2xFZiamRGSzuRGvMcHk5C8hGI2xEmP2eT0oW5Hfp64JdAv3VDGZzQLmwtrxZWstiV1y5ivgF0rRx9OCWdyjRBT9B84ygXTCFx/i2Z3N3QXgXFJt38PppQFSjZ2xqfSDYG1v/ZUc4eFInp7SxM5GP+G4lq7wLZI7UsIEs5RC/nNNHi4EzCXIeRIRq2ajrzJCZUUN36yg6dxl7Zw+dS+PXocWm3FuD/ON4y6P49H5Apmog/mgWCZ1gTkobdGxJi8MDxAJr0VGtu91hwZHY+ZzAkel5HvSqFp8FAfckKhFFkiiRW9b+0jcHHeW","preamble":85,"sender":54300,"t":{"ns_residual":-1479025396,"tow":1227027783,"wn":5075}}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_specan_1();

done_testing();