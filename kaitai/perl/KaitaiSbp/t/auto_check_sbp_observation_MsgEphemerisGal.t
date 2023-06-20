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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGal.yaml
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
sub test_auto_check_sbp_observation_msg_ephemeris_gal_1() {
    my $buf = decode_base64("VY0AgPCZGw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAAR9A=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd047, "crc");
    
    is($msg->{'length'}, 153, "length");
    
    is($msg->{'msg_type'}, 0x8d, "msg_type");
    
    is($msg->{'payload'}, "Gw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf080, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), -1.7088896129280325e-05, "af0");
    
    is($msg->af1(), -8.185452315956353e-12, "af1");
    
    is($msg->af2(), 0.0, "af2");
    
    is($msg->bgd_e1e5a(), 2.0954757928848267e-09, "bgd_e1e5a");
    
    is($msg->bgd_e1e5b(), 2.0954757928848267e-09, "bgd_e1e5b");
    
    is($msg->c_ic(), -3.166496753692627e-08, "c_ic");
    
    is($msg->c_is(), -3.166496753692627e-08, "c_is");
    
    is($msg->c_rc(), 265.4375, "c_rc");
    
    is($msg->c_rs(), 10.125, "c_rs");
    
    is($msg->c_uc(), 5.364418029785156e-07, "c_uc");
    
    is($msg->c_us(), 3.993511199951172e-06, "c_us");
    
    is($json->encode($msg->common()), $json->encode($json->decode(q{{"fit_interval":14400,"health_bits":0,"sid":{"code":14,"sat":27},"toe":{"tow":448800,"wn":2154},"ura":3.119999885559082,"valid":1}})), "common");
    
    is($msg->dn(), 3.2262058129932258e-09, "dn");
    
    is($msg->ecc(), 0.00017060607206076384, "ecc");
    
    is($msg->inc(), 0.9777456094977858, "inc");
    
    is($msg->inc_dot(), -3.1787038343451465e-10, "inc_dot");
    
    is($msg->iodc(), 108, "iodc");
    
    is($msg->iode(), 108, "iode");
    
    is($msg->m0(), -1.8457115744155868, "m0");
    
    is($msg->omega0(), 1.16967730598334, "omega0");
    
    is($msg->omegadot(), -5.757382675240872e-09, "omegadot");
    
    is($msg->source(), 0, "source");
    
    is($msg->sqrta(), 5440.602401733398, "sqrta");
    
    is($json->encode($msg->toc()), $json->encode($json->decode(q{{"tow":448800,"wn":2154}})), "toc");
    
    is($msg->w(), 0.12250912091662625, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":-1.7088896129280325e-05,"af1":-8.185452315956353e-12,"af2":0.0,"bgd_e1e5a":2.0954757928848267e-09,"bgd_e1e5b":2.0954757928848267e-09,"c_ic":-3.166496753692627e-08,"c_is":-3.166496753692627e-08,"c_rc":265.4375,"c_rs":10.125,"c_uc":5.364418029785156e-07,"c_us":3.993511199951172e-06,"common":{"fit_interval":14400,"health_bits":0,"sid":{"code":14,"sat":27},"toe":{"tow":448800,"wn":2154},"ura":3.119999885559082,"valid":1},"crc":53319,"dn":3.2262058129932258e-09,"ecc":0.00017060607206076384,"inc":0.9777456094977858,"inc_dot":-3.1787038343451465e-10,"iodc":108,"iode":108,"length":153,"m0":-1.8457115744155868,"msg_type":141,"omega0":1.16967730598334,"omegadot":-5.757382675240872e-09,"payload":"Gw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAA","preamble":85,"sender":61568,"source":0,"sqrta":5440.602401733398,"toc":{"tow":448800,"wn":2154},"w":0.12250912091662625}})), "raw_json");
}
test_auto_check_sbp_observation_msg_ephemeris_gal_1();

done_testing();