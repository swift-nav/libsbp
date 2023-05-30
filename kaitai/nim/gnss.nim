import kaitai_struct_nim_runtime
import options

type
  Gnss* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Gnss_GnssSignalDep* = ref object of KaitaiStruct
    `sat`*: uint16
    `code`*: uint8
    `reserved`*: uint8
    `parent`*: KaitaiStruct
  Gnss_CarrierPhase* = ref object of KaitaiStruct
    `i`*: int32
    `f`*: uint8
    `parent`*: KaitaiStruct
  Gnss_GpsTimeDep* = ref object of KaitaiStruct
    `tow`*: uint32
    `wn`*: uint16
    `parent`*: KaitaiStruct
  Gnss_GnssSignal* = ref object of KaitaiStruct
    `sat`*: uint8
    `code`*: uint8
    `parent`*: KaitaiStruct
  Gnss_GpsTime* = ref object of KaitaiStruct
    `tow`*: uint32
    `nsResidual`*: int32
    `wn`*: uint16
    `parent`*: KaitaiStruct
  Gnss_GpsTimeSec* = ref object of KaitaiStruct
    `tow`*: uint32
    `wn`*: uint16
    `parent`*: KaitaiStruct
  Gnss_SvId* = ref object of KaitaiStruct
    `satId`*: uint8
    `constellation`*: uint8
    `parent`*: KaitaiStruct

proc read*(_: typedesc[Gnss], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss
proc read*(_: typedesc[Gnss_GnssSignalDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GnssSignalDep
proc read*(_: typedesc[Gnss_CarrierPhase], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_CarrierPhase
proc read*(_: typedesc[Gnss_GpsTimeDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GpsTimeDep
proc read*(_: typedesc[Gnss_GnssSignal], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GnssSignal
proc read*(_: typedesc[Gnss_GpsTime], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GpsTime
proc read*(_: typedesc[Gnss_GpsTimeSec], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GpsTimeSec
proc read*(_: typedesc[Gnss_SvId], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_SvId


proc read*(_: typedesc[Gnss], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss =
  template this: untyped = result
  this = new(Gnss)
  let root = if root == nil: cast[Gnss](this) else: cast[Gnss](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Gnss], filename: string): Gnss =
  Gnss.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Gnss_GnssSignalDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GnssSignalDep =
  template this: untyped = result
  this = new(Gnss_GnssSignalDep)
  let root = if root == nil: cast[Gnss](this) else: cast[Gnss](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Constellation-specific satellite identifier.

Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1).
Other constellations do not have this offset.

  ]##
  let satExpr = this.io.readU2le()
  this.sat = satExpr

  ##[
  Signal constellation, band and code

  ]##
  let codeExpr = this.io.readU1()
  this.code = codeExpr

  ##[
  Reserved

  ]##
  let reservedExpr = this.io.readU1()
  this.reserved = reservedExpr

proc fromFile*(_: typedesc[Gnss_GnssSignalDep], filename: string): Gnss_GnssSignalDep =
  Gnss_GnssSignalDep.read(newKaitaiFileStream(filename), nil, nil)


##[
Carrier phase measurement in cycles represented as a 40-bit fixed point
number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
fractional cycles. This phase has the same sign as the pseudorange.

]##
proc read*(_: typedesc[Gnss_CarrierPhase], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_CarrierPhase =
  template this: untyped = result
  this = new(Gnss_CarrierPhase)
  let root = if root == nil: cast[Gnss](this) else: cast[Gnss](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Carrier phase whole cycles

  ]##
  let iExpr = this.io.readS4le()
  this.i = iExpr

  ##[
  Carrier phase fractional part

  ]##
  let fExpr = this.io.readU1()
  this.f = fExpr

proc fromFile*(_: typedesc[Gnss_CarrierPhase], filename: string): Gnss_CarrierPhase =
  Gnss_CarrierPhase.read(newKaitaiFileStream(filename), nil, nil)


##[
A wire-appropriate GPS time, defined as the number of milliseconds since
beginning of the week on the Saturday/Sunday transition.

]##
proc read*(_: typedesc[Gnss_GpsTimeDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GpsTimeDep =
  template this: untyped = result
  this = new(Gnss_GpsTimeDep)
  let root = if root == nil: cast[Gnss](this) else: cast[Gnss](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Milliseconds since start of GPS week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  GPS week number

  ]##
  let wnExpr = this.io.readU2le()
  this.wn = wnExpr

proc fromFile*(_: typedesc[Gnss_GpsTimeDep], filename: string): Gnss_GpsTimeDep =
  Gnss_GpsTimeDep.read(newKaitaiFileStream(filename), nil, nil)


##[
Signal identifier containing constellation, band, and satellite
identifier.

]##
proc read*(_: typedesc[Gnss_GnssSignal], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GnssSignal =
  template this: untyped = result
  this = new(Gnss_GnssSignal)
  let root = if root == nil: cast[Gnss](this) else: cast[Gnss](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Constellation-specific satellite id. For GLO can either be (100+FCN)
where FCN is in [-7,+6] or the Slot ID in [1,28].

  ]##
  let satExpr = this.io.readU1()
  this.sat = satExpr

  ##[
  Signal constellation, band and code

  ]##
  let codeExpr = this.io.readU1()
  this.code = codeExpr

proc fromFile*(_: typedesc[Gnss_GnssSignal], filename: string): Gnss_GnssSignal =
  Gnss_GnssSignal.read(newKaitaiFileStream(filename), nil, nil)


##[
A wire-appropriate receiver clock time, defined as the time since the
beginning of the week on the Saturday/Sunday transition. In most cases,
observations are epoch aligned so ns field will be 0.

]##
proc read*(_: typedesc[Gnss_GpsTime], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GpsTime =
  template this: untyped = result
  this = new(Gnss_GpsTime)
  let root = if root == nil: cast[Gnss](this) else: cast[Gnss](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Milliseconds since start of GPS week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Nanosecond residual of millisecond-rounded TOW (ranges from -500000
to 500000)

  ]##
  let nsResidualExpr = this.io.readS4le()
  this.nsResidual = nsResidualExpr

  ##[
  GPS week number

  ]##
  let wnExpr = this.io.readU2le()
  this.wn = wnExpr

proc fromFile*(_: typedesc[Gnss_GpsTime], filename: string): Gnss_GpsTime =
  Gnss_GpsTime.read(newKaitaiFileStream(filename), nil, nil)


##[
A GPS time, defined as the number of seconds since beginning of the week
on the Saturday/Sunday transition.

]##
proc read*(_: typedesc[Gnss_GpsTimeSec], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_GpsTimeSec =
  template this: untyped = result
  this = new(Gnss_GpsTimeSec)
  let root = if root == nil: cast[Gnss](this) else: cast[Gnss](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Seconds since start of GPS week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  GPS week number

  ]##
  let wnExpr = this.io.readU2le()
  this.wn = wnExpr

proc fromFile*(_: typedesc[Gnss_GpsTimeSec], filename: string): Gnss_GpsTimeSec =
  Gnss_GpsTimeSec.read(newKaitaiFileStream(filename), nil, nil)


##[
A (Constellation ID, satellite ID) tuple that uniquely identifies a
space vehicle.

]##
proc read*(_: typedesc[Gnss_SvId], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Gnss_SvId =
  template this: untyped = result
  this = new(Gnss_SvId)
  let root = if root == nil: cast[Gnss](this) else: cast[Gnss](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Constellation-specific satellite id. For GLO can either be (100+FCN)
where FCN is in [-7,+6] or the Slot ID in [1,28].

  ]##
  let satIdExpr = this.io.readU1()
  this.satId = satIdExpr

  ##[
  Constellation ID to which the SV belongs

  ]##
  let constellationExpr = this.io.readU1()
  this.constellation = constellationExpr

proc fromFile*(_: typedesc[Gnss_SvId], filename: string): Gnss_SvId =
  Gnss_SvId.read(newKaitaiFileStream(filename), nil, nil)

