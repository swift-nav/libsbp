import sys
import pytest

if sys.version_info >= (3, 0):

    import numba as nb
    import numpy as np

    from sbp.file_io import MsgFileioWriteReq

    from sbp.jit.msg import unpack_payload

    from sbp.jit.msg import get_string
    from sbp.jit.msg import get_fixed_string

    from sbp.jit.table import dispatch


skip_on_py2 = pytest.mark.skipif(sys.version_info < (3, 0), reason="requires python 3")


def _mk_string(val, null='\x00'):
    ba = bytearray(val + (null if null is not None else ''), 'ascii')
    return np.array(ba, dtype=np.uint8)


@skip_on_py2
def test_get_string():
    s = _mk_string('thisisastring')
    out, offset, length = get_string(s, 0, len(s))
    assert len(out) == len('thisisastring')
    assert out == 'thisisastring'


@skip_on_py2
def test_get_string_no_null():
    s = _mk_string('thisisastring', null=None)
    out, offset, length = get_string(s, 0, len(s))
    assert len(out) == len('thisisastring')
    assert out == 'thisisastring'


@skip_on_py2
def test_get_string_offset_no_null():
    s = _mk_string('________thisisastring', null=None)
    out, offset, length = get_string(s, 8, len(s) - 8)
    assert len(out) == len('thisisastring')
    assert out == 'thisisastring'


@skip_on_py2
def test_get_string_offset():
    s = _mk_string('________thisisastring')
    out, offset, length = get_string(s, 8, len(s))
    assert len(out) == len('thisisastring')
    assert out == 'thisisastring'


@skip_on_py2
def test_get_fixed_string():
    s = 'main\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    a = np.fromstring(s, dtype=np.uint8)
    out, offset, length = get_fixed_string(len(s))(a, 0, len(a))
    assert len(out) == len(s)
    assert out == s


@skip_on_py2
def test_get_fixed_string_offset():
    s = _mk_string('________thisisastring')
    out, offset, length = get_fixed_string(6)(s, 8, len(s))
    assert len(out) == len('thisis')
    assert out == 'thisis'


@skip_on_py2
def test_parse():

    header_len = 6
    data = b'floofydata'

    m = MsgFileioWriteReq(
        sequence=123,
        offset=42,
        filename=b'floof.bin\0' + data,
        data=b'')

    buf = np.fromstring(m.to_binary(), dtype=np.uint8)

    assert len(buf) > 0

    pkt_len, payload_len, msg_type, sender, crc, crc_fail = unpack_payload(buf, 0, len(buf))
    assert not crc_fail

    m = dispatch(msg_type)(msg_type)
    res, offset, length = m.unpack(buf, header_len, payload_len)

    assert res is not None

    assert res['sequence'] == 123
    assert res['offset'] == 42
    assert res['filename'] == 'floof.bin'

    assert bytearray(res['data']) == bytearray(data)


@skip_on_py2
def test_jit():
    @nb.jit('Tuple((Tuple((u2,u2)),u2))()', nopython=True, nogil=True)
    def func():
        return ((123, 321), 42)
    ((x, y), z) = func()
