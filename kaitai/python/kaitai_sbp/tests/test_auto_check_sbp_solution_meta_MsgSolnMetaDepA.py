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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMetaDepA.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_solution_meta_msg_soln_meta_dep_a_1():
    buf = base64.standard_b64decode("VQ//VPH+t96deQWk7h++c107ZyRToZwu/UNXyCf69fLkSBLeC1jP2ucN4uAWxBXyDFlH27ZVkcySKMwzFZnjLA8c/yfN2PC+XdtnKim2TN4RF30fEuUcL9YZZFRqSDAK3ujrSW2jM5iF61dGAmxbZcg3GJzpSSdCYYz84+bth/H1zUYA27xriLI6AR0s1eGTvmDAbOQPyxID3rREZeXfy/OkXKXcn655cKfwKDsD5jSVlNqO1G2wR7OsTQHBRpOVF5CU78O6Vh4ij5zPPzd1/97e25Hgv9JtVpkVIOIKPD9q7F1gHqNq7pOFhGuY1t25yhX8M4I7psp/qjrB130WOocvWI5N0w==")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd34d
    
    assert msg.length == 254
    
    assert msg.msg_type == 0xff0f
    
    assert msg.payload == "t96deQWk7h++c107ZyRToZwu/UNXyCf69fLkSBLeC1jP2ucN4uAWxBXyDFlH27ZVkcySKMwzFZnjLA8c/yfN2PC+XdtnKim2TN4RF30fEuUcL9YZZFRqSDAK3ujrSW2jM5iF61dGAmxbZcg3GJzpSSdCYYz84+bth/H1zUYA27xriLI6AR0s1eGTvmDAbOQPyxID3rREZeXfy/OkXKXcn655cKfwKDsD5jSVlNqO1G2wR7OsTQHBRpOVF5CU78O6Vh4ij5zPPzd1/97e25Hgv9JtVpkVIOIKPD9q7F1gHqNq7pOFhGuY1t25yhX8M4I7psp/qjrB130WOocvWI4="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xf154
    
    assert dictify(msg.age_corrections) == 48671
    
    assert dictify(msg.alignment_status) == 115
    
    assert dictify(msg.hdop) == 31133
    
    assert dictify(msg.last_used_gnss_pos_tow) == 610745181
    
    assert dictify(msg.last_used_gnss_vel_tow) == 782016851
    
    assert dictify(msg.n_sats) == 238
    
    assert dictify(msg.pdop) == 57015
    
    assert dictify(msg.sol_in) == [{'flags': 67, 'sensor_type': 253}, {'flags': 200, 'sensor_type': 87}, {'flags': 250, 'sensor_type': 39}, {'flags': 242, 'sensor_type': 245}, {'flags': 72, 'sensor_type': 228}, {'flags': 222, 'sensor_type': 18}, {'flags': 88, 'sensor_type': 11}, {'flags': 218, 'sensor_type': 207}, {'flags': 13, 'sensor_type': 231}, {'flags': 224, 'sensor_type': 226}, {'flags': 196, 'sensor_type': 22}, {'flags': 242, 'sensor_type': 21}, {'flags': 89, 'sensor_type': 12}, {'flags': 219, 'sensor_type': 71}, {'flags': 85, 'sensor_type': 182}, {'flags': 204, 'sensor_type': 145}, {'flags': 40, 'sensor_type': 146}, {'flags': 51, 'sensor_type': 204}, {'flags': 153, 'sensor_type': 21}, {'flags': 44, 'sensor_type': 227}, {'flags': 28, 'sensor_type': 15}, {'flags': 39, 'sensor_type': 255}, {'flags': 216, 'sensor_type': 205}, {'flags': 190, 'sensor_type': 240}, {'flags': 219, 'sensor_type': 93}, {'flags': 42, 'sensor_type': 103}, {'flags': 182, 'sensor_type': 41}, {'flags': 222, 'sensor_type': 76}, {'flags': 23, 'sensor_type': 17}, {'flags': 31, 'sensor_type': 125}, {'flags': 229, 'sensor_type': 18}, {'flags': 47, 'sensor_type': 28}, {'flags': 25, 'sensor_type': 214}, {'flags': 84, 'sensor_type': 100}, {'flags': 72, 'sensor_type': 106}, {'flags': 10, 'sensor_type': 48}, {'flags': 232, 'sensor_type': 222}, {'flags': 73, 'sensor_type': 235}, {'flags': 163, 'sensor_type': 109}, {'flags': 152, 'sensor_type': 51}, {'flags': 235, 'sensor_type': 133}, {'flags': 70, 'sensor_type': 87}, {'flags': 108, 'sensor_type': 2}, {'flags': 101, 'sensor_type': 91}, {'flags': 55, 'sensor_type': 200}, {'flags': 156, 'sensor_type': 24}, {'flags': 73, 'sensor_type': 233}, {'flags': 66, 'sensor_type': 39}, {'flags': 140, 'sensor_type': 97}, {'flags': 227, 'sensor_type': 252}, {'flags': 237, 'sensor_type': 230}, {'flags': 241, 'sensor_type': 135}, {'flags': 205, 'sensor_type': 245}, {'flags': 0, 'sensor_type': 70}, {'flags': 188, 'sensor_type': 219}, {'flags': 136, 'sensor_type': 107}, {'flags': 58, 'sensor_type': 178}, {'flags': 29, 'sensor_type': 1}, {'flags': 213, 'sensor_type': 44}, {'flags': 147, 'sensor_type': 225}, {'flags': 96, 'sensor_type': 190}, {'flags': 108, 'sensor_type': 192}, {'flags': 15, 'sensor_type': 228}, {'flags': 18, 'sensor_type': 203}, {'flags': 222, 'sensor_type': 3}, {'flags': 68, 'sensor_type': 180}, {'flags': 229, 'sensor_type': 101}, {'flags': 203, 'sensor_type': 223}, {'flags': 164, 'sensor_type': 243}, {'flags': 165, 'sensor_type': 92}, {'flags': 159, 'sensor_type': 220}, {'flags': 121, 'sensor_type': 174}, {'flags': 167, 'sensor_type': 112}, {'flags': 40, 'sensor_type': 240}, {'flags': 3, 'sensor_type': 59}, {'flags': 52, 'sensor_type': 230}, {'flags': 148, 'sensor_type': 149}, {'flags': 142, 'sensor_type': 218}, {'flags': 109, 'sensor_type': 212}, {'flags': 71, 'sensor_type': 176}, {'flags': 172, 'sensor_type': 179}, {'flags': 1, 'sensor_type': 77}, {'flags': 70, 'sensor_type': 193}, {'flags': 149, 'sensor_type': 147}, {'flags': 144, 'sensor_type': 23}, {'flags': 239, 'sensor_type': 148}, {'flags': 186, 'sensor_type': 195}, {'flags': 30, 'sensor_type': 86}, {'flags': 143, 'sensor_type': 34}, {'flags': 207, 'sensor_type': 156}, {'flags': 55, 'sensor_type': 63}, {'flags': 255, 'sensor_type': 117}, {'flags': 222, 'sensor_type': 222}, {'flags': 145, 'sensor_type': 219}, {'flags': 191, 'sensor_type': 224}, {'flags': 109, 'sensor_type': 210}, {'flags': 153, 'sensor_type': 86}, {'flags': 32, 'sensor_type': 21}, {'flags': 10, 'sensor_type': 226}, {'flags': 63, 'sensor_type': 60}, {'flags': 236, 'sensor_type': 106}, {'flags': 96, 'sensor_type': 93}, {'flags': 163, 'sensor_type': 30}, {'flags': 238, 'sensor_type': 106}, {'flags': 133, 'sensor_type': 147}, {'flags': 107, 'sensor_type': 132}, {'flags': 214, 'sensor_type': 152}, {'flags': 185, 'sensor_type': 221}, {'flags': 21, 'sensor_type': 202}, {'flags': 51, 'sensor_type': 252}, {'flags': 59, 'sensor_type': 130}, {'flags': 202, 'sensor_type': 166}, {'flags': 170, 'sensor_type': 127}, {'flags': 193, 'sensor_type': 58}, {'flags': 125, 'sensor_type': 215}, {'flags': 58, 'sensor_type': 22}, {'flags': 47, 'sensor_type': 135}, {'flags': 142, 'sensor_type': 88}]
    
    assert dictify(msg.vdop) == 41989

    assert dictify(msg) == {'crc': 54093, 'length': 254, 'msg_type': 65295, 'payload': 't96deQWk7h++c107ZyRToZwu/UNXyCf69fLkSBLeC1jP2ucN4uAWxBXyDFlH27ZVkcySKMwzFZnjLA8c/yfN2PC+XdtnKim2TN4RF30fEuUcL9YZZFRqSDAK3ujrSW2jM5iF61dGAmxbZcg3GJzpSSdCYYz84+bth/H1zUYA27xriLI6AR0s1eGTvmDAbOQPyxID3rREZeXfy/OkXKXcn655cKfwKDsD5jSVlNqO1G2wR7OsTQHBRpOVF5CU78O6Vh4ij5zPPzd1/97e25Hgv9JtVpkVIOIKPD9q7F1gHqNq7pOFhGuY1t25yhX8M4I7psp/qjrB130WOocvWI4=', 'preamble': 85, 'sender': 61780, 'pdop': 57015, 'hdop': 31133, 'vdop': 41989, 'n_sats': 238, 'age_corrections': 48671, 'alignment_status': 115, 'last_used_gnss_pos_tow': 610745181, 'last_used_gnss_vel_tow': 782016851, 'sol_in': [{'sensor_type': 253, 'flags': 67}, {'sensor_type': 87, 'flags': 200}, {'sensor_type': 39, 'flags': 250}, {'sensor_type': 245, 'flags': 242}, {'sensor_type': 228, 'flags': 72}, {'sensor_type': 18, 'flags': 222}, {'sensor_type': 11, 'flags': 88}, {'sensor_type': 207, 'flags': 218}, {'sensor_type': 231, 'flags': 13}, {'sensor_type': 226, 'flags': 224}, {'sensor_type': 22, 'flags': 196}, {'sensor_type': 21, 'flags': 242}, {'sensor_type': 12, 'flags': 89}, {'sensor_type': 71, 'flags': 219}, {'sensor_type': 182, 'flags': 85}, {'sensor_type': 145, 'flags': 204}, {'sensor_type': 146, 'flags': 40}, {'sensor_type': 204, 'flags': 51}, {'sensor_type': 21, 'flags': 153}, {'sensor_type': 227, 'flags': 44}, {'sensor_type': 15, 'flags': 28}, {'sensor_type': 255, 'flags': 39}, {'sensor_type': 205, 'flags': 216}, {'sensor_type': 240, 'flags': 190}, {'sensor_type': 93, 'flags': 219}, {'sensor_type': 103, 'flags': 42}, {'sensor_type': 41, 'flags': 182}, {'sensor_type': 76, 'flags': 222}, {'sensor_type': 17, 'flags': 23}, {'sensor_type': 125, 'flags': 31}, {'sensor_type': 18, 'flags': 229}, {'sensor_type': 28, 'flags': 47}, {'sensor_type': 214, 'flags': 25}, {'sensor_type': 100, 'flags': 84}, {'sensor_type': 106, 'flags': 72}, {'sensor_type': 48, 'flags': 10}, {'sensor_type': 222, 'flags': 232}, {'sensor_type': 235, 'flags': 73}, {'sensor_type': 109, 'flags': 163}, {'sensor_type': 51, 'flags': 152}, {'sensor_type': 133, 'flags': 235}, {'sensor_type': 87, 'flags': 70}, {'sensor_type': 2, 'flags': 108}, {'sensor_type': 91, 'flags': 101}, {'sensor_type': 200, 'flags': 55}, {'sensor_type': 24, 'flags': 156}, {'sensor_type': 233, 'flags': 73}, {'sensor_type': 39, 'flags': 66}, {'sensor_type': 97, 'flags': 140}, {'sensor_type': 252, 'flags': 227}, {'sensor_type': 230, 'flags': 237}, {'sensor_type': 135, 'flags': 241}, {'sensor_type': 245, 'flags': 205}, {'sensor_type': 70, 'flags': 0}, {'sensor_type': 219, 'flags': 188}, {'sensor_type': 107, 'flags': 136}, {'sensor_type': 178, 'flags': 58}, {'sensor_type': 1, 'flags': 29}, {'sensor_type': 44, 'flags': 213}, {'sensor_type': 225, 'flags': 147}, {'sensor_type': 190, 'flags': 96}, {'sensor_type': 192, 'flags': 108}, {'sensor_type': 228, 'flags': 15}, {'sensor_type': 203, 'flags': 18}, {'sensor_type': 3, 'flags': 222}, {'sensor_type': 180, 'flags': 68}, {'sensor_type': 101, 'flags': 229}, {'sensor_type': 223, 'flags': 203}, {'sensor_type': 243, 'flags': 164}, {'sensor_type': 92, 'flags': 165}, {'sensor_type': 220, 'flags': 159}, {'sensor_type': 174, 'flags': 121}, {'sensor_type': 112, 'flags': 167}, {'sensor_type': 240, 'flags': 40}, {'sensor_type': 59, 'flags': 3}, {'sensor_type': 230, 'flags': 52}, {'sensor_type': 149, 'flags': 148}, {'sensor_type': 218, 'flags': 142}, {'sensor_type': 212, 'flags': 109}, {'sensor_type': 176, 'flags': 71}, {'sensor_type': 179, 'flags': 172}, {'sensor_type': 77, 'flags': 1}, {'sensor_type': 193, 'flags': 70}, {'sensor_type': 147, 'flags': 149}, {'sensor_type': 23, 'flags': 144}, {'sensor_type': 148, 'flags': 239}, {'sensor_type': 195, 'flags': 186}, {'sensor_type': 86, 'flags': 30}, {'sensor_type': 34, 'flags': 143}, {'sensor_type': 156, 'flags': 207}, {'sensor_type': 63, 'flags': 55}, {'sensor_type': 117, 'flags': 255}, {'sensor_type': 222, 'flags': 222}, {'sensor_type': 219, 'flags': 145}, {'sensor_type': 224, 'flags': 191}, {'sensor_type': 210, 'flags': 109}, {'sensor_type': 86, 'flags': 153}, {'sensor_type': 21, 'flags': 32}, {'sensor_type': 226, 'flags': 10}, {'sensor_type': 60, 'flags': 63}, {'sensor_type': 106, 'flags': 236}, {'sensor_type': 93, 'flags': 96}, {'sensor_type': 30, 'flags': 163}, {'sensor_type': 106, 'flags': 238}, {'sensor_type': 147, 'flags': 133}, {'sensor_type': 132, 'flags': 107}, {'sensor_type': 152, 'flags': 214}, {'sensor_type': 221, 'flags': 185}, {'sensor_type': 202, 'flags': 21}, {'sensor_type': 252, 'flags': 51}, {'sensor_type': 130, 'flags': 59}, {'sensor_type': 166, 'flags': 202}, {'sensor_type': 127, 'flags': 170}, {'sensor_type': 58, 'flags': 193}, {'sensor_type': 215, 'flags': 125}, {'sensor_type': 22, 'flags': 58}, {'sensor_type': 135, 'flags': 47}, {'sensor_type': 88, 'flags': 142}]}
