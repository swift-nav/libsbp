# Utilities for tests cases for the python version of the Kaitai Struct SBP
# parser
#
# We consider the Kaitai Struct version to work "correctly" if it produces the
# same JSON output as the original construct-based implementation.

import kaitai.python.sbp as kaitai_sbp
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
def kaitai2json(obj):
    # encode payload
    obj.payload._io.seek(0)
    payload_b64 = base64.standard_b64encode(obj.payload._io.read_bytes_full()).decode('ascii')

    message = dictify(obj.payload)
    message["preamble"] = ord(obj.header.preamble)
    message["msg_type"] = obj.header.msg_type
    message["sender"] = obj.header.sender
    message["length"] = obj.header.length
    message["crc"] = obj.crc
    message["payload"] = payload_b64
    return message


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



# wrapper object which allows KaitaiStream to be used with inputs which do
# not support seeking
class BufferedKaitaiStream(KaitaiStream):
    def __init__(self, fp, buf_size=io.DEFAULT_BUFFER_SIZE):
        super().__init__(io.BytesIO(fp.read(buf_size)))

        self.fp = fp
        self.buf_size = buf_size


    def reload(self):
        pos = self._io.tell()
        view = self._io.getbuffer()
        num_bytes = len(view[pos:])
        space = self.buf_size - num_bytes
        if space > 0:
            read_data = self.fp.read(space)
            read_len = len(read_data)
            if read_len > 0:
                view[0:num_bytes] = view[pos:]
                new_size = num_bytes + read_len
                view[num_bytes:new_size] = read_data
            else: # nothing read, drop only
                view[0:num_bytes] = view[pos:]
                new_size = num_bytes
        else: # no space, drop only
            view[0:num_bytes] = view[pos:]
            new_size = num_bytes

        if new_size != len(view):
            del view
            self._io.truncate(new_size)
        self._io.seek(0)


    def get_crc_bytes(self, payload_len):
        payload = self._io.getbuffer()[1:SBP_HEADER_LEN + payload_len]
        self._io.seek(SBP_HEADER_LEN + payload_len + 2)
        return payload


# work-alike of get_next_msg_construct() based upon Kaitai Struct
def get_next_msg_kaitai(fp):
    stream = BufferedKaitaiStream(fp, SBP_HEADER_LEN + 256 + 2)
    while True:
        obj = None
        stream.reload()
        try:
            obj = kaitai_sbp.Sbp.Message(stream)
        except (KaitaiStructError, UnicodeDecodeError):
            stream.seek(1)
            continue
        except EOFError:
            # end of substream or end of file
            pass

        if obj is None:
            if stream.is_eof():
                break
            else:
                stream.seek(1)
                continue

        # check CRC
        crc_read = obj.crc
        crc_expected = binascii.crc_hqx(stream.get_crc_bytes(obj.header.length), 0)
        if crc_read != crc_expected:
            sys.stderr.write("Bad CRC: {} vs {}\n".format(crc_read, crc_expected))
            stream.seek(1)
            continue

        if KaitaiStream.resolve_enum(kaitai_sbp.Sbp.MsgIds, obj.header.msg_type) == obj.header.msg_type:
            sys.stderr.write("Skipping unknown message type: {}\n".format(obj.header.msg_type))
            stream.seek(1)
            continue

        yield kaitai2json(obj)


# hybrid version of sbp2json which uses original parser + kaitai struct to
# avoid calling sbp.table.dispatch()
def get_next_msg_hybrid1(fileobj):
    for msg_type, sender, payload_len, buf, crc_read in parse_file_construct(fileobj):
        stream = KaitaiStream(io.BytesIO(buf))
        obj = kaitai_sbp.Sbp.Message(stream)

        if KaitaiStream.resolve_enum(kaitai_sbp.Sbp.MsgIds, obj.header.msg_type) == obj.header.msg_type:
            sys.stderr.write("Skipping unknown message type: {}\n".format(obj.header.msg_type))
            continue

        yield kaitai2json(obj)


# hybrid version of sbp2json which uses original parser + sbp.msg.SBP + kaitai
# struct to avoid calling sbp.table.dispatch()
# this version can be used to speed up parsing in existing code based upon the
# construct version
def get_next_msg_hybrid2(fileobj):
    for msg_type, sender, payload_len, buf, crc_read in parse_file_construct(fileobj):
        msg_buf = buf[SBP_HEADER_LEN:SBP_HEADER_LEN + payload_len]
        msg = sbp.msg.SBP(msg_type, sender, payload_len, msg_buf, crc_read)
        stream = KaitaiStream(io.BytesIO(msg.to_binary()))
        obj = kaitai_sbp.Sbp.Message(stream)

        if KaitaiStream.resolve_enum(kaitai_sbp.Sbp.MsgIds, obj.header.msg_type) == obj.header.msg_type:
            sys.stderr.write("Skipping unknown message type: {}\n".format(obj.header.msg_type))
            continue

        yield kaitai2json(obj)


# return number of messages generated by parsing 'filename' with 'fn'
def count_messages(filename, fn):
    num_messages = 0

    infile = open(filename, 'rb')
    for msg in fn(infile):
        num_messages += 1

    return num_messages


# implementation of sbp2json using Kaitai Struct parser
def sbp2json_kaitai():
    for msg in get_next_msg_kaitai(sys.stdin.buffer):
        print(json.dumps(msg, allow_nan=False, sort_keys=True, separators=(',', ':')))


# confirm that the JSON output from all 4 parsers is identical
def compare_parser_outputs(filename):
    num_messages = 0

    file1 = open(filename, 'rb')
    file2 = open(filename, 'rb')
    file3 = open(filename, 'rb')
    file4 = open(filename, 'rb')

    for msg_construct, msg_kaitai, msg_hybrid1, msg_hybrid2 in zip(get_next_msg_construct(file1), get_next_msg_kaitai(file2), get_next_msg_hybrid1(file3), get_next_msg_hybrid2(file4)):
        json_construct = json.dumps(lc_keys(msg_construct), allow_nan=False, sort_keys=True, separators=(',', ':'))
        json_kaitai = json.dumps(msg_kaitai, allow_nan=False, sort_keys=True, separators=(',', ':'))
        json_hybrid1 = json.dumps(msg_hybrid1, allow_nan=False, sort_keys=True, separators=(',', ':'))
        json_hybrid2 = json.dumps(msg_hybrid2, allow_nan=False, sort_keys=True, separators=(',', ':'))

        assert json_construct == json_kaitai, "Mismatch:\n{}\nvs\n{}".format(json_construct, json_kaitai)
        assert json_construct == json_hybrid1, "Mismatch:\n{}\nvs\n{}".format(json_construct, json_hybrid1)
        assert json_construct == json_hybrid2, "Mismatch:\n{}\nvs\n{}".format(json_construct, json_hybrid2)
        num_messages += 1
    return num_messages
