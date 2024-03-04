# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Profiling(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class ResourceBucket(KaitaiStruct):
        """Information about allocation of various resources grouped by buckets.
        Refer to product documentation to understand the meaning and values in
        this message.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.name = (self._io.read_bytes(21)).decode(u"ascii")
            self.thread = self._io.read_u1()
            self.mutex = self._io.read_u1()
            self.cv = self._io.read_u1()
            self.io = self._io.read_u1()
            self.heap_bytes_alloc = self._io.read_u4le()
            self.heap_bytes_free = self._io.read_u4le()
            self.io_write = self._io.read_u4le()
            self.io_read = self._io.read_u4le()


    class MsgProfilingSystemInfo(KaitaiStruct):
        """Contains basic information about system resource usage. System is
        defined in terms of the source of this message and may vary from  sender
        to sender. Refer to product documentation to understand the exact scope
        and meaning of this message.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.total_cpu_time = self._io.read_u8le()
            self.age = self._io.read_u8le()
            self.n_threads = self._io.read_u1()
            self.heap_usage = self._io.read_u4le()


    class MsgMeasurementPoint(KaitaiStruct):
        """Tracks execution time of certain code paths in specially built products.
        This message should only be expected and processed on the direction of
        Swift's engineering teams.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.total_time = self._io.read_u4le()
            self.num_executions = self._io.read_u2le()
            self.min = self._io.read_u4le()
            self.max = self._io.read_u4le()
            self.return_addr = self._io.read_u8le()
            self.id = self._io.read_u8le()
            self.slice_time = self._io.read_u8le()
            self.line = self._io.read_u2le()
            self.func = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgProfilingResourceCounter(KaitaiStruct):
        """Information about resource buckets. Refer to product documentation to
        understand the meaning and values in this message.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.seq_no = self._io.read_u1()
            self.seq_len = self._io.read_u1()
            self.buckets = []
            i = 0
            while not self._io.is_eof():
                self.buckets.append(Profiling.ResourceBucket(self._io, self, self._root))
                i += 1



    class MsgProfilingThreadInfo(KaitaiStruct):
        """Contains profiling information related to a single thread being tracked
        by the producing system. Refer to product documentation to understand
        the exact scope and meaning of this message.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.total_cpu_time = self._io.read_u8le()
            self.age = self._io.read_u8le()
            self.state = self._io.read_u1()
            self.stack_size = self._io.read_u4le()
            self.stack_usage = self._io.read_u4le()
            self.name = (self._io.read_bytes_full()).decode(u"ascii")



