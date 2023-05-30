import kaitai_struct_nim_runtime
import options
import gnss

type
  Piksi* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Piksi_MsgNetworkStateResp* = ref object of KaitaiStruct
    `ipv4Address`*: seq[uint8]
    `ipv4MaskSize`*: uint8
    `ipv6Address`*: seq[uint8]
    `ipv6MaskSize`*: uint8
    `rxBytes`*: uint32
    `txBytes`*: uint32
    `interfaceName`*: string
    `flags`*: uint32
    `parent`*: Sbp_Message
  Piksi_NetworkUsage* = ref object of KaitaiStruct
    `duration`*: uint64
    `totalBytes`*: uint64
    `rxBytes`*: uint32
    `txBytes`*: uint32
    `interfaceName`*: string
    `parent`*: Piksi_MsgNetworkBandwidthUsage
  Piksi_MsgCommandResp* = ref object of KaitaiStruct
    `sequence`*: uint32
    `code`*: int32
    `parent`*: Sbp_Message
  Piksi_MsgCommandOutput* = ref object of KaitaiStruct
    `sequence`*: uint32
    `line`*: string
    `parent`*: Sbp_Message
  Piksi_Latency* = ref object of KaitaiStruct
    `avg`*: int32
    `lmin`*: int32
    `lmax`*: int32
    `current`*: int32
    `parent`*: KaitaiStruct
  Piksi_MsgThreadState* = ref object of KaitaiStruct
    `name`*: string
    `cpu`*: uint16
    `stackFree`*: uint32
    `parent`*: Sbp_Message
  Piksi_MsgUartStateDepa* = ref object of KaitaiStruct
    `uartA`*: Piksi_UartChannel
    `uartB`*: Piksi_UartChannel
    `uartFtdi`*: Piksi_UartChannel
    `latency`*: Piksi_Latency
    `parent`*: Sbp_Message
  Piksi_MsgNetworkStateReq* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Piksi_MsgDeviceMonitor* = ref object of KaitaiStruct
    `devVin`*: int16
    `cpuVint`*: int16
    `cpuVaux`*: int16
    `cpuTemperature`*: int16
    `feTemperature`*: int16
    `parent`*: Sbp_Message
  Piksi_MsgMaskSatelliteDep* = ref object of KaitaiStruct
    `mask`*: uint8
    `sid`*: Gnss_GnssSignalDep
    `parent`*: Sbp_Message
  Piksi_MsgUartState* = ref object of KaitaiStruct
    `uartA`*: Piksi_UartChannel
    `uartB`*: Piksi_UartChannel
    `uartFtdi`*: Piksi_UartChannel
    `latency`*: Piksi_Latency
    `obsPeriod`*: Piksi_Period
    `parent`*: Sbp_Message
  Piksi_MsgSpecan* = ref object of KaitaiStruct
    `channelTag`*: uint16
    `t`*: Gnss_GpsTime
    `freqRef`*: float32
    `freqStep`*: float32
    `amplitudeRef`*: float32
    `amplitudeUnit`*: float32
    `amplitudeValue`*: seq[uint8]
    `parent`*: Sbp_Message
  Piksi_MsgIarState* = ref object of KaitaiStruct
    `numHyps`*: uint32
    `parent`*: Sbp_Message
  Piksi_MsgAlmanac* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Piksi_MsgResetFilters* = ref object of KaitaiStruct
    `filter`*: uint8
    `parent`*: Sbp_Message
  Piksi_UartChannel* = ref object of KaitaiStruct
    `txThroughput`*: float32
    `rxThroughput`*: float32
    `crcErrorCount`*: uint16
    `ioErrorCount`*: uint16
    `txBufferLevel`*: uint8
    `rxBufferLevel`*: uint8
    `parent`*: KaitaiStruct
  Piksi_MsgCommandReq* = ref object of KaitaiStruct
    `sequence`*: uint32
    `command`*: string
    `parent`*: Sbp_Message
  Piksi_MsgMaskSatellite* = ref object of KaitaiStruct
    `mask`*: uint8
    `sid`*: Gnss_GnssSignal
    `parent`*: Sbp_Message
  Piksi_MsgNetworkBandwidthUsage* = ref object of KaitaiStruct
    `interfaces`*: seq[Piksi_NetworkUsage]
    `parent`*: Sbp_Message
  Piksi_MsgReset* = ref object of KaitaiStruct
    `flags`*: uint32
    `parent`*: Sbp_Message
  Piksi_MsgCellModemStatus* = ref object of KaitaiStruct
    `signalStrength`*: int8
    `signalErrorRate`*: float32
    `reserved`*: seq[uint8]
    `parent`*: Sbp_Message
  Piksi_MsgFrontEndGain* = ref object of KaitaiStruct
    `rfGain`*: seq[int8]
    `ifGain`*: seq[int8]
    `parent`*: Sbp_Message
  Piksi_MsgResetDep* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Piksi_MsgSetTime* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Piksi_MsgCwResults* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Piksi_MsgSpecanDep* = ref object of KaitaiStruct
    `channelTag`*: uint16
    `t`*: Gnss_GpsTimeDep
    `freqRef`*: float32
    `freqStep`*: float32
    `amplitudeRef`*: float32
    `amplitudeUnit`*: float32
    `amplitudeValue`*: seq[uint8]
    `parent`*: Sbp_Message
  Piksi_MsgInitBaseDep* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Piksi_Period* = ref object of KaitaiStruct
    `avg`*: int32
    `pmin`*: int32
    `pmax`*: int32
    `current`*: int32
    `parent`*: Piksi_MsgUartState
  Piksi_MsgCwStart* = ref object of KaitaiStruct
    `parent`*: Sbp_Message

proc read*(_: typedesc[Piksi], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Piksi
proc read*(_: typedesc[Piksi_MsgNetworkStateResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgNetworkStateResp
proc read*(_: typedesc[Piksi_NetworkUsage], io: KaitaiStream, root: KaitaiStruct, parent: Piksi_MsgNetworkBandwidthUsage): Piksi_NetworkUsage
proc read*(_: typedesc[Piksi_MsgCommandResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCommandResp
proc read*(_: typedesc[Piksi_MsgCommandOutput], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCommandOutput
proc read*(_: typedesc[Piksi_Latency], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Piksi_Latency
proc read*(_: typedesc[Piksi_MsgThreadState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgThreadState
proc read*(_: typedesc[Piksi_MsgUartStateDepa], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgUartStateDepa
proc read*(_: typedesc[Piksi_MsgNetworkStateReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgNetworkStateReq
proc read*(_: typedesc[Piksi_MsgDeviceMonitor], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgDeviceMonitor
proc read*(_: typedesc[Piksi_MsgMaskSatelliteDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgMaskSatelliteDep
proc read*(_: typedesc[Piksi_MsgUartState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgUartState
proc read*(_: typedesc[Piksi_MsgSpecan], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgSpecan
proc read*(_: typedesc[Piksi_MsgIarState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgIarState
proc read*(_: typedesc[Piksi_MsgAlmanac], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgAlmanac
proc read*(_: typedesc[Piksi_MsgResetFilters], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgResetFilters
proc read*(_: typedesc[Piksi_UartChannel], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Piksi_UartChannel
proc read*(_: typedesc[Piksi_MsgCommandReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCommandReq
proc read*(_: typedesc[Piksi_MsgMaskSatellite], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgMaskSatellite
proc read*(_: typedesc[Piksi_MsgNetworkBandwidthUsage], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgNetworkBandwidthUsage
proc read*(_: typedesc[Piksi_MsgReset], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgReset
proc read*(_: typedesc[Piksi_MsgCellModemStatus], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCellModemStatus
proc read*(_: typedesc[Piksi_MsgFrontEndGain], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgFrontEndGain
proc read*(_: typedesc[Piksi_MsgResetDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgResetDep
proc read*(_: typedesc[Piksi_MsgSetTime], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgSetTime
proc read*(_: typedesc[Piksi_MsgCwResults], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCwResults
proc read*(_: typedesc[Piksi_MsgSpecanDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgSpecanDep
proc read*(_: typedesc[Piksi_MsgInitBaseDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgInitBaseDep
proc read*(_: typedesc[Piksi_Period], io: KaitaiStream, root: KaitaiStruct, parent: Piksi_MsgUartState): Piksi_Period
proc read*(_: typedesc[Piksi_MsgCwStart], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCwStart


proc read*(_: typedesc[Piksi], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Piksi =
  template this: untyped = result
  this = new(Piksi)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Piksi], filename: string): Piksi =
  Piksi.read(newKaitaiFileStream(filename), nil, nil)


##[
The state of a network interface on the Piksi. Data is made to reflect
output of ifaddrs struct returned by getifaddrs in c.

]##
proc read*(_: typedesc[Piksi_MsgNetworkStateResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgNetworkStateResp =
  template this: untyped = result
  this = new(Piksi_MsgNetworkStateResp)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  IPv4 address (all zero when unavailable)

  ]##
  for i in 0 ..< int(4):
    let it = this.io.readU1()
    this.ipv4Address.add(it)

  ##[
  IPv4 netmask CIDR notation

  ]##
  let ipv4MaskSizeExpr = this.io.readU1()
  this.ipv4MaskSize = ipv4MaskSizeExpr

  ##[
  IPv6 address (all zero when unavailable)

  ]##
  for i in 0 ..< int(16):
    let it = this.io.readU1()
    this.ipv6Address.add(it)

  ##[
  IPv6 netmask CIDR notation

  ]##
  let ipv6MaskSizeExpr = this.io.readU1()
  this.ipv6MaskSize = ipv6MaskSizeExpr

  ##[
  Number of Rx bytes

  ]##
  let rxBytesExpr = this.io.readU4le()
  this.rxBytes = rxBytesExpr

  ##[
  Number of Tx bytes

  ]##
  let txBytesExpr = this.io.readU4le()
  this.txBytes = txBytesExpr

  ##[
  Interface Name

  ]##
  let interfaceNameExpr = encode(this.io.readBytesFull(), "ascii")
  this.interfaceName = interfaceNameExpr

  ##[
  Interface flags from SIOCGIFFLAGS

  ]##
  let flagsExpr = this.io.readU4le()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Piksi_MsgNetworkStateResp], filename: string): Piksi_MsgNetworkStateResp =
  Piksi_MsgNetworkStateResp.read(newKaitaiFileStream(filename), nil, nil)


##[
The bandwidth usage for each interface can be reported within this
struct and utilize multiple fields to fully specify the type of traffic
that is being tracked. As either the interval of collection or the
collection time may vary, both a timestamp and period field is provided,
though may not necessarily be populated with a value.

]##
proc read*(_: typedesc[Piksi_NetworkUsage], io: KaitaiStream, root: KaitaiStruct, parent: Piksi_MsgNetworkBandwidthUsage): Piksi_NetworkUsage =
  template this: untyped = result
  this = new(Piksi_NetworkUsage)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Duration over which the measurement was collected

  ]##
  let durationExpr = this.io.readU8le()
  this.duration = durationExpr

  ##[
  Number of bytes handled in total within period

  ]##
  let totalBytesExpr = this.io.readU8le()
  this.totalBytes = totalBytesExpr

  ##[
  Number of bytes transmitted within period

  ]##
  let rxBytesExpr = this.io.readU4le()
  this.rxBytes = rxBytesExpr

  ##[
  Number of bytes received within period

  ]##
  let txBytesExpr = this.io.readU4le()
  this.txBytes = txBytesExpr

  ##[
  Interface Name

  ]##
  let interfaceNameExpr = encode(this.io.readBytesFull(), "ascii")
  this.interfaceName = interfaceNameExpr

proc fromFile*(_: typedesc[Piksi_NetworkUsage], filename: string): Piksi_NetworkUsage =
  Piksi_NetworkUsage.read(newKaitaiFileStream(filename), nil, nil)


##[
The response to MSG_COMMAND_REQ with the return code of the command.  A
return code of zero indicates success.

]##
proc read*(_: typedesc[Piksi_MsgCommandResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCommandResp =
  template this: untyped = result
  this = new(Piksi_MsgCommandResp)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  Exit code

  ]##
  let codeExpr = this.io.readS4le()
  this.code = codeExpr

proc fromFile*(_: typedesc[Piksi_MsgCommandResp], filename: string): Piksi_MsgCommandResp =
  Piksi_MsgCommandResp.read(newKaitaiFileStream(filename), nil, nil)


##[
Returns the standard output and standard error of the command requested
by MSG_COMMAND_REQ. The sequence number can be used to filter for
filtering the correct command.

]##
proc read*(_: typedesc[Piksi_MsgCommandOutput], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCommandOutput =
  template this: untyped = result
  this = new(Piksi_MsgCommandOutput)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  Line of standard output or standard error

  ]##
  let lineExpr = encode(this.io.readBytesFull(), "ascii")
  this.line = lineExpr

proc fromFile*(_: typedesc[Piksi_MsgCommandOutput], filename: string): Piksi_MsgCommandOutput =
  Piksi_MsgCommandOutput.read(newKaitaiFileStream(filename), nil, nil)


##[
Statistics on the latency of observations received from the base
station. As observation packets are received their GPS time is compared
to the current GPS time calculated locally by the receiver to give a
precise measurement of the end-to-end communication latency in the
system.

]##
proc read*(_: typedesc[Piksi_Latency], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Piksi_Latency =
  template this: untyped = result
  this = new(Piksi_Latency)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Average latency

  ]##
  let avgExpr = this.io.readS4le()
  this.avg = avgExpr

  ##[
  Minimum latency

  ]##
  let lminExpr = this.io.readS4le()
  this.lmin = lminExpr

  ##[
  Maximum latency

  ]##
  let lmaxExpr = this.io.readS4le()
  this.lmax = lmaxExpr

  ##[
  Smoothed estimate of the current latency

  ]##
  let currentExpr = this.io.readS4le()
  this.current = currentExpr

proc fromFile*(_: typedesc[Piksi_Latency], filename: string): Piksi_Latency =
  Piksi_Latency.read(newKaitaiFileStream(filename), nil, nil)


##[
The thread usage message from the device reports real-time operating
system (RTOS) thread usage statistics for the named thread. The reported
percentage values must be normalized.

]##
proc read*(_: typedesc[Piksi_MsgThreadState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgThreadState =
  template this: untyped = result
  this = new(Piksi_MsgThreadState)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Thread name (NULL terminated)

  ]##
  let nameExpr = encode(this.io.readBytesFull(), "ascii")
  this.name = nameExpr

  ##[
  Percentage cpu use for this thread. Values range from 0 - 1000 and
needs to be renormalized to 100

  ]##
  let cpuExpr = this.io.readU2le()
  this.cpu = cpuExpr

  ##[
  Free stack space for this thread

  ]##
  let stackFreeExpr = this.io.readU4le()
  this.stackFree = stackFreeExpr

proc fromFile*(_: typedesc[Piksi_MsgThreadState], filename: string): Piksi_MsgThreadState =
  Piksi_MsgThreadState.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated

]##
proc read*(_: typedesc[Piksi_MsgUartStateDepa], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgUartStateDepa =
  template this: untyped = result
  this = new(Piksi_MsgUartStateDepa)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  State of UART A

  ]##
  let uartAExpr = Piksi_UartChannel.read(this.io, this.root, this)
  this.uartA = uartAExpr

  ##[
  State of UART B

  ]##
  let uartBExpr = Piksi_UartChannel.read(this.io, this.root, this)
  this.uartB = uartBExpr

  ##[
  State of UART FTDI (USB logger)

  ]##
  let uartFtdiExpr = Piksi_UartChannel.read(this.io, this.root, this)
  this.uartFtdi = uartFtdiExpr

  ##[
  UART communication latency

  ]##
  let latencyExpr = Piksi_Latency.read(this.io, this.root, this)
  this.latency = latencyExpr

proc fromFile*(_: typedesc[Piksi_MsgUartStateDepa], filename: string): Piksi_MsgUartStateDepa =
  Piksi_MsgUartStateDepa.read(newKaitaiFileStream(filename), nil, nil)


##[
Request state of Piksi network interfaces. Output will be sent in
MSG_NETWORK_STATE_RESP messages.

]##
proc read*(_: typedesc[Piksi_MsgNetworkStateReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgNetworkStateReq =
  template this: untyped = result
  this = new(Piksi_MsgNetworkStateReq)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Piksi_MsgNetworkStateReq], filename: string): Piksi_MsgNetworkStateReq =
  Piksi_MsgNetworkStateReq.read(newKaitaiFileStream(filename), nil, nil)


##[
This message contains temperature and voltage level measurements from
the processor's monitoring system and the RF frontend die temperature if
available.

]##
proc read*(_: typedesc[Piksi_MsgDeviceMonitor], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgDeviceMonitor =
  template this: untyped = result
  this = new(Piksi_MsgDeviceMonitor)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Device V_in

  ]##
  let devVinExpr = this.io.readS2le()
  this.devVin = devVinExpr

  ##[
  Processor V_int

  ]##
  let cpuVintExpr = this.io.readS2le()
  this.cpuVint = cpuVintExpr

  ##[
  Processor V_aux

  ]##
  let cpuVauxExpr = this.io.readS2le()
  this.cpuVaux = cpuVauxExpr

  ##[
  Processor temperature

  ]##
  let cpuTemperatureExpr = this.io.readS2le()
  this.cpuTemperature = cpuTemperatureExpr

  ##[
  Frontend temperature (if available)

  ]##
  let feTemperatureExpr = this.io.readS2le()
  this.feTemperature = feTemperatureExpr

proc fromFile*(_: typedesc[Piksi_MsgDeviceMonitor], filename: string): Piksi_MsgDeviceMonitor =
  Piksi_MsgDeviceMonitor.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Piksi_MsgMaskSatelliteDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgMaskSatelliteDep =
  template this: untyped = result
  this = new(Piksi_MsgMaskSatelliteDep)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Mask of systems that should ignore this satellite.

  ]##
  let maskExpr = this.io.readU1()
  this.mask = maskExpr

  ##[
  GNSS signal for which the mask is applied

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

proc fromFile*(_: typedesc[Piksi_MsgMaskSatelliteDep], filename: string): Piksi_MsgMaskSatelliteDep =
  Piksi_MsgMaskSatelliteDep.read(newKaitaiFileStream(filename), nil, nil)


##[
The UART message reports data latency and throughput of the UART
channels providing SBP I/O. On the default Piksi configuration, UARTs A
and B are used for telemetry radios, but can also be host access ports
for embedded hosts, or other interfaces in future. The reported
percentage values must be normalized. Observations latency and period
can be used to assess the health of the differential corrections link.
Latency provides the timeliness of received base observations while the
period indicates their likelihood of transmission.

]##
proc read*(_: typedesc[Piksi_MsgUartState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgUartState =
  template this: untyped = result
  this = new(Piksi_MsgUartState)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  State of UART A

  ]##
  let uartAExpr = Piksi_UartChannel.read(this.io, this.root, this)
  this.uartA = uartAExpr

  ##[
  State of UART B

  ]##
  let uartBExpr = Piksi_UartChannel.read(this.io, this.root, this)
  this.uartB = uartBExpr

  ##[
  State of UART FTDI (USB logger)

  ]##
  let uartFtdiExpr = Piksi_UartChannel.read(this.io, this.root, this)
  this.uartFtdi = uartFtdiExpr

  ##[
  UART communication latency

  ]##
  let latencyExpr = Piksi_Latency.read(this.io, this.root, this)
  this.latency = latencyExpr

  ##[
  Observation receipt period

  ]##
  let obsPeriodExpr = Piksi_Period.read(this.io, this.root, this)
  this.obsPeriod = obsPeriodExpr

proc fromFile*(_: typedesc[Piksi_MsgUartState], filename: string): Piksi_MsgUartState =
  Piksi_MsgUartState.read(newKaitaiFileStream(filename), nil, nil)


##[
Spectrum analyzer packet.

]##
proc read*(_: typedesc[Piksi_MsgSpecan], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgSpecan =
  template this: untyped = result
  this = new(Piksi_MsgSpecan)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Channel ID

  ]##
  let channelTagExpr = this.io.readU2le()
  this.channelTag = channelTagExpr

  ##[
  Receiver time of this observation

  ]##
  let tExpr = Gnss_GpsTime.read(this.io, this.root, this)
  this.t = tExpr

  ##[
  Reference frequency of this packet

  ]##
  let freqRefExpr = this.io.readF4le()
  this.freqRef = freqRefExpr

  ##[
  Frequency step of points in this packet

  ]##
  let freqStepExpr = this.io.readF4le()
  this.freqStep = freqStepExpr

  ##[
  Reference amplitude of this packet

  ]##
  let amplitudeRefExpr = this.io.readF4le()
  this.amplitudeRef = amplitudeRefExpr

  ##[
  Amplitude unit value of points in this packet

  ]##
  let amplitudeUnitExpr = this.io.readF4le()
  this.amplitudeUnit = amplitudeUnitExpr

  ##[
  Amplitude values (in the above units) of points in this packet

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.amplitudeValue.add(it)
      inc i

proc fromFile*(_: typedesc[Piksi_MsgSpecan], filename: string): Piksi_MsgSpecan =
  Piksi_MsgSpecan.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the state of the Integer Ambiguity Resolution (IAR)
process, which resolves unknown integer ambiguities from double-
differenced carrier-phase measurements from satellite observations.

]##
proc read*(_: typedesc[Piksi_MsgIarState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgIarState =
  template this: untyped = result
  this = new(Piksi_MsgIarState)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Number of integer ambiguity hypotheses remaining

  ]##
  let numHypsExpr = this.io.readU4le()
  this.numHyps = numHypsExpr

proc fromFile*(_: typedesc[Piksi_MsgIarState], filename: string): Piksi_MsgIarState =
  Piksi_MsgIarState.read(newKaitaiFileStream(filename), nil, nil)


##[
This is a legacy message for sending and loading a satellite alamanac
onto the Piksi's flash memory from the host.

]##
proc read*(_: typedesc[Piksi_MsgAlmanac], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgAlmanac =
  template this: untyped = result
  this = new(Piksi_MsgAlmanac)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Piksi_MsgAlmanac], filename: string): Piksi_MsgAlmanac =
  Piksi_MsgAlmanac.read(newKaitaiFileStream(filename), nil, nil)


##[
This message resets either the DGNSS Kalman filters or Integer Ambiguity
Resolution (IAR) process.

]##
proc read*(_: typedesc[Piksi_MsgResetFilters], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgResetFilters =
  template this: untyped = result
  this = new(Piksi_MsgResetFilters)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Filter flags

  ]##
  let filterExpr = this.io.readU1()
  this.filter = filterExpr

proc fromFile*(_: typedesc[Piksi_MsgResetFilters], filename: string): Piksi_MsgResetFilters =
  Piksi_MsgResetFilters.read(newKaitaiFileStream(filename), nil, nil)


##[
Throughput, utilization, and error counts on the RX/TX buffers of this
UART channel. The reported percentage values must be normalized.

]##
proc read*(_: typedesc[Piksi_UartChannel], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Piksi_UartChannel =
  template this: untyped = result
  this = new(Piksi_UartChannel)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  UART transmit throughput

  ]##
  let txThroughputExpr = this.io.readF4le()
  this.txThroughput = txThroughputExpr

  ##[
  UART receive throughput

  ]##
  let rxThroughputExpr = this.io.readF4le()
  this.rxThroughput = rxThroughputExpr

  ##[
  UART CRC error count

  ]##
  let crcErrorCountExpr = this.io.readU2le()
  this.crcErrorCount = crcErrorCountExpr

  ##[
  UART IO error count

  ]##
  let ioErrorCountExpr = this.io.readU2le()
  this.ioErrorCount = ioErrorCountExpr

  ##[
  UART transmit buffer percentage utilization (ranges from 0 to 255)

  ]##
  let txBufferLevelExpr = this.io.readU1()
  this.txBufferLevel = txBufferLevelExpr

  ##[
  UART receive buffer percentage utilization (ranges from 0 to 255)

  ]##
  let rxBufferLevelExpr = this.io.readU1()
  this.rxBufferLevel = rxBufferLevelExpr

proc fromFile*(_: typedesc[Piksi_UartChannel], filename: string): Piksi_UartChannel =
  Piksi_UartChannel.read(newKaitaiFileStream(filename), nil, nil)


##[
Request the recipient to execute an command. Output will be sent in
MSG_LOG messages, and the exit code will be returned with
MSG_COMMAND_RESP.

]##
proc read*(_: typedesc[Piksi_MsgCommandReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCommandReq =
  template this: untyped = result
  this = new(Piksi_MsgCommandReq)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  Command line to execute

  ]##
  let commandExpr = encode(this.io.readBytesFull(), "ascii")
  this.command = commandExpr

proc fromFile*(_: typedesc[Piksi_MsgCommandReq], filename: string): Piksi_MsgCommandReq =
  Piksi_MsgCommandReq.read(newKaitaiFileStream(filename), nil, nil)


##[
This message allows setting a mask to prevent a particular satellite
from being used in various Piksi subsystems.

]##
proc read*(_: typedesc[Piksi_MsgMaskSatellite], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgMaskSatellite =
  template this: untyped = result
  this = new(Piksi_MsgMaskSatellite)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Mask of systems that should ignore this satellite.

  ]##
  let maskExpr = this.io.readU1()
  this.mask = maskExpr

  ##[
  GNSS signal for which the mask is applied

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

proc fromFile*(_: typedesc[Piksi_MsgMaskSatellite], filename: string): Piksi_MsgMaskSatellite =
  Piksi_MsgMaskSatellite.read(newKaitaiFileStream(filename), nil, nil)


##[
The bandwidth usage, a list of usage by interface.

]##
proc read*(_: typedesc[Piksi_MsgNetworkBandwidthUsage], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgNetworkBandwidthUsage =
  template this: untyped = result
  this = new(Piksi_MsgNetworkBandwidthUsage)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Usage measurement array

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Piksi_NetworkUsage.read(this.io, this.root, this)
      this.interfaces.add(it)
      inc i

proc fromFile*(_: typedesc[Piksi_MsgNetworkBandwidthUsage], filename: string): Piksi_MsgNetworkBandwidthUsage =
  Piksi_MsgNetworkBandwidthUsage.read(newKaitaiFileStream(filename), nil, nil)


##[
This message from the host resets the Piksi back into the bootloader.

]##
proc read*(_: typedesc[Piksi_MsgReset], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgReset =
  template this: untyped = result
  this = new(Piksi_MsgReset)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Reset flags

  ]##
  let flagsExpr = this.io.readU4le()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Piksi_MsgReset], filename: string): Piksi_MsgReset =
  Piksi_MsgReset.read(newKaitaiFileStream(filename), nil, nil)


##[
If a cell modem is present on a piksi device, this message will be send
periodically to update the host on the status of the modem and its
various parameters.

]##
proc read*(_: typedesc[Piksi_MsgCellModemStatus], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCellModemStatus =
  template this: untyped = result
  this = new(Piksi_MsgCellModemStatus)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Received cell signal strength in dBm, zero translates to unknown

  ]##
  let signalStrengthExpr = this.io.readS1()
  this.signalStrength = signalStrengthExpr

  ##[
  BER as reported by the modem, zero translates to unknown

  ]##
  let signalErrorRateExpr = this.io.readF4le()
  this.signalErrorRate = signalErrorRateExpr

  ##[
  Unspecified data TBD for this schema

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.reserved.add(it)
      inc i

proc fromFile*(_: typedesc[Piksi_MsgCellModemStatus], filename: string): Piksi_MsgCellModemStatus =
  Piksi_MsgCellModemStatus.read(newKaitaiFileStream(filename), nil, nil)


##[
This message describes the gain of each channel in the receiver
frontend. Each gain is encoded as a non-dimensional percentage relative
to the maximum range possible for the gain stage of the frontend. By
convention, each gain array has 8 entries and the index of the array
corresponding to the index of the rf channel in the frontend. A gain of
127 percent encodes that rf channel is not present in the hardware. A
negative value implies an error for the particular gain stage as
reported by the frontend.

]##
proc read*(_: typedesc[Piksi_MsgFrontEndGain], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgFrontEndGain =
  template this: untyped = result
  this = new(Piksi_MsgFrontEndGain)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  RF gain for each frontend channel

  ]##
  for i in 0 ..< int(8):
    let it = this.io.readS1()
    this.rfGain.add(it)

  ##[
  Intermediate frequency gain for each frontend channel

  ]##
  for i in 0 ..< int(8):
    let it = this.io.readS1()
    this.ifGain.add(it)

proc fromFile*(_: typedesc[Piksi_MsgFrontEndGain], filename: string): Piksi_MsgFrontEndGain =
  Piksi_MsgFrontEndGain.read(newKaitaiFileStream(filename), nil, nil)


##[
This message from the host resets the Piksi back into the bootloader.

]##
proc read*(_: typedesc[Piksi_MsgResetDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgResetDep =
  template this: untyped = result
  this = new(Piksi_MsgResetDep)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Piksi_MsgResetDep], filename: string): Piksi_MsgResetDep =
  Piksi_MsgResetDep.read(newKaitaiFileStream(filename), nil, nil)


##[
This message sets up timing functionality using a coarse GPS time
estimate sent by the host.

]##
proc read*(_: typedesc[Piksi_MsgSetTime], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgSetTime =
  template this: untyped = result
  this = new(Piksi_MsgSetTime)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Piksi_MsgSetTime], filename: string): Piksi_MsgSetTime =
  Piksi_MsgSetTime.read(newKaitaiFileStream(filename), nil, nil)


##[
This is an unused legacy message for result reporting from the CW
interference channel on the SwiftNAP. This message will be removed in a
future release.

]##
proc read*(_: typedesc[Piksi_MsgCwResults], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCwResults =
  template this: untyped = result
  this = new(Piksi_MsgCwResults)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Piksi_MsgCwResults], filename: string): Piksi_MsgCwResults =
  Piksi_MsgCwResults.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Piksi_MsgSpecanDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgSpecanDep =
  template this: untyped = result
  this = new(Piksi_MsgSpecanDep)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Channel ID

  ]##
  let channelTagExpr = this.io.readU2le()
  this.channelTag = channelTagExpr

  ##[
  Receiver time of this observation

  ]##
  let tExpr = Gnss_GpsTimeDep.read(this.io, this.root, this)
  this.t = tExpr

  ##[
  Reference frequency of this packet

  ]##
  let freqRefExpr = this.io.readF4le()
  this.freqRef = freqRefExpr

  ##[
  Frequency step of points in this packet

  ]##
  let freqStepExpr = this.io.readF4le()
  this.freqStep = freqStepExpr

  ##[
  Reference amplitude of this packet

  ]##
  let amplitudeRefExpr = this.io.readF4le()
  this.amplitudeRef = amplitudeRefExpr

  ##[
  Amplitude unit value of points in this packet

  ]##
  let amplitudeUnitExpr = this.io.readF4le()
  this.amplitudeUnit = amplitudeUnitExpr

  ##[
  Amplitude values (in the above units) of points in this packet

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.amplitudeValue.add(it)
      inc i

proc fromFile*(_: typedesc[Piksi_MsgSpecanDep], filename: string): Piksi_MsgSpecanDep =
  Piksi_MsgSpecanDep.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated

]##
proc read*(_: typedesc[Piksi_MsgInitBaseDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgInitBaseDep =
  template this: untyped = result
  this = new(Piksi_MsgInitBaseDep)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Piksi_MsgInitBaseDep], filename: string): Piksi_MsgInitBaseDep =
  Piksi_MsgInitBaseDep.read(newKaitaiFileStream(filename), nil, nil)


##[
Statistics on the period of observations received from the base station.
As complete observation sets are received, their time of reception is
compared with the prior set''s time of reception. This measurement
provides a proxy for link quality as incomplete or missing sets will
increase the period.  Long periods can cause momentary RTK solution
outages.

]##
proc read*(_: typedesc[Piksi_Period], io: KaitaiStream, root: KaitaiStruct, parent: Piksi_MsgUartState): Piksi_Period =
  template this: untyped = result
  this = new(Piksi_Period)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Average period

  ]##
  let avgExpr = this.io.readS4le()
  this.avg = avgExpr

  ##[
  Minimum period

  ]##
  let pminExpr = this.io.readS4le()
  this.pmin = pminExpr

  ##[
  Maximum period

  ]##
  let pmaxExpr = this.io.readS4le()
  this.pmax = pmaxExpr

  ##[
  Smoothed estimate of the current period

  ]##
  let currentExpr = this.io.readS4le()
  this.current = currentExpr

proc fromFile*(_: typedesc[Piksi_Period], filename: string): Piksi_Period =
  Piksi_Period.read(newKaitaiFileStream(filename), nil, nil)


##[
This is an unused legacy message from the host for starting the CW
interference channel on the SwiftNAP. This message will be removed in a
future release.

]##
proc read*(_: typedesc[Piksi_MsgCwStart], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Piksi_MsgCwStart =
  template this: untyped = result
  this = new(Piksi_MsgCwStart)
  let root = if root == nil: cast[Piksi](this) else: cast[Piksi](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Piksi_MsgCwStart], filename: string): Piksi_MsgCwStart =
  Piksi_MsgCwStart.read(newKaitaiFileStream(filename), nil, nil)

