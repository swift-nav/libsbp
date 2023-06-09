# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Bootload(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgNapDeviceDnaReq(KaitaiStruct):
        """The device message from the host reads a unique device identifier from
        the SwiftNAP, an FPGA. The host requests the ID by sending a
        MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
        MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
        that this ID is tied to the FPGA, and not related to the Piksi's serial
        number.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgBootloaderJumpToApp(KaitaiStruct):
        """The host initiates the bootloader to jump to the application.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.jump = self._io.read_u1()


    class MsgBootloaderHandshakeResp(KaitaiStruct):
        """The handshake message response from the device establishes a handshake
        between the device bootloader and the host. The request from the host is
        MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
        version number and the SBP protocol version number.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.flags = self._io.read_u4le()
            self.version = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgNapDeviceDnaResp(KaitaiStruct):
        """The device message from the host reads a unique device identifier from
        the SwiftNAP, an FPGA. The host requests the ID by sending a
        MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
        MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
        that this ID is tied to the FPGA, and not related to the Piksi's serial
        number.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.dna = []
            for i in range(8):
                self.dna.append(self._io.read_u1())



    class MsgBootloaderHandshakeReq(KaitaiStruct):
        """The handshake message request from the host establishes a handshake
        between the device bootloader and the host. The response from the device
        is MSG_BOOTLOADER_HANDSHAKE_RESP.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgBootloaderHandshakeDepA(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.handshake = []
            i = 0
            while not self._io.is_eof():
                self.handshake.append(self._io.read_u1())
                i += 1




