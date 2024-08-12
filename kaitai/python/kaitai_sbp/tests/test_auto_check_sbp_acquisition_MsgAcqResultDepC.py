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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepC.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_acquisition_msg_acq_result_dep_c_1():
    buf = base64.standard_b64decode("VR8AKAwQSAkiQpuY5EMcIt1ECgAAAAm9")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xbd09
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x1f
    
    assert msg.payload == "SAkiQpuY5EMcIt1ECgAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xc28
    
    assert dictify(msg.cf) == 1769.06591796875
    
    assert dictify(msg.cn0) == 40.509063720703125
    
    assert dictify(msg.cp) == 457.1922302246094
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 10}

    assert dictify(msg) == {'sender': 3112, 'msg_type': 31, 'cf': 1769.06591796875, 'cn0': 40.509063720703125, 'crc': 48393, 'length': 16, 'sid': {'code': 0, 'reserved': 0, 'sat': 10}, 'cp': 457.1922302246094, 'preamble': 85, 'payload': 'SAkiQpuY5EMcIt1ECgAAAA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_c_2():
    buf = base64.standard_b64decode("VR8AKAwQhPotQs9dWEREufzDBgAAAIi5")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xb988
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x1f
    
    assert msg.payload == "hPotQs9dWEREufzDBgAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xc28
    
    assert dictify(msg.cf) == -505.4473876953125
    
    assert dictify(msg.cn0) == 43.49464416503906
    
    assert dictify(msg.cp) == 865.4657592773438
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 6}

    assert dictify(msg) == {'sender': 3112, 'msg_type': 31, 'cf': -505.4473876953125, 'cn0': 43.49464416503906, 'crc': 47496, 'length': 16, 'sid': {'code': 0, 'reserved': 0, 'sat': 6}, 'cp': 865.4657592773438, 'preamble': 85, 'payload': 'hPotQs9dWEREufzDBgAAAA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_c_3():
    buf = base64.standard_b64decode("VR8AKAwQo98YQkBbZkPK853EDQAAAJah")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xa196
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x1f
    
    assert msg.payload == "o98YQkBbZkPK853EDQAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xc28
    
    assert dictify(msg.cf) == -1263.618408203125
    
    assert dictify(msg.cn0) == 38.2183952331543
    
    assert dictify(msg.cp) == 230.3564453125
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 13}

    assert dictify(msg) == {'sender': 3112, 'msg_type': 31, 'cf': -1263.618408203125, 'cn0': 38.2183952331543, 'crc': 41366, 'length': 16, 'sid': {'code': 0, 'reserved': 0, 'sat': 13}, 'cp': 230.3564453125, 'preamble': 85, 'payload': 'o98YQkBbZkPK853EDQAAAA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_c_4():
    buf = base64.standard_b64decode("VR8AKAwQgUEVQuDWfEPzij1FAQAAAG3R")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xd16d
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x1f
    
    assert msg.payload == "gUEVQuDWfEPzij1FAQAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xc28
    
    assert dictify(msg.cf) == 3032.684326171875
    
    assert dictify(msg.cn0) == 37.313968658447266
    
    assert dictify(msg.cp) == 252.83935546875
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 1}

    assert dictify(msg) == {'sender': 3112, 'msg_type': 31, 'cf': 3032.684326171875, 'cn0': 37.313968658447266, 'crc': 53613, 'length': 16, 'sid': {'code': 0, 'reserved': 0, 'sat': 1}, 'cp': 252.83935546875, 'preamble': 85, 'payload': 'gUEVQuDWfEPzij1FAQAAAA=='}

def test_auto_check_sbp_acquisition_msg_acq_result_dep_c_5():
    buf = base64.standard_b64decode("VR8AKAwQfiM+QuIlZkTK8x1FGwAAAFtD")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x435b
    
    assert msg.length == 16
    
    assert msg.msg_type == 0x1f
    
    assert msg.payload == "fiM+QuIlZkTK8x1FGwAAAA=="
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xc28
    
    assert dictify(msg.cf) == 2527.23681640625
    
    assert dictify(msg.cn0) == 47.53466033935547
    
    assert dictify(msg.cp) == 920.5919189453125
    
    assert dictify(msg.sid) == {'code': 0, 'reserved': 0, 'sat': 27}

    assert dictify(msg) == {'sender': 3112, 'msg_type': 31, 'cf': 2527.23681640625, 'cn0': 47.53466033935547, 'crc': 17243, 'length': 16, 'sid': {'code': 0, 'reserved': 0, 'sat': 27}, 'cp': 920.5919189453125, 'preamble': 85, 'payload': 'fiM+QuIlZkTK8x1FGwAAAA=='}