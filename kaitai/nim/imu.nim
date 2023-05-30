import kaitai_struct_nim_runtime
import options

type
  Imu* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Imu_MsgImuRaw* = ref object of KaitaiStruct
    `tow`*: uint32
    `towF`*: uint8
    `accX`*: int16
    `accY`*: int16
    `accZ`*: int16
    `gyrX`*: int16
    `gyrY`*: int16
    `gyrZ`*: int16
    `parent`*: Sbp_Message
  Imu_MsgImuAux* = ref object of KaitaiStruct
    `imuType`*: uint8
    `temp`*: int16
    `imuConf`*: uint8
    `parent`*: Sbp_Message

proc read*(_: typedesc[Imu], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Imu
proc read*(_: typedesc[Imu_MsgImuRaw], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Imu_MsgImuRaw
proc read*(_: typedesc[Imu_MsgImuAux], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Imu_MsgImuAux


proc read*(_: typedesc[Imu], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Imu =
  template this: untyped = result
  this = new(Imu)
  let root = if root == nil: cast[Imu](this) else: cast[Imu](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Imu], filename: string): Imu =
  Imu.read(newKaitaiFileStream(filename), nil, nil)


##[
Raw data from the Inertial Measurement Unit, containing accelerometer
and gyroscope readings. The sense of the measurements are to be aligned
with the indications on the device itself. Measurement units, which are
specific to the device hardware and settings, are communicated via the
MSG_IMU_AUX message. If using "time since startup" time tags, the
receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
becomes available to synchronise IMU measurements with GNSS. The
timestamp must wrap around to zero when reaching one week (604800
seconds).

The time-tagging mode should not change throughout a run.

]##
proc read*(_: typedesc[Imu_MsgImuRaw], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Imu_MsgImuRaw =
  template this: untyped = result
  this = new(Imu_MsgImuRaw)
  let root = if root == nil: cast[Imu](this) else: cast[Imu](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Milliseconds since reference epoch and time status.

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Milliseconds since reference epoch, fractional part

  ]##
  let towFExpr = this.io.readU1()
  this.towF = towFExpr

  ##[
  Acceleration in the IMU frame X axis

  ]##
  let accXExpr = this.io.readS2le()
  this.accX = accXExpr

  ##[
  Acceleration in the IMU frame Y axis

  ]##
  let accYExpr = this.io.readS2le()
  this.accY = accYExpr

  ##[
  Acceleration in the IMU frame Z axis

  ]##
  let accZExpr = this.io.readS2le()
  this.accZ = accZExpr

  ##[
  Angular rate around IMU frame X axis

  ]##
  let gyrXExpr = this.io.readS2le()
  this.gyrX = gyrXExpr

  ##[
  Angular rate around IMU frame Y axis

  ]##
  let gyrYExpr = this.io.readS2le()
  this.gyrY = gyrYExpr

  ##[
  Angular rate around IMU frame Z axis

  ]##
  let gyrZExpr = this.io.readS2le()
  this.gyrZ = gyrZExpr

proc fromFile*(_: typedesc[Imu_MsgImuRaw], filename: string): Imu_MsgImuRaw =
  Imu_MsgImuRaw.read(newKaitaiFileStream(filename), nil, nil)


##[
Auxiliary data specific to a particular IMU. The `imu_type` field will
always be consistent but the rest of the payload is device specific and
depends on the value of `imu_type`.

]##
proc read*(_: typedesc[Imu_MsgImuAux], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Imu_MsgImuAux =
  template this: untyped = result
  this = new(Imu_MsgImuAux)
  let root = if root == nil: cast[Imu](this) else: cast[Imu](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  IMU type

  ]##
  let imuTypeExpr = this.io.readU1()
  this.imuType = imuTypeExpr

  ##[
  Raw IMU temperature

  ]##
  let tempExpr = this.io.readS2le()
  this.temp = tempExpr

  ##[
  IMU configuration

  ]##
  let imuConfExpr = this.io.readU1()
  this.imuConf = imuConfExpr

proc fromFile*(_: typedesc[Imu_MsgImuAux], filename: string): Imu_MsgImuAux =
  Imu_MsgImuAux.read(newKaitaiFileStream(filename), nil, nil)

