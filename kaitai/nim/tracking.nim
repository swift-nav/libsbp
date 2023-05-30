import kaitai_struct_nim_runtime
import options
import gnss

type
  Tracking* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Tracking_MsgTrackingStateDetailedDep* = ref object of KaitaiStruct
    `recvTime`*: uint64
    `tot`*: Gnss_GpsTimeDep
    `p`*: uint32
    `pStd`*: uint16
    `l`*: Gnss_CarrierPhase
    `cn0`*: uint8
    `lock`*: uint16
    `sid`*: Gnss_GnssSignalDep
    `doppler`*: int32
    `dopplerStd`*: uint16
    `uptime`*: uint32
    `clockOffset`*: int16
    `clockDrift`*: int16
    `corrSpacing`*: uint16
    `acceleration`*: int8
    `syncFlags`*: uint8
    `towFlags`*: uint8
    `trackFlags`*: uint8
    `navFlags`*: uint8
    `psetFlags`*: uint8
    `miscFlags`*: uint8
    `parent`*: Sbp_Message
  Tracking_TrackingChannelStateDepB* = ref object of KaitaiStruct
    `state`*: uint8
    `sid`*: Gnss_GnssSignalDep
    `cn0`*: float32
    `parent`*: Tracking_MsgTrackingStateDepB
  Tracking_TrackingChannelState* = ref object of KaitaiStruct
    `sid`*: Gnss_GnssSignal
    `fcn`*: uint8
    `cn0`*: uint8
    `parent`*: Tracking_MsgTrackingState
  Tracking_MsgTrackingState* = ref object of KaitaiStruct
    `states`*: seq[Tracking_TrackingChannelState]
    `parent`*: Sbp_Message
  Tracking_TrackingChannelStateDepA* = ref object of KaitaiStruct
    `state`*: uint8
    `prn`*: uint8
    `cn0`*: float32
    `parent`*: Tracking_MsgTrackingStateDepA
  Tracking_MsgTrackingIqDepA* = ref object of KaitaiStruct
    `channel`*: uint8
    `sid`*: Gnss_GnssSignalDep
    `corrs`*: seq[uint64]
    `parent`*: Sbp_Message
  Tracking_TrackingChannelCorrelationDep* = ref object of KaitaiStruct
    `i`*: int32
    `q`*: int32
    `parent`*: KaitaiStruct
  Tracking_MsgTrackingStateDepA* = ref object of KaitaiStruct
    `states`*: seq[Tracking_TrackingChannelStateDepA]
    `parent`*: Sbp_Message
  Tracking_MsgMeasurementState* = ref object of KaitaiStruct
    `states`*: seq[Tracking_MeasurementState]
    `parent`*: Sbp_Message
  Tracking_TrackingChannelCorrelation* = ref object of KaitaiStruct
    `i`*: int16
    `q`*: int16
    `parent`*: KaitaiStruct
  Tracking_MsgTrackingIq* = ref object of KaitaiStruct
    `channel`*: uint8
    `sid`*: Gnss_GnssSignal
    `corrs`*: seq[uint64]
    `parent`*: Sbp_Message
  Tracking_MsgTrackingStateDetailedDepA* = ref object of KaitaiStruct
    `recvTime`*: uint64
    `tot`*: Gnss_GpsTime
    `p`*: uint32
    `pStd`*: uint16
    `l`*: Gnss_CarrierPhase
    `cn0`*: uint8
    `lock`*: uint16
    `sid`*: Gnss_GnssSignal
    `doppler`*: int32
    `dopplerStd`*: uint16
    `uptime`*: uint32
    `clockOffset`*: int16
    `clockDrift`*: int16
    `corrSpacing`*: uint16
    `acceleration`*: int8
    `syncFlags`*: uint8
    `towFlags`*: uint8
    `trackFlags`*: uint8
    `navFlags`*: uint8
    `psetFlags`*: uint8
    `miscFlags`*: uint8
    `parent`*: Sbp_Message
  Tracking_MsgTrackingStateDepB* = ref object of KaitaiStruct
    `states`*: seq[Tracking_TrackingChannelStateDepB]
    `parent`*: Sbp_Message
  Tracking_MeasurementState* = ref object of KaitaiStruct
    `mesid`*: Gnss_GnssSignal
    `cn0`*: uint8
    `parent`*: Tracking_MsgMeasurementState
  Tracking_MsgTrackingIqDepB* = ref object of KaitaiStruct
    `channel`*: uint8
    `sid`*: Gnss_GnssSignal
    `corrs`*: seq[uint64]
    `parent`*: Sbp_Message

proc read*(_: typedesc[Tracking], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Tracking
proc read*(_: typedesc[Tracking_MsgTrackingStateDetailedDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingStateDetailedDep
proc read*(_: typedesc[Tracking_TrackingChannelStateDepB], io: KaitaiStream, root: KaitaiStruct, parent: Tracking_MsgTrackingStateDepB): Tracking_TrackingChannelStateDepB
proc read*(_: typedesc[Tracking_TrackingChannelState], io: KaitaiStream, root: KaitaiStruct, parent: Tracking_MsgTrackingState): Tracking_TrackingChannelState
proc read*(_: typedesc[Tracking_MsgTrackingState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingState
proc read*(_: typedesc[Tracking_TrackingChannelStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Tracking_MsgTrackingStateDepA): Tracking_TrackingChannelStateDepA
proc read*(_: typedesc[Tracking_MsgTrackingIqDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingIqDepA
proc read*(_: typedesc[Tracking_TrackingChannelCorrelationDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Tracking_TrackingChannelCorrelationDep
proc read*(_: typedesc[Tracking_MsgTrackingStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingStateDepA
proc read*(_: typedesc[Tracking_MsgMeasurementState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgMeasurementState
proc read*(_: typedesc[Tracking_TrackingChannelCorrelation], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Tracking_TrackingChannelCorrelation
proc read*(_: typedesc[Tracking_MsgTrackingIq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingIq
proc read*(_: typedesc[Tracking_MsgTrackingStateDetailedDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingStateDetailedDepA
proc read*(_: typedesc[Tracking_MsgTrackingStateDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingStateDepB
proc read*(_: typedesc[Tracking_MeasurementState], io: KaitaiStream, root: KaitaiStruct, parent: Tracking_MsgMeasurementState): Tracking_MeasurementState
proc read*(_: typedesc[Tracking_MsgTrackingIqDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingIqDepB


proc read*(_: typedesc[Tracking], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Tracking =
  template this: untyped = result
  this = new(Tracking)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Tracking], filename: string): Tracking =
  Tracking.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Tracking_MsgTrackingStateDetailedDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingStateDetailedDep =
  template this: untyped = result
  this = new(Tracking_MsgTrackingStateDetailedDep)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Receiver clock time.

  ]##
  let recvTimeExpr = this.io.readU8le()
  this.recvTime = recvTimeExpr

  ##[
  Time of transmission of signal from satellite. TOW only valid when
TOW status is decoded or propagated. WN only valid when week number
valid flag is set.

  ]##
  let totExpr = Gnss_GpsTimeDep.read(this.io, this.root, this)
  this.tot = totExpr

  ##[
  Pseudorange observation. Valid only when pseudorange valid flag is
set.

  ]##
  let pExpr = this.io.readU4le()
  this.p = pExpr

  ##[
  Pseudorange observation standard deviation. Valid only when
pseudorange valid flag is set.

  ]##
  let pStdExpr = this.io.readU2le()
  this.pStd = pStdExpr

  ##[
  Carrier phase observation with typical sign convention. Valid only
when PLL pessimistic lock is achieved.

  ]##
  let lExpr = Gnss_CarrierPhase.read(this.io, this.root, this)
  this.l = lExpr

  ##[
  Carrier-to-Noise density

  ]##
  let cn0Expr = this.io.readU1()
  this.cn0 = cn0Expr

  ##[
  Lock time. It is encoded according to DF402 from the RTCM 10403.2
Amendment 2 specification. Valid values range from 0 to 15.

  ]##
  let lockExpr = this.io.readU2le()
  this.lock = lockExpr

  ##[
  GNSS signal identifier.

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Carrier Doppler frequency.

  ]##
  let dopplerExpr = this.io.readS4le()
  this.doppler = dopplerExpr

  ##[
  Carrier Doppler frequency standard deviation.

  ]##
  let dopplerStdExpr = this.io.readU2le()
  this.dopplerStd = dopplerStdExpr

  ##[
  Number of seconds of continuous tracking. Specifies how much time
signal is in continuous track.

  ]##
  let uptimeExpr = this.io.readU4le()
  this.uptime = uptimeExpr

  ##[
  TCXO clock offset. Valid only when valid clock valid flag is set.

  ]##
  let clockOffsetExpr = this.io.readS2le()
  this.clockOffset = clockOffsetExpr

  ##[
  TCXO clock drift. Valid only when valid clock valid flag is set.

  ]##
  let clockDriftExpr = this.io.readS2le()
  this.clockDrift = clockDriftExpr

  ##[
  Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.

  ]##
  let corrSpacingExpr = this.io.readU2le()
  this.corrSpacing = corrSpacingExpr

  ##[
  Acceleration. Valid only when acceleration valid flag is set.

  ]##
  let accelerationExpr = this.io.readS1()
  this.acceleration = accelerationExpr

  ##[
  Synchronization status flags.

  ]##
  let syncFlagsExpr = this.io.readU1()
  this.syncFlags = syncFlagsExpr

  ##[
  TOW status flags.

  ]##
  let towFlagsExpr = this.io.readU1()
  this.towFlags = towFlagsExpr

  ##[
  Tracking loop status flags.

  ]##
  let trackFlagsExpr = this.io.readU1()
  this.trackFlags = trackFlagsExpr

  ##[
  Navigation data status flags.

  ]##
  let navFlagsExpr = this.io.readU1()
  this.navFlags = navFlagsExpr

  ##[
  Parameters sets flags.

  ]##
  let psetFlagsExpr = this.io.readU1()
  this.psetFlags = psetFlagsExpr

  ##[
  Miscellaneous flags.

  ]##
  let miscFlagsExpr = this.io.readU1()
  this.miscFlags = miscFlagsExpr

proc fromFile*(_: typedesc[Tracking_MsgTrackingStateDetailedDep], filename: string): Tracking_MsgTrackingStateDetailedDep =
  Tracking_MsgTrackingStateDetailedDep.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Tracking_TrackingChannelStateDepB], io: KaitaiStream, root: KaitaiStruct, parent: Tracking_MsgTrackingStateDepB): Tracking_TrackingChannelStateDepB =
  template this: untyped = result
  this = new(Tracking_TrackingChannelStateDepB)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Status of tracking channel

  ]##
  let stateExpr = this.io.readU1()
  this.state = stateExpr

  ##[
  GNSS signal being tracked

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Carrier-to-noise density

  ]##
  let cn0Expr = this.io.readF4le()
  this.cn0 = cn0Expr

proc fromFile*(_: typedesc[Tracking_TrackingChannelStateDepB], filename: string): Tracking_TrackingChannelStateDepB =
  Tracking_TrackingChannelStateDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
Tracking channel state for a specific satellite signal and measured
signal power.

]##
proc read*(_: typedesc[Tracking_TrackingChannelState], io: KaitaiStream, root: KaitaiStruct, parent: Tracking_MsgTrackingState): Tracking_TrackingChannelState =
  template this: untyped = result
  this = new(Tracking_TrackingChannelState)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS signal being tracked

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Frequency channel number (GLONASS only)

  ]##
  let fcnExpr = this.io.readU1()
  this.fcn = fcnExpr

  ##[
  Carrier-to-Noise density.  Zero implies invalid cn0.

  ]##
  let cn0Expr = this.io.readU1()
  this.cn0 = cn0Expr

proc fromFile*(_: typedesc[Tracking_TrackingChannelState], filename: string): Tracking_TrackingChannelState =
  Tracking_TrackingChannelState.read(newKaitaiFileStream(filename), nil, nil)


##[
The tracking message returns a variable-length array of tracking channel
states. It reports status and carrier-to-noise density measurements for
all tracked satellites.

]##
proc read*(_: typedesc[Tracking_MsgTrackingState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingState =
  template this: untyped = result
  this = new(Tracking_MsgTrackingState)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Signal tracking channel state

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Tracking_TrackingChannelState.read(this.io, this.root, this)
      this.states.add(it)
      inc i

proc fromFile*(_: typedesc[Tracking_MsgTrackingState], filename: string): Tracking_MsgTrackingState =
  Tracking_MsgTrackingState.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Tracking_TrackingChannelStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Tracking_MsgTrackingStateDepA): Tracking_TrackingChannelStateDepA =
  template this: untyped = result
  this = new(Tracking_TrackingChannelStateDepA)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Status of tracking channel

  ]##
  let stateExpr = this.io.readU1()
  this.state = stateExpr

  ##[
  PRN-1 being tracked

  ]##
  let prnExpr = this.io.readU1()
  this.prn = prnExpr

  ##[
  Carrier-to-noise density

  ]##
  let cn0Expr = this.io.readF4le()
  this.cn0 = cn0Expr

proc fromFile*(_: typedesc[Tracking_TrackingChannelStateDepA], filename: string): Tracking_TrackingChannelStateDepA =
  Tracking_TrackingChannelStateDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Tracking_MsgTrackingIqDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingIqDepA =
  template this: untyped = result
  this = new(Tracking_MsgTrackingIqDepA)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Tracking channel of origin

  ]##
  let channelExpr = this.io.readU1()
  this.channel = channelExpr

  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Early, Prompt and Late correlations

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readU8le()
    this.corrs.add(it)

proc fromFile*(_: typedesc[Tracking_MsgTrackingIqDepA], filename: string): Tracking_MsgTrackingIqDepA =
  Tracking_MsgTrackingIqDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Structure containing in-phase and quadrature correlation components.

]##
proc read*(_: typedesc[Tracking_TrackingChannelCorrelationDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Tracking_TrackingChannelCorrelationDep =
  template this: untyped = result
  this = new(Tracking_TrackingChannelCorrelationDep)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  In-phase correlation

  ]##
  let iExpr = this.io.readS4le()
  this.i = iExpr

  ##[
  Quadrature correlation

  ]##
  let qExpr = this.io.readS4le()
  this.q = qExpr

proc fromFile*(_: typedesc[Tracking_TrackingChannelCorrelationDep], filename: string): Tracking_TrackingChannelCorrelationDep =
  Tracking_TrackingChannelCorrelationDep.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Tracking_MsgTrackingStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingStateDepA =
  template this: untyped = result
  this = new(Tracking_MsgTrackingStateDepA)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Satellite tracking channel state

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Tracking_TrackingChannelStateDepA.read(this.io, this.root, this)
      this.states.add(it)
      inc i

proc fromFile*(_: typedesc[Tracking_MsgTrackingStateDepA], filename: string): Tracking_MsgTrackingStateDepA =
  Tracking_MsgTrackingStateDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
The tracking message returns a variable-length array of tracking channel
states. It reports status and carrier-to-noise density measurements for
all tracked satellites.

]##
proc read*(_: typedesc[Tracking_MsgMeasurementState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgMeasurementState =
  template this: untyped = result
  this = new(Tracking_MsgMeasurementState)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  ME signal tracking channel state

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Tracking_MeasurementState.read(this.io, this.root, this)
      this.states.add(it)
      inc i

proc fromFile*(_: typedesc[Tracking_MsgMeasurementState], filename: string): Tracking_MsgMeasurementState =
  Tracking_MsgMeasurementState.read(newKaitaiFileStream(filename), nil, nil)


##[
Structure containing in-phase and quadrature correlation components.

]##
proc read*(_: typedesc[Tracking_TrackingChannelCorrelation], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Tracking_TrackingChannelCorrelation =
  template this: untyped = result
  this = new(Tracking_TrackingChannelCorrelation)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  In-phase correlation

  ]##
  let iExpr = this.io.readS2le()
  this.i = iExpr

  ##[
  Quadrature correlation

  ]##
  let qExpr = this.io.readS2le()
  this.q = qExpr

proc fromFile*(_: typedesc[Tracking_TrackingChannelCorrelation], filename: string): Tracking_TrackingChannelCorrelation =
  Tracking_TrackingChannelCorrelation.read(newKaitaiFileStream(filename), nil, nil)


##[
When enabled, a tracking channel can output the correlations at each
update interval.

]##
proc read*(_: typedesc[Tracking_MsgTrackingIq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingIq =
  template this: untyped = result
  this = new(Tracking_MsgTrackingIq)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Tracking channel of origin

  ]##
  let channelExpr = this.io.readU1()
  this.channel = channelExpr

  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Early, Prompt and Late correlations

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readU8le()
    this.corrs.add(it)

proc fromFile*(_: typedesc[Tracking_MsgTrackingIq], filename: string): Tracking_MsgTrackingIq =
  Tracking_MsgTrackingIq.read(newKaitaiFileStream(filename), nil, nil)


##[
The tracking message returns a set tracking channel parameters for a
single tracking channel useful for debugging issues.

]##
proc read*(_: typedesc[Tracking_MsgTrackingStateDetailedDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingStateDetailedDepA =
  template this: untyped = result
  this = new(Tracking_MsgTrackingStateDetailedDepA)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Receiver clock time.

  ]##
  let recvTimeExpr = this.io.readU8le()
  this.recvTime = recvTimeExpr

  ##[
  Time of transmission of signal from satellite. TOW only valid when
TOW status is decoded or propagated. WN only valid when week number
valid flag is set.

  ]##
  let totExpr = Gnss_GpsTime.read(this.io, this.root, this)
  this.tot = totExpr

  ##[
  Pseudorange observation. Valid only when pseudorange valid flag is
set.

  ]##
  let pExpr = this.io.readU4le()
  this.p = pExpr

  ##[
  Pseudorange observation standard deviation. Valid only when
pseudorange valid flag is set.

  ]##
  let pStdExpr = this.io.readU2le()
  this.pStd = pStdExpr

  ##[
  Carrier phase observation with typical sign convention. Valid only
when PLL pessimistic lock is achieved.

  ]##
  let lExpr = Gnss_CarrierPhase.read(this.io, this.root, this)
  this.l = lExpr

  ##[
  Carrier-to-Noise density

  ]##
  let cn0Expr = this.io.readU1()
  this.cn0 = cn0Expr

  ##[
  Lock time. It is encoded according to DF402 from the RTCM 10403.2
Amendment 2 specification. Valid values range from 0 to 15.

  ]##
  let lockExpr = this.io.readU2le()
  this.lock = lockExpr

  ##[
  GNSS signal identifier.

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Carrier Doppler frequency.

  ]##
  let dopplerExpr = this.io.readS4le()
  this.doppler = dopplerExpr

  ##[
  Carrier Doppler frequency standard deviation.

  ]##
  let dopplerStdExpr = this.io.readU2le()
  this.dopplerStd = dopplerStdExpr

  ##[
  Number of seconds of continuous tracking. Specifies how much time
signal is in continuous track.

  ]##
  let uptimeExpr = this.io.readU4le()
  this.uptime = uptimeExpr

  ##[
  TCXO clock offset. Valid only when valid clock valid flag is set.

  ]##
  let clockOffsetExpr = this.io.readS2le()
  this.clockOffset = clockOffsetExpr

  ##[
  TCXO clock drift. Valid only when valid clock valid flag is set.

  ]##
  let clockDriftExpr = this.io.readS2le()
  this.clockDrift = clockDriftExpr

  ##[
  Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.

  ]##
  let corrSpacingExpr = this.io.readU2le()
  this.corrSpacing = corrSpacingExpr

  ##[
  Acceleration. Valid only when acceleration valid flag is set.

  ]##
  let accelerationExpr = this.io.readS1()
  this.acceleration = accelerationExpr

  ##[
  Synchronization status flags.

  ]##
  let syncFlagsExpr = this.io.readU1()
  this.syncFlags = syncFlagsExpr

  ##[
  TOW status flags.

  ]##
  let towFlagsExpr = this.io.readU1()
  this.towFlags = towFlagsExpr

  ##[
  Tracking loop status flags.

  ]##
  let trackFlagsExpr = this.io.readU1()
  this.trackFlags = trackFlagsExpr

  ##[
  Navigation data status flags.

  ]##
  let navFlagsExpr = this.io.readU1()
  this.navFlags = navFlagsExpr

  ##[
  Parameters sets flags.

  ]##
  let psetFlagsExpr = this.io.readU1()
  this.psetFlags = psetFlagsExpr

  ##[
  Miscellaneous flags.

  ]##
  let miscFlagsExpr = this.io.readU1()
  this.miscFlags = miscFlagsExpr

proc fromFile*(_: typedesc[Tracking_MsgTrackingStateDetailedDepA], filename: string): Tracking_MsgTrackingStateDetailedDepA =
  Tracking_MsgTrackingStateDetailedDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Tracking_MsgTrackingStateDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingStateDepB =
  template this: untyped = result
  this = new(Tracking_MsgTrackingStateDepB)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Signal tracking channel state

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Tracking_TrackingChannelStateDepB.read(this.io, this.root, this)
      this.states.add(it)
      inc i

proc fromFile*(_: typedesc[Tracking_MsgTrackingStateDepB], filename: string): Tracking_MsgTrackingStateDepB =
  Tracking_MsgTrackingStateDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
Measurement Engine tracking channel state for a specific satellite
signal and measured signal power. The mesid field for Glonass can either
carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
1 to 28).

]##
proc read*(_: typedesc[Tracking_MeasurementState], io: KaitaiStream, root: KaitaiStruct, parent: Tracking_MsgMeasurementState): Tracking_MeasurementState =
  template this: untyped = result
  this = new(Tracking_MeasurementState)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Measurement Engine GNSS signal being tracked (carries either Glonass
FCN or SLOT)

  ]##
  let mesidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.mesid = mesidExpr

  ##[
  Carrier-to-Noise density.  Zero implies invalid cn0.

  ]##
  let cn0Expr = this.io.readU1()
  this.cn0 = cn0Expr

proc fromFile*(_: typedesc[Tracking_MeasurementState], filename: string): Tracking_MeasurementState =
  Tracking_MeasurementState.read(newKaitaiFileStream(filename), nil, nil)


##[
When enabled, a tracking channel can output the correlations at each
update interval.

]##
proc read*(_: typedesc[Tracking_MsgTrackingIqDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Tracking_MsgTrackingIqDepB =
  template this: untyped = result
  this = new(Tracking_MsgTrackingIqDepB)
  let root = if root == nil: cast[Tracking](this) else: cast[Tracking](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Tracking channel of origin

  ]##
  let channelExpr = this.io.readU1()
  this.channel = channelExpr

  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Early, Prompt and Late correlations

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readU8le()
    this.corrs.add(it)

proc fromFile*(_: typedesc[Tracking_MsgTrackingIqDepB], filename: string): Tracking_MsgTrackingIqDepB =
  Tracking_MsgTrackingIqDepB.read(newKaitaiFileStream(filename), nil, nil)

