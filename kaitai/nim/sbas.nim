import kaitai_struct_nim_runtime
import options
import gnss

type
  Sbas* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Sbas_MsgSbasRaw* = ref object of KaitaiStruct
    `sid`*: Gnss_GnssSignal
    `tow`*: uint32
    `messageType`*: uint8
    `data`*: seq[uint8]
    `parent`*: Sbp_Message

proc read*(_: typedesc[Sbas], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Sbas
proc read*(_: typedesc[Sbas_MsgSbasRaw], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Sbas_MsgSbasRaw


proc read*(_: typedesc[Sbas], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Sbas =
  template this: untyped = result
  this = new(Sbas)
  let root = if root == nil: cast[Sbas](this) else: cast[Sbas](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Sbas], filename: string): Sbas =
  Sbas.read(newKaitaiFileStream(filename), nil, nil)


##[
This message is sent once per second per SBAS satellite. ME checks the
parity of the data block and sends only blocks that pass the check.

]##
proc read*(_: typedesc[Sbas_MsgSbasRaw], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Sbas_MsgSbasRaw =
  template this: untyped = result
  this = new(Sbas_MsgSbasRaw)
  let root = if root == nil: cast[Sbas](this) else: cast[Sbas](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS signal identifier.

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  GPS time-of-week at the start of the data block.

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  SBAS message type (0-63)

  ]##
  let messageTypeExpr = this.io.readU1()
  this.messageType = messageTypeExpr

  ##[
  Raw SBAS data field of 212 bits (last byte padded with zeros).

  ]##
  for i in 0 ..< int(27):
    let it = this.io.readU1()
    this.data.add(it)

proc fromFile*(_: typedesc[Sbas_MsgSbasRaw], filename: string): Sbas_MsgSbasRaw =
  Sbas_MsgSbasRaw.read(newKaitaiFileStream(filename), nil, nil)

