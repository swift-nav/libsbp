from __future__ import print_function

import sys

import io

import json

from construct.core import StreamError

import sbp.msg
import sbp.table

from sbp.msg import SBP_PREAMBLE
from sbp.msg import UnpackError


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


def base_cl_options():
    import argparse
    parser = argparse.ArgumentParser(prog="sbp2json", description="Swift Navigation SBP to JSON parser")
    parser.add_argument('--mode', type=str, choices=JSON_CHOICES, default=DEFAULT_JSON,
                        help="the JSON serialization library to use, default: {}".format(DEFAULT_JSON))
    parser.add_argument('--include', nargs="+", type=int, default=[],
                        help="list of SBP message IDs to include, empty means all")
    parser.add_argument('file', nargs='?', metavar='FILE', type=argparse.FileType('rb'),
                        default=sys.stdin, help="the input file, stdin by default")

    group_json = parser.add_argument_group('json specific arguments')
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

    return args


def dump(args, res):
    if 'json' == args.mode:
        sys.stdout.write(json.dumps(res.to_json_dict(),
                                    allow_nan=False,
                                    sort_keys=args.sort_keys,
                                    separators=(',', ':')))
    elif 'rapidjson' == args.mode:
        sys.stdout.write(rapidjson.dumps(res.to_json_dict()))
    sys.stdout.write("\n")


def sbp_main(args):
    header_len = 6
    reader = io.open(args.file.fileno(), 'rb')
    buf = memoryview(bytearray(4096))
    unconsumed_offset = 0
    read_offset = 0
    buffer_remaining = len(buf)
    include = set(args.include)
    while True:
        if buffer_remaining == 0:
            buf[0:(read_offset - unconsumed_offset)] = buf[unconsumed_offset:read_offset]
            read_offset = read_offset - unconsumed_offset
            unconsumed_offset = 0
            buffer_remaining = len(buf) - read_offset
        mv = buf[read_offset:]
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
            bytes_available = read_offset - unconsumed_offset
            b = buf[unconsumed_offset:(unconsumed_offset + bytes_available)]
            if len(b) == 0:
                break
            if b[0] != SBP_PREAMBLE:
                consumed = 1
            else:
                try:
                    m = sbp.msg.SBP.unpack(b)
                    if not include or m.msg_type in include:
                        m = sbp.table.dispatch(m)
                        dump(args, m)
                    consumed = header_len + m.length + 2
                except (UnpackError, StreamError, ValueError):
                    consumed = 1
            unconsumed_offset += consumed


def module_main():
    args = get_args()
    if not args:
        sys.exit(1)
    try:
        sbp_main(args)
    except KeyboardInterrupt:
        pass
