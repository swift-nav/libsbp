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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml
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
sub test_auto_check_sbp_tracking_msg_tracking_state_1() {
    my $buf = decode_base64("VUEAN4H8dbgDZiZqjI0ZBFrD9mxLUol/LaMgLrtdmTzJkxcdBdC1HttF/ogDeSFikNeFtg44qU3aPvJUq/mYiYOCwRUqRP3j2OMYGtKzEw/j/3pLu8jZMNp6u+6Ole43+9SAoMJocf+NPitF9Sdk5mw490SVj4ll6UYxpSZu2uZQ1cSzi4APssSrCNRhwlPpT2M3Wh+0BRlpuhbgUG8IMGqmBDCcMVYTjpJbfHNAHOZzsr6DEPJpO7ZxwLQws6YfrNNN5IwxgE3wwobCKToSNYE3W0iGXCHgnTi6NuCuUlSUvuw2PkM01zn+EIUkrtuskRHAs29hzzjQhrQRK+L/toxxjW8=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6f8d, "crc");
    
    is($msg->{'length'}, 252, "length");
    
    is($msg->{'msg_type'}, 0x41, "msg_type");
    
    is($msg->{'payload'}, "dbgDZiZqjI0ZBFrD9mxLUol/LaMgLrtdmTzJkxcdBdC1HttF/ogDeSFikNeFtg44qU3aPvJUq/mYiYOCwRUqRP3j2OMYGtKzEw/j/3pLu8jZMNp6u+6Ole43+9SAoMJocf+NPitF9Sdk5mw490SVj4ll6UYxpSZu2uZQ1cSzi4APssSrCNRhwlPpT2M3Wh+0BRlpuhbgUG8IMGqmBDCcMVYTjpJbfHNAHOZzsr6DEPJpO7ZxwLQws6YfrNNN5IwxgE3wwobCKToSNYE3W0iGXCHgnTi6NuCuUlSUvuw2PkM01zn+EIUkrtuskRHAs29hzzjQhrQRK+L/toxx", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x8137, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":102,"fcn":3,"sid":{"code":184,"sat":117}},{"cn0":141,"fcn":140,"sid":{"code":106,"sat":38}},{"cn0":195,"fcn":90,"sid":{"code":4,"sat":25}},{"cn0":82,"fcn":75,"sid":{"code":108,"sat":246}},{"cn0":163,"fcn":45,"sid":{"code":127,"sat":137}},{"cn0":93,"fcn":187,"sid":{"code":46,"sat":32}},{"cn0":147,"fcn":201,"sid":{"code":60,"sat":153}},{"cn0":208,"fcn":5,"sid":{"code":29,"sat":23}},{"cn0":69,"fcn":219,"sid":{"code":30,"sat":181}},{"cn0":121,"fcn":3,"sid":{"code":136,"sat":254}},{"cn0":215,"fcn":144,"sid":{"code":98,"sat":33}},{"cn0":56,"fcn":14,"sid":{"code":182,"sat":133}},{"cn0":62,"fcn":218,"sid":{"code":77,"sat":169}},{"cn0":249,"fcn":171,"sid":{"code":84,"sat":242}},{"cn0":130,"fcn":131,"sid":{"code":137,"sat":152}},{"cn0":68,"fcn":42,"sid":{"code":21,"sat":193}},{"cn0":227,"fcn":216,"sid":{"code":227,"sat":253}},{"cn0":179,"fcn":210,"sid":{"code":26,"sat":24}},{"cn0":255,"fcn":227,"sid":{"code":15,"sat":19}},{"cn0":200,"fcn":187,"sid":{"code":75,"sat":122}},{"cn0":122,"fcn":218,"sid":{"code":48,"sat":217}},{"cn0":149,"fcn":142,"sid":{"code":238,"sat":187}},{"cn0":212,"fcn":251,"sid":{"code":55,"sat":238}},{"cn0":104,"fcn":194,"sid":{"code":160,"sat":128}},{"cn0":62,"fcn":141,"sid":{"code":255,"sat":113}},{"cn0":39,"fcn":245,"sid":{"code":69,"sat":43}},{"cn0":56,"fcn":108,"sid":{"code":230,"sat":100}},{"cn0":143,"fcn":149,"sid":{"code":68,"sat":247}},{"cn0":70,"fcn":233,"sid":{"code":101,"sat":137}},{"cn0":110,"fcn":38,"sid":{"code":165,"sat":49}},{"cn0":213,"fcn":80,"sid":{"code":230,"sat":218}},{"cn0":128,"fcn":139,"sid":{"code":179,"sat":196}},{"cn0":171,"fcn":196,"sid":{"code":178,"sat":15}},{"cn0":194,"fcn":97,"sid":{"code":212,"sat":8}},{"cn0":99,"fcn":79,"sid":{"code":233,"sat":83}},{"cn0":180,"fcn":31,"sid":{"code":90,"sat":55}},{"cn0":186,"fcn":105,"sid":{"code":25,"sat":5}},{"cn0":111,"fcn":80,"sid":{"code":224,"sat":22}},{"cn0":166,"fcn":106,"sid":{"code":48,"sat":8}},{"cn0":49,"fcn":156,"sid":{"code":48,"sat":4}},{"cn0":146,"fcn":142,"sid":{"code":19,"sat":86}},{"cn0":64,"fcn":115,"sid":{"code":124,"sat":91}},{"cn0":178,"fcn":115,"sid":{"code":230,"sat":28}},{"cn0":242,"fcn":16,"sid":{"code":131,"sat":190}},{"cn0":113,"fcn":182,"sid":{"code":59,"sat":105}},{"cn0":179,"fcn":48,"sid":{"code":180,"sat":192}},{"cn0":211,"fcn":172,"sid":{"code":31,"sat":166}},{"cn0":49,"fcn":140,"sid":{"code":228,"sat":77}},{"cn0":194,"fcn":240,"sid":{"code":77,"sat":128}},{"cn0":58,"fcn":41,"sid":{"code":194,"sat":134}},{"cn0":55,"fcn":129,"sid":{"code":53,"sat":18}},{"cn0":92,"fcn":134,"sid":{"code":72,"sat":91}},{"cn0":56,"fcn":157,"sid":{"code":224,"sat":33}},{"cn0":174,"fcn":224,"sid":{"code":54,"sat":186}},{"cn0":190,"fcn":148,"sid":{"code":84,"sat":82}},{"cn0":67,"fcn":62,"sid":{"code":54,"sat":236}},{"cn0":254,"fcn":57,"sid":{"code":215,"sat":52}},{"cn0":174,"fcn":36,"sid":{"code":133,"sat":16}},{"cn0":17,"fcn":145,"sid":{"code":172,"sat":219}},{"cn0":97,"fcn":111,"sid":{"code":179,"sat":192}},{"cn0":134,"fcn":208,"sid":{"code":56,"sat":207}},{"cn0":226,"fcn":43,"sid":{"code":17,"sat":180}},{"cn0":113,"fcn":140,"sid":{"code":182,"sat":255}}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":28557,"length":252,"msg_type":65,"payload":"dbgDZiZqjI0ZBFrD9mxLUol/LaMgLrtdmTzJkxcdBdC1HttF/ogDeSFikNeFtg44qU3aPvJUq/mYiYOCwRUqRP3j2OMYGtKzEw/j/3pLu8jZMNp6u+6Ole43+9SAoMJocf+NPitF9Sdk5mw490SVj4ll6UYxpSZu2uZQ1cSzi4APssSrCNRhwlPpT2M3Wh+0BRlpuhbgUG8IMGqmBDCcMVYTjpJbfHNAHOZzsr6DEPJpO7ZxwLQws6YfrNNN5IwxgE3wwobCKToSNYE3W0iGXCHgnTi6NuCuUlSUvuw2PkM01zn+EIUkrtuskRHAs29hzzjQhrQRK+L/toxx","preamble":85,"sender":33079,"states":[{"cn0":102,"fcn":3,"sid":{"code":184,"sat":117}},{"cn0":141,"fcn":140,"sid":{"code":106,"sat":38}},{"cn0":195,"fcn":90,"sid":{"code":4,"sat":25}},{"cn0":82,"fcn":75,"sid":{"code":108,"sat":246}},{"cn0":163,"fcn":45,"sid":{"code":127,"sat":137}},{"cn0":93,"fcn":187,"sid":{"code":46,"sat":32}},{"cn0":147,"fcn":201,"sid":{"code":60,"sat":153}},{"cn0":208,"fcn":5,"sid":{"code":29,"sat":23}},{"cn0":69,"fcn":219,"sid":{"code":30,"sat":181}},{"cn0":121,"fcn":3,"sid":{"code":136,"sat":254}},{"cn0":215,"fcn":144,"sid":{"code":98,"sat":33}},{"cn0":56,"fcn":14,"sid":{"code":182,"sat":133}},{"cn0":62,"fcn":218,"sid":{"code":77,"sat":169}},{"cn0":249,"fcn":171,"sid":{"code":84,"sat":242}},{"cn0":130,"fcn":131,"sid":{"code":137,"sat":152}},{"cn0":68,"fcn":42,"sid":{"code":21,"sat":193}},{"cn0":227,"fcn":216,"sid":{"code":227,"sat":253}},{"cn0":179,"fcn":210,"sid":{"code":26,"sat":24}},{"cn0":255,"fcn":227,"sid":{"code":15,"sat":19}},{"cn0":200,"fcn":187,"sid":{"code":75,"sat":122}},{"cn0":122,"fcn":218,"sid":{"code":48,"sat":217}},{"cn0":149,"fcn":142,"sid":{"code":238,"sat":187}},{"cn0":212,"fcn":251,"sid":{"code":55,"sat":238}},{"cn0":104,"fcn":194,"sid":{"code":160,"sat":128}},{"cn0":62,"fcn":141,"sid":{"code":255,"sat":113}},{"cn0":39,"fcn":245,"sid":{"code":69,"sat":43}},{"cn0":56,"fcn":108,"sid":{"code":230,"sat":100}},{"cn0":143,"fcn":149,"sid":{"code":68,"sat":247}},{"cn0":70,"fcn":233,"sid":{"code":101,"sat":137}},{"cn0":110,"fcn":38,"sid":{"code":165,"sat":49}},{"cn0":213,"fcn":80,"sid":{"code":230,"sat":218}},{"cn0":128,"fcn":139,"sid":{"code":179,"sat":196}},{"cn0":171,"fcn":196,"sid":{"code":178,"sat":15}},{"cn0":194,"fcn":97,"sid":{"code":212,"sat":8}},{"cn0":99,"fcn":79,"sid":{"code":233,"sat":83}},{"cn0":180,"fcn":31,"sid":{"code":90,"sat":55}},{"cn0":186,"fcn":105,"sid":{"code":25,"sat":5}},{"cn0":111,"fcn":80,"sid":{"code":224,"sat":22}},{"cn0":166,"fcn":106,"sid":{"code":48,"sat":8}},{"cn0":49,"fcn":156,"sid":{"code":48,"sat":4}},{"cn0":146,"fcn":142,"sid":{"code":19,"sat":86}},{"cn0":64,"fcn":115,"sid":{"code":124,"sat":91}},{"cn0":178,"fcn":115,"sid":{"code":230,"sat":28}},{"cn0":242,"fcn":16,"sid":{"code":131,"sat":190}},{"cn0":113,"fcn":182,"sid":{"code":59,"sat":105}},{"cn0":179,"fcn":48,"sid":{"code":180,"sat":192}},{"cn0":211,"fcn":172,"sid":{"code":31,"sat":166}},{"cn0":49,"fcn":140,"sid":{"code":228,"sat":77}},{"cn0":194,"fcn":240,"sid":{"code":77,"sat":128}},{"cn0":58,"fcn":41,"sid":{"code":194,"sat":134}},{"cn0":55,"fcn":129,"sid":{"code":53,"sat":18}},{"cn0":92,"fcn":134,"sid":{"code":72,"sat":91}},{"cn0":56,"fcn":157,"sid":{"code":224,"sat":33}},{"cn0":174,"fcn":224,"sid":{"code":54,"sat":186}},{"cn0":190,"fcn":148,"sid":{"code":84,"sat":82}},{"cn0":67,"fcn":62,"sid":{"code":54,"sat":236}},{"cn0":254,"fcn":57,"sid":{"code":215,"sat":52}},{"cn0":174,"fcn":36,"sid":{"code":133,"sat":16}},{"cn0":17,"fcn":145,"sid":{"code":172,"sat":219}},{"cn0":97,"fcn":111,"sid":{"code":179,"sat":192}},{"cn0":134,"fcn":208,"sid":{"code":56,"sat":207}},{"cn0":226,"fcn":43,"sid":{"code":17,"sat":180}},{"cn0":113,"fcn":140,"sid":{"code":182,"sat":255}}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msg_tracking_state_2() {
    my $buf = decode_base64("VRMA9tdjAcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/3mE=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x61de, "crc");
    
    is($msg->{'length'}, 99, "length");
    
    is($msg->{'msg_type'}, 0x13, "msg_type");
    
    is($msg->{'payload'}, "AcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":39.24782180786133,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":36.09756088256836,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":37.62678527832031,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":39.020729064941406,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":42.03290557861328,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.43546676635742,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":38.4229621887207,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":38.91520309448242,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.62259292602539,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":25054,"length":99,"msg_type":19,"payload":"AcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/","preamble":85,"sender":55286,"states":[{"cn0":39.24782180786133,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":36.09756088256836,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":37.62678527832031,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":39.020729064941406,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":42.03290557861328,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.43546676635742,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":38.4229621887207,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":38.91520309448242,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.62259292602539,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msg_tracking_state_3() {
    my $buf = decode_base64("VRMA9tdjAcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/FB8=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1f14, "crc");
    
    is($msg->{'length'}, 99, "length");
    
    is($msg->{'msg_type'}, 0x13, "msg_type");
    
    is($msg->{'payload'}, "AcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":38.994117736816406,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":34.889801025390625,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":37.44603729248047,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":38.72849655151367,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":41.983219146728516,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.46448516845703,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":38.44300079345703,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":39.03423309326172,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.89944839477539,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":7956,"length":99,"msg_type":19,"payload":"AcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/","preamble":85,"sender":55286,"states":[{"cn0":38.994117736816406,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":34.889801025390625,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":37.44603729248047,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":38.72849655151367,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":41.983219146728516,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.46448516845703,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":38.44300079345703,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":39.03423309326172,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.89944839477539,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msg_tracking_state_4() {
    my $buf = decode_base64("VRMA9tdjAcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/6Uc=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x47e9, "crc");
    
    is($msg->{'length'}, 99, "length");
    
    is($msg->{'msg_type'}, 0x13, "msg_type");
    
    is($msg->{'payload'}, "AcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":38.95457077026367,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":35.813316345214844,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":37.553924560546875,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":38.88901901245117,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":42.4013557434082,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.63916015625,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":37.919986724853516,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":39.25254440307617,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.59827423095703,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":18409,"length":99,"msg_type":19,"payload":"AcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/","preamble":85,"sender":55286,"states":[{"cn0":38.95457077026367,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":35.813316345214844,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":37.553924560546875,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":38.88901901245117,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":42.4013557434082,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.63916015625,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":37.919986724853516,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":39.25254440307617,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.59827423095703,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msg_tracking_state_5() {
    my $buf = decode_base64("VRMA9tdjAcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/ScE=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc149, "crc");
    
    is($msg->{'length'}, 99, "length");
    
    is($msg->{'msg_type'}, 0x13, "msg_type");
    
    is($msg->{'payload'}, "AcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":39.369598388671875,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":36.52173614501953,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":38.15976333618164,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":39.19989776611328,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":41.55845642089844,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.026981353759766,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":38.1049690246582,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":39.04584503173828,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.37783432006836,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":49481,"length":99,"msg_type":19,"payload":"AcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/","preamble":85,"sender":55286,"states":[{"cn0":39.369598388671875,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":36.52173614501953,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":38.15976333618164,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":39.19989776611328,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":41.55845642089844,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.026981353759766,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":38.1049690246582,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":39.04584503173828,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.37783432006836,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msg_tracking_state_6() {
    my $buf = decode_base64("VRMA9tdjAcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/fi8=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2f7e, "crc");
    
    is($msg->{'length'}, 99, "length");
    
    is($msg->{'msg_type'}, 0x13, "msg_type");
    
    is($msg->{'payload'}, "AcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->states()), $json->encode($json->decode(q{[{"cn0":39.70351791381836,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":36.52388381958008,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":37.169708251953125,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":38.81692886352539,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":42.05073165893555,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.807498931884766,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":37.71632385253906,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":38.5289192199707,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.27101516723633,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]})), "states");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":12158,"length":99,"msg_type":19,"payload":"AcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/","preamble":85,"sender":55286,"states":[{"cn0":39.70351791381836,"sid":{"code":0,"reserved":0,"sat":202},"state":1},{"cn0":36.52388381958008,"sid":{"code":0,"reserved":0,"sat":203},"state":1},{"cn0":37.169708251953125,"sid":{"code":0,"reserved":0,"sat":208},"state":1},{"cn0":38.81692886352539,"sid":{"code":0,"reserved":0,"sat":212},"state":1},{"cn0":42.05073165893555,"sid":{"code":0,"reserved":0,"sat":217},"state":1},{"cn0":37.807498931884766,"sid":{"code":0,"reserved":0,"sat":218},"state":1},{"cn0":37.71632385253906,"sid":{"code":0,"reserved":0,"sat":220},"state":1},{"cn0":38.5289192199707,"sid":{"code":0,"reserved":0,"sat":222},"state":1},{"cn0":42.27101516723633,"sid":{"code":0,"reserved":0,"sat":225},"state":1},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0},{"cn0":-1.0,"sid":{"code":0,"reserved":0,"sat":0},"state":0}]}})), "raw_json");
}
test_auto_check_sbp_tracking_msg_tracking_state_1();
test_auto_check_sbp_tracking_msg_tracking_state_2();
test_auto_check_sbp_tracking_msg_tracking_state_3();
test_auto_check_sbp_tracking_msg_tracking_state_4();
test_auto_check_sbp_tracking_msg_tracking_state_5();
test_auto_check_sbp_tracking_msg_tracking_state_6();

done_testing();