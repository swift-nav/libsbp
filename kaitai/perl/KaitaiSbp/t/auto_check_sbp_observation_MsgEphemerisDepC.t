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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisDepC.yaml
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
sub test_auto_check_sbp_observation_msg_ephemeris_dep_c_1() {
    my $buf = decode_base64("VUcAwwS5AAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9mpmZmZmZyT/NzMzMwD4bQWoIzczMzMA+G0FqCAEAFgAAAC0tAAAAAAAXqg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xaa17, "crc");
    
    is($msg->{'length'}, 185, "length");
    
    is($msg->{'msg_type'}, 0x47, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9mpmZmZmZyT/NzMzMwD4bQWoIzczMzMA+G0FqCAEAFgAAAC0tAAAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), -0.0006315018981695175, "af0");
    
    is($msg->af1(), 8.981260180007666e-12, "af1");
    
    is($msg->af2(), 0.2, "af2");
    
    is($msg->c_ic(), 7.450580596923828e-09, "c_ic");
    
    is($msg->c_is(), -1.1548399925231934e-07, "c_is");
    
    is($msg->c_rc(), 308.625, "c_rc");
    
    is($msg->c_rs(), -52.3125, "c_rs");
    
    is($msg->c_uc(), -2.7436763048171997e-06, "c_uc");
    
    is($msg->c_us(), 3.1366944313049316e-06, "c_us");
    
    is($msg->dn(), 5.694522914022375e-09, "dn");
    
    is($msg->ecc(), 0.007072207052260637, "ecc");
    
    is($msg->healthy(), 0, "healthy");
    
    is($msg->inc(), 0.9341514480259797, "inc");
    
    is($msg->inc_dot(), -4.035882396415757e-11, "inc_dot");
    
    is($msg->iodc(), 45, "iodc");
    
    is($msg->iode(), 45, "iode");
    
    is($msg->m0(), -0.02200078842114688, "m0");
    
    is($msg->omega0(), -1.8731818448797617, "omega0");
    
    is($msg->omegadot(), -8.903585155774196e-09, "omegadot");
    
    is($msg->reserved(), 0, "reserved");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":22}})), "sid");
    
    is($msg->sqrta(), 5153.550029754639, "sqrta");
    
    is($msg->tgd(), -1.7695128917694092e-08, "tgd");
    
    is($msg->toc_tow(), 446384.2, "toc_tow");
    
    is($msg->toc_wn(), 2154, "toc_wn");
    
    is($msg->toe_tow(), 446384.2, "toe_tow");
    
    is($msg->toe_wn(), 2154, "toe_wn");
    
    is($msg->valid(), 1, "valid");
    
    is($msg->w(), -0.9893036629599647, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":-0.0006315018981695175,"af1":8.981260180007666e-12,"af2":0.2,"c_ic":7.450580596923828e-09,"c_is":-1.1548399925231934e-07,"c_rc":308.625,"c_rs":-52.3125,"c_uc":-2.7436763048171997e-06,"c_us":3.1366944313049316e-06,"crc":43543,"dn":5.694522914022375e-09,"ecc":0.007072207052260637,"healthy":0,"inc":0.9341514480259797,"inc_dot":-4.035882396415757e-11,"iodc":45,"iode":45,"length":185,"m0":-0.02200078842114688,"msg_type":71,"omega0":-1.8731818448797617,"omegadot":-8.903585155774196e-09,"payload":"AAAAAAAAU74AAAAAAChKwAAAAAAASnNAAAAAAAAEx74AAAAAAFDKPgAAAAAAAEA+AAAAAAAAf75y2GC0MXU4Po4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/3S9k4P8vxr0AAAAAbLFEvwAAAAAAwKM9mpmZmZmZyT/NzMzMwD4bQWoIzczMzMA+G0FqCAEAFgAAAC0tAAAAAAA=","preamble":85,"reserved":0,"sender":1219,"sid":{"code":0,"reserved":0,"sat":22},"sqrta":5153.550029754639,"tgd":-1.7695128917694092e-08,"toc_tow":446384.2,"toc_wn":2154,"toe_tow":446384.2,"toe_wn":2154,"valid":1,"w":-0.9893036629599647}})), "raw_json");
}
test_auto_check_sbp_observation_msg_ephemeris_dep_c_1();

done_testing();