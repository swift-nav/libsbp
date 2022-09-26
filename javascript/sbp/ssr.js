/**
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/**********************
 * Automatically generated from spec/yaml/swiftnav/sbp/ssr.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Precise State Space Representation (SSR) corrections format
***********************/

let SBP = require('./sbp');
let Parser = require('./parser');
let Int64 = require('node-int64');
let UInt64 = require('cuint').UINT64;
let CarrierPhase = require("./gnss").CarrierPhase;
let GnssSignal = require("./gnss").GnssSignal;
let GnssSignalDep = require("./gnss").GnssSignalDep;
let GPSTime = require("./gnss").GPSTime;
let GPSTimeDep = require("./gnss").GPSTimeDep;
let GPSTimeSec = require("./gnss").GPSTimeSec;
let SvId = require("./gnss").SvId;

/**
 * SBP class for message fragment CodeBiasesContent
 *
 * Code biases are to be added to pseudorange. The corrections conform with RTCMv3
 * MT 1059 / 1065.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field code number (unsigned 8-bit int, 1 byte) Signal encoded following RTCM specifications (DF380, DF381, DF382 and DF467).
 * @field value number (signed 16-bit int, 2 bytes) Code bias value
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let CodeBiasesContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "CodeBiasesContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
CodeBiasesContent.prototype = Object.create(SBP.prototype);
CodeBiasesContent.prototype.messageType = "CodeBiasesContent";
CodeBiasesContent.prototype.constructor = CodeBiasesContent;
CodeBiasesContent.prototype.parser = new Parser()
  .endianess('little')
  .uint8('code')
  .int16('value');
CodeBiasesContent.prototype.fieldSpec = [];
CodeBiasesContent.prototype.fieldSpec.push(['code', 'writeUInt8', 1]);
CodeBiasesContent.prototype.fieldSpec.push(['value', 'writeInt16LE', 2]);

/**
 * SBP class for message fragment PhaseBiasesContent
 *
 * Phase biases are to be added to carrier phase measurements.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field code number (unsigned 8-bit int, 1 byte) Signal encoded following RTCM specifications (DF380, DF381, DF382 and DF467)
 * @field integer_indicator number (unsigned 8-bit int, 1 byte) Indicator for integer property
 * @field widelane_integer_indicator number (unsigned 8-bit int, 1 byte) Indicator for two groups of Wide-Lane(s) integer property
 * @field discontinuity_counter number (unsigned 8-bit int, 1 byte) Signal phase discontinuity counter. Increased for every discontinuity in phase.
 * @field bias number (signed 32-bit int, 4 bytes) Phase bias for specified signal
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let PhaseBiasesContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PhaseBiasesContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PhaseBiasesContent.prototype = Object.create(SBP.prototype);
PhaseBiasesContent.prototype.messageType = "PhaseBiasesContent";
PhaseBiasesContent.prototype.constructor = PhaseBiasesContent;
PhaseBiasesContent.prototype.parser = new Parser()
  .endianess('little')
  .uint8('code')
  .uint8('integer_indicator')
  .uint8('widelane_integer_indicator')
  .uint8('discontinuity_counter')
  .int32('bias');
PhaseBiasesContent.prototype.fieldSpec = [];
PhaseBiasesContent.prototype.fieldSpec.push(['code', 'writeUInt8', 1]);
PhaseBiasesContent.prototype.fieldSpec.push(['integer_indicator', 'writeUInt8', 1]);
PhaseBiasesContent.prototype.fieldSpec.push(['widelane_integer_indicator', 'writeUInt8', 1]);
PhaseBiasesContent.prototype.fieldSpec.push(['discontinuity_counter', 'writeUInt8', 1]);
PhaseBiasesContent.prototype.fieldSpec.push(['bias', 'writeInt32LE', 4]);

/**
 * SBP class for message fragment STECHeader
 *
 * A full set of STEC information will likely span multiple SBP messages, since SBP
 * message a limited to 255 bytes.  The header is used to tie multiple SBP messages
 * into a sequence.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tile_set_id number (unsigned 16-bit int, 2 bytes) Unique identifier of the tile set this tile belongs to.
 * @field tile_id number (unsigned 16-bit int, 2 bytes) Unique identifier of this tile in the tile set.
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field num_msgs number (unsigned 8-bit int, 1 byte) Number of messages in the dataset
 * @field seq_num number (unsigned 8-bit int, 1 byte) Position of this message in the dataset
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections. Encoded following RTCM DF391
 *   specification.
 * @field iod_atmo number (unsigned 8-bit int, 1 byte) IOD of the SSR atmospheric correction
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let STECHeader = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "STECHeader";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
STECHeader.prototype = Object.create(SBP.prototype);
STECHeader.prototype.messageType = "STECHeader";
STECHeader.prototype.constructor = STECHeader;
STECHeader.prototype.parser = new Parser()
  .endianess('little')
  .uint16('tile_set_id')
  .uint16('tile_id')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .uint8('num_msgs')
  .uint8('seq_num')
  .uint8('update_interval')
  .uint8('iod_atmo');
STECHeader.prototype.fieldSpec = [];
STECHeader.prototype.fieldSpec.push(['tile_set_id', 'writeUInt16LE', 2]);
STECHeader.prototype.fieldSpec.push(['tile_id', 'writeUInt16LE', 2]);
STECHeader.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
STECHeader.prototype.fieldSpec.push(['num_msgs', 'writeUInt8', 1]);
STECHeader.prototype.fieldSpec.push(['seq_num', 'writeUInt8', 1]);
STECHeader.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
STECHeader.prototype.fieldSpec.push(['iod_atmo', 'writeUInt8', 1]);

/**
 * SBP class for message fragment GriddedCorrectionHeader
 *
 * The LPP message contains nested variable length arrays which are not supported
 * in SBP, so each grid point will be identified by the index.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tile_set_id number (unsigned 16-bit int, 2 bytes) Unique identifier of the tile set this tile belongs to.
 * @field tile_id number (unsigned 16-bit int, 2 bytes) Unique identifier of this tile in the tile set.
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field num_msgs number (unsigned 16-bit int, 2 bytes) Number of messages in the dataset
 * @field seq_num number (unsigned 16-bit int, 2 bytes) Position of this message in the dataset
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections. Encoded following RTCM DF391
 *   specification.
 * @field iod_atmo number (unsigned 8-bit int, 1 byte) IOD of the SSR atmospheric correction
 * @field tropo_quality_indicator number (unsigned 8-bit int, 1 byte) Quality of the troposphere data. Encoded following RTCM DF389 specification in
 *   units of m.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let GriddedCorrectionHeader = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GriddedCorrectionHeader";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GriddedCorrectionHeader.prototype = Object.create(SBP.prototype);
GriddedCorrectionHeader.prototype.messageType = "GriddedCorrectionHeader";
GriddedCorrectionHeader.prototype.constructor = GriddedCorrectionHeader;
GriddedCorrectionHeader.prototype.parser = new Parser()
  .endianess('little')
  .uint16('tile_set_id')
  .uint16('tile_id')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .uint16('num_msgs')
  .uint16('seq_num')
  .uint8('update_interval')
  .uint8('iod_atmo')
  .uint8('tropo_quality_indicator');
GriddedCorrectionHeader.prototype.fieldSpec = [];
GriddedCorrectionHeader.prototype.fieldSpec.push(['tile_set_id', 'writeUInt16LE', 2]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['tile_id', 'writeUInt16LE', 2]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['num_msgs', 'writeUInt16LE', 2]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['seq_num', 'writeUInt16LE', 2]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['iod_atmo', 'writeUInt8', 1]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['tropo_quality_indicator', 'writeUInt8', 1]);

/**
 * SBP class for message fragment STECSatElement
 *
 * STEC polynomial for the given satellite.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sv_id SvId Unique space vehicle identifier
 * @field stec_quality_indicator number (unsigned 8-bit int, 1 byte) Quality of the STEC data. Encoded following RTCM DF389 specification but in
 *   units of TECU instead of m.
 * @field stec_coeff array Coefficients of the STEC polynomial in the order of C00, C01, C10, C11. C00 =
 *   0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let STECSatElement = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "STECSatElement";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
STECSatElement.prototype = Object.create(SBP.prototype);
STECSatElement.prototype.messageType = "STECSatElement";
STECSatElement.prototype.constructor = STECSatElement;
STECSatElement.prototype.parser = new Parser()
  .endianess('little')
  .nest('sv_id', { type: SvId.prototype.parser })
  .uint8('stec_quality_indicator')
  .array('stec_coeff', { length: 4, type: 'int16le' });
STECSatElement.prototype.fieldSpec = [];
STECSatElement.prototype.fieldSpec.push(['sv_id', SvId.prototype.fieldSpec]);
STECSatElement.prototype.fieldSpec.push(['stec_quality_indicator', 'writeUInt8', 1]);
STECSatElement.prototype.fieldSpec.push(['stec_coeff', 'array', 'writeInt16LE', function () { return 2; }, 4]);

/**
 * SBP class for message fragment TroposphericDelayCorrectionNoStd
 *
 * Troposphere vertical delays at the grid point.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field hydro number (signed 16-bit int, 2 bytes) Hydrostatic vertical delay
 * @field wet number (signed 8-bit int, 1 byte) Wet vertical delay
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let TroposphericDelayCorrectionNoStd = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TroposphericDelayCorrectionNoStd";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TroposphericDelayCorrectionNoStd.prototype = Object.create(SBP.prototype);
TroposphericDelayCorrectionNoStd.prototype.messageType = "TroposphericDelayCorrectionNoStd";
TroposphericDelayCorrectionNoStd.prototype.constructor = TroposphericDelayCorrectionNoStd;
TroposphericDelayCorrectionNoStd.prototype.parser = new Parser()
  .endianess('little')
  .int16('hydro')
  .int8('wet');
TroposphericDelayCorrectionNoStd.prototype.fieldSpec = [];
TroposphericDelayCorrectionNoStd.prototype.fieldSpec.push(['hydro', 'writeInt16LE', 2]);
TroposphericDelayCorrectionNoStd.prototype.fieldSpec.push(['wet', 'writeInt8', 1]);

/**
 * SBP class for message fragment TroposphericDelayCorrection
 *
 * Troposphere vertical delays (mean and standard deviation) at the grid point.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field hydro number (signed 16-bit int, 2 bytes) Hydrostatic vertical delay. Add 2.3 m to get actual value.
 * @field wet number (signed 8-bit int, 1 byte) Wet vertical delay. Add 0.252 m to get actual value.
 * @field stddev number (unsigned 8-bit int, 1 byte) Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 + value/16) -
 *   1)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let TroposphericDelayCorrection = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TroposphericDelayCorrection";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TroposphericDelayCorrection.prototype = Object.create(SBP.prototype);
TroposphericDelayCorrection.prototype.messageType = "TroposphericDelayCorrection";
TroposphericDelayCorrection.prototype.constructor = TroposphericDelayCorrection;
TroposphericDelayCorrection.prototype.parser = new Parser()
  .endianess('little')
  .int16('hydro')
  .int8('wet')
  .uint8('stddev');
TroposphericDelayCorrection.prototype.fieldSpec = [];
TroposphericDelayCorrection.prototype.fieldSpec.push(['hydro', 'writeInt16LE', 2]);
TroposphericDelayCorrection.prototype.fieldSpec.push(['wet', 'writeInt8', 1]);
TroposphericDelayCorrection.prototype.fieldSpec.push(['stddev', 'writeUInt8', 1]);

/**
 * SBP class for message fragment STECResidualNoStd
 *
 * STEC residual for the given satellite at the grid point.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sv_id SvId space vehicle identifier
 * @field residual number (signed 16-bit int, 2 bytes) STEC residual
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let STECResidualNoStd = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "STECResidualNoStd";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
STECResidualNoStd.prototype = Object.create(SBP.prototype);
STECResidualNoStd.prototype.messageType = "STECResidualNoStd";
STECResidualNoStd.prototype.constructor = STECResidualNoStd;
STECResidualNoStd.prototype.parser = new Parser()
  .endianess('little')
  .nest('sv_id', { type: SvId.prototype.parser })
  .int16('residual');
STECResidualNoStd.prototype.fieldSpec = [];
STECResidualNoStd.prototype.fieldSpec.push(['sv_id', SvId.prototype.fieldSpec]);
STECResidualNoStd.prototype.fieldSpec.push(['residual', 'writeInt16LE', 2]);

/**
 * SBP class for message fragment STECResidual
 *
 * STEC residual (mean and standard deviation) for the given satellite at the grid
 * point.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sv_id SvId space vehicle identifier
 * @field residual number (signed 16-bit int, 2 bytes) STEC residual
 * @field stddev number (unsigned 8-bit int, 1 byte) Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 + value/16) -
 *   1) * 10
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let STECResidual = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "STECResidual";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
STECResidual.prototype = Object.create(SBP.prototype);
STECResidual.prototype.messageType = "STECResidual";
STECResidual.prototype.constructor = STECResidual;
STECResidual.prototype.parser = new Parser()
  .endianess('little')
  .nest('sv_id', { type: SvId.prototype.parser })
  .int16('residual')
  .uint8('stddev');
STECResidual.prototype.fieldSpec = [];
STECResidual.prototype.fieldSpec.push(['sv_id', SvId.prototype.fieldSpec]);
STECResidual.prototype.fieldSpec.push(['residual', 'writeInt16LE', 2]);
STECResidual.prototype.fieldSpec.push(['stddev', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DD).
 *
 * The precise orbit and clock correction message is to be applied as a delta
 * correction to broadcast ephemeris and is an equivalent to the 1060 /1066 RTCM
 * message types.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections. Encoded following RTCM DF391
 *   specification.
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) IOD of the SSR correction. A change of Issue Of Data SSR is used to indicate a
 *   change in the SSR generating configuration
 * @field iod number (unsigned 32-bit int, 4 bytes) Issue of broadcast ephemeris data or IODCRC (Beidou)
 * @field radial number (signed 32-bit int, 4 bytes) Orbit radial delta correction
 * @field along number (signed 32-bit int, 4 bytes) Orbit along delta correction
 * @field cross number (signed 32-bit int, 4 bytes) Orbit along delta correction
 * @field dot_radial number (signed 32-bit int, 4 bytes) Velocity of orbit radial delta correction
 * @field dot_along number (signed 32-bit int, 4 bytes) Velocity of orbit along delta correction
 * @field dot_cross number (signed 32-bit int, 4 bytes) Velocity of orbit cross delta correction
 * @field c0 number (signed 32-bit int, 4 bytes) C0 polynomial coefficient for correction of broadcast satellite clock
 * @field c1 number (signed 32-bit int, 4 bytes) C1 polynomial coefficient for correction of broadcast satellite clock
 * @field c2 number (signed 32-bit int, 4 bytes) C2 polynomial coefficient for correction of broadcast satellite clock
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrOrbitClock = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_ORBIT_CLOCK";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrOrbitClock.prototype = Object.create(SBP.prototype);
MsgSsrOrbitClock.prototype.messageType = "MSG_SSR_ORBIT_CLOCK";
MsgSsrOrbitClock.prototype.msg_type = 0x05DD;
MsgSsrOrbitClock.prototype.constructor = MsgSsrOrbitClock;
MsgSsrOrbitClock.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('update_interval')
  .uint8('iod_ssr')
  .uint32('iod')
  .int32('radial')
  .int32('along')
  .int32('cross')
  .int32('dot_radial')
  .int32('dot_along')
  .int32('dot_cross')
  .int32('c0')
  .int32('c1')
  .int32('c2');
MsgSsrOrbitClock.prototype.fieldSpec = [];
MsgSsrOrbitClock.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['iod_ssr', 'writeUInt8', 1]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['iod', 'writeUInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['radial', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['along', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['cross', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['dot_radial', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['dot_along', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['dot_cross', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['c0', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['c1', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['c2', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_SSR_CODE_BIASES (0x05E1).
 *
 * The precise code biases message is to be added to the pseudorange of the
 * corresponding signal to get corrected pseudorange. It is an equivalent to the
 * 1059 / 1065 RTCM message types.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections. Encoded following RTCM DF391
 *   specification.
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) IOD of the SSR correction. A change of Issue Of Data SSR is used to indicate a
 *   change in the SSR generating configuration
 * @field biases array Code biases for the different satellite signals
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrCodeBiases = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_CODE_BIASES";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrCodeBiases.prototype = Object.create(SBP.prototype);
MsgSsrCodeBiases.prototype.messageType = "MSG_SSR_CODE_BIASES";
MsgSsrCodeBiases.prototype.msg_type = 0x05E1;
MsgSsrCodeBiases.prototype.constructor = MsgSsrCodeBiases;
MsgSsrCodeBiases.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('update_interval')
  .uint8('iod_ssr')
  .array('biases', { type: CodeBiasesContent.prototype.parser, readUntil: 'eof' });
MsgSsrCodeBiases.prototype.fieldSpec = [];
MsgSsrCodeBiases.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrCodeBiases.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgSsrCodeBiases.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
MsgSsrCodeBiases.prototype.fieldSpec.push(['iod_ssr', 'writeUInt8', 1]);
MsgSsrCodeBiases.prototype.fieldSpec.push(['biases', 'array', CodeBiasesContent.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_SSR_PHASE_BIASES (0x05E6).
 *
 * The precise phase biases message contains the biases to be added to the carrier
 * phase of the corresponding signal to get corrected carrier phase measurement, as
 * well as the satellite yaw angle to be applied to compute the phase wind-up
 * correction. It is typically an equivalent to the 1265 RTCM message types.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections. Encoded following RTCM DF391
 *   specification.
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) IOD of the SSR correction. A change of Issue Of Data SSR is used to indicate a
 *   change in the SSR generating configuration
 * @field dispersive_bias number (unsigned 8-bit int, 1 byte) Indicator for the dispersive phase biases property.
 * @field mw_consistency number (unsigned 8-bit int, 1 byte) Consistency indicator for Melbourne-Wubbena linear combinations
 * @field yaw number (unsigned 16-bit int, 2 bytes) Satellite yaw angle
 * @field yaw_rate number (signed 8-bit int, 1 byte) Satellite yaw angle rate
 * @field biases array Phase biases corrections for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrPhaseBiases = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_PHASE_BIASES";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrPhaseBiases.prototype = Object.create(SBP.prototype);
MsgSsrPhaseBiases.prototype.messageType = "MSG_SSR_PHASE_BIASES";
MsgSsrPhaseBiases.prototype.msg_type = 0x05E6;
MsgSsrPhaseBiases.prototype.constructor = MsgSsrPhaseBiases;
MsgSsrPhaseBiases.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('update_interval')
  .uint8('iod_ssr')
  .uint8('dispersive_bias')
  .uint8('mw_consistency')
  .uint16('yaw')
  .int8('yaw_rate')
  .array('biases', { type: PhaseBiasesContent.prototype.parser, readUntil: 'eof' });
MsgSsrPhaseBiases.prototype.fieldSpec = [];
MsgSsrPhaseBiases.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['iod_ssr', 'writeUInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['dispersive_bias', 'writeUInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['mw_consistency', 'writeUInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['yaw', 'writeUInt16LE', 2]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['yaw_rate', 'writeInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['biases', 'array', PhaseBiasesContent.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_SSR_STEC_CORRECTION_DEP (0x05FB).
 *
 * The Slant Total Electron Content per space vehicle, given as polynomial
 * approximation for a given tile. This should be combined with the
 * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation of the
 * atmospheric delay.  It is typically equivalent to the QZSS CLAS Sub Type 8
 * messages.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header STECHeader Header of a STEC polynomial coefficient message.
 * @field stec_sat_list array Array of STEC polynomial coefficients for each space vehicle.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrStecCorrectionDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_STEC_CORRECTION_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrStecCorrectionDep.prototype = Object.create(SBP.prototype);
MsgSsrStecCorrectionDep.prototype.messageType = "MSG_SSR_STEC_CORRECTION_DEP";
MsgSsrStecCorrectionDep.prototype.msg_type = 0x05FB;
MsgSsrStecCorrectionDep.prototype.constructor = MsgSsrStecCorrectionDep;
MsgSsrStecCorrectionDep.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: STECHeader.prototype.parser })
  .array('stec_sat_list', { type: STECSatElement.prototype.parser, readUntil: 'eof' });
MsgSsrStecCorrectionDep.prototype.fieldSpec = [];
MsgSsrStecCorrectionDep.prototype.fieldSpec.push(['header', STECHeader.prototype.fieldSpec]);
MsgSsrStecCorrectionDep.prototype.fieldSpec.push(['stec_sat_list', 'array', STECSatElement.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment BoundsHeader
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the bound
 * @field num_msgs number (unsigned 8-bit int, 1 byte) Number of messages in the dataset
 * @field seq_num number (unsigned 8-bit int, 1 byte) Position of this message in the dataset
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive bounds. Similar to RTCM DF391.
 * @field sol_id number (unsigned 8-bit int, 1 byte) SSR Solution ID.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let BoundsHeader = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "BoundsHeader";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
BoundsHeader.prototype = Object.create(SBP.prototype);
BoundsHeader.prototype.messageType = "BoundsHeader";
BoundsHeader.prototype.constructor = BoundsHeader;
BoundsHeader.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .uint8('num_msgs')
  .uint8('seq_num')
  .uint8('update_interval')
  .uint8('sol_id');
BoundsHeader.prototype.fieldSpec = [];
BoundsHeader.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
BoundsHeader.prototype.fieldSpec.push(['num_msgs', 'writeUInt8', 1]);
BoundsHeader.prototype.fieldSpec.push(['seq_num', 'writeUInt8', 1]);
BoundsHeader.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
BoundsHeader.prototype.fieldSpec.push(['sol_id', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_STEC_CORRECTION (0x05FD).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header BoundsHeader Header of a STEC correction with bounds message.
 * @field ssr_iod_atmo number (unsigned 8-bit int, 1 byte) IOD of the SSR atmospheric correction
 * @field tile_set_id number (unsigned 16-bit int, 2 bytes) Tile set ID
 * @field tile_id number (unsigned 16-bit int, 2 bytes) Tile ID
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites.
 * @field stec_sat_list array Array of STEC polynomial coefficients for each space vehicle.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrStecCorrection = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_STEC_CORRECTION";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrStecCorrection.prototype = Object.create(SBP.prototype);
MsgSsrStecCorrection.prototype.messageType = "MSG_SSR_STEC_CORRECTION";
MsgSsrStecCorrection.prototype.msg_type = 0x05FD;
MsgSsrStecCorrection.prototype.constructor = MsgSsrStecCorrection;
MsgSsrStecCorrection.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: BoundsHeader.prototype.parser })
  .uint8('ssr_iod_atmo')
  .uint16('tile_set_id')
  .uint16('tile_id')
  .uint8('n_sats')
  .array('stec_sat_list', { type: STECSatElement.prototype.parser, length: 'n_sats' });
MsgSsrStecCorrection.prototype.fieldSpec = [];
MsgSsrStecCorrection.prototype.fieldSpec.push(['header', BoundsHeader.prototype.fieldSpec]);
MsgSsrStecCorrection.prototype.fieldSpec.push(['ssr_iod_atmo', 'writeUInt8', 1]);
MsgSsrStecCorrection.prototype.fieldSpec.push(['tile_set_id', 'writeUInt16LE', 2]);
MsgSsrStecCorrection.prototype.fieldSpec.push(['tile_id', 'writeUInt16LE', 2]);
MsgSsrStecCorrection.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgSsrStecCorrection.prototype.fieldSpec.push(['stec_sat_list', 'array', STECSatElement.prototype.fieldSpec, function () { return this.fields.array.length; }, 'n_sats']);

/**
 * SBP class for message MSG_SSR_GRIDDED_CORRECTION (0x05FC).
 *
 * STEC residuals are per space vehicle, troposphere is not.  It is typically
 * equivalent to the QZSS CLAS Sub Type 9 messages.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header GriddedCorrectionHeader Header of a gridded correction message
 * @field index number (unsigned 16-bit int, 2 bytes) Index of the grid point.
 * @field tropo_delay_correction TroposphericDelayCorrection Wet and hydrostatic vertical delays (mean, stddev).
 * @field stec_residuals array STEC residuals for each satellite (mean, stddev).
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrGriddedCorrection = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_GRIDDED_CORRECTION";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrGriddedCorrection.prototype = Object.create(SBP.prototype);
MsgSsrGriddedCorrection.prototype.messageType = "MSG_SSR_GRIDDED_CORRECTION";
MsgSsrGriddedCorrection.prototype.msg_type = 0x05FC;
MsgSsrGriddedCorrection.prototype.constructor = MsgSsrGriddedCorrection;
MsgSsrGriddedCorrection.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: GriddedCorrectionHeader.prototype.parser })
  .uint16('index')
  .nest('tropo_delay_correction', { type: TroposphericDelayCorrection.prototype.parser })
  .array('stec_residuals', { type: STECResidual.prototype.parser, readUntil: 'eof' });
MsgSsrGriddedCorrection.prototype.fieldSpec = [];
MsgSsrGriddedCorrection.prototype.fieldSpec.push(['header', GriddedCorrectionHeader.prototype.fieldSpec]);
MsgSsrGriddedCorrection.prototype.fieldSpec.push(['index', 'writeUInt16LE', 2]);
MsgSsrGriddedCorrection.prototype.fieldSpec.push(['tropo_delay_correction', TroposphericDelayCorrection.prototype.fieldSpec]);
MsgSsrGriddedCorrection.prototype.fieldSpec.push(['stec_residuals', 'array', STECResidual.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment STECSatElementIntegrity
 *
 * STEC polynomial and bounds for the given satellite.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field stec_residual STECResidual STEC residuals (mean, stddev)
 * @field stec_bound_mu number (unsigned 8-bit int, 1 byte) Error Bound Mean. See Note 1.
 * @field stec_bound_sig number (unsigned 8-bit int, 1 byte) Error Bound StDev. See Note 1.
 * @field stec_bound_mu_dot number (unsigned 8-bit int, 1 byte) Error Bound Mean First derivative.
 * @field stec_bound_sig_dot number (unsigned 8-bit int, 1 byte) Error Bound StDev First derivative.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let STECSatElementIntegrity = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "STECSatElementIntegrity";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
STECSatElementIntegrity.prototype = Object.create(SBP.prototype);
STECSatElementIntegrity.prototype.messageType = "STECSatElementIntegrity";
STECSatElementIntegrity.prototype.constructor = STECSatElementIntegrity;
STECSatElementIntegrity.prototype.parser = new Parser()
  .endianess('little')
  .nest('stec_residual', { type: STECResidual.prototype.parser })
  .uint8('stec_bound_mu')
  .uint8('stec_bound_sig')
  .uint8('stec_bound_mu_dot')
  .uint8('stec_bound_sig_dot');
STECSatElementIntegrity.prototype.fieldSpec = [];
STECSatElementIntegrity.prototype.fieldSpec.push(['stec_residual', STECResidual.prototype.fieldSpec]);
STECSatElementIntegrity.prototype.fieldSpec.push(['stec_bound_mu', 'writeUInt8', 1]);
STECSatElementIntegrity.prototype.fieldSpec.push(['stec_bound_sig', 'writeUInt8', 1]);
STECSatElementIntegrity.prototype.fieldSpec.push(['stec_bound_mu_dot', 'writeUInt8', 1]);
STECSatElementIntegrity.prototype.fieldSpec.push(['stec_bound_sig_dot', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_GRIDDED_CORRECTION_BOUNDS (0x05FE).
 *
 * Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230, mean=2+0.1(i-200);
 * i>230, mean=5+0.5(i-230).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header BoundsHeader Header of a bounds message.
 * @field ssr_iod_atmo number (unsigned 8-bit int, 1 byte) IOD of the correction.
 * @field tile_set_id number (unsigned 16-bit int, 2 bytes) Set this tile belongs to.
 * @field tile_id number (unsigned 16-bit int, 2 bytes) Unique identifier of this tile in the tile set.
 * @field tropo_qi number (unsigned 8-bit int, 1 byte) Tropo Quality Indicator. Similar to RTCM DF389.
 * @field grid_point_id number (unsigned 16-bit int, 2 bytes) Index of the Grid Point.
 * @field tropo_delay_correction TroposphericDelayCorrection Tropospheric delay at grid point.
 * @field tropo_v_hydro_bound_mu number (unsigned 8-bit int, 1 byte) Vertical Hydrostatic Error Bound Mean.
 * @field tropo_v_hydro_bound_sig number (unsigned 8-bit int, 1 byte) Vertical Hydrostatic Error Bound StDev.
 * @field tropo_v_wet_bound_mu number (unsigned 8-bit int, 1 byte) Vertical Wet Error Bound Mean.
 * @field tropo_v_wet_bound_sig number (unsigned 8-bit int, 1 byte) Vertical Wet Error Bound StDev.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites.
 * @field stec_sat_list array Array of STEC polynomial coefficients and its bounds for each space vehicle.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrGriddedCorrectionBounds = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_GRIDDED_CORRECTION_BOUNDS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrGriddedCorrectionBounds.prototype = Object.create(SBP.prototype);
MsgSsrGriddedCorrectionBounds.prototype.messageType = "MSG_SSR_GRIDDED_CORRECTION_BOUNDS";
MsgSsrGriddedCorrectionBounds.prototype.msg_type = 0x05FE;
MsgSsrGriddedCorrectionBounds.prototype.constructor = MsgSsrGriddedCorrectionBounds;
MsgSsrGriddedCorrectionBounds.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: BoundsHeader.prototype.parser })
  .uint8('ssr_iod_atmo')
  .uint16('tile_set_id')
  .uint16('tile_id')
  .uint8('tropo_qi')
  .uint16('grid_point_id')
  .nest('tropo_delay_correction', { type: TroposphericDelayCorrection.prototype.parser })
  .uint8('tropo_v_hydro_bound_mu')
  .uint8('tropo_v_hydro_bound_sig')
  .uint8('tropo_v_wet_bound_mu')
  .uint8('tropo_v_wet_bound_sig')
  .uint8('n_sats')
  .array('stec_sat_list', { type: STECSatElementIntegrity.prototype.parser, length: 'n_sats' });
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec = [];
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['header', BoundsHeader.prototype.fieldSpec]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['ssr_iod_atmo', 'writeUInt8', 1]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['tile_set_id', 'writeUInt16LE', 2]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['tile_id', 'writeUInt16LE', 2]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['tropo_qi', 'writeUInt8', 1]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['grid_point_id', 'writeUInt16LE', 2]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['tropo_delay_correction', TroposphericDelayCorrection.prototype.fieldSpec]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['tropo_v_hydro_bound_mu', 'writeUInt8', 1]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['tropo_v_hydro_bound_sig', 'writeUInt8', 1]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['tropo_v_wet_bound_mu', 'writeUInt8', 1]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['tropo_v_wet_bound_sig', 'writeUInt8', 1]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgSsrGriddedCorrectionBounds.prototype.fieldSpec.push(['stec_sat_list', 'array', STECSatElementIntegrity.prototype.fieldSpec, function () { return this.fields.array.length; }, 'n_sats']);

/**
 * SBP class for message MSG_SSR_TILE_DEFINITION_DEP (0x05F6).
 *
 * Provides the correction point coordinates for the atmospheric correction values
 * in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION messages.
 * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information element
 * GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of correction
 * points, not lists of points.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tile_set_id number (unsigned 16-bit int, 2 bytes) Unique identifier of the tile set this tile belongs to.
 * @field tile_id number (unsigned 16-bit int, 2 bytes) Unique identifier of this tile in the tile set. See GNSS-SSR-
 *   ArrayOfCorrectionPoints field correctionPointSetID.
 * @field corner_nw_lat number (signed 16-bit int, 2 bytes) North-West corner correction point latitude.  The relation between the latitude
 *   X in the range [-90, 90] and the coded number N is:  N = floor((X / 90) * 2^14)
 *   See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
 * @field corner_nw_lon number (signed 16-bit int, 2 bytes) North-West corner correction point longitude.  The relation between the
 *   longitude X in the range [-180, 180] and the coded number N is:  N = floor((X /
 *   180) * 2^15)  See GNSS-SSR-ArrayOfCorrectionPoints field
 *   referencePointLongitude.
 * @field spacing_lat number (unsigned 16-bit int, 2 bytes) Spacing of the correction points in the latitude direction.  See GNSS-SSR-
 *   ArrayOfCorrectionPoints field stepOfLatitude.
 * @field spacing_lon number (unsigned 16-bit int, 2 bytes) Spacing of the correction points in the longitude direction.  See GNSS-SSR-
 *   ArrayOfCorrectionPoints field stepOfLongitude.
 * @field rows number (unsigned 16-bit int, 2 bytes) Number of steps in the latitude direction.  See GNSS-SSR-ArrayOfCorrectionPoints
 *   field numberOfStepsLatitude.
 * @field cols number (unsigned 16-bit int, 2 bytes) Number of steps in the longitude direction.  See GNSS-SSR-
 *   ArrayOfCorrectionPoints field numberOfStepsLongitude.
 * @field bitmask number (unsigned 64-bit int, 8 bytes) Specifies the availability of correction data at the correction points in the
 *   array.  If a specific bit is enabled (set to 1), the correction is not
 *   available. Only the first rows * cols bits are used, the remainder are set to 0.
 *   If there are more then 64 correction points the remaining corrections are always
 *   available.  Starting with the northwest corner of the array (top left on a north
 *   oriented map) the correction points are enumerated with row precedence - first
 *   row west to east, second row west to east, until last row west to east - ending
 *   with the southeast corner of the array.  See GNSS-SSR-ArrayOfCorrectionPoints
 *   field bitmaskOfGrids but note the definition of the bits is inverted.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrTileDefinitionDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_TILE_DEFINITION_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrTileDefinitionDep.prototype = Object.create(SBP.prototype);
MsgSsrTileDefinitionDep.prototype.messageType = "MSG_SSR_TILE_DEFINITION_DEP";
MsgSsrTileDefinitionDep.prototype.msg_type = 0x05F6;
MsgSsrTileDefinitionDep.prototype.constructor = MsgSsrTileDefinitionDep;
MsgSsrTileDefinitionDep.prototype.parser = new Parser()
  .endianess('little')
  .uint16('tile_set_id')
  .uint16('tile_id')
  .int16('corner_nw_lat')
  .int16('corner_nw_lon')
  .uint16('spacing_lat')
  .uint16('spacing_lon')
  .uint16('rows')
  .uint16('cols')
  .uint64('bitmask');
MsgSsrTileDefinitionDep.prototype.fieldSpec = [];
MsgSsrTileDefinitionDep.prototype.fieldSpec.push(['tile_set_id', 'writeUInt16LE', 2]);
MsgSsrTileDefinitionDep.prototype.fieldSpec.push(['tile_id', 'writeUInt16LE', 2]);
MsgSsrTileDefinitionDep.prototype.fieldSpec.push(['corner_nw_lat', 'writeInt16LE', 2]);
MsgSsrTileDefinitionDep.prototype.fieldSpec.push(['corner_nw_lon', 'writeInt16LE', 2]);
MsgSsrTileDefinitionDep.prototype.fieldSpec.push(['spacing_lat', 'writeUInt16LE', 2]);
MsgSsrTileDefinitionDep.prototype.fieldSpec.push(['spacing_lon', 'writeUInt16LE', 2]);
MsgSsrTileDefinitionDep.prototype.fieldSpec.push(['rows', 'writeUInt16LE', 2]);
MsgSsrTileDefinitionDep.prototype.fieldSpec.push(['cols', 'writeUInt16LE', 2]);
MsgSsrTileDefinitionDep.prototype.fieldSpec.push(['bitmask', 'writeUInt64LE', 8]);

/**
 * SBP class for message MSG_SSR_TILE_DEFINITION (0x05F7).
 *
 * Provides the correction point coordinates for the atmospheric correction values
 * in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION messages.  Based
 * on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information element GNSS-
 * SSR-CorrectionPoints. SBP only supports gridded arrays of correction points, not
 * lists of points.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field ssr_sol_id number (unsigned 8-bit int, 1 byte) SSR Solution ID.
 * @field tile_set_id number (unsigned 16-bit int, 2 bytes) Unique identifier of the tile set this tile belongs to.
 * @field tile_id number (unsigned 16-bit int, 2 bytes) Unique identifier of this tile in the tile set. See GNSS-SSR-
 *   ArrayOfCorrectionPoints field correctionPointSetID.
 * @field corner_nw_lat number (signed 16-bit int, 2 bytes) North-West corner correction point latitude.  The relation between the latitude
 *   X in the range [-90, 90] and the coded number N is:  N = floor((X / 90) * 2^14)
 *   See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
 * @field corner_nw_lon number (signed 16-bit int, 2 bytes) North-West corner correction point longitude.  The relation between the
 *   longitude X in the range [-180, 180] and the coded number N is:  N = floor((X /
 *   180) * 2^15)  See GNSS-SSR-ArrayOfCorrectionPoints field
 *   referencePointLongitude.
 * @field spacing_lat number (unsigned 16-bit int, 2 bytes) Spacing of the correction points in the latitude direction.  See GNSS-SSR-
 *   ArrayOfCorrectionPoints field stepOfLatitude.
 * @field spacing_lon number (unsigned 16-bit int, 2 bytes) Spacing of the correction points in the longitude direction.  See GNSS-SSR-
 *   ArrayOfCorrectionPoints field stepOfLongitude.
 * @field rows number (unsigned 16-bit int, 2 bytes) Number of steps in the latitude direction.  See GNSS-SSR-ArrayOfCorrectionPoints
 *   field numberOfStepsLatitude.
 * @field cols number (unsigned 16-bit int, 2 bytes) Number of steps in the longitude direction.  See GNSS-SSR-
 *   ArrayOfCorrectionPoints field numberOfStepsLongitude.
 * @field bitmask number (unsigned 64-bit int, 8 bytes) Specifies the availability of correction data at the correction points in the
 *   array.  If a specific bit is enabled (set to 1), the correction is not
 *   available. Only the first rows * cols bits are used, the remainder are set to 0.
 *   If there are more then 64 correction points the remaining corrections are always
 *   available.  Starting with the northwest corner of the array (top left on a north
 *   oriented map) the correction points are enumerated with row precedence - first
 *   row west to east, second row west to east, until last row west to east - ending
 *   with the southeast corner of the array.  See GNSS-SSR-ArrayOfCorrectionPoints
 *   field bitmaskOfGrids but note the definition of the bits is inverted.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrTileDefinition = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_TILE_DEFINITION";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrTileDefinition.prototype = Object.create(SBP.prototype);
MsgSsrTileDefinition.prototype.messageType = "MSG_SSR_TILE_DEFINITION";
MsgSsrTileDefinition.prototype.msg_type = 0x05F7;
MsgSsrTileDefinition.prototype.constructor = MsgSsrTileDefinition;
MsgSsrTileDefinition.prototype.parser = new Parser()
  .endianess('little')
  .uint8('ssr_sol_id')
  .uint16('tile_set_id')
  .uint16('tile_id')
  .int16('corner_nw_lat')
  .int16('corner_nw_lon')
  .uint16('spacing_lat')
  .uint16('spacing_lon')
  .uint16('rows')
  .uint16('cols')
  .uint64('bitmask');
MsgSsrTileDefinition.prototype.fieldSpec = [];
MsgSsrTileDefinition.prototype.fieldSpec.push(['ssr_sol_id', 'writeUInt8', 1]);
MsgSsrTileDefinition.prototype.fieldSpec.push(['tile_set_id', 'writeUInt16LE', 2]);
MsgSsrTileDefinition.prototype.fieldSpec.push(['tile_id', 'writeUInt16LE', 2]);
MsgSsrTileDefinition.prototype.fieldSpec.push(['corner_nw_lat', 'writeInt16LE', 2]);
MsgSsrTileDefinition.prototype.fieldSpec.push(['corner_nw_lon', 'writeInt16LE', 2]);
MsgSsrTileDefinition.prototype.fieldSpec.push(['spacing_lat', 'writeUInt16LE', 2]);
MsgSsrTileDefinition.prototype.fieldSpec.push(['spacing_lon', 'writeUInt16LE', 2]);
MsgSsrTileDefinition.prototype.fieldSpec.push(['rows', 'writeUInt16LE', 2]);
MsgSsrTileDefinition.prototype.fieldSpec.push(['cols', 'writeUInt16LE', 2]);
MsgSsrTileDefinition.prototype.fieldSpec.push(['bitmask', 'writeUInt64LE', 8]);

/**
 * SBP class for message fragment SatelliteAPC
 *
 * Contains phase center offset and elevation variation corrections for one signal
 * on a satellite.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field sat_info number (unsigned 8-bit int, 1 byte) Additional satellite information
 * @field svn number (unsigned 16-bit int, 2 bytes) Satellite Code, as defined by IGS. Typically the space vehicle number.
 * @field pco array Mean phase center offset, X Y and Z axes. See IGS ANTEX file format description
 *   for coordinate system definition.
 * @field pcv array Elevation dependent phase center variations. First element is 0 degrees
 *   separation from the Z axis, subsequent elements represent elevation variations
 *   in 1 degree increments.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let SatelliteAPC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "SatelliteAPC";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
SatelliteAPC.prototype = Object.create(SBP.prototype);
SatelliteAPC.prototype.messageType = "SatelliteAPC";
SatelliteAPC.prototype.constructor = SatelliteAPC;
SatelliteAPC.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('sat_info')
  .uint16('svn')
  .array('pco', { length: 3, type: 'int16le' })
  .array('pcv', { length: 21, type: 'int8' });
SatelliteAPC.prototype.fieldSpec = [];
SatelliteAPC.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
SatelliteAPC.prototype.fieldSpec.push(['sat_info', 'writeUInt8', 1]);
SatelliteAPC.prototype.fieldSpec.push(['svn', 'writeUInt16LE', 2]);
SatelliteAPC.prototype.fieldSpec.push(['pco', 'array', 'writeInt16LE', function () { return 2; }, 3]);
SatelliteAPC.prototype.fieldSpec.push(['pcv', 'array', 'writeInt8', function () { return 1; }, 21]);

/**
 * SBP class for message MSG_SSR_SATELLITE_APC (0x0604).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field apc array Satellite antenna phase center corrections
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrSatelliteApc = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_SATELLITE_APC";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrSatelliteApc.prototype = Object.create(SBP.prototype);
MsgSsrSatelliteApc.prototype.messageType = "MSG_SSR_SATELLITE_APC";
MsgSsrSatelliteApc.prototype.msg_type = 0x0604;
MsgSsrSatelliteApc.prototype.constructor = MsgSsrSatelliteApc;
MsgSsrSatelliteApc.prototype.parser = new Parser()
  .endianess('little')
  .array('apc', { type: SatelliteAPC.prototype.parser, readUntil: 'eof' });
MsgSsrSatelliteApc.prototype.fieldSpec = [];
MsgSsrSatelliteApc.prototype.fieldSpec.push(['apc', 'array', SatelliteAPC.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_SSR_ORBIT_CLOCK_DEP_A (0x05DC).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections. Encoded following RTCM DF391
 *   specification.
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) IOD of the SSR correction. A change of Issue Of Data SSR is used to indicate a
 *   change in the SSR generating configuration
 * @field iod number (unsigned 8-bit int, 1 byte) Issue of broadcast ephemeris data
 * @field radial number (signed 32-bit int, 4 bytes) Orbit radial delta correction
 * @field along number (signed 32-bit int, 4 bytes) Orbit along delta correction
 * @field cross number (signed 32-bit int, 4 bytes) Orbit along delta correction
 * @field dot_radial number (signed 32-bit int, 4 bytes) Velocity of orbit radial delta correction
 * @field dot_along number (signed 32-bit int, 4 bytes) Velocity of orbit along delta correction
 * @field dot_cross number (signed 32-bit int, 4 bytes) Velocity of orbit cross delta correction
 * @field c0 number (signed 32-bit int, 4 bytes) C0 polynomial coefficient for correction of broadcast satellite clock
 * @field c1 number (signed 32-bit int, 4 bytes) C1 polynomial coefficient for correction of broadcast satellite clock
 * @field c2 number (signed 32-bit int, 4 bytes) C2 polynomial coefficient for correction of broadcast satellite clock
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrOrbitClockDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_ORBIT_CLOCK_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrOrbitClockDepA.prototype = Object.create(SBP.prototype);
MsgSsrOrbitClockDepA.prototype.messageType = "MSG_SSR_ORBIT_CLOCK_DEP_A";
MsgSsrOrbitClockDepA.prototype.msg_type = 0x05DC;
MsgSsrOrbitClockDepA.prototype.constructor = MsgSsrOrbitClockDepA;
MsgSsrOrbitClockDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('update_interval')
  .uint8('iod_ssr')
  .uint8('iod')
  .int32('radial')
  .int32('along')
  .int32('cross')
  .int32('dot_radial')
  .int32('dot_along')
  .int32('dot_cross')
  .int32('c0')
  .int32('c1')
  .int32('c2');
MsgSsrOrbitClockDepA.prototype.fieldSpec = [];
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['iod_ssr', 'writeUInt8', 1]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['iod', 'writeUInt8', 1]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['radial', 'writeInt32LE', 4]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['along', 'writeInt32LE', 4]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['cross', 'writeInt32LE', 4]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['dot_radial', 'writeInt32LE', 4]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['dot_along', 'writeInt32LE', 4]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['dot_cross', 'writeInt32LE', 4]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['c0', 'writeInt32LE', 4]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['c1', 'writeInt32LE', 4]);
MsgSsrOrbitClockDepA.prototype.fieldSpec.push(['c2', 'writeInt32LE', 4]);

/**
 * SBP class for message fragment STECHeaderDepA
 *
 * A full set of STEC information will likely span multiple SBP messages, since SBP
 * message a limited to 255 bytes.  The header is used to tie multiple SBP messages
 * into a sequence.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field num_msgs number (unsigned 8-bit int, 1 byte) Number of messages in the dataset
 * @field seq_num number (unsigned 8-bit int, 1 byte) Position of this message in the dataset
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections. Encoded following RTCM DF391
 *   specification.
 * @field iod_atmo number (unsigned 8-bit int, 1 byte) IOD of the SSR atmospheric correction
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let STECHeaderDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "STECHeaderDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
STECHeaderDepA.prototype = Object.create(SBP.prototype);
STECHeaderDepA.prototype.messageType = "STECHeaderDepA";
STECHeaderDepA.prototype.constructor = STECHeaderDepA;
STECHeaderDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .uint8('num_msgs')
  .uint8('seq_num')
  .uint8('update_interval')
  .uint8('iod_atmo');
STECHeaderDepA.prototype.fieldSpec = [];
STECHeaderDepA.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
STECHeaderDepA.prototype.fieldSpec.push(['num_msgs', 'writeUInt8', 1]);
STECHeaderDepA.prototype.fieldSpec.push(['seq_num', 'writeUInt8', 1]);
STECHeaderDepA.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
STECHeaderDepA.prototype.fieldSpec.push(['iod_atmo', 'writeUInt8', 1]);

/**
 * SBP class for message fragment GriddedCorrectionHeaderDepA
 *
 * The 3GPP message contains nested variable length arrays which are not supported
 * in SBP, so each grid point will be identified by the index.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field num_msgs number (unsigned 16-bit int, 2 bytes) Number of messages in the dataset
 * @field seq_num number (unsigned 16-bit int, 2 bytes) Position of this message in the dataset
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections. Encoded following RTCM DF391
 *   specification.
 * @field iod_atmo number (unsigned 8-bit int, 1 byte) IOD of the SSR atmospheric correction
 * @field tropo_quality_indicator number (unsigned 8-bit int, 1 byte) Quality of the troposphere data. Encoded following RTCM DF389 specification in
 *   units of m.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let GriddedCorrectionHeaderDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GriddedCorrectionHeaderDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GriddedCorrectionHeaderDepA.prototype = Object.create(SBP.prototype);
GriddedCorrectionHeaderDepA.prototype.messageType = "GriddedCorrectionHeaderDepA";
GriddedCorrectionHeaderDepA.prototype.constructor = GriddedCorrectionHeaderDepA;
GriddedCorrectionHeaderDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .uint16('num_msgs')
  .uint16('seq_num')
  .uint8('update_interval')
  .uint8('iod_atmo')
  .uint8('tropo_quality_indicator');
GriddedCorrectionHeaderDepA.prototype.fieldSpec = [];
GriddedCorrectionHeaderDepA.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
GriddedCorrectionHeaderDepA.prototype.fieldSpec.push(['num_msgs', 'writeUInt16LE', 2]);
GriddedCorrectionHeaderDepA.prototype.fieldSpec.push(['seq_num', 'writeUInt16LE', 2]);
GriddedCorrectionHeaderDepA.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
GriddedCorrectionHeaderDepA.prototype.fieldSpec.push(['iod_atmo', 'writeUInt8', 1]);
GriddedCorrectionHeaderDepA.prototype.fieldSpec.push(['tropo_quality_indicator', 'writeUInt8', 1]);

/**
 * SBP class for message fragment GridDefinitionHeaderDepA
 *
 * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an RLE
 * encoded validity list.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field region_size_inverse number (unsigned 8-bit int, 1 byte) region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
 * @field area_width number (unsigned 16-bit int, 2 bytes) grid height (deg) = grid width (deg) = area_width / region_size 0 is an invalid
 *   value.
 * @field lat_nw_corner_enc number (unsigned 16-bit int, 2 bytes) North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90
 * @field lon_nw_corner_enc number (unsigned 16-bit int, 2 bytes) North-West corner longitude (deg) = region_size * lon_nw_corner_enc - 180
 * @field num_msgs number (unsigned 8-bit int, 1 byte) Number of messages in the dataset
 * @field seq_num number (unsigned 8-bit int, 1 byte) Position of this message in the dataset
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let GridDefinitionHeaderDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GridDefinitionHeaderDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GridDefinitionHeaderDepA.prototype = Object.create(SBP.prototype);
GridDefinitionHeaderDepA.prototype.messageType = "GridDefinitionHeaderDepA";
GridDefinitionHeaderDepA.prototype.constructor = GridDefinitionHeaderDepA;
GridDefinitionHeaderDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint8('region_size_inverse')
  .uint16('area_width')
  .uint16('lat_nw_corner_enc')
  .uint16('lon_nw_corner_enc')
  .uint8('num_msgs')
  .uint8('seq_num');
GridDefinitionHeaderDepA.prototype.fieldSpec = [];
GridDefinitionHeaderDepA.prototype.fieldSpec.push(['region_size_inverse', 'writeUInt8', 1]);
GridDefinitionHeaderDepA.prototype.fieldSpec.push(['area_width', 'writeUInt16LE', 2]);
GridDefinitionHeaderDepA.prototype.fieldSpec.push(['lat_nw_corner_enc', 'writeUInt16LE', 2]);
GridDefinitionHeaderDepA.prototype.fieldSpec.push(['lon_nw_corner_enc', 'writeUInt16LE', 2]);
GridDefinitionHeaderDepA.prototype.fieldSpec.push(['num_msgs', 'writeUInt8', 1]);
GridDefinitionHeaderDepA.prototype.fieldSpec.push(['seq_num', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_STEC_CORRECTION_DEP_A (0x05EB).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header STECHeaderDepA Header of a STEC message
 * @field stec_sat_list array Array of STEC information for each space vehicle
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrStecCorrectionDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_STEC_CORRECTION_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrStecCorrectionDepA.prototype = Object.create(SBP.prototype);
MsgSsrStecCorrectionDepA.prototype.messageType = "MSG_SSR_STEC_CORRECTION_DEP_A";
MsgSsrStecCorrectionDepA.prototype.msg_type = 0x05EB;
MsgSsrStecCorrectionDepA.prototype.constructor = MsgSsrStecCorrectionDepA;
MsgSsrStecCorrectionDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: STECHeaderDepA.prototype.parser })
  .array('stec_sat_list', { type: STECSatElement.prototype.parser, readUntil: 'eof' });
MsgSsrStecCorrectionDepA.prototype.fieldSpec = [];
MsgSsrStecCorrectionDepA.prototype.fieldSpec.push(['header', STECHeaderDepA.prototype.fieldSpec]);
MsgSsrStecCorrectionDepA.prototype.fieldSpec.push(['stec_sat_list', 'array', STECSatElement.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A (0x05F0).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header GriddedCorrectionHeaderDepA Header of a Gridded Correction message
 * @field index number (unsigned 16-bit int, 2 bytes) Index of the grid point
 * @field tropo_delay_correction TroposphericDelayCorrectionNoStd Wet and hydrostatic vertical delays
 * @field stec_residuals array STEC residuals for each satellite
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrGriddedCorrectionNoStdDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrGriddedCorrectionNoStdDepA.prototype = Object.create(SBP.prototype);
MsgSsrGriddedCorrectionNoStdDepA.prototype.messageType = "MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A";
MsgSsrGriddedCorrectionNoStdDepA.prototype.msg_type = 0x05F0;
MsgSsrGriddedCorrectionNoStdDepA.prototype.constructor = MsgSsrGriddedCorrectionNoStdDepA;
MsgSsrGriddedCorrectionNoStdDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: GriddedCorrectionHeaderDepA.prototype.parser })
  .uint16('index')
  .nest('tropo_delay_correction', { type: TroposphericDelayCorrectionNoStd.prototype.parser })
  .array('stec_residuals', { type: STECResidualNoStd.prototype.parser, readUntil: 'eof' });
MsgSsrGriddedCorrectionNoStdDepA.prototype.fieldSpec = [];
MsgSsrGriddedCorrectionNoStdDepA.prototype.fieldSpec.push(['header', GriddedCorrectionHeaderDepA.prototype.fieldSpec]);
MsgSsrGriddedCorrectionNoStdDepA.prototype.fieldSpec.push(['index', 'writeUInt16LE', 2]);
MsgSsrGriddedCorrectionNoStdDepA.prototype.fieldSpec.push(['tropo_delay_correction', TroposphericDelayCorrectionNoStd.prototype.fieldSpec]);
MsgSsrGriddedCorrectionNoStdDepA.prototype.fieldSpec.push(['stec_residuals', 'array', STECResidualNoStd.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_SSR_GRIDDED_CORRECTION_DEP_A (0x05FA).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header GriddedCorrectionHeaderDepA Header of a Gridded Correction message
 * @field index number (unsigned 16-bit int, 2 bytes) Index of the grid point
 * @field tropo_delay_correction TroposphericDelayCorrection Wet and hydrostatic vertical delays (mean, stddev)
 * @field stec_residuals array STEC residuals for each satellite (mean, stddev)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrGriddedCorrectionDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_GRIDDED_CORRECTION_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrGriddedCorrectionDepA.prototype = Object.create(SBP.prototype);
MsgSsrGriddedCorrectionDepA.prototype.messageType = "MSG_SSR_GRIDDED_CORRECTION_DEP_A";
MsgSsrGriddedCorrectionDepA.prototype.msg_type = 0x05FA;
MsgSsrGriddedCorrectionDepA.prototype.constructor = MsgSsrGriddedCorrectionDepA;
MsgSsrGriddedCorrectionDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: GriddedCorrectionHeaderDepA.prototype.parser })
  .uint16('index')
  .nest('tropo_delay_correction', { type: TroposphericDelayCorrection.prototype.parser })
  .array('stec_residuals', { type: STECResidual.prototype.parser, readUntil: 'eof' });
MsgSsrGriddedCorrectionDepA.prototype.fieldSpec = [];
MsgSsrGriddedCorrectionDepA.prototype.fieldSpec.push(['header', GriddedCorrectionHeaderDepA.prototype.fieldSpec]);
MsgSsrGriddedCorrectionDepA.prototype.fieldSpec.push(['index', 'writeUInt16LE', 2]);
MsgSsrGriddedCorrectionDepA.prototype.fieldSpec.push(['tropo_delay_correction', TroposphericDelayCorrection.prototype.fieldSpec]);
MsgSsrGriddedCorrectionDepA.prototype.fieldSpec.push(['stec_residuals', 'array', STECResidual.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_SSR_GRID_DEFINITION_DEP_A (0x05F5).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header GridDefinitionHeaderDepA Header of a Gridded Correction message
 * @field rle_list array Run Length Encode list of quadrants that contain valid data. The spec describes
 *   the encoding scheme in detail, but essentially the index of the quadrants that
 *   contain transitions between valid and invalid (and vice versa) are encoded as u8
 *   integers.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrGridDefinitionDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_GRID_DEFINITION_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrGridDefinitionDepA.prototype = Object.create(SBP.prototype);
MsgSsrGridDefinitionDepA.prototype.messageType = "MSG_SSR_GRID_DEFINITION_DEP_A";
MsgSsrGridDefinitionDepA.prototype.msg_type = 0x05F5;
MsgSsrGridDefinitionDepA.prototype.constructor = MsgSsrGridDefinitionDepA;
MsgSsrGridDefinitionDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: GridDefinitionHeaderDepA.prototype.parser })
  .array('rle_list', { type: 'uint8', readUntil: 'eof' });
MsgSsrGridDefinitionDepA.prototype.fieldSpec = [];
MsgSsrGridDefinitionDepA.prototype.fieldSpec.push(['header', GridDefinitionHeaderDepA.prototype.fieldSpec]);
MsgSsrGridDefinitionDepA.prototype.fieldSpec.push(['rle_list', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message fragment OrbitClockBound
 *
 * Orbit and clock bound.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sat_id number (unsigned 8-bit int, 1 byte) Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo), or DF488
 *   (BDS) depending on the constellation.
 * @field orb_radial_bound_mu number (unsigned 8-bit int, 1 byte) Mean Radial. See Note 1.
 * @field orb_along_bound_mu number (unsigned 8-bit int, 1 byte) Mean Along-Track. See Note 1.
 * @field orb_cross_bound_mu number (unsigned 8-bit int, 1 byte) Mean Cross-Track. See Note 1.
 * @field orb_radial_bound_sig number (unsigned 8-bit int, 1 byte) Standard Deviation Radial. See Note 2.
 * @field orb_along_bound_sig number (unsigned 8-bit int, 1 byte) Standard Deviation Along-Track. See Note 2.
 * @field orb_cross_bound_sig number (unsigned 8-bit int, 1 byte) Standard Deviation Cross-Track. See Note 2.
 * @field clock_bound_mu number (unsigned 8-bit int, 1 byte) Clock Bound Mean. See Note 1.
 * @field clock_bound_sig number (unsigned 8-bit int, 1 byte) Clock Bound Standard Deviation. See Note 2.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let OrbitClockBound = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "OrbitClockBound";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
OrbitClockBound.prototype = Object.create(SBP.prototype);
OrbitClockBound.prototype.messageType = "OrbitClockBound";
OrbitClockBound.prototype.constructor = OrbitClockBound;
OrbitClockBound.prototype.parser = new Parser()
  .endianess('little')
  .uint8('sat_id')
  .uint8('orb_radial_bound_mu')
  .uint8('orb_along_bound_mu')
  .uint8('orb_cross_bound_mu')
  .uint8('orb_radial_bound_sig')
  .uint8('orb_along_bound_sig')
  .uint8('orb_cross_bound_sig')
  .uint8('clock_bound_mu')
  .uint8('clock_bound_sig');
OrbitClockBound.prototype.fieldSpec = [];
OrbitClockBound.prototype.fieldSpec.push(['sat_id', 'writeUInt8', 1]);
OrbitClockBound.prototype.fieldSpec.push(['orb_radial_bound_mu', 'writeUInt8', 1]);
OrbitClockBound.prototype.fieldSpec.push(['orb_along_bound_mu', 'writeUInt8', 1]);
OrbitClockBound.prototype.fieldSpec.push(['orb_cross_bound_mu', 'writeUInt8', 1]);
OrbitClockBound.prototype.fieldSpec.push(['orb_radial_bound_sig', 'writeUInt8', 1]);
OrbitClockBound.prototype.fieldSpec.push(['orb_along_bound_sig', 'writeUInt8', 1]);
OrbitClockBound.prototype.fieldSpec.push(['orb_cross_bound_sig', 'writeUInt8', 1]);
OrbitClockBound.prototype.fieldSpec.push(['clock_bound_mu', 'writeUInt8', 1]);
OrbitClockBound.prototype.fieldSpec.push(['clock_bound_sig', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_ORBIT_CLOCK_BOUNDS (0x05DE).
 *
 * Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230, mean=2+0.1(i-200);
 * i>230, mean=5+0.5(i-230).  Note 2: Range: 0-17.5 m. i<=200, std=0.01i;
 * 200<i<=230, std=2+0.1(i-200) i>230, std=5+0.5(i-230).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header BoundsHeader Header of a bounds message.
 * @field ssr_iod number (unsigned 8-bit int, 1 byte) IOD of the SSR bound.
 * @field const_id number (unsigned 8-bit int, 1 byte) Constellation ID to which the SVs belong.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites.
 * @field orbit_clock_bounds array Orbit and Clock Bounds per Satellite
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrOrbitClockBounds = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_ORBIT_CLOCK_BOUNDS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrOrbitClockBounds.prototype = Object.create(SBP.prototype);
MsgSsrOrbitClockBounds.prototype.messageType = "MSG_SSR_ORBIT_CLOCK_BOUNDS";
MsgSsrOrbitClockBounds.prototype.msg_type = 0x05DE;
MsgSsrOrbitClockBounds.prototype.constructor = MsgSsrOrbitClockBounds;
MsgSsrOrbitClockBounds.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: BoundsHeader.prototype.parser })
  .uint8('ssr_iod')
  .uint8('const_id')
  .uint8('n_sats')
  .array('orbit_clock_bounds', { type: OrbitClockBound.prototype.parser, length: 'n_sats' });
MsgSsrOrbitClockBounds.prototype.fieldSpec = [];
MsgSsrOrbitClockBounds.prototype.fieldSpec.push(['header', BoundsHeader.prototype.fieldSpec]);
MsgSsrOrbitClockBounds.prototype.fieldSpec.push(['ssr_iod', 'writeUInt8', 1]);
MsgSsrOrbitClockBounds.prototype.fieldSpec.push(['const_id', 'writeUInt8', 1]);
MsgSsrOrbitClockBounds.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgSsrOrbitClockBounds.prototype.fieldSpec.push(['orbit_clock_bounds', 'array', OrbitClockBound.prototype.fieldSpec, function () { return this.fields.array.length; }, 'n_sats']);

/**
 * SBP class for message fragment CodePhaseBiasesSatSig
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sat_id number (unsigned 8-bit int, 1 byte) Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo), or DF488
 *   (BDS) depending on the constellation.
 * @field signal_id number (unsigned 8-bit int, 1 byte) Signal and Tracking Mode Identifier. Similar to either RTCM DF380 (GPS), DF382
 *   (Galileo) or DF467 (BDS) depending on the constellation.
 * @field code_bias_bound_mu number (unsigned 8-bit int, 1 byte) Code Bias Mean. Range: 0-1.275 m
 * @field code_bias_bound_sig number (unsigned 8-bit int, 1 byte) Code Bias Standard Deviation.  Range: 0-1.275 m
 * @field phase_bias_bound_mu number (unsigned 8-bit int, 1 byte) Phase Bias Mean. Range: 0-1.275 m
 * @field phase_bias_bound_sig number (unsigned 8-bit int, 1 byte) Phase Bias Standard Deviation.  Range: 0-1.275 m
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let CodePhaseBiasesSatSig = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "CodePhaseBiasesSatSig";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
CodePhaseBiasesSatSig.prototype = Object.create(SBP.prototype);
CodePhaseBiasesSatSig.prototype.messageType = "CodePhaseBiasesSatSig";
CodePhaseBiasesSatSig.prototype.constructor = CodePhaseBiasesSatSig;
CodePhaseBiasesSatSig.prototype.parser = new Parser()
  .endianess('little')
  .uint8('sat_id')
  .uint8('signal_id')
  .uint8('code_bias_bound_mu')
  .uint8('code_bias_bound_sig')
  .uint8('phase_bias_bound_mu')
  .uint8('phase_bias_bound_sig');
CodePhaseBiasesSatSig.prototype.fieldSpec = [];
CodePhaseBiasesSatSig.prototype.fieldSpec.push(['sat_id', 'writeUInt8', 1]);
CodePhaseBiasesSatSig.prototype.fieldSpec.push(['signal_id', 'writeUInt8', 1]);
CodePhaseBiasesSatSig.prototype.fieldSpec.push(['code_bias_bound_mu', 'writeUInt8', 1]);
CodePhaseBiasesSatSig.prototype.fieldSpec.push(['code_bias_bound_sig', 'writeUInt8', 1]);
CodePhaseBiasesSatSig.prototype.fieldSpec.push(['phase_bias_bound_mu', 'writeUInt8', 1]);
CodePhaseBiasesSatSig.prototype.fieldSpec.push(['phase_bias_bound_sig', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_CODE_PHASE_BIASES_BOUNDS (0x05EC).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header BoundsHeader Header of a bounds message.
 * @field ssr_iod number (unsigned 8-bit int, 1 byte) IOD of the SSR bound.
 * @field const_id number (unsigned 8-bit int, 1 byte) Constellation ID to which the SVs belong.
 * @field n_sats_signals number (unsigned 8-bit int, 1 byte) Number of satellite-signal couples.
 * @field satellites_signals array Code and Phase Biases Bounds per Satellite-Signal couple.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrCodePhaseBiasesBounds = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_CODE_PHASE_BIASES_BOUNDS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrCodePhaseBiasesBounds.prototype = Object.create(SBP.prototype);
MsgSsrCodePhaseBiasesBounds.prototype.messageType = "MSG_SSR_CODE_PHASE_BIASES_BOUNDS";
MsgSsrCodePhaseBiasesBounds.prototype.msg_type = 0x05EC;
MsgSsrCodePhaseBiasesBounds.prototype.constructor = MsgSsrCodePhaseBiasesBounds;
MsgSsrCodePhaseBiasesBounds.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: BoundsHeader.prototype.parser })
  .uint8('ssr_iod')
  .uint8('const_id')
  .uint8('n_sats_signals')
  .array('satellites_signals', { type: CodePhaseBiasesSatSig.prototype.parser, length: 'n_sats_signals' });
MsgSsrCodePhaseBiasesBounds.prototype.fieldSpec = [];
MsgSsrCodePhaseBiasesBounds.prototype.fieldSpec.push(['header', BoundsHeader.prototype.fieldSpec]);
MsgSsrCodePhaseBiasesBounds.prototype.fieldSpec.push(['ssr_iod', 'writeUInt8', 1]);
MsgSsrCodePhaseBiasesBounds.prototype.fieldSpec.push(['const_id', 'writeUInt8', 1]);
MsgSsrCodePhaseBiasesBounds.prototype.fieldSpec.push(['n_sats_signals', 'writeUInt8', 1]);
MsgSsrCodePhaseBiasesBounds.prototype.fieldSpec.push(['satellites_signals', 'array', CodePhaseBiasesSatSig.prototype.fieldSpec, function () { return this.fields.array.length; }, 'n_sats_signals']);

/**
 * SBP class for message fragment OrbitClockBoundDegradation
 *
 * Orbit and clock bound degradation.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field orb_radial_bound_mu_dot number (unsigned 8-bit int, 1 byte) Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
 * @field orb_along_bound_mu_dot number (unsigned 8-bit int, 1 byte) Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
 * @field orb_cross_bound_mu_dot number (unsigned 8-bit int, 1 byte) Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
 * @field orb_radial_bound_sig_dot number (unsigned 8-bit int, 1 byte) Orbit Bound Standard Deviation Radial First derivative. Range: 0-0.255 m/s
 * @field orb_along_bound_sig_dot number (unsigned 8-bit int, 1 byte) Orbit Bound Standard Deviation Along-Track First derivative. Range: 0-0.255 m/s
 * @field orb_cross_bound_sig_dot number (unsigned 8-bit int, 1 byte) Orbit Bound Standard Deviation Cross-Track First derivative. Range: 0-0.255 m/s
 * @field clock_bound_mu_dot number (unsigned 8-bit int, 1 byte) Clock Bound Mean First derivative. Range: 0-0.255 m/s
 * @field clock_bound_sig_dot number (unsigned 8-bit int, 1 byte) Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let OrbitClockBoundDegradation = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "OrbitClockBoundDegradation";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
OrbitClockBoundDegradation.prototype = Object.create(SBP.prototype);
OrbitClockBoundDegradation.prototype.messageType = "OrbitClockBoundDegradation";
OrbitClockBoundDegradation.prototype.constructor = OrbitClockBoundDegradation;
OrbitClockBoundDegradation.prototype.parser = new Parser()
  .endianess('little')
  .uint8('orb_radial_bound_mu_dot')
  .uint8('orb_along_bound_mu_dot')
  .uint8('orb_cross_bound_mu_dot')
  .uint8('orb_radial_bound_sig_dot')
  .uint8('orb_along_bound_sig_dot')
  .uint8('orb_cross_bound_sig_dot')
  .uint8('clock_bound_mu_dot')
  .uint8('clock_bound_sig_dot');
OrbitClockBoundDegradation.prototype.fieldSpec = [];
OrbitClockBoundDegradation.prototype.fieldSpec.push(['orb_radial_bound_mu_dot', 'writeUInt8', 1]);
OrbitClockBoundDegradation.prototype.fieldSpec.push(['orb_along_bound_mu_dot', 'writeUInt8', 1]);
OrbitClockBoundDegradation.prototype.fieldSpec.push(['orb_cross_bound_mu_dot', 'writeUInt8', 1]);
OrbitClockBoundDegradation.prototype.fieldSpec.push(['orb_radial_bound_sig_dot', 'writeUInt8', 1]);
OrbitClockBoundDegradation.prototype.fieldSpec.push(['orb_along_bound_sig_dot', 'writeUInt8', 1]);
OrbitClockBoundDegradation.prototype.fieldSpec.push(['orb_cross_bound_sig_dot', 'writeUInt8', 1]);
OrbitClockBoundDegradation.prototype.fieldSpec.push(['clock_bound_mu_dot', 'writeUInt8', 1]);
OrbitClockBoundDegradation.prototype.fieldSpec.push(['clock_bound_sig_dot', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION (0x05DF).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header BoundsHeader Header of a bounds message.
 * @field ssr_iod number (unsigned 8-bit int, 1 byte) IOD of the SSR bound degradation parameter.
 * @field const_id number (unsigned 8-bit int, 1 byte) Constellation ID to which the SVs belong.
 * @field sat_bitmask number (unsigned 64-bit int, 8 bytes) Satellite Bit Mask. Put 1 for each satellite where the following degradation
 *   parameters are applicable, 0 otherwise. Encoded following RTCM DF394
 *   specification.
 * @field orbit_clock_bounds_degradation OrbitClockBoundDegradation Orbit and Clock Bounds Degradation Parameters
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrOrbitClockBoundsDegradation = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrOrbitClockBoundsDegradation.prototype = Object.create(SBP.prototype);
MsgSsrOrbitClockBoundsDegradation.prototype.messageType = "MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION";
MsgSsrOrbitClockBoundsDegradation.prototype.msg_type = 0x05DF;
MsgSsrOrbitClockBoundsDegradation.prototype.constructor = MsgSsrOrbitClockBoundsDegradation;
MsgSsrOrbitClockBoundsDegradation.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: BoundsHeader.prototype.parser })
  .uint8('ssr_iod')
  .uint8('const_id')
  .uint64('sat_bitmask')
  .nest('orbit_clock_bounds_degradation', { type: OrbitClockBoundDegradation.prototype.parser });
MsgSsrOrbitClockBoundsDegradation.prototype.fieldSpec = [];
MsgSsrOrbitClockBoundsDegradation.prototype.fieldSpec.push(['header', BoundsHeader.prototype.fieldSpec]);
MsgSsrOrbitClockBoundsDegradation.prototype.fieldSpec.push(['ssr_iod', 'writeUInt8', 1]);
MsgSsrOrbitClockBoundsDegradation.prototype.fieldSpec.push(['const_id', 'writeUInt8', 1]);
MsgSsrOrbitClockBoundsDegradation.prototype.fieldSpec.push(['sat_bitmask', 'writeUInt64LE', 8]);
MsgSsrOrbitClockBoundsDegradation.prototype.fieldSpec.push(['orbit_clock_bounds_degradation', OrbitClockBoundDegradation.prototype.fieldSpec]);

module.exports = {
  CodeBiasesContent: CodeBiasesContent,
  PhaseBiasesContent: PhaseBiasesContent,
  STECHeader: STECHeader,
  GriddedCorrectionHeader: GriddedCorrectionHeader,
  STECSatElement: STECSatElement,
  TroposphericDelayCorrectionNoStd: TroposphericDelayCorrectionNoStd,
  TroposphericDelayCorrection: TroposphericDelayCorrection,
  STECResidualNoStd: STECResidualNoStd,
  STECResidual: STECResidual,
  0x05DD: MsgSsrOrbitClock,
  MsgSsrOrbitClock: MsgSsrOrbitClock,
  0x05E1: MsgSsrCodeBiases,
  MsgSsrCodeBiases: MsgSsrCodeBiases,
  0x05E6: MsgSsrPhaseBiases,
  MsgSsrPhaseBiases: MsgSsrPhaseBiases,
  0x05FB: MsgSsrStecCorrectionDep,
  MsgSsrStecCorrectionDep: MsgSsrStecCorrectionDep,
  BoundsHeader: BoundsHeader,
  0x05FD: MsgSsrStecCorrection,
  MsgSsrStecCorrection: MsgSsrStecCorrection,
  0x05FC: MsgSsrGriddedCorrection,
  MsgSsrGriddedCorrection: MsgSsrGriddedCorrection,
  STECSatElementIntegrity: STECSatElementIntegrity,
  0x05FE: MsgSsrGriddedCorrectionBounds,
  MsgSsrGriddedCorrectionBounds: MsgSsrGriddedCorrectionBounds,
  0x05F6: MsgSsrTileDefinitionDep,
  MsgSsrTileDefinitionDep: MsgSsrTileDefinitionDep,
  0x05F7: MsgSsrTileDefinition,
  MsgSsrTileDefinition: MsgSsrTileDefinition,
  SatelliteAPC: SatelliteAPC,
  0x0604: MsgSsrSatelliteApc,
  MsgSsrSatelliteApc: MsgSsrSatelliteApc,
  0x05DC: MsgSsrOrbitClockDepA,
  MsgSsrOrbitClockDepA: MsgSsrOrbitClockDepA,
  STECHeaderDepA: STECHeaderDepA,
  GriddedCorrectionHeaderDepA: GriddedCorrectionHeaderDepA,
  GridDefinitionHeaderDepA: GridDefinitionHeaderDepA,
  0x05EB: MsgSsrStecCorrectionDepA,
  MsgSsrStecCorrectionDepA: MsgSsrStecCorrectionDepA,
  0x05F0: MsgSsrGriddedCorrectionNoStdDepA,
  MsgSsrGriddedCorrectionNoStdDepA: MsgSsrGriddedCorrectionNoStdDepA,
  0x05FA: MsgSsrGriddedCorrectionDepA,
  MsgSsrGriddedCorrectionDepA: MsgSsrGriddedCorrectionDepA,
  0x05F5: MsgSsrGridDefinitionDepA,
  MsgSsrGridDefinitionDepA: MsgSsrGridDefinitionDepA,
  OrbitClockBound: OrbitClockBound,
  0x05DE: MsgSsrOrbitClockBounds,
  MsgSsrOrbitClockBounds: MsgSsrOrbitClockBounds,
  CodePhaseBiasesSatSig: CodePhaseBiasesSatSig,
  0x05EC: MsgSsrCodePhaseBiasesBounds,
  MsgSsrCodePhaseBiasesBounds: MsgSsrCodePhaseBiasesBounds,
  OrbitClockBoundDegradation: OrbitClockBoundDegradation,
  0x05DF: MsgSsrOrbitClockBoundsDegradation,
  MsgSsrOrbitClockBoundsDegradation: MsgSsrOrbitClockBoundsDegradation,
}