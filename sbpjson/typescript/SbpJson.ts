// To parse this data:
//
//   import { Convert, AcqSvProfile, AlmanacCommonContent, CarrierPhase, CodeBiasesContent, Doppler, EphemerisCommonContent, EstimatedHorizontalErrorEllipse, GNSSInputType, GnssCapb, GnssSignal, GpsTime, GpsTimeSEC, GridElement, GridElementNoStd, GriddedCorrectionHeader, IMUInputType, Latency, MeasurementState, MsgAcqResult, MsgAcqSvProfile, MsgAgeCorrections, MsgAlmanacGPS, MsgAlmanacGlo, MsgAngularRate, MsgBasePosECEF, MsgBasePosLLH, MsgBaselineECEF, MsgBaselineHeading, MsgBaselineNED, MsgBootloaderHandshakeResp, MsgBootloaderJumpToApp, MsgCellModemStatus, MsgCommandOutput, MsgCommandReq, MsgCommandResp, MsgCsacTelemetry, MsgCsacTelemetryLabels, MsgDeviceMonitor, MsgDgnssStatus, MsgDops, MsgEphemerisBds, MsgEphemerisGPS, MsgEphemerisGal, MsgEphemerisGlo, MsgEphemerisQzss, MsgEphemerisSbas, MsgEXTEvent, MsgFileioConfigReq, MsgFileioConfigResp, MsgFileioReadDirReq, MsgFileioReadDirResp, MsgFileioReadReq, MsgFileioReadResp, MsgFileioRemove, MsgFileioWriteReq, MsgFileioWriteResp, MsgFlashDone, MsgFlashErase, MsgFlashProgram, MsgFlashReadReq, MsgFlashReadResp, MsgFrontEndGain, MsgFwd, MsgGPSTime, MsgGPSTimeGnss, MsgGloBiases, MsgGnssCapb, MsgGnssTimeOffset, MsgGroupDelay, MsgGroupMeta, MsgHeartbeat, MsgIarState, MsgImuAux, MsgImuRaw, MsgInsStatus, MsgInsUpdates, MsgIono, MsgLinuxCPUState, MsgLinuxMemState, MsgLinuxProcessFdCount, MsgLinuxProcessFdSummary, MsgLinuxProcessSocketCounts, MsgLinuxProcessSocketQueues, MsgLinuxSocketUsage, MsgLinuxSysState, MsgLog, MsgM25FlashWriteStatus, MsgMagRaw, MsgMaskSatellite, MsgMeasurementState, MsgNapDeviceDnaResp, MsgNdbEvent, MsgNetworkBandwidthUsage, MsgNetworkStateResp, MsgObs, MsgOdometry, MsgOrientEuler, MsgOrientQuat, MsgOsr, MsgPosECEF, MsgPosECEFCov, MsgPosECEFCovGnss, MsgPosECEFGnss, MsgPosLLH, MsgPosLLHAcc, MsgPosLLHCov, MsgPosLLHCovGnss, MsgPosLLHGnss, MsgPpsTime, MsgProtectionLevel, MsgReset, MsgResetFilters, MsgSbasRaw, MsgSettingsReadByIndexReq, MsgSettingsReadByIndexResp, MsgSettingsReadReq, MsgSettingsReadResp, MsgSettingsRegister, MsgSettingsRegisterResp, MsgSettingsWrite, MsgSettingsWriteResp, MsgSolnMeta, MsgSpecan, MsgSsrCodeBiases, MsgSsrGriddedCorrection, MsgSsrOrbitClock, MsgSsrPhaseBiases, MsgSsrSatelliteApc, MsgSsrStecCorrection, MsgSsrTileDefinition, MsgStartup, MsgStatusReport, MsgStmFlashLockSector, MsgStmFlashUnlockSector, MsgStmUniqueIDResp, MsgSvAzEl, MsgThreadState, MsgTrackingIq, MsgTrackingState, MsgUARTState, MsgUserData, MsgUTCTime, MsgUTCTimeGnss, MsgVelBody, MsgVelECEF, MsgVelECEFCov, MsgVelECEFCovGnss, MsgVelECEFGnss, MsgVelNED, MsgVelNEDCov, MsgVelNEDCovGnss, MsgVelNEDGnss, MsgWheeltick, NetworkUsage, ObservationHeader, OdoInputType, PackedObsContent, PackedOsrContent, Period, PhaseBiasesContent, STECHeader, STECResidual, STECResidualNoStd, STECSatElement, SatelliteAPC, SolutionInputType, SubSystemReport, SvAzEl, SvID, TrackingChannelCorrelation, TrackingChannelState, TroposphericDelayCorrection, TroposphericDelayCorrectionNoStd, UARTChannel } from "./file";
//
//   const acqSvProfile = Convert.toAcqSvProfile(json);
//   const almanacCommonContent = Convert.toAlmanacCommonContent(json);
//   const carrierPhase = Convert.toCarrierPhase(json);
//   const codeBiasesContent = Convert.toCodeBiasesContent(json);
//   const doppler = Convert.toDoppler(json);
//   const ephemerisCommonContent = Convert.toEphemerisCommonContent(json);
//   const estimatedHorizontalErrorEllipse = Convert.toEstimatedHorizontalErrorEllipse(json);
//   const gNSSInputType = Convert.toGNSSInputType(json);
//   const gnssCapb = Convert.toGnssCapb(json);
//   const gnssSignal = Convert.toGnssSignal(json);
//   const gpsTime = Convert.toGpsTime(json);
//   const gpsTimeSEC = Convert.toGpsTimeSEC(json);
//   const gridElement = Convert.toGridElement(json);
//   const gridElementNoStd = Convert.toGridElementNoStd(json);
//   const griddedCorrectionHeader = Convert.toGriddedCorrectionHeader(json);
//   const iMUInputType = Convert.toIMUInputType(json);
//   const latency = Convert.toLatency(json);
//   const measurementState = Convert.toMeasurementState(json);
//   const msgAcqResult = Convert.toMsgAcqResult(json);
//   const msgAcqSvProfile = Convert.toMsgAcqSvProfile(json);
//   const msgAgeCorrections = Convert.toMsgAgeCorrections(json);
//   const msgAlmanac = Convert.toMsgAlmanac(json);
//   const msgAlmanacGPS = Convert.toMsgAlmanacGPS(json);
//   const msgAlmanacGlo = Convert.toMsgAlmanacGlo(json);
//   const msgAngularRate = Convert.toMsgAngularRate(json);
//   const msgBasePosECEF = Convert.toMsgBasePosECEF(json);
//   const msgBasePosLLH = Convert.toMsgBasePosLLH(json);
//   const msgBaselineECEF = Convert.toMsgBaselineECEF(json);
//   const msgBaselineHeading = Convert.toMsgBaselineHeading(json);
//   const msgBaselineNED = Convert.toMsgBaselineNED(json);
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
//   const msgEphemerisGPS = Convert.toMsgEphemerisGPS(json);
//   const msgEphemerisGal = Convert.toMsgEphemerisGal(json);
//   const msgEphemerisGlo = Convert.toMsgEphemerisGlo(json);
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
//   const msgGPSTime = Convert.toMsgGPSTime(json);
//   const msgGPSTimeGnss = Convert.toMsgGPSTimeGnss(json);
//   const msgGloBiases = Convert.toMsgGloBiases(json);
//   const msgGnssCapb = Convert.toMsgGnssCapb(json);
//   const msgGnssTimeOffset = Convert.toMsgGnssTimeOffset(json);
//   const msgGroupDelay = Convert.toMsgGroupDelay(json);
//   const msgGroupMeta = Convert.toMsgGroupMeta(json);
//   const msgHeartbeat = Convert.toMsgHeartbeat(json);
//   const msgIarState = Convert.toMsgIarState(json);
//   const msgImuAux = Convert.toMsgImuAux(json);
//   const msgImuRaw = Convert.toMsgImuRaw(json);
//   const msgInsStatus = Convert.toMsgInsStatus(json);
//   const msgInsUpdates = Convert.toMsgInsUpdates(json);
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
//   const msgPosECEF = Convert.toMsgPosECEF(json);
//   const msgPosECEFCov = Convert.toMsgPosECEFCov(json);
//   const msgPosECEFCovGnss = Convert.toMsgPosECEFCovGnss(json);
//   const msgPosECEFGnss = Convert.toMsgPosECEFGnss(json);
//   const msgPosLLH = Convert.toMsgPosLLH(json);
//   const msgPosLLHAcc = Convert.toMsgPosLLHAcc(json);
//   const msgPosLLHCov = Convert.toMsgPosLLHCov(json);
//   const msgPosLLHCovGnss = Convert.toMsgPosLLHCovGnss(json);
//   const msgPosLLHGnss = Convert.toMsgPosLLHGnss(json);
//   const msgPpsTime = Convert.toMsgPpsTime(json);
//   const msgProtectionLevel = Convert.toMsgProtectionLevel(json);
//   const msgReset = Convert.toMsgReset(json);
//   const msgResetFilters = Convert.toMsgResetFilters(json);
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
//   const msgSolnMeta = Convert.toMsgSolnMeta(json);
//   const msgSpecan = Convert.toMsgSpecan(json);
//   const msgSsrCodeBiases = Convert.toMsgSsrCodeBiases(json);
//   const msgSsrGriddedCorrection = Convert.toMsgSsrGriddedCorrection(json);
//   const msgSsrOrbitClock = Convert.toMsgSsrOrbitClock(json);
//   const msgSsrPhaseBiases = Convert.toMsgSsrPhaseBiases(json);
//   const msgSsrSatelliteApc = Convert.toMsgSsrSatelliteApc(json);
//   const msgSsrStecCorrection = Convert.toMsgSsrStecCorrection(json);
//   const msgSsrTileDefinition = Convert.toMsgSsrTileDefinition(json);
//   const msgStartup = Convert.toMsgStartup(json);
//   const msgStatusReport = Convert.toMsgStatusReport(json);
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
//   const msgUTCTimeGnss = Convert.toMsgUTCTimeGnss(json);
//   const msgVelBody = Convert.toMsgVelBody(json);
//   const msgVelECEF = Convert.toMsgVelECEF(json);
//   const msgVelECEFCov = Convert.toMsgVelECEFCov(json);
//   const msgVelECEFCovGnss = Convert.toMsgVelECEFCovGnss(json);
//   const msgVelECEFGnss = Convert.toMsgVelECEFGnss(json);
//   const msgVelNED = Convert.toMsgVelNED(json);
//   const msgVelNEDCov = Convert.toMsgVelNEDCov(json);
//   const msgVelNEDCovGnss = Convert.toMsgVelNEDCovGnss(json);
//   const msgVelNEDGnss = Convert.toMsgVelNEDGnss(json);
//   const msgWheeltick = Convert.toMsgWheeltick(json);
//   const networkUsage = Convert.toNetworkUsage(json);
//   const observationHeader = Convert.toObservationHeader(json);
//   const odoInputType = Convert.toOdoInputType(json);
//   const packedObsContent = Convert.toPackedObsContent(json);
//   const packedOsrContent = Convert.toPackedOsrContent(json);
//   const period = Convert.toPeriod(json);
//   const phaseBiasesContent = Convert.toPhaseBiasesContent(json);
//   const sTECHeader = Convert.toSTECHeader(json);
//   const sTECResidual = Convert.toSTECResidual(json);
//   const sTECResidualNoStd = Convert.toSTECResidualNoStd(json);
//   const sTECSatElement = Convert.toSTECSatElement(json);
//   const satelliteAPC = Convert.toSatelliteAPC(json);
//   const solutionInputType = Convert.toSolutionInputType(json);
//   const subSystemReport = Convert.toSubSystemReport(json);
//   const svAzEl = Convert.toSvAzEl(json);
//   const svID = Convert.toSvID(json);
//   const trackingChannelCorrelation = Convert.toTrackingChannelCorrelation(json);
//   const trackingChannelState = Convert.toTrackingChannelState(json);
//   const troposphericDelayCorrection = Convert.toTroposphericDelayCorrection(json);
//   const troposphericDelayCorrectionNoStd = Convert.toTroposphericDelayCorrectionNoStd(json);
//   const uARTChannel = Convert.toUARTChannel(json);
//
// These functions will throw an error if the JSON doesn't
// match the expected interface, even if the JSON is valid.

/**
 * Metadata around the GNSS sensors involved in the fuzed solution. Accessible through
 * sol_in[N].flags in a MSG_SOLN_META.
 */
export interface GNSSInputType {
    flags: number;
}

/**
 * Contains one tropo delay, plus STEC residuals for each satellite at the grid point.
 */
export interface GridElementNoStd {
    index:                  number;
    stec_residuals:         STECResidualNoStd[];
    tropo_delay_correction: TroposphericDelayCorrectionNoStd;
}

/**
 * STEC residual for the given satellite at the grid point.
 */
export interface STECResidualNoStd {
    residual: number;
    sv_id:    SvID;
}

/**
 * A (Constellation ID, satellite ID) tuple that uniquely identifies a space vehicle.
 */
export interface SvID {
    constellation: number;
    satId:         number;
}

/**
 * Troposphere vertical delays at the grid point.
 */
export interface TroposphericDelayCorrectionNoStd {
    hydro: number;
    wet:   number;
}

/**
 * Metadata around the IMU sensors involved in the fuzed solution. Accessible through
 * sol_in[N].flags in a MSG_SOLN_META.
 */
export interface IMUInputType {
    flags: number;
}

/**
 * This message describes the results from an attempted GPS signal acquisition search for a
 * satellite PRN over a code phase/carrier frequency range. It contains the parameters of
 * the point in the acquisition search space with the best carrier-to-noise (CN/0) ratio.
 */
export interface MsgAcqResult {
    cf:  number;
    cn0: number;
    cp:  number;
    sid: GnssSignal;
}

/**
 * Signal identifier containing constellation, band, and satellite identifier.
 */
export interface GnssSignal {
    code: number;
    sat:  number;
}

/**
 * The message describes all SV profiles during acquisition time. The message is used to
 * debug and measure the performance.
 */
export interface MsgAcqSvProfile {
    acq_sv_profile: AcqSvProfile[];
}

/**
 * Profile for a specific SV for debugging purposes. The message describes SV profile during
 * acquisition time. The message is used to debug and measure the performance.
 */
export interface AcqSvProfile {
    bin_width:  number;
    cf:         number;
    cf_max:     number;
    cf_min:     number;
    cn0:        number;
    cp:         number;
    int_time:   number;
    job_type:   number;
    sid:        GnssSignal;
    status:     number;
    time_spent: number;
    timestamp:  number;
}

/**
 * This message reports the Age of the corrections used for the current Differential
 * solution.
 */
export interface MsgAgeCorrections {
    age: number;
    tow: number;
}

/**
 * The almanac message returns a set of satellite orbit parameters. Almanac data is not very
 * precise and is considered valid for up to several months. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data)
 * for more details.
 */
export interface MsgAlmanacGPS {
    af0:      number;
    af1:      number;
    common:   AlmanacCommonContent;
    ecc:      number;
    inc:      number;
    m0:       number;
    omega0:   number;
    omegadot: number;
    sqrta:    number;
    w:        number;
}

export interface AlmanacCommonContent {
    fit_interval: number;
    health_bits:  number;
    sid:          GnssSignal;
    toa:          GpsTimeSEC;
    ura:          number;
    valid:        number;
}

/**
 * A GPS time, defined as the number of seconds since beginning of the week on the
 * Saturday/Sunday transition.
 */
export interface GpsTimeSEC {
    tow: number;
    wn:  number;
}

/**
 * The almanac message returns a set of satellite orbit parameters. Almanac data is not very
 * precise and is considered valid for up to several months. Please see the GLO ICD 5.1
 * "Chapter 4.5 Non-immediate information and almanac" for details.
 */
export interface MsgAlmanacGlo {
    common:      AlmanacCommonContent;
    epsilon:     number;
    i:           number;
    lambda_na:   number;
    omega:       number;
    t:           number;
    t_dot:       number;
    t_lambda_na: number;
}

/**
 * This message reports the orientation rates in the vehicle body frame. The values
 * represent the measurements a strapped down gyroscope would make and are not equivalent to
 * the time derivative of the Euler angles. The orientation and origin of the user frame is
 * specified via device settings. By convention, the vehicle x-axis is expected to be
 * aligned with the forward direction, while the vehicle y-axis is expected to be aligned
 * with the right direction, and the vehicle z-axis should be aligned with the down
 * direction. This message will only be available in future INS versions of Swift Products
 * and is not produced by Piksi Multi or Duro.
 */
export interface MsgAngularRate {
    flags: number;
    tow:   number;
    x:     number;
    y:     number;
    z:     number;
}

/**
 * The base station position message is the position reported by the base station itself in
 * absolute Earth Centered Earth Fixed coordinates. It is used for pseudo-absolute RTK
 * positioning, and is required to be a high-accuracy surveyed location of the base station.
 * Any error here will result in an error in the pseudo-absolute position output.
 */
export interface MsgBasePosECEF {
    x: number;
    y: number;
    z: number;
}

/**
 * The base station position message is the position reported by the base station itself. It
 * is used for pseudo-absolute RTK positioning, and is required to be a high-accuracy
 * surveyed location of the base station. Any error here will result in an error in the
 * pseudo-absolute position output.
 */
export interface MsgBasePosLLH {
    height: number;
    lat:    number;
    lon:    number;
}

/**
 * This message reports the baseline solution in Earth Centered Earth Fixed (ECEF)
 * coordinates. This baseline is the relative vector distance from the base station to the
 * rover receiver. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
export interface MsgBaselineECEF {
    accuracy: number;
    flags:    number;
    n_sats:   number;
    tow:      number;
    x:        number;
    y:        number;
    z:        number;
}

/**
 * This message reports the baseline heading pointing from the base station to the rover
 * relative to True North. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow). It is intended that time-matched RTK mode is used when the
 * base station is moving.
 */
export interface MsgBaselineHeading {
    flags:   number;
    heading: number;
    n_sats:  number;
    tow:     number;
}

/**
 * This message reports the baseline solution in North East Down (NED) coordinates. This
 * baseline is the relative vector distance from the base station to the rover receiver, and
 * NED coordinate system is defined at the local WGS84 tangent plane centered at the base
 * station position.  The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
export interface MsgBaselineNED {
    d:          number;
    e:          number;
    flags:      number;
    h_accuracy: number;
    n:          number;
    n_sats:     number;
    tow:        number;
    v_accuracy: number;
}

/**
 * The handshake message response from the device establishes a handshake between the device
 * bootloader and the host. The request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The
 * payload contains the bootloader version number and the SBP protocol version number.
 */
export interface MsgBootloaderHandshakeResp {
    flags:   number;
    version: string;
}

/**
 * The host initiates the bootloader to jump to the application.
 */
export interface MsgBootloaderJumpToApp {
    jump: number;
}

/**
 * If a cell modem is present on a piksi device, this message will be send periodically to
 * update the host on the status of the modem and its various parameters.
 */
export interface MsgCellModemStatus {
    signal_error_rate: number;
    signal_strength:   number;
}

/**
 * Returns the standard output and standard error of the command requested by
 * MSG_COMMAND_REQ. The sequence number can be used to filter for filtering the correct
 * command.
 */
export interface MsgCommandOutput {
    line:     string;
    sequence: number;
}

/**
 * Request the recipient to execute an command. Output will be sent in MSG_LOG messages, and
 * the exit code will be returned with MSG_COMMAND_RESP.
 */
export interface MsgCommandReq {
    command:  string;
    sequence: number;
}

/**
 * The response to MSG_COMMAND_REQ with the return code of the command.  A return code of
 * zero indicates success.
 */
export interface MsgCommandResp {
    code:     number;
    sequence: number;
}

/**
 * The CSAC telemetry message has an implementation defined telemetry string from a device.
 * It is not produced or available on general Swift Products. It is intended to be a low
 * rate message for status purposes.
 */
export interface MsgCsacTelemetry {
    id:        number;
    telemetry: string;
}

/**
 * The CSAC telemetry message provides labels for each member of the string produced by
 * MSG_CSAC_TELEMETRY. It should be provided by a device at a lower rate than the
 * MSG_CSAC_TELEMETRY.
 */
export interface MsgCsacTelemetryLabels {
    id:               number;
    telemetry_labels: string;
}

/**
 * This message contains temperature and voltage level measurements from the processor's
 * monitoring system and the RF frontend die temperature if available.
 */
export interface MsgDeviceMonitor {
    cpu_temperature: number;
    cpu_vaux:        number;
    cpu_vint:        number;
    dev_vin:         number;
    fe_temperature:  number;
}

/**
 * This message provides information about the receipt of Differential corrections.  It is
 * expected to be sent with each receipt of a complete corrections packet.
 */
export interface MsgDgnssStatus {
    flags:       number;
    latency:     number;
    num_signals: number;
    source:      string;
}

/**
 * This dilution of precision (DOP) message describes the effect of navigation satellite
 * geometry on positional measurement precision.  The flags field indicated whether the DOP
 * reported corresponds to differential or SPP solution.
 */
export interface MsgDops {
    flags: number;
    gdop:  number;
    hdop:  number;
    pdop:  number;
    tdop:  number;
    tow:   number;
    vdop:  number;
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that is used to
 * calculate BDS satellite position, velocity, and clock offset. Please see the BeiDou
 * Navigation Satellite System SIS-ICD Version 2.1, Table 5-9 for more details.
 */
export interface MsgEphemerisBds {
    af0:      number;
    af1:      number;
    af2:      number;
    c_ic:     number;
    c_is:     number;
    c_rc:     number;
    c_rs:     number;
    c_uc:     number;
    c_us:     number;
    common:   EphemerisCommonContent;
    dn:       number;
    ecc:      number;
    inc:      number;
    inc_dot:  number;
    iodc:     number;
    iode:     number;
    m0:       number;
    omega0:   number;
    omegadot: number;
    sqrta:    number;
    tgd1:     number;
    tgd2:     number;
    toc:      GpsTimeSEC;
    w:        number;
}

export interface EphemerisCommonContent {
    fit_interval: number;
    health_bits:  number;
    sid:          GnssSignal;
    toe:          GpsTimeSEC;
    ura:          number;
    valid:        number;
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that is used to
 * calculate GPS satellite position, velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table 20-III) for more details.
 */
export interface MsgEphemerisGPS {
    af0:      number;
    af1:      number;
    af2:      number;
    c_ic:     number;
    c_is:     number;
    c_rc:     number;
    c_rs:     number;
    c_uc:     number;
    c_us:     number;
    common:   EphemerisCommonContent;
    dn:       number;
    ecc:      number;
    inc:      number;
    inc_dot:  number;
    iodc:     number;
    iode:     number;
    m0:       number;
    omega0:   number;
    omegadot: number;
    sqrta:    number;
    tgd:      number;
    toc:      GpsTimeSEC;
    w:        number;
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that is used to
 * calculate Galileo satellite position, velocity, and clock offset. Please see the Signal
 * In Space ICD OS SIS ICD, Issue 1.3, December 2016 for more details.
 */
export interface MsgEphemerisGal {
    af0:       number;
    af1:       number;
    af2:       number;
    bgd_e1e5a: number;
    bgd_e1e5b: number;
    c_ic:      number;
    c_is:      number;
    c_rc:      number;
    c_rs:      number;
    c_uc:      number;
    c_us:      number;
    common:    EphemerisCommonContent;
    dn:        number;
    ecc:       number;
    inc:       number;
    inc_dot:   number;
    iodc:      number;
    iode:      number;
    m0:        number;
    omega0:    number;
    omegadot:  number;
    source:    number;
    sqrta:     number;
    toc:       GpsTimeSEC;
    w:         number;
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that is used to
 * calculate GLO satellite position, velocity, and clock offset. Please see the GLO ICD 5.1
 * "Table 4.5 Characteristics of words of immediate information (ephemeris parameters)" for
 * more details.
 */
export interface MsgEphemerisGlo {
    acc:    number[];
    common: EphemerisCommonContent;
    d_tau:  number;
    fcn:    number;
    gamma:  number;
    iod:    number;
    pos:    number[];
    tau:    number;
    vel:    number[];
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that is used to
 * calculate QZSS satellite position, velocity, and clock offset.
 */
export interface MsgEphemerisQzss {
    af0:      number;
    af1:      number;
    af2:      number;
    c_ic:     number;
    c_is:     number;
    c_rc:     number;
    c_rs:     number;
    c_uc:     number;
    c_us:     number;
    common:   EphemerisCommonContent;
    dn:       number;
    ecc:      number;
    inc:      number;
    inc_dot:  number;
    iodc:     number;
    iode:     number;
    m0:       number;
    omega0:   number;
    omegadot: number;
    sqrta:    number;
    tgd:      number;
    toc:      GpsTimeSEC;
    w:        number;
}

export interface MsgEphemerisSbas {
    a_gf0:  number;
    a_gf1:  number;
    acc:    number[];
    common: EphemerisCommonContent;
    pos:    number[];
    vel:    number[];
}

/**
 * Reports detection of an external event, the GPS time it occurred, which pin it was and
 * whether it was rising or falling.
 */
export interface MsgEXTEvent {
    flags:       number;
    ns_residual: number;
    pin:         number;
    tow:         number;
    wn:          number;
}

/**
 * Requests advice on the optimal configuration for a FileIO transfer.  Newer version of
 * FileIO can support greater throughput by supporting a large window of FileIO data that
 * can be in-flight during read or write operations.
 */
export interface MsgFileioConfigReq {
    sequence: number;
}

/**
 * The advice on the optimal configuration for a FileIO transfer.  Newer version of FileIO
 * can support greater throughput by supporting a large window of FileIO data that can be
 * in-flight during read or write operations.
 */
export interface MsgFileioConfigResp {
    batch_size:     number;
    fileio_version: number;
    sequence:       number;
    window_size:    number;
}

/**
 * The read directory message lists the files in a directory on the device's onboard flash
 * file system.  The offset parameter can be used to skip the first n elements of the file
 * list. Returns a MSG_FILEIO_READ_DIR_RESP message containing the directory listings as a
 * NULL delimited list. The listing is chunked over multiple SBP packets. The sequence
 * number in the request will be returned in the response.  If message is invalid, a
 * followup MSG_PRINT message will print "Invalid fileio read message". A device will only
 * respond to this message when it is received from sender ID 0x42.
 */
export interface MsgFileioReadDirReq {
    dirname:  string;
    offset:   number;
    sequence: number;
}

/**
 * The read directory message lists the files in a directory on the device's onboard flash
 * file system. Message contains the directory listings as a NULL delimited list. The
 * listing is chunked over multiple SBP packets and the end of the list is identified by an
 * packet with no entries. The sequence number in the response is preserved from the request.
 */
export interface MsgFileioReadDirResp {
    contents: number[];
    sequence: number;
}

/**
 * The file read message reads a certain length (up to 255 bytes) from a given offset into a
 * file, and returns the data in a MSG_FILEIO_READ_RESP message where the message length
 * field indicates how many bytes were successfully read.The sequence number in the request
 * will be returned in the response. If the message is invalid, a followup MSG_PRINT message
 * will print "Invalid fileio read message". A device will only respond to this message when
 * it is received from sender ID 0x42.
 */
export interface MsgFileioReadReq {
    chunk_size: number;
    filename:   string;
    offset:     number;
    sequence:   number;
}

/**
 * The file read message reads a certain length (up to 255 bytes) from a given offset into a
 * file, and returns the data in a message where the message length field indicates how many
 * bytes were successfully read. The sequence number in the response is preserved from the
 * request.
 */
export interface MsgFileioReadResp {
    contents: number[];
    sequence: number;
}

/**
 * The file remove message deletes a file from the file system. If the message is invalid, a
 * followup MSG_PRINT message will print "Invalid fileio remove message". A device will only
 * process this message when it is received from sender ID 0x42.
 */
export interface MsgFileioRemove {
    filename: string;
}

/**
 * The file write message writes a certain length (up to 255 bytes) of data to a file at a
 * given offset. Returns a copy of the original MSG_FILEIO_WRITE_RESP message to check
 * integrity of the write. The sequence number in the request will be returned in the
 * response. If message is invalid, a followup MSG_PRINT message will print "Invalid fileio
 * write message". A device will only process this message when it is received from sender
 * ID 0x42.
 */
export interface MsgFileioWriteReq {
    data:     number[];
    filename: string;
    offset:   number;
    sequence: number;
}

/**
 * The file write message writes a certain length (up to 255 bytes) of data to a file at a
 * given offset. The message is a copy of the original MSG_FILEIO_WRITE_REQ message to check
 * integrity of the write. The sequence number in the response is preserved from the request.
 */
export interface MsgFileioWriteResp {
    sequence: number;
}

/**
 * This message defines success or failure codes for a variety of flash memory requests from
 * the host to the device. Flash read and write messages, such as MSG_FLASH_READ_REQ, or
 * MSG_FLASH_PROGRAM, may return this message on failure.
 */
export interface MsgFlashDone {
    response: number;
}

/**
 * The flash erase message from the host erases a sector of either the STM or M25 onboard
 * flash memory. The device will reply with a MSG_FLASH_DONE message containing the return
 * code - FLASH_OK (0) on success or FLASH_INVALID_FLASH (1) if the flash specified is
 * invalid.
 */
export interface MsgFlashErase {
    sector_num: number;
    target:     number;
}

/**
 * The flash program message programs a set of addresses of either the STM or M25 flash. The
 * device replies with either a MSG_FLASH_DONE message containing the return code FLASH_OK
 * (0) on success, or FLASH_INVALID_LEN (2) if the maximum write size is exceeded. Note that
 * the sector-containing addresses must be erased before addresses can be programmed.
 */
export interface MsgFlashProgram {
    addr_len:   number;
    addr_start: number[];
    data:       number[];
    target:     number;
}

/**
 * The flash read message reads a set of addresses of either the STM or M25 onboard flash.
 * The device replies with a MSG_FLASH_READ_RESP message containing either the read data on
 * success or a MSG_FLASH_DONE message containing the return code FLASH_INVALID_LEN (2) if
 * the maximum read size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
 * the allowed range.
 */
export interface MsgFlashReadReq {
    addr_len:   number;
    addr_start: number[];
    target:     number;
}

/**
 * The flash read message reads a set of addresses of either the STM or M25 onboard flash.
 * The device replies with a MSG_FLASH_READ_RESP message containing either the read data on
 * success or a MSG_FLASH_DONE message containing the return code FLASH_INVALID_LEN (2) if
 * the maximum read size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
 * the allowed range.
 */
export interface MsgFlashReadResp {
    addr_len:   number;
    addr_start: number[];
    target:     number;
}

/**
 * This message describes the gain of each channel in the receiver frontend. Each gain is
 * encoded as a non-dimensional percentage relative to the maximum range possible for the
 * gain stage of the frontend. By convention, each gain array has 8 entries and the index of
 * the array corresponding to the index of the rf channel in the frontend. A gain of 127
 * percent encodes that rf channel is not present in the hardware. A negative value implies
 * an error for the particular gain stage as reported by the frontend.
 */
export interface MsgFrontEndGain {
    if_gain: number[];
    rf_gain: number[];
}

/**
 * This message provides the ability to forward messages over SBP.  This may take the form
 * of wrapping up SBP messages received by Piksi for logging purposes or wrapping another
 * protocol with SBP.,
 * ,
 * The source identifier indicates from what interface a forwarded stream derived. The
 * protocol identifier identifies what the expected protocol the forwarded msg contains.
 * Protocol 0 represents SBP and the remaining values are implementation defined.
 */
export interface MsgFwd {
    fwd_payload: number[];
    protocol:    number;
    source:      number;
}

/**
 * This message reports the GPS time, representing the time since the GPS epoch began on
 * midnight January 6, 1980 UTC. GPS time counts the weeks and seconds of the week. The
 * weeks begin at the Saturday/Sunday transition. GPS week 0 began at the beginning of the
 * GPS time scale.,
 * ,
 * Within each week number, the GPS time of the week is between between 0 and 604800 seconds
 * (=60*60*24*7). Note that GPS time does not accumulate leap seconds, and as of now, has a
 * small offset from UTC. In a message stream, this message precedes a set of other
 * navigation messages referenced to the same time (but lacking the ns field) and indicates
 * a more precise time of these messages.
 */
export interface MsgGPSTime {
    flags:       number;
    ns_residual: number;
    tow:         number;
    wn:          number;
}

/**
 * This message reports the GPS time, representing the time since the GPS epoch began on
 * midnight January 6, 1980 UTC. GPS time counts the weeks and seconds of the week. The
 * weeks begin at the Saturday/Sunday transition. GPS week 0 began at the beginning of the
 * GPS time scale.,
 * ,
 * Within each week number, the GPS time of the week is between between 0 and 604800 seconds
 * (=60*60*24*7). Note that GPS time does not accumulate leap seconds, and as of now, has a
 * small offset from UTC. In a message stream, this message precedes a set of other
 * navigation messages referenced to the same time (but lacking the ns field) and indicates
 * a more precise time of these messages.
 */
export interface MsgGPSTimeGnss {
    flags:       number;
    ns_residual: number;
    tow:         number;
    wn:          number;
}

/**
 * The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS integer ambiguity
 * resolution for baselines with mixed receiver types (e.g. receiver of different
 * manufacturers).
 */
export interface MsgGloBiases {
    l1ca_bias: number;
    l1p_bias:  number;
    l2ca_bias: number;
    l2p_bias:  number;
    mask:      number;
}

export interface MsgGnssCapb {
    gc:     GnssCapb;
    t_nmct: GpsTimeSEC;
}

export interface GnssCapb {
    bds_active:  number;
    bds_b2:      number;
    bds_b2a:     number;
    bds_d2nav:   number;
    gal_active:  number;
    gal_e5:      number;
    glo_active:  number;
    glo_l2of:    number;
    glo_l3:      number;
    gps_active:  number;
    gps_l2c:     number;
    gps_l5:      number;
    qzss_active: number;
    sbas_active: number;
    sbas_l5:     number;
}

/**
 * The GNSS time offset message contains the information that is needed to translate
 * messages tagged with a local timestamp (e.g. IMU or wheeltick messages) to GNSS time for
 * the sender producing this message.
 */
export interface MsgGnssTimeOffset {
    flags:        number;
    microseconds: number;
    milliseconds: number;
    weeks:        number;
}

/**
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
export interface MsgGroupDelay {
    isc_l1ca: number;
    isc_l2c:  number;
    sid:      GnssSignal;
    t_op:     GpsTimeSEC;
    tgd:      number;
    valid:    number;
}

/**
 * This leading message lists the time metadata of the Solution Group. It also lists the
 * atomic contents (i.e. types of messages included) of the Solution Group.
 */
export interface MsgGroupMeta {
    flags:        number;
    group_id:     number;
    group_msgs:   number[];
    n_group_msgs: number;
}

/**
 * The heartbeat message is sent periodically to inform the host or other attached devices
 * that the system is running. It is used to monitor system malfunctions. It also contains
 * status flags that indicate to the host the status of the system and whether it is
 * operating correctly. Currently, the expected heartbeat interval is 1 sec.,
 * ,
 * The system error flag is used to indicate that an error has occurred in the system. To
 * determine the source of the error, the remaining error flags should be inspected.
 */
export interface MsgHeartbeat {
    flags: number;
}

/**
 * This message reports the state of the Integer Ambiguity Resolution (IAR) process, which
 * resolves unknown integer ambiguities from double-differenced carrier-phase measurements
 * from satellite observations.
 */
export interface MsgIarState {
    num_hyps: number;
}

/**
 * Auxiliary data specific to a particular IMU. The `imu_type` field will always be
 * consistent but the rest of the payload is device specific and depends on the value of
 * `imu_type`.
 */
export interface MsgImuAux {
    imu_conf: number;
    imu_type: number;
    temp:     number;
}

/**
 * Raw data from the Inertial Measurement Unit, containing accelerometer and gyroscope
 * readings. The sense of the measurements are to be aligned with the indications on the
 * device itself. Measurement units, which are specific to the device hardware and settings,
 * are communicated via the MSG_IMU_AUX message. If using "time since startup" time tags,
 * the receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available
 * to synchronise IMU measurements with GNSS. The timestamp must wrap around to zero when
 * reaching one week (604800 seconds).,
 * ,
 * The time-tagging mode should not change throughout a run.
 */
export interface MsgImuRaw {
    acc_x: number;
    acc_y: number;
    acc_z: number;
    gyr_x: number;
    gyr_y: number;
    gyr_z: number;
    tow:   number;
    tow_f: number;
}

/**
 * The INS status message describes the state of the operation and initialization of the
 * inertial navigation system.
 */
export interface MsgInsStatus {
    flags: number;
}

/**
 * The INS update status message contains information about executed and rejected INS
 * updates. This message is expected to be extended in the future as new types of
 * measurements are being added.
 */
export interface MsgInsUpdates {
    gnsspos:    number;
    gnssvel:    number;
    nhc:        number;
    speed:      number;
    tow:        number;
    wheelticks: number;
    zerovel:    number;
}

/**
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user to utilize the
 * ionospheric model for computation of the ionospheric delay. Please see ICD-GPS-200
 * (Chapter 20.3.3.5.1.7) for more details.
 */
export interface MsgIono {
    a0:     number;
    a1:     number;
    a2:     number;
    a3:     number;
    b0:     number;
    b1:     number;
    b2:     number;
    b3:     number;
    t_nmct: GpsTimeSEC;
}

/**
 * This message indicates the process state of the top 10 heaviest consumers of CPU on the
 * system, including a timestamp.
 */
export interface MsgLinuxCPUState {
    cmdline: string;
    flags:   number;
    index:   number;
    pcpu:    number;
    pid:     number;
    time:    number;
    tname:   string;
}

/**
 * This message indicates the process state of the top 10 heaviest consumers of memory on
 * the system, including a timestamp.
 */
export interface MsgLinuxMemState {
    cmdline: string;
    flags:   number;
    index:   number;
    pid:     number;
    pmem:    number;
    time:    number;
    tname:   string;
}

/**
 * Top 10 list of processes with a large number of open file descriptors.
 */
export interface MsgLinuxProcessFdCount {
    cmdline:  string;
    fd_count: number;
    index:    number;
    pid:      number;
}

/**
 * Summary of open file descriptors on the system.
 */
export interface MsgLinuxProcessFdSummary {
    most_opened:  string;
    sys_fd_count: number;
}

/**
 * Top 10 list of processes with high socket counts.
 */
export interface MsgLinuxProcessSocketCounts {
    cmdline:       string;
    index:         number;
    pid:           number;
    socket_count:  number;
    socket_states: number;
    socket_types:  number;
}

/**
 * Top 10 list of sockets with deep queues.
 */
export interface MsgLinuxProcessSocketQueues {
    address_of_largest: string;
    cmdline:            string;
    index:              number;
    pid:                number;
    recv_queued:        number;
    send_queued:        number;
    socket_states:      number;
    socket_types:       number;
}

/**
 * Summaries the socket usage across the system.
 */
export interface MsgLinuxSocketUsage {
    avg_queue_depth:     number;
    max_queue_depth:     number;
    socket_state_counts: number[];
    socket_type_counts:  number[];
}

/**
 * This presents a summary of CPU and memory utilization, including a timestamp.
 */
export interface MsgLinuxSysState {
    flags:          number;
    mem_total:      number;
    pcpu:           number;
    pid_count:      number;
    pmem:           number;
    procs_starting: number;
    procs_stopping: number;
    time:           number;
}

/**
 * This message contains a human-readable payload string from the device containing errors,
 * warnings and informational messages at ERROR, WARNING, DEBUG, INFO logging levels.
 */
export interface MsgLog {
    level: number;
    text:  string;
}

/**
 * The flash status message writes to the 8-bit M25 flash status register. The device
 * replies with a MSG_FLASH_DONE message.
 */
export interface MsgM25FlashWriteStatus {
    status: number[];
}

/**
 * Raw data from the magnetometer.
 */
export interface MsgMagRaw {
    mag_x: number;
    mag_y: number;
    mag_z: number;
    tow:   number;
    tow_f: number;
}

/**
 * This message allows setting a mask to prevent a particular satellite from being used in
 * various Piksi subsystems.
 */
export interface MsgMaskSatellite {
    mask: number;
    sid:  GnssSignal;
}

/**
 * The tracking message returns a variable-length array of tracking channel states. It
 * reports status and carrier-to-noise density measurements for all tracked satellites.
 */
export interface MsgMeasurementState {
    states: MeasurementState[];
}

/**
 * Measurement Engine tracking channel state for a specific satellite signal and measured
 * signal power. The mesid field for Glonass can either carry the FCN as 100 + FCN where FCN
 * is in [-7, +6] or the Slot ID (from 1 to 28).
 */
export interface MeasurementState {
    cn0:   number;
    mesid: GnssSignal;
}

/**
 * The device message from the host reads a unique device identifier from the SwiftNAP, an
 * FPGA. The host requests the ID by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
 * responds with a MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
 * that this ID is tied to the FPGA, and not related to the Piksi's serial number.
 */
export interface MsgNapDeviceDnaResp {
    dna: number[];
}

/**
 * This message is sent out when an object is stored into NDB. If needed message could also
 * be sent out when fetching an object from NDB.
 */
export interface MsgNdbEvent {
    data_source:     number;
    event:           number;
    object_sid:      GnssSignal;
    object_type:     number;
    original_sender: number;
    recv_time:       number;
    result:          number;
    src_sid:         GnssSignal;
}

/**
 * The bandwidth usage, a list of usage by interface.
 */
export interface MsgNetworkBandwidthUsage {
    interfaces: NetworkUsage[];
}

/**
 * The bandwidth usage for each interface can be reported within this struct and utilize
 * multiple fields to fully specify the type of traffic that is being tracked. As either the
 * interval of collection or the collection time may vary, both a timestamp and period field
 * is provided, though may not necessarily be populated with a value.
 */
export interface NetworkUsage {
    duration:       number;
    interface_name: string;
    rx_bytes:       number;
    total_bytes:    number;
    tx_bytes:       number;
}

/**
 * The state of a network interface on the Piksi. Data is made to reflect output of ifaddrs
 * struct returned by getifaddrs in c.
 */
export interface MsgNetworkStateResp {
    flags:          number;
    interface_name: string;
    ipv4_address:   number[];
    ipv4_mask_size: number;
    ipv6_address:   number[];
    ipv6_mask_size: number;
    rx_bytes:       number;
    tx_bytes:       number;
}

/**
 * The GPS observations message reports all the raw pseudorange and carrier phase
 * observations for the satellites being tracked by the device. Carrier phase observation
 * here is represented as a 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles). The observations are be interoperable with
 * 3rd party receivers and conform with typical RTCMv3 GNSS observations.
 */
export interface MsgObs {
    header: ObservationHeader;
    obs:    PackedObsContent[];
}

/**
 * Header of a GNSS observation message.
 */
export interface ObservationHeader {
    n_obs: number;
    t:     GpsTime;
}

/**
 * A wire-appropriate receiver clock time, defined as the time since the beginning of the
 * week on the Saturday/Sunday transition. In most cases, observations are epoch aligned so
 * ns field will be 0.
 */
export interface GpsTime {
    ns_residual: number;
    tow:         number;
    wn:          number;
}

/**
 * Pseudorange and carrier phase observation for a satellite being tracked. The observations
 * are interoperable with 3rd party receivers and conform with typical RTCM 3.1 message
 * GPS/GLO observations.,
 * ,
 * Carrier phase observations are not guaranteed to be aligned to the RINEX 3 or RTCM 3.3
 * MSM reference signal and no 1/4 cycle adjustments are currently performed.
 */
export interface PackedObsContent {
    cn0:   number;
    D:     Doppler;
    flags: number;
    L:     CarrierPhase;
    lock:  number;
    P:     number;
    sid:   GnssSignal;
}

/**
 * Doppler measurement in Hz represented as a 24-bit fixed point number with Q16.8 layout,
 * i.e. 16-bits of whole doppler and 8-bits of fractional doppler. This doppler is defined
 * as positive for approaching satellites.
 */
export interface Doppler {
    f: number;
    i: number;
}

/**
 * Carrier phase measurement in cycles represented as a 40-bit fixed point number with Q32.8
 * layout, i.e. 32-bits of whole cycles and 8-bits of fractional cycles. This phase has the
 * same sign as the pseudorange.
 */
export interface CarrierPhase {
    f: number;
    i: number;
}

/**
 * Message representing the x component of vehicle velocity in the user frame at the
 * odometry reference point(s) specified by the user. The offset for the odometry reference
 * point and the definition and origin of the user frame are defined through the device
 * settings interface. There are 4 possible user-defined sources of this message which are
 * labeled arbitrarily source 0 through 3. If using "processor time" time tags, the
 * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to
 * synchronise odometry measurements with GNSS. Processor time shall roll over to zero after
 * one week.
 */
export interface MsgOdometry {
    flags:    number;
    tow:      number;
    velocity: number;
}

/**
 * This message reports the yaw, pitch, and roll angles of the vehicle body frame. The
 * rotations should applied intrinsically in the order yaw, pitch, and roll in order to
 * rotate the from a frame aligned with the local-level NED frame to the vehicle body
 * frame.  This message will only be available in future INS versions of Swift Products and
 * is not produced by Piksi Multi or Duro.
 */
export interface MsgOrientEuler {
    flags:          number;
    pitch:          number;
    pitch_accuracy: number;
    roll:           number;
    roll_accuracy:  number;
    tow:            number;
    yaw:            number;
    yaw_accuracy:   number;
}

/**
 * This message reports the quaternion vector describing the vehicle body frame's
 * orientation with respect to a local-level NED frame. The components of the vector should
 * sum to a unit vector assuming that the LSB of each component as a value of 2^-31. This
 * message will only be available in future INS versions of Swift Products and is not
 * produced by Piksi Multi or Duro.
 */
export interface MsgOrientQuat {
    flags:      number;
    tow:        number;
    w:          number;
    w_accuracy: number;
    x:          number;
    x_accuracy: number;
    y:          number;
    y_accuracy: number;
    z:          number;
    z_accuracy: number;
}

/**
 * The OSR message contains network corrections in an observation-like format.
 */
export interface MsgOsr {
    header: ObservationHeader;
    obs:    PackedOsrContent[];
}

/**
 * Pseudorange and carrier phase network corrections for a satellite signal.
 */
export interface PackedOsrContent {
    flags:     number;
    iono_std:  number;
    L:         CarrierPhase;
    lock:      number;
    P:         number;
    range_std: number;
    sid:       GnssSignal;
    tropo_std: number;
}

/**
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. If the rover receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position solution using the base station
 * position and the rover's RTK baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
export interface MsgPosECEF {
    accuracy: number;
    flags:    number;
    n_sats:   number;
    tow:      number;
    x:        number;
    y:        number;
    z:        number;
}

/**
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. The message also reports the upper triangular portion of the 3x3 covariance
 * matrix. If the receiver knows the surveyed position of the base station and has an RTK
 * solution, this reports a pseudo-absolute position solution using the base station
 * position and the rover's RTK baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
export interface MsgPosECEFCov {
    cov_x_x: number;
    cov_x_y: number;
    cov_x_z: number;
    cov_y_y: number;
    cov_y_z: number;
    cov_z_z: number;
    flags:   number;
    n_sats:  number;
    tow:     number;
    x:       number;
    y:       number;
    z:       number;
}

/**
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. The message also reports the upper triangular portion of the 3x3 covariance
 * matrix. If the receiver knows the surveyed position of the base station and has an RTK
 * solution, this reports a pseudo-absolute position solution using the base station
 * position and the rover's RTK baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
export interface MsgPosECEFCovGnss {
    cov_x_x: number;
    cov_x_y: number;
    cov_x_z: number;
    cov_y_y: number;
    cov_y_z: number;
    cov_z_z: number;
    flags:   number;
    n_sats:  number;
    tow:     number;
    x:       number;
    y:       number;
    z:       number;
}

/**
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. If the rover receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position solution using the base station
 * position and the rover's RTK baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
export interface MsgPosECEFGnss {
    accuracy: number;
    flags:    number;
    n_sats:   number;
    tow:      number;
    x:        number;
    y:        number;
    z:        number;
}

/**
 * This position solution message reports the absolute geodetic coordinates and the status
 * (single point vs pseudo-absolute RTK) of the position solution. If the rover receiver
 * knows the surveyed position of the base station and has an RTK solution, this reports a
 * pseudo-absolute position solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
export interface MsgPosLLH {
    flags:      number;
    h_accuracy: number;
    height:     number;
    lat:        number;
    lon:        number;
    n_sats:     number;
    tow:        number;
    v_accuracy: number;
}

/**
 * This position solution message reports the absolute geodetic coordinates and the status
 * (single point vs pseudo-absolute RTK) of the position solution as well as the estimated
 * horizontal, vertical, cross-track and along-track errors.  The position information and
 * Fix Mode flags  follow the MSG_POS_LLH message. Since the covariance matrix is computed
 * in the local-level North, East, Down frame, the estimated error terms follow that
 * convention.,
 * ,
 * The estimated errors are reported at a user-configurable confidence level. The
 * user-configured percentile is encoded in the percentile field.
 */
export interface MsgPosLLHAcc {
    at_accuracy:          number;
    confidence_and_geoid: number;
    ct_accuracy:          number;
    flags:                number;
    h_accuracy:           number;
    h_ellipse:            EstimatedHorizontalErrorEllipse;
    height:               number;
    lat:                  number;
    lon:                  number;
    n_sats:               number;
    orthometric_height:   number;
    tow:                  number;
    v_accuracy:           number;
}

export interface EstimatedHorizontalErrorEllipse {
    orientation: number;
    semi_major:  number;
    semi_minor:  number;
}

/**
 * This position solution message reports the absolute geodetic coordinates and the status
 * (single point vs pseudo-absolute RTK) of the position solution as well as the upper
 * triangle of the 3x3 covariance matrix.  The position information and Fix Mode flags
 * follow the MSG_POS_LLH message.  Since the covariance matrix is computed in the
 * local-level North, East, Down frame, the covariance terms follow that convention. Thus,
 * covariances are reported against the "downward" measurement and care should be taken with
 * the sign convention.
 */
export interface MsgPosLLHCov {
    cov_d_d: number;
    cov_e_d: number;
    cov_e_e: number;
    cov_n_d: number;
    cov_n_e: number;
    cov_n_n: number;
    flags:   number;
    height:  number;
    lat:     number;
    lon:     number;
    n_sats:  number;
    tow:     number;
}

/**
 * This position solution message reports the absolute geodetic coordinates and the status
 * (single point vs pseudo-absolute RTK) of the position solution as well as the upper
 * triangle of the 3x3 covariance matrix.  The position information and Fix Mode flags
 * should follow the MSG_POS_LLH message.  Since the covariance matrix is computed in the
 * local-level North, East, Down frame, the covariance terms follow with that convention.
 * Thus, covariances are reported against the "downward" measurement and care should be
 * taken with the sign convention.
 */
export interface MsgPosLLHCovGnss {
    cov_d_d: number;
    cov_e_d: number;
    cov_e_e: number;
    cov_n_d: number;
    cov_n_e: number;
    cov_n_n: number;
    flags:   number;
    height:  number;
    lat:     number;
    lon:     number;
    n_sats:  number;
    tow:     number;
}

/**
 * This position solution message reports the absolute geodetic coordinates and the status
 * (single point vs pseudo-absolute RTK) of the position solution. If the rover receiver
 * knows the surveyed position of the base station and has an RTK solution, this reports a
 * pseudo-absolute position solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
export interface MsgPosLLHGnss {
    flags:      number;
    h_accuracy: number;
    height:     number;
    lat:        number;
    lon:        number;
    n_sats:     number;
    tow:        number;
    v_accuracy: number;
}

/**
 * The PPS time message contains the value of the sender's local time in microseconds at the
 * moment a pulse is detected on the PPS input. This is to be used for syncronisation of
 * sensor data sampled with a local timestamp (e.g. IMU or wheeltick messages) where GNSS
 * time is unknown to the sender.,
 * ,
 * The local time used to timestamp the PPS pulse must be generated by the same clock which
 * is used to timestamp the IMU/wheel sensor data and should follow the same roll-over
 * rules.  A separate MSG_PPS_TIME message should be sent for each source of sensor data
 * which uses PPS-relative timestamping.  The sender ID for each of these MSG_PPS_TIME
 * messages should match the sender ID of the respective sensor data.
 */
export interface MsgPpsTime {
    flags: number;
    time:  number;
}

/**
 * This message reports the protection levels associated to the given state estimate. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
export interface MsgProtectionLevel {
    atpl:    number;
    ctpl:    number;
    flags:   number;
    heading: number;
    height:  number;
    hopl:    number;
    hpl:     number;
    hvpl:    number;
    lat:     number;
    lon:     number;
    pitch:   number;
    popl:    number;
    roll:    number;
    ropl:    number;
    tow:     number;
    v_x:     number;
    v_y:     number;
    v_z:     number;
    vpl:     number;
    vvpl:    number;
    wn:      number;
}

/**
 * This message from the host resets the Piksi back into the bootloader.
 */
export interface MsgReset {
    flags: number;
}

/**
 * This message resets either the DGNSS Kalman filters or Integer Ambiguity Resolution (IAR)
 * process.
 */
export interface MsgResetFilters {
    filter: number;
}

/**
 * This message is sent once per second per SBAS satellite. ME checks the parity of the data
 * block and sends only blocks that pass the check.
 */
export interface MsgSbasRaw {
    data:         number[];
    message_type: number;
    sid:          GnssSignal;
    tow:          number;
}

/**
 * The settings message for iterating through the settings values. A device will respond to
 * this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
 */
export interface MsgSettingsReadByIndexReq {
    index: number;
}

/**
 * The settings message that reports the value of a setting at an index.,
 * ,
 * In the string field, it reports NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where the '\0' escape sequence denotes
 * the NULL character and where quotation marks are omitted. The FORMAT_TYPE field is
 * optional and denotes possible string values of the setting as a hint to the user. If
 * included, the format type portion of the string has the format
 * "enum:value1,value2,value3". An example string that could be sent from the device is
 * "simulator\0enabled\0True\0enum:True,False\0".
 */
export interface MsgSettingsReadByIndexResp {
    index:   number;
    setting: string;
}

/**
 * The setting message that reads the device configuration. The string field is a
 * NULL-terminated and NULL-delimited string with contents "SECTION_SETTING\0SETTING\0"
 * where the '\0' escape sequence denotes the NULL character and where quotation marks are
 * omitted. An example string that could be sent to a device is "solution\0soln_freq\0". A
 * device will only respond to this message when it is received from sender ID 0x42. A
 * device should respond with a MSG_SETTINGS_READ_RESP message (msg_id 0x00A5).
 */
export interface MsgSettingsReadReq {
    setting: string;
}

/**
 * The setting message which which the device responds after a MSG_SETTING_READ_REQ is sent
 * to device. The string field is a NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes the NULL
 * character and where quotation marks are omitted. An example string that could be sent
 * from device is "solution\0soln_freq\010\0".
 */
export interface MsgSettingsReadResp {
    setting: string;
}

/**
 * This message registers the presence and default value of a setting with a settings
 * daemon.  The host should reply with MSG_SETTINGS_WRITE for this setting to set the
 * initial value.
 */
export interface MsgSettingsRegister {
    setting: string;
}

/**
 * This message responds to setting registration with the effective value. The effective
 * value shall differ from the given default value if setting was already registered or is
 * available in the permanent setting storage and had a different value.
 */
export interface MsgSettingsRegisterResp {
    setting: string;
    status:  number;
}

/**
 * The setting message writes the device configuration for a particular setting via A
 * NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes the NULL
 * character and where quotation marks are omitted. A device will only process to this
 * message when it is received from sender ID 0x42. An example string that could be sent to
 * a device is "solution\0soln_freq\010\0".
 */
export interface MsgSettingsWrite {
    setting: string;
}

/**
 * Return the status of a write request with the new value of the setting.  If the requested
 * value is rejected, the current value will be returned. The string field is a
 * NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes the NULL
 * character and where quotation marks are omitted. An example string that could be sent
 * from device is "solution\0soln_freq\010\0".
 */
export interface MsgSettingsWriteResp {
    setting: string;
    status:  number;
}

/**
 * This message contains all metadata about the sensors received and/or used in computing
 * the sensorfusion solution. It focuses primarily, but not only, on GNSS metadata.
 * Regarding the age of the last received valid GNSS solution, the highest two bits are time
 * status, indicating whether age gnss can or can not be used to retrieve time of
 * measurement (noted TOM, also known as time of validity) If it can, subtract 'age gnss'
 * from 'tow' in navigation messages to get TOM. Can be used before alignment is complete in
 * the Fusion Engine, when output solution is the last received valid GNSS solution and its
 * tow is not a TOM.
 */
export interface MsgSolnMeta {
    age_corrections: number;
    age_gnss:        number;
    hdop:            number;
    pdop:            number;
    sol_in:          SolutionInputType[];
    tow:             number;
    vdop:            number;
}

/**
 * Metadata describing which sensors were involved in the solution. The structure is fixed
 * no matter what the actual sensor type is. The sensor_type field tells you which sensor we
 * are talking about. It also tells you whether the sensor data was actually used or not.
 * The flags field, always a u8, contains the sensor-specific data. The content of flags,
 * for each sensor type, is described in the relevant structures in this section.
 */
export interface SolutionInputType {
    flags:       number;
    sensor_type: number;
}

/**
 * Spectrum analyzer packet.
 */
export interface MsgSpecan {
    amplitude_ref:   number;
    amplitude_unit:  number;
    amplitude_value: number[];
    channel_tag:     number;
    freq_ref:        number;
    freq_step:       number;
    t:               GpsTime;
}

/**
 * The precise code biases message is to be added to the pseudorange of the corresponding
 * signal to get corrected pseudorange. It is an equivalent to the 1059 / 1065 RTCM message
 * types.
 */
export interface MsgSsrCodeBiases {
    biases:          CodeBiasesContent[];
    iod_ssr:         number;
    sid:             GnssSignal;
    time:            GpsTimeSEC;
    update_interval: number;
}

/**
 * Code biases are to be added to pseudorange. The corrections conform with RTCMv3 MT 1059 /
 * 1065.
 */
export interface CodeBiasesContent {
    code:  number;
    value: number;
}

/**
 * STEC residuals are per space vehicle, troposphere is not.,
 * ,
 * It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
 */
export interface MsgSsrGriddedCorrection {
    element: GridElement;
    header:  GriddedCorrectionHeader;
}

/**
 * Contains one tropo delay (mean and stddev), plus STEC residuals (mean and stddev) for
 * each satellite at the grid point.
 */
export interface GridElement {
    index:                  number;
    stec_residuals:         STECResidual[];
    tropo_delay_correction: TroposphericDelayCorrection;
}

/**
 * STEC residual (mean and standard deviation) for the given satellite at the grid point.
 */
export interface STECResidual {
    residual: number;
    stddev:   number;
    sv_id:    SvID;
}

/**
 * Troposphere vertical delays (mean and standard deviation) at the grid point.
 */
export interface TroposphericDelayCorrection {
    hydro:  number;
    stddev: number;
    wet:    number;
}

/**
 * The LPP message contains nested variable length arrays which are not supported in SBP, so
 * each grid point will be identified by the index.
 */
export interface GriddedCorrectionHeader {
    iod_atmo:                number;
    num_msgs:                number;
    seq_num:                 number;
    tile_id:                 number;
    tile_set_id:             number;
    time:                    GpsTimeSEC;
    tropo_quality_indicator: number;
    update_interval:         number;
}

/**
 * The precise orbit and clock correction message is to be applied as a delta correction to
 * broadcast ephemeris and is an equivalent to the 1060 /1066 RTCM message types.
 */
export interface MsgSsrOrbitClock {
    along:           number;
    c0:              number;
    c1:              number;
    c2:              number;
    cross:           number;
    dot_along:       number;
    dot_cross:       number;
    dot_radial:      number;
    iod:             number;
    iod_ssr:         number;
    radial:          number;
    sid:             GnssSignal;
    time:            GpsTimeSEC;
    update_interval: number;
}

/**
 * The precise phase biases message contains the biases to be added to the carrier phase of
 * the corresponding signal to get corrected carrier phase measurement, as well as the
 * satellite yaw angle to be applied to compute the phase wind-up correction. It is
 * typically an equivalent to the 1265 RTCM message types.
 */
export interface MsgSsrPhaseBiases {
    biases:          PhaseBiasesContent[];
    dispersive_bias: number;
    iod_ssr:         number;
    mw_consistency:  number;
    sid:             GnssSignal;
    time:            GpsTimeSEC;
    update_interval: number;
    yaw:             number;
    yaw_rate:        number;
}

/**
 * Phase biases are to be added to carrier phase measurements.
 */
export interface PhaseBiasesContent {
    bias:                       number;
    code:                       number;
    discontinuity_counter:      number;
    integer_indicator:          number;
    widelane_integer_indicator: number;
}

export interface MsgSsrSatelliteApc {
    apc: SatelliteAPC[];
}

/**
 * Contains phase center offset and elevation variation corrections for one signal on a
 * satellite.
 */
export interface SatelliteAPC {
    pco:      number[];
    pcv:      number[];
    sat_info: number;
    sid:      GnssSignal;
    svn:      number;
}

/**
 * The Slant Total Electron Content per space vehicle, given as polynomial approximation for
 * a given tile. This should be combined with the MSG_SSR_GRIDDED_CORRECTION message to get
 * the state space representation of the atmospheric delay.,
 * ,
 * It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
 */
export interface MsgSsrStecCorrection {
    header:        STECHeader;
    stec_sat_list: STECSatElement[];
}

/**
 * A full set of STEC information will likely span multiple SBP messages, since SBP message
 * a limited to 255 bytes.  The header is used to tie multiple SBP messages into a sequence.
 */
export interface STECHeader {
    iod_atmo:        number;
    num_msgs:        number;
    seq_num:         number;
    tile_id:         number;
    tile_set_id:     number;
    time:            GpsTimeSEC;
    update_interval: number;
}

/**
 * STEC polynomial for the given satellite.
 */
export interface STECSatElement {
    stec_coeff:             number[];
    stec_quality_indicator: number;
    sv_id:                  SvID;
}

/**
 * Provides the correction point coordinates for the atmospheric correction values in the
 * MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION messages.,
 * ,
 * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information element
 * GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of correction points, not
 * lists of points.
 */
export interface MsgSsrTileDefinition {
    bitmask:       number;
    cols:          number;
    corner_nw_lat: number;
    corner_nw_lon: number;
    rows:          number;
    spacing_lat:   number;
    spacing_lon:   number;
    tile_id:       number;
    tile_set_id:   number;
}

/**
 * The system start-up message is sent once on system start-up. It notifies the host or
 * other attached devices that the system has started and is now ready to respond to
 * commands or configuration requests.
 */
export interface MsgStartup {
    cause:        number;
    startup_type: number;
}

/**
 * The status report is sent periodically to inform the host or other attached devices that
 * the system is running. It is used to monitor system malfunctions. It contains status
 * reports that indicate to the host the status of each sub-system and whether it is
 * operating correctly.,
 * ,
 * Interpretation of the subsystem specific status code is product dependent, but if the
 * generic status code is initializing, it should be ignored.  Refer to product
 * documentation for details.
 */
export interface MsgStatusReport {
    reporting_system: number;
    sbp_version:      number;
    sequence:         number;
    status:           SubSystemReport[];
    uptime:           number;
}

/**
 * Report the general and specific state of a sub-system.  If the generic state is reported
 * as initializing, the specific state should be ignored.
 */
export interface SubSystemReport {
    component: number;
    generic:   number;
    specific:  number;
}

/**
 * The flash lock message locks a sector of the STM flash memory. The device replies with a
 * MSG_FLASH_DONE message.
 */
export interface MsgStmFlashLockSector {
    sector: number;
}

/**
 * The flash unlock message unlocks a sector of the STM flash memory. The device replies
 * with a MSG_FLASH_DONE message.
 */
export interface MsgStmFlashUnlockSector {
    sector: number;
}

/**
 * This message reads the device's hard-coded unique ID. The host requests the ID by sending
 * a MSG_STM_UNIQUE_ID_REQ. The device responds with a MSG_STM_UNIQUE_ID_RESP with the
 * 12-byte unique ID in the payload.
 */
export interface MsgStmUniqueIDResp {
    stm_id: number[];
}

/**
 * Azimuth and elevation angles of all the visible satellites that the device does have
 * ephemeris or almanac for.
 */
export interface MsgSvAzEl {
    azel: SvAzEl[];
}

/**
 * Satellite azimuth and elevation.
 */
export interface SvAzEl {
    az:  number;
    el:  number;
    sid: GnssSignal;
}

/**
 * The thread usage message from the device reports real-time operating system (RTOS) thread
 * usage statistics for the named thread. The reported percentage values must be normalized.
 */
export interface MsgThreadState {
    cpu:        number;
    name:       string;
    stack_free: number;
}

/**
 * When enabled, a tracking channel can output the correlations at each update interval.
 */
export interface MsgTrackingIq {
    channel: number;
    corrs:   TrackingChannelCorrelation[];
    sid:     GnssSignal;
}

/**
 * Structure containing in-phase and quadrature correlation components.
 */
export interface TrackingChannelCorrelation {
    I: number;
    Q: number;
}

/**
 * The tracking message returns a variable-length array of tracking channel states. It
 * reports status and carrier-to-noise density measurements for all tracked satellites.
 */
export interface MsgTrackingState {
    states: TrackingChannelState[];
}

/**
 * Tracking channel state for a specific satellite signal and measured signal power.
 */
export interface TrackingChannelState {
    cn0: number;
    fcn: number;
    sid: GnssSignal;
}

/**
 * The UART message reports data latency and throughput of the UART channels providing SBP
 * I/O. On the default Piksi configuration, UARTs A and B are used for telemetry radios, but
 * can also be host access ports for embedded hosts, or other interfaces in future. The
 * reported percentage values must be normalized. Observations latency and period can be
 * used to assess the health of the differential corrections link. Latency provides the
 * timeliness of received base observations while the period indicates their likelihood of
 * transmission.
 */
export interface MsgUARTState {
    latency:    Latency;
    obs_period: Period;
    uart_a:     UARTChannel;
    uart_b:     UARTChannel;
    uart_ftdi:  UARTChannel;
}

/**
 * Statistics on the latency of observations received from the base station. As observation
 * packets are received their GPS time is compared to the current GPS time calculated
 * locally by the receiver to give a precise measurement of the end-to-end communication
 * latency in the system.
 */
export interface Latency {
    avg:     number;
    current: number;
    lmax:    number;
    lmin:    number;
}

/**
 * Statistics on the period of observations received from the base station. As complete
 * observation sets are received, their time of reception is compared with the prior set''s
 * time of reception. This measurement provides a proxy for link quality as incomplete or
 * missing sets will increase the period.  Long periods can cause momentary RTK solution
 * outages.
 */
export interface Period {
    avg:     number;
    current: number;
    pmax:    number;
    pmin:    number;
}

/**
 * Throughput, utilization, and error counts on the RX/TX buffers of this UART channel. The
 * reported percentage values must be normalized.
 */
export interface UARTChannel {
    crc_error_count: number;
    io_error_count:  number;
    rx_buffer_level: number;
    rx_throughput:   number;
    tx_buffer_level: number;
    tx_throughput:   number;
}

/**
 * This message can contain any application specific user data up to a maximum length of 255
 * bytes per message.
 */
export interface MsgUserData {
    contents: number[];
}

/**
 * This message reports the Universal Coordinated Time (UTC).  Note the flags which indicate
 * the source of the UTC offset value and source of the time fix.
 */
export interface MsgUTCTime {
    day:     number;
    flags:   number;
    hours:   number;
    minutes: number;
    month:   number;
    ns:      number;
    seconds: number;
    tow:     number;
    year:    number;
}

/**
 * This message reports the Universal Coordinated Time (UTC).  Note the flags which indicate
 * the source of the UTC offset value and source of the time fix.
 */
export interface MsgUTCTimeGnss {
    day:     number;
    flags:   number;
    hours:   number;
    minutes: number;
    month:   number;
    ns:      number;
    seconds: number;
    tow:     number;
    year:    number;
}

/**
 * This message reports the velocity in the Vehicle Body Frame. By convention, the x-axis
 * should point out the nose of the vehicle and represent the forward direction, while as
 * the y-axis should point out the right hand side of the vehicle. Since this is a right
 * handed system, z should point out the bottom of the vehicle. The orientation and origin
 * of the Vehicle Body Frame are specified via the device settings. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow). This message is
 * only produced by inertial versions of Swift products and is not available from Piksi
 * Multi or Duro.
 */
export interface MsgVelBody {
    cov_x_x: number;
    cov_x_y: number;
    cov_x_z: number;
    cov_y_y: number;
    cov_y_z: number;
    cov_z_z: number;
    flags:   number;
    n_sats:  number;
    tow:     number;
    x:       number;
    y:       number;
    z:       number;
}

/**
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF) coordinates. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
export interface MsgVelECEF {
    accuracy: number;
    flags:    number;
    n_sats:   number;
    tow:      number;
    x:        number;
    y:        number;
    z:        number;
}

/**
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF) coordinates. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
export interface MsgVelECEFCov {
    cov_x_x: number;
    cov_x_y: number;
    cov_x_z: number;
    cov_y_y: number;
    cov_y_z: number;
    cov_z_z: number;
    flags:   number;
    n_sats:  number;
    tow:     number;
    x:       number;
    y:       number;
    z:       number;
}

/**
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF) coordinates. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
export interface MsgVelECEFCovGnss {
    cov_x_x: number;
    cov_x_y: number;
    cov_x_z: number;
    cov_y_y: number;
    cov_y_z: number;
    cov_z_z: number;
    flags:   number;
    n_sats:  number;
    tow:     number;
    x:       number;
    y:       number;
    z:       number;
}

/**
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF) coordinates. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
export interface MsgVelECEFGnss {
    accuracy: number;
    flags:    number;
    n_sats:   number;
    tow:      number;
    x:        number;
    y:        number;
    z:        number;
}

/**
 * This message reports the velocity in local North East Down (NED) coordinates. The NED
 * coordinate system is defined as the local WGS84 tangent plane centered at the current
 * position. The full GPS time is given by the preceding MSG_GPS_TIME with the matching
 * time-of-week (tow).
 */
export interface MsgVelNED {
    d:          number;
    e:          number;
    flags:      number;
    h_accuracy: number;
    n:          number;
    n_sats:     number;
    tow:        number;
    v_accuracy: number;
}

/**
 * This message reports the velocity in local North East Down (NED) coordinates. The NED
 * coordinate system is defined as the local WGS84 tangent plane centered at the current
 * position. The full GPS time is given by the preceding MSG_GPS_TIME with the matching
 * time-of-week (tow). This message is similar to the MSG_VEL_NED, but it includes the upper
 * triangular portion of the 3x3 covariance matrix.
 */
export interface MsgVelNEDCov {
    cov_d_d: number;
    cov_e_d: number;
    cov_e_e: number;
    cov_n_d: number;
    cov_n_e: number;
    cov_n_n: number;
    d:       number;
    e:       number;
    flags:   number;
    n:       number;
    n_sats:  number;
    tow:     number;
}

/**
 * This message reports the velocity in local North East Down (NED) coordinates. The NED
 * coordinate system is defined as the local WGS84 tangent plane centered at the current
 * position. The full GPS time is given by the preceding MSG_GPS_TIME with the matching
 * time-of-week (tow). This message is similar to the MSG_VEL_NED, but it includes the upper
 * triangular portion of the 3x3 covariance matrix.
 */
export interface MsgVelNEDCovGnss {
    cov_d_d: number;
    cov_e_d: number;
    cov_e_e: number;
    cov_n_d: number;
    cov_n_e: number;
    cov_n_n: number;
    d:       number;
    e:       number;
    flags:   number;
    n:       number;
    n_sats:  number;
    tow:     number;
}

/**
 * This message reports the velocity in local North East Down (NED) coordinates. The NED
 * coordinate system is defined as the local WGS84 tangent plane centered at the current
 * position. The full GPS time is given by the preceding MSG_GPS_TIME with the matching
 * time-of-week (tow).
 */
export interface MsgVelNEDGnss {
    d:          number;
    e:          number;
    flags:      number;
    h_accuracy: number;
    n:          number;
    n_sats:     number;
    tow:        number;
    v_accuracy: number;
}

/**
 * Message containing the accumulated distance travelled by a wheel located at an odometry
 * reference point defined by the user. The offset for the odometry reference point and the
 * definition and origin of the user frame are defined through the device settings
 * interface. The source of this message is identified by the source field, which is an
 * integer ranging from 0 to 255. The timestamp associated with this message should
 * represent the time when the accumulated tick count reached the value given by the
 * contents of this message as accurately as possible. If using "local CPU time" time tags,
 * the receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available
 * to synchronise wheeltick measurements with GNSS. Local CPU time shall roll over to zero
 * after one week.
 */
export interface MsgWheeltick {
    flags:  number;
    source: number;
    ticks:  number;
    time:   number;
}

/**
 * Metadata around the Odometry sensors involved in the fuzed solution. Accessible through
 * sol_in[N].flags in a MSG_SOLN_META.
 */
export interface OdoInputType {
    flags: number;
}

// Converts JSON strings to/from your types
// and asserts the results of JSON.parse at runtime
export class Convert {
    public static toAcqSvProfile(json: string): AcqSvProfile {
        return cast(JSON.parse(json), r("AcqSvProfile"));
    }

    public static acqSvProfileToJson(value: AcqSvProfile): string {
        return JSON.stringify(uncast(value, r("AcqSvProfile")), null, 2);
    }

    public static toAlmanacCommonContent(json: string): AlmanacCommonContent {
        return cast(JSON.parse(json), r("AlmanacCommonContent"));
    }

    public static almanacCommonContentToJson(value: AlmanacCommonContent): string {
        return JSON.stringify(uncast(value, r("AlmanacCommonContent")), null, 2);
    }

    public static toCarrierPhase(json: string): CarrierPhase {
        return cast(JSON.parse(json), r("CarrierPhase"));
    }

    public static carrierPhaseToJson(value: CarrierPhase): string {
        return JSON.stringify(uncast(value, r("CarrierPhase")), null, 2);
    }

    public static toCodeBiasesContent(json: string): CodeBiasesContent {
        return cast(JSON.parse(json), r("CodeBiasesContent"));
    }

    public static codeBiasesContentToJson(value: CodeBiasesContent): string {
        return JSON.stringify(uncast(value, r("CodeBiasesContent")), null, 2);
    }

    public static toDoppler(json: string): Doppler {
        return cast(JSON.parse(json), r("Doppler"));
    }

    public static dopplerToJson(value: Doppler): string {
        return JSON.stringify(uncast(value, r("Doppler")), null, 2);
    }

    public static toEphemerisCommonContent(json: string): EphemerisCommonContent {
        return cast(JSON.parse(json), r("EphemerisCommonContent"));
    }

    public static ephemerisCommonContentToJson(value: EphemerisCommonContent): string {
        return JSON.stringify(uncast(value, r("EphemerisCommonContent")), null, 2);
    }

    public static toEstimatedHorizontalErrorEllipse(json: string): EstimatedHorizontalErrorEllipse {
        return cast(JSON.parse(json), r("EstimatedHorizontalErrorEllipse"));
    }

    public static estimatedHorizontalErrorEllipseToJson(value: EstimatedHorizontalErrorEllipse): string {
        return JSON.stringify(uncast(value, r("EstimatedHorizontalErrorEllipse")), null, 2);
    }

    public static toGNSSInputType(json: string): GNSSInputType {
        return cast(JSON.parse(json), r("GNSSInputType"));
    }

    public static gNSSInputTypeToJson(value: GNSSInputType): string {
        return JSON.stringify(uncast(value, r("GNSSInputType")), null, 2);
    }

    public static toGnssCapb(json: string): GnssCapb {
        return cast(JSON.parse(json), r("GnssCapb"));
    }

    public static gnssCapbToJson(value: GnssCapb): string {
        return JSON.stringify(uncast(value, r("GnssCapb")), null, 2);
    }

    public static toGnssSignal(json: string): GnssSignal {
        return cast(JSON.parse(json), r("GnssSignal"));
    }

    public static gnssSignalToJson(value: GnssSignal): string {
        return JSON.stringify(uncast(value, r("GnssSignal")), null, 2);
    }

    public static toGpsTime(json: string): GpsTime {
        return cast(JSON.parse(json), r("GpsTime"));
    }

    public static gpsTimeToJson(value: GpsTime): string {
        return JSON.stringify(uncast(value, r("GpsTime")), null, 2);
    }

    public static toGpsTimeSEC(json: string): GpsTimeSEC {
        return cast(JSON.parse(json), r("GpsTimeSEC"));
    }

    public static gpsTimeSECToJson(value: GpsTimeSEC): string {
        return JSON.stringify(uncast(value, r("GpsTimeSEC")), null, 2);
    }

    public static toGridElement(json: string): GridElement {
        return cast(JSON.parse(json), r("GridElement"));
    }

    public static gridElementToJson(value: GridElement): string {
        return JSON.stringify(uncast(value, r("GridElement")), null, 2);
    }

    public static toGridElementNoStd(json: string): GridElementNoStd {
        return cast(JSON.parse(json), r("GridElementNoStd"));
    }

    public static gridElementNoStdToJson(value: GridElementNoStd): string {
        return JSON.stringify(uncast(value, r("GridElementNoStd")), null, 2);
    }

    public static toGriddedCorrectionHeader(json: string): GriddedCorrectionHeader {
        return cast(JSON.parse(json), r("GriddedCorrectionHeader"));
    }

    public static griddedCorrectionHeaderToJson(value: GriddedCorrectionHeader): string {
        return JSON.stringify(uncast(value, r("GriddedCorrectionHeader")), null, 2);
    }

    public static toIMUInputType(json: string): IMUInputType {
        return cast(JSON.parse(json), r("IMUInputType"));
    }

    public static iMUInputTypeToJson(value: IMUInputType): string {
        return JSON.stringify(uncast(value, r("IMUInputType")), null, 2);
    }

    public static toLatency(json: string): Latency {
        return cast(JSON.parse(json), r("Latency"));
    }

    public static latencyToJson(value: Latency): string {
        return JSON.stringify(uncast(value, r("Latency")), null, 2);
    }

    public static toMeasurementState(json: string): MeasurementState {
        return cast(JSON.parse(json), r("MeasurementState"));
    }

    public static measurementStateToJson(value: MeasurementState): string {
        return JSON.stringify(uncast(value, r("MeasurementState")), null, 2);
    }

    public static toMsgAcqResult(json: string): MsgAcqResult {
        return cast(JSON.parse(json), r("MsgAcqResult"));
    }

    public static msgAcqResultToJson(value: MsgAcqResult): string {
        return JSON.stringify(uncast(value, r("MsgAcqResult")), null, 2);
    }

    public static toMsgAcqSvProfile(json: string): MsgAcqSvProfile {
        return cast(JSON.parse(json), r("MsgAcqSvProfile"));
    }

    public static msgAcqSvProfileToJson(value: MsgAcqSvProfile): string {
        return JSON.stringify(uncast(value, r("MsgAcqSvProfile")), null, 2);
    }

    public static toMsgAgeCorrections(json: string): MsgAgeCorrections {
        return cast(JSON.parse(json), r("MsgAgeCorrections"));
    }

    public static msgAgeCorrectionsToJson(value: MsgAgeCorrections): string {
        return JSON.stringify(uncast(value, r("MsgAgeCorrections")), null, 2);
    }

    public static toMsgAlmanac(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgAlmanacToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgAlmanacGPS(json: string): MsgAlmanacGPS {
        return cast(JSON.parse(json), r("MsgAlmanacGPS"));
    }

    public static msgAlmanacGPSToJson(value: MsgAlmanacGPS): string {
        return JSON.stringify(uncast(value, r("MsgAlmanacGPS")), null, 2);
    }

    public static toMsgAlmanacGlo(json: string): MsgAlmanacGlo {
        return cast(JSON.parse(json), r("MsgAlmanacGlo"));
    }

    public static msgAlmanacGloToJson(value: MsgAlmanacGlo): string {
        return JSON.stringify(uncast(value, r("MsgAlmanacGlo")), null, 2);
    }

    public static toMsgAngularRate(json: string): MsgAngularRate {
        return cast(JSON.parse(json), r("MsgAngularRate"));
    }

    public static msgAngularRateToJson(value: MsgAngularRate): string {
        return JSON.stringify(uncast(value, r("MsgAngularRate")), null, 2);
    }

    public static toMsgBasePosECEF(json: string): MsgBasePosECEF {
        return cast(JSON.parse(json), r("MsgBasePosECEF"));
    }

    public static msgBasePosECEFToJson(value: MsgBasePosECEF): string {
        return JSON.stringify(uncast(value, r("MsgBasePosECEF")), null, 2);
    }

    public static toMsgBasePosLLH(json: string): MsgBasePosLLH {
        return cast(JSON.parse(json), r("MsgBasePosLLH"));
    }

    public static msgBasePosLLHToJson(value: MsgBasePosLLH): string {
        return JSON.stringify(uncast(value, r("MsgBasePosLLH")), null, 2);
    }

    public static toMsgBaselineECEF(json: string): MsgBaselineECEF {
        return cast(JSON.parse(json), r("MsgBaselineECEF"));
    }

    public static msgBaselineECEFToJson(value: MsgBaselineECEF): string {
        return JSON.stringify(uncast(value, r("MsgBaselineECEF")), null, 2);
    }

    public static toMsgBaselineHeading(json: string): MsgBaselineHeading {
        return cast(JSON.parse(json), r("MsgBaselineHeading"));
    }

    public static msgBaselineHeadingToJson(value: MsgBaselineHeading): string {
        return JSON.stringify(uncast(value, r("MsgBaselineHeading")), null, 2);
    }

    public static toMsgBaselineNED(json: string): MsgBaselineNED {
        return cast(JSON.parse(json), r("MsgBaselineNED"));
    }

    public static msgBaselineNEDToJson(value: MsgBaselineNED): string {
        return JSON.stringify(uncast(value, r("MsgBaselineNED")), null, 2);
    }

    public static toMsgBootloaderHandshakeReq(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgBootloaderHandshakeReqToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgBootloaderHandshakeResp(json: string): MsgBootloaderHandshakeResp {
        return cast(JSON.parse(json), r("MsgBootloaderHandshakeResp"));
    }

    public static msgBootloaderHandshakeRespToJson(value: MsgBootloaderHandshakeResp): string {
        return JSON.stringify(uncast(value, r("MsgBootloaderHandshakeResp")), null, 2);
    }

    public static toMsgBootloaderJumpToApp(json: string): MsgBootloaderJumpToApp {
        return cast(JSON.parse(json), r("MsgBootloaderJumpToApp"));
    }

    public static msgBootloaderJumpToAppToJson(value: MsgBootloaderJumpToApp): string {
        return JSON.stringify(uncast(value, r("MsgBootloaderJumpToApp")), null, 2);
    }

    public static toMsgCellModemStatus(json: string): MsgCellModemStatus {
        return cast(JSON.parse(json), r("MsgCellModemStatus"));
    }

    public static msgCellModemStatusToJson(value: MsgCellModemStatus): string {
        return JSON.stringify(uncast(value, r("MsgCellModemStatus")), null, 2);
    }

    public static toMsgCommandOutput(json: string): MsgCommandOutput {
        return cast(JSON.parse(json), r("MsgCommandOutput"));
    }

    public static msgCommandOutputToJson(value: MsgCommandOutput): string {
        return JSON.stringify(uncast(value, r("MsgCommandOutput")), null, 2);
    }

    public static toMsgCommandReq(json: string): MsgCommandReq {
        return cast(JSON.parse(json), r("MsgCommandReq"));
    }

    public static msgCommandReqToJson(value: MsgCommandReq): string {
        return JSON.stringify(uncast(value, r("MsgCommandReq")), null, 2);
    }

    public static toMsgCommandResp(json: string): MsgCommandResp {
        return cast(JSON.parse(json), r("MsgCommandResp"));
    }

    public static msgCommandRespToJson(value: MsgCommandResp): string {
        return JSON.stringify(uncast(value, r("MsgCommandResp")), null, 2);
    }

    public static toMsgCsacTelemetry(json: string): MsgCsacTelemetry {
        return cast(JSON.parse(json), r("MsgCsacTelemetry"));
    }

    public static msgCsacTelemetryToJson(value: MsgCsacTelemetry): string {
        return JSON.stringify(uncast(value, r("MsgCsacTelemetry")), null, 2);
    }

    public static toMsgCsacTelemetryLabels(json: string): MsgCsacTelemetryLabels {
        return cast(JSON.parse(json), r("MsgCsacTelemetryLabels"));
    }

    public static msgCsacTelemetryLabelsToJson(value: MsgCsacTelemetryLabels): string {
        return JSON.stringify(uncast(value, r("MsgCsacTelemetryLabels")), null, 2);
    }

    public static toMsgCwResults(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgCwResultsToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgCwStart(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgCwStartToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgDeviceMonitor(json: string): MsgDeviceMonitor {
        return cast(JSON.parse(json), r("MsgDeviceMonitor"));
    }

    public static msgDeviceMonitorToJson(value: MsgDeviceMonitor): string {
        return JSON.stringify(uncast(value, r("MsgDeviceMonitor")), null, 2);
    }

    public static toMsgDgnssStatus(json: string): MsgDgnssStatus {
        return cast(JSON.parse(json), r("MsgDgnssStatus"));
    }

    public static msgDgnssStatusToJson(value: MsgDgnssStatus): string {
        return JSON.stringify(uncast(value, r("MsgDgnssStatus")), null, 2);
    }

    public static toMsgDops(json: string): MsgDops {
        return cast(JSON.parse(json), r("MsgDops"));
    }

    public static msgDopsToJson(value: MsgDops): string {
        return JSON.stringify(uncast(value, r("MsgDops")), null, 2);
    }

    public static toMsgEphemerisBds(json: string): MsgEphemerisBds {
        return cast(JSON.parse(json), r("MsgEphemerisBds"));
    }

    public static msgEphemerisBdsToJson(value: MsgEphemerisBds): string {
        return JSON.stringify(uncast(value, r("MsgEphemerisBds")), null, 2);
    }

    public static toMsgEphemerisGPS(json: string): MsgEphemerisGPS {
        return cast(JSON.parse(json), r("MsgEphemerisGPS"));
    }

    public static msgEphemerisGPSToJson(value: MsgEphemerisGPS): string {
        return JSON.stringify(uncast(value, r("MsgEphemerisGPS")), null, 2);
    }

    public static toMsgEphemerisGal(json: string): MsgEphemerisGal {
        return cast(JSON.parse(json), r("MsgEphemerisGal"));
    }

    public static msgEphemerisGalToJson(value: MsgEphemerisGal): string {
        return JSON.stringify(uncast(value, r("MsgEphemerisGal")), null, 2);
    }

    public static toMsgEphemerisGlo(json: string): MsgEphemerisGlo {
        return cast(JSON.parse(json), r("MsgEphemerisGlo"));
    }

    public static msgEphemerisGloToJson(value: MsgEphemerisGlo): string {
        return JSON.stringify(uncast(value, r("MsgEphemerisGlo")), null, 2);
    }

    public static toMsgEphemerisQzss(json: string): MsgEphemerisQzss {
        return cast(JSON.parse(json), r("MsgEphemerisQzss"));
    }

    public static msgEphemerisQzssToJson(value: MsgEphemerisQzss): string {
        return JSON.stringify(uncast(value, r("MsgEphemerisQzss")), null, 2);
    }

    public static toMsgEphemerisSbas(json: string): MsgEphemerisSbas {
        return cast(JSON.parse(json), r("MsgEphemerisSbas"));
    }

    public static msgEphemerisSbasToJson(value: MsgEphemerisSbas): string {
        return JSON.stringify(uncast(value, r("MsgEphemerisSbas")), null, 2);
    }

    public static toMsgEXTEvent(json: string): MsgEXTEvent {
        return cast(JSON.parse(json), r("MsgEXTEvent"));
    }

    public static msgEXTEventToJson(value: MsgEXTEvent): string {
        return JSON.stringify(uncast(value, r("MsgEXTEvent")), null, 2);
    }

    public static toMsgFileioConfigReq(json: string): MsgFileioConfigReq {
        return cast(JSON.parse(json), r("MsgFileioConfigReq"));
    }

    public static msgFileioConfigReqToJson(value: MsgFileioConfigReq): string {
        return JSON.stringify(uncast(value, r("MsgFileioConfigReq")), null, 2);
    }

    public static toMsgFileioConfigResp(json: string): MsgFileioConfigResp {
        return cast(JSON.parse(json), r("MsgFileioConfigResp"));
    }

    public static msgFileioConfigRespToJson(value: MsgFileioConfigResp): string {
        return JSON.stringify(uncast(value, r("MsgFileioConfigResp")), null, 2);
    }

    public static toMsgFileioReadDirReq(json: string): MsgFileioReadDirReq {
        return cast(JSON.parse(json), r("MsgFileioReadDirReq"));
    }

    public static msgFileioReadDirReqToJson(value: MsgFileioReadDirReq): string {
        return JSON.stringify(uncast(value, r("MsgFileioReadDirReq")), null, 2);
    }

    public static toMsgFileioReadDirResp(json: string): MsgFileioReadDirResp {
        return cast(JSON.parse(json), r("MsgFileioReadDirResp"));
    }

    public static msgFileioReadDirRespToJson(value: MsgFileioReadDirResp): string {
        return JSON.stringify(uncast(value, r("MsgFileioReadDirResp")), null, 2);
    }

    public static toMsgFileioReadReq(json: string): MsgFileioReadReq {
        return cast(JSON.parse(json), r("MsgFileioReadReq"));
    }

    public static msgFileioReadReqToJson(value: MsgFileioReadReq): string {
        return JSON.stringify(uncast(value, r("MsgFileioReadReq")), null, 2);
    }

    public static toMsgFileioReadResp(json: string): MsgFileioReadResp {
        return cast(JSON.parse(json), r("MsgFileioReadResp"));
    }

    public static msgFileioReadRespToJson(value: MsgFileioReadResp): string {
        return JSON.stringify(uncast(value, r("MsgFileioReadResp")), null, 2);
    }

    public static toMsgFileioRemove(json: string): MsgFileioRemove {
        return cast(JSON.parse(json), r("MsgFileioRemove"));
    }

    public static msgFileioRemoveToJson(value: MsgFileioRemove): string {
        return JSON.stringify(uncast(value, r("MsgFileioRemove")), null, 2);
    }

    public static toMsgFileioWriteReq(json: string): MsgFileioWriteReq {
        return cast(JSON.parse(json), r("MsgFileioWriteReq"));
    }

    public static msgFileioWriteReqToJson(value: MsgFileioWriteReq): string {
        return JSON.stringify(uncast(value, r("MsgFileioWriteReq")), null, 2);
    }

    public static toMsgFileioWriteResp(json: string): MsgFileioWriteResp {
        return cast(JSON.parse(json), r("MsgFileioWriteResp"));
    }

    public static msgFileioWriteRespToJson(value: MsgFileioWriteResp): string {
        return JSON.stringify(uncast(value, r("MsgFileioWriteResp")), null, 2);
    }

    public static toMsgFlashDone(json: string): MsgFlashDone {
        return cast(JSON.parse(json), r("MsgFlashDone"));
    }

    public static msgFlashDoneToJson(value: MsgFlashDone): string {
        return JSON.stringify(uncast(value, r("MsgFlashDone")), null, 2);
    }

    public static toMsgFlashErase(json: string): MsgFlashErase {
        return cast(JSON.parse(json), r("MsgFlashErase"));
    }

    public static msgFlashEraseToJson(value: MsgFlashErase): string {
        return JSON.stringify(uncast(value, r("MsgFlashErase")), null, 2);
    }

    public static toMsgFlashProgram(json: string): MsgFlashProgram {
        return cast(JSON.parse(json), r("MsgFlashProgram"));
    }

    public static msgFlashProgramToJson(value: MsgFlashProgram): string {
        return JSON.stringify(uncast(value, r("MsgFlashProgram")), null, 2);
    }

    public static toMsgFlashReadReq(json: string): MsgFlashReadReq {
        return cast(JSON.parse(json), r("MsgFlashReadReq"));
    }

    public static msgFlashReadReqToJson(value: MsgFlashReadReq): string {
        return JSON.stringify(uncast(value, r("MsgFlashReadReq")), null, 2);
    }

    public static toMsgFlashReadResp(json: string): MsgFlashReadResp {
        return cast(JSON.parse(json), r("MsgFlashReadResp"));
    }

    public static msgFlashReadRespToJson(value: MsgFlashReadResp): string {
        return JSON.stringify(uncast(value, r("MsgFlashReadResp")), null, 2);
    }

    public static toMsgFrontEndGain(json: string): MsgFrontEndGain {
        return cast(JSON.parse(json), r("MsgFrontEndGain"));
    }

    public static msgFrontEndGainToJson(value: MsgFrontEndGain): string {
        return JSON.stringify(uncast(value, r("MsgFrontEndGain")), null, 2);
    }

    public static toMsgFwd(json: string): MsgFwd {
        return cast(JSON.parse(json), r("MsgFwd"));
    }

    public static msgFwdToJson(value: MsgFwd): string {
        return JSON.stringify(uncast(value, r("MsgFwd")), null, 2);
    }

    public static toMsgGPSTime(json: string): MsgGPSTime {
        return cast(JSON.parse(json), r("MsgGPSTime"));
    }

    public static msgGPSTimeToJson(value: MsgGPSTime): string {
        return JSON.stringify(uncast(value, r("MsgGPSTime")), null, 2);
    }

    public static toMsgGPSTimeGnss(json: string): MsgGPSTimeGnss {
        return cast(JSON.parse(json), r("MsgGPSTimeGnss"));
    }

    public static msgGPSTimeGnssToJson(value: MsgGPSTimeGnss): string {
        return JSON.stringify(uncast(value, r("MsgGPSTimeGnss")), null, 2);
    }

    public static toMsgGloBiases(json: string): MsgGloBiases {
        return cast(JSON.parse(json), r("MsgGloBiases"));
    }

    public static msgGloBiasesToJson(value: MsgGloBiases): string {
        return JSON.stringify(uncast(value, r("MsgGloBiases")), null, 2);
    }

    public static toMsgGnssCapb(json: string): MsgGnssCapb {
        return cast(JSON.parse(json), r("MsgGnssCapb"));
    }

    public static msgGnssCapbToJson(value: MsgGnssCapb): string {
        return JSON.stringify(uncast(value, r("MsgGnssCapb")), null, 2);
    }

    public static toMsgGnssTimeOffset(json: string): MsgGnssTimeOffset {
        return cast(JSON.parse(json), r("MsgGnssTimeOffset"));
    }

    public static msgGnssTimeOffsetToJson(value: MsgGnssTimeOffset): string {
        return JSON.stringify(uncast(value, r("MsgGnssTimeOffset")), null, 2);
    }

    public static toMsgGroupDelay(json: string): MsgGroupDelay {
        return cast(JSON.parse(json), r("MsgGroupDelay"));
    }

    public static msgGroupDelayToJson(value: MsgGroupDelay): string {
        return JSON.stringify(uncast(value, r("MsgGroupDelay")), null, 2);
    }

    public static toMsgGroupMeta(json: string): MsgGroupMeta {
        return cast(JSON.parse(json), r("MsgGroupMeta"));
    }

    public static msgGroupMetaToJson(value: MsgGroupMeta): string {
        return JSON.stringify(uncast(value, r("MsgGroupMeta")), null, 2);
    }

    public static toMsgHeartbeat(json: string): MsgHeartbeat {
        return cast(JSON.parse(json), r("MsgHeartbeat"));
    }

    public static msgHeartbeatToJson(value: MsgHeartbeat): string {
        return JSON.stringify(uncast(value, r("MsgHeartbeat")), null, 2);
    }

    public static toMsgIarState(json: string): MsgIarState {
        return cast(JSON.parse(json), r("MsgIarState"));
    }

    public static msgIarStateToJson(value: MsgIarState): string {
        return JSON.stringify(uncast(value, r("MsgIarState")), null, 2);
    }

    public static toMsgImuAux(json: string): MsgImuAux {
        return cast(JSON.parse(json), r("MsgImuAux"));
    }

    public static msgImuAuxToJson(value: MsgImuAux): string {
        return JSON.stringify(uncast(value, r("MsgImuAux")), null, 2);
    }

    public static toMsgImuRaw(json: string): MsgImuRaw {
        return cast(JSON.parse(json), r("MsgImuRaw"));
    }

    public static msgImuRawToJson(value: MsgImuRaw): string {
        return JSON.stringify(uncast(value, r("MsgImuRaw")), null, 2);
    }

    public static toMsgInsStatus(json: string): MsgInsStatus {
        return cast(JSON.parse(json), r("MsgInsStatus"));
    }

    public static msgInsStatusToJson(value: MsgInsStatus): string {
        return JSON.stringify(uncast(value, r("MsgInsStatus")), null, 2);
    }

    public static toMsgInsUpdates(json: string): MsgInsUpdates {
        return cast(JSON.parse(json), r("MsgInsUpdates"));
    }

    public static msgInsUpdatesToJson(value: MsgInsUpdates): string {
        return JSON.stringify(uncast(value, r("MsgInsUpdates")), null, 2);
    }

    public static toMsgIono(json: string): MsgIono {
        return cast(JSON.parse(json), r("MsgIono"));
    }

    public static msgIonoToJson(value: MsgIono): string {
        return JSON.stringify(uncast(value, r("MsgIono")), null, 2);
    }

    public static toMsgLinuxCPUState(json: string): MsgLinuxCPUState {
        return cast(JSON.parse(json), r("MsgLinuxCPUState"));
    }

    public static msgLinuxCPUStateToJson(value: MsgLinuxCPUState): string {
        return JSON.stringify(uncast(value, r("MsgLinuxCPUState")), null, 2);
    }

    public static toMsgLinuxMemState(json: string): MsgLinuxMemState {
        return cast(JSON.parse(json), r("MsgLinuxMemState"));
    }

    public static msgLinuxMemStateToJson(value: MsgLinuxMemState): string {
        return JSON.stringify(uncast(value, r("MsgLinuxMemState")), null, 2);
    }

    public static toMsgLinuxProcessFdCount(json: string): MsgLinuxProcessFdCount {
        return cast(JSON.parse(json), r("MsgLinuxProcessFdCount"));
    }

    public static msgLinuxProcessFdCountToJson(value: MsgLinuxProcessFdCount): string {
        return JSON.stringify(uncast(value, r("MsgLinuxProcessFdCount")), null, 2);
    }

    public static toMsgLinuxProcessFdSummary(json: string): MsgLinuxProcessFdSummary {
        return cast(JSON.parse(json), r("MsgLinuxProcessFdSummary"));
    }

    public static msgLinuxProcessFdSummaryToJson(value: MsgLinuxProcessFdSummary): string {
        return JSON.stringify(uncast(value, r("MsgLinuxProcessFdSummary")), null, 2);
    }

    public static toMsgLinuxProcessSocketCounts(json: string): MsgLinuxProcessSocketCounts {
        return cast(JSON.parse(json), r("MsgLinuxProcessSocketCounts"));
    }

    public static msgLinuxProcessSocketCountsToJson(value: MsgLinuxProcessSocketCounts): string {
        return JSON.stringify(uncast(value, r("MsgLinuxProcessSocketCounts")), null, 2);
    }

    public static toMsgLinuxProcessSocketQueues(json: string): MsgLinuxProcessSocketQueues {
        return cast(JSON.parse(json), r("MsgLinuxProcessSocketQueues"));
    }

    public static msgLinuxProcessSocketQueuesToJson(value: MsgLinuxProcessSocketQueues): string {
        return JSON.stringify(uncast(value, r("MsgLinuxProcessSocketQueues")), null, 2);
    }

    public static toMsgLinuxSocketUsage(json: string): MsgLinuxSocketUsage {
        return cast(JSON.parse(json), r("MsgLinuxSocketUsage"));
    }

    public static msgLinuxSocketUsageToJson(value: MsgLinuxSocketUsage): string {
        return JSON.stringify(uncast(value, r("MsgLinuxSocketUsage")), null, 2);
    }

    public static toMsgLinuxSysState(json: string): MsgLinuxSysState {
        return cast(JSON.parse(json), r("MsgLinuxSysState"));
    }

    public static msgLinuxSysStateToJson(value: MsgLinuxSysState): string {
        return JSON.stringify(uncast(value, r("MsgLinuxSysState")), null, 2);
    }

    public static toMsgLog(json: string): MsgLog {
        return cast(JSON.parse(json), r("MsgLog"));
    }

    public static msgLogToJson(value: MsgLog): string {
        return JSON.stringify(uncast(value, r("MsgLog")), null, 2);
    }

    public static toMsgM25FlashWriteStatus(json: string): MsgM25FlashWriteStatus {
        return cast(JSON.parse(json), r("MsgM25FlashWriteStatus"));
    }

    public static msgM25FlashWriteStatusToJson(value: MsgM25FlashWriteStatus): string {
        return JSON.stringify(uncast(value, r("MsgM25FlashWriteStatus")), null, 2);
    }

    public static toMsgMagRaw(json: string): MsgMagRaw {
        return cast(JSON.parse(json), r("MsgMagRaw"));
    }

    public static msgMagRawToJson(value: MsgMagRaw): string {
        return JSON.stringify(uncast(value, r("MsgMagRaw")), null, 2);
    }

    public static toMsgMaskSatellite(json: string): MsgMaskSatellite {
        return cast(JSON.parse(json), r("MsgMaskSatellite"));
    }

    public static msgMaskSatelliteToJson(value: MsgMaskSatellite): string {
        return JSON.stringify(uncast(value, r("MsgMaskSatellite")), null, 2);
    }

    public static toMsgMeasurementState(json: string): MsgMeasurementState {
        return cast(JSON.parse(json), r("MsgMeasurementState"));
    }

    public static msgMeasurementStateToJson(value: MsgMeasurementState): string {
        return JSON.stringify(uncast(value, r("MsgMeasurementState")), null, 2);
    }

    public static toMsgNapDeviceDnaReq(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgNapDeviceDnaReqToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgNapDeviceDnaResp(json: string): MsgNapDeviceDnaResp {
        return cast(JSON.parse(json), r("MsgNapDeviceDnaResp"));
    }

    public static msgNapDeviceDnaRespToJson(value: MsgNapDeviceDnaResp): string {
        return JSON.stringify(uncast(value, r("MsgNapDeviceDnaResp")), null, 2);
    }

    public static toMsgNdbEvent(json: string): MsgNdbEvent {
        return cast(JSON.parse(json), r("MsgNdbEvent"));
    }

    public static msgNdbEventToJson(value: MsgNdbEvent): string {
        return JSON.stringify(uncast(value, r("MsgNdbEvent")), null, 2);
    }

    public static toMsgNetworkBandwidthUsage(json: string): MsgNetworkBandwidthUsage {
        return cast(JSON.parse(json), r("MsgNetworkBandwidthUsage"));
    }

    public static msgNetworkBandwidthUsageToJson(value: MsgNetworkBandwidthUsage): string {
        return JSON.stringify(uncast(value, r("MsgNetworkBandwidthUsage")), null, 2);
    }

    public static toMsgNetworkStateReq(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgNetworkStateReqToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgNetworkStateResp(json: string): MsgNetworkStateResp {
        return cast(JSON.parse(json), r("MsgNetworkStateResp"));
    }

    public static msgNetworkStateRespToJson(value: MsgNetworkStateResp): string {
        return JSON.stringify(uncast(value, r("MsgNetworkStateResp")), null, 2);
    }

    public static toMsgObs(json: string): MsgObs {
        return cast(JSON.parse(json), r("MsgObs"));
    }

    public static msgObsToJson(value: MsgObs): string {
        return JSON.stringify(uncast(value, r("MsgObs")), null, 2);
    }

    public static toMsgOdometry(json: string): MsgOdometry {
        return cast(JSON.parse(json), r("MsgOdometry"));
    }

    public static msgOdometryToJson(value: MsgOdometry): string {
        return JSON.stringify(uncast(value, r("MsgOdometry")), null, 2);
    }

    public static toMsgOrientEuler(json: string): MsgOrientEuler {
        return cast(JSON.parse(json), r("MsgOrientEuler"));
    }

    public static msgOrientEulerToJson(value: MsgOrientEuler): string {
        return JSON.stringify(uncast(value, r("MsgOrientEuler")), null, 2);
    }

    public static toMsgOrientQuat(json: string): MsgOrientQuat {
        return cast(JSON.parse(json), r("MsgOrientQuat"));
    }

    public static msgOrientQuatToJson(value: MsgOrientQuat): string {
        return JSON.stringify(uncast(value, r("MsgOrientQuat")), null, 2);
    }

    public static toMsgOsr(json: string): MsgOsr {
        return cast(JSON.parse(json), r("MsgOsr"));
    }

    public static msgOsrToJson(value: MsgOsr): string {
        return JSON.stringify(uncast(value, r("MsgOsr")), null, 2);
    }

    public static toMsgPosECEF(json: string): MsgPosECEF {
        return cast(JSON.parse(json), r("MsgPosECEF"));
    }

    public static msgPosECEFToJson(value: MsgPosECEF): string {
        return JSON.stringify(uncast(value, r("MsgPosECEF")), null, 2);
    }

    public static toMsgPosECEFCov(json: string): MsgPosECEFCov {
        return cast(JSON.parse(json), r("MsgPosECEFCov"));
    }

    public static msgPosECEFCovToJson(value: MsgPosECEFCov): string {
        return JSON.stringify(uncast(value, r("MsgPosECEFCov")), null, 2);
    }

    public static toMsgPosECEFCovGnss(json: string): MsgPosECEFCovGnss {
        return cast(JSON.parse(json), r("MsgPosECEFCovGnss"));
    }

    public static msgPosECEFCovGnssToJson(value: MsgPosECEFCovGnss): string {
        return JSON.stringify(uncast(value, r("MsgPosECEFCovGnss")), null, 2);
    }

    public static toMsgPosECEFGnss(json: string): MsgPosECEFGnss {
        return cast(JSON.parse(json), r("MsgPosECEFGnss"));
    }

    public static msgPosECEFGnssToJson(value: MsgPosECEFGnss): string {
        return JSON.stringify(uncast(value, r("MsgPosECEFGnss")), null, 2);
    }

    public static toMsgPosLLH(json: string): MsgPosLLH {
        return cast(JSON.parse(json), r("MsgPosLLH"));
    }

    public static msgPosLLHToJson(value: MsgPosLLH): string {
        return JSON.stringify(uncast(value, r("MsgPosLLH")), null, 2);
    }

    public static toMsgPosLLHAcc(json: string): MsgPosLLHAcc {
        return cast(JSON.parse(json), r("MsgPosLLHAcc"));
    }

    public static msgPosLLHAccToJson(value: MsgPosLLHAcc): string {
        return JSON.stringify(uncast(value, r("MsgPosLLHAcc")), null, 2);
    }

    public static toMsgPosLLHCov(json: string): MsgPosLLHCov {
        return cast(JSON.parse(json), r("MsgPosLLHCov"));
    }

    public static msgPosLLHCovToJson(value: MsgPosLLHCov): string {
        return JSON.stringify(uncast(value, r("MsgPosLLHCov")), null, 2);
    }

    public static toMsgPosLLHCovGnss(json: string): MsgPosLLHCovGnss {
        return cast(JSON.parse(json), r("MsgPosLLHCovGnss"));
    }

    public static msgPosLLHCovGnssToJson(value: MsgPosLLHCovGnss): string {
        return JSON.stringify(uncast(value, r("MsgPosLLHCovGnss")), null, 2);
    }

    public static toMsgPosLLHGnss(json: string): MsgPosLLHGnss {
        return cast(JSON.parse(json), r("MsgPosLLHGnss"));
    }

    public static msgPosLLHGnssToJson(value: MsgPosLLHGnss): string {
        return JSON.stringify(uncast(value, r("MsgPosLLHGnss")), null, 2);
    }

    public static toMsgPpsTime(json: string): MsgPpsTime {
        return cast(JSON.parse(json), r("MsgPpsTime"));
    }

    public static msgPpsTimeToJson(value: MsgPpsTime): string {
        return JSON.stringify(uncast(value, r("MsgPpsTime")), null, 2);
    }

    public static toMsgProtectionLevel(json: string): MsgProtectionLevel {
        return cast(JSON.parse(json), r("MsgProtectionLevel"));
    }

    public static msgProtectionLevelToJson(value: MsgProtectionLevel): string {
        return JSON.stringify(uncast(value, r("MsgProtectionLevel")), null, 2);
    }

    public static toMsgReset(json: string): MsgReset {
        return cast(JSON.parse(json), r("MsgReset"));
    }

    public static msgResetToJson(value: MsgReset): string {
        return JSON.stringify(uncast(value, r("MsgReset")), null, 2);
    }

    public static toMsgResetFilters(json: string): MsgResetFilters {
        return cast(JSON.parse(json), r("MsgResetFilters"));
    }

    public static msgResetFiltersToJson(value: MsgResetFilters): string {
        return JSON.stringify(uncast(value, r("MsgResetFilters")), null, 2);
    }

    public static toMsgSbasRaw(json: string): MsgSbasRaw {
        return cast(JSON.parse(json), r("MsgSbasRaw"));
    }

    public static msgSbasRawToJson(value: MsgSbasRaw): string {
        return JSON.stringify(uncast(value, r("MsgSbasRaw")), null, 2);
    }

    public static toMsgSetTime(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgSetTimeToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgSettingsReadByIndexDone(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgSettingsReadByIndexDoneToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgSettingsReadByIndexReq(json: string): MsgSettingsReadByIndexReq {
        return cast(JSON.parse(json), r("MsgSettingsReadByIndexReq"));
    }

    public static msgSettingsReadByIndexReqToJson(value: MsgSettingsReadByIndexReq): string {
        return JSON.stringify(uncast(value, r("MsgSettingsReadByIndexReq")), null, 2);
    }

    public static toMsgSettingsReadByIndexResp(json: string): MsgSettingsReadByIndexResp {
        return cast(JSON.parse(json), r("MsgSettingsReadByIndexResp"));
    }

    public static msgSettingsReadByIndexRespToJson(value: MsgSettingsReadByIndexResp): string {
        return JSON.stringify(uncast(value, r("MsgSettingsReadByIndexResp")), null, 2);
    }

    public static toMsgSettingsReadReq(json: string): MsgSettingsReadReq {
        return cast(JSON.parse(json), r("MsgSettingsReadReq"));
    }

    public static msgSettingsReadReqToJson(value: MsgSettingsReadReq): string {
        return JSON.stringify(uncast(value, r("MsgSettingsReadReq")), null, 2);
    }

    public static toMsgSettingsReadResp(json: string): MsgSettingsReadResp {
        return cast(JSON.parse(json), r("MsgSettingsReadResp"));
    }

    public static msgSettingsReadRespToJson(value: MsgSettingsReadResp): string {
        return JSON.stringify(uncast(value, r("MsgSettingsReadResp")), null, 2);
    }

    public static toMsgSettingsRegister(json: string): MsgSettingsRegister {
        return cast(JSON.parse(json), r("MsgSettingsRegister"));
    }

    public static msgSettingsRegisterToJson(value: MsgSettingsRegister): string {
        return JSON.stringify(uncast(value, r("MsgSettingsRegister")), null, 2);
    }

    public static toMsgSettingsRegisterResp(json: string): MsgSettingsRegisterResp {
        return cast(JSON.parse(json), r("MsgSettingsRegisterResp"));
    }

    public static msgSettingsRegisterRespToJson(value: MsgSettingsRegisterResp): string {
        return JSON.stringify(uncast(value, r("MsgSettingsRegisterResp")), null, 2);
    }

    public static toMsgSettingsSave(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgSettingsSaveToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgSettingsWrite(json: string): MsgSettingsWrite {
        return cast(JSON.parse(json), r("MsgSettingsWrite"));
    }

    public static msgSettingsWriteToJson(value: MsgSettingsWrite): string {
        return JSON.stringify(uncast(value, r("MsgSettingsWrite")), null, 2);
    }

    public static toMsgSettingsWriteResp(json: string): MsgSettingsWriteResp {
        return cast(JSON.parse(json), r("MsgSettingsWriteResp"));
    }

    public static msgSettingsWriteRespToJson(value: MsgSettingsWriteResp): string {
        return JSON.stringify(uncast(value, r("MsgSettingsWriteResp")), null, 2);
    }

    public static toMsgSolnMeta(json: string): MsgSolnMeta {
        return cast(JSON.parse(json), r("MsgSolnMeta"));
    }

    public static msgSolnMetaToJson(value: MsgSolnMeta): string {
        return JSON.stringify(uncast(value, r("MsgSolnMeta")), null, 2);
    }

    public static toMsgSpecan(json: string): MsgSpecan {
        return cast(JSON.parse(json), r("MsgSpecan"));
    }

    public static msgSpecanToJson(value: MsgSpecan): string {
        return JSON.stringify(uncast(value, r("MsgSpecan")), null, 2);
    }

    public static toMsgSsrCodeBiases(json: string): MsgSsrCodeBiases {
        return cast(JSON.parse(json), r("MsgSsrCodeBiases"));
    }

    public static msgSsrCodeBiasesToJson(value: MsgSsrCodeBiases): string {
        return JSON.stringify(uncast(value, r("MsgSsrCodeBiases")), null, 2);
    }

    public static toMsgSsrGriddedCorrection(json: string): MsgSsrGriddedCorrection {
        return cast(JSON.parse(json), r("MsgSsrGriddedCorrection"));
    }

    public static msgSsrGriddedCorrectionToJson(value: MsgSsrGriddedCorrection): string {
        return JSON.stringify(uncast(value, r("MsgSsrGriddedCorrection")), null, 2);
    }

    public static toMsgSsrOrbitClock(json: string): MsgSsrOrbitClock {
        return cast(JSON.parse(json), r("MsgSsrOrbitClock"));
    }

    public static msgSsrOrbitClockToJson(value: MsgSsrOrbitClock): string {
        return JSON.stringify(uncast(value, r("MsgSsrOrbitClock")), null, 2);
    }

    public static toMsgSsrPhaseBiases(json: string): MsgSsrPhaseBiases {
        return cast(JSON.parse(json), r("MsgSsrPhaseBiases"));
    }

    public static msgSsrPhaseBiasesToJson(value: MsgSsrPhaseBiases): string {
        return JSON.stringify(uncast(value, r("MsgSsrPhaseBiases")), null, 2);
    }

    public static toMsgSsrSatelliteApc(json: string): MsgSsrSatelliteApc {
        return cast(JSON.parse(json), r("MsgSsrSatelliteApc"));
    }

    public static msgSsrSatelliteApcToJson(value: MsgSsrSatelliteApc): string {
        return JSON.stringify(uncast(value, r("MsgSsrSatelliteApc")), null, 2);
    }

    public static toMsgSsrStecCorrection(json: string): MsgSsrStecCorrection {
        return cast(JSON.parse(json), r("MsgSsrStecCorrection"));
    }

    public static msgSsrStecCorrectionToJson(value: MsgSsrStecCorrection): string {
        return JSON.stringify(uncast(value, r("MsgSsrStecCorrection")), null, 2);
    }

    public static toMsgSsrTileDefinition(json: string): MsgSsrTileDefinition {
        return cast(JSON.parse(json), r("MsgSsrTileDefinition"));
    }

    public static msgSsrTileDefinitionToJson(value: MsgSsrTileDefinition): string {
        return JSON.stringify(uncast(value, r("MsgSsrTileDefinition")), null, 2);
    }

    public static toMsgStartup(json: string): MsgStartup {
        return cast(JSON.parse(json), r("MsgStartup"));
    }

    public static msgStartupToJson(value: MsgStartup): string {
        return JSON.stringify(uncast(value, r("MsgStartup")), null, 2);
    }

    public static toMsgStatusReport(json: string): MsgStatusReport {
        return cast(JSON.parse(json), r("MsgStatusReport"));
    }

    public static msgStatusReportToJson(value: MsgStatusReport): string {
        return JSON.stringify(uncast(value, r("MsgStatusReport")), null, 2);
    }

    public static toMsgStmFlashLockSector(json: string): MsgStmFlashLockSector {
        return cast(JSON.parse(json), r("MsgStmFlashLockSector"));
    }

    public static msgStmFlashLockSectorToJson(value: MsgStmFlashLockSector): string {
        return JSON.stringify(uncast(value, r("MsgStmFlashLockSector")), null, 2);
    }

    public static toMsgStmFlashUnlockSector(json: string): MsgStmFlashUnlockSector {
        return cast(JSON.parse(json), r("MsgStmFlashUnlockSector"));
    }

    public static msgStmFlashUnlockSectorToJson(value: MsgStmFlashUnlockSector): string {
        return JSON.stringify(uncast(value, r("MsgStmFlashUnlockSector")), null, 2);
    }

    public static toMsgStmUniqueIDReq(json: string): { [key: string]: any } {
        return cast(JSON.parse(json), m("any"));
    }

    public static msgStmUniqueIDReqToJson(value: { [key: string]: any }): string {
        return JSON.stringify(uncast(value, m("any")), null, 2);
    }

    public static toMsgStmUniqueIDResp(json: string): MsgStmUniqueIDResp {
        return cast(JSON.parse(json), r("MsgStmUniqueIDResp"));
    }

    public static msgStmUniqueIDRespToJson(value: MsgStmUniqueIDResp): string {
        return JSON.stringify(uncast(value, r("MsgStmUniqueIDResp")), null, 2);
    }

    public static toMsgSvAzEl(json: string): MsgSvAzEl {
        return cast(JSON.parse(json), r("MsgSvAzEl"));
    }

    public static msgSvAzElToJson(value: MsgSvAzEl): string {
        return JSON.stringify(uncast(value, r("MsgSvAzEl")), null, 2);
    }

    public static toMsgThreadState(json: string): MsgThreadState {
        return cast(JSON.parse(json), r("MsgThreadState"));
    }

    public static msgThreadStateToJson(value: MsgThreadState): string {
        return JSON.stringify(uncast(value, r("MsgThreadState")), null, 2);
    }

    public static toMsgTrackingIq(json: string): MsgTrackingIq {
        return cast(JSON.parse(json), r("MsgTrackingIq"));
    }

    public static msgTrackingIqToJson(value: MsgTrackingIq): string {
        return JSON.stringify(uncast(value, r("MsgTrackingIq")), null, 2);
    }

    public static toMsgTrackingState(json: string): MsgTrackingState {
        return cast(JSON.parse(json), r("MsgTrackingState"));
    }

    public static msgTrackingStateToJson(value: MsgTrackingState): string {
        return JSON.stringify(uncast(value, r("MsgTrackingState")), null, 2);
    }

    public static toMsgUARTState(json: string): MsgUARTState {
        return cast(JSON.parse(json), r("MsgUARTState"));
    }

    public static msgUARTStateToJson(value: MsgUARTState): string {
        return JSON.stringify(uncast(value, r("MsgUARTState")), null, 2);
    }

    public static toMsgUserData(json: string): MsgUserData {
        return cast(JSON.parse(json), r("MsgUserData"));
    }

    public static msgUserDataToJson(value: MsgUserData): string {
        return JSON.stringify(uncast(value, r("MsgUserData")), null, 2);
    }

    public static toMsgUTCTime(json: string): MsgUTCTime {
        return cast(JSON.parse(json), r("MsgUTCTime"));
    }

    public static msgUTCTimeToJson(value: MsgUTCTime): string {
        return JSON.stringify(uncast(value, r("MsgUTCTime")), null, 2);
    }

    public static toMsgUTCTimeGnss(json: string): MsgUTCTimeGnss {
        return cast(JSON.parse(json), r("MsgUTCTimeGnss"));
    }

    public static msgUTCTimeGnssToJson(value: MsgUTCTimeGnss): string {
        return JSON.stringify(uncast(value, r("MsgUTCTimeGnss")), null, 2);
    }

    public static toMsgVelBody(json: string): MsgVelBody {
        return cast(JSON.parse(json), r("MsgVelBody"));
    }

    public static msgVelBodyToJson(value: MsgVelBody): string {
        return JSON.stringify(uncast(value, r("MsgVelBody")), null, 2);
    }

    public static toMsgVelECEF(json: string): MsgVelECEF {
        return cast(JSON.parse(json), r("MsgVelECEF"));
    }

    public static msgVelECEFToJson(value: MsgVelECEF): string {
        return JSON.stringify(uncast(value, r("MsgVelECEF")), null, 2);
    }

    public static toMsgVelECEFCov(json: string): MsgVelECEFCov {
        return cast(JSON.parse(json), r("MsgVelECEFCov"));
    }

    public static msgVelECEFCovToJson(value: MsgVelECEFCov): string {
        return JSON.stringify(uncast(value, r("MsgVelECEFCov")), null, 2);
    }

    public static toMsgVelECEFCovGnss(json: string): MsgVelECEFCovGnss {
        return cast(JSON.parse(json), r("MsgVelECEFCovGnss"));
    }

    public static msgVelECEFCovGnssToJson(value: MsgVelECEFCovGnss): string {
        return JSON.stringify(uncast(value, r("MsgVelECEFCovGnss")), null, 2);
    }

    public static toMsgVelECEFGnss(json: string): MsgVelECEFGnss {
        return cast(JSON.parse(json), r("MsgVelECEFGnss"));
    }

    public static msgVelECEFGnssToJson(value: MsgVelECEFGnss): string {
        return JSON.stringify(uncast(value, r("MsgVelECEFGnss")), null, 2);
    }

    public static toMsgVelNED(json: string): MsgVelNED {
        return cast(JSON.parse(json), r("MsgVelNED"));
    }

    public static msgVelNEDToJson(value: MsgVelNED): string {
        return JSON.stringify(uncast(value, r("MsgVelNED")), null, 2);
    }

    public static toMsgVelNEDCov(json: string): MsgVelNEDCov {
        return cast(JSON.parse(json), r("MsgVelNEDCov"));
    }

    public static msgVelNEDCovToJson(value: MsgVelNEDCov): string {
        return JSON.stringify(uncast(value, r("MsgVelNEDCov")), null, 2);
    }

    public static toMsgVelNEDCovGnss(json: string): MsgVelNEDCovGnss {
        return cast(JSON.parse(json), r("MsgVelNEDCovGnss"));
    }

    public static msgVelNEDCovGnssToJson(value: MsgVelNEDCovGnss): string {
        return JSON.stringify(uncast(value, r("MsgVelNEDCovGnss")), null, 2);
    }

    public static toMsgVelNEDGnss(json: string): MsgVelNEDGnss {
        return cast(JSON.parse(json), r("MsgVelNEDGnss"));
    }

    public static msgVelNEDGnssToJson(value: MsgVelNEDGnss): string {
        return JSON.stringify(uncast(value, r("MsgVelNEDGnss")), null, 2);
    }

    public static toMsgWheeltick(json: string): MsgWheeltick {
        return cast(JSON.parse(json), r("MsgWheeltick"));
    }

    public static msgWheeltickToJson(value: MsgWheeltick): string {
        return JSON.stringify(uncast(value, r("MsgWheeltick")), null, 2);
    }

    public static toNetworkUsage(json: string): NetworkUsage {
        return cast(JSON.parse(json), r("NetworkUsage"));
    }

    public static networkUsageToJson(value: NetworkUsage): string {
        return JSON.stringify(uncast(value, r("NetworkUsage")), null, 2);
    }

    public static toObservationHeader(json: string): ObservationHeader {
        return cast(JSON.parse(json), r("ObservationHeader"));
    }

    public static observationHeaderToJson(value: ObservationHeader): string {
        return JSON.stringify(uncast(value, r("ObservationHeader")), null, 2);
    }

    public static toOdoInputType(json: string): OdoInputType {
        return cast(JSON.parse(json), r("OdoInputType"));
    }

    public static odoInputTypeToJson(value: OdoInputType): string {
        return JSON.stringify(uncast(value, r("OdoInputType")), null, 2);
    }

    public static toPackedObsContent(json: string): PackedObsContent {
        return cast(JSON.parse(json), r("PackedObsContent"));
    }

    public static packedObsContentToJson(value: PackedObsContent): string {
        return JSON.stringify(uncast(value, r("PackedObsContent")), null, 2);
    }

    public static toPackedOsrContent(json: string): PackedOsrContent {
        return cast(JSON.parse(json), r("PackedOsrContent"));
    }

    public static packedOsrContentToJson(value: PackedOsrContent): string {
        return JSON.stringify(uncast(value, r("PackedOsrContent")), null, 2);
    }

    public static toPeriod(json: string): Period {
        return cast(JSON.parse(json), r("Period"));
    }

    public static periodToJson(value: Period): string {
        return JSON.stringify(uncast(value, r("Period")), null, 2);
    }

    public static toPhaseBiasesContent(json: string): PhaseBiasesContent {
        return cast(JSON.parse(json), r("PhaseBiasesContent"));
    }

    public static phaseBiasesContentToJson(value: PhaseBiasesContent): string {
        return JSON.stringify(uncast(value, r("PhaseBiasesContent")), null, 2);
    }

    public static toSTECHeader(json: string): STECHeader {
        return cast(JSON.parse(json), r("STECHeader"));
    }

    public static sTECHeaderToJson(value: STECHeader): string {
        return JSON.stringify(uncast(value, r("STECHeader")), null, 2);
    }

    public static toSTECResidual(json: string): STECResidual {
        return cast(JSON.parse(json), r("STECResidual"));
    }

    public static sTECResidualToJson(value: STECResidual): string {
        return JSON.stringify(uncast(value, r("STECResidual")), null, 2);
    }

    public static toSTECResidualNoStd(json: string): STECResidualNoStd {
        return cast(JSON.parse(json), r("STECResidualNoStd"));
    }

    public static sTECResidualNoStdToJson(value: STECResidualNoStd): string {
        return JSON.stringify(uncast(value, r("STECResidualNoStd")), null, 2);
    }

    public static toSTECSatElement(json: string): STECSatElement {
        return cast(JSON.parse(json), r("STECSatElement"));
    }

    public static sTECSatElementToJson(value: STECSatElement): string {
        return JSON.stringify(uncast(value, r("STECSatElement")), null, 2);
    }

    public static toSatelliteAPC(json: string): SatelliteAPC {
        return cast(JSON.parse(json), r("SatelliteAPC"));
    }

    public static satelliteAPCToJson(value: SatelliteAPC): string {
        return JSON.stringify(uncast(value, r("SatelliteAPC")), null, 2);
    }

    public static toSolutionInputType(json: string): SolutionInputType {
        return cast(JSON.parse(json), r("SolutionInputType"));
    }

    public static solutionInputTypeToJson(value: SolutionInputType): string {
        return JSON.stringify(uncast(value, r("SolutionInputType")), null, 2);
    }

    public static toSubSystemReport(json: string): SubSystemReport {
        return cast(JSON.parse(json), r("SubSystemReport"));
    }

    public static subSystemReportToJson(value: SubSystemReport): string {
        return JSON.stringify(uncast(value, r("SubSystemReport")), null, 2);
    }

    public static toSvAzEl(json: string): SvAzEl {
        return cast(JSON.parse(json), r("SvAzEl"));
    }

    public static svAzElToJson(value: SvAzEl): string {
        return JSON.stringify(uncast(value, r("SvAzEl")), null, 2);
    }

    public static toSvID(json: string): SvID {
        return cast(JSON.parse(json), r("SvID"));
    }

    public static svIDToJson(value: SvID): string {
        return JSON.stringify(uncast(value, r("SvID")), null, 2);
    }

    public static toTrackingChannelCorrelation(json: string): TrackingChannelCorrelation {
        return cast(JSON.parse(json), r("TrackingChannelCorrelation"));
    }

    public static trackingChannelCorrelationToJson(value: TrackingChannelCorrelation): string {
        return JSON.stringify(uncast(value, r("TrackingChannelCorrelation")), null, 2);
    }

    public static toTrackingChannelState(json: string): TrackingChannelState {
        return cast(JSON.parse(json), r("TrackingChannelState"));
    }

    public static trackingChannelStateToJson(value: TrackingChannelState): string {
        return JSON.stringify(uncast(value, r("TrackingChannelState")), null, 2);
    }

    public static toTroposphericDelayCorrection(json: string): TroposphericDelayCorrection {
        return cast(JSON.parse(json), r("TroposphericDelayCorrection"));
    }

    public static troposphericDelayCorrectionToJson(value: TroposphericDelayCorrection): string {
        return JSON.stringify(uncast(value, r("TroposphericDelayCorrection")), null, 2);
    }

    public static toTroposphericDelayCorrectionNoStd(json: string): TroposphericDelayCorrectionNoStd {
        return cast(JSON.parse(json), r("TroposphericDelayCorrectionNoStd"));
    }

    public static troposphericDelayCorrectionNoStdToJson(value: TroposphericDelayCorrectionNoStd): string {
        return JSON.stringify(uncast(value, r("TroposphericDelayCorrectionNoStd")), null, 2);
    }

    public static toUARTChannel(json: string): UARTChannel {
        return cast(JSON.parse(json), r("UARTChannel"));
    }

    public static uARTChannelToJson(value: UARTChannel): string {
        return JSON.stringify(uncast(value, r("UARTChannel")), null, 2);
    }
}

function invalidValue(typ: any, val: any, key: any = ''): never {
    if (key) {
        throw Error(`Invalid value for key "${key}". Expected type ${JSON.stringify(typ)} but got ${JSON.stringify(val)}`);
    }
    throw Error(`Invalid value ${JSON.stringify(val)} for type ${JSON.stringify(typ)}`, );
}

function jsonToJSProps(typ: any): any {
    if (typ.jsonToJS === undefined) {
        const map: any = {};
        typ.props.forEach((p: any) => map[p.json] = { key: p.js, typ: p.typ });
        typ.jsonToJS = map;
    }
    return typ.jsonToJS;
}

function jsToJSONProps(typ: any): any {
    if (typ.jsToJSON === undefined) {
        const map: any = {};
        typ.props.forEach((p: any) => map[p.js] = { key: p.json, typ: p.typ });
        typ.jsToJSON = map;
    }
    return typ.jsToJSON;
}

function transform(val: any, typ: any, getProps: any, key: any = ''): any {
    function transformPrimitive(typ: string, val: any): any {
        if (typeof typ === typeof val) return val;
        return invalidValue(typ, val, key);
    }

    function transformUnion(typs: any[], val: any): any {
        // val must validate against one typ in typs
        const l = typs.length;
        for (let i = 0; i < l; i++) {
            const typ = typs[i];
            try {
                return transform(val, typ, getProps);
            } catch (_) {}
        }
        return invalidValue(typs, val);
    }

    function transformEnum(cases: string[], val: any): any {
        if (cases.indexOf(val) !== -1) return val;
        return invalidValue(cases, val);
    }

    function transformArray(typ: any, val: any): any {
        // val must be an array with no invalid elements
        if (!Array.isArray(val)) return invalidValue("array", val);
        return val.map(el => transform(el, typ, getProps));
    }

    function transformDate(val: any): any {
        if (val === null) {
            return null;
        }
        const d = new Date(val);
        if (isNaN(d.valueOf())) {
            return invalidValue("Date", val);
        }
        return d;
    }

    function transformObject(props: { [k: string]: any }, additional: any, val: any): any {
        if (val === null || typeof val !== "object" || Array.isArray(val)) {
            return invalidValue("object", val);
        }
        const result: any = {};
        Object.getOwnPropertyNames(props).forEach(key => {
            const prop = props[key];
            const v = Object.prototype.hasOwnProperty.call(val, key) ? val[key] : undefined;
            result[prop.key] = transform(v, prop.typ, getProps, prop.key);
        });
        Object.getOwnPropertyNames(val).forEach(key => {
            if (!Object.prototype.hasOwnProperty.call(props, key)) {
                result[key] = transform(val[key], additional, getProps, key);
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
    if (typ === Date && typeof val !== "number") return transformDate(val);
    return transformPrimitive(typ, val);
}

function cast<T>(val: any, typ: any): T {
    return transform(val, typ, jsonToJSProps);
}

function uncast<T>(val: T, typ: any): any {
    return transform(val, typ, jsToJSONProps);
}

function a(typ: any) {
    return { arrayItems: typ };
}

function u(...typs: any[]) {
    return { unionMembers: typs };
}

function o(props: any[], additional: any) {
    return { props, additional };
}

function m(additional: any) {
    return { props: [], additional };
}

function r(name: string) {
    return { ref: name };
}

const typeMap: any = {
    "GNSSInputType": o([
        { json: "flags", js: "flags", typ: 0 },
    ], "any"),
    "GridElementNoStd": o([
        { json: "index", js: "index", typ: 0 },
        { json: "stec_residuals", js: "stec_residuals", typ: a(r("STECResidualNoStd")) },
        { json: "tropo_delay_correction", js: "tropo_delay_correction", typ: r("TroposphericDelayCorrectionNoStd") },
    ], "any"),
    "STECResidualNoStd": o([
        { json: "residual", js: "residual", typ: 0 },
        { json: "sv_id", js: "sv_id", typ: r("SvID") },
    ], "any"),
    "SvID": o([
        { json: "constellation", js: "constellation", typ: 0 },
        { json: "satId", js: "satId", typ: 0 },
    ], "any"),
    "TroposphericDelayCorrectionNoStd": o([
        { json: "hydro", js: "hydro", typ: 0 },
        { json: "wet", js: "wet", typ: 0 },
    ], "any"),
    "IMUInputType": o([
        { json: "flags", js: "flags", typ: 0 },
    ], "any"),
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
    "MsgAngularRate": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 0 },
        { json: "y", js: "y", typ: 0 },
        { json: "z", js: "z", typ: 0 },
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
        { json: "fwd_payload", js: "fwd_payload", typ: a(0) },
        { json: "protocol", js: "protocol", typ: 0 },
        { json: "source", js: "source", typ: 0 },
    ], "any"),
    "MsgGPSTime": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "ns_residual", js: "ns_residual", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "wn", js: "wn", typ: 0 },
    ], "any"),
    "MsgGPSTimeGnss": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "ns_residual", js: "ns_residual", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "wn", js: "wn", typ: 0 },
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
    "MsgGnssTimeOffset": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "microseconds", js: "microseconds", typ: 0 },
        { json: "milliseconds", js: "milliseconds", typ: 0 },
        { json: "weeks", js: "weeks", typ: 0 },
    ], "any"),
    "MsgGroupDelay": o([
        { json: "isc_l1ca", js: "isc_l1ca", typ: 0 },
        { json: "isc_l2c", js: "isc_l2c", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "t_op", js: "t_op", typ: r("GpsTimeSEC") },
        { json: "tgd", js: "tgd", typ: 0 },
        { json: "valid", js: "valid", typ: 0 },
    ], "any"),
    "MsgGroupMeta": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "group_id", js: "group_id", typ: 0 },
        { json: "group_msgs", js: "group_msgs", typ: a(0) },
        { json: "n_group_msgs", js: "n_group_msgs", typ: 0 },
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
    "MsgInsUpdates": o([
        { json: "gnsspos", js: "gnsspos", typ: 0 },
        { json: "gnssvel", js: "gnssvel", typ: 0 },
        { json: "nhc", js: "nhc", typ: 0 },
        { json: "speed", js: "speed", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "wheelticks", js: "wheelticks", typ: 0 },
        { json: "zerovel", js: "zerovel", typ: 0 },
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
        { json: "flags", js: "flags", typ: 0 },
        { json: "index", js: "index", typ: 0 },
        { json: "pcpu", js: "pcpu", typ: 0 },
        { json: "pid", js: "pid", typ: 0 },
        { json: "time", js: "time", typ: 0 },
        { json: "tname", js: "tname", typ: "" },
    ], "any"),
    "MsgLinuxMemState": o([
        { json: "cmdline", js: "cmdline", typ: "" },
        { json: "flags", js: "flags", typ: 0 },
        { json: "index", js: "index", typ: 0 },
        { json: "pid", js: "pid", typ: 0 },
        { json: "pmem", js: "pmem", typ: 0 },
        { json: "time", js: "time", typ: 0 },
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
        { json: "flags", js: "flags", typ: 0 },
        { json: "mem_total", js: "mem_total", typ: 0 },
        { json: "pcpu", js: "pcpu", typ: 0 },
        { json: "pid_count", js: "pid_count", typ: 0 },
        { json: "pmem", js: "pmem", typ: 0 },
        { json: "procs_starting", js: "procs_starting", typ: 0 },
        { json: "procs_stopping", js: "procs_stopping", typ: 0 },
        { json: "time", js: "time", typ: 0 },
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
    "MsgPosECEF": o([
        { json: "accuracy", js: "accuracy", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 3.14 },
        { json: "y", js: "y", typ: 3.14 },
        { json: "z", js: "z", typ: 3.14 },
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
    "MsgPosECEFCovGnss": o([
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
    "MsgPosECEFGnss": o([
        { json: "accuracy", js: "accuracy", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 3.14 },
        { json: "y", js: "y", typ: 3.14 },
        { json: "z", js: "z", typ: 3.14 },
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
    "MsgPosLLHAcc": o([
        { json: "at_accuracy", js: "at_accuracy", typ: 3.14 },
        { json: "confidence_and_geoid", js: "confidence_and_geoid", typ: 0 },
        { json: "ct_accuracy", js: "ct_accuracy", typ: 3.14 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "h_accuracy", js: "h_accuracy", typ: 3.14 },
        { json: "h_ellipse", js: "h_ellipse", typ: r("EstimatedHorizontalErrorEllipse") },
        { json: "height", js: "height", typ: 3.14 },
        { json: "lat", js: "lat", typ: 3.14 },
        { json: "lon", js: "lon", typ: 3.14 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "orthometric_height", js: "orthometric_height", typ: 3.14 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "v_accuracy", js: "v_accuracy", typ: 3.14 },
    ], "any"),
    "EstimatedHorizontalErrorEllipse": o([
        { json: "orientation", js: "orientation", typ: 3.14 },
        { json: "semi_major", js: "semi_major", typ: 3.14 },
        { json: "semi_minor", js: "semi_minor", typ: 3.14 },
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
    "MsgPosLLHCovGnss": o([
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
    "MsgPosLLHGnss": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "h_accuracy", js: "h_accuracy", typ: 0 },
        { json: "height", js: "height", typ: 3.14 },
        { json: "lat", js: "lat", typ: 3.14 },
        { json: "lon", js: "lon", typ: 3.14 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "v_accuracy", js: "v_accuracy", typ: 0 },
    ], "any"),
    "MsgPpsTime": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "time", js: "time", typ: 0 },
    ], "any"),
    "MsgProtectionLevel": o([
        { json: "atpl", js: "atpl", typ: 0 },
        { json: "ctpl", js: "ctpl", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "heading", js: "heading", typ: 0 },
        { json: "height", js: "height", typ: 3.14 },
        { json: "hopl", js: "hopl", typ: 0 },
        { json: "hpl", js: "hpl", typ: 0 },
        { json: "hvpl", js: "hvpl", typ: 0 },
        { json: "lat", js: "lat", typ: 3.14 },
        { json: "lon", js: "lon", typ: 3.14 },
        { json: "pitch", js: "pitch", typ: 0 },
        { json: "popl", js: "popl", typ: 0 },
        { json: "roll", js: "roll", typ: 0 },
        { json: "ropl", js: "ropl", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "v_x", js: "v_x", typ: 0 },
        { json: "v_y", js: "v_y", typ: 0 },
        { json: "v_z", js: "v_z", typ: 0 },
        { json: "vpl", js: "vpl", typ: 0 },
        { json: "vvpl", js: "vvpl", typ: 0 },
        { json: "wn", js: "wn", typ: 0 },
    ], "any"),
    "MsgReset": o([
        { json: "flags", js: "flags", typ: 0 },
    ], "any"),
    "MsgResetFilters": o([
        { json: "filter", js: "filter", typ: 0 },
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
    "MsgSolnMeta": o([
        { json: "age_corrections", js: "age_corrections", typ: 0 },
        { json: "age_gnss", js: "age_gnss", typ: 0 },
        { json: "hdop", js: "hdop", typ: 0 },
        { json: "pdop", js: "pdop", typ: 0 },
        { json: "sol_in", js: "sol_in", typ: a(r("SolutionInputType")) },
        { json: "tow", js: "tow", typ: 0 },
        { json: "vdop", js: "vdop", typ: 0 },
    ], "any"),
    "SolutionInputType": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "sensor_type", js: "sensor_type", typ: 0 },
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
        { json: "stddev", js: "stddev", typ: 0 },
        { json: "sv_id", js: "sv_id", typ: r("SvID") },
    ], "any"),
    "TroposphericDelayCorrection": o([
        { json: "hydro", js: "hydro", typ: 0 },
        { json: "stddev", js: "stddev", typ: 0 },
        { json: "wet", js: "wet", typ: 0 },
    ], "any"),
    "GriddedCorrectionHeader": o([
        { json: "iod_atmo", js: "iod_atmo", typ: 0 },
        { json: "num_msgs", js: "num_msgs", typ: 0 },
        { json: "seq_num", js: "seq_num", typ: 0 },
        { json: "tile_id", js: "tile_id", typ: 0 },
        { json: "tile_set_id", js: "tile_set_id", typ: 0 },
        { json: "time", js: "time", typ: r("GpsTimeSEC") },
        { json: "tropo_quality_indicator", js: "tropo_quality_indicator", typ: 0 },
        { json: "update_interval", js: "update_interval", typ: 0 },
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
    "MsgSsrSatelliteApc": o([
        { json: "apc", js: "apc", typ: a(r("SatelliteAPC")) },
    ], "any"),
    "SatelliteAPC": o([
        { json: "pco", js: "pco", typ: a(0) },
        { json: "pcv", js: "pcv", typ: a(0) },
        { json: "sat_info", js: "sat_info", typ: 0 },
        { json: "sid", js: "sid", typ: r("GnssSignal") },
        { json: "svn", js: "svn", typ: 0 },
    ], "any"),
    "MsgSsrStecCorrection": o([
        { json: "header", js: "header", typ: r("STECHeader") },
        { json: "stec_sat_list", js: "stec_sat_list", typ: a(r("STECSatElement")) },
    ], "any"),
    "STECHeader": o([
        { json: "iod_atmo", js: "iod_atmo", typ: 0 },
        { json: "num_msgs", js: "num_msgs", typ: 0 },
        { json: "seq_num", js: "seq_num", typ: 0 },
        { json: "tile_id", js: "tile_id", typ: 0 },
        { json: "tile_set_id", js: "tile_set_id", typ: 0 },
        { json: "time", js: "time", typ: r("GpsTimeSEC") },
        { json: "update_interval", js: "update_interval", typ: 0 },
    ], "any"),
    "STECSatElement": o([
        { json: "stec_coeff", js: "stec_coeff", typ: a(0) },
        { json: "stec_quality_indicator", js: "stec_quality_indicator", typ: 0 },
        { json: "sv_id", js: "sv_id", typ: r("SvID") },
    ], "any"),
    "MsgSsrTileDefinition": o([
        { json: "bitmask", js: "bitmask", typ: 0 },
        { json: "cols", js: "cols", typ: 0 },
        { json: "corner_nw_lat", js: "corner_nw_lat", typ: 0 },
        { json: "corner_nw_lon", js: "corner_nw_lon", typ: 0 },
        { json: "rows", js: "rows", typ: 0 },
        { json: "spacing_lat", js: "spacing_lat", typ: 0 },
        { json: "spacing_lon", js: "spacing_lon", typ: 0 },
        { json: "tile_id", js: "tile_id", typ: 0 },
        { json: "tile_set_id", js: "tile_set_id", typ: 0 },
    ], "any"),
    "MsgStartup": o([
        { json: "cause", js: "cause", typ: 0 },
        { json: "startup_type", js: "startup_type", typ: 0 },
    ], "any"),
    "MsgStatusReport": o([
        { json: "reporting_system", js: "reporting_system", typ: 0 },
        { json: "sbp_version", js: "sbp_version", typ: 0 },
        { json: "sequence", js: "sequence", typ: 0 },
        { json: "status", js: "status", typ: a(r("SubSystemReport")) },
        { json: "uptime", js: "uptime", typ: 0 },
    ], "any"),
    "SubSystemReport": o([
        { json: "component", js: "component", typ: 0 },
        { json: "generic", js: "generic", typ: 0 },
        { json: "specific", js: "specific", typ: 0 },
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
    "MsgUTCTimeGnss": o([
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
    "MsgVelECEF": o([
        { json: "accuracy", js: "accuracy", typ: 0 },
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
    "MsgVelECEFCovGnss": o([
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
    "MsgVelECEFGnss": o([
        { json: "accuracy", js: "accuracy", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "x", js: "x", typ: 0 },
        { json: "y", js: "y", typ: 0 },
        { json: "z", js: "z", typ: 0 },
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
    "MsgVelNEDCovGnss": o([
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
    "MsgVelNEDGnss": o([
        { json: "d", js: "d", typ: 0 },
        { json: "e", js: "e", typ: 0 },
        { json: "flags", js: "flags", typ: 0 },
        { json: "h_accuracy", js: "h_accuracy", typ: 0 },
        { json: "n", js: "n", typ: 0 },
        { json: "n_sats", js: "n_sats", typ: 0 },
        { json: "tow", js: "tow", typ: 0 },
        { json: "v_accuracy", js: "v_accuracy", typ: 0 },
    ], "any"),
    "MsgWheeltick": o([
        { json: "flags", js: "flags", typ: 0 },
        { json: "source", js: "source", typ: 0 },
        { json: "ticks", js: "ticks", typ: 0 },
        { json: "time", js: "time", typ: 0 },
    ], "any"),
    "OdoInputType": o([
        { json: "flags", js: "flags", typ: 0 },
    ], "any"),
};
