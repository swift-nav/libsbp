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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBounds.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import dictify
from kaitai.python.tests.utils_kaitai import get_flattened_msg
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_orbit_clock_bounds_1():
    buf = base64.standard_b64decode("Vd4FQgAftAAAAAMAAQIDMA8BAhgnJiUBAgMnAQMnJiUBAgMnARVV")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(kaitai_sbp.Sbp.SbpMessage(stream))
    
    assert msg.preamble == 0x55
    
    assert msg.msg_type == 0x05DE
    
    assert msg.sender == 0x0042
    
    assert msg.length == 31
    
    assert msg.payload == "tAAAAAMAAQIDMA8BAhgnJiUBAgMnAQMnJiUBAgMnAQ=="
    
    assert msg.crc == 0x5515
    
    assert dictify(msg.const_id) == 1
    
    assert dictify(msg.header) == {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'update_interval': 3, 'sol_id': 48}
    
    assert dictify(msg.n_sats) == 2
    
    assert dictify(msg.orbit_clock_bounds) == [{'sat_id': 24, 'orb_radial_bound_mu': 39, 'orb_along_bound_mu': 38, 'orb_cross_bound_mu': 37, 'orb_radial_bound_sig': 1, 'orb_along_bound_sig': 2, 'orb_cross_bound_sig': 3, 'clock_bound_mu': 39, 'clock_bound_sig': 1}, {'sat_id': 3, 'orb_radial_bound_mu': 39, 'orb_along_bound_mu': 38, 'orb_cross_bound_mu': 37, 'orb_radial_bound_sig': 1, 'orb_along_bound_sig': 2, 'orb_cross_bound_sig': 3, 'clock_bound_mu': 39, 'clock_bound_sig': 1}]
    
    assert dictify(msg.ssr_iod) == 15

    assert dictify(msg) == {'header': {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'update_interval': 3, 'sol_id': 48}, 'ssr_iod': 15, 'const_id': 1, 'n_sats': 2, 'orbit_clock_bounds': [{'sat_id': 24, 'orb_radial_bound_mu': 39, 'orb_along_bound_mu': 38, 'orb_cross_bound_mu': 37, 'orb_radial_bound_sig': 1, 'orb_along_bound_sig': 2, 'orb_cross_bound_sig': 3, 'clock_bound_mu': 39, 'clock_bound_sig': 1}, {'sat_id': 3, 'orb_radial_bound_mu': 39, 'orb_along_bound_mu': 38, 'orb_cross_bound_mu': 37, 'orb_radial_bound_sig': 1, 'orb_along_bound_sig': 2, 'orb_cross_bound_sig': 3, 'clock_bound_mu': 39, 'clock_bound_sig': 1}], 'preamble': 85, 'msg_type': 1502, 'sender': 66, 'length': 31, 'payload': 'tAAAAAMAAQIDMA8BAhgnJiUBAgMnAQMnJiUBAgMnAQ==', 'crc': 21781}