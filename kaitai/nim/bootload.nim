import kaitai_struct_nim_runtime
import options

type
  Bootload* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Bootload_MsgNapDeviceDnaReq* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Bootload_MsgBootloaderJumpToApp* = ref object of KaitaiStruct
    `jump`*: uint8
    `parent`*: Sbp_Message
  Bootload_MsgBootloaderHandshakeResp* = ref object of KaitaiStruct
    `flags`*: uint32
    `version`*: string
    `parent`*: Sbp_Message
  Bootload_MsgNapDeviceDnaResp* = ref object of KaitaiStruct
    `dna`*: seq[uint8]
    `parent`*: Sbp_Message
  Bootload_MsgBootloaderHandshakeReq* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Bootload_MsgBootloaderHandshakeDepA* = ref object of KaitaiStruct
    `handshake`*: seq[uint8]
    `parent`*: Sbp_Message

proc read*(_: typedesc[Bootload], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Bootload
proc read*(_: typedesc[Bootload_MsgNapDeviceDnaReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgNapDeviceDnaReq
proc read*(_: typedesc[Bootload_MsgBootloaderJumpToApp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgBootloaderJumpToApp
proc read*(_: typedesc[Bootload_MsgBootloaderHandshakeResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgBootloaderHandshakeResp
proc read*(_: typedesc[Bootload_MsgNapDeviceDnaResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgNapDeviceDnaResp
proc read*(_: typedesc[Bootload_MsgBootloaderHandshakeReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgBootloaderHandshakeReq
proc read*(_: typedesc[Bootload_MsgBootloaderHandshakeDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgBootloaderHandshakeDepA


proc read*(_: typedesc[Bootload], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Bootload =
  template this: untyped = result
  this = new(Bootload)
  let root = if root == nil: cast[Bootload](this) else: cast[Bootload](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Bootload], filename: string): Bootload =
  Bootload.read(newKaitaiFileStream(filename), nil, nil)


##[
The device message from the host reads a unique device identifier from
the SwiftNAP, an FPGA. The host requests the ID by sending a
MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
that this ID is tied to the FPGA, and not related to the Piksi's serial
number.

]##
proc read*(_: typedesc[Bootload_MsgNapDeviceDnaReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgNapDeviceDnaReq =
  template this: untyped = result
  this = new(Bootload_MsgNapDeviceDnaReq)
  let root = if root == nil: cast[Bootload](this) else: cast[Bootload](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Bootload_MsgNapDeviceDnaReq], filename: string): Bootload_MsgNapDeviceDnaReq =
  Bootload_MsgNapDeviceDnaReq.read(newKaitaiFileStream(filename), nil, nil)


##[
The host initiates the bootloader to jump to the application.

]##
proc read*(_: typedesc[Bootload_MsgBootloaderJumpToApp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgBootloaderJumpToApp =
  template this: untyped = result
  this = new(Bootload_MsgBootloaderJumpToApp)
  let root = if root == nil: cast[Bootload](this) else: cast[Bootload](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Ignored by the device

  ]##
  let jumpExpr = this.io.readU1()
  this.jump = jumpExpr

proc fromFile*(_: typedesc[Bootload_MsgBootloaderJumpToApp], filename: string): Bootload_MsgBootloaderJumpToApp =
  Bootload_MsgBootloaderJumpToApp.read(newKaitaiFileStream(filename), nil, nil)


##[
The handshake message response from the device establishes a handshake
between the device bootloader and the host. The request from the host is
MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
version number and the SBP protocol version number.

]##
proc read*(_: typedesc[Bootload_MsgBootloaderHandshakeResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgBootloaderHandshakeResp =
  template this: untyped = result
  this = new(Bootload_MsgBootloaderHandshakeResp)
  let root = if root == nil: cast[Bootload](this) else: cast[Bootload](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Bootloader flags

  ]##
  let flagsExpr = this.io.readU4le()
  this.flags = flagsExpr

  ##[
  Bootloader version number

  ]##
  let versionExpr = encode(this.io.readBytesFull(), "ascii")
  this.version = versionExpr

proc fromFile*(_: typedesc[Bootload_MsgBootloaderHandshakeResp], filename: string): Bootload_MsgBootloaderHandshakeResp =
  Bootload_MsgBootloaderHandshakeResp.read(newKaitaiFileStream(filename), nil, nil)


##[
The device message from the host reads a unique device identifier from
the SwiftNAP, an FPGA. The host requests the ID by sending a
MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
that this ID is tied to the FPGA, and not related to the Piksi's serial
number.

]##
proc read*(_: typedesc[Bootload_MsgNapDeviceDnaResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgNapDeviceDnaResp =
  template this: untyped = result
  this = new(Bootload_MsgNapDeviceDnaResp)
  let root = if root == nil: cast[Bootload](this) else: cast[Bootload](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the
right.

  ]##
  for i in 0 ..< int(8):
    let it = this.io.readU1()
    this.dna.add(it)

proc fromFile*(_: typedesc[Bootload_MsgNapDeviceDnaResp], filename: string): Bootload_MsgNapDeviceDnaResp =
  Bootload_MsgNapDeviceDnaResp.read(newKaitaiFileStream(filename), nil, nil)


##[
The handshake message request from the host establishes a handshake
between the device bootloader and the host. The response from the device
is MSG_BOOTLOADER_HANDSHAKE_RESP.

]##
proc read*(_: typedesc[Bootload_MsgBootloaderHandshakeReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgBootloaderHandshakeReq =
  template this: untyped = result
  this = new(Bootload_MsgBootloaderHandshakeReq)
  let root = if root == nil: cast[Bootload](this) else: cast[Bootload](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Bootload_MsgBootloaderHandshakeReq], filename: string): Bootload_MsgBootloaderHandshakeReq =
  Bootload_MsgBootloaderHandshakeReq.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Bootload_MsgBootloaderHandshakeDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Bootload_MsgBootloaderHandshakeDepA =
  template this: untyped = result
  this = new(Bootload_MsgBootloaderHandshakeDepA)
  let root = if root == nil: cast[Bootload](this) else: cast[Bootload](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Version number string (not NULL terminated)

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.handshake.add(it)
      inc i

proc fromFile*(_: typedesc[Bootload_MsgBootloaderHandshakeDepA], filename: string): Bootload_MsgBootloaderHandshakeDepA =
  Bootload_MsgBootloaderHandshakeDepA.read(newKaitaiFileStream(filename), nil, nil)

