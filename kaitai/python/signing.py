# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Signing(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgEd25519SignatureDepB(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.stream_counter = self._io.read_u1()
            self.on_demand_counter = self._io.read_u1()
            self.signature = []
            for i in range(64):
                self.signature.append(self._io.read_u1())

            self.fingerprint = []
            for i in range(20):
                self.fingerprint.append(self._io.read_u1())

            self.signed_messages = []
            i = 0
            while not self._io.is_eof():
                self.signed_messages.append(self._io.read_u4le())
                i += 1



    class MsgEd25519CertificateDep(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.n_msg = self._io.read_u1()
            self.fingerprint = []
            for i in range(20):
                self.fingerprint.append(self._io.read_u1())

            self.certificate_bytes = []
            i = 0
            while not self._io.is_eof():
                self.certificate_bytes.append(self._io.read_u1())
                i += 1



    class UtcTime(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.year = self._io.read_u2le()
            self.month = self._io.read_u1()
            self.day = self._io.read_u1()
            self.hours = self._io.read_u1()
            self.minutes = self._io.read_u1()
            self.seconds = self._io.read_u1()
            self.ns = self._io.read_u4le()


    class MsgEd25519SignatureDepA(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.signature = []
            for i in range(64):
                self.signature.append(self._io.read_u1())

            self.fingerprint = []
            for i in range(20):
                self.fingerprint.append(self._io.read_u1())

            self.signed_messages = []
            i = 0
            while not self._io.is_eof():
                self.signed_messages.append(self._io.read_u4le())
                i += 1



    class MsgCertificateChain(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.root_certificate = []
            for i in range(20):
                self.root_certificate.append(self._io.read_u1())

            self.intermediate_certificate = []
            for i in range(20):
                self.intermediate_certificate.append(self._io.read_u1())

            self.corrections_certificate = []
            for i in range(20):
                self.corrections_certificate.append(self._io.read_u1())

            self.expiration = Signing.UtcTime(self._io, self, self._root)
            self.signature = []
            for i in range(64):
                self.signature.append(self._io.read_u1())



    class MsgEcdsaCertificate(KaitaiStruct):
        """A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.n_msg = self._io.read_u1()
            self.certificate_id = []
            for i in range(4):
                self.certificate_id.append(self._io.read_u1())

            self.flags = self._io.read_u1()
            self.certificate_bytes = []
            i = 0
            while not self._io.is_eof():
                self.certificate_bytes.append(self._io.read_u1())
                i += 1



    class MsgEcdsaSignature(KaitaiStruct):
        """An ECDSA-256 signature using SHA-256 as the message digest algorithm.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.flags = self._io.read_u1()
            self.stream_counter = self._io.read_u1()
            self.on_demand_counter = self._io.read_u1()
            self.certificate_id = []
            for i in range(4):
                self.certificate_id.append(self._io.read_u1())

            self.signature = []
            for i in range(64):
                self.signature.append(self._io.read_u1())

            self.signed_messages = []
            i = 0
            while not self._io.is_eof():
                self.signed_messages.append(self._io.read_u1())
                i += 1




