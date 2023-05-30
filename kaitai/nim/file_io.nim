import kaitai_struct_nim_runtime
import options

type
  FileIo* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  FileIo_MsgFileioWriteReq* = ref object of KaitaiStruct
    `sequence`*: uint32
    `offset`*: uint32
    `filename`*: string
    `data`*: seq[uint8]
    `parent`*: Sbp_Message
  FileIo_MsgFileioConfigResp* = ref object of KaitaiStruct
    `sequence`*: uint32
    `windowSize`*: uint32
    `batchSize`*: uint32
    `fileioVersion`*: uint32
    `parent`*: Sbp_Message
  FileIo_MsgFileioRemove* = ref object of KaitaiStruct
    `filename`*: string
    `parent`*: Sbp_Message
  FileIo_MsgFileioConfigReq* = ref object of KaitaiStruct
    `sequence`*: uint32
    `parent`*: Sbp_Message
  FileIo_MsgFileioReadDirReq* = ref object of KaitaiStruct
    `sequence`*: uint32
    `offset`*: uint32
    `dirname`*: string
    `parent`*: Sbp_Message
  FileIo_MsgFileioWriteResp* = ref object of KaitaiStruct
    `sequence`*: uint32
    `parent`*: Sbp_Message
  FileIo_MsgFileioReadDirResp* = ref object of KaitaiStruct
    `sequence`*: uint32
    `contents`*: seq[uint8]
    `parent`*: Sbp_Message
  FileIo_MsgFileioReadReq* = ref object of KaitaiStruct
    `sequence`*: uint32
    `offset`*: uint32
    `chunkSize`*: uint8
    `filename`*: string
    `parent`*: Sbp_Message
  FileIo_MsgFileioReadResp* = ref object of KaitaiStruct
    `sequence`*: uint32
    `contents`*: seq[uint8]
    `parent`*: Sbp_Message

proc read*(_: typedesc[FileIo], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): FileIo
proc read*(_: typedesc[FileIo_MsgFileioWriteReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioWriteReq
proc read*(_: typedesc[FileIo_MsgFileioConfigResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioConfigResp
proc read*(_: typedesc[FileIo_MsgFileioRemove], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioRemove
proc read*(_: typedesc[FileIo_MsgFileioConfigReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioConfigReq
proc read*(_: typedesc[FileIo_MsgFileioReadDirReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioReadDirReq
proc read*(_: typedesc[FileIo_MsgFileioWriteResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioWriteResp
proc read*(_: typedesc[FileIo_MsgFileioReadDirResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioReadDirResp
proc read*(_: typedesc[FileIo_MsgFileioReadReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioReadReq
proc read*(_: typedesc[FileIo_MsgFileioReadResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioReadResp


proc read*(_: typedesc[FileIo], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): FileIo =
  template this: untyped = result
  this = new(FileIo)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[FileIo], filename: string): FileIo =
  FileIo.read(newKaitaiFileStream(filename), nil, nil)


##[
The file write message writes a certain length (up to 255 bytes) of data
to a file at a given offset. Returns a copy of the original
MSG_FILEIO_WRITE_RESP message to check integrity of the write. The
sequence number in the request will be returned in the response. If
message is invalid, a followup MSG_PRINT message will print "Invalid
fileio write message". A device will only process this message when it
is received from sender ID 0x42.

]##
proc read*(_: typedesc[FileIo_MsgFileioWriteReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioWriteReq =
  template this: untyped = result
  this = new(FileIo_MsgFileioWriteReq)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Write sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  Offset into the file at which to start writing in bytes

  ]##
  let offsetExpr = this.io.readU4le()
  this.offset = offsetExpr

  ##[
  Name of the file to write to

  ]##
  let filenameExpr = encode(this.io.readBytesFull(), "ascii")
  this.filename = filenameExpr

  ##[
  Variable-length array of data to write

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.data.add(it)
      inc i

proc fromFile*(_: typedesc[FileIo_MsgFileioWriteReq], filename: string): FileIo_MsgFileioWriteReq =
  FileIo_MsgFileioWriteReq.read(newKaitaiFileStream(filename), nil, nil)


##[
The advice on the optimal configuration for a FileIO transfer.  Newer
version of FileIO can support greater throughput by supporting a large
window of FileIO data that can be in-flight during read or write
operations.

]##
proc read*(_: typedesc[FileIo_MsgFileioConfigResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioConfigResp =
  template this: untyped = result
  this = new(FileIo_MsgFileioConfigResp)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Advice sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  The number of SBP packets in the data in-flight window

  ]##
  let windowSizeExpr = this.io.readU4le()
  this.windowSize = windowSizeExpr

  ##[
  The number of SBP packets sent in one PDU

  ]##
  let batchSizeExpr = this.io.readU4le()
  this.batchSize = batchSizeExpr

  ##[
  The version of FileIO that is supported

  ]##
  let fileioVersionExpr = this.io.readU4le()
  this.fileioVersion = fileioVersionExpr

proc fromFile*(_: typedesc[FileIo_MsgFileioConfigResp], filename: string): FileIo_MsgFileioConfigResp =
  FileIo_MsgFileioConfigResp.read(newKaitaiFileStream(filename), nil, nil)


##[
The file remove message deletes a file from the file system. If the
message is invalid, a followup MSG_PRINT message will print "Invalid
fileio remove message". A device will only process this message when it
is received from sender ID 0x42.

]##
proc read*(_: typedesc[FileIo_MsgFileioRemove], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioRemove =
  template this: untyped = result
  this = new(FileIo_MsgFileioRemove)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Name of the file to delete

  ]##
  let filenameExpr = encode(this.io.readBytesFull(), "ascii")
  this.filename = filenameExpr

proc fromFile*(_: typedesc[FileIo_MsgFileioRemove], filename: string): FileIo_MsgFileioRemove =
  FileIo_MsgFileioRemove.read(newKaitaiFileStream(filename), nil, nil)


##[
Requests advice on the optimal configuration for a FileIO transfer.
Newer version of FileIO can support greater throughput by supporting a
large window of FileIO data that can be in-flight during read or write
operations.

]##
proc read*(_: typedesc[FileIo_MsgFileioConfigReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioConfigReq =
  template this: untyped = result
  this = new(FileIo_MsgFileioConfigReq)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Advice sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

proc fromFile*(_: typedesc[FileIo_MsgFileioConfigReq], filename: string): FileIo_MsgFileioConfigReq =
  FileIo_MsgFileioConfigReq.read(newKaitaiFileStream(filename), nil, nil)


##[
The read directory message lists the files in a directory on the
device's onboard flash file system.  The offset parameter can be used to
skip the first n elements of the file list. Returns a
MSG_FILEIO_READ_DIR_RESP message containing the directory listings as a
NULL delimited list. The listing is chunked over multiple SBP packets.
The sequence number in the request will be returned in the response.  If
message is invalid, a followup MSG_PRINT message will print "Invalid
fileio read message". A device will only respond to this message when it
is received from sender ID 0x42.

]##
proc read*(_: typedesc[FileIo_MsgFileioReadDirReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioReadDirReq =
  template this: untyped = result
  this = new(FileIo_MsgFileioReadDirReq)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Read sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  The offset to skip the first n elements of the file list

  ]##
  let offsetExpr = this.io.readU4le()
  this.offset = offsetExpr

  ##[
  Name of the directory to list

  ]##
  let dirnameExpr = encode(this.io.readBytesFull(), "ascii")
  this.dirname = dirnameExpr

proc fromFile*(_: typedesc[FileIo_MsgFileioReadDirReq], filename: string): FileIo_MsgFileioReadDirReq =
  FileIo_MsgFileioReadDirReq.read(newKaitaiFileStream(filename), nil, nil)


##[
The file write message writes a certain length (up to 255 bytes) of data
to a file at a given offset. The message is a copy of the original
MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
sequence number in the response is preserved from the request.

]##
proc read*(_: typedesc[FileIo_MsgFileioWriteResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioWriteResp =
  template this: untyped = result
  this = new(FileIo_MsgFileioWriteResp)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Write sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

proc fromFile*(_: typedesc[FileIo_MsgFileioWriteResp], filename: string): FileIo_MsgFileioWriteResp =
  FileIo_MsgFileioWriteResp.read(newKaitaiFileStream(filename), nil, nil)


##[
The read directory message lists the files in a directory on the
device's onboard flash file system. Message contains the directory
listings as a NULL delimited list. The listing is chunked over multiple
SBP packets and the end of the list is identified by an packet with no
entries. The sequence number in the response is preserved from the
request.

]##
proc read*(_: typedesc[FileIo_MsgFileioReadDirResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioReadDirResp =
  template this: untyped = result
  this = new(FileIo_MsgFileioReadDirResp)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Read sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  Contents of read directory

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.contents.add(it)
      inc i

proc fromFile*(_: typedesc[FileIo_MsgFileioReadDirResp], filename: string): FileIo_MsgFileioReadDirResp =
  FileIo_MsgFileioReadDirResp.read(newKaitaiFileStream(filename), nil, nil)


##[
The file read message reads a certain length (up to 255 bytes) from a
given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
message where the message length field indicates how many bytes were
successfully read. The sequence number in the request will be returned
in the response. If the message is invalid, a followup MSG_PRINT message
will print "Invalid fileio read message". A device will only respond to
this message when it is received from sender ID 0x42.

]##
proc read*(_: typedesc[FileIo_MsgFileioReadReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioReadReq =
  template this: untyped = result
  this = new(FileIo_MsgFileioReadReq)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Read sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  File offset

  ]##
  let offsetExpr = this.io.readU4le()
  this.offset = offsetExpr

  ##[
  Chunk size to read

  ]##
  let chunkSizeExpr = this.io.readU1()
  this.chunkSize = chunkSizeExpr

  ##[
  Name of the file to read from

  ]##
  let filenameExpr = encode(this.io.readBytesFull(), "ascii")
  this.filename = filenameExpr

proc fromFile*(_: typedesc[FileIo_MsgFileioReadReq], filename: string): FileIo_MsgFileioReadReq =
  FileIo_MsgFileioReadReq.read(newKaitaiFileStream(filename), nil, nil)


##[
The file read message reads a certain length (up to 255 bytes) from a
given offset into a file, and returns the data in a message where the
message length field indicates how many bytes were successfully read.
The sequence number in the response is preserved from the request.

]##
proc read*(_: typedesc[FileIo_MsgFileioReadResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): FileIo_MsgFileioReadResp =
  template this: untyped = result
  this = new(FileIo_MsgFileioReadResp)
  let root = if root == nil: cast[FileIo](this) else: cast[FileIo](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Read sequence number

  ]##
  let sequenceExpr = this.io.readU4le()
  this.sequence = sequenceExpr

  ##[
  Contents of read file

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.contents.add(it)
      inc i

proc fromFile*(_: typedesc[FileIo_MsgFileioReadResp], filename: string): FileIo_MsgFileioReadResp =
  FileIo_MsgFileioReadResp.read(newKaitaiFileStream(filename), nil, nil)

