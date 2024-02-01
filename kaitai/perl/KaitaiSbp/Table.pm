# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Automatically generated with generate.py.  Do not hand edit!

use strict;
use warnings;
use KaitaiSbp::Sbp;

use KaitaiSbp::Acquisition;
use KaitaiSbp::Bootload;
use KaitaiSbp::ExtEvents;
use KaitaiSbp::FileIo;
use KaitaiSbp::Flash;
use KaitaiSbp::Gnss;
use KaitaiSbp::Imu;
use KaitaiSbp::Integrity;
use KaitaiSbp::Linux;
use KaitaiSbp::Logging;
use KaitaiSbp::Mag;
use KaitaiSbp::Navigation;
use KaitaiSbp::Ndb;
use KaitaiSbp::Observation;
use KaitaiSbp::Orientation;
use KaitaiSbp::Piksi;
use KaitaiSbp::Profiling;
use KaitaiSbp::Sbas;
use KaitaiSbp::Settings;
use KaitaiSbp::Signing;
use KaitaiSbp::SolutionMeta;
use KaitaiSbp::Ssr;
use KaitaiSbp::System;
use KaitaiSbp::Telemetry;
use KaitaiSbp::Tracking;
use KaitaiSbp::User;
use KaitaiSbp::Vehicle;

package Table::SbpMessage;

our @ISA = 'Sbp::SbpMessage';

our %TABLE = (

  
    47 => sub{Acquisition::MsgAcqResult->new(@_)},
    31 => sub{Acquisition::MsgAcqResultDepC->new(@_)},
    20 => sub{Acquisition::MsgAcqResultDepB->new(@_)},
    21 => sub{Acquisition::MsgAcqResultDepA->new(@_)},
    46 => sub{Acquisition::MsgAcqSvProfile->new(@_)},
    30 => sub{Acquisition::MsgAcqSvProfileDep->new(@_)},
  
    179 => sub{Bootload::MsgBootloaderHandshakeReq->new(@_)},
    180 => sub{Bootload::MsgBootloaderHandshakeResp->new(@_)},
    177 => sub{Bootload::MsgBootloaderJumpToApp->new(@_)},
    222 => sub{Bootload::MsgNapDeviceDnaReq->new(@_)},
    221 => sub{Bootload::MsgNapDeviceDnaResp->new(@_)},
    176 => sub{Bootload::MsgBootloaderHandshakeDepA->new(@_)},
  
    257 => sub{ExtEvents::MsgExtEvent->new(@_)},
  
    168 => sub{FileIo::MsgFileioReadReq->new(@_)},
    163 => sub{FileIo::MsgFileioReadResp->new(@_)},
    169 => sub{FileIo::MsgFileioReadDirReq->new(@_)},
    170 => sub{FileIo::MsgFileioReadDirResp->new(@_)},
    172 => sub{FileIo::MsgFileioRemove->new(@_)},
    173 => sub{FileIo::MsgFileioWriteReq->new(@_)},
    171 => sub{FileIo::MsgFileioWriteResp->new(@_)},
    4097 => sub{FileIo::MsgFileioConfigReq->new(@_)},
    4098 => sub{FileIo::MsgFileioConfigResp->new(@_)},
  
    230 => sub{Flash::MsgFlashProgram->new(@_)},
    224 => sub{Flash::MsgFlashDone->new(@_)},
    231 => sub{Flash::MsgFlashReadReq->new(@_)},
    225 => sub{Flash::MsgFlashReadResp->new(@_)},
    226 => sub{Flash::MsgFlashErase->new(@_)},
    227 => sub{Flash::MsgStmFlashLockSector->new(@_)},
    228 => sub{Flash::MsgStmFlashUnlockSector->new(@_)},
    232 => sub{Flash::MsgStmUniqueIdReq->new(@_)},
    229 => sub{Flash::MsgStmUniqueIdResp->new(@_)},
    243 => sub{Flash::MsgM25FlashWriteStatus->new(@_)},
  
  
    2304 => sub{Imu::MsgImuRaw->new(@_)},
    2305 => sub{Imu::MsgImuAux->new(@_)},
  
    3001 => sub{Integrity::MsgSsrFlagHighLevel->new(@_)},
    3005 => sub{Integrity::MsgSsrFlagSatellites->new(@_)},
    3011 => sub{Integrity::MsgSsrFlagTropoGridPoints->new(@_)},
    3015 => sub{Integrity::MsgSsrFlagIonoGridPoints->new(@_)},
    3021 => sub{Integrity::MsgSsrFlagIonoTileSatLos->new(@_)},
    3025 => sub{Integrity::MsgSsrFlagIonoGridPointSatLos->new(@_)},
    3026 => sub{Integrity::MsgAcknowledge->new(@_)},
  
    32512 => sub{Linux::MsgLinuxCpuStateDepA->new(@_)},
    32513 => sub{Linux::MsgLinuxMemStateDepA->new(@_)},
    32514 => sub{Linux::MsgLinuxSysStateDepA->new(@_)},
    32515 => sub{Linux::MsgLinuxProcessSocketCounts->new(@_)},
    32516 => sub{Linux::MsgLinuxProcessSocketQueues->new(@_)},
    32517 => sub{Linux::MsgLinuxSocketUsage->new(@_)},
    32518 => sub{Linux::MsgLinuxProcessFdCount->new(@_)},
    32519 => sub{Linux::MsgLinuxProcessFdSummary->new(@_)},
    32520 => sub{Linux::MsgLinuxCpuState->new(@_)},
    32521 => sub{Linux::MsgLinuxMemState->new(@_)},
    32522 => sub{Linux::MsgLinuxSysState->new(@_)},
  
    1025 => sub{Logging::MsgLog->new(@_)},
    1026 => sub{Logging::MsgFwd->new(@_)},
    16 => sub{Logging::MsgPrintDep->new(@_)},
  
    2306 => sub{Mag::MsgMagRaw->new(@_)},
  
    258 => sub{Navigation::MsgGpsTime->new(@_)},
    260 => sub{Navigation::MsgGpsTimeGnss->new(@_)},
    259 => sub{Navigation::MsgUtcTime->new(@_)},
    261 => sub{Navigation::MsgUtcTimeGnss->new(@_)},
    520 => sub{Navigation::MsgDops->new(@_)},
    521 => sub{Navigation::MsgPosEcef->new(@_)},
    532 => sub{Navigation::MsgPosEcefCov->new(@_)},
    522 => sub{Navigation::MsgPosLlh->new(@_)},
    529 => sub{Navigation::MsgPosLlhCov->new(@_)},
    536 => sub{Navigation::MsgPosLlhAcc->new(@_)},
    523 => sub{Navigation::MsgBaselineEcef->new(@_)},
    524 => sub{Navigation::MsgBaselineNed->new(@_)},
    525 => sub{Navigation::MsgVelEcef->new(@_)},
    533 => sub{Navigation::MsgVelEcefCov->new(@_)},
    526 => sub{Navigation::MsgVelNed->new(@_)},
    530 => sub{Navigation::MsgVelNedCov->new(@_)},
    553 => sub{Navigation::MsgPosEcefGnss->new(@_)},
    564 => sub{Navigation::MsgPosEcefCovGnss->new(@_)},
    554 => sub{Navigation::MsgPosLlhGnss->new(@_)},
    561 => sub{Navigation::MsgPosLlhCovGnss->new(@_)},
    557 => sub{Navigation::MsgVelEcefGnss->new(@_)},
    565 => sub{Navigation::MsgVelEcefCovGnss->new(@_)},
    558 => sub{Navigation::MsgVelNedGnss->new(@_)},
    562 => sub{Navigation::MsgVelNedCovGnss->new(@_)},
    531 => sub{Navigation::MsgVelBody->new(@_)},
    540 => sub{Navigation::MsgVelCog->new(@_)},
    528 => sub{Navigation::MsgAgeCorrections->new(@_)},
    256 => sub{Navigation::MsgGpsTimeDepA->new(@_)},
    518 => sub{Navigation::MsgDopsDepA->new(@_)},
    512 => sub{Navigation::MsgPosEcefDepA->new(@_)},
    513 => sub{Navigation::MsgPosLlhDepA->new(@_)},
    514 => sub{Navigation::MsgBaselineEcefDepA->new(@_)},
    515 => sub{Navigation::MsgBaselineNedDepA->new(@_)},
    516 => sub{Navigation::MsgVelEcefDepA->new(@_)},
    517 => sub{Navigation::MsgVelNedDepA->new(@_)},
    519 => sub{Navigation::MsgBaselineHeadingDepA->new(@_)},
    534 => sub{Navigation::MsgProtectionLevelDepA->new(@_)},
    535 => sub{Navigation::MsgProtectionLevel->new(@_)},
    570 => sub{Navigation::MsgUtcLeapSecond->new(@_)},
    580 => sub{Navigation::MsgReferenceFrameParam->new(@_)},
    581 => sub{Navigation::MsgPoseRelative->new(@_)},
  
    1024 => sub{Ndb::MsgNdbEvent->new(@_)},
  
    74 => sub{Observation::MsgObs->new(@_)},
    68 => sub{Observation::MsgBasePosLlh->new(@_)},
    72 => sub{Observation::MsgBasePosEcef->new(@_)},
    129 => sub{Observation::MsgEphemerisGpsDepE->new(@_)},
    134 => sub{Observation::MsgEphemerisGpsDepF->new(@_)},
    138 => sub{Observation::MsgEphemerisGps->new(@_)},
    142 => sub{Observation::MsgEphemerisQzss->new(@_)},
    137 => sub{Observation::MsgEphemerisBds->new(@_)},
    149 => sub{Observation::MsgEphemerisGalDepA->new(@_)},
    141 => sub{Observation::MsgEphemerisGal->new(@_)},
    130 => sub{Observation::MsgEphemerisSbasDepA->new(@_)},
    131 => sub{Observation::MsgEphemerisGloDepA->new(@_)},
    132 => sub{Observation::MsgEphemerisSbasDepB->new(@_)},
    140 => sub{Observation::MsgEphemerisSbas->new(@_)},
    133 => sub{Observation::MsgEphemerisGloDepB->new(@_)},
    135 => sub{Observation::MsgEphemerisGloDepC->new(@_)},
    136 => sub{Observation::MsgEphemerisGloDepD->new(@_)},
    139 => sub{Observation::MsgEphemerisGlo->new(@_)},
    128 => sub{Observation::MsgEphemerisDepD->new(@_)},
    26 => sub{Observation::MsgEphemerisDepA->new(@_)},
    70 => sub{Observation::MsgEphemerisDepB->new(@_)},
    71 => sub{Observation::MsgEphemerisDepC->new(@_)},
    69 => sub{Observation::MsgObsDepA->new(@_)},
    67 => sub{Observation::MsgObsDepB->new(@_)},
    73 => sub{Observation::MsgObsDepC->new(@_)},
    144 => sub{Observation::MsgIono->new(@_)},
    145 => sub{Observation::MsgSvConfigurationGpsDep->new(@_)},
    150 => sub{Observation::MsgGnssCapb->new(@_)},
    146 => sub{Observation::MsgGroupDelayDepA->new(@_)},
    147 => sub{Observation::MsgGroupDelayDepB->new(@_)},
    148 => sub{Observation::MsgGroupDelay->new(@_)},
    112 => sub{Observation::MsgAlmanacGpsDep->new(@_)},
    114 => sub{Observation::MsgAlmanacGps->new(@_)},
    113 => sub{Observation::MsgAlmanacGloDep->new(@_)},
    115 => sub{Observation::MsgAlmanacGlo->new(@_)},
    117 => sub{Observation::MsgGloBiases->new(@_)},
    151 => sub{Observation::MsgSvAzEl->new(@_)},
    1600 => sub{Observation::MsgOsr->new(@_)},
  
    527 => sub{Orientation::MsgBaselineHeading->new(@_)},
    544 => sub{Orientation::MsgOrientQuat->new(@_)},
    545 => sub{Orientation::MsgOrientEuler->new(@_)},
    546 => sub{Orientation::MsgAngularRate->new(@_)},
  
    105 => sub{Piksi::MsgAlmanac->new(@_)},
    104 => sub{Piksi::MsgSetTime->new(@_)},
    182 => sub{Piksi::MsgReset->new(@_)},
    178 => sub{Piksi::MsgResetDep->new(@_)},
    192 => sub{Piksi::MsgCwResults->new(@_)},
    193 => sub{Piksi::MsgCwStart->new(@_)},
    34 => sub{Piksi::MsgResetFilters->new(@_)},
    35 => sub{Piksi::MsgInitBaseDep->new(@_)},
    23 => sub{Piksi::MsgThreadState->new(@_)},
    29 => sub{Piksi::MsgUartState->new(@_)},
    24 => sub{Piksi::MsgUartStateDepa->new(@_)},
    25 => sub{Piksi::MsgIarState->new(@_)},
    43 => sub{Piksi::MsgMaskSatellite->new(@_)},
    27 => sub{Piksi::MsgMaskSatelliteDep->new(@_)},
    181 => sub{Piksi::MsgDeviceMonitor->new(@_)},
    184 => sub{Piksi::MsgCommandReq->new(@_)},
    185 => sub{Piksi::MsgCommandResp->new(@_)},
    188 => sub{Piksi::MsgCommandOutput->new(@_)},
    186 => sub{Piksi::MsgNetworkStateReq->new(@_)},
    187 => sub{Piksi::MsgNetworkStateResp->new(@_)},
    189 => sub{Piksi::MsgNetworkBandwidthUsage->new(@_)},
    190 => sub{Piksi::MsgCellModemStatus->new(@_)},
    80 => sub{Piksi::MsgSpecanDep->new(@_)},
    81 => sub{Piksi::MsgSpecan->new(@_)},
    191 => sub{Piksi::MsgFrontEndGain->new(@_)},
  
    52992 => sub{Profiling::MsgMeasurementPoint->new(@_)},
    52993 => sub{Profiling::MsgProfilingSystemInfo->new(@_)},
    52994 => sub{Profiling::MsgProfilingThreadInfo->new(@_)},
    52995 => sub{Profiling::MsgProfilingResourceCounter->new(@_)},
  
    30583 => sub{Sbas::MsgSbasRaw->new(@_)},
  
    161 => sub{Settings::MsgSettingsSave->new(@_)},
    160 => sub{Settings::MsgSettingsWrite->new(@_)},
    175 => sub{Settings::MsgSettingsWriteResp->new(@_)},
    164 => sub{Settings::MsgSettingsReadReq->new(@_)},
    165 => sub{Settings::MsgSettingsReadResp->new(@_)},
    162 => sub{Settings::MsgSettingsReadByIndexReq->new(@_)},
    167 => sub{Settings::MsgSettingsReadByIndexResp->new(@_)},
    166 => sub{Settings::MsgSettingsReadByIndexDone->new(@_)},
    174 => sub{Settings::MsgSettingsRegister->new(@_)},
    431 => sub{Settings::MsgSettingsRegisterResp->new(@_)},
  
    3076 => sub{Signing::MsgEcdsaCertificate->new(@_)},
    3081 => sub{Signing::MsgCertificateChain->new(@_)},
    3077 => sub{Signing::MsgCertificateChainDep->new(@_)},
    3080 => sub{Signing::MsgEcdsaSignature->new(@_)},
    3079 => sub{Signing::MsgEcdsaSignatureDepB->new(@_)},
    3078 => sub{Signing::MsgEcdsaSignatureDepA->new(@_)},
    3074 => sub{Signing::MsgEd25519CertificateDep->new(@_)},
    3073 => sub{Signing::MsgEd25519SignatureDepA->new(@_)},
    3075 => sub{Signing::MsgEd25519SignatureDepB->new(@_)},
  
    65295 => sub{SolutionMeta::MsgSolnMetaDepA->new(@_)},
    65294 => sub{SolutionMeta::MsgSolnMeta->new(@_)},
  
    1501 => sub{Ssr::MsgSsrOrbitClock->new(@_)},
    1505 => sub{Ssr::MsgSsrCodeBiases->new(@_)},
    1510 => sub{Ssr::MsgSsrPhaseBiases->new(@_)},
    1531 => sub{Ssr::MsgSsrStecCorrectionDep->new(@_)},
    1533 => sub{Ssr::MsgSsrStecCorrection->new(@_)},
    1532 => sub{Ssr::MsgSsrGriddedCorrection->new(@_)},
    1534 => sub{Ssr::MsgSsrGriddedCorrectionBounds->new(@_)},
    1526 => sub{Ssr::MsgSsrTileDefinitionDepA->new(@_)},
    1527 => sub{Ssr::MsgSsrTileDefinitionDepB->new(@_)},
    1528 => sub{Ssr::MsgSsrTileDefinition->new(@_)},
    1540 => sub{Ssr::MsgSsrSatelliteApcDep->new(@_)},
    1541 => sub{Ssr::MsgSsrSatelliteApc->new(@_)},
    1500 => sub{Ssr::MsgSsrOrbitClockDepA->new(@_)},
    1515 => sub{Ssr::MsgSsrStecCorrectionDepA->new(@_)},
    1520 => sub{Ssr::MsgSsrGriddedCorrectionNoStdDepA->new(@_)},
    1530 => sub{Ssr::MsgSsrGriddedCorrectionDepA->new(@_)},
    1525 => sub{Ssr::MsgSsrGridDefinitionDepA->new(@_)},
    1502 => sub{Ssr::MsgSsrOrbitClockBounds->new(@_)},
    1516 => sub{Ssr::MsgSsrCodePhaseBiasesBounds->new(@_)},
    1503 => sub{Ssr::MsgSsrOrbitClockBoundsDegradation->new(@_)},
  
    65280 => sub{System::MsgStartup->new(@_)},
    65282 => sub{System::MsgDgnssStatus->new(@_)},
    65535 => sub{System::MsgHeartbeat->new(@_)},
    65534 => sub{System::MsgStatusReport->new(@_)},
    65533 => sub{System::MsgStatusJournal->new(@_)},
    65283 => sub{System::MsgInsStatus->new(@_)},
    65284 => sub{System::MsgCsacTelemetry->new(@_)},
    65285 => sub{System::MsgCsacTelemetryLabels->new(@_)},
    65286 => sub{System::MsgInsUpdates->new(@_)},
    65287 => sub{System::MsgGnssTimeOffset->new(@_)},
    65288 => sub{System::MsgPpsTime->new(@_)},
    65289 => sub{System::MsgSensorAidEvent->new(@_)},
    65290 => sub{System::MsgGroupMeta->new(@_)},
  
    288 => sub{Telemetry::MsgTelSv->new(@_)},
  
    33 => sub{Tracking::MsgTrackingStateDetailedDepA->new(@_)},
    17 => sub{Tracking::MsgTrackingStateDetailedDep->new(@_)},
    65 => sub{Tracking::MsgTrackingState->new(@_)},
    97 => sub{Tracking::MsgMeasurementState->new(@_)},
    45 => sub{Tracking::MsgTrackingIq->new(@_)},
    44 => sub{Tracking::MsgTrackingIqDepB->new(@_)},
    28 => sub{Tracking::MsgTrackingIqDepA->new(@_)},
    22 => sub{Tracking::MsgTrackingStateDepA->new(@_)},
    19 => sub{Tracking::MsgTrackingStateDepB->new(@_)},
  
    2048 => sub{User::MsgUserData->new(@_)},
  
    2307 => sub{Vehicle::MsgOdometry->new(@_)},
    2308 => sub{Vehicle::MsgWheeltick->new(@_)},
);

sub _read {
    my ($self) = @_;
    my $io = $self->{_io};

    $self->{preamble} = $io->read_bytes(1);
    die "Invalid preamble $self->{preamble}" if(ord($self->{preamble}) != 0x55);

    $self->{msg_type} = $io->read_u2le();
    my $msg_type = $self->{msg_type};
    $self->{sender} = $io->read_u2le();
    $self->{length} = $io->read_u1();

    die "Unknown message type $msg_type" if(!exists($TABLE{$msg_type}));

    $self->{_raw_payload} = $io->read_bytes($self->length());
    my $io__raw_payload = IO::KaitaiStruct::Stream->new($self->{_raw_payload});
    $self->{payload} = $TABLE{$msg_type}($io__raw_payload, $self, $self->{_root});

    $self->{crc} = $io->read_u2le();
}


1;