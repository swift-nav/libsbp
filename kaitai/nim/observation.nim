import kaitai_struct_nim_runtime
import options
import gnss

type
  Observation* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Observation_MsgSvAzEl* = ref object of KaitaiStruct
    `azel`*: seq[Observation_SvAzEl]
    `parent`*: Sbp_Message
  Observation_GnssCapb* = ref object of KaitaiStruct
    `gpsActive`*: uint64
    `gpsL2c`*: uint64
    `gpsL5`*: uint64
    `gloActive`*: uint32
    `gloL2of`*: uint32
    `gloL3`*: uint32
    `sbasActive`*: uint64
    `sbasL5`*: uint64
    `bdsActive`*: uint64
    `bdsD2nav`*: uint64
    `bdsB2`*: uint64
    `bdsB2a`*: uint64
    `qzssActive`*: uint32
    `galActive`*: uint64
    `galE5`*: uint64
    `parent`*: Observation_MsgGnssCapb
  Observation_MsgGroupDelayDepB* = ref object of KaitaiStruct
    `tOp`*: Gnss_GpsTimeSec
    `sid`*: Gnss_GnssSignalDep
    `valid`*: uint8
    `tgd`*: int16
    `iscL1ca`*: int16
    `iscL2c`*: int16
    `parent`*: Sbp_Message
  Observation_ObservationHeaderDep* = ref object of KaitaiStruct
    `t`*: Gnss_GpsTimeDep
    `nObs`*: uint8
    `parent`*: KaitaiStruct
  Observation_AlmanacCommonContentDep* = ref object of KaitaiStruct
    `sid`*: Gnss_GnssSignalDep
    `toa`*: Gnss_GpsTimeSec
    `ura`*: float64
    `fitInterval`*: uint32
    `valid`*: uint8
    `healthBits`*: uint8
    `parent`*: KaitaiStruct
  Observation_EphemerisCommonContentDepA* = ref object of KaitaiStruct
    `sid`*: Gnss_GnssSignalDep
    `toe`*: Gnss_GpsTimeDep
    `ura`*: float64
    `fitInterval`*: uint32
    `valid`*: uint8
    `healthBits`*: uint8
    `parent`*: KaitaiStruct
  Observation_EphemerisCommonContent* = ref object of KaitaiStruct
    `sid`*: Gnss_GnssSignal
    `toe`*: Gnss_GpsTimeSec
    `ura`*: float32
    `fitInterval`*: uint32
    `valid`*: uint8
    `healthBits`*: uint8
    `parent`*: KaitaiStruct
  Observation_PackedObsContentDepC* = ref object of KaitaiStruct
    `p`*: uint32
    `l`*: Gnss_CarrierPhase
    `cn0`*: uint8
    `lock`*: uint16
    `sid`*: Gnss_GnssSignalDep
    `parent`*: Observation_MsgObsDepC
  Observation_MsgEphemerisGloDepD* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContentDepB
    `gamma`*: float64
    `tau`*: float64
    `dTau`*: float64
    `pos`*: seq[float64]
    `vel`*: seq[float64]
    `acc`*: seq[float64]
    `fcn`*: uint8
    `iod`*: uint8
    `parent`*: Sbp_Message
  Observation_MsgObsDepA* = ref object of KaitaiStruct
    `header`*: Observation_ObservationHeaderDep
    `obs`*: seq[Observation_PackedObsContentDepA]
    `parent`*: Sbp_Message
  Observation_MsgEphemerisDepB* = ref object of KaitaiStruct
    `tgd`*: float64
    `cRs`*: float64
    `cRc`*: float64
    `cUc`*: float64
    `cUs`*: float64
    `cIc`*: float64
    `cIs`*: float64
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float64
    `af1`*: float64
    `af2`*: float64
    `toeTow`*: float64
    `toeWn`*: uint16
    `tocTow`*: float64
    `tocWn`*: uint16
    `valid`*: uint8
    `healthy`*: uint8
    `prn`*: uint8
    `iode`*: uint8
    `parent`*: Sbp_Message
  Observation_MsgObs* = ref object of KaitaiStruct
    `header`*: Observation_ObservationHeader
    `obs`*: seq[Observation_PackedObsContent]
    `parent`*: Sbp_Message
  Observation_Doppler* = ref object of KaitaiStruct
    `i`*: int16
    `f`*: uint8
    `parent`*: Observation_PackedObsContent
  Observation_MsgAlmanacGloDep* = ref object of KaitaiStruct
    `common`*: Observation_AlmanacCommonContentDep
    `lambdaNa`*: float64
    `tLambdaNa`*: float64
    `i`*: float64
    `t`*: float64
    `tDot`*: float64
    `epsilon`*: float64
    `omega`*: float64
    `parent`*: Sbp_Message
  Observation_MsgAlmanacGpsDep* = ref object of KaitaiStruct
    `common`*: Observation_AlmanacCommonContentDep
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `af0`*: float64
    `af1`*: float64
    `parent`*: Sbp_Message
  Observation_SvAzEl* = ref object of KaitaiStruct
    `sid`*: Gnss_GnssSignal
    `az`*: uint8
    `el`*: int8
    `parent`*: Observation_MsgSvAzEl
  Observation_MsgGloBiases* = ref object of KaitaiStruct
    `mask`*: uint8
    `l1caBias`*: int16
    `l1pBias`*: int16
    `l2caBias`*: int16
    `l2pBias`*: int16
    `parent`*: Sbp_Message
  Observation_MsgEphemerisSbasDepB* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContentDepB
    `pos`*: seq[float64]
    `vel`*: seq[float64]
    `acc`*: seq[float64]
    `aGf0`*: float64
    `aGf1`*: float64
    `parent`*: Sbp_Message
  Observation_MsgEphemerisGpsDepE* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContentDepA
    `tgd`*: float64
    `cRs`*: float64
    `cRc`*: float64
    `cUc`*: float64
    `cUs`*: float64
    `cIc`*: float64
    `cIs`*: float64
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float64
    `af1`*: float64
    `af2`*: float64
    `toc`*: Gnss_GpsTimeDep
    `iode`*: uint8
    `iodc`*: uint16
    `parent`*: Sbp_Message
  Observation_MsgGnssCapb* = ref object of KaitaiStruct
    `tNmct`*: Gnss_GpsTimeSec
    `gc`*: Observation_GnssCapb
    `parent`*: Sbp_Message
  Observation_MsgAlmanacGps* = ref object of KaitaiStruct
    `common`*: Observation_AlmanacCommonContent
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `af0`*: float64
    `af1`*: float64
    `parent`*: Sbp_Message
  Observation_MsgEphemerisQzss* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContent
    `tgd`*: float32
    `cRs`*: float32
    `cRc`*: float32
    `cUc`*: float32
    `cUs`*: float32
    `cIc`*: float32
    `cIs`*: float32
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float32
    `af1`*: float32
    `af2`*: float32
    `toc`*: Gnss_GpsTimeSec
    `iode`*: uint8
    `iodc`*: uint16
    `parent`*: Sbp_Message
  Observation_MsgGroupDelayDepA* = ref object of KaitaiStruct
    `tOp`*: Gnss_GpsTimeDep
    `prn`*: uint8
    `valid`*: uint8
    `tgd`*: int16
    `iscL1ca`*: int16
    `iscL2c`*: int16
    `parent`*: Sbp_Message
  Observation_MsgEphemerisDepC* = ref object of KaitaiStruct
    `tgd`*: float64
    `cRs`*: float64
    `cRc`*: float64
    `cUc`*: float64
    `cUs`*: float64
    `cIc`*: float64
    `cIs`*: float64
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float64
    `af1`*: float64
    `af2`*: float64
    `toeTow`*: float64
    `toeWn`*: uint16
    `tocTow`*: float64
    `tocWn`*: uint16
    `valid`*: uint8
    `healthy`*: uint8
    `sid`*: Gnss_GnssSignalDep
    `iode`*: uint8
    `iodc`*: uint16
    `reserved`*: uint32
    `parent`*: Sbp_Message
  Observation_CarrierPhaseDepA* = ref object of KaitaiStruct
    `i`*: int32
    `f`*: uint8
    `parent`*: KaitaiStruct
  Observation_MsgEphemerisGal* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContent
    `bgdE1e5a`*: float32
    `bgdE1e5b`*: float32
    `cRs`*: float32
    `cRc`*: float32
    `cUc`*: float32
    `cUs`*: float32
    `cIc`*: float32
    `cIs`*: float32
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float64
    `af1`*: float64
    `af2`*: float32
    `toc`*: Gnss_GpsTimeSec
    `iode`*: uint16
    `iodc`*: uint16
    `source`*: uint8
    `parent`*: Sbp_Message
  Observation_PackedOsrContent* = ref object of KaitaiStruct
    `p`*: uint32
    `l`*: Gnss_CarrierPhase
    `lock`*: uint8
    `flags`*: uint8
    `sid`*: Gnss_GnssSignal
    `ionoStd`*: uint16
    `tropoStd`*: uint16
    `rangeStd`*: uint16
    `parent`*: Observation_MsgOsr
  Observation_MsgEphemerisBds* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContent
    `tgd1`*: float32
    `tgd2`*: float32
    `cRs`*: float32
    `cRc`*: float32
    `cUc`*: float32
    `cUs`*: float32
    `cIc`*: float32
    `cIs`*: float32
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float64
    `af1`*: float32
    `af2`*: float32
    `toc`*: Gnss_GpsTimeSec
    `iode`*: uint8
    `iodc`*: uint16
    `parent`*: Sbp_Message
  Observation_MsgEphemerisGpsDepF* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContentDepB
    `tgd`*: float64
    `cRs`*: float64
    `cRc`*: float64
    `cUc`*: float64
    `cUs`*: float64
    `cIc`*: float64
    `cIs`*: float64
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float64
    `af1`*: float64
    `af2`*: float64
    `toc`*: Gnss_GpsTimeSec
    `iode`*: uint8
    `iodc`*: uint16
    `parent`*: Sbp_Message
  Observation_ObservationHeader* = ref object of KaitaiStruct
    `t`*: Gnss_GpsTime
    `nObs`*: uint8
    `parent`*: KaitaiStruct
  Observation_MsgEphemerisSbasDepA* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContentDepA
    `pos`*: seq[float64]
    `vel`*: seq[float64]
    `acc`*: seq[float64]
    `aGf0`*: float64
    `aGf1`*: float64
    `parent`*: Sbp_Message
  Observation_PackedObsContent* = ref object of KaitaiStruct
    `p`*: uint32
    `l`*: Gnss_CarrierPhase
    `d`*: Observation_Doppler
    `cn0`*: uint8
    `lock`*: uint8
    `flags`*: uint8
    `sid`*: Gnss_GnssSignal
    `parent`*: Observation_MsgObs
  Observation_MsgBasePosEcef* = ref object of KaitaiStruct
    `x`*: float64
    `y`*: float64
    `z`*: float64
    `parent`*: Sbp_Message
  Observation_MsgEphemerisGloDepA* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContentDepA
    `gamma`*: float64
    `tau`*: float64
    `pos`*: seq[float64]
    `vel`*: seq[float64]
    `acc`*: seq[float64]
    `parent`*: Sbp_Message
  Observation_MsgGroupDelay* = ref object of KaitaiStruct
    `tOp`*: Gnss_GpsTimeSec
    `sid`*: Gnss_GnssSignal
    `valid`*: uint8
    `tgd`*: int16
    `iscL1ca`*: int16
    `iscL2c`*: int16
    `parent`*: Sbp_Message
  Observation_MsgAlmanacGlo* = ref object of KaitaiStruct
    `common`*: Observation_AlmanacCommonContent
    `lambdaNa`*: float64
    `tLambdaNa`*: float64
    `i`*: float64
    `t`*: float64
    `tDot`*: float64
    `epsilon`*: float64
    `omega`*: float64
    `parent`*: Sbp_Message
  Observation_MsgEphemerisGalDepA* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContent
    `bgdE1e5a`*: float32
    `bgdE1e5b`*: float32
    `cRs`*: float32
    `cRc`*: float32
    `cUc`*: float32
    `cUs`*: float32
    `cIc`*: float32
    `cIs`*: float32
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float64
    `af1`*: float64
    `af2`*: float32
    `toc`*: Gnss_GpsTimeSec
    `iode`*: uint16
    `iodc`*: uint16
    `parent`*: Sbp_Message
  Observation_MsgObsDepB* = ref object of KaitaiStruct
    `header`*: Observation_ObservationHeaderDep
    `obs`*: seq[Observation_PackedObsContentDepB]
    `parent`*: Sbp_Message
  Observation_PackedObsContentDepA* = ref object of KaitaiStruct
    `p`*: uint32
    `l`*: Observation_CarrierPhaseDepA
    `cn0`*: uint8
    `lock`*: uint16
    `prn`*: uint8
    `parent`*: Observation_MsgObsDepA
  Observation_MsgEphemerisGlo* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContent
    `gamma`*: float32
    `tau`*: float32
    `dTau`*: float32
    `pos`*: seq[float64]
    `vel`*: seq[float64]
    `acc`*: seq[float32]
    `fcn`*: uint8
    `iod`*: uint8
    `parent`*: Sbp_Message
  Observation_MsgIono* = ref object of KaitaiStruct
    `tNmct`*: Gnss_GpsTimeSec
    `a0`*: float64
    `a1`*: float64
    `a2`*: float64
    `a3`*: float64
    `b0`*: float64
    `b1`*: float64
    `b2`*: float64
    `b3`*: float64
    `parent`*: Sbp_Message
  Observation_MsgEphemerisDepD* = ref object of KaitaiStruct
    `tgd`*: float64
    `cRs`*: float64
    `cRc`*: float64
    `cUc`*: float64
    `cUs`*: float64
    `cIc`*: float64
    `cIs`*: float64
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float64
    `af1`*: float64
    `af2`*: float64
    `toeTow`*: float64
    `toeWn`*: uint16
    `tocTow`*: float64
    `tocWn`*: uint16
    `valid`*: uint8
    `healthy`*: uint8
    `sid`*: Gnss_GnssSignalDep
    `iode`*: uint8
    `iodc`*: uint16
    `reserved`*: uint32
    `parent`*: Sbp_Message
  Observation_MsgEphemerisGps* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContent
    `tgd`*: float32
    `cRs`*: float32
    `cRc`*: float32
    `cUc`*: float32
    `cUs`*: float32
    `cIc`*: float32
    `cIs`*: float32
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float32
    `af1`*: float32
    `af2`*: float32
    `toc`*: Gnss_GpsTimeSec
    `iode`*: uint8
    `iodc`*: uint16
    `parent`*: Sbp_Message
  Observation_MsgBasePosLlh* = ref object of KaitaiStruct
    `lat`*: float64
    `lon`*: float64
    `height`*: float64
    `parent`*: Sbp_Message
  Observation_AlmanacCommonContent* = ref object of KaitaiStruct
    `sid`*: Gnss_GnssSignal
    `toa`*: Gnss_GpsTimeSec
    `ura`*: float64
    `fitInterval`*: uint32
    `valid`*: uint8
    `healthBits`*: uint8
    `parent`*: KaitaiStruct
  Observation_MsgOsr* = ref object of KaitaiStruct
    `header`*: Observation_ObservationHeader
    `obs`*: seq[Observation_PackedOsrContent]
    `parent`*: Sbp_Message
  Observation_MsgEphemerisGloDepC* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContentDepB
    `gamma`*: float64
    `tau`*: float64
    `dTau`*: float64
    `pos`*: seq[float64]
    `vel`*: seq[float64]
    `acc`*: seq[float64]
    `fcn`*: uint8
    `parent`*: Sbp_Message
  Observation_MsgEphemerisGloDepB* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContentDepB
    `gamma`*: float64
    `tau`*: float64
    `pos`*: seq[float64]
    `vel`*: seq[float64]
    `acc`*: seq[float64]
    `parent`*: Sbp_Message
  Observation_MsgSvConfigurationGpsDep* = ref object of KaitaiStruct
    `tNmct`*: Gnss_GpsTimeSec
    `l2cMask`*: uint32
    `parent`*: Sbp_Message
  Observation_MsgEphemerisSbas* = ref object of KaitaiStruct
    `common`*: Observation_EphemerisCommonContent
    `pos`*: seq[float64]
    `vel`*: seq[float32]
    `acc`*: seq[float32]
    `aGf0`*: float32
    `aGf1`*: float32
    `parent`*: Sbp_Message
  Observation_PackedObsContentDepB* = ref object of KaitaiStruct
    `p`*: uint32
    `l`*: Observation_CarrierPhaseDepA
    `cn0`*: uint8
    `lock`*: uint16
    `sid`*: Gnss_GnssSignalDep
    `parent`*: Observation_MsgObsDepB
  Observation_MsgObsDepC* = ref object of KaitaiStruct
    `header`*: Observation_ObservationHeaderDep
    `obs`*: seq[Observation_PackedObsContentDepC]
    `parent`*: Sbp_Message
  Observation_MsgEphemerisDepA* = ref object of KaitaiStruct
    `tgd`*: float64
    `cRs`*: float64
    `cRc`*: float64
    `cUc`*: float64
    `cUs`*: float64
    `cIc`*: float64
    `cIs`*: float64
    `dn`*: float64
    `m0`*: float64
    `ecc`*: float64
    `sqrta`*: float64
    `omega0`*: float64
    `omegadot`*: float64
    `w`*: float64
    `inc`*: float64
    `incDot`*: float64
    `af0`*: float64
    `af1`*: float64
    `af2`*: float64
    `toeTow`*: float64
    `toeWn`*: uint16
    `tocTow`*: float64
    `tocWn`*: uint16
    `valid`*: uint8
    `healthy`*: uint8
    `prn`*: uint8
    `parent`*: Sbp_Message
  Observation_EphemerisCommonContentDepB* = ref object of KaitaiStruct
    `sid`*: Gnss_GnssSignal
    `toe`*: Gnss_GpsTimeSec
    `ura`*: float64
    `fitInterval`*: uint32
    `valid`*: uint8
    `healthBits`*: uint8
    `parent`*: KaitaiStruct

proc read*(_: typedesc[Observation], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation
proc read*(_: typedesc[Observation_MsgSvAzEl], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgSvAzEl
proc read*(_: typedesc[Observation_GnssCapb], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgGnssCapb): Observation_GnssCapb
proc read*(_: typedesc[Observation_MsgGroupDelayDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGroupDelayDepB
proc read*(_: typedesc[Observation_ObservationHeaderDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_ObservationHeaderDep
proc read*(_: typedesc[Observation_AlmanacCommonContentDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_AlmanacCommonContentDep
proc read*(_: typedesc[Observation_EphemerisCommonContentDepA], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_EphemerisCommonContentDepA
proc read*(_: typedesc[Observation_EphemerisCommonContent], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_EphemerisCommonContent
proc read*(_: typedesc[Observation_PackedObsContentDepC], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgObsDepC): Observation_PackedObsContentDepC
proc read*(_: typedesc[Observation_MsgEphemerisGloDepD], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGloDepD
proc read*(_: typedesc[Observation_MsgObsDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgObsDepA
proc read*(_: typedesc[Observation_MsgEphemerisDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisDepB
proc read*(_: typedesc[Observation_MsgObs], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgObs
proc read*(_: typedesc[Observation_Doppler], io: KaitaiStream, root: KaitaiStruct, parent: Observation_PackedObsContent): Observation_Doppler
proc read*(_: typedesc[Observation_MsgAlmanacGloDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgAlmanacGloDep
proc read*(_: typedesc[Observation_MsgAlmanacGpsDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgAlmanacGpsDep
proc read*(_: typedesc[Observation_SvAzEl], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgSvAzEl): Observation_SvAzEl
proc read*(_: typedesc[Observation_MsgGloBiases], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGloBiases
proc read*(_: typedesc[Observation_MsgEphemerisSbasDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisSbasDepB
proc read*(_: typedesc[Observation_MsgEphemerisGpsDepE], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGpsDepE
proc read*(_: typedesc[Observation_MsgGnssCapb], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGnssCapb
proc read*(_: typedesc[Observation_MsgAlmanacGps], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgAlmanacGps
proc read*(_: typedesc[Observation_MsgEphemerisQzss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisQzss
proc read*(_: typedesc[Observation_MsgGroupDelayDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGroupDelayDepA
proc read*(_: typedesc[Observation_MsgEphemerisDepC], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisDepC
proc read*(_: typedesc[Observation_CarrierPhaseDepA], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_CarrierPhaseDepA
proc read*(_: typedesc[Observation_MsgEphemerisGal], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGal
proc read*(_: typedesc[Observation_PackedOsrContent], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgOsr): Observation_PackedOsrContent
proc read*(_: typedesc[Observation_MsgEphemerisBds], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisBds
proc read*(_: typedesc[Observation_MsgEphemerisGpsDepF], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGpsDepF
proc read*(_: typedesc[Observation_ObservationHeader], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_ObservationHeader
proc read*(_: typedesc[Observation_MsgEphemerisSbasDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisSbasDepA
proc read*(_: typedesc[Observation_PackedObsContent], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgObs): Observation_PackedObsContent
proc read*(_: typedesc[Observation_MsgBasePosEcef], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgBasePosEcef
proc read*(_: typedesc[Observation_MsgEphemerisGloDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGloDepA
proc read*(_: typedesc[Observation_MsgGroupDelay], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGroupDelay
proc read*(_: typedesc[Observation_MsgAlmanacGlo], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgAlmanacGlo
proc read*(_: typedesc[Observation_MsgEphemerisGalDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGalDepA
proc read*(_: typedesc[Observation_MsgObsDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgObsDepB
proc read*(_: typedesc[Observation_PackedObsContentDepA], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgObsDepA): Observation_PackedObsContentDepA
proc read*(_: typedesc[Observation_MsgEphemerisGlo], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGlo
proc read*(_: typedesc[Observation_MsgIono], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgIono
proc read*(_: typedesc[Observation_MsgEphemerisDepD], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisDepD
proc read*(_: typedesc[Observation_MsgEphemerisGps], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGps
proc read*(_: typedesc[Observation_MsgBasePosLlh], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgBasePosLlh
proc read*(_: typedesc[Observation_AlmanacCommonContent], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_AlmanacCommonContent
proc read*(_: typedesc[Observation_MsgOsr], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgOsr
proc read*(_: typedesc[Observation_MsgEphemerisGloDepC], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGloDepC
proc read*(_: typedesc[Observation_MsgEphemerisGloDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGloDepB
proc read*(_: typedesc[Observation_MsgSvConfigurationGpsDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgSvConfigurationGpsDep
proc read*(_: typedesc[Observation_MsgEphemerisSbas], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisSbas
proc read*(_: typedesc[Observation_PackedObsContentDepB], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgObsDepB): Observation_PackedObsContentDepB
proc read*(_: typedesc[Observation_MsgObsDepC], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgObsDepC
proc read*(_: typedesc[Observation_MsgEphemerisDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisDepA
proc read*(_: typedesc[Observation_EphemerisCommonContentDepB], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_EphemerisCommonContentDepB


proc read*(_: typedesc[Observation], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation =
  template this: untyped = result
  this = new(Observation)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Observation], filename: string): Observation =
  Observation.read(newKaitaiFileStream(filename), nil, nil)


##[
Azimuth and elevation angles of all the visible satellites that the
device does have ephemeris or almanac for.

]##
proc read*(_: typedesc[Observation_MsgSvAzEl], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgSvAzEl =
  template this: untyped = result
  this = new(Observation_MsgSvAzEl)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Azimuth and elevation per satellite

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Observation_SvAzEl.read(this.io, this.root, this)
      this.azel.add(it)
      inc i

proc fromFile*(_: typedesc[Observation_MsgSvAzEl], filename: string): Observation_MsgSvAzEl =
  Observation_MsgSvAzEl.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Observation_GnssCapb], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgGnssCapb): Observation_GnssCapb =
  template this: untyped = result
  this = new(Observation_GnssCapb)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS SV active mask

  ]##
  let gpsActiveExpr = this.io.readU8le()
  this.gpsActive = gpsActiveExpr

  ##[
  GPS L2C active mask

  ]##
  let gpsL2cExpr = this.io.readU8le()
  this.gpsL2c = gpsL2cExpr

  ##[
  GPS L5 active mask

  ]##
  let gpsL5Expr = this.io.readU8le()
  this.gpsL5 = gpsL5Expr

  ##[
  GLO active mask

  ]##
  let gloActiveExpr = this.io.readU4le()
  this.gloActive = gloActiveExpr

  ##[
  GLO L2OF active mask

  ]##
  let gloL2ofExpr = this.io.readU4le()
  this.gloL2of = gloL2ofExpr

  ##[
  GLO L3 active mask

  ]##
  let gloL3Expr = this.io.readU4le()
  this.gloL3 = gloL3Expr

  ##[
  SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)

  ]##
  let sbasActiveExpr = this.io.readU8le()
  this.sbasActive = sbasActiveExpr

  ##[
  SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)

  ]##
  let sbasL5Expr = this.io.readU8le()
  this.sbasL5 = sbasL5Expr

  ##[
  BDS active mask

  ]##
  let bdsActiveExpr = this.io.readU8le()
  this.bdsActive = bdsActiveExpr

  ##[
  BDS D2NAV active mask

  ]##
  let bdsD2navExpr = this.io.readU8le()
  this.bdsD2nav = bdsD2navExpr

  ##[
  BDS B2 active mask

  ]##
  let bdsB2Expr = this.io.readU8le()
  this.bdsB2 = bdsB2Expr

  ##[
  BDS B2A active mask

  ]##
  let bdsB2aExpr = this.io.readU8le()
  this.bdsB2a = bdsB2aExpr

  ##[
  QZSS active mask

  ]##
  let qzssActiveExpr = this.io.readU4le()
  this.qzssActive = qzssActiveExpr

  ##[
  GAL active mask

  ]##
  let galActiveExpr = this.io.readU8le()
  this.galActive = galActiveExpr

  ##[
  GAL E5 active mask

  ]##
  let galE5Expr = this.io.readU8le()
  this.galE5 = galE5Expr

proc fromFile*(_: typedesc[Observation_GnssCapb], filename: string): Observation_GnssCapb =
  Observation_GnssCapb.read(newKaitaiFileStream(filename), nil, nil)


##[
Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.

]##
proc read*(_: typedesc[Observation_MsgGroupDelayDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGroupDelayDepB =
  template this: untyped = result
  this = new(Observation_MsgGroupDelayDepB)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Data Predict Time of Week

  ]##
  let tOpExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.tOp = tOpExpr

  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  bit-field indicating validity of the values, LSB indicating tgd
validity etc. 1 = value is valid, 0 = value is not valid.

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr
  let tgdExpr = this.io.readS2le()
  this.tgd = tgdExpr
  let iscL1caExpr = this.io.readS2le()
  this.iscL1ca = iscL1caExpr
  let iscL2cExpr = this.io.readS2le()
  this.iscL2c = iscL2cExpr

proc fromFile*(_: typedesc[Observation_MsgGroupDelayDepB], filename: string): Observation_MsgGroupDelayDepB =
  Observation_MsgGroupDelayDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
Header of a GPS observation message.

]##
proc read*(_: typedesc[Observation_ObservationHeaderDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_ObservationHeaderDep =
  template this: untyped = result
  this = new(Observation_ObservationHeaderDep)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GPS time of this observation

  ]##
  let tExpr = Gnss_GpsTimeDep.read(this.io, this.root, this)
  this.t = tExpr

  ##[
  Total number of observations. First nibble is the size of the
sequence (n), second nibble is the zero-indexed counter (ith packet
of n)

  ]##
  let nObsExpr = this.io.readU1()
  this.nObs = nObsExpr

proc fromFile*(_: typedesc[Observation_ObservationHeaderDep], filename: string): Observation_ObservationHeaderDep =
  Observation_ObservationHeaderDep.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Observation_AlmanacCommonContentDep], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_AlmanacCommonContentDep =
  template this: untyped = result
  this = new(Observation_AlmanacCommonContentDep)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Reference time of almanac

  ]##
  let toaExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toa = toaExpr

  ##[
  User Range Accuracy

  ]##
  let uraExpr = this.io.readF8le()
  this.ura = uraExpr

  ##[
  Curve fit interval

  ]##
  let fitIntervalExpr = this.io.readU4le()
  this.fitInterval = fitIntervalExpr

  ##[
  Status of almanac, 1 = valid, 0 = invalid

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr

  ##[
  Satellite health status for GPS:
  - bits 5-7: NAV data health status. See IS-GPS-200H
    Table 20-VII: NAV Data Health Indications.
  - bits 0-4: Signal health status. See IS-GPS-200H
    Table 20-VIII. Codes for Health of SV Signal
    Components.
Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
details):
  - bit 0: C(n), "unhealthy" flag that is transmitted within
    non-immediate data and indicates overall constellation status
    at the moment of almanac uploading.
    '0' indicates malfunction of n-satellite.
    '1' indicates that n-satellite is operational.
  - bit 1: Bn(ln), '0' indicates the satellite is operational
    and suitable for navigation.

  ]##
  let healthBitsExpr = this.io.readU1()
  this.healthBits = healthBitsExpr

proc fromFile*(_: typedesc[Observation_AlmanacCommonContentDep], filename: string): Observation_AlmanacCommonContentDep =
  Observation_AlmanacCommonContentDep.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Observation_EphemerisCommonContentDepA], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_EphemerisCommonContentDepA =
  template this: untyped = result
  this = new(Observation_EphemerisCommonContentDepA)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Time of Ephemerides

  ]##
  let toeExpr = Gnss_GpsTimeDep.read(this.io, this.root, this)
  this.toe = toeExpr

  ##[
  User Range Accuracy

  ]##
  let uraExpr = this.io.readF8le()
  this.ura = uraExpr

  ##[
  Curve fit interval

  ]##
  let fitIntervalExpr = this.io.readU4le()
  this.fitInterval = fitIntervalExpr

  ##[
  Status of ephemeris, 1 = valid, 0 = invalid

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr

  ##[
  Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid

  ]##
  let healthBitsExpr = this.io.readU1()
  this.healthBits = healthBitsExpr

proc fromFile*(_: typedesc[Observation_EphemerisCommonContentDepA], filename: string): Observation_EphemerisCommonContentDepA =
  Observation_EphemerisCommonContentDepA.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Observation_EphemerisCommonContent], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_EphemerisCommonContent =
  template this: untyped = result
  this = new(Observation_EphemerisCommonContent)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Time of Ephemerides

  ]##
  let toeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toe = toeExpr

  ##[
  User Range Accuracy

  ]##
  let uraExpr = this.io.readF4le()
  this.ura = uraExpr

  ##[
  Curve fit interval

  ]##
  let fitIntervalExpr = this.io.readU4le()
  this.fitInterval = fitIntervalExpr

  ##[
  Status of ephemeris, 1 = valid, 0 = invalid

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr

  ##[
  Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid

  ]##
  let healthBitsExpr = this.io.readU1()
  this.healthBits = healthBitsExpr

proc fromFile*(_: typedesc[Observation_EphemerisCommonContent], filename: string): Observation_EphemerisCommonContent =
  Observation_EphemerisCommonContent.read(newKaitaiFileStream(filename), nil, nil)


##[
Pseudorange and carrier phase observation for a satellite being tracked.
The observations are be interoperable with 3rd party receivers and
conform with typical RTCMv3 GNSS observations.

]##
proc read*(_: typedesc[Observation_PackedObsContentDepC], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgObsDepC): Observation_PackedObsContentDepC =
  template this: untyped = result
  this = new(Observation_PackedObsContentDepC)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Pseudorange observation

  ]##
  let pExpr = this.io.readU4le()
  this.p = pExpr

  ##[
  Carrier phase observation with typical sign convention.

  ]##
  let lExpr = Gnss_CarrierPhase.read(this.io, this.root, this)
  this.l = lExpr

  ##[
  Carrier-to-Noise density

  ]##
  let cn0Expr = this.io.readU1()
  this.cn0 = cn0Expr

  ##[
  Lock indicator. This value changes whenever a satellite signal has
lost and regained lock, indicating that the carrier phase ambiguity
may have changed.

  ]##
  let lockExpr = this.io.readU2le()
  this.lock = lockExpr

  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

proc fromFile*(_: typedesc[Observation_PackedObsContentDepC], filename: string): Observation_PackedObsContentDepC =
  Observation_PackedObsContentDepC.read(newKaitaiFileStream(filename), nil, nil)


##[
This observation message has been deprecated in favor of ephemeris
message using floats for size reduction.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGloDepD], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGloDepD =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGloDepD)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContentDepB.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Relative deviation of predicted carrier frequency from nominal

  ]##
  let gammaExpr = this.io.readF8le()
  this.gamma = gammaExpr

  ##[
  Correction to the SV time

  ]##
  let tauExpr = this.io.readF8le()
  this.tau = tauExpr

  ##[
  Equipment delay between L1 and L2

  ]##
  let dTauExpr = this.io.readF8le()
  this.dTau = dTauExpr

  ##[
  Position of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.pos.add(it)

  ##[
  Velocity vector of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.vel.add(it)

  ##[
  Acceleration vector of the SV at tb in PZ-90.02 coordinates sys

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.acc.add(it)

  ##[
  Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid

  ]##
  let fcnExpr = this.io.readU1()
  this.fcn = fcnExpr

  ##[
  Issue of data. Equal to the 7 bits of the immediate data word t_b

  ]##
  let iodExpr = this.io.readU1()
  this.iod = iodExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisGloDepD], filename: string): Observation_MsgEphemerisGloDepD =
  Observation_MsgEphemerisGloDepD.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Observation_MsgObsDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgObsDepA =
  template this: untyped = result
  this = new(Observation_MsgObsDepA)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a GPS observation message

  ]##
  let headerExpr = Observation_ObservationHeaderDep.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Pseudorange and carrier phase observation for a satellite being
tracked.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Observation_PackedObsContentDepA.read(this.io, this.root, this)
      this.obs.add(it)
      inc i

proc fromFile*(_: typedesc[Observation_MsgObsDepA], filename: string): Observation_MsgObsDepA =
  Observation_MsgObsDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Observation_MsgEphemerisDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisDepB =
  template this: untyped = result
  this = new(Observation_MsgEphemerisDepB)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Group delay differential between L1 and L2

  ]##
  let tgdExpr = this.io.readF8le()
  this.tgd = tgdExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF8le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF8le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF8le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF8le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF8le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF8le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF8le()
  this.af2 = af2Expr

  ##[
  Time of week

  ]##
  let toeTowExpr = this.io.readF8le()
  this.toeTow = toeTowExpr

  ##[
  Week number

  ]##
  let toeWnExpr = this.io.readU2le()
  this.toeWn = toeWnExpr

  ##[
  Clock reference time of week

  ]##
  let tocTowExpr = this.io.readF8le()
  this.tocTow = tocTowExpr

  ##[
  Clock reference week number

  ]##
  let tocWnExpr = this.io.readU2le()
  this.tocWn = tocWnExpr

  ##[
  Is valid?

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr

  ##[
  Satellite is healthy?

  ]##
  let healthyExpr = this.io.readU1()
  this.healthy = healthyExpr

  ##[
  PRN being tracked

  ]##
  let prnExpr = this.io.readU1()
  this.prn = prnExpr

  ##[
  Issue of ephemeris data

  ]##
  let iodeExpr = this.io.readU1()
  this.iode = iodeExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisDepB], filename: string): Observation_MsgEphemerisDepB =
  Observation_MsgEphemerisDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
The GPS observations message reports all the raw pseudorange and carrier
phase observations for the satellites being tracked by the device.
Carrier phase observation here is represented as a 40-bit fixed point
number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
fractional cycles). The observations are be interoperable with 3rd party
receivers and conform with typical RTCMv3 GNSS observations.

]##
proc read*(_: typedesc[Observation_MsgObs], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgObs =
  template this: untyped = result
  this = new(Observation_MsgObs)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a GPS observation message

  ]##
  let headerExpr = Observation_ObservationHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Pseudorange and carrier phase observation for a satellite being
tracked.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Observation_PackedObsContent.read(this.io, this.root, this)
      this.obs.add(it)
      inc i

proc fromFile*(_: typedesc[Observation_MsgObs], filename: string): Observation_MsgObs =
  Observation_MsgObs.read(newKaitaiFileStream(filename), nil, nil)


##[
Doppler measurement in Hz represented as a 24-bit fixed point number
with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
fractional doppler. This doppler is defined as positive for approaching
satellites.

]##
proc read*(_: typedesc[Observation_Doppler], io: KaitaiStream, root: KaitaiStruct, parent: Observation_PackedObsContent): Observation_Doppler =
  template this: untyped = result
  this = new(Observation_Doppler)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Doppler whole Hz

  ]##
  let iExpr = this.io.readS2le()
  this.i = iExpr

  ##[
  Doppler fractional part

  ]##
  let fExpr = this.io.readU1()
  this.f = fExpr

proc fromFile*(_: typedesc[Observation_Doppler], filename: string): Observation_Doppler =
  Observation_Doppler.read(newKaitaiFileStream(filename), nil, nil)


##[
The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several
months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
information and almanac" for details.

]##
proc read*(_: typedesc[Observation_MsgAlmanacGloDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgAlmanacGloDep =
  template this: untyped = result
  this = new(Observation_MsgAlmanacGloDep)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all almanac types

  ]##
  let commonExpr = Observation_AlmanacCommonContentDep.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Longitude of the first ascending node of the orbit in PZ-90.02
coordinate system

  ]##
  let lambdaNaExpr = this.io.readF8le()
  this.lambdaNa = lambdaNaExpr

  ##[
  Time of the first ascending node passage

  ]##
  let tLambdaNaExpr = this.io.readF8le()
  this.tLambdaNa = tLambdaNaExpr

  ##[
  Value of inclination at instant of t_lambda

  ]##
  let iExpr = this.io.readF8le()
  this.i = iExpr

  ##[
  Value of Draconian period at instant of t_lambda

  ]##
  let tExpr = this.io.readF8le()
  this.t = tExpr

  ##[
  Rate of change of the Draconian period

  ]##
  let tDotExpr = this.io.readF8le()
  this.tDot = tDotExpr

  ##[
  Eccentricity at instant of t_lambda

  ]##
  let epsilonExpr = this.io.readF8le()
  this.epsilon = epsilonExpr

  ##[
  Argument of perigee at instant of t_lambda

  ]##
  let omegaExpr = this.io.readF8le()
  this.omega = omegaExpr

proc fromFile*(_: typedesc[Observation_MsgAlmanacGloDep], filename: string): Observation_MsgAlmanacGloDep =
  Observation_MsgAlmanacGloDep.read(newKaitaiFileStream(filename), nil, nil)


##[
The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several
months. Please see the Navstar GPS Space Segment/Navigation user
interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
details.

]##
proc read*(_: typedesc[Observation_MsgAlmanacGpsDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgAlmanacGpsDep =
  template this: untyped = result
  this = new(Observation_MsgAlmanacGpsDep)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all almanac types

  ]##
  let commonExpr = Observation_AlmanacCommonContentDep.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

proc fromFile*(_: typedesc[Observation_MsgAlmanacGpsDep], filename: string): Observation_MsgAlmanacGpsDep =
  Observation_MsgAlmanacGpsDep.read(newKaitaiFileStream(filename), nil, nil)


##[
Satellite azimuth and elevation.

]##
proc read*(_: typedesc[Observation_SvAzEl], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgSvAzEl): Observation_SvAzEl =
  template this: untyped = result
  this = new(Observation_SvAzEl)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Azimuth angle (range 0..179)

  ]##
  let azExpr = this.io.readU1()
  this.az = azExpr

  ##[
  Elevation angle (range -90..90)

  ]##
  let elExpr = this.io.readS1()
  this.el = elExpr

proc fromFile*(_: typedesc[Observation_SvAzEl], filename: string): Observation_SvAzEl =
  Observation_SvAzEl.read(newKaitaiFileStream(filename), nil, nil)


##[
The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
integer ambiguity resolution for baselines with mixed receiver types
(e.g. receiver of different manufacturers).

]##
proc read*(_: typedesc[Observation_MsgGloBiases], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGloBiases =
  template this: untyped = result
  this = new(Observation_MsgGloBiases)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GLONASS FDMA signals mask

  ]##
  let maskExpr = this.io.readU1()
  this.mask = maskExpr

  ##[
  GLONASS L1 C/A Code-Phase Bias

  ]##
  let l1caBiasExpr = this.io.readS2le()
  this.l1caBias = l1caBiasExpr

  ##[
  GLONASS L1 P Code-Phase Bias

  ]##
  let l1pBiasExpr = this.io.readS2le()
  this.l1pBias = l1pBiasExpr

  ##[
  GLONASS L2 C/A Code-Phase Bias

  ]##
  let l2caBiasExpr = this.io.readS2le()
  this.l2caBias = l2caBiasExpr

  ##[
  GLONASS L2 P Code-Phase Bias

  ]##
  let l2pBiasExpr = this.io.readS2le()
  this.l2pBias = l2pBiasExpr

proc fromFile*(_: typedesc[Observation_MsgGloBiases], filename: string): Observation_MsgGloBiases =
  Observation_MsgGloBiases.read(newKaitaiFileStream(filename), nil, nil)


##[
This observation message has been deprecated in favor of ephemeris
message using floats for size reduction.

]##
proc read*(_: typedesc[Observation_MsgEphemerisSbasDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisSbasDepB =
  template this: untyped = result
  this = new(Observation_MsgEphemerisSbasDepB)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContentDepB.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Position of the GEO at time toe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.pos.add(it)

  ##[
  Velocity of the GEO at time toe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.vel.add(it)

  ##[
  Acceleration of the GEO at time toe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.acc.add(it)

  ##[
  Time offset of the GEO clock w.r.t. SBAS Network Time

  ]##
  let aGf0Expr = this.io.readF8le()
  this.aGf0 = aGf0Expr

  ##[
  Drift of the GEO clock w.r.t. SBAS Network Time

  ]##
  let aGf1Expr = this.io.readF8le()
  this.aGf1 = aGf1Expr

proc fromFile*(_: typedesc[Observation_MsgEphemerisSbasDepB], filename: string): Observation_MsgEphemerisSbasDepB =
  Observation_MsgEphemerisSbasDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate GPS satellite position, velocity, and clock offset.
Please see the Navstar GPS Space Segment/Navigation user interfaces
(ICD-GPS-200, Table 20-III) for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGpsDepE], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGpsDepE =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGpsDepE)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContentDepA.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Group delay differential between L1 and L2

  ]##
  let tgdExpr = this.io.readF8le()
  this.tgd = tgdExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF8le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF8le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF8le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF8le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF8le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF8le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF8le()
  this.af2 = af2Expr

  ##[
  Clock reference

  ]##
  let tocExpr = Gnss_GpsTimeDep.read(this.io, this.root, this)
  this.toc = tocExpr

  ##[
  Issue of ephemeris data

  ]##
  let iodeExpr = this.io.readU1()
  this.iode = iodeExpr

  ##[
  Issue of clock data

  ]##
  let iodcExpr = this.io.readU2le()
  this.iodc = iodcExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisGpsDepE], filename: string): Observation_MsgEphemerisGpsDepE =
  Observation_MsgEphemerisGpsDepE.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Observation_MsgGnssCapb], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGnssCapb =
  template this: untyped = result
  this = new(Observation_MsgGnssCapb)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Navigation Message Correction Table Validity Time

  ]##
  let tNmctExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.tNmct = tNmctExpr

  ##[
  GNSS capabilities masks

  ]##
  let gcExpr = Observation_GnssCapb.read(this.io, this.root, this)
  this.gc = gcExpr

proc fromFile*(_: typedesc[Observation_MsgGnssCapb], filename: string): Observation_MsgGnssCapb =
  Observation_MsgGnssCapb.read(newKaitaiFileStream(filename), nil, nil)


##[
The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several
months. Please see the Navstar GPS Space Segment/Navigation user
interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
details.

]##
proc read*(_: typedesc[Observation_MsgAlmanacGps], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgAlmanacGps =
  template this: untyped = result
  this = new(Observation_MsgAlmanacGps)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all almanac types

  ]##
  let commonExpr = Observation_AlmanacCommonContent.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

proc fromFile*(_: typedesc[Observation_MsgAlmanacGps], filename: string): Observation_MsgAlmanacGps =
  Observation_MsgAlmanacGps.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate QZSS satellite position, velocity, and clock
offset.

]##
proc read*(_: typedesc[Observation_MsgEphemerisQzss], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisQzss =
  template this: untyped = result
  this = new(Observation_MsgEphemerisQzss)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContent.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Group delay differential between L1 and L2

  ]##
  let tgdExpr = this.io.readF4le()
  this.tgd = tgdExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF4le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF4le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF4le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF4le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF4le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF4le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF4le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF4le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF4le()
  this.af2 = af2Expr

  ##[
  Clock reference

  ]##
  let tocExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toc = tocExpr

  ##[
  Issue of ephemeris data

  ]##
  let iodeExpr = this.io.readU1()
  this.iode = iodeExpr

  ##[
  Issue of clock data

  ]##
  let iodcExpr = this.io.readU2le()
  this.iodc = iodcExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisQzss], filename: string): Observation_MsgEphemerisQzss =
  Observation_MsgEphemerisQzss.read(newKaitaiFileStream(filename), nil, nil)


##[
Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.

]##
proc read*(_: typedesc[Observation_MsgGroupDelayDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGroupDelayDepA =
  template this: untyped = result
  this = new(Observation_MsgGroupDelayDepA)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Data Predict Time of Week

  ]##
  let tOpExpr = Gnss_GpsTimeDep.read(this.io, this.root, this)
  this.tOp = tOpExpr

  ##[
  Satellite number

  ]##
  let prnExpr = this.io.readU1()
  this.prn = prnExpr

  ##[
  bit-field indicating validity of the values, LSB indicating tgd
validity etc. 1 = value is valid, 0 = value is not valid.

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr
  let tgdExpr = this.io.readS2le()
  this.tgd = tgdExpr
  let iscL1caExpr = this.io.readS2le()
  this.iscL1ca = iscL1caExpr
  let iscL2cExpr = this.io.readS2le()
  this.iscL2c = iscL2cExpr

proc fromFile*(_: typedesc[Observation_MsgGroupDelayDepA], filename: string): Observation_MsgGroupDelayDepA =
  Observation_MsgGroupDelayDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate GPS satellite position, velocity, and clock offset.
Please see the Navstar GPS Space Segment/Navigation user interfaces
(ICD-GPS-200, Table 20-III) for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisDepC], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisDepC =
  template this: untyped = result
  this = new(Observation_MsgEphemerisDepC)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Group delay differential between L1 and L2

  ]##
  let tgdExpr = this.io.readF8le()
  this.tgd = tgdExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF8le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF8le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF8le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF8le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF8le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF8le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF8le()
  this.af2 = af2Expr

  ##[
  Time of week

  ]##
  let toeTowExpr = this.io.readF8le()
  this.toeTow = toeTowExpr

  ##[
  Week number

  ]##
  let toeWnExpr = this.io.readU2le()
  this.toeWn = toeWnExpr

  ##[
  Clock reference time of week

  ]##
  let tocTowExpr = this.io.readF8le()
  this.tocTow = tocTowExpr

  ##[
  Clock reference week number

  ]##
  let tocWnExpr = this.io.readU2le()
  this.tocWn = tocWnExpr

  ##[
  Is valid?

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr

  ##[
  Satellite is healthy?

  ]##
  let healthyExpr = this.io.readU1()
  this.healthy = healthyExpr

  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Issue of ephemeris data

  ]##
  let iodeExpr = this.io.readU1()
  this.iode = iodeExpr

  ##[
  Issue of clock data

  ]##
  let iodcExpr = this.io.readU2le()
  this.iodc = iodcExpr

  ##[
  Reserved field

  ]##
  let reservedExpr = this.io.readU4le()
  this.reserved = reservedExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisDepC], filename: string): Observation_MsgEphemerisDepC =
  Observation_MsgEphemerisDepC.read(newKaitaiFileStream(filename), nil, nil)


##[
Carrier phase measurement in cycles represented as a 40-bit fixed point
number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
fractional cycles. This has the opposite sign convention than a typical
GPS receiver and the phase has the opposite sign as the pseudorange.

]##
proc read*(_: typedesc[Observation_CarrierPhaseDepA], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_CarrierPhaseDepA =
  template this: untyped = result
  this = new(Observation_CarrierPhaseDepA)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Carrier phase whole cycles

  ]##
  let iExpr = this.io.readS4le()
  this.i = iExpr

  ##[
  Carrier phase fractional part

  ]##
  let fExpr = this.io.readU1()
  this.f = fExpr

proc fromFile*(_: typedesc[Observation_CarrierPhaseDepA], filename: string): Observation_CarrierPhaseDepA =
  Observation_CarrierPhaseDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate Galileo satellite position, velocity, and clock
offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
December 2016 for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGal], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGal =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGal)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContent.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  E1-E5a Broadcast Group Delay

  ]##
  let bgdE1e5aExpr = this.io.readF4le()
  this.bgdE1e5a = bgdE1e5aExpr

  ##[
  E1-E5b Broadcast Group Delay

  ]##
  let bgdE1e5bExpr = this.io.readF4le()
  this.bgdE1e5b = bgdE1e5bExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF4le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF4le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF4le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF4le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF4le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF4le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF4le()
  this.af2 = af2Expr

  ##[
  Clock reference

  ]##
  let tocExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toc = tocExpr

  ##[
  Issue of data (IODnav)

  ]##
  let iodeExpr = this.io.readU2le()
  this.iode = iodeExpr

  ##[
  Issue of data (IODnav). Always equal to iode

  ]##
  let iodcExpr = this.io.readU2le()
  this.iodc = iodcExpr

  ##[
  0=I/NAV, 1=F/NAV

  ]##
  let sourceExpr = this.io.readU1()
  this.source = sourceExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisGal], filename: string): Observation_MsgEphemerisGal =
  Observation_MsgEphemerisGal.read(newKaitaiFileStream(filename), nil, nil)


##[
Pseudorange and carrier phase network corrections for a satellite
signal.

]##
proc read*(_: typedesc[Observation_PackedOsrContent], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgOsr): Observation_PackedOsrContent =
  template this: untyped = result
  this = new(Observation_PackedOsrContent)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Pseudorange observation

  ]##
  let pExpr = this.io.readU4le()
  this.p = pExpr

  ##[
  Carrier phase observation with typical sign convention.

  ]##
  let lExpr = Gnss_CarrierPhase.read(this.io, this.root, this)
  this.l = lExpr

  ##[
  Lock timer. This value gives an indication of the time for which a
signal has maintained continuous phase lock. Whenever a signal has
lost and regained lock, this value is reset to zero. It is encoded
according to DF402 from the RTCM 10403.2 Amendment 2 specification.
Valid values range from 0 to 15 and the most significant nibble is
reserved for future use.

  ]##
  let lockExpr = this.io.readU1()
  this.lock = lockExpr

  ##[
  Correction flags.

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Slant ionospheric correction standard deviation

  ]##
  let ionoStdExpr = this.io.readU2le()
  this.ionoStd = ionoStdExpr

  ##[
  Slant tropospheric correction standard deviation

  ]##
  let tropoStdExpr = this.io.readU2le()
  this.tropoStd = tropoStdExpr

  ##[
  Orbit/clock/bias correction projected on range standard deviation

  ]##
  let rangeStdExpr = this.io.readU2le()
  this.rangeStd = rangeStdExpr

proc fromFile*(_: typedesc[Observation_PackedOsrContent], filename: string): Observation_PackedOsrContent =
  Observation_PackedOsrContent.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate BDS satellite position, velocity, and clock offset.
Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
Table 5-9 for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisBds], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisBds =
  template this: untyped = result
  this = new(Observation_MsgEphemerisBds)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContent.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Group delay differential for B1

  ]##
  let tgd1Expr = this.io.readF4le()
  this.tgd1 = tgd1Expr

  ##[
  Group delay differential for B2

  ]##
  let tgd2Expr = this.io.readF4le()
  this.tgd2 = tgd2Expr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF4le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF4le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF4le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF4le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF4le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF4le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF4le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF4le()
  this.af2 = af2Expr

  ##[
  Clock reference

  ]##
  let tocExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toc = tocExpr

  ##[
  Issue of ephemeris data
Calculated from the navigation data parameter t_oe per RTCM/CSNO
recommendation: IODE = mod (t_oe / 720, 240)

  ]##
  let iodeExpr = this.io.readU1()
  this.iode = iodeExpr

  ##[
  Issue of clock data
Calculated from the navigation data parameter t_oe per RTCM/CSNO
recommendation: IODE = mod (t_oc / 720, 240)

  ]##
  let iodcExpr = this.io.readU2le()
  this.iodc = iodcExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisBds], filename: string): Observation_MsgEphemerisBds =
  Observation_MsgEphemerisBds.read(newKaitaiFileStream(filename), nil, nil)


##[
This observation message has been deprecated in favor of ephemeris
message using floats for size reduction.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGpsDepF], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGpsDepF =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGpsDepF)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContentDepB.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Group delay differential between L1 and L2

  ]##
  let tgdExpr = this.io.readF8le()
  this.tgd = tgdExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF8le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF8le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF8le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF8le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF8le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF8le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF8le()
  this.af2 = af2Expr

  ##[
  Clock reference

  ]##
  let tocExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toc = tocExpr

  ##[
  Issue of ephemeris data

  ]##
  let iodeExpr = this.io.readU1()
  this.iode = iodeExpr

  ##[
  Issue of clock data

  ]##
  let iodcExpr = this.io.readU2le()
  this.iodc = iodcExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisGpsDepF], filename: string): Observation_MsgEphemerisGpsDepF =
  Observation_MsgEphemerisGpsDepF.read(newKaitaiFileStream(filename), nil, nil)


##[
Header of a GNSS observation message.

]##
proc read*(_: typedesc[Observation_ObservationHeader], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_ObservationHeader =
  template this: untyped = result
  this = new(Observation_ObservationHeader)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS time of this observation

  ]##
  let tExpr = Gnss_GpsTime.read(this.io, this.root, this)
  this.t = tExpr

  ##[
  Total number of observations. First nibble is the size of the
sequence (n), second nibble is the zero-indexed counter (ith packet
of n)

  ]##
  let nObsExpr = this.io.readU1()
  this.nObs = nObsExpr

proc fromFile*(_: typedesc[Observation_ObservationHeader], filename: string): Observation_ObservationHeader =
  Observation_ObservationHeader.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Observation_MsgEphemerisSbasDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisSbasDepA =
  template this: untyped = result
  this = new(Observation_MsgEphemerisSbasDepA)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContentDepA.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Position of the GEO at time toe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.pos.add(it)

  ##[
  Velocity of the GEO at time toe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.vel.add(it)

  ##[
  Acceleration of the GEO at time toe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.acc.add(it)

  ##[
  Time offset of the GEO clock w.r.t. SBAS Network Time

  ]##
  let aGf0Expr = this.io.readF8le()
  this.aGf0 = aGf0Expr

  ##[
  Drift of the GEO clock w.r.t. SBAS Network Time

  ]##
  let aGf1Expr = this.io.readF8le()
  this.aGf1 = aGf1Expr

proc fromFile*(_: typedesc[Observation_MsgEphemerisSbasDepA], filename: string): Observation_MsgEphemerisSbasDepA =
  Observation_MsgEphemerisSbasDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Pseudorange and carrier phase observation for a satellite being tracked.
The observations are interoperable with 3rd party receivers and conform
with typical RTCM 3.1 message GPS/GLO observations.

Carrier phase observations are not guaranteed to be aligned to the RINEX
3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
currently performed.

]##
proc read*(_: typedesc[Observation_PackedObsContent], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgObs): Observation_PackedObsContent =
  template this: untyped = result
  this = new(Observation_PackedObsContent)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Pseudorange observation

  ]##
  let pExpr = this.io.readU4le()
  this.p = pExpr

  ##[
  Carrier phase observation with typical sign convention.

  ]##
  let lExpr = Gnss_CarrierPhase.read(this.io, this.root, this)
  this.l = lExpr

  ##[
  Doppler observation with typical sign convention.

  ]##
  let dExpr = Observation_Doppler.read(this.io, this.root, this)
  this.d = dExpr

  ##[
  Carrier-to-Noise density.  Zero implies invalid cn0.

  ]##
  let cn0Expr = this.io.readU1()
  this.cn0 = cn0Expr

  ##[
  Lock timer. This value gives an indication of the time for which a
signal has maintained continuous phase lock. Whenever a signal has
lost and regained lock, this value is reset to zero. It is encoded
according to DF402 from the RTCM 10403.2 Amendment 2 specification.
Valid values range from 0 to 15 and the most significant nibble is
reserved for future use.

  ]##
  let lockExpr = this.io.readU1()
  this.lock = lockExpr

  ##[
  Measurement status flags. A bit field of flags providing the status
of this observation.  If this field is 0 it means only the Cn0
estimate for the signal is valid.

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

proc fromFile*(_: typedesc[Observation_PackedObsContent], filename: string): Observation_PackedObsContent =
  Observation_PackedObsContent.read(newKaitaiFileStream(filename), nil, nil)


##[
The base station position message is the position reported by the base
station itself in absolute Earth Centered Earth Fixed coordinates. It is
used for pseudo-absolute RTK positioning, and is required to be a high-
accuracy surveyed location of the base station. Any error here will
result in an error in the pseudo-absolute position output.

]##
proc read*(_: typedesc[Observation_MsgBasePosEcef], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgBasePosEcef =
  template this: untyped = result
  this = new(Observation_MsgBasePosEcef)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


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

proc fromFile*(_: typedesc[Observation_MsgBasePosEcef], filename: string): Observation_MsgBasePosEcef =
  Observation_MsgBasePosEcef.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate GLO satellite position, velocity, and clock offset.
Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
immediate information (ephemeris parameters)" for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGloDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGloDepA =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGloDepA)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContentDepA.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Relative deviation of predicted carrier frequency from nominal

  ]##
  let gammaExpr = this.io.readF8le()
  this.gamma = gammaExpr

  ##[
  Correction to the SV time

  ]##
  let tauExpr = this.io.readF8le()
  this.tau = tauExpr

  ##[
  Position of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.pos.add(it)

  ##[
  Velocity vector of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.vel.add(it)

  ##[
  Acceleration vector of the SV at tb in PZ-90.02 coordinates sys

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.acc.add(it)

proc fromFile*(_: typedesc[Observation_MsgEphemerisGloDepA], filename: string): Observation_MsgEphemerisGloDepA =
  Observation_MsgEphemerisGloDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.

]##
proc read*(_: typedesc[Observation_MsgGroupDelay], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgGroupDelay =
  template this: untyped = result
  this = new(Observation_MsgGroupDelay)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Data Predict Time of Week

  ]##
  let tOpExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.tOp = tOpExpr

  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  bit-field indicating validity of the values, LSB indicating tgd
validity etc. 1 = value is valid, 0 = value is not valid.

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr
  let tgdExpr = this.io.readS2le()
  this.tgd = tgdExpr
  let iscL1caExpr = this.io.readS2le()
  this.iscL1ca = iscL1caExpr
  let iscL2cExpr = this.io.readS2le()
  this.iscL2c = iscL2cExpr

proc fromFile*(_: typedesc[Observation_MsgGroupDelay], filename: string): Observation_MsgGroupDelay =
  Observation_MsgGroupDelay.read(newKaitaiFileStream(filename), nil, nil)


##[
The almanac message returns a set of satellite orbit parameters. Almanac
data is not very precise and is considered valid for up to several
months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
information and almanac" for details.

]##
proc read*(_: typedesc[Observation_MsgAlmanacGlo], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgAlmanacGlo =
  template this: untyped = result
  this = new(Observation_MsgAlmanacGlo)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all almanac types

  ]##
  let commonExpr = Observation_AlmanacCommonContent.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Longitude of the first ascending node of the orbit in PZ-90.02
coordinate system

  ]##
  let lambdaNaExpr = this.io.readF8le()
  this.lambdaNa = lambdaNaExpr

  ##[
  Time of the first ascending node passage

  ]##
  let tLambdaNaExpr = this.io.readF8le()
  this.tLambdaNa = tLambdaNaExpr

  ##[
  Value of inclination at instant of t_lambda

  ]##
  let iExpr = this.io.readF8le()
  this.i = iExpr

  ##[
  Value of Draconian period at instant of t_lambda

  ]##
  let tExpr = this.io.readF8le()
  this.t = tExpr

  ##[
  Rate of change of the Draconian period

  ]##
  let tDotExpr = this.io.readF8le()
  this.tDot = tDotExpr

  ##[
  Eccentricity at instant of t_lambda

  ]##
  let epsilonExpr = this.io.readF8le()
  this.epsilon = epsilonExpr

  ##[
  Argument of perigee at instant of t_lambda

  ]##
  let omegaExpr = this.io.readF8le()
  this.omega = omegaExpr

proc fromFile*(_: typedesc[Observation_MsgAlmanacGlo], filename: string): Observation_MsgAlmanacGlo =
  Observation_MsgAlmanacGlo.read(newKaitaiFileStream(filename), nil, nil)


##[
This observation message has been deprecated in favor of an ephemeris
message with explicit source of NAV data.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGalDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGalDepA =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGalDepA)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContent.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  E1-E5a Broadcast Group Delay

  ]##
  let bgdE1e5aExpr = this.io.readF4le()
  this.bgdE1e5a = bgdE1e5aExpr

  ##[
  E1-E5b Broadcast Group Delay

  ]##
  let bgdE1e5bExpr = this.io.readF4le()
  this.bgdE1e5b = bgdE1e5bExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF4le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF4le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF4le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF4le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF4le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF4le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF4le()
  this.af2 = af2Expr

  ##[
  Clock reference

  ]##
  let tocExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toc = tocExpr

  ##[
  Issue of data (IODnav)

  ]##
  let iodeExpr = this.io.readU2le()
  this.iode = iodeExpr

  ##[
  Issue of data (IODnav). Always equal to iode

  ]##
  let iodcExpr = this.io.readU2le()
  this.iodc = iodcExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisGalDepA], filename: string): Observation_MsgEphemerisGalDepA =
  Observation_MsgEphemerisGalDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
This observation message has been deprecated in favor of observations
that are more interoperable. This message should be used for
observations referenced to a nominal pseudorange which are not
interoperable with most 3rd party GNSS receivers or typical RTCMv3
observations.

]##
proc read*(_: typedesc[Observation_MsgObsDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgObsDepB =
  template this: untyped = result
  this = new(Observation_MsgObsDepB)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a GPS observation message

  ]##
  let headerExpr = Observation_ObservationHeaderDep.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Pseudorange and carrier phase observation for a satellite being
tracked.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Observation_PackedObsContentDepB.read(this.io, this.root, this)
      this.obs.add(it)
      inc i

proc fromFile*(_: typedesc[Observation_MsgObsDepB], filename: string): Observation_MsgObsDepB =
  Observation_MsgObsDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Observation_PackedObsContentDepA], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgObsDepA): Observation_PackedObsContentDepA =
  template this: untyped = result
  this = new(Observation_PackedObsContentDepA)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Pseudorange observation

  ]##
  let pExpr = this.io.readU4le()
  this.p = pExpr

  ##[
  Carrier phase observation with opposite sign from typical convention

  ]##
  let lExpr = Observation_CarrierPhaseDepA.read(this.io, this.root, this)
  this.l = lExpr

  ##[
  Carrier-to-Noise density

  ]##
  let cn0Expr = this.io.readU1()
  this.cn0 = cn0Expr

  ##[
  Lock indicator. This value changes whenever a satellite signal has
lost and regained lock, indicating that the carrier phase ambiguity
may have changed.

  ]##
  let lockExpr = this.io.readU2le()
  this.lock = lockExpr

  ##[
  PRN-1 identifier of the satellite signal

  ]##
  let prnExpr = this.io.readU1()
  this.prn = prnExpr

proc fromFile*(_: typedesc[Observation_PackedObsContentDepA], filename: string): Observation_PackedObsContentDepA =
  Observation_PackedObsContentDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate GLO satellite position, velocity, and clock offset.
Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
immediate information (ephemeris parameters)" for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGlo], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGlo =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGlo)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContent.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Relative deviation of predicted carrier frequency from nominal

  ]##
  let gammaExpr = this.io.readF4le()
  this.gamma = gammaExpr

  ##[
  Correction to the SV time

  ]##
  let tauExpr = this.io.readF4le()
  this.tau = tauExpr

  ##[
  Equipment delay between L1 and L2

  ]##
  let dTauExpr = this.io.readF4le()
  this.dTau = dTauExpr

  ##[
  Position of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.pos.add(it)

  ##[
  Velocity vector of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.vel.add(it)

  ##[
  Acceleration vector of the SV at tb in PZ-90.02 coordinates sys

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF4le()
    this.acc.add(it)

  ##[
  Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid

  ]##
  let fcnExpr = this.io.readU1()
  this.fcn = fcnExpr

  ##[
  Issue of data. Equal to the 7 bits of the immediate data word t_b

  ]##
  let iodExpr = this.io.readU1()
  this.iod = iodExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisGlo], filename: string): Observation_MsgEphemerisGlo =
  Observation_MsgEphemerisGlo.read(newKaitaiFileStream(filename), nil, nil)


##[
The ionospheric parameters which allow the "L1 only" or "L2 only" user
to utilize the ionospheric model for computation of the ionospheric
delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.

]##
proc read*(_: typedesc[Observation_MsgIono], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgIono =
  template this: untyped = result
  this = new(Observation_MsgIono)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Navigation Message Correction Table Validity Time

  ]##
  let tNmctExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.tNmct = tNmctExpr
  let a0Expr = this.io.readF8le()
  this.a0 = a0Expr
  let a1Expr = this.io.readF8le()
  this.a1 = a1Expr
  let a2Expr = this.io.readF8le()
  this.a2 = a2Expr
  let a3Expr = this.io.readF8le()
  this.a3 = a3Expr
  let b0Expr = this.io.readF8le()
  this.b0 = b0Expr
  let b1Expr = this.io.readF8le()
  this.b1 = b1Expr
  let b2Expr = this.io.readF8le()
  this.b2 = b2Expr
  let b3Expr = this.io.readF8le()
  this.b3 = b3Expr

proc fromFile*(_: typedesc[Observation_MsgIono], filename: string): Observation_MsgIono =
  Observation_MsgIono.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate GPS satellite position, velocity, and clock offset.
Please see the Navstar GPS Space Segment/Navigation user interfaces
(ICD-GPS-200, Table 20-III) for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisDepD], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisDepD =
  template this: untyped = result
  this = new(Observation_MsgEphemerisDepD)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Group delay differential between L1 and L2

  ]##
  let tgdExpr = this.io.readF8le()
  this.tgd = tgdExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF8le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF8le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF8le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF8le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF8le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF8le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF8le()
  this.af2 = af2Expr

  ##[
  Time of week

  ]##
  let toeTowExpr = this.io.readF8le()
  this.toeTow = toeTowExpr

  ##[
  Week number

  ]##
  let toeWnExpr = this.io.readU2le()
  this.toeWn = toeWnExpr

  ##[
  Clock reference time of week

  ]##
  let tocTowExpr = this.io.readF8le()
  this.tocTow = tocTowExpr

  ##[
  Clock reference week number

  ]##
  let tocWnExpr = this.io.readU2le()
  this.tocWn = tocWnExpr

  ##[
  Is valid?

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr

  ##[
  Satellite is healthy?

  ]##
  let healthyExpr = this.io.readU1()
  this.healthy = healthyExpr

  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Issue of ephemeris data

  ]##
  let iodeExpr = this.io.readU1()
  this.iode = iodeExpr

  ##[
  Issue of clock data

  ]##
  let iodcExpr = this.io.readU2le()
  this.iodc = iodcExpr

  ##[
  Reserved field

  ]##
  let reservedExpr = this.io.readU4le()
  this.reserved = reservedExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisDepD], filename: string): Observation_MsgEphemerisDepD =
  Observation_MsgEphemerisDepD.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate GPS satellite position, velocity, and clock offset.
Please see the Navstar GPS Space Segment/Navigation user interfaces
(ICD-GPS-200, Table 20-III) for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGps], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGps =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGps)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContent.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Group delay differential between L1 and L2

  ]##
  let tgdExpr = this.io.readF4le()
  this.tgd = tgdExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF4le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF4le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF4le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF4le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF4le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF4le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF4le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF4le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF4le()
  this.af2 = af2Expr

  ##[
  Clock reference

  ]##
  let tocExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toc = tocExpr

  ##[
  Issue of ephemeris data

  ]##
  let iodeExpr = this.io.readU1()
  this.iode = iodeExpr

  ##[
  Issue of clock data

  ]##
  let iodcExpr = this.io.readU2le()
  this.iodc = iodcExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisGps], filename: string): Observation_MsgEphemerisGps =
  Observation_MsgEphemerisGps.read(newKaitaiFileStream(filename), nil, nil)


##[
The base station position message is the position reported by the base
station itself. It is used for pseudo-absolute RTK positioning, and is
required to be a high-accuracy surveyed location of the base station.
Any error here will result in an error in the pseudo-absolute position
output.

]##
proc read*(_: typedesc[Observation_MsgBasePosLlh], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgBasePosLlh =
  template this: untyped = result
  this = new(Observation_MsgBasePosLlh)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


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

proc fromFile*(_: typedesc[Observation_MsgBasePosLlh], filename: string): Observation_MsgBasePosLlh =
  Observation_MsgBasePosLlh.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Observation_AlmanacCommonContent], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_AlmanacCommonContent =
  template this: untyped = result
  this = new(Observation_AlmanacCommonContent)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Reference time of almanac

  ]##
  let toaExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toa = toaExpr

  ##[
  User Range Accuracy

  ]##
  let uraExpr = this.io.readF8le()
  this.ura = uraExpr

  ##[
  Curve fit interval

  ]##
  let fitIntervalExpr = this.io.readU4le()
  this.fitInterval = fitIntervalExpr

  ##[
  Status of almanac, 1 = valid, 0 = invalid

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr

  ##[
  Satellite health status for GPS:
  - bits 5-7: NAV data health status. See IS-GPS-200H
    Table 20-VII: NAV Data Health Indications.
  - bits 0-4: Signal health status. See IS-GPS-200H
    Table 20-VIII. Codes for Health of SV Signal
    Components.
Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
details):
  - bit 0: C(n), "unhealthy" flag that is transmitted within
    non-immediate data and indicates overall constellation status
    at the moment of almanac uploading.
    '0' indicates malfunction of n-satellite.
    '1' indicates that n-satellite is operational.
  - bit 1: Bn(ln), '0' indicates the satellite is operational
    and suitable for navigation.

  ]##
  let healthBitsExpr = this.io.readU1()
  this.healthBits = healthBitsExpr

proc fromFile*(_: typedesc[Observation_AlmanacCommonContent], filename: string): Observation_AlmanacCommonContent =
  Observation_AlmanacCommonContent.read(newKaitaiFileStream(filename), nil, nil)


##[
The OSR message contains network corrections in an observation-like
format.

]##
proc read*(_: typedesc[Observation_MsgOsr], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgOsr =
  template this: untyped = result
  this = new(Observation_MsgOsr)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a GPS observation message

  ]##
  let headerExpr = Observation_ObservationHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Network correction for a satellite signal.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Observation_PackedOsrContent.read(this.io, this.root, this)
      this.obs.add(it)
      inc i

proc fromFile*(_: typedesc[Observation_MsgOsr], filename: string): Observation_MsgOsr =
  Observation_MsgOsr.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate GLO satellite position, velocity, and clock offset.
Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
immediate information (ephemeris parameters)" for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGloDepC], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGloDepC =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGloDepC)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContentDepB.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Relative deviation of predicted carrier frequency from nominal

  ]##
  let gammaExpr = this.io.readF8le()
  this.gamma = gammaExpr

  ##[
  Correction to the SV time

  ]##
  let tauExpr = this.io.readF8le()
  this.tau = tauExpr

  ##[
  Equipment delay between L1 and L2

  ]##
  let dTauExpr = this.io.readF8le()
  this.dTau = dTauExpr

  ##[
  Position of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.pos.add(it)

  ##[
  Velocity vector of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.vel.add(it)

  ##[
  Acceleration vector of the SV at tb in PZ-90.02 coordinates sys

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.acc.add(it)

  ##[
  Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid

  ]##
  let fcnExpr = this.io.readU1()
  this.fcn = fcnExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisGloDepC], filename: string): Observation_MsgEphemerisGloDepC =
  Observation_MsgEphemerisGloDepC.read(newKaitaiFileStream(filename), nil, nil)


##[
The ephemeris message returns a set of satellite orbit parameters that
is used to calculate GLO satellite position, velocity, and clock offset.
Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
immediate information (ephemeris parameters)" for more details.

]##
proc read*(_: typedesc[Observation_MsgEphemerisGloDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisGloDepB =
  template this: untyped = result
  this = new(Observation_MsgEphemerisGloDepB)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContentDepB.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Relative deviation of predicted carrier frequency from nominal

  ]##
  let gammaExpr = this.io.readF8le()
  this.gamma = gammaExpr

  ##[
  Correction to the SV time

  ]##
  let tauExpr = this.io.readF8le()
  this.tau = tauExpr

  ##[
  Position of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.pos.add(it)

  ##[
  Velocity vector of the SV at tb in PZ-90.02 coordinates system

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.vel.add(it)

  ##[
  Acceleration vector of the SV at tb in PZ-90.02 coordinates sys

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.acc.add(it)

proc fromFile*(_: typedesc[Observation_MsgEphemerisGloDepB], filename: string): Observation_MsgEphemerisGloDepB =
  Observation_MsgEphemerisGloDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.

]##
proc read*(_: typedesc[Observation_MsgSvConfigurationGpsDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgSvConfigurationGpsDep =
  template this: untyped = result
  this = new(Observation_MsgSvConfigurationGpsDep)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Navigation Message Correction Table Validity Time

  ]##
  let tNmctExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.tNmct = tNmctExpr

  ##[
  L2C capability mask, SV32 bit being MSB, SV1 bit being LSB

  ]##
  let l2cMaskExpr = this.io.readU4le()
  this.l2cMask = l2cMaskExpr

proc fromFile*(_: typedesc[Observation_MsgSvConfigurationGpsDep], filename: string): Observation_MsgSvConfigurationGpsDep =
  Observation_MsgSvConfigurationGpsDep.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Observation_MsgEphemerisSbas], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisSbas =
  template this: untyped = result
  this = new(Observation_MsgEphemerisSbas)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Values common for all ephemeris types

  ]##
  let commonExpr = Observation_EphemerisCommonContent.read(this.io, this.root, this)
  this.common = commonExpr

  ##[
  Position of the GEO at time toe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF8le()
    this.pos.add(it)

  ##[
  Velocity of the GEO at time toe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF4le()
    this.vel.add(it)

  ##[
  Acceleration of the GEO at time toe

  ]##
  for i in 0 ..< int(3):
    let it = this.io.readF4le()
    this.acc.add(it)

  ##[
  Time offset of the GEO clock w.r.t. SBAS Network Time

  ]##
  let aGf0Expr = this.io.readF4le()
  this.aGf0 = aGf0Expr

  ##[
  Drift of the GEO clock w.r.t. SBAS Network Time

  ]##
  let aGf1Expr = this.io.readF4le()
  this.aGf1 = aGf1Expr

proc fromFile*(_: typedesc[Observation_MsgEphemerisSbas], filename: string): Observation_MsgEphemerisSbas =
  Observation_MsgEphemerisSbas.read(newKaitaiFileStream(filename), nil, nil)


##[
Pseudorange and carrier phase observation for a satellite being tracked.
Pseudoranges are referenced to a nominal pseudorange.

]##
proc read*(_: typedesc[Observation_PackedObsContentDepB], io: KaitaiStream, root: KaitaiStruct, parent: Observation_MsgObsDepB): Observation_PackedObsContentDepB =
  template this: untyped = result
  this = new(Observation_PackedObsContentDepB)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Pseudorange observation

  ]##
  let pExpr = this.io.readU4le()
  this.p = pExpr

  ##[
  Carrier phase observation with opposite sign from typical
convention.

  ]##
  let lExpr = Observation_CarrierPhaseDepA.read(this.io, this.root, this)
  this.l = lExpr

  ##[
  Carrier-to-Noise density

  ]##
  let cn0Expr = this.io.readU1()
  this.cn0 = cn0Expr

  ##[
  Lock indicator. This value changes whenever a satellite signal has
lost and regained lock, indicating that the carrier phase ambiguity
may have changed.

  ]##
  let lockExpr = this.io.readU2le()
  this.lock = lockExpr

  ##[
  GNSS signal identifier

  ]##
  let sidExpr = Gnss_GnssSignalDep.read(this.io, this.root, this)
  this.sid = sidExpr

proc fromFile*(_: typedesc[Observation_PackedObsContentDepB], filename: string): Observation_PackedObsContentDepB =
  Observation_PackedObsContentDepB.read(newKaitaiFileStream(filename), nil, nil)


##[
The GPS observations message reports all the raw pseudorange and carrier
phase observations for the satellites being tracked by the device.
Carrier phase observation here is represented as a 40-bit fixed point
number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
fractional cycles). The observations are interoperable with 3rd party
receivers and conform with typical RTCMv3 GNSS observations.

]##
proc read*(_: typedesc[Observation_MsgObsDepC], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgObsDepC =
  template this: untyped = result
  this = new(Observation_MsgObsDepC)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of a GPS observation message

  ]##
  let headerExpr = Observation_ObservationHeaderDep.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Pseudorange and carrier phase observation for a satellite being
tracked.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Observation_PackedObsContentDepC.read(this.io, this.root, this)
      this.obs.add(it)
      inc i

proc fromFile*(_: typedesc[Observation_MsgObsDepC], filename: string): Observation_MsgObsDepC =
  Observation_MsgObsDepC.read(newKaitaiFileStream(filename), nil, nil)


##[
Deprecated.

]##
proc read*(_: typedesc[Observation_MsgEphemerisDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Observation_MsgEphemerisDepA =
  template this: untyped = result
  this = new(Observation_MsgEphemerisDepA)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Group delay differential between L1 and L2

  ]##
  let tgdExpr = this.io.readF8le()
  this.tgd = tgdExpr

  ##[
  Amplitude of the sine harmonic correction term to the orbit radius

  ]##
  let cRsExpr = this.io.readF8le()
  this.cRs = cRsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the orbit radius

  ]##
  let cRcExpr = this.io.readF8le()
  this.cRc = cRcExpr

  ##[
  Amplitude of the cosine harmonic correction term to the argument of
latitude

  ]##
  let cUcExpr = this.io.readF8le()
  this.cUc = cUcExpr

  ##[
  Amplitude of the sine harmonic correction term to the argument of
latitude

  ]##
  let cUsExpr = this.io.readF8le()
  this.cUs = cUsExpr

  ##[
  Amplitude of the cosine harmonic correction term to the angle of
inclination

  ]##
  let cIcExpr = this.io.readF8le()
  this.cIc = cIcExpr

  ##[
  Amplitude of the sine harmonic correction term to the angle of
inclination

  ]##
  let cIsExpr = this.io.readF8le()
  this.cIs = cIsExpr

  ##[
  Mean motion difference

  ]##
  let dnExpr = this.io.readF8le()
  this.dn = dnExpr

  ##[
  Mean anomaly at reference time

  ]##
  let m0Expr = this.io.readF8le()
  this.m0 = m0Expr

  ##[
  Eccentricity of satellite orbit

  ]##
  let eccExpr = this.io.readF8le()
  this.ecc = eccExpr

  ##[
  Square root of the semi-major axis of orbit

  ]##
  let sqrtaExpr = this.io.readF8le()
  this.sqrta = sqrtaExpr

  ##[
  Longitude of ascending node of orbit plane at weekly epoch

  ]##
  let omega0Expr = this.io.readF8le()
  this.omega0 = omega0Expr

  ##[
  Rate of right ascension

  ]##
  let omegadotExpr = this.io.readF8le()
  this.omegadot = omegadotExpr

  ##[
  Argument of perigee

  ]##
  let wExpr = this.io.readF8le()
  this.w = wExpr

  ##[
  Inclination

  ]##
  let incExpr = this.io.readF8le()
  this.inc = incExpr

  ##[
  Inclination first derivative

  ]##
  let incDotExpr = this.io.readF8le()
  this.incDot = incDotExpr

  ##[
  Polynomial clock correction coefficient (clock bias)

  ]##
  let af0Expr = this.io.readF8le()
  this.af0 = af0Expr

  ##[
  Polynomial clock correction coefficient (clock drift)

  ]##
  let af1Expr = this.io.readF8le()
  this.af1 = af1Expr

  ##[
  Polynomial clock correction coefficient (rate of clock drift)

  ]##
  let af2Expr = this.io.readF8le()
  this.af2 = af2Expr

  ##[
  Time of week

  ]##
  let toeTowExpr = this.io.readF8le()
  this.toeTow = toeTowExpr

  ##[
  Week number

  ]##
  let toeWnExpr = this.io.readU2le()
  this.toeWn = toeWnExpr

  ##[
  Clock reference time of week

  ]##
  let tocTowExpr = this.io.readF8le()
  this.tocTow = tocTowExpr

  ##[
  Clock reference week number

  ]##
  let tocWnExpr = this.io.readU2le()
  this.tocWn = tocWnExpr

  ##[
  Is valid?

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr

  ##[
  Satellite is healthy?

  ]##
  let healthyExpr = this.io.readU1()
  this.healthy = healthyExpr

  ##[
  PRN being tracked

  ]##
  let prnExpr = this.io.readU1()
  this.prn = prnExpr

proc fromFile*(_: typedesc[Observation_MsgEphemerisDepA], filename: string): Observation_MsgEphemerisDepA =
  Observation_MsgEphemerisDepA.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Observation_EphemerisCommonContentDepB], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Observation_EphemerisCommonContentDepB =
  template this: untyped = result
  this = new(Observation_EphemerisCommonContentDepB)
  let root = if root == nil: cast[Observation](this) else: cast[Observation](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS signal identifier (16 bit)

  ]##
  let sidExpr = Gnss_GnssSignal.read(this.io, this.root, this)
  this.sid = sidExpr

  ##[
  Time of Ephemerides

  ]##
  let toeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.toe = toeExpr

  ##[
  User Range Accuracy

  ]##
  let uraExpr = this.io.readF8le()
  this.ura = uraExpr

  ##[
  Curve fit interval

  ]##
  let fitIntervalExpr = this.io.readU4le()
  this.fitInterval = fitIntervalExpr

  ##[
  Status of ephemeris, 1 = valid, 0 = invalid

  ]##
  let validExpr = this.io.readU1()
  this.valid = validExpr

  ##[
  Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
Others: 0 = valid, non-zero = invalid

  ]##
  let healthBitsExpr = this.io.readU1()
  this.healthBits = healthBitsExpr

proc fromFile*(_: typedesc[Observation_EphemerisCommonContentDepB], filename: string): Observation_EphemerisCommonContentDepB =
  Observation_EphemerisCommonContentDepB.read(newKaitaiFileStream(filename), nil, nil)

