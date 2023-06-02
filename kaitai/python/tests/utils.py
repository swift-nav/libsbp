# Utilities for tests cases for the python version of the Kaitai Struct SBP
# parser

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils_kaitai import get_next_msg_kaitai, kaitai2dict
from kaitaistruct import KaitaiStream
import json
import binascii
import struct
import sys
import io
import sbp.msg
import sbp.table
from sbp.msg import SBP_PREAMBLE
import re

SBP_HEADER_LEN = 6


# convert CamelCase to snake_case
def snake_case(s):
  if "_" in s:
    return "_".join(snake_case(p) for p in s.split("_"))
  if len(s) == 1:
    return s.lower()
  s = re.sub("(.)([A-Z][a-z]+)", r"\1_\2", s)
  return re.sub("([a-z0-9])([A-Z])", r"\1_\2", s).lower()


# convert all keys in a dict to snake_case
def snake_case_keys(x):
   if isinstance(x, list):
     return [snake_case_keys(v) for v in x]
   elif isinstance(x, dict):
     return dict((snake_case(k), snake_case_keys(v)) for k, v in x.items())
   else:
     return x


# adapted from construct-based python version of sbp2json
def parse_file_construct(fp):
    buf = bytearray(4096)
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

            msg_type = None
            if len(b) > 0 and b[0] != sbp.msg.SBP_PREAMBLE:
                consumed = 1
            else:
                if len(b) < SBP_HEADER_LEN:
                    # insufficient data, keep retrying until enough data becomes
                    # available
                    consumed = 0
                else:
                    preamble, msg_type, sender, payload_len = struct.unpack("<BHHB", b[:6])
                    if len(b) < SBP_HEADER_LEN + payload_len + 2:
                        # insufficient data, keep retrying until enough data becomes
                        # available
                        consumed = 0
                    else:
                        # check CRC
                        b = b[:SBP_HEADER_LEN + payload_len + 2]
                        crc_read, = struct.unpack("<H", b[SBP_HEADER_LEN + payload_len:SBP_HEADER_LEN + payload_len + 2])
                        crc_expected = binascii.crc_hqx(b[1:SBP_HEADER_LEN + payload_len], 0)
                        if crc_read != crc_expected:
                            sys.stderr.write("CRC error: {} vs {} for msg type {}\n".format(crc_read, crc_expected, msg_type))
                            msg_type = None
                            consumed = 1
                        else:
                            consumed = SBP_HEADER_LEN + payload_len + 2

            if consumed == 0:
                break

            if msg_type is not None:
                yield msg_type, sender, payload_len, b, crc_read

            unconsumed_offset += consumed


# "original" version of sbp2json based entirely upon construct
def get_next_msg_construct(fileobj):
    for msg_type, sender, payload_len, buf, crc_read in parse_file_construct(fileobj):
        msg_buf = buf[SBP_HEADER_LEN:SBP_HEADER_LEN + payload_len]
        msg = sbp.msg.SBP(msg_type, sender, payload_len, msg_buf, crc_read)

        if msg_type not in sbp.table._SBP_TABLE:
            sys.stderr.write("Skipping unknown message type: {}\n".format(msg_type))
            continue

        msg = sbp.table.dispatch(msg)
        yield msg.to_json_dict()


# hybrid version of sbp2json which uses original parser + kaitai struct to
# avoid calling sbp.table.dispatch()
def get_next_msg_hybrid1(fileobj):
    for msg_type, sender, payload_len, buf, crc_read in parse_file_construct(fileobj):
        stream = KaitaiStream(io.BytesIO(buf))
        obj = kaitai_sbp.Sbp.SbpMessage(stream)

        if KaitaiStream.resolve_enum(kaitai_sbp.Sbp.MsgIds, obj.msg_type) == obj.msg_type:
            sys.stderr.write("Skipping unknown message type: {}\n".format(obj.msg_type))
            continue

        yield kaitai2dict(obj)


# hybrid version of sbp2json which uses original parser + sbp.msg.SBP + kaitai
# struct to avoid calling sbp.table.dispatch()
# this version can be used to speed up parsing in existing code based upon the
# construct version
def get_next_msg_hybrid2(fileobj):
    for msg_type, sender, payload_len, buf, crc_read in parse_file_construct(fileobj):
        msg_buf = buf[SBP_HEADER_LEN:SBP_HEADER_LEN + payload_len]
        msg = sbp.msg.SBP(msg_type, sender, payload_len, msg_buf, crc_read)
        stream = KaitaiStream(io.BytesIO(msg.to_binary()))
        obj = kaitai_sbp.Sbp.SbpMessage(stream)

        if KaitaiStream.resolve_enum(kaitai_sbp.Sbp.MsgIds, obj.msg_type) == obj.msg_type:
            sys.stderr.write("Skipping unknown message type: {}\n".format(obj.msg_type))
            continue

        yield kaitai2dict(obj)


# return number of messages generated by parsing 'filename' with 'fn'
def count_messages(filename, fn):
    num_messages = 0

    infile = open(filename, 'rb')
    for msg in fn(infile):
        num_messages += 1

    return num_messages


# confirm that the JSON output from all 4 parsers is identical
def compare_parser_outputs(filename):
    num_messages = 0

    file1 = open(filename, 'rb')
    file2 = open(filename, 'rb')
    file3 = open(filename, 'rb')
    file4 = open(filename, 'rb')

    for msg_construct, msg_kaitai, msg_hybrid1, msg_hybrid2 in zip(get_next_msg_construct(file1), get_next_msg_kaitai(file2), get_next_msg_hybrid1(file3), get_next_msg_hybrid2(file4)):
        json_construct = json.dumps(snake_case_keys(msg_construct), allow_nan=False, sort_keys=True, separators=(',', ':'))
        json_kaitai = json.dumps(msg_kaitai, allow_nan=False, sort_keys=True, separators=(',', ':'))
        json_hybrid1 = json.dumps(msg_hybrid1, allow_nan=False, sort_keys=True, separators=(',', ':'))
        json_hybrid2 = json.dumps(msg_hybrid2, allow_nan=False, sort_keys=True, separators=(',', ':'))

        assert json_construct == json_kaitai, "Mismatch:\n{}\nvs\n{}".format(json_construct, json_kaitai)
        assert json_construct == json_hybrid1, "Mismatch:\n{}\nvs\n{}".format(json_construct, json_hybrid1)
        assert json_construct == json_hybrid2, "Mismatch:\n{}\nvs\n{}".format(json_construct, json_hybrid2)
        num_messages += 1
    return num_messages
