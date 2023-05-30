import kaitai_struct_nim_runtime
import options

type
  Navigation* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Navigation_MsgPosLlhDepA* = ref object of KaitaiStruct
    `tow`*: uint32
    `lat`*: float64
    `lon`*: float64
    `height`*: float64
    `hAccuracy`*: uint16
    `vAccuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgProtectionLevelDepA* = ref object of KaitaiStruct
    `tow`*: uint32
    `vpl`*: uint16
    `hpl`*: uint16
    `lat`*: float64
    `lon`*: float64
    `height`*: float64
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgPosLlhCov* = ref object of KaitaiStruct
    `tow`*: uint32
    `lat`*: float64
    `lon`*: float64
    `height`*: float64
    `covNN`*: float32
    `covNE`*: float32
    `covND`*: float32
    `covEE`*: float32
    `covED`*: float32
    `covDD`*: float32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelNedDepA* = ref object of KaitaiStruct
    `tow`*: uint32
    `n`*: int32
    `e`*: int32
    `d`*: int32
    `hAccuracy`*: uint16
    `vAccuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelNedCov* = ref object of KaitaiStruct
    `tow`*: uint32
    `n`*: int32
    `e`*: int32
    `d`*: int32
    `covNN`*: float32
    `covNE`*: float32
    `covND`*: float32
    `covEE`*: float32
    `covED`*: float32
    `covDD`*: float32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgUtcTime* = ref object of KaitaiStruct
    `flags`*: uint8
    `tow`*: uint32
    `year`*: uint16
    `month`*: uint8
    `day`*: uint8
    `hours`*: uint8
    `minutes`*: uint8
    `seconds`*: uint8
    `ns`*: uint32
    `parent`*: Sbp_Message
  Navigation_MsgPosEcefCovGnss* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: float64
    `y`*: float64
    `z`*: float64
    `covXX`*: float32
    `covXY`*: float32
    `covXZ`*: float32
    `covYY`*: float32
    `covYZ`*: float32
    `covZZ`*: float32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelNedGnss* = ref object of KaitaiStruct
    `tow`*: uint32
    `n`*: int32
    `e`*: int32
    `d`*: int32
    `hAccuracy`*: uint16
    `vAccuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelNedCovGnss* = ref object of KaitaiStruct
    `tow`*: uint32
    `n`*: int32
    `e`*: int32
    `d`*: int32
    `covNN`*: float32
    `covNE`*: float32
    `covND`*: float32
    `covEE`*: float32
    `covED`*: float32
    `covDD`*: float32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgBaselineNedDepA* = ref object of KaitaiStruct
    `tow`*: uint32
    `n`*: int32
    `e`*: int32
    `d`*: int32
    `hAccuracy`*: uint16
    `vAccuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelEcefDepA* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `accuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgReferenceFrameParam* = ref object of KaitaiStruct
    `ssrIod`*: uint8
    `sn`*: string
    `tn`*: string
    `sin`*: uint8
    `utn`*: uint16
    `reT0`*: uint16
    `deltaX0`*: int32
    `deltaY0`*: int32
    `deltaZ0`*: int32
    `theta01`*: int32
    `theta02`*: int32
    `theta03`*: int32
    `scale`*: int32
    `dotDeltaX0`*: int32
    `dotDeltaY0`*: int32
    `dotDeltaZ0`*: int32
    `dotTheta01`*: int32
    `dotTheta02`*: int32
    `dotTheta03`*: int32
    `dotScale`*: int16
    `parent`*: Sbp_Message
  Navigation_MsgPoseRelative* = ref object of KaitaiStruct
    `tow`*: uint32
    `sensorId`*: uint8
    `timestamp1`*: uint32
    `timestamp2`*: uint32
    `trans`*: seq[int32]
    `w`*: int32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `covRXX`*: float32
    `covRXY`*: float32
    `covRXZ`*: float32
    `covRYY`*: float32
    `covRYZ`*: float32
    `covRZZ`*: float32
    `covCXX`*: float32
    `covCXY`*: float32
    `covCXZ`*: float32
    `covCYY`*: float32
    `covCYZ`*: float32
    `covCZZ`*: float32
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelEcefCov* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `covXX`*: float32
    `covXY`*: float32
    `covXZ`*: float32
    `covYY`*: float32
    `covYZ`*: float32
    `covZZ`*: float32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelBody* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `covXX`*: float32
    `covXY`*: float32
    `covXZ`*: float32
    `covYY`*: float32
    `covYZ`*: float32
    `covZZ`*: float32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelEcefGnss* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `accuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelEcef* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `accuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgPosLlhCovGnss* = ref object of KaitaiStruct
    `tow`*: uint32
    `lat`*: float64
    `lon`*: float64
    `height`*: float64
    `covNN`*: float32
    `covNE`*: float32
    `covND`*: float32
    `covEE`*: float32
    `covED`*: float32
    `covDD`*: float32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgBaselineEcef* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `accuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgDopsDepA* = ref object of KaitaiStruct
    `tow`*: uint32
    `gdop`*: uint16
    `pdop`*: uint16
    `tdop`*: uint16
    `hdop`*: uint16
    `vdop`*: uint16
    `parent`*: Sbp_Message
  Navigation_MsgPosEcef* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: float64
    `y`*: float64
    `z`*: float64
    `accuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgAgeCorrections* = ref object of KaitaiStruct
    `tow`*: uint32
    `age`*: uint16
    `parent`*: Sbp_Message
  Navigation_MsgVelEcefCovGnss* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `covXX`*: float32
    `covXY`*: float32
    `covXZ`*: float32
    `covYY`*: float32
    `covYZ`*: float32
    `covZZ`*: float32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgProtectionLevel* = ref object of KaitaiStruct
    `tow`*: uint32
    `wn`*: int16
    `hpl`*: uint16
    `vpl`*: uint16
    `atpl`*: uint16
    `ctpl`*: uint16
    `hvpl`*: uint16
    `vvpl`*: uint16
    `hopl`*: uint16
    `popl`*: uint16
    `ropl`*: uint16
    `lat`*: float64
    `lon`*: float64
    `height`*: float64
    `vX`*: int32
    `vY`*: int32
    `vZ`*: int32
    `roll`*: int32
    `pitch`*: int32
    `heading`*: int32
    `flags`*: uint32
    `parent`*: Sbp_Message
  Navigation_MsgPosEcefCov* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: float64
    `y`*: float64
    `z`*: float64
    `covXX`*: float32
    `covXY`*: float32
    `covXZ`*: float32
    `covYY`*: float32
    `covYZ`*: float32
    `covZZ`*: float32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgPosEcefGnss* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: float64
    `y`*: float64
    `z`*: float64
    `accuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgVelNed* = ref object of KaitaiStruct
    `tow`*: uint32
    `n`*: int32
    `e`*: int32
    `d`*: int32
    `hAccuracy`*: uint16
    `vAccuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgUtcLeapSecond* = ref object of KaitaiStruct
    `reserved0`*: int16
    `reserved1`*: int16
    `reserved2`*: int8
    `countBefore`*: int8
    `reserved3`*: uint16
    `reserved4`*: uint16
    `refWn`*: uint16
    `refDn`*: uint8
    `countAfter`*: int8
    `parent`*: Sbp_Message
  Navigation_MsgGpsTimeDepA* = ref object of KaitaiStruct
    `wn`*: uint16
    `tow`*: uint32
    `nsResidual`*: int32
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgPosLlhGnss* = ref object of KaitaiStruct
    `tow`*: uint32
    `lat`*: float64
    `lon`*: float64
    `height`*: float64
    `hAccuracy`*: uint16
    `vAccuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgUtcTimeGnss* = ref object of KaitaiStruct
    `flags`*: uint8
    `tow`*: uint32
    `year`*: uint16
    `month`*: uint8
    `day`*: uint8
    `hours`*: uint8
    `minutes`*: uint8
    `seconds`*: uint8
    `ns`*: uint32
    `parent`*: Sbp_Message
  Navigation_MsgVelCog* = ref object of KaitaiStruct
    `tow`*: uint32
    `cog`*: uint32
    `sog`*: uint32
    `vUp`*: int32
    `cogAccuracy`*: uint32
    `sogAccuracy`*: uint32
    `vUpAccuracy`*: uint32
    `flags`*: uint16
    `parent`*: Sbp_Message
  Navigation_MsgBaselineNed* = ref object of KaitaiStruct
    `tow`*: uint32
    `n`*: int32
    `e`*: int32
    `d`*: int32
    `hAccuracy`*: uint16
    `vAccuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgPosLlh* = ref object of KaitaiStruct
    `tow`*: uint32
    `lat`*: float64
    `lon`*: float64
    `height`*: float64
    `hAccuracy`*: uint16
    `vAccuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgBaselineHeadingDepA* = ref object of KaitaiStruct
    `tow`*: uint32
    `heading`*: uint32
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgGpsTimeGnss* = ref object of KaitaiStruct
    `wn`*: uint16
    `tow`*: uint32
    `nsResidual`*: int32
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgBaselineEcefDepA* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: int32
    `y`*: int32
    `z`*: int32
    `accuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgGpsTime* = ref object of KaitaiStruct
    `wn`*: uint16
    `tow`*: uint32
    `nsResidual`*: int32
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgDops* = ref object of KaitaiStruct
    `tow`*: uint32
    `gdop`*: uint16
    `pdop`*: uint16
    `tdop`*: uint16
    `hdop`*: uint16
    `vdop`*: uint16
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_MsgPosEcefDepA* = ref object of KaitaiStruct
    `tow`*: uint32
    `x`*: float64
    `y`*: float64
    `z`*: float64
    `accuracy`*: uint16
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message
  Navigation_EstimatedHorizontalErrorEllipse* = ref object of KaitaiStruct
    `semiMajor`*: float32
    `semiMinor`*: float32
    `orientation`*: float32
    `parent`*: Navigation_MsgPosLlhAcc
  Navigation_MsgPosLlhAcc* = ref object of KaitaiStruct
    `tow`*: uint32
    `lat`*: float64
    `lon`*: float64
    `height`*: float64
    `orthometricHeight`*: float64
    `hAccuracy`*: float32
    `vAccuracy`*: float32
    `ctAccuracy`*: float32
    `atAccuracy`*: float32
    `hEllipse`*: Navigation_EstimatedHorizontalErrorEllipse
    `confidenceAndGeoid`*: uint8
    `nSats`*: uint8
    `flags`*: uint8
    `parent`*: Sbp_Message

proc read*(_: typedesc[Navigation], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Navigation
proc read*(_: typedesc[Navigation_MsgPosLlhDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhDepA
proc read*(_: typedesc[Navigation_MsgProtectionLevelDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgProtectionLevelDepA
proc read*(_: typedesc[Navigation_MsgPosLlhCov], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhCov
proc read*(_: typedesc[Navigation_MsgVelNedDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNedDepA
proc read*(_: typedesc[Navigation_MsgVelNedCov], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNedCov
proc read*(_: typedesc[Navigation_MsgUtcTime], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgUtcTime
proc read*(_: typedesc[Navigation_MsgPosEcefCovGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcefCovGnss
proc read*(_: typedesc[Navigation_MsgVelNedGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNedGnss
proc read*(_: typedesc[Navigation_MsgVelNedCovGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNedCovGnss
proc read*(_: typedesc[Navigation_MsgBaselineNedDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineNedDepA
proc read*(_: typedesc[Navigation_MsgVelEcefDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcefDepA
proc read*(_: typedesc[Navigation_MsgReferenceFrameParam], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgReferenceFrameParam
proc read*(_: typedesc[Navigation_MsgPoseRelative], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPoseRelative
proc read*(_: typedesc[Navigation_MsgVelEcefCov], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcefCov
proc read*(_: typedesc[Navigation_MsgVelBody], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelBody
proc read*(_: typedesc[Navigation_MsgVelEcefGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcefGnss
proc read*(_: typedesc[Navigation_MsgVelEcef], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcef
proc read*(_: typedesc[Navigation_MsgPosLlhCovGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhCovGnss
proc read*(_: typedesc[Navigation_MsgBaselineEcef], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineEcef
proc read*(_: typedesc[Navigation_MsgDopsDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgDopsDepA
proc read*(_: typedesc[Navigation_MsgPosEcef], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcef
proc read*(_: typedesc[Navigation_MsgAgeCorrections], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgAgeCorrections
proc read*(_: typedesc[Navigation_MsgVelEcefCovGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcefCovGnss
proc read*(_: typedesc[Navigation_MsgProtectionLevel], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgProtectionLevel
proc read*(_: typedesc[Navigation_MsgPosEcefCov], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcefCov
proc read*(_: typedesc[Navigation_MsgPosEcefGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcefGnss
proc read*(_: typedesc[Navigation_MsgVelNed], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNed
proc read*(_: typedesc[Navigation_MsgUtcLeapSecond], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgUtcLeapSecond
proc read*(_: typedesc[Navigation_MsgGpsTimeDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgGpsTimeDepA
proc read*(_: typedesc[Navigation_MsgPosLlhGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhGnss
proc read*(_: typedesc[Navigation_MsgUtcTimeGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgUtcTimeGnss
proc read*(_: typedesc[Navigation_MsgVelCog], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelCog
proc read*(_: typedesc[Navigation_MsgBaselineNed], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineNed
proc read*(_: typedesc[Navigation_MsgPosLlh], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlh
proc read*(_: typedesc[Navigation_MsgBaselineHeadingDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineHeadingDepA
proc read*(_: typedesc[Navigation_MsgGpsTimeGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgGpsTimeGnss
proc read*(_: typedesc[Navigation_MsgBaselineEcefDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineEcefDepA
proc read*(_: typedesc[Navigation_MsgGpsTime], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgGpsTime
proc read*(_: typedesc[Navigation_MsgDops], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgDops
proc read*(_: typedesc[Navigation_MsgPosEcefDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcefDepA
proc read*(_: typedesc[Navigation_EstimatedHorizontalErrorEllipse], io: KaitaiStream, root: KaitaiStruct, parent: Navigation_MsgPosLlhAcc): Navigation_EstimatedHorizontalErrorEllipse
proc read*(_: typedesc[Navigation_MsgPosLlhAcc], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhAcc


proc read*(_: typedesc[Navigation], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Navigation =
  template this: untyped = result
  this = new(Navigation)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Navigation], filename: string): Navigation =
  Navigation.read(newKaitaiFileStream(filename), nil, nil)


##[
This position solution message reports the absolute geodetic coordinates
and the status (single point vs pseudo-absolute RTK) of the position
solution. If the rover receiver knows the surveyed position of the base
station and has an RTK solution, this reports a pseudo-absolute position
solution using the base station position and the rover's RTK baseline
vector. The full GPS time is given by the preceding MSG_GPS_TIME with
the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgPosLlhDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhDepA =
  template this: untyped = result
  this = new(Navigation_MsgPosLlhDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Latitude

  ]##
  let latExpr = this.io.readF8le()
  this.lat = latExpr

  ##[
  Longitude

  ]##
  let lonExpr = this.io.readF8le()
  this.lon = lonExpr

  ##[
  Height

  ]##
  let heightExpr = this.io.readF8le()
  this.height = heightExpr

  ##[
  Horizontal position accuracy estimate (not implemented). Defaults to
0.

  ]##
  let hAccuracyExpr = this.io.readU2le()
  this.hAccuracy = hAccuracyExpr

  ##[
  Vertical position accuracy estimate (not implemented). Defaults to
0.

  ]##
  let vAccuracyExpr = this.io.readU2le()
  this.vAccuracy = vAccuracyExpr

  ##[
  Number of satellites used in solution.

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgPosLlhDepA], filename: string): Navigation_MsgPosLlhDepA =
  Navigation_MsgPosLlhDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the local vertical and horizontal protection levels
associated with a given LLH position solution. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week
(tow).

]##
proc read*(_: typedesc[Navigation_MsgProtectionLevelDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgProtectionLevelDepA =
  template this: untyped = result
  this = new(Navigation_MsgProtectionLevelDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Vertical protection level

  ]##
  let vplExpr = this.io.readU2le()
  this.vpl = vplExpr

  ##[
  Horizontal protection level

  ]##
  let hplExpr = this.io.readU2le()
  this.hpl = hplExpr

  ##[
  Latitude

  ]##
  let latExpr = this.io.readF8le()
  this.lat = latExpr

  ##[
  Longitude

  ]##
  let lonExpr = this.io.readF8le()
  this.lon = lonExpr

  ##[
  Height

  ]##
  let heightExpr = this.io.readF8le()
  this.height = heightExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgProtectionLevelDepA], filename: string): Navigation_MsgProtectionLevelDepA =
  Navigation_MsgProtectionLevelDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
This position solution message reports the absolute geodetic coordinates
and the status (single point vs pseudo-absolute RTK) of the position
solution as well as the upper triangle of the 3x3 covariance matrix.
The position information and Fix Mode flags follow the MSG_POS_LLH
message.  Since the covariance matrix is computed in the local-level
North, East, Down frame, the covariance terms follow that convention.
Thus, covariances are reported against the "downward" measurement and
care should be taken with the sign convention.

]##
proc read*(_: typedesc[Navigation_MsgPosLlhCov], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhCov =
  template this: untyped = result
  this = new(Navigation_MsgPosLlhCov)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Latitude

  ]##
  let latExpr = this.io.readF8le()
  this.lat = latExpr

  ##[
  Longitude

  ]##
  let lonExpr = this.io.readF8le()
  this.lon = lonExpr

  ##[
  Height above WGS84 ellipsoid

  ]##
  let heightExpr = this.io.readF8le()
  this.height = heightExpr

  ##[
  Estimated variance of northing

  ]##
  let covNNExpr = this.io.readF4le()
  this.covNN = covNNExpr

  ##[
  Covariance of northing and easting

  ]##
  let covNEExpr = this.io.readF4le()
  this.covNE = covNEExpr

  ##[
  Covariance of northing and downward measurement

  ]##
  let covNDExpr = this.io.readF4le()
  this.covND = covNDExpr

  ##[
  Estimated variance of easting

  ]##
  let covEEExpr = this.io.readF4le()
  this.covEE = covEEExpr

  ##[
  Covariance of easting and downward measurement

  ]##
  let covEDExpr = this.io.readF4le()
  this.covED = covEDExpr

  ##[
  Estimated variance of downward measurement

  ]##
  let covDDExpr = this.io.readF4le()
  this.covDD = covDDExpr

  ##[
  Number of satellites used in solution.

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgPosLlhCov], filename: string): Navigation_MsgPosLlhCov =
  Navigation_MsgPosLlhCov.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week
(tow).

]##
proc read*(_: typedesc[Navigation_MsgVelNedDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNedDepA =
  template this: untyped = result
  this = new(Navigation_MsgVelNedDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity North coordinate

  ]##
  let nExpr = this.io.readS4le()
  this.n = nExpr

  ##[
  Velocity East coordinate

  ]##
  let eExpr = this.io.readS4le()
  this.e = eExpr

  ##[
  Velocity Down coordinate

  ]##
  let dExpr = this.io.readS4le()
  this.d = dExpr

  ##[
  Horizontal velocity accuracy estimate (not implemented). Defaults to
0.

  ]##
  let hAccuracyExpr = this.io.readU2le()
  this.hAccuracy = hAccuracyExpr

  ##[
  Vertical velocity accuracy estimate (not implemented). Defaults to
0.

  ]##
  let vAccuracyExpr = this.io.readU2le()
  this.vAccuracy = vAccuracyExpr

  ##[
  Number of satellites used in solution

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Status flags (reserved)

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgVelNedDepA], filename: string): Navigation_MsgVelNedDepA =
  Navigation_MsgVelNedDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week
(tow). This message is similar to the MSG_VEL_NED, but it includes the
upper triangular portion of the 3x3 covariance matrix.

]##
proc read*(_: typedesc[Navigation_MsgVelNedCov], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNedCov =
  template this: untyped = result
  this = new(Navigation_MsgVelNedCov)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity North coordinate

  ]##
  let nExpr = this.io.readS4le()
  this.n = nExpr

  ##[
  Velocity East coordinate

  ]##
  let eExpr = this.io.readS4le()
  this.e = eExpr

  ##[
  Velocity Down coordinate

  ]##
  let dExpr = this.io.readS4le()
  this.d = dExpr

  ##[
  Estimated variance of northward measurement

  ]##
  let covNNExpr = this.io.readF4le()
  this.covNN = covNNExpr

  ##[
  Covariance of northward and eastward measurement

  ]##
  let covNEExpr = this.io.readF4le()
  this.covNE = covNEExpr

  ##[
  Covariance of northward and downward measurement

  ]##
  let covNDExpr = this.io.readF4le()
  this.covND = covNDExpr

  ##[
  Estimated variance of eastward measurement

  ]##
  let covEEExpr = this.io.readF4le()
  this.covEE = covEEExpr

  ##[
  Covariance of eastward and downward measurement

  ]##
  let covEDExpr = this.io.readF4le()
  this.covED = covEDExpr

  ##[
  Estimated variance of downward measurement

  ]##
  let covDDExpr = this.io.readF4le()
  this.covDD = covDDExpr

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

proc fromFile*(_: typedesc[Navigation_MsgVelNedCov], filename: string): Navigation_MsgVelNedCov =
  Navigation_MsgVelNedCov.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the Universal Coordinated Time (UTC).  Note the
flags which indicate the source of the UTC offset value and source of
the time fix.

]##
proc read*(_: typedesc[Navigation_MsgUtcTime], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgUtcTime =
  template this: untyped = result
  this = new(Navigation_MsgUtcTime)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Indicates source and time validity

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  GPS time of week rounded to the nearest millisecond

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Year

  ]##
  let yearExpr = this.io.readU2le()
  this.year = yearExpr

  ##[
  Month (range 1 .. 12)

  ]##
  let monthExpr = this.io.readU1()
  this.month = monthExpr

  ##[
  days in the month (range 1-31)

  ]##
  let dayExpr = this.io.readU1()
  this.day = dayExpr

  ##[
  hours of day (range 0-23)

  ]##
  let hoursExpr = this.io.readU1()
  this.hours = hoursExpr

  ##[
  minutes of hour (range 0-59)

  ]##
  let minutesExpr = this.io.readU1()
  this.minutes = minutesExpr

  ##[
  seconds of minute (range 0-60) rounded down

  ]##
  let secondsExpr = this.io.readU1()
  this.seconds = secondsExpr

  ##[
  nanoseconds of second (range 0-999999999)

  ]##
  let nsExpr = this.io.readU4le()
  this.ns = nsExpr

proc fromFile*(_: typedesc[Navigation_MsgUtcTime], filename: string): Navigation_MsgUtcTime =
  Navigation_MsgUtcTime.read(newKaitaiFileStream(filename), nil, nil)


##[
The position solution message reports absolute Earth Centered Earth
Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
RTK) of the position solution. The message also reports the upper
triangular portion of the 3x3 covariance matrix. If the receiver knows
the surveyed position of the base station and has an RTK solution, this
reports a pseudo-absolute position solution using the base station
position and the rover's RTK baseline vector. The full GPS time is given
by the preceding MSG_GPS_TIME with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgPosEcefCovGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcefCovGnss =
  template this: untyped = result
  this = new(Navigation_MsgPosEcefCovGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  ECEF X coordinate

  ]##
  let xExpr = this.io.readF8le()
  this.x = xExpr

  ##[
  ECEF Y coordinate

  ]##
  let yExpr = this.io.readF8le()
  this.y = yExpr

  ##[
  ECEF Z coordinate

  ]##
  let zExpr = this.io.readF8le()
  this.z = zExpr

  ##[
  Estimated variance of x

  ]##
  let covXXExpr = this.io.readF4le()
  this.covXX = covXXExpr

  ##[
  Estimated covariance of x and y

  ]##
  let covXYExpr = this.io.readF4le()
  this.covXY = covXYExpr

  ##[
  Estimated covariance of x and z

  ]##
  let covXZExpr = this.io.readF4le()
  this.covXZ = covXZExpr

  ##[
  Estimated variance of y

  ]##
  let covYYExpr = this.io.readF4le()
  this.covYY = covYYExpr

  ##[
  Estimated covariance of y and z

  ]##
  let covYZExpr = this.io.readF4le()
  this.covYZ = covYZExpr

  ##[
  Estimated variance of z

  ]##
  let covZZExpr = this.io.readF4le()
  this.covZZ = covZZExpr

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

proc fromFile*(_: typedesc[Navigation_MsgPosEcefCovGnss], filename: string): Navigation_MsgPosEcefCovGnss =
  Navigation_MsgPosEcefCovGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week
(tow).

]##
proc read*(_: typedesc[Navigation_MsgVelNedGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNedGnss =
  template this: untyped = result
  this = new(Navigation_MsgVelNedGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity North coordinate

  ]##
  let nExpr = this.io.readS4le()
  this.n = nExpr

  ##[
  Velocity East coordinate

  ]##
  let eExpr = this.io.readS4le()
  this.e = eExpr

  ##[
  Velocity Down coordinate

  ]##
  let dExpr = this.io.readS4le()
  this.d = dExpr

  ##[
  Horizontal velocity estimated standard deviation

  ]##
  let hAccuracyExpr = this.io.readU2le()
  this.hAccuracy = hAccuracyExpr

  ##[
  Vertical velocity estimated standard deviation

  ]##
  let vAccuracyExpr = this.io.readU2le()
  this.vAccuracy = vAccuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgVelNedGnss], filename: string): Navigation_MsgVelNedGnss =
  Navigation_MsgVelNedGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week
(tow). This message is similar to the MSG_VEL_NED, but it includes the
upper triangular portion of the 3x3 covariance matrix.

]##
proc read*(_: typedesc[Navigation_MsgVelNedCovGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNedCovGnss =
  template this: untyped = result
  this = new(Navigation_MsgVelNedCovGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity North coordinate

  ]##
  let nExpr = this.io.readS4le()
  this.n = nExpr

  ##[
  Velocity East coordinate

  ]##
  let eExpr = this.io.readS4le()
  this.e = eExpr

  ##[
  Velocity Down coordinate

  ]##
  let dExpr = this.io.readS4le()
  this.d = dExpr

  ##[
  Estimated variance of northward measurement

  ]##
  let covNNExpr = this.io.readF4le()
  this.covNN = covNNExpr

  ##[
  Covariance of northward and eastward measurement

  ]##
  let covNEExpr = this.io.readF4le()
  this.covNE = covNEExpr

  ##[
  Covariance of northward and downward measurement

  ]##
  let covNDExpr = this.io.readF4le()
  this.covND = covNDExpr

  ##[
  Estimated variance of eastward measurement

  ]##
  let covEEExpr = this.io.readF4le()
  this.covEE = covEEExpr

  ##[
  Covariance of eastward and downward measurement

  ]##
  let covEDExpr = this.io.readF4le()
  this.covED = covEDExpr

  ##[
  Estimated variance of downward measurement

  ]##
  let covDDExpr = this.io.readF4le()
  this.covDD = covDDExpr

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

proc fromFile*(_: typedesc[Navigation_MsgVelNedCovGnss], filename: string): Navigation_MsgVelNedCovGnss =
  Navigation_MsgVelNedCovGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the baseline solution in North East Down (NED)
coordinates. This baseline is the relative vector distance from the base
station to the rover receiver, and NED coordinate system is defined at
the local WGS84 tangent plane centered at the base station position.
The full GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgBaselineNedDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineNedDepA =
  template this: untyped = result
  this = new(Navigation_MsgBaselineNedDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Baseline North coordinate

  ]##
  let nExpr = this.io.readS4le()
  this.n = nExpr

  ##[
  Baseline East coordinate

  ]##
  let eExpr = this.io.readS4le()
  this.e = eExpr

  ##[
  Baseline Down coordinate

  ]##
  let dExpr = this.io.readS4le()
  this.d = dExpr

  ##[
  Horizontal position accuracy estimate (not implemented). Defaults to
0.

  ]##
  let hAccuracyExpr = this.io.readU2le()
  this.hAccuracy = hAccuracyExpr

  ##[
  Vertical position accuracy estimate (not implemented). Defaults to
0.

  ]##
  let vAccuracyExpr = this.io.readU2le()
  this.vAccuracy = vAccuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgBaselineNedDepA], filename: string): Navigation_MsgBaselineNedDepA =
  Navigation_MsgBaselineNedDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in Earth Centered Earth Fixed (ECEF)
coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgVelEcefDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcefDepA =
  template this: untyped = result
  this = new(Navigation_MsgVelEcefDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity ECEF X coordinate

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  Velocity ECEF Y coordinate

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  Velocity ECEF Z coordinate

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Velocity accuracy estimate (not implemented). Defaults to 0.

  ]##
  let accuracyExpr = this.io.readU2le()
  this.accuracy = accuracyExpr

  ##[
  Number of satellites used in solution

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Status flags (reserved)

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgVelEcefDepA], filename: string): Navigation_MsgVelEcefDepA =
  Navigation_MsgVelEcefDepA.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Navigation_MsgReferenceFrameParam], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgReferenceFrameParam =
  template this: untyped = result
  this = new(Navigation_MsgReferenceFrameParam)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  SSR IOD parameter.

  ]##
  let ssrIodExpr = this.io.readU1()
  this.ssrIod = ssrIodExpr

  ##[
  Name of source coordinate-system.

  ]##
  let snExpr = encode(this.io.readBytesFull(), "ascii")
  this.sn = snExpr

  ##[
  Name of target coordinate-system.

  ]##
  let tnExpr = encode(this.io.readBytesFull(), "ascii")
  this.tn = tnExpr

  ##[
  System Identification Number.

  ]##
  let sinExpr = this.io.readU1()
  this.sin = sinExpr

  ##[
  Utilized Transformation Message.

  ]##
  let utnExpr = this.io.readU2le()
  this.utn = utnExpr

  ##[
  Reference Epoch t0 for transformation parameter set given as
Modified Julian Day (MJD) Number minus 44244 days.

  ]##
  let reT0Expr = this.io.readU2le()
  this.reT0 = reT0Expr

  ##[
  Translation in X for Reference Epoch t0.

  ]##
  let deltaX0Expr = this.io.readS4le()
  this.deltaX0 = deltaX0Expr

  ##[
  Translation in Y for Reference Epoch t0.

  ]##
  let deltaY0Expr = this.io.readS4le()
  this.deltaY0 = deltaY0Expr

  ##[
  Translation in Z for Reference Epoch t0.

  ]##
  let deltaZ0Expr = this.io.readS4le()
  this.deltaZ0 = deltaZ0Expr

  ##[
  Rotation around the X-axis for Reference Epoch t0.

  ]##
  let theta01Expr = this.io.readS4le()
  this.theta01 = theta01Expr

  ##[
  Rotation around the Y-axis for Reference Epoch t0.

  ]##
  let theta02Expr = this.io.readS4le()
  this.theta02 = theta02Expr

  ##[
  Rotation around the Z-axis for Reference Epoch t0.

  ]##
  let theta03Expr = this.io.readS4le()
  this.theta03 = theta03Expr

  ##[
  Scale correction for Reference Epoch t0.

  ]##
  let scaleExpr = this.io.readS4le()
  this.scale = scaleExpr

  ##[
  Rate of change of translation in X.

  ]##
  let dotDeltaX0Expr = this.io.readS4le()
  this.dotDeltaX0 = dotDeltaX0Expr

  ##[
  Rate of change of translation in Y.

  ]##
  let dotDeltaY0Expr = this.io.readS4le()
  this.dotDeltaY0 = dotDeltaY0Expr

  ##[
  Rate of change of translation in Z.

  ]##
  let dotDeltaZ0Expr = this.io.readS4le()
  this.dotDeltaZ0 = dotDeltaZ0Expr

  ##[
  Rate of change of rotation around the X-axis.

  ]##
  let dotTheta01Expr = this.io.readS4le()
  this.dotTheta01 = dotTheta01Expr

  ##[
  Rate of change of rotation around the Y-axis.

  ]##
  let dotTheta02Expr = this.io.readS4le()
  this.dotTheta02 = dotTheta02Expr

  ##[
  Rate of change of rotation around the Z-axis.

  ]##
  let dotTheta03Expr = this.io.readS4le()
  this.dotTheta03 = dotTheta03Expr

  ##[
  Rate of change of scale correction.

  ]##
  let dotScaleExpr = this.io.readS2le()
  this.dotScale = dotScaleExpr

proc fromFile*(_: typedesc[Navigation_MsgReferenceFrameParam], filename: string): Navigation_MsgReferenceFrameParam =
  Navigation_MsgReferenceFrameParam.read(newKaitaiFileStream(filename), nil, nil)


##[
This solution message reports the relative pose of a sensor between two
time instances. The relative pose comprises of a rotation and a
translation which relates the sensor (e.g. camera) frame at a given time
(first keyframe) to the sensor frame at another time (second keyframe).
The relative translations is a 3x1 vector described in the first
keyframe.  Relative rotation is described by a quaternion from second
keyframe to the first keyframe.

]##
proc read*(_: typedesc[Navigation_MsgPoseRelative], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPoseRelative =
  template this: untyped = result
  this = new(Navigation_MsgPoseRelative)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  ID of the sensor producing this message

  ]##
  let sensorIdExpr = this.io.readU1()
  this.sensorId = sensorIdExpr

  ##[
  Timestamp of first keyframe

  ]##
  let timestamp1Expr = this.io.readU4le()
  this.timestamp1 = timestamp1Expr

  ##[
  Timestamp of second keyframe

  ]##
  let timestamp2Expr = this.io.readU4le()
  this.timestamp2 = timestamp2Expr

  ##[
  Relative translation [x,y,z] described in first keyframe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readS4le()
    this.trans.add(it)

  ##[
  Real component of quaternion to describe relative rotation (second
to first keyframe)

  ]##
  let wExpr = this.io.readS4le()
  this.w = wExpr

  ##[
  1st imaginary component of quaternion to describe relative rotation
(second to first keyframe)

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  2nd imaginary component of quaternion to describe relative rotation
(second to first keyframe)

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  3rd imaginary component of quaternion to describe relative rotation
(second to first keyframe)

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Estimated variance of x (relative translation)

  ]##
  let covRXXExpr = this.io.readF4le()
  this.covRXX = covRXXExpr

  ##[
  Covariance of x and y (relative translation)

  ]##
  let covRXYExpr = this.io.readF4le()
  this.covRXY = covRXYExpr

  ##[
  Covariance of x and z (relative translation)

  ]##
  let covRXZExpr = this.io.readF4le()
  this.covRXZ = covRXZExpr

  ##[
  Estimated variance of y (relative translation)

  ]##
  let covRYYExpr = this.io.readF4le()
  this.covRYY = covRYYExpr

  ##[
  Covariance of y and z (relative translation)

  ]##
  let covRYZExpr = this.io.readF4le()
  this.covRYZ = covRYZExpr

  ##[
  Estimated variance of z (relative translation)

  ]##
  let covRZZExpr = this.io.readF4le()
  this.covRZZ = covRZZExpr

  ##[
  Estimated variance of x (relative rotation)

  ]##
  let covCXXExpr = this.io.readF4le()
  this.covCXX = covCXXExpr

  ##[
  Covariance of x and y (relative rotation)

  ]##
  let covCXYExpr = this.io.readF4le()
  this.covCXY = covCXYExpr

  ##[
  Covariance of x and z (relative rotation)

  ]##
  let covCXZExpr = this.io.readF4le()
  this.covCXZ = covCXZExpr

  ##[
  Estimated variance of y (relative rotation)

  ]##
  let covCYYExpr = this.io.readF4le()
  this.covCYY = covCYYExpr

  ##[
  Covariance of y and z (relative rotation)

  ]##
  let covCYZExpr = this.io.readF4le()
  this.covCYZ = covCYZExpr

  ##[
  Estimated variance of z (relative rotation)

  ]##
  let covCZZExpr = this.io.readF4le()
  this.covCZZ = covCZZExpr

  ##[
  Status flags of relative translation and rotation

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgPoseRelative], filename: string): Navigation_MsgPoseRelative =
  Navigation_MsgPoseRelative.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in Earth Centered Earth Fixed (ECEF)
coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgVelEcefCov], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcefCov =
  template this: untyped = result
  this = new(Navigation_MsgVelEcefCov)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity ECEF X coordinate

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  Velocity ECEF Y coordinate

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  Velocity ECEF Z coordinate

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Estimated variance of x

  ]##
  let covXXExpr = this.io.readF4le()
  this.covXX = covXXExpr

  ##[
  Estimated covariance of x and y

  ]##
  let covXYExpr = this.io.readF4le()
  this.covXY = covXYExpr

  ##[
  Estimated covariance of x and z

  ]##
  let covXZExpr = this.io.readF4le()
  this.covXZ = covXZExpr

  ##[
  Estimated variance of y

  ]##
  let covYYExpr = this.io.readF4le()
  this.covYY = covYYExpr

  ##[
  Estimated covariance of y and z

  ]##
  let covYZExpr = this.io.readF4le()
  this.covYZ = covYZExpr

  ##[
  Estimated variance of z

  ]##
  let covZZExpr = this.io.readF4le()
  this.covZZ = covZZExpr

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

proc fromFile*(_: typedesc[Navigation_MsgVelEcefCov], filename: string): Navigation_MsgVelEcefCov =
  Navigation_MsgVelEcefCov.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in the Vehicle Body Frame. By
convention, the x-axis should point out the nose of the vehicle and
represent the forward direction, while as the y-axis should point out
the right hand side of the vehicle. Since this is a right handed system,
z should point out the bottom of the vehicle. The orientation and origin
of the Vehicle Body Frame are specified via the device settings. The
full GPS time is given by the preceding MSG_GPS_TIME with the matching
time-of-week (tow). This message is only produced by inertial versions
of Swift products and is not available from Piksi Multi or Duro.

]##
proc read*(_: typedesc[Navigation_MsgVelBody], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelBody =
  template this: untyped = result
  this = new(Navigation_MsgVelBody)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity in x direction

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  Velocity in y direction

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  Velocity in z direction

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Estimated variance of x

  ]##
  let covXXExpr = this.io.readF4le()
  this.covXX = covXXExpr

  ##[
  Covariance of x and y

  ]##
  let covXYExpr = this.io.readF4le()
  this.covXY = covXYExpr

  ##[
  Covariance of x and z

  ]##
  let covXZExpr = this.io.readF4le()
  this.covXZ = covXZExpr

  ##[
  Estimated variance of y

  ]##
  let covYYExpr = this.io.readF4le()
  this.covYY = covYYExpr

  ##[
  Covariance of y and z

  ]##
  let covYZExpr = this.io.readF4le()
  this.covYZ = covYZExpr

  ##[
  Estimated variance of z

  ]##
  let covZZExpr = this.io.readF4le()
  this.covZZ = covZZExpr

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

proc fromFile*(_: typedesc[Navigation_MsgVelBody], filename: string): Navigation_MsgVelBody =
  Navigation_MsgVelBody.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in Earth Centered Earth Fixed (ECEF)
coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgVelEcefGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcefGnss =
  template this: untyped = result
  this = new(Navigation_MsgVelEcefGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity ECEF X coordinate

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  Velocity ECEF Y coordinate

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  Velocity ECEF Z coordinate

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Velocity estimated standard deviation

  ]##
  let accuracyExpr = this.io.readU2le()
  this.accuracy = accuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgVelEcefGnss], filename: string): Navigation_MsgVelEcefGnss =
  Navigation_MsgVelEcefGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in Earth Centered Earth Fixed (ECEF)
coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgVelEcef], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcef =
  template this: untyped = result
  this = new(Navigation_MsgVelEcef)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity ECEF X coordinate

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  Velocity ECEF Y coordinate

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  Velocity ECEF Z coordinate

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Velocity estimated standard deviation

  ]##
  let accuracyExpr = this.io.readU2le()
  this.accuracy = accuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgVelEcef], filename: string): Navigation_MsgVelEcef =
  Navigation_MsgVelEcef.read(newKaitaiFileStream(filename), nil, nil)


##[
This position solution message reports the absolute geodetic coordinates
and the status (single point vs pseudo-absolute RTK) of the position
solution as well as the upper triangle of the 3x3 covariance matrix.
The position information and Fix Mode flags should follow the
MSG_POS_LLH message.  Since the covariance matrix is computed in the
local-level North, East, Down frame, the covariance terms follow with
that convention. Thus, covariances are reported against the "downward"
measurement and care should be taken with the sign convention.

]##
proc read*(_: typedesc[Navigation_MsgPosLlhCovGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhCovGnss =
  template this: untyped = result
  this = new(Navigation_MsgPosLlhCovGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Latitude

  ]##
  let latExpr = this.io.readF8le()
  this.lat = latExpr

  ##[
  Longitude

  ]##
  let lonExpr = this.io.readF8le()
  this.lon = lonExpr

  ##[
  Height above WGS84 ellipsoid

  ]##
  let heightExpr = this.io.readF8le()
  this.height = heightExpr

  ##[
  Estimated variance of northing

  ]##
  let covNNExpr = this.io.readF4le()
  this.covNN = covNNExpr

  ##[
  Covariance of northing and easting

  ]##
  let covNEExpr = this.io.readF4le()
  this.covNE = covNEExpr

  ##[
  Covariance of northing and downward measurement

  ]##
  let covNDExpr = this.io.readF4le()
  this.covND = covNDExpr

  ##[
  Estimated variance of easting

  ]##
  let covEEExpr = this.io.readF4le()
  this.covEE = covEEExpr

  ##[
  Covariance of easting and downward measurement

  ]##
  let covEDExpr = this.io.readF4le()
  this.covED = covEDExpr

  ##[
  Estimated variance of downward measurement

  ]##
  let covDDExpr = this.io.readF4le()
  this.covDD = covDDExpr

  ##[
  Number of satellites used in solution.

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgPosLlhCovGnss], filename: string): Navigation_MsgPosLlhCovGnss =
  Navigation_MsgPosLlhCovGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the baseline solution in Earth Centered Earth Fixed
(ECEF) coordinates. This baseline is the relative vector distance from
the base station to the rover receiver. The full GPS time is given by
the preceding MSG_GPS_TIME with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgBaselineEcef], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineEcef =
  template this: untyped = result
  this = new(Navigation_MsgBaselineEcef)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Baseline ECEF X coordinate

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  Baseline ECEF Y coordinate

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  Baseline ECEF Z coordinate

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Position estimated standard deviation

  ]##
  let accuracyExpr = this.io.readU2le()
  this.accuracy = accuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgBaselineEcef], filename: string): Navigation_MsgBaselineEcef =
  Navigation_MsgBaselineEcef.read(newKaitaiFileStream(filename), nil, nil)


##[
This dilution of precision (DOP) message describes the effect of
navigation satellite geometry on positional measurement precision.

]##
proc read*(_: typedesc[Navigation_MsgDopsDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgDopsDepA =
  template this: untyped = result
  this = new(Navigation_MsgDopsDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Geometric Dilution of Precision

  ]##
  let gdopExpr = this.io.readU2le()
  this.gdop = gdopExpr

  ##[
  Position Dilution of Precision

  ]##
  let pdopExpr = this.io.readU2le()
  this.pdop = pdopExpr

  ##[
  Time Dilution of Precision

  ]##
  let tdopExpr = this.io.readU2le()
  this.tdop = tdopExpr

  ##[
  Horizontal Dilution of Precision

  ]##
  let hdopExpr = this.io.readU2le()
  this.hdop = hdopExpr

  ##[
  Vertical Dilution of Precision

  ]##
  let vdopExpr = this.io.readU2le()
  this.vdop = vdopExpr

proc fromFile*(_: typedesc[Navigation_MsgDopsDepA], filename: string): Navigation_MsgDopsDepA =
  Navigation_MsgDopsDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
The position solution message reports absolute Earth Centered Earth
Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
RTK) of the position solution. If the rover receiver knows the surveyed
position of the base station and has an RTK solution, this reports a
pseudo-absolute position solution using the base station position and
the rover's RTK baseline vector. The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgPosEcef], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcef =
  template this: untyped = result
  this = new(Navigation_MsgPosEcef)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  ECEF X coordinate

  ]##
  let xExpr = this.io.readF8le()
  this.x = xExpr

  ##[
  ECEF Y coordinate

  ]##
  let yExpr = this.io.readF8le()
  this.y = yExpr

  ##[
  ECEF Z coordinate

  ]##
  let zExpr = this.io.readF8le()
  this.z = zExpr

  ##[
  Position estimated standard deviation

  ]##
  let accuracyExpr = this.io.readU2le()
  this.accuracy = accuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgPosEcef], filename: string): Navigation_MsgPosEcef =
  Navigation_MsgPosEcef.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the Age of the corrections used for the current
Differential solution.

]##
proc read*(_: typedesc[Navigation_MsgAgeCorrections], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgAgeCorrections =
  template this: untyped = result
  this = new(Navigation_MsgAgeCorrections)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Age of the corrections (0xFFFF indicates invalid)

  ]##
  let ageExpr = this.io.readU2le()
  this.age = ageExpr

proc fromFile*(_: typedesc[Navigation_MsgAgeCorrections], filename: string): Navigation_MsgAgeCorrections =
  Navigation_MsgAgeCorrections.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in Earth Centered Earth Fixed (ECEF)
coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgVelEcefCovGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelEcefCovGnss =
  template this: untyped = result
  this = new(Navigation_MsgVelEcefCovGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity ECEF X coordinate

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  Velocity ECEF Y coordinate

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  Velocity ECEF Z coordinate

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Estimated variance of x

  ]##
  let covXXExpr = this.io.readF4le()
  this.covXX = covXXExpr

  ##[
  Estimated covariance of x and y

  ]##
  let covXYExpr = this.io.readF4le()
  this.covXY = covXYExpr

  ##[
  Estimated covariance of x and z

  ]##
  let covXZExpr = this.io.readF4le()
  this.covXZ = covXZExpr

  ##[
  Estimated variance of y

  ]##
  let covYYExpr = this.io.readF4le()
  this.covYY = covYYExpr

  ##[
  Estimated covariance of y and z

  ]##
  let covYZExpr = this.io.readF4le()
  this.covYZ = covYZExpr

  ##[
  Estimated variance of z

  ]##
  let covZZExpr = this.io.readF4le()
  this.covZZ = covZZExpr

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

proc fromFile*(_: typedesc[Navigation_MsgVelEcefCovGnss], filename: string): Navigation_MsgVelEcefCovGnss =
  Navigation_MsgVelEcefCovGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the protection levels associated to the given state
estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgProtectionLevel], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgProtectionLevel =
  template this: untyped = result
  this = new(Navigation_MsgProtectionLevel)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  GPS week number

  ]##
  let wnExpr = this.io.readS2le()
  this.wn = wnExpr

  ##[
  Horizontal protection level

  ]##
  let hplExpr = this.io.readU2le()
  this.hpl = hplExpr

  ##[
  Vertical protection level

  ]##
  let vplExpr = this.io.readU2le()
  this.vpl = vplExpr

  ##[
  Along-track position error protection level

  ]##
  let atplExpr = this.io.readU2le()
  this.atpl = atplExpr

  ##[
  Cross-track position error protection level

  ]##
  let ctplExpr = this.io.readU2le()
  this.ctpl = ctplExpr

  ##[
  Protection level for the error vector between estimated and true
along/cross track velocity vector

  ]##
  let hvplExpr = this.io.readU2le()
  this.hvpl = hvplExpr

  ##[
  Protection level for the velocity in vehicle upright direction
(different from vertical direction if on a slope)

  ]##
  let vvplExpr = this.io.readU2le()
  this.vvpl = vvplExpr

  ##[
  Heading orientation protection level

  ]##
  let hoplExpr = this.io.readU2le()
  this.hopl = hoplExpr

  ##[
  Pitch orientation protection level

  ]##
  let poplExpr = this.io.readU2le()
  this.popl = poplExpr

  ##[
  Roll orientation protection level

  ]##
  let roplExpr = this.io.readU2le()
  this.ropl = roplExpr

  ##[
  Latitude

  ]##
  let latExpr = this.io.readF8le()
  this.lat = latExpr

  ##[
  Longitude

  ]##
  let lonExpr = this.io.readF8le()
  this.lon = lonExpr

  ##[
  Height

  ]##
  let heightExpr = this.io.readF8le()
  this.height = heightExpr

  ##[
  Velocity in vehicle x direction

  ]##
  let vXExpr = this.io.readS4le()
  this.vX = vXExpr

  ##[
  Velocity in vehicle y direction

  ]##
  let vYExpr = this.io.readS4le()
  this.vY = vYExpr

  ##[
  Velocity in vehicle z direction

  ]##
  let vZExpr = this.io.readS4le()
  this.vZ = vZExpr

  ##[
  Roll angle

  ]##
  let rollExpr = this.io.readS4le()
  this.roll = rollExpr

  ##[
  Pitch angle

  ]##
  let pitchExpr = this.io.readS4le()
  this.pitch = pitchExpr

  ##[
  Heading angle

  ]##
  let headingExpr = this.io.readS4le()
  this.heading = headingExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU4le()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgProtectionLevel], filename: string): Navigation_MsgProtectionLevel =
  Navigation_MsgProtectionLevel.read(newKaitaiFileStream(filename), nil, nil)


##[
The position solution message reports absolute Earth Centered Earth
Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
RTK) of the position solution. The message also reports the upper
triangular portion of the 3x3 covariance matrix. If the receiver knows
the surveyed position of the base station and has an RTK solution, this
reports a pseudo-absolute position solution using the base station
position and the rover's RTK baseline vector. The full GPS time is given
by the preceding MSG_GPS_TIME with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgPosEcefCov], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcefCov =
  template this: untyped = result
  this = new(Navigation_MsgPosEcefCov)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  ECEF X coordinate

  ]##
  let xExpr = this.io.readF8le()
  this.x = xExpr

  ##[
  ECEF Y coordinate

  ]##
  let yExpr = this.io.readF8le()
  this.y = yExpr

  ##[
  ECEF Z coordinate

  ]##
  let zExpr = this.io.readF8le()
  this.z = zExpr

  ##[
  Estimated variance of x

  ]##
  let covXXExpr = this.io.readF4le()
  this.covXX = covXXExpr

  ##[
  Estimated covariance of x and y

  ]##
  let covXYExpr = this.io.readF4le()
  this.covXY = covXYExpr

  ##[
  Estimated covariance of x and z

  ]##
  let covXZExpr = this.io.readF4le()
  this.covXZ = covXZExpr

  ##[
  Estimated variance of y

  ]##
  let covYYExpr = this.io.readF4le()
  this.covYY = covYYExpr

  ##[
  Estimated covariance of y and z

  ]##
  let covYZExpr = this.io.readF4le()
  this.covYZ = covYZExpr

  ##[
  Estimated variance of z

  ]##
  let covZZExpr = this.io.readF4le()
  this.covZZ = covZZExpr

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

proc fromFile*(_: typedesc[Navigation_MsgPosEcefCov], filename: string): Navigation_MsgPosEcefCov =
  Navigation_MsgPosEcefCov.read(newKaitaiFileStream(filename), nil, nil)


##[
The position solution message reports absolute Earth Centered Earth
Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
RTK) of the position solution. If the rover receiver knows the surveyed
position of the base station and has an RTK solution, this reports a
pseudo-absolute position solution using the base station position and
the rover's RTK baseline vector. The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgPosEcefGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcefGnss =
  template this: untyped = result
  this = new(Navigation_MsgPosEcefGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  ECEF X coordinate

  ]##
  let xExpr = this.io.readF8le()
  this.x = xExpr

  ##[
  ECEF Y coordinate

  ]##
  let yExpr = this.io.readF8le()
  this.y = yExpr

  ##[
  ECEF Z coordinate

  ]##
  let zExpr = this.io.readF8le()
  this.z = zExpr

  ##[
  Position estimated standard deviation

  ]##
  let accuracyExpr = this.io.readU2le()
  this.accuracy = accuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgPosEcefGnss], filename: string): Navigation_MsgPosEcefGnss =
  Navigation_MsgPosEcefGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the velocity in local North East Down (NED)
coordinates. The NED coordinate system is defined as the local WGS84
tangent plane centered at the current position. The full GPS time is
given by the preceding MSG_GPS_TIME with the matching time-of-week
(tow).

]##
proc read*(_: typedesc[Navigation_MsgVelNed], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelNed =
  template this: untyped = result
  this = new(Navigation_MsgVelNed)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Velocity North coordinate

  ]##
  let nExpr = this.io.readS4le()
  this.n = nExpr

  ##[
  Velocity East coordinate

  ]##
  let eExpr = this.io.readS4le()
  this.e = eExpr

  ##[
  Velocity Down coordinate

  ]##
  let dExpr = this.io.readS4le()
  this.d = dExpr

  ##[
  Horizontal velocity estimated standard deviation

  ]##
  let hAccuracyExpr = this.io.readU2le()
  this.hAccuracy = hAccuracyExpr

  ##[
  Vertical velocity estimated standard deviation

  ]##
  let vAccuracyExpr = this.io.readU2le()
  this.vAccuracy = vAccuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgVelNed], filename: string): Navigation_MsgVelNed =
  Navigation_MsgVelNed.read(newKaitaiFileStream(filename), nil, nil)


##[
UTC-GPST leap seconds before and after the most recent (past, or future,
for announced insertions) UTC leap second insertion.

]##
proc read*(_: typedesc[Navigation_MsgUtcLeapSecond], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgUtcLeapSecond =
  template this: untyped = result
  this = new(Navigation_MsgUtcLeapSecond)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Reserved.

  ]##
  let reserved0Expr = this.io.readS2le()
  this.reserved0 = reserved0Expr

  ##[
  Reserved.

  ]##
  let reserved1Expr = this.io.readS2le()
  this.reserved1 = reserved1Expr

  ##[
  Reserved.

  ]##
  let reserved2Expr = this.io.readS1()
  this.reserved2 = reserved2Expr

  ##[
  Leap second count before insertion.

  ]##
  let countBeforeExpr = this.io.readS1()
  this.countBefore = countBeforeExpr

  ##[
  Reserved.

  ]##
  let reserved3Expr = this.io.readU2le()
  this.reserved3 = reserved3Expr

  ##[
  Reserved.

  ]##
  let reserved4Expr = this.io.readU2le()
  this.reserved4 = reserved4Expr

  ##[
  Leap second reference GPS week number.

  ]##
  let refWnExpr = this.io.readU2le()
  this.refWn = refWnExpr

  ##[
  Leap second reference day number.

  ]##
  let refDnExpr = this.io.readU1()
  this.refDn = refDnExpr

  ##[
  Leap second count after insertion.

  ]##
  let countAfterExpr = this.io.readS1()
  this.countAfter = countAfterExpr

proc fromFile*(_: typedesc[Navigation_MsgUtcLeapSecond], filename: string): Navigation_MsgUtcLeapSecond =
  Navigation_MsgUtcLeapSecond.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the GPS time, representing the time since the GPS
epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
and seconds of the week. The weeks begin at the Saturday/Sunday
transition. GPS week 0 began at the beginning of the GPS time scale.

Within each week number, the GPS time of the week is between between 0
and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
leap seconds, and as of now, has a small offset from UTC. In a message
stream, this message precedes a set of other navigation messages
referenced to the same time (but lacking the ns field) and indicates a
more precise time of these messages.

]##
proc read*(_: typedesc[Navigation_MsgGpsTimeDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgGpsTimeDepA =
  template this: untyped = result
  this = new(Navigation_MsgGpsTimeDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS week number

  ]##
  let wnExpr = this.io.readU2le()
  this.wn = wnExpr

  ##[
  GPS time of week rounded to the nearest millisecond

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Nanosecond residual of millisecond-rounded TOW (ranges from -500000
to 500000)

  ]##
  let nsResidualExpr = this.io.readS4le()
  this.nsResidual = nsResidualExpr

  ##[
  Status flags (reserved)

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgGpsTimeDepA], filename: string): Navigation_MsgGpsTimeDepA =
  Navigation_MsgGpsTimeDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
This position solution message reports the absolute geodetic coordinates
and the status (single point vs pseudo-absolute RTK) of the position
solution. If the rover receiver knows the surveyed position of the base
station and has an RTK solution, this reports a pseudo-absolute position
solution using the base station position and the rover's RTK baseline
vector. The full GPS time is given by the preceding MSG_GPS_TIME with
the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgPosLlhGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhGnss =
  template this: untyped = result
  this = new(Navigation_MsgPosLlhGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Latitude

  ]##
  let latExpr = this.io.readF8le()
  this.lat = latExpr

  ##[
  Longitude

  ]##
  let lonExpr = this.io.readF8le()
  this.lon = lonExpr

  ##[
  Height above WGS84 ellipsoid

  ]##
  let heightExpr = this.io.readF8le()
  this.height = heightExpr

  ##[
  Horizontal position estimated standard deviation

  ]##
  let hAccuracyExpr = this.io.readU2le()
  this.hAccuracy = hAccuracyExpr

  ##[
  Vertical position estimated standard deviation

  ]##
  let vAccuracyExpr = this.io.readU2le()
  this.vAccuracy = vAccuracyExpr

  ##[
  Number of satellites used in solution.

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgPosLlhGnss], filename: string): Navigation_MsgPosLlhGnss =
  Navigation_MsgPosLlhGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the Universal Coordinated Time (UTC).  Note the
flags which indicate the source of the UTC offset value and source of
the time fix.

]##
proc read*(_: typedesc[Navigation_MsgUtcTimeGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgUtcTimeGnss =
  template this: untyped = result
  this = new(Navigation_MsgUtcTimeGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Indicates source and time validity

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  GPS time of week rounded to the nearest millisecond

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Year

  ]##
  let yearExpr = this.io.readU2le()
  this.year = yearExpr

  ##[
  Month (range 1 .. 12)

  ]##
  let monthExpr = this.io.readU1()
  this.month = monthExpr

  ##[
  days in the month (range 1-31)

  ]##
  let dayExpr = this.io.readU1()
  this.day = dayExpr

  ##[
  hours of day (range 0-23)

  ]##
  let hoursExpr = this.io.readU1()
  this.hours = hoursExpr

  ##[
  minutes of hour (range 0-59)

  ]##
  let minutesExpr = this.io.readU1()
  this.minutes = minutesExpr

  ##[
  seconds of minute (range 0-60) rounded down

  ]##
  let secondsExpr = this.io.readU1()
  this.seconds = secondsExpr

  ##[
  nanoseconds of second (range 0-999999999)

  ]##
  let nsExpr = this.io.readU4le()
  this.ns = nsExpr

proc fromFile*(_: typedesc[Navigation_MsgUtcTimeGnss], filename: string): Navigation_MsgUtcTimeGnss =
  Navigation_MsgUtcTimeGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the receiver course over ground (COG) and speed
over  ground (SOG) based on the horizontal (N-E) components of the NED
velocity  vector. It also includes the vertical velocity coordinate. A
flag is provided to indicate whether the COG value has been frozen. When
the flag is set to true, the COG field is set to its last valid value
until  the system exceeds a minimum velocity threshold. No other fields
are  affected by this flag.  The NED coordinate system is defined as the
local WGS84 tangent  plane centered at the current position. The full
GPS time is given by the  preceding MSG_GPS_TIME with the matching time-
of-week (tow). Note: course over ground represents the receiver's
direction of travel,  but not necessarily the device heading.

]##
proc read*(_: typedesc[Navigation_MsgVelCog], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgVelCog =
  template this: untyped = result
  this = new(Navigation_MsgVelCog)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Course over ground relative to north direction

  ]##
  let cogExpr = this.io.readU4le()
  this.cog = cogExpr

  ##[
  Speed over ground (based on horizontal velocity)

  ]##
  let sogExpr = this.io.readU4le()
  this.sog = sogExpr

  ##[
  Vertical velocity component (positive up)

  ]##
  let vUpExpr = this.io.readS4le()
  this.vUp = vUpExpr

  ##[
  Course over ground estimated standard deviation

  ]##
  let cogAccuracyExpr = this.io.readU4le()
  this.cogAccuracy = cogAccuracyExpr

  ##[
  Speed over ground estimated standard deviation

  ]##
  let sogAccuracyExpr = this.io.readU4le()
  this.sogAccuracy = sogAccuracyExpr

  ##[
  Vertical velocity estimated standard deviation

  ]##
  let vUpAccuracyExpr = this.io.readU4le()
  this.vUpAccuracy = vUpAccuracyExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU2le()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgVelCog], filename: string): Navigation_MsgVelCog =
  Navigation_MsgVelCog.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the baseline solution in North East Down (NED)
coordinates. This baseline is the relative vector distance from the base
station to the rover receiver, and NED coordinate system is defined at
the local WGS84 tangent plane centered at the base station position.
The full GPS time is given by the preceding MSG_GPS_TIME with the
matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgBaselineNed], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineNed =
  template this: untyped = result
  this = new(Navigation_MsgBaselineNed)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Baseline North coordinate

  ]##
  let nExpr = this.io.readS4le()
  this.n = nExpr

  ##[
  Baseline East coordinate

  ]##
  let eExpr = this.io.readS4le()
  this.e = eExpr

  ##[
  Baseline Down coordinate

  ]##
  let dExpr = this.io.readS4le()
  this.d = dExpr

  ##[
  Horizontal position estimated standard deviation

  ]##
  let hAccuracyExpr = this.io.readU2le()
  this.hAccuracy = hAccuracyExpr

  ##[
  Vertical position estimated standard deviation

  ]##
  let vAccuracyExpr = this.io.readU2le()
  this.vAccuracy = vAccuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgBaselineNed], filename: string): Navigation_MsgBaselineNed =
  Navigation_MsgBaselineNed.read(newKaitaiFileStream(filename), nil, nil)


##[
This position solution message reports the absolute geodetic coordinates
and the status (single point vs pseudo-absolute RTK) of the position
solution. If the rover receiver knows the surveyed position of the base
station and has an RTK solution, this reports a pseudo-absolute position
solution using the base station position and the rover's RTK baseline
vector. The full GPS time is given by the preceding MSG_GPS_TIME with
the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgPosLlh], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlh =
  template this: untyped = result
  this = new(Navigation_MsgPosLlh)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Latitude

  ]##
  let latExpr = this.io.readF8le()
  this.lat = latExpr

  ##[
  Longitude

  ]##
  let lonExpr = this.io.readF8le()
  this.lon = lonExpr

  ##[
  Height above WGS84 ellipsoid

  ]##
  let heightExpr = this.io.readF8le()
  this.height = heightExpr

  ##[
  Horizontal position estimated standard deviation

  ]##
  let hAccuracyExpr = this.io.readU2le()
  this.hAccuracy = hAccuracyExpr

  ##[
  Vertical position estimated standard deviation

  ]##
  let vAccuracyExpr = this.io.readU2le()
  this.vAccuracy = vAccuracyExpr

  ##[
  Number of satellites used in solution.

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgPosLlh], filename: string): Navigation_MsgPosLlh =
  Navigation_MsgPosLlh.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the baseline heading pointing from the base station
to the rover relative to True North. The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgBaselineHeadingDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineHeadingDepA =
  template this: untyped = result
  this = new(Navigation_MsgBaselineHeadingDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
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

proc fromFile*(_: typedesc[Navigation_MsgBaselineHeadingDepA], filename: string): Navigation_MsgBaselineHeadingDepA =
  Navigation_MsgBaselineHeadingDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the GPS time, representing the time since the GPS
epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
and seconds of the week. The weeks begin at the Saturday/Sunday
transition. GPS week 0 began at the beginning of the GPS time scale.

Within each week number, the GPS time of the week is between between 0
and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
leap seconds, and as of now, has a small offset from UTC. In a message
stream, this message precedes a set of other navigation messages
referenced to the same time (but lacking the ns field) and indicates a
more precise time of these messages.

]##
proc read*(_: typedesc[Navigation_MsgGpsTimeGnss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgGpsTimeGnss =
  template this: untyped = result
  this = new(Navigation_MsgGpsTimeGnss)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS week number

  ]##
  let wnExpr = this.io.readU2le()
  this.wn = wnExpr

  ##[
  GPS time of week rounded to the nearest millisecond

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Nanosecond residual of millisecond-rounded TOW (ranges from -500000
to 500000)

  ]##
  let nsResidualExpr = this.io.readS4le()
  this.nsResidual = nsResidualExpr

  ##[
  Status flags (reserved)

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgGpsTimeGnss], filename: string): Navigation_MsgGpsTimeGnss =
  Navigation_MsgGpsTimeGnss.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the baseline solution in Earth Centered Earth Fixed
(ECEF) coordinates. This baseline is the relative vector distance from
the base station to the rover receiver. The full GPS time is given by
the preceding MSG_GPS_TIME with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgBaselineEcefDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgBaselineEcefDepA =
  template this: untyped = result
  this = new(Navigation_MsgBaselineEcefDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Baseline ECEF X coordinate

  ]##
  let xExpr = this.io.readS4le()
  this.x = xExpr

  ##[
  Baseline ECEF Y coordinate

  ]##
  let yExpr = this.io.readS4le()
  this.y = yExpr

  ##[
  Baseline ECEF Z coordinate

  ]##
  let zExpr = this.io.readS4le()
  this.z = zExpr

  ##[
  Position accuracy estimate

  ]##
  let accuracyExpr = this.io.readU2le()
  this.accuracy = accuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgBaselineEcefDepA], filename: string): Navigation_MsgBaselineEcefDepA =
  Navigation_MsgBaselineEcefDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
This message reports the GPS time, representing the time since the GPS
epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
and seconds of the week. The weeks begin at the Saturday/Sunday
transition. GPS week 0 began at the beginning of the GPS time scale.

Within each week number, the GPS time of the week is between between 0
and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
leap seconds, and as of now, has a small offset from UTC. In a message
stream, this message precedes a set of other navigation messages
referenced to the same time (but lacking the ns field) and indicates a
more precise time of these messages.

]##
proc read*(_: typedesc[Navigation_MsgGpsTime], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgGpsTime =
  template this: untyped = result
  this = new(Navigation_MsgGpsTime)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS week number

  ]##
  let wnExpr = this.io.readU2le()
  this.wn = wnExpr

  ##[
  GPS time of week rounded to the nearest millisecond

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Nanosecond residual of millisecond-rounded TOW (ranges from -500000
to 500000)

  ]##
  let nsResidualExpr = this.io.readS4le()
  this.nsResidual = nsResidualExpr

  ##[
  Status flags (reserved)

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgGpsTime], filename: string): Navigation_MsgGpsTime =
  Navigation_MsgGpsTime.read(newKaitaiFileStream(filename), nil, nil)


##[
This dilution of precision (DOP) message describes the effect of
navigation satellite geometry on positional measurement precision.  The
flags field indicated whether the DOP reported corresponds to
differential or SPP solution.

]##
proc read*(_: typedesc[Navigation_MsgDops], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgDops =
  template this: untyped = result
  this = new(Navigation_MsgDops)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Geometric Dilution of Precision

  ]##
  let gdopExpr = this.io.readU2le()
  this.gdop = gdopExpr

  ##[
  Position Dilution of Precision

  ]##
  let pdopExpr = this.io.readU2le()
  this.pdop = pdopExpr

  ##[
  Time Dilution of Precision

  ]##
  let tdopExpr = this.io.readU2le()
  this.tdop = tdopExpr

  ##[
  Horizontal Dilution of Precision

  ]##
  let hdopExpr = this.io.readU2le()
  this.hdop = hdopExpr

  ##[
  Vertical Dilution of Precision

  ]##
  let vdopExpr = this.io.readU2le()
  this.vdop = vdopExpr

  ##[
  Indicates the position solution with which the DOPS message
corresponds

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgDops], filename: string): Navigation_MsgDops =
  Navigation_MsgDops.read(newKaitaiFileStream(filename), nil, nil)


##[
The position solution message reports absolute Earth Centered Earth
Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
RTK) of the position solution. If the rover receiver knows the surveyed
position of the base station and has an RTK solution, this reports a
pseudo-absolute position solution using the base station position and
the rover's RTK baseline vector. The full GPS time is given by the
preceding MSG_GPS_TIME with the matching time-of-week (tow).

]##
proc read*(_: typedesc[Navigation_MsgPosEcefDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosEcefDepA =
  template this: untyped = result
  this = new(Navigation_MsgPosEcefDepA)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  ECEF X coordinate

  ]##
  let xExpr = this.io.readF8le()
  this.x = xExpr

  ##[
  ECEF Y coordinate

  ]##
  let yExpr = this.io.readF8le()
  this.y = yExpr

  ##[
  ECEF Z coordinate

  ]##
  let zExpr = this.io.readF8le()
  this.z = zExpr

  ##[
  Position accuracy estimate (not implemented). Defaults to 0.

  ]##
  let accuracyExpr = this.io.readU2le()
  this.accuracy = accuracyExpr

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

proc fromFile*(_: typedesc[Navigation_MsgPosEcefDepA], filename: string): Navigation_MsgPosEcefDepA =
  Navigation_MsgPosEcefDepA.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Navigation_EstimatedHorizontalErrorEllipse], io: KaitaiStream, root: KaitaiStruct, parent: Navigation_MsgPosLlhAcc): Navigation_EstimatedHorizontalErrorEllipse =
  template this: untyped = result
  this = new(Navigation_EstimatedHorizontalErrorEllipse)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  The semi major axis of the estimated horizontal error ellipse at the
user-configured confidence level; zero implies invalid.

  ]##
  let semiMajorExpr = this.io.readF4le()
  this.semiMajor = semiMajorExpr

  ##[
  The semi minor axis of the estimated horizontal error ellipse at the
user-configured confidence level; zero implies invalid.

  ]##
  let semiMinorExpr = this.io.readF4le()
  this.semiMinor = semiMinorExpr

  ##[
  The orientation of the semi major axis of the estimated horizontal
error ellipse with respect to North.

  ]##
  let orientationExpr = this.io.readF4le()
  this.orientation = orientationExpr

proc fromFile*(_: typedesc[Navigation_EstimatedHorizontalErrorEllipse], filename: string): Navigation_EstimatedHorizontalErrorEllipse =
  Navigation_EstimatedHorizontalErrorEllipse.read(newKaitaiFileStream(filename), nil, nil)


##[
This position solution message reports the absolute geodetic coordinates
and the status (single point vs pseudo-absolute RTK) of the position
solution as well as the estimated horizontal, vertical, cross-track and
along-track errors.  The position information and Fix Mode flags  follow
the MSG_POS_LLH message. Since the covariance matrix is computed in the
local-level North, East, Down frame, the estimated error terms follow
that convention.

The estimated errors are reported at a user-configurable confidence
level. The user-configured percentile is encoded in the percentile
field.

]##
proc read*(_: typedesc[Navigation_MsgPosLlhAcc], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Navigation_MsgPosLlhAcc =
  template this: untyped = result
  this = new(Navigation_MsgPosLlhAcc)
  let root = if root == nil: cast[Navigation](this) else: cast[Navigation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS Time of Week

  ]##
  let towExpr = this.io.readU4le()
  this.tow = towExpr

  ##[
  Latitude

  ]##
  let latExpr = this.io.readF8le()
  this.lat = latExpr

  ##[
  Longitude

  ]##
  let lonExpr = this.io.readF8le()
  this.lon = lonExpr

  ##[
  Height above WGS84 ellipsoid

  ]##
  let heightExpr = this.io.readF8le()
  this.height = heightExpr

  ##[
  Height above the geoid (i.e. height above mean sea level). See
confidence_and_geoid for geoid model used.

  ]##
  let orthometricHeightExpr = this.io.readF8le()
  this.orthometricHeight = orthometricHeightExpr

  ##[
  Estimated horizontal error at the user-configured confidence level;
zero implies invalid.

  ]##
  let hAccuracyExpr = this.io.readF4le()
  this.hAccuracy = hAccuracyExpr

  ##[
  Estimated vertical error at the user-configured confidence level;
zero implies invalid.

  ]##
  let vAccuracyExpr = this.io.readF4le()
  this.vAccuracy = vAccuracyExpr

  ##[
  Estimated cross-track error at the user-configured confidence level;
zero implies invalid.

  ]##
  let ctAccuracyExpr = this.io.readF4le()
  this.ctAccuracy = ctAccuracyExpr

  ##[
  Estimated along-track error at the user-configured confidence level;
zero implies invalid.

  ]##
  let atAccuracyExpr = this.io.readF4le()
  this.atAccuracy = atAccuracyExpr

  ##[
  The estimated horizontal error ellipse at the user-configured
confidence level.

  ]##
  let hEllipseExpr = Navigation_EstimatedHorizontalErrorEllipse.read(this.io, this.root, this)
  this.hEllipse = hEllipseExpr

  ##[
  The lower bits describe the configured confidence level for the
estimated position error. The middle bits describe the geoid model
used to calculate the orthometric height.

  ]##
  let confidenceAndGeoidExpr = this.io.readU1()
  this.confidenceAndGeoid = confidenceAndGeoidExpr

  ##[
  Number of satellites used in solution.

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Status flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Navigation_MsgPosLlhAcc], filename: string): Navigation_MsgPosLlhAcc =
  Navigation_MsgPosLlhAcc.read(newKaitaiFileStream(filename), nil, nil)

