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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisDepB.yaml
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
sub test_auto_check_sbp_observation_msg_ephemeris_dep_b_1() {
    my $buf = decode_base64("VUYAwwSwAAAAAAAAPL4AAAAAALpSwAAAAAAATG1AAAAAAACE0L4AAAAAAP7cPgAAAAAAAHE+AAAAAAAAhb4cJBlR3/40Ptx02CchvQNAAAAAnLHMhj8AAKDctiG0QJjhwCz+TO6/KZYYApScQb78WncwD9fwP3x/c17QEO4/pXM0SmGn9r0AAAAAwLTlvgAAAAAAAHC9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAwDhnA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9ce1, "crc");
    
    is($msg->{'length'}, 176, "length");
    
    is($msg->{'msg_type'}, 0x46, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAAPL4AAAAAALpSwAAAAAAATG1AAAAAAACE0L4AAAAAAP7cPgAAAAAAAHE+AAAAAAAAhb4cJBlR3/40Ptx02CchvQNAAAAAnLHMhj8AAKDctiG0QJjhwCz+TO6/KZYYApScQb78WncwD9fwP3x/c17QEO4/pXM0SmGn9r0AAAAAwLTlvgAAAAAAAHC9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAwA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), -1.035025343298912e-05, "af0");
    
    is($msg->af1(), -9.094947017729282e-13, "af1");
    
    is($msg->af2(), 0.0, "af2");
    
    is($msg->c_ic(), 6.332993507385254e-08, "c_ic");
    
    is($msg->c_is(), -1.564621925354004e-07, "c_is");
    
    is($msg->c_rc(), 234.375, "c_rc");
    
    is($msg->c_rs(), -74.90625, "c_rs");
    
    is($msg->c_uc(), -3.937631845474243e-06, "c_uc");
    
    is($msg->c_us(), 6.9122761487960815e-06, "c_us");
    
    is($msg->dn(), 4.8884179079418005e-09, "dn");
    
    is($msg->ecc(), 0.011132609914056957, "ecc");
    
    is($msg->healthy(), 1, "healthy");
    
    is($msg->inc(), 0.9395524830579087, "inc");
    
    is($msg->inc_dot(), -3.296565886629854e-10, "inc_dot");
    
    is($msg->iode(), 0, "iode");
    
    is($msg->m0(), 2.467348395627239, "m0");
    
    is($msg->omega0(), -0.9468985437479658, "omega0");
    
    is($msg->omegadot(), -8.201055892610478e-09, "omegadot");
    
    is($msg->prn(), 3, "prn");
    
    is($msg->sqrta(), 5153.714303970337, "sqrta");
    
    is($msg->tgd(), -6.51925802230835e-09, "tgd");
    
    is($msg->toc_tow(), 410400.0, "toc_tow");
    
    is($msg->toc_wn(), 1838, "toc_wn");
    
    is($msg->toe_tow(), 410400.0, "toe_tow");
    
    is($msg->toe_wn(), 1838, "toe_wn");
    
    is($msg->valid(), 1, "valid");
    
    is($msg->w(), 1.0525047200405302, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":-1.035025343298912e-05,"af1":-9.094947017729282e-13,"af2":0.0,"c_ic":6.332993507385254e-08,"c_is":-1.564621925354004e-07,"c_rc":234.375,"c_rs":-74.90625,"c_uc":-3.937631845474243e-06,"c_us":6.9122761487960815e-06,"crc":40161,"dn":4.8884179079418005e-09,"ecc":0.011132609914056957,"healthy":1,"inc":0.9395524830579087,"inc_dot":-3.296565886629854e-10,"iode":0,"length":176,"m0":2.467348395627239,"msg_type":70,"omega0":-0.9468985437479658,"omegadot":-8.201055892610478e-09,"payload":"AAAAAAAAPL4AAAAAALpSwAAAAAAATG1AAAAAAACE0L4AAAAAAP7cPgAAAAAAAHE+AAAAAAAAhb4cJBlR3/40Ptx02CchvQNAAAAAnLHMhj8AAKDctiG0QJjhwCz+TO6/KZYYApScQb78WncwD9fwP3x/c17QEO4/pXM0SmGn9r0AAAAAwLTlvgAAAAAAAHC9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAwA=","preamble":85,"prn":3,"sender":1219,"sqrta":5153.714303970337,"tgd":-6.51925802230835e-09,"toc_tow":410400.0,"toc_wn":1838,"toe_tow":410400.0,"toe_wn":1838,"valid":1,"w":1.0525047200405302}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_ephemeris_dep_b_2() {
    my $buf = decode_base64("VUYAwwSwAAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQC0FQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x15b4, "crc");
    
    is($msg->{'length'}, 176, "length");
    
    is($msg->{'msg_type'}, 0x46, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), 7.384549826383591e-05, "af0");
    
    is($msg->af1(), -2.8421709430404007e-12, "af1");
    
    is($msg->af2(), 0.0, "af2");
    
    is($msg->c_ic(), 1.341104507446289e-07, "c_ic");
    
    is($msg->c_is(), 1.1920928955078125e-07, "c_is");
    
    is($msg->c_rc(), 315.78125, "c_rc");
    
    is($msg->c_rs(), 36.5625, "c_rs");
    
    is($msg->c_uc(), 2.0638108253479004e-06, "c_uc");
    
    is($msg->c_us(), 3.4142285585403442e-06, "c_us");
    
    is($msg->dn(), 4.86198823561129e-09, "dn");
    
    is($msg->ecc(), 0.007922741584479809, "ecc");
    
    is($msg->healthy(), 1, "healthy");
    
    is($msg->inc(), 0.9669012918227122, "inc");
    
    is($msg->inc_dot(), 2.6251093463412166e-10, "inc_dot");
    
    is($msg->iode(), 0, "iode");
    
    is($msg->m0(), -1.588160855720083, "m0");
    
    is($msg->omega0(), 1.237919941568746, "omega0");
    
    is($msg->omegadot(), -8.295702692172441e-09, "omegadot");
    
    is($msg->prn(), 13, "prn");
    
    is($msg->sqrta(), 5153.57085609436, "sqrta");
    
    is($msg->tgd(), -9.313225746154785e-09, "tgd");
    
    is($msg->toc_tow(), 410400.0, "toc_tow");
    
    is($msg->toc_wn(), 1838, "toc_wn");
    
    is($msg->toe_tow(), 410400.0, "toe_tow");
    
    is($msg->toe_wn(), 1838, "toe_wn");
    
    is($msg->valid(), 1, "valid");
    
    is($msg->w(), -1.9736022837941165, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":7.384549826383591e-05,"af1":-2.8421709430404007e-12,"af2":0.0,"c_ic":1.341104507446289e-07,"c_is":1.1920928955078125e-07,"c_rc":315.78125,"c_rs":36.5625,"c_uc":2.0638108253479004e-06,"c_us":3.4142285585403442e-06,"crc":5556,"dn":4.86198823561129e-09,"ecc":0.007922741584479809,"healthy":1,"inc":0.9669012918227122,"inc_dot":2.6251093463412166e-10,"iode":0,"length":176,"m0":-1.588160855720083,"msg_type":70,"omega0":1.237919941568746,"omegadot":-8.295702692172441e-09,"payload":"AAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQA=","preamble":85,"prn":13,"sender":1219,"sqrta":5153.57085609436,"tgd":-9.313225746154785e-09,"toc_tow":410400.0,"toc_wn":1838,"toe_tow":410400.0,"toe_wn":1838,"valid":1,"w":-1.9736022837941165}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_ephemeris_dep_b_3() {
    my $buf = decode_base64("VUYAwwSwAAAAAAAAOD4AAAAAAChRwAAAAAAAgW1AAAAAAAAczb4AAAAAAEzfPgAAAAAAAGm+AAAAAAAAXL6God//8yszPpKwcY7qpAVAAAAAOK+McD8AAMBaqyG0QCQm7f/IoO2/zFw/mjFbQb59XvuEND3YPwKLHBvnx+4/fLcEtMIe970AAAAAAGjevgAAAAAAAGA9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAADemA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x98de, "crc");
    
    is($msg->{'length'}, 176, "length");
    
    is($msg->{'msg_type'}, 0x46, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAAOD4AAAAAAChRwAAAAAAAgW1AAAAAAAAczb4AAAAAAEzfPgAAAAAAAGm+AAAAAAAAXL6God//8yszPpKwcY7qpAVAAAAAOK+McD8AAMBaqyG0QCQm7f/IoO2/zFw/mjFbQb59XvuEND3YPwKLHBvnx+4/fLcEtMIe970AAAAAAGjevgAAAAAAAGA9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), -7.249414920806885e-06, "af0");
    
    is($msg->af1(), 4.547473508864641e-13, "af1");
    
    is($msg->af2(), 0.0, "af2");
    
    is($msg->c_ic(), -4.6566128730773926e-08, "c_ic");
    
    is($msg->c_is(), -2.60770320892334e-08, "c_is");
    
    is($msg->c_rc(), 236.03125, "c_rc");
    
    is($msg->c_rs(), -68.625, "c_rs");
    
    is($msg->c_uc(), -3.470107913017273e-06, "c_uc");
    
    is($msg->c_us(), 7.461756467819214e-06, "c_us");
    
    is($msg->dn(), 4.4637573619826565e-09, "dn");
    
    is($msg->ecc(), 0.004040417145006359, "ecc");
    
    is($msg->healthy(), 1, "healthy");
    
    is($msg->inc(), 0.9619021920701416, "inc");
    
    is($msg->inc_dot(), -3.3644258561271105e-10, "inc_dot");
    
    is($msg->iode(), 0, "iode");
    
    is($msg->m0(), 2.7055255058713295, "m0");
    
    is($msg->omega0(), -0.9258770941316397, "omega0");
    
    is($msg->omegadot(), -8.082122367123182e-09, "omegadot");
    
    is($msg->prn(), 0, "prn");
    
    is($msg->sqrta(), 5153.669353485107, "sqrta");
    
    is($msg->tgd(), 5.587935447692871e-09, "tgd");
    
    is($msg->toc_tow(), 410400.0, "toc_tow");
    
    is($msg->toc_wn(), 1838, "toc_wn");
    
    is($msg->toe_tow(), 410400.0, "toe_tow");
    
    is($msg->toe_wn(), 1838, "toe_wn");
    
    is($msg->valid(), 1, "valid");
    
    is($msg->w(), 0.37873566614641857, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":-7.249414920806885e-06,"af1":4.547473508864641e-13,"af2":0.0,"c_ic":-4.6566128730773926e-08,"c_is":-2.60770320892334e-08,"c_rc":236.03125,"c_rs":-68.625,"c_uc":-3.470107913017273e-06,"c_us":7.461756467819214e-06,"crc":39134,"dn":4.4637573619826565e-09,"ecc":0.004040417145006359,"healthy":1,"inc":0.9619021920701416,"inc_dot":-3.3644258561271105e-10,"iode":0,"length":176,"m0":2.7055255058713295,"msg_type":70,"omega0":-0.9258770941316397,"omegadot":-8.082122367123182e-09,"payload":"AAAAAAAAOD4AAAAAAChRwAAAAAAAgW1AAAAAAAAczb4AAAAAAEzfPgAAAAAAAGm+AAAAAAAAXL6God//8yszPpKwcY7qpAVAAAAAOK+McD8AAMBaqyG0QCQm7f/IoO2/zFw/mjFbQb59XvuEND3YPwKLHBvnx+4/fLcEtMIe970AAAAAAGjevgAAAAAAAGA9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAAA=","preamble":85,"prn":0,"sender":1219,"sqrta":5153.669353485107,"tgd":5.587935447692871e-09,"toc_tow":410400.0,"toc_wn":1838,"toe_tow":410400.0,"toe_wn":1838,"valid":1,"w":0.37873566614641857}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_ephemeris_dep_b_4() {
    my $buf = decode_base64("VUYAwwSwAAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQC0FQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x15b4, "crc");
    
    is($msg->{'length'}, 176, "length");
    
    is($msg->{'msg_type'}, 0x46, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), 7.384549826383591e-05, "af0");
    
    is($msg->af1(), -2.8421709430404007e-12, "af1");
    
    is($msg->af2(), 0.0, "af2");
    
    is($msg->c_ic(), 1.341104507446289e-07, "c_ic");
    
    is($msg->c_is(), 1.1920928955078125e-07, "c_is");
    
    is($msg->c_rc(), 315.78125, "c_rc");
    
    is($msg->c_rs(), 36.5625, "c_rs");
    
    is($msg->c_uc(), 2.0638108253479004e-06, "c_uc");
    
    is($msg->c_us(), 3.4142285585403442e-06, "c_us");
    
    is($msg->dn(), 4.86198823561129e-09, "dn");
    
    is($msg->ecc(), 0.007922741584479809, "ecc");
    
    is($msg->healthy(), 1, "healthy");
    
    is($msg->inc(), 0.9669012918227122, "inc");
    
    is($msg->inc_dot(), 2.6251093463412166e-10, "inc_dot");
    
    is($msg->iode(), 0, "iode");
    
    is($msg->m0(), -1.588160855720083, "m0");
    
    is($msg->omega0(), 1.237919941568746, "omega0");
    
    is($msg->omegadot(), -8.295702692172441e-09, "omegadot");
    
    is($msg->prn(), 13, "prn");
    
    is($msg->sqrta(), 5153.57085609436, "sqrta");
    
    is($msg->tgd(), -9.313225746154785e-09, "tgd");
    
    is($msg->toc_tow(), 410400.0, "toc_tow");
    
    is($msg->toc_wn(), 1838, "toc_wn");
    
    is($msg->toe_tow(), 410400.0, "toe_tow");
    
    is($msg->toe_wn(), 1838, "toe_wn");
    
    is($msg->valid(), 1, "valid");
    
    is($msg->w(), -1.9736022837941165, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":7.384549826383591e-05,"af1":-2.8421709430404007e-12,"af2":0.0,"c_ic":1.341104507446289e-07,"c_is":1.1920928955078125e-07,"c_rc":315.78125,"c_rs":36.5625,"c_uc":2.0638108253479004e-06,"c_us":3.4142285585403442e-06,"crc":5556,"dn":4.86198823561129e-09,"ecc":0.007922741584479809,"healthy":1,"inc":0.9669012918227122,"inc_dot":2.6251093463412166e-10,"iode":0,"length":176,"m0":-1.588160855720083,"msg_type":70,"omega0":1.237919941568746,"omegadot":-8.295702692172441e-09,"payload":"AAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQA=","preamble":85,"prn":13,"sender":1219,"sqrta":5153.57085609436,"tgd":-9.313225746154785e-09,"toc_tow":410400.0,"toc_wn":1838,"toe_tow":410400.0,"toe_wn":1838,"valid":1,"w":-1.9736022837941165}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_ephemeris_dep_b_5() {
    my $buf = decode_base64("VUYAwwSwAAAAAACAVb4AAAAAAJxFQAAAAACAE3NAAAAAAACgwT4AAAAAAJjPPgAAAAAAAGG+AAAAAADAi74aGg2VEJg2PmgHLtZLVAXAAAAAgOZShD8AAKD8oiG0QEkGgjbZq/I/UeCje+4qQr7OK41D850FwHGzmbsrXO4//uwfK+Cd9D0AAAAA6AQavwAAAAAAAIa9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBFgBjPQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3d63, "crc");
    
    is($msg->{'length'}, 176, "length");
    
    is($msg->{'msg_type'}, 0x46, "msg_type");
    
    is($msg->{'payload'}, "AAAAAACAVb4AAAAAAJxFQAAAAACAE3NAAAAAAACgwT4AAAAAAJjPPgAAAAAAAGG+AAAAAADAi74aGg2VEJg2PmgHLtZLVAXAAAAAgOZShD8AAKD8oiG0QEkGgjbZq/I/UeCje+4qQr7OK41D850FwHGzmbsrXO4//uwfK+Cd9D0AAAAA6AQavwAAAAAAAIa9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBFgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), -9.925523772835732e-05, "af0");
    
    is($msg->af1(), -2.5011104298755527e-12, "af1");
    
    is($msg->af2(), 0.0, "af2");
    
    is($msg->c_ic(), -3.166496753692627e-08, "c_ic");
    
    is($msg->c_is(), -2.0675361156463623e-07, "c_is");
    
    is($msg->c_rc(), 305.21875, "c_rc");
    
    is($msg->c_rs(), 43.21875, "c_rs");
    
    is($msg->c_uc(), 2.1010637283325195e-06, "c_uc");
    
    is($msg->c_us(), 3.766268491744995e-06, "c_us");
    
    is($msg->dn(), 5.26057626697412e-09, "dn");
    
    is($msg->ecc(), 0.009923744946718216, "ecc");
    
    is($msg->healthy(), 1, "healthy");
    
    is($msg->inc(), 0.9487513221807672, "inc");
    
    is($msg->inc_dot(), 3.000124967247105e-10, "inc_dot");
    
    is($msg->iode(), 0, "iode");
    
    is($msg->m0(), -2.666160271911327, "m0");
    
    is($msg->omega0(), 1.1669551972594425, "omega0");
    
    is($msg->omegadot(), -8.45999524990264e-09, "omegadot");
    
    is($msg->prn(), 22, "prn");
    
    is($msg->sqrta(), 5153.636667251587, "sqrta");
    
    is($msg->tgd(), -2.0023435354232788e-08, "tgd");
    
    is($msg->toc_tow(), 410400.0, "toc_tow");
    
    is($msg->toc_wn(), 1838, "toc_wn");
    
    is($msg->toe_tow(), 410400.0, "toe_tow");
    
    is($msg->toe_wn(), 1838, "toe_wn");
    
    is($msg->valid(), 1, "valid");
    
    is($msg->w(), -2.7021241452652935, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":-9.925523772835732e-05,"af1":-2.5011104298755527e-12,"af2":0.0,"c_ic":-3.166496753692627e-08,"c_is":-2.0675361156463623e-07,"c_rc":305.21875,"c_rs":43.21875,"c_uc":2.1010637283325195e-06,"c_us":3.766268491744995e-06,"crc":15715,"dn":5.26057626697412e-09,"ecc":0.009923744946718216,"healthy":1,"inc":0.9487513221807672,"inc_dot":3.000124967247105e-10,"iode":0,"length":176,"m0":-2.666160271911327,"msg_type":70,"omega0":1.1669551972594425,"omegadot":-8.45999524990264e-09,"payload":"AAAAAACAVb4AAAAAAJxFQAAAAACAE3NAAAAAAACgwT4AAAAAAJjPPgAAAAAAAGG+AAAAAADAi74aGg2VEJg2PmgHLtZLVAXAAAAAgOZShD8AAKD8oiG0QEkGgjbZq/I/UeCje+4qQr7OK41D850FwHGzmbsrXO4//uwfK+Cd9D0AAAAA6AQavwAAAAAAAIa9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBFgA=","preamble":85,"prn":22,"sender":1219,"sqrta":5153.636667251587,"tgd":-2.0023435354232788e-08,"toc_tow":410400.0,"toc_wn":1838,"toe_tow":410400.0,"toe_wn":1838,"valid":1,"w":-2.7021241452652935}})), "raw_json");
}
sub test_auto_check_sbp_observation_msg_ephemeris_dep_b_6() {
    my $buf = decode_base64("VUYAwwSwAAAAAAAATb4AAAAAAHpTwAAAAAAA6W5AAAAAAAA8z74AAAAAABzePgAAAAAAgHg+AAAAAAAAbD4K5reM1uYyPjZWxKT8Cv8/AAAAJPe/gD8AAKAFwSG0QLqKUYFY7wFAXtJ4qmoZQb5n1SCb48Lgv5wvaF1lN+8/xFNk/jM2BL4AAAAAMvI0PwAAAAAAAHK9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBHgCqIQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x21aa, "crc");
    
    is($msg->{'length'}, 176, "length");
    
    is($msg->{'msg_type'}, 0x46, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAATb4AAAAAAHpTwAAAAAAA6W5AAAAAAAA8z74AAAAAABzePgAAAAAAgHg+AAAAAAAAbD4K5reM1uYyPjZWxKT8Cv8/AAAAJPe/gD8AAKAFwSG0QLqKUYFY7wFAXtJ4qmoZQb5n1SCb48Lgv5wvaF1lN+8/xFNk/jM2BL4AAAAAMvI0PwAAAAAAAHK9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBHgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), 0.0003196117468178272, "af0");
    
    is($msg->af1(), -1.0231815394945443e-12, "af1");
    
    is($msg->af2(), 0.0, "af2");
    
    is($msg->c_ic(), 9.12696123123169e-08, "c_ic");
    
    is($msg->c_is(), 5.21540641784668e-08, "c_is");
    
    is($msg->c_rc(), 247.28125, "c_rc");
    
    is($msg->c_rs(), -77.90625, "c_rs");
    
    is($msg->c_uc(), -3.723427653312683e-06, "c_uc");
    
    is($msg->c_us(), 7.178634405136108e-06, "c_us");
    
    is($msg->dn(), 4.400897600764146e-09, "dn");
    
    is($msg->ecc(), 0.008178644930012524, "ecc");
    
    is($msg->healthy(), 1, "healthy");
    
    is($msg->inc(), 0.9755122017245301, "inc");
    
    is($msg->inc_dot(), -5.882387882209502e-10, "inc_dot");
    
    is($msg->iode(), 0, "iode");
    
    is($msg->m0(), 1.9401823459824192, "m0");
    
    is($msg->omega0(), 2.241868028927766, "omega0");
    
    is($msg->omegadot(), -7.962474526167494e-09, "omegadot");
    
    is($msg->prn(), 30, "prn");
    
    is($msg->sqrta(), 5153.7539920806885, "sqrta");
    
    is($msg->tgd(), -1.3504177331924438e-08, "tgd");
    
    is($msg->toc_tow(), 410400.0, "toc_tow");
    
    is($msg->toc_wn(), 1838, "toc_wn");
    
    is($msg->toe_tow(), 410400.0, "toe_tow");
    
    is($msg->toe_wn(), 1838, "toe_wn");
    
    is($msg->valid(), 1, "valid");
    
    is($msg->w(), -0.5237901716088061, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":0.0003196117468178272,"af1":-1.0231815394945443e-12,"af2":0.0,"c_ic":9.12696123123169e-08,"c_is":5.21540641784668e-08,"c_rc":247.28125,"c_rs":-77.90625,"c_uc":-3.723427653312683e-06,"c_us":7.178634405136108e-06,"crc":8618,"dn":4.400897600764146e-09,"ecc":0.008178644930012524,"healthy":1,"inc":0.9755122017245301,"inc_dot":-5.882387882209502e-10,"iode":0,"length":176,"m0":1.9401823459824192,"msg_type":70,"omega0":2.241868028927766,"omegadot":-7.962474526167494e-09,"payload":"AAAAAAAATb4AAAAAAHpTwAAAAAAA6W5AAAAAAAA8z74AAAAAABzePgAAAAAAgHg+AAAAAAAAbD4K5reM1uYyPjZWxKT8Cv8/AAAAJPe/gD8AAKAFwSG0QLqKUYFY7wFAXtJ4qmoZQb5n1SCb48Lgv5wvaF1lN+8/xFNk/jM2BL4AAAAAMvI0PwAAAAAAAHK9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBHgA=","preamble":85,"prn":30,"sender":1219,"sqrta":5153.7539920806885,"tgd":-1.3504177331924438e-08,"toc_tow":410400.0,"toc_wn":1838,"toe_tow":410400.0,"toe_wn":1838,"valid":1,"w":-0.5237901716088061}})), "raw_json");
}
test_auto_check_sbp_observation_msg_ephemeris_dep_b_1();
test_auto_check_sbp_observation_msg_ephemeris_dep_b_2();
test_auto_check_sbp_observation_msg_ephemeris_dep_b_3();
test_auto_check_sbp_observation_msg_ephemeris_dep_b_4();
test_auto_check_sbp_observation_msg_ephemeris_dep_b_5();
test_auto_check_sbp_observation_msg_ephemeris_dep_b_6();

done_testing();
