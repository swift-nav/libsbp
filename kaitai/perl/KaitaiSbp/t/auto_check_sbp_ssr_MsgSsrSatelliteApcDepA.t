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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApcDepA.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_satellite_apc_dep_a_1() {
    my $buf = decode_base64("VQQGOBPgy6nwTgTVq/7W1AQIIR9QFQRp4SeLfJUwD9bFjSAhh5aUezGHYSdaFKnvL5mvI5GRe8ICZkqVX6vu+Qftqn1qnlO8tcIbVOKOe03Z+EPXgXKKGfAKOEw9odgWta4hDfzs5sSA1+/qs9ws1DksrTEkifjrYXCdixpzwB9Vf+RR/Nv5bpMIodfUtBlTkPcMG8etShcE72ff3Itbf9ZWMMvkYy1Tnwv6h6oq2cfpKqpOzikrUfdjxpAChALg3JQ6VYrSyJ4HnkMuyIR28Q0lPmv9vohCCVSbVrQpxCh3ZfzfkJkyDQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x0d32, "crc");
    
    is($msg->{'length'}, 224, "length");
    
    is($msg->{'msg_type'}, 0x604, "msg_type");
    
    is($msg->{'payload'}, "y6nwTgTVq/7W1AQIIR9QFQRp4SeLfJUwD9bFjSAhh5aUezGHYSdaFKnvL5mvI5GRe8ICZkqVX6vu+Qftqn1qnlO8tcIbVOKOe03Z+EPXgXKKGfAKOEw9odgWta4hDfzs5sSA1+/qs9ws1DksrTEkifjrYXCdixpzwB9Vf+RR/Nv5bpMIodfUtBlTkPcMG8etShcE72ff3Itbf9ZWMMvkYy1Tnwv6h6oq2cfpKqpOzikrUfdjxpAChALg3JQ6VYrSyJ4HnkMuyIR28Q0lPmv9vohCCVSbVrQpxCh3ZfzfkJk=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1338, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->apc()), $json->encode($json->decode(q{[{"pco":[-21547,-10498,1236],"pcv":[8,33,31,80,21,4,105,-31,39,-117,124,-107,48,15,-42,-59,-115,32,33,-121,-106],"sat_info":240,"sid":{"code":169,"sat":203},"svn":1102},{"pco":[23079,-22252,12271],"pcv":[-103,-81,35,-111,-111,123,-62,2,102,74,-107,95,-85,-18,-7,7,-19,-86,125,106,-98],"sat_info":49,"sid":{"code":123,"sat":148},"svn":24967},{"pco":[-7596,31630,-9907],"pcv":[-8,67,-41,-127,114,-118,25,-16,10,56,76,61,-95,-40,22,-75,-82,33,13,-4,-20],"sat_info":181,"sid":{"code":188,"sat":83},"svn":7106},{"pco":[-19478,11484,14804],"pcv":[44,-83,49,36,-119,-8,-21,97,112,-99,-117,26,115,-64,31,85,127,-28,81,-4,-37],"sat_info":128,"sid":{"code":196,"sat":230},"svn":61399},{"pco":[-11049,6580,-28589],"pcv":[-9,12,27,-57,-83,74,23,4,-17,103,-33,-36,-117,91,127,-42,86,48,-53,-28,99],"sat_info":147,"sid":{"code":110,"sat":249},"svn":41224},{"pco":[-21881,-9942,-5689],"pcv":[42,-86,78,-50,41,43,81,-9,99,-58,-112,2,-124,2,-32,-36,-108,58,85,-118,-46],"sat_info":159,"sid":{"code":83,"sat":45},"svn":64011},{"pco":[-14290,30340,3569],"pcv":[37,62,107,-3,-66,-120,66,9,84,-101,86,-76,41,-60,40,119,101,-4,-33,-112,-103],"sat_info":7,"sid":{"code":158,"sat":200},"svn":17310}]})), "apc");

    is($json->encode($msg), $json->encode($json->decode(q{{"apc":[{"pco":[-21547,-10498,1236],"pcv":[8,33,31,80,21,4,105,-31,39,-117,124,-107,48,15,-42,-59,-115,32,33,-121,-106],"sat_info":240,"sid":{"code":169,"sat":203},"svn":1102},{"pco":[23079,-22252,12271],"pcv":[-103,-81,35,-111,-111,123,-62,2,102,74,-107,95,-85,-18,-7,7,-19,-86,125,106,-98],"sat_info":49,"sid":{"code":123,"sat":148},"svn":24967},{"pco":[-7596,31630,-9907],"pcv":[-8,67,-41,-127,114,-118,25,-16,10,56,76,61,-95,-40,22,-75,-82,33,13,-4,-20],"sat_info":181,"sid":{"code":188,"sat":83},"svn":7106},{"pco":[-19478,11484,14804],"pcv":[44,-83,49,36,-119,-8,-21,97,112,-99,-117,26,115,-64,31,85,127,-28,81,-4,-37],"sat_info":128,"sid":{"code":196,"sat":230},"svn":61399},{"pco":[-11049,6580,-28589],"pcv":[-9,12,27,-57,-83,74,23,4,-17,103,-33,-36,-117,91,127,-42,86,48,-53,-28,99],"sat_info":147,"sid":{"code":110,"sat":249},"svn":41224},{"pco":[-21881,-9942,-5689],"pcv":[42,-86,78,-50,41,43,81,-9,99,-58,-112,2,-124,2,-32,-36,-108,58,85,-118,-46],"sat_info":159,"sid":{"code":83,"sat":45},"svn":64011},{"pco":[-14290,30340,3569],"pcv":[37,62,107,-3,-66,-120,66,9,84,-101,86,-76,41,-60,40,119,101,-4,-33,-112,-103],"sat_info":7,"sid":{"code":158,"sat":200},"svn":17310}],"crc":3378,"length":224,"msg_type":1540,"payload":"y6nwTgTVq/7W1AQIIR9QFQRp4SeLfJUwD9bFjSAhh5aUezGHYSdaFKnvL5mvI5GRe8ICZkqVX6vu+Qftqn1qnlO8tcIbVOKOe03Z+EPXgXKKGfAKOEw9odgWta4hDfzs5sSA1+/qs9ws1DksrTEkifjrYXCdixpzwB9Vf+RR/Nv5bpMIodfUtBlTkPcMG8etShcE72ff3Itbf9ZWMMvkYy1Tnwv6h6oq2cfpKqpOzikrUfdjxpAChALg3JQ6VYrSyJ4HnkMuyIR28Q0lPmv9vohCCVSbVrQpxCh3ZfzfkJk=","preamble":85,"sender":4920}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_satellite_apc_dep_a_1();

done_testing();