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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBoundsDegradation.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_ssr_msg_ssr_orbit_clock_bounds_degradation_1():
    buf = base64.standard_b64decode("Vd8FQgActAAAAAMAAQIDMA8BCgAAAAAAAADIx8bFxMPCwch1")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    payload = get_payload(obj)
    assert payload.preamble == 0x55
    assert payload.msg_type == 0x05DF
    assert payload.sender == 0x0042
    assert payload.length == 28
    assert payload.payload == "tAAAAAMAAQIDMA8BCgAAAAAAAADIx8bFxMPCwQ=="
    assert payload.crc == 0x75C8
    assert dictify(obj.payload.const_id) == snake_case_keys( 1 )
    assert dictify(obj.payload.header) == snake_case_keys( {'time': {'tow': 180, 'wn': 3}, 'num_msgs': 1, 'seq_num': 2, 'update_interval': 3, 'sol_id': 48} )
    assert dictify(obj.payload.orbit_clock_bounds_degradation) == snake_case_keys( {'orb_radial_bound_mu_dot': 200, 'orb_along_bound_mu_dot': 199, 'orb_cross_bound_mu_dot': 198, 'orb_radial_bound_sig_dot': 197, 'orb_along_bound_sig_dot': 196, 'orb_cross_bound_sig_dot': 195, 'clock_bound_mu_dot': 194, 'clock_bound_sig_dot': 193} )
    assert dictify(obj.payload.sat_bitmask) == snake_case_keys( 10 )
    assert dictify(obj.payload.ssr_iod) == snake_case_keys( 15 )

    assert dictify(payload) == snake_case_keys( {"header": {"time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 2, "update_interval": 3, "sol_id": 48}, "ssr_iod": 15, "const_id": 1, "sat_bitmask": 10, "orbit_clock_bounds_degradation": {"orb_radial_bound_mu_dot": 200, "orb_along_bound_mu_dot": 199, "orb_cross_bound_mu_dot": 199, "orb_cross_bound_mu_dot": 198, "orb_radial_bound_sig_dot": 197, "orb_along_bound_sig_dot": 196, "orb_cross_bound_sig_dot": 195, "clock_bound_mu_dot": 194, "clock_bound_sig_dot": 193}, "preamble": 85, "msg_type": 1503, "sender": 66, "length": 28, "payload": "tAAAAAMAAQIDMA8BCgAAAAAAAADIx8bFxMPCwQ==", "crc": 30152} )