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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaCertificate.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_sbp2json import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_signing_msg_ecdsa_certificate_1():
    buf = base64.standard_b64decode("VQQMQgD9MAoLDA0CtKB0TfMcrSRWIQgfeElAqZTgOV8RKNVcw5Lr5LFlUrYZrKr67Ad3BMkKDtAvfjHSrkvdyxhCNCMaHoxv9ifizcayxAVRCSyko9aKe0xK7XkNibphwb3IfEVz5p+5njMM4UHAaTgpVYUT2aYwi4Ng2GKThOqn+Pcg78K8/nJ1Uxn7v2jwdkQqXRIQJehjsxdaXogGfVv/D0crLhn85VCPOvELPrWbNZmVmOOWV3ClAoDnGZ30zGz9f3qRcaLFq8c2uN7OQ5BOu888042HatxPt/UVoagigTKwAdoUgjv5bdsAZGc3HfJumr7pji0918ruWNFGP5cbZtse")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1EDB
    
    assert msg.length == 253
    
    assert msg.msg_type == 0xC04
    
    assert msg.payload == "MAoLDA0CtKB0TfMcrSRWIQgfeElAqZTgOV8RKNVcw5Lr5LFlUrYZrKr67Ad3BMkKDtAvfjHSrkvdyxhCNCMaHoxv9ifizcayxAVRCSyko9aKe0xK7XkNibphwb3IfEVz5p+5njMM4UHAaTgpVYUT2aYwi4Ng2GKThOqn+Pcg78K8/nJ1Uxn7v2jwdkQqXRIQJehjsxdaXogGfVv/D0crLhn85VCPOvELPrWbNZmVmOOWV3ClAoDnGZ30zGz9f3qRcaLFq8c2uN7OQ5BOu888042HatxPt/UVoagigTKwAdoUgjv5bdsAZGc3HfJumr7pji0918ruWNFGP5cbZg=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x42
    
    assert dictify(msg.certificate_bytes) == [180, 160, 116, 77, 243, 28, 173, 36, 86, 33, 8, 31, 120, 73, 64, 169, 148, 224, 57, 95, 17, 40, 213, 92, 195, 146, 235, 228, 177, 101, 82, 182, 25, 172, 170, 250, 236, 7, 119, 4, 201, 10, 14, 208, 47, 126, 49, 210, 174, 75, 221, 203, 24, 66, 52, 35, 26, 30, 140, 111, 246, 39, 226, 205, 198, 178, 196, 5, 81, 9, 44, 164, 163, 214, 138, 123, 76, 74, 237, 121, 13, 137, 186, 97, 193, 189, 200, 124, 69, 115, 230, 159, 185, 158, 51, 12, 225, 65, 192, 105, 56, 41, 85, 133, 19, 217, 166, 48, 139, 131, 96, 216, 98, 147, 132, 234, 167, 248, 247, 32, 239, 194, 188, 254, 114, 117, 83, 25, 251, 191, 104, 240, 118, 68, 42, 93, 18, 16, 37, 232, 99, 179, 23, 90, 94, 136, 6, 125, 91, 255, 15, 71, 43, 46, 25, 252, 229, 80, 143, 58, 241, 11, 62, 181, 155, 53, 153, 149, 152, 227, 150, 87, 112, 165, 2, 128, 231, 25, 157, 244, 204, 108, 253, 127, 122, 145, 113, 162, 197, 171, 199, 54, 184, 222, 206, 67, 144, 78, 187, 207, 60, 211, 141, 135, 106, 220, 79, 183, 245, 21, 161, 168, 34, 129, 50, 176, 1, 218, 20, 130, 59, 249, 109, 219, 0, 100, 103, 55, 29, 242, 110, 154, 190, 233, 142, 45, 61, 215, 202, 238, 88, 209, 70, 63, 151, 27, 102]
    
    assert dictify(msg.certificate_id) == [10, 11, 12, 13]
    
    assert dictify(msg.flags) == 2
    
    assert dictify(msg.n_msg) == 48

    assert dictify(msg) == {'preamble': 85, 'msg_type': 3076, 'sender': 66, 'length': 253, 'payload': 'MAoLDA0CtKB0TfMcrSRWIQgfeElAqZTgOV8RKNVcw5Lr5LFlUrYZrKr67Ad3BMkKDtAvfjHSrkvdyxhCNCMaHoxv9ifizcayxAVRCSyko9aKe0xK7XkNibphwb3IfEVz5p+5njMM4UHAaTgpVYUT2aYwi4Ng2GKThOqn+Pcg78K8/nJ1Uxn7v2jwdkQqXRIQJehjsxdaXogGfVv/D0crLhn85VCPOvELPrWbNZmVmOOWV3ClAoDnGZ30zGz9f3qRcaLFq8c2uN7OQ5BOu888042HatxPt/UVoagigTKwAdoUgjv5bdsAZGc3HfJumr7pji0918ruWNFGP5cbZg==', 'crc': 7899, 'n_msg': 48, 'certificate_id': [10, 11, 12, 13], 'flags': 2, 'certificate_bytes': [180, 160, 116, 77, 243, 28, 173, 36, 86, 33, 8, 31, 120, 73, 64, 169, 148, 224, 57, 95, 17, 40, 213, 92, 195, 146, 235, 228, 177, 101, 82, 182, 25, 172, 170, 250, 236, 7, 119, 4, 201, 10, 14, 208, 47, 126, 49, 210, 174, 75, 221, 203, 24, 66, 52, 35, 26, 30, 140, 111, 246, 39, 226, 205, 198, 178, 196, 5, 81, 9, 44, 164, 163, 214, 138, 123, 76, 74, 237, 121, 13, 137, 186, 97, 193, 189, 200, 124, 69, 115, 230, 159, 185, 158, 51, 12, 225, 65, 192, 105, 56, 41, 85, 133, 19, 217, 166, 48, 139, 131, 96, 216, 98, 147, 132, 234, 167, 248, 247, 32, 239, 194, 188, 254, 114, 117, 83, 25, 251, 191, 104, 240, 118, 68, 42, 93, 18, 16, 37, 232, 99, 179, 23, 90, 94, 136, 6, 125, 91, 255, 15, 71, 43, 46, 25, 252, 229, 80, 143, 58, 241, 11, 62, 181, 155, 53, 153, 149, 152, 227, 150, 87, 112, 165, 2, 128, 231, 25, 157, 244, 204, 108, 253, 127, 122, 145, 113, 162, 197, 171, 199, 54, 184, 222, 206, 67, 144, 78, 187, 207, 60, 211, 141, 135, 106, 220, 79, 183, 245, 21, 161, 168, 34, 129, 50, 176, 1, 218, 20, 130, 59, 249, 109, 219, 0, 100, 103, 55, 29, 242, 110, 154, 190, 233, 142, 45, 61, 215, 202, 238, 88, 209, 70, 63, 151, 27, 102]}