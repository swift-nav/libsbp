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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCovGNSS.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_ecef_cov_gnss_1() {
    my $buf = decode_base64("VTQCABA2GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQZ7oHjza3RQ8gYjGu814pjwFpiO8erFzPBIEn2Y=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x669f, "crc");
    
    is($msg->{'length'}, 54, "length");
    
    is($msg->{'msg_type'}, 0x234, "msg_type");
    
    is($msg->{'payload'}, "GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQZ7oHjza3RQ8gYjGu814pjwFpiO8erFzPBIE", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_x_x(), 0.009699014946818352, "cov_x_x");
    
    is($msg->cov_x_y(), 0.009086096659302711, "cov_x_y");
    
    is($msg->cov_x_z(), -0.006058753002434969, "cov_x_z");
    
    is($msg->cov_y_y(), 0.020321274176239967, "cov_y_y");
    
    is($msg->cov_y_z(), -0.009988312609493732, "cov_y_z");
    
    is($msg->cov_z_z(), 0.01487385667860508, "cov_z_z");
    
    is($msg->flags(), 4, "flags");
    
    is($msg->n_sats(), 18, "n_sats");
    
    is($msg->tow(), 501867800, "tow");
    
    is($msg->x(), -2694229.7079770807, "x");
    
    is($msg->y(), -4264073.427345817, "y");
    
    is($msg->z(), 3890655.013186158, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_x_x":0.009699014946818352,"cov_x_y":0.009086096659302711,"cov_x_z":-0.006058753002434969,"cov_y_y":0.020321274176239967,"cov_y_z":-0.009988312609493732,"cov_z_z":0.01487385667860508,"crc":26271,"flags":4,"length":54,"msg_type":564,"n_sats":18,"payload":"GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQZ7oHjza3RQ8gYjGu814pjwFpiO8erFzPBIE","preamble":85,"sender":4096,"tow":501867800,"x":-2694229.7079770807,"y":-4264073.427345817,"z":3890655.013186158}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_ecef_cov_gnss_1();

done_testing();