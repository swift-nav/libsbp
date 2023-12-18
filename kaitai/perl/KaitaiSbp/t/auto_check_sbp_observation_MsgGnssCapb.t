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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGnssCapb.yaml
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
sub test_auto_check_sbp_observation_msg_gnss_capb_1() {
    my $buf = decode_base64("VZYAewBusM8GAGoIGqtQQAAAAABRrZAuAAAAANGLXWwAAAAA/MzIAM1cHjHwyxUY1F22IAAAAABpIMAbAAAAAChL+nIAAAAAd5N7UQAAAABVWQQCAAAAAOl0iRYAAAAAx23bC92r+FIAAAAA/D7dHAAAAACjWg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5aa3, "crc");
    
    is($msg->{'length'}, 110, "length");
    
    is($msg->{'msg_type'}, 0x96, "msg_type");
    
    is($msg->{'payload'}, "sM8GAGoIGqtQQAAAAABRrZAuAAAAANGLXWwAAAAA/MzIAM1cHjHwyxUY1F22IAAAAABpIMAbAAAAAChL+nIAAAAAd5N7UQAAAABVWQQCAAAAAOl0iRYAAAAAx23bC92r+FIAAAAA/D7dHAAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x007b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->gc()), $json->encode($json->decode(q{{"bds_active":1929005864,"bds_b2":33839445,"bds_b2a":378107113,"bds_d2nav":1367053175,"gal_active":1392028637,"gal_e5":484261628,"glo_active":13159676,"glo_l2of":824073421,"glo_l3":404081648,"gps_active":1079028506,"gps_l2c":781233489,"gps_l5":1818069969,"qzss_active":198929863,"sbas_active":548822484,"sbas_l5":465576041}})), "gc");
    
    is($json->encode($msg->t_nmct()), $json->encode($json->decode(q{{"tow":446384,"wn":2154}})), "t_nmct");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":23203,"gc":{"bds_active":1929005864,"bds_b2":33839445,"bds_b2a":378107113,"bds_d2nav":1367053175,"gal_active":1392028637,"gal_e5":484261628,"glo_active":13159676,"glo_l2of":824073421,"glo_l3":404081648,"gps_active":1079028506,"gps_l2c":781233489,"gps_l5":1818069969,"qzss_active":198929863,"sbas_active":548822484,"sbas_l5":465576041},"length":110,"msg_type":150,"payload":"sM8GAGoIGqtQQAAAAABRrZAuAAAAANGLXWwAAAAA/MzIAM1cHjHwyxUY1F22IAAAAABpIMAbAAAAAChL+nIAAAAAd5N7UQAAAABVWQQCAAAAAOl0iRYAAAAAx23bC92r+FIAAAAA/D7dHAAAAAA=","preamble":85,"sender":123,"t_nmct":{"tow":446384,"wn":2154}}})), "raw_json");
}
test_auto_check_sbp_observation_msg_gnss_capb_1();

done_testing();