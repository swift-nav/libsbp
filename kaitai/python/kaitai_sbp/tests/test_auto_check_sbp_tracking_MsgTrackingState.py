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

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msg_tracking_state_1():
    buf = base64.standard_b64decode("VUEAN4H8dbgDZiZqjI0ZBFrD9mxLUol/LaMgLrtdmTzJkxcdBdC1HttF/ogDeSFikNeFtg44qU3aPvJUq/mYiYOCwRUqRP3j2OMYGtKzEw/j/3pLu8jZMNp6u+6Ole43+9SAoMJocf+NPitF9Sdk5mw490SVj4ll6UYxpSZu2uZQ1cSzi4APssSrCNRhwlPpT2M3Wh+0BRlpuhbgUG8IMGqmBDCcMVYTjpJbfHNAHOZzsr6DEPJpO7ZxwLQws6YfrNNN5IwxgE3wwobCKToSNYE3W0iGXCHgnTi6NuCuUlSUvuw2PkM01zn+EIUkrtuskRHAs29hzzjQhrQRK+L/toxxjW8=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x6f8d
    
    assert msg.length == 252
    
    assert msg.msg_type == 0x41
    
    assert msg.payload == "dbgDZiZqjI0ZBFrD9mxLUol/LaMgLrtdmTzJkxcdBdC1HttF/ogDeSFikNeFtg44qU3aPvJUq/mYiYOCwRUqRP3j2OMYGtKzEw/j/3pLu8jZMNp6u+6Ole43+9SAoMJocf+NPitF9Sdk5mw490SVj4ll6UYxpSZu2uZQ1cSzi4APssSrCNRhwlPpT2M3Wh+0BRlpuhbgUG8IMGqmBDCcMVYTjpJbfHNAHOZzsr6DEPJpO7ZxwLQws6YfrNNN5IwxgE3wwobCKToSNYE3W0iGXCHgnTi6NuCuUlSUvuw2PkM01zn+EIUkrtuskRHAs29hzzjQhrQRK+L/toxx"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x8137
    
    assert dictify(msg.states) == [{'cn0': 102, 'fcn': 3, 'sid': {'code': 184, 'sat': 117}}, {'cn0': 141, 'fcn': 140, 'sid': {'code': 106, 'sat': 38}}, {'cn0': 195, 'fcn': 90, 'sid': {'code': 4, 'sat': 25}}, {'cn0': 82, 'fcn': 75, 'sid': {'code': 108, 'sat': 246}}, {'cn0': 163, 'fcn': 45, 'sid': {'code': 127, 'sat': 137}}, {'cn0': 93, 'fcn': 187, 'sid': {'code': 46, 'sat': 32}}, {'cn0': 147, 'fcn': 201, 'sid': {'code': 60, 'sat': 153}}, {'cn0': 208, 'fcn': 5, 'sid': {'code': 29, 'sat': 23}}, {'cn0': 69, 'fcn': 219, 'sid': {'code': 30, 'sat': 181}}, {'cn0': 121, 'fcn': 3, 'sid': {'code': 136, 'sat': 254}}, {'cn0': 215, 'fcn': 144, 'sid': {'code': 98, 'sat': 33}}, {'cn0': 56, 'fcn': 14, 'sid': {'code': 182, 'sat': 133}}, {'cn0': 62, 'fcn': 218, 'sid': {'code': 77, 'sat': 169}}, {'cn0': 249, 'fcn': 171, 'sid': {'code': 84, 'sat': 242}}, {'cn0': 130, 'fcn': 131, 'sid': {'code': 137, 'sat': 152}}, {'cn0': 68, 'fcn': 42, 'sid': {'code': 21, 'sat': 193}}, {'cn0': 227, 'fcn': 216, 'sid': {'code': 227, 'sat': 253}}, {'cn0': 179, 'fcn': 210, 'sid': {'code': 26, 'sat': 24}}, {'cn0': 255, 'fcn': 227, 'sid': {'code': 15, 'sat': 19}}, {'cn0': 200, 'fcn': 187, 'sid': {'code': 75, 'sat': 122}}, {'cn0': 122, 'fcn': 218, 'sid': {'code': 48, 'sat': 217}}, {'cn0': 149, 'fcn': 142, 'sid': {'code': 238, 'sat': 187}}, {'cn0': 212, 'fcn': 251, 'sid': {'code': 55, 'sat': 238}}, {'cn0': 104, 'fcn': 194, 'sid': {'code': 160, 'sat': 128}}, {'cn0': 62, 'fcn': 141, 'sid': {'code': 255, 'sat': 113}}, {'cn0': 39, 'fcn': 245, 'sid': {'code': 69, 'sat': 43}}, {'cn0': 56, 'fcn': 108, 'sid': {'code': 230, 'sat': 100}}, {'cn0': 143, 'fcn': 149, 'sid': {'code': 68, 'sat': 247}}, {'cn0': 70, 'fcn': 233, 'sid': {'code': 101, 'sat': 137}}, {'cn0': 110, 'fcn': 38, 'sid': {'code': 165, 'sat': 49}}, {'cn0': 213, 'fcn': 80, 'sid': {'code': 230, 'sat': 218}}, {'cn0': 128, 'fcn': 139, 'sid': {'code': 179, 'sat': 196}}, {'cn0': 171, 'fcn': 196, 'sid': {'code': 178, 'sat': 15}}, {'cn0': 194, 'fcn': 97, 'sid': {'code': 212, 'sat': 8}}, {'cn0': 99, 'fcn': 79, 'sid': {'code': 233, 'sat': 83}}, {'cn0': 180, 'fcn': 31, 'sid': {'code': 90, 'sat': 55}}, {'cn0': 186, 'fcn': 105, 'sid': {'code': 25, 'sat': 5}}, {'cn0': 111, 'fcn': 80, 'sid': {'code': 224, 'sat': 22}}, {'cn0': 166, 'fcn': 106, 'sid': {'code': 48, 'sat': 8}}, {'cn0': 49, 'fcn': 156, 'sid': {'code': 48, 'sat': 4}}, {'cn0': 146, 'fcn': 142, 'sid': {'code': 19, 'sat': 86}}, {'cn0': 64, 'fcn': 115, 'sid': {'code': 124, 'sat': 91}}, {'cn0': 178, 'fcn': 115, 'sid': {'code': 230, 'sat': 28}}, {'cn0': 242, 'fcn': 16, 'sid': {'code': 131, 'sat': 190}}, {'cn0': 113, 'fcn': 182, 'sid': {'code': 59, 'sat': 105}}, {'cn0': 179, 'fcn': 48, 'sid': {'code': 180, 'sat': 192}}, {'cn0': 211, 'fcn': 172, 'sid': {'code': 31, 'sat': 166}}, {'cn0': 49, 'fcn': 140, 'sid': {'code': 228, 'sat': 77}}, {'cn0': 194, 'fcn': 240, 'sid': {'code': 77, 'sat': 128}}, {'cn0': 58, 'fcn': 41, 'sid': {'code': 194, 'sat': 134}}, {'cn0': 55, 'fcn': 129, 'sid': {'code': 53, 'sat': 18}}, {'cn0': 92, 'fcn': 134, 'sid': {'code': 72, 'sat': 91}}, {'cn0': 56, 'fcn': 157, 'sid': {'code': 224, 'sat': 33}}, {'cn0': 174, 'fcn': 224, 'sid': {'code': 54, 'sat': 186}}, {'cn0': 190, 'fcn': 148, 'sid': {'code': 84, 'sat': 82}}, {'cn0': 67, 'fcn': 62, 'sid': {'code': 54, 'sat': 236}}, {'cn0': 254, 'fcn': 57, 'sid': {'code': 215, 'sat': 52}}, {'cn0': 174, 'fcn': 36, 'sid': {'code': 133, 'sat': 16}}, {'cn0': 17, 'fcn': 145, 'sid': {'code': 172, 'sat': 219}}, {'cn0': 97, 'fcn': 111, 'sid': {'code': 179, 'sat': 192}}, {'cn0': 134, 'fcn': 208, 'sid': {'code': 56, 'sat': 207}}, {'cn0': 226, 'fcn': 43, 'sid': {'code': 17, 'sat': 180}}, {'cn0': 113, 'fcn': 140, 'sid': {'code': 182, 'sat': 255}}]

    assert dictify(msg) == {'crc': 28557, 'length': 252, 'msg_type': 65, 'payload': 'dbgDZiZqjI0ZBFrD9mxLUol/LaMgLrtdmTzJkxcdBdC1HttF/ogDeSFikNeFtg44qU3aPvJUq/mYiYOCwRUqRP3j2OMYGtKzEw/j/3pLu8jZMNp6u+6Ole43+9SAoMJocf+NPitF9Sdk5mw490SVj4ll6UYxpSZu2uZQ1cSzi4APssSrCNRhwlPpT2M3Wh+0BRlpuhbgUG8IMGqmBDCcMVYTjpJbfHNAHOZzsr6DEPJpO7ZxwLQws6YfrNNN5IwxgE3wwobCKToSNYE3W0iGXCHgnTi6NuCuUlSUvuw2PkM01zn+EIUkrtuskRHAs29hzzjQhrQRK+L/toxx', 'preamble': 85, 'sender': 33079, 'states': [{'sid': {'sat': 117, 'code': 184}, 'fcn': 3, 'cn0': 102}, {'sid': {'sat': 38, 'code': 106}, 'fcn': 140, 'cn0': 141}, {'sid': {'sat': 25, 'code': 4}, 'fcn': 90, 'cn0': 195}, {'sid': {'sat': 246, 'code': 108}, 'fcn': 75, 'cn0': 82}, {'sid': {'sat': 137, 'code': 127}, 'fcn': 45, 'cn0': 163}, {'sid': {'sat': 32, 'code': 46}, 'fcn': 187, 'cn0': 93}, {'sid': {'sat': 153, 'code': 60}, 'fcn': 201, 'cn0': 147}, {'sid': {'sat': 23, 'code': 29}, 'fcn': 5, 'cn0': 208}, {'sid': {'sat': 181, 'code': 30}, 'fcn': 219, 'cn0': 69}, {'sid': {'sat': 254, 'code': 136}, 'fcn': 3, 'cn0': 121}, {'sid': {'sat': 33, 'code': 98}, 'fcn': 144, 'cn0': 215}, {'sid': {'sat': 133, 'code': 182}, 'fcn': 14, 'cn0': 56}, {'sid': {'sat': 169, 'code': 77}, 'fcn': 218, 'cn0': 62}, {'sid': {'sat': 242, 'code': 84}, 'fcn': 171, 'cn0': 249}, {'sid': {'sat': 152, 'code': 137}, 'fcn': 131, 'cn0': 130}, {'sid': {'sat': 193, 'code': 21}, 'fcn': 42, 'cn0': 68}, {'sid': {'sat': 253, 'code': 227}, 'fcn': 216, 'cn0': 227}, {'sid': {'sat': 24, 'code': 26}, 'fcn': 210, 'cn0': 179}, {'sid': {'sat': 19, 'code': 15}, 'fcn': 227, 'cn0': 255}, {'sid': {'sat': 122, 'code': 75}, 'fcn': 187, 'cn0': 200}, {'sid': {'sat': 217, 'code': 48}, 'fcn': 218, 'cn0': 122}, {'sid': {'sat': 187, 'code': 238}, 'fcn': 142, 'cn0': 149}, {'sid': {'sat': 238, 'code': 55}, 'fcn': 251, 'cn0': 212}, {'sid': {'sat': 128, 'code': 160}, 'fcn': 194, 'cn0': 104}, {'sid': {'sat': 113, 'code': 255}, 'fcn': 141, 'cn0': 62}, {'sid': {'sat': 43, 'code': 69}, 'fcn': 245, 'cn0': 39}, {'sid': {'sat': 100, 'code': 230}, 'fcn': 108, 'cn0': 56}, {'sid': {'sat': 247, 'code': 68}, 'fcn': 149, 'cn0': 143}, {'sid': {'sat': 137, 'code': 101}, 'fcn': 233, 'cn0': 70}, {'sid': {'sat': 49, 'code': 165}, 'fcn': 38, 'cn0': 110}, {'sid': {'sat': 218, 'code': 230}, 'fcn': 80, 'cn0': 213}, {'sid': {'sat': 196, 'code': 179}, 'fcn': 139, 'cn0': 128}, {'sid': {'sat': 15, 'code': 178}, 'fcn': 196, 'cn0': 171}, {'sid': {'sat': 8, 'code': 212}, 'fcn': 97, 'cn0': 194}, {'sid': {'sat': 83, 'code': 233}, 'fcn': 79, 'cn0': 99}, {'sid': {'sat': 55, 'code': 90}, 'fcn': 31, 'cn0': 180}, {'sid': {'sat': 5, 'code': 25}, 'fcn': 105, 'cn0': 186}, {'sid': {'sat': 22, 'code': 224}, 'fcn': 80, 'cn0': 111}, {'sid': {'sat': 8, 'code': 48}, 'fcn': 106, 'cn0': 166}, {'sid': {'sat': 4, 'code': 48}, 'fcn': 156, 'cn0': 49}, {'sid': {'sat': 86, 'code': 19}, 'fcn': 142, 'cn0': 146}, {'sid': {'sat': 91, 'code': 124}, 'fcn': 115, 'cn0': 64}, {'sid': {'sat': 28, 'code': 230}, 'fcn': 115, 'cn0': 178}, {'sid': {'sat': 190, 'code': 131}, 'fcn': 16, 'cn0': 242}, {'sid': {'sat': 105, 'code': 59}, 'fcn': 182, 'cn0': 113}, {'sid': {'sat': 192, 'code': 180}, 'fcn': 48, 'cn0': 179}, {'sid': {'sat': 166, 'code': 31}, 'fcn': 172, 'cn0': 211}, {'sid': {'sat': 77, 'code': 228}, 'fcn': 140, 'cn0': 49}, {'sid': {'sat': 128, 'code': 77}, 'fcn': 240, 'cn0': 194}, {'sid': {'sat': 134, 'code': 194}, 'fcn': 41, 'cn0': 58}, {'sid': {'sat': 18, 'code': 53}, 'fcn': 129, 'cn0': 55}, {'sid': {'sat': 91, 'code': 72}, 'fcn': 134, 'cn0': 92}, {'sid': {'sat': 33, 'code': 224}, 'fcn': 157, 'cn0': 56}, {'sid': {'sat': 186, 'code': 54}, 'fcn': 224, 'cn0': 174}, {'sid': {'sat': 82, 'code': 84}, 'fcn': 148, 'cn0': 190}, {'sid': {'sat': 236, 'code': 54}, 'fcn': 62, 'cn0': 67}, {'sid': {'sat': 52, 'code': 215}, 'fcn': 57, 'cn0': 254}, {'sid': {'sat': 16, 'code': 133}, 'fcn': 36, 'cn0': 174}, {'sid': {'sat': 219, 'code': 172}, 'fcn': 145, 'cn0': 17}, {'sid': {'sat': 192, 'code': 179}, 'fcn': 111, 'cn0': 97}, {'sid': {'sat': 207, 'code': 56}, 'fcn': 208, 'cn0': 134}, {'sid': {'sat': 180, 'code': 17}, 'fcn': 43, 'cn0': 226}, {'sid': {'sat': 255, 'code': 182}, 'fcn': 140, 'cn0': 113}]}

def test_auto_check_sbp_tracking_msg_tracking_state_2():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/3mE=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x61de
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 39.24782180786133, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 36.09756088256836, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 37.62678527832031, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 39.020729064941406, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 42.03290557861328, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.43546676635742, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 38.4229621887207, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 38.91520309448242, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.62259292602539, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 39.24782180786133, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 36.09756088256836, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 37.62678527832031, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 39.020729064941406, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 42.03290557861328, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.43546676635742, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 38.4229621887207, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 38.91520309448242, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.62259292602539, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 25054, 'length': 99, 'preamble': 85, 'payload': 'AcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/'}

def test_auto_check_sbp_tracking_msg_tracking_state_3():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/FB8=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1f14
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 38.994117736816406, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 34.889801025390625, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 37.44603729248047, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 38.72849655151367, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 41.983219146728516, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.46448516845703, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 38.44300079345703, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 39.03423309326172, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.89944839477539, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 38.994117736816406, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 34.889801025390625, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 37.44603729248047, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 38.72849655151367, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 41.983219146728516, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.46448516845703, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 38.44300079345703, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 39.03423309326172, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.89944839477539, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 7956, 'length': 99, 'preamble': 85, 'payload': 'AcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/'}

def test_auto_check_sbp_tracking_msg_tracking_state_4():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/6Uc=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x47e9
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 38.95457077026367, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 35.813316345214844, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 37.553924560546875, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 38.88901901245117, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 42.4013557434082, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.63916015625, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 37.919986724853516, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 39.25254440307617, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.59827423095703, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 38.95457077026367, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 35.813316345214844, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 37.553924560546875, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 38.88901901245117, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 42.4013557434082, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.63916015625, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 37.919986724853516, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 39.25254440307617, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.59827423095703, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 18409, 'length': 99, 'preamble': 85, 'payload': 'AcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/'}

def test_auto_check_sbp_tracking_msg_tracking_state_5():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/ScE=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc149
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 39.369598388671875, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 36.52173614501953, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 38.15976333618164, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 39.19989776611328, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 41.55845642089844, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.026981353759766, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 38.1049690246582, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 39.04584503173828, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.37783432006836, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 39.369598388671875, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 36.52173614501953, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 38.15976333618164, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 39.19989776611328, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 41.55845642089844, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.026981353759766, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 38.1049690246582, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 39.04584503173828, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.37783432006836, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 49481, 'length': 99, 'preamble': 85, 'payload': 'AcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/'}

def test_auto_check_sbp_tracking_msg_tracking_state_6():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/fi8=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2f7e
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 39.70351791381836, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 36.52388381958008, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 37.169708251953125, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 38.81692886352539, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 42.05073165893555, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.807498931884766, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 37.71632385253906, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 38.5289192199707, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.27101516723633, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 39.70351791381836, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 36.52388381958008, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 37.169708251953125, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 38.81692886352539, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 42.05073165893555, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.807498931884766, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 37.71632385253906, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 38.5289192199707, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.27101516723633, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 12158, 'length': 99, 'preamble': 85, 'payload': 'AcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/'}
