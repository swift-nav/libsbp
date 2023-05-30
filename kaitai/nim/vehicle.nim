import kaitai_struct_nim_runtime
import options

type
  Vehicle* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Vehicle_MsgOdometry* = ref object of KaitaiStruct
    `tow`*: uint32
    `velocity`*: int32
    `flags`*: uint8
    `parent`*: Sbp_Message
  Vehicle_MsgWheeltick* = ref object of KaitaiStruct
    `time`*: uint64
    `flags`*: uint8
    `source`*: uint8
    `ticks`*: int32
    `parent`*: Sbp_Message

proc read*(_: typedesc[Vehicle], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Vehicle
proc read*(_: typedesc[Vehicle_MsgOdometry], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Vehicle_MsgOdometry
proc read*(_: typedesc[Vehicle_MsgWheeltick], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Vehicle_MsgWheeltick


proc read*(_: typedesc[Vehicle], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Vehicle =
  template this: untyped = result
  this = new(Vehicle)
  let root = if root == nil: cast[Vehicle](this) else: cast[Vehicle](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Vehicle], filename: string): Vehicle =
  Vehicle.read(newKaitaiFileStream(filename), nil, nil)


##[
Message representing the x component of vehicle velocity in the user
frame at the odometry reference point(s) specified by the user. The
offset for the odometry reference point and the definition and origin of
the user frame are defined through the device settings interface. There
are 4 possible user-defined sources of this message which are labeled
arbitrarily source 0 through 3. If using "processor time" time tags, the
receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
becomes available to synchronise odometry measurements with GNSS.
Processor time shall roll over to zero after one week.

]##
proc read*(_: typedesc[Vehicle_MsgOdometry], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Vehicle_MsgOdometry =
  template this: untyped = result
  this = new(Vehicle_MsgOdometry)
  let root = if root == nil: cast[Vehicle](this) else: cast[Vehicle](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Time field representing either milliseconds in the GPS Week or local
CPU time from the producing system in milliseconds.  See the
tow_source flag for the exact source of this timestamp.

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  The signed forward component of vehicle velocity.

  ]##
  let velocityExpr = this.io.readS4le()
  this.velocity = velocityExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Vehicle_MsgOdometry], filename: string): Vehicle_MsgOdometry =
  Vehicle_MsgOdometry.read(newKaitaiFileStream(filename), nil, nil)


##[
Message containing the accumulated distance travelled by a wheel located
at an odometry reference point defined by the user. The offset for the
odometry reference point and the definition and origin of the user frame
are defined through the device settings interface. The source of this
message is identified by the source field, which is an integer ranging
from 0 to 255. The timestamp associated with this message should
represent the time when the accumulated tick count reached the value
given by the contents of this message as accurately as possible. If
using "local CPU time" time tags, the receiving end will expect a
`MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise
wheeltick measurements with GNSS. Local CPU time shall roll over to zero
after one week.

]##
proc read*(_: typedesc[Vehicle_MsgWheeltick], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Vehicle_MsgWheeltick =
  template this: untyped = result
  this = new(Vehicle_MsgWheeltick)
  let root = if root == nil: cast[Vehicle](this) else: cast[Vehicle](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Time field representing either microseconds since the last PPS,
microseconds in the GPS Week or local CPU time from the producing
system in microseconds. See the synch_type field for the exact
meaning of this timestamp.

  ]##
  let timeExpr = this.io.readU8le()
  this.time = timeExpr

  ##[
  Field indicating the type of timestamp contained in the time field.

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  ID of the sensor producing this message

  ]##
  let sourceExpr = this.io.readU1()
  this.source = sourceExpr

  ##[
  Free-running counter of the accumulated distance for this sensor.
The counter should be incrementing if travelling into one direction
and decrementing when travelling in the opposite direction.

  ]##
  let ticksExpr = this.io.readS4le()
  this.ticks = ticksExpr

proc fromFile*(_: typedesc[Vehicle_MsgWheeltick], filename: string): Vehicle_MsgWheeltick =
  Vehicle_MsgWheeltick.read(newKaitaiFileStream(filename), nil, nil)

