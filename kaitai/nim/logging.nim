import kaitai_struct_nim_runtime
import options

type
  Logging* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Logging_MsgLog* = ref object of KaitaiStruct
    `level`*: uint8
    `text`*: string
    `parent`*: Sbp_Message
  Logging_MsgFwd* = ref object of KaitaiStruct
    `source`*: uint8
    `protocol`*: uint8
    `fwdPayload`*: seq[uint8]
    `parent`*: Sbp_Message
  Logging_MsgPrintDep* = ref object of KaitaiStruct
    `text`*: string
    `parent`*: Sbp_Message

proc read*(_: typedesc[Logging], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Logging
proc read*(_: typedesc[Logging_MsgLog], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Logging_MsgLog
proc read*(_: typedesc[Logging_MsgFwd], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Logging_MsgFwd
proc read*(_: typedesc[Logging_MsgPrintDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Logging_MsgPrintDep


proc read*(_: typedesc[Logging], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Logging =
  template this: untyped = result
  this = new(Logging)
  let root = if root == nil: cast[Logging](this) else: cast[Logging](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Logging], filename: string): Logging =
  Logging.read(newKaitaiFileStream(filename), nil, nil)


##[
This message contains a human-readable payload string from the device
containing errors, warnings and informational messages at ERROR,
WARNING, DEBUG, INFO logging levels.

]##
proc read*(_: typedesc[Logging_MsgLog], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Logging_MsgLog =
  template this: untyped = result
  this = new(Logging_MsgLog)
  let root = if root == nil: cast[Logging](this) else: cast[Logging](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Logging level

  ]##
  let levelExpr = this.io.readU1()
  this.level = levelExpr

  ##[
  Human-readable string

  ]##
  let textExpr = encode(this.io.readBytesFull(), "ascii")
  this.text = textExpr

proc fromFile*(_: typedesc[Logging_MsgLog], filename: string): Logging_MsgLog =
  Logging_MsgLog.read(newKaitaiFileStream(filename), nil, nil)


##[
This message provides the ability to forward messages over SBP.  This
may take the form of wrapping up SBP messages received by Piksi for
logging purposes or wrapping another protocol with SBP.

The source identifier indicates from what interface a forwarded stream
derived. The protocol identifier identifies what the expected protocol
the forwarded msg contains. Protocol 0 represents SBP and the remaining
values are implementation defined.

]##
proc read*(_: typedesc[Logging_MsgFwd], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Logging_MsgFwd =
  template this: untyped = result
  this = new(Logging_MsgFwd)
  let root = if root == nil: cast[Logging](this) else: cast[Logging](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  source identifier

  ]##
  let sourceExpr = this.io.readU1()
  this.source = sourceExpr

  ##[
  protocol identifier

  ]##
  let protocolExpr = this.io.readU1()
  this.protocol = protocolExpr

  ##[
  variable length wrapped binary message

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.fwdPayload.add(it)
      inc i

proc fromFile*(_: typedesc[Logging_MsgFwd], filename: string): Logging_MsgFwd =
  Logging_MsgFwd.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Logging_MsgPrintDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Logging_MsgPrintDep =
  template this: untyped = result
  this = new(Logging_MsgPrintDep)
  let root = if root == nil: cast[Logging](this) else: cast[Logging](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Human-readable string

  ]##
  let textExpr = encode(this.io.readBytesFull(), "ascii")
  this.text = textExpr

proc fromFile*(_: typedesc[Logging_MsgPrintDep], filename: string): Logging_MsgPrintDep =
  Logging_MsgPrintDep.read(newKaitaiFileStream(filename), nil, nil)

