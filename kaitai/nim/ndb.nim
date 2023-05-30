import kaitai_struct_nim_runtime
import options
import gnss

type
  Ndb* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Ndb_MsgNdbEvent* = ref object of KaitaiStruct
    `recvTime`*: uint64
    `event`*: uint8
    `objectType`*: uint8
    `result`*: uint8
    `dataSource`*: uint8
    `objectSid`*: Gnss_GnssSignal
    `srcSid`*: Gnss_GnssSignal
    `originalSender`*: uint16
    `parent`*: Sbp_Message

proc read*(_: typedesc[Ndb], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ndb
proc read*(_: typedesc[Ndb_MsgNdbEvent], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ndb_MsgNdbEvent


proc read*(_: typedesc[Ndb], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ndb =
  template this: untyped = result
  this = new(Ndb)
  let root = if root == nil: cast[Ndb](this) else: cast[Ndb](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Ndb], filename: string): Ndb =
  Ndb.read(newKaitaiFileStream(filename), nil, nil)


##[
This message is sent out when an object is stored into NDB. If needed
message could also be sent out when fetching an object from NDB.

]##
proc read*(_: typedesc[Ndb_MsgNdbEvent], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ndb_MsgNdbEvent =
  template this: untyped = result
  this = new(Ndb_MsgNdbEvent)
  let root = if root == nil: cast[Ndb](this) else: cast[Ndb](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  HW time in milliseconds.

  ]##
  let recvTimeExpr = this.io.readU8le()
  this.recvTime = recvTimeExpr

  ##[
  Event type.

  ]##
  let eventExpr = this.io.readU1()
  this.event = eventExpr

  ##[
  Event object type.

  ]##
  let objectTypeExpr = this.io.readU1()
  this.objectType = objectTypeExpr

  ##[
  Event result.

  ]##
  let resultExpr = this.io.readU1()
  this.result = resultExpr

  ##[
  Data source for STORE event, reserved for other events.

  ]##
  let dataSourceExpr = this.io.readU1()
  this.dataSource = dataSourceExpr

  ##[
  GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
indicates for which signal the object belongs to. Reserved in other
cases.

  ]##
  let objectSidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.objectSid = objectSidExpr

  ##[
  GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono
OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
from which SV data was decoded. Reserved in other cases.

  ]##
  let srcSidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.srcSid = srcSidExpr

  ##[
  A unique identifier of the sending hardware. For v1.0, set to the 2
least significant bytes of the device serial number, valid only if
data_source is NDB_DS_SBP. Reserved in case of other data_source.

  ]##
  let originalSenderExpr = this.io.readU2le()
  this.originalSender = originalSenderExpr

proc fromFile*(_: typedesc[Ndb_MsgNdbEvent], filename: string): Ndb_MsgNdbEvent =
  Ndb_MsgNdbEvent.read(newKaitaiFileStream(filename), nil, nil)

