# Utilities for tests cases for the python version of the Kaitai Struct SBP
# parser only with focus on producing sbp2json-style output from Kaitai Struct
# parser

from kaitaistruct import KaitaiStream, KaitaiStruct, KaitaiStructError
import kaitai.python.sbp as kaitai_sbp
import io
import rapidjson
import binascii
import sys
import base64


SBP_HEADER_LEN = 6


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
def kaitai2dict(obj):
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
    stream = BufferedKaitaiStream(fp, SBP_HEADER_LEN + 256 + 2) # header + max message + CRC
    while True:
        obj = None
        stream.reload()
        try:
            obj = kaitai_sbp.Sbp.SbpMessage(stream)
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

        yield kaitai2dict(obj)


# implementation of sbp2json using Kaitai Struct parser
def sbp2json_kaitai():
    for msg in get_next_msg_kaitai(sys.stdin.buffer):
        print(rapidjson.dumps(msg))
