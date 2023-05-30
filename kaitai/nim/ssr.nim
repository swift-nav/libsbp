import kaitai_struct_nim_runtime
import options
import gnss

type
  Ssr* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Ssr_GridDefinitionHeaderDepA* = ref object of KaitaiStruct
    `regionSizeInverse`*: uint8
    `areaWidth`*: uint16
    `latNwCornerEnc`*: uint16
    `lonNwCornerEnc`*: uint16
    `numMsgs`*: uint8
    `seqNum`*: uint8
    `parent`*: Ssr_MsgSsrGridDefinitionDepA
  Ssr_StecResidualNoStd* = ref object of KaitaiStruct
    `svId`*: Gnss_SvId
    `residual`*: int16
    `parent`*: Ssr_MsgSsrGriddedCorrectionNoStdDepA
  Ssr_TroposphericDelayCorrectionNoStd* = ref object of KaitaiStruct
    `hydro`*: int16
    `wet`*: int8
    `parent`*: Ssr_MsgSsrGriddedCorrectionNoStdDepA
  Ssr_MsgSsrStecCorrectionDep* = ref object of KaitaiStruct
    `header`*: Ssr_StecHeader
    `stecSatList`*: seq[Ssr_StecSatElement]
    `parent`*: Sbp_Message
  Ssr_StecSatElementIntegrity* = ref object of KaitaiStruct
    `stecResidual`*: Ssr_StecResidual
    `stecBoundMu`*: uint8
    `stecBoundSig`*: uint8
    `stecBoundMuDot`*: uint8
    `stecBoundSigDot`*: uint8
    `parent`*: Ssr_MsgSsrGriddedCorrectionBounds
  Ssr_MsgSsrOrbitClockDepA* = ref object of KaitaiStruct
    `time`*: Gnss_GpsTimeSec
    `sid`*: Gnss_GnssSignal
    `updateInterval`*: uint8
    `iodSsr`*: uint8
    `iod`*: uint8
    `radial`*: int32
    `along`*: int32
    `cross`*: int32
    `dotRadial`*: int32
    `dotAlong`*: int32
    `dotCross`*: int32
    `c0`*: int32
    `c1`*: int32
    `c2`*: int32
    `parent`*: Sbp_Message
  Ssr_MsgSsrStecCorrection* = ref object of KaitaiStruct
    `header`*: Ssr_BoundsHeader
    `ssrIodAtmo`*: uint8
    `tileSetId`*: uint16
    `tileId`*: uint16
    `nSats`*: uint8
    `stecSatList`*: seq[Ssr_StecSatElement]
    `parent`*: Sbp_Message
  Ssr_MsgSsrOrbitClock* = ref object of KaitaiStruct
    `time`*: Gnss_GpsTimeSec
    `sid`*: Gnss_GnssSignal
    `updateInterval`*: uint8
    `iodSsr`*: uint8
    `iod`*: uint32
    `radial`*: int32
    `along`*: int32
    `cross`*: int32
    `dotRadial`*: int32
    `dotAlong`*: int32
    `dotCross`*: int32
    `c0`*: int32
    `c1`*: int32
    `c2`*: int32
    `parent`*: Sbp_Message
  Ssr_BoundsHeader* = ref object of KaitaiStruct
    `time`*: Gnss_GpsTimeSec
    `numMsgs`*: uint8
    `seqNum`*: uint8
    `updateInterval`*: uint8
    `solId`*: uint8
    `parent`*: KaitaiStruct
  Ssr_MsgSsrGriddedCorrection* = ref object of KaitaiStruct
    `header`*: Ssr_GriddedCorrectionHeader
    `index`*: uint16
    `tropoDelayCorrection`*: Ssr_TroposphericDelayCorrection
    `stecResiduals`*: seq[Ssr_StecResidual]
    `parent`*: Sbp_Message
  Ssr_StecResidual* = ref object of KaitaiStruct
    `svId`*: Gnss_SvId
    `residual`*: int16
    `stddev`*: uint8
    `parent`*: KaitaiStruct
  Ssr_CodePhaseBiasesSatSig* = ref object of KaitaiStruct
    `satId`*: uint8
    `signalId`*: uint8
    `codeBiasBoundMu`*: uint8
    `codeBiasBoundSig`*: uint8
    `phaseBiasBoundMu`*: uint8
    `phaseBiasBoundSig`*: uint8
    `parent`*: Ssr_MsgSsrCodePhaseBiasesBounds
  Ssr_SatelliteApc* = ref object of KaitaiStruct
    `sid`*: Gnss_GnssSignal
    `satInfo`*: uint8
    `svn`*: uint16
    `pco`*: seq[int16]
    `pcv`*: seq[int8]
    `parent`*: KaitaiStruct
  Ssr_GriddedCorrectionHeader* = ref object of KaitaiStruct
    `tileSetId`*: uint16
    `tileId`*: uint16
    `time`*: Gnss_GpsTimeSec
    `numMsgs`*: uint16
    `seqNum`*: uint16
    `updateInterval`*: uint8
    `iodAtmo`*: uint8
    `tropoQualityIndicator`*: uint8
    `parent`*: Ssr_MsgSsrGriddedCorrection
  Ssr_StecSatElement* = ref object of KaitaiStruct
    `svId`*: Gnss_SvId
    `stecQualityIndicator`*: uint8
    `stecCoeff`*: seq[int16]
    `parent`*: KaitaiStruct
  Ssr_StecHeaderDepA* = ref object of KaitaiStruct
    `time`*: Gnss_GpsTimeSec
    `numMsgs`*: uint8
    `seqNum`*: uint8
    `updateInterval`*: uint8
    `iodAtmo`*: uint8
    `parent`*: Ssr_MsgSsrStecCorrectionDepA
  Ssr_StecHeader* = ref object of KaitaiStruct
    `tileSetId`*: uint16
    `tileId`*: uint16
    `time`*: Gnss_GpsTimeSec
    `numMsgs`*: uint8
    `seqNum`*: uint8
    `updateInterval`*: uint8
    `iodAtmo`*: uint8
    `parent`*: Ssr_MsgSsrStecCorrectionDep
  Ssr_MsgSsrStecCorrectionDepA* = ref object of KaitaiStruct
    `header`*: Ssr_StecHeaderDepA
    `stecSatList`*: seq[Ssr_StecSatElement]
    `parent`*: Sbp_Message
  Ssr_GriddedCorrectionHeaderDepA* = ref object of KaitaiStruct
    `time`*: Gnss_GpsTimeSec
    `numMsgs`*: uint16
    `seqNum`*: uint16
    `updateInterval`*: uint8
    `iodAtmo`*: uint8
    `tropoQualityIndicator`*: uint8
    `parent`*: KaitaiStruct
  Ssr_MsgSsrOrbitClockBounds* = ref object of KaitaiStruct
    `header`*: Ssr_BoundsHeader
    `ssrIod`*: uint8
    `constId`*: uint8
    `nSats`*: uint8
    `orbitClockBounds`*: seq[Ssr_OrbitClockBound]
    `parent`*: Sbp_Message
  Ssr_MsgSsrGriddedCorrectionBounds* = ref object of KaitaiStruct
    `header`*: Ssr_BoundsHeader
    `ssrIodAtmo`*: uint8
    `tileSetId`*: uint16
    `tileId`*: uint16
    `tropoQi`*: uint8
    `gridPointId`*: uint16
    `tropoDelayCorrection`*: Ssr_TroposphericDelayCorrection
    `tropoVHydroBoundMu`*: uint8
    `tropoVHydroBoundSig`*: uint8
    `tropoVWetBoundMu`*: uint8
    `tropoVWetBoundSig`*: uint8
    `nSats`*: uint8
    `stecSatList`*: seq[Ssr_StecSatElementIntegrity]
    `parent`*: Sbp_Message
  Ssr_MsgSsrGridDefinitionDepA* = ref object of KaitaiStruct
    `header`*: Ssr_GridDefinitionHeaderDepA
    `rleList`*: seq[uint8]
    `parent`*: Sbp_Message
  Ssr_CodeBiasesContent* = ref object of KaitaiStruct
    `code`*: uint8
    `value`*: int16
    `parent`*: Ssr_MsgSsrCodeBiases
  Ssr_MsgSsrSatelliteApc* = ref object of KaitaiStruct
    `time`*: Gnss_GpsTimeSec
    `updateInterval`*: uint8
    `solId`*: uint8
    `iodSsr`*: uint8
    `apc`*: seq[Ssr_SatelliteApc]
    `parent`*: Sbp_Message
  Ssr_PhaseBiasesContent* = ref object of KaitaiStruct
    `code`*: uint8
    `integerIndicator`*: uint8
    `widelaneIntegerIndicator`*: uint8
    `discontinuityCounter`*: uint8
    `bias`*: int32
    `parent`*: Ssr_MsgSsrPhaseBiases
  Ssr_MsgSsrTileDefinitionDepA* = ref object of KaitaiStruct
    `tileSetId`*: uint16
    `tileId`*: uint16
    `cornerNwLat`*: int16
    `cornerNwLon`*: int16
    `spacingLat`*: uint16
    `spacingLon`*: uint16
    `rows`*: uint16
    `cols`*: uint16
    `bitmask`*: uint64
    `parent`*: Sbp_Message
  Ssr_OrbitClockBound* = ref object of KaitaiStruct
    `satId`*: uint8
    `orbRadialBoundMu`*: uint8
    `orbAlongBoundMu`*: uint8
    `orbCrossBoundMu`*: uint8
    `orbRadialBoundSig`*: uint8
    `orbAlongBoundSig`*: uint8
    `orbCrossBoundSig`*: uint8
    `clockBoundMu`*: uint8
    `clockBoundSig`*: uint8
    `parent`*: Ssr_MsgSsrOrbitClockBounds
  Ssr_MsgSsrGriddedCorrectionDepA* = ref object of KaitaiStruct
    `header`*: Ssr_GriddedCorrectionHeaderDepA
    `index`*: uint16
    `tropoDelayCorrection`*: Ssr_TroposphericDelayCorrection
    `stecResiduals`*: seq[Ssr_StecResidual]
    `parent`*: Sbp_Message
  Ssr_MsgSsrOrbitClockBoundsDegradation* = ref object of KaitaiStruct
    `header`*: Ssr_BoundsHeader
    `ssrIod`*: uint8
    `constId`*: uint8
    `satBitmask`*: uint64
    `orbitClockBoundsDegradation`*: Ssr_OrbitClockBoundDegradation
    `parent`*: Sbp_Message
  Ssr_MsgSsrGriddedCorrectionNoStdDepA* = ref object of KaitaiStruct
    `header`*: Ssr_GriddedCorrectionHeaderDepA
    `index`*: uint16
    `tropoDelayCorrection`*: Ssr_TroposphericDelayCorrectionNoStd
    `stecResiduals`*: seq[Ssr_StecResidualNoStd]
    `parent`*: Sbp_Message
  Ssr_MsgSsrCodePhaseBiasesBounds* = ref object of KaitaiStruct
    `header`*: Ssr_BoundsHeader
    `ssrIod`*: uint8
    `constId`*: uint8
    `nSatsSignals`*: uint8
    `satellitesSignals`*: seq[Ssr_CodePhaseBiasesSatSig]
    `parent`*: Sbp_Message
  Ssr_MsgSsrCodeBiases* = ref object of KaitaiStruct
    `time`*: Gnss_GpsTimeSec
    `sid`*: Gnss_GnssSignal
    `updateInterval`*: uint8
    `iodSsr`*: uint8
    `biases`*: seq[Ssr_CodeBiasesContent]
    `parent`*: Sbp_Message
  Ssr_MsgSsrTileDefinition* = ref object of KaitaiStruct
    `time`*: Gnss_GpsTimeSec
    `updateInterval`*: uint8
    `solId`*: uint8
    `iodAtmo`*: uint8
    `tileSetId`*: uint16
    `tileId`*: uint16
    `cornerNwLat`*: int16
    `cornerNwLon`*: int16
    `spacingLat`*: uint16
    `spacingLon`*: uint16
    `rows`*: uint16
    `cols`*: uint16
    `bitmask`*: uint64
    `parent`*: Sbp_Message
  Ssr_OrbitClockBoundDegradation* = ref object of KaitaiStruct
    `orbRadialBoundMuDot`*: uint8
    `orbAlongBoundMuDot`*: uint8
    `orbCrossBoundMuDot`*: uint8
    `orbRadialBoundSigDot`*: uint8
    `orbAlongBoundSigDot`*: uint8
    `orbCrossBoundSigDot`*: uint8
    `clockBoundMuDot`*: uint8
    `clockBoundSigDot`*: uint8
    `parent`*: Ssr_MsgSsrOrbitClockBoundsDegradation
  Ssr_MsgSsrSatelliteApcDep* = ref object of KaitaiStruct
    `apc`*: seq[Ssr_SatelliteApc]
    `parent`*: Sbp_Message
  Ssr_TroposphericDelayCorrection* = ref object of KaitaiStruct
    `hydro`*: int16
    `wet`*: int8
    `stddev`*: uint8
    `parent`*: KaitaiStruct
  Ssr_MsgSsrTileDefinitionDepB* = ref object of KaitaiStruct
    `ssrSolId`*: uint8
    `tileSetId`*: uint16
    `tileId`*: uint16
    `cornerNwLat`*: int16
    `cornerNwLon`*: int16
    `spacingLat`*: uint16
    `spacingLon`*: uint16
    `rows`*: uint16
    `cols`*: uint16
    `bitmask`*: uint64
    `parent`*: Sbp_Message
  Ssr_MsgSsrPhaseBiases* = ref object of KaitaiStruct
    `time`*: Gnss_GpsTimeSec
    `sid`*: Gnss_GnssSignal
    `updateInterval`*: uint8
    `iodSsr`*: uint8
    `dispersiveBias`*: uint8
    `mwConsistency`*: uint8
    `yaw`*: uint16
    `yawRate`*: int8
    `biases`*: seq[Ssr_PhaseBiasesContent]
    `parent`*: Sbp_Message

proc read*(_: typedesc[Ssr], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr
proc read*(_: typedesc[Ssr_GridDefinitionHeaderDepA], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGridDefinitionDepA): Ssr_GridDefinitionHeaderDepA
proc read*(_: typedesc[Ssr_StecResidualNoStd], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGriddedCorrectionNoStdDepA): Ssr_StecResidualNoStd
proc read*(_: typedesc[Ssr_TroposphericDelayCorrectionNoStd], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGriddedCorrectionNoStdDepA): Ssr_TroposphericDelayCorrectionNoStd
proc read*(_: typedesc[Ssr_MsgSsrStecCorrectionDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrStecCorrectionDep
proc read*(_: typedesc[Ssr_StecSatElementIntegrity], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGriddedCorrectionBounds): Ssr_StecSatElementIntegrity
proc read*(_: typedesc[Ssr_MsgSsrOrbitClockDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrOrbitClockDepA
proc read*(_: typedesc[Ssr_MsgSsrStecCorrection], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrStecCorrection
proc read*(_: typedesc[Ssr_MsgSsrOrbitClock], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrOrbitClock
proc read*(_: typedesc[Ssr_BoundsHeader], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_BoundsHeader
proc read*(_: typedesc[Ssr_MsgSsrGriddedCorrection], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGriddedCorrection
proc read*(_: typedesc[Ssr_StecResidual], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_StecResidual
proc read*(_: typedesc[Ssr_CodePhaseBiasesSatSig], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrCodePhaseBiasesBounds): Ssr_CodePhaseBiasesSatSig
proc read*(_: typedesc[Ssr_SatelliteApc], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_SatelliteApc
proc read*(_: typedesc[Ssr_GriddedCorrectionHeader], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGriddedCorrection): Ssr_GriddedCorrectionHeader
proc read*(_: typedesc[Ssr_StecSatElement], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_StecSatElement
proc read*(_: typedesc[Ssr_StecHeaderDepA], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrStecCorrectionDepA): Ssr_StecHeaderDepA
proc read*(_: typedesc[Ssr_StecHeader], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrStecCorrectionDep): Ssr_StecHeader
proc read*(_: typedesc[Ssr_MsgSsrStecCorrectionDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrStecCorrectionDepA
proc read*(_: typedesc[Ssr_GriddedCorrectionHeaderDepA], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_GriddedCorrectionHeaderDepA
proc read*(_: typedesc[Ssr_MsgSsrOrbitClockBounds], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrOrbitClockBounds
proc read*(_: typedesc[Ssr_MsgSsrGriddedCorrectionBounds], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGriddedCorrectionBounds
proc read*(_: typedesc[Ssr_MsgSsrGridDefinitionDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGridDefinitionDepA
proc read*(_: typedesc[Ssr_CodeBiasesContent], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrCodeBiases): Ssr_CodeBiasesContent
proc read*(_: typedesc[Ssr_MsgSsrSatelliteApc], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrSatelliteApc
proc read*(_: typedesc[Ssr_PhaseBiasesContent], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrPhaseBiases): Ssr_PhaseBiasesContent
proc read*(_: typedesc[Ssr_MsgSsrTileDefinitionDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrTileDefinitionDepA
proc read*(_: typedesc[Ssr_OrbitClockBound], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrOrbitClockBounds): Ssr_OrbitClockBound
proc read*(_: typedesc[Ssr_MsgSsrGriddedCorrectionDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGriddedCorrectionDepA
proc read*(_: typedesc[Ssr_MsgSsrOrbitClockBoundsDegradation], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrOrbitClockBoundsDegradation
proc read*(_: typedesc[Ssr_MsgSsrGriddedCorrectionNoStdDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGriddedCorrectionNoStdDepA
proc read*(_: typedesc[Ssr_MsgSsrCodePhaseBiasesBounds], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrCodePhaseBiasesBounds
proc read*(_: typedesc[Ssr_MsgSsrCodeBiases], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrCodeBiases
proc read*(_: typedesc[Ssr_MsgSsrTileDefinition], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrTileDefinition
proc read*(_: typedesc[Ssr_OrbitClockBoundDegradation], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrOrbitClockBoundsDegradation): Ssr_OrbitClockBoundDegradation
proc read*(_: typedesc[Ssr_MsgSsrSatelliteApcDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrSatelliteApcDep
proc read*(_: typedesc[Ssr_TroposphericDelayCorrection], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_TroposphericDelayCorrection
proc read*(_: typedesc[Ssr_MsgSsrTileDefinitionDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrTileDefinitionDepB
proc read*(_: typedesc[Ssr_MsgSsrPhaseBiases], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrPhaseBiases


proc read*(_: typedesc[Ssr], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr =
  template this: untyped = result
  this = new(Ssr)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Ssr], filename: string): Ssr =
  Ssr.read(newKaitaiFileStream(filename), nil, nil)


##[
Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
an RLE encoded validity list.

]##
proc read*(_: typedesc[Ssr_GridDefinitionHeaderDepA], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGridDefinitionDepA): Ssr_GridDefinitionHeaderDepA =
  template this: untyped = result
  this = new(Ssr_GridDefinitionHeaderDepA)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  region_size (deg) = 10 / region_size_inverse 0 is an invalid value.

  ]##
  let regionSizeInverseExpr = this.io.readU1()
  this.regionSizeInverse = regionSizeInverseExpr

  ##[
  grid height (deg) = grid width (deg) = area_width / region_size 0 is
an invalid value.

  ]##
  let areaWidthExpr = this.io.readU2le()
  this.areaWidth = areaWidthExpr

  ##[
  North-West corner latitude (deg) = region_size * lat_nw_corner_enc -
90

  ]##
  let latNwCornerEncExpr = this.io.readU2le()
  this.latNwCornerEnc = latNwCornerEncExpr

  ##[
  North-West corner longitude (deg) = region_size * lon_nw_corner_enc
- 180

  ]##
  let lonNwCornerEncExpr = this.io.readU2le()
  this.lonNwCornerEnc = lonNwCornerEncExpr

  ##[
  Number of messages in the dataset

  ]##
  let numMsgsExpr = this.io.readU1()
  this.numMsgs = numMsgsExpr

  ##[
  Position of this message in the dataset

  ]##
  let seqNumExpr = this.io.readU1()
  this.seqNum = seqNumExpr

proc fromFile*(_: typedesc[Ssr_GridDefinitionHeaderDepA], filename: string): Ssr_GridDefinitionHeaderDepA =
  Ssr_GridDefinitionHeaderDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
STEC residual for the given satellite at the grid point.

]##
proc read*(_: typedesc[Ssr_StecResidualNoStd], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGriddedCorrectionNoStdDepA): Ssr_StecResidualNoStd =
  template this: untyped = result
  this = new(Ssr_StecResidualNoStd)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  space vehicle identifier

  ]##
  let svIdExpr = Gnss_SvId.read(this.io, this.root, this)
  this.svId = svIdExpr

  ##[
  STEC residual

  ]##
  let residualExpr = this.io.readS2le()
  this.residual = residualExpr

proc fromFile*(_: typedesc[Ssr_StecResidualNoStd], filename: string): Ssr_StecResidualNoStd =
  Ssr_StecResidualNoStd.read(newKaitaiFileStream(filename), nil, nil)


##[
Troposphere vertical delays at the grid point.

]##
proc read*(_: typedesc[Ssr_TroposphericDelayCorrectionNoStd], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGriddedCorrectionNoStdDepA): Ssr_TroposphericDelayCorrectionNoStd =
  template this: untyped = result
  this = new(Ssr_TroposphericDelayCorrectionNoStd)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Hydrostatic vertical delay

  ]##
  let hydroExpr = this.io.readS2le()
  this.hydro = hydroExpr

  ##[
  Wet vertical delay

  ]##
  let wetExpr = this.io.readS1()
  this.wet = wetExpr

proc fromFile*(_: typedesc[Ssr_TroposphericDelayCorrectionNoStd], filename: string): Ssr_TroposphericDelayCorrectionNoStd =
  Ssr_TroposphericDelayCorrectionNoStd.read(newKaitaiFileStream(filename), nil, nil)


##[
The Slant Total Electron Content per space vehicle, given as polynomial
approximation for a given tile. This should be combined with the
MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
of the atmospheric delay.

It is typically equivalent to the QZSS CLAS Sub Type 8 messages.

]##
proc read*(_: typedesc[Ssr_MsgSsrStecCorrectionDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrStecCorrectionDep =
  template this: untyped = result
  this = new(Ssr_MsgSsrStecCorrectionDep)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a STEC polynomial coefficient message.

  ]##
  let headerExpr = Ssr_StecHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Array of STEC polynomial coefficients for each space vehicle.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_StecSatElement.read(this.io, this.root, this)
      this.stecSatList.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrStecCorrectionDep], filename: string): Ssr_MsgSsrStecCorrectionDep =
  Ssr_MsgSsrStecCorrectionDep.read(newKaitaiFileStream(filename), nil, nil)


##[
STEC polynomial and bounds for the given satellite.

]##
proc read*(_: typedesc[Ssr_StecSatElementIntegrity], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGriddedCorrectionBounds): Ssr_StecSatElementIntegrity =
  template this: untyped = result
  this = new(Ssr_StecSatElementIntegrity)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  STEC residuals (mean, stddev)

  ]##
  let stecResidualExpr = Ssr_StecResidual.read(this.io, this.root, this)
  this.stecResidual = stecResidualExpr

  ##[
  Error Bound Mean. See Note 1.

  ]##
  let stecBoundMuExpr = this.io.readU1()
  this.stecBoundMu = stecBoundMuExpr

  ##[
  Error Bound StDev. See Note 1.

  ]##
  let stecBoundSigExpr = this.io.readU1()
  this.stecBoundSig = stecBoundSigExpr

  ##[
  Error Bound Mean First derivative.

  ]##
  let stecBoundMuDotExpr = this.io.readU1()
  this.stecBoundMuDot = stecBoundMuDotExpr

  ##[
  Error Bound StDev First derivative.

  ]##
  let stecBoundSigDotExpr = this.io.readU1()
  this.stecBoundSigDot = stecBoundSigDotExpr

proc fromFile*(_: typedesc[Ssr_StecSatElementIntegrity], filename: string): Ssr_StecSatElementIntegrity =
  Ssr_StecSatElementIntegrity.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrOrbitClockDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrOrbitClockDepA =
  template this: untyped = result
  this = new(Ssr_MsgSsrOrbitClockDepA)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  IOD of the SSR correction. A change of Issue Of Data SSR is used to
indicate a change in the SSR generating configuration

  ]##
  let iodSsrExpr = this.io.readU1()
  this.iodSsr = iodSsrExpr

  ##[
  Issue of broadcast ephemeris data

  ]##
  let iodExpr = this.io.readU1()
  this.iod = iodExpr

  ##[
  Orbit radial delta correction

  ]##
  let radialExpr = this.io.readS4le()
  this.radial = radialExpr

  ##[
  Orbit along delta correction

  ]##
  let alongExpr = this.io.readS4le()
  this.along = alongExpr

  ##[
  Orbit along delta correction

  ]##
  let crossExpr = this.io.readS4le()
  this.cross = crossExpr

  ##[
  Velocity of orbit radial delta correction

  ]##
  let dotRadialExpr = this.io.readS4le()
  this.dotRadial = dotRadialExpr

  ##[
  Velocity of orbit along delta correction

  ]##
  let dotAlongExpr = this.io.readS4le()
  this.dotAlong = dotAlongExpr

  ##[
  Velocity of orbit cross delta correction

  ]##
  let dotCrossExpr = this.io.readS4le()
  this.dotCross = dotCrossExpr

  ##[
  C0 polynomial coefficient for correction of broadcast satellite
clock

  ]##
  let c0Expr = this.io.readS4le()
  this.c0 = c0Expr

  ##[
  C1 polynomial coefficient for correction of broadcast satellite
clock

  ]##
  let c1Expr = this.io.readS4le()
  this.c1 = c1Expr

  ##[
  C2 polynomial coefficient for correction of broadcast satellite
clock

  ]##
  let c2Expr = this.io.readS4le()
  this.c2 = c2Expr

proc fromFile*(_: typedesc[Ssr_MsgSsrOrbitClockDepA], filename: string): Ssr_MsgSsrOrbitClockDepA =
  Ssr_MsgSsrOrbitClockDepA.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrStecCorrection], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrStecCorrection =
  template this: untyped = result
  this = new(Ssr_MsgSsrStecCorrection)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a STEC correction with bounds message.

  ]##
  let headerExpr = Ssr_BoundsHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  IOD of the SSR atmospheric correction

  ]##
  let ssrIodAtmoExpr = this.io.readU1()
  this.ssrIodAtmo = ssrIodAtmoExpr

  ##[
  Tile set ID

  ]##
  let tileSetIdExpr = this.io.readU2le()
  this.tileSetId = tileSetIdExpr

  ##[
  Tile ID

  ]##
  let tileIdExpr = this.io.readU2le()
  this.tileId = tileIdExpr

  ##[
  Number of satellites.

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Array of STEC polynomial coefficients for each space vehicle.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_StecSatElement.read(this.io, this.root, this)
      this.stecSatList.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrStecCorrection], filename: string): Ssr_MsgSsrStecCorrection =
  Ssr_MsgSsrStecCorrection.read(newKaitaiFileStream(filename), nil, nil)


##[
The precise orbit and clock correction message is to be applied as a
delta correction to broadcast ephemeris and is an equivalent to the 1060
/1066 RTCM message types.

]##
proc read*(_: typedesc[Ssr_MsgSsrOrbitClock], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrOrbitClock =
  template this: untyped = result
  this = new(Ssr_MsgSsrOrbitClock)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  IOD of the SSR correction. A change of Issue Of Data SSR is used to
indicate a change in the SSR generating configuration

  ]##
  let iodSsrExpr = this.io.readU1()
  this.iodSsr = iodSsrExpr

  ##[
  Issue of broadcast ephemeris data or IODCRC (Beidou)

  ]##
  let iodExpr = this.io.readU4le()
  this.iod = iodExpr

  ##[
  Orbit radial delta correction

  ]##
  let radialExpr = this.io.readS4le()
  this.radial = radialExpr

  ##[
  Orbit along delta correction

  ]##
  let alongExpr = this.io.readS4le()
  this.along = alongExpr

  ##[
  Orbit along delta correction

  ]##
  let crossExpr = this.io.readS4le()
  this.cross = crossExpr

  ##[
  Velocity of orbit radial delta correction

  ]##
  let dotRadialExpr = this.io.readS4le()
  this.dotRadial = dotRadialExpr

  ##[
  Velocity of orbit along delta correction

  ]##
  let dotAlongExpr = this.io.readS4le()
  this.dotAlong = dotAlongExpr

  ##[
  Velocity of orbit cross delta correction

  ]##
  let dotCrossExpr = this.io.readS4le()
  this.dotCross = dotCrossExpr

  ##[
  C0 polynomial coefficient for correction of broadcast satellite
clock

  ]##
  let c0Expr = this.io.readS4le()
  this.c0 = c0Expr

  ##[
  C1 polynomial coefficient for correction of broadcast satellite
clock

  ]##
  let c1Expr = this.io.readS4le()
  this.c1 = c1Expr

  ##[
  C2 polynomial coefficient for correction of broadcast satellite
clock

  ]##
  let c2Expr = this.io.readS4le()
  this.c2 = c2Expr

proc fromFile*(_: typedesc[Ssr_MsgSsrOrbitClock], filename: string): Ssr_MsgSsrOrbitClock =
  Ssr_MsgSsrOrbitClock.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_BoundsHeader], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_BoundsHeader =
  template this: untyped = result
  this = new(Ssr_BoundsHeader)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the bound

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  Number of messages in the dataset

  ]##
  let numMsgsExpr = this.io.readU1()
  this.numMsgs = numMsgsExpr

  ##[
  Position of this message in the dataset

  ]##
  let seqNumExpr = this.io.readU1()
  this.seqNum = seqNumExpr

  ##[
  Update interval between consecutive bounds. Similar to RTCM DF391.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  SSR Solution ID.

  ]##
  let solIdExpr = this.io.readU1()
  this.solId = solIdExpr

proc fromFile*(_: typedesc[Ssr_BoundsHeader], filename: string): Ssr_BoundsHeader =
  Ssr_BoundsHeader.read(newKaitaiFileStream(filename), nil, nil)


##[
STEC residuals are per space vehicle, troposphere is not.

It is typically equivalent to the QZSS CLAS Sub Type 9 messages.

]##
proc read*(_: typedesc[Ssr_MsgSsrGriddedCorrection], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGriddedCorrection =
  template this: untyped = result
  this = new(Ssr_MsgSsrGriddedCorrection)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a gridded correction message

  ]##
  let headerExpr = Ssr_GriddedCorrectionHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Index of the grid point.

  ]##
  let indexExpr = this.io.readU2le()
  this.index = indexExpr

  ##[
  Wet and hydrostatic vertical delays (mean, stddev).

  ]##
  let tropoDelayCorrectionExpr = Ssr_TroposphericDelayCorrection.read(this.io, this.root, this)
  this.tropoDelayCorrection = tropoDelayCorrectionExpr

  ##[
  STEC residuals for each satellite (mean, stddev).

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_StecResidual.read(this.io, this.root, this)
      this.stecResiduals.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrGriddedCorrection], filename: string): Ssr_MsgSsrGriddedCorrection =
  Ssr_MsgSsrGriddedCorrection.read(newKaitaiFileStream(filename), nil, nil)


##[
STEC residual (mean and standard deviation) for the given satellite at
the grid point.

]##
proc read*(_: typedesc[Ssr_StecResidual], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_StecResidual =
  template this: untyped = result
  this = new(Ssr_StecResidual)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  space vehicle identifier

  ]##
  let svIdExpr = Gnss_SvId.read(this.io, this.root, this)
  this.svId = svIdExpr

  ##[
  STEC residual

  ]##
  let residualExpr = this.io.readS2le()
  this.residual = residualExpr

  ##[
  Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
value/16) - 1) * 10

  ]##
  let stddevExpr = this.io.readU1()
  this.stddev = stddevExpr

proc fromFile*(_: typedesc[Ssr_StecResidual], filename: string): Ssr_StecResidual =
  Ssr_StecResidual.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_CodePhaseBiasesSatSig], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrCodePhaseBiasesBounds): Ssr_CodePhaseBiasesSatSig =
  template this: untyped = result
  this = new(Ssr_CodePhaseBiasesSatSig)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
or DF488 (BDS) depending on the constellation.

  ]##
  let satIdExpr = this.io.readU1()
  this.satId = satIdExpr

  ##[
  Signal and Tracking Mode Identifier. Similar to either RTCM DF380
(GPS), DF382 (Galileo) or DF467 (BDS) depending on the
constellation.

  ]##
  let signalIdExpr = this.io.readU1()
  this.signalId = signalIdExpr

  ##[
  Code Bias Mean. Range: 0-1.275 m

  ]##
  let codeBiasBoundMuExpr = this.io.readU1()
  this.codeBiasBoundMu = codeBiasBoundMuExpr

  ##[
  Code Bias Standard Deviation.  Range: 0-1.275 m

  ]##
  let codeBiasBoundSigExpr = this.io.readU1()
  this.codeBiasBoundSig = codeBiasBoundSigExpr

  ##[
  Phase Bias Mean. Range: 0-1.275 m

  ]##
  let phaseBiasBoundMuExpr = this.io.readU1()
  this.phaseBiasBoundMu = phaseBiasBoundMuExpr

  ##[
  Phase Bias Standard Deviation.  Range: 0-1.275 m

  ]##
  let phaseBiasBoundSigExpr = this.io.readU1()
  this.phaseBiasBoundSig = phaseBiasBoundSigExpr

proc fromFile*(_: typedesc[Ssr_CodePhaseBiasesSatSig], filename: string): Ssr_CodePhaseBiasesSatSig =
  Ssr_CodePhaseBiasesSatSig.read(newKaitaiFileStream(filename), nil, nil)


##[
Contains phase center offset and elevation variation corrections for one
signal on a satellite.

]##
proc read*(_: typedesc[Ssr_SatelliteApc], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_SatelliteApc =
  template this: untyped = result
  this = new(Ssr_SatelliteApc)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Additional satellite information

  ]##
  let satInfoExpr = this.io.readU1()
  this.satInfo = satInfoExpr

  ##[
  Satellite Code, as defined by IGS. Typically the space vehicle
number.

  ]##
  let svnExpr = this.io.readU2le()
  this.svn = svnExpr

  ##[
  Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
description for coordinate system definition.

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readS2le()
    this.pco.add(it)

  ##[
  Elevation dependent phase center variations. First element is 0
degrees separation from the Z axis, subsequent elements represent
elevation variations in 1 degree increments.

  ]##
  for i in 0 ..< int(21):
    let it = this.io.readS1()
    this.pcv.add(it)

proc fromFile*(_: typedesc[Ssr_SatelliteApc], filename: string): Ssr_SatelliteApc =
  Ssr_SatelliteApc.read(newKaitaiFileStream(filename), nil, nil)


##[
The LPP message contains nested variable length arrays which are not
supported in SBP, so each grid point will be identified by the index.

]##
proc read*(_: typedesc[Ssr_GriddedCorrectionHeader], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrGriddedCorrection): Ssr_GriddedCorrectionHeader =
  template this: untyped = result
  this = new(Ssr_GriddedCorrectionHeader)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Unique identifier of the tile set this tile belongs to.

  ]##
  let tileSetIdExpr = this.io.readU2le()
  this.tileSetId = tileSetIdExpr

  ##[
  Unique identifier of this tile in the tile set.

  ]##
  let tileIdExpr = this.io.readU2le()
  this.tileId = tileIdExpr

  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  Number of messages in the dataset

  ]##
  let numMsgsExpr = this.io.readU2le()
  this.numMsgs = numMsgsExpr

  ##[
  Position of this message in the dataset

  ]##
  let seqNumExpr = this.io.readU2le()
  this.seqNum = seqNumExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  IOD of the SSR atmospheric correction

  ]##
  let iodAtmoExpr = this.io.readU1()
  this.iodAtmo = iodAtmoExpr

  ##[
  Quality of the troposphere data. Encoded following RTCM DF389
specification in units of m.

  ]##
  let tropoQualityIndicatorExpr = this.io.readU1()
  this.tropoQualityIndicator = tropoQualityIndicatorExpr

proc fromFile*(_: typedesc[Ssr_GriddedCorrectionHeader], filename: string): Ssr_GriddedCorrectionHeader =
  Ssr_GriddedCorrectionHeader.read(newKaitaiFileStream(filename), nil, nil)


##[
STEC polynomial for the given satellite.

]##
proc read*(_: typedesc[Ssr_StecSatElement], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_StecSatElement =
  template this: untyped = result
  this = new(Ssr_StecSatElement)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Unique space vehicle identifier

  ]##
  let svIdExpr = Gnss_SvId.read(this.io, this.root, this)
  this.svId = svIdExpr

  ##[
  Quality of the STEC data. Encoded following RTCM DF389 specification
but in units of TECU instead of m.

  ]##
  let stecQualityIndicatorExpr = this.io.readU1()
  this.stecQualityIndicator = stecQualityIndicatorExpr

  ##[
  Coefficients of the STEC polynomial in the order of C00, C01, C10,
C11. C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2

  ]##
  for i in 0 ..< int(4):
    let it = this.io.readS2le()
    this.stecCoeff.add(it)

proc fromFile*(_: typedesc[Ssr_StecSatElement], filename: string): Ssr_StecSatElement =
  Ssr_StecSatElement.read(newKaitaiFileStream(filename), nil, nil)


##[
A full set of STEC information will likely span multiple SBP messages,
since SBP message a limited to 255 bytes.  The header is used to tie
multiple SBP messages into a sequence.

]##
proc read*(_: typedesc[Ssr_StecHeaderDepA], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrStecCorrectionDepA): Ssr_StecHeaderDepA =
  template this: untyped = result
  this = new(Ssr_StecHeaderDepA)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  Number of messages in the dataset

  ]##
  let numMsgsExpr = this.io.readU1()
  this.numMsgs = numMsgsExpr

  ##[
  Position of this message in the dataset

  ]##
  let seqNumExpr = this.io.readU1()
  this.seqNum = seqNumExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  IOD of the SSR atmospheric correction

  ]##
  let iodAtmoExpr = this.io.readU1()
  this.iodAtmo = iodAtmoExpr

proc fromFile*(_: typedesc[Ssr_StecHeaderDepA], filename: string): Ssr_StecHeaderDepA =
  Ssr_StecHeaderDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
A full set of STEC information will likely span multiple SBP messages,
since SBP message a limited to 255 bytes.  The header is used to tie
multiple SBP messages into a sequence.

]##
proc read*(_: typedesc[Ssr_StecHeader], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrStecCorrectionDep): Ssr_StecHeader =
  template this: untyped = result
  this = new(Ssr_StecHeader)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Unique identifier of the tile set this tile belongs to.

  ]##
  let tileSetIdExpr = this.io.readU2le()
  this.tileSetId = tileSetIdExpr

  ##[
  Unique identifier of this tile in the tile set.

  ]##
  let tileIdExpr = this.io.readU2le()
  this.tileId = tileIdExpr

  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  Number of messages in the dataset

  ]##
  let numMsgsExpr = this.io.readU1()
  this.numMsgs = numMsgsExpr

  ##[
  Position of this message in the dataset

  ]##
  let seqNumExpr = this.io.readU1()
  this.seqNum = seqNumExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  IOD of the SSR atmospheric correction

  ]##
  let iodAtmoExpr = this.io.readU1()
  this.iodAtmo = iodAtmoExpr

proc fromFile*(_: typedesc[Ssr_StecHeader], filename: string): Ssr_StecHeader =
  Ssr_StecHeader.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrStecCorrectionDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrStecCorrectionDepA =
  template this: untyped = result
  this = new(Ssr_MsgSsrStecCorrectionDepA)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a STEC message

  ]##
  let headerExpr = Ssr_StecHeaderDepA.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Array of STEC information for each space vehicle

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_StecSatElement.read(this.io, this.root, this)
      this.stecSatList.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrStecCorrectionDepA], filename: string): Ssr_MsgSsrStecCorrectionDepA =
  Ssr_MsgSsrStecCorrectionDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
The 3GPP message contains nested variable length arrays which are not
supported in SBP, so each grid point will be identified by the index.

]##
proc read*(_: typedesc[Ssr_GriddedCorrectionHeaderDepA], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_GriddedCorrectionHeaderDepA =
  template this: untyped = result
  this = new(Ssr_GriddedCorrectionHeaderDepA)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  Number of messages in the dataset

  ]##
  let numMsgsExpr = this.io.readU2le()
  this.numMsgs = numMsgsExpr

  ##[
  Position of this message in the dataset

  ]##
  let seqNumExpr = this.io.readU2le()
  this.seqNum = seqNumExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  IOD of the SSR atmospheric correction

  ]##
  let iodAtmoExpr = this.io.readU1()
  this.iodAtmo = iodAtmoExpr

  ##[
  Quality of the troposphere data. Encoded following RTCM DF389
specification in units of m.

  ]##
  let tropoQualityIndicatorExpr = this.io.readU1()
  this.tropoQualityIndicator = tropoQualityIndicatorExpr

proc fromFile*(_: typedesc[Ssr_GriddedCorrectionHeaderDepA], filename: string): Ssr_GriddedCorrectionHeaderDepA =
  Ssr_GriddedCorrectionHeaderDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230,
mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).

Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
i>230, std=5+0.5(i-230).

]##
proc read*(_: typedesc[Ssr_MsgSsrOrbitClockBounds], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrOrbitClockBounds =
  template this: untyped = result
  this = new(Ssr_MsgSsrOrbitClockBounds)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a bounds message.

  ]##
  let headerExpr = Ssr_BoundsHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  IOD of the SSR bound.

  ]##
  let ssrIodExpr = this.io.readU1()
  this.ssrIod = ssrIodExpr

  ##[
  Constellation ID to which the SVs belong.

  ]##
  let constIdExpr = this.io.readU1()
  this.constId = constIdExpr

  ##[
  Number of satellites.

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Orbit and Clock Bounds per Satellite

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_OrbitClockBound.read(this.io, this.root, this)
      this.orbitClockBounds.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrOrbitClockBounds], filename: string): Ssr_MsgSsrOrbitClockBounds =
  Ssr_MsgSsrOrbitClockBounds.read(newKaitaiFileStream(filename), nil, nil)


##[
Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).

]##
proc read*(_: typedesc[Ssr_MsgSsrGriddedCorrectionBounds], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGriddedCorrectionBounds =
  template this: untyped = result
  this = new(Ssr_MsgSsrGriddedCorrectionBounds)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a bounds message.

  ]##
  let headerExpr = Ssr_BoundsHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  IOD of the correction.

  ]##
  let ssrIodAtmoExpr = this.io.readU1()
  this.ssrIodAtmo = ssrIodAtmoExpr

  ##[
  Set this tile belongs to.

  ]##
  let tileSetIdExpr = this.io.readU2le()
  this.tileSetId = tileSetIdExpr

  ##[
  Unique identifier of this tile in the tile set.

  ]##
  let tileIdExpr = this.io.readU2le()
  this.tileId = tileIdExpr

  ##[
  Tropo Quality Indicator. Similar to RTCM DF389.

  ]##
  let tropoQiExpr = this.io.readU1()
  this.tropoQi = tropoQiExpr

  ##[
  Index of the Grid Point.

  ]##
  let gridPointIdExpr = this.io.readU2le()
  this.gridPointId = gridPointIdExpr

  ##[
  Tropospheric delay at grid point.

  ]##
  let tropoDelayCorrectionExpr = Ssr_TroposphericDelayCorrection.read(this.io, this.root, this)
  this.tropoDelayCorrection = tropoDelayCorrectionExpr

  ##[
  Vertical Hydrostatic Error Bound Mean.

  ]##
  let tropoVHydroBoundMuExpr = this.io.readU1()
  this.tropoVHydroBoundMu = tropoVHydroBoundMuExpr

  ##[
  Vertical Hydrostatic Error Bound StDev.

  ]##
  let tropoVHydroBoundSigExpr = this.io.readU1()
  this.tropoVHydroBoundSig = tropoVHydroBoundSigExpr

  ##[
  Vertical Wet Error Bound Mean.

  ]##
  let tropoVWetBoundMuExpr = this.io.readU1()
  this.tropoVWetBoundMu = tropoVWetBoundMuExpr

  ##[
  Vertical Wet Error Bound StDev.

  ]##
  let tropoVWetBoundSigExpr = this.io.readU1()
  this.tropoVWetBoundSig = tropoVWetBoundSigExpr

  ##[
  Number of satellites.

  ]##
  let nSatsExpr = this.io.readU1()
  this.nSats = nSatsExpr

  ##[
  Array of STEC polynomial coefficients and its bounds for each space
vehicle.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_StecSatElementIntegrity.read(this.io, this.root, this)
      this.stecSatList.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrGriddedCorrectionBounds], filename: string): Ssr_MsgSsrGriddedCorrectionBounds =
  Ssr_MsgSsrGriddedCorrectionBounds.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrGridDefinitionDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGridDefinitionDepA =
  template this: untyped = result
  this = new(Ssr_MsgSsrGridDefinitionDepA)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a Gridded Correction message

  ]##
  let headerExpr = Ssr_GridDefinitionHeaderDepA.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Run Length Encode list of quadrants that contain valid data. The
spec describes the encoding scheme in detail, but essentially the
index of the quadrants that contain transitions between valid and
invalid (and vice versa) are encoded as u8 integers.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.rleList.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrGridDefinitionDepA], filename: string): Ssr_MsgSsrGridDefinitionDepA =
  Ssr_MsgSsrGridDefinitionDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Code biases are to be added to pseudorange. The corrections conform with
RTCMv3 MT 1059 / 1065.

]##
proc read*(_: typedesc[Ssr_CodeBiasesContent], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrCodeBiases): Ssr_CodeBiasesContent =
  template this: untyped = result
  this = new(Ssr_CodeBiasesContent)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Signal encoded following RTCM specifications (DF380, DF381, DF382
and DF467).

  ]##
  let codeExpr = this.io.readU1()
  this.code = codeExpr

  ##[
  Code bias value

  ]##
  let valueExpr = this.io.readS2le()
  this.value = valueExpr

proc fromFile*(_: typedesc[Ssr_CodeBiasesContent], filename: string): Ssr_CodeBiasesContent =
  Ssr_CodeBiasesContent.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrSatelliteApc], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrSatelliteApc =
  template this: untyped = result
  this = new(Ssr_MsgSsrSatelliteApc)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  SSR Solution ID. Similar to RTCM DF415.

  ]##
  let solIdExpr = this.io.readU1()
  this.solId = solIdExpr

  ##[
  IOD of the SSR correction. A change of Issue Of Data SSR is used to
indicate a change in the SSR generating configuration

  ]##
  let iodSsrExpr = this.io.readU1()
  this.iodSsr = iodSsrExpr

  ##[
  Satellite antenna phase center corrections

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_SatelliteApc.read(this.io, this.root, this)
      this.apc.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrSatelliteApc], filename: string): Ssr_MsgSsrSatelliteApc =
  Ssr_MsgSsrSatelliteApc.read(newKaitaiFileStream(filename), nil, nil)


##[
Phase biases are to be added to carrier phase measurements.

]##
proc read*(_: typedesc[Ssr_PhaseBiasesContent], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrPhaseBiases): Ssr_PhaseBiasesContent =
  template this: untyped = result
  this = new(Ssr_PhaseBiasesContent)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Signal encoded following RTCM specifications (DF380, DF381, DF382
and DF467)

  ]##
  let codeExpr = this.io.readU1()
  this.code = codeExpr

  ##[
  Indicator for integer property

  ]##
  let integerIndicatorExpr = this.io.readU1()
  this.integerIndicator = integerIndicatorExpr

  ##[
  Indicator for two groups of Wide-Lane(s) integer property

  ]##
  let widelaneIntegerIndicatorExpr = this.io.readU1()
  this.widelaneIntegerIndicator = widelaneIntegerIndicatorExpr

  ##[
  Signal phase discontinuity counter. Increased for every
discontinuity in phase.

  ]##
  let discontinuityCounterExpr = this.io.readU1()
  this.discontinuityCounter = discontinuityCounterExpr

  ##[
  Phase bias for specified signal

  ]##
  let biasExpr = this.io.readS4le()
  this.bias = biasExpr

proc fromFile*(_: typedesc[Ssr_PhaseBiasesContent], filename: string): Ssr_PhaseBiasesContent =
  Ssr_PhaseBiasesContent.read(newKaitaiFileStream(filename), nil, nil)


##[
Provides the correction point coordinates for the atmospheric correction
values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
messages.

Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
correction points, not lists of points.

]##
proc read*(_: typedesc[Ssr_MsgSsrTileDefinitionDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrTileDefinitionDepA =
  template this: untyped = result
  this = new(Ssr_MsgSsrTileDefinitionDepA)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Unique identifier of the tile set this tile belongs to.

  ]##
  let tileSetIdExpr = this.io.readU2le()
  this.tileSetId = tileSetIdExpr

  ##[
  Unique identifier of this tile in the tile set.
See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.

  ]##
  let tileIdExpr = this.io.readU2le()
  this.tileId = tileIdExpr

  ##[
  North-West corner correction point latitude.

The relation between the latitude X in the range [-90, 90] and the
coded number N is:

N = floor((X / 90) * 2^14)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.

  ]##
  let cornerNwLatExpr = this.io.readS2le()
  this.cornerNwLat = cornerNwLatExpr

  ##[
  North-West corner correction point longitude.

The relation between the longitude X in the range [-180, 180] and
the coded number N is:

N = floor((X / 180) * 2^15)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.

  ]##
  let cornerNwLonExpr = this.io.readS2le()
  this.cornerNwLon = cornerNwLonExpr

  ##[
  Spacing of the correction points in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.

  ]##
  let spacingLatExpr = this.io.readU2le()
  this.spacingLat = spacingLatExpr

  ##[
  Spacing of the correction points in the longitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.

  ]##
  let spacingLonExpr = this.io.readU2le()
  this.spacingLon = spacingLonExpr

  ##[
  Number of steps in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.

  ]##
  let rowsExpr = this.io.readU2le()
  this.rows = rowsExpr

  ##[
  Number of steps in the longitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.

  ]##
  let colsExpr = this.io.readU2le()
  this.cols = colsExpr

  ##[
  Specifies the availability of correction data at the correction
points in the array.

If a specific bit is enabled (set to 1), the correction is not
available. Only the first rows * cols bits are used, the remainder
are set to 0. If there are more then 64 correction points the
remaining corrections are always available.

Starting with the northwest corner of the array (top left on a north
oriented map) the correction points are enumerated with row
precedence - first row west to east, second row west to east, until
last row west to east - ending with the southeast corner of the
array.

See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
the definition of the bits is inverted.

  ]##
  let bitmaskExpr = this.io.readU8le()
  this.bitmask = bitmaskExpr

proc fromFile*(_: typedesc[Ssr_MsgSsrTileDefinitionDepA], filename: string): Ssr_MsgSsrTileDefinitionDepA =
  Ssr_MsgSsrTileDefinitionDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Orbit and clock bound.

]##
proc read*(_: typedesc[Ssr_OrbitClockBound], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrOrbitClockBounds): Ssr_OrbitClockBound =
  template this: untyped = result
  this = new(Ssr_OrbitClockBound)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
or DF488 (BDS) depending on the constellation.

  ]##
  let satIdExpr = this.io.readU1()
  this.satId = satIdExpr

  ##[
  Mean Radial. See Note 1.

  ]##
  let orbRadialBoundMuExpr = this.io.readU1()
  this.orbRadialBoundMu = orbRadialBoundMuExpr

  ##[
  Mean Along-Track. See Note 1.

  ]##
  let orbAlongBoundMuExpr = this.io.readU1()
  this.orbAlongBoundMu = orbAlongBoundMuExpr

  ##[
  Mean Cross-Track. See Note 1.

  ]##
  let orbCrossBoundMuExpr = this.io.readU1()
  this.orbCrossBoundMu = orbCrossBoundMuExpr

  ##[
  Standard Deviation Radial. See Note 2.

  ]##
  let orbRadialBoundSigExpr = this.io.readU1()
  this.orbRadialBoundSig = orbRadialBoundSigExpr

  ##[
  Standard Deviation Along-Track. See Note 2.

  ]##
  let orbAlongBoundSigExpr = this.io.readU1()
  this.orbAlongBoundSig = orbAlongBoundSigExpr

  ##[
  Standard Deviation Cross-Track. See Note 2.

  ]##
  let orbCrossBoundSigExpr = this.io.readU1()
  this.orbCrossBoundSig = orbCrossBoundSigExpr

  ##[
  Clock Bound Mean. See Note 1.

  ]##
  let clockBoundMuExpr = this.io.readU1()
  this.clockBoundMu = clockBoundMuExpr

  ##[
  Clock Bound Standard Deviation. See Note 2.

  ]##
  let clockBoundSigExpr = this.io.readU1()
  this.clockBoundSig = clockBoundSigExpr

proc fromFile*(_: typedesc[Ssr_OrbitClockBound], filename: string): Ssr_OrbitClockBound =
  Ssr_OrbitClockBound.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrGriddedCorrectionDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGriddedCorrectionDepA =
  template this: untyped = result
  this = new(Ssr_MsgSsrGriddedCorrectionDepA)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a Gridded Correction message

  ]##
  let headerExpr = Ssr_GriddedCorrectionHeaderDepA.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Index of the grid point

  ]##
  let indexExpr = this.io.readU2le()
  this.index = indexExpr

  ##[
  Wet and hydrostatic vertical delays (mean, stddev)

  ]##
  let tropoDelayCorrectionExpr = Ssr_TroposphericDelayCorrection.read(this.io, this.root, this)
  this.tropoDelayCorrection = tropoDelayCorrectionExpr

  ##[
  STEC residuals for each satellite (mean, stddev)

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_StecResidual.read(this.io, this.root, this)
      this.stecResiduals.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrGriddedCorrectionDepA], filename: string): Ssr_MsgSsrGriddedCorrectionDepA =
  Ssr_MsgSsrGriddedCorrectionDepA.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrOrbitClockBoundsDegradation], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrOrbitClockBoundsDegradation =
  template this: untyped = result
  this = new(Ssr_MsgSsrOrbitClockBoundsDegradation)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a bounds message.

  ]##
  let headerExpr = Ssr_BoundsHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  IOD of the SSR bound degradation parameter.

  ]##
  let ssrIodExpr = this.io.readU1()
  this.ssrIod = ssrIodExpr

  ##[
  Constellation ID to which the SVs belong.

  ]##
  let constIdExpr = this.io.readU1()
  this.constId = constIdExpr

  ##[
  Satellite Bit Mask. Put 1 for each satellite where the following
degradation parameters are applicable, 0 otherwise. Encoded
following RTCM DF394 specification.

  ]##
  let satBitmaskExpr = this.io.readU8le()
  this.satBitmask = satBitmaskExpr

  ##[
  Orbit and Clock Bounds Degradation Parameters

  ]##
  let orbitClockBoundsDegradationExpr = Ssr_OrbitClockBoundDegradation.read(this.io, this.root, this)
  this.orbitClockBoundsDegradation = orbitClockBoundsDegradationExpr

proc fromFile*(_: typedesc[Ssr_MsgSsrOrbitClockBoundsDegradation], filename: string): Ssr_MsgSsrOrbitClockBoundsDegradation =
  Ssr_MsgSsrOrbitClockBoundsDegradation.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrGriddedCorrectionNoStdDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrGriddedCorrectionNoStdDepA =
  template this: untyped = result
  this = new(Ssr_MsgSsrGriddedCorrectionNoStdDepA)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a Gridded Correction message

  ]##
  let headerExpr = Ssr_GriddedCorrectionHeaderDepA.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Index of the grid point

  ]##
  let indexExpr = this.io.readU2le()
  this.index = indexExpr

  ##[
  Wet and hydrostatic vertical delays

  ]##
  let tropoDelayCorrectionExpr = Ssr_TroposphericDelayCorrectionNoStd.read(this.io, this.root, this)
  this.tropoDelayCorrection = tropoDelayCorrectionExpr

  ##[
  STEC residuals for each satellite

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_StecResidualNoStd.read(this.io, this.root, this)
      this.stecResiduals.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrGriddedCorrectionNoStdDepA], filename: string): Ssr_MsgSsrGriddedCorrectionNoStdDepA =
  Ssr_MsgSsrGriddedCorrectionNoStdDepA.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrCodePhaseBiasesBounds], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrCodePhaseBiasesBounds =
  template this: untyped = result
  this = new(Ssr_MsgSsrCodePhaseBiasesBounds)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a bounds message.

  ]##
  let headerExpr = Ssr_BoundsHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  IOD of the SSR bound.

  ]##
  let ssrIodExpr = this.io.readU1()
  this.ssrIod = ssrIodExpr

  ##[
  Constellation ID to which the SVs belong.

  ]##
  let constIdExpr = this.io.readU1()
  this.constId = constIdExpr

  ##[
  Number of satellite-signal couples.

  ]##
  let nSatsSignalsExpr = this.io.readU1()
  this.nSatsSignals = nSatsSignalsExpr

  ##[
  Code and Phase Biases Bounds per Satellite-Signal couple.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_CodePhaseBiasesSatSig.read(this.io, this.root, this)
      this.satellitesSignals.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrCodePhaseBiasesBounds], filename: string): Ssr_MsgSsrCodePhaseBiasesBounds =
  Ssr_MsgSsrCodePhaseBiasesBounds.read(newKaitaiFileStream(filename), nil, nil)


##[
The precise code biases message is to be added to the pseudorange of the
corresponding signal to get corrected pseudorange. It is an equivalent
to the 1059 / 1065 RTCM message types.

]##
proc read*(_: typedesc[Ssr_MsgSsrCodeBiases], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrCodeBiases =
  template this: untyped = result
  this = new(Ssr_MsgSsrCodeBiases)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  IOD of the SSR correction. A change of Issue Of Data SSR is used to
indicate a change in the SSR generating configuration

  ]##
  let iodSsrExpr = this.io.readU1()
  this.iodSsr = iodSsrExpr

  ##[
  Code biases for the different satellite signals

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_CodeBiasesContent.read(this.io, this.root, this)
      this.biases.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrCodeBiases], filename: string): Ssr_MsgSsrCodeBiases =
  Ssr_MsgSsrCodeBiases.read(newKaitaiFileStream(filename), nil, nil)


##[
Provides the correction point coordinates for the atmospheric correction
values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
messages.

Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
correction points, not lists of points.

]##
proc read*(_: typedesc[Ssr_MsgSsrTileDefinition], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrTileDefinition =
  template this: untyped = result
  this = new(Ssr_MsgSsrTileDefinition)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  SSR Solution ID. Similar to RTCM DF415.

  ]##
  let solIdExpr = this.io.readU1()
  this.solId = solIdExpr

  ##[
  IOD of the SSR atmospheric correction.

  ]##
  let iodAtmoExpr = this.io.readU1()
  this.iodAtmo = iodAtmoExpr

  ##[
  Unique identifier of the tile set this tile belongs to.

  ]##
  let tileSetIdExpr = this.io.readU2le()
  this.tileSetId = tileSetIdExpr

  ##[
  Unique identifier of this tile in the tile set.
See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.

  ]##
  let tileIdExpr = this.io.readU2le()
  this.tileId = tileIdExpr

  ##[
  North-West corner correction point latitude.

The relation between the latitude X in the range [-90, 90] and the
coded number N is:  N = floor((X / 90) * 2^14)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.

  ]##
  let cornerNwLatExpr = this.io.readS2le()
  this.cornerNwLat = cornerNwLatExpr

  ##[
  North-West corner correction point longitude.

The relation between the longitude X in the range [-180, 180] and
the coded number N is: N = floor((X / 180) * 2^15)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.

  ]##
  let cornerNwLonExpr = this.io.readS2le()
  this.cornerNwLon = cornerNwLonExpr

  ##[
  Spacing of the correction points in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.

  ]##
  let spacingLatExpr = this.io.readU2le()
  this.spacingLat = spacingLatExpr

  ##[
  Spacing of the correction points in the longitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.

  ]##
  let spacingLonExpr = this.io.readU2le()
  this.spacingLon = spacingLonExpr

  ##[
  Number of steps in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.

  ]##
  let rowsExpr = this.io.readU2le()
  this.rows = rowsExpr

  ##[
  Number of steps in the longitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.

  ]##
  let colsExpr = this.io.readU2le()
  this.cols = colsExpr

  ##[
  Specifies the absence of correction data at the correction points in
the array (grid).

Only the first rows * cols bits are used, and if a specific bit is
enabled (set to 1), the correction is not available. If there are
more than 64 correction points the remaining corrections are always
available.

The correction points are packed by rows, starting with the
northwest corner of the array (top-left on a north oriented map),
with each row spanning west to east, ending with the southeast
corner of the array.

See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
the definition of the bits is inverted.

  ]##
  let bitmaskExpr = this.io.readU8le()
  this.bitmask = bitmaskExpr

proc fromFile*(_: typedesc[Ssr_MsgSsrTileDefinition], filename: string): Ssr_MsgSsrTileDefinition =
  Ssr_MsgSsrTileDefinition.read(newKaitaiFileStream(filename), nil, nil)


##[
Orbit and clock bound degradation.

]##
proc read*(_: typedesc[Ssr_OrbitClockBoundDegradation], io: KaitaiStream, root: KaitaiStruct, parent: Ssr_MsgSsrOrbitClockBoundsDegradation): Ssr_OrbitClockBoundDegradation =
  template this: untyped = result
  this = new(Ssr_OrbitClockBoundDegradation)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s

  ]##
  let orbRadialBoundMuDotExpr = this.io.readU1()
  this.orbRadialBoundMuDot = orbRadialBoundMuDotExpr

  ##[
  Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s

  ]##
  let orbAlongBoundMuDotExpr = this.io.readU1()
  this.orbAlongBoundMuDot = orbAlongBoundMuDotExpr

  ##[
  Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s

  ]##
  let orbCrossBoundMuDotExpr = this.io.readU1()
  this.orbCrossBoundMuDot = orbCrossBoundMuDotExpr

  ##[
  Orbit Bound Standard Deviation Radial First derivative. Range:
0-0.255 m/s

  ]##
  let orbRadialBoundSigDotExpr = this.io.readU1()
  this.orbRadialBoundSigDot = orbRadialBoundSigDotExpr

  ##[
  Orbit Bound Standard Deviation Along-Track First derivative. Range:
0-0.255 m/s

  ]##
  let orbAlongBoundSigDotExpr = this.io.readU1()
  this.orbAlongBoundSigDot = orbAlongBoundSigDotExpr

  ##[
  Orbit Bound Standard Deviation Cross-Track First derivative. Range:
0-0.255 m/s

  ]##
  let orbCrossBoundSigDotExpr = this.io.readU1()
  this.orbCrossBoundSigDot = orbCrossBoundSigDotExpr

  ##[
  Clock Bound Mean First derivative. Range: 0-0.255 m/s

  ]##
  let clockBoundMuDotExpr = this.io.readU1()
  this.clockBoundMuDot = clockBoundMuDotExpr

  ##[
  Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s

  ]##
  let clockBoundSigDotExpr = this.io.readU1()
  this.clockBoundSigDot = clockBoundSigDotExpr

proc fromFile*(_: typedesc[Ssr_OrbitClockBoundDegradation], filename: string): Ssr_OrbitClockBoundDegradation =
  Ssr_OrbitClockBoundDegradation.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Ssr_MsgSsrSatelliteApcDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrSatelliteApcDep =
  template this: untyped = result
  this = new(Ssr_MsgSsrSatelliteApcDep)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Satellite antenna phase center corrections

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_SatelliteApc.read(this.io, this.root, this)
      this.apc.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrSatelliteApcDep], filename: string): Ssr_MsgSsrSatelliteApcDep =
  Ssr_MsgSsrSatelliteApcDep.read(newKaitaiFileStream(filename), nil, nil)


##[
Troposphere vertical delays (mean and standard deviation) at the grid
point.

]##
proc read*(_: typedesc[Ssr_TroposphericDelayCorrection], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Ssr_TroposphericDelayCorrection =
  template this: untyped = result
  this = new(Ssr_TroposphericDelayCorrection)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Hydrostatic vertical delay. Add 2.3 m to get actual value.

  ]##
  let hydroExpr = this.io.readS2le()
  this.hydro = hydroExpr

  ##[
  Wet vertical delay. Add 0.252 m to get actual value.

  ]##
  let wetExpr = this.io.readS1()
  this.wet = wetExpr

  ##[
  Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
value/16) - 1)

  ]##
  let stddevExpr = this.io.readU1()
  this.stddev = stddevExpr

proc fromFile*(_: typedesc[Ssr_TroposphericDelayCorrection], filename: string): Ssr_TroposphericDelayCorrection =
  Ssr_TroposphericDelayCorrection.read(newKaitaiFileStream(filename), nil, nil)


##[
Provides the correction point coordinates for the atmospheric correction
values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
messages.

Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
correction points, not lists of points.

]##
proc read*(_: typedesc[Ssr_MsgSsrTileDefinitionDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrTileDefinitionDepB =
  template this: untyped = result
  this = new(Ssr_MsgSsrTileDefinitionDepB)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  SSR Solution ID.

  ]##
  let ssrSolIdExpr = this.io.readU1()
  this.ssrSolId = ssrSolIdExpr

  ##[
  Unique identifier of the tile set this tile belongs to.

  ]##
  let tileSetIdExpr = this.io.readU2le()
  this.tileSetId = tileSetIdExpr

  ##[
  Unique identifier of this tile in the tile set.
See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.

  ]##
  let tileIdExpr = this.io.readU2le()
  this.tileId = tileIdExpr

  ##[
  North-West corner correction point latitude.

The relation between the latitude X in the range [-90, 90] and the
coded number N is:

N = floor((X / 90) * 2^14)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.

  ]##
  let cornerNwLatExpr = this.io.readS2le()
  this.cornerNwLat = cornerNwLatExpr

  ##[
  North-West corner correction point longitude.

The relation between the longitude X in the range [-180, 180] and
the coded number N is:

N = floor((X / 180) * 2^15)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.

  ]##
  let cornerNwLonExpr = this.io.readS2le()
  this.cornerNwLon = cornerNwLonExpr

  ##[
  Spacing of the correction points in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.

  ]##
  let spacingLatExpr = this.io.readU2le()
  this.spacingLat = spacingLatExpr

  ##[
  Spacing of the correction points in the longitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.

  ]##
  let spacingLonExpr = this.io.readU2le()
  this.spacingLon = spacingLonExpr

  ##[
  Number of steps in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.

  ]##
  let rowsExpr = this.io.readU2le()
  this.rows = rowsExpr

  ##[
  Number of steps in the longitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.

  ]##
  let colsExpr = this.io.readU2le()
  this.cols = colsExpr

  ##[
  Specifies the availability of correction data at the correction
points in the array.

If a specific bit is enabled (set to 1), the correction is not
available. Only the first rows * cols bits are used, the remainder
are set to 0. If there are more then 64 correction points the
remaining corrections are always available.

Starting with the northwest corner of the array (top left on a north
oriented map) the correction points are enumerated with row
precedence - first row west to east, second row west to east, until
last row west to east - ending with the southeast corner of the
array.

See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
the definition of the bits is inverted.

  ]##
  let bitmaskExpr = this.io.readU8le()
  this.bitmask = bitmaskExpr

proc fromFile*(_: typedesc[Ssr_MsgSsrTileDefinitionDepB], filename: string): Ssr_MsgSsrTileDefinitionDepB =
  Ssr_MsgSsrTileDefinitionDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
The precise phase biases message contains the biases to be added to the
carrier phase of the corresponding signal to get corrected carrier phase
measurement, as well as the satellite yaw angle to be applied to compute
the phase wind-up correction. It is typically an equivalent to the 1265
RTCM message types.

]##
proc read*(_: typedesc[Ssr_MsgSsrPhaseBiases], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Ssr_MsgSsrPhaseBiases =
  template this: untyped = result
  this = new(Ssr_MsgSsrPhaseBiases)
  let root = if root == nil: cast[Ssr](this) else: cast[Ssr](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the correction

  ]##
  let timeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.time = timeExpr

  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Update interval between consecutive corrections. Encoded following
RTCM DF391 specification.

  ]##
  let updateIntervalExpr = this.io.readU1()
  this.updateInterval = updateIntervalExpr

  ##[
  IOD of the SSR correction. A change of Issue Of Data SSR is used to
indicate a change in the SSR generating configuration

  ]##
  let iodSsrExpr = this.io.readU1()
  this.iodSsr = iodSsrExpr

  ##[
  Indicator for the dispersive phase biases property.

  ]##
  let dispersiveBiasExpr = this.io.readU1()
  this.dispersiveBias = dispersiveBiasExpr

  ##[
  Consistency indicator for Melbourne-Wubbena linear combinations

  ]##
  let mwConsistencyExpr = this.io.readU1()
  this.mwConsistency = mwConsistencyExpr

  ##[
  Satellite yaw angle

  ]##
  let yawExpr = this.io.readU2le()
  this.yaw = yawExpr

  ##[
  Satellite yaw angle rate

  ]##
  let yawRateExpr = this.io.readS1()
  this.yawRate = yawRateExpr

  ##[
  Phase biases corrections for a satellite being tracked.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Ssr_PhaseBiasesContent.read(this.io, this.root, this)
      this.biases.add(it)
      inc i

proc fromFile*(_: typedesc[Ssr_MsgSsrPhaseBiases], filename: string): Ssr_MsgSsrPhaseBiases =
  Ssr_MsgSsrPhaseBiases.read(newKaitaiFileStream(filename), nil, nil)

