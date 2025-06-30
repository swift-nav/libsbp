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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_1():
    buf = base64.standard_b64decode("VREAO2c3o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACabW")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd6a6
    
    assert msg.length == 55
    
    assert msg.msg_type == 0x11
    
    assert msg.payload == "o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x673b
    
    assert dictify(msg.l) == {'f': 169, 'i': 1319}
    
    assert dictify(msg.p) == 0
    
    assert dictify(msg.p_std) == 0
    
    assert dictify(msg.acceleration) == 108
    
    assert dictify(msg.clock_drift) == 0
    
    assert dictify(msg.clock_offset) == 0
    
    assert dictify(msg.cn0) == 177
    
    assert dictify(msg.corr_spacing) == 40
    
    assert dictify(msg.doppler) == 15701
    
    assert dictify(msg.doppler_std) == 39
    
    assert dictify(msg.lock) == 14032
    
    assert dictify(msg.misc_flags) == 9
    
    assert dictify(msg.nav_flags) == 0
    
    assert dictify(msg.pset_flags) == 0
    
    assert dictify(msg.recv_time) == 7909447587
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 15}
    
    assert dictify(msg.sync_flags) == 1
    
    assert dictify(msg.tot) == {'tow': 0, 'wn': 0}
    
    assert dictify(msg.tow_flags) == 0
    
    assert dictify(msg.track_flags) == 11
    
    assert dictify(msg.uptime) == 1

    assert dictify(msg) == {'track_flags': 11, 'doppler': 15701, 'clock_offset': 0, 'msg_type': 17, 'lock': 14032, 'nav_flags': 0, 'p_std': 0, 'l': {'i': 1319, 'f': 169}, 'pset_flags': 0, 'p': 0, 'misc_flags': 9, 'preamble': 85, 'payload': 'o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACQ==', 'recv_time': 7909447587, 'acceleration': 108, 'uptime': 1, 'sender': 26427, 'cn0': 177, 'doppler_std': 39, 'tow_flags': 0, 'tot': {'wn': 0, 'tow': 0}, 'crc': 54950, 'length': 55, 'clock_drift': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 15}, 'sync_flags': 1, 'corr_spacing': 40}

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_2():
    buf = base64.standard_b64decode("VREAO2c3Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACYiz")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb388
    
    assert msg.length == 55
    
    assert msg.msg_type == 0x11
    
    assert msg.payload == "Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x673b
    
    assert dictify(msg.l) == {'f': 14, 'i': 1810}
    
    assert dictify(msg.p) == 0
    
    assert dictify(msg.p_std) == 0
    
    assert dictify(msg.acceleration) == -32
    
    assert dictify(msg.clock_drift) == 0
    
    assert dictify(msg.clock_offset) == 0
    
    assert dictify(msg.cn0) == 175
    
    assert dictify(msg.corr_spacing) == 40
    
    assert dictify(msg.doppler) == 15667
    
    assert dictify(msg.doppler_std) == 30
    
    assert dictify(msg.lock) == 14032
    
    assert dictify(msg.misc_flags) == 9
    
    assert dictify(msg.nav_flags) == 0
    
    assert dictify(msg.pset_flags) == 0
    
    assert dictify(msg.recv_time) == 8409447265
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 15}
    
    assert dictify(msg.sync_flags) == 1
    
    assert dictify(msg.tot) == {'tow': 0, 'wn': 0}
    
    assert dictify(msg.tow_flags) == 0
    
    assert dictify(msg.track_flags) == 11
    
    assert dictify(msg.uptime) == 1

    assert dictify(msg) == {'track_flags': 11, 'doppler': 15667, 'clock_offset': 0, 'msg_type': 17, 'lock': 14032, 'nav_flags': 0, 'p_std': 0, 'l': {'i': 1810, 'f': 14}, 'pset_flags': 0, 'p': 0, 'misc_flags': 9, 'preamble': 85, 'payload': 'Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACQ==', 'recv_time': 8409447265, 'acceleration': -32, 'uptime': 1, 'sender': 26427, 'cn0': 175, 'doppler_std': 30, 'tow_flags': 0, 'tot': {'wn': 0, 'tow': 0}, 'crc': 45960, 'length': 55, 'clock_drift': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 15}, 'sync_flags': 1, 'corr_spacing': 40}

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_3():
    buf = base64.standard_b64decode("VREAO2c3i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCdmf")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x9fd9
    
    assert msg.length == 55
    
    assert msg.msg_type == 0x11
    
    assert msg.payload == "i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x673b
    
    assert dictify(msg.l) == {'f': 8, 'i': 2298}
    
    assert dictify(msg.p) == 0
    
    assert dictify(msg.p_std) == 0
    
    assert dictify(msg.acceleration) == 27
    
    assert dictify(msg.clock_drift) == 0
    
    assert dictify(msg.clock_offset) == 0
    
    assert dictify(msg.cn0) == 179
    
    assert dictify(msg.corr_spacing) == 40
    
    assert dictify(msg.doppler) == 15683
    
    assert dictify(msg.doppler_std) == 22
    
    assert dictify(msg.lock) == 14032
    
    assert dictify(msg.misc_flags) == 9
    
    assert dictify(msg.nav_flags) == 0
    
    assert dictify(msg.pset_flags) == 2
    
    assert dictify(msg.recv_time) == 8907446923
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 15}
    
    assert dictify(msg.sync_flags) == 1
    
    assert dictify(msg.tot) == {'tow': 0, 'wn': 0}
    
    assert dictify(msg.tow_flags) == 0
    
    assert dictify(msg.track_flags) == 11
    
    assert dictify(msg.uptime) == 2

    assert dictify(msg) == {'track_flags': 11, 'doppler': 15683, 'clock_offset': 0, 'msg_type': 17, 'lock': 14032, 'nav_flags': 0, 'p_std': 0, 'l': {'i': 2298, 'f': 8}, 'pset_flags': 2, 'p': 0, 'misc_flags': 9, 'preamble': 85, 'payload': 'i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCQ==', 'recv_time': 8907446923, 'acceleration': 27, 'uptime': 2, 'sender': 26427, 'cn0': 179, 'doppler_std': 22, 'tow_flags': 0, 'tot': {'wn': 0, 'tow': 0}, 'crc': 40921, 'length': 55, 'clock_drift': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 15}, 'sync_flags': 1, 'corr_spacing': 40}

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_4():
    buf = base64.standard_b64decode("VREAO2c3//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCUJf")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x5f42
    
    assert msg.length == 55
    
    assert msg.msg_type == 0x11
    
    assert msg.payload == "//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x673b
    
    assert dictify(msg.l) == {'f': 125, 'i': 2786}
    
    assert dictify(msg.p) == 0
    
    assert dictify(msg.p_std) == 0
    
    assert dictify(msg.acceleration) == -36
    
    assert dictify(msg.clock_drift) == 0
    
    assert dictify(msg.clock_offset) == 0
    
    assert dictify(msg.cn0) == 181
    
    assert dictify(msg.corr_spacing) == 40
    
    assert dictify(msg.doppler) == 15645
    
    assert dictify(msg.doppler_std) == 10
    
    assert dictify(msg.lock) == 14032
    
    assert dictify(msg.misc_flags) == 9
    
    assert dictify(msg.nav_flags) == 0
    
    assert dictify(msg.pset_flags) == 3
    
    assert dictify(msg.recv_time) == 9406446591
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 15}
    
    assert dictify(msg.sync_flags) == 1
    
    assert dictify(msg.tot) == {'tow': 0, 'wn': 0}
    
    assert dictify(msg.tow_flags) == 0
    
    assert dictify(msg.track_flags) == 11
    
    assert dictify(msg.uptime) == 2

    assert dictify(msg) == {'track_flags': 11, 'doppler': 15645, 'clock_offset': 0, 'msg_type': 17, 'lock': 14032, 'nav_flags': 0, 'p_std': 0, 'l': {'i': 2786, 'f': 125}, 'pset_flags': 3, 'p': 0, 'misc_flags': 9, 'preamble': 85, 'payload': '//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCQ==', 'recv_time': 9406446591, 'acceleration': -36, 'uptime': 2, 'sender': 26427, 'cn0': 181, 'doppler_std': 10, 'tow_flags': 0, 'tot': {'wn': 0, 'tow': 0}, 'crc': 24386, 'length': 55, 'clock_drift': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 15}, 'sync_flags': 1, 'corr_spacing': 40}

def test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_5():
    buf = base64.standard_b64decode("VREAO2c3vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCcLO")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xcec2
    
    assert msg.length == 55
    
    assert msg.msg_type == 0x11
    
    assert msg.payload == "vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCQ=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0x673b
    
    assert dictify(msg.l) == {'f': 64, 'i': 3275}
    
    assert dictify(msg.p) == 0
    
    assert dictify(msg.p_std) == 0
    
    assert dictify(msg.acceleration) == 2
    
    assert dictify(msg.clock_drift) == 0
    
    assert dictify(msg.clock_offset) == 0
    
    assert dictify(msg.cn0) == 184
    
    assert dictify(msg.corr_spacing) == 40
    
    assert dictify(msg.doppler) == 15640
    
    assert dictify(msg.doppler_std) == 4
    
    assert dictify(msg.lock) == 14032
    
    assert dictify(msg.misc_flags) == 9
    
    assert dictify(msg.nav_flags) == 0
    
    assert dictify(msg.pset_flags) == 3
    
    assert dictify(msg.recv_time) == 9906446269
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 15}
    
    assert dictify(msg.sync_flags) == 1
    
    assert dictify(msg.tot) == {'tow': 0, 'wn': 0}
    
    assert dictify(msg.tow_flags) == 0
    
    assert dictify(msg.track_flags) == 11
    
    assert dictify(msg.uptime) == 3

    assert dictify(msg) == {'track_flags': 11, 'doppler': 15640, 'clock_offset': 0, 'msg_type': 17, 'lock': 14032, 'nav_flags': 0, 'p_std': 0, 'l': {'i': 3275, 'f': 64}, 'pset_flags': 3, 'p': 0, 'misc_flags': 9, 'preamble': 85, 'payload': 'vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCQ==', 'recv_time': 9906446269, 'acceleration': 2, 'uptime': 3, 'sender': 26427, 'cn0': 184, 'doppler_std': 4, 'tow_flags': 0, 'tot': {'wn': 0, 'tow': 0}, 'crc': 52930, 'length': 55, 'clock_drift': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 15}, 'sync_flags': 1, 'corr_spacing': 40}
