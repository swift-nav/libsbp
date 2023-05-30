# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Logging(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgLog(KaitaiStruct):
        """This message contains a human-readable payload string from the device
        containing errors, warnings and informational messages at ERROR,
        WARNING, DEBUG, INFO logging levels.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.level = self._io.read_u1()
            self.text = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgFwd(KaitaiStruct):
        """This message provides the ability to forward messages over SBP.  This
        may take the form of wrapping up SBP messages received by Piksi for
        logging purposes or wrapping another protocol with SBP.
        
        The source identifier indicates from what interface a forwarded stream
        derived. The protocol identifier identifies what the expected protocol
        the forwarded msg contains. Protocol 0 represents SBP and the remaining
        values are implementation defined.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.source = self._io.read_u1()
            self.protocol = self._io.read_u1()
            self.fwd_payload = []
            i = 0
            while not self._io.is_eof():
                self.fwd_payload.append(self._io.read_u1())
                i += 1



    class MsgPrintDep(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.text = (self._io.read_bytes_full()).decode(u"ascii")



