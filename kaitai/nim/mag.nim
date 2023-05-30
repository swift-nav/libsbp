import kaitai_struct_nim_runtime
import options

type
  Mag* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Mag_MsgMagRaw* = ref object of KaitaiStruct
    `tow`*: uint32
    `towF`*: uint8
    `magX`*: int16
    `magY`*: int16
    `magZ`*: int16
    `parent`*: Sbp_Message

proc read*(_: typedesc[Mag], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Mag
proc read*(_: typedesc[Mag_MsgMagRaw], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Mag_MsgMagRaw


proc read*(_: typedesc[Mag], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Mag =
  template this: untyped = result
  this = new(Mag)
  let root = if root == nil: cast[Mag](this) else: cast[Mag](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Mag], filename: string): Mag =
  Mag.read(newKaitaiFileStream(filename), nil, nil)


##[
Raw data from the magnetometer.

]##
proc read*(_: typedesc[Mag_MsgMagRaw], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Mag_MsgMagRaw =
  template this: untyped = result
  this = new(Mag_MsgMagRaw)
  let root = if root == nil: cast[Mag](this) else: cast[Mag](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Milliseconds since start of GPS week. If the high bit is set, the
time is unknown or invalid.

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Milliseconds since start of GPS week, fractional part

  ]##
  let towFExpr = this.io.readU1()
  this.towF = towFExpr

  ##[
  Magnetic field in the body frame X axis

  ]##
  let magXExpr = this.io.readS2le()
  this.magX = magXExpr

  ##[
  Magnetic field in the body frame Y axis

  ]##
  let magYExpr = this.io.readS2le()
  this.magY = magYExpr

  ##[
  Magnetic field in the body frame Z axis

  ]##
  let magZExpr = this.io.readS2le()
  this.magZ = magZExpr

proc fromFile*(_: typedesc[Mag_MsgMagRaw], filename: string): Mag_MsgMagRaw =
  Mag_MsgMagRaw.read(newKaitaiFileStream(filename), nil, nil)

