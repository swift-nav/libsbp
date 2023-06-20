from __future__ import print_function

import sys

import io

import json
import struct
import binascii

from construct.core import StreamError

import sbp.msg
import sbp.table

from sbp.msg import SBP_PREAMBLE


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

SBP_HEADER_LEN = 6


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


# generator to produce SBP messages from a file object
def iter_messages(fp):
    buf = memoryview(bytearray(4096))
    unconsumed_offset = 0
    read_offset = 0
    buffer_remaining = len(buf)
    while True:
        if buffer_remaining == 0:
            buf[0:(read_offset - unconsumed_offset)] = buf[unconsumed_offset:read_offset]
            read_offset = read_offset - unconsumed_offset
            unconsumed_offset = 0
            buffer_remaining = len(buf) - read_offset
        mv = buf[read_offset:]
        read_length = fp.readinto(mv)
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

            if len(b) > 0 and b[0] != SBP_PREAMBLE:
                consumed = 1
            else:
                if len(b) < SBP_HEADER_LEN:
                    # insufficient data, keep retrying until enough data becomes
                    # available
                    consumed = 0
                else:
                    preamble, msg_type, sender, payload_len = struct.unpack("<BHHB", b[:SBP_HEADER_LEN])
                    if len(b) < SBP_HEADER_LEN + payload_len + 2:
                        # insufficient data, keep retrying until enough data becomes
                        # available
                        consumed = 0
                    else:
                        # check CRC
                        b = b[:SBP_HEADER_LEN + payload_len + 2]
                        crc_read, = struct.unpack("<H", b[SBP_HEADER_LEN + payload_len:SBP_HEADER_LEN + payload_len + 2])
                        crc_expected = binascii.crc_hqx(b[1:SBP_HEADER_LEN + payload_len], 0)
                        if crc_read == crc_expected:
                            yield msg_type, sender, payload_len, b, crc_read
                            consumed = SBP_HEADER_LEN + payload_len + 2
                        else:
                            sys.stderr.write("CRC error: {} vs {} for msg type {}\n".format(crc_read, crc_expected, msg_type))
                            consumed = 1

            if consumed == 0:
                break

            unconsumed_offset += consumed


def sbp_main(args):
    reader = io.open(args.file.fileno(), 'rb')
    include = set(args.include)

    for msg_type, sender, payload_len, buf, crc_read in iter_messages(reader):
        msg_buf = buf[SBP_HEADER_LEN:SBP_HEADER_LEN + payload_len]
        if not include or msg_type in include:
            try:
                msg = sbp.msg.SBP(msg_type, sender, payload_len, msg_buf, crc_read)
                msg = sbp.table.dispatch(msg)
                dump(args, msg)
            except (StreamError, ValueError):
                pass


def module_main():
    args = get_args()
    if not args:
        sys.exit(1)
    try:
        sbp_main(args)
    except KeyboardInterrupt:
        pass
