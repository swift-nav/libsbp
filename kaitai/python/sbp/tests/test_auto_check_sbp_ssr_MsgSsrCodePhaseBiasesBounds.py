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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodePhaseBiasesBounds.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp.sbp as sbp
from kaitai.python.sbp.parse_utils import get_flattened_msg
from kaitai.python.sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_code_phase_biases_bounds_1():
    buf = base64.standard_b64decode("VewFQgAftAAAAAMAAQIBDg8BAwADJwEnAQEDJwEnAQEBJwEnARdx")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x05EC
    
    assert msg.sender == 0x0042
    
    assert msg.length == 31
    
    assert msg.payload == "tAAAAAMAAQIBDg8BAwADJwEnAQEDJwEnAQEBJwEnAQ=="
    
    assert msg.crc == 0x7117
    
    assert dictify(msg.const_id) == 1
    
    assert dictify(msg.header) == {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'update_interval': 1, 'sol_id': 14}
    
    assert dictify(msg.n_sats_signals) == 3
    
    assert dictify(msg.satellites_signals) == [{'sat_id': 0, 'signal_id': 3, 'code_bias_bound_mu': 39, 'code_bias_bound_sig': 1, 'phase_bias_bound_mu': 39, 'phase_bias_bound_sig': 1}, {'sat_id': 1, 'signal_id': 3, 'code_bias_bound_mu': 39, 'code_bias_bound_sig': 1, 'phase_bias_bound_mu': 39, 'phase_bias_bound_sig': 1}, {'sat_id': 1, 'signal_id': 1, 'code_bias_bound_mu': 39, 'code_bias_bound_sig': 1, 'phase_bias_bound_mu': 39, 'phase_bias_bound_sig': 1}]
    
    assert dictify(msg.ssr_iod) == 15

    assert dictify(msg) == {'header': {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'update_interval': 1, 'sol_id': 14}, 'ssr_iod': 15, 'const_id': 1, 'n_sats_signals': 3, 'satellites_signals': [{'sat_id': 0, 'signal_id': 3, 'code_bias_bound_mu': 39, 'code_bias_bound_sig': 1, 'phase_bias_bound_mu': 39, 'phase_bias_bound_sig': 1}, {'sat_id': 1, 'signal_id': 3, 'code_bias_bound_mu': 39, 'code_bias_bound_sig': 1, 'phase_bias_bound_mu': 39, 'phase_bias_bound_sig': 1}, {'sat_id': 1, 'signal_id': 1, 'code_bias_bound_mu': 39, 'code_bias_bound_sig': 1, 'phase_bias_bound_mu': 39, 'phase_bias_bound_sig': 1}], 'preamble': 85, 'msg_type': 1516, 'sender': 66, 'length': 31, 'payload': 'tAAAAAMAAQIBDg8BAwADJwEnAQEDJwEnAQEBJwEnAQ==', 'crc': 28951}