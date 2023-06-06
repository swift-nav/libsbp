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


# for JSON serialisation
def serialise(obj):
    return {k: v for k, v in obj.__dict__.items() if not k.startswith("_")}


# convert KaitaiStruct object to have similar structure to sbp2json output
def get_flattened_msg(obj):
    obj.payload.preamble = ord(obj.preamble)
    obj.payload.msg_type = obj.msg_type
    obj.payload.sender = obj.sender
    obj.payload.length = obj.length
    obj.payload._io.seek(0)
    obj.payload.payload = base64.standard_b64encode(obj.payload._io.read_bytes_full()).decode('ascii')
    obj.payload.crc = obj.crc

    return obj.payload


# wrapper object which allows KaitaiStream to be used with inputs which do
# not support seeking
class BufferedKaitaiStream(KaitaiStream):
    def __init__(self, fp, max_buf_size=io.DEFAULT_BUFFER_SIZE):
        super().__init__(io.BytesIO(fp.read(max_buf_size)))

        self.fp = fp
        self.max_buf_size = max_buf_size


    def reload(self):
        pos = self._io.tell()
        view = self._io.getbuffer()
        num_bytes = len(view[pos:])
        space = self.max_buf_size - num_bytes
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
        return self._io.getbuffer()[1:SBP_HEADER_LEN + payload_len]


# work-alike of get_next_msg_construct() based upon Kaitai Struct
def get_next_msg_kaitai(fp):
    stream = BufferedKaitaiStream(fp, SBP_HEADER_LEN + 256 + 2) # header + max message + CRC
    msg_types = [item.value for item in kaitai_sbp.Sbp.MsgIds]

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

        if obj.msg_type not in msg_types:
            sys.stderr.write("Skipping unknown message type: {}\n".format(obj.msg_type))
            stream.seek(1)
            continue

        # check CRC
        crc_read = obj.crc
        crc_expected = binascii.crc_hqx(stream.get_crc_bytes(obj.length), 0)
        if crc_read != crc_expected:
            sys.stderr.write("Bad CRC: {} vs {}\n".format(crc_read, crc_expected))
            stream.seek(1)
            continue

        yield get_flattened_msg(obj)


# implementation of sbp2json using Kaitai Struct parser
def sbp2json():
    with open(0, 'rb') as f:
        for msg in get_next_msg_kaitai(f):
            print(rapidjson.dumps(msg, default=serialise))
