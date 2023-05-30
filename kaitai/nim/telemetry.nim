import kaitai_struct_nim_runtime
import options
import gnss

type
  Telemetry* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Telemetry_TelemetrySv* = ref object of KaitaiStruct
    `az`*: uint8
    `el`*: int8
    `availabilityFlags`*: uint8
    `pseudorangeResidual`*: int16
    `phaseResidual`*: int16
    `outlierFlags`*: uint8
    `ephemerisFlags`*: uint8
    `correctionFlags`*: uint8
    `sid`*: Gnss_GnssSignal
    `parent`*: Telemetry_MsgTelSv
  Telemetry_MsgTelSv* = ref object of KaitaiStruct
    `wn`*: uint16
    `tow`*: uint32
    `nObs`*: uint8
    `originFlags`*: uint8
    `svTel`*: seq[Telemetry_TelemetrySv]
    `parent`*: Sbp_Message

proc read*(_: typedesc[Telemetry], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Telemetry
proc read*(_: typedesc[Telemetry_TelemetrySv], io: KaitaiStream, root: KaitaiStruct, parent: Telemetry_MsgTelSv): Telemetry_TelemetrySv
proc read*(_: typedesc[Telemetry_MsgTelSv], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Telemetry_MsgTelSv


proc read*(_: typedesc[Telemetry], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Telemetry =
  template this: untyped = result
  this = new(Telemetry)
  let root = if root == nil: cast[Telemetry](this) else: cast[Telemetry](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Telemetry], filename: string): Telemetry =
  Telemetry.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Telemetry_TelemetrySv], io: KaitaiStream, root: KaitaiStruct, parent: Telemetry_MsgTelSv): Telemetry_TelemetrySv =
  template this: untyped = result
  this = new(Telemetry_TelemetrySv)
  let root = if root == nil: cast[Telemetry](this) else: cast[Telemetry](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Azimuth angle (range 0..179)

  ]##
  let azExpr = this.io.readU1()
  this.az = azExpr

  ##[
  Elevation angle (range -90..90)

  ]##
  let elExpr = this.io.readS1()
  this.el = elExpr

  ##[
  Observation availability at filter update

  ]##
  let availabilityFlagsExpr = this.io.readU1()
  this.availabilityFlags = availabilityFlagsExpr

  ##[
  Pseudorange observation residual

  ]##
  let pseudorangeResidualExpr = this.io.readS2le()
  this.pseudorangeResidual = pseudorangeResidualExpr

  ##[
  Carrier-phase or carrier-phase-derived observation residual

  ]##
  let phaseResidualExpr = this.io.readS2le()
  this.phaseResidual = phaseResidualExpr

  ##[
  Reports if observation is marked as an outlier and is excluded from
the update

  ]##
  let outlierFlagsExpr = this.io.readU1()
  this.outlierFlags = outlierFlagsExpr

  ##[
  Ephemeris metadata

  ]##
  let ephemerisFlagsExpr = this.io.readU1()
  this.ephemerisFlags = ephemerisFlagsExpr

  ##[
  Reserved

  ]##
  let correctionFlagsExpr = this.io.readU1()
  this.correctionFlags = correctionFlagsExpr

  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

proc fromFile*(_: typedesc[Telemetry_TelemetrySv], filename: string): Telemetry_TelemetrySv =
  Telemetry_TelemetrySv.read(newKaitaiFileStream(filename), nil, nil)


##[
This message includes telemetry pertinent to satellite signals available
to Starling.

]##
proc read*(_: typedesc[Telemetry_MsgTelSv], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Telemetry_MsgTelSv =
  template this: untyped = result
  this = new(Telemetry_MsgTelSv)
  let root = if root == nil: cast[Telemetry](this) else: cast[Telemetry](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS week number

  ]##
  let wnExpr = this.io.readU2le()
  this.wn = wnExpr

  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Total number of observations. First nibble is the size of the
sequence (n), second nibble is the zero-indexed counter (ith packet
of n)

  ]##
  let nObsExpr = this.io.readU1()
  this.nObs = nObsExpr

  ##[
  Flags to identify the filter type from which the telemetry is
reported from

  ]##
  let originFlagsExpr = this.io.readU1()
  this.originFlags = originFlagsExpr

  ##[
  Array of per-signal telemetry entries

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Telemetry_TelemetrySv.read(this.io, this.root, this)
      this.svTel.add(it)
      inc i

proc fromFile*(_: typedesc[Telemetry_MsgTelSv], filename: string): Telemetry_MsgTelSv =
  Telemetry_MsgTelSv.read(newKaitaiFileStream(filename), nil, nil)

