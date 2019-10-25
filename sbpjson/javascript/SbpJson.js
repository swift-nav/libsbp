// To parse this data:
//
//   const Convert = require("./file");
//
//   const acqSvProfile = Convert.toAcqSvProfile(json);
//   const almanacCommonContent = Convert.toAlmanacCommonContent(json);
//   const carrierPhase = Convert.toCarrierPhase(json);
//   const codeBiasesContent = Convert.toCodeBiasesContent(json);
//   const doppler = Convert.toDoppler(json);
//   const ephemerisCommonContent = Convert.toEphemerisCommonContent(json);
//   const gnssCapb = Convert.toGnssCapb(json);
//   const gnssSignal = Convert.toGnssSignal(json);
//   const gpsTime = Convert.toGpsTime(json);
//   const gpsTimeSEC = Convert.toGpsTimeSEC(json);
//   const griddedCorrectionHeader = Convert.toGriddedCorrectionHeader(json);
//   const gridDefinitionHeader = Convert.toGridDefinitionHeader(json);
//   const gridElement = Convert.toGridElement(json);
//   const latency = Convert.toLatency(json);
//   const measurementState = Convert.toMeasurementState(json);
//   const msgAcqResult = Convert.toMsgAcqResult(json);
//   const msgAcqSvProfile = Convert.toMsgAcqSvProfile(json);
//   const msgAgeCorrections = Convert.toMsgAgeCorrections(json);
//   const msgAlmanacGlo = Convert.toMsgAlmanacGlo(json);
//   const msgAlmanacGPS = Convert.toMsgAlmanacGPS(json);
//   const msgAlmanac = Convert.toMsgAlmanac(json);
//   const msgAngularRate = Convert.toMsgAngularRate(json);
//   const msgBaselineECEF = Convert.toMsgBaselineECEF(json);
//   const msgBaselineHeading = Convert.toMsgBaselineHeading(json);
//   const msgBaselineNED = Convert.toMsgBaselineNED(json);
//   const msgBasePosECEF = Convert.toMsgBasePosECEF(json);
//   const msgBasePosLLH = Convert.toMsgBasePosLLH(json);
//   const msgBootloaderHandshakeReq = Convert.toMsgBootloaderHandshakeReq(json);
//   const msgBootloaderHandshakeResp = Convert.toMsgBootloaderHandshakeResp(json);
//   const msgBootloaderJumpToApp = Convert.toMsgBootloaderJumpToApp(json);
//   const msgCellModemStatus = Convert.toMsgCellModemStatus(json);
//   const msgCommandOutput = Convert.toMsgCommandOutput(json);
//   const msgCommandReq = Convert.toMsgCommandReq(json);
//   const msgCommandResp = Convert.toMsgCommandResp(json);
//   const msgCsacTelemetry = Convert.toMsgCsacTelemetry(json);
//   const msgCsacTelemetryLabels = Convert.toMsgCsacTelemetryLabels(json);
//   const msgCwResults = Convert.toMsgCwResults(json);
//   const msgCwStart = Convert.toMsgCwStart(json);
//   const msgDeviceMonitor = Convert.toMsgDeviceMonitor(json);
//   const msgDgnssStatus = Convert.toMsgDgnssStatus(json);
//   const msgDops = Convert.toMsgDops(json);
//   const msgEphemerisBds = Convert.toMsgEphemerisBds(json);
//   const msgEphemerisGal = Convert.toMsgEphemerisGal(json);
//   const msgEphemerisGlo = Convert.toMsgEphemerisGlo(json);
//   const msgEphemerisGPS = Convert.toMsgEphemerisGPS(json);
//   const msgEphemerisQzss = Convert.toMsgEphemerisQzss(json);
//   const msgEphemerisSbas = Convert.toMsgEphemerisSbas(json);
//   const msgEXTEvent = Convert.toMsgEXTEvent(json);
//   const msgFileioConfigReq = Convert.toMsgFileioConfigReq(json);
//   const msgFileioConfigResp = Convert.toMsgFileioConfigResp(json);
//   const msgFileioReadDirReq = Convert.toMsgFileioReadDirReq(json);
//   const msgFileioReadDirResp = Convert.toMsgFileioReadDirResp(json);
//   const msgFileioReadReq = Convert.toMsgFileioReadReq(json);
//   const msgFileioReadResp = Convert.toMsgFileioReadResp(json);
//   const msgFileioRemove = Convert.toMsgFileioRemove(json);
//   const msgFileioWriteReq = Convert.toMsgFileioWriteReq(json);
//   const msgFileioWriteResp = Convert.toMsgFileioWriteResp(json);
//   const msgFlashDone = Convert.toMsgFlashDone(json);
//   const msgFlashErase = Convert.toMsgFlashErase(json);
//   const msgFlashProgram = Convert.toMsgFlashProgram(json);
//   const msgFlashReadReq = Convert.toMsgFlashReadReq(json);
//   const msgFlashReadResp = Convert.toMsgFlashReadResp(json);
//   const msgFrontEndGain = Convert.toMsgFrontEndGain(json);
//   const msgFwd = Convert.toMsgFwd(json);
//   const msgGloBiases = Convert.toMsgGloBiases(json);
//   const msgGnssCapb = Convert.toMsgGnssCapb(json);
//   const msgGPSTime = Convert.toMsgGPSTime(json);
//   const msgGroupDelay = Convert.toMsgGroupDelay(json);
//   const msgHeartbeat = Convert.toMsgHeartbeat(json);
//   const msgIarState = Convert.toMsgIarState(json);
//   const msgImuAux = Convert.toMsgImuAux(json);
//   const msgImuRaw = Convert.toMsgImuRaw(json);
//   const msgInsStatus = Convert.toMsgInsStatus(json);
//   const msgIono = Convert.toMsgIono(json);
//   const msgLinuxCPUState = Convert.toMsgLinuxCPUState(json);
//   const msgLinuxMemState = Convert.toMsgLinuxMemState(json);
//   const msgLinuxProcessFdCount = Convert.toMsgLinuxProcessFdCount(json);
//   const msgLinuxProcessFdSummary = Convert.toMsgLinuxProcessFdSummary(json);
//   const msgLinuxProcessSocketCounts = Convert.toMsgLinuxProcessSocketCounts(json);
//   const msgLinuxProcessSocketQueues = Convert.toMsgLinuxProcessSocketQueues(json);
//   const msgLinuxSocketUsage = Convert.toMsgLinuxSocketUsage(json);
//   const msgLinuxSysState = Convert.toMsgLinuxSysState(json);
//   const msgLog = Convert.toMsgLog(json);
//   const msgM25FlashWriteStatus = Convert.toMsgM25FlashWriteStatus(json);
//   const msgMagRaw = Convert.toMsgMagRaw(json);
//   const msgMaskSatellite = Convert.toMsgMaskSatellite(json);
//   const msgMeasurementState = Convert.toMsgMeasurementState(json);
//   const msgNapDeviceDnaReq = Convert.toMsgNapDeviceDnaReq(json);
//   const msgNapDeviceDnaResp = Convert.toMsgNapDeviceDnaResp(json);
//   const msgNdbEvent = Convert.toMsgNdbEvent(json);
//   const msgNetworkBandwidthUsage = Convert.toMsgNetworkBandwidthUsage(json);
//   const msgNetworkStateReq = Convert.toMsgNetworkStateReq(json);
//   const msgNetworkStateResp = Convert.toMsgNetworkStateResp(json);
//   const msgObs = Convert.toMsgObs(json);
//   const msgOdometry = Convert.toMsgOdometry(json);
//   const msgOrientEuler = Convert.toMsgOrientEuler(json);
//   const msgOrientQuat = Convert.toMsgOrientQuat(json);
//   const msgOsr = Convert.toMsgOsr(json);
//   const msgPosECEFCov = Convert.toMsgPosECEFCov(json);
//   const msgPosECEF = Convert.toMsgPosECEF(json);
//   const msgPosLLHCov = Convert.toMsgPosLLHCov(json);
//   const msgPosLLH = Convert.toMsgPosLLH(json);
//   const msgResetFilters = Convert.toMsgResetFilters(json);
//   const msgReset = Convert.toMsgReset(json);
//   const msgSbasRaw = Convert.toMsgSbasRaw(json);
//   const msgSetTime = Convert.toMsgSetTime(json);
//   const msgSettingsReadByIndexDone = Convert.toMsgSettingsReadByIndexDone(json);
//   const msgSettingsReadByIndexReq = Convert.toMsgSettingsReadByIndexReq(json);
//   const msgSettingsReadByIndexResp = Convert.toMsgSettingsReadByIndexResp(json);
//   const msgSettingsReadReq = Convert.toMsgSettingsReadReq(json);
//   const msgSettingsReadResp = Convert.toMsgSettingsReadResp(json);
//   const msgSettingsRegister = Convert.toMsgSettingsRegister(json);
//   const msgSettingsRegisterResp = Convert.toMsgSettingsRegisterResp(json);
//   const msgSettingsSave = Convert.toMsgSettingsSave(json);
//   const msgSettingsWrite = Convert.toMsgSettingsWrite(json);
//   const msgSettingsWriteResp = Convert.toMsgSettingsWriteResp(json);
//   const msgSpecan = Convert.toMsgSpecan(json);
//   const msgSsrCodeBiases = Convert.toMsgSsrCodeBiases(json);
//   const msgSsrGriddedCorrection = Convert.toMsgSsrGriddedCorrection(json);
//   const msgSsrGridDefinition = Convert.toMsgSsrGridDefinition(json);
//   const msgSsrOrbitClock = Convert.toMsgSsrOrbitClock(json);
//   const msgSsrPhaseBiases = Convert.toMsgSsrPhaseBiases(json);
//   const msgSsrStecCorrection = Convert.toMsgSsrStecCorrection(json);
//   const msgStartup = Convert.toMsgStartup(json);
//   const msgStmFlashLockSector = Convert.toMsgStmFlashLockSector(json);
//   const msgStmFlashUnlockSector = Convert.toMsgStmFlashUnlockSector(json);
//   const msgStmUniqueIDReq = Convert.toMsgStmUniqueIDReq(json);
//   const msgStmUniqueIDResp = Convert.toMsgStmUniqueIDResp(json);
//   const msgSvAzEl = Convert.toMsgSvAzEl(json);
//   const msgThreadState = Convert.toMsgThreadState(json);
//   const msgTrackingIq = Convert.toMsgTrackingIq(json);
//   const msgTrackingState = Convert.toMsgTrackingState(json);
//   const msgUARTState = Convert.toMsgUARTState(json);
//   const msgUserData = Convert.toMsgUserData(json);
//   const msgUTCTime = Convert.toMsgUTCTime(json);
//   const msgVelBody = Convert.toMsgVelBody(json);
//   const msgVelECEFCov = Convert.toMsgVelECEFCov(json);
//   const msgVelECEF = Convert.toMsgVelECEF(json);
//   const msgVelNEDCov = Convert.toMsgVelNEDCov(json);
//   const msgVelNED = Convert.toMsgVelNED(json);
//   const networkUsage = Convert.toNetworkUsage(json);
//   const observationHeader = Convert.toObservationHeader(json);
//   const packedObsContent = Convert.toPackedObsContent(json);
//   const packedOsrContent = Convert.toPackedOsrContent(json);
//   const period = Convert.toPeriod(json);
//   const phaseBiasesContent = Convert.toPhaseBiasesContent(json);
//   const sTECHeader = Convert.toSTECHeader(json);
//   const sTECResidual = Convert.toSTECResidual(json);
//   const sTECSatElement = Convert.toSTECSatElement(json);
//   const svAzEl = Convert.toSvAzEl(json);
//   const svID = Convert.toSvID(json);
//   const trackingChannelCorrelation = Convert.toTrackingChannelCorrelation(json);
//   const trackingChannelState = Convert.toTrackingChannelState(json);
//   const troposphericDelayCorrection = Convert.toTroposphericDelayCorrection(json);
//   const uARTChannel = Convert.toUARTChannel(json);
//
// These functions will throw an error if the JSON doesn't
// match the expected interface, even if the JSON is valid.

// Converts JSON strings to/from your types
// and asserts the results of JSON.parse at runtime
function toAcqSvProfile(json) {
    return cast(JSON.parse(json), r("AcqSvProfile"));
}

function acqSvProfileToJson(value) {
    return JSON.stringify(uncast(value, r("AcqSvProfile")), null, 2);
}

function toAlmanacCommonContent(json) {
    return cast(JSON.parse(json), r("AlmanacCommonContent"));
}

function almanacCommonContentToJson(value) {
    return JSON.stringify(uncast(value, r("AlmanacCommonContent")), null, 2);
}

function toCarrierPhase(json) {
    return cast(JSON.parse(json), r("CarrierPhase"));
}

function carrierPhaseToJson(value) {
    return JSON.stringify(uncast(value, r("CarrierPhase")), null, 2);
}

function toCodeBiasesContent(json) {
    return cast(JSON.parse(json), r("CodeBiasesContent"));
}

function codeBiasesContentToJson(value) {
    return JSON.stringify(uncast(value, r("CodeBiasesContent")), null, 2);
}

function toDoppler(json) {
    return cast(JSON.parse(json), r("Doppler"));
}

function dopplerToJson(value) {
    return JSON.stringify(uncast(value, r("Doppler")), null, 2);
}

function toEphemerisCommonContent(json) {
    return cast(JSON.parse(json), r("EphemerisCommonContent"));
}

function ephemerisCommonContentToJson(value) {
    return JSON.stringify(uncast(value, r("EphemerisCommonContent")), null, 2);
}

function toGnssCapb(json) {
    return cast(JSON.parse(json), r("GnssCapb"));
}

function gnssCapbToJson(value) {
    return JSON.stringify(uncast(value, r("GnssCapb")), null, 2);
}

function toGnssSignal(json) {
    return cast(JSON.parse(json), r("GnssSignal"));
}

function gnssSignalToJson(value) {
    return JSON.stringify(uncast(value, r("GnssSignal")), null, 2);
}

function toGpsTime(json) {
    return cast(JSON.parse(json), r("GpsTime"));
}

function gpsTimeToJson(value) {
    return JSON.stringify(uncast(value, r("GpsTime")), null, 2);
}

function toGpsTimeSEC(json) {
    return cast(JSON.parse(json), r("GpsTimeSEC"));
}

function gpsTimeSECToJson(value) {
    return JSON.stringify(uncast(value, r("GpsTimeSEC")), null, 2);
}

function toGriddedCorrectionHeader(json) {
    return cast(JSON.parse(json), r("GriddedCorrectionHeader"));
}

function griddedCorrectionHeaderToJson(value) {
    return JSON.stringify(uncast(value, r("GriddedCorrectionHeader")), null, 2);
}

function toGridDefinitionHeader(json) {
    return cast(JSON.parse(json), r("GridDefinitionHeader"));
}

function gridDefinitionHeaderToJson(value) {
    return JSON.stringify(uncast(value, r("GridDefinitionHeader")), null, 2);
}

function toGridElement(json) {
    return cast(JSON.parse(json), r("GridElement"));
}

function gridElementToJson(value) {
    return JSON.stringify(uncast(value, r("GridElement")), null, 2);
}

function toLatency(json) {
    return cast(JSON.parse(json), r("Latency"));
}

function latencyToJson(value) {
    return JSON.stringify(uncast(value, r("Latency")), null, 2);
}

function toMeasurementState(json) {
    return cast(JSON.parse(json), r("MeasurementState"));
}

function measurementStateToJson(value) {
    return JSON.stringify(uncast(value, r("MeasurementState")), null, 2);
}

function toMsgAcqResult(json) {
    return cast(JSON.parse(json), r("MsgAcqResult"));
}

function msgAcqResultToJson(value) {
    return JSON.stringify(uncast(value, r("MsgAcqResult")), null, 2);
}

function toMsgAcqSvProfile(json) {
    return cast(JSON.parse(json), r("MsgAcqSvProfile"));
}

function msgAcqSvProfileToJson(value) {
    return JSON.stringify(uncast(value, r("MsgAcqSvProfile")), null, 2);
}

function toMsgAgeCorrections(json) {
    return cast(JSON.parse(json), r("MsgAgeCorrections"));
}

function msgAgeCorrectionsToJson(value) {
    return JSON.stringify(uncast(value, r("MsgAgeCorrections")), null, 2);
}

function toMsgAlmanacGlo(json) {
    return cast(JSON.parse(json), r("MsgAlmanacGlo"));
}

function msgAlmanacGloToJson(value) {
    return JSON.stringify(uncast(value, r("MsgAlmanacGlo")), null, 2);
}

function toMsgAlmanacGPS(json) {
    return cast(JSON.parse(json), r("MsgAlmanacGPS"));
}

function msgAlmanacGPSToJson(value) {
    return JSON.stringify(uncast(value, r("MsgAlmanacGPS")), null, 2);
}

function toMsgAlmanac(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgAlmanacToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgAngularRate(json) {
    return cast(JSON.parse(json), r("MsgAngularRate"));
}

function msgAngularRateToJson(value) {
    return JSON.stringify(uncast(value, r("MsgAngularRate")), null, 2);
}

function toMsgBaselineECEF(json) {
    return cast(JSON.parse(json), r("MsgBaselineECEF"));
}

function msgBaselineECEFToJson(value) {
    return JSON.stringify(uncast(value, r("MsgBaselineECEF")), null, 2);
}

function toMsgBaselineHeading(json) {
    return cast(JSON.parse(json), r("MsgBaselineHeading"));
}

function msgBaselineHeadingToJson(value) {
    return JSON.stringify(uncast(value, r("MsgBaselineHeading")), null, 2);
}

function toMsgBaselineNED(json) {
    return cast(JSON.parse(json), r("MsgBaselineNED"));
}

function msgBaselineNEDToJson(value) {
    return JSON.stringify(uncast(value, r("MsgBaselineNED")), null, 2);
}

function toMsgBasePosECEF(json) {
    return cast(JSON.parse(json), r("MsgBasePosECEF"));
}

function msgBasePosECEFToJson(value) {
    return JSON.stringify(uncast(value, r("MsgBasePosECEF")), null, 2);
}

function toMsgBasePosLLH(json) {
    return cast(JSON.parse(json), r("MsgBasePosLLH"));
}

function msgBasePosLLHToJson(value) {
    return JSON.stringify(uncast(value, r("MsgBasePosLLH")), null, 2);
}

function toMsgBootloaderHandshakeReq(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgBootloaderHandshakeReqToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgBootloaderHandshakeResp(json) {
    return cast(JSON.parse(json), r("MsgBootloaderHandshakeResp"));
}

function msgBootloaderHandshakeRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgBootloaderHandshakeResp")), null, 2);
}

function toMsgBootloaderJumpToApp(json) {
    return cast(JSON.parse(json), r("MsgBootloaderJumpToApp"));
}

function msgBootloaderJumpToAppToJson(value) {
    return JSON.stringify(uncast(value, r("MsgBootloaderJumpToApp")), null, 2);
}

function toMsgCellModemStatus(json) {
    return cast(JSON.parse(json), r("MsgCellModemStatus"));
}

function msgCellModemStatusToJson(value) {
    return JSON.stringify(uncast(value, r("MsgCellModemStatus")), null, 2);
}

function toMsgCommandOutput(json) {
    return cast(JSON.parse(json), r("MsgCommandOutput"));
}

function msgCommandOutputToJson(value) {
    return JSON.stringify(uncast(value, r("MsgCommandOutput")), null, 2);
}

function toMsgCommandReq(json) {
    return cast(JSON.parse(json), r("MsgCommandReq"));
}

function msgCommandReqToJson(value) {
    return JSON.stringify(uncast(value, r("MsgCommandReq")), null, 2);
}

function toMsgCommandResp(json) {
    return cast(JSON.parse(json), r("MsgCommandResp"));
}

function msgCommandRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgCommandResp")), null, 2);
}

function toMsgCsacTelemetry(json) {
    return cast(JSON.parse(json), r("MsgCsacTelemetry"));
}

function msgCsacTelemetryToJson(value) {
    return JSON.stringify(uncast(value, r("MsgCsacTelemetry")), null, 2);
}

function toMsgCsacTelemetryLabels(json) {
    return cast(JSON.parse(json), r("MsgCsacTelemetryLabels"));
}

function msgCsacTelemetryLabelsToJson(value) {
    return JSON.stringify(uncast(value, r("MsgCsacTelemetryLabels")), null, 2);
}

function toMsgCwResults(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgCwResultsToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgCwStart(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgCwStartToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgDeviceMonitor(json) {
    return cast(JSON.parse(json), r("MsgDeviceMonitor"));
}

function msgDeviceMonitorToJson(value) {
    return JSON.stringify(uncast(value, r("MsgDeviceMonitor")), null, 2);
}

function toMsgDgnssStatus(json) {
    return cast(JSON.parse(json), r("MsgDgnssStatus"));
}

function msgDgnssStatusToJson(value) {
    return JSON.stringify(uncast(value, r("MsgDgnssStatus")), null, 2);
}

function toMsgDops(json) {
    return cast(JSON.parse(json), r("MsgDops"));
}

function msgDopsToJson(value) {
    return JSON.stringify(uncast(value, r("MsgDops")), null, 2);
}

function toMsgEphemerisBds(json) {
    return cast(JSON.parse(json), r("MsgEphemerisBds"));
}

function msgEphemerisBdsToJson(value) {
    return JSON.stringify(uncast(value, r("MsgEphemerisBds")), null, 2);
}

function toMsgEphemerisGal(json) {
    return cast(JSON.parse(json), r("MsgEphemerisGal"));
}

function msgEphemerisGalToJson(value) {
    return JSON.stringify(uncast(value, r("MsgEphemerisGal")), null, 2);
}

function toMsgEphemerisGlo(json) {
    return cast(JSON.parse(json), r("MsgEphemerisGlo"));
}

function msgEphemerisGloToJson(value) {
    return JSON.stringify(uncast(value, r("MsgEphemerisGlo")), null, 2);
}

function toMsgEphemerisGPS(json) {
    return cast(JSON.parse(json), r("MsgEphemerisGPS"));
}

function msgEphemerisGPSToJson(value) {
    return JSON.stringify(uncast(value, r("MsgEphemerisGPS")), null, 2);
}

function toMsgEphemerisQzss(json) {
    return cast(JSON.parse(json), r("MsgEphemerisQzss"));
}

function msgEphemerisQzssToJson(value) {
    return JSON.stringify(uncast(value, r("MsgEphemerisQzss")), null, 2);
}

function toMsgEphemerisSbas(json) {
    return cast(JSON.parse(json), r("MsgEphemerisSbas"));
}

function msgEphemerisSbasToJson(value) {
    return JSON.stringify(uncast(value, r("MsgEphemerisSbas")), null, 2);
}

function toMsgEXTEvent(json) {
    return cast(JSON.parse(json), r("MsgEXTEvent"));
}

function msgEXTEventToJson(value) {
    return JSON.stringify(uncast(value, r("MsgEXTEvent")), null, 2);
}

function toMsgFileioConfigReq(json) {
    return cast(JSON.parse(json), r("MsgFileioConfigReq"));
}

function msgFileioConfigReqToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFileioConfigReq")), null, 2);
}

function toMsgFileioConfigResp(json) {
    return cast(JSON.parse(json), r("MsgFileioConfigResp"));
}

function msgFileioConfigRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFileioConfigResp")), null, 2);
}

function toMsgFileioReadDirReq(json) {
    return cast(JSON.parse(json), r("MsgFileioReadDirReq"));
}

function msgFileioReadDirReqToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFileioReadDirReq")), null, 2);
}

function toMsgFileioReadDirResp(json) {
    return cast(JSON.parse(json), r("MsgFileioReadDirResp"));
}

function msgFileioReadDirRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFileioReadDirResp")), null, 2);
}

function toMsgFileioReadReq(json) {
    return cast(JSON.parse(json), r("MsgFileioReadReq"));
}

function msgFileioReadReqToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFileioReadReq")), null, 2);
}

function toMsgFileioReadResp(json) {
    return cast(JSON.parse(json), r("MsgFileioReadResp"));
}

function msgFileioReadRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFileioReadResp")), null, 2);
}

function toMsgFileioRemove(json) {
    return cast(JSON.parse(json), r("MsgFileioRemove"));
}

function msgFileioRemoveToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFileioRemove")), null, 2);
}

function toMsgFileioWriteReq(json) {
    return cast(JSON.parse(json), r("MsgFileioWriteReq"));
}

function msgFileioWriteReqToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFileioWriteReq")), null, 2);
}

function toMsgFileioWriteResp(json) {
    return cast(JSON.parse(json), r("MsgFileioWriteResp"));
}

function msgFileioWriteRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFileioWriteResp")), null, 2);
}

function toMsgFlashDone(json) {
    return cast(JSON.parse(json), r("MsgFlashDone"));
}

function msgFlashDoneToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFlashDone")), null, 2);
}

function toMsgFlashErase(json) {
    return cast(JSON.parse(json), r("MsgFlashErase"));
}

function msgFlashEraseToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFlashErase")), null, 2);
}

function toMsgFlashProgram(json) {
    return cast(JSON.parse(json), r("MsgFlashProgram"));
}

function msgFlashProgramToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFlashProgram")), null, 2);
}

function toMsgFlashReadReq(json) {
    return cast(JSON.parse(json), r("MsgFlashReadReq"));
}

function msgFlashReadReqToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFlashReadReq")), null, 2);
}

function toMsgFlashReadResp(json) {
    return cast(JSON.parse(json), r("MsgFlashReadResp"));
}

function msgFlashReadRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFlashReadResp")), null, 2);
}

function toMsgFrontEndGain(json) {
    return cast(JSON.parse(json), r("MsgFrontEndGain"));
}

function msgFrontEndGainToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFrontEndGain")), null, 2);
}

function toMsgFwd(json) {
    return cast(JSON.parse(json), r("MsgFwd"));
}

function msgFwdToJson(value) {
    return JSON.stringify(uncast(value, r("MsgFwd")), null, 2);
}

function toMsgGloBiases(json) {
    return cast(JSON.parse(json), r("MsgGloBiases"));
}

function msgGloBiasesToJson(value) {
    return JSON.stringify(uncast(value, r("MsgGloBiases")), null, 2);
}

function toMsgGnssCapb(json) {
    return cast(JSON.parse(json), r("MsgGnssCapb"));
}

function msgGnssCapbToJson(value) {
    return JSON.stringify(uncast(value, r("MsgGnssCapb")), null, 2);
}

function toMsgGPSTime(json) {
    return cast(JSON.parse(json), r("MsgGPSTime"));
}

function msgGPSTimeToJson(value) {
    return JSON.stringify(uncast(value, r("MsgGPSTime")), null, 2);
}

function toMsgGroupDelay(json) {
    return cast(JSON.parse(json), r("MsgGroupDelay"));
}

function msgGroupDelayToJson(value) {
    return JSON.stringify(uncast(value, r("MsgGroupDelay")), null, 2);
}

function toMsgHeartbeat(json) {
    return cast(JSON.parse(json), r("MsgHeartbeat"));
}

function msgHeartbeatToJson(value) {
    return JSON.stringify(uncast(value, r("MsgHeartbeat")), null, 2);
}

function toMsgIarState(json) {
    return cast(JSON.parse(json), r("MsgIarState"));
}

function msgIarStateToJson(value) {
    return JSON.stringify(uncast(value, r("MsgIarState")), null, 2);
}

function toMsgImuAux(json) {
    return cast(JSON.parse(json), r("MsgImuAux"));
}

function msgImuAuxToJson(value) {
    return JSON.stringify(uncast(value, r("MsgImuAux")), null, 2);
}

function toMsgImuRaw(json) {
    return cast(JSON.parse(json), r("MsgImuRaw"));
}

function msgImuRawToJson(value) {
    return JSON.stringify(uncast(value, r("MsgImuRaw")), null, 2);
}

function toMsgInsStatus(json) {
    return cast(JSON.parse(json), r("MsgInsStatus"));
}

function msgInsStatusToJson(value) {
    return JSON.stringify(uncast(value, r("MsgInsStatus")), null, 2);
}

function toMsgIono(json) {
    return cast(JSON.parse(json), r("MsgIono"));
}

function msgIonoToJson(value) {
    return JSON.stringify(uncast(value, r("MsgIono")), null, 2);
}

function toMsgLinuxCPUState(json) {
    return cast(JSON.parse(json), r("MsgLinuxCPUState"));
}

function msgLinuxCPUStateToJson(value) {
    return JSON.stringify(uncast(value, r("MsgLinuxCPUState")), null, 2);
}

function toMsgLinuxMemState(json) {
    return cast(JSON.parse(json), r("MsgLinuxMemState"));
}

function msgLinuxMemStateToJson(value) {
    return JSON.stringify(uncast(value, r("MsgLinuxMemState")), null, 2);
}

function toMsgLinuxProcessFdCount(json) {
    return cast(JSON.parse(json), r("MsgLinuxProcessFdCount"));
}

function msgLinuxProcessFdCountToJson(value) {
    return JSON.stringify(uncast(value, r("MsgLinuxProcessFdCount")), null, 2);
}

function toMsgLinuxProcessFdSummary(json) {
    return cast(JSON.parse(json), r("MsgLinuxProcessFdSummary"));
}

function msgLinuxProcessFdSummaryToJson(value) {
    return JSON.stringify(uncast(value, r("MsgLinuxProcessFdSummary")), null, 2);
}

function toMsgLinuxProcessSocketCounts(json) {
    return cast(JSON.parse(json), r("MsgLinuxProcessSocketCounts"));
}

function msgLinuxProcessSocketCountsToJson(value) {
    return JSON.stringify(uncast(value, r("MsgLinuxProcessSocketCounts")), null, 2);
}

function toMsgLinuxProcessSocketQueues(json) {
    return cast(JSON.parse(json), r("MsgLinuxProcessSocketQueues"));
}

function msgLinuxProcessSocketQueuesToJson(value) {
    return JSON.stringify(uncast(value, r("MsgLinuxProcessSocketQueues")), null, 2);
}

function toMsgLinuxSocketUsage(json) {
    return cast(JSON.parse(json), r("MsgLinuxSocketUsage"));
}

function msgLinuxSocketUsageToJson(value) {
    return JSON.stringify(uncast(value, r("MsgLinuxSocketUsage")), null, 2);
}

function toMsgLinuxSysState(json) {
    return cast(JSON.parse(json), r("MsgLinuxSysState"));
}

function msgLinuxSysStateToJson(value) {
    return JSON.stringify(uncast(value, r("MsgLinuxSysState")), null, 2);
}

function toMsgLog(json) {
    return cast(JSON.parse(json), r("MsgLog"));
}

function msgLogToJson(value) {
    return JSON.stringify(uncast(value, r("MsgLog")), null, 2);
}

function toMsgM25FlashWriteStatus(json) {
    return cast(JSON.parse(json), r("MsgM25FlashWriteStatus"));
}

function msgM25FlashWriteStatusToJson(value) {
    return JSON.stringify(uncast(value, r("MsgM25FlashWriteStatus")), null, 2);
}

function toMsgMagRaw(json) {
    return cast(JSON.parse(json), r("MsgMagRaw"));
}

function msgMagRawToJson(value) {
    return JSON.stringify(uncast(value, r("MsgMagRaw")), null, 2);
}

function toMsgMaskSatellite(json) {
    return cast(JSON.parse(json), r("MsgMaskSatellite"));
}

function msgMaskSatelliteToJson(value) {
    return JSON.stringify(uncast(value, r("MsgMaskSatellite")), null, 2);
}

function toMsgMeasurementState(json) {
    return cast(JSON.parse(json), r("MsgMeasurementState"));
}

function msgMeasurementStateToJson(value) {
    return JSON.stringify(uncast(value, r("MsgMeasurementState")), null, 2);
}

function toMsgNapDeviceDnaReq(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgNapDeviceDnaReqToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgNapDeviceDnaResp(json) {
    return cast(JSON.parse(json), r("MsgNapDeviceDnaResp"));
}

function msgNapDeviceDnaRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgNapDeviceDnaResp")), null, 2);
}

function toMsgNdbEvent(json) {
    return cast(JSON.parse(json), r("MsgNdbEvent"));
}

function msgNdbEventToJson(value) {
    return JSON.stringify(uncast(value, r("MsgNdbEvent")), null, 2);
}

function toMsgNetworkBandwidthUsage(json) {
    return cast(JSON.parse(json), r("MsgNetworkBandwidthUsage"));
}

function msgNetworkBandwidthUsageToJson(value) {
    return JSON.stringify(uncast(value, r("MsgNetworkBandwidthUsage")), null, 2);
}

function toMsgNetworkStateReq(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgNetworkStateReqToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgNetworkStateResp(json) {
    return cast(JSON.parse(json), r("MsgNetworkStateResp"));
}

function msgNetworkStateRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgNetworkStateResp")), null, 2);
}

function toMsgObs(json) {
    return cast(JSON.parse(json), r("MsgObs"));
}

function msgObsToJson(value) {
    return JSON.stringify(uncast(value, r("MsgObs")), null, 2);
}

function toMsgOdometry(json) {
    return cast(JSON.parse(json), r("MsgOdometry"));
}

function msgOdometryToJson(value) {
    return JSON.stringify(uncast(value, r("MsgOdometry")), null, 2);
}

function toMsgOrientEuler(json) {
    return cast(JSON.parse(json), r("MsgOrientEuler"));
}

function msgOrientEulerToJson(value) {
    return JSON.stringify(uncast(value, r("MsgOrientEuler")), null, 2);
}

function toMsgOrientQuat(json) {
    return cast(JSON.parse(json), r("MsgOrientQuat"));
}

function msgOrientQuatToJson(value) {
    return JSON.stringify(uncast(value, r("MsgOrientQuat")), null, 2);
}

function toMsgOsr(json) {
    return cast(JSON.parse(json), r("MsgOsr"));
}

function msgOsrToJson(value) {
    return JSON.stringify(uncast(value, r("MsgOsr")), null, 2);
}

function toMsgPosECEFCov(json) {
    return cast(JSON.parse(json), r("MsgPosECEFCov"));
}

function msgPosECEFCovToJson(value) {
    return JSON.stringify(uncast(value, r("MsgPosECEFCov")), null, 2);
}

function toMsgPosECEF(json) {
    return cast(JSON.parse(json), r("MsgPosECEF"));
}

function msgPosECEFToJson(value) {
    return JSON.stringify(uncast(value, r("MsgPosECEF")), null, 2);
}

function toMsgPosLLHCov(json) {
    return cast(JSON.parse(json), r("MsgPosLLHCov"));
}

function msgPosLLHCovToJson(value) {
    return JSON.stringify(uncast(value, r("MsgPosLLHCov")), null, 2);
}

function toMsgPosLLH(json) {
    return cast(JSON.parse(json), r("MsgPosLLH"));
}

function msgPosLLHToJson(value) {
    return JSON.stringify(uncast(value, r("MsgPosLLH")), null, 2);
}

function toMsgResetFilters(json) {
    return cast(JSON.parse(json), r("MsgResetFilters"));
}

function msgResetFiltersToJson(value) {
    return JSON.stringify(uncast(value, r("MsgResetFilters")), null, 2);
}

function toMsgReset(json) {
    return cast(JSON.parse(json), r("MsgReset"));
}

function msgResetToJson(value) {
    return JSON.stringify(uncast(value, r("MsgReset")), null, 2);
}

function toMsgSbasRaw(json) {
    return cast(JSON.parse(json), r("MsgSbasRaw"));
}

function msgSbasRawToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSbasRaw")), null, 2);
}

function toMsgSetTime(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgSetTimeToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgSettingsReadByIndexDone(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgSettingsReadByIndexDoneToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgSettingsReadByIndexReq(json) {
    return cast(JSON.parse(json), r("MsgSettingsReadByIndexReq"));
}

function msgSettingsReadByIndexReqToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSettingsReadByIndexReq")), null, 2);
}

function toMsgSettingsReadByIndexResp(json) {
    return cast(JSON.parse(json), r("MsgSettingsReadByIndexResp"));
}

function msgSettingsReadByIndexRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSettingsReadByIndexResp")), null, 2);
}

function toMsgSettingsReadReq(json) {
    return cast(JSON.parse(json), r("MsgSettingsReadReq"));
}

function msgSettingsReadReqToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSettingsReadReq")), null, 2);
}

function toMsgSettingsReadResp(json) {
    return cast(JSON.parse(json), r("MsgSettingsReadResp"));
}

function msgSettingsReadRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSettingsReadResp")), null, 2);
}

function toMsgSettingsRegister(json) {
    return cast(JSON.parse(json), r("MsgSettingsRegister"));
}

function msgSettingsRegisterToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSettingsRegister")), null, 2);
}

function toMsgSettingsRegisterResp(json) {
    return cast(JSON.parse(json), r("MsgSettingsRegisterResp"));
}

function msgSettingsRegisterRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSettingsRegisterResp")), null, 2);
}

function toMsgSettingsSave(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgSettingsSaveToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgSettingsWrite(json) {
    return cast(JSON.parse(json), r("MsgSettingsWrite"));
}

function msgSettingsWriteToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSettingsWrite")), null, 2);
}

function toMsgSettingsWriteResp(json) {
    return cast(JSON.parse(json), r("MsgSettingsWriteResp"));
}

function msgSettingsWriteRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSettingsWriteResp")), null, 2);
}

function toMsgSpecan(json) {
    return cast(JSON.parse(json), r("MsgSpecan"));
}

function msgSpecanToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSpecan")), null, 2);
}

function toMsgSsrCodeBiases(json) {
    return cast(JSON.parse(json), r("MsgSsrCodeBiases"));
}

function msgSsrCodeBiasesToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSsrCodeBiases")), null, 2);
}

function toMsgSsrGriddedCorrection(json) {
    return cast(JSON.parse(json), r("MsgSsrGriddedCorrection"));
}

function msgSsrGriddedCorrectionToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSsrGriddedCorrection")), null, 2);
}

function toMsgSsrGridDefinition(json) {
    return cast(JSON.parse(json), r("MsgSsrGridDefinition"));
}

function msgSsrGridDefinitionToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSsrGridDefinition")), null, 2);
}

function toMsgSsrOrbitClock(json) {
    return cast(JSON.parse(json), r("MsgSsrOrbitClock"));
}

function msgSsrOrbitClockToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSsrOrbitClock")), null, 2);
}

function toMsgSsrPhaseBiases(json) {
    return cast(JSON.parse(json), r("MsgSsrPhaseBiases"));
}

function msgSsrPhaseBiasesToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSsrPhaseBiases")), null, 2);
}

function toMsgSsrStecCorrection(json) {
    return cast(JSON.parse(json), r("MsgSsrStecCorrection"));
}

function msgSsrStecCorrectionToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSsrStecCorrection")), null, 2);
}

function toMsgStartup(json) {
    return cast(JSON.parse(json), r("MsgStartup"));
}

function msgStartupToJson(value) {
    return JSON.stringify(uncast(value, r("MsgStartup")), null, 2);
}

function toMsgStmFlashLockSector(json) {
    return cast(JSON.parse(json), r("MsgStmFlashLockSector"));
}

function msgStmFlashLockSectorToJson(value) {
    return JSON.stringify(uncast(value, r("MsgStmFlashLockSector")), null, 2);
}

function toMsgStmFlashUnlockSector(json) {
    return cast(JSON.parse(json), r("MsgStmFlashUnlockSector"));
}

function msgStmFlashUnlockSectorToJson(value) {
    return JSON.stringify(uncast(value, r("MsgStmFlashUnlockSector")), null, 2);
}

function toMsgStmUniqueIDReq(json) {
    return cast(JSON.parse(json), m("any"));
}

function msgStmUniqueIDReqToJson(value) {
    return JSON.stringify(uncast(value, m("any")), null, 2);
}

function toMsgStmUniqueIDResp(json) {
    return cast(JSON.parse(json), r("MsgStmUniqueIDResp"));
}

function msgStmUniqueIDRespToJson(value) {
    return JSON.stringify(uncast(value, r("MsgStmUniqueIDResp")), null, 2);
}

function toMsgSvAzEl(json) {
    return cast(JSON.parse(json), r("MsgSvAzEl"));
}

function msgSvAzElToJson(value) {
    return JSON.stringify(uncast(value, r("MsgSvAzEl")), null, 2);
}

function toMsgThreadState(json) {
    return cast(JSON.parse(json), r("MsgThreadState"));
}

function msgThreadStateToJson(value) {
    return JSON.stringify(uncast(value, r("MsgThreadState")), null, 2);
}

function toMsgTrackingIq(json) {
    return cast(JSON.parse(json), r("MsgTrackingIq"));
}

function msgTrackingIqToJson(value) {
    return JSON.stringify(uncast(value, r("MsgTrackingIq")), null, 2);
}

function toMsgTrackingState(json) {
    return cast(JSON.parse(json), r("MsgTrackingState"));
}

function msgTrackingStateToJson(value) {
    return JSON.stringify(uncast(value, r("MsgTrackingState")), null, 2);
}

function toMsgUARTState(json) {
    return cast(JSON.parse(json), r("MsgUARTState"));
}

function msgUARTStateToJson(value) {
    return JSON.stringify(uncast(value, r("MsgUARTState")), null, 2);
}

function toMsgUserData(json) {
    return cast(JSON.parse(json), r("MsgUserData"));
}

function msgUserDataToJson(value) {
    return JSON.stringify(uncast(value, r("MsgUserData")), null, 2);
}

function toMsgUTCTime(json) {
    return cast(JSON.parse(json), r("MsgUTCTime"));
}

function msgUTCTimeToJson(value) {
    return JSON.stringify(uncast(value, r("MsgUTCTime")), null, 2);
}

function toMsgVelBody(json) {
    return cast(JSON.parse(json), r("MsgVelBody"));
}

function msgVelBodyToJson(value) {
    return JSON.stringify(uncast(value, r("MsgVelBody")), null, 2);
}

function toMsgVelECEFCov(json) {
    return cast(JSON.parse(json), r("MsgVelECEFCov"));
}

function msgVelECEFCovToJson(value) {
    return JSON.stringify(uncast(value, r("MsgVelECEFCov")), null, 2);
}

function toMsgVelECEF(json) {
    return cast(JSON.parse(json), r("MsgVelECEF"));
}

function msgVelECEFToJson(value) {
    return JSON.stringify(uncast(value, r("MsgVelECEF")), null, 2);
}

function toMsgVelNEDCov(json) {
    return cast(JSON.parse(json), r("MsgVelNEDCov"));
}

function msgVelNEDCovToJson(value) {
    return JSON.stringify(uncast(value, r("MsgVelNEDCov")), null, 2);
}

function toMsgVelNED(json) {
    return cast(JSON.parse(json), r("MsgVelNED"));
}

function msgVelNEDToJson(value) {
    return JSON.stringify(uncast(value, r("MsgVelNED")), null, 2);
}

function toNetworkUsage(json) {
    return cast(JSON.parse(json), r("NetworkUsage"));
}

function networkUsageToJson(value) {
    return JSON.stringify(uncast(value, r("NetworkUsage")), null, 2);
}

function toObservationHeader(json) {
    return cast(JSON.parse(json), r("ObservationHeader"));
}

function observationHeaderToJson(value) {
    return JSON.stringify(uncast(value, r("ObservationHeader")), null, 2);
}

function toPackedObsContent(json) {
    return cast(JSON.parse(json), r("PackedObsContent"));
}

function packedObsContentToJson(value) {
    return JSON.stringify(uncast(value, r("PackedObsContent")), null, 2);
}

function toPackedOsrContent(json) {
    return cast(JSON.parse(json), r("PackedOsrContent"));
}

function packedOsrContentToJson(value) {
    return JSON.stringify(uncast(value, r("PackedOsrContent")), null, 2);
}

function toPeriod(json) {
    return cast(JSON.parse(json), r("Period"));
}

function periodToJson(value) {
    return JSON.stringify(uncast(value, r("Period")), null, 2);
}

function toPhaseBiasesContent(json) {
    return cast(JSON.parse(json), r("PhaseBiasesContent"));
}

function phaseBiasesContentToJson(value) {
    return JSON.stringify(uncast(value, r("PhaseBiasesContent")), null, 2);
}

function toSTECHeader(json) {
    return cast(JSON.parse(json), r("STECHeader"));
}

function sTECHeaderToJson(value) {
    return JSON.stringify(uncast(value, r("STECHeader")), null, 2);
}

function toSTECResidual(json) {
    return cast(JSON.parse(json), r("STECResidual"));
}

function sTECResidualToJson(value) {
    return JSON.stringify(uncast(value, r("STECResidual")), null, 2);
}

function toSTECSatElement(json) {
    return cast(JSON.parse(json), r("STECSatElement"));
}

function sTECSatElementToJson(value) {
    return JSON.stringify(uncast(value, r("STECSatElement")), null, 2);
}

function toSvAzEl(json) {
    return cast(JSON.parse(json), r("SvAzEl"));
}

function svAzElToJson(value) {
    return JSON.stringify(uncast(value, r("SvAzEl")), null, 2);
}

function toSvID(json) {
    return cast(JSON.parse(json), r("SvID"));
}

function svIDToJson(value) {
    return JSON.stringify(uncast(value, r("SvID")), null, 2);
}

function toTrackingChannelCorrelation(json) {
    return cast(JSON.parse(json), r("TrackingChannelCorrelation"));
}

function trackingChannelCorrelationToJson(value) {
    return JSON.stringify(uncast(value, r("TrackingChannelCorrelation")), null, 2);
}

function toTrackingChannelState(json) {
    return cast(JSON.parse(json), r("TrackingChannelState"));
}

function trackingChannelStateToJson(value) {
    return JSON.stringify(uncast(value, r("TrackingChannelState")), null, 2);
}

function toTroposphericDelayCorrection(json) {
    return cast(JSON.parse(json), r("TroposphericDelayCorrection"));
}

function troposphericDelayCorrectionToJson(value) {
    return JSON.stringify(uncast(value, r("TroposphericDelayCorrection")), null, 2);
}

function toUARTChannel(json) {
    return cast(JSON.parse(json), r("UARTChannel"));
}

function uARTChannelToJson(value) {
    return JSON.stringify(uncast(value, r("UARTChannel")), null, 2);
}

function invalidValue(typ, val) {
    throw Error(`Invalid value ${JSON.stringify(val)} for type ${JSON.stringify(typ)}`);
}

function jsonToJSProps(typ) {
    if (typ.jsonToJS === undefined) {
        var map = {};
        typ.props.forEach((p) => map[p.json] = { key: p.js, typ: p.typ });
        typ.jsonToJS = map;
    }
    return typ.jsonToJS;
}

function jsToJSONProps(typ) {
    if (typ.jsToJSON === undefined) {
        var map = {};
        typ.props.forEach((p) => map[p.js] = { key: p.json, typ: p.typ });
        typ.jsToJSON = map;
    }
    return typ.jsToJSON;
}

function transform(val, typ, getProps) {
    function transformPrimitive(typ, val) {
        if (typeof typ === typeof val) return val;
        return invalidValue(typ, val);
    }

    function transformUnion(typs, val) {
        // val must validate against one typ in typs
        var l = typs.length;
        for (var i = 0; i < l; i++) {
            var typ = typs[i];
            try {
                return transform(val, typ, getProps);
            } catch (_) {}
        }
        return invalidValue(typs, val);
    }

    function transformEnum(cases, val) {
        if (cases.indexOf(val) !== -1) return val;
        return invalidValue(cases, val);
    }

    function transformArray(typ, val) {
        // val must be an array with no invalid elements
        if (!Array.isArray(val)) return invalidValue("array", val);
        return val.map(el => transform(el, typ, getProps));
    }

    function transformDate(typ, val) {
        if (val === null) {
            return null;
        }
        const d = new Date(val);
        if (isNaN(d.valueOf())) {
            return invalidValue("Date", val);
        }
        return d;
    }

    function transformObject(props, additional, val) {
        if (val === null || typeof val !== "object" || Array.isArray(val)) {
            return invalidValue("object", val);
        }
        var result = {};
        Object.getOwnPropertyNames(props).forEach(key => {
            const prop = props[key];
            const v = Object.prototype.hasOwnProperty.call(val, key) ? val[key] : undefined;
            result[prop.key] = transform(v, prop.typ, getProps);
        });
        Object.getOwnPropertyNames(val).forEach(key => {
            if (!Object.prototype.hasOwnProperty.call(props, key)) {
                result[key] = transform(val[key], additional, getProps);
            }
        });
        return result;
    }

    if (typ === "any") return val;
    if (typ === null) {
        if (val === null) return val;
        return invalidValue(typ, val);
    }
    if (typ === false) return invalidValue(typ, val);
    while (typeof typ === "object" && typ.ref !== undefined) {
        typ = typeMap[typ.ref];
    }
    if (Array.isArray(typ)) return transformEnum(typ, val);
    if (typeof typ === "object") {
        return typ.hasOwnProperty("unionMembers") ? transformUnion(typ.unionMembers, val)
            : typ.hasOwnProperty("arrayItems")    ? transformArray(typ.arrayItems, val)
            : typ.hasOwnProperty("props")         ? transformObject(getProps(typ), typ.additional, val)
            : invalidValue(typ, val);
    }
    // Numbers can be parsed by Date but shouldn't be.
    if (typ === Date && typeof val !== "number") return transformDate(typ, val);
    return transformPrimitive(typ, val);
}

function cast(val, typ) {
    return transform(val, typ, jsonToJSProps);
}

function uncast(val, typ) {
    return transform(val, typ, jsToJSONProps);
}

function a(typ) {
    return { arrayItems: typ };
}

function u(...typs) {
    return { unionMembers: typs };
}

function o(props, additional) {
    return { props, additional };
}

function m(additional) {
    return { props: [], additional };
}

function r(name) {
    return { ref: name };
}

const typeMap = {
    "MsgAcqResult": o([
        { json: "cf", js: "cf", typ: 3.14 },
        { json: "cn0", js: "cn0", typ: 3.14 },
        { json: "cp", js: "cp", typ: 3.14 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
    ], "any"),
    "GnssSignal": o([
        { json: "code", js: "code", typ: 0 },
        { json: "sat", js: "sat", typ: 0 },
    ], "any"),
    "MsgAcqSvProfile": o([
        { json: "acq_sv_profile", js: "acq_sv_profile", typ: a(r("AcqSvProfile")) },
    ], "any"),
    "AcqSvProfile": o([
        { json: "bin_width", js: "bin_width", typ: 0 },
        { json: "cf", js: "cf", typ: 0 },
        { json: "cf_max", js: "cf_max", typ: 0 },
        { json: "cf_min", js: "cf_min", typ: 0 },
        { json: "cn0", js: "cn0", typ: 0 },
        { json: "cp", js: "cp", typ: 0 },
        { json: "int_time", js: "int_time", typ: 0 },
        { json: "job_type", js: "job_type", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "status", js: "status", typ: 0 },
        { json: "time_spent", js: "time_spent", typ: 0 },
        { json: "timestamp", js: "timestamp", typ: 0 },
    ], "any"),
    "MsgAgeCorrections": o([
        { json: "age", js: "age", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
    ], "any"),
    "MsgAlmanacGlo": o([
        { json: "common", js: "common", typ: r("AlmanacCommonContent") },
        { json: "epsilon", js: "epsilon", typ: 3.14 },
        { json: "i", js: "i", typ: 3.14 },
        { json: "lambda_na", js: "lambda_na", typ: 3.14 },
        { json: "omega", js: "omega", typ: 3.14 },
        { json: "t", js: "t", typ: 3.14 },
        { json: "t_dot", js: "t_dot", typ: 3.14 },
        { json: "t_lambda_na", js: "t_lambda_na", typ: 3.14 },
    ], "any"),
    "AlmanacCommonContent": o([
        { json: "fit_interval", js: "fit_interval", typ: 0 },
        { json: "health_bits", js: "health_bits", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "toa", js: "toa", typ: r("GpsTimeSEC") },
        { json: "ura", js: "ura", typ: 3.14 },
        { json: "valid", js: "valid", typ: 0 },
    ], "any"),
    "GpsTimeSEC": o([
        { json: "tow", js: "tow", typ: 0 },
        { json: "wn", js: "wn", typ: 0 },
    ], "any"),
    "MsgAlmanacGPS": o([
        { json: "af0", js: "af0", typ: 3.14 },
        { json: "af1", js: "af1", typ: 3.14 },
        { json: "common", js: "common", typ: r("AlmanacCommonContent") },
        { json: "ecc", js: "ecc", typ: 3.14 },
        { json: "inc", js: "inc", typ: 3.14 },
        { json: "m0", js: "m0", typ: 3.14 },
        { json: "omega0", js: "omega0", typ: 3.14 },
        { json: "omegadot", js: "omegadot", typ: 3.14 },
        { json: "sqrta", js: "sqrta", typ: 3.14 },
        { json: "w", js: "w", typ: 3.14 },
    ], "any"),
    "MsgAngularRate": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 0 },
        { json: "y", js: "y", typ: 0 },
        { json: "z", js: "z", typ: 0 },
    ], "any"),
    "MsgBaselineECEF": o([
        { json: "accuracy", js: "accuracy", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 0 },
        { json: "y", js: "y", typ: 0 },
        { json: "z", js: "z", typ: 0 },
    ], "any"),
    "MsgBaselineHeading": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "heading", js: "heading", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
    ], "any"),
    "MsgBaselineNED": o([
        { json: "d", js: "d", typ: 0 },
        { json: "e", js: "e", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "h_accuracy", js: "h_accuracy", typ: 0 },
        { json: "n", js: "n", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "v_accuracy", js: "v_accuracy", typ: 0 },
    ], "any"),
    "MsgBasePosECEF": o([
        { json: "x", js: "x", typ: 3.14 },
        { json: "y", js: "y", typ: 3.14 },
        { json: "z", js: "z", typ: 3.14 },
    ], "any"),
    "MsgBasePosLLH": o([
        { json: "height", js: "height", typ: 3.14 },
        { json: "lat", js: "lat", typ: 3.14 },
        { json: "lon", js: "lon", typ: 3.14 },
    ], "any"),
    "MsgBootloaderHandshakeResp": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "version", js: "version", typ: "" },
    ], "any"),
    "MsgBootloaderJumpToApp": o([
        { json: "jump", js: "jump", typ: 0 },
    ], "any"),
    "MsgCellModemStatus": o([
        { json: "signal_error_rate", js: "signal_error_rate", typ: 3.14 },
        { json: "signal_strength", js: "signal_strength", typ: 0 },
    ], "any"),
    "MsgCommandOutput": o([
        { json: "line", js: "line", typ: "" },
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgCommandReq": o([
        { json: "command", js: "command", typ: "" },
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgCommandResp": o([
        { json: "code", js: "code", typ: 0 },
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgCsacTelemetry": o([
        { json: "id", js: "id", typ: 0 },
        { json: "telemetry", js: "telemetry", typ: "" },
    ], "any"),
    "MsgCsacTelemetryLabels": o([
        { json: "id", js: "id", typ: 0 },
        { json: "telemetry_labels", js: "telemetry_labels", typ: "" },
    ], "any"),
    "MsgDeviceMonitor": o([
        { json: "cpu_temperature", js: "cpu_temperature", typ: 0 },
        { json: "cpu_vaux", js: "cpu_vaux", typ: 0 },
        { json: "cpu_vint", js: "cpu_vint", typ: 0 },
        { json: "dev_vin", js: "dev_vin", typ: 0 },
        { json: "fe_temperature", js: "fe_temperature", typ: 0 },
    ], "any"),
    "MsgDgnssStatus": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "latency", js: "latency", typ: 0 },
        { json: "num_signals", js: "num_signals", typ: 0 },
        { json: "source", js: "source", typ: "" },
    ], "any"),
    "MsgDops": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "gdop", js: "gdop", typ: 0 },
        { json: "hdop", js: "hdop", typ: 0 },
        { json: "pdop", js: "pdop", typ: 0 },
        { json: "tdop", js: "tdop", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "vdop", js: "vdop", typ: 0 },
    ], "any"),
    "MsgEphemerisBds": o([
        { json: "af0", js: "af0", typ: 3.14 },
        { json: "af1", js: "af1", typ: 3.14 },
        { json: "af2", js: "af2", typ: 3.14 },
        { json: "c_ic", js: "c_ic", typ: 3.14 },
        { json: "c_is", js: "c_is", typ: 3.14 },
        { json: "c_rc", js: "c_rc", typ: 3.14 },
        { json: "c_rs", js: "c_rs", typ: 3.14 },
        { json: "c_uc", js: "c_uc", typ: 3.14 },
        { json: "c_us", js: "c_us", typ: 3.14 },
        { json: "common", js: "common", typ: r("EphemerisCommonContent") },
        { json: "dn", js: "dn", typ: 3.14 },
        { json: "ecc", js: "ecc", typ: 3.14 },
        { json: "inc", js: "inc", typ: 3.14 },
        { json: "inc_dot", js: "inc_dot", typ: 3.14 },
        { json: "iodc", js: "iodc", typ: 0 },
        { json: "iode", js: "iode", typ: 0 },
        { json: "m0", js: "m0", typ: 3.14 },
        { json: "omega0", js: "omega0", typ: 3.14 },
        { json: "omegadot", js: "omegadot", typ: 3.14 },
        { json: "sqrta", js: "sqrta", typ: 3.14 },
        { json: "tgd1", js: "tgd1", typ: 3.14 },
        { json: "tgd2", js: "tgd2", typ: 3.14 },
        { json: "toc", js: "toc", typ: r("GpsTimeSEC") },
        { json: "w", js: "w", typ: 3.14 },
    ], "any"),
    "EphemerisCommonContent": o([
        { json: "fit_interval", js: "fit_interval", typ: 0 },
        { json: "health_bits", js: "health_bits", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "toe", js: "toe", typ: r("GpsTimeSEC") },
        { json: "ura", js: "ura", typ: 3.14 },
        { json: "valid", js: "valid", typ: 0 },
    ], "any"),
    "MsgEphemerisGal": o([
        { json: "af0", js: "af0", typ: 3.14 },
        { json: "af1", js: "af1", typ: 3.14 },
        { json: "af2", js: "af2", typ: 3.14 },
        { json: "bgd_e1e5a", js: "bgd_e1e5a", typ: 3.14 },
        { json: "bgd_e1e5b", js: "bgd_e1e5b", typ: 3.14 },
        { json: "c_ic", js: "c_ic", typ: 3.14 },
        { json: "c_is", js: "c_is", typ: 3.14 },
        { json: "c_rc", js: "c_rc", typ: 3.14 },
        { json: "c_rs", js: "c_rs", typ: 3.14 },
        { json: "c_uc", js: "c_uc", typ: 3.14 },
        { json: "c_us", js: "c_us", typ: 3.14 },
        { json: "common", js: "common", typ: r("EphemerisCommonContent") },
        { json: "dn", js: "dn", typ: 3.14 },
        { json: "ecc", js: "ecc", typ: 3.14 },
        { json: "inc", js: "inc", typ: 3.14 },
        { json: "inc_dot", js: "inc_dot", typ: 3.14 },
        { json: "iodc", js: "iodc", typ: 0 },
        { json: "iode", js: "iode", typ: 0 },
        { json: "m0", js: "m0", typ: 3.14 },
        { json: "omega0", js: "omega0", typ: 3.14 },
        { json: "omegadot", js: "omegadot", typ: 3.14 },
        { json: "source", js: "source", typ: 0 },
        { json: "sqrta", js: "sqrta", typ: 3.14 },
        { json: "toc", js: "toc", typ: r("GpsTimeSEC") },
        { json: "w", js: "w", typ: 3.14 },
    ], "any"),
    "MsgEphemerisGlo": o([
        { json: "acc", js: "acc", typ: a(3.14) },
        { json: "common", js: "common", typ: r("EphemerisCommonContent") },
        { json: "d_tau", js: "d_tau", typ: 3.14 },
        { json: "fcn", js: "fcn", typ: 0 },
        { json: "gamma", js: "gamma", typ: 3.14 },
        { json: "iod", js: "iod", typ: 0 },
        { json: "pos", js: "pos", typ: a(3.14) },
        { json: "tau", js: "tau", typ: 3.14 },
        { json: "vel", js: "vel", typ: a(3.14) },
    ], "any"),
    "MsgEphemerisGPS": o([
        { json: "af0", js: "af0", typ: 3.14 },
        { json: "af1", js: "af1", typ: 3.14 },
        { json: "af2", js: "af2", typ: 3.14 },
        { json: "c_ic", js: "c_ic", typ: 3.14 },
        { json: "c_is", js: "c_is", typ: 3.14 },
        { json: "c_rc", js: "c_rc", typ: 3.14 },
        { json: "c_rs", js: "c_rs", typ: 3.14 },
        { json: "c_uc", js: "c_uc", typ: 3.14 },
        { json: "c_us", js: "c_us", typ: 3.14 },
        { json: "common", js: "common", typ: r("EphemerisCommonContent") },
        { json: "dn", js: "dn", typ: 3.14 },
        { json: "ecc", js: "ecc", typ: 3.14 },
        { json: "inc", js: "inc", typ: 3.14 },
        { json: "inc_dot", js: "inc_dot", typ: 3.14 },
        { json: "iodc", js: "iodc", typ: 0 },
        { json: "iode", js: "iode", typ: 0 },
        { json: "m0", js: "m0", typ: 3.14 },
        { json: "omega0", js: "omega0", typ: 3.14 },
        { json: "omegadot", js: "omegadot", typ: 3.14 },
        { json: "sqrta", js: "sqrta", typ: 3.14 },
        { json: "tgd", js: "tgd", typ: 3.14 },
        { json: "toc", js: "toc", typ: r("GpsTimeSEC") },
        { json: "w", js: "w", typ: 3.14 },
    ], "any"),
    "MsgEphemerisQzss": o([
        { json: "af0", js: "af0", typ: 3.14 },
        { json: "af1", js: "af1", typ: 3.14 },
        { json: "af2", js: "af2", typ: 3.14 },
        { json: "c_ic", js: "c_ic", typ: 3.14 },
        { json: "c_is", js: "c_is", typ: 3.14 },
        { json: "c_rc", js: "c_rc", typ: 3.14 },
        { json: "c_rs", js: "c_rs", typ: 3.14 },
        { json: "c_uc", js: "c_uc", typ: 3.14 },
        { json: "c_us", js: "c_us", typ: 3.14 },
        { json: "common", js: "common", typ: r("EphemerisCommonContent") },
        { json: "dn", js: "dn", typ: 3.14 },
        { json: "ecc", js: "ecc", typ: 3.14 },
        { json: "inc", js: "inc", typ: 3.14 },
        { json: "inc_dot", js: "inc_dot", typ: 3.14 },
        { json: "iodc", js: "iodc", typ: 0 },
        { json: "iode", js: "iode", typ: 0 },
        { json: "m0", js: "m0", typ: 3.14 },
        { json: "omega0", js: "omega0", typ: 3.14 },
        { json: "omegadot", js: "omegadot", typ: 3.14 },
        { json: "sqrta", js: "sqrta", typ: 3.14 },
        { json: "tgd", js: "tgd", typ: 3.14 },
        { json: "toc", js: "toc", typ: r("GpsTimeSEC") },
        { json: "w", js: "w", typ: 3.14 },
    ], "any"),
    "MsgEphemerisSbas": o([
        { json: "a_gf0", js: "a_gf0", typ: 3.14 },
        { json: "a_gf1", js: "a_gf1", typ: 3.14 },
        { json: "acc", js: "acc", typ: a(3.14) },
        { json: "common", js: "common", typ: r("EphemerisCommonContent") },
        { json: "pos", js: "pos", typ: a(3.14) },
        { json: "vel", js: "vel", typ: a(3.14) },
    ], "any"),
    "MsgEXTEvent": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "ns_residual", js: "ns_residual", typ: 0 },
        { json: "pin", js: "pin", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "wn", js: "wn", typ: 0 },
    ], "any"),
    "MsgFileioConfigReq": o([
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgFileioConfigResp": o([
        { json: "batch_size", js: "batch_size", typ: 0 },
        { json: "fileio_version", js: "fileio_version", typ: 0 },
        { json: "sequence", js: "sequence", typ: 0 },
        { json: "window_size", js: "window_size", typ: 0 },
    ], "any"),
    "MsgFileioReadDirReq": o([
        { json: "dirname", js: "dirname", typ: "" },
        { json: "offset", js: "offset", typ: 0 },
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgFileioReadDirResp": o([
        { json: "contents", js: "contents", typ: a(0) },
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgFileioReadReq": o([
        { json: "chunk_size", js: "chunk_size", typ: 0 },
        { json: "filename", js: "filename", typ: "" },
        { json: "offset", js: "offset", typ: 0 },
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgFileioReadResp": o([
        { json: "contents", js: "contents", typ: a(0) },
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgFileioRemove": o([
        { json: "filename", js: "filename", typ: "" },
    ], "any"),
    "MsgFileioWriteReq": o([
        { json: "data", js: "data", typ: a(0) },
        { json: "filename", js: "filename", typ: "" },
        { json: "offset", js: "offset", typ: 0 },
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgFileioWriteResp": o([
        { json: "sequence", js: "sequence", typ: 0 },
    ], "any"),
    "MsgFlashDone": o([
        { json: "response", js: "response", typ: 0 },
    ], "any"),
    "MsgFlashErase": o([
        { json: "sector_num", js: "sector_num", typ: 0 },
        { json: "target", js: "target", typ: 0 },
    ], "any"),
    "MsgFlashProgram": o([
        { json: "addr_len", js: "addr_len", typ: 0 },
        { json: "addr_start", js: "addr_start", typ: a(0) },
        { json: "data", js: "data", typ: a(0) },
        { json: "target", js: "target", typ: 0 },
    ], "any"),
    "MsgFlashReadReq": o([
        { json: "addr_len", js: "addr_len", typ: 0 },
        { json: "addr_start", js: "addr_start", typ: a(0) },
        { json: "target", js: "target", typ: 0 },
    ], "any"),
    "MsgFlashReadResp": o([
        { json: "addr_len", js: "addr_len", typ: 0 },
        { json: "addr_start", js: "addr_start", typ: a(0) },
        { json: "target", js: "target", typ: 0 },
    ], "any"),
    "MsgFrontEndGain": o([
        { json: "if_gain", js: "if_gain", typ: a(0) },
        { json: "rf_gain", js: "rf_gain", typ: a(0) },
    ], "any"),
    "MsgFwd": o([
        { json: "fwd_payload", js: "fwd_payload", typ: "" },
        { json: "protocol", js: "protocol", typ: 0 },
        { json: "source", js: "source", typ: 0 },
    ], "any"),
    "MsgGloBiases": o([
        { json: "l1ca_bias", js: "l1ca_bias", typ: 0 },
        { json: "l1p_bias", js: "l1p_bias", typ: 0 },
        { json: "l2ca_bias", js: "l2ca_bias", typ: 0 },
        { json: "l2p_bias", js: "l2p_bias", typ: 0 },
        { json: "mask", js: "mask", typ: 0 },
    ], "any"),
    "MsgGnssCapb": o([
        { json: "gc", js: "gc", typ: r("GnssCapb") },
        { json: "t_nmct", js: "t_nmct", typ: r("GpsTimeSEC") },
    ], "any"),
    "GnssCapb": o([
        { json: "bds_active", js: "bds_active", typ: 0 },
        { json: "bds_b2", js: "bds_b2", typ: 0 },
        { json: "bds_b2a", js: "bds_b2a", typ: 0 },
        { json: "bds_d2nav", js: "bds_d2nav", typ: 0 },
        { json: "gal_active", js: "gal_active", typ: 0 },
        { json: "gal_e5", js: "gal_e5", typ: 0 },
        { json: "glo_active", js: "glo_active", typ: 0 },
        { json: "glo_l2of", js: "glo_l2of", typ: 0 },
        { json: "glo_l3", js: "glo_l3", typ: 0 },
        { json: "gps_active", js: "gps_active", typ: 0 },
        { json: "gps_l2c", js: "gps_l2c", typ: 0 },
        { json: "gps_l5", js: "gps_l5", typ: 0 },
        { json: "qzss_active", js: "qzss_active", typ: 0 },
        { json: "sbas_active", js: "sbas_active", typ: 0 },
        { json: "sbas_l5", js: "sbas_l5", typ: 0 },
    ], "any"),
    "MsgGPSTime": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "ns_residual", js: "ns_residual", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "wn", js: "wn", typ: 0 },
    ], "any"),
    "MsgGroupDelay": o([
        { json: "isc_l1ca", js: "isc_l1ca", typ: 0 },
        { json: "isc_l2c", js: "isc_l2c", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "t_op", js: "t_op", typ: r("GpsTimeSEC") },
        { json: "tgd", js: "tgd", typ: 0 },
        { json: "valid", js: "valid", typ: 0 },
    ], "any"),
    "MsgHeartbeat": o([
        { json: "flags", js: "flags", typ: 0 },
    ], "any"),
    "MsgIarState": o([
        { json: "num_hyps", js: "num_hyps", typ: 0 },
    ], "any"),
    "MsgImuAux": o([
        { json: "imu_conf", js: "imu_conf", typ: 0 },
        { json: "imu_type", js: "imu_type", typ: 0 },
        { json: "temp", js: "temp", typ: 0 },
    ], "any"),
    "MsgImuRaw": o([
        { json: "acc_x", js: "acc_x", typ: 0 },
        { json: "acc_y", js: "acc_y", typ: 0 },
        { json: "acc_z", js: "acc_z", typ: 0 },
        { json: "gyr_x", js: "gyr_x", typ: 0 },
        { json: "gyr_y", js: "gyr_y", typ: 0 },
        { json: "gyr_z", js: "gyr_z", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "tow_f", js: "tow_f", typ: 0 },
    ], "any"),
    "MsgInsStatus": o([
        { json: "flags", js: "flags", typ: 0 },
    ], "any"),
    "MsgIono": o([
        { json: "a0", js: "a0", typ: 3.14 },
        { json: "a1", js: "a1", typ: 3.14 },
        { json: "a2", js: "a2", typ: 3.14 },
        { json: "a3", js: "a3", typ: 3.14 },
        { json: "b0", js: "b0", typ: 3.14 },
        { json: "b1", js: "b1", typ: 3.14 },
        { json: "b2", js: "b2", typ: 3.14 },
        { json: "b3", js: "b3", typ: 3.14 },
        { json: "t_nmct", js: "t_nmct", typ: r("GpsTimeSEC") },
    ], "any"),
    "MsgLinuxCPUState": o([
        { json: "cmdline", js: "cmdline", typ: "" },
        { json: "index", js: "index", typ: 0 },
        { json: "pcpu", js: "pcpu", typ: 0 },
        { json: "pid", js: "pid", typ: 0 },
        { json: "tname", js: "tname", typ: "" },
    ], "any"),
    "MsgLinuxMemState": o([
        { json: "cmdline", js: "cmdline", typ: "" },
        { json: "index", js: "index", typ: 0 },
        { json: "pid", js: "pid", typ: 0 },
        { json: "pmem", js: "pmem", typ: 0 },
        { json: "tname", js: "tname", typ: "" },
    ], "any"),
    "MsgLinuxProcessFdCount": o([
        { json: "cmdline", js: "cmdline", typ: "" },
        { json: "fd_count", js: "fd_count", typ: 0 },
        { json: "index", js: "index", typ: 0 },
        { json: "pid", js: "pid", typ: 0 },
    ], "any"),
    "MsgLinuxProcessFdSummary": o([
        { json: "most_opened", js: "most_opened", typ: "" },
        { json: "sys_fd_count", js: "sys_fd_count", typ: 0 },
    ], "any"),
    "MsgLinuxProcessSocketCounts": o([
        { json: "cmdline", js: "cmdline", typ: "" },
        { json: "index", js: "index", typ: 0 },
        { json: "pid", js: "pid", typ: 0 },
        { json: "socket_count", js: "socket_count", typ: 0 },
        { json: "socket_states", js: "socket_states", typ: 0 },
        { json: "socket_types", js: "socket_types", typ: 0 },
    ], "any"),
    "MsgLinuxProcessSocketQueues": o([
        { json: "address_of_largest", js: "address_of_largest", typ: "" },
        { json: "cmdline", js: "cmdline", typ: "" },
        { json: "index", js: "index", typ: 0 },
        { json: "pid", js: "pid", typ: 0 },
        { json: "recv_queued", js: "recv_queued", typ: 0 },
        { json: "send_queued", js: "send_queued", typ: 0 },
        { json: "socket_states", js: "socket_states", typ: 0 },
        { json: "socket_types", js: "socket_types", typ: 0 },
    ], "any"),
    "MsgLinuxSocketUsage": o([
        { json: "avg_queue_depth", js: "avg_queue_depth", typ: 0 },
        { json: "max_queue_depth", js: "max_queue_depth", typ: 0 },
        { json: "socket_state_counts", js: "socket_state_counts", typ: a(0) },
        { json: "socket_type_counts", js: "socket_type_counts", typ: a(0) },
    ], "any"),
    "MsgLinuxSysState": o([
        { json: "mem_total", js: "mem_total", typ: 0 },
        { json: "pcpu", js: "pcpu", typ: 0 },
        { json: "pid_count", js: "pid_count", typ: 0 },
        { json: "pmem", js: "pmem", typ: 0 },
        { json: "procs_starting", js: "procs_starting", typ: 0 },
        { json: "procs_stopping", js: "procs_stopping", typ: 0 },
    ], "any"),
    "MsgLog": o([
        { json: "level", js: "level", typ: 0 },
        { json: "text", js: "text", typ: "" },
    ], "any"),
    "MsgM25FlashWriteStatus": o([
        { json: "status", js: "status", typ: a(0) },
    ], "any"),
    "MsgMagRaw": o([
        { json: "mag_x", js: "mag_x", typ: 0 },
        { json: "mag_y", js: "mag_y", typ: 0 },
        { json: "mag_z", js: "mag_z", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "tow_f", js: "tow_f", typ: 0 },
    ], "any"),
    "MsgMaskSatellite": o([
        { json: "mask", js: "mask", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
    ], "any"),
    "MsgMeasurementState": o([
        { json: "states", js: "states", typ: a(r("MeasurementState")) },
    ], "any"),
    "MeasurementState": o([
        { json: "cn0", js: "cn0", typ: 0 },
        { json: "mesid", js: "mesid", typ: r("GnssSignal") },
    ], "any"),
    "MsgNapDeviceDnaResp": o([
        { json: "dna", js: "dna", typ: a(0) },
    ], "any"),
    "MsgNdbEvent": o([
        { json: "data_source", js: "data_source", typ: 0 },
        { json: "event", js: "event", typ: 0 },
        { json: "object_sid", js: "object_sid", typ: r("GnssSignal") },
        { json: "object_type", js: "object_type", typ: 0 },
        { json: "original_sender", js: "original_sender", typ: 0 },
        { json: "recv_time", js: "recv_time", typ: 0 },
        { json: "result", js: "result", typ: 0 },
        { json: "src_sid", js: "src_sid", typ: r("GnssSignal") },
    ], "any"),
    "MsgNetworkBandwidthUsage": o([
        { json: "interfaces", js: "interfaces", typ: a(r("NetworkUsage")) },
    ], "any"),
    "NetworkUsage": o([
        { json: "duration", js: "duration", typ: 0 },
        { json: "interface_name", js: "interface_name", typ: "" },
        { json: "rx_bytes", js: "rx_bytes", typ: 0 },
        { json: "total_bytes", js: "total_bytes", typ: 0 },
        { json: "tx_bytes", js: "tx_bytes", typ: 0 },
    ], "any"),
    "MsgNetworkStateResp": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "interface_name", js: "interface_name", typ: "" },
        { json: "ipv4_address", js: "ipv4_address", typ: a(0) },
        { json: "ipv4_mask_size", js: "ipv4_mask_size", typ: 0 },
        { json: "ipv6_address", js: "ipv6_address", typ: a(0) },
        { json: "ipv6_mask_size", js: "ipv6_mask_size", typ: 0 },
        { json: "rx_bytes", js: "rx_bytes", typ: 0 },
        { json: "tx_bytes", js: "tx_bytes", typ: 0 },
    ], "any"),
    "MsgObs": o([
        { json: "header", js: "header", typ: r("ObservationHeader") },
        { json: "obs", js: "obs", typ: a(r("PackedObsContent")) },
    ], "any"),
    "ObservationHeader": o([
        { json: "n_obs", js: "n_obs", typ: 0 },
        { json: "t", js: "t", typ: r("GpsTime") },
    ], "any"),
    "GpsTime": o([
        { json: "ns_residual", js: "ns_residual", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "wn", js: "wn", typ: 0 },
    ], "any"),
    "PackedObsContent": o([
        { json: "cn0", js: "cn0", typ: 0 },
        { json: "D", js: "D", typ: r("Doppler") },
        { json: "flags", js: "flags", typ: 0 },
        { json: "L", js: "L", typ: r("CarrierPhase") },
        { json: "lock", js: "lock", typ: 0 },
        { json: "P", js: "P", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
    ], "any"),
    "Doppler": o([
        { json: "f", js: "f", typ: 0 },
        { json: "i", js: "i", typ: 0 },
    ], "any"),
    "CarrierPhase": o([
        { json: "f", js: "f", typ: 0 },
        { json: "i", js: "i", typ: 0 },
    ], "any"),
    "MsgOdometry": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "velocity", js: "velocity", typ: 0 },
    ], "any"),
    "MsgOrientEuler": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "pitch", js: "pitch", typ: 0 },
        { json: "pitch_accuracy", js: "pitch_accuracy", typ: 3.14 },
        { json: "roll", js: "roll", typ: 0 },
        { json: "roll_accuracy", js: "roll_accuracy", typ: 3.14 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "yaw", js: "yaw", typ: 0 },
        { json: "yaw_accuracy", js: "yaw_accuracy", typ: 3.14 },
    ], "any"),
    "MsgOrientQuat": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "w", js: "w", typ: 0 },
        { json: "w_accuracy", js: "w_accuracy", typ: 3.14 },
        { json: "x", js: "x", typ: 0 },
        { json: "x_accuracy", js: "x_accuracy", typ: 3.14 },
        { json: "y", js: "y", typ: 0 },
        { json: "y_accuracy", js: "y_accuracy", typ: 3.14 },
        { json: "z", js: "z", typ: 0 },
        { json: "z_accuracy", js: "z_accuracy", typ: 3.14 },
    ], "any"),
    "MsgOsr": o([
        { json: "header", js: "header", typ: r("ObservationHeader") },
        { json: "obs", js: "obs", typ: a(r("PackedOsrContent")) },
    ], "any"),
    "PackedOsrContent": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "iono_std", js: "iono_std", typ: 0 },
        { json: "L", js: "L", typ: r("CarrierPhase") },
        { json: "lock", js: "lock", typ: 0 },
        { json: "P", js: "P", typ: 0 },
        { json: "range_std", js: "range_std", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "tropo_std", js: "tropo_std", typ: 0 },
    ], "any"),
    "MsgPosECEFCov": o([
        { json: "cov_x_x", js: "cov_x_x", typ: 3.14 },
        { json: "cov_x_y", js: "cov_x_y", typ: 3.14 },
        { json: "cov_x_z", js: "cov_x_z", typ: 3.14 },
        { json: "cov_y_y", js: "cov_y_y", typ: 3.14 },
        { json: "cov_y_z", js: "cov_y_z", typ: 3.14 },
        { json: "cov_z_z", js: "cov_z_z", typ: 3.14 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 3.14 },
        { json: "y", js: "y", typ: 3.14 },
        { json: "z", js: "z", typ: 3.14 },
    ], "any"),
    "MsgPosECEF": o([
        { json: "accuracy", js: "accuracy", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 3.14 },
        { json: "y", js: "y", typ: 3.14 },
        { json: "z", js: "z", typ: 3.14 },
    ], "any"),
    "MsgPosLLHCov": o([
        { json: "cov_d_d", js: "cov_d_d", typ: 3.14 },
        { json: "cov_e_d", js: "cov_e_d", typ: 3.14 },
        { json: "cov_e_e", js: "cov_e_e", typ: 3.14 },
        { json: "cov_n_d", js: "cov_n_d", typ: 3.14 },
        { json: "cov_n_e", js: "cov_n_e", typ: 3.14 },
        { json: "cov_n_n", js: "cov_n_n", typ: 3.14 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "height", js: "height", typ: 3.14 },
        { json: "lat", js: "lat", typ: 3.14 },
        { json: "lon", js: "lon", typ: 3.14 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
    ], "any"),
    "MsgPosLLH": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "h_accuracy", js: "h_accuracy", typ: 0 },
        { json: "height", js: "height", typ: 3.14 },
        { json: "lat", js: "lat", typ: 3.14 },
        { json: "lon", js: "lon", typ: 3.14 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "v_accuracy", js: "v_accuracy", typ: 0 },
    ], "any"),
    "MsgResetFilters": o([
        { json: "filter", js: "filter", typ: 0 },
    ], "any"),
    "MsgReset": o([
        { json: "flags", js: "flags", typ: 0 },
    ], "any"),
    "MsgSbasRaw": o([
        { json: "data", js: "data", typ: a(0) },
        { json: "message_type", js: "message_type", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "tow", js: "tow", typ: 0 },
    ], "any"),
    "MsgSettingsReadByIndexReq": o([
        { json: "index", js: "index", typ: 0 },
    ], "any"),
    "MsgSettingsReadByIndexResp": o([
        { json: "index", js: "index", typ: 0 },
        { json: "setting", js: "setting", typ: "" },
    ], "any"),
    "MsgSettingsReadReq": o([
        { json: "setting", js: "setting", typ: "" },
    ], "any"),
    "MsgSettingsReadResp": o([
        { json: "setting", js: "setting", typ: "" },
    ], "any"),
    "MsgSettingsRegister": o([
        { json: "setting", js: "setting", typ: "" },
    ], "any"),
    "MsgSettingsRegisterResp": o([
        { json: "setting", js: "setting", typ: "" },
        { json: "status", js: "status", typ: 0 },
    ], "any"),
    "MsgSettingsWrite": o([
        { json: "setting", js: "setting", typ: "" },
    ], "any"),
    "MsgSettingsWriteResp": o([
        { json: "setting", js: "setting", typ: "" },
        { json: "status", js: "status", typ: 0 },
    ], "any"),
    "MsgSpecan": o([
        { json: "amplitude_ref", js: "amplitude_ref", typ: 3.14 },
        { json: "amplitude_unit", js: "amplitude_unit", typ: 3.14 },
        { json: "amplitude_value", js: "amplitude_value", typ: a(0) },
        { json: "channel_tag", js: "channel_tag", typ: 0 },
        { json: "freq_ref", js: "freq_ref", typ: 3.14 },
        { json: "freq_step", js: "freq_step", typ: 3.14 },
        { json: "t", js: "t", typ: r("GpsTime") },
    ], "any"),
    "MsgSsrCodeBiases": o([
        { json: "biases", js: "biases", typ: a(r("CodeBiasesContent")) },
        { json: "iod_ssr", js: "iod_ssr", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "time", js: "time", typ: r("GpsTimeSEC") },
        { json: "update_interval", js: "update_interval", typ: 0 },
    ], "any"),
    "CodeBiasesContent": o([
        { json: "code", js: "code", typ: 0 },
        { json: "value", js: "value", typ: 0 },
    ], "any"),
    "MsgSsrGriddedCorrection": o([
        { json: "element", js: "element", typ: r("GridElement") },
        { json: "header", js: "header", typ: r("GriddedCorrectionHeader") },
    ], "any"),
    "GridElement": o([
        { json: "index", js: "index", typ: 0 },
        { json: "stec_residuals", js: "stec_residuals", typ: a(r("STECResidual")) },
        { json: "tropo_delay_correction", js: "tropo_delay_correction", typ: r("TroposphericDelayCorrection") },
    ], "any"),
    "STECResidual": o([
        { json: "residual", js: "residual", typ: 0 },
        { json: "sv_id", js: "sv_id", typ: r("SvID") },
    ], "any"),
    "SvID": o([
        { json: "constellation", js: "constellation", typ: 0 },
        { json: "satId", js: "satId", typ: 0 },
    ], "any"),
    "TroposphericDelayCorrection": o([
        { json: "hydro", js: "hydro", typ: 0 },
        { json: "wet", js: "wet", typ: 0 },
    ], "any"),
    "GriddedCorrectionHeader": o([
        { json: "iod_atmo", js: "iod_atmo", typ: 0 },
        { json: "num_msgs", js: "num_msgs", typ: 0 },
        { json: "seq_num", js: "seq_num", typ: 0 },
        { json: "time", js: "time", typ: r("GpsTimeSEC") },
        { json: "tropo_quality_indicator", js: "tropo_quality_indicator", typ: 0 },
        { json: "update_interval", js: "update_interval", typ: 0 },
    ], "any"),
    "MsgSsrGridDefinition": o([
        { json: "header", js: "header", typ: r("GridDefinitionHeader") },
        { json: "rle_list", js: "rle_list", typ: a(0) },
    ], "any"),
    "GridDefinitionHeader": o([
        { json: "area_width", js: "area_width", typ: 0 },
        { json: "lat_nw_corner_enc", js: "lat_nw_corner_enc", typ: 0 },
        { json: "lon_nw_corner_enc", js: "lon_nw_corner_enc", typ: 0 },
        { json: "num_msgs", js: "num_msgs", typ: 0 },
        { json: "region_size_inverse", js: "region_size_inverse", typ: 0 },
        { json: "seq_num", js: "seq_num", typ: 0 },
    ], "any"),
    "MsgSsrOrbitClock": o([
        { json: "along", js: "along", typ: 0 },
        { json: "c0", js: "c0", typ: 0 },
        { json: "c1", js: "c1", typ: 0 },
        { json: "c2", js: "c2", typ: 0 },
        { json: "cross", js: "cross", typ: 0 },
        { json: "dot_along", js: "dot_along", typ: 0 },
        { json: "dot_cross", js: "dot_cross", typ: 0 },
        { json: "dot_radial", js: "dot_radial", typ: 0 },
        { json: "iod", js: "iod", typ: 0 },
        { json: "iod_ssr", js: "iod_ssr", typ: 0 },
        { json: "radial", js: "radial", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "time", js: "time", typ: r("GpsTimeSEC") },
        { json: "update_interval", js: "update_interval", typ: 0 },
    ], "any"),
    "MsgSsrPhaseBiases": o([
        { json: "biases", js: "biases", typ: a(r("PhaseBiasesContent")) },
        { json: "dispersive_bias", js: "dispersive_bias", typ: 0 },
        { json: "iod_ssr", js: "iod_ssr", typ: 0 },
        { json: "mw_consistency", js: "mw_consistency", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "time", js: "time", typ: r("GpsTimeSEC") },
        { json: "update_interval", js: "update_interval", typ: 0 },
        { json: "yaw", js: "yaw", typ: 0 },
        { json: "yaw_rate", js: "yaw_rate", typ: 0 },
    ], "any"),
    "PhaseBiasesContent": o([
        { json: "bias", js: "bias", typ: 0 },
        { json: "code", js: "code", typ: 0 },
        { json: "discontinuity_counter", js: "discontinuity_counter", typ: 0 },
        { json: "integer_indicator", js: "integer_indicator", typ: 0 },
        { json: "widelane_integer_indicator", js: "widelane_integer_indicator", typ: 0 },
    ], "any"),
    "MsgSsrStecCorrection": o([
        { json: "header", js: "header", typ: r("STECHeader") },
        { json: "stec_sat_list", js: "stec_sat_list", typ: a(r("STECSatElement")) },
    ], "any"),
    "STECHeader": o([
        { json: "iod_atmo", js: "iod_atmo", typ: 0 },
        { json: "num_msgs", js: "num_msgs", typ: 0 },
        { json: "seq_num", js: "seq_num", typ: 0 },
        { json: "time", js: "time", typ: r("GpsTimeSEC") },
        { json: "update_interval", js: "update_interval", typ: 0 },
    ], "any"),
    "STECSatElement": o([
        { json: "stec_coeff", js: "stec_coeff", typ: a(0) },
        { json: "stec_quality_indicator", js: "stec_quality_indicator", typ: 0 },
        { json: "sv_id", js: "sv_id", typ: r("SvID") },
    ], "any"),
    "MsgStartup": o([
        { json: "cause", js: "cause", typ: 0 },
        { json: "startup_type", js: "startup_type", typ: 0 },
    ], "any"),
    "MsgStmFlashLockSector": o([
        { json: "sector", js: "sector", typ: 0 },
    ], "any"),
    "MsgStmFlashUnlockSector": o([
        { json: "sector", js: "sector", typ: 0 },
    ], "any"),
    "MsgStmUniqueIDResp": o([
        { json: "stm_id", js: "stm_id", typ: a(0) },
    ], "any"),
    "MsgSvAzEl": o([
        { json: "azel", js: "azel", typ: a(r("SvAzEl")) },
    ], "any"),
    "SvAzEl": o([
        { json: "az", js: "az", typ: 0 },
        { json: "el", js: "el", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
    ], "any"),
    "MsgThreadState": o([
        { json: "cpu", js: "cpu", typ: 0 },
        { json: "name", js: "name", typ: "" },
        { json: "stack_free", js: "stack_free", typ: 0 },
    ], "any"),
    "MsgTrackingIq": o([
        { json: "channel", js: "channel", typ: 0 },
        { json: "corrs", js: "corrs", typ: a(r("TrackingChannelCorrelation")) },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
    ], "any"),
    "TrackingChannelCorrelation": o([
        { json: "I", js: "I", typ: 0 },
        { json: "Q", js: "Q", typ: 0 },
    ], "any"),
    "MsgTrackingState": o([
        { json: "states", js: "states", typ: a(r("TrackingChannelState")) },
    ], "any"),
    "TrackingChannelState": o([
        { json: "cn0", js: "cn0", typ: 0 },
        { json: "fcn", js: "fcn", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
    ], "any"),
    "MsgUARTState": o([
        { json: "latency", js: "latency", typ: r("Latency") },
        { json: "obs_period", js: "obs_period", typ: r("Period") },
        { json: "uart_a", js: "uart_a", typ: r("UARTChannel") },
        { json: "uart_b", js: "uart_b", typ: r("UARTChannel") },
        { json: "uart_ftdi", js: "uart_ftdi", typ: r("UARTChannel") },
    ], "any"),
    "Latency": o([
        { json: "avg", js: "avg", typ: 0 },
        { json: "current", js: "current", typ: 0 },
        { json: "lmax", js: "lmax", typ: 0 },
        { json: "lmin", js: "lmin", typ: 0 },
    ], "any"),
    "Period": o([
        { json: "avg", js: "avg", typ: 0 },
        { json: "current", js: "current", typ: 0 },
        { json: "pmax", js: "pmax", typ: 0 },
        { json: "pmin", js: "pmin", typ: 0 },
    ], "any"),
    "UARTChannel": o([
        { json: "crc_error_count", js: "crc_error_count", typ: 0 },
        { json: "io_error_count", js: "io_error_count", typ: 0 },
        { json: "rx_buffer_level", js: "rx_buffer_level", typ: 0 },
        { json: "rx_throughput", js: "rx_throughput", typ: 3.14 },
        { json: "tx_buffer_level", js: "tx_buffer_level", typ: 0 },
        { json: "tx_throughput", js: "tx_throughput", typ: 3.14 },
    ], "any"),
    "MsgUserData": o([
        { json: "contents", js: "contents", typ: a(0) },
    ], "any"),
    "MsgUTCTime": o([
        { json: "day", js: "day", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "hours", js: "hours", typ: 0 },
        { json: "minutes", js: "minutes", typ: 0 },
        { json: "month", js: "month", typ: 0 },
        { json: "ns", js: "ns", typ: 0 },
        { json: "seconds", js: "seconds", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "year", js: "year", typ: 0 },
    ], "any"),
    "MsgVelBody": o([
        { json: "cov_x_x", js: "cov_x_x", typ: 3.14 },
        { json: "cov_x_y", js: "cov_x_y", typ: 3.14 },
        { json: "cov_x_z", js: "cov_x_z", typ: 3.14 },
        { json: "cov_y_y", js: "cov_y_y", typ: 3.14 },
        { json: "cov_y_z", js: "cov_y_z", typ: 3.14 },
        { json: "cov_z_z", js: "cov_z_z", typ: 3.14 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 0 },
        { json: "y", js: "y", typ: 0 },
        { json: "z", js: "z", typ: 0 },
    ], "any"),
    "MsgVelECEFCov": o([
        { json: "cov_x_x", js: "cov_x_x", typ: 3.14 },
        { json: "cov_x_y", js: "cov_x_y", typ: 3.14 },
        { json: "cov_x_z", js: "cov_x_z", typ: 3.14 },
        { json: "cov_y_y", js: "cov_y_y", typ: 3.14 },
        { json: "cov_y_z", js: "cov_y_z", typ: 3.14 },
        { json: "cov_z_z", js: "cov_z_z", typ: 3.14 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 0 },
        { json: "y", js: "y", typ: 0 },
        { json: "z", js: "z", typ: 0 },
    ], "any"),
    "MsgVelECEF": o([
        { json: "accuracy", js: "accuracy", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 0 },
        { json: "y", js: "y", typ: 0 },
        { json: "z", js: "z", typ: 0 },
    ], "any"),
    "MsgVelNEDCov": o([
        { json: "cov_d_d", js: "cov_d_d", typ: 3.14 },
        { json: "cov_e_d", js: "cov_e_d", typ: 3.14 },
        { json: "cov_e_e", js: "cov_e_e", typ: 3.14 },
        { json: "cov_n_d", js: "cov_n_d", typ: 3.14 },
        { json: "cov_n_e", js: "cov_n_e", typ: 3.14 },
        { json: "cov_n_n", js: "cov_n_n", typ: 3.14 },
        { json: "d", js: "d", typ: 0 },
        { json: "e", js: "e", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n", js: "n", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
    ], "any"),
    "MsgVelNED": o([
        { json: "d", js: "d", typ: 0 },
        { json: "e", js: "e", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "h_accuracy", js: "h_accuracy", typ: 0 },
        { json: "n", js: "n", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "v_accuracy", js: "v_accuracy", typ: 0 },
    ], "any"),
};

module.exports = {
    "acqSvProfileToJson": acqSvProfileToJson,
    "toAcqSvProfile": toAcqSvProfile,
    "almanacCommonContentToJson": almanacCommonContentToJson,
    "toAlmanacCommonContent": toAlmanacCommonContent,
    "carrierPhaseToJson": carrierPhaseToJson,
    "toCarrierPhase": toCarrierPhase,
    "codeBiasesContentToJson": codeBiasesContentToJson,
    "toCodeBiasesContent": toCodeBiasesContent,
    "dopplerToJson": dopplerToJson,
    "toDoppler": toDoppler,
    "ephemerisCommonContentToJson": ephemerisCommonContentToJson,
    "toEphemerisCommonContent": toEphemerisCommonContent,
    "gnssCapbToJson": gnssCapbToJson,
    "toGnssCapb": toGnssCapb,
    "gnssSignalToJson": gnssSignalToJson,
    "toGnssSignal": toGnssSignal,
    "gpsTimeToJson": gpsTimeToJson,
    "toGpsTime": toGpsTime,
    "gpsTimeSECToJson": gpsTimeSECToJson,
    "toGpsTimeSEC": toGpsTimeSEC,
    "griddedCorrectionHeaderToJson": griddedCorrectionHeaderToJson,
    "toGriddedCorrectionHeader": toGriddedCorrectionHeader,
    "gridDefinitionHeaderToJson": gridDefinitionHeaderToJson,
    "toGridDefinitionHeader": toGridDefinitionHeader,
    "gridElementToJson": gridElementToJson,
    "toGridElement": toGridElement,
    "latencyToJson": latencyToJson,
    "toLatency": toLatency,
    "measurementStateToJson": measurementStateToJson,
    "toMeasurementState": toMeasurementState,
    "msgAcqResultToJson": msgAcqResultToJson,
    "toMsgAcqResult": toMsgAcqResult,
    "msgAcqSvProfileToJson": msgAcqSvProfileToJson,
    "toMsgAcqSvProfile": toMsgAcqSvProfile,
    "msgAgeCorrectionsToJson": msgAgeCorrectionsToJson,
    "toMsgAgeCorrections": toMsgAgeCorrections,
    "msgAlmanacGloToJson": msgAlmanacGloToJson,
    "toMsgAlmanacGlo": toMsgAlmanacGlo,
    "msgAlmanacGPSToJson": msgAlmanacGPSToJson,
    "toMsgAlmanacGPS": toMsgAlmanacGPS,
    "msgAlmanacToJson": msgAlmanacToJson,
    "toMsgAlmanac": toMsgAlmanac,
    "msgAngularRateToJson": msgAngularRateToJson,
    "toMsgAngularRate": toMsgAngularRate,
    "msgBaselineECEFToJson": msgBaselineECEFToJson,
    "toMsgBaselineECEF": toMsgBaselineECEF,
    "msgBaselineHeadingToJson": msgBaselineHeadingToJson,
    "toMsgBaselineHeading": toMsgBaselineHeading,
    "msgBaselineNEDToJson": msgBaselineNEDToJson,
    "toMsgBaselineNED": toMsgBaselineNED,
    "msgBasePosECEFToJson": msgBasePosECEFToJson,
    "toMsgBasePosECEF": toMsgBasePosECEF,
    "msgBasePosLLHToJson": msgBasePosLLHToJson,
    "toMsgBasePosLLH": toMsgBasePosLLH,
    "msgBootloaderHandshakeReqToJson": msgBootloaderHandshakeReqToJson,
    "toMsgBootloaderHandshakeReq": toMsgBootloaderHandshakeReq,
    "msgBootloaderHandshakeRespToJson": msgBootloaderHandshakeRespToJson,
    "toMsgBootloaderHandshakeResp": toMsgBootloaderHandshakeResp,
    "msgBootloaderJumpToAppToJson": msgBootloaderJumpToAppToJson,
    "toMsgBootloaderJumpToApp": toMsgBootloaderJumpToApp,
    "msgCellModemStatusToJson": msgCellModemStatusToJson,
    "toMsgCellModemStatus": toMsgCellModemStatus,
    "msgCommandOutputToJson": msgCommandOutputToJson,
    "toMsgCommandOutput": toMsgCommandOutput,
    "msgCommandReqToJson": msgCommandReqToJson,
    "toMsgCommandReq": toMsgCommandReq,
    "msgCommandRespToJson": msgCommandRespToJson,
    "toMsgCommandResp": toMsgCommandResp,
    "msgCsacTelemetryToJson": msgCsacTelemetryToJson,
    "toMsgCsacTelemetry": toMsgCsacTelemetry,
    "msgCsacTelemetryLabelsToJson": msgCsacTelemetryLabelsToJson,
    "toMsgCsacTelemetryLabels": toMsgCsacTelemetryLabels,
    "msgCwResultsToJson": msgCwResultsToJson,
    "toMsgCwResults": toMsgCwResults,
    "msgCwStartToJson": msgCwStartToJson,
    "toMsgCwStart": toMsgCwStart,
    "msgDeviceMonitorToJson": msgDeviceMonitorToJson,
    "toMsgDeviceMonitor": toMsgDeviceMonitor,
    "msgDgnssStatusToJson": msgDgnssStatusToJson,
    "toMsgDgnssStatus": toMsgDgnssStatus,
    "msgDopsToJson": msgDopsToJson,
    "toMsgDops": toMsgDops,
    "msgEphemerisBdsToJson": msgEphemerisBdsToJson,
    "toMsgEphemerisBds": toMsgEphemerisBds,
    "msgEphemerisGalToJson": msgEphemerisGalToJson,
    "toMsgEphemerisGal": toMsgEphemerisGal,
    "msgEphemerisGloToJson": msgEphemerisGloToJson,
    "toMsgEphemerisGlo": toMsgEphemerisGlo,
    "msgEphemerisGPSToJson": msgEphemerisGPSToJson,
    "toMsgEphemerisGPS": toMsgEphemerisGPS,
    "msgEphemerisQzssToJson": msgEphemerisQzssToJson,
    "toMsgEphemerisQzss": toMsgEphemerisQzss,
    "msgEphemerisSbasToJson": msgEphemerisSbasToJson,
    "toMsgEphemerisSbas": toMsgEphemerisSbas,
    "msgEXTEventToJson": msgEXTEventToJson,
    "toMsgEXTEvent": toMsgEXTEvent,
    "msgFileioConfigReqToJson": msgFileioConfigReqToJson,
    "toMsgFileioConfigReq": toMsgFileioConfigReq,
    "msgFileioConfigRespToJson": msgFileioConfigRespToJson,
    "toMsgFileioConfigResp": toMsgFileioConfigResp,
    "msgFileioReadDirReqToJson": msgFileioReadDirReqToJson,
    "toMsgFileioReadDirReq": toMsgFileioReadDirReq,
    "msgFileioReadDirRespToJson": msgFileioReadDirRespToJson,
    "toMsgFileioReadDirResp": toMsgFileioReadDirResp,
    "msgFileioReadReqToJson": msgFileioReadReqToJson,
    "toMsgFileioReadReq": toMsgFileioReadReq,
    "msgFileioReadRespToJson": msgFileioReadRespToJson,
    "toMsgFileioReadResp": toMsgFileioReadResp,
    "msgFileioRemoveToJson": msgFileioRemoveToJson,
    "toMsgFileioRemove": toMsgFileioRemove,
    "msgFileioWriteReqToJson": msgFileioWriteReqToJson,
    "toMsgFileioWriteReq": toMsgFileioWriteReq,
    "msgFileioWriteRespToJson": msgFileioWriteRespToJson,
    "toMsgFileioWriteResp": toMsgFileioWriteResp,
    "msgFlashDoneToJson": msgFlashDoneToJson,
    "toMsgFlashDone": toMsgFlashDone,
    "msgFlashEraseToJson": msgFlashEraseToJson,
    "toMsgFlashErase": toMsgFlashErase,
    "msgFlashProgramToJson": msgFlashProgramToJson,
    "toMsgFlashProgram": toMsgFlashProgram,
    "msgFlashReadReqToJson": msgFlashReadReqToJson,
    "toMsgFlashReadReq": toMsgFlashReadReq,
    "msgFlashReadRespToJson": msgFlashReadRespToJson,
    "toMsgFlashReadResp": toMsgFlashReadResp,
    "msgFrontEndGainToJson": msgFrontEndGainToJson,
    "toMsgFrontEndGain": toMsgFrontEndGain,
    "msgFwdToJson": msgFwdToJson,
    "toMsgFwd": toMsgFwd,
    "msgGloBiasesToJson": msgGloBiasesToJson,
    "toMsgGloBiases": toMsgGloBiases,
    "msgGnssCapbToJson": msgGnssCapbToJson,
    "toMsgGnssCapb": toMsgGnssCapb,
    "msgGPSTimeToJson": msgGPSTimeToJson,
    "toMsgGPSTime": toMsgGPSTime,
    "msgGroupDelayToJson": msgGroupDelayToJson,
    "toMsgGroupDelay": toMsgGroupDelay,
    "msgHeartbeatToJson": msgHeartbeatToJson,
    "toMsgHeartbeat": toMsgHeartbeat,
    "msgIarStateToJson": msgIarStateToJson,
    "toMsgIarState": toMsgIarState,
    "msgImuAuxToJson": msgImuAuxToJson,
    "toMsgImuAux": toMsgImuAux,
    "msgImuRawToJson": msgImuRawToJson,
    "toMsgImuRaw": toMsgImuRaw,
    "msgInsStatusToJson": msgInsStatusToJson,
    "toMsgInsStatus": toMsgInsStatus,
    "msgIonoToJson": msgIonoToJson,
    "toMsgIono": toMsgIono,
    "msgLinuxCPUStateToJson": msgLinuxCPUStateToJson,
    "toMsgLinuxCPUState": toMsgLinuxCPUState,
    "msgLinuxMemStateToJson": msgLinuxMemStateToJson,
    "toMsgLinuxMemState": toMsgLinuxMemState,
    "msgLinuxProcessFdCountToJson": msgLinuxProcessFdCountToJson,
    "toMsgLinuxProcessFdCount": toMsgLinuxProcessFdCount,
    "msgLinuxProcessFdSummaryToJson": msgLinuxProcessFdSummaryToJson,
    "toMsgLinuxProcessFdSummary": toMsgLinuxProcessFdSummary,
    "msgLinuxProcessSocketCountsToJson": msgLinuxProcessSocketCountsToJson,
    "toMsgLinuxProcessSocketCounts": toMsgLinuxProcessSocketCounts,
    "msgLinuxProcessSocketQueuesToJson": msgLinuxProcessSocketQueuesToJson,
    "toMsgLinuxProcessSocketQueues": toMsgLinuxProcessSocketQueues,
    "msgLinuxSocketUsageToJson": msgLinuxSocketUsageToJson,
    "toMsgLinuxSocketUsage": toMsgLinuxSocketUsage,
    "msgLinuxSysStateToJson": msgLinuxSysStateToJson,
    "toMsgLinuxSysState": toMsgLinuxSysState,
    "msgLogToJson": msgLogToJson,
    "toMsgLog": toMsgLog,
    "msgM25FlashWriteStatusToJson": msgM25FlashWriteStatusToJson,
    "toMsgM25FlashWriteStatus": toMsgM25FlashWriteStatus,
    "msgMagRawToJson": msgMagRawToJson,
    "toMsgMagRaw": toMsgMagRaw,
    "msgMaskSatelliteToJson": msgMaskSatelliteToJson,
    "toMsgMaskSatellite": toMsgMaskSatellite,
    "msgMeasurementStateToJson": msgMeasurementStateToJson,
    "toMsgMeasurementState": toMsgMeasurementState,
    "msgNapDeviceDnaReqToJson": msgNapDeviceDnaReqToJson,
    "toMsgNapDeviceDnaReq": toMsgNapDeviceDnaReq,
    "msgNapDeviceDnaRespToJson": msgNapDeviceDnaRespToJson,
    "toMsgNapDeviceDnaResp": toMsgNapDeviceDnaResp,
    "msgNdbEventToJson": msgNdbEventToJson,
    "toMsgNdbEvent": toMsgNdbEvent,
    "msgNetworkBandwidthUsageToJson": msgNetworkBandwidthUsageToJson,
    "toMsgNetworkBandwidthUsage": toMsgNetworkBandwidthUsage,
    "msgNetworkStateReqToJson": msgNetworkStateReqToJson,
    "toMsgNetworkStateReq": toMsgNetworkStateReq,
    "msgNetworkStateRespToJson": msgNetworkStateRespToJson,
    "toMsgNetworkStateResp": toMsgNetworkStateResp,
    "msgObsToJson": msgObsToJson,
    "toMsgObs": toMsgObs,
    "msgOdometryToJson": msgOdometryToJson,
    "toMsgOdometry": toMsgOdometry,
    "msgOrientEulerToJson": msgOrientEulerToJson,
    "toMsgOrientEuler": toMsgOrientEuler,
    "msgOrientQuatToJson": msgOrientQuatToJson,
    "toMsgOrientQuat": toMsgOrientQuat,
    "msgOsrToJson": msgOsrToJson,
    "toMsgOsr": toMsgOsr,
    "msgPosECEFCovToJson": msgPosECEFCovToJson,
    "toMsgPosECEFCov": toMsgPosECEFCov,
    "msgPosECEFToJson": msgPosECEFToJson,
    "toMsgPosECEF": toMsgPosECEF,
    "msgPosLLHCovToJson": msgPosLLHCovToJson,
    "toMsgPosLLHCov": toMsgPosLLHCov,
    "msgPosLLHToJson": msgPosLLHToJson,
    "toMsgPosLLH": toMsgPosLLH,
    "msgResetFiltersToJson": msgResetFiltersToJson,
    "toMsgResetFilters": toMsgResetFilters,
    "msgResetToJson": msgResetToJson,
    "toMsgReset": toMsgReset,
    "msgSbasRawToJson": msgSbasRawToJson,
    "toMsgSbasRaw": toMsgSbasRaw,
    "msgSetTimeToJson": msgSetTimeToJson,
    "toMsgSetTime": toMsgSetTime,
    "msgSettingsReadByIndexDoneToJson": msgSettingsReadByIndexDoneToJson,
    "toMsgSettingsReadByIndexDone": toMsgSettingsReadByIndexDone,
    "msgSettingsReadByIndexReqToJson": msgSettingsReadByIndexReqToJson,
    "toMsgSettingsReadByIndexReq": toMsgSettingsReadByIndexReq,
    "msgSettingsReadByIndexRespToJson": msgSettingsReadByIndexRespToJson,
    "toMsgSettingsReadByIndexResp": toMsgSettingsReadByIndexResp,
    "msgSettingsReadReqToJson": msgSettingsReadReqToJson,
    "toMsgSettingsReadReq": toMsgSettingsReadReq,
    "msgSettingsReadRespToJson": msgSettingsReadRespToJson,
    "toMsgSettingsReadResp": toMsgSettingsReadResp,
    "msgSettingsRegisterToJson": msgSettingsRegisterToJson,
    "toMsgSettingsRegister": toMsgSettingsRegister,
    "msgSettingsRegisterRespToJson": msgSettingsRegisterRespToJson,
    "toMsgSettingsRegisterResp": toMsgSettingsRegisterResp,
    "msgSettingsSaveToJson": msgSettingsSaveToJson,
    "toMsgSettingsSave": toMsgSettingsSave,
    "msgSettingsWriteToJson": msgSettingsWriteToJson,
    "toMsgSettingsWrite": toMsgSettingsWrite,
    "msgSettingsWriteRespToJson": msgSettingsWriteRespToJson,
    "toMsgSettingsWriteResp": toMsgSettingsWriteResp,
    "msgSpecanToJson": msgSpecanToJson,
    "toMsgSpecan": toMsgSpecan,
    "msgSsrCodeBiasesToJson": msgSsrCodeBiasesToJson,
    "toMsgSsrCodeBiases": toMsgSsrCodeBiases,
    "msgSsrGriddedCorrectionToJson": msgSsrGriddedCorrectionToJson,
    "toMsgSsrGriddedCorrection": toMsgSsrGriddedCorrection,
    "msgSsrGridDefinitionToJson": msgSsrGridDefinitionToJson,
    "toMsgSsrGridDefinition": toMsgSsrGridDefinition,
    "msgSsrOrbitClockToJson": msgSsrOrbitClockToJson,
    "toMsgSsrOrbitClock": toMsgSsrOrbitClock,
    "msgSsrPhaseBiasesToJson": msgSsrPhaseBiasesToJson,
    "toMsgSsrPhaseBiases": toMsgSsrPhaseBiases,
    "msgSsrStecCorrectionToJson": msgSsrStecCorrectionToJson,
    "toMsgSsrStecCorrection": toMsgSsrStecCorrection,
    "msgStartupToJson": msgStartupToJson,
    "toMsgStartup": toMsgStartup,
    "msgStmFlashLockSectorToJson": msgStmFlashLockSectorToJson,
    "toMsgStmFlashLockSector": toMsgStmFlashLockSector,
    "msgStmFlashUnlockSectorToJson": msgStmFlashUnlockSectorToJson,
    "toMsgStmFlashUnlockSector": toMsgStmFlashUnlockSector,
    "msgStmUniqueIDReqToJson": msgStmUniqueIDReqToJson,
    "toMsgStmUniqueIDReq": toMsgStmUniqueIDReq,
    "msgStmUniqueIDRespToJson": msgStmUniqueIDRespToJson,
    "toMsgStmUniqueIDResp": toMsgStmUniqueIDResp,
    "msgSvAzElToJson": msgSvAzElToJson,
    "toMsgSvAzEl": toMsgSvAzEl,
    "msgThreadStateToJson": msgThreadStateToJson,
    "toMsgThreadState": toMsgThreadState,
    "msgTrackingIqToJson": msgTrackingIqToJson,
    "toMsgTrackingIq": toMsgTrackingIq,
    "msgTrackingStateToJson": msgTrackingStateToJson,
    "toMsgTrackingState": toMsgTrackingState,
    "msgUARTStateToJson": msgUARTStateToJson,
    "toMsgUARTState": toMsgUARTState,
    "msgUserDataToJson": msgUserDataToJson,
    "toMsgUserData": toMsgUserData,
    "msgUTCTimeToJson": msgUTCTimeToJson,
    "toMsgUTCTime": toMsgUTCTime,
    "msgVelBodyToJson": msgVelBodyToJson,
    "toMsgVelBody": toMsgVelBody,
    "msgVelECEFCovToJson": msgVelECEFCovToJson,
    "toMsgVelECEFCov": toMsgVelECEFCov,
    "msgVelECEFToJson": msgVelECEFToJson,
    "toMsgVelECEF": toMsgVelECEF,
    "msgVelNEDCovToJson": msgVelNEDCovToJson,
    "toMsgVelNEDCov": toMsgVelNEDCov,
    "msgVelNEDToJson": msgVelNEDToJson,
    "toMsgVelNED": toMsgVelNED,
    "networkUsageToJson": networkUsageToJson,
    "toNetworkUsage": toNetworkUsage,
    "observationHeaderToJson": observationHeaderToJson,
    "toObservationHeader": toObservationHeader,
    "packedObsContentToJson": packedObsContentToJson,
    "toPackedObsContent": toPackedObsContent,
    "packedOsrContentToJson": packedOsrContentToJson,
    "toPackedOsrContent": toPackedOsrContent,
    "periodToJson": periodToJson,
    "toPeriod": toPeriod,
    "phaseBiasesContentToJson": phaseBiasesContentToJson,
    "toPhaseBiasesContent": toPhaseBiasesContent,
    "sTECHeaderToJson": sTECHeaderToJson,
    "toSTECHeader": toSTECHeader,
    "sTECResidualToJson": sTECResidualToJson,
    "toSTECResidual": toSTECResidual,
    "sTECSatElementToJson": sTECSatElementToJson,
    "toSTECSatElement": toSTECSatElement,
    "svAzElToJson": svAzElToJson,
    "toSvAzEl": toSvAzEl,
    "svIDToJson": svIDToJson,
    "toSvID": toSvID,
    "trackingChannelCorrelationToJson": trackingChannelCorrelationToJson,
    "toTrackingChannelCorrelation": toTrackingChannelCorrelation,
    "trackingChannelStateToJson": trackingChannelStateToJson,
    "toTrackingChannelState": toTrackingChannelState,
    "troposphericDelayCorrectionToJson": troposphericDelayCorrectionToJson,
    "toTroposphericDelayCorrection": toTroposphericDelayCorrection,
    "uARTChannelToJson": uARTChannelToJson,
    "toUARTChannel": toUARTChannel,
};
