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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml
# with generate.py.  Do not modify by hand!

import kaitai_sbp.sbp as sbp
from kaitai_sbp.parse_utils import get_flattened_msg
from kaitai_sbp.tests.utils import dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_tracking_msg_tracking_state_1():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/3mE=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x61de
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 39.24782180786133, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 36.09756088256836, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 37.62678527832031, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 39.020729064941406, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 42.03290557861328, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.43546676635742, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 38.4229621887207, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 38.91520309448242, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.62259292602539, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 39.24782180786133, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 36.09756088256836, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 37.62678527832031, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 39.020729064941406, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 42.03290557861328, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.43546676635742, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 38.4229621887207, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 38.91520309448242, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.62259292602539, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 25054, 'length': 99, 'preamble': 85, 'payload': 'AcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/'}

def test_auto_check_sbp_tracking_msg_tracking_state_2():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/FB8=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x1f14
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 38.994117736816406, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 34.889801025390625, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 37.44603729248047, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 38.72849655151367, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 41.983219146728516, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.46448516845703, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 38.44300079345703, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 39.03423309326172, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.89944839477539, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 38.994117736816406, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 34.889801025390625, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 37.44603729248047, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 38.72849655151367, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 41.983219146728516, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.46448516845703, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 38.44300079345703, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 39.03423309326172, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.89944839477539, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 7956, 'length': 99, 'preamble': 85, 'payload': 'AcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/'}

def test_auto_check_sbp_tracking_msg_tracking_state_3():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/6Uc=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x47e9
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 38.95457077026367, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 35.813316345214844, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 37.553924560546875, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 38.88901901245117, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 42.4013557434082, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.63916015625, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 37.919986724853516, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 39.25254440307617, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.59827423095703, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 38.95457077026367, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 35.813316345214844, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 37.553924560546875, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 38.88901901245117, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 42.4013557434082, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.63916015625, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 37.919986724853516, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 39.25254440307617, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.59827423095703, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 18409, 'length': 99, 'preamble': 85, 'payload': 'AcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/'}

def test_auto_check_sbp_tracking_msg_tracking_state_4():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/ScE=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0xc149
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 39.369598388671875, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 36.52173614501953, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 38.15976333618164, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 39.19989776611328, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 41.55845642089844, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.026981353759766, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 38.1049690246582, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 39.04584503173828, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.37783432006836, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 39.369598388671875, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 36.52173614501953, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 38.15976333618164, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 39.19989776611328, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 41.55845642089844, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.026981353759766, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 38.1049690246582, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 39.04584503173828, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.37783432006836, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 49481, 'length': 99, 'preamble': 85, 'payload': 'AcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/'}

def test_auto_check_sbp_tracking_msg_tracking_state_5():
    buf = base64.standard_b64decode("VRMA9tdjAcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/fi8=")

    stream = KaitaiStream(io.BytesIO(buf))
    msg = get_flattened_msg(sbp.Sbp.SbpMessage(stream))
    
    assert msg.crc == 0x2f7e
    
    assert msg.length == 99
    
    assert msg.msg_type == 0x13
    
    assert msg.payload == "AcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/"
    
    assert msg.preamble == 0x55
    
    assert msg.sender == 0xd7f6
    
    assert dictify(msg.states) == [{'cn0': 39.70351791381836, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}, 'state': 1}, {'cn0': 36.52388381958008, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}, 'state': 1}, {'cn0': 37.169708251953125, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}, 'state': 1}, {'cn0': 38.81692886352539, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}, 'state': 1}, {'cn0': 42.05073165893555, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}, 'state': 1}, {'cn0': 37.807498931884766, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}, 'state': 1}, {'cn0': 37.71632385253906, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}, 'state': 1}, {'cn0': 38.5289192199707, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}, 'state': 1}, {'cn0': 42.27101516723633, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}, 'state': 1}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}, {'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}, 'state': 0}]

    assert dictify(msg) == {'sender': 55286, 'msg_type': 19, 'states': [{'state': 1, 'cn0': 39.70351791381836, 'sid': {'code': 0, 'reserved': 0, 'sat': 202}}, {'state': 1, 'cn0': 36.52388381958008, 'sid': {'code': 0, 'reserved': 0, 'sat': 203}}, {'state': 1, 'cn0': 37.169708251953125, 'sid': {'code': 0, 'reserved': 0, 'sat': 208}}, {'state': 1, 'cn0': 38.81692886352539, 'sid': {'code': 0, 'reserved': 0, 'sat': 212}}, {'state': 1, 'cn0': 42.05073165893555, 'sid': {'code': 0, 'reserved': 0, 'sat': 217}}, {'state': 1, 'cn0': 37.807498931884766, 'sid': {'code': 0, 'reserved': 0, 'sat': 218}}, {'state': 1, 'cn0': 37.71632385253906, 'sid': {'code': 0, 'reserved': 0, 'sat': 220}}, {'state': 1, 'cn0': 38.5289192199707, 'sid': {'code': 0, 'reserved': 0, 'sat': 222}}, {'state': 1, 'cn0': 42.27101516723633, 'sid': {'code': 0, 'reserved': 0, 'sat': 225}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}, {'state': 0, 'cn0': -1.0, 'sid': {'code': 0, 'reserved': 0, 'sat': 0}}], 'crc': 12158, 'length': 99, 'preamble': 85, 'payload': 'AcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/'}