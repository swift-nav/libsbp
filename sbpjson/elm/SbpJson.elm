-- To decode the JSON data, add this file to your project, run
--
--     elm-package install NoRedInk/elm-decode-pipeline
--
-- add these imports
--
--     import Json.Decode exposing (decodeString)`);
--     import SbpModule exposing (acqSvProfile, almanacCommonContent, carrierPhase, codeBiasesContent, doppler, ephemerisCommonContent, gnssCapb, gnssSignal, gpsTime, gpsTimeSEC, griddedCorrectionHeader, gridDefinitionHeader, gridElement, latency, measurementState, msgAcqResult, msgAcqSvProfile, msgAgeCorrections, msgAlmanacGlo, msgAlmanacGPS, msgAlmanac, msgAngularRate, msgBaselineECEF, msgBaselineHeading, msgBaselineNED, msgBasePosECEF, msgBasePosLLH, msgBootloaderHandshakeReq, msgBootloaderHandshakeResp, msgBootloaderJumpToApp, msgCellModemStatus, msgCommandOutput, msgCommandReq, msgCommandResp, msgCsacTelemetry, msgCsacTelemetryLabels, msgCwResults, msgCwStart, msgDeviceMonitor, msgDgnssStatus, msgDops, msgEphemerisBds, msgEphemerisGal, msgEphemerisGlo, msgEphemerisGPS, msgEphemerisQzss, msgEphemerisSbas, msgEXTEvent, msgFileioConfigReq, msgFileioConfigResp, msgFileioReadDirReq, msgFileioReadDirResp, msgFileioReadReq, msgFileioReadResp, msgFileioRemove, msgFileioWriteReq, msgFileioWriteResp, msgFlashDone, msgFlashErase, msgFlashProgram, msgFlashReadReq, msgFlashReadResp, msgFrontEndGain, msgFwd, msgGloBiases, msgGnssCapb, msgGPSTime, msgGroupDelay, msgHeartbeat, msgIarState, msgImuAux, msgImuRaw, msgInsStatus, msgIono, msgLinuxCPUState, msgLinuxMemState, msgLinuxProcessFdCount, msgLinuxProcessFdSummary, msgLinuxProcessSocketCounts, msgLinuxProcessSocketQueues, msgLinuxSocketUsage, msgLinuxSysState, msgLog, msgM25FlashWriteStatus, msgMagRaw, msgMaskSatellite, msgMeasurementState, msgNapDeviceDnaReq, msgNapDeviceDnaResp, msgNdbEvent, msgNetworkBandwidthUsage, msgNetworkStateReq, msgNetworkStateResp, msgObs, msgOdometry, msgOrientEuler, msgOrientQuat, msgOsr, msgPosECEFCov, msgPosECEF, msgPosLLHCov, msgPosLLH, msgResetFilters, msgReset, msgSbasRaw, msgSetTime, msgSettingsReadByIndexDone, msgSettingsReadByIndexReq, msgSettingsReadByIndexResp, msgSettingsReadReq, msgSettingsReadResp, msgSettingsRegister, msgSettingsRegisterResp, msgSettingsSave, msgSettingsWrite, msgSettingsWriteResp, msgSpecan, msgSsrCodeBiases, msgSsrGriddedCorrection, msgSsrGridDefinition, msgSsrOrbitClock, msgSsrPhaseBiases, msgSsrStecCorrection, msgStartup, msgStmFlashLockSector, msgStmFlashUnlockSector, msgStmUniqueIDReq, msgStmUniqueIDResp, msgSvAzEl, msgThreadState, msgTrackingIq, msgTrackingState, msgUARTState, msgUserData, msgUTCTime, msgVelBody, msgVelECEFCov, msgVelECEF, msgVelNEDCov, msgVelNED, networkUsage, observationHeader, packedObsContent, packedOsrContent, period, phaseBiasesContent, stecHeader, stecResidual, stecSatElement, svAzEl, svID, trackingChannelCorrelation, trackingChannelState, troposphericDelayCorrection, uartChannel)
--
-- and you're off to the races with
--
--     decodeString acqSvProfile myJsonString
--     decodeString almanacCommonContent myJsonString
--     decodeString carrierPhase myJsonString
--     decodeString codeBiasesContent myJsonString
--     decodeString doppler myJsonString
--     decodeString ephemerisCommonContent myJsonString
--     decodeString gnssCapb myJsonString
--     decodeString gnssSignal myJsonString
--     decodeString gpsTime myJsonString
--     decodeString gpsTimeSEC myJsonString
--     decodeString griddedCorrectionHeader myJsonString
--     decodeString gridDefinitionHeader myJsonString
--     decodeString gridElement myJsonString
--     decodeString latency myJsonString
--     decodeString measurementState myJsonString
--     decodeString msgAcqResult myJsonString
--     decodeString msgAcqSvProfile myJsonString
--     decodeString msgAgeCorrections myJsonString
--     decodeString msgAlmanacGlo myJsonString
--     decodeString msgAlmanacGPS myJsonString
--     decodeString msgAlmanac myJsonString
--     decodeString msgAngularRate myJsonString
--     decodeString msgBaselineECEF myJsonString
--     decodeString msgBaselineHeading myJsonString
--     decodeString msgBaselineNED myJsonString
--     decodeString msgBasePosECEF myJsonString
--     decodeString msgBasePosLLH myJsonString
--     decodeString msgBootloaderHandshakeReq myJsonString
--     decodeString msgBootloaderHandshakeResp myJsonString
--     decodeString msgBootloaderJumpToApp myJsonString
--     decodeString msgCellModemStatus myJsonString
--     decodeString msgCommandOutput myJsonString
--     decodeString msgCommandReq myJsonString
--     decodeString msgCommandResp myJsonString
--     decodeString msgCsacTelemetry myJsonString
--     decodeString msgCsacTelemetryLabels myJsonString
--     decodeString msgCwResults myJsonString
--     decodeString msgCwStart myJsonString
--     decodeString msgDeviceMonitor myJsonString
--     decodeString msgDgnssStatus myJsonString
--     decodeString msgDops myJsonString
--     decodeString msgEphemerisBds myJsonString
--     decodeString msgEphemerisGal myJsonString
--     decodeString msgEphemerisGlo myJsonString
--     decodeString msgEphemerisGPS myJsonString
--     decodeString msgEphemerisQzss myJsonString
--     decodeString msgEphemerisSbas myJsonString
--     decodeString msgEXTEvent myJsonString
--     decodeString msgFileioConfigReq myJsonString
--     decodeString msgFileioConfigResp myJsonString
--     decodeString msgFileioReadDirReq myJsonString
--     decodeString msgFileioReadDirResp myJsonString
--     decodeString msgFileioReadReq myJsonString
--     decodeString msgFileioReadResp myJsonString
--     decodeString msgFileioRemove myJsonString
--     decodeString msgFileioWriteReq myJsonString
--     decodeString msgFileioWriteResp myJsonString
--     decodeString msgFlashDone myJsonString
--     decodeString msgFlashErase myJsonString
--     decodeString msgFlashProgram myJsonString
--     decodeString msgFlashReadReq myJsonString
--     decodeString msgFlashReadResp myJsonString
--     decodeString msgFrontEndGain myJsonString
--     decodeString msgFwd myJsonString
--     decodeString msgGloBiases myJsonString
--     decodeString msgGnssCapb myJsonString
--     decodeString msgGPSTime myJsonString
--     decodeString msgGroupDelay myJsonString
--     decodeString msgHeartbeat myJsonString
--     decodeString msgIarState myJsonString
--     decodeString msgImuAux myJsonString
--     decodeString msgImuRaw myJsonString
--     decodeString msgInsStatus myJsonString
--     decodeString msgIono myJsonString
--     decodeString msgLinuxCPUState myJsonString
--     decodeString msgLinuxMemState myJsonString
--     decodeString msgLinuxProcessFdCount myJsonString
--     decodeString msgLinuxProcessFdSummary myJsonString
--     decodeString msgLinuxProcessSocketCounts myJsonString
--     decodeString msgLinuxProcessSocketQueues myJsonString
--     decodeString msgLinuxSocketUsage myJsonString
--     decodeString msgLinuxSysState myJsonString
--     decodeString msgLog myJsonString
--     decodeString msgM25FlashWriteStatus myJsonString
--     decodeString msgMagRaw myJsonString
--     decodeString msgMaskSatellite myJsonString
--     decodeString msgMeasurementState myJsonString
--     decodeString msgNapDeviceDnaReq myJsonString
--     decodeString msgNapDeviceDnaResp myJsonString
--     decodeString msgNdbEvent myJsonString
--     decodeString msgNetworkBandwidthUsage myJsonString
--     decodeString msgNetworkStateReq myJsonString
--     decodeString msgNetworkStateResp myJsonString
--     decodeString msgObs myJsonString
--     decodeString msgOdometry myJsonString
--     decodeString msgOrientEuler myJsonString
--     decodeString msgOrientQuat myJsonString
--     decodeString msgOsr myJsonString
--     decodeString msgPosECEFCov myJsonString
--     decodeString msgPosECEF myJsonString
--     decodeString msgPosLLHCov myJsonString
--     decodeString msgPosLLH myJsonString
--     decodeString msgResetFilters myJsonString
--     decodeString msgReset myJsonString
--     decodeString msgSbasRaw myJsonString
--     decodeString msgSetTime myJsonString
--     decodeString msgSettingsReadByIndexDone myJsonString
--     decodeString msgSettingsReadByIndexReq myJsonString
--     decodeString msgSettingsReadByIndexResp myJsonString
--     decodeString msgSettingsReadReq myJsonString
--     decodeString msgSettingsReadResp myJsonString
--     decodeString msgSettingsRegister myJsonString
--     decodeString msgSettingsRegisterResp myJsonString
--     decodeString msgSettingsSave myJsonString
--     decodeString msgSettingsWrite myJsonString
--     decodeString msgSettingsWriteResp myJsonString
--     decodeString msgSpecan myJsonString
--     decodeString msgSsrCodeBiases myJsonString
--     decodeString msgSsrGriddedCorrection myJsonString
--     decodeString msgSsrGridDefinition myJsonString
--     decodeString msgSsrOrbitClock myJsonString
--     decodeString msgSsrPhaseBiases myJsonString
--     decodeString msgSsrStecCorrection myJsonString
--     decodeString msgStartup myJsonString
--     decodeString msgStmFlashLockSector myJsonString
--     decodeString msgStmFlashUnlockSector myJsonString
--     decodeString msgStmUniqueIDReq myJsonString
--     decodeString msgStmUniqueIDResp myJsonString
--     decodeString msgSvAzEl myJsonString
--     decodeString msgThreadState myJsonString
--     decodeString msgTrackingIq myJsonString
--     decodeString msgTrackingState myJsonString
--     decodeString msgUARTState myJsonString
--     decodeString msgUserData myJsonString
--     decodeString msgUTCTime myJsonString
--     decodeString msgVelBody myJsonString
--     decodeString msgVelECEFCov myJsonString
--     decodeString msgVelECEF myJsonString
--     decodeString msgVelNEDCov myJsonString
--     decodeString msgVelNED myJsonString
--     decodeString networkUsage myJsonString
--     decodeString observationHeader myJsonString
--     decodeString packedObsContent myJsonString
--     decodeString packedOsrContent myJsonString
--     decodeString period myJsonString
--     decodeString phaseBiasesContent myJsonString
--     decodeString stecHeader myJsonString
--     decodeString stecResidual myJsonString
--     decodeString stecSatElement myJsonString
--     decodeString svAzEl myJsonString
--     decodeString svID myJsonString
--     decodeString trackingChannelCorrelation myJsonString
--     decodeString trackingChannelState myJsonString
--     decodeString troposphericDelayCorrection myJsonString
--     decodeString uartChannel myJsonString

module SbpModule exposing
    ( AcqSvProfile
    , acqSvProfileToString
    , acqSvProfile
    , AlmanacCommonContent
    , almanacCommonContentToString
    , almanacCommonContent
    , CarrierPhase
    , carrierPhaseToString
    , carrierPhase
    , CodeBiasesContent
    , codeBiasesContentToString
    , codeBiasesContent
    , Doppler
    , dopplerToString
    , doppler
    , EphemerisCommonContent
    , ephemerisCommonContentToString
    , ephemerisCommonContent
    , GnssCapb
    , gnssCapbToString
    , gnssCapb
    , GnssSignal
    , gnssSignalToString
    , gnssSignal
    , GpsTime
    , gpsTimeToString
    , gpsTime
    , GpsTimeSEC
    , gpsTimeSECToString
    , gpsTimeSEC
    , GriddedCorrectionHeader
    , griddedCorrectionHeaderToString
    , griddedCorrectionHeader
    , GridDefinitionHeader
    , gridDefinitionHeaderToString
    , gridDefinitionHeader
    , GridElement
    , gridElementToString
    , gridElement
    , Latency
    , latencyToString
    , latency
    , MeasurementState
    , measurementStateToString
    , measurementState
    , MsgAcqResult
    , msgAcqResultToString
    , msgAcqResult
    , MsgAcqSvProfile
    , msgAcqSvProfileToString
    , msgAcqSvProfile
    , MsgAgeCorrections
    , msgAgeCorrectionsToString
    , msgAgeCorrections
    , MsgAlmanacGlo
    , msgAlmanacGloToString
    , msgAlmanacGlo
    , MsgAlmanacGPS
    , msgAlmanacGPSToString
    , msgAlmanacGPS
    , MsgAlmanac
    , msgAlmanacToString
    , msgAlmanac
    , MsgAngularRate
    , msgAngularRateToString
    , msgAngularRate
    , MsgBaselineECEF
    , msgBaselineECEFToString
    , msgBaselineECEF
    , MsgBaselineHeading
    , msgBaselineHeadingToString
    , msgBaselineHeading
    , MsgBaselineNED
    , msgBaselineNEDToString
    , msgBaselineNED
    , MsgBasePosECEF
    , msgBasePosECEFToString
    , msgBasePosECEF
    , MsgBasePosLLH
    , msgBasePosLLHToString
    , msgBasePosLLH
    , MsgBootloaderHandshakeReq
    , msgBootloaderHandshakeReqToString
    , msgBootloaderHandshakeReq
    , MsgBootloaderHandshakeResp
    , msgBootloaderHandshakeRespToString
    , msgBootloaderHandshakeResp
    , MsgBootloaderJumpToApp
    , msgBootloaderJumpToAppToString
    , msgBootloaderJumpToApp
    , MsgCellModemStatus
    , msgCellModemStatusToString
    , msgCellModemStatus
    , MsgCommandOutput
    , msgCommandOutputToString
    , msgCommandOutput
    , MsgCommandReq
    , msgCommandReqToString
    , msgCommandReq
    , MsgCommandResp
    , msgCommandRespToString
    , msgCommandResp
    , MsgCsacTelemetry
    , msgCsacTelemetryToString
    , msgCsacTelemetry
    , MsgCsacTelemetryLabels
    , msgCsacTelemetryLabelsToString
    , msgCsacTelemetryLabels
    , MsgCwResults
    , msgCwResultsToString
    , msgCwResults
    , MsgCwStart
    , msgCwStartToString
    , msgCwStart
    , MsgDeviceMonitor
    , msgDeviceMonitorToString
    , msgDeviceMonitor
    , MsgDgnssStatus
    , msgDgnssStatusToString
    , msgDgnssStatus
    , MsgDops
    , msgDopsToString
    , msgDops
    , MsgEphemerisBds
    , msgEphemerisBdsToString
    , msgEphemerisBds
    , MsgEphemerisGal
    , msgEphemerisGalToString
    , msgEphemerisGal
    , MsgEphemerisGlo
    , msgEphemerisGloToString
    , msgEphemerisGlo
    , MsgEphemerisGPS
    , msgEphemerisGPSToString
    , msgEphemerisGPS
    , MsgEphemerisQzss
    , msgEphemerisQzssToString
    , msgEphemerisQzss
    , MsgEphemerisSbas
    , msgEphemerisSbasToString
    , msgEphemerisSbas
    , MsgEXTEvent
    , msgEXTEventToString
    , msgEXTEvent
    , MsgFileioConfigReq
    , msgFileioConfigReqToString
    , msgFileioConfigReq
    , MsgFileioConfigResp
    , msgFileioConfigRespToString
    , msgFileioConfigResp
    , MsgFileioReadDirReq
    , msgFileioReadDirReqToString
    , msgFileioReadDirReq
    , MsgFileioReadDirResp
    , msgFileioReadDirRespToString
    , msgFileioReadDirResp
    , MsgFileioReadReq
    , msgFileioReadReqToString
    , msgFileioReadReq
    , MsgFileioReadResp
    , msgFileioReadRespToString
    , msgFileioReadResp
    , MsgFileioRemove
    , msgFileioRemoveToString
    , msgFileioRemove
    , MsgFileioWriteReq
    , msgFileioWriteReqToString
    , msgFileioWriteReq
    , MsgFileioWriteResp
    , msgFileioWriteRespToString
    , msgFileioWriteResp
    , MsgFlashDone
    , msgFlashDoneToString
    , msgFlashDone
    , MsgFlashErase
    , msgFlashEraseToString
    , msgFlashErase
    , MsgFlashProgram
    , msgFlashProgramToString
    , msgFlashProgram
    , MsgFlashReadReq
    , msgFlashReadReqToString
    , msgFlashReadReq
    , MsgFlashReadResp
    , msgFlashReadRespToString
    , msgFlashReadResp
    , MsgFrontEndGain
    , msgFrontEndGainToString
    , msgFrontEndGain
    , MsgFwd
    , msgFwdToString
    , msgFwd
    , MsgGloBiases
    , msgGloBiasesToString
    , msgGloBiases
    , MsgGnssCapb
    , msgGnssCapbToString
    , msgGnssCapb
    , MsgGPSTime
    , msgGPSTimeToString
    , msgGPSTime
    , MsgGroupDelay
    , msgGroupDelayToString
    , msgGroupDelay
    , MsgHeartbeat
    , msgHeartbeatToString
    , msgHeartbeat
    , MsgIarState
    , msgIarStateToString
    , msgIarState
    , MsgImuAux
    , msgImuAuxToString
    , msgImuAux
    , MsgImuRaw
    , msgImuRawToString
    , msgImuRaw
    , MsgInsStatus
    , msgInsStatusToString
    , msgInsStatus
    , MsgIono
    , msgIonoToString
    , msgIono
    , MsgLinuxCPUState
    , msgLinuxCPUStateToString
    , msgLinuxCPUState
    , MsgLinuxMemState
    , msgLinuxMemStateToString
    , msgLinuxMemState
    , MsgLinuxProcessFdCount
    , msgLinuxProcessFdCountToString
    , msgLinuxProcessFdCount
    , MsgLinuxProcessFdSummary
    , msgLinuxProcessFdSummaryToString
    , msgLinuxProcessFdSummary
    , MsgLinuxProcessSocketCounts
    , msgLinuxProcessSocketCountsToString
    , msgLinuxProcessSocketCounts
    , MsgLinuxProcessSocketQueues
    , msgLinuxProcessSocketQueuesToString
    , msgLinuxProcessSocketQueues
    , MsgLinuxSocketUsage
    , msgLinuxSocketUsageToString
    , msgLinuxSocketUsage
    , MsgLinuxSysState
    , msgLinuxSysStateToString
    , msgLinuxSysState
    , MsgLog
    , msgLogToString
    , msgLog
    , MsgM25FlashWriteStatus
    , msgM25FlashWriteStatusToString
    , msgM25FlashWriteStatus
    , MsgMagRaw
    , msgMagRawToString
    , msgMagRaw
    , MsgMaskSatellite
    , msgMaskSatelliteToString
    , msgMaskSatellite
    , MsgMeasurementState
    , msgMeasurementStateToString
    , msgMeasurementState
    , MsgNapDeviceDnaReq
    , msgNapDeviceDnaReqToString
    , msgNapDeviceDnaReq
    , MsgNapDeviceDnaResp
    , msgNapDeviceDnaRespToString
    , msgNapDeviceDnaResp
    , MsgNdbEvent
    , msgNdbEventToString
    , msgNdbEvent
    , MsgNetworkBandwidthUsage
    , msgNetworkBandwidthUsageToString
    , msgNetworkBandwidthUsage
    , MsgNetworkStateReq
    , msgNetworkStateReqToString
    , msgNetworkStateReq
    , MsgNetworkStateResp
    , msgNetworkStateRespToString
    , msgNetworkStateResp
    , MsgObs
    , msgObsToString
    , msgObs
    , MsgOdometry
    , msgOdometryToString
    , msgOdometry
    , MsgOrientEuler
    , msgOrientEulerToString
    , msgOrientEuler
    , MsgOrientQuat
    , msgOrientQuatToString
    , msgOrientQuat
    , MsgOsr
    , msgOsrToString
    , msgOsr
    , MsgPosECEFCov
    , msgPosECEFCovToString
    , msgPosECEFCov
    , MsgPosECEF
    , msgPosECEFToString
    , msgPosECEF
    , MsgPosLLHCov
    , msgPosLLHCovToString
    , msgPosLLHCov
    , MsgPosLLH
    , msgPosLLHToString
    , msgPosLLH
    , MsgResetFilters
    , msgResetFiltersToString
    , msgResetFilters
    , MsgReset
    , msgResetToString
    , msgReset
    , MsgSbasRaw
    , msgSbasRawToString
    , msgSbasRaw
    , MsgSetTime
    , msgSetTimeToString
    , msgSetTime
    , MsgSettingsReadByIndexDone
    , msgSettingsReadByIndexDoneToString
    , msgSettingsReadByIndexDone
    , MsgSettingsReadByIndexReq
    , msgSettingsReadByIndexReqToString
    , msgSettingsReadByIndexReq
    , MsgSettingsReadByIndexResp
    , msgSettingsReadByIndexRespToString
    , msgSettingsReadByIndexResp
    , MsgSettingsReadReq
    , msgSettingsReadReqToString
    , msgSettingsReadReq
    , MsgSettingsReadResp
    , msgSettingsReadRespToString
    , msgSettingsReadResp
    , MsgSettingsRegister
    , msgSettingsRegisterToString
    , msgSettingsRegister
    , MsgSettingsRegisterResp
    , msgSettingsRegisterRespToString
    , msgSettingsRegisterResp
    , MsgSettingsSave
    , msgSettingsSaveToString
    , msgSettingsSave
    , MsgSettingsWrite
    , msgSettingsWriteToString
    , msgSettingsWrite
    , MsgSettingsWriteResp
    , msgSettingsWriteRespToString
    , msgSettingsWriteResp
    , MsgSpecan
    , msgSpecanToString
    , msgSpecan
    , MsgSsrCodeBiases
    , msgSsrCodeBiasesToString
    , msgSsrCodeBiases
    , MsgSsrGriddedCorrection
    , msgSsrGriddedCorrectionToString
    , msgSsrGriddedCorrection
    , MsgSsrGridDefinition
    , msgSsrGridDefinitionToString
    , msgSsrGridDefinition
    , MsgSsrOrbitClock
    , msgSsrOrbitClockToString
    , msgSsrOrbitClock
    , MsgSsrPhaseBiases
    , msgSsrPhaseBiasesToString
    , msgSsrPhaseBiases
    , MsgSsrStecCorrection
    , msgSsrStecCorrectionToString
    , msgSsrStecCorrection
    , MsgStartup
    , msgStartupToString
    , msgStartup
    , MsgStmFlashLockSector
    , msgStmFlashLockSectorToString
    , msgStmFlashLockSector
    , MsgStmFlashUnlockSector
    , msgStmFlashUnlockSectorToString
    , msgStmFlashUnlockSector
    , MsgStmUniqueIDReq
    , msgStmUniqueIDReqToString
    , msgStmUniqueIDReq
    , MsgStmUniqueIDResp
    , msgStmUniqueIDRespToString
    , msgStmUniqueIDResp
    , MsgSvAzEl
    , msgSvAzElToString
    , msgSvAzEl
    , MsgThreadState
    , msgThreadStateToString
    , msgThreadState
    , MsgTrackingIq
    , msgTrackingIqToString
    , msgTrackingIq
    , MsgTrackingState
    , msgTrackingStateToString
    , msgTrackingState
    , MsgUARTState
    , msgUARTStateToString
    , msgUARTState
    , MsgUserData
    , msgUserDataToString
    , msgUserData
    , MsgUTCTime
    , msgUTCTimeToString
    , msgUTCTime
    , MsgVelBody
    , msgVelBodyToString
    , msgVelBody
    , MsgVelECEFCov
    , msgVelECEFCovToString
    , msgVelECEFCov
    , MsgVelECEF
    , msgVelECEFToString
    , msgVelECEF
    , MsgVelNEDCov
    , msgVelNEDCovToString
    , msgVelNEDCov
    , MsgVelNED
    , msgVelNEDToString
    , msgVelNED
    , NetworkUsage
    , networkUsageToString
    , networkUsage
    , ObservationHeader
    , observationHeaderToString
    , observationHeader
    , PackedObsContent
    , packedObsContentToString
    , packedObsContent
    , PackedOsrContent
    , packedOsrContentToString
    , packedOsrContent
    , Period
    , periodToString
    , period
    , PhaseBiasesContent
    , phaseBiasesContentToString
    , phaseBiasesContent
    , STECHeader
    , stecHeaderToString
    , stecHeader
    , STECResidual
    , stecResidualToString
    , stecResidual
    , STECSatElement
    , stecSatElementToString
    , stecSatElement
    , SvAzEl
    , svAzElToString
    , svAzEl
    , SvID
    , svIDToString
    , svID
    , TrackingChannelCorrelation
    , trackingChannelCorrelationToString
    , trackingChannelCorrelation
    , TrackingChannelState
    , trackingChannelStateToString
    , trackingChannelState
    , TroposphericDelayCorrection
    , troposphericDelayCorrectionToString
    , troposphericDelayCorrection
    , UARTChannel
    , uartChannelToString
    , uartChannel
    )

import Json.Decode as Jdec
import Json.Decode.Pipeline as Jpipe
import Json.Encode as Jenc
import Dict exposing (Dict, map, toList)
import Array exposing (Array, map)

type alias MsgAlmanac = Dict String Jdec.Value

type alias MsgBootloaderHandshakeReq = Dict String Jdec.Value

type alias MsgCwResults = Dict String Jdec.Value

type alias MsgCwStart = Dict String Jdec.Value

type alias MsgNapDeviceDnaReq = Dict String Jdec.Value

type alias MsgNetworkStateReq = Dict String Jdec.Value

type alias MsgSetTime = Dict String Jdec.Value

type alias MsgSettingsReadByIndexDone = Dict String Jdec.Value

type alias MsgSettingsSave = Dict String Jdec.Value

type alias MsgStmUniqueIDReq = Dict String Jdec.Value

{-| This message describes the results from an attempted GPS signal,
acquisition search for a satellite PRN over a code phase/carrier,
frequency range. It contains the parameters of the point in the,
acquisition search space with the best carrier-to-noise (CN/0),
ratio.
-}
type alias MsgAcqResult =
    { cf : Float
    , cn0 : Float
    , cp : Float
    , sid : GnssSignal
    }

{-| Signal identifier containing constellation, band, and satellite identifier -}
type alias GnssSignal =
    { code : Int
    , sat : Int
    }

{-| The message describes all SV profiles during acquisition time.,
The message is used to debug and measure the performance.
-}
type alias MsgAcqSvProfile =
    { acqSvProfile : Array AcqSvProfile
    }

{-| Profile for a specific SV for debugging purposes,
The message describes SV profile during acquisition time.,
The message is used to debug and measure the performance.
-}
type alias AcqSvProfile =
    { binWidth : Int
    , cf : Int
    , cfMax : Int
    , cfMin : Int
    , cn0 : Int
    , cp : Int
    , intTime : Int
    , jobType : Int
    , sid : GnssSignal
    , status : Int
    , timeSpent : Int
    , timestamp : Int
    }

{-| This message reports the Age of the corrections used for the current,
Differential solution
-}
type alias MsgAgeCorrections =
    { age : Int
    , tow : Int
    }

{-| The almanac message returns a set of satellite orbit parameters. Almanac,
data is not very precise and is considered valid for up to several months.,
Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and,
almanac" for details.
-}
type alias MsgAlmanacGlo =
    { common : AlmanacCommonContent
    , epsilon : Float
    , i : Float
    , lambdaNa : Float
    , omega : Float
    , t : Float
    , tDot : Float
    , tLambdaNa : Float
    }

type alias AlmanacCommonContent =
    { fitInterval : Int
    , healthBits : Int
    , sid : GnssSignal
    , toa : GpsTimeSEC
    , ura : Float
    , valid : Int
    }

{-| A GPS time, defined as the number of,
seconds since beginning of the week on the Saturday/Sunday,
transition.
-}
type alias GpsTimeSEC =
    { tow : Int
    , wn : Int
    }

{-| The almanac message returns a set of satellite orbit parameters. Almanac,
data is not very precise and is considered valid for up to several months.,
Please see the Navstar GPS Space Segment/Navigation user interfaces,
(ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
-}
type alias MsgAlmanacGPS =
    { af0 : Float
    , af1 : Float
    , common : AlmanacCommonContent
    , ecc : Float
    , inc : Float
    , m0 : Float
    , omega0 : Float
    , omegadot : Float
    , sqrta : Float
    , w : Float
    }

{-| This message reports the orientation rates in the vehicle body frame. ,
The values represent the measurements a strapped down gyroscope would ,
make and are not equivalent to the time derivative of the Euler angles.,
The orientation and origin of the user frame is specified via device settings.,
By convention, the vehicle x-axis is expected to be aligned with the forward,
direction, while the vehicle y-axis is expected to be aligned with the right,
direction, and the vehicle z-axis should be aligned with the down direction.,
This message will only be available in future INS versions of Swift Products ,
and is not produced by Piksi Multi or Duro.
-}
type alias MsgAngularRate =
    { flags : Int
    , tow : Int
    , x : Int
    , y : Int
    , z : Int
    }

{-| This message reports the baseline solution in Earth Centered,
Earth Fixed (ECEF) coordinates. This baseline is the relative,
vector distance from the base station to the rover receiver. The,
full GPS time is given by the preceding MSG_GPS_TIME with the,
matching time-of-week (tow).
-}
type alias MsgBaselineECEF =
    { accuracy : Int
    , flags : Int
    , nSats : Int
    , tow : Int
    , x : Int
    , y : Int
    , z : Int
    }

{-| This message reports the baseline heading pointing from the base station,
to the rover relative to True North. The full GPS time is given by the,
preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended,
that time-matched RTK mode is used when the base station is moving.
-}
type alias MsgBaselineHeading =
    { flags : Int
    , heading : Int
    , nSats : Int
    , tow : Int
    }

{-| This message reports the baseline solution in North East Down,
(NED) coordinates. This baseline is the relative vector distance,
from the base station to the rover receiver, and NED coordinate,
system is defined at the local WGS84 tangent plane centered at the,
base station position.  The full GPS time is given by the,
preceding MSG_GPS_TIME with the matching time-of-week (tow).
-}
type alias MsgBaselineNED =
    { d : Int
    , e : Int
    , flags : Int
    , hAccuracy : Int
    , n : Int
    , nSats : Int
    , tow : Int
    , vAccuracy : Int
    }

{-| The base station position message is the position reported by,
the base station itself in absolute Earth Centered Earth Fixed,
coordinates. It is used for pseudo-absolute RTK positioning, and,
is required to be a high-accuracy surveyed location of the base,
station. Any error here will result in an error in the,
pseudo-absolute position output.
-}
type alias MsgBasePosECEF =
    { x : Float
    , y : Float
    , z : Float
    }

{-| The base station position message is the position reported by,
the base station itself. It is used for pseudo-absolute RTK,
positioning, and is required to be a high-accuracy surveyed,
location of the base station. Any error here will result in an,
error in the pseudo-absolute position output.
-}
type alias MsgBasePosLLH =
    { height : Float
    , lat : Float
    , lon : Float
    }

{-| The handshake message response from the device establishes a,
handshake between the device bootloader and the host. The,
request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The,
payload contains the bootloader version number and the SBP,
protocol version number.
-}
type alias MsgBootloaderHandshakeResp =
    { flags : Int
    , version : String
    }

{-| The host initiates the bootloader to jump to the application. -}
type alias MsgBootloaderJumpToApp =
    { jump : Int
    }

{-| If a cell modem is present on a piksi device, this message,
will be send periodically to update the host on the status,
of the modem and its various parameters.
-}
type alias MsgCellModemStatus =
    { signalErrorRate : Float
    , signalStrength : Int
    }

{-| Returns the standard output and standard error of the,
command requested by MSG_COMMAND_REQ.,
The sequence number can be used to filter for filtering,
the correct command.
-}
type alias MsgCommandOutput =
    { line : String
    , sequence : Int
    }

{-| Request the recipient to execute an command.,
Output will be sent in MSG_LOG messages, and the exit,
code will be returned with MSG_COMMAND_RESP.
-}
type alias MsgCommandReq =
    { command : String
    , sequence : Int
    }

{-| The response to MSG_COMMAND_REQ with the return code of,
the command.  A return code of zero indicates success.
-}
type alias MsgCommandResp =
    { code : Int
    , sequence : Int
    }

{-| The CSAC telemetry message has an implementation defined telemetry string,
from a device. It is not produced or available on general Swift Products.,
It is intended to be a low rate message for status purposes.
-}
type alias MsgCsacTelemetry =
    { id : Int
    , telemetry : String
    }

{-| The CSAC telemetry message provides labels for each member of the string,
produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower,
rate than the MSG_CSAC_TELEMETRY.
-}
type alias MsgCsacTelemetryLabels =
    { id : Int
    , telemetryLabels : String
    }

{-| This message contains temperature and voltage level measurements from the,
processor's monitoring system and the RF frontend die temperature if,
available.
-}
type alias MsgDeviceMonitor =
    { cpuTemperature : Int
    , cpuVaux : Int
    , cpuVint : Int
    , devVin : Int
    , feTemperature : Int
    }

{-| This message provides information about the receipt of Differential,
corrections.  It is expected to be sent with each receipt of a complete,
corrections packet.
-}
type alias MsgDgnssStatus =
    { flags : Int
    , latency : Int
    , numSignals : Int
    , source : String
    }

{-| This dilution of precision (DOP) message describes the effect of,
navigation satellite geometry on positional measurement,
precision.  The flags field indicated whether the DOP reported,
corresponds to differential or SPP solution.
-}
type alias MsgDops =
    { flags : Int
    , gdop : Int
    , hdop : Int
    , pdop : Int
    , tdop : Int
    , tow : Int
    , vdop : Int
    }

{-| The ephemeris message returns a set of satellite orbit,
parameters that is used to calculate BDS satellite position,,
velocity, and clock offset. Please see the BeiDou Navigation,
Satellite System SIS-ICD Version 2.1, Table 5-9 for more details.
-}
type alias MsgEphemerisBds =
    { af0 : Float
    , af1 : Float
    , af2 : Float
    , cIC : Float
    , cIs : Float
    , cRC : Float
    , cRs : Float
    , cUc : Float
    , cUs : Float
    , common : EphemerisCommonContent
    , dn : Float
    , ecc : Float
    , inc : Float
    , incDot : Float
    , iodc : Int
    , iode : Int
    , m0 : Float
    , omega0 : Float
    , omegadot : Float
    , sqrta : Float
    , tgd1 : Float
    , tgd2 : Float
    , toc : GpsTimeSEC
    , w : Float
    }

type alias EphemerisCommonContent =
    { fitInterval : Int
    , healthBits : Int
    , sid : GnssSignal
    , toe : GpsTimeSEC
    , ura : Float
    , valid : Int
    }

{-| The ephemeris message returns a set of satellite orbit,
parameters that is used to calculate Galileo satellite position,,
velocity, and clock offset. Please see the Signal In Space ICD,
OS SIS ICD, Issue 1.3, December 2016 for more details.
-}
type alias MsgEphemerisGal =
    { af0 : Float
    , af1 : Float
    , af2 : Float
    , bgdE1E5A : Float
    , bgdE1E5B : Float
    , cIC : Float
    , cIs : Float
    , cRC : Float
    , cRs : Float
    , cUc : Float
    , cUs : Float
    , common : EphemerisCommonContent
    , dn : Float
    , ecc : Float
    , inc : Float
    , incDot : Float
    , iodc : Int
    , iode : Int
    , m0 : Float
    , omega0 : Float
    , omegadot : Float
    , source : Int
    , sqrta : Float
    , toc : GpsTimeSEC
    , w : Float
    }

{-| The ephemeris message returns a set of satellite orbit,
parameters that is used to calculate GLO satellite position,,
velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5,
Characteristics of words of immediate information (ephemeris parameters)",
for more details.
-}
type alias MsgEphemerisGlo =
    { acc : Array Float
    , common : EphemerisCommonContent
    , dTau : Float
    , fcn : Int
    , gamma : Float
    , iod : Int
    , pos : Array Float
    , tau : Float
    , vel : Array Float
    }

{-| The ephemeris message returns a set of satellite orbit,
parameters that is used to calculate GPS satellite position,,
velocity, and clock offset. Please see the Navstar GPS,
Space Segment/Navigation user interfaces (ICD-GPS-200, Table,
20-III) for more details.
-}
type alias MsgEphemerisGPS =
    { af0 : Float
    , af1 : Float
    , af2 : Float
    , cIC : Float
    , cIs : Float
    , cRC : Float
    , cRs : Float
    , cUc : Float
    , cUs : Float
    , common : EphemerisCommonContent
    , dn : Float
    , ecc : Float
    , inc : Float
    , incDot : Float
    , iodc : Int
    , iode : Int
    , m0 : Float
    , omega0 : Float
    , omegadot : Float
    , sqrta : Float
    , tgd : Float
    , toc : GpsTimeSEC
    , w : Float
    }

{-| The ephemeris message returns a set of satellite orbit,
parameters that is used to calculate QZSS satellite position,,
velocity, and clock offset.
-}
type alias MsgEphemerisQzss =
    { af0 : Float
    , af1 : Float
    , af2 : Float
    , cIC : Float
    , cIs : Float
    , cRC : Float
    , cRs : Float
    , cUc : Float
    , cUs : Float
    , common : EphemerisCommonContent
    , dn : Float
    , ecc : Float
    , inc : Float
    , incDot : Float
    , iodc : Int
    , iode : Int
    , m0 : Float
    , omega0 : Float
    , omegadot : Float
    , sqrta : Float
    , tgd : Float
    , toc : GpsTimeSEC
    , w : Float
    }

type alias MsgEphemerisSbas =
    { aGf0 : Float
    , aGf1 : Float
    , acc : Array Float
    , common : EphemerisCommonContent
    , pos : Array Float
    , vel : Array Float
    }

{-| Reports detection of an external event, the GPS time it occurred,,
which pin it was and whether it was rising or falling.
-}
type alias MsgEXTEvent =
    { flags : Int
    , nsResidual : Int
    , pin : Int
    , tow : Int
    , wn : Int
    }

{-| Requests advice on the optimal configuration for a FileIO ,
transfer.  Newer version of FileIO can support greater,
throughput by supporting a large window of FileIO data,
that can be in-flight during read or write operations.
-}
type alias MsgFileioConfigReq =
    { sequence : Int
    }

{-| The advice on the optimal configuration for a FileIO,
transfer.  Newer version of FileIO can support greater,
throughput by supporting a large window of FileIO data,
that can be in-flight during read or write operations.
-}
type alias MsgFileioConfigResp =
    { batchSize : Int
    , fileioVersion : Int
    , sequence : Int
    , windowSize : Int
    }

{-| The read directory message lists the files in a directory on the,
device's onboard flash file system.  The offset parameter can be,
used to skip the first n elements of the file list. Returns a,
MSG_FILEIO_READ_DIR_RESP message containing the directory,
listings as a NULL delimited list. The listing is chunked over,
multiple SBP packets. The sequence number in the request will be,
returned in the response.  If message is invalid, a followup,
MSG_PRINT message will print "Invalid fileio read message".,
A device will only respond to this message when it is received,
from sender ID 0x42.
-}
type alias MsgFileioReadDirReq =
    { dirname : String
    , offset : Int
    , sequence : Int
    }

{-| The read directory message lists the files in a directory on the,
device's onboard flash file system. Message contains the directory,
listings as a NULL delimited list. The listing is chunked over,
multiple SBP packets and the end of the list is identified by an,
entry containing just the character 0xFF. The sequence number in,
the response is preserved from the request.
-}
type alias MsgFileioReadDirResp =
    { contents : Array Int
    , sequence : Int
    }

{-| The file read message reads a certain length (up to 255 bytes),
from a given offset into a file, and returns the data in a,
MSG_FILEIO_READ_RESP message where the message length field,
indicates how many bytes were succesfully read.The sequence,
number in the request will be returned in the response.,
If the message is invalid, a followup MSG_PRINT message will,
print "Invalid fileio read message". A device will only respond,
to this message when it is received from sender ID 0x42.
-}
type alias MsgFileioReadReq =
    { chunkSize : Int
    , filename : String
    , offset : Int
    , sequence : Int
    }

{-| The file read message reads a certain length (up to 255 bytes),
from a given offset into a file, and returns the data in a,
message where the message length field indicates how many bytes,
were succesfully read. The sequence number in the response is,
preserved from the request.
-}
type alias MsgFileioReadResp =
    { contents : Array Int
    , sequence : Int
    }

{-| The file remove message deletes a file from the file system.,
If the message is invalid, a followup MSG_PRINT message will,
print "Invalid fileio remove message". A device will only,
process this message when it is received from sender ID 0x42.
-}
type alias MsgFileioRemove =
    { filename : String
    }

{-| The file write message writes a certain length (up to 255 bytes),
of data to a file at a given offset. Returns a copy of the,
original MSG_FILEIO_WRITE_RESP message to check integrity of,
the write. The sequence number in the request will be returned,
in the response. If message is invalid, a followup MSG_PRINT,
message will print "Invalid fileio write message". A device will,
only  process this message when it is received from sender ID,
0x42.
-}
type alias MsgFileioWriteReq =
    { data : Array Int
    , filename : String
    , offset : Int
    , sequence : Int
    }

{-| The file write message writes a certain length (up to 255 bytes),
of data to a file at a given offset. The message is a copy of the,
original MSG_FILEIO_WRITE_REQ message to check integrity of the,
write. The sequence number in the response is preserved from the,
request.
-}
type alias MsgFileioWriteResp =
    { sequence : Int
    }

{-| This message defines success or failure codes for a variety of,
flash memory requests from the host to the device. Flash read,
and write messages, such as MSG_FLASH_READ_REQ, or,
MSG_FLASH_PROGRAM, may return this message on failure.
-}
type alias MsgFlashDone =
    { response : Int
    }

{-| The flash erase message from the host erases a sector of either,
the STM or M25 onboard flash memory. The device will reply with a,
MSG_FLASH_DONE message containing the return code - FLASH_OK (0),
on success or FLASH_INVALID_FLASH (1) if the flash specified is,
invalid.
-}
type alias MsgFlashErase =
    { sectorNum : Int
    , target : Int
    }

{-| The flash program message programs a set of addresses of either,
the STM or M25 flash. The device replies with either a,
MSG_FLASH_DONE message containing the return code FLASH_OK (0),
on success, or FLASH_INVALID_LEN (2) if the maximum write size,
is exceeded. Note that the sector-containing addresses must be,
erased before addresses can be programmed.
-}
type alias MsgFlashProgram =
    { addrLen : Int
    , addrStart : Array Int
    , data : Array Int
    , target : Int
    }

{-| The flash read message reads a set of addresses of either the,
STM or M25 onboard flash. The device replies with a,
MSG_FLASH_READ_RESP message containing either the read data on,
success or a MSG_FLASH_DONE message containing the return code,
FLASH_INVALID_LEN (2) if the maximum read size is exceeded or,
FLASH_INVALID_ADDR (3) if the address is outside of the allowed,
range.
-}
type alias MsgFlashReadReq =
    { addrLen : Int
    , addrStart : Array Int
    , target : Int
    }

{-| The flash read message reads a set of addresses of either the,
STM or M25 onboard flash. The device replies with a,
MSG_FLASH_READ_RESP message containing either the read data on,
success or a MSG_FLASH_DONE message containing the return code,
FLASH_INVALID_LEN (2) if the maximum read size is exceeded or,
FLASH_INVALID_ADDR (3) if the address is outside of the allowed,
range.
-}
type alias MsgFlashReadResp =
    { addrLen : Int
    , addrStart : Array Int
    , target : Int
    }

{-| This message describes the gain of each channel in the receiver frontend. Each ,
gain is encoded as a non-dimensional percentage relative to the maximum range  ,
possible for the gain stage of the frontend. By convention, each gain array ,
has 8 entries and the index of the array corresponding to the index of the rf channel ,
in the frontend. A gain of 127 percent encodes that rf channel is not present in the
hardware.,
A negative value implies an error for the particular gain stage as reported by the
frontend.
-}
type alias MsgFrontEndGain =
    { ifGain : Array Int
    , rfGain : Array Int
    }

{-| This message provides the ability to forward messages over SBP.  This may take the form,
of wrapping up SBP messages received by Piksi for logging purposes or wrapping ,
another protocol with SBP.,
,
The source identifier indicates from what interface a forwarded stream derived.,
The protocol identifier identifies what the expected protocol the forwarded msg
contains.,
Protocol 0 represents SBP and the remaining values are implementation defined.
-}
type alias MsgFwd =
    { fwdPayload : String
    , protocol : Int
    , source : Int
    }

{-| The GLONASS L1/L2 Code-Phase biases allows to perform,
GPS+GLONASS integer ambiguity resolution for baselines,
with mixed receiver types (e.g. receiver of different,
manufacturers)
-}
type alias MsgGloBiases =
    { l1CABias : Int
    , l1PBias : Int
    , l2CABias : Int
    , l2PBias : Int
    , mask : Int
    }

type alias MsgGnssCapb =
    { gc : GnssCapb
    , tNmct : GpsTimeSEC
    }

type alias GnssCapb =
    { bdsActive : Int
    , bdsB2 : Int
    , bdsB2A : Int
    , bdsD2Nav : Int
    , galActive : Int
    , galE5 : Int
    , gloActive : Int
    , gloL2Of : Int
    , gloL3 : Int
    , gpsActive : Int
    , gpsL2C : Int
    , gpsL5 : Int
    , qzssActive : Int
    , sbasActive : Int
    , sbasL5 : Int
    }

{-| This message reports the GPS time, representing the time since,
the GPS epoch began on midnight January 6, 1980 UTC. GPS time,
counts the weeks and seconds of the week. The weeks begin at the,
Saturday/Sunday transition. GPS week 0 began at the beginning of,
the GPS time scale.,
,
Within each week number, the GPS time of the week is between,
between 0 and 604800 seconds (=60*60*24*7). Note that GPS time,
does not accumulate leap seconds, and as of now, has a small,
offset from UTC. In a message stream, this message precedes a,
set of other navigation messages referenced to the same time,
(but lacking the ns field) and indicates a more precise time of,
these messages.
-}
type alias MsgGPSTime =
    { flags : Int
    , nsResidual : Int
    , tow : Int
    , wn : Int
    }

{-| Please see ICD-GPS-200 (30.3.3.3.1.1) for more details. -}
type alias MsgGroupDelay =
    { iscL1CA : Int
    , iscL2C : Int
    , sid : GnssSignal
    , tOp : GpsTimeSEC
    , tgd : Int
    , valid : Int
    }

{-| The heartbeat message is sent periodically to inform the host,
or other attached devices that the system is running. It is,
used to monitor system malfunctions. It also contains status,
flags that indicate to the host the status of the system and,
whether it is operating correctly. Currently, the expected,
heartbeat interval is 1 sec.,
,
The system error flag is used to indicate that an error has,
occurred in the system. To determine the source of the error,,
the remaining error flags should be inspected.
-}
type alias MsgHeartbeat =
    { flags : Int
    }

{-| This message reports the state of the Integer Ambiguity,
Resolution (IAR) process, which resolves unknown integer,
ambiguities from double-differenced carrier-phase measurements,
from satellite observations.
-}
type alias MsgIarState =
    { numHyps : Int
    }

{-| Auxiliary data specific to a particular IMU. The `imu_type` field will,
always be consistent but the rest of the payload is device specific and,
depends on the value of `imu_type`.
-}
type alias MsgImuAux =
    { imuConf : Int
    , imuType : Int
    , temp : Int
    }

{-| Raw data from the Inertial Measurement Unit, containing accelerometer and,
gyroscope readings. The sense of the measurements are to be aligned with ,
the indications on the device itself. Measurement units, which are specific to the,
device hardware and settings, are communicated via the MSG_IMU_AUX message.
-}
type alias MsgImuRaw =
    { accX : Int
    , accY : Int
    , accZ : Int
    , gyrX : Int
    , gyrY : Int
    , gyrZ : Int
    , tow : Int
    , towF : Int
    }

{-| The INS status message describes the state of the operation,
and initialization of the inertial navigation system.
-}
type alias MsgInsStatus =
    { flags : Int
    }

{-| The ionospheric parameters which allow the "L1 only" or "L2 only" user to,
utilize the ionospheric model for computation of the ionospheric delay.,
Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
-}
type alias MsgIono =
    { a0 : Float
    , a1 : Float
    , a2 : Float
    , a3 : Float
    , b0 : Float
    , b1 : Float
    , b2 : Float
    , b3 : Float
    , tNmct : GpsTimeSEC
    }

{-| This message indicates the process state of the top 10 heaviest,
consumers of CPU on the system.
-}
type alias MsgLinuxCPUState =
    { cmdline : String
    , index : Int
    , pcpu : Int
    , pid : Int
    , tname : String
    }

{-| This message indicates the process state of the top 10 heaviest,
consumers of memory on the system.
-}
type alias MsgLinuxMemState =
    { cmdline : String
    , index : Int
    , pid : Int
    , pmem : Int
    , tname : String
    }

{-| Top 10 list of processes with a large number of open file descriptors. -}
type alias MsgLinuxProcessFdCount =
    { cmdline : String
    , fdCount : Int
    , index : Int
    , pid : Int
    }

{-| Summary of open file descriptors on the system. -}
type alias MsgLinuxProcessFdSummary =
    { mostOpened : String
    , sysFdCount : Int
    }

{-| Top 10 list of processes with high socket counts. -}
type alias MsgLinuxProcessSocketCounts =
    { cmdline : String
    , index : Int
    , pid : Int
    , socketCount : Int
    , socketStates : Int
    , socketTypes : Int
    }

{-| Top 10 list of sockets with deep queues. -}
type alias MsgLinuxProcessSocketQueues =
    { addressOfLargest : String
    , cmdline : String
    , index : Int
    , pid : Int
    , recvQueued : Int
    , sendQueued : Int
    , socketStates : Int
    , socketTypes : Int
    }

{-| Summaries the socket usage across the system. -}
type alias MsgLinuxSocketUsage =
    { avgQueueDepth : Int
    , maxQueueDepth : Int
    , socketStateCounts : Array Int
    , socketTypeCounts : Array Int
    }

{-| This presents a summary of CPU and memory utilization. -}
type alias MsgLinuxSysState =
    { memTotal : Int
    , pcpu : Int
    , pidCount : Int
    , pmem : Int
    , procsStarting : Int
    , procsStopping : Int
    }

{-| This message contains a human-readable payload string from the,
device containing errors, warnings and informational messages at,
ERROR, WARNING, DEBUG, INFO logging levels.
-}
type alias MsgLog =
    { level : Int
    , text : String
    }

{-| The flash status message writes to the 8-bit M25 flash status,
register. The device replies with a MSG_FLASH_DONE message.
-}
type alias MsgM25FlashWriteStatus =
    { status : Array Int
    }

{-| Raw data from the magnetometer. -}
type alias MsgMagRaw =
    { magX : Int
    , magY : Int
    , magZ : Int
    , tow : Int
    , towF : Int
    }

{-| This message allows setting a mask to prevent a particular satellite,
from being used in various Piksi subsystems.
-}
type alias MsgMaskSatellite =
    { mask : Int
    , sid : GnssSignal
    }

{-| The tracking message returns a variable-length array of tracking,
channel states. It reports status and carrier-to-noise density,
measurements for all tracked satellites.
-}
type alias MsgMeasurementState =
    { states : Array MeasurementState
    }

{-| Measurement Engine tracking channel state for a specific satellite signal,
and measured signal power.,
The mesid field for Glonass can either,
carry the FCN as 100 + FCN where FCN is in [-7, +6] or,
the Slot ID (from 1 to 28)
-}
type alias MeasurementState =
    { cn0 : Int
    , mesid : GnssSignal
    }

{-| The device message from the host reads a unique device,
identifier from the SwiftNAP, an FPGA. The host requests the ID,
by sending a MSG_NAP_DEVICE_DNA_REQ message. The device,
responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the,
device ID in the payload. Note that this ID is tied to the FPGA,,
and not related to the Piksi's serial number.
-}
type alias MsgNapDeviceDnaResp =
    { dna : Array Int
    }

{-| This message is sent out when an object is stored into NDB. If needed,
message could also be sent out when fetching an object from NDB.
-}
type alias MsgNdbEvent =
    { dataSource : Int
    , event : Int
    , objectSid : GnssSignal
    , objectType : Int
    , originalSender : Int
    , recvTime : Int
    , result : Int
    , srcSid : GnssSignal
    }

{-| The bandwidth usage, a list of usage by interface. -}
type alias MsgNetworkBandwidthUsage =
    { interfaces : Array NetworkUsage
    }

{-| The bandwidth usage for each interface can be reported,
within this struct and utilize multiple fields to fully,
specify the type of traffic that is being tracked. As,
either the interval of collection or the collection time,
may vary, both a timestamp and period field is provided,,
though may not necessarily be populated with a value.
-}
type alias NetworkUsage =
    { duration : Int
    , interfaceName : String
    , rxBytes : Int
    , totalBytes : Int
    , txBytes : Int
    }

{-| The state of a network interface on the Piksi.,
Data is made to reflect output of ifaddrs struct returned by getifaddrs,
in c.
-}
type alias MsgNetworkStateResp =
    { flags : Int
    , interfaceName : String
    , ipv4Address : Array Int
    , ipv4MaskSize : Int
    , ipv6Address : Array Int
    , ipv6MaskSize : Int
    , rxBytes : Int
    , txBytes : Int
    }

{-| The GPS observations message reports all the raw pseudorange and,
carrier phase observations for the satellites being tracked by,
the device. Carrier phase observation here is represented as a,
40-bit fixed point number with Q32.8 layout (i.e. 32-bits of,
whole cycles and 8-bits of fractional cycles). The observations,
are be interoperable with 3rd party receivers and conform,
with typical RTCMv3 GNSS observations.
-}
type alias MsgObs =
    { header : ObservationHeader
    , obs : Array PackedObsContent
    }

{-| Header of a GNSS observation message. -}
type alias ObservationHeader =
    { nObs : Int
    , t : GpsTime
    }

{-| A wire-appropriate receiver clock time, defined as the time,
since the beginning of the week on the Saturday/Sunday,
transition. In most cases, observations are epoch aligned,
so ns field will be 0.
-}
type alias GpsTime =
    { nsResidual : Int
    , tow : Int
    , wn : Int
    }

{-| Pseudorange and carrier phase observation for a satellite being tracked.,
The observations are interoperable with 3rd party receivers and conform with,
typical RTCM 3.1 message GPS/GLO observations.,
,
Carrier phase observations are not guaranteed to be aligned to the RINEX 3,
or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are currently,
peformed.
-}
type alias PackedObsContent =
    { cn0 : Int
    , d : Doppler
    , flags : Int
    , l : CarrierPhase
    , lock : Int
    , p : Int
    , sid : GnssSignal
    }

{-| Doppler measurement in Hz represented as a 24-bit,
fixed point number with Q16.8 layout, i.e. 16-bits of whole,
doppler and 8-bits of fractional doppler. This doppler is defined,
as positive for approaching satellites.
-}
type alias Doppler =
    { f : Int
    , i : Int
    }

{-| Carrier phase measurement in cycles represented as a 40-bit,
fixed point number with Q32.8 layout, i.e. 32-bits of whole,
cycles and 8-bits of fractional cycles. This phase has the,
same sign as the pseudorange.
-}
type alias CarrierPhase =
    { f : Int
    , i : Int
    }

{-| Message representing the x component of vehicle velocity in the user frame at the
odometry,
reference point(s) specified by the user. The offset for the odometry reference point and
,
the definition and origin of the user frame are defined through the device settings
interface.,
There are 4 possible user-defined sources of this message  which are labeled arbitrarily
,
source 0 through 3.
-}
type alias MsgOdometry =
    { flags : Int
    , tow : Int
    , velocity : Int
    }

{-| This message reports the yaw, pitch, and roll angles of the vehicle body frame.,
The rotations should applied intrinsically in the order yaw, pitch, and roll ,
in order to rotate the from a frame aligned with the local-level NED frame ,
to the vehicle body frame.  This message will only be available in future ,
INS versions of Swift Products and is not produced by Piksi Multi or Duro.
-}
type alias MsgOrientEuler =
    { flags : Int
    , pitch : Int
    , pitchAccuracy : Float
    , roll : Int
    , rollAccuracy : Float
    , tow : Int
    , yaw : Int
    , yawAccuracy : Float
    }

{-| This message reports the quaternion vector describing the vehicle body frame's
orientation,
with respect to a local-level NED frame. The components of the vector should sum to a
unit,
vector assuming that the LSB of each component as a value of 2^-31. This message will
only,
be available in future INS versions of Swift Products and is not produced by Piksi Multi
,
or Duro.
-}
type alias MsgOrientQuat =
    { flags : Int
    , tow : Int
    , w : Int
    , wAccuracy : Float
    , x : Int
    , xAccuracy : Float
    , y : Int
    , yAccuracy : Float
    , z : Int
    , zAccuracy : Float
    }

{-| The OSR message contains network corrections in an observation-like format -}
type alias MsgOsr =
    { header : ObservationHeader
    , obs : Array PackedOsrContent
    }

{-| Pseudorange and carrier phase network corrections for a satellite signal. -}
type alias PackedOsrContent =
    { flags : Int
    , ionoStd : Int
    , l : CarrierPhase
    , lock : Int
    , p : Int
    , rangeStd : Int
    , sid : GnssSignal
    , tropoStd : Int
    }

{-| The position solution message reports absolute Earth Centered,
Earth Fixed (ECEF) coordinates and the status (single point vs,
pseudo-absolute RTK) of the position solution. The message also,
reports the upper triangular portion of the 3x3 covariance matrix.,
If the receiver knows the surveyed position of the base station and has,
an RTK solution, this reports a pseudo-absolute position,
solution using the base station position and the rover's RTK,
baseline vector. The full GPS time is given by the preceding,
MSG_GPS_TIME with the matching time-of-week (tow).
-}
type alias MsgPosECEFCov =
    { covXX : Float
    , covXY : Float
    , covXZ : Float
    , covYY : Float
    , covYZ : Float
    , covZZ : Float
    , flags : Int
    , nSats : Int
    , tow : Int
    , x : Float
    , y : Float
    , z : Float
    }

{-| The position solution message reports absolute Earth Centered,
Earth Fixed (ECEF) coordinates and the status (single point vs,
pseudo-absolute RTK) of the position solution. If the rover,
receiver knows the surveyed position of the base station and has,
an RTK solution, this reports a pseudo-absolute position,
solution using the base station position and the rover's RTK,
baseline vector. The full GPS time is given by the preceding,
MSG_GPS_TIME with the matching time-of-week (tow).
-}
type alias MsgPosECEF =
    { accuracy : Int
    , flags : Int
    , nSats : Int
    , tow : Int
    , x : Float
    , y : Float
    , z : Float
    }

{-| This position solution message reports the absolute geodetic,
coordinates and the status (single point vs pseudo-absolute RTK),
of the position solution as well as the upper triangle of the 3x3,
covariance matrix.  The position information and Fix Mode flags should,
follow the MSG_POS_LLH message.  Since the covariance matrix is computed,
in the local-level North, East, Down frame, the covariance terms follow,
with that convention. Thus, covariances are reported against the "downward",
measurement and care should be taken with the sign convention.
-}
type alias MsgPosLLHCov =
    { covDD : Float
    , covED : Float
    , covEE : Float
    , covND : Float
    , covNE : Float
    , covNN : Float
    , flags : Int
    , height : Float
    , lat : Float
    , lon : Float
    , nSats : Int
    , tow : Int
    }

{-| This position solution message reports the absolute geodetic,
coordinates and the status (single point vs pseudo-absolute RTK),
of the position solution. If the rover receiver knows the,
surveyed position of the base station and has an RTK solution,,
this reports a pseudo-absolute position solution using the base,
station position and the rover's RTK baseline vector. The full,
GPS time is given by the preceding MSG_GPS_TIME with the,
matching time-of-week (tow).
-}
type alias MsgPosLLH =
    { flags : Int
    , hAccuracy : Int
    , height : Float
    , lat : Float
    , lon : Float
    , nSats : Int
    , tow : Int
    , vAccuracy : Int
    }

{-| This message resets either the DGNSS Kalman filters or Integer,
Ambiguity Resolution (IAR) process.
-}
type alias MsgResetFilters =
    { filter : Int
    }

{-| This message from the host resets the Piksi back into the,
bootloader.
-}
type alias MsgReset =
    { flags : Int
    }

{-| This message is sent once per second per SBAS satellite. ME checks the,
parity of the data block and sends only blocks that pass the check.
-}
type alias MsgSbasRaw =
    { data : Array Int
    , messageType : Int
    , sid : GnssSignal
    , tow : Int
    }

{-| The settings message for iterating through the settings,
values. A device will respond to this message with a ,
"MSG_SETTINGS_READ_BY_INDEX_RESP".
-}
type alias MsgSettingsReadByIndexReq =
    { index : Int
    }

{-| The settings message that reports the value of a setting at an index.,
,
In the string field, it reports NULL-terminated and delimited string,
with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where,
the '\0' escape sequence denotes the NULL character and where quotation,
marks are omitted. The FORMAT_TYPE field is optional and denotes,
possible string values of the setting as a hint to the user. If,
included, the format type portion of the string has the format,
"enum:value1,value2,value3". An example string that could be sent from,
the device is "simulator\0enabled\0True\0enum:True,False\0"
-}
type alias MsgSettingsReadByIndexResp =
    { index : Int
    , setting : String
    }

{-| The setting message that reads the device configuration. The string,
field is a NULL-terminated and NULL-delimited string with contents,
"SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the,
NULL character and where quotation marks are omitted. An example,
string that could be sent to a device is "solution\0soln_freq\0". A,
device will only respond to this message when it is received from,
sender ID 0x42. A device should respond with a MSG_SETTINGS_READ_RESP,
message (msg_id 0x00A5).
-}
type alias MsgSettingsReadReq =
    { setting : String
    }

{-| The setting message wich which the device responds after a,
MSG_SETTING_READ_REQ is sent to device. The string field is a,
NULL-terminated and NULL-delimited string with contents,
"SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence,
denotes the NULL character and where quotation marks are omitted. An,
example string that could be sent from device is,
"solution\0soln_freq\010\0".
-}
type alias MsgSettingsReadResp =
    { setting : String
    }

{-| This message registers the presence and default value of a setting,
with a settings daemon.  The host should reply with MSG_SETTINGS_WRITE,
for this setting to set the initial value.
-}
type alias MsgSettingsRegister =
    { setting : String
    }

{-| This message responds to setting registration with the effective value.,
The effective value shall differ from the given default value if setting,
was already registered or is available in the permanent setting storage,
and had a different value.
-}
type alias MsgSettingsRegisterResp =
    { setting : String
    , status : Int
    }

{-| The setting message writes the device configuration for a particular,
setting via A NULL-terminated and NULL-delimited string with contents,
"SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes ,
the NULL character and where quotation marks are omitted. A device will,
only process to this message when it is received from sender ID 0x42.,
An example string that could be sent to a device is,
"solution\0soln_freq\010\0".
-}
type alias MsgSettingsWrite =
    { setting : String
    }

{-| Return the status of a write request with the new value of the,
setting.  If the requested value is rejected, the current value,
will be returned. The string field is a NULL-terminated and NULL-delimited,
string with contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0',
escape sequence denotes the NULL character and where quotation marks,
are omitted. An example string that could be sent from device is,
"solution\0soln_freq\010\0".
-}
type alias MsgSettingsWriteResp =
    { setting : String
    , status : Int
    }

{-| Spectrum analyzer packet. -}
type alias MsgSpecan =
    { amplitudeRef : Float
    , amplitudeUnit : Float
    , amplitudeValue : Array Int
    , channelTag : Int
    , freqRef : Float
    , freqStep : Float
    , t : GpsTime
    }

{-| The precise code biases message is to be added,
to the pseudorange of the corresponding signal,
to get corrected pseudorange. It is typically,
an equivalent to the 1059 and 1065 RTCM message types
-}
type alias MsgSsrCodeBiases =
    { biases : Array CodeBiasesContent
    , iodSsr : Int
    , sid : GnssSignal
    , time : GpsTimeSEC
    , updateInterval : Int
    }

{-| Code biases are to be added to pseudorange.,
The corrections conform with typical RTCMv3 MT1059 and 1065.
-}
type alias CodeBiasesContent =
    { code : Int
    , value : Int
    }

{-| STEC residuals are per space vehicle, tropo is not.,
It is typically equivalent to the QZSS CLAS Sub Type 9 messages
-}
type alias MsgSsrGriddedCorrection =
    { element : GridElement
    , header : GriddedCorrectionHeader
    }

{-| Contains one tropo delay, plus STEC residuals for each satellite at the,
grid point.
-}
type alias GridElement =
    { index : Int
    , stecResiduals : Array STECResidual
    , tropoDelayCorrection : TroposphericDelayCorrection
    }

{-| STEC residual for the given satellite at the grid point. -}
type alias STECResidual =
    { residual : Int
    , svID : SvID
    }

{-| A (Constellation ID, satellite ID) tuple that uniquely identifies,
a space vehicle
-}
type alias SvID =
    { constellation : Int
    , satID : Int
    }

{-| Troposphere vertical delays at the grid point. -}
type alias TroposphericDelayCorrection =
    { hydro : Int
    , wet : Int
    }

{-| The 3GPP message contains nested variable length arrays,
which are not suppported in SBP, so each grid point will,
be identified by the index.
-}
type alias GriddedCorrectionHeader =
    { iodAtmo : Int
    , numMsgs : Int
    , seqNum : Int
    , time : GpsTimeSEC
    , tropoQualityIndicator : Int
    , updateInterval : Int
    }

{-| Based on the 3GPP proposal R2-1906781 which is in turn based on,
OMA-LPPe-ValidityArea from OMA-TS-LPPe-V2_0-20141202-C
-}
type alias MsgSsrGridDefinition =
    { header : GridDefinitionHeader
    , rleList : Array Int
    }

{-| Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.,
Also includes an RLE encoded validity list.
-}
type alias GridDefinitionHeader =
    { areaWidth : Int
    , latNwCornerEnc : Int
    , lonNwCornerEnc : Int
    , numMsgs : Int
    , regionSizeInverse : Int
    , seqNum : Int
    }

{-| The precise orbit and clock correction message is,
to be applied as a delta correction to broadcast,
ephemeris and is typically an equivalent to the 1060,
and 1066 RTCM message types
-}
type alias MsgSsrOrbitClock =
    { along : Int
    , c0 : Int
    , c1 : Int
    , c2 : Int
    , cross : Int
    , dotAlong : Int
    , dotCross : Int
    , dotRadial : Int
    , iod : Int
    , iodSsr : Int
    , radial : Int
    , sid : GnssSignal
    , time : GpsTimeSEC
    , updateInterval : Int
    }

{-| The precise phase biases message contains the biases,
to be added to the carrier phase of the corresponding,
signal to get corrected carrier phase measurement, as,
well as the satellite yaw angle to be applied to compute,
the phase wind-up correction.,
It is typically an equivalent to the 1265 RTCM message types
-}
type alias MsgSsrPhaseBiases =
    { biases : Array PhaseBiasesContent
    , dispersiveBias : Int
    , iodSsr : Int
    , mwConsistency : Int
    , sid : GnssSignal
    , time : GpsTimeSEC
    , updateInterval : Int
    , yaw : Int
    , yawRate : Int
    }

{-| Phase biases are to be added to carrier phase measurements.,
The corrections conform with typical RTCMv3 MT1059 and 1065.
-}
type alias PhaseBiasesContent =
    { bias : Int
    , code : Int
    , discontinuityCounter : Int
    , integerIndicator : Int
    , widelaneIntegerIndicator : Int
    }

{-| The STEC per space vehicle, given as polynomial approximation for,
a given grid.  This should be combined with MSG_SSR_GRIDDED_CORRECTION,
message to get the state space representation of the atmospheric,
delay. It is typically equivalent to the QZSS CLAS Sub Type 8 messages
-}
type alias MsgSsrStecCorrection =
    { header : STECHeader
    , stecSatList : Array STECSatElement
    }

{-| A full set of STEC information will likely span multiple SBP,
messages, since SBP message a limited to 255 bytes.  The header,
is used to tie multiple SBP messages into a sequence.
-}
type alias STECHeader =
    { iodAtmo : Int
    , numMsgs : Int
    , seqNum : Int
    , time : GpsTimeSEC
    , updateInterval : Int
    }

{-| STEC polynomial for the given satellite. -}
type alias STECSatElement =
    { stecCoeff : Array Int
    , stecQualityIndicator : Int
    , svID : SvID
    }

{-| The system start-up message is sent once on system,
start-up. It notifies the host or other attached devices that,
the system has started and is now ready to respond to commands,
or configuration requests.
-}
type alias MsgStartup =
    { cause : Int
    , startupType : Int
    }

{-| The flash lock message locks a sector of the STM flash,
memory. The device replies with a MSG_FLASH_DONE message.
-}
type alias MsgStmFlashLockSector =
    { sector : Int
    }

{-| The flash unlock message unlocks a sector of the STM flash,
memory. The device replies with a MSG_FLASH_DONE message.
-}
type alias MsgStmFlashUnlockSector =
    { sector : Int
    }

{-| This message reads the device's hardcoded unique ID. The host,
requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device,
responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique,
ID in the payload..
-}
type alias MsgStmUniqueIDResp =
    { stmID : Array Int
    }

{-| Azimuth and elevation angles of all the visible satellites,
that the device does have ephemeris or almanac for.
-}
type alias MsgSvAzEl =
    { azel : Array SvAzEl
    }

{-| Satellite azimuth and elevation. -}
type alias SvAzEl =
    { az : Int
    , el : Int
    , sid : GnssSignal
    }

{-| The thread usage message from the device reports real-time,
operating system (RTOS) thread usage statistics for the named,
thread. The reported percentage values must be normalized.
-}
type alias MsgThreadState =
    { cpu : Int
    , name : String
    , stackFree : Int
    }

{-| When enabled, a tracking channel can output the correlations at each,
update interval.
-}
type alias MsgTrackingIq =
    { channel : Int
    , corrs : Array TrackingChannelCorrelation
    , sid : GnssSignal
    }

{-| Structure containing in-phase and quadrature correlation components. -}
type alias TrackingChannelCorrelation =
    { i : Int
    , q : Int
    }

{-| The tracking message returns a variable-length array of tracking,
channel states. It reports status and carrier-to-noise density,
measurements for all tracked satellites.
-}
type alias MsgTrackingState =
    { states : Array TrackingChannelState
    }

{-| Tracking channel state for a specific satellite signal and,
measured signal power.
-}
type alias TrackingChannelState =
    { cn0 : Int
    , fcn : Int
    , sid : GnssSignal
    }

{-| The UART message reports data latency and throughput of the UART,
channels providing SBP I/O. On the default Piksi configuration,,
UARTs A and B are used for telemetry radios, but can also be,
host access ports for embedded hosts, or other interfaces in,
future. The reported percentage values must be normalized.,
Observations latency and period can be used to assess the,
health of the differential corrections link. Latency provides,
the timeliness of received base observations while the,
period indicates their likelihood of transmission.
-}
type alias MsgUARTState =
    { latency : Latency
    , obsPeriod : Period
    , uartA : UARTChannel
    , uartB : UARTChannel
    , uartFtdi : UARTChannel
    }

{-| Statistics on the latency of observations received from the base,
station. As observation packets are received their GPS time is,
compared to the current GPS time calculated locally by the,
receiver to give a precise measurement of the end-to-end,
communication latency in the system.
-}
type alias Latency =
    { avg : Int
    , current : Int
    , lmax : Int
    , lmin : Int
    }

{-| Statistics on the period of observations received from the base,
station. As complete observation sets are received, their time,
of reception is compared with the prior set''s time of reception.,
This measurement provides a proxy for link quality as incomplete,
or missing sets will increase the period.  Long periods,
can cause momentary RTK solution outages.
-}
type alias Period =
    { avg : Int
    , current : Int
    , pmax : Int
    , pmin : Int
    }

{-| Throughput, utilization, and error counts on the RX/TX buffers,
of this UART channel. The reported percentage values must,
be normalized.
-}
type alias UARTChannel =
    { crcErrorCount : Int
    , ioErrorCount : Int
    , rxBufferLevel : Int
    , rxThroughput : Float
    , txBufferLevel : Int
    , txThroughput : Float
    }

{-| This message can contain any application specific user data up to a,
maximum length of 255 bytes per message.
-}
type alias MsgUserData =
    { contents : Array Int
    }

{-| This message reports the Universal Coordinated Time (UTC).  Note the flags,
which indicate the source of the UTC offset value and source of the time fix.
-}
type alias MsgUTCTime =
    { day : Int
    , flags : Int
    , hours : Int
    , minutes : Int
    , month : Int
    , ns : Int
    , seconds : Int
    , tow : Int
    , year : Int
    }

{-| This message reports the velocity in the Vehicle Body Frame. By convention,,
the x-axis should point out the nose of the vehicle and represent the forward,
direction, while as the y-axis should point out the right hand side of the vehicle.,
Since this is a right handed system, z should point out the bottom of the vehicle.,
The orientation and origin of the Vehicle Body Frame are specified via the device
settings.,
The full GPS time is given by the preceding MSG_GPS_TIME with the,
matching time-of-week (tow). This message is only produced by inertial versions of Swift,
products and is not available from Piksi Multi or Duro.
-}
type alias MsgVelBody =
    { covXX : Float
    , covXY : Float
    , covXZ : Float
    , covYY : Float
    , covYZ : Float
    , covZZ : Float
    , flags : Int
    , nSats : Int
    , tow : Int
    , x : Int
    , y : Int
    , z : Int
    }

{-| This message reports the velocity in Earth Centered Earth Fixed,
(ECEF) coordinates. The full GPS time is given by the preceding,
MSG_GPS_TIME with the matching time-of-week (tow).
-}
type alias MsgVelECEFCov =
    { covXX : Float
    , covXY : Float
    , covXZ : Float
    , covYY : Float
    , covYZ : Float
    , covZZ : Float
    , flags : Int
    , nSats : Int
    , tow : Int
    , x : Int
    , y : Int
    , z : Int
    }

{-| This message reports the velocity in Earth Centered Earth Fixed,
(ECEF) coordinates. The full GPS time is given by the preceding,
MSG_GPS_TIME with the matching time-of-week (tow).
-}
type alias MsgVelECEF =
    { accuracy : Int
    , flags : Int
    , nSats : Int
    , tow : Int
    , x : Int
    , y : Int
    , z : Int
    }

{-| This message reports the velocity in local North East Down (NED),
coordinates. The NED coordinate system is defined as the local WGS84,
tangent plane centered at the current position. The full GPS time is,
given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).,
This message is similar to the MSG_VEL_NED, but it includes the upper triangular,
portion of the 3x3 covariance matrix.
-}
type alias MsgVelNEDCov =
    { covDD : Float
    , covED : Float
    , covEE : Float
    , covND : Float
    , covNE : Float
    , covNN : Float
    , d : Int
    , e : Int
    , flags : Int
    , n : Int
    , nSats : Int
    , tow : Int
    }

{-| This message reports the velocity in local North East Down (NED),
coordinates. The NED coordinate system is defined as the local WGS84,
tangent plane centered at the current position. The full GPS time is,
given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
-}
type alias MsgVelNED =
    { d : Int
    , e : Int
    , flags : Int
    , hAccuracy : Int
    , n : Int
    , nSats : Int
    , tow : Int
    , vAccuracy : Int
    }

-- decoders and encoders

acqSvProfileToString : AcqSvProfile -> String
acqSvProfileToString r = Jenc.encode 0 (encodeAcqSvProfile r)

almanacCommonContentToString : AlmanacCommonContent -> String
almanacCommonContentToString r = Jenc.encode 0 (encodeAlmanacCommonContent r)

carrierPhaseToString : CarrierPhase -> String
carrierPhaseToString r = Jenc.encode 0 (encodeCarrierPhase r)

codeBiasesContentToString : CodeBiasesContent -> String
codeBiasesContentToString r = Jenc.encode 0 (encodeCodeBiasesContent r)

dopplerToString : Doppler -> String
dopplerToString r = Jenc.encode 0 (encodeDoppler r)

ephemerisCommonContentToString : EphemerisCommonContent -> String
ephemerisCommonContentToString r = Jenc.encode 0 (encodeEphemerisCommonContent r)

gnssCapbToString : GnssCapb -> String
gnssCapbToString r = Jenc.encode 0 (encodeGnssCapb r)

gnssSignalToString : GnssSignal -> String
gnssSignalToString r = Jenc.encode 0 (encodeGnssSignal r)

gpsTimeToString : GpsTime -> String
gpsTimeToString r = Jenc.encode 0 (encodeGpsTime r)

gpsTimeSECToString : GpsTimeSEC -> String
gpsTimeSECToString r = Jenc.encode 0 (encodeGpsTimeSEC r)

griddedCorrectionHeaderToString : GriddedCorrectionHeader -> String
griddedCorrectionHeaderToString r = Jenc.encode 0 (encodeGriddedCorrectionHeader r)

gridDefinitionHeaderToString : GridDefinitionHeader -> String
gridDefinitionHeaderToString r = Jenc.encode 0 (encodeGridDefinitionHeader r)

gridElementToString : GridElement -> String
gridElementToString r = Jenc.encode 0 (encodeGridElement r)

latencyToString : Latency -> String
latencyToString r = Jenc.encode 0 (encodeLatency r)

measurementStateToString : MeasurementState -> String
measurementStateToString r = Jenc.encode 0 (encodeMeasurementState r)

msgAcqResultToString : MsgAcqResult -> String
msgAcqResultToString r = Jenc.encode 0 (encodeMsgAcqResult r)

msgAcqSvProfileToString : MsgAcqSvProfile -> String
msgAcqSvProfileToString r = Jenc.encode 0 (encodeMsgAcqSvProfile r)

msgAgeCorrectionsToString : MsgAgeCorrections -> String
msgAgeCorrectionsToString r = Jenc.encode 0 (encodeMsgAgeCorrections r)

msgAlmanacGloToString : MsgAlmanacGlo -> String
msgAlmanacGloToString r = Jenc.encode 0 (encodeMsgAlmanacGlo r)

msgAlmanacGPSToString : MsgAlmanacGPS -> String
msgAlmanacGPSToString r = Jenc.encode 0 (encodeMsgAlmanacGPS r)

msgAlmanac : Jdec.Decoder MsgAlmanac
msgAlmanac = Jdec.dict Jdec.value

msgAlmanacToString : MsgAlmanac -> String
msgAlmanacToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgAngularRateToString : MsgAngularRate -> String
msgAngularRateToString r = Jenc.encode 0 (encodeMsgAngularRate r)

msgBaselineECEFToString : MsgBaselineECEF -> String
msgBaselineECEFToString r = Jenc.encode 0 (encodeMsgBaselineECEF r)

msgBaselineHeadingToString : MsgBaselineHeading -> String
msgBaselineHeadingToString r = Jenc.encode 0 (encodeMsgBaselineHeading r)

msgBaselineNEDToString : MsgBaselineNED -> String
msgBaselineNEDToString r = Jenc.encode 0 (encodeMsgBaselineNED r)

msgBasePosECEFToString : MsgBasePosECEF -> String
msgBasePosECEFToString r = Jenc.encode 0 (encodeMsgBasePosECEF r)

msgBasePosLLHToString : MsgBasePosLLH -> String
msgBasePosLLHToString r = Jenc.encode 0 (encodeMsgBasePosLLH r)

msgBootloaderHandshakeReq : Jdec.Decoder MsgBootloaderHandshakeReq
msgBootloaderHandshakeReq = Jdec.dict Jdec.value

msgBootloaderHandshakeReqToString : MsgBootloaderHandshakeReq -> String
msgBootloaderHandshakeReqToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgBootloaderHandshakeRespToString : MsgBootloaderHandshakeResp -> String
msgBootloaderHandshakeRespToString r = Jenc.encode 0 (encodeMsgBootloaderHandshakeResp r)

msgBootloaderJumpToAppToString : MsgBootloaderJumpToApp -> String
msgBootloaderJumpToAppToString r = Jenc.encode 0 (encodeMsgBootloaderJumpToApp r)

msgCellModemStatusToString : MsgCellModemStatus -> String
msgCellModemStatusToString r = Jenc.encode 0 (encodeMsgCellModemStatus r)

msgCommandOutputToString : MsgCommandOutput -> String
msgCommandOutputToString r = Jenc.encode 0 (encodeMsgCommandOutput r)

msgCommandReqToString : MsgCommandReq -> String
msgCommandReqToString r = Jenc.encode 0 (encodeMsgCommandReq r)

msgCommandRespToString : MsgCommandResp -> String
msgCommandRespToString r = Jenc.encode 0 (encodeMsgCommandResp r)

msgCsacTelemetryToString : MsgCsacTelemetry -> String
msgCsacTelemetryToString r = Jenc.encode 0 (encodeMsgCsacTelemetry r)

msgCsacTelemetryLabelsToString : MsgCsacTelemetryLabels -> String
msgCsacTelemetryLabelsToString r = Jenc.encode 0 (encodeMsgCsacTelemetryLabels r)

msgCwResults : Jdec.Decoder MsgCwResults
msgCwResults = Jdec.dict Jdec.value

msgCwResultsToString : MsgCwResults -> String
msgCwResultsToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgCwStart : Jdec.Decoder MsgCwStart
msgCwStart = Jdec.dict Jdec.value

msgCwStartToString : MsgCwStart -> String
msgCwStartToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgDeviceMonitorToString : MsgDeviceMonitor -> String
msgDeviceMonitorToString r = Jenc.encode 0 (encodeMsgDeviceMonitor r)

msgDgnssStatusToString : MsgDgnssStatus -> String
msgDgnssStatusToString r = Jenc.encode 0 (encodeMsgDgnssStatus r)

msgDopsToString : MsgDops -> String
msgDopsToString r = Jenc.encode 0 (encodeMsgDops r)

msgEphemerisBdsToString : MsgEphemerisBds -> String
msgEphemerisBdsToString r = Jenc.encode 0 (encodeMsgEphemerisBds r)

msgEphemerisGalToString : MsgEphemerisGal -> String
msgEphemerisGalToString r = Jenc.encode 0 (encodeMsgEphemerisGal r)

msgEphemerisGloToString : MsgEphemerisGlo -> String
msgEphemerisGloToString r = Jenc.encode 0 (encodeMsgEphemerisGlo r)

msgEphemerisGPSToString : MsgEphemerisGPS -> String
msgEphemerisGPSToString r = Jenc.encode 0 (encodeMsgEphemerisGPS r)

msgEphemerisQzssToString : MsgEphemerisQzss -> String
msgEphemerisQzssToString r = Jenc.encode 0 (encodeMsgEphemerisQzss r)

msgEphemerisSbasToString : MsgEphemerisSbas -> String
msgEphemerisSbasToString r = Jenc.encode 0 (encodeMsgEphemerisSbas r)

msgEXTEventToString : MsgEXTEvent -> String
msgEXTEventToString r = Jenc.encode 0 (encodeMsgEXTEvent r)

msgFileioConfigReqToString : MsgFileioConfigReq -> String
msgFileioConfigReqToString r = Jenc.encode 0 (encodeMsgFileioConfigReq r)

msgFileioConfigRespToString : MsgFileioConfigResp -> String
msgFileioConfigRespToString r = Jenc.encode 0 (encodeMsgFileioConfigResp r)

msgFileioReadDirReqToString : MsgFileioReadDirReq -> String
msgFileioReadDirReqToString r = Jenc.encode 0 (encodeMsgFileioReadDirReq r)

msgFileioReadDirRespToString : MsgFileioReadDirResp -> String
msgFileioReadDirRespToString r = Jenc.encode 0 (encodeMsgFileioReadDirResp r)

msgFileioReadReqToString : MsgFileioReadReq -> String
msgFileioReadReqToString r = Jenc.encode 0 (encodeMsgFileioReadReq r)

msgFileioReadRespToString : MsgFileioReadResp -> String
msgFileioReadRespToString r = Jenc.encode 0 (encodeMsgFileioReadResp r)

msgFileioRemoveToString : MsgFileioRemove -> String
msgFileioRemoveToString r = Jenc.encode 0 (encodeMsgFileioRemove r)

msgFileioWriteReqToString : MsgFileioWriteReq -> String
msgFileioWriteReqToString r = Jenc.encode 0 (encodeMsgFileioWriteReq r)

msgFileioWriteRespToString : MsgFileioWriteResp -> String
msgFileioWriteRespToString r = Jenc.encode 0 (encodeMsgFileioWriteResp r)

msgFlashDoneToString : MsgFlashDone -> String
msgFlashDoneToString r = Jenc.encode 0 (encodeMsgFlashDone r)

msgFlashEraseToString : MsgFlashErase -> String
msgFlashEraseToString r = Jenc.encode 0 (encodeMsgFlashErase r)

msgFlashProgramToString : MsgFlashProgram -> String
msgFlashProgramToString r = Jenc.encode 0 (encodeMsgFlashProgram r)

msgFlashReadReqToString : MsgFlashReadReq -> String
msgFlashReadReqToString r = Jenc.encode 0 (encodeMsgFlashReadReq r)

msgFlashReadRespToString : MsgFlashReadResp -> String
msgFlashReadRespToString r = Jenc.encode 0 (encodeMsgFlashReadResp r)

msgFrontEndGainToString : MsgFrontEndGain -> String
msgFrontEndGainToString r = Jenc.encode 0 (encodeMsgFrontEndGain r)

msgFwdToString : MsgFwd -> String
msgFwdToString r = Jenc.encode 0 (encodeMsgFwd r)

msgGloBiasesToString : MsgGloBiases -> String
msgGloBiasesToString r = Jenc.encode 0 (encodeMsgGloBiases r)

msgGnssCapbToString : MsgGnssCapb -> String
msgGnssCapbToString r = Jenc.encode 0 (encodeMsgGnssCapb r)

msgGPSTimeToString : MsgGPSTime -> String
msgGPSTimeToString r = Jenc.encode 0 (encodeMsgGPSTime r)

msgGroupDelayToString : MsgGroupDelay -> String
msgGroupDelayToString r = Jenc.encode 0 (encodeMsgGroupDelay r)

msgHeartbeatToString : MsgHeartbeat -> String
msgHeartbeatToString r = Jenc.encode 0 (encodeMsgHeartbeat r)

msgIarStateToString : MsgIarState -> String
msgIarStateToString r = Jenc.encode 0 (encodeMsgIarState r)

msgImuAuxToString : MsgImuAux -> String
msgImuAuxToString r = Jenc.encode 0 (encodeMsgImuAux r)

msgImuRawToString : MsgImuRaw -> String
msgImuRawToString r = Jenc.encode 0 (encodeMsgImuRaw r)

msgInsStatusToString : MsgInsStatus -> String
msgInsStatusToString r = Jenc.encode 0 (encodeMsgInsStatus r)

msgIonoToString : MsgIono -> String
msgIonoToString r = Jenc.encode 0 (encodeMsgIono r)

msgLinuxCPUStateToString : MsgLinuxCPUState -> String
msgLinuxCPUStateToString r = Jenc.encode 0 (encodeMsgLinuxCPUState r)

msgLinuxMemStateToString : MsgLinuxMemState -> String
msgLinuxMemStateToString r = Jenc.encode 0 (encodeMsgLinuxMemState r)

msgLinuxProcessFdCountToString : MsgLinuxProcessFdCount -> String
msgLinuxProcessFdCountToString r = Jenc.encode 0 (encodeMsgLinuxProcessFdCount r)

msgLinuxProcessFdSummaryToString : MsgLinuxProcessFdSummary -> String
msgLinuxProcessFdSummaryToString r = Jenc.encode 0 (encodeMsgLinuxProcessFdSummary r)

msgLinuxProcessSocketCountsToString : MsgLinuxProcessSocketCounts -> String
msgLinuxProcessSocketCountsToString r = Jenc.encode 0 (encodeMsgLinuxProcessSocketCounts r)

msgLinuxProcessSocketQueuesToString : MsgLinuxProcessSocketQueues -> String
msgLinuxProcessSocketQueuesToString r = Jenc.encode 0 (encodeMsgLinuxProcessSocketQueues r)

msgLinuxSocketUsageToString : MsgLinuxSocketUsage -> String
msgLinuxSocketUsageToString r = Jenc.encode 0 (encodeMsgLinuxSocketUsage r)

msgLinuxSysStateToString : MsgLinuxSysState -> String
msgLinuxSysStateToString r = Jenc.encode 0 (encodeMsgLinuxSysState r)

msgLogToString : MsgLog -> String
msgLogToString r = Jenc.encode 0 (encodeMsgLog r)

msgM25FlashWriteStatusToString : MsgM25FlashWriteStatus -> String
msgM25FlashWriteStatusToString r = Jenc.encode 0 (encodeMsgM25FlashWriteStatus r)

msgMagRawToString : MsgMagRaw -> String
msgMagRawToString r = Jenc.encode 0 (encodeMsgMagRaw r)

msgMaskSatelliteToString : MsgMaskSatellite -> String
msgMaskSatelliteToString r = Jenc.encode 0 (encodeMsgMaskSatellite r)

msgMeasurementStateToString : MsgMeasurementState -> String
msgMeasurementStateToString r = Jenc.encode 0 (encodeMsgMeasurementState r)

msgNapDeviceDnaReq : Jdec.Decoder MsgNapDeviceDnaReq
msgNapDeviceDnaReq = Jdec.dict Jdec.value

msgNapDeviceDnaReqToString : MsgNapDeviceDnaReq -> String
msgNapDeviceDnaReqToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgNapDeviceDnaRespToString : MsgNapDeviceDnaResp -> String
msgNapDeviceDnaRespToString r = Jenc.encode 0 (encodeMsgNapDeviceDnaResp r)

msgNdbEventToString : MsgNdbEvent -> String
msgNdbEventToString r = Jenc.encode 0 (encodeMsgNdbEvent r)

msgNetworkBandwidthUsageToString : MsgNetworkBandwidthUsage -> String
msgNetworkBandwidthUsageToString r = Jenc.encode 0 (encodeMsgNetworkBandwidthUsage r)

msgNetworkStateReq : Jdec.Decoder MsgNetworkStateReq
msgNetworkStateReq = Jdec.dict Jdec.value

msgNetworkStateReqToString : MsgNetworkStateReq -> String
msgNetworkStateReqToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgNetworkStateRespToString : MsgNetworkStateResp -> String
msgNetworkStateRespToString r = Jenc.encode 0 (encodeMsgNetworkStateResp r)

msgObsToString : MsgObs -> String
msgObsToString r = Jenc.encode 0 (encodeMsgObs r)

msgOdometryToString : MsgOdometry -> String
msgOdometryToString r = Jenc.encode 0 (encodeMsgOdometry r)

msgOrientEulerToString : MsgOrientEuler -> String
msgOrientEulerToString r = Jenc.encode 0 (encodeMsgOrientEuler r)

msgOrientQuatToString : MsgOrientQuat -> String
msgOrientQuatToString r = Jenc.encode 0 (encodeMsgOrientQuat r)

msgOsrToString : MsgOsr -> String
msgOsrToString r = Jenc.encode 0 (encodeMsgOsr r)

msgPosECEFCovToString : MsgPosECEFCov -> String
msgPosECEFCovToString r = Jenc.encode 0 (encodeMsgPosECEFCov r)

msgPosECEFToString : MsgPosECEF -> String
msgPosECEFToString r = Jenc.encode 0 (encodeMsgPosECEF r)

msgPosLLHCovToString : MsgPosLLHCov -> String
msgPosLLHCovToString r = Jenc.encode 0 (encodeMsgPosLLHCov r)

msgPosLLHToString : MsgPosLLH -> String
msgPosLLHToString r = Jenc.encode 0 (encodeMsgPosLLH r)

msgResetFiltersToString : MsgResetFilters -> String
msgResetFiltersToString r = Jenc.encode 0 (encodeMsgResetFilters r)

msgResetToString : MsgReset -> String
msgResetToString r = Jenc.encode 0 (encodeMsgReset r)

msgSbasRawToString : MsgSbasRaw -> String
msgSbasRawToString r = Jenc.encode 0 (encodeMsgSbasRaw r)

msgSetTime : Jdec.Decoder MsgSetTime
msgSetTime = Jdec.dict Jdec.value

msgSetTimeToString : MsgSetTime -> String
msgSetTimeToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgSettingsReadByIndexDone : Jdec.Decoder MsgSettingsReadByIndexDone
msgSettingsReadByIndexDone = Jdec.dict Jdec.value

msgSettingsReadByIndexDoneToString : MsgSettingsReadByIndexDone -> String
msgSettingsReadByIndexDoneToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgSettingsReadByIndexReqToString : MsgSettingsReadByIndexReq -> String
msgSettingsReadByIndexReqToString r = Jenc.encode 0 (encodeMsgSettingsReadByIndexReq r)

msgSettingsReadByIndexRespToString : MsgSettingsReadByIndexResp -> String
msgSettingsReadByIndexRespToString r = Jenc.encode 0 (encodeMsgSettingsReadByIndexResp r)

msgSettingsReadReqToString : MsgSettingsReadReq -> String
msgSettingsReadReqToString r = Jenc.encode 0 (encodeMsgSettingsReadReq r)

msgSettingsReadRespToString : MsgSettingsReadResp -> String
msgSettingsReadRespToString r = Jenc.encode 0 (encodeMsgSettingsReadResp r)

msgSettingsRegisterToString : MsgSettingsRegister -> String
msgSettingsRegisterToString r = Jenc.encode 0 (encodeMsgSettingsRegister r)

msgSettingsRegisterRespToString : MsgSettingsRegisterResp -> String
msgSettingsRegisterRespToString r = Jenc.encode 0 (encodeMsgSettingsRegisterResp r)

msgSettingsSave : Jdec.Decoder MsgSettingsSave
msgSettingsSave = Jdec.dict Jdec.value

msgSettingsSaveToString : MsgSettingsSave -> String
msgSettingsSaveToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgSettingsWriteToString : MsgSettingsWrite -> String
msgSettingsWriteToString r = Jenc.encode 0 (encodeMsgSettingsWrite r)

msgSettingsWriteRespToString : MsgSettingsWriteResp -> String
msgSettingsWriteRespToString r = Jenc.encode 0 (encodeMsgSettingsWriteResp r)

msgSpecanToString : MsgSpecan -> String
msgSpecanToString r = Jenc.encode 0 (encodeMsgSpecan r)

msgSsrCodeBiasesToString : MsgSsrCodeBiases -> String
msgSsrCodeBiasesToString r = Jenc.encode 0 (encodeMsgSsrCodeBiases r)

msgSsrGriddedCorrectionToString : MsgSsrGriddedCorrection -> String
msgSsrGriddedCorrectionToString r = Jenc.encode 0 (encodeMsgSsrGriddedCorrection r)

msgSsrGridDefinitionToString : MsgSsrGridDefinition -> String
msgSsrGridDefinitionToString r = Jenc.encode 0 (encodeMsgSsrGridDefinition r)

msgSsrOrbitClockToString : MsgSsrOrbitClock -> String
msgSsrOrbitClockToString r = Jenc.encode 0 (encodeMsgSsrOrbitClock r)

msgSsrPhaseBiasesToString : MsgSsrPhaseBiases -> String
msgSsrPhaseBiasesToString r = Jenc.encode 0 (encodeMsgSsrPhaseBiases r)

msgSsrStecCorrectionToString : MsgSsrStecCorrection -> String
msgSsrStecCorrectionToString r = Jenc.encode 0 (encodeMsgSsrStecCorrection r)

msgStartupToString : MsgStartup -> String
msgStartupToString r = Jenc.encode 0 (encodeMsgStartup r)

msgStmFlashLockSectorToString : MsgStmFlashLockSector -> String
msgStmFlashLockSectorToString r = Jenc.encode 0 (encodeMsgStmFlashLockSector r)

msgStmFlashUnlockSectorToString : MsgStmFlashUnlockSector -> String
msgStmFlashUnlockSectorToString r = Jenc.encode 0 (encodeMsgStmFlashUnlockSector r)

msgStmUniqueIDReq : Jdec.Decoder MsgStmUniqueIDReq
msgStmUniqueIDReq = Jdec.dict Jdec.value

msgStmUniqueIDReqToString : MsgStmUniqueIDReq -> String
msgStmUniqueIDReqToString r = Jenc.encode 0 (makeDictEncoder identity r)

msgStmUniqueIDRespToString : MsgStmUniqueIDResp -> String
msgStmUniqueIDRespToString r = Jenc.encode 0 (encodeMsgStmUniqueIDResp r)

msgSvAzElToString : MsgSvAzEl -> String
msgSvAzElToString r = Jenc.encode 0 (encodeMsgSvAzEl r)

msgThreadStateToString : MsgThreadState -> String
msgThreadStateToString r = Jenc.encode 0 (encodeMsgThreadState r)

msgTrackingIqToString : MsgTrackingIq -> String
msgTrackingIqToString r = Jenc.encode 0 (encodeMsgTrackingIq r)

msgTrackingStateToString : MsgTrackingState -> String
msgTrackingStateToString r = Jenc.encode 0 (encodeMsgTrackingState r)

msgUARTStateToString : MsgUARTState -> String
msgUARTStateToString r = Jenc.encode 0 (encodeMsgUARTState r)

msgUserDataToString : MsgUserData -> String
msgUserDataToString r = Jenc.encode 0 (encodeMsgUserData r)

msgUTCTimeToString : MsgUTCTime -> String
msgUTCTimeToString r = Jenc.encode 0 (encodeMsgUTCTime r)

msgVelBodyToString : MsgVelBody -> String
msgVelBodyToString r = Jenc.encode 0 (encodeMsgVelBody r)

msgVelECEFCovToString : MsgVelECEFCov -> String
msgVelECEFCovToString r = Jenc.encode 0 (encodeMsgVelECEFCov r)

msgVelECEFToString : MsgVelECEF -> String
msgVelECEFToString r = Jenc.encode 0 (encodeMsgVelECEF r)

msgVelNEDCovToString : MsgVelNEDCov -> String
msgVelNEDCovToString r = Jenc.encode 0 (encodeMsgVelNEDCov r)

msgVelNEDToString : MsgVelNED -> String
msgVelNEDToString r = Jenc.encode 0 (encodeMsgVelNED r)

networkUsageToString : NetworkUsage -> String
networkUsageToString r = Jenc.encode 0 (encodeNetworkUsage r)

observationHeaderToString : ObservationHeader -> String
observationHeaderToString r = Jenc.encode 0 (encodeObservationHeader r)

packedObsContentToString : PackedObsContent -> String
packedObsContentToString r = Jenc.encode 0 (encodePackedObsContent r)

packedOsrContentToString : PackedOsrContent -> String
packedOsrContentToString r = Jenc.encode 0 (encodePackedOsrContent r)

periodToString : Period -> String
periodToString r = Jenc.encode 0 (encodePeriod r)

phaseBiasesContentToString : PhaseBiasesContent -> String
phaseBiasesContentToString r = Jenc.encode 0 (encodePhaseBiasesContent r)

stecHeaderToString : STECHeader -> String
stecHeaderToString r = Jenc.encode 0 (encodeSTECHeader r)

stecResidualToString : STECResidual -> String
stecResidualToString r = Jenc.encode 0 (encodeSTECResidual r)

stecSatElementToString : STECSatElement -> String
stecSatElementToString r = Jenc.encode 0 (encodeSTECSatElement r)

svAzElToString : SvAzEl -> String
svAzElToString r = Jenc.encode 0 (encodeSvAzEl r)

svIDToString : SvID -> String
svIDToString r = Jenc.encode 0 (encodeSvID r)

trackingChannelCorrelationToString : TrackingChannelCorrelation -> String
trackingChannelCorrelationToString r = Jenc.encode 0 (encodeTrackingChannelCorrelation r)

trackingChannelStateToString : TrackingChannelState -> String
trackingChannelStateToString r = Jenc.encode 0 (encodeTrackingChannelState r)

troposphericDelayCorrectionToString : TroposphericDelayCorrection -> String
troposphericDelayCorrectionToString r = Jenc.encode 0 (encodeTroposphericDelayCorrection r)

uartChannelToString : UARTChannel -> String
uartChannelToString r = Jenc.encode 0 (encodeUARTChannel r)

msgAcqResult : Jdec.Decoder MsgAcqResult
msgAcqResult =
    Jpipe.decode MsgAcqResult
        |> Jpipe.required "cf" Jdec.float
        |> Jpipe.required "cn0" Jdec.float
        |> Jpipe.required "cp" Jdec.float
        |> Jpipe.required "sid" gnssSignal

encodeMsgAcqResult : MsgAcqResult -> Jenc.Value
encodeMsgAcqResult x =
    Jenc.object
        [ ("cf", Jenc.float x.cf)
        , ("cn0", Jenc.float x.cn0)
        , ("cp", Jenc.float x.cp)
        , ("sid", encodeGnssSignal x.sid)
        ]

gnssSignal : Jdec.Decoder GnssSignal
gnssSignal =
    Jpipe.decode GnssSignal
        |> Jpipe.required "code" Jdec.int
        |> Jpipe.required "sat" Jdec.int

encodeGnssSignal : GnssSignal -> Jenc.Value
encodeGnssSignal x =
    Jenc.object
        [ ("code", Jenc.int x.code)
        , ("sat", Jenc.int x.sat)
        ]

msgAcqSvProfile : Jdec.Decoder MsgAcqSvProfile
msgAcqSvProfile =
    Jpipe.decode MsgAcqSvProfile
        |> Jpipe.required "acq_sv_profile" (Jdec.array acqSvProfile)

encodeMsgAcqSvProfile : MsgAcqSvProfile -> Jenc.Value
encodeMsgAcqSvProfile x =
    Jenc.object
        [ ("acq_sv_profile", makeArrayEncoder encodeAcqSvProfile x.acqSvProfile)
        ]

acqSvProfile : Jdec.Decoder AcqSvProfile
acqSvProfile =
    Jpipe.decode AcqSvProfile
        |> Jpipe.required "bin_width" Jdec.int
        |> Jpipe.required "cf" Jdec.int
        |> Jpipe.required "cf_max" Jdec.int
        |> Jpipe.required "cf_min" Jdec.int
        |> Jpipe.required "cn0" Jdec.int
        |> Jpipe.required "cp" Jdec.int
        |> Jpipe.required "int_time" Jdec.int
        |> Jpipe.required "job_type" Jdec.int
        |> Jpipe.required "sid" gnssSignal
        |> Jpipe.required "status" Jdec.int
        |> Jpipe.required "time_spent" Jdec.int
        |> Jpipe.required "timestamp" Jdec.int

encodeAcqSvProfile : AcqSvProfile -> Jenc.Value
encodeAcqSvProfile x =
    Jenc.object
        [ ("bin_width", Jenc.int x.binWidth)
        , ("cf", Jenc.int x.cf)
        , ("cf_max", Jenc.int x.cfMax)
        , ("cf_min", Jenc.int x.cfMin)
        , ("cn0", Jenc.int x.cn0)
        , ("cp", Jenc.int x.cp)
        , ("int_time", Jenc.int x.intTime)
        , ("job_type", Jenc.int x.jobType)
        , ("sid", encodeGnssSignal x.sid)
        , ("status", Jenc.int x.status)
        , ("time_spent", Jenc.int x.timeSpent)
        , ("timestamp", Jenc.int x.timestamp)
        ]

msgAgeCorrections : Jdec.Decoder MsgAgeCorrections
msgAgeCorrections =
    Jpipe.decode MsgAgeCorrections
        |> Jpipe.required "age" Jdec.int
        |> Jpipe.required "tow" Jdec.int

encodeMsgAgeCorrections : MsgAgeCorrections -> Jenc.Value
encodeMsgAgeCorrections x =
    Jenc.object
        [ ("age", Jenc.int x.age)
        , ("tow", Jenc.int x.tow)
        ]

msgAlmanacGlo : Jdec.Decoder MsgAlmanacGlo
msgAlmanacGlo =
    Jpipe.decode MsgAlmanacGlo
        |> Jpipe.required "common" almanacCommonContent
        |> Jpipe.required "epsilon" Jdec.float
        |> Jpipe.required "i" Jdec.float
        |> Jpipe.required "lambda_na" Jdec.float
        |> Jpipe.required "omega" Jdec.float
        |> Jpipe.required "t" Jdec.float
        |> Jpipe.required "t_dot" Jdec.float
        |> Jpipe.required "t_lambda_na" Jdec.float

encodeMsgAlmanacGlo : MsgAlmanacGlo -> Jenc.Value
encodeMsgAlmanacGlo x =
    Jenc.object
        [ ("common", encodeAlmanacCommonContent x.common)
        , ("epsilon", Jenc.float x.epsilon)
        , ("i", Jenc.float x.i)
        , ("lambda_na", Jenc.float x.lambdaNa)
        , ("omega", Jenc.float x.omega)
        , ("t", Jenc.float x.t)
        , ("t_dot", Jenc.float x.tDot)
        , ("t_lambda_na", Jenc.float x.tLambdaNa)
        ]

almanacCommonContent : Jdec.Decoder AlmanacCommonContent
almanacCommonContent =
    Jpipe.decode AlmanacCommonContent
        |> Jpipe.required "fit_interval" Jdec.int
        |> Jpipe.required "health_bits" Jdec.int
        |> Jpipe.required "sid" gnssSignal
        |> Jpipe.required "toa" gpsTimeSEC
        |> Jpipe.required "ura" Jdec.float
        |> Jpipe.required "valid" Jdec.int

encodeAlmanacCommonContent : AlmanacCommonContent -> Jenc.Value
encodeAlmanacCommonContent x =
    Jenc.object
        [ ("fit_interval", Jenc.int x.fitInterval)
        , ("health_bits", Jenc.int x.healthBits)
        , ("sid", encodeGnssSignal x.sid)
        , ("toa", encodeGpsTimeSEC x.toa)
        , ("ura", Jenc.float x.ura)
        , ("valid", Jenc.int x.valid)
        ]

gpsTimeSEC : Jdec.Decoder GpsTimeSEC
gpsTimeSEC =
    Jpipe.decode GpsTimeSEC
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "wn" Jdec.int

encodeGpsTimeSEC : GpsTimeSEC -> Jenc.Value
encodeGpsTimeSEC x =
    Jenc.object
        [ ("tow", Jenc.int x.tow)
        , ("wn", Jenc.int x.wn)
        ]

msgAlmanacGPS : Jdec.Decoder MsgAlmanacGPS
msgAlmanacGPS =
    Jpipe.decode MsgAlmanacGPS
        |> Jpipe.required "af0" Jdec.float
        |> Jpipe.required "af1" Jdec.float
        |> Jpipe.required "common" almanacCommonContent
        |> Jpipe.required "ecc" Jdec.float
        |> Jpipe.required "inc" Jdec.float
        |> Jpipe.required "m0" Jdec.float
        |> Jpipe.required "omega0" Jdec.float
        |> Jpipe.required "omegadot" Jdec.float
        |> Jpipe.required "sqrta" Jdec.float
        |> Jpipe.required "w" Jdec.float

encodeMsgAlmanacGPS : MsgAlmanacGPS -> Jenc.Value
encodeMsgAlmanacGPS x =
    Jenc.object
        [ ("af0", Jenc.float x.af0)
        , ("af1", Jenc.float x.af1)
        , ("common", encodeAlmanacCommonContent x.common)
        , ("ecc", Jenc.float x.ecc)
        , ("inc", Jenc.float x.inc)
        , ("m0", Jenc.float x.m0)
        , ("omega0", Jenc.float x.omega0)
        , ("omegadot", Jenc.float x.omegadot)
        , ("sqrta", Jenc.float x.sqrta)
        , ("w", Jenc.float x.w)
        ]

msgAngularRate : Jdec.Decoder MsgAngularRate
msgAngularRate =
    Jpipe.decode MsgAngularRate
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "x" Jdec.int
        |> Jpipe.required "y" Jdec.int
        |> Jpipe.required "z" Jdec.int

encodeMsgAngularRate : MsgAngularRate -> Jenc.Value
encodeMsgAngularRate x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("tow", Jenc.int x.tow)
        , ("x", Jenc.int x.x)
        , ("y", Jenc.int x.y)
        , ("z", Jenc.int x.z)
        ]

msgBaselineECEF : Jdec.Decoder MsgBaselineECEF
msgBaselineECEF =
    Jpipe.decode MsgBaselineECEF
        |> Jpipe.required "accuracy" Jdec.int
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "x" Jdec.int
        |> Jpipe.required "y" Jdec.int
        |> Jpipe.required "z" Jdec.int

encodeMsgBaselineECEF : MsgBaselineECEF -> Jenc.Value
encodeMsgBaselineECEF x =
    Jenc.object
        [ ("accuracy", Jenc.int x.accuracy)
        , ("flags", Jenc.int x.flags)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        , ("x", Jenc.int x.x)
        , ("y", Jenc.int x.y)
        , ("z", Jenc.int x.z)
        ]

msgBaselineHeading : Jdec.Decoder MsgBaselineHeading
msgBaselineHeading =
    Jpipe.decode MsgBaselineHeading
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "heading" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int

encodeMsgBaselineHeading : MsgBaselineHeading -> Jenc.Value
encodeMsgBaselineHeading x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("heading", Jenc.int x.heading)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        ]

msgBaselineNED : Jdec.Decoder MsgBaselineNED
msgBaselineNED =
    Jpipe.decode MsgBaselineNED
        |> Jpipe.required "d" Jdec.int
        |> Jpipe.required "e" Jdec.int
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "h_accuracy" Jdec.int
        |> Jpipe.required "n" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "v_accuracy" Jdec.int

encodeMsgBaselineNED : MsgBaselineNED -> Jenc.Value
encodeMsgBaselineNED x =
    Jenc.object
        [ ("d", Jenc.int x.d)
        , ("e", Jenc.int x.e)
        , ("flags", Jenc.int x.flags)
        , ("h_accuracy", Jenc.int x.hAccuracy)
        , ("n", Jenc.int x.n)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        , ("v_accuracy", Jenc.int x.vAccuracy)
        ]

msgBasePosECEF : Jdec.Decoder MsgBasePosECEF
msgBasePosECEF =
    Jpipe.decode MsgBasePosECEF
        |> Jpipe.required "x" Jdec.float
        |> Jpipe.required "y" Jdec.float
        |> Jpipe.required "z" Jdec.float

encodeMsgBasePosECEF : MsgBasePosECEF -> Jenc.Value
encodeMsgBasePosECEF x =
    Jenc.object
        [ ("x", Jenc.float x.x)
        , ("y", Jenc.float x.y)
        , ("z", Jenc.float x.z)
        ]

msgBasePosLLH : Jdec.Decoder MsgBasePosLLH
msgBasePosLLH =
    Jpipe.decode MsgBasePosLLH
        |> Jpipe.required "height" Jdec.float
        |> Jpipe.required "lat" Jdec.float
        |> Jpipe.required "lon" Jdec.float

encodeMsgBasePosLLH : MsgBasePosLLH -> Jenc.Value
encodeMsgBasePosLLH x =
    Jenc.object
        [ ("height", Jenc.float x.height)
        , ("lat", Jenc.float x.lat)
        , ("lon", Jenc.float x.lon)
        ]

msgBootloaderHandshakeResp : Jdec.Decoder MsgBootloaderHandshakeResp
msgBootloaderHandshakeResp =
    Jpipe.decode MsgBootloaderHandshakeResp
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "version" Jdec.string

encodeMsgBootloaderHandshakeResp : MsgBootloaderHandshakeResp -> Jenc.Value
encodeMsgBootloaderHandshakeResp x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("version", Jenc.string x.version)
        ]

msgBootloaderJumpToApp : Jdec.Decoder MsgBootloaderJumpToApp
msgBootloaderJumpToApp =
    Jpipe.decode MsgBootloaderJumpToApp
        |> Jpipe.required "jump" Jdec.int

encodeMsgBootloaderJumpToApp : MsgBootloaderJumpToApp -> Jenc.Value
encodeMsgBootloaderJumpToApp x =
    Jenc.object
        [ ("jump", Jenc.int x.jump)
        ]

msgCellModemStatus : Jdec.Decoder MsgCellModemStatus
msgCellModemStatus =
    Jpipe.decode MsgCellModemStatus
        |> Jpipe.required "signal_error_rate" Jdec.float
        |> Jpipe.required "signal_strength" Jdec.int

encodeMsgCellModemStatus : MsgCellModemStatus -> Jenc.Value
encodeMsgCellModemStatus x =
    Jenc.object
        [ ("signal_error_rate", Jenc.float x.signalErrorRate)
        , ("signal_strength", Jenc.int x.signalStrength)
        ]

msgCommandOutput : Jdec.Decoder MsgCommandOutput
msgCommandOutput =
    Jpipe.decode MsgCommandOutput
        |> Jpipe.required "line" Jdec.string
        |> Jpipe.required "sequence" Jdec.int

encodeMsgCommandOutput : MsgCommandOutput -> Jenc.Value
encodeMsgCommandOutput x =
    Jenc.object
        [ ("line", Jenc.string x.line)
        , ("sequence", Jenc.int x.sequence)
        ]

msgCommandReq : Jdec.Decoder MsgCommandReq
msgCommandReq =
    Jpipe.decode MsgCommandReq
        |> Jpipe.required "command" Jdec.string
        |> Jpipe.required "sequence" Jdec.int

encodeMsgCommandReq : MsgCommandReq -> Jenc.Value
encodeMsgCommandReq x =
    Jenc.object
        [ ("command", Jenc.string x.command)
        , ("sequence", Jenc.int x.sequence)
        ]

msgCommandResp : Jdec.Decoder MsgCommandResp
msgCommandResp =
    Jpipe.decode MsgCommandResp
        |> Jpipe.required "code" Jdec.int
        |> Jpipe.required "sequence" Jdec.int

encodeMsgCommandResp : MsgCommandResp -> Jenc.Value
encodeMsgCommandResp x =
    Jenc.object
        [ ("code", Jenc.int x.code)
        , ("sequence", Jenc.int x.sequence)
        ]

msgCsacTelemetry : Jdec.Decoder MsgCsacTelemetry
msgCsacTelemetry =
    Jpipe.decode MsgCsacTelemetry
        |> Jpipe.required "id" Jdec.int
        |> Jpipe.required "telemetry" Jdec.string

encodeMsgCsacTelemetry : MsgCsacTelemetry -> Jenc.Value
encodeMsgCsacTelemetry x =
    Jenc.object
        [ ("id", Jenc.int x.id)
        , ("telemetry", Jenc.string x.telemetry)
        ]

msgCsacTelemetryLabels : Jdec.Decoder MsgCsacTelemetryLabels
msgCsacTelemetryLabels =
    Jpipe.decode MsgCsacTelemetryLabels
        |> Jpipe.required "id" Jdec.int
        |> Jpipe.required "telemetry_labels" Jdec.string

encodeMsgCsacTelemetryLabels : MsgCsacTelemetryLabels -> Jenc.Value
encodeMsgCsacTelemetryLabels x =
    Jenc.object
        [ ("id", Jenc.int x.id)
        , ("telemetry_labels", Jenc.string x.telemetryLabels)
        ]

msgDeviceMonitor : Jdec.Decoder MsgDeviceMonitor
msgDeviceMonitor =
    Jpipe.decode MsgDeviceMonitor
        |> Jpipe.required "cpu_temperature" Jdec.int
        |> Jpipe.required "cpu_vaux" Jdec.int
        |> Jpipe.required "cpu_vint" Jdec.int
        |> Jpipe.required "dev_vin" Jdec.int
        |> Jpipe.required "fe_temperature" Jdec.int

encodeMsgDeviceMonitor : MsgDeviceMonitor -> Jenc.Value
encodeMsgDeviceMonitor x =
    Jenc.object
        [ ("cpu_temperature", Jenc.int x.cpuTemperature)
        , ("cpu_vaux", Jenc.int x.cpuVaux)
        , ("cpu_vint", Jenc.int x.cpuVint)
        , ("dev_vin", Jenc.int x.devVin)
        , ("fe_temperature", Jenc.int x.feTemperature)
        ]

msgDgnssStatus : Jdec.Decoder MsgDgnssStatus
msgDgnssStatus =
    Jpipe.decode MsgDgnssStatus
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "latency" Jdec.int
        |> Jpipe.required "num_signals" Jdec.int
        |> Jpipe.required "source" Jdec.string

encodeMsgDgnssStatus : MsgDgnssStatus -> Jenc.Value
encodeMsgDgnssStatus x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("latency", Jenc.int x.latency)
        , ("num_signals", Jenc.int x.numSignals)
        , ("source", Jenc.string x.source)
        ]

msgDops : Jdec.Decoder MsgDops
msgDops =
    Jpipe.decode MsgDops
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "gdop" Jdec.int
        |> Jpipe.required "hdop" Jdec.int
        |> Jpipe.required "pdop" Jdec.int
        |> Jpipe.required "tdop" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "vdop" Jdec.int

encodeMsgDops : MsgDops -> Jenc.Value
encodeMsgDops x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("gdop", Jenc.int x.gdop)
        , ("hdop", Jenc.int x.hdop)
        , ("pdop", Jenc.int x.pdop)
        , ("tdop", Jenc.int x.tdop)
        , ("tow", Jenc.int x.tow)
        , ("vdop", Jenc.int x.vdop)
        ]

msgEphemerisBds : Jdec.Decoder MsgEphemerisBds
msgEphemerisBds =
    Jpipe.decode MsgEphemerisBds
        |> Jpipe.required "af0" Jdec.float
        |> Jpipe.required "af1" Jdec.float
        |> Jpipe.required "af2" Jdec.float
        |> Jpipe.required "c_ic" Jdec.float
        |> Jpipe.required "c_is" Jdec.float
        |> Jpipe.required "c_rc" Jdec.float
        |> Jpipe.required "c_rs" Jdec.float
        |> Jpipe.required "c_uc" Jdec.float
        |> Jpipe.required "c_us" Jdec.float
        |> Jpipe.required "common" ephemerisCommonContent
        |> Jpipe.required "dn" Jdec.float
        |> Jpipe.required "ecc" Jdec.float
        |> Jpipe.required "inc" Jdec.float
        |> Jpipe.required "inc_dot" Jdec.float
        |> Jpipe.required "iodc" Jdec.int
        |> Jpipe.required "iode" Jdec.int
        |> Jpipe.required "m0" Jdec.float
        |> Jpipe.required "omega0" Jdec.float
        |> Jpipe.required "omegadot" Jdec.float
        |> Jpipe.required "sqrta" Jdec.float
        |> Jpipe.required "tgd1" Jdec.float
        |> Jpipe.required "tgd2" Jdec.float
        |> Jpipe.required "toc" gpsTimeSEC
        |> Jpipe.required "w" Jdec.float

encodeMsgEphemerisBds : MsgEphemerisBds -> Jenc.Value
encodeMsgEphemerisBds x =
    Jenc.object
        [ ("af0", Jenc.float x.af0)
        , ("af1", Jenc.float x.af1)
        , ("af2", Jenc.float x.af2)
        , ("c_ic", Jenc.float x.cIC)
        , ("c_is", Jenc.float x.cIs)
        , ("c_rc", Jenc.float x.cRC)
        , ("c_rs", Jenc.float x.cRs)
        , ("c_uc", Jenc.float x.cUc)
        , ("c_us", Jenc.float x.cUs)
        , ("common", encodeEphemerisCommonContent x.common)
        , ("dn", Jenc.float x.dn)
        , ("ecc", Jenc.float x.ecc)
        , ("inc", Jenc.float x.inc)
        , ("inc_dot", Jenc.float x.incDot)
        , ("iodc", Jenc.int x.iodc)
        , ("iode", Jenc.int x.iode)
        , ("m0", Jenc.float x.m0)
        , ("omega0", Jenc.float x.omega0)
        , ("omegadot", Jenc.float x.omegadot)
        , ("sqrta", Jenc.float x.sqrta)
        , ("tgd1", Jenc.float x.tgd1)
        , ("tgd2", Jenc.float x.tgd2)
        , ("toc", encodeGpsTimeSEC x.toc)
        , ("w", Jenc.float x.w)
        ]

ephemerisCommonContent : Jdec.Decoder EphemerisCommonContent
ephemerisCommonContent =
    Jpipe.decode EphemerisCommonContent
        |> Jpipe.required "fit_interval" Jdec.int
        |> Jpipe.required "health_bits" Jdec.int
        |> Jpipe.required "sid" gnssSignal
        |> Jpipe.required "toe" gpsTimeSEC
        |> Jpipe.required "ura" Jdec.float
        |> Jpipe.required "valid" Jdec.int

encodeEphemerisCommonContent : EphemerisCommonContent -> Jenc.Value
encodeEphemerisCommonContent x =
    Jenc.object
        [ ("fit_interval", Jenc.int x.fitInterval)
        , ("health_bits", Jenc.int x.healthBits)
        , ("sid", encodeGnssSignal x.sid)
        , ("toe", encodeGpsTimeSEC x.toe)
        , ("ura", Jenc.float x.ura)
        , ("valid", Jenc.int x.valid)
        ]

msgEphemerisGal : Jdec.Decoder MsgEphemerisGal
msgEphemerisGal =
    Jpipe.decode MsgEphemerisGal
        |> Jpipe.required "af0" Jdec.float
        |> Jpipe.required "af1" Jdec.float
        |> Jpipe.required "af2" Jdec.float
        |> Jpipe.required "bgd_e1e5a" Jdec.float
        |> Jpipe.required "bgd_e1e5b" Jdec.float
        |> Jpipe.required "c_ic" Jdec.float
        |> Jpipe.required "c_is" Jdec.float
        |> Jpipe.required "c_rc" Jdec.float
        |> Jpipe.required "c_rs" Jdec.float
        |> Jpipe.required "c_uc" Jdec.float
        |> Jpipe.required "c_us" Jdec.float
        |> Jpipe.required "common" ephemerisCommonContent
        |> Jpipe.required "dn" Jdec.float
        |> Jpipe.required "ecc" Jdec.float
        |> Jpipe.required "inc" Jdec.float
        |> Jpipe.required "inc_dot" Jdec.float
        |> Jpipe.required "iodc" Jdec.int
        |> Jpipe.required "iode" Jdec.int
        |> Jpipe.required "m0" Jdec.float
        |> Jpipe.required "omega0" Jdec.float
        |> Jpipe.required "omegadot" Jdec.float
        |> Jpipe.required "source" Jdec.int
        |> Jpipe.required "sqrta" Jdec.float
        |> Jpipe.required "toc" gpsTimeSEC
        |> Jpipe.required "w" Jdec.float

encodeMsgEphemerisGal : MsgEphemerisGal -> Jenc.Value
encodeMsgEphemerisGal x =
    Jenc.object
        [ ("af0", Jenc.float x.af0)
        , ("af1", Jenc.float x.af1)
        , ("af2", Jenc.float x.af2)
        , ("bgd_e1e5a", Jenc.float x.bgdE1E5A)
        , ("bgd_e1e5b", Jenc.float x.bgdE1E5B)
        , ("c_ic", Jenc.float x.cIC)
        , ("c_is", Jenc.float x.cIs)
        , ("c_rc", Jenc.float x.cRC)
        , ("c_rs", Jenc.float x.cRs)
        , ("c_uc", Jenc.float x.cUc)
        , ("c_us", Jenc.float x.cUs)
        , ("common", encodeEphemerisCommonContent x.common)
        , ("dn", Jenc.float x.dn)
        , ("ecc", Jenc.float x.ecc)
        , ("inc", Jenc.float x.inc)
        , ("inc_dot", Jenc.float x.incDot)
        , ("iodc", Jenc.int x.iodc)
        , ("iode", Jenc.int x.iode)
        , ("m0", Jenc.float x.m0)
        , ("omega0", Jenc.float x.omega0)
        , ("omegadot", Jenc.float x.omegadot)
        , ("source", Jenc.int x.source)
        , ("sqrta", Jenc.float x.sqrta)
        , ("toc", encodeGpsTimeSEC x.toc)
        , ("w", Jenc.float x.w)
        ]

msgEphemerisGlo : Jdec.Decoder MsgEphemerisGlo
msgEphemerisGlo =
    Jpipe.decode MsgEphemerisGlo
        |> Jpipe.required "acc" (Jdec.array Jdec.float)
        |> Jpipe.required "common" ephemerisCommonContent
        |> Jpipe.required "d_tau" Jdec.float
        |> Jpipe.required "fcn" Jdec.int
        |> Jpipe.required "gamma" Jdec.float
        |> Jpipe.required "iod" Jdec.int
        |> Jpipe.required "pos" (Jdec.array Jdec.float)
        |> Jpipe.required "tau" Jdec.float
        |> Jpipe.required "vel" (Jdec.array Jdec.float)

encodeMsgEphemerisGlo : MsgEphemerisGlo -> Jenc.Value
encodeMsgEphemerisGlo x =
    Jenc.object
        [ ("acc", makeArrayEncoder Jenc.float x.acc)
        , ("common", encodeEphemerisCommonContent x.common)
        , ("d_tau", Jenc.float x.dTau)
        , ("fcn", Jenc.int x.fcn)
        , ("gamma", Jenc.float x.gamma)
        , ("iod", Jenc.int x.iod)
        , ("pos", makeArrayEncoder Jenc.float x.pos)
        , ("tau", Jenc.float x.tau)
        , ("vel", makeArrayEncoder Jenc.float x.vel)
        ]

msgEphemerisGPS : Jdec.Decoder MsgEphemerisGPS
msgEphemerisGPS =
    Jpipe.decode MsgEphemerisGPS
        |> Jpipe.required "af0" Jdec.float
        |> Jpipe.required "af1" Jdec.float
        |> Jpipe.required "af2" Jdec.float
        |> Jpipe.required "c_ic" Jdec.float
        |> Jpipe.required "c_is" Jdec.float
        |> Jpipe.required "c_rc" Jdec.float
        |> Jpipe.required "c_rs" Jdec.float
        |> Jpipe.required "c_uc" Jdec.float
        |> Jpipe.required "c_us" Jdec.float
        |> Jpipe.required "common" ephemerisCommonContent
        |> Jpipe.required "dn" Jdec.float
        |> Jpipe.required "ecc" Jdec.float
        |> Jpipe.required "inc" Jdec.float
        |> Jpipe.required "inc_dot" Jdec.float
        |> Jpipe.required "iodc" Jdec.int
        |> Jpipe.required "iode" Jdec.int
        |> Jpipe.required "m0" Jdec.float
        |> Jpipe.required "omega0" Jdec.float
        |> Jpipe.required "omegadot" Jdec.float
        |> Jpipe.required "sqrta" Jdec.float
        |> Jpipe.required "tgd" Jdec.float
        |> Jpipe.required "toc" gpsTimeSEC
        |> Jpipe.required "w" Jdec.float

encodeMsgEphemerisGPS : MsgEphemerisGPS -> Jenc.Value
encodeMsgEphemerisGPS x =
    Jenc.object
        [ ("af0", Jenc.float x.af0)
        , ("af1", Jenc.float x.af1)
        , ("af2", Jenc.float x.af2)
        , ("c_ic", Jenc.float x.cIC)
        , ("c_is", Jenc.float x.cIs)
        , ("c_rc", Jenc.float x.cRC)
        , ("c_rs", Jenc.float x.cRs)
        , ("c_uc", Jenc.float x.cUc)
        , ("c_us", Jenc.float x.cUs)
        , ("common", encodeEphemerisCommonContent x.common)
        , ("dn", Jenc.float x.dn)
        , ("ecc", Jenc.float x.ecc)
        , ("inc", Jenc.float x.inc)
        , ("inc_dot", Jenc.float x.incDot)
        , ("iodc", Jenc.int x.iodc)
        , ("iode", Jenc.int x.iode)
        , ("m0", Jenc.float x.m0)
        , ("omega0", Jenc.float x.omega0)
        , ("omegadot", Jenc.float x.omegadot)
        , ("sqrta", Jenc.float x.sqrta)
        , ("tgd", Jenc.float x.tgd)
        , ("toc", encodeGpsTimeSEC x.toc)
        , ("w", Jenc.float x.w)
        ]

msgEphemerisQzss : Jdec.Decoder MsgEphemerisQzss
msgEphemerisQzss =
    Jpipe.decode MsgEphemerisQzss
        |> Jpipe.required "af0" Jdec.float
        |> Jpipe.required "af1" Jdec.float
        |> Jpipe.required "af2" Jdec.float
        |> Jpipe.required "c_ic" Jdec.float
        |> Jpipe.required "c_is" Jdec.float
        |> Jpipe.required "c_rc" Jdec.float
        |> Jpipe.required "c_rs" Jdec.float
        |> Jpipe.required "c_uc" Jdec.float
        |> Jpipe.required "c_us" Jdec.float
        |> Jpipe.required "common" ephemerisCommonContent
        |> Jpipe.required "dn" Jdec.float
        |> Jpipe.required "ecc" Jdec.float
        |> Jpipe.required "inc" Jdec.float
        |> Jpipe.required "inc_dot" Jdec.float
        |> Jpipe.required "iodc" Jdec.int
        |> Jpipe.required "iode" Jdec.int
        |> Jpipe.required "m0" Jdec.float
        |> Jpipe.required "omega0" Jdec.float
        |> Jpipe.required "omegadot" Jdec.float
        |> Jpipe.required "sqrta" Jdec.float
        |> Jpipe.required "tgd" Jdec.float
        |> Jpipe.required "toc" gpsTimeSEC
        |> Jpipe.required "w" Jdec.float

encodeMsgEphemerisQzss : MsgEphemerisQzss -> Jenc.Value
encodeMsgEphemerisQzss x =
    Jenc.object
        [ ("af0", Jenc.float x.af0)
        , ("af1", Jenc.float x.af1)
        , ("af2", Jenc.float x.af2)
        , ("c_ic", Jenc.float x.cIC)
        , ("c_is", Jenc.float x.cIs)
        , ("c_rc", Jenc.float x.cRC)
        , ("c_rs", Jenc.float x.cRs)
        , ("c_uc", Jenc.float x.cUc)
        , ("c_us", Jenc.float x.cUs)
        , ("common", encodeEphemerisCommonContent x.common)
        , ("dn", Jenc.float x.dn)
        , ("ecc", Jenc.float x.ecc)
        , ("inc", Jenc.float x.inc)
        , ("inc_dot", Jenc.float x.incDot)
        , ("iodc", Jenc.int x.iodc)
        , ("iode", Jenc.int x.iode)
        , ("m0", Jenc.float x.m0)
        , ("omega0", Jenc.float x.omega0)
        , ("omegadot", Jenc.float x.omegadot)
        , ("sqrta", Jenc.float x.sqrta)
        , ("tgd", Jenc.float x.tgd)
        , ("toc", encodeGpsTimeSEC x.toc)
        , ("w", Jenc.float x.w)
        ]

msgEphemerisSbas : Jdec.Decoder MsgEphemerisSbas
msgEphemerisSbas =
    Jpipe.decode MsgEphemerisSbas
        |> Jpipe.required "a_gf0" Jdec.float
        |> Jpipe.required "a_gf1" Jdec.float
        |> Jpipe.required "acc" (Jdec.array Jdec.float)
        |> Jpipe.required "common" ephemerisCommonContent
        |> Jpipe.required "pos" (Jdec.array Jdec.float)
        |> Jpipe.required "vel" (Jdec.array Jdec.float)

encodeMsgEphemerisSbas : MsgEphemerisSbas -> Jenc.Value
encodeMsgEphemerisSbas x =
    Jenc.object
        [ ("a_gf0", Jenc.float x.aGf0)
        , ("a_gf1", Jenc.float x.aGf1)
        , ("acc", makeArrayEncoder Jenc.float x.acc)
        , ("common", encodeEphemerisCommonContent x.common)
        , ("pos", makeArrayEncoder Jenc.float x.pos)
        , ("vel", makeArrayEncoder Jenc.float x.vel)
        ]

msgEXTEvent : Jdec.Decoder MsgEXTEvent
msgEXTEvent =
    Jpipe.decode MsgEXTEvent
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "ns_residual" Jdec.int
        |> Jpipe.required "pin" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "wn" Jdec.int

encodeMsgEXTEvent : MsgEXTEvent -> Jenc.Value
encodeMsgEXTEvent x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("ns_residual", Jenc.int x.nsResidual)
        , ("pin", Jenc.int x.pin)
        , ("tow", Jenc.int x.tow)
        , ("wn", Jenc.int x.wn)
        ]

msgFileioConfigReq : Jdec.Decoder MsgFileioConfigReq
msgFileioConfigReq =
    Jpipe.decode MsgFileioConfigReq
        |> Jpipe.required "sequence" Jdec.int

encodeMsgFileioConfigReq : MsgFileioConfigReq -> Jenc.Value
encodeMsgFileioConfigReq x =
    Jenc.object
        [ ("sequence", Jenc.int x.sequence)
        ]

msgFileioConfigResp : Jdec.Decoder MsgFileioConfigResp
msgFileioConfigResp =
    Jpipe.decode MsgFileioConfigResp
        |> Jpipe.required "batch_size" Jdec.int
        |> Jpipe.required "fileio_version" Jdec.int
        |> Jpipe.required "sequence" Jdec.int
        |> Jpipe.required "window_size" Jdec.int

encodeMsgFileioConfigResp : MsgFileioConfigResp -> Jenc.Value
encodeMsgFileioConfigResp x =
    Jenc.object
        [ ("batch_size", Jenc.int x.batchSize)
        , ("fileio_version", Jenc.int x.fileioVersion)
        , ("sequence", Jenc.int x.sequence)
        , ("window_size", Jenc.int x.windowSize)
        ]

msgFileioReadDirReq : Jdec.Decoder MsgFileioReadDirReq
msgFileioReadDirReq =
    Jpipe.decode MsgFileioReadDirReq
        |> Jpipe.required "dirname" Jdec.string
        |> Jpipe.required "offset" Jdec.int
        |> Jpipe.required "sequence" Jdec.int

encodeMsgFileioReadDirReq : MsgFileioReadDirReq -> Jenc.Value
encodeMsgFileioReadDirReq x =
    Jenc.object
        [ ("dirname", Jenc.string x.dirname)
        , ("offset", Jenc.int x.offset)
        , ("sequence", Jenc.int x.sequence)
        ]

msgFileioReadDirResp : Jdec.Decoder MsgFileioReadDirResp
msgFileioReadDirResp =
    Jpipe.decode MsgFileioReadDirResp
        |> Jpipe.required "contents" (Jdec.array Jdec.int)
        |> Jpipe.required "sequence" Jdec.int

encodeMsgFileioReadDirResp : MsgFileioReadDirResp -> Jenc.Value
encodeMsgFileioReadDirResp x =
    Jenc.object
        [ ("contents", makeArrayEncoder Jenc.int x.contents)
        , ("sequence", Jenc.int x.sequence)
        ]

msgFileioReadReq : Jdec.Decoder MsgFileioReadReq
msgFileioReadReq =
    Jpipe.decode MsgFileioReadReq
        |> Jpipe.required "chunk_size" Jdec.int
        |> Jpipe.required "filename" Jdec.string
        |> Jpipe.required "offset" Jdec.int
        |> Jpipe.required "sequence" Jdec.int

encodeMsgFileioReadReq : MsgFileioReadReq -> Jenc.Value
encodeMsgFileioReadReq x =
    Jenc.object
        [ ("chunk_size", Jenc.int x.chunkSize)
        , ("filename", Jenc.string x.filename)
        , ("offset", Jenc.int x.offset)
        , ("sequence", Jenc.int x.sequence)
        ]

msgFileioReadResp : Jdec.Decoder MsgFileioReadResp
msgFileioReadResp =
    Jpipe.decode MsgFileioReadResp
        |> Jpipe.required "contents" (Jdec.array Jdec.int)
        |> Jpipe.required "sequence" Jdec.int

encodeMsgFileioReadResp : MsgFileioReadResp -> Jenc.Value
encodeMsgFileioReadResp x =
    Jenc.object
        [ ("contents", makeArrayEncoder Jenc.int x.contents)
        , ("sequence", Jenc.int x.sequence)
        ]

msgFileioRemove : Jdec.Decoder MsgFileioRemove
msgFileioRemove =
    Jpipe.decode MsgFileioRemove
        |> Jpipe.required "filename" Jdec.string

encodeMsgFileioRemove : MsgFileioRemove -> Jenc.Value
encodeMsgFileioRemove x =
    Jenc.object
        [ ("filename", Jenc.string x.filename)
        ]

msgFileioWriteReq : Jdec.Decoder MsgFileioWriteReq
msgFileioWriteReq =
    Jpipe.decode MsgFileioWriteReq
        |> Jpipe.required "data" (Jdec.array Jdec.int)
        |> Jpipe.required "filename" Jdec.string
        |> Jpipe.required "offset" Jdec.int
        |> Jpipe.required "sequence" Jdec.int

encodeMsgFileioWriteReq : MsgFileioWriteReq -> Jenc.Value
encodeMsgFileioWriteReq x =
    Jenc.object
        [ ("data", makeArrayEncoder Jenc.int x.data)
        , ("filename", Jenc.string x.filename)
        , ("offset", Jenc.int x.offset)
        , ("sequence", Jenc.int x.sequence)
        ]

msgFileioWriteResp : Jdec.Decoder MsgFileioWriteResp
msgFileioWriteResp =
    Jpipe.decode MsgFileioWriteResp
        |> Jpipe.required "sequence" Jdec.int

encodeMsgFileioWriteResp : MsgFileioWriteResp -> Jenc.Value
encodeMsgFileioWriteResp x =
    Jenc.object
        [ ("sequence", Jenc.int x.sequence)
        ]

msgFlashDone : Jdec.Decoder MsgFlashDone
msgFlashDone =
    Jpipe.decode MsgFlashDone
        |> Jpipe.required "response" Jdec.int

encodeMsgFlashDone : MsgFlashDone -> Jenc.Value
encodeMsgFlashDone x =
    Jenc.object
        [ ("response", Jenc.int x.response)
        ]

msgFlashErase : Jdec.Decoder MsgFlashErase
msgFlashErase =
    Jpipe.decode MsgFlashErase
        |> Jpipe.required "sector_num" Jdec.int
        |> Jpipe.required "target" Jdec.int

encodeMsgFlashErase : MsgFlashErase -> Jenc.Value
encodeMsgFlashErase x =
    Jenc.object
        [ ("sector_num", Jenc.int x.sectorNum)
        , ("target", Jenc.int x.target)
        ]

msgFlashProgram : Jdec.Decoder MsgFlashProgram
msgFlashProgram =
    Jpipe.decode MsgFlashProgram
        |> Jpipe.required "addr_len" Jdec.int
        |> Jpipe.required "addr_start" (Jdec.array Jdec.int)
        |> Jpipe.required "data" (Jdec.array Jdec.int)
        |> Jpipe.required "target" Jdec.int

encodeMsgFlashProgram : MsgFlashProgram -> Jenc.Value
encodeMsgFlashProgram x =
    Jenc.object
        [ ("addr_len", Jenc.int x.addrLen)
        , ("addr_start", makeArrayEncoder Jenc.int x.addrStart)
        , ("data", makeArrayEncoder Jenc.int x.data)
        , ("target", Jenc.int x.target)
        ]

msgFlashReadReq : Jdec.Decoder MsgFlashReadReq
msgFlashReadReq =
    Jpipe.decode MsgFlashReadReq
        |> Jpipe.required "addr_len" Jdec.int
        |> Jpipe.required "addr_start" (Jdec.array Jdec.int)
        |> Jpipe.required "target" Jdec.int

encodeMsgFlashReadReq : MsgFlashReadReq -> Jenc.Value
encodeMsgFlashReadReq x =
    Jenc.object
        [ ("addr_len", Jenc.int x.addrLen)
        , ("addr_start", makeArrayEncoder Jenc.int x.addrStart)
        , ("target", Jenc.int x.target)
        ]

msgFlashReadResp : Jdec.Decoder MsgFlashReadResp
msgFlashReadResp =
    Jpipe.decode MsgFlashReadResp
        |> Jpipe.required "addr_len" Jdec.int
        |> Jpipe.required "addr_start" (Jdec.array Jdec.int)
        |> Jpipe.required "target" Jdec.int

encodeMsgFlashReadResp : MsgFlashReadResp -> Jenc.Value
encodeMsgFlashReadResp x =
    Jenc.object
        [ ("addr_len", Jenc.int x.addrLen)
        , ("addr_start", makeArrayEncoder Jenc.int x.addrStart)
        , ("target", Jenc.int x.target)
        ]

msgFrontEndGain : Jdec.Decoder MsgFrontEndGain
msgFrontEndGain =
    Jpipe.decode MsgFrontEndGain
        |> Jpipe.required "if_gain" (Jdec.array Jdec.int)
        |> Jpipe.required "rf_gain" (Jdec.array Jdec.int)

encodeMsgFrontEndGain : MsgFrontEndGain -> Jenc.Value
encodeMsgFrontEndGain x =
    Jenc.object
        [ ("if_gain", makeArrayEncoder Jenc.int x.ifGain)
        , ("rf_gain", makeArrayEncoder Jenc.int x.rfGain)
        ]

msgFwd : Jdec.Decoder MsgFwd
msgFwd =
    Jpipe.decode MsgFwd
        |> Jpipe.required "fwd_payload" Jdec.string
        |> Jpipe.required "protocol" Jdec.int
        |> Jpipe.required "source" Jdec.int

encodeMsgFwd : MsgFwd -> Jenc.Value
encodeMsgFwd x =
    Jenc.object
        [ ("fwd_payload", Jenc.string x.fwdPayload)
        , ("protocol", Jenc.int x.protocol)
        , ("source", Jenc.int x.source)
        ]

msgGloBiases : Jdec.Decoder MsgGloBiases
msgGloBiases =
    Jpipe.decode MsgGloBiases
        |> Jpipe.required "l1ca_bias" Jdec.int
        |> Jpipe.required "l1p_bias" Jdec.int
        |> Jpipe.required "l2ca_bias" Jdec.int
        |> Jpipe.required "l2p_bias" Jdec.int
        |> Jpipe.required "mask" Jdec.int

encodeMsgGloBiases : MsgGloBiases -> Jenc.Value
encodeMsgGloBiases x =
    Jenc.object
        [ ("l1ca_bias", Jenc.int x.l1CABias)
        , ("l1p_bias", Jenc.int x.l1PBias)
        , ("l2ca_bias", Jenc.int x.l2CABias)
        , ("l2p_bias", Jenc.int x.l2PBias)
        , ("mask", Jenc.int x.mask)
        ]

msgGnssCapb : Jdec.Decoder MsgGnssCapb
msgGnssCapb =
    Jpipe.decode MsgGnssCapb
        |> Jpipe.required "gc" gnssCapb
        |> Jpipe.required "t_nmct" gpsTimeSEC

encodeMsgGnssCapb : MsgGnssCapb -> Jenc.Value
encodeMsgGnssCapb x =
    Jenc.object
        [ ("gc", encodeGnssCapb x.gc)
        , ("t_nmct", encodeGpsTimeSEC x.tNmct)
        ]

gnssCapb : Jdec.Decoder GnssCapb
gnssCapb =
    Jpipe.decode GnssCapb
        |> Jpipe.required "bds_active" Jdec.int
        |> Jpipe.required "bds_b2" Jdec.int
        |> Jpipe.required "bds_b2a" Jdec.int
        |> Jpipe.required "bds_d2nav" Jdec.int
        |> Jpipe.required "gal_active" Jdec.int
        |> Jpipe.required "gal_e5" Jdec.int
        |> Jpipe.required "glo_active" Jdec.int
        |> Jpipe.required "glo_l2of" Jdec.int
        |> Jpipe.required "glo_l3" Jdec.int
        |> Jpipe.required "gps_active" Jdec.int
        |> Jpipe.required "gps_l2c" Jdec.int
        |> Jpipe.required "gps_l5" Jdec.int
        |> Jpipe.required "qzss_active" Jdec.int
        |> Jpipe.required "sbas_active" Jdec.int
        |> Jpipe.required "sbas_l5" Jdec.int

encodeGnssCapb : GnssCapb -> Jenc.Value
encodeGnssCapb x =
    Jenc.object
        [ ("bds_active", Jenc.int x.bdsActive)
        , ("bds_b2", Jenc.int x.bdsB2)
        , ("bds_b2a", Jenc.int x.bdsB2A)
        , ("bds_d2nav", Jenc.int x.bdsD2Nav)
        , ("gal_active", Jenc.int x.galActive)
        , ("gal_e5", Jenc.int x.galE5)
        , ("glo_active", Jenc.int x.gloActive)
        , ("glo_l2of", Jenc.int x.gloL2Of)
        , ("glo_l3", Jenc.int x.gloL3)
        , ("gps_active", Jenc.int x.gpsActive)
        , ("gps_l2c", Jenc.int x.gpsL2C)
        , ("gps_l5", Jenc.int x.gpsL5)
        , ("qzss_active", Jenc.int x.qzssActive)
        , ("sbas_active", Jenc.int x.sbasActive)
        , ("sbas_l5", Jenc.int x.sbasL5)
        ]

msgGPSTime : Jdec.Decoder MsgGPSTime
msgGPSTime =
    Jpipe.decode MsgGPSTime
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "ns_residual" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "wn" Jdec.int

encodeMsgGPSTime : MsgGPSTime -> Jenc.Value
encodeMsgGPSTime x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("ns_residual", Jenc.int x.nsResidual)
        , ("tow", Jenc.int x.tow)
        , ("wn", Jenc.int x.wn)
        ]

msgGroupDelay : Jdec.Decoder MsgGroupDelay
msgGroupDelay =
    Jpipe.decode MsgGroupDelay
        |> Jpipe.required "isc_l1ca" Jdec.int
        |> Jpipe.required "isc_l2c" Jdec.int
        |> Jpipe.required "sid" gnssSignal
        |> Jpipe.required "t_op" gpsTimeSEC
        |> Jpipe.required "tgd" Jdec.int
        |> Jpipe.required "valid" Jdec.int

encodeMsgGroupDelay : MsgGroupDelay -> Jenc.Value
encodeMsgGroupDelay x =
    Jenc.object
        [ ("isc_l1ca", Jenc.int x.iscL1CA)
        , ("isc_l2c", Jenc.int x.iscL2C)
        , ("sid", encodeGnssSignal x.sid)
        , ("t_op", encodeGpsTimeSEC x.tOp)
        , ("tgd", Jenc.int x.tgd)
        , ("valid", Jenc.int x.valid)
        ]

msgHeartbeat : Jdec.Decoder MsgHeartbeat
msgHeartbeat =
    Jpipe.decode MsgHeartbeat
        |> Jpipe.required "flags" Jdec.int

encodeMsgHeartbeat : MsgHeartbeat -> Jenc.Value
encodeMsgHeartbeat x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        ]

msgIarState : Jdec.Decoder MsgIarState
msgIarState =
    Jpipe.decode MsgIarState
        |> Jpipe.required "num_hyps" Jdec.int

encodeMsgIarState : MsgIarState -> Jenc.Value
encodeMsgIarState x =
    Jenc.object
        [ ("num_hyps", Jenc.int x.numHyps)
        ]

msgImuAux : Jdec.Decoder MsgImuAux
msgImuAux =
    Jpipe.decode MsgImuAux
        |> Jpipe.required "imu_conf" Jdec.int
        |> Jpipe.required "imu_type" Jdec.int
        |> Jpipe.required "temp" Jdec.int

encodeMsgImuAux : MsgImuAux -> Jenc.Value
encodeMsgImuAux x =
    Jenc.object
        [ ("imu_conf", Jenc.int x.imuConf)
        , ("imu_type", Jenc.int x.imuType)
        , ("temp", Jenc.int x.temp)
        ]

msgImuRaw : Jdec.Decoder MsgImuRaw
msgImuRaw =
    Jpipe.decode MsgImuRaw
        |> Jpipe.required "acc_x" Jdec.int
        |> Jpipe.required "acc_y" Jdec.int
        |> Jpipe.required "acc_z" Jdec.int
        |> Jpipe.required "gyr_x" Jdec.int
        |> Jpipe.required "gyr_y" Jdec.int
        |> Jpipe.required "gyr_z" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "tow_f" Jdec.int

encodeMsgImuRaw : MsgImuRaw -> Jenc.Value
encodeMsgImuRaw x =
    Jenc.object
        [ ("acc_x", Jenc.int x.accX)
        , ("acc_y", Jenc.int x.accY)
        , ("acc_z", Jenc.int x.accZ)
        , ("gyr_x", Jenc.int x.gyrX)
        , ("gyr_y", Jenc.int x.gyrY)
        , ("gyr_z", Jenc.int x.gyrZ)
        , ("tow", Jenc.int x.tow)
        , ("tow_f", Jenc.int x.towF)
        ]

msgInsStatus : Jdec.Decoder MsgInsStatus
msgInsStatus =
    Jpipe.decode MsgInsStatus
        |> Jpipe.required "flags" Jdec.int

encodeMsgInsStatus : MsgInsStatus -> Jenc.Value
encodeMsgInsStatus x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        ]

msgIono : Jdec.Decoder MsgIono
msgIono =
    Jpipe.decode MsgIono
        |> Jpipe.required "a0" Jdec.float
        |> Jpipe.required "a1" Jdec.float
        |> Jpipe.required "a2" Jdec.float
        |> Jpipe.required "a3" Jdec.float
        |> Jpipe.required "b0" Jdec.float
        |> Jpipe.required "b1" Jdec.float
        |> Jpipe.required "b2" Jdec.float
        |> Jpipe.required "b3" Jdec.float
        |> Jpipe.required "t_nmct" gpsTimeSEC

encodeMsgIono : MsgIono -> Jenc.Value
encodeMsgIono x =
    Jenc.object
        [ ("a0", Jenc.float x.a0)
        , ("a1", Jenc.float x.a1)
        , ("a2", Jenc.float x.a2)
        , ("a3", Jenc.float x.a3)
        , ("b0", Jenc.float x.b0)
        , ("b1", Jenc.float x.b1)
        , ("b2", Jenc.float x.b2)
        , ("b3", Jenc.float x.b3)
        , ("t_nmct", encodeGpsTimeSEC x.tNmct)
        ]

msgLinuxCPUState : Jdec.Decoder MsgLinuxCPUState
msgLinuxCPUState =
    Jpipe.decode MsgLinuxCPUState
        |> Jpipe.required "cmdline" Jdec.string
        |> Jpipe.required "index" Jdec.int
        |> Jpipe.required "pcpu" Jdec.int
        |> Jpipe.required "pid" Jdec.int
        |> Jpipe.required "tname" Jdec.string

encodeMsgLinuxCPUState : MsgLinuxCPUState -> Jenc.Value
encodeMsgLinuxCPUState x =
    Jenc.object
        [ ("cmdline", Jenc.string x.cmdline)
        , ("index", Jenc.int x.index)
        , ("pcpu", Jenc.int x.pcpu)
        , ("pid", Jenc.int x.pid)
        , ("tname", Jenc.string x.tname)
        ]

msgLinuxMemState : Jdec.Decoder MsgLinuxMemState
msgLinuxMemState =
    Jpipe.decode MsgLinuxMemState
        |> Jpipe.required "cmdline" Jdec.string
        |> Jpipe.required "index" Jdec.int
        |> Jpipe.required "pid" Jdec.int
        |> Jpipe.required "pmem" Jdec.int
        |> Jpipe.required "tname" Jdec.string

encodeMsgLinuxMemState : MsgLinuxMemState -> Jenc.Value
encodeMsgLinuxMemState x =
    Jenc.object
        [ ("cmdline", Jenc.string x.cmdline)
        , ("index", Jenc.int x.index)
        , ("pid", Jenc.int x.pid)
        , ("pmem", Jenc.int x.pmem)
        , ("tname", Jenc.string x.tname)
        ]

msgLinuxProcessFdCount : Jdec.Decoder MsgLinuxProcessFdCount
msgLinuxProcessFdCount =
    Jpipe.decode MsgLinuxProcessFdCount
        |> Jpipe.required "cmdline" Jdec.string
        |> Jpipe.required "fd_count" Jdec.int
        |> Jpipe.required "index" Jdec.int
        |> Jpipe.required "pid" Jdec.int

encodeMsgLinuxProcessFdCount : MsgLinuxProcessFdCount -> Jenc.Value
encodeMsgLinuxProcessFdCount x =
    Jenc.object
        [ ("cmdline", Jenc.string x.cmdline)
        , ("fd_count", Jenc.int x.fdCount)
        , ("index", Jenc.int x.index)
        , ("pid", Jenc.int x.pid)
        ]

msgLinuxProcessFdSummary : Jdec.Decoder MsgLinuxProcessFdSummary
msgLinuxProcessFdSummary =
    Jpipe.decode MsgLinuxProcessFdSummary
        |> Jpipe.required "most_opened" Jdec.string
        |> Jpipe.required "sys_fd_count" Jdec.int

encodeMsgLinuxProcessFdSummary : MsgLinuxProcessFdSummary -> Jenc.Value
encodeMsgLinuxProcessFdSummary x =
    Jenc.object
        [ ("most_opened", Jenc.string x.mostOpened)
        , ("sys_fd_count", Jenc.int x.sysFdCount)
        ]

msgLinuxProcessSocketCounts : Jdec.Decoder MsgLinuxProcessSocketCounts
msgLinuxProcessSocketCounts =
    Jpipe.decode MsgLinuxProcessSocketCounts
        |> Jpipe.required "cmdline" Jdec.string
        |> Jpipe.required "index" Jdec.int
        |> Jpipe.required "pid" Jdec.int
        |> Jpipe.required "socket_count" Jdec.int
        |> Jpipe.required "socket_states" Jdec.int
        |> Jpipe.required "socket_types" Jdec.int

encodeMsgLinuxProcessSocketCounts : MsgLinuxProcessSocketCounts -> Jenc.Value
encodeMsgLinuxProcessSocketCounts x =
    Jenc.object
        [ ("cmdline", Jenc.string x.cmdline)
        , ("index", Jenc.int x.index)
        , ("pid", Jenc.int x.pid)
        , ("socket_count", Jenc.int x.socketCount)
        , ("socket_states", Jenc.int x.socketStates)
        , ("socket_types", Jenc.int x.socketTypes)
        ]

msgLinuxProcessSocketQueues : Jdec.Decoder MsgLinuxProcessSocketQueues
msgLinuxProcessSocketQueues =
    Jpipe.decode MsgLinuxProcessSocketQueues
        |> Jpipe.required "address_of_largest" Jdec.string
        |> Jpipe.required "cmdline" Jdec.string
        |> Jpipe.required "index" Jdec.int
        |> Jpipe.required "pid" Jdec.int
        |> Jpipe.required "recv_queued" Jdec.int
        |> Jpipe.required "send_queued" Jdec.int
        |> Jpipe.required "socket_states" Jdec.int
        |> Jpipe.required "socket_types" Jdec.int

encodeMsgLinuxProcessSocketQueues : MsgLinuxProcessSocketQueues -> Jenc.Value
encodeMsgLinuxProcessSocketQueues x =
    Jenc.object
        [ ("address_of_largest", Jenc.string x.addressOfLargest)
        , ("cmdline", Jenc.string x.cmdline)
        , ("index", Jenc.int x.index)
        , ("pid", Jenc.int x.pid)
        , ("recv_queued", Jenc.int x.recvQueued)
        , ("send_queued", Jenc.int x.sendQueued)
        , ("socket_states", Jenc.int x.socketStates)
        , ("socket_types", Jenc.int x.socketTypes)
        ]

msgLinuxSocketUsage : Jdec.Decoder MsgLinuxSocketUsage
msgLinuxSocketUsage =
    Jpipe.decode MsgLinuxSocketUsage
        |> Jpipe.required "avg_queue_depth" Jdec.int
        |> Jpipe.required "max_queue_depth" Jdec.int
        |> Jpipe.required "socket_state_counts" (Jdec.array Jdec.int)
        |> Jpipe.required "socket_type_counts" (Jdec.array Jdec.int)

encodeMsgLinuxSocketUsage : MsgLinuxSocketUsage -> Jenc.Value
encodeMsgLinuxSocketUsage x =
    Jenc.object
        [ ("avg_queue_depth", Jenc.int x.avgQueueDepth)
        , ("max_queue_depth", Jenc.int x.maxQueueDepth)
        , ("socket_state_counts", makeArrayEncoder Jenc.int x.socketStateCounts)
        , ("socket_type_counts", makeArrayEncoder Jenc.int x.socketTypeCounts)
        ]

msgLinuxSysState : Jdec.Decoder MsgLinuxSysState
msgLinuxSysState =
    Jpipe.decode MsgLinuxSysState
        |> Jpipe.required "mem_total" Jdec.int
        |> Jpipe.required "pcpu" Jdec.int
        |> Jpipe.required "pid_count" Jdec.int
        |> Jpipe.required "pmem" Jdec.int
        |> Jpipe.required "procs_starting" Jdec.int
        |> Jpipe.required "procs_stopping" Jdec.int

encodeMsgLinuxSysState : MsgLinuxSysState -> Jenc.Value
encodeMsgLinuxSysState x =
    Jenc.object
        [ ("mem_total", Jenc.int x.memTotal)
        , ("pcpu", Jenc.int x.pcpu)
        , ("pid_count", Jenc.int x.pidCount)
        , ("pmem", Jenc.int x.pmem)
        , ("procs_starting", Jenc.int x.procsStarting)
        , ("procs_stopping", Jenc.int x.procsStopping)
        ]

msgLog : Jdec.Decoder MsgLog
msgLog =
    Jpipe.decode MsgLog
        |> Jpipe.required "level" Jdec.int
        |> Jpipe.required "text" Jdec.string

encodeMsgLog : MsgLog -> Jenc.Value
encodeMsgLog x =
    Jenc.object
        [ ("level", Jenc.int x.level)
        , ("text", Jenc.string x.text)
        ]

msgM25FlashWriteStatus : Jdec.Decoder MsgM25FlashWriteStatus
msgM25FlashWriteStatus =
    Jpipe.decode MsgM25FlashWriteStatus
        |> Jpipe.required "status" (Jdec.array Jdec.int)

encodeMsgM25FlashWriteStatus : MsgM25FlashWriteStatus -> Jenc.Value
encodeMsgM25FlashWriteStatus x =
    Jenc.object
        [ ("status", makeArrayEncoder Jenc.int x.status)
        ]

msgMagRaw : Jdec.Decoder MsgMagRaw
msgMagRaw =
    Jpipe.decode MsgMagRaw
        |> Jpipe.required "mag_x" Jdec.int
        |> Jpipe.required "mag_y" Jdec.int
        |> Jpipe.required "mag_z" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "tow_f" Jdec.int

encodeMsgMagRaw : MsgMagRaw -> Jenc.Value
encodeMsgMagRaw x =
    Jenc.object
        [ ("mag_x", Jenc.int x.magX)
        , ("mag_y", Jenc.int x.magY)
        , ("mag_z", Jenc.int x.magZ)
        , ("tow", Jenc.int x.tow)
        , ("tow_f", Jenc.int x.towF)
        ]

msgMaskSatellite : Jdec.Decoder MsgMaskSatellite
msgMaskSatellite =
    Jpipe.decode MsgMaskSatellite
        |> Jpipe.required "mask" Jdec.int
        |> Jpipe.required "sid" gnssSignal

encodeMsgMaskSatellite : MsgMaskSatellite -> Jenc.Value
encodeMsgMaskSatellite x =
    Jenc.object
        [ ("mask", Jenc.int x.mask)
        , ("sid", encodeGnssSignal x.sid)
        ]

msgMeasurementState : Jdec.Decoder MsgMeasurementState
msgMeasurementState =
    Jpipe.decode MsgMeasurementState
        |> Jpipe.required "states" (Jdec.array measurementState)

encodeMsgMeasurementState : MsgMeasurementState -> Jenc.Value
encodeMsgMeasurementState x =
    Jenc.object
        [ ("states", makeArrayEncoder encodeMeasurementState x.states)
        ]

measurementState : Jdec.Decoder MeasurementState
measurementState =
    Jpipe.decode MeasurementState
        |> Jpipe.required "cn0" Jdec.int
        |> Jpipe.required "mesid" gnssSignal

encodeMeasurementState : MeasurementState -> Jenc.Value
encodeMeasurementState x =
    Jenc.object
        [ ("cn0", Jenc.int x.cn0)
        , ("mesid", encodeGnssSignal x.mesid)
        ]

msgNapDeviceDnaResp : Jdec.Decoder MsgNapDeviceDnaResp
msgNapDeviceDnaResp =
    Jpipe.decode MsgNapDeviceDnaResp
        |> Jpipe.required "dna" (Jdec.array Jdec.int)

encodeMsgNapDeviceDnaResp : MsgNapDeviceDnaResp -> Jenc.Value
encodeMsgNapDeviceDnaResp x =
    Jenc.object
        [ ("dna", makeArrayEncoder Jenc.int x.dna)
        ]

msgNdbEvent : Jdec.Decoder MsgNdbEvent
msgNdbEvent =
    Jpipe.decode MsgNdbEvent
        |> Jpipe.required "data_source" Jdec.int
        |> Jpipe.required "event" Jdec.int
        |> Jpipe.required "object_sid" gnssSignal
        |> Jpipe.required "object_type" Jdec.int
        |> Jpipe.required "original_sender" Jdec.int
        |> Jpipe.required "recv_time" Jdec.int
        |> Jpipe.required "result" Jdec.int
        |> Jpipe.required "src_sid" gnssSignal

encodeMsgNdbEvent : MsgNdbEvent -> Jenc.Value
encodeMsgNdbEvent x =
    Jenc.object
        [ ("data_source", Jenc.int x.dataSource)
        , ("event", Jenc.int x.event)
        , ("object_sid", encodeGnssSignal x.objectSid)
        , ("object_type", Jenc.int x.objectType)
        , ("original_sender", Jenc.int x.originalSender)
        , ("recv_time", Jenc.int x.recvTime)
        , ("result", Jenc.int x.result)
        , ("src_sid", encodeGnssSignal x.srcSid)
        ]

msgNetworkBandwidthUsage : Jdec.Decoder MsgNetworkBandwidthUsage
msgNetworkBandwidthUsage =
    Jpipe.decode MsgNetworkBandwidthUsage
        |> Jpipe.required "interfaces" (Jdec.array networkUsage)

encodeMsgNetworkBandwidthUsage : MsgNetworkBandwidthUsage -> Jenc.Value
encodeMsgNetworkBandwidthUsage x =
    Jenc.object
        [ ("interfaces", makeArrayEncoder encodeNetworkUsage x.interfaces)
        ]

networkUsage : Jdec.Decoder NetworkUsage
networkUsage =
    Jpipe.decode NetworkUsage
        |> Jpipe.required "duration" Jdec.int
        |> Jpipe.required "interface_name" Jdec.string
        |> Jpipe.required "rx_bytes" Jdec.int
        |> Jpipe.required "total_bytes" Jdec.int
        |> Jpipe.required "tx_bytes" Jdec.int

encodeNetworkUsage : NetworkUsage -> Jenc.Value
encodeNetworkUsage x =
    Jenc.object
        [ ("duration", Jenc.int x.duration)
        , ("interface_name", Jenc.string x.interfaceName)
        , ("rx_bytes", Jenc.int x.rxBytes)
        , ("total_bytes", Jenc.int x.totalBytes)
        , ("tx_bytes", Jenc.int x.txBytes)
        ]

msgNetworkStateResp : Jdec.Decoder MsgNetworkStateResp
msgNetworkStateResp =
    Jpipe.decode MsgNetworkStateResp
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "interface_name" Jdec.string
        |> Jpipe.required "ipv4_address" (Jdec.array Jdec.int)
        |> Jpipe.required "ipv4_mask_size" Jdec.int
        |> Jpipe.required "ipv6_address" (Jdec.array Jdec.int)
        |> Jpipe.required "ipv6_mask_size" Jdec.int
        |> Jpipe.required "rx_bytes" Jdec.int
        |> Jpipe.required "tx_bytes" Jdec.int

encodeMsgNetworkStateResp : MsgNetworkStateResp -> Jenc.Value
encodeMsgNetworkStateResp x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("interface_name", Jenc.string x.interfaceName)
        , ("ipv4_address", makeArrayEncoder Jenc.int x.ipv4Address)
        , ("ipv4_mask_size", Jenc.int x.ipv4MaskSize)
        , ("ipv6_address", makeArrayEncoder Jenc.int x.ipv6Address)
        , ("ipv6_mask_size", Jenc.int x.ipv6MaskSize)
        , ("rx_bytes", Jenc.int x.rxBytes)
        , ("tx_bytes", Jenc.int x.txBytes)
        ]

msgObs : Jdec.Decoder MsgObs
msgObs =
    Jpipe.decode MsgObs
        |> Jpipe.required "header" observationHeader
        |> Jpipe.required "obs" (Jdec.array packedObsContent)

encodeMsgObs : MsgObs -> Jenc.Value
encodeMsgObs x =
    Jenc.object
        [ ("header", encodeObservationHeader x.header)
        , ("obs", makeArrayEncoder encodePackedObsContent x.obs)
        ]

observationHeader : Jdec.Decoder ObservationHeader
observationHeader =
    Jpipe.decode ObservationHeader
        |> Jpipe.required "n_obs" Jdec.int
        |> Jpipe.required "t" gpsTime

encodeObservationHeader : ObservationHeader -> Jenc.Value
encodeObservationHeader x =
    Jenc.object
        [ ("n_obs", Jenc.int x.nObs)
        , ("t", encodeGpsTime x.t)
        ]

gpsTime : Jdec.Decoder GpsTime
gpsTime =
    Jpipe.decode GpsTime
        |> Jpipe.required "ns_residual" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "wn" Jdec.int

encodeGpsTime : GpsTime -> Jenc.Value
encodeGpsTime x =
    Jenc.object
        [ ("ns_residual", Jenc.int x.nsResidual)
        , ("tow", Jenc.int x.tow)
        , ("wn", Jenc.int x.wn)
        ]

packedObsContent : Jdec.Decoder PackedObsContent
packedObsContent =
    Jpipe.decode PackedObsContent
        |> Jpipe.required "cn0" Jdec.int
        |> Jpipe.required "D" doppler
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "L" carrierPhase
        |> Jpipe.required "lock" Jdec.int
        |> Jpipe.required "P" Jdec.int
        |> Jpipe.required "sid" gnssSignal

encodePackedObsContent : PackedObsContent -> Jenc.Value
encodePackedObsContent x =
    Jenc.object
        [ ("cn0", Jenc.int x.cn0)
        , ("D", encodeDoppler x.d)
        , ("flags", Jenc.int x.flags)
        , ("L", encodeCarrierPhase x.l)
        , ("lock", Jenc.int x.lock)
        , ("P", Jenc.int x.p)
        , ("sid", encodeGnssSignal x.sid)
        ]

doppler : Jdec.Decoder Doppler
doppler =
    Jpipe.decode Doppler
        |> Jpipe.required "f" Jdec.int
        |> Jpipe.required "i" Jdec.int

encodeDoppler : Doppler -> Jenc.Value
encodeDoppler x =
    Jenc.object
        [ ("f", Jenc.int x.f)
        , ("i", Jenc.int x.i)
        ]

carrierPhase : Jdec.Decoder CarrierPhase
carrierPhase =
    Jpipe.decode CarrierPhase
        |> Jpipe.required "f" Jdec.int
        |> Jpipe.required "i" Jdec.int

encodeCarrierPhase : CarrierPhase -> Jenc.Value
encodeCarrierPhase x =
    Jenc.object
        [ ("f", Jenc.int x.f)
        , ("i", Jenc.int x.i)
        ]

msgOdometry : Jdec.Decoder MsgOdometry
msgOdometry =
    Jpipe.decode MsgOdometry
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "velocity" Jdec.int

encodeMsgOdometry : MsgOdometry -> Jenc.Value
encodeMsgOdometry x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("tow", Jenc.int x.tow)
        , ("velocity", Jenc.int x.velocity)
        ]

msgOrientEuler : Jdec.Decoder MsgOrientEuler
msgOrientEuler =
    Jpipe.decode MsgOrientEuler
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "pitch" Jdec.int
        |> Jpipe.required "pitch_accuracy" Jdec.float
        |> Jpipe.required "roll" Jdec.int
        |> Jpipe.required "roll_accuracy" Jdec.float
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "yaw" Jdec.int
        |> Jpipe.required "yaw_accuracy" Jdec.float

encodeMsgOrientEuler : MsgOrientEuler -> Jenc.Value
encodeMsgOrientEuler x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("pitch", Jenc.int x.pitch)
        , ("pitch_accuracy", Jenc.float x.pitchAccuracy)
        , ("roll", Jenc.int x.roll)
        , ("roll_accuracy", Jenc.float x.rollAccuracy)
        , ("tow", Jenc.int x.tow)
        , ("yaw", Jenc.int x.yaw)
        , ("yaw_accuracy", Jenc.float x.yawAccuracy)
        ]

msgOrientQuat : Jdec.Decoder MsgOrientQuat
msgOrientQuat =
    Jpipe.decode MsgOrientQuat
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "w" Jdec.int
        |> Jpipe.required "w_accuracy" Jdec.float
        |> Jpipe.required "x" Jdec.int
        |> Jpipe.required "x_accuracy" Jdec.float
        |> Jpipe.required "y" Jdec.int
        |> Jpipe.required "y_accuracy" Jdec.float
        |> Jpipe.required "z" Jdec.int
        |> Jpipe.required "z_accuracy" Jdec.float

encodeMsgOrientQuat : MsgOrientQuat -> Jenc.Value
encodeMsgOrientQuat x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("tow", Jenc.int x.tow)
        , ("w", Jenc.int x.w)
        , ("w_accuracy", Jenc.float x.wAccuracy)
        , ("x", Jenc.int x.x)
        , ("x_accuracy", Jenc.float x.xAccuracy)
        , ("y", Jenc.int x.y)
        , ("y_accuracy", Jenc.float x.yAccuracy)
        , ("z", Jenc.int x.z)
        , ("z_accuracy", Jenc.float x.zAccuracy)
        ]

msgOsr : Jdec.Decoder MsgOsr
msgOsr =
    Jpipe.decode MsgOsr
        |> Jpipe.required "header" observationHeader
        |> Jpipe.required "obs" (Jdec.array packedOsrContent)

encodeMsgOsr : MsgOsr -> Jenc.Value
encodeMsgOsr x =
    Jenc.object
        [ ("header", encodeObservationHeader x.header)
        , ("obs", makeArrayEncoder encodePackedOsrContent x.obs)
        ]

packedOsrContent : Jdec.Decoder PackedOsrContent
packedOsrContent =
    Jpipe.decode PackedOsrContent
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "iono_std" Jdec.int
        |> Jpipe.required "L" carrierPhase
        |> Jpipe.required "lock" Jdec.int
        |> Jpipe.required "P" Jdec.int
        |> Jpipe.required "range_std" Jdec.int
        |> Jpipe.required "sid" gnssSignal
        |> Jpipe.required "tropo_std" Jdec.int

encodePackedOsrContent : PackedOsrContent -> Jenc.Value
encodePackedOsrContent x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("iono_std", Jenc.int x.ionoStd)
        , ("L", encodeCarrierPhase x.l)
        , ("lock", Jenc.int x.lock)
        , ("P", Jenc.int x.p)
        , ("range_std", Jenc.int x.rangeStd)
        , ("sid", encodeGnssSignal x.sid)
        , ("tropo_std", Jenc.int x.tropoStd)
        ]

msgPosECEFCov : Jdec.Decoder MsgPosECEFCov
msgPosECEFCov =
    Jpipe.decode MsgPosECEFCov
        |> Jpipe.required "cov_x_x" Jdec.float
        |> Jpipe.required "cov_x_y" Jdec.float
        |> Jpipe.required "cov_x_z" Jdec.float
        |> Jpipe.required "cov_y_y" Jdec.float
        |> Jpipe.required "cov_y_z" Jdec.float
        |> Jpipe.required "cov_z_z" Jdec.float
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "x" Jdec.float
        |> Jpipe.required "y" Jdec.float
        |> Jpipe.required "z" Jdec.float

encodeMsgPosECEFCov : MsgPosECEFCov -> Jenc.Value
encodeMsgPosECEFCov x =
    Jenc.object
        [ ("cov_x_x", Jenc.float x.covXX)
        , ("cov_x_y", Jenc.float x.covXY)
        , ("cov_x_z", Jenc.float x.covXZ)
        , ("cov_y_y", Jenc.float x.covYY)
        , ("cov_y_z", Jenc.float x.covYZ)
        , ("cov_z_z", Jenc.float x.covZZ)
        , ("flags", Jenc.int x.flags)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        , ("x", Jenc.float x.x)
        , ("y", Jenc.float x.y)
        , ("z", Jenc.float x.z)
        ]

msgPosECEF : Jdec.Decoder MsgPosECEF
msgPosECEF =
    Jpipe.decode MsgPosECEF
        |> Jpipe.required "accuracy" Jdec.int
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "x" Jdec.float
        |> Jpipe.required "y" Jdec.float
        |> Jpipe.required "z" Jdec.float

encodeMsgPosECEF : MsgPosECEF -> Jenc.Value
encodeMsgPosECEF x =
    Jenc.object
        [ ("accuracy", Jenc.int x.accuracy)
        , ("flags", Jenc.int x.flags)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        , ("x", Jenc.float x.x)
        , ("y", Jenc.float x.y)
        , ("z", Jenc.float x.z)
        ]

msgPosLLHCov : Jdec.Decoder MsgPosLLHCov
msgPosLLHCov =
    Jpipe.decode MsgPosLLHCov
        |> Jpipe.required "cov_d_d" Jdec.float
        |> Jpipe.required "cov_e_d" Jdec.float
        |> Jpipe.required "cov_e_e" Jdec.float
        |> Jpipe.required "cov_n_d" Jdec.float
        |> Jpipe.required "cov_n_e" Jdec.float
        |> Jpipe.required "cov_n_n" Jdec.float
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "height" Jdec.float
        |> Jpipe.required "lat" Jdec.float
        |> Jpipe.required "lon" Jdec.float
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int

encodeMsgPosLLHCov : MsgPosLLHCov -> Jenc.Value
encodeMsgPosLLHCov x =
    Jenc.object
        [ ("cov_d_d", Jenc.float x.covDD)
        , ("cov_e_d", Jenc.float x.covED)
        , ("cov_e_e", Jenc.float x.covEE)
        , ("cov_n_d", Jenc.float x.covND)
        , ("cov_n_e", Jenc.float x.covNE)
        , ("cov_n_n", Jenc.float x.covNN)
        , ("flags", Jenc.int x.flags)
        , ("height", Jenc.float x.height)
        , ("lat", Jenc.float x.lat)
        , ("lon", Jenc.float x.lon)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        ]

msgPosLLH : Jdec.Decoder MsgPosLLH
msgPosLLH =
    Jpipe.decode MsgPosLLH
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "h_accuracy" Jdec.int
        |> Jpipe.required "height" Jdec.float
        |> Jpipe.required "lat" Jdec.float
        |> Jpipe.required "lon" Jdec.float
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "v_accuracy" Jdec.int

encodeMsgPosLLH : MsgPosLLH -> Jenc.Value
encodeMsgPosLLH x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        , ("h_accuracy", Jenc.int x.hAccuracy)
        , ("height", Jenc.float x.height)
        , ("lat", Jenc.float x.lat)
        , ("lon", Jenc.float x.lon)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        , ("v_accuracy", Jenc.int x.vAccuracy)
        ]

msgResetFilters : Jdec.Decoder MsgResetFilters
msgResetFilters =
    Jpipe.decode MsgResetFilters
        |> Jpipe.required "filter" Jdec.int

encodeMsgResetFilters : MsgResetFilters -> Jenc.Value
encodeMsgResetFilters x =
    Jenc.object
        [ ("filter", Jenc.int x.filter)
        ]

msgReset : Jdec.Decoder MsgReset
msgReset =
    Jpipe.decode MsgReset
        |> Jpipe.required "flags" Jdec.int

encodeMsgReset : MsgReset -> Jenc.Value
encodeMsgReset x =
    Jenc.object
        [ ("flags", Jenc.int x.flags)
        ]

msgSbasRaw : Jdec.Decoder MsgSbasRaw
msgSbasRaw =
    Jpipe.decode MsgSbasRaw
        |> Jpipe.required "data" (Jdec.array Jdec.int)
        |> Jpipe.required "message_type" Jdec.int
        |> Jpipe.required "sid" gnssSignal
        |> Jpipe.required "tow" Jdec.int

encodeMsgSbasRaw : MsgSbasRaw -> Jenc.Value
encodeMsgSbasRaw x =
    Jenc.object
        [ ("data", makeArrayEncoder Jenc.int x.data)
        , ("message_type", Jenc.int x.messageType)
        , ("sid", encodeGnssSignal x.sid)
        , ("tow", Jenc.int x.tow)
        ]

msgSettingsReadByIndexReq : Jdec.Decoder MsgSettingsReadByIndexReq
msgSettingsReadByIndexReq =
    Jpipe.decode MsgSettingsReadByIndexReq
        |> Jpipe.required "index" Jdec.int

encodeMsgSettingsReadByIndexReq : MsgSettingsReadByIndexReq -> Jenc.Value
encodeMsgSettingsReadByIndexReq x =
    Jenc.object
        [ ("index", Jenc.int x.index)
        ]

msgSettingsReadByIndexResp : Jdec.Decoder MsgSettingsReadByIndexResp
msgSettingsReadByIndexResp =
    Jpipe.decode MsgSettingsReadByIndexResp
        |> Jpipe.required "index" Jdec.int
        |> Jpipe.required "setting" Jdec.string

encodeMsgSettingsReadByIndexResp : MsgSettingsReadByIndexResp -> Jenc.Value
encodeMsgSettingsReadByIndexResp x =
    Jenc.object
        [ ("index", Jenc.int x.index)
        , ("setting", Jenc.string x.setting)
        ]

msgSettingsReadReq : Jdec.Decoder MsgSettingsReadReq
msgSettingsReadReq =
    Jpipe.decode MsgSettingsReadReq
        |> Jpipe.required "setting" Jdec.string

encodeMsgSettingsReadReq : MsgSettingsReadReq -> Jenc.Value
encodeMsgSettingsReadReq x =
    Jenc.object
        [ ("setting", Jenc.string x.setting)
        ]

msgSettingsReadResp : Jdec.Decoder MsgSettingsReadResp
msgSettingsReadResp =
    Jpipe.decode MsgSettingsReadResp
        |> Jpipe.required "setting" Jdec.string

encodeMsgSettingsReadResp : MsgSettingsReadResp -> Jenc.Value
encodeMsgSettingsReadResp x =
    Jenc.object
        [ ("setting", Jenc.string x.setting)
        ]

msgSettingsRegister : Jdec.Decoder MsgSettingsRegister
msgSettingsRegister =
    Jpipe.decode MsgSettingsRegister
        |> Jpipe.required "setting" Jdec.string

encodeMsgSettingsRegister : MsgSettingsRegister -> Jenc.Value
encodeMsgSettingsRegister x =
    Jenc.object
        [ ("setting", Jenc.string x.setting)
        ]

msgSettingsRegisterResp : Jdec.Decoder MsgSettingsRegisterResp
msgSettingsRegisterResp =
    Jpipe.decode MsgSettingsRegisterResp
        |> Jpipe.required "setting" Jdec.string
        |> Jpipe.required "status" Jdec.int

encodeMsgSettingsRegisterResp : MsgSettingsRegisterResp -> Jenc.Value
encodeMsgSettingsRegisterResp x =
    Jenc.object
        [ ("setting", Jenc.string x.setting)
        , ("status", Jenc.int x.status)
        ]

msgSettingsWrite : Jdec.Decoder MsgSettingsWrite
msgSettingsWrite =
    Jpipe.decode MsgSettingsWrite
        |> Jpipe.required "setting" Jdec.string

encodeMsgSettingsWrite : MsgSettingsWrite -> Jenc.Value
encodeMsgSettingsWrite x =
    Jenc.object
        [ ("setting", Jenc.string x.setting)
        ]

msgSettingsWriteResp : Jdec.Decoder MsgSettingsWriteResp
msgSettingsWriteResp =
    Jpipe.decode MsgSettingsWriteResp
        |> Jpipe.required "setting" Jdec.string
        |> Jpipe.required "status" Jdec.int

encodeMsgSettingsWriteResp : MsgSettingsWriteResp -> Jenc.Value
encodeMsgSettingsWriteResp x =
    Jenc.object
        [ ("setting", Jenc.string x.setting)
        , ("status", Jenc.int x.status)
        ]

msgSpecan : Jdec.Decoder MsgSpecan
msgSpecan =
    Jpipe.decode MsgSpecan
        |> Jpipe.required "amplitude_ref" Jdec.float
        |> Jpipe.required "amplitude_unit" Jdec.float
        |> Jpipe.required "amplitude_value" (Jdec.array Jdec.int)
        |> Jpipe.required "channel_tag" Jdec.int
        |> Jpipe.required "freq_ref" Jdec.float
        |> Jpipe.required "freq_step" Jdec.float
        |> Jpipe.required "t" gpsTime

encodeMsgSpecan : MsgSpecan -> Jenc.Value
encodeMsgSpecan x =
    Jenc.object
        [ ("amplitude_ref", Jenc.float x.amplitudeRef)
        , ("amplitude_unit", Jenc.float x.amplitudeUnit)
        , ("amplitude_value", makeArrayEncoder Jenc.int x.amplitudeValue)
        , ("channel_tag", Jenc.int x.channelTag)
        , ("freq_ref", Jenc.float x.freqRef)
        , ("freq_step", Jenc.float x.freqStep)
        , ("t", encodeGpsTime x.t)
        ]

msgSsrCodeBiases : Jdec.Decoder MsgSsrCodeBiases
msgSsrCodeBiases =
    Jpipe.decode MsgSsrCodeBiases
        |> Jpipe.required "biases" (Jdec.array codeBiasesContent)
        |> Jpipe.required "iod_ssr" Jdec.int
        |> Jpipe.required "sid" gnssSignal
        |> Jpipe.required "time" gpsTimeSEC
        |> Jpipe.required "update_interval" Jdec.int

encodeMsgSsrCodeBiases : MsgSsrCodeBiases -> Jenc.Value
encodeMsgSsrCodeBiases x =
    Jenc.object
        [ ("biases", makeArrayEncoder encodeCodeBiasesContent x.biases)
        , ("iod_ssr", Jenc.int x.iodSsr)
        , ("sid", encodeGnssSignal x.sid)
        , ("time", encodeGpsTimeSEC x.time)
        , ("update_interval", Jenc.int x.updateInterval)
        ]

codeBiasesContent : Jdec.Decoder CodeBiasesContent
codeBiasesContent =
    Jpipe.decode CodeBiasesContent
        |> Jpipe.required "code" Jdec.int
        |> Jpipe.required "value" Jdec.int

encodeCodeBiasesContent : CodeBiasesContent -> Jenc.Value
encodeCodeBiasesContent x =
    Jenc.object
        [ ("code", Jenc.int x.code)
        , ("value", Jenc.int x.value)
        ]

msgSsrGriddedCorrection : Jdec.Decoder MsgSsrGriddedCorrection
msgSsrGriddedCorrection =
    Jpipe.decode MsgSsrGriddedCorrection
        |> Jpipe.required "element" gridElement
        |> Jpipe.required "header" griddedCorrectionHeader

encodeMsgSsrGriddedCorrection : MsgSsrGriddedCorrection -> Jenc.Value
encodeMsgSsrGriddedCorrection x =
    Jenc.object
        [ ("element", encodeGridElement x.element)
        , ("header", encodeGriddedCorrectionHeader x.header)
        ]

gridElement : Jdec.Decoder GridElement
gridElement =
    Jpipe.decode GridElement
        |> Jpipe.required "index" Jdec.int
        |> Jpipe.required "stec_residuals" (Jdec.array stecResidual)
        |> Jpipe.required "tropo_delay_correction" troposphericDelayCorrection

encodeGridElement : GridElement -> Jenc.Value
encodeGridElement x =
    Jenc.object
        [ ("index", Jenc.int x.index)
        , ("stec_residuals", makeArrayEncoder encodeSTECResidual x.stecResiduals)
        , ("tropo_delay_correction", encodeTroposphericDelayCorrection x.tropoDelayCorrection)
        ]

stecResidual : Jdec.Decoder STECResidual
stecResidual =
    Jpipe.decode STECResidual
        |> Jpipe.required "residual" Jdec.int
        |> Jpipe.required "sv_id" svID

encodeSTECResidual : STECResidual -> Jenc.Value
encodeSTECResidual x =
    Jenc.object
        [ ("residual", Jenc.int x.residual)
        , ("sv_id", encodeSvID x.svID)
        ]

svID : Jdec.Decoder SvID
svID =
    Jpipe.decode SvID
        |> Jpipe.required "constellation" Jdec.int
        |> Jpipe.required "satId" Jdec.int

encodeSvID : SvID -> Jenc.Value
encodeSvID x =
    Jenc.object
        [ ("constellation", Jenc.int x.constellation)
        , ("satId", Jenc.int x.satID)
        ]

troposphericDelayCorrection : Jdec.Decoder TroposphericDelayCorrection
troposphericDelayCorrection =
    Jpipe.decode TroposphericDelayCorrection
        |> Jpipe.required "hydro" Jdec.int
        |> Jpipe.required "wet" Jdec.int

encodeTroposphericDelayCorrection : TroposphericDelayCorrection -> Jenc.Value
encodeTroposphericDelayCorrection x =
    Jenc.object
        [ ("hydro", Jenc.int x.hydro)
        , ("wet", Jenc.int x.wet)
        ]

griddedCorrectionHeader : Jdec.Decoder GriddedCorrectionHeader
griddedCorrectionHeader =
    Jpipe.decode GriddedCorrectionHeader
        |> Jpipe.required "iod_atmo" Jdec.int
        |> Jpipe.required "num_msgs" Jdec.int
        |> Jpipe.required "seq_num" Jdec.int
        |> Jpipe.required "time" gpsTimeSEC
        |> Jpipe.required "tropo_quality_indicator" Jdec.int
        |> Jpipe.required "update_interval" Jdec.int

encodeGriddedCorrectionHeader : GriddedCorrectionHeader -> Jenc.Value
encodeGriddedCorrectionHeader x =
    Jenc.object
        [ ("iod_atmo", Jenc.int x.iodAtmo)
        , ("num_msgs", Jenc.int x.numMsgs)
        , ("seq_num", Jenc.int x.seqNum)
        , ("time", encodeGpsTimeSEC x.time)
        , ("tropo_quality_indicator", Jenc.int x.tropoQualityIndicator)
        , ("update_interval", Jenc.int x.updateInterval)
        ]

msgSsrGridDefinition : Jdec.Decoder MsgSsrGridDefinition
msgSsrGridDefinition =
    Jpipe.decode MsgSsrGridDefinition
        |> Jpipe.required "header" gridDefinitionHeader
        |> Jpipe.required "rle_list" (Jdec.array Jdec.int)

encodeMsgSsrGridDefinition : MsgSsrGridDefinition -> Jenc.Value
encodeMsgSsrGridDefinition x =
    Jenc.object
        [ ("header", encodeGridDefinitionHeader x.header)
        , ("rle_list", makeArrayEncoder Jenc.int x.rleList)
        ]

gridDefinitionHeader : Jdec.Decoder GridDefinitionHeader
gridDefinitionHeader =
    Jpipe.decode GridDefinitionHeader
        |> Jpipe.required "area_width" Jdec.int
        |> Jpipe.required "lat_nw_corner_enc" Jdec.int
        |> Jpipe.required "lon_nw_corner_enc" Jdec.int
        |> Jpipe.required "num_msgs" Jdec.int
        |> Jpipe.required "region_size_inverse" Jdec.int
        |> Jpipe.required "seq_num" Jdec.int

encodeGridDefinitionHeader : GridDefinitionHeader -> Jenc.Value
encodeGridDefinitionHeader x =
    Jenc.object
        [ ("area_width", Jenc.int x.areaWidth)
        , ("lat_nw_corner_enc", Jenc.int x.latNwCornerEnc)
        , ("lon_nw_corner_enc", Jenc.int x.lonNwCornerEnc)
        , ("num_msgs", Jenc.int x.numMsgs)
        , ("region_size_inverse", Jenc.int x.regionSizeInverse)
        , ("seq_num", Jenc.int x.seqNum)
        ]

msgSsrOrbitClock : Jdec.Decoder MsgSsrOrbitClock
msgSsrOrbitClock =
    Jpipe.decode MsgSsrOrbitClock
        |> Jpipe.required "along" Jdec.int
        |> Jpipe.required "c0" Jdec.int
        |> Jpipe.required "c1" Jdec.int
        |> Jpipe.required "c2" Jdec.int
        |> Jpipe.required "cross" Jdec.int
        |> Jpipe.required "dot_along" Jdec.int
        |> Jpipe.required "dot_cross" Jdec.int
        |> Jpipe.required "dot_radial" Jdec.int
        |> Jpipe.required "iod" Jdec.int
        |> Jpipe.required "iod_ssr" Jdec.int
        |> Jpipe.required "radial" Jdec.int
        |> Jpipe.required "sid" gnssSignal
        |> Jpipe.required "time" gpsTimeSEC
        |> Jpipe.required "update_interval" Jdec.int

encodeMsgSsrOrbitClock : MsgSsrOrbitClock -> Jenc.Value
encodeMsgSsrOrbitClock x =
    Jenc.object
        [ ("along", Jenc.int x.along)
        , ("c0", Jenc.int x.c0)
        , ("c1", Jenc.int x.c1)
        , ("c2", Jenc.int x.c2)
        , ("cross", Jenc.int x.cross)
        , ("dot_along", Jenc.int x.dotAlong)
        , ("dot_cross", Jenc.int x.dotCross)
        , ("dot_radial", Jenc.int x.dotRadial)
        , ("iod", Jenc.int x.iod)
        , ("iod_ssr", Jenc.int x.iodSsr)
        , ("radial", Jenc.int x.radial)
        , ("sid", encodeGnssSignal x.sid)
        , ("time", encodeGpsTimeSEC x.time)
        , ("update_interval", Jenc.int x.updateInterval)
        ]

msgSsrPhaseBiases : Jdec.Decoder MsgSsrPhaseBiases
msgSsrPhaseBiases =
    Jpipe.decode MsgSsrPhaseBiases
        |> Jpipe.required "biases" (Jdec.array phaseBiasesContent)
        |> Jpipe.required "dispersive_bias" Jdec.int
        |> Jpipe.required "iod_ssr" Jdec.int
        |> Jpipe.required "mw_consistency" Jdec.int
        |> Jpipe.required "sid" gnssSignal
        |> Jpipe.required "time" gpsTimeSEC
        |> Jpipe.required "update_interval" Jdec.int
        |> Jpipe.required "yaw" Jdec.int
        |> Jpipe.required "yaw_rate" Jdec.int

encodeMsgSsrPhaseBiases : MsgSsrPhaseBiases -> Jenc.Value
encodeMsgSsrPhaseBiases x =
    Jenc.object
        [ ("biases", makeArrayEncoder encodePhaseBiasesContent x.biases)
        , ("dispersive_bias", Jenc.int x.dispersiveBias)
        , ("iod_ssr", Jenc.int x.iodSsr)
        , ("mw_consistency", Jenc.int x.mwConsistency)
        , ("sid", encodeGnssSignal x.sid)
        , ("time", encodeGpsTimeSEC x.time)
        , ("update_interval", Jenc.int x.updateInterval)
        , ("yaw", Jenc.int x.yaw)
        , ("yaw_rate", Jenc.int x.yawRate)
        ]

phaseBiasesContent : Jdec.Decoder PhaseBiasesContent
phaseBiasesContent =
    Jpipe.decode PhaseBiasesContent
        |> Jpipe.required "bias" Jdec.int
        |> Jpipe.required "code" Jdec.int
        |> Jpipe.required "discontinuity_counter" Jdec.int
        |> Jpipe.required "integer_indicator" Jdec.int
        |> Jpipe.required "widelane_integer_indicator" Jdec.int

encodePhaseBiasesContent : PhaseBiasesContent -> Jenc.Value
encodePhaseBiasesContent x =
    Jenc.object
        [ ("bias", Jenc.int x.bias)
        , ("code", Jenc.int x.code)
        , ("discontinuity_counter", Jenc.int x.discontinuityCounter)
        , ("integer_indicator", Jenc.int x.integerIndicator)
        , ("widelane_integer_indicator", Jenc.int x.widelaneIntegerIndicator)
        ]

msgSsrStecCorrection : Jdec.Decoder MsgSsrStecCorrection
msgSsrStecCorrection =
    Jpipe.decode MsgSsrStecCorrection
        |> Jpipe.required "header" stecHeader
        |> Jpipe.required "stec_sat_list" (Jdec.array stecSatElement)

encodeMsgSsrStecCorrection : MsgSsrStecCorrection -> Jenc.Value
encodeMsgSsrStecCorrection x =
    Jenc.object
        [ ("header", encodeSTECHeader x.header)
        , ("stec_sat_list", makeArrayEncoder encodeSTECSatElement x.stecSatList)
        ]

stecHeader : Jdec.Decoder STECHeader
stecHeader =
    Jpipe.decode STECHeader
        |> Jpipe.required "iod_atmo" Jdec.int
        |> Jpipe.required "num_msgs" Jdec.int
        |> Jpipe.required "seq_num" Jdec.int
        |> Jpipe.required "time" gpsTimeSEC
        |> Jpipe.required "update_interval" Jdec.int

encodeSTECHeader : STECHeader -> Jenc.Value
encodeSTECHeader x =
    Jenc.object
        [ ("iod_atmo", Jenc.int x.iodAtmo)
        , ("num_msgs", Jenc.int x.numMsgs)
        , ("seq_num", Jenc.int x.seqNum)
        , ("time", encodeGpsTimeSEC x.time)
        , ("update_interval", Jenc.int x.updateInterval)
        ]

stecSatElement : Jdec.Decoder STECSatElement
stecSatElement =
    Jpipe.decode STECSatElement
        |> Jpipe.required "stec_coeff" (Jdec.array Jdec.int)
        |> Jpipe.required "stec_quality_indicator" Jdec.int
        |> Jpipe.required "sv_id" svID

encodeSTECSatElement : STECSatElement -> Jenc.Value
encodeSTECSatElement x =
    Jenc.object
        [ ("stec_coeff", makeArrayEncoder Jenc.int x.stecCoeff)
        , ("stec_quality_indicator", Jenc.int x.stecQualityIndicator)
        , ("sv_id", encodeSvID x.svID)
        ]

msgStartup : Jdec.Decoder MsgStartup
msgStartup =
    Jpipe.decode MsgStartup
        |> Jpipe.required "cause" Jdec.int
        |> Jpipe.required "startup_type" Jdec.int

encodeMsgStartup : MsgStartup -> Jenc.Value
encodeMsgStartup x =
    Jenc.object
        [ ("cause", Jenc.int x.cause)
        , ("startup_type", Jenc.int x.startupType)
        ]

msgStmFlashLockSector : Jdec.Decoder MsgStmFlashLockSector
msgStmFlashLockSector =
    Jpipe.decode MsgStmFlashLockSector
        |> Jpipe.required "sector" Jdec.int

encodeMsgStmFlashLockSector : MsgStmFlashLockSector -> Jenc.Value
encodeMsgStmFlashLockSector x =
    Jenc.object
        [ ("sector", Jenc.int x.sector)
        ]

msgStmFlashUnlockSector : Jdec.Decoder MsgStmFlashUnlockSector
msgStmFlashUnlockSector =
    Jpipe.decode MsgStmFlashUnlockSector
        |> Jpipe.required "sector" Jdec.int

encodeMsgStmFlashUnlockSector : MsgStmFlashUnlockSector -> Jenc.Value
encodeMsgStmFlashUnlockSector x =
    Jenc.object
        [ ("sector", Jenc.int x.sector)
        ]

msgStmUniqueIDResp : Jdec.Decoder MsgStmUniqueIDResp
msgStmUniqueIDResp =
    Jpipe.decode MsgStmUniqueIDResp
        |> Jpipe.required "stm_id" (Jdec.array Jdec.int)

encodeMsgStmUniqueIDResp : MsgStmUniqueIDResp -> Jenc.Value
encodeMsgStmUniqueIDResp x =
    Jenc.object
        [ ("stm_id", makeArrayEncoder Jenc.int x.stmID)
        ]

msgSvAzEl : Jdec.Decoder MsgSvAzEl
msgSvAzEl =
    Jpipe.decode MsgSvAzEl
        |> Jpipe.required "azel" (Jdec.array svAzEl)

encodeMsgSvAzEl : MsgSvAzEl -> Jenc.Value
encodeMsgSvAzEl x =
    Jenc.object
        [ ("azel", makeArrayEncoder encodeSvAzEl x.azel)
        ]

svAzEl : Jdec.Decoder SvAzEl
svAzEl =
    Jpipe.decode SvAzEl
        |> Jpipe.required "az" Jdec.int
        |> Jpipe.required "el" Jdec.int
        |> Jpipe.required "sid" gnssSignal

encodeSvAzEl : SvAzEl -> Jenc.Value
encodeSvAzEl x =
    Jenc.object
        [ ("az", Jenc.int x.az)
        , ("el", Jenc.int x.el)
        , ("sid", encodeGnssSignal x.sid)
        ]

msgThreadState : Jdec.Decoder MsgThreadState
msgThreadState =
    Jpipe.decode MsgThreadState
        |> Jpipe.required "cpu" Jdec.int
        |> Jpipe.required "name" Jdec.string
        |> Jpipe.required "stack_free" Jdec.int

encodeMsgThreadState : MsgThreadState -> Jenc.Value
encodeMsgThreadState x =
    Jenc.object
        [ ("cpu", Jenc.int x.cpu)
        , ("name", Jenc.string x.name)
        , ("stack_free", Jenc.int x.stackFree)
        ]

msgTrackingIq : Jdec.Decoder MsgTrackingIq
msgTrackingIq =
    Jpipe.decode MsgTrackingIq
        |> Jpipe.required "channel" Jdec.int
        |> Jpipe.required "corrs" (Jdec.array trackingChannelCorrelation)
        |> Jpipe.required "sid" gnssSignal

encodeMsgTrackingIq : MsgTrackingIq -> Jenc.Value
encodeMsgTrackingIq x =
    Jenc.object
        [ ("channel", Jenc.int x.channel)
        , ("corrs", makeArrayEncoder encodeTrackingChannelCorrelation x.corrs)
        , ("sid", encodeGnssSignal x.sid)
        ]

trackingChannelCorrelation : Jdec.Decoder TrackingChannelCorrelation
trackingChannelCorrelation =
    Jpipe.decode TrackingChannelCorrelation
        |> Jpipe.required "I" Jdec.int
        |> Jpipe.required "Q" Jdec.int

encodeTrackingChannelCorrelation : TrackingChannelCorrelation -> Jenc.Value
encodeTrackingChannelCorrelation x =
    Jenc.object
        [ ("I", Jenc.int x.i)
        , ("Q", Jenc.int x.q)
        ]

msgTrackingState : Jdec.Decoder MsgTrackingState
msgTrackingState =
    Jpipe.decode MsgTrackingState
        |> Jpipe.required "states" (Jdec.array trackingChannelState)

encodeMsgTrackingState : MsgTrackingState -> Jenc.Value
encodeMsgTrackingState x =
    Jenc.object
        [ ("states", makeArrayEncoder encodeTrackingChannelState x.states)
        ]

trackingChannelState : Jdec.Decoder TrackingChannelState
trackingChannelState =
    Jpipe.decode TrackingChannelState
        |> Jpipe.required "cn0" Jdec.int
        |> Jpipe.required "fcn" Jdec.int
        |> Jpipe.required "sid" gnssSignal

encodeTrackingChannelState : TrackingChannelState -> Jenc.Value
encodeTrackingChannelState x =
    Jenc.object
        [ ("cn0", Jenc.int x.cn0)
        , ("fcn", Jenc.int x.fcn)
        , ("sid", encodeGnssSignal x.sid)
        ]

msgUARTState : Jdec.Decoder MsgUARTState
msgUARTState =
    Jpipe.decode MsgUARTState
        |> Jpipe.required "latency" latency
        |> Jpipe.required "obs_period" period
        |> Jpipe.required "uart_a" uartChannel
        |> Jpipe.required "uart_b" uartChannel
        |> Jpipe.required "uart_ftdi" uartChannel

encodeMsgUARTState : MsgUARTState -> Jenc.Value
encodeMsgUARTState x =
    Jenc.object
        [ ("latency", encodeLatency x.latency)
        , ("obs_period", encodePeriod x.obsPeriod)
        , ("uart_a", encodeUARTChannel x.uartA)
        , ("uart_b", encodeUARTChannel x.uartB)
        , ("uart_ftdi", encodeUARTChannel x.uartFtdi)
        ]

latency : Jdec.Decoder Latency
latency =
    Jpipe.decode Latency
        |> Jpipe.required "avg" Jdec.int
        |> Jpipe.required "current" Jdec.int
        |> Jpipe.required "lmax" Jdec.int
        |> Jpipe.required "lmin" Jdec.int

encodeLatency : Latency -> Jenc.Value
encodeLatency x =
    Jenc.object
        [ ("avg", Jenc.int x.avg)
        , ("current", Jenc.int x.current)
        , ("lmax", Jenc.int x.lmax)
        , ("lmin", Jenc.int x.lmin)
        ]

period : Jdec.Decoder Period
period =
    Jpipe.decode Period
        |> Jpipe.required "avg" Jdec.int
        |> Jpipe.required "current" Jdec.int
        |> Jpipe.required "pmax" Jdec.int
        |> Jpipe.required "pmin" Jdec.int

encodePeriod : Period -> Jenc.Value
encodePeriod x =
    Jenc.object
        [ ("avg", Jenc.int x.avg)
        , ("current", Jenc.int x.current)
        , ("pmax", Jenc.int x.pmax)
        , ("pmin", Jenc.int x.pmin)
        ]

uartChannel : Jdec.Decoder UARTChannel
uartChannel =
    Jpipe.decode UARTChannel
        |> Jpipe.required "crc_error_count" Jdec.int
        |> Jpipe.required "io_error_count" Jdec.int
        |> Jpipe.required "rx_buffer_level" Jdec.int
        |> Jpipe.required "rx_throughput" Jdec.float
        |> Jpipe.required "tx_buffer_level" Jdec.int
        |> Jpipe.required "tx_throughput" Jdec.float

encodeUARTChannel : UARTChannel -> Jenc.Value
encodeUARTChannel x =
    Jenc.object
        [ ("crc_error_count", Jenc.int x.crcErrorCount)
        , ("io_error_count", Jenc.int x.ioErrorCount)
        , ("rx_buffer_level", Jenc.int x.rxBufferLevel)
        , ("rx_throughput", Jenc.float x.rxThroughput)
        , ("tx_buffer_level", Jenc.int x.txBufferLevel)
        , ("tx_throughput", Jenc.float x.txThroughput)
        ]

msgUserData : Jdec.Decoder MsgUserData
msgUserData =
    Jpipe.decode MsgUserData
        |> Jpipe.required "contents" (Jdec.array Jdec.int)

encodeMsgUserData : MsgUserData -> Jenc.Value
encodeMsgUserData x =
    Jenc.object
        [ ("contents", makeArrayEncoder Jenc.int x.contents)
        ]

msgUTCTime : Jdec.Decoder MsgUTCTime
msgUTCTime =
    Jpipe.decode MsgUTCTime
        |> Jpipe.required "day" Jdec.int
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "hours" Jdec.int
        |> Jpipe.required "minutes" Jdec.int
        |> Jpipe.required "month" Jdec.int
        |> Jpipe.required "ns" Jdec.int
        |> Jpipe.required "seconds" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "year" Jdec.int

encodeMsgUTCTime : MsgUTCTime -> Jenc.Value
encodeMsgUTCTime x =
    Jenc.object
        [ ("day", Jenc.int x.day)
        , ("flags", Jenc.int x.flags)
        , ("hours", Jenc.int x.hours)
        , ("minutes", Jenc.int x.minutes)
        , ("month", Jenc.int x.month)
        , ("ns", Jenc.int x.ns)
        , ("seconds", Jenc.int x.seconds)
        , ("tow", Jenc.int x.tow)
        , ("year", Jenc.int x.year)
        ]

msgVelBody : Jdec.Decoder MsgVelBody
msgVelBody =
    Jpipe.decode MsgVelBody
        |> Jpipe.required "cov_x_x" Jdec.float
        |> Jpipe.required "cov_x_y" Jdec.float
        |> Jpipe.required "cov_x_z" Jdec.float
        |> Jpipe.required "cov_y_y" Jdec.float
        |> Jpipe.required "cov_y_z" Jdec.float
        |> Jpipe.required "cov_z_z" Jdec.float
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "x" Jdec.int
        |> Jpipe.required "y" Jdec.int
        |> Jpipe.required "z" Jdec.int

encodeMsgVelBody : MsgVelBody -> Jenc.Value
encodeMsgVelBody x =
    Jenc.object
        [ ("cov_x_x", Jenc.float x.covXX)
        , ("cov_x_y", Jenc.float x.covXY)
        , ("cov_x_z", Jenc.float x.covXZ)
        , ("cov_y_y", Jenc.float x.covYY)
        , ("cov_y_z", Jenc.float x.covYZ)
        , ("cov_z_z", Jenc.float x.covZZ)
        , ("flags", Jenc.int x.flags)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        , ("x", Jenc.int x.x)
        , ("y", Jenc.int x.y)
        , ("z", Jenc.int x.z)
        ]

msgVelECEFCov : Jdec.Decoder MsgVelECEFCov
msgVelECEFCov =
    Jpipe.decode MsgVelECEFCov
        |> Jpipe.required "cov_x_x" Jdec.float
        |> Jpipe.required "cov_x_y" Jdec.float
        |> Jpipe.required "cov_x_z" Jdec.float
        |> Jpipe.required "cov_y_y" Jdec.float
        |> Jpipe.required "cov_y_z" Jdec.float
        |> Jpipe.required "cov_z_z" Jdec.float
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "x" Jdec.int
        |> Jpipe.required "y" Jdec.int
        |> Jpipe.required "z" Jdec.int

encodeMsgVelECEFCov : MsgVelECEFCov -> Jenc.Value
encodeMsgVelECEFCov x =
    Jenc.object
        [ ("cov_x_x", Jenc.float x.covXX)
        , ("cov_x_y", Jenc.float x.covXY)
        , ("cov_x_z", Jenc.float x.covXZ)
        , ("cov_y_y", Jenc.float x.covYY)
        , ("cov_y_z", Jenc.float x.covYZ)
        , ("cov_z_z", Jenc.float x.covZZ)
        , ("flags", Jenc.int x.flags)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        , ("x", Jenc.int x.x)
        , ("y", Jenc.int x.y)
        , ("z", Jenc.int x.z)
        ]

msgVelECEF : Jdec.Decoder MsgVelECEF
msgVelECEF =
    Jpipe.decode MsgVelECEF
        |> Jpipe.required "accuracy" Jdec.int
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "x" Jdec.int
        |> Jpipe.required "y" Jdec.int
        |> Jpipe.required "z" Jdec.int

encodeMsgVelECEF : MsgVelECEF -> Jenc.Value
encodeMsgVelECEF x =
    Jenc.object
        [ ("accuracy", Jenc.int x.accuracy)
        , ("flags", Jenc.int x.flags)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        , ("x", Jenc.int x.x)
        , ("y", Jenc.int x.y)
        , ("z", Jenc.int x.z)
        ]

msgVelNEDCov : Jdec.Decoder MsgVelNEDCov
msgVelNEDCov =
    Jpipe.decode MsgVelNEDCov
        |> Jpipe.required "cov_d_d" Jdec.float
        |> Jpipe.required "cov_e_d" Jdec.float
        |> Jpipe.required "cov_e_e" Jdec.float
        |> Jpipe.required "cov_n_d" Jdec.float
        |> Jpipe.required "cov_n_e" Jdec.float
        |> Jpipe.required "cov_n_n" Jdec.float
        |> Jpipe.required "d" Jdec.int
        |> Jpipe.required "e" Jdec.int
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "n" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int

encodeMsgVelNEDCov : MsgVelNEDCov -> Jenc.Value
encodeMsgVelNEDCov x =
    Jenc.object
        [ ("cov_d_d", Jenc.float x.covDD)
        , ("cov_e_d", Jenc.float x.covED)
        , ("cov_e_e", Jenc.float x.covEE)
        , ("cov_n_d", Jenc.float x.covND)
        , ("cov_n_e", Jenc.float x.covNE)
        , ("cov_n_n", Jenc.float x.covNN)
        , ("d", Jenc.int x.d)
        , ("e", Jenc.int x.e)
        , ("flags", Jenc.int x.flags)
        , ("n", Jenc.int x.n)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        ]

msgVelNED : Jdec.Decoder MsgVelNED
msgVelNED =
    Jpipe.decode MsgVelNED
        |> Jpipe.required "d" Jdec.int
        |> Jpipe.required "e" Jdec.int
        |> Jpipe.required "flags" Jdec.int
        |> Jpipe.required "h_accuracy" Jdec.int
        |> Jpipe.required "n" Jdec.int
        |> Jpipe.required "n_sats" Jdec.int
        |> Jpipe.required "tow" Jdec.int
        |> Jpipe.required "v_accuracy" Jdec.int

encodeMsgVelNED : MsgVelNED -> Jenc.Value
encodeMsgVelNED x =
    Jenc.object
        [ ("d", Jenc.int x.d)
        , ("e", Jenc.int x.e)
        , ("flags", Jenc.int x.flags)
        , ("h_accuracy", Jenc.int x.hAccuracy)
        , ("n", Jenc.int x.n)
        , ("n_sats", Jenc.int x.nSats)
        , ("tow", Jenc.int x.tow)
        , ("v_accuracy", Jenc.int x.vAccuracy)
        ]

--- encoder helpers

makeArrayEncoder : (a -> Jenc.Value) -> Array a -> Jenc.Value
makeArrayEncoder f arr =
    Jenc.array (Array.map f arr)

makeDictEncoder : (a -> Jenc.Value) -> Dict String a -> Jenc.Value
makeDictEncoder f dict =
    Jenc.object (toList (Dict.map (\k -> f) dict))

makeNullableEncoder : (a -> Jenc.Value) -> Maybe a -> Jenc.Value
makeNullableEncoder f m =
    case m of
    Just x -> f x
    Nothing -> Jenc.null
