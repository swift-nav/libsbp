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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashProgram.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_flash_msg_flash_program_1():
    buf = base64.standard_b64decode("VeYAwwT/1Fc09Pqw3utqkB2N/wMQwO2s/tUE3GIi3ubWBtmsei4NJvDsPHkv/KON3h2o1nY3yekV1jn19hMDeTHnJbo67mInRuiFGQqGgUXkhglYt4Wr/6ZkmOdcCcRq9h2RnJcgQ7w/6Y6ui5p/Izw4u3lnh5i2WKD/4/A2ZFsfjWaC/jbj5T414Y9Yi37r6yM2hqNcOVeCshaeEu3Ru+IBLkDi69W6n926GXNUg6fJaAHIDTJHScHJ+qzBDRTugvNEBEguwnH/7g/mQLJ/2VygyXajkDocrkFJLXt2U2vvqCDUv1Fdut8gEzqJSNmX+1MUcSWXIiVHX2nrkKRTxf6331sTLeM=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xe32d
    
    assert msg.length == 255
    
    assert msg.msg_type == 0xe6
    
    assert msg.payload == "1Fc09Pqw3utqkB2N/wMQwO2s/tUE3GIi3ubWBtmsei4NJvDsPHkv/KON3h2o1nY3yekV1jn19hMDeTHnJbo67mInRuiFGQqGgUXkhglYt4Wr/6ZkmOdcCcRq9h2RnJcgQ7w/6Y6ui5p/Izw4u3lnh5i2WKD/4/A2ZFsfjWaC/jbj5T414Y9Yi37r6yM2hqNcOVeCshaeEu3Ru+IBLkDi69W6n926GXNUg6fJaAHIDTJHScHJ+qzBDRTugvNEBEguwnH/7g/mQLJ/2VygyXajkDocrkFJLXt2U2vvqCDUv1Fdut8gEzqJSNmX+1MUcSWXIiVHX2nrkKRTxf6331sT"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x04c3
    
    assert dictify(msg.addr_len) == 250
    
    assert dictify(msg.addr_start) == [87, 52, 244]
    
    assert dictify(msg.data) == [176, 222, 235, 106, 144, 29, 141, 255, 3, 16, 192, 237, 172, 254, 213, 4, 220, 98, 34, 222, 230, 214, 6, 217, 172, 122, 46, 13, 38, 240, 236, 60, 121, 47, 252, 163, 141, 222, 29, 168, 214, 118, 55, 201, 233, 21, 214, 57, 245, 246, 19, 3, 121, 49, 231, 37, 186, 58, 238, 98, 39, 70, 232, 133, 25, 10, 134, 129, 69, 228, 134, 9, 88, 183, 133, 171, 255, 166, 100, 152, 231, 92, 9, 196, 106, 246, 29, 145, 156, 151, 32, 67, 188, 63, 233, 142, 174, 139, 154, 127, 35, 60, 56, 187, 121, 103, 135, 152, 182, 88, 160, 255, 227, 240, 54, 100, 91, 31, 141, 102, 130, 254, 54, 227, 229, 62, 53, 225, 143, 88, 139, 126, 235, 235, 35, 54, 134, 163, 92, 57, 87, 130, 178, 22, 158, 18, 237, 209, 187, 226, 1, 46, 64, 226, 235, 213, 186, 159, 221, 186, 25, 115, 84, 131, 167, 201, 104, 1, 200, 13, 50, 71, 73, 193, 201, 250, 172, 193, 13, 20, 238, 130, 243, 68, 4, 72, 46, 194, 113, 255, 238, 15, 230, 64, 178, 127, 217, 92, 160, 201, 118, 163, 144, 58, 28, 174, 65, 73, 45, 123, 118, 83, 107, 239, 168, 32, 212, 191, 81, 93, 186, 223, 32, 19, 58, 137, 72, 217, 151, 251, 83, 20, 113, 37, 151, 34, 37, 71, 95, 105, 235, 144, 164, 83, 197, 254, 183, 223, 91, 19]
    
    assert dictify(msg.target) == 212

    assert dictify(msg) == {'crc': 58157, 'length': 255, 'msg_type': 230, 'payload': '1Fc09Pqw3utqkB2N/wMQwO2s/tUE3GIi3ubWBtmsei4NJvDsPHkv/KON3h2o1nY3yekV1jn19hMDeTHnJbo67mInRuiFGQqGgUXkhglYt4Wr/6ZkmOdcCcRq9h2RnJcgQ7w/6Y6ui5p/Izw4u3lnh5i2WKD/4/A2ZFsfjWaC/jbj5T414Y9Yi37r6yM2hqNcOVeCshaeEu3Ru+IBLkDi69W6n926GXNUg6fJaAHIDTJHScHJ+qzBDRTugvNEBEguwnH/7g/mQLJ/2VygyXajkDocrkFJLXt2U2vvqCDUv1Fdut8gEzqJSNmX+1MUcSWXIiVHX2nrkKRTxf6331sT', 'preamble': 85, 'sender': 1219, 'target': 212, 'addr_start': [87, 52, 244], 'addr_len': 250, 'data': [176, 222, 235, 106, 144, 29, 141, 255, 3, 16, 192, 237, 172, 254, 213, 4, 220, 98, 34, 222, 230, 214, 6, 217, 172, 122, 46, 13, 38, 240, 236, 60, 121, 47, 252, 163, 141, 222, 29, 168, 214, 118, 55, 201, 233, 21, 214, 57, 245, 246, 19, 3, 121, 49, 231, 37, 186, 58, 238, 98, 39, 70, 232, 133, 25, 10, 134, 129, 69, 228, 134, 9, 88, 183, 133, 171, 255, 166, 100, 152, 231, 92, 9, 196, 106, 246, 29, 145, 156, 151, 32, 67, 188, 63, 233, 142, 174, 139, 154, 127, 35, 60, 56, 187, 121, 103, 135, 152, 182, 88, 160, 255, 227, 240, 54, 100, 91, 31, 141, 102, 130, 254, 54, 227, 229, 62, 53, 225, 143, 88, 139, 126, 235, 235, 35, 54, 134, 163, 92, 57, 87, 130, 178, 22, 158, 18, 237, 209, 187, 226, 1, 46, 64, 226, 235, 213, 186, 159, 221, 186, 25, 115, 84, 131, 167, 201, 104, 1, 200, 13, 50, 71, 73, 193, 201, 250, 172, 193, 13, 20, 238, 130, 243, 68, 4, 72, 46, 194, 113, 255, 238, 15, 230, 64, 178, 127, 217, 92, 160, 201, 118, 163, 144, 58, 28, 174, 65, 73, 45, 123, 118, 83, 107, 239, 168, 32, 212, 191, 81, 93, 186, 223, 32, 19, 58, 137, 72, 217, 151, 251, 83, 20, 113, 37, 151, 34, 37, 71, 95, 105, 235, 144, 164, 83, 197, 254, 183, 223, 91, 19]}