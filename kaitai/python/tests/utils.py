# Utilities for tests cases for the python version of the Kaitai Struct SBP
# parser
#
# We consider the Kaitai Struct version to work "correctly" if it produces the
# same JSON output as the original construct-based implementation.
# Note that the version of sbp2json in libsbp has a bug which causes it to
# not produce output for all input messages, which has been corrected in the
# version used here.

import kaitai.python.sbp as sbp_ksy
from kaitaistruct import KaitaiStream, KaitaiStruct, KaitaiStructError
import json
import binascii
import base64
from construct.core import StreamError
import struct
import sys
import io
import sbp.msg
import sbp.table
from sbp.msg import SBP_PREAMBLE
from sbp.msg import UnpackError

SBP_HEADER_LEN = 6


# convert all keys in a dict to lower case
def lc_keys(x):
   if isinstance(x, list):
     return [lc_keys(v) for v in x]
   elif isinstance(x, dict):
     return dict((k.lower(), lc_keys(v)) for k, v in x.items())
   else:
     return x


# convert KaitaiStruct object into dict
def dictify(obj):
    if isinstance(obj, KaitaiStruct):
        return {k: dictify(v) for k, v in obj.__dict__.items() if not k.startswith("_")}
    elif isinstance(obj, dict):
        return {k: dictify(v) for k, v in obj.items()}
    elif isinstance(obj, list):
        return [dictify(x) for x in obj]
    else:
        return obj


# convert KaitaiStruct object into dict with keys similar to sbp2json output
def ksy2json(obj):
    # encode payload
    obj.payload._io.seek(0)
    payload_b64 = base64.standard_b64encode(obj.payload._io.read_bytes_full()).decode('ascii')

    message = dictify(obj.payload)
    message["preamble"] = ord(obj.header.preamble)
    message["msg_type"] = obj.header.msg_type.value
    message["sender"] = obj.header.sender
    message["length"] = obj.header.length
    message["crc"] = obj.crc
    message["payload"] = payload_b64
    return message


# adapted from construct-based python version of sbp2json
def parse_file_construct(filename):
    buf = bytearray(4096)
    reader = open(filename, 'rb')
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
def get_next_msg_construct(filename):
    for msg_type, sender, payload_len, buf, crc_read in parse_file_construct(filename):
        msg_buf = buf[SBP_HEADER_LEN:SBP_HEADER_LEN + payload_len]
        msg = sbp.msg.SBP(msg_type, sender, payload_len, msg_buf, crc_read)

        if msg_type not in sbp.table._SBP_TABLE:
            sys.stderr.write("Skipping unknown message type: {}\n".format(msg_type))
            continue

        msg = sbp.table.dispatch(msg)
        yield msg.to_json_dict()


# work-alike of get_next_msg_construct based upon kaitai struct
def get_next_msg_ksy(filename):
    with open(filename, 'rb') as f:
        stream = KaitaiStream(f)
        while True:
            pos_msg_start = stream.pos()
            try:
                obj = sbp_ksy.Sbp.Message(stream)
            except (KaitaiStructError, UnicodeDecodeError):
                stream.seek(pos_msg_start + 1)
                continue
            except EOFError:
                return

            if obj is None:
                break

            # check CRC
            crc_read = obj.crc
            length = obj.header.length
            pos_msg_end = obj.header._io.pos()
            obj.header._io.seek(pos_msg_end - length - SBP_HEADER_LEN - 1)
            crc_expected = binascii.crc_hqx(obj.header._io.read_bytes(SBP_HEADER_LEN - 1 + length), 0)
            obj.header._io.seek(pos_msg_end)
            if crc_read != crc_expected:
                sys.stderr.write("Bad CRC: {} vs {}\n".format(crc_read, crc_expected))
                stream.seek(pos_msg_start + 1)
                continue

            if type(obj.header.msg_type) != sbp_ksy.Sbp.MsgIds:
                sys.stderr.write("Skipping unknown message type: {}\n".format(obj.header.msg_type))
                stream.seek(pos_msg_start + 1)
                continue

            yield ksy2json(obj)


# hybrid version of sbp2json which uses original parser + kaitai struct to
# avoid calling sbp.table.dispatch()
def get_next_msg_hybrid1(filename):
    for msg_type, sender, payload_len, buf, crc_read in parse_file_construct(filename):
        stream = KaitaiStream(io.BytesIO(buf))
        obj = sbp_ksy.Sbp.Message(stream)

        if type(obj.header.msg_type) != sbp_ksy.Sbp.MsgIds:
            sys.stderr.write("Skipping unknown message type: {}\n".format(obj.header.msg_type))
            continue

        yield ksy2json(obj)


# hybrid version of sbp2json which uses original parser + sbp.msg.SBP + kaitai
# struct to avoid calling sbp.table.dispatch()
# this version can be used to speed up parsing in existing code based upon the
# construct version
def get_next_msg_hybrid2(filename):
    for msg_type, sender, payload_len, buf, crc_read in parse_file_construct(filename):
        msg_buf = buf[SBP_HEADER_LEN:SBP_HEADER_LEN + payload_len]
        msg = sbp.msg.SBP(msg_type, sender, payload_len, msg_buf, crc_read)
        stream = KaitaiStream(io.BytesIO(msg.to_binary()))
        obj = sbp_ksy.Sbp.Message(stream)

        if type(obj.header.msg_type) != sbp_ksy.Sbp.MsgIds:
            sys.stderr.write("Skipping unknown message type: {}\n".format(obj.header.msg_type))
            continue

        yield ksy2json(obj)


# confirm that the JSON output from all 4 parsers is identical
def compare_parsers(filename):
    num_messages = 0
    for msg_construct, msg_ksy, msg_hybrid1, msg_hybrid2 in zip(get_next_msg_construct(filename), get_next_msg_ksy(filename), get_next_msg_hybrid1(filename), get_next_msg_hybrid2(filename)):
        json_construct = json.dumps(lc_keys(msg_construct), allow_nan=False, sort_keys=True, separators=(',', ':'))
        json_ksy = json.dumps(msg_ksy, allow_nan=False, sort_keys=True, separators=(',', ':'))
        json_hybrid1 = json.dumps(msg_hybrid1, allow_nan=False, sort_keys=True, separators=(',', ':'))
        json_hybrid2 = json.dumps(msg_hybrid2, allow_nan=False, sort_keys=True, separators=(',', ':'))

        assert json_construct == json_ksy, "Mismatch:\n{}\nvs\n{}".format(json_construct, json_ksy)
        assert json_construct == json_hybrid1, "Mismatch:\n{}\nvs\n{}".format(json_construct, json_hybrid1)
        assert json_construct == json_hybrid2, "Mismatch:\n{}\nvs\n{}".format(json_construct, json_hybrid2)
        num_messages += 1
    return num_messages
