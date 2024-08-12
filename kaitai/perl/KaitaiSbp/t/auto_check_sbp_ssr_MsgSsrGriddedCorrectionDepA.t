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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionDepA.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_gridded_correction_dep_a_1() {
    my $buf = decode_base64("VfoFbGr+pNksNWJdP5No/IX1HF9kkykhXFcZjpdKl19eB5LtLadWKnTgqercF7ASDbJPoKBuDzXOl54WdbgwqlIoNXpFtG4mQWj0E+7jWKmkkj8lt1VH66hy02ndnDwS5gKOrBAnIX5qY7zqKaLFiuNQDDZD7gVdAc+BDS5zMTq5f5zIYNnKD/U3xlHahEZJUpMa/w6GYIo31lOcqqNPreRzM/Fr9XCo0goFdQE5bPjUkXfipQWNymoAPCQ988vY1wyJEBz3c5i1d9Dky+wip8QgbQERZcgZXn2oiZ0EpB0fMIRI5X66REyFFQC0i6SUd5XWeLHJUFBpCoh2TS7p6eMLnmen2A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd8a7, "crc");
    
    is($msg->{'length'}, 254, "length");
    
    is($msg->{'msg_type'}, 0x5fa, "msg_type");
    
    is($msg->{'payload'}, "pNksNWJdP5No/IX1HF9kkykhXFcZjpdKl19eB5LtLadWKnTgqercF7ASDbJPoKBuDzXOl54WdbgwqlIoNXpFtG4mQWj0E+7jWKmkkj8lt1VH66hy02ndnDwS5gKOrBAnIX5qY7zqKaLFiuNQDDZD7gVdAc+BDS5zMTq5f5zIYNnKD/U3xlHahEZJUpMa/w6GYIo31lOcqqNPreRzM/Fr9XCo0goFdQE5bPjUkXfipQWNymoAPCQ988vY1wyJEBz3c5i1d9Dky+wip8QgbQERZcgZXn2oiZ0EpB0fMIRI5X66REyFFQC0i6SUd5XWeLHJUFBpCoh2TS7p6eMLnmc=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x6a6c, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"iod_atmo":245,"num_msgs":37695,"seq_num":64616,"time":{"tow":892131748,"wn":23906},"tropo_quality_indicator":28,"update_interval":133}})), "header");
    
    is($msg->index(), 25695, "index");
    
    is($json->encode($msg->stec_residuals()), $json->encode($json->decode(q{[{"residual":-26738,"stddev":74,"sv_id":{"constellation":25,"sat_id":87}},{"residual":1886,"stddev":146,"sv_id":{"constellation":95,"sat_id":151}},{"residual":22183,"stddev":42,"sv_id":{"constellation":45,"sat_id":237}},{"residual":-5463,"stddev":220,"sv_id":{"constellation":224,"sat_id":116}},{"residual":3346,"stddev":178,"sv_id":{"constellation":176,"sat_id":23}},{"residual":28320,"stddev":15,"sv_id":{"constellation":160,"sat_id":79}},{"residual":-24937,"stddev":22,"sv_id":{"constellation":206,"sat_id":53}},{"residual":-21968,"stddev":82,"sv_id":{"constellation":184,"sat_id":117}},{"residual":17786,"stddev":180,"sv_id":{"constellation":53,"sat_id":40}},{"residual":26689,"stddev":244,"sv_id":{"constellation":38,"sat_id":110}},{"residual":22755,"stddev":169,"sv_id":{"constellation":238,"sat_id":19}},{"residual":9535,"stddev":183,"sv_id":{"constellation":146,"sat_id":164}},{"residual":-22293,"stddev":114,"sv_id":{"constellation":71,"sat_id":85}},{"residual":-25379,"stddev":60,"sv_id":{"constellation":105,"sat_id":211}},{"residual":-29182,"stddev":172,"sv_id":{"constellation":230,"sat_id":18}},{"residual":32289,"stddev":106,"sv_id":{"constellation":39,"sat_id":16}},{"residual":10730,"stddev":162,"sv_id":{"constellation":188,"sat_id":99}},{"residual":20707,"stddev":12,"sv_id":{"constellation":138,"sat_id":197}},{"residual":1518,"stddev":93,"sv_id":{"constellation":67,"sat_id":54}},{"residual":3457,"stddev":46,"sv_id":{"constellation":207,"sat_id":1}},{"residual":-18118,"stddev":127,"sv_id":{"constellation":49,"sat_id":115}},{"residual":-9888,"stddev":202,"sv_id":{"constellation":200,"sat_id":156}},{"residual":-14793,"stddev":81,"sv_id":{"constellation":245,"sat_id":15}},{"residual":18758,"stddev":82,"sv_id":{"constellation":132,"sat_id":218}},{"residual":3839,"stddev":134,"sv_id":{"constellation":26,"sat_id":147}},{"residual":-10697,"stddev":83,"sv_id":{"constellation":138,"sat_id":96}},{"residual":20387,"stddev":173,"sv_id":{"constellation":170,"sat_id":156}},{"residual":-3789,"stddev":107,"sv_id":{"constellation":115,"sat_id":228}},{"residual":-11608,"stddev":10,"sv_id":{"constellation":112,"sat_id":245}},{"residual":14593,"stddev":108,"sv_id":{"constellation":117,"sat_id":5}},{"residual":30609,"stddev":226,"sv_id":{"constellation":212,"sat_id":248}},{"residual":-13683,"stddev":106,"sv_id":{"constellation":5,"sat_id":165}},{"residual":15652,"stddev":243,"sv_id":{"constellation":60,"sat_id":0}},{"residual":3287,"stddev":137,"sv_id":{"constellation":216,"sat_id":203}},{"residual":29687,"stddev":152,"sv_id":{"constellation":28,"sat_id":16}},{"residual":-6960,"stddev":203,"sv_id":{"constellation":119,"sat_id":181}},{"residual":-15193,"stddev":32,"sv_id":{"constellation":34,"sat_id":236}},{"residual":25873,"stddev":200,"sv_id":{"constellation":1,"sat_id":109}},{"residual":-22403,"stddev":137,"sv_id":{"constellation":94,"sat_id":25}},{"residual":7588,"stddev":31,"sv_id":{"constellation":4,"sat_id":157}},{"residual":-6840,"stddev":126,"sv_id":{"constellation":132,"sat_id":48}},{"residual":-31412,"stddev":21,"sv_id":{"constellation":68,"sat_id":186}},{"residual":-23413,"stddev":148,"sv_id":{"constellation":180,"sat_id":0}},{"residual":30934,"stddev":177,"sv_id":{"constellation":149,"sat_id":119}},{"residual":26960,"stddev":10,"sv_id":{"constellation":80,"sat_id":201}},{"residual":11853,"stddev":233,"sv_id":{"constellation":118,"sat_id":136}},{"residual":-25077,"stddev":103,"sv_id":{"constellation":227,"sat_id":233}}]})), "stec_residuals");
    
    is($json->encode($msg->tropo_delay_correction()), $json->encode($json->decode(q{{"hydro":10643,"stddev":92,"wet":33}})), "tropo_delay_correction");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":55463,"header":{"iod_atmo":245,"num_msgs":37695,"seq_num":64616,"time":{"tow":892131748,"wn":23906},"tropo_quality_indicator":28,"update_interval":133},"index":25695,"length":254,"msg_type":1530,"payload":"pNksNWJdP5No/IX1HF9kkykhXFcZjpdKl19eB5LtLadWKnTgqercF7ASDbJPoKBuDzXOl54WdbgwqlIoNXpFtG4mQWj0E+7jWKmkkj8lt1VH66hy02ndnDwS5gKOrBAnIX5qY7zqKaLFiuNQDDZD7gVdAc+BDS5zMTq5f5zIYNnKD/U3xlHahEZJUpMa/w6GYIo31lOcqqNPreRzM/Fr9XCo0goFdQE5bPjUkXfipQWNymoAPCQ988vY1wyJEBz3c5i1d9Dky+wip8QgbQERZcgZXn2oiZ0EpB0fMIRI5X66REyFFQC0i6SUd5XWeLHJUFBpCoh2TS7p6eMLnmc=","preamble":85,"sender":27244,"stec_residuals":[{"residual":-26738,"stddev":74,"sv_id":{"constellation":25,"sat_id":87}},{"residual":1886,"stddev":146,"sv_id":{"constellation":95,"sat_id":151}},{"residual":22183,"stddev":42,"sv_id":{"constellation":45,"sat_id":237}},{"residual":-5463,"stddev":220,"sv_id":{"constellation":224,"sat_id":116}},{"residual":3346,"stddev":178,"sv_id":{"constellation":176,"sat_id":23}},{"residual":28320,"stddev":15,"sv_id":{"constellation":160,"sat_id":79}},{"residual":-24937,"stddev":22,"sv_id":{"constellation":206,"sat_id":53}},{"residual":-21968,"stddev":82,"sv_id":{"constellation":184,"sat_id":117}},{"residual":17786,"stddev":180,"sv_id":{"constellation":53,"sat_id":40}},{"residual":26689,"stddev":244,"sv_id":{"constellation":38,"sat_id":110}},{"residual":22755,"stddev":169,"sv_id":{"constellation":238,"sat_id":19}},{"residual":9535,"stddev":183,"sv_id":{"constellation":146,"sat_id":164}},{"residual":-22293,"stddev":114,"sv_id":{"constellation":71,"sat_id":85}},{"residual":-25379,"stddev":60,"sv_id":{"constellation":105,"sat_id":211}},{"residual":-29182,"stddev":172,"sv_id":{"constellation":230,"sat_id":18}},{"residual":32289,"stddev":106,"sv_id":{"constellation":39,"sat_id":16}},{"residual":10730,"stddev":162,"sv_id":{"constellation":188,"sat_id":99}},{"residual":20707,"stddev":12,"sv_id":{"constellation":138,"sat_id":197}},{"residual":1518,"stddev":93,"sv_id":{"constellation":67,"sat_id":54}},{"residual":3457,"stddev":46,"sv_id":{"constellation":207,"sat_id":1}},{"residual":-18118,"stddev":127,"sv_id":{"constellation":49,"sat_id":115}},{"residual":-9888,"stddev":202,"sv_id":{"constellation":200,"sat_id":156}},{"residual":-14793,"stddev":81,"sv_id":{"constellation":245,"sat_id":15}},{"residual":18758,"stddev":82,"sv_id":{"constellation":132,"sat_id":218}},{"residual":3839,"stddev":134,"sv_id":{"constellation":26,"sat_id":147}},{"residual":-10697,"stddev":83,"sv_id":{"constellation":138,"sat_id":96}},{"residual":20387,"stddev":173,"sv_id":{"constellation":170,"sat_id":156}},{"residual":-3789,"stddev":107,"sv_id":{"constellation":115,"sat_id":228}},{"residual":-11608,"stddev":10,"sv_id":{"constellation":112,"sat_id":245}},{"residual":14593,"stddev":108,"sv_id":{"constellation":117,"sat_id":5}},{"residual":30609,"stddev":226,"sv_id":{"constellation":212,"sat_id":248}},{"residual":-13683,"stddev":106,"sv_id":{"constellation":5,"sat_id":165}},{"residual":15652,"stddev":243,"sv_id":{"constellation":60,"sat_id":0}},{"residual":3287,"stddev":137,"sv_id":{"constellation":216,"sat_id":203}},{"residual":29687,"stddev":152,"sv_id":{"constellation":28,"sat_id":16}},{"residual":-6960,"stddev":203,"sv_id":{"constellation":119,"sat_id":181}},{"residual":-15193,"stddev":32,"sv_id":{"constellation":34,"sat_id":236}},{"residual":25873,"stddev":200,"sv_id":{"constellation":1,"sat_id":109}},{"residual":-22403,"stddev":137,"sv_id":{"constellation":94,"sat_id":25}},{"residual":7588,"stddev":31,"sv_id":{"constellation":4,"sat_id":157}},{"residual":-6840,"stddev":126,"sv_id":{"constellation":132,"sat_id":48}},{"residual":-31412,"stddev":21,"sv_id":{"constellation":68,"sat_id":186}},{"residual":-23413,"stddev":148,"sv_id":{"constellation":180,"sat_id":0}},{"residual":30934,"stddev":177,"sv_id":{"constellation":149,"sat_id":119}},{"residual":26960,"stddev":10,"sv_id":{"constellation":80,"sat_id":201}},{"residual":11853,"stddev":233,"sv_id":{"constellation":118,"sat_id":136}},{"residual":-25077,"stddev":103,"sv_id":{"constellation":227,"sat_id":233}}],"tropo_delay_correction":{"hydro":10643,"stddev":92,"wet":33}}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_gridded_correction_dep_a_1();

done_testing();