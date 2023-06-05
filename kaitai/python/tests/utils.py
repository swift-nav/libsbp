# Utilities for tests cases for the python version of the Kaitai Struct SBP
# parser

import kaitai.python.sbp as kaitai_sbp
from kaitai.python.tests.utils_sbp2json import get_next_msg_kaitai, get_flattened_msg, serialise
from generator.sbpg.targets.common import snake_case, snake_case_keys, decode_json
from kaitaistruct import KaitaiStream, KaitaiStruct
import json
import binascii
import struct
import sys
import io
import sbp.msg
import sbp.table
from sbp.msg import SBP_PREAMBLE
import re
from subprocess import Popen, PIPE

SBP_HEADER_LEN = 6
PERL_CMD = ['perl', 'kaitai/perl/t/sbp2json.pl']


# convert KaitaiStruct object into dict
def dictify(obj, round_floats=False):
    if isinstance(obj, KaitaiStruct):
        return {k: dictify(v, round_floats) for k, v in obj.__dict__.items() if not k.startswith("_")}
    elif isinstance(obj, dict):
        return {k: dictify(v, round_floats) for k, v in obj.items()}
    elif isinstance(obj, list):
        return [dictify(x, round_floats) for x in obj]
    elif round_floats and type(obj) == float:
        return float('{:.10f}'.format(obj)[:11])
    else:
        return obj


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

        yield get_flattened_msg(obj)


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

        yield get_flattened_msg(obj)


def get_next_msg_external(cmd, filename):
    proc = Popen(cmd + [filename], stdout=PIPE)

    for line in proc.stdout:
        yield line


# return number of messages generated by parsing 'filename' with 'fn'
def count_messages(filename, fn, cmd=None):
    num_messages = 0

    args = [open(filename, 'rb')] if cmd is None else [cmd, filename]
    for msg in fn(*args):
        num_messages += 1

    return num_messages


# confirm that all known parsers produce identical output.  The known parsers
# are as follows:
# 1. construct: based completely upon the construct-based python bindings from
#    libsbp
# 2. kaitai: based completely upon the python bindings generated by
#    kaitai-struct-compiler
# 3. hybrid1: use parsing code from construct version + kaitai struct objects
#    (to avoid calling sbp.table.dispatch())
# 4. hybrid2: use parsing code from construct version + sbp.msg.SBP + kaitai
#    struct objects (to avoid calling sbp.table.dispatch()
# 5. perl: based completely upon the perl bindings generated by
#    kaitai-struct-compiler
def compare_parser_outputs(filename):
    num_messages = 0

    file1 = open(filename, 'rb')
    file2 = open(filename, 'rb')
    file3 = open(filename, 'rb')
    file4 = open(filename, 'rb')

    for msg_construct, msg_kaitai, msg_hybrid1, msg_hybrid2, msg_perl in zip(get_next_msg_construct(file1), get_next_msg_kaitai(file2), get_next_msg_hybrid1(file3), get_next_msg_hybrid2(file4), get_next_msg_external(PERL_CMD, filename)):
        msg_construct = snake_case_keys(msg_construct)
        msg_perl = decode_json(msg_perl)

        dict_construct = dictify(msg_construct)
        dict_kaitai = dictify(msg_kaitai)
        dict_hybrid1 = dictify(msg_hybrid1)
        dict_hybrid2 = dictify(msg_hybrid2)

        assert dict_construct == dict_kaitai, "Mismatch:\n{}\nvs\n{}".format(dict_construct, dict_kaitai)
        assert dict_construct == dict_hybrid1, "Mismatch:\n{}\nvs\n{}".format(dict_construct, dict_hybrid1)
        assert dict_construct == dict_hybrid2, "Mismatch:\n{}\nvs\n{}".format(dict_construct, dict_hybrid2)

        # need to round floats due to difference in rounding approaches used
        # by perl and python JSON encoders
        dict_construct = dictify(msg_construct, round_floats=True)
        dict_perl = dictify(msg_perl, round_floats=True)
        assert dict_construct == dict_perl, "Mismatch:\n{}\nvs\n{}".format(dict_construct, dict_perl)
        num_messages += 1
    return num_messages
