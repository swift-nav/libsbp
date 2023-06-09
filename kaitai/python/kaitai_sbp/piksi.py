# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
from .gnss import *

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Piksi(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgNetworkStateResp(KaitaiStruct):
        """The state of a network interface on the Piksi. Data is made to reflect
        output of ifaddrs struct returned by getifaddrs in c.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.ipv4_address = []
            for i in range(4):
                self.ipv4_address.append(self._io.read_u1())

            self.ipv4_mask_size = self._io.read_u1()
            self.ipv6_address = []
            for i in range(16):
                self.ipv6_address.append(self._io.read_u1())

            self.ipv6_mask_size = self._io.read_u1()
            self.rx_bytes = self._io.read_u4le()
            self.tx_bytes = self._io.read_u4le()
            self.interface_name = (self._io.read_bytes(16)).decode(u"ascii")
            self.flags = self._io.read_u4le()


    class NetworkUsage(KaitaiStruct):
        """The bandwidth usage for each interface can be reported within this
        struct and utilize multiple fields to fully specify the type of traffic
        that is being tracked. As either the interval of collection or the
        collection time may vary, both a timestamp and period field is provided,
        though may not necessarily be populated with a value.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.duration = self._io.read_u8le()
            self.total_bytes = self._io.read_u8le()
            self.rx_bytes = self._io.read_u4le()
            self.tx_bytes = self._io.read_u4le()
            self.interface_name = (self._io.read_bytes(16)).decode(u"ascii")


    class MsgCommandResp(KaitaiStruct):
        """The response to MSG_COMMAND_REQ with the return code of the command.  A
        return code of zero indicates success.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()
            self.code = self._io.read_s4le()


    class MsgCommandOutput(KaitaiStruct):
        """Returns the standard output and standard error of the command requested
        by MSG_COMMAND_REQ. The sequence number can be used to filter for
        filtering the correct command.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()
            self.line = (self._io.read_bytes_full()).decode(u"ascii")


    class Latency(KaitaiStruct):
        """Statistics on the latency of observations received from the base
        station. As observation packets are received their GPS time is compared
        to the current GPS time calculated locally by the receiver to give a
        precise measurement of the end-to-end communication latency in the
        system.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.avg = self._io.read_s4le()
            self.lmin = self._io.read_s4le()
            self.lmax = self._io.read_s4le()
            self.current = self._io.read_s4le()


    class MsgThreadState(KaitaiStruct):
        """The thread usage message from the device reports real-time operating
        system (RTOS) thread usage statistics for the named thread. The reported
        percentage values must be normalized.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.name = (self._io.read_bytes(20)).decode(u"ascii")
            self.cpu = self._io.read_u2le()
            self.stack_free = self._io.read_u4le()


    class MsgUartStateDepa(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.uart_a = Piksi.UartChannel(self._io, self, self._root)
            self.uart_b = Piksi.UartChannel(self._io, self, self._root)
            self.uart_ftdi = Piksi.UartChannel(self._io, self, self._root)
            self.latency = Piksi.Latency(self._io, self, self._root)


    class MsgNetworkStateReq(KaitaiStruct):
        """Request state of Piksi network interfaces. Output will be sent in
        MSG_NETWORK_STATE_RESP messages.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgDeviceMonitor(KaitaiStruct):
        """This message contains temperature and voltage level measurements from
        the processor's monitoring system and the RF frontend die temperature if
        available.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.dev_vin = self._io.read_s2le()
            self.cpu_vint = self._io.read_s2le()
            self.cpu_vaux = self._io.read_s2le()
            self.cpu_temperature = self._io.read_s2le()
            self.fe_temperature = self._io.read_s2le()


    class MsgMaskSatelliteDep(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.mask = self._io.read_u1()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)


    class MsgUartState(KaitaiStruct):
        """The UART message reports data latency and throughput of the UART
        channels providing SBP I/O. On the default Piksi configuration, UARTs A
        and B are used for telemetry radios, but can also be host access ports
        for embedded hosts, or other interfaces in future. The reported
        percentage values must be normalized. Observations latency and period
        can be used to assess the health of the differential corrections link.
        Latency provides the timeliness of received base observations while the
        period indicates their likelihood of transmission.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.uart_a = Piksi.UartChannel(self._io, self, self._root)
            self.uart_b = Piksi.UartChannel(self._io, self, self._root)
            self.uart_ftdi = Piksi.UartChannel(self._io, self, self._root)
            self.latency = Piksi.Latency(self._io, self, self._root)
            self.obs_period = Piksi.Period(self._io, self, self._root)


    class MsgSpecan(KaitaiStruct):
        """Spectrum analyzer packet.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.channel_tag = self._io.read_u2le()
            self.t = Gnss.GpsTime(self._io, self, self._root)
            self.freq_ref = self._io.read_f4le()
            self.freq_step = self._io.read_f4le()
            self.amplitude_ref = self._io.read_f4le()
            self.amplitude_unit = self._io.read_f4le()
            self.amplitude_value = []
            i = 0
            while not self._io.is_eof():
                self.amplitude_value.append(self._io.read_u1())
                i += 1



    class MsgIarState(KaitaiStruct):
        """This message reports the state of the Integer Ambiguity Resolution (IAR)
        process, which resolves unknown integer ambiguities from double-
        differenced carrier-phase measurements from satellite observations.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.num_hyps = self._io.read_u4le()


    class MsgAlmanac(KaitaiStruct):
        """This is a legacy message for sending and loading a satellite alamanac
        onto the Piksi's flash memory from the host.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgResetFilters(KaitaiStruct):
        """This message resets either the DGNSS Kalman filters or Integer Ambiguity
        Resolution (IAR) process.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.filter = self._io.read_u1()


    class UartChannel(KaitaiStruct):
        """Throughput, utilization, and error counts on the RX/TX buffers of this
        UART channel. The reported percentage values must be normalized.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tx_throughput = self._io.read_f4le()
            self.rx_throughput = self._io.read_f4le()
            self.crc_error_count = self._io.read_u2le()
            self.io_error_count = self._io.read_u2le()
            self.tx_buffer_level = self._io.read_u1()
            self.rx_buffer_level = self._io.read_u1()


    class MsgCommandReq(KaitaiStruct):
        """Request the recipient to execute an command. Output will be sent in
        MSG_LOG messages, and the exit code will be returned with
        MSG_COMMAND_RESP.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()
            self.command = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgMaskSatellite(KaitaiStruct):
        """This message allows setting a mask to prevent a particular satellite
        from being used in various Piksi subsystems.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.mask = self._io.read_u1()
            self.sid = Gnss.GnssSignal(self._io, self, self._root)


    class MsgNetworkBandwidthUsage(KaitaiStruct):
        """The bandwidth usage, a list of usage by interface.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.interfaces = []
            i = 0
            while not self._io.is_eof():
                self.interfaces.append(Piksi.NetworkUsage(self._io, self, self._root))
                i += 1



    class MsgReset(KaitaiStruct):
        """This message from the host resets the Piksi back into the bootloader.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.flags = self._io.read_u4le()


    class MsgCellModemStatus(KaitaiStruct):
        """If a cell modem is present on a piksi device, this message will be send
        periodically to update the host on the status of the modem and its
        various parameters.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.signal_strength = self._io.read_s1()
            self.signal_error_rate = self._io.read_f4le()
            self.reserved = []
            i = 0
            while not self._io.is_eof():
                self.reserved.append(self._io.read_u1())
                i += 1



    class MsgFrontEndGain(KaitaiStruct):
        """This message describes the gain of each channel in the receiver
        frontend. Each gain is encoded as a non-dimensional percentage relative
        to the maximum range possible for the gain stage of the frontend. By
        convention, each gain array has 8 entries and the index of the array
        corresponding to the index of the rf channel in the frontend. A gain of
        127 percent encodes that rf channel is not present in the hardware. A
        negative value implies an error for the particular gain stage as
        reported by the frontend.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.rf_gain = []
            for i in range(8):
                self.rf_gain.append(self._io.read_s1())

            self.if_gain = []
            for i in range(8):
                self.if_gain.append(self._io.read_s1())



    class MsgResetDep(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgSetTime(KaitaiStruct):
        """This message sets up timing functionality using a coarse GPS time
        estimate sent by the host.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgCwResults(KaitaiStruct):
        """This is an unused legacy message for result reporting from the CW
        interference channel on the SwiftNAP. This message will be removed in a
        future release.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgSpecanDep(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.channel_tag = self._io.read_u2le()
            self.t = Gnss.GpsTimeDep(self._io, self, self._root)
            self.freq_ref = self._io.read_f4le()
            self.freq_step = self._io.read_f4le()
            self.amplitude_ref = self._io.read_f4le()
            self.amplitude_unit = self._io.read_f4le()
            self.amplitude_value = []
            i = 0
            while not self._io.is_eof():
                self.amplitude_value.append(self._io.read_u1())
                i += 1



    class MsgInitBaseDep(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class Period(KaitaiStruct):
        """Statistics on the period of observations received from the base station.
        As complete observation sets are received, their time of reception is
        compared with the prior set''s time of reception. This measurement
        provides a proxy for link quality as incomplete or missing sets will
        increase the period.  Long periods can cause momentary RTK solution
        outages.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.avg = self._io.read_s4le()
            self.pmin = self._io.read_s4le()
            self.pmax = self._io.read_s4le()
            self.current = self._io.read_s4le()


    class MsgCwStart(KaitaiStruct):
        """This is an unused legacy message from the host for starting the CW
        interference channel on the SwiftNAP. This message will be removed in a
        future release.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass



