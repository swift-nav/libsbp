import kaitai_struct_nim_runtime
import options
import gnss

type
  Acquisition* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Acquisition_MsgAcqResultDepC* = ref object of KaitaiStruct
    `cn0`*: float32
    `cp`*: float32
    `cf`*: float32
    `sid`*: Gnss_GnssSignalDep
    `parent`*: Sbp_Message
  Acquisition_MsgAcqResultDepB* = ref object of KaitaiStruct
    `snr`*: float32
    `cp`*: float32
    `cf`*: float32
    `sid`*: Gnss_GnssSignalDep
    `parent`*: Sbp_Message
  Acquisition_AcqSvProfile* = ref object of KaitaiStruct
    `jobType`*: uint8
    `status`*: uint8
    `cn0`*: uint16
    `intTime`*: uint8
    `sid`*: Gnss_GnssSignal
    `binWidth`*: uint16
    `timestamp`*: uint32
    `timeSpent`*: uint32
    `cfMin`*: int32
    `cfMax`*: int32
    `cf`*: int32
    `cp`*: uint32
    `parent`*: Acquisition_MsgAcqSvProfile
  Acquisition_MsgAcqSvProfile* = ref object of KaitaiStruct
    `acqSvProfile`*: seq[Acquisition_AcqSvProfile]
    `parent`*: Sbp_Message
  Acquisition_AcqSvProfileDep* = ref object of KaitaiStruct
    `jobType`*: uint8
    `status`*: uint8
    `cn0`*: uint16
    `intTime`*: uint8
    `sid`*: Gnss_GnssSignalDep
    `binWidth`*: uint16
    `timestamp`*: uint32
    `timeSpent`*: uint32
    `cfMin`*: int32
    `cfMax`*: int32
    `cf`*: int32
    `cp`*: uint32
    `parent`*: Acquisition_MsgAcqSvProfileDep
  Acquisition_MsgAcqResult* = ref object of KaitaiStruct
    `cn0`*: float32
    `cp`*: float32
    `cf`*: float32
    `sid`*: Gnss_GnssSignal
    `parent`*: Sbp_Message
  Acquisition_MsgAcqResultDepA* = ref object of KaitaiStruct
    `snr`*: float32
    `cp`*: float32
    `cf`*: float32
    `prn`*: uint8
    `parent`*: Sbp_Message
  Acquisition_MsgAcqSvProfileDep* = ref object of KaitaiStruct
    `acqSvProfile`*: seq[Acquisition_AcqSvProfileDep]
    `parent`*: Sbp_Message

proc read*(_: typedesc[Acquisition], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Acquisition
proc read*(_: typedesc[Acquisition_MsgAcqResultDepC], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqResultDepC
proc read*(_: typedesc[Acquisition_MsgAcqResultDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqResultDepB
proc read*(_: typedesc[Acquisition_AcqSvProfile], io: KaitaiStream, root: KaitaiStruct, parent: Acquisition_MsgAcqSvProfile): Acquisition_AcqSvProfile
proc read*(_: typedesc[Acquisition_MsgAcqSvProfile], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqSvProfile
proc read*(_: typedesc[Acquisition_AcqSvProfileDep], io: KaitaiStream, root: KaitaiStruct, parent: Acquisition_MsgAcqSvProfileDep): Acquisition_AcqSvProfileDep
proc read*(_: typedesc[Acquisition_MsgAcqResult], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqResult
proc read*(_: typedesc[Acquisition_MsgAcqResultDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqResultDepA
proc read*(_: typedesc[Acquisition_MsgAcqSvProfileDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqSvProfileDep


proc read*(_: typedesc[Acquisition], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Acquisition =
  template this: untyped = result
  this = new(Acquisition)
  let root = if root == nil: cast[Acquisition](this) else: cast[Acquisition](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Acquisition], filename: string): Acquisition =
  Acquisition.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Acquisition_MsgAcqResultDepC], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqResultDepC =
  template this: untyped = result
  this = new(Acquisition_MsgAcqResultDepC)
  let root = if root == nil: cast[Acquisition](this) else: cast[Acquisition](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  CN/0 of best point

  ]##
  let cn0Expr = this.io.readF4le()
  this.cn0 = cn0Expr

  ##[
  Code phase of best point

  ]##
  let cpExpr = this.io.readF4le()
  this.cp = cpExpr

  ##[
  Carrier frequency of best point

  ]##
  let cfExpr = this.io.readF4le()
  this.cf = cfExpr

  ##[
  GNSS signal for which acquisition was attempted

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

proc fromFile*(_: typedesc[Acquisition_MsgAcqResultDepC], filename: string): Acquisition_MsgAcqResultDepC =
  Acquisition_MsgAcqResultDepC.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Acquisition_MsgAcqResultDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqResultDepB =
  template this: untyped = result
  this = new(Acquisition_MsgAcqResultDepB)
  let root = if root == nil: cast[Acquisition](this) else: cast[Acquisition](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  SNR of best point. Currently in arbitrary SNR points, but will be in
units of dB Hz in a later revision of this message.

  ]##
  let snrExpr = this.io.readF4le()
  this.snr = snrExpr

  ##[
  Code phase of best point

  ]##
  let cpExpr = this.io.readF4le()
  this.cp = cpExpr

  ##[
  Carrier frequency of best point

  ]##
  let cfExpr = this.io.readF4le()
  this.cf = cfExpr

  ##[
  GNSS signal for which acquisition was attempted

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

proc fromFile*(_: typedesc[Acquisition_MsgAcqResultDepB], filename: string): Acquisition_MsgAcqResultDepB =
  Acquisition_MsgAcqResultDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
Profile for a specific SV for debugging purposes. The message describes
SV profile during acquisition time. The message is used to debug and
measure the performance.

]##
proc read*(_: typedesc[Acquisition_AcqSvProfile], io: KaitaiStream, root: KaitaiStruct, parent: Acquisition_MsgAcqSvProfile): Acquisition_AcqSvProfile =
  template this: untyped = result
  this = new(Acquisition_AcqSvProfile)
  let root = if root == nil: cast[Acquisition](this) else: cast[Acquisition](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  SV search job type (deep, fallback, etc)

  ]##
  let jobTypeExpr = this.io.readU1()
  this.jobType = jobTypeExpr

  ##[
  Acquisition status 1 is Success, 0 is Failure

  ]##
  let statusExpr = this.io.readU1()
  this.status = statusExpr

  ##[
  CN0 value. Only valid if status is '1'

  ]##
  let cn0Expr = this.io.readU2le()
  this.cn0 = cn0Expr

  ##[
  Acquisition integration time

  ]##
  let intTimeExpr = this.io.readU1()
  this.intTime = intTimeExpr

  ##[
  GNSS signal for which acquisition was attempted

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Acq frequency bin width

  ]##
  let binWidthExpr = this.io.readU2le()
  this.binWidth = binWidthExpr

  ##[
  Timestamp of the job complete event

  ]##
  let timestampExpr = this.io.readU4le()
  this.timestamp = timestampExpr

  ##[
  Time spent to search for sid.code

  ]##
  let timeSpentExpr = this.io.readU4le()
  this.timeSpent = timeSpentExpr

  ##[
  Doppler range lowest frequency

  ]##
  let cfMinExpr = this.io.readS4le()
  this.cfMin = cfMinExpr

  ##[
  Doppler range highest frequency

  ]##
  let cfMaxExpr = this.io.readS4le()
  this.cfMax = cfMaxExpr

  ##[
  Doppler value of detected peak. Only valid if status is '1'

  ]##
  let cfExpr = this.io.readS4le()
  this.cf = cfExpr

  ##[
  Codephase of detected peak. Only valid if status is '1'

  ]##
  let cpExpr = this.io.readU4le()
  this.cp = cpExpr

proc fromFile*(_: typedesc[Acquisition_AcqSvProfile], filename: string): Acquisition_AcqSvProfile =
  Acquisition_AcqSvProfile.read(newKaitaiFileStream(filename), nil, nil)


##[
The message describes all SV profiles during acquisition time. The
message is used to debug and measure the performance.

]##
proc read*(_: typedesc[Acquisition_MsgAcqSvProfile], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqSvProfile =
  template this: untyped = result
  this = new(Acquisition_MsgAcqSvProfile)
  let root = if root == nil: cast[Acquisition](this) else: cast[Acquisition](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  SV profiles during acquisition time

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Acquisition_AcqSvProfile.read(this.io, this.root, this)
      this.acqSvProfile.add(it)
      inc i

proc fromFile*(_: typedesc[Acquisition_MsgAcqSvProfile], filename: string): Acquisition_MsgAcqSvProfile =
  Acquisition_MsgAcqSvProfile.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Acquisition_AcqSvProfileDep], io: KaitaiStream, root: KaitaiStruct, parent: Acquisition_MsgAcqSvProfileDep): Acquisition_AcqSvProfileDep =
  template this: untyped = result
  this = new(Acquisition_AcqSvProfileDep)
  let root = if root == nil: cast[Acquisition](this) else: cast[Acquisition](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  SV search job type (deep, fallback, etc)

  ]##
  let jobTypeExpr = this.io.readU1()
  this.jobType = jobTypeExpr

  ##[
  Acquisition status 1 is Success, 0 is Failure

  ]##
  let statusExpr = this.io.readU1()
  this.status = statusExpr

  ##[
  CN0 value. Only valid if status is '1'

  ]##
  let cn0Expr = this.io.readU2le()
  this.cn0 = cn0Expr

  ##[
  Acquisition integration time

  ]##
  let intTimeExpr = this.io.readU1()
  this.intTime = intTimeExpr

  ##[
  GNSS signal for which acquisition was attempted

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Acq frequency bin width

  ]##
  let binWidthExpr = this.io.readU2le()
  this.binWidth = binWidthExpr

  ##[
  Timestamp of the job complete event

  ]##
  let timestampExpr = this.io.readU4le()
  this.timestamp = timestampExpr

  ##[
  Time spent to search for sid.code

  ]##
  let timeSpentExpr = this.io.readU4le()
  this.timeSpent = timeSpentExpr

  ##[
  Doppler range lowest frequency

  ]##
  let cfMinExpr = this.io.readS4le()
  this.cfMin = cfMinExpr

  ##[
  Doppler range highest frequency

  ]##
  let cfMaxExpr = this.io.readS4le()
  this.cfMax = cfMaxExpr

  ##[
  Doppler value of detected peak. Only valid if status is '1'

  ]##
  let cfExpr = this.io.readS4le()
  this.cf = cfExpr

  ##[
  Codephase of detected peak. Only valid if status is '1'

  ]##
  let cpExpr = this.io.readU4le()
  this.cp = cpExpr

proc fromFile*(_: typedesc[Acquisition_AcqSvProfileDep], filename: string): Acquisition_AcqSvProfileDep =
  Acquisition_AcqSvProfileDep.read(newKaitaiFileStream(filename), nil, nil)


##[
This message describes the results from an attempted GPS signal
acquisition search for a satellite PRN over a code phase/carrier
frequency range. It contains the parameters of the point in the
acquisition search space with the best carrier-to-noise (CN/0) ratio.

]##
proc read*(_: typedesc[Acquisition_MsgAcqResult], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqResult =
  template this: untyped = result
  this = new(Acquisition_MsgAcqResult)
  let root = if root == nil: cast[Acquisition](this) else: cast[Acquisition](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  CN/0 of best point

  ]##
  let cn0Expr = this.io.readF4le()
  this.cn0 = cn0Expr

  ##[
  Code phase of best point

  ]##
  let cpExpr = this.io.readF4le()
  this.cp = cpExpr

  ##[
  Carrier frequency of best point

  ]##
  let cfExpr = this.io.readF4le()
  this.cf = cfExpr

  ##[
  GNSS signal for which acquisition was attempted

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

proc fromFile*(_: typedesc[Acquisition_MsgAcqResult], filename: string): Acquisition_MsgAcqResult =
  Acquisition_MsgAcqResult.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Acquisition_MsgAcqResultDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqResultDepA =
  template this: untyped = result
  this = new(Acquisition_MsgAcqResultDepA)
  let root = if root == nil: cast[Acquisition](this) else: cast[Acquisition](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  SNR of best point. Currently dimensionless, but will have units of
dB Hz in the revision of this message.

  ]##
  let snrExpr = this.io.readF4le()
  this.snr = snrExpr

  ##[
  Code phase of best point

  ]##
  let cpExpr = this.io.readF4le()
  this.cp = cpExpr

  ##[
  Carrier frequency of best point

  ]##
  let cfExpr = this.io.readF4le()
  this.cf = cfExpr

  ##[
  PRN-1 identifier of the satellite signal for which acquisition was
attempted

  ]##
  let prnExpr = this.io.readU1()
  this.prn = prnExpr

proc fromFile*(_: typedesc[Acquisition_MsgAcqResultDepA], filename: string): Acquisition_MsgAcqResultDepA =
  Acquisition_MsgAcqResultDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Acquisition_MsgAcqSvProfileDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Acquisition_MsgAcqSvProfileDep =
  template this: untyped = result
  this = new(Acquisition_MsgAcqSvProfileDep)
  let root = if root == nil: cast[Acquisition](this) else: cast[Acquisition](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  SV profiles during acquisition time

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Acquisition_AcqSvProfileDep.read(this.io, this.root, this)
      this.acqSvProfile.add(it)
      inc i

proc fromFile*(_: typedesc[Acquisition_MsgAcqSvProfileDep], filename: string): Acquisition_MsgAcqSvProfileDep =
  Acquisition_MsgAcqSvProfileDep.read(newKaitaiFileStream(filename), nil, nil)

