# helper methods for parsing SBP input using the Kaitai Struct python bindings
# and producing sbp2json-style output

from kaitaistruct import KaitaiStream, KaitaiStructError
from .table import SbpMessage
import binascii
import sys
import base64


SBP_HEADER_LEN = 6


# wrapper object which allows KaitaiStream to be used with a simple byte array
class BufferKaitaiStream(KaitaiStream):
    # simple emulation of io.BytesIO interface expected by KaitaiStream
    class IOBytes:
        def __init__(self, buf):
            self.buf = buf
            self.pos = 0

        def read(self, size=-1):
            if size < 0:
                size = len(self.buf) - self.pos
            if self.pos + size > len(self.buf):
                raise EOFError
            buf = self.buf[self.pos:self.pos + size]
            self.pos += size
            return buf

        def seek(self, pos):
            self.pos = pos

        def tell(self):
            return self.pos


    def __init__(self, buf=b''):
        super().__init__(BufferKaitaiStream.IOBytes(buf))


    def set_buffer(self, buf):
        self._io.buf = buf
        self._io.pos = 0


    def is_eof(self):
        return True if self._io.pos == len(self._io.buf) else False


# wrapper object which allows KaitaiStream to be used with file-like inputs
# which do not support seeking
class BufferedFileKaitaiStream(BufferKaitaiStream):
    def __init__(self, fp, max_buf_size):
        super().__init__(fp.read(max_buf_size))

        self.fp = fp
        self.max_buf_size = max_buf_size


    # try to read more data so that buffer size is 'max_buf_size'
    def fill_buffer(self):
        pos = self._io.pos
        space = self.max_buf_size - len(self._io.buf) + pos
        buf = self._io.buf[pos:]
        if space > 0:
            buf += self.fp.read(space)

        self.set_buffer(buf)


    def get_crc_bytes(self, payload_len):
        return self._io.buf[1:SBP_HEADER_LEN + payload_len]


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


# generator to produce SBP messages from a file object
def iter_messages(fp):
    stream = BufferedFileKaitaiStream(fp, SBP_HEADER_LEN + 256 + 2) # header + max message + CRC

    while True:
        obj = None
        stream.fill_buffer()
        try:
            obj = SbpMessage(stream)
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
        crc_expected = binascii.crc_hqx(stream.get_crc_bytes(obj.length), 0)
        if crc_read != crc_expected:
            sys.stderr.write("Bad CRC: {} vs {}\n".format(crc_read, crc_expected))
            stream.seek(1)
            continue

        yield get_flattened_msg(obj)
