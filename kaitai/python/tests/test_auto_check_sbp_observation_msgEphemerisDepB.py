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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisDepB.yaml
# with generate.py.  Do not modify by hand!

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils import snake_case_keys
from kaitai.python.tests.utils_kaitai import kaitai2dict, dictify
from kaitaistruct import KaitaiStream
import io
import base64

def test_auto_check_sbp_observation_msg_ephemeris_dep_b_1():
    buf = base64.standard_b64decode("VUYAwwSwAAAAAAAAPL4AAAAAALpSwAAAAAAATG1AAAAAAACE0L4AAAAAAP7cPgAAAAAAAHE+AAAAAAAAhb4cJBlR3/40Ptx02CchvQNAAAAAnLHMhj8AAKDctiG0QJjhwCz+TO6/KZYYApScQb78WncwD9fwP3x/c17QEO4/pXM0SmGn9r0AAAAAwLTlvgAAAAAAAHC9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAwDhnA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"msg_type": 70, "c_rs": -74.90625, "toe_wn": 1838, "prn": 3, "inc_dot": -3.296565886629854e-10, "tgd": -6.51925802230835e-09, "c_rc": 234.375, "ecc": 0.011132609914056957, "sqrta": 5153.714303970337, "payload": "AAAAAAAAPL4AAAAAALpSwAAAAAAATG1AAAAAAACE0L4AAAAAAP7cPgAAAAAAAHE+AAAAAAAAhb4cJBlR3/40Ptx02CchvQNAAAAAnLHMhj8AAKDctiG0QJjhwCz+TO6/KZYYApScQb78WncwD9fwP3x/c17QEO4/pXM0SmGn9r0AAAAAwLTlvgAAAAAAAHC9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAwA=", "inc": 0.9395524830579087, "toe_tow": 410400.0, "c_uc": -3.937631845474243e-06, "c_us": 6.9122761487960815e-06, "valid": 1, "m0": 2.467348395627239, "toc_tow": 410400.0, "dn": 4.8884179079418005e-09, "omegadot": -8.201055892610478e-09, "toc_wn": 1838, "c_ic": 6.332993507385254e-08, "c_is": -1.564621925354004e-07, "preamble": 85, "sender": 1219, "healthy": 1, "iode": 0, "af1": -9.094947017729282e-13, "crc": 40161, "length": 176, "w": 1.0525047200405302, "af0": -1.035025343298912e-05, "omega0": -0.9468985437479658, "af2": 0.0}
    assert parsed_dict['crc'] == 0x9ce1
    assert parsed_dict['length'] == 176
    assert parsed_dict['msg_type'] == 0x46
    assert parsed_dict['payload'] == "AAAAAAAAPL4AAAAAALpSwAAAAAAATG1AAAAAAACE0L4AAAAAAP7cPgAAAAAAAHE+AAAAAAAAhb4cJBlR3/40Ptx02CchvQNAAAAAnLHMhj8AAKDctiG0QJjhwCz+TO6/KZYYApScQb78WncwD9fwP3x/c17QEO4/pXM0SmGn9r0AAAAAwLTlvgAAAAAAAHC9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAwA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.af0) == snake_case_keys( -1.035025343298912e-05 )
    assert dictify(obj.payload.af1) == snake_case_keys( -9.094947017729282e-13 )
    assert dictify(obj.payload.af2) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.c_ic) == snake_case_keys( 6.332993507385254e-08 )
    assert dictify(obj.payload.c_is) == snake_case_keys( -1.564621925354004e-07 )
    assert dictify(obj.payload.c_rc) == snake_case_keys( 234.375 )
    assert dictify(obj.payload.c_rs) == snake_case_keys( -74.90625 )
    assert dictify(obj.payload.c_uc) == snake_case_keys( -3.937631845474243e-06 )
    assert dictify(obj.payload.c_us) == snake_case_keys( 6.9122761487960815e-06 )
    assert dictify(obj.payload.dn) == snake_case_keys( 4.8884179079418005e-09 )
    assert dictify(obj.payload.ecc) == snake_case_keys( 0.011132609914056957 )
    assert dictify(obj.payload.healthy) == snake_case_keys( 1 )
    assert dictify(obj.payload.inc) == snake_case_keys( 0.9395524830579087 )
    assert dictify(obj.payload.inc_dot) == snake_case_keys( -3.296565886629854e-10 )
    assert dictify(obj.payload.iode) == snake_case_keys( 0 )
    assert dictify(obj.payload.m0) == snake_case_keys( 2.467348395627239 )
    assert dictify(obj.payload.omega0) == snake_case_keys( -0.9468985437479658 )
    assert dictify(obj.payload.omegadot) == snake_case_keys( -8.201055892610478e-09 )
    assert dictify(obj.payload.prn) == snake_case_keys( 3 )
    assert dictify(obj.payload.sqrta) == snake_case_keys( 5153.714303970337 )
    assert dictify(obj.payload.tgd) == snake_case_keys( -6.51925802230835e-09 )
    assert dictify(obj.payload.toc_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toc_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.toe_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toe_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.valid) == snake_case_keys( 1 )
    assert dictify(obj.payload.w) == snake_case_keys( 1.0525047200405302 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_observation_msg_ephemeris_dep_b_2():
    buf = base64.standard_b64decode("VUYAwwSwAAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQC0FQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"msg_type": 70, "c_rs": 36.5625, "toe_wn": 1838, "prn": 13, "inc_dot": 2.6251093463412166e-10, "tgd": -9.313225746154785e-09, "c_rc": 315.78125, "ecc": 0.007922741584479809, "sqrta": 5153.57085609436, "payload": "AAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQA=", "inc": 0.9669012918227122, "toe_tow": 410400.0, "c_uc": 2.0638108253479004e-06, "c_us": 3.4142285585403442e-06, "valid": 1, "m0": -1.588160855720083, "toc_tow": 410400.0, "dn": 4.86198823561129e-09, "omegadot": -8.295702692172441e-09, "toc_wn": 1838, "c_ic": 1.341104507446289e-07, "c_is": 1.1920928955078125e-07, "preamble": 85, "sender": 1219, "healthy": 1, "iode": 0, "af1": -2.8421709430404007e-12, "crc": 5556, "length": 176, "w": -1.9736022837941165, "af0": 7.384549826383591e-05, "omega0": 1.237919941568746, "af2": 0.0}
    assert parsed_dict['crc'] == 0x15b4
    assert parsed_dict['length'] == 176
    assert parsed_dict['msg_type'] == 0x46
    assert parsed_dict['payload'] == "AAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.af0) == snake_case_keys( 7.384549826383591e-05 )
    assert dictify(obj.payload.af1) == snake_case_keys( -2.8421709430404007e-12 )
    assert dictify(obj.payload.af2) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.c_ic) == snake_case_keys( 1.341104507446289e-07 )
    assert dictify(obj.payload.c_is) == snake_case_keys( 1.1920928955078125e-07 )
    assert dictify(obj.payload.c_rc) == snake_case_keys( 315.78125 )
    assert dictify(obj.payload.c_rs) == snake_case_keys( 36.5625 )
    assert dictify(obj.payload.c_uc) == snake_case_keys( 2.0638108253479004e-06 )
    assert dictify(obj.payload.c_us) == snake_case_keys( 3.4142285585403442e-06 )
    assert dictify(obj.payload.dn) == snake_case_keys( 4.86198823561129e-09 )
    assert dictify(obj.payload.ecc) == snake_case_keys( 0.007922741584479809 )
    assert dictify(obj.payload.healthy) == snake_case_keys( 1 )
    assert dictify(obj.payload.inc) == snake_case_keys( 0.9669012918227122 )
    assert dictify(obj.payload.inc_dot) == snake_case_keys( 2.6251093463412166e-10 )
    assert dictify(obj.payload.iode) == snake_case_keys( 0 )
    assert dictify(obj.payload.m0) == snake_case_keys( -1.588160855720083 )
    assert dictify(obj.payload.omega0) == snake_case_keys( 1.237919941568746 )
    assert dictify(obj.payload.omegadot) == snake_case_keys( -8.295702692172441e-09 )
    assert dictify(obj.payload.prn) == snake_case_keys( 13 )
    assert dictify(obj.payload.sqrta) == snake_case_keys( 5153.57085609436 )
    assert dictify(obj.payload.tgd) == snake_case_keys( -9.313225746154785e-09 )
    assert dictify(obj.payload.toc_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toc_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.toe_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toe_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.valid) == snake_case_keys( 1 )
    assert dictify(obj.payload.w) == snake_case_keys( -1.9736022837941165 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_observation_msg_ephemeris_dep_b_3():
    buf = base64.standard_b64decode("VUYAwwSwAAAAAAAAOD4AAAAAAChRwAAAAAAAgW1AAAAAAAAczb4AAAAAAEzfPgAAAAAAAGm+AAAAAAAAXL6God//8yszPpKwcY7qpAVAAAAAOK+McD8AAMBaqyG0QCQm7f/IoO2/zFw/mjFbQb59XvuEND3YPwKLHBvnx+4/fLcEtMIe970AAAAAAGjevgAAAAAAAGA9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAADemA==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"msg_type": 70, "c_rs": -68.625, "toe_wn": 1838, "prn": 0, "inc_dot": -3.3644258561271105e-10, "tgd": 5.587935447692871e-09, "c_rc": 236.03125, "ecc": 0.004040417145006359, "sqrta": 5153.669353485107, "payload": "AAAAAAAAOD4AAAAAAChRwAAAAAAAgW1AAAAAAAAczb4AAAAAAEzfPgAAAAAAAGm+AAAAAAAAXL6God//8yszPpKwcY7qpAVAAAAAOK+McD8AAMBaqyG0QCQm7f/IoO2/zFw/mjFbQb59XvuEND3YPwKLHBvnx+4/fLcEtMIe970AAAAAAGjevgAAAAAAAGA9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAAA=", "inc": 0.9619021920701416, "toe_tow": 410400.0, "c_uc": -3.470107913017273e-06, "c_us": 7.461756467819214e-06, "valid": 1, "m0": 2.7055255058713295, "toc_tow": 410400.0, "dn": 4.4637573619826565e-09, "omegadot": -8.082122367123182e-09, "toc_wn": 1838, "c_ic": -4.6566128730773926e-08, "c_is": -2.60770320892334e-08, "preamble": 85, "sender": 1219, "healthy": 1, "iode": 0, "af1": 4.547473508864641e-13, "crc": 39134, "length": 176, "w": 0.37873566614641857, "af0": -7.249414920806885e-06, "omega0": -0.9258770941316397, "af2": 0.0}
    assert parsed_dict['crc'] == 0x98de
    assert parsed_dict['length'] == 176
    assert parsed_dict['msg_type'] == 0x46
    assert parsed_dict['payload'] == "AAAAAAAAOD4AAAAAAChRwAAAAAAAgW1AAAAAAAAczb4AAAAAAEzfPgAAAAAAAGm+AAAAAAAAXL6God//8yszPpKwcY7qpAVAAAAAOK+McD8AAMBaqyG0QCQm7f/IoO2/zFw/mjFbQb59XvuEND3YPwKLHBvnx+4/fLcEtMIe970AAAAAAGjevgAAAAAAAGA9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBAAA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.af0) == snake_case_keys( -7.249414920806885e-06 )
    assert dictify(obj.payload.af1) == snake_case_keys( 4.547473508864641e-13 )
    assert dictify(obj.payload.af2) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.c_ic) == snake_case_keys( -4.6566128730773926e-08 )
    assert dictify(obj.payload.c_is) == snake_case_keys( -2.60770320892334e-08 )
    assert dictify(obj.payload.c_rc) == snake_case_keys( 236.03125 )
    assert dictify(obj.payload.c_rs) == snake_case_keys( -68.625 )
    assert dictify(obj.payload.c_uc) == snake_case_keys( -3.470107913017273e-06 )
    assert dictify(obj.payload.c_us) == snake_case_keys( 7.461756467819214e-06 )
    assert dictify(obj.payload.dn) == snake_case_keys( 4.4637573619826565e-09 )
    assert dictify(obj.payload.ecc) == snake_case_keys( 0.004040417145006359 )
    assert dictify(obj.payload.healthy) == snake_case_keys( 1 )
    assert dictify(obj.payload.inc) == snake_case_keys( 0.9619021920701416 )
    assert dictify(obj.payload.inc_dot) == snake_case_keys( -3.3644258561271105e-10 )
    assert dictify(obj.payload.iode) == snake_case_keys( 0 )
    assert dictify(obj.payload.m0) == snake_case_keys( 2.7055255058713295 )
    assert dictify(obj.payload.omega0) == snake_case_keys( -0.9258770941316397 )
    assert dictify(obj.payload.omegadot) == snake_case_keys( -8.082122367123182e-09 )
    assert dictify(obj.payload.prn) == snake_case_keys( 0 )
    assert dictify(obj.payload.sqrta) == snake_case_keys( 5153.669353485107 )
    assert dictify(obj.payload.tgd) == snake_case_keys( 5.587935447692871e-09 )
    assert dictify(obj.payload.toc_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toc_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.toe_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toe_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.valid) == snake_case_keys( 1 )
    assert dictify(obj.payload.w) == snake_case_keys( 0.37873566614641857 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_observation_msg_ephemeris_dep_b_4():
    buf = base64.standard_b64decode("VUYAwwSwAAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQC0FQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"msg_type": 70, "c_rs": 36.5625, "toe_wn": 1838, "prn": 13, "inc_dot": 2.6251093463412166e-10, "tgd": -9.313225746154785e-09, "c_rc": 315.78125, "ecc": 0.007922741584479809, "sqrta": 5153.57085609436, "payload": "AAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQA=", "inc": 0.9669012918227122, "toe_tow": 410400.0, "c_uc": 2.0638108253479004e-06, "c_us": 3.4142285585403442e-06, "valid": 1, "m0": -1.588160855720083, "toc_tow": 410400.0, "dn": 4.86198823561129e-09, "omegadot": -8.295702692172441e-09, "toc_wn": 1838, "c_ic": 1.341104507446289e-07, "c_is": 1.1920928955078125e-07, "preamble": 85, "sender": 1219, "healthy": 1, "iode": 0, "af1": -2.8421709430404007e-12, "crc": 5556, "length": 176, "w": -1.9736022837941165, "af0": 7.384549826383591e-05, "omega0": 1.237919941568746, "af2": 0.0}
    assert parsed_dict['crc'] == 0x15b4
    assert parsed_dict['length'] == 176
    assert parsed_dict['msg_type'] == 0x46
    assert parsed_dict['payload'] == "AAAAAAAARL4AAAAAAEhCQAAAAACAvHNAAAAAAABQwT4AAAAAAKTMPgAAAAAAAII+AAAAAAAAgD5ItX8G0OE0Pp6ugVsbafm/AAAAYMw5gD8AAKAjkiG0QPepASSFzvM/TwttXJzQQb5nTgP935P/v6TWWvra8O4/Xu+7JSQK8j0AAAAAsFsTPwAAAAAAAIm9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBDQA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.af0) == snake_case_keys( 7.384549826383591e-05 )
    assert dictify(obj.payload.af1) == snake_case_keys( -2.8421709430404007e-12 )
    assert dictify(obj.payload.af2) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.c_ic) == snake_case_keys( 1.341104507446289e-07 )
    assert dictify(obj.payload.c_is) == snake_case_keys( 1.1920928955078125e-07 )
    assert dictify(obj.payload.c_rc) == snake_case_keys( 315.78125 )
    assert dictify(obj.payload.c_rs) == snake_case_keys( 36.5625 )
    assert dictify(obj.payload.c_uc) == snake_case_keys( 2.0638108253479004e-06 )
    assert dictify(obj.payload.c_us) == snake_case_keys( 3.4142285585403442e-06 )
    assert dictify(obj.payload.dn) == snake_case_keys( 4.86198823561129e-09 )
    assert dictify(obj.payload.ecc) == snake_case_keys( 0.007922741584479809 )
    assert dictify(obj.payload.healthy) == snake_case_keys( 1 )
    assert dictify(obj.payload.inc) == snake_case_keys( 0.9669012918227122 )
    assert dictify(obj.payload.inc_dot) == snake_case_keys( 2.6251093463412166e-10 )
    assert dictify(obj.payload.iode) == snake_case_keys( 0 )
    assert dictify(obj.payload.m0) == snake_case_keys( -1.588160855720083 )
    assert dictify(obj.payload.omega0) == snake_case_keys( 1.237919941568746 )
    assert dictify(obj.payload.omegadot) == snake_case_keys( -8.295702692172441e-09 )
    assert dictify(obj.payload.prn) == snake_case_keys( 13 )
    assert dictify(obj.payload.sqrta) == snake_case_keys( 5153.57085609436 )
    assert dictify(obj.payload.tgd) == snake_case_keys( -9.313225746154785e-09 )
    assert dictify(obj.payload.toc_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toc_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.toe_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toe_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.valid) == snake_case_keys( 1 )
    assert dictify(obj.payload.w) == snake_case_keys( -1.9736022837941165 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_observation_msg_ephemeris_dep_b_5():
    buf = base64.standard_b64decode("VUYAwwSwAAAAAACAVb4AAAAAAJxFQAAAAACAE3NAAAAAAACgwT4AAAAAAJjPPgAAAAAAAGG+AAAAAADAi74aGg2VEJg2PmgHLtZLVAXAAAAAgOZShD8AAKD8oiG0QEkGgjbZq/I/UeCje+4qQr7OK41D850FwHGzmbsrXO4//uwfK+Cd9D0AAAAA6AQavwAAAAAAAIa9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBFgBjPQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"msg_type": 70, "c_rs": 43.21875, "toe_wn": 1838, "prn": 22, "inc_dot": 3.000124967247105e-10, "tgd": -2.0023435354232788e-08, "c_rc": 305.21875, "ecc": 0.009923744946718216, "sqrta": 5153.636667251587, "payload": "AAAAAACAVb4AAAAAAJxFQAAAAACAE3NAAAAAAACgwT4AAAAAAJjPPgAAAAAAAGG+AAAAAADAi74aGg2VEJg2PmgHLtZLVAXAAAAAgOZShD8AAKD8oiG0QEkGgjbZq/I/UeCje+4qQr7OK41D850FwHGzmbsrXO4//uwfK+Cd9D0AAAAA6AQavwAAAAAAAIa9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBFgA=", "inc": 0.9487513221807672, "toe_tow": 410400.0, "c_uc": 2.1010637283325195e-06, "c_us": 3.766268491744995e-06, "valid": 1, "m0": -2.666160271911327, "toc_tow": 410400.0, "dn": 5.26057626697412e-09, "omegadot": -8.45999524990264e-09, "toc_wn": 1838, "c_ic": -3.166496753692627e-08, "c_is": -2.0675361156463623e-07, "preamble": 85, "sender": 1219, "healthy": 1, "iode": 0, "af1": -2.5011104298755527e-12, "crc": 15715, "length": 176, "w": -2.7021241452652935, "af0": -9.925523772835732e-05, "omega0": 1.1669551972594425, "af2": 0.0}
    assert parsed_dict['crc'] == 0x3d63
    assert parsed_dict['length'] == 176
    assert parsed_dict['msg_type'] == 0x46
    assert parsed_dict['payload'] == "AAAAAACAVb4AAAAAAJxFQAAAAACAE3NAAAAAAACgwT4AAAAAAJjPPgAAAAAAAGG+AAAAAADAi74aGg2VEJg2PmgHLtZLVAXAAAAAgOZShD8AAKD8oiG0QEkGgjbZq/I/UeCje+4qQr7OK41D850FwHGzmbsrXO4//uwfK+Cd9D0AAAAA6AQavwAAAAAAAIa9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBFgA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.af0) == snake_case_keys( -9.925523772835732e-05 )
    assert dictify(obj.payload.af1) == snake_case_keys( -2.5011104298755527e-12 )
    assert dictify(obj.payload.af2) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.c_ic) == snake_case_keys( -3.166496753692627e-08 )
    assert dictify(obj.payload.c_is) == snake_case_keys( -2.0675361156463623e-07 )
    assert dictify(obj.payload.c_rc) == snake_case_keys( 305.21875 )
    assert dictify(obj.payload.c_rs) == snake_case_keys( 43.21875 )
    assert dictify(obj.payload.c_uc) == snake_case_keys( 2.1010637283325195e-06 )
    assert dictify(obj.payload.c_us) == snake_case_keys( 3.766268491744995e-06 )
    assert dictify(obj.payload.dn) == snake_case_keys( 5.26057626697412e-09 )
    assert dictify(obj.payload.ecc) == snake_case_keys( 0.009923744946718216 )
    assert dictify(obj.payload.healthy) == snake_case_keys( 1 )
    assert dictify(obj.payload.inc) == snake_case_keys( 0.9487513221807672 )
    assert dictify(obj.payload.inc_dot) == snake_case_keys( 3.000124967247105e-10 )
    assert dictify(obj.payload.iode) == snake_case_keys( 0 )
    assert dictify(obj.payload.m0) == snake_case_keys( -2.666160271911327 )
    assert dictify(obj.payload.omega0) == snake_case_keys( 1.1669551972594425 )
    assert dictify(obj.payload.omegadot) == snake_case_keys( -8.45999524990264e-09 )
    assert dictify(obj.payload.prn) == snake_case_keys( 22 )
    assert dictify(obj.payload.sqrta) == snake_case_keys( 5153.636667251587 )
    assert dictify(obj.payload.tgd) == snake_case_keys( -2.0023435354232788e-08 )
    assert dictify(obj.payload.toc_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toc_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.toe_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toe_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.valid) == snake_case_keys( 1 )
    assert dictify(obj.payload.w) == snake_case_keys( -2.7021241452652935 )

    assert parsed_dict == snake_case_keys(orig_dict)

def test_auto_check_sbp_observation_msg_ephemeris_dep_b_6():
    buf = base64.standard_b64decode("VUYAwwSwAAAAAAAATb4AAAAAAHpTwAAAAAAA6W5AAAAAAAA8z74AAAAAABzePgAAAAAAgHg+AAAAAAAAbD4K5reM1uYyPjZWxKT8Cv8/AAAAJPe/gD8AAKAFwSG0QLqKUYFY7wFAXtJ4qmoZQb5n1SCb48Lgv5wvaF1lN+8/xFNk/jM2BL4AAAAAMvI0PwAAAAAAAHK9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBHgCqIQ==")

    stream = KaitaiStream(io.BytesIO(buf))
    obj = kaitai_sbp.Sbp.SbpMessage(stream)

    parsed_dict = kaitai2dict(obj)
    orig_dict = {"msg_type": 70, "c_rs": -77.90625, "toe_wn": 1838, "prn": 30, "inc_dot": -5.882387882209502e-10, "tgd": -1.3504177331924438e-08, "c_rc": 247.28125, "ecc": 0.008178644930012524, "sqrta": 5153.7539920806885, "payload": "AAAAAAAATb4AAAAAAHpTwAAAAAAA6W5AAAAAAAA8z74AAAAAABzePgAAAAAAgHg+AAAAAAAAbD4K5reM1uYyPjZWxKT8Cv8/AAAAJPe/gD8AAKAFwSG0QLqKUYFY7wFAXtJ4qmoZQb5n1SCb48Lgv5wvaF1lN+8/xFNk/jM2BL4AAAAAMvI0PwAAAAAAAHK9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBHgA=", "inc": 0.9755122017245301, "toe_tow": 410400.0, "c_uc": -3.723427653312683e-06, "c_us": 7.178634405136108e-06, "valid": 1, "m0": 1.9401823459824192, "toc_tow": 410400.0, "dn": 4.400897600764146e-09, "omegadot": -7.962474526167494e-09, "toc_wn": 1838, "c_ic": 9.12696123123169e-08, "c_is": 5.21540641784668e-08, "preamble": 85, "sender": 1219, "healthy": 1, "iode": 0, "af1": -1.0231815394945443e-12, "crc": 8618, "length": 176, "w": -0.5237901716088061, "af0": 0.0003196117468178272, "omega0": 2.241868028927766, "af2": 0.0}
    assert parsed_dict['crc'] == 0x21aa
    assert parsed_dict['length'] == 176
    assert parsed_dict['msg_type'] == 0x46
    assert parsed_dict['payload'] == "AAAAAAAATb4AAAAAAHpTwAAAAAAA6W5AAAAAAAA8z74AAAAAABzePgAAAAAAgHg+AAAAAAAAbD4K5reM1uYyPjZWxKT8Cv8/AAAAJPe/gD8AAKAFwSG0QLqKUYFY7wFAXtJ4qmoZQb5n1SCb48Lgv5wvaF1lN+8/xFNk/jM2BL4AAAAAMvI0PwAAAAAAAHK9AAAAAAAAAAAAAAAAgAwZQS4HAAAAAIAMGUEuBwEBHgA="
    assert parsed_dict['preamble'] == 0x55
    assert parsed_dict['sender'] == 0x4c3
    assert dictify(obj.payload.af0) == snake_case_keys( 0.0003196117468178272 )
    assert dictify(obj.payload.af1) == snake_case_keys( -1.0231815394945443e-12 )
    assert dictify(obj.payload.af2) == snake_case_keys( 0.0 )
    assert dictify(obj.payload.c_ic) == snake_case_keys( 9.12696123123169e-08 )
    assert dictify(obj.payload.c_is) == snake_case_keys( 5.21540641784668e-08 )
    assert dictify(obj.payload.c_rc) == snake_case_keys( 247.28125 )
    assert dictify(obj.payload.c_rs) == snake_case_keys( -77.90625 )
    assert dictify(obj.payload.c_uc) == snake_case_keys( -3.723427653312683e-06 )
    assert dictify(obj.payload.c_us) == snake_case_keys( 7.178634405136108e-06 )
    assert dictify(obj.payload.dn) == snake_case_keys( 4.400897600764146e-09 )
    assert dictify(obj.payload.ecc) == snake_case_keys( 0.008178644930012524 )
    assert dictify(obj.payload.healthy) == snake_case_keys( 1 )
    assert dictify(obj.payload.inc) == snake_case_keys( 0.9755122017245301 )
    assert dictify(obj.payload.inc_dot) == snake_case_keys( -5.882387882209502e-10 )
    assert dictify(obj.payload.iode) == snake_case_keys( 0 )
    assert dictify(obj.payload.m0) == snake_case_keys( 1.9401823459824192 )
    assert dictify(obj.payload.omega0) == snake_case_keys( 2.241868028927766 )
    assert dictify(obj.payload.omegadot) == snake_case_keys( -7.962474526167494e-09 )
    assert dictify(obj.payload.prn) == snake_case_keys( 30 )
    assert dictify(obj.payload.sqrta) == snake_case_keys( 5153.7539920806885 )
    assert dictify(obj.payload.tgd) == snake_case_keys( -1.3504177331924438e-08 )
    assert dictify(obj.payload.toc_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toc_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.toe_tow) == snake_case_keys( 410400.0 )
    assert dictify(obj.payload.toe_wn) == snake_case_keys( 1838 )
    assert dictify(obj.payload.valid) == snake_case_keys( 1 )
    assert dictify(obj.payload.w) == snake_case_keys( -0.5237901716088061 )

    assert parsed_dict == snake_case_keys(orig_dict)