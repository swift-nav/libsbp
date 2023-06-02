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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepB.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_obs_dep_b_1():
    buf = base64.standard_b64decode("VUMA9tdneC4nAPsGILSvu4XfNQcHG50AAMoAAAA6jFWTWBy+B6+QAADLAAAA3Iz4itCsTQeHlwAA0AAAAK3CSIdzEhwH8pwAANQAAACkkGl8EsSJBnioAADZAAAAHujki9IHWgdXlgAA2gAAAKlV")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 55286, "msg_type": 67, "header": {"n_obs": 32, "t": {"wn": 1787, "tow": 2567800}}, "obs": [{"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 202}, "L": {"i": 117913055, "f": 27}, "cn0": 157, "P": 2243669940}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 203}, "L": {"i": 129899608, "f": 175}, "cn0": 144, "P": 2471857210}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 208}, "L": {"i": 122531024, "f": 135}, "cn0": 151, "P": 2331544796}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 212}, "L": {"i": 119280243, "f": 242}, "cn0": 156, "P": 2269692589}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 217}, "L": {"i": 109691922, "f": 120}, "cn0": 168, "P": 2087293092}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 218}, "L": {"i": 123340754, "f": 87}, "cn0": 150, "P": 2347034654}], "crc": 21929, "length": 103, "preamble": 85, "payload": "eC4nAPsGILSvu4XfNQcHG50AAMoAAAA6jFWTWBy+B6+QAADLAAAA3Iz4itCsTQeHlwAA0AAAAK3CSIdzEhwH8pwAANQAAACkkGl8EsSJBnioAADZAAAAHujki9IHWgdXlgAA2gAAAA=="}
    assert parsed_dict['crc'] == 0x55a9
    assert parsed_dict['length'] == 103
    assert parsed_dict['msg_type'] == 0x43
    assert parsed_dict['payload'] == "eC4nAPsGILSvu4XfNQcHG50AAMoAAAA6jFWTWBy+B6+QAADLAAAA3Iz4itCsTQeHlwAA0AAAAK3CSIdzEhwH8pwAANQAAACkkGl8EsSJBnioAADZAAAAHujki9IHWgdXlgAA2gAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.header) == snake_case_keys( {'n_obs': 32, 't': {'tow': 2567800, 'wn': 1787}} )
    assert dictify(obj.payload.obs) == snake_case_keys( [{'L': {'f': 27, 'i': 117913055}, 'P': 2243669940, 'cn0': 157, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'L': {'f': 175, 'i': 129899608}, 'P': 2471857210, 'cn0': 144, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'L': {'f': 135, 'i': 122531024}, 'P': 2331544796, 'cn0': 151, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'L': {'f': 242, 'i': 119280243}, 'P': 2269692589, 'cn0': 156, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'L': {'f': 120, 'i': 109691922}, 'P': 2087293092, 'cn0': 168, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'L': {'f': 87, 'i': 123340754}, 'P': 2347034654, 'cn0': 150, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}] )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_observation_msg_obs_dep_b_2():
    buf = base64.standard_b64decode("VUMA9tc3eC4nAPsGIUTHZYiF9yoH25oAANwAAADbDnuFYNcDB+ucAADeAAAAV6ZRegWtbQauqgAA4QAAAAvp")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 55286, "msg_type": 67, "header": {"n_obs": 33, "t": {"wn": 1787, "tow": 2567800}}, "obs": [{"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 220}, "L": {"i": 120256389, "f": 219}, "cn0": 154, "P": 2288371524}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 222}, "L": {"i": 117692256, "f": 235}, "cn0": 156, "P": 2239434459}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 225}, "L": {"i": 107851013, "f": 174}, "cn0": 170, "P": 2052171351}], "crc": 59659, "length": 55, "preamble": 85, "payload": "eC4nAPsGIUTHZYiF9yoH25oAANwAAADbDnuFYNcDB+ucAADeAAAAV6ZRegWtbQauqgAA4QAAAA=="}
    assert parsed_dict['crc'] == 0xe90b
    assert parsed_dict['length'] == 55
    assert parsed_dict['msg_type'] == 0x43
    assert parsed_dict['payload'] == "eC4nAPsGIUTHZYiF9yoH25oAANwAAADbDnuFYNcDB+ucAADeAAAAV6ZRegWtbQauqgAA4QAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.header) == snake_case_keys( {'n_obs': 33, 't': {'tow': 2567800, 'wn': 1787}} )
    assert dictify(obj.payload.obs) == snake_case_keys( [{'L': {'f': 219, 'i': 120256389}, 'P': 2288371524, 'cn0': 154, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'L': {'f': 235, 'i': 117692256}, 'P': 2239434459, 'cn0': 156, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'L': {'f': 174, 'i': 107851013}, 'P': 2052171351, 'cn0': 170, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}] )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_observation_msg_obs_dep_b_3():
    buf = base64.standard_b64decode("VUMA9tdnQC8nAPsGIGSEu4XsMwcHXpwAAMoAAABhuFWTsh6+ByiMAADLAAAAh2/4ilqrTQcClgAA0AAAALTuSIe+FBwH8ZsAANQAAAAPmWl8XMSJBpmoAADZAAAAMbnki5AFWgcplgAA2gAAAPFi")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 55286, "msg_type": 67, "header": {"n_obs": 32, "t": {"wn": 1787, "tow": 2568000}}, "obs": [{"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 202}, "L": {"i": 117912556, "f": 94}, "cn0": 156, "P": 2243658852}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 203}, "L": {"i": 129900210, "f": 40}, "cn0": 140, "P": 2471868513}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 208}, "L": {"i": 122530650, "f": 2}, "cn0": 150, "P": 2331537287}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 212}, "L": {"i": 119280830, "f": 241}, "cn0": 155, "P": 2269703860}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 217}, "L": {"i": 109691996, "f": 153}, "cn0": 168, "P": 2087295247}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 218}, "L": {"i": 123340176, "f": 41}, "cn0": 150, "P": 2347022641}], "crc": 25329, "length": 103, "preamble": 85, "payload": "QC8nAPsGIGSEu4XsMwcHXpwAAMoAAABhuFWTsh6+ByiMAADLAAAAh2/4ilqrTQcClgAA0AAAALTuSIe+FBwH8ZsAANQAAAAPmWl8XMSJBpmoAADZAAAAMbnki5AFWgcplgAA2gAAAA=="}
    assert parsed_dict['crc'] == 0x62f1
    assert parsed_dict['length'] == 103
    assert parsed_dict['msg_type'] == 0x43
    assert parsed_dict['payload'] == "QC8nAPsGIGSEu4XsMwcHXpwAAMoAAABhuFWTsh6+ByiMAADLAAAAh2/4ilqrTQcClgAA0AAAALTuSIe+FBwH8ZsAANQAAAAPmWl8XMSJBpmoAADZAAAAMbnki5AFWgcplgAA2gAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.header) == snake_case_keys( {'n_obs': 32, 't': {'tow': 2568000, 'wn': 1787}} )
    assert dictify(obj.payload.obs) == snake_case_keys( [{'L': {'f': 94, 'i': 117912556}, 'P': 2243658852, 'cn0': 156, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'L': {'f': 40, 'i': 129900210}, 'P': 2471868513, 'cn0': 140, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'L': {'f': 2, 'i': 122530650}, 'P': 2331537287, 'cn0': 150, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'L': {'f': 241, 'i': 119280830}, 'P': 2269703860, 'cn0': 155, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'L': {'f': 153, 'i': 109691996}, 'P': 2087295247, 'cn0': 168, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'L': {'f': 41, 'i': 123340176}, 'P': 2347022641, 'cn0': 150, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}] )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_observation_msg_obs_dep_b_4():
    buf = base64.standard_b64decode("VUMA9tc3QC8nAPsGIeqUZYgP9SoHFJoAANwAAADQ93qFENYDByacAADeAAAAD5ZRehasbQYHrAAA4QAAAMkN")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 55286, "msg_type": 67, "header": {"n_obs": 33, "t": {"wn": 1787, "tow": 2568000}}, "obs": [{"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 220}, "L": {"i": 120255759, "f": 20}, "cn0": 154, "P": 2288358634}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 222}, "L": {"i": 117691920, "f": 38}, "cn0": 156, "P": 2239428560}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 225}, "L": {"i": 107850774, "f": 7}, "cn0": 172, "P": 2052167183}], "crc": 3529, "length": 55, "preamble": 85, "payload": "QC8nAPsGIeqUZYgP9SoHFJoAANwAAADQ93qFENYDByacAADeAAAAD5ZRehasbQYHrAAA4QAAAA=="}
    assert parsed_dict['crc'] == 0xdc9
    assert parsed_dict['length'] == 55
    assert parsed_dict['msg_type'] == 0x43
    assert parsed_dict['payload'] == "QC8nAPsGIeqUZYgP9SoHFJoAANwAAADQ93qFENYDByacAADeAAAAD5ZRehasbQYHrAAA4QAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.header) == snake_case_keys( {'n_obs': 33, 't': {'tow': 2568000, 'wn': 1787}} )
    assert dictify(obj.payload.obs) == snake_case_keys( [{'L': {'f': 20, 'i': 120255759}, 'P': 2288358634, 'cn0': 154, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'L': {'f': 38, 'i': 117691920}, 'P': 2239428560, 'cn0': 156, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'L': {'f': 7, 'i': 107850774}, 'P': 2052167183, 'cn0': 172, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}] )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_observation_msg_obs_dep_b_5():
    buf = base64.standard_b64decode("VUMA9tdnCDAnAPsGIP5gu4X5MQcHpZwAAMoAAABx5VWTCyG+B2qPAADLAAAAtlX4iuOpTQeflgAA0AAAABEYSYcKFxwHB5wAANQAAABsm2l8psSJBrqqAADZAAAA1o7ki00DWgfslwAA2gAAADt2")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"sender": 55286, "msg_type": 67, "header": {"n_obs": 32, "t": {"wn": 1787, "tow": 2568200}}, "obs": [{"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 202}, "L": {"i": 117912057, "f": 165}, "cn0": 156, "P": 2243649790}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 203}, "L": {"i": 129900811, "f": 106}, "cn0": 143, "P": 2471880049}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 208}, "L": {"i": 122530275, "f": 159}, "cn0": 150, "P": 2331530678}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 212}, "L": {"i": 119281418, "f": 7}, "cn0": 156, "P": 2269714449}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 217}, "L": {"i": 109692070, "f": 186}, "cn0": 170, "P": 2087295852}, {"lock": 0, "sid": {"code": 0, "reserved": 0, "sat": 218}, "L": {"i": 123339597, "f": 236}, "cn0": 151, "P": 2347011798}], "crc": 30267, "length": 103, "preamble": 85, "payload": "CDAnAPsGIP5gu4X5MQcHpZwAAMoAAABx5VWTCyG+B2qPAADLAAAAtlX4iuOpTQeflgAA0AAAABEYSYcKFxwHB5wAANQAAABsm2l8psSJBrqqAADZAAAA1o7ki00DWgfslwAA2gAAAA=="}
    assert parsed_dict['crc'] == 0x763b
    assert parsed_dict['length'] == 103
    assert parsed_dict['msg_type'] == 0x43
    assert parsed_dict['payload'] == "CDAnAPsGIP5gu4X5MQcHpZwAAMoAAABx5VWTCyG+B2qPAADLAAAAtlX4iuOpTQeflgAA0AAAABEYSYcKFxwHB5wAANQAAABsm2l8psSJBrqqAADZAAAA1o7ki00DWgfslwAA2gAAAA=="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0xd7f6
    assert dictify(obj.payload.header) == snake_case_keys( {'n_obs': 32, 't': {'tow': 2568200, 'wn': 1787}} )
    assert dictify(obj.payload.obs) == snake_case_keys( [{'L': {'f': 165, 'i': 117912057}, 'P': 2243649790, 'cn0': 156, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'L': {'f': 106, 'i': 129900811}, 'P': 2471880049, 'cn0': 143, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'L': {'f': 159, 'i': 122530275}, 'P': 2331530678, 'cn0': 150, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'L': {'f': 7, 'i': 119281418}, 'P': 2269714449, 'cn0': 156, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'L': {'f': 186, 'i': 109692070}, 'P': 2087295852, 'cn0': 170, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'L': {'f': 236, 'i': 123339597}, 'P': 2347011798, 'cn0': 151, 'lock': 0, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}] )

    assert parsed_dict == snake_case_keys(orig_dict)