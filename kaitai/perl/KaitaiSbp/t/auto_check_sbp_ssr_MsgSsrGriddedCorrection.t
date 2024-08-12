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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrection.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_gridded_correction_1() {
    my $buf = decode_base64("VfwFxPn9FQ6XMniFHZeu5Ze9zMRpqniVqSX0TkiMZQKtWEa0NphzTsmhF4eYYj1Lsnjlkjc6qermRay/f5JZlltv4SkRdzSmpng53QwDnEacI38IfzqAN3NQnXqZfBuAYmfMS+6A4pT4PdjQlafgKJC6neNI8GQjDNQHO7BRVhsYm0MrhC3LLAZwt+ewT8L992db4nSUFz7j8B3bzRLyz0hHTyUqsMnKW2lzkjtuLG2At7lDH6VcT720XgeieZzSLwcHza4p8YHSK2W60MPi97vboHjAZqYq9q1eZpzeHiP3QL2JzNwgR97eyfYDGS3773NY2grReEGvg8IprokRRBz9KrIj");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x23b2, "crc");
    
    is($msg->{'length'}, 253, "length");
    
    is($msg->{'msg_type'}, 0x5fc, "msg_type");
    
    is($msg->{'payload'}, "FQ6XMniFHZeu5Ze9zMRpqniVqSX0TkiMZQKtWEa0NphzTsmhF4eYYj1Lsnjlkjc6qermRay/f5JZlltv4SkRdzSmpng53QwDnEacI38IfzqAN3NQnXqZfBuAYmfMS+6A4pT4PdjQlafgKJC6neNI8GQjDNQHO7BRVhsYm0MrhC3LLAZwt+ewT8L992db4nSUFz7j8B3bzRLyz0hHTyUqsMnKW2lzkjtuLG2At7lDH6VcT720XgeieZzSLwcHza4p8YHSK2W60MPi97vboHjAZqYq9q1eZpzeHiP3QL2JzNwgR97eyfYDGS3773NY2grReEGvg8IprokRRBz9Kg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf9c4, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"iod_atmo":170,"num_msgs":48535,"seq_num":50380,"tile_id":12951,"tile_set_id":3605,"time":{"tow":2535294328,"wn":58798},"tropo_quality_indicator":120,"update_interval":105}})), "header");
    
    is($msg->index(), 43413, "index");
    
    is($json->encode($msg->stec_residuals()), $json->encode($json->decode(q{[{"residual":-21246,"stddev":88,"sv_id":{"constellation":101,"sat_id":140}},{"residual":-26570,"stddev":115,"sv_id":{"constellation":180,"sat_id":70}},{"residual":6049,"stddev":135,"sv_id":{"constellation":201,"sat_id":78}},{"residual":19261,"stddev":178,"sv_id":{"constellation":98,"sat_id":152}},{"residual":14226,"stddev":58,"sv_id":{"constellation":229,"sat_id":120}},{"residual":17894,"stddev":172,"sv_id":{"constellation":234,"sat_id":169}},{"residual":22930,"stddev":150,"sv_id":{"constellation":127,"sat_id":191}},{"residual":10721,"stddev":17,"sv_id":{"constellation":111,"sat_id":91}},{"residual":-22874,"stddev":120,"sv_id":{"constellation":52,"sat_id":119}},{"residual":780,"stddev":156,"sv_id":{"constellation":221,"sat_id":57}},{"residual":32547,"stddev":8,"sv_id":{"constellation":156,"sat_id":70}},{"residual":14208,"stddev":115,"sv_id":{"constellation":58,"sat_id":127}},{"residual":-26246,"stddev":124,"sv_id":{"constellation":157,"sat_id":80}},{"residual":26466,"stddev":204,"sv_id":{"constellation":128,"sat_id":27}},{"residual":-7552,"stddev":148,"sv_id":{"constellation":238,"sat_id":75}},{"residual":-12072,"stddev":149,"sv_id":{"constellation":61,"sat_id":248}},{"residual":-28632,"stddev":186,"sv_id":{"constellation":224,"sat_id":167}},{"residual":-4024,"stddev":100,"sv_id":{"constellation":227,"sat_id":157}},{"residual":2004,"stddev":59,"sv_id":{"constellation":12,"sat_id":35}},{"residual":6998,"stddev":24,"sv_id":{"constellation":81,"sat_id":176}},{"residual":-31701,"stddev":45,"sv_id":{"constellation":67,"sat_id":155}},{"residual":28678,"stddev":183,"sv_id":{"constellation":44,"sat_id":203}},{"residual":-15793,"stddev":253,"sv_id":{"constellation":176,"sat_id":231}},{"residual":-7589,"stddev":116,"sv_id":{"constellation":103,"sat_id":247}},{"residual":-7362,"stddev":240,"sv_id":{"constellation":23,"sat_id":148}},{"residual":4813,"stddev":242,"sv_id":{"constellation":219,"sat_id":29}},{"residual":20295,"stddev":37,"sv_id":{"constellation":72,"sat_id":207}},{"residual":-13623,"stddev":91,"sv_id":{"constellation":176,"sat_id":42}},{"residual":15250,"stddev":110,"sv_id":{"constellation":115,"sat_id":105}},{"residual":-18560,"stddev":185,"sv_id":{"constellation":109,"sat_id":44}},{"residual":23717,"stddev":79,"sv_id":{"constellation":31,"sat_id":67}},{"residual":1886,"stddev":162,"sv_id":{"constellation":180,"sat_id":189}},{"residual":12242,"stddev":7,"sv_id":{"constellation":156,"sat_id":121}},{"residual":10670,"stddev":241,"sv_id":{"constellation":205,"sat_id":7}},{"residual":25899,"stddev":186,"sv_id":{"constellation":210,"sat_id":129}},{"residual":-2078,"stddev":187,"sv_id":{"constellation":195,"sat_id":208}},{"residual":-16264,"stddev":102,"sv_id":{"constellation":160,"sat_id":219}},{"residual":-21002,"stddev":94,"sv_id":{"constellation":42,"sat_id":166}},{"residual":7902,"stddev":35,"sv_id":{"constellation":156,"sat_id":102}},{"residual":-30275,"stddev":204,"sv_id":{"constellation":64,"sat_id":247}},{"residual":-8633,"stddev":222,"sv_id":{"constellation":32,"sat_id":220}},{"residual":6403,"stddev":45,"sv_id":{"constellation":246,"sat_id":201}},{"residual":22643,"stddev":218,"sv_id":{"constellation":239,"sat_id":251}},{"residual":16760,"stddev":175,"sv_id":{"constellation":209,"sat_id":10}},{"residual":-20951,"stddev":137,"sv_id":{"constellation":194,"sat_id":131}},{"residual":-740,"stddev":42,"sv_id":{"constellation":68,"sat_id":17}}]})), "stec_residuals");
    
    is($json->encode($msg->tropo_delay_correction()), $json->encode($json->decode(q{{"hydro":-3035,"stddev":72,"wet":78}})), "tropo_delay_correction");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":9138,"header":{"iod_atmo":170,"num_msgs":48535,"seq_num":50380,"tile_id":12951,"tile_set_id":3605,"time":{"tow":2535294328,"wn":58798},"tropo_quality_indicator":120,"update_interval":105},"index":43413,"length":253,"msg_type":1532,"payload":"FQ6XMniFHZeu5Ze9zMRpqniVqSX0TkiMZQKtWEa0NphzTsmhF4eYYj1Lsnjlkjc6qermRay/f5JZlltv4SkRdzSmpng53QwDnEacI38IfzqAN3NQnXqZfBuAYmfMS+6A4pT4PdjQlafgKJC6neNI8GQjDNQHO7BRVhsYm0MrhC3LLAZwt+ewT8L992db4nSUFz7j8B3bzRLyz0hHTyUqsMnKW2lzkjtuLG2At7lDH6VcT720XgeieZzSLwcHza4p8YHSK2W60MPi97vboHjAZqYq9q1eZpzeHiP3QL2JzNwgR97eyfYDGS3773NY2grReEGvg8IprokRRBz9Kg==","preamble":85,"sender":63940,"stec_residuals":[{"residual":-21246,"stddev":88,"sv_id":{"constellation":101,"sat_id":140}},{"residual":-26570,"stddev":115,"sv_id":{"constellation":180,"sat_id":70}},{"residual":6049,"stddev":135,"sv_id":{"constellation":201,"sat_id":78}},{"residual":19261,"stddev":178,"sv_id":{"constellation":98,"sat_id":152}},{"residual":14226,"stddev":58,"sv_id":{"constellation":229,"sat_id":120}},{"residual":17894,"stddev":172,"sv_id":{"constellation":234,"sat_id":169}},{"residual":22930,"stddev":150,"sv_id":{"constellation":127,"sat_id":191}},{"residual":10721,"stddev":17,"sv_id":{"constellation":111,"sat_id":91}},{"residual":-22874,"stddev":120,"sv_id":{"constellation":52,"sat_id":119}},{"residual":780,"stddev":156,"sv_id":{"constellation":221,"sat_id":57}},{"residual":32547,"stddev":8,"sv_id":{"constellation":156,"sat_id":70}},{"residual":14208,"stddev":115,"sv_id":{"constellation":58,"sat_id":127}},{"residual":-26246,"stddev":124,"sv_id":{"constellation":157,"sat_id":80}},{"residual":26466,"stddev":204,"sv_id":{"constellation":128,"sat_id":27}},{"residual":-7552,"stddev":148,"sv_id":{"constellation":238,"sat_id":75}},{"residual":-12072,"stddev":149,"sv_id":{"constellation":61,"sat_id":248}},{"residual":-28632,"stddev":186,"sv_id":{"constellation":224,"sat_id":167}},{"residual":-4024,"stddev":100,"sv_id":{"constellation":227,"sat_id":157}},{"residual":2004,"stddev":59,"sv_id":{"constellation":12,"sat_id":35}},{"residual":6998,"stddev":24,"sv_id":{"constellation":81,"sat_id":176}},{"residual":-31701,"stddev":45,"sv_id":{"constellation":67,"sat_id":155}},{"residual":28678,"stddev":183,"sv_id":{"constellation":44,"sat_id":203}},{"residual":-15793,"stddev":253,"sv_id":{"constellation":176,"sat_id":231}},{"residual":-7589,"stddev":116,"sv_id":{"constellation":103,"sat_id":247}},{"residual":-7362,"stddev":240,"sv_id":{"constellation":23,"sat_id":148}},{"residual":4813,"stddev":242,"sv_id":{"constellation":219,"sat_id":29}},{"residual":20295,"stddev":37,"sv_id":{"constellation":72,"sat_id":207}},{"residual":-13623,"stddev":91,"sv_id":{"constellation":176,"sat_id":42}},{"residual":15250,"stddev":110,"sv_id":{"constellation":115,"sat_id":105}},{"residual":-18560,"stddev":185,"sv_id":{"constellation":109,"sat_id":44}},{"residual":23717,"stddev":79,"sv_id":{"constellation":31,"sat_id":67}},{"residual":1886,"stddev":162,"sv_id":{"constellation":180,"sat_id":189}},{"residual":12242,"stddev":7,"sv_id":{"constellation":156,"sat_id":121}},{"residual":10670,"stddev":241,"sv_id":{"constellation":205,"sat_id":7}},{"residual":25899,"stddev":186,"sv_id":{"constellation":210,"sat_id":129}},{"residual":-2078,"stddev":187,"sv_id":{"constellation":195,"sat_id":208}},{"residual":-16264,"stddev":102,"sv_id":{"constellation":160,"sat_id":219}},{"residual":-21002,"stddev":94,"sv_id":{"constellation":42,"sat_id":166}},{"residual":7902,"stddev":35,"sv_id":{"constellation":156,"sat_id":102}},{"residual":-30275,"stddev":204,"sv_id":{"constellation":64,"sat_id":247}},{"residual":-8633,"stddev":222,"sv_id":{"constellation":32,"sat_id":220}},{"residual":6403,"stddev":45,"sv_id":{"constellation":246,"sat_id":201}},{"residual":22643,"stddev":218,"sv_id":{"constellation":239,"sat_id":251}},{"residual":16760,"stddev":175,"sv_id":{"constellation":209,"sat_id":10}},{"residual":-20951,"stddev":137,"sv_id":{"constellation":194,"sat_id":131}},{"residual":-740,"stddev":42,"sv_id":{"constellation":68,"sat_id":17}}],"tropo_delay_correction":{"hydro":-3035,"stddev":72,"wet":78}}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_gridded_correction_1();

done_testing();