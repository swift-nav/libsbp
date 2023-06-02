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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys, dictify
from kaitai.python.tests.utils_kaitai import get_payload
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_1():
    buf = base64.standard_b64decode("VREAO2c3o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACabW")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"track_flags": 11, "doppler": 15701, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 1319, "f": 169}, "pset_flags": 0, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACQ==", "recv_time": 7909447587, "acceleration": 108, "uptime": 1, "sender": 26427, "cn0": 177, "doppler_std": 39, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 54950, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}
    assert parsed_dict['crc'] == 0xd6a6
    assert parsed_dict['length'] == 55
    assert parsed_dict['msg_type'] == 0x11
    assert parsed_dict['payload'] == "o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x673b
    assert dictify(obj.payload.l) == snake_case_keys( {'f': 169, 'i': 1319} )
    assert dictify(obj.payload.p) == snake_case_keys( 0 )
    assert dictify(obj.payload.p_std) == snake_case_keys( 0 )
    assert dictify(obj.payload.acceleration) == snake_case_keys( 108 )
    assert dictify(obj.payload.clock_drift) == snake_case_keys( 0 )
    assert dictify(obj.payload.clock_offset) == snake_case_keys( 0 )
    assert dictify(obj.payload.cn0) == snake_case_keys( 177 )
    assert dictify(obj.payload.corr_spacing) == snake_case_keys( 40 )
    assert dictify(obj.payload.doppler) == snake_case_keys( 15701 )
    assert dictify(obj.payload.doppler_std) == snake_case_keys( 39 )
    assert dictify(obj.payload.lock) == snake_case_keys( 14032 )
    assert dictify(obj.payload.misc_flags) == snake_case_keys( 9 )
    assert dictify(obj.payload.nav_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.pset_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.recv_time) == snake_case_keys( 7909447587 )
    assert dictify(obj.payload.sid) == snake_case_keys( {'code': 0, 'reserved': 0, 'sat': 15} )
    assert dictify(obj.payload.sync_flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.tot) == snake_case_keys( {'tow': 0, 'wn': 0} )
    assert dictify(obj.payload.tow_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.track_flags) == snake_case_keys( 11 )
    assert dictify(obj.payload.uptime) == snake_case_keys( 1 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_2():
    buf = base64.standard_b64decode("VREAO2c3Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACYiz")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"track_flags": 11, "doppler": 15667, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 1810, "f": 14}, "pset_flags": 0, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACQ==", "recv_time": 8409447265, "acceleration": -32, "uptime": 1, "sender": 26427, "cn0": 175, "doppler_std": 30, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 45960, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}
    assert parsed_dict['crc'] == 0xb388
    assert parsed_dict['length'] == 55
    assert parsed_dict['msg_type'] == 0x11
    assert parsed_dict['payload'] == "Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x673b
    assert dictify(obj.payload.l) == snake_case_keys( {'f': 14, 'i': 1810} )
    assert dictify(obj.payload.p) == snake_case_keys( 0 )
    assert dictify(obj.payload.p_std) == snake_case_keys( 0 )
    assert dictify(obj.payload.acceleration) == snake_case_keys( -32 )
    assert dictify(obj.payload.clock_drift) == snake_case_keys( 0 )
    assert dictify(obj.payload.clock_offset) == snake_case_keys( 0 )
    assert dictify(obj.payload.cn0) == snake_case_keys( 175 )
    assert dictify(obj.payload.corr_spacing) == snake_case_keys( 40 )
    assert dictify(obj.payload.doppler) == snake_case_keys( 15667 )
    assert dictify(obj.payload.doppler_std) == snake_case_keys( 30 )
    assert dictify(obj.payload.lock) == snake_case_keys( 14032 )
    assert dictify(obj.payload.misc_flags) == snake_case_keys( 9 )
    assert dictify(obj.payload.nav_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.pset_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.recv_time) == snake_case_keys( 8409447265 )
    assert dictify(obj.payload.sid) == snake_case_keys( {'code': 0, 'reserved': 0, 'sat': 15} )
    assert dictify(obj.payload.sync_flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.tot) == snake_case_keys( {'tow': 0, 'wn': 0} )
    assert dictify(obj.payload.tow_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.track_flags) == snake_case_keys( 11 )
    assert dictify(obj.payload.uptime) == snake_case_keys( 1 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_3():
    buf = base64.standard_b64decode("VREAO2c3i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCdmf")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"track_flags": 11, "doppler": 15683, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 2298, "f": 8}, "pset_flags": 2, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCQ==", "recv_time": 8907446923, "acceleration": 27, "uptime": 2, "sender": 26427, "cn0": 179, "doppler_std": 22, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 40921, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}
    assert parsed_dict['crc'] == 0x9fd9
    assert parsed_dict['length'] == 55
    assert parsed_dict['msg_type'] == 0x11
    assert parsed_dict['payload'] == "i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x673b
    assert dictify(obj.payload.l) == snake_case_keys( {'f': 8, 'i': 2298} )
    assert dictify(obj.payload.p) == snake_case_keys( 0 )
    assert dictify(obj.payload.p_std) == snake_case_keys( 0 )
    assert dictify(obj.payload.acceleration) == snake_case_keys( 27 )
    assert dictify(obj.payload.clock_drift) == snake_case_keys( 0 )
    assert dictify(obj.payload.clock_offset) == snake_case_keys( 0 )
    assert dictify(obj.payload.cn0) == snake_case_keys( 179 )
    assert dictify(obj.payload.corr_spacing) == snake_case_keys( 40 )
    assert dictify(obj.payload.doppler) == snake_case_keys( 15683 )
    assert dictify(obj.payload.doppler_std) == snake_case_keys( 22 )
    assert dictify(obj.payload.lock) == snake_case_keys( 14032 )
    assert dictify(obj.payload.misc_flags) == snake_case_keys( 9 )
    assert dictify(obj.payload.nav_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.pset_flags) == snake_case_keys( 2 )
    assert dictify(obj.payload.recv_time) == snake_case_keys( 8907446923 )
    assert dictify(obj.payload.sid) == snake_case_keys( {'code': 0, 'reserved': 0, 'sat': 15} )
    assert dictify(obj.payload.sync_flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.tot) == snake_case_keys( {'tow': 0, 'wn': 0} )
    assert dictify(obj.payload.tow_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.track_flags) == snake_case_keys( 11 )
    assert dictify(obj.payload.uptime) == snake_case_keys( 2 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_4():
    buf = base64.standard_b64decode("VREAO2c3//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCUJf")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"track_flags": 11, "doppler": 15645, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 2786, "f": 125}, "pset_flags": 3, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCQ==", "recv_time": 9406446591, "acceleration": -36, "uptime": 2, "sender": 26427, "cn0": 181, "doppler_std": 10, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 24386, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}
    assert parsed_dict['crc'] == 0x5f42
    assert parsed_dict['length'] == 55
    assert parsed_dict['msg_type'] == 0x11
    assert parsed_dict['payload'] == "//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x673b
    assert dictify(obj.payload.l) == snake_case_keys( {'f': 125, 'i': 2786} )
    assert dictify(obj.payload.p) == snake_case_keys( 0 )
    assert dictify(obj.payload.p_std) == snake_case_keys( 0 )
    assert dictify(obj.payload.acceleration) == snake_case_keys( -36 )
    assert dictify(obj.payload.clock_drift) == snake_case_keys( 0 )
    assert dictify(obj.payload.clock_offset) == snake_case_keys( 0 )
    assert dictify(obj.payload.cn0) == snake_case_keys( 181 )
    assert dictify(obj.payload.corr_spacing) == snake_case_keys( 40 )
    assert dictify(obj.payload.doppler) == snake_case_keys( 15645 )
    assert dictify(obj.payload.doppler_std) == snake_case_keys( 10 )
    assert dictify(obj.payload.lock) == snake_case_keys( 14032 )
    assert dictify(obj.payload.misc_flags) == snake_case_keys( 9 )
    assert dictify(obj.payload.nav_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.pset_flags) == snake_case_keys( 3 )
    assert dictify(obj.payload.recv_time) == snake_case_keys( 9406446591 )
    assert dictify(obj.payload.sid) == snake_case_keys( {'code': 0, 'reserved': 0, 'sat': 15} )
    assert dictify(obj.payload.sync_flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.tot) == snake_case_keys( {'tow': 0, 'wn': 0} )
    assert dictify(obj.payload.tow_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.track_flags) == snake_case_keys( 11 )
    assert dictify(obj.payload.uptime) == snake_case_keys( 2 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_5():
    buf = base64.standard_b64decode("VREAO2c3vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCcLO")

    stream = KaitaiStream(io.BytesIO(buf))
    payload = kaitai_sbp.Sbp.SbpMessage(stream).get_payload()

    parsed_dict = dictify(payload)
    orig_dict = {"track_flags": 11, "doppler": 15640, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 3275, "f": 64}, "pset_flags": 3, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCQ==", "recv_time": 9906446269, "acceleration": 2, "uptime": 3, "sender": 26427, "cn0": 184, "doppler_std": 4, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 52930, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}
    assert parsed_dict['crc'] == 0xcec2
    assert parsed_dict['length'] == 55
    assert parsed_dict['msg_type'] == 0x11
    assert parsed_dict['payload'] == "vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCQ=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x673b
    assert dictify(obj.payload.l) == snake_case_keys( {'f': 64, 'i': 3275} )
    assert dictify(obj.payload.p) == snake_case_keys( 0 )
    assert dictify(obj.payload.p_std) == snake_case_keys( 0 )
    assert dictify(obj.payload.acceleration) == snake_case_keys( 2 )
    assert dictify(obj.payload.clock_drift) == snake_case_keys( 0 )
    assert dictify(obj.payload.clock_offset) == snake_case_keys( 0 )
    assert dictify(obj.payload.cn0) == snake_case_keys( 184 )
    assert dictify(obj.payload.corr_spacing) == snake_case_keys( 40 )
    assert dictify(obj.payload.doppler) == snake_case_keys( 15640 )
    assert dictify(obj.payload.doppler_std) == snake_case_keys( 4 )
    assert dictify(obj.payload.lock) == snake_case_keys( 14032 )
    assert dictify(obj.payload.misc_flags) == snake_case_keys( 9 )
    assert dictify(obj.payload.nav_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.pset_flags) == snake_case_keys( 3 )
    assert dictify(obj.payload.recv_time) == snake_case_keys( 9906446269 )
    assert dictify(obj.payload.sid) == snake_case_keys( {'code': 0, 'reserved': 0, 'sat': 15} )
    assert dictify(obj.payload.sync_flags) == snake_case_keys( 1 )
    assert dictify(obj.payload.tot) == snake_case_keys( {'tow': 0, 'wn': 0} )
    assert dictify(obj.payload.tow_flags) == snake_case_keys( 0 )
    assert dictify(obj.payload.track_flags) == snake_case_keys( 11 )
    assert dictify(obj.payload.uptime) == snake_case_keys( 3 )

    assert parsed_dict == snake_case_keys(orig_dict)