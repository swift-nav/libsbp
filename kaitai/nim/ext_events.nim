import kaitai_struct_nim_runtime
import options

type
  ExtEvents* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  ExtEvents_MsgExtEvent* = ref object of KaitaiStruct
    `wn`*: uint16
    `tow`*: uint32
    `nsResidual`*: int32
    `flags`*: uint8
    `pin`*: uint8
    `parent`*: Sbp_Message

proc read*(_: typedesc[ExtEvents], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): ExtEvents
proc read*(_: typedesc[ExtEvents_MsgExtEvent], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): ExtEvents_MsgExtEvent


proc read*(_: typedesc[ExtEvents], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): ExtEvents =
  template this: untyped = result
  this = new(ExtEvents)
  let root = if root == nil: cast[ExtEvents](this) else: cast[ExtEvents](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[ExtEvents], filename: string): ExtEvents =
  ExtEvents.read(newKaitaiFileStream(filename), nil, nil)


##[
Reports detection of an external event, the GPS time it occurred, which
pin it was and whether it was rising or falling.

]##
proc read*(_: typedesc[ExtEvents_MsgExtEvent], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): ExtEvents_MsgExtEvent =
  template this: untyped = result
  this = new(ExtEvents_MsgExtEvent)
  let root = if root == nil: cast[ExtEvents](this) else: cast[ExtEvents](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS week number

  ]##
  let wnExpr = this.io.readU2le()
  this.wn = wnExpr

  ##[
  GPS time of week rounded to the nearest millisecond

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
  Flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  Pin number.  0..9 = DEBUG0..9.

  ]##
  let pinExpr = this.io.readU1()
  this.pin = pinExpr

proc fromFile*(_: typedesc[ExtEvents_MsgExtEvent], filename: string): ExtEvents_MsgExtEvent =
  ExtEvents_MsgExtEvent.read(newKaitaiFileStream(filename), nil, nil)

