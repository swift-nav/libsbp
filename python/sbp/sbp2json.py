from __future__ import print_function

import os
import sys

import io

import json

import decimal as dec
from sbp.msg import SBP_PREAMBLE
from sbp import msg as msg_nojit
from sbp.table import dispatch as dispatch_nojit

SBP_NO_JIT = os.environ.get('SBP_NO_JIT', False)

if not SBP_NO_JIT:
    try:
        from sbp.jit import msg
        from sbp.jit.table import dispatch
    except ImportError:
        SBP_NO_JIT = True

try:
    import numpy as np
    HAS_NUMPY = True
    def get_buffer(size):
        return np.zeros(size, dtype=np.uint8)
except ImportError:
    HAS_NUMPY = False
    def get_buffer(size):
        return bytearray(size)

DEFAULT_JSON='rapidjson'
JSON_CHOICES=['json', 'rapidjson']
try:
    import rapidjson
except ImportError:
    DEFAULT_JSON='json'
    JSON_CHOICES=['json']

try:
    memoryview
except NameError:
    memoryview = lambda x: x

dec.getcontext().rounding = dec.ROUND_HALF_UP


def base_cl_options():
    import argparse
    parser = argparse.ArgumentParser(prog="sbp2json", description="Swift Navigation SBP to JSON parser")
    parser.add_argument('--mode', type=str, choices=JSON_CHOICES, default=DEFAULT_JSON)
    parser.add_argument('file', nargs='?', metavar='FILE', type=argparse.FileType('rb'),
                        default=sys.stdin, help="the input file, stdin by default")

    group_json = parser.add_argument_group('json specific arguments')
    if HAS_NUMPY and sys.version_info[0] >= 3:
        group_json.add_argument(
            "--judicious-rounding",
            action="store_true",
            help="Use Numpy's judicious rounding.")
    group_json.add_argument(
        "--sort-keys",
        action="store_true",
        help="Sort JSON log elements by keys")

    return parser


def get_args():
    """
    Get and parse arguments.
    """
    parser = base_cl_options()
    args = parser.parse_args()

    if args.mode == 'rapidjson' and getattr(args, 'judicious_rounding', False):
        print('ERROR: rapidjson mode does not support given arguments', file=sys.stderr)
        parser.print_help()
        return None

    return args


class SbpJSONEncoder(json.JSONEncoder):
    # Overwrite for json.JSONEncoder.iterencode()
    def iterencode(self, o, _one_shot=False):
        """Encode the given object and yield each string
        representation as available.
        For example::
            for chunk in JSONEncoder().iterencode(bigobject):
                mysocket.write(chunk)
        """
        if self.check_circular:
            markers = {}
        else:
            markers = None
        if self.ensure_ascii:
            _encoder = json.encoder.encode_basestring_ascii
        else:
            _encoder = json.encoder.encode_basestring

        def floatstr(o, allow_nan=self.allow_nan,
                     _repr=float.__repr__, _inf=float('inf'), _neginf=-float('inf')):
            # Check for specials.  Note that this type of test is processor
            # and/or platform-specific, so do tests which don't depend on the
            # internals.
            if o != o:
                text = 'NaN'
            elif o == _inf:
                text = 'Infinity'
            elif o == _neginf:
                text = '-Infinity'
            elif o.is_integer():
                return str(int(o))
            elif abs(o) < 0.1 or abs(o) > 9999999:
                # GHC uses showFloat to print which will result in the
                # scientific notation whenever the absolute value is outside the
                # range between 0.1 and 9,999,999. Numpy wants to put '+' after
                # exponent sign, strip it. Use decimal module to control
                # rounding method.
                text = np.format_float_scientific(o, precision=None, unique=True, trim='0', exp_digits=1)
                d = dec.Decimal(text)
                rounded = round(dec.Decimal(o), abs(d.as_tuple().exponent))

                if d == rounded:
                    # original is good
                    return text.replace('+', '')

                return ('{:.' + str(len(d.as_tuple().digits) - 1) + 'e}').format(rounded).replace('+', '')
            else:
                d = dec.Decimal(np.format_float_positional(o, precision=None, unique=True, trim='0'))
                return round(dec.Decimal(o), abs(d.as_tuple().exponent)).to_eng_string()

            if not allow_nan:
                raise ValueError(
                    "Out of range float values are not JSON compliant: " +
                    repr(o))

            return text

        _iterencode = json.encoder._make_iterencode(
            markers, self.default, _encoder, self.indent, floatstr,
            self.key_separator, self.item_separator, self.sort_keys,
            self.skipkeys, _one_shot)
        return _iterencode(o, 0)

def get_jsonable(res):
    if hasattr(res, 'to_json_dict'):
        return res.to_json_dict()
    return res


def dump(args, res):
    if 'json' == args.mode:
        if getattr(args, 'judicious_rounding', False):
            assert HAS_NUMPY, "The 'numpy' package is required for the --judicious-rounding option"
            encoder_cls=SbpJSONEncoder
        else:
            encoder_cls=None
        sys.stdout.write(json.dumps(get_jsonable(res),
                         allow_nan=False,
                         sort_keys=args.sort_keys,
                         separators=(',', ':'),
                         cls=encoder_cls))
    elif 'rapidjson' == args.mode:
        sys.stdout.write(rapidjson.dumps(get_jsonable(res)))
    sys.stdout.write("\n")


def configure_judicious_rounding(args):
    try:
        _m = msg
    except NameError:
        _m = msg_nojit
    _m.SBP.judicious_rounding = getattr(args, 'judicious_rounding', False)


def sbp_main(args):
    configure_judicious_rounding(args)
    header_len = 6
    reader = io.open(args.file.fileno(), 'rb')
    buf = get_buffer(4096)
    unconsumed_offset = 0
    read_offset = 0
    buffer_remaining = len(buf)
    while True:
        if buffer_remaining == 0:
            memoryview(buf)[0:(read_offset - unconsumed_offset)] = \
                memoryview(buf)[unconsumed_offset:read_offset]
            read_offset = read_offset - unconsumed_offset
            unconsumed_offset = 0
            buffer_remaining = len(buf) - read_offset
        mv = memoryview(buf)[read_offset:]
        read_length = reader.readinto(mv)
        if read_length == 0:
            unconsumed = read_offset - unconsumed_offset
            if unconsumed != 0:
                sys.stderr.write("unconsumed: {}\n".format(unconsumed))
                sys.stderr.flush()
            break
        read_offset += read_length
        buffer_remaining -= read_length
        while True:
            if SBP_NO_JIT:
                from construct.core import StreamError
                bytes_available = read_offset - unconsumed_offset
                b = buf[unconsumed_offset:(unconsumed_offset + bytes_available)]
                if len(b) == 0:
                    break
                if b[0] != SBP_PREAMBLE:
                    consumed = 1
                else:
                    try:
                        m = msg_nojit.SBP.unpack(b)
                        m = dispatch_nojit(m)
                        dump(args, m)
                        consumed = header_len + m.length + 2
                    except StreamError:
                        # Framing failed, find next preamble
                        consumed = 1
                    except ValueError as exc:
                        # CRC error, skip malformed message and find next preamble
                        consumed = header_len + exc.malformed_msg.length
            else:
                consumed, payload_len, msg_type, sender, crc, crc_fail = \
                    msg.unpack_payload(buf, unconsumed_offset, (read_offset - unconsumed_offset))
                if not crc_fail and msg_type != 0:
                    payload = buf[unconsumed_offset + header_len:unconsumed_offset + header_len + payload_len]
                    m = dispatch(msg_type)(msg_type, sender, payload_len, payload, crc)
                    res, offset, length = m.unpack(buf, unconsumed_offset + header_len, payload_len)
                    dump(args, res)
                if consumed == 0:
                    break
            unconsumed_offset += consumed


def module_main():
    args = get_args()
    if not args:
        sys.exit(1)
    try:
        sbp_main(args)
    except KeyboardInterrupt:
        pass
