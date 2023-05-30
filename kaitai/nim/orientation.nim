import kaitai_struct_nim_runtime
import options

type
  Orientation* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Orientation_MsgBaselineHeading* = ref object of KaitaiStruct
    `tow`*: uint32
    `heading`*: uint32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Orientation_MsgOrientQuat* = ref object of KaitaiStruct
    `tow`*: uint32
    `w`*: int32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `wAccuracy`*: float32
    `xAccuracy`*: float32
    `yAccuracy`*: float32
    `zAccuracy`*: float32
    `flags`*: uint8
    `parent`*: Sbp_Message
  Orientation_MsgOrientEuler* = ref object of KaitaiStruct
    `tow`*: uint32
    `roll`*: int32
    `pitch`*: int32
    `yaw`*: int32
    `rollAccuracy`*: float32
    `pitchAccuracy`*: float32
    `yawAccuracy`*: float32
    `flags`*: uint8
    `parent`*: Sbp_Message
  Orientation_MsgAngularRate* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `flags`*: uint8
    `parent`*: Sbp_Message

proc read*(_: typedesc[Orientation], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Orientation
proc read*(_: typedesc[Orientation_MsgBaselineHeading], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Orientation_MsgBaselineHeading
proc read*(_: typedesc[Orientation_MsgOrientQuat], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Orientation_MsgOrientQuat
proc read*(_: typedesc[Orientation_MsgOrientEuler], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Orientation_MsgOrientEuler
proc read*(_: typedesc[Orientation_MsgAngularRate], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Orientation_MsgAngularRate


proc read*(_: typedesc[Orientation], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Orientation =
  template this: untyped = result
  this = new(Orientation)
  let root = if root == nil: cast[Orientation](this) else: cast[Orientation](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Orientation], filename: string): Orientation =
  Orientation.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the baseline heading pointing from the base station
to the rover relative to True North. The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
intended that time-matched RTK mode is used when the base station is
moving.

]##
proc read*(_: typedesc[Orientation_MsgBaselineHeading], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Orientation_MsgBaselineHeading =
  template this: untyped = result
  this = new(Orientation_MsgBaselineHeading)
  let root = if root == nil: cast[Orientation](this) else: cast[Orientation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Heading

  ]##
  let headingExpr = this.io.readU4le()
  this.heading = headingExpr

  ##[
  Number of satellites used in solution

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Orientation_MsgBaselineHeading], filename: string): Orientation_MsgBaselineHeading =
  Orientation_MsgBaselineHeading.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the quaternion vector describing the vehicle body
frame's orientation with respect to a local-level NED frame. The
components of the vector should sum to a unit vector assuming that the
LSB of each component as a value of 2^-31. This message will only be
available in future INS versions of Swift Products and is not produced
by Piksi Multi or Duro.

]##
proc read*(_: typedesc[Orientation_MsgOrientQuat], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Orientation_MsgOrientQuat =
  template this: untyped = result
  this = new(Orientation_MsgOrientQuat)
  let root = if root == nil: cast[Orientation](this) else: cast[Orientation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Real component

  ]##
  let wExpr = this.io.readS4le()
  this.w = wExpr

  ##[
  1st imaginary component

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  2nd imaginary component

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  3rd imaginary component

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Estimated standard deviation of w

  ]##
  let wAccuracyExpr = this.io.readF4le()
  this.wAccuracy = wAccuracyExpr

  ##[
  Estimated standard deviation of x

  ]##
  let xAccuracyExpr = this.io.readF4le()
  this.xAccuracy = xAccuracyExpr

  ##[
  Estimated standard deviation of y

  ]##
  let yAccuracyExpr = this.io.readF4le()
  this.yAccuracy = yAccuracyExpr

  ##[
  Estimated standard deviation of z

  ]##
  let zAccuracyExpr = this.io.readF4le()
  this.zAccuracy = zAccuracyExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Orientation_MsgOrientQuat], filename: string): Orientation_MsgOrientQuat =
  Orientation_MsgOrientQuat.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the yaw, pitch, and roll angles of the vehicle body
frame. The rotations should applied intrinsically in the order yaw,
pitch, and roll in order to rotate the from a frame aligned with the
local-level NED frame to the vehicle body frame.  This message will only
be available in future INS versions of Swift Products and is not
produced by Piksi Multi or Duro.

]##
proc read*(_: typedesc[Orientation_MsgOrientEuler], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Orientation_MsgOrientEuler =
  template this: untyped = result
  this = new(Orientation_MsgOrientEuler)
  let root = if root == nil: cast[Orientation](this) else: cast[Orientation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  rotation about the forward axis of the vehicle

  ]##
  let rollExpr = this.io.readS4le()
  this.roll = rollExpr

  ##[
  rotation about the rightward axis of the vehicle

  ]##
  let pitchExpr = this.io.readS4le()
  this.pitch = pitchExpr

  ##[
  rotation about the downward axis of the vehicle

  ]##
  let yawExpr = this.io.readS4le()
  this.yaw = yawExpr

  ##[
  Estimated standard deviation of roll

  ]##
  let rollAccuracyExpr = this.io.readF4le()
  this.rollAccuracy = rollAccuracyExpr

  ##[
  Estimated standard deviation of pitch

  ]##
  let pitchAccuracyExpr = this.io.readF4le()
  this.pitchAccuracy = pitchAccuracyExpr

  ##[
  Estimated standard deviation of yaw

  ]##
  let yawAccuracyExpr = this.io.readF4le()
  this.yawAccuracy = yawAccuracyExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Orientation_MsgOrientEuler], filename: string): Orientation_MsgOrientEuler =
  Orientation_MsgOrientEuler.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the orientation rates in the vehicle body frame.
The values represent the measurements a strapped down gyroscope would
make and are not equivalent to the time derivative of the Euler angles.
The orientation and origin of the user frame is specified via device
settings. By convention, the vehicle x-axis is expected to be aligned
with the forward direction, while the vehicle y-axis is expected to be
aligned with the right direction, and the vehicle z-axis should be
aligned with the down direction. This message will only be available in
future INS versions of Swift Products and is not produced by Piksi Multi
or Duro.

]##
proc read*(_: typedesc[Orientation_MsgAngularRate], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Orientation_MsgAngularRate =
  template this: untyped = result
  this = new(Orientation_MsgAngularRate)
  let root = if root == nil: cast[Orientation](this) else: cast[Orientation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  angular rate about x axis

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  angular rate about y axis

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  angular rate about z axis

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Orientation_MsgAngularRate], filename: string): Orientation_MsgAngularRate =
  Orientation_MsgAngularRate.read(newKaitaiFileStream(filename), nil, nil)

