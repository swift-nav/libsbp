# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Flash(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgFlashDone(KaitaiStruct):
        """This message defines success or failure codes for a variety of flash
        memory requests from the host to the device. Flash read and write
        messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
        this message on failure.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.response = self._io.read_u1()


    class MsgM25FlashWriteStatus(KaitaiStruct):
        """The flash status message writes to the 8-bit M25 flash status register.
        The device replies with a MSG_FLASH_DONE message.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.status = []
            for i in range(1):
                self.status.append(self._io.read_u1())



    class MsgFlashReadResp(KaitaiStruct):
        """The flash read message reads a set of addresses of either the STM or M25
        onboard flash. The device replies with a MSG_FLASH_READ_RESP message
        containing either the read data on success or a MSG_FLASH_DONE message
        containing the return code FLASH_INVALID_LEN (2) if the maximum read
        size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
        the allowed range.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.target = self._io.read_u1()
            self.addr_start = []
            for i in range(3):
                self.addr_start.append(self._io.read_u1())

            self.addr_len = self._io.read_u1()


    class MsgFlashErase(KaitaiStruct):
        """The flash erase message from the host erases a sector of either the STM
        or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
        message containing the return code - FLASH_OK (0) on success or
        FLASH_INVALID_FLASH (1) if the flash specified is invalid.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.target = self._io.read_u1()
            self.sector_num = self._io.read_u4le()


    class MsgStmUniqueIdResp(KaitaiStruct):
        """This message reads the device's hard-coded unique ID. The host requests
        the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
        MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.stm_id = []
            for i in range(12):
                self.stm_id.append(self._io.read_u1())



    class MsgStmUniqueIdReq(KaitaiStruct):
        """This message reads the device's hard-coded unique ID. The host requests
        the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
        MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgFlashProgram(KaitaiStruct):
        """The flash program message programs a set of addresses of either the STM
        or M25 flash. The device replies with either a MSG_FLASH_DONE message
        containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
        (2) if the maximum write size is exceeded. Note that the sector-
        containing addresses must be erased before addresses can be programmed.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.target = self._io.read_u1()
            self.addr_start = []
            for i in range(3):
                self.addr_start.append(self._io.read_u1())

            self.addr_len = self._io.read_u1()
            self.data = []
            i = 0
            while not self._io.is_eof():
                self.data.append(self._io.read_u1())
                i += 1



    class MsgFlashReadReq(KaitaiStruct):
        """The flash read message reads a set of addresses of either the STM or M25
        onboard flash. The device replies with a MSG_FLASH_READ_RESP message
        containing either the read data on success or a MSG_FLASH_DONE message
        containing the return code FLASH_INVALID_LEN (2) if the maximum read
        size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
        the allowed range.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.target = self._io.read_u1()
            self.addr_start = []
            for i in range(3):
                self.addr_start.append(self._io.read_u1())

            self.addr_len = self._io.read_u1()


    class MsgStmFlashUnlockSector(KaitaiStruct):
        """The flash unlock message unlocks a sector of the STM flash memory. The
        device replies with a MSG_FLASH_DONE message.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sector = self._io.read_u4le()


    class MsgStmFlashLockSector(KaitaiStruct):
        """The flash lock message locks a sector of the STM flash memory. The
        device replies with a MSG_FLASH_DONE message.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sector = self._io.read_u4le()



