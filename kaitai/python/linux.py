# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Linux(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgLinuxSocketUsage(KaitaiStruct):
        """Summaries the socket usage across the system.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.avg_queue_depth = self._io.read_u4le()
            self.max_queue_depth = self._io.read_u4le()
            self.socket_state_counts = []
            for i in range(16):
                self.socket_state_counts.append(self._io.read_u2le())

            self.socket_type_counts = []
            for i in range(16):
                self.socket_type_counts.append(self._io.read_u2le())



    class MsgLinuxSysState(KaitaiStruct):
        """This presents a summary of CPU and memory utilization, including a
        timestamp.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.mem_total = self._io.read_u2le()
            self.pcpu = self._io.read_u1()
            self.pmem = self._io.read_u1()
            self.procs_starting = self._io.read_u2le()
            self.procs_stopping = self._io.read_u2le()
            self.pid_count = self._io.read_u2le()
            self.time = self._io.read_u4le()
            self.flags = self._io.read_u1()


    class MsgLinuxCpuStateDepA(KaitaiStruct):
        """This message indicates the process state of the top 10 heaviest
        consumers of CPU on the system.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.index = self._io.read_u1()
            self.pid = self._io.read_u2le()
            self.pcpu = self._io.read_u1()
            self.tname = (self._io.read_bytes_full()).decode(u"ascii")
            self.cmdline = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgLinuxMemState(KaitaiStruct):
        """This message indicates the process state of the top 10 heaviest
        consumers of memory on the system, including a timestamp.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.index = self._io.read_u1()
            self.pid = self._io.read_u2le()
            self.pmem = self._io.read_u1()
            self.time = self._io.read_u4le()
            self.flags = self._io.read_u1()
            self.tname = (self._io.read_bytes_full()).decode(u"ascii")
            self.cmdline = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgLinuxProcessFdCount(KaitaiStruct):
        """Top 10 list of processes with a large number of open file descriptors.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.index = self._io.read_u1()
            self.pid = self._io.read_u2le()
            self.fd_count = self._io.read_u2le()
            self.cmdline = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgLinuxMemStateDepA(KaitaiStruct):
        """This message indicates the process state of the top 10 heaviest
        consumers of memory on the system.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.index = self._io.read_u1()
            self.pid = self._io.read_u2le()
            self.pmem = self._io.read_u1()
            self.tname = (self._io.read_bytes_full()).decode(u"ascii")
            self.cmdline = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgLinuxProcessSocketQueues(KaitaiStruct):
        """Top 10 list of sockets with deep queues.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.index = self._io.read_u1()
            self.pid = self._io.read_u2le()
            self.recv_queued = self._io.read_u2le()
            self.send_queued = self._io.read_u2le()
            self.socket_types = self._io.read_u2le()
            self.socket_states = self._io.read_u2le()
            self.address_of_largest = (self._io.read_bytes_full()).decode(u"ascii")
            self.cmdline = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgLinuxSysStateDepA(KaitaiStruct):
        """This presents a summary of CPU and memory utilization.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.mem_total = self._io.read_u2le()
            self.pcpu = self._io.read_u1()
            self.pmem = self._io.read_u1()
            self.procs_starting = self._io.read_u2le()
            self.procs_stopping = self._io.read_u2le()
            self.pid_count = self._io.read_u2le()


    class MsgLinuxProcessFdSummary(KaitaiStruct):
        """Summary of open file descriptors on the system.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sys_fd_count = self._io.read_u4le()
            self.most_opened = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgLinuxCpuState(KaitaiStruct):
        """This message indicates the process state of the top 10 heaviest
        consumers of CPU on the system, including a timestamp.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.index = self._io.read_u1()
            self.pid = self._io.read_u2le()
            self.pcpu = self._io.read_u1()
            self.time = self._io.read_u4le()
            self.flags = self._io.read_u1()
            self.tname = (self._io.read_bytes_full()).decode(u"ascii")
            self.cmdline = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgLinuxProcessSocketCounts(KaitaiStruct):
        """Top 10 list of processes with high socket counts.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.index = self._io.read_u1()
            self.pid = self._io.read_u2le()
            self.socket_count = self._io.read_u2le()
            self.socket_types = self._io.read_u2le()
            self.socket_states = self._io.read_u2le()
            self.cmdline = (self._io.read_bytes_full()).decode(u"ascii")



