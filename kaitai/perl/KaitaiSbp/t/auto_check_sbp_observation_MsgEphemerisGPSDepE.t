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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGPSDepE.yaml
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
sub test_auto_check_sbp_observation_msg_ephemeris_gps_dep_e_1() {
    my $buf = decode_base64("VYEAewC5FgAAALDPBgBqCAAAAAAAAABAQDgAAAEAAAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9AAAAAAAAAACwzwYAaggtLQAG7g==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xee06, "crc");
    
    is($msg->{'length'}, 185, "length");
    
    is($msg->{'msg_type'}, 0x81, "msg_type");
    
    is($msg->{'payload'}, "FgAAALDPBgBqCAAAAAAAAABAQDgAAAEAAAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9AAAAAAAAAACwzwYAaggtLQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x007b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), -0.0006315018981695175, "af0");
    
    is($msg->af1(), 8.981260180007666e-12, "af1");
    
    is($msg->af2(), 0.0, "af2");
    
    is($msg->c_ic(), 7.450580596923828e-09, "c_ic");
    
    is($msg->c_is(), -1.1548399925231934e-07, "c_is");
    
    is($msg->c_rc(), 308.625, "c_rc");
    
    is($msg->c_rs(), -52.3125, "c_rs");
    
    is($msg->c_uc(), -2.7436763048171997e-06, "c_uc");
    
    is($msg->c_us(), 3.1366944313049316e-06, "c_us");
    
    is($json->encode($msg->common()), $json->encode($json->decode(q{{"fit_interval":14400,"health_bits":0,"sid":{"code":0,"reserved":0,"sat":22},"toe":{"tow":446384,"wn":2154},"ura":2.0,"valid":1}})), "common");
    
    is($msg->dn(), 5.694522914022375e-09, "dn");
    
    is($msg->ecc(), 0.007072207052260637, "ecc");
    
    is($msg->inc(), 0.9341514480259797, "inc");
    
    is($msg->inc_dot(), -4.035882396415757e-11, "inc_dot");
    
    is($msg->iodc(), 45, "iodc");
    
    is($msg->iode(), 45, "iode");
    
    is($msg->m0(), -0.02200078842114688, "m0");
    
    is($msg->omega0(), -1.8731818448797617, "omega0");
    
    is($msg->omegadot(), -8.903585155774196e-09, "omegadot");
    
    is($msg->sqrta(), 5153.550029754639, "sqrta");
    
    is($msg->tgd(), -1.7695128917694092e-08, "tgd");
    
    is($json->encode($msg->toc()), $json->encode($json->decode(q{{"tow":446384,"wn":2154}})), "toc");
    
    is($msg->w(), -0.9893036629599647, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":-0.0006315018981695175,"af1":8.981260180007666e-12,"af2":0,"c_ic":7.450580596923828e-09,"c_is":-1.1548399925231934e-07,"c_rc":308.625,"c_rs":-52.3125,"c_uc":-2.7436763048171997e-06,"c_us":3.1366944313049316e-06,"common":{"fit_interval":14400,"health_bits":0,"sid":{"code":0,"reserved":0,"sat":22},"toe":{"tow":446384,"wn":2154},"ura":2,"valid":1},"crc":60934,"dn":5.694522914022375e-09,"ecc":0.007072207052260637,"inc":0.9341514480259797,"inc_dot":-4.035882396415757e-11,"iodc":45,"iode":45,"length":185,"m0":-0.02200078842114688,"msg_type":129,"omega0":-1.8731818448797617,"omegadot":-8.903585155774196e-09,"payload":"FgAAALDPBgBqCAAAAAAAAABAQDgAAAEAAAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9AAAAAAAAAACwzwYAaggtLQA=","preamble":85,"sender":123,"sqrta":5153.550029754639,"tgd":-1.7695128917694092e-08,"toc":{"tow":446384,"wn":2154},"w":-0.9893036629599647}})), "raw_json");
}
test_auto_check_sbp_observation_msg_ephemeris_gps_dep_e_1();

done_testing();
