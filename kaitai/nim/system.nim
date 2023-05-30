import kaitai_struct_nim_runtime
import options

type
  System* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  System_MsgHeartbeat* = ref object of KaitaiStruct
    `flags`*: uint32
    `parent`*: Sbp_Message
  System_MsgStatusJournal* = ref object of KaitaiStruct
    `reportingSystem`*: uint16
    `sbpVersion`*: uint16
    `totalStatusReports`*: uint32
    `sequenceDescriptor`*: uint8
    `journal`*: seq[System_StatusJournalItem]
    `parent`*: Sbp_Message
  System_MsgInsStatus* = ref object of KaitaiStruct
    `flags`*: uint32
    `parent`*: Sbp_Message
  System_MsgGnssTimeOffset* = ref object of KaitaiStruct
    `weeks`*: int16
    `milliseconds`*: int32
    `microseconds`*: int16
    `flags`*: uint8
    `parent`*: Sbp_Message
  System_MsgCsacTelemetry* = ref object of KaitaiStruct
    `id`*: uint8
    `telemetry`*: string
    `parent`*: Sbp_Message
  System_MsgPpsTime* = ref object of KaitaiStruct
    `time`*: uint64
    `flags`*: uint8
    `parent`*: Sbp_Message
  System_MsgInsUpdates* = ref object of KaitaiStruct
    `tow`*: uint32
    `gnsspos`*: uint8
    `gnssvel`*: uint8
    `wheelticks`*: uint8
    `speed`*: uint8
    `nhc`*: uint8
    `zerovel`*: uint8
    `parent`*: Sbp_Message
  System_MsgDgnssStatus* = ref object of KaitaiStruct
    `flags`*: uint8
    `latency`*: uint16
    `numSignals`*: uint8
    `source`*: string
    `parent`*: Sbp_Message
  System_MsgCsacTelemetryLabels* = ref object of KaitaiStruct
    `id`*: uint8
    `telemetryLabels`*: string
    `parent`*: Sbp_Message
  System_MsgStartup* = ref object of KaitaiStruct
    `cause`*: uint8
    `startupType`*: uint8
    `reserved`*: uint16
    `parent`*: Sbp_Message
  System_MsgGroupMeta* = ref object of KaitaiStruct
    `groupId`*: uint8
    `flags`*: uint8
    `nGroupMsgs`*: uint8
    `groupMsgs`*: seq[uint16]
    `parent`*: Sbp_Message
  System_MsgSensorAidEvent* = ref object of KaitaiStruct
    `time`*: uint32
    `sensorType`*: uint8
    `sensorId`*: uint16
    `sensorState`*: uint8
    `nAvailableMeas`*: uint8
    `nAttemptedMeas`*: uint8
    `nAcceptedMeas`*: uint8
    `flags`*: uint32
    `parent`*: Sbp_Message
  System_SubSystemReport* = ref object of KaitaiStruct
    `component`*: uint16
    `generic`*: uint8
    `specific`*: uint8
    `parent`*: KaitaiStruct
  System_MsgStatusReport* = ref object of KaitaiStruct
    `reportingSystem`*: uint16
    `sbpVersion`*: uint16
    `sequence`*: uint32
    `uptime`*: uint32
    `status`*: seq[System_SubSystemReport]
    `parent`*: Sbp_Message
  System_StatusJournalItem* = ref object of KaitaiStruct
    `uptime`*: uint32
    `report`*: System_SubSystemReport
    `parent`*: System_MsgStatusJournal

proc read*(_: typedesc[System], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): System
proc read*(_: typedesc[System_MsgHeartbeat], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgHeartbeat
proc read*(_: typedesc[System_MsgStatusJournal], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgStatusJournal
proc read*(_: typedesc[System_MsgInsStatus], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgInsStatus
proc read*(_: typedesc[System_MsgGnssTimeOffset], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgGnssTimeOffset
proc read*(_: typedesc[System_MsgCsacTelemetry], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgCsacTelemetry
proc read*(_: typedesc[System_MsgPpsTime], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgPpsTime
proc read*(_: typedesc[System_MsgInsUpdates], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgInsUpdates
proc read*(_: typedesc[System_MsgDgnssStatus], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgDgnssStatus
proc read*(_: typedesc[System_MsgCsacTelemetryLabels], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgCsacTelemetryLabels
proc read*(_: typedesc[System_MsgStartup], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgStartup
proc read*(_: typedesc[System_MsgGroupMeta], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgGroupMeta
proc read*(_: typedesc[System_MsgSensorAidEvent], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgSensorAidEvent
proc read*(_: typedesc[System_SubSystemReport], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): System_SubSystemReport
proc read*(_: typedesc[System_MsgStatusReport], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgStatusReport
proc read*(_: typedesc[System_StatusJournalItem], io: KaitaiStream, root: KaitaiStruct, parent: System_MsgStatusJournal): System_StatusJournalItem


proc read*(_: typedesc[System], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): System =
  template this: untyped = result
  this = new(System)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[System], filename: string): System =
  System.read(newKaitaiFileStream(filename), nil, nil)


##[
The heartbeat message is sent periodically to inform the host or other
attached devices that the system is running. It is used to monitor
system malfunctions. It also contains status flags that indicate to the
host the status of the system and whether it is operating correctly.
Currently, the expected heartbeat interval is 1 sec.

The system error flag is used to indicate that an error has occurred in
the system. To determine the source of the error, the remaining error
flags should be inspected.

]##
proc read*(_: typedesc[System_MsgHeartbeat], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgHeartbeat =
  template this: untyped = result
  this = new(System_MsgHeartbeat)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU4le()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[System_MsgHeartbeat], filename: string): System_MsgHeartbeat =
  System_MsgHeartbeat.read(newKaitaiFileStream(filename), nil, nil)


##[
The status journal message contains past status reports (see
MSG_STATUS_REPORT) and functions as a error/event storage for telemetry
purposes.

]##
proc read*(_: typedesc[System_MsgStatusJournal], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgStatusJournal =
  template this: untyped = result
  this = new(System_MsgStatusJournal)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Identity of reporting system

  ]##
  let reportingSystemExpr = this.io.readU2le()
  this.reportingSystem = reportingSystemExpr

  ##[
  SBP protocol version

  ]##
  let sbpVersionExpr = this.io.readU2le()
  this.sbpVersion = sbpVersionExpr

  ##[
  Total number of status reports sent since system startup

  ]##
  let totalStatusReportsExpr = this.io.readU4le()
  this.totalStatusReports = totalStatusReportsExpr

  ##[
  Index and number of messages in this sequence. First nibble is the
size of the sequence (n), second nibble is the zero-indexed counter
(ith packet of n)

  ]##
  let sequenceDescriptorExpr = this.io.readU1()
  this.sequenceDescriptor = sequenceDescriptorExpr

  ##[
  Status journal

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = System_StatusJournalItem.read(this.io, this.root, this)
      this.journal.add(it)
      inc i

proc fromFile*(_: typedesc[System_MsgStatusJournal], filename: string): System_MsgStatusJournal =
  System_MsgStatusJournal.read(newKaitaiFileStream(filename), nil, nil)


##[
The INS status message describes the state of the operation and
initialization of the inertial navigation system.

]##
proc read*(_: typedesc[System_MsgInsStatus], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgInsStatus =
  template this: untyped = result
  this = new(System_MsgInsStatus)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU4le()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[System_MsgInsStatus], filename: string): System_MsgInsStatus =
  System_MsgInsStatus.read(newKaitaiFileStream(filename), nil, nil)


##[
The GNSS time offset message contains the information that is needed to
translate messages tagged with a local timestamp (e.g. IMU or wheeltick
messages) to GNSS time for the sender producing this message.

]##
proc read*(_: typedesc[System_MsgGnssTimeOffset], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgGnssTimeOffset =
  template this: untyped = result
  this = new(System_MsgGnssTimeOffset)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Weeks portion of the time offset

  ]##
  let weeksExpr = this.io.readS2le()
  this.weeks = weeksExpr

  ##[
  Milliseconds portion of the time offset

  ]##
  let millisecondsExpr = this.io.readS4le()
  this.milliseconds = millisecondsExpr

  ##[
  Microseconds portion of the time offset

  ]##
  let microsecondsExpr = this.io.readS2le()
  this.microseconds = microsecondsExpr

  ##[
  Status flags (reserved)

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[System_MsgGnssTimeOffset], filename: string): System_MsgGnssTimeOffset =
  System_MsgGnssTimeOffset.read(newKaitaiFileStream(filename), nil, nil)


##[
The CSAC telemetry message has an implementation defined telemetry
string from a device. It is not produced or available on general Swift
Products. It is intended to be a low rate message for status purposes.

]##
proc read*(_: typedesc[System_MsgCsacTelemetry], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgCsacTelemetry =
  template this: untyped = result
  this = new(System_MsgCsacTelemetry)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Index representing the type of telemetry in use.  It is
implementation defined.

  ]##
  let idExpr = this.io.readU1()
  this.id = idExpr

  ##[
  Comma separated list of values as defined by the index

  ]##
  let telemetryExpr = encode(this.io.readBytesFull(), "ascii")
  this.telemetry = telemetryExpr

proc fromFile*(_: typedesc[System_MsgCsacTelemetry], filename: string): System_MsgCsacTelemetry =
  System_MsgCsacTelemetry.read(newKaitaiFileStream(filename), nil, nil)


##[
The PPS time message contains the value of the sender's local time in
microseconds at the moment a pulse is detected on the PPS input. This is
to be used for syncronisation of sensor data sampled with a local
timestamp (e.g. IMU or wheeltick messages) where GNSS time is unknown to
the sender.

The local time used to timestamp the PPS pulse must be generated by the
same clock which is used to timestamp the IMU/wheel sensor data and
should follow the same roll-over rules.  A separate MSG_PPS_TIME message
should be sent for each source of sensor data which uses PPS-relative
timestamping.  The sender ID for each of these MSG_PPS_TIME messages
should match the sender ID of the respective sensor data.

]##
proc read*(_: typedesc[System_MsgPpsTime], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgPpsTime =
  template this: untyped = result
  this = new(System_MsgPpsTime)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Local time in microseconds

  ]##
  let timeExpr = this.io.readU8le()
  this.time = timeExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[System_MsgPpsTime], filename: string): System_MsgPpsTime =
  System_MsgPpsTime.read(newKaitaiFileStream(filename), nil, nil)


##[
The INS update status message contains information about executed and
rejected INS updates. This message is expected to be extended in the
future as new types of measurements are being added.

]##
proc read*(_: typedesc[System_MsgInsUpdates], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgInsUpdates =
  template this: untyped = result
  this = new(System_MsgInsUpdates)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  GNSS position update status flags

  ]##
  let gnssposExpr = this.io.readU1()
  this.gnsspos = gnssposExpr

  ##[
  GNSS velocity update status flags

  ]##
  let gnssvelExpr = this.io.readU1()
  this.gnssvel = gnssvelExpr

  ##[
  Wheelticks update status flags

  ]##
  let wheelticksExpr = this.io.readU1()
  this.wheelticks = wheelticksExpr

  ##[
  Wheelticks update status flags

  ]##
  let speedExpr = this.io.readU1()
  this.speed = speedExpr

  ##[
  NHC update status flags

  ]##
  let nhcExpr = this.io.readU1()
  this.nhc = nhcExpr

  ##[
  Zero velocity update status flags

  ]##
  let zerovelExpr = this.io.readU1()
  this.zerovel = zerovelExpr

proc fromFile*(_: typedesc[System_MsgInsUpdates], filename: string): System_MsgInsUpdates =
  System_MsgInsUpdates.read(newKaitaiFileStream(filename), nil, nil)


##[
This message provides information about the receipt of Differential
corrections.  It is expected to be sent with each receipt of a complete
corrections packet.

]##
proc read*(_: typedesc[System_MsgDgnssStatus], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgDgnssStatus =
  template this: untyped = result
  this = new(System_MsgDgnssStatus)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  Latency of observation receipt

  ]##
  let latencyExpr = this.io.readU2le()
  this.latency = latencyExpr

  ##[
  Number of signals from base station

  ]##
  let numSignalsExpr = this.io.readU1()
  this.numSignals = numSignalsExpr

  ##[
  Corrections source string

  ]##
  let sourceExpr = encode(this.io.readBytesFull(), "ascii")
  this.source = sourceExpr

proc fromFile*(_: typedesc[System_MsgDgnssStatus], filename: string): System_MsgDgnssStatus =
  System_MsgDgnssStatus.read(newKaitaiFileStream(filename), nil, nil)


##[
The CSAC telemetry message provides labels for each member of the string
produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
lower rate than the MSG_CSAC_TELEMETRY.

]##
proc read*(_: typedesc[System_MsgCsacTelemetryLabels], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgCsacTelemetryLabels =
  template this: untyped = result
  this = new(System_MsgCsacTelemetryLabels)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Index representing the type of telemetry in use.  It is
implementation defined.

  ]##
  let idExpr = this.io.readU1()
  this.id = idExpr

  ##[
  Comma separated list of telemetry field values

  ]##
  let telemetryLabelsExpr = encode(this.io.readBytesFull(), "ascii")
  this.telemetryLabels = telemetryLabelsExpr

proc fromFile*(_: typedesc[System_MsgCsacTelemetryLabels], filename: string): System_MsgCsacTelemetryLabels =
  System_MsgCsacTelemetryLabels.read(newKaitaiFileStream(filename), nil, nil)


##[
The system start-up message is sent once on system start-up. It notifies
the host or other attached devices that the system has started and is
now ready to respond to commands or configuration requests.

]##
proc read*(_: typedesc[System_MsgStartup], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgStartup =
  template this: untyped = result
  this = new(System_MsgStartup)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Cause of startup

  ]##
  let causeExpr = this.io.readU1()
  this.cause = causeExpr

  ##[
  Startup type

  ]##
  let startupTypeExpr = this.io.readU1()
  this.startupType = startupTypeExpr

  ##[
  Reserved

  ]##
  let reservedExpr = this.io.readU2le()
  this.reserved = reservedExpr

proc fromFile*(_: typedesc[System_MsgStartup], filename: string): System_MsgStartup =
  System_MsgStartup.read(newKaitaiFileStream(filename), nil, nil)


##[
This leading message lists the time metadata of the Solution Group. It
also lists the atomic contents (i.e. types of messages included) of the
Solution Group.

]##
proc read*(_: typedesc[System_MsgGroupMeta], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgGroupMeta =
  template this: untyped = result
  this = new(System_MsgGroupMeta)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss

  ]##
  let groupIdExpr = this.io.readU1()
  this.groupId = groupIdExpr

  ##[
  Status flags (reserved)

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  Size of list group_msgs

  ]##
  let nGroupMsgsExpr = this.io.readU1()
  this.nGroupMsgs = nGroupMsgsExpr

  ##[
  An in-order list of message types included in the Solution Group,
including GROUP_META itself

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU2le()
      this.groupMsgs.add(it)
      inc i

proc fromFile*(_: typedesc[System_MsgGroupMeta], filename: string): System_MsgGroupMeta =
  System_MsgGroupMeta.read(newKaitaiFileStream(filename), nil, nil)


##[
This diagnostic message contains state and update status information for
all sensors that are being used by the fusion engine. This message will
be generated asynchronously to the solution messages and will be emitted
anytime a sensor update is being processed.

]##
proc read*(_: typedesc[System_MsgSensorAidEvent], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgSensorAidEvent =
  template this: untyped = result
  this = new(System_MsgSensorAidEvent)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Update timestamp in milliseconds.

  ]##
  let timeExpr = this.io.readU4le()
  this.time = timeExpr

  ##[
  Sensor type

  ]##
  let sensorTypeExpr = this.io.readU1()
  this.sensorType = sensorTypeExpr

  ##[
  Sensor identifier

  ]##
  let sensorIdExpr = this.io.readU2le()
  this.sensorId = sensorIdExpr

  ##[
  Reserved for future use

  ]##
  let sensorStateExpr = this.io.readU1()
  this.sensorState = sensorStateExpr

  ##[
  Number of available measurements in this epoch

  ]##
  let nAvailableMeasExpr = this.io.readU1()
  this.nAvailableMeas = nAvailableMeasExpr

  ##[
  Number of attempted measurements in this epoch

  ]##
  let nAttemptedMeasExpr = this.io.readU1()
  this.nAttemptedMeas = nAttemptedMeasExpr

  ##[
  Number of accepted measurements in this epoch

  ]##
  let nAcceptedMeasExpr = this.io.readU1()
  this.nAcceptedMeas = nAcceptedMeasExpr

  ##[
  Reserved for future use

  ]##
  let flagsExpr = this.io.readU4le()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[System_MsgSensorAidEvent], filename: string): System_MsgSensorAidEvent =
  System_MsgSensorAidEvent.read(newKaitaiFileStream(filename), nil, nil)


##[
Report the general and specific state of a subsystem.  If the generic
state is reported as initializing, the specific state should be ignored.

]##
proc read*(_: typedesc[System_SubSystemReport], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): System_SubSystemReport =
  template this: untyped = result
  this = new(System_SubSystemReport)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Identity of reporting subsystem

  ]##
  let componentExpr = this.io.readU2le()
  this.component = componentExpr

  ##[
  Generic form status report

  ]##
  let genericExpr = this.io.readU1()
  this.generic = genericExpr

  ##[
  Subsystem specific status code

  ]##
  let specificExpr = this.io.readU1()
  this.specific = specificExpr

proc fromFile*(_: typedesc[System_SubSystemReport], filename: string): System_SubSystemReport =
  System_SubSystemReport.read(newKaitaiFileStream(filename), nil, nil)


##[
The status report is sent periodically to inform the host or other
attached devices that the system is running. It is used to monitor
system malfunctions. It contains status reports that indicate to the
host the status of each subsystem and whether it is operating correctly.

Interpretation of the subsystem specific status code is product
dependent, but if the generic status code is initializing, it should be
ignored.  Refer to product documentation for details.

]##
proc read*(_: typedesc[System_MsgStatusReport], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): System_MsgStatusReport =
  template this: untyped = result
  this = new(System_MsgStatusReport)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Identity of reporting system

  ]##
  let reportingSystemExpr = this.io.readU2le()
  this.reportingSystem = reportingSystemExpr

  ##[
  SBP protocol version

  ]##
  let sbpVersionExpr = this.io.readU2le()
  this.sbpVersion = sbpVersionExpr

  ##[
  Increments on each status report sent

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  Number of seconds since system start-up

  ]##
  let uptimeExpr = this.io.readU4le()
  this.uptime = uptimeExpr

  ##[
  Reported status of individual subsystems

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = System_SubSystemReport.read(this.io, this.root, this)
      this.status.add(it)
      inc i

proc fromFile*(_: typedesc[System_MsgStatusReport], filename: string): System_MsgStatusReport =
  System_MsgStatusReport.read(newKaitaiFileStream(filename), nil, nil)


##[
Reports the uptime and the state of a subsystem via generic and specific
status codes.  If the generic state is reported as initializing, the
specific state should be ignored.

]##
proc read*(_: typedesc[System_StatusJournalItem], io: KaitaiStream, root: KaitaiStruct, parent: System_MsgStatusJournal): System_StatusJournalItem =
  template this: untyped = result
  this = new(System_StatusJournalItem)
  let root = if root == nil: cast[System](this) else: cast[System](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Milliseconds since system startup

  ]##
  let uptimeExpr = this.io.readU4le()
  this.uptime = uptimeExpr
  let reportExpr = System_SubSystemReport.read(this.io, this.root, this)
  this.report = reportExpr

proc fromFile*(_: typedesc[System_StatusJournalItem], filename: string): System_StatusJournalItem =
  System_StatusJournalItem.read(newKaitaiFileStream(filename), nil, nil)

