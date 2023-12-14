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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDepB.yaml
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
sub test_auto_check_sbp_tracking_msg_tracking_state_dep_b_1() {
    my $buf = decode_base64("VRMA8vH8c7fjP0SaAbdF/695K94zQyNFTvAFNRQz0zZFmYLtQpsz40dFNfKIob7NvAZGmX3/jpWa2bhF+GZfH0yaIalFg3ONGwya4chF0CyTJxczA0JF7Z/7McszY2ZFRtZXgM6aebpFDs5v2hOaealF2GLRNgKaGdtDyIVjByJmxuhEmytVhy6asapFmwNTq8ma8ehFeSvFEBOa8d5FgPU1P7Azc0JFJBQ9mTOaSYZFLlJ0jBYzkyVFsUOSYI/NTGtE3DOgyftmZsBEqMICodxmZrRERQgJfbJmRoZEuRSHuqszowRFEnybVarN0A1GOfTO/7qaaZVFpcddta8zQ0BFBhw=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1c06, "crc");
    
    is($msg->{'length'}, 252, "length");
    
    is($msg->{'msg_type'}, 0x13, "msg_type");
    
    is($msg->{'payload'}, "c7fjP0SaAbdF/695K94zQyNFTvAFNRQz0zZFmYLtQpsz40dFNfKIob7NvAZGmX3/jpWa2bhF+GZfH0yaIalFg3ONGwya4chF0CyTJxczA0JF7Z/7McszY2ZFRtZXgM6aebpFDs5v2hOaealF2GLRNgKaGdtDyIVjByJmxuhEmytVhy6asapFmwNTq8ma8ehFeSvFEBOa8d5FgPU1P7Azc0JFJBQ9mTOaSYZFLlJ0jBYzkyVFsUOSYI/NTGtE3DOgyftmZsBEqMICodxmZrRERQgJfbJmRoZEuRSHuqszowRFEnybVarN0A1GOfTO/7qaaZVFpcddta8zQ0BF", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf1f2, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":5856.2001953125,"sid":{"code":63,"reserved":68,"sat":58295},"state":115},{"cn0":2612.199951171875,"sid":{"code":43,"reserved":222,"sat":31151},"state":255},{"cn0":2925.199951171875,"sid":{"code":53,"reserved":20,"sat":1520},"state":78},{"cn0":3198.199951171875,"sid":{"code":66,"reserved":155,"sat":60802},"state":153},{"cn0":8623.2001953125,"sid":{"code":161,"reserved":190,"sat":35058},"state":53},{"cn0":5915.2001953125,"sid":{"code":142,"reserved":149,"sat":65405},"state":153},{"cn0":5412.2001953125,"sid":{"code":31,"reserved":76,"sat":24422},"state":248},{"cn0":6428.2001953125,"sid":{"code":27,"reserved":12,"sat":36211},"state":131},{"cn0":3104.199951171875,"sid":{"code":39,"reserved":23,"sat":37676},"state":208},{"cn0":3686.199951171875,"sid":{"code":49,"reserved":203,"sat":64415},"state":237},{"cn0":5967.2001953125,"sid":{"code":128,"reserved":206,"sat":22486},"state":70},{"cn0":5423.2001953125,"sid":{"code":218,"reserved":19,"sat":28622},"state":14},{"cn0":438.20001220703125,"sid":{"code":54,"reserved":2,"sat":53602},"state":216},{"cn0":1862.199951171875,"sid":{"code":7,"reserved":34,"sat":25477},"state":200},{"cn0":5462.2001953125,"sid":{"code":135,"reserved":46,"sat":21803},"state":155},{"cn0":7454.2001953125,"sid":{"code":171,"reserved":201,"sat":21251},"state":155},{"cn0":7134.2001953125,"sid":{"code":16,"reserved":19,"sat":50475},"state":121},{"cn0":3111.199951171875,"sid":{"code":63,"reserved":176,"sat":13813},"state":128},{"cn0":4297.2001953125,"sid":{"code":153,"reserved":51,"sat":15636},"state":36},{"cn0":2649.199951171875,"sid":{"code":140,"reserved":22,"sat":29778},"state":46},{"cn0":941.2000122070312,"sid":{"code":96,"reserved":143,"sat":37443},"state":177},{"cn0":1539.199951171875,"sid":{"code":201,"reserved":251,"sat":41011},"state":220},{"cn0":1443.199951171875,"sid":{"code":161,"reserved":220,"sat":706},"state":168},{"cn0":1074.199951171875,"sid":{"code":125,"reserved":178,"sat":2312},"state":69},{"cn0":2122.199951171875,"sid":{"code":186,"reserved":171,"sat":34580},"state":185},{"cn0":9076.2001953125,"sid":{"code":85,"reserved":170,"sat":39804},"state":18},{"cn0":4781.2001953125,"sid":{"code":255,"reserved":186,"sat":52980},"state":57},{"cn0":3076.199951171875,"sid":{"code":181,"reserved":175,"sat":24007},"state":165}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":7174,"length":252,"msg_type":19,"payload":"c7fjP0SaAbdF/695K94zQyNFTvAFNRQz0zZFmYLtQpsz40dFNfKIob7NvAZGmX3/jpWa2bhF+GZfH0yaIalFg3ONGwya4chF0CyTJxczA0JF7Z/7McszY2ZFRtZXgM6aebpFDs5v2hOaealF2GLRNgKaGdtDyIVjByJmxuhEmytVhy6asapFmwNTq8ma8ehFeSvFEBOa8d5FgPU1P7Azc0JFJBQ9mTOaSYZFLlJ0jBYzkyVFsUOSYI/NTGtE3DOgyftmZsBEqMICodxmZrRERQgJfbJmRoZEuRSHuqszowRFEnybVarN0A1GOfTO/7qaaZVFpcddta8zQ0BF","preamble":85,"sender":61938,"states":[{"cn0":5856.2001953125,"sid":{"code":63,"reserved":68,"sat":58295},"state":115},{"cn0":2612.199951171875,"sid":{"code":43,"reserved":222,"sat":31151},"state":255},{"cn0":2925.199951171875,"sid":{"code":53,"reserved":20,"sat":1520},"state":78},{"cn0":3198.199951171875,"sid":{"code":66,"reserved":155,"sat":60802},"state":153},{"cn0":8623.2001953125,"sid":{"code":161,"reserved":190,"sat":35058},"state":53},{"cn0":5915.2001953125,"sid":{"code":142,"reserved":149,"sat":65405},"state":153},{"cn0":5412.2001953125,"sid":{"code":31,"reserved":76,"sat":24422},"state":248},{"cn0":6428.2001953125,"sid":{"code":27,"reserved":12,"sat":36211},"state":131},{"cn0":3104.199951171875,"sid":{"code":39,"reserved":23,"sat":37676},"state":208},{"cn0":3686.199951171875,"sid":{"code":49,"reserved":203,"sat":64415},"state":237},{"cn0":5967.2001953125,"sid":{"code":128,"reserved":206,"sat":22486},"state":70},{"cn0":5423.2001953125,"sid":{"code":218,"reserved":19,"sat":28622},"state":14},{"cn0":438.20001220703125,"sid":{"code":54,"reserved":2,"sat":53602},"state":216},{"cn0":1862.199951171875,"sid":{"code":7,"reserved":34,"sat":25477},"state":200},{"cn0":5462.2001953125,"sid":{"code":135,"reserved":46,"sat":21803},"state":155},{"cn0":7454.2001953125,"sid":{"code":171,"reserved":201,"sat":21251},"state":155},{"cn0":7134.2001953125,"sid":{"code":16,"reserved":19,"sat":50475},"state":121},{"cn0":3111.199951171875,"sid":{"code":63,"reserved":176,"sat":13813},"state":128},{"cn0":4297.2001953125,"sid":{"code":153,"reserved":51,"sat":15636},"state":36},{"cn0":2649.199951171875,"sid":{"code":140,"reserved":22,"sat":29778},"state":46},{"cn0":941.2000122070312,"sid":{"code":96,"reserved":143,"sat":37443},"state":177},{"cn0":1539.199951171875,"sid":{"code":201,"reserved":251,"sat":41011},"state":220},{"cn0":1443.199951171875,"sid":{"code":161,"reserved":220,"sat":706},"state":168},{"cn0":1074.199951171875,"sid":{"code":125,"reserved":178,"sat":2312},"state":69},{"cn0":2122.199951171875,"sid":{"code":186,"reserved":171,"sat":34580},"state":185},{"cn0":9076.2001953125,"sid":{"code":85,"reserved":170,"sat":39804},"state":18},{"cn0":4781.2001953125,"sid":{"code":255,"reserved":186,"sat":52980},"state":57},{"cn0":3076.199951171875,"sid":{"code":181,"reserved":175,"sat":24007},"state":165}]}})), "raw_json");
}
test_auto_check_sbp_tracking_msg_tracking_state_dep_b_1();

done_testing();