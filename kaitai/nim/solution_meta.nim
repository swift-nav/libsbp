import kaitai_struct_nim_runtime
import options

type
  SolutionMeta* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  SolutionMeta_GnssInputType* = ref object of KaitaiStruct
    `flags`*: uint8
    `parent`*: KaitaiStruct
  SolutionMeta_MsgSolnMeta* = ref object of KaitaiStruct
    `tow`*: uint32
    `pdop`*: uint16
    `hdop`*: uint16
    `vdop`*: uint16
    `ageCorrections`*: uint16
    `ageGnss`*: uint32
    `solIn`*: seq[SolutionMeta_SolutionInputType]
    `parent`*: Sbp_Message
  SolutionMeta_MsgSolnMetaDepA* = ref object of KaitaiStruct
    `pdop`*: uint16
    `hdop`*: uint16
    `vdop`*: uint16
    `nSats`*: uint8
    `ageCorrections`*: uint16
    `alignmentStatus`*: uint8
    `lastUsedGnssPosTow`*: uint32
    `lastUsedGnssVelTow`*: uint32
    `solIn`*: seq[SolutionMeta_SolutionInputType]
    `parent`*: Sbp_Message
  SolutionMeta_ImuInputType* = ref object of KaitaiStruct
    `flags`*: uint8
    `parent`*: KaitaiStruct
  SolutionMeta_OdoInputType* = ref object of KaitaiStruct
    `flags`*: uint8
    `parent`*: KaitaiStruct
  SolutionMeta_SolutionInputType* = ref object of KaitaiStruct
    `sensorType`*: uint8
    `flags`*: uint8
    `parent`*: KaitaiStruct

proc read*(_: typedesc[SolutionMeta], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta
proc read*(_: typedesc[SolutionMeta_GnssInputType], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta_GnssInputType
proc read*(_: typedesc[SolutionMeta_MsgSolnMeta], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): SolutionMeta_MsgSolnMeta
proc read*(_: typedesc[SolutionMeta_MsgSolnMetaDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): SolutionMeta_MsgSolnMetaDepA
proc read*(_: typedesc[SolutionMeta_ImuInputType], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta_ImuInputType
proc read*(_: typedesc[SolutionMeta_OdoInputType], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta_OdoInputType
proc read*(_: typedesc[SolutionMeta_SolutionInputType], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta_SolutionInputType


proc read*(_: typedesc[SolutionMeta], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta =
  template this: untyped = result
  this = new(SolutionMeta)
  let root = if root == nil: cast[SolutionMeta](this) else: cast[SolutionMeta](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[SolutionMeta], filename: string): SolutionMeta =
  SolutionMeta.read(newKaitaiFileStream(filename), nil, nil)


##[
Metadata around the GNSS sensors involved in the fuzed solution.
Accessible through sol_in[N].flags in a MSG_SOLN_META.

]##
proc read*(_: typedesc[SolutionMeta_GnssInputType], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta_GnssInputType =
  template this: untyped = result
  this = new(SolutionMeta_GnssInputType)
  let root = if root == nil: cast[SolutionMeta](this) else: cast[SolutionMeta](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  flags that store all relevant info specific to this sensor type.

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[SolutionMeta_GnssInputType], filename: string): SolutionMeta_GnssInputType =
  SolutionMeta_GnssInputType.read(newKaitaiFileStream(filename), nil, nil)


##[
This message contains all metadata about the sensors received and/or
used in computing the sensorfusion solution. It focuses primarily, but
not only, on GNSS metadata. Regarding the age of the last received valid
GNSS solution, the highest two bits are time status, indicating whether
age gnss can or can not be used to retrieve time of measurement (noted
TOM, also known as time of validity) If it can, subtract 'age gnss' from
'tow' in navigation messages to get TOM. Can be used before alignment is
complete in the Fusion Engine, when output solution is the last received
valid GNSS solution and its tow is not a TOM.

]##
proc read*(_: typedesc[SolutionMeta_MsgSolnMeta], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): SolutionMeta_MsgSolnMeta =
  template this: untyped = result
  this = new(SolutionMeta_MsgSolnMeta)
  let root = if root == nil: cast[SolutionMeta](this) else: cast[SolutionMeta](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS time of week rounded to the nearest millisecond

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Position Dilution of Precision as per last available DOPS from PVT
engine (0xFFFF indicates invalid)

  ]##
  let pdopExpr = this.io.readU2le()
  this.pdop = pdopExpr

  ##[
  Horizontal Dilution of Precision as per last available DOPS from PVT
engine (0xFFFF indicates invalid)

  ]##
  let hdopExpr = this.io.readU2le()
  this.hdop = hdopExpr

  ##[
  Vertical Dilution of Precision as per last available DOPS from PVT
engine (0xFFFF indicates invalid)

  ]##
  let vdopExpr = this.io.readU2le()
  this.vdop = vdopExpr

  ##[
  Age of corrections as per last available AGE_CORRECTIONS from PVT
engine (0xFFFF indicates invalid)

  ]##
  let ageCorrectionsExpr = this.io.readU2le()
  this.ageCorrections = ageCorrectionsExpr

  ##[
  Age and Time Status of the last received valid GNSS solution.

  ]##
  let ageGnssExpr = this.io.readU4le()
  this.ageGnss = ageGnssExpr

  ##[
  Array of Metadata describing the sensors potentially involved in the
solution. Each element in the array represents a single sensor type
and consists of flags containing (meta)data pertaining to that
specific single sensor. Refer to each (XX)InputType descriptor in
the present doc.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = SolutionMeta_SolutionInputType.read(this.io, this.root, this)
      this.solIn.add(it)
      inc i

proc fromFile*(_: typedesc[SolutionMeta_MsgSolnMeta], filename: string): SolutionMeta_MsgSolnMeta =
  SolutionMeta_MsgSolnMeta.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

This message contains all metadata about the sensors received and/or
used in computing the Fuzed Solution. It focuses primarily, but not
only, on GNSS metadata.

]##
proc read*(_: typedesc[SolutionMeta_MsgSolnMetaDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): SolutionMeta_MsgSolnMetaDepA =
  template this: untyped = result
  this = new(SolutionMeta_MsgSolnMetaDepA)
  let root = if root == nil: cast[SolutionMeta](this) else: cast[SolutionMeta](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Position Dilution of Precision as per last available DOPS from PVT
engine (0xFFFF indicates invalid)

  ]##
  let pdopExpr = this.io.readU2le()
  this.pdop = pdopExpr

  ##[
  Horizontal Dilution of Precision as per last available DOPS from PVT
engine (0xFFFF indicates invalid)

  ]##
  let hdopExpr = this.io.readU2le()
  this.hdop = hdopExpr

  ##[
  Vertical Dilution of Precision as per last available DOPS from PVT
engine (0xFFFF indicates invalid)

  ]##
  let vdopExpr = this.io.readU2le()
  this.vdop = vdopExpr

  ##[
  Number of satellites as per last available solution from PVT engine

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Age of corrections as per last available AGE_CORRECTIONS from PVT
engine (0xFFFF indicates invalid)

  ]##
  let ageCorrectionsExpr = this.io.readU2le()
  this.ageCorrections = ageCorrectionsExpr

  ##[
  State of alignment and the status and receipt of the alignment
inputs

  ]##
  let alignmentStatusExpr = this.io.readU1()
  this.alignmentStatus = alignmentStatusExpr

  ##[
  Tow of last-used GNSS position measurement

  ]##
  let lastUsedGnssPosTowExpr = this.io.readU4le()
  this.lastUsedGnssPosTow = lastUsedGnssPosTowExpr

  ##[
  Tow of last-used GNSS velocity measurement

  ]##
  let lastUsedGnssVelTowExpr = this.io.readU4le()
  this.lastUsedGnssVelTow = lastUsedGnssVelTowExpr

  ##[
  Array of Metadata describing the sensors potentially involved in the
solution. Each element in the array represents a single sensor type
and consists of flags containing (meta)data pertaining to that
specific single sensor. Refer to each (XX)InputType descriptor in
the present doc.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = SolutionMeta_SolutionInputType.read(this.io, this.root, this)
      this.solIn.add(it)
      inc i

proc fromFile*(_: typedesc[SolutionMeta_MsgSolnMetaDepA], filename: string): SolutionMeta_MsgSolnMetaDepA =
  SolutionMeta_MsgSolnMetaDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Metadata around the IMU sensors involved in the fuzed solution.
Accessible through sol_in[N].flags in a MSG_SOLN_META.

]##
proc read*(_: typedesc[SolutionMeta_ImuInputType], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta_ImuInputType =
  template this: untyped = result
  this = new(SolutionMeta_ImuInputType)
  let root = if root == nil: cast[SolutionMeta](this) else: cast[SolutionMeta](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Instrument time, grade, and architecture for a sensor.

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[SolutionMeta_ImuInputType], filename: string): SolutionMeta_ImuInputType =
  SolutionMeta_ImuInputType.read(newKaitaiFileStream(filename), nil, nil)


##[
Metadata around the Odometry sensors involved in the fuzed solution.
Accessible through sol_in[N].flags in a MSG_SOLN_META.

]##
proc read*(_: typedesc[SolutionMeta_OdoInputType], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta_OdoInputType =
  template this: untyped = result
  this = new(SolutionMeta_OdoInputType)
  let root = if root == nil: cast[SolutionMeta](this) else: cast[SolutionMeta](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Instrument ODO rate, grade, and quality.

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[SolutionMeta_OdoInputType], filename: string): SolutionMeta_OdoInputType =
  SolutionMeta_OdoInputType.read(newKaitaiFileStream(filename), nil, nil)


##[
Metadata describing which sensors were involved in the solution. The
structure is fixed no matter what the actual sensor type is. The
sensor_type field tells you which sensor we are talking about. It also
tells you whether the sensor data was actually used or not. The flags
field, always a u8, contains the sensor-specific data. The content of
flags, for each sensor type, is described in the relevant structures in
this section.

]##
proc read*(_: typedesc[SolutionMeta_SolutionInputType], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): SolutionMeta_SolutionInputType =
  template this: untyped = result
  this = new(SolutionMeta_SolutionInputType)
  let root = if root == nil: cast[SolutionMeta](this) else: cast[SolutionMeta](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  The type of sensor

  ]##
  let sensorTypeExpr = this.io.readU1()
  this.sensorType = sensorTypeExpr

  ##[
  Refer to each InputType description

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[SolutionMeta_SolutionInputType], filename: string): SolutionMeta_SolutionInputType =
  SolutionMeta_SolutionInputType.read(newKaitaiFileStream(filename), nil, nil)

