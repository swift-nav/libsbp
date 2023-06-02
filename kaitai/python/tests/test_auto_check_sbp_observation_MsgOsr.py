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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgOsr.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_osr_1():
    buf = base64.standard_b64decode("VUAGAADv+OHpHQAAAABoCEBLj/FE5vo+B0IPAwEADQAHAAcAzuhpP+wxqgZLDwMNAA0AAwADAC2Rxj4hB5kGgA8DDgANAAMAAwBZhMxDjy4gB38PAw8ADQAFAAUA9P6kPBawXwY3DwMRAAAAAgACAGqdZT6X1o4GbA8DEwANAAMAAwBR7Tw/tXelBs4PAxwADQADAAMAhuRuQLefxQbIDwMeAA0AAwADADWQ8UROcKUFqg8DAQYVAAcABwD76Gk/o4AxBYEPAw0GFQADAAMAcJHGPiUgJAUuDwMOBhUAAwADAKaEzEO4cI0FXw8DDwYVAAUABQB54w==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"header":{"t":{"tow":501867000,"ns_residual":0,"wn":2152},"n_obs":64},"obs":[{"P":1156681547,"L":{"i":121567974,"f":66},"lock":15,"flags":3,"sid":{"sat":1,"code":0},"iono_std":13,"tropo_std":7,"range_std":7},{"P":1063905486,"L":{"i":111817196,"f":75},"lock":15,"flags":3,"sid":{"sat":13,"code":0},"iono_std":13,"tropo_std":3,"range_std":3},{"P":1053200685,"L":{"i":110692129,"f":128},"lock":15,"flags":3,"sid":{"sat":14,"code":0},"iono_std":13,"tropo_std":3,"range_std":3},{"P":1137476697,"L":{"i":119549583,"f":127},"lock":15,"flags":3,"sid":{"sat":15,"code":0},"iono_std":13,"tropo_std":5,"range_std":5},{"P":1017446132,"L":{"i":106934294,"f":55},"lock":15,"flags":3,"sid":{"sat":17,"code":0},"iono_std":0,"tropo_std":2,"range_std":2},{"P":1046846826,"L":{"i":110024343,"f":108},"lock":15,"flags":3,"sid":{"sat":19,"code":0},"iono_std":13,"tropo_std":3,"range_std":3},{"P":1060957521,"L":{"i":111507381,"f":206},"lock":15,"flags":3,"sid":{"sat":28,"code":0},"iono_std":13,"tropo_std":3,"range_std":3},{"P":1081009286,"L":{"i":113614775,"f":200},"lock":15,"flags":3,"sid":{"sat":30,"code":0},"iono_std":13,"tropo_std":3,"range_std":3},{"P":1156681781,"L":{"i":94728270,"f":170},"lock":15,"flags":3,"sid":{"sat":1,"code":6},"iono_std":21,"tropo_std":7,"range_std":7},{"P":1063905531,"L":{"i":87130275,"f":129},"lock":15,"flags":3,"sid":{"sat":13,"code":6},"iono_std":21,"tropo_std":3,"range_std":3},{"P":1053200752,"L":{"i":86253605,"f":46},"lock":15,"flags":3,"sid":{"sat":14,"code":6},"iono_std":21,"tropo_std":3,"range_std":3},{"P":1137476774,"L":{"i":93155512,"f":95},"lock":15,"flags":3,"sid":{"sat":15,"code":6},"iono_std":21,"tropo_std":5,"range_std":5}],"preamble":85,"msg_type":1600,"sender":0,"payload":"+OHpHQAAAABoCEBLj/FE5vo+B0IPAwEADQAHAAcAzuhpP+wxqgZLDwMNAA0AAwADAC2Rxj4hB5kGgA8DDgANAAMAAwBZhMxDjy4gB38PAw8ADQAFAAUA9P6kPBawXwY3DwMRAAAAAgACAGqdZT6X1o4GbA8DEwANAAMAAwBR7Tw/tXelBs4PAxwADQADAAMAhuRuQLefxQbIDwMeAA0AAwADADWQ8UROcKUFqg8DAQYVAAcABwD76Gk/o4AxBYEPAw0GFQADAAMAcJHGPiUgJAUuDwMOBhUAAwADAKaEzEO4cI0FXw8DDwYVAAUABQA=","crc":58233,"length":239}
    assert parsed_dict['crc'] == 0xe379
    assert parsed_dict['length'] == 239
    assert parsed_dict['payload'] == "+OHpHQAAAABoCEBLj/FE5vo+B0IPAwEADQAHAAcAzuhpP+wxqgZLDwMNAA0AAwADAC2Rxj4hB5kGgA8DDgANAAMAAwBZhMxDjy4gB38PAw8ADQAFAAUA9P6kPBawXwY3DwMRAAAAAgACAGqdZT6X1o4GbA8DEwANAAMAAwBR7Tw/tXelBs4PAxwADQADAAMAhuRuQLefxQbIDwMeAA0AAwADADWQ8UROcKUFqg8DAQYVAAcABwD76Gk/o4AxBYEPAw0GFQADAAMAcJHGPiUgJAUuDwMOBhUAAwADAKaEzEO4cI0FXw8DDwYVAAUABQA="
    assert parsed_dict['msg_type'] == 0x640
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0
    assert dictify(obj.payload.header) == snake_case_keys( {'t': {'tow': 501867000, 'ns_residual': 0, 'wn': 2152}, 'n_obs': 64} )
    assert dictify(obj.payload.obs) == snake_case_keys( [{'P': 1156681547, 'L': {'i': 121567974, 'f': 66}, 'lock': 15, 'flags': 3, 'sid': {'sat': 1, 'code': 0}, 'iono_std': 13, 'tropo_std': 7, 'range_std': 7}, {'P': 1063905486, 'L': {'i': 111817196, 'f': 75}, 'lock': 15, 'flags': 3, 'sid': {'sat': 13, 'code': 0}, 'iono_std': 13, 'tropo_std': 3, 'range_std': 3}, {'P': 1053200685, 'L': {'i': 110692129, 'f': 128}, 'lock': 15, 'flags': 3, 'sid': {'sat': 14, 'code': 0}, 'iono_std': 13, 'tropo_std': 3, 'range_std': 3}, {'P': 1137476697, 'L': {'i': 119549583, 'f': 127}, 'lock': 15, 'flags': 3, 'sid': {'sat': 15, 'code': 0}, 'iono_std': 13, 'tropo_std': 5, 'range_std': 5}, {'P': 1017446132, 'L': {'i': 106934294, 'f': 55}, 'lock': 15, 'flags': 3, 'sid': {'sat': 17, 'code': 0}, 'iono_std': 0, 'tropo_std': 2, 'range_std': 2}, {'P': 1046846826, 'L': {'i': 110024343, 'f': 108}, 'lock': 15, 'flags': 3, 'sid': {'sat': 19, 'code': 0}, 'iono_std': 13, 'tropo_std': 3, 'range_std': 3}, {'P': 1060957521, 'L': {'i': 111507381, 'f': 206}, 'lock': 15, 'flags': 3, 'sid': {'sat': 28, 'code': 0}, 'iono_std': 13, 'tropo_std': 3, 'range_std': 3}, {'P': 1081009286, 'L': {'i': 113614775, 'f': 200}, 'lock': 15, 'flags': 3, 'sid': {'sat': 30, 'code': 0}, 'iono_std': 13, 'tropo_std': 3, 'range_std': 3}, {'P': 1156681781, 'L': {'i': 94728270, 'f': 170}, 'lock': 15, 'flags': 3, 'sid': {'sat': 1, 'code': 6}, 'iono_std': 21, 'tropo_std': 7, 'range_std': 7}, {'P': 1063905531, 'L': {'i': 87130275, 'f': 129}, 'lock': 15, 'flags': 3, 'sid': {'sat': 13, 'code': 6}, 'iono_std': 21, 'tropo_std': 3, 'range_std': 3}, {'P': 1053200752, 'L': {'i': 86253605, 'f': 46}, 'lock': 15, 'flags': 3, 'sid': {'sat': 14, 'code': 6}, 'iono_std': 21, 'tropo_std': 3, 'range_std': 3}, {'P': 1137476774, 'L': {'i': 93155512, 'f': 95}, 'lock': 15, 'flags': 3, 'sid': {'sat': 15, 'code': 6}, 'iono_std': 21, 'tropo_std': 5, 'range_std': 5}] )

    assert parsed_dict == snake_case_keys(orig_dict)