import kaitai_struct_nim_runtime
import options

type
  Flash* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Flash_MsgFlashDone* = ref object of KaitaiStruct
    `response`*: uint8
    `parent`*: Sbp_Message
  Flash_MsgM25FlashWriteStatus* = ref object of KaitaiStruct
    `status`*: seq[uint8]
    `parent`*: Sbp_Message
  Flash_MsgFlashReadResp* = ref object of KaitaiStruct
    `target`*: uint8
    `addrStart`*: seq[uint8]
    `addrLen`*: uint8
    `parent`*: Sbp_Message
  Flash_MsgFlashErase* = ref object of KaitaiStruct
    `target`*: uint8
    `sectorNum`*: uint32
    `parent`*: Sbp_Message
  Flash_MsgStmUniqueIdResp* = ref object of KaitaiStruct
    `stmId`*: seq[uint8]
    `parent`*: Sbp_Message
  Flash_MsgStmUniqueIdReq* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Flash_MsgFlashProgram* = ref object of KaitaiStruct
    `target`*: uint8
    `addrStart`*: seq[uint8]
    `addrLen`*: uint8
    `data`*: seq[uint8]
    `parent`*: Sbp_Message
  Flash_MsgFlashReadReq* = ref object of KaitaiStruct
    `target`*: uint8
    `addrStart`*: seq[uint8]
    `addrLen`*: uint8
    `parent`*: Sbp_Message
  Flash_MsgStmFlashUnlockSector* = ref object of KaitaiStruct
    `sector`*: uint32
    `parent`*: Sbp_Message
  Flash_MsgStmFlashLockSector* = ref object of KaitaiStruct
    `sector`*: uint32
    `parent`*: Sbp_Message

proc read*(_: typedesc[Flash], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Flash
proc read*(_: typedesc[Flash_MsgFlashDone], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashDone
proc read*(_: typedesc[Flash_MsgM25FlashWriteStatus], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgM25FlashWriteStatus
proc read*(_: typedesc[Flash_MsgFlashReadResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashReadResp
proc read*(_: typedesc[Flash_MsgFlashErase], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashErase
proc read*(_: typedesc[Flash_MsgStmUniqueIdResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgStmUniqueIdResp
proc read*(_: typedesc[Flash_MsgStmUniqueIdReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgStmUniqueIdReq
proc read*(_: typedesc[Flash_MsgFlashProgram], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashProgram
proc read*(_: typedesc[Flash_MsgFlashReadReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashReadReq
proc read*(_: typedesc[Flash_MsgStmFlashUnlockSector], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgStmFlashUnlockSector
proc read*(_: typedesc[Flash_MsgStmFlashLockSector], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgStmFlashLockSector


proc read*(_: typedesc[Flash], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Flash =
  template this: untyped = result
  this = new(Flash)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Flash], filename: string): Flash =
  Flash.read(newKaitaiFileStream(filename), nil, nil)


##[
This message defines success or failure codes for a variety of flash
memory requests from the host to the device. Flash read and write
messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
this message on failure.

]##
proc read*(_: typedesc[Flash_MsgFlashDone], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashDone =
  template this: untyped = result
  this = new(Flash_MsgFlashDone)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Response flags

  ]##
  let responseExpr = this.io.readU1()
  this.response = responseExpr

proc fromFile*(_: typedesc[Flash_MsgFlashDone], filename: string): Flash_MsgFlashDone =
  Flash_MsgFlashDone.read(newKaitaiFileStream(filename), nil, nil)


##[
The flash status message writes to the 8-bit M25 flash status register.
The device replies with a MSG_FLASH_DONE message.

]##
proc read*(_: typedesc[Flash_MsgM25FlashWriteStatus], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgM25FlashWriteStatus =
  template this: untyped = result
  this = new(Flash_MsgM25FlashWriteStatus)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Byte to write to the M25 flash status register

  ]##
  for i in 0 ..< int(1):
    let it = this.io.readU1()
    this.status.add(it)

proc fromFile*(_: typedesc[Flash_MsgM25FlashWriteStatus], filename: string): Flash_MsgM25FlashWriteStatus =
  Flash_MsgM25FlashWriteStatus.read(newKaitaiFileStream(filename), nil, nil)


##[
The flash read message reads a set of addresses of either the STM or M25
onboard flash. The device replies with a MSG_FLASH_READ_RESP message
containing either the read data on success or a MSG_FLASH_DONE message
containing the return code FLASH_INVALID_LEN (2) if the maximum read
size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
the allowed range.

]##
proc read*(_: typedesc[Flash_MsgFlashReadResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashReadResp =
  template this: untyped = result
  this = new(Flash_MsgFlashReadResp)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Target flags

  ]##
  let targetExpr = this.io.readU1()
  this.target = targetExpr

  ##[
  Starting address offset to read from

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readU1()
    this.addrStart.add(it)

  ##[
  Length of set of addresses to read, counting up from starting
address

  ]##
  let addrLenExpr = this.io.readU1()
  this.addrLen = addrLenExpr

proc fromFile*(_: typedesc[Flash_MsgFlashReadResp], filename: string): Flash_MsgFlashReadResp =
  Flash_MsgFlashReadResp.read(newKaitaiFileStream(filename), nil, nil)


##[
The flash erase message from the host erases a sector of either the STM
or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
message containing the return code - FLASH_OK (0) on success or
FLASH_INVALID_FLASH (1) if the flash specified is invalid.

]##
proc read*(_: typedesc[Flash_MsgFlashErase], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashErase =
  template this: untyped = result
  this = new(Flash_MsgFlashErase)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Target flags

  ]##
  let targetExpr = this.io.readU1()
  this.target = targetExpr

  ##[
  Flash sector number to erase (0-11 for the STM, 0-15 for the M25)

  ]##
  let sectorNumExpr = this.io.readU4le()
  this.sectorNum = sectorNumExpr

proc fromFile*(_: typedesc[Flash_MsgFlashErase], filename: string): Flash_MsgFlashErase =
  Flash_MsgFlashErase.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reads the device's hard-coded unique ID. The host requests
the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.

]##
proc read*(_: typedesc[Flash_MsgStmUniqueIdResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgStmUniqueIdResp =
  template this: untyped = result
  this = new(Flash_MsgStmUniqueIdResp)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Device unique ID

  ]##
  for i in 0 ..< int(12):
    let it = this.io.readU1()
    this.stmId.add(it)

proc fromFile*(_: typedesc[Flash_MsgStmUniqueIdResp], filename: string): Flash_MsgStmUniqueIdResp =
  Flash_MsgStmUniqueIdResp.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reads the device's hard-coded unique ID. The host requests
the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.

]##
proc read*(_: typedesc[Flash_MsgStmUniqueIdReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgStmUniqueIdReq =
  template this: untyped = result
  this = new(Flash_MsgStmUniqueIdReq)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Flash_MsgStmUniqueIdReq], filename: string): Flash_MsgStmUniqueIdReq =
  Flash_MsgStmUniqueIdReq.read(newKaitaiFileStream(filename), nil, nil)


##[
The flash program message programs a set of addresses of either the STM
or M25 flash. The device replies with either a MSG_FLASH_DONE message
containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
(2) if the maximum write size is exceeded. Note that the sector-
containing addresses must be erased before addresses can be programmed.

]##
proc read*(_: typedesc[Flash_MsgFlashProgram], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashProgram =
  template this: untyped = result
  this = new(Flash_MsgFlashProgram)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Target flags

  ]##
  let targetExpr = this.io.readU1()
  this.target = targetExpr

  ##[
  Starting address offset to program

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readU1()
    this.addrStart.add(it)

  ##[
  Length of set of addresses to program, counting up from starting
address

  ]##
  let addrLenExpr = this.io.readU1()
  this.addrLen = addrLenExpr

  ##[
  Data to program addresses with, with length N=addr_len

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.data.add(it)
      inc i

proc fromFile*(_: typedesc[Flash_MsgFlashProgram], filename: string): Flash_MsgFlashProgram =
  Flash_MsgFlashProgram.read(newKaitaiFileStream(filename), nil, nil)


##[
The flash read message reads a set of addresses of either the STM or M25
onboard flash. The device replies with a MSG_FLASH_READ_RESP message
containing either the read data on success or a MSG_FLASH_DONE message
containing the return code FLASH_INVALID_LEN (2) if the maximum read
size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
the allowed range.

]##
proc read*(_: typedesc[Flash_MsgFlashReadReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgFlashReadReq =
  template this: untyped = result
  this = new(Flash_MsgFlashReadReq)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Target flags

  ]##
  let targetExpr = this.io.readU1()
  this.target = targetExpr

  ##[
  Starting address offset to read from

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readU1()
    this.addrStart.add(it)

  ##[
  Length of set of addresses to read, counting up from starting
address

  ]##
  let addrLenExpr = this.io.readU1()
  this.addrLen = addrLenExpr

proc fromFile*(_: typedesc[Flash_MsgFlashReadReq], filename: string): Flash_MsgFlashReadReq =
  Flash_MsgFlashReadReq.read(newKaitaiFileStream(filename), nil, nil)


##[
The flash unlock message unlocks a sector of the STM flash memory. The
device replies with a MSG_FLASH_DONE message.

]##
proc read*(_: typedesc[Flash_MsgStmFlashUnlockSector], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgStmFlashUnlockSector =
  template this: untyped = result
  this = new(Flash_MsgStmFlashUnlockSector)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Flash sector number to unlock

  ]##
  let sectorExpr = this.io.readU4le()
  this.sector = sectorExpr

proc fromFile*(_: typedesc[Flash_MsgStmFlashUnlockSector], filename: string): Flash_MsgStmFlashUnlockSector =
  Flash_MsgStmFlashUnlockSector.read(newKaitaiFileStream(filename), nil, nil)


##[
The flash lock message locks a sector of the STM flash memory. The
device replies with a MSG_FLASH_DONE message.

]##
proc read*(_: typedesc[Flash_MsgStmFlashLockSector], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Flash_MsgStmFlashLockSector =
  template this: untyped = result
  this = new(Flash_MsgStmFlashLockSector)
  let root = if root == nil: cast[Flash](this) else: cast[Flash](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Flash sector number to lock

  ]##
  let sectorExpr = this.io.readU4le()
  this.sector = sectorExpr

proc fromFile*(_: typedesc[Flash_MsgStmFlashLockSector], filename: string): Flash_MsgStmFlashLockSector =
  Flash_MsgStmFlashLockSector.read(newKaitaiFileStream(filename), nil, nil)

