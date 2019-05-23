/**
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/**********************
 * Automatically generated from piksi/yaml/swiftnav/sbp/ssr.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Precise State Space Representation (SSR) corrections format
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;
var GnssSignal = require("./gnss").GnssSignal;
var GnssSignalDep = require("./gnss").GnssSignalDep;
var GPSTime = require("./gnss").GPSTime;
var CarrierPhase = require("./gnss").CarrierPhase;
var GPSTime = require("./gnss").GPSTime;
var GPSTimeSec = require("./gnss").GPSTimeSec;
var GPSTimeDep = require("./gnss").GPSTimeDep;
var SvId = require("./gnss").SvId;

/**
 * SBP class for message fragment CodeBiasesContent
 *
 * Code biases are to be added to pseudorange. The corrections are conform with
 * typical RTCMv3 MT1059 and 1065.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field code number (unsigned 8-bit int, 1 byte) Signal constellation, band and code
 * @field value number (signed 16-bit int, 2 bytes) Code bias value
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var CodeBiasesContent = function (sbp, fields) {
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
 * Phase biases are to be added to carrier phase measurements. The corrections are
 * conform with typical RTCMv3 MT1059 and 1065.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field code number (unsigned 8-bit int, 1 byte) Signal constellation, band and code
 * @field integer_indicator number (unsigned 8-bit int, 1 byte) Indicator for integer property
 * @field widelane_integer_indicator number (unsigned 8-bit int, 1 byte) Indicator for two groups of Wide-Lane(s) integer property
 * @field discontinuity_counter number (unsigned 8-bit int, 1 byte) Signal phase discontinuity counter. Increased for every discontinuity in phase.
 * @field bias number (signed 32-bit int, 4 bytes) Phase bias for specified signal
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PhaseBiasesContent = function (sbp, fields) {
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
 * @field time GPSTime GNSS time of the STEC data
 * @field num_msgs number (unsigned 8-bit int, 1 byte) Number of messages in the dataset
 * @field seq_num number (unsigned 8-bit int, 1 byte) Position of this message in the dataset
 * @field ssr_update_interval number (unsigned 16-bit int, 2 bytes) update interval in seconds
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) range 0 - 15
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var STECHeader = function (sbp, fields) {
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
  .nest('time', { type: GPSTime.prototype.parser })
  .uint8('num_msgs')
  .uint8('seq_num')
  .uint16('ssr_update_interval')
  .uint8('iod_ssr');
STECHeader.prototype.fieldSpec = [];
STECHeader.prototype.fieldSpec.push(['time', GPSTime.prototype.fieldSpec]);
STECHeader.prototype.fieldSpec.push(['num_msgs', 'writeUInt8', 1]);
STECHeader.prototype.fieldSpec.push(['seq_num', 'writeUInt8', 1]);
STECHeader.prototype.fieldSpec.push(['ssr_update_interval', 'writeUInt16LE', 2]);
STECHeader.prototype.fieldSpec.push(['iod_ssr', 'writeUInt8', 1]);

/**
 * SBP class for message fragment GriddedCorrectionHeader
 *
 * The 3GPP message contains nested variable length arrays which are not suppported
 * in SBP, so each grid point will be identified by the index.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTime GNSS time of the STEC data
 * @field num_msgs number (unsigned 16-bit int, 2 bytes) Number of messages in the dataset
 * @field seq_num number (unsigned 16-bit int, 2 bytes) Position of this message in the dataset
 * @field ssr_update_interval number (unsigned 16-bit int, 2 bytes) update interval in seconds
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) range 0 - 15
 * @field tropo_quality number (unsigned 8-bit int, 1 byte) troposphere quality indicator
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GriddedCorrectionHeader = function (sbp, fields) {
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
  .nest('time', { type: GPSTime.prototype.parser })
  .uint16('num_msgs')
  .uint16('seq_num')
  .uint16('ssr_update_interval')
  .uint8('iod_ssr')
  .uint8('tropo_quality');
GriddedCorrectionHeader.prototype.fieldSpec = [];
GriddedCorrectionHeader.prototype.fieldSpec.push(['time', GPSTime.prototype.fieldSpec]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['num_msgs', 'writeUInt16LE', 2]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['seq_num', 'writeUInt16LE', 2]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['ssr_update_interval', 'writeUInt16LE', 2]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['iod_ssr', 'writeUInt8', 1]);
GriddedCorrectionHeader.prototype.fieldSpec.push(['tropo_quality', 'writeUInt8', 1]);

/**
 * SBP class for message fragment STECSatElement
 *
 * STEC for the given satellite.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sv_id SvId Unique space vehicle identifier
 * @field stec_quality_indicator number (unsigned 8-bit int, 1 byte) quality of STEC data
 * @field stec_coeff array coefficents of the STEC polynomial
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var STECSatElement = function (sbp, fields) {
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
 * SBP class for message fragment TroposphericDelayCorrection
 *
 * Contains wet vertical and hydrostatic vertical delay
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field hydro number (signed 16-bit int, 2 bytes) hydrostatic vertical delay
 * @field wet number (signed 8-bit int, 1 byte) wet vertical delay
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TroposphericDelayCorrection = function (sbp, fields) {
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
  .int8('wet');
TroposphericDelayCorrection.prototype.fieldSpec = [];
TroposphericDelayCorrection.prototype.fieldSpec.push(['hydro', 'writeInt16LE', 2]);
TroposphericDelayCorrection.prototype.fieldSpec.push(['wet', 'writeInt8', 1]);

/**
 * SBP class for message fragment STECResidual
 *
 * STEC residual
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sv_id SvId space vehicle identifier
 * @field residual number (signed 16-bit int, 2 bytes) STEC residual
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var STECResidual = function (sbp, fields) {
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
  .int16('residual');
STECResidual.prototype.fieldSpec = [];
STECResidual.prototype.fieldSpec.push(['sv_id', SvId.prototype.fieldSpec]);
STECResidual.prototype.fieldSpec.push(['residual', 'writeInt16LE', 2]);

/**
 * SBP class for message fragment GridElement
 *
 * Contains one tropo datum, plus STEC residuals for each space vehicle
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 16-bit int, 2 bytes) index of the grid point
 * @field tropo_delay_correction TroposphericDelayCorrection Wet and Hydrostatic Vertical Delay
 * @field STEC_residuals array STEC Residual for the given space vehicle
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GridElement = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GridElement";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GridElement.prototype = Object.create(SBP.prototype);
GridElement.prototype.messageType = "GridElement";
GridElement.prototype.constructor = GridElement;
GridElement.prototype.parser = new Parser()
  .endianess('little')
  .uint16('index')
  .nest('tropo_delay_correction', { type: TroposphericDelayCorrection.prototype.parser })
  .array('STEC_residuals', { type: STECResidual.prototype.parser, readUntil: 'eof' });
GridElement.prototype.fieldSpec = [];
GridElement.prototype.fieldSpec.push(['index', 'writeUInt16LE', 2]);
GridElement.prototype.fieldSpec.push(['tropo_delay_correction', TroposphericDelayCorrection.prototype.fieldSpec]);
GridElement.prototype.fieldSpec.push(['STEC_residuals', 'array', STECResidual.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment GridDefinitionHeader
 *
 * Defines the grid for STEC and tropo grid messages. Also includes an RLE encoded
 * validity list.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field region_size_inverse number (unsigned 8-bit int, 1 byte) inverse of region size
 * @field area_width number (unsigned 16-bit int, 2 bytes) area width; see spec for details
 * @field lat_nw_corner_enc number (unsigned 16-bit int, 2 bytes) encoded latitude of the northwest corner of the grid
 * @field lon_nw_corner_enc number (unsigned 16-bit int, 2 bytes) encoded longitude of the northwest corner of the grid
 * @field num_msgs number (unsigned 8-bit int, 1 byte) Number of messages in the dataset
 * @field seq_num number (unsigned 8-bit int, 1 byte) Postion of this message in the dataset
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GridDefinitionHeader = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GridDefinitionHeader";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GridDefinitionHeader.prototype = Object.create(SBP.prototype);
GridDefinitionHeader.prototype.messageType = "GridDefinitionHeader";
GridDefinitionHeader.prototype.constructor = GridDefinitionHeader;
GridDefinitionHeader.prototype.parser = new Parser()
  .endianess('little')
  .uint8('region_size_inverse')
  .uint16('area_width')
  .uint16('lat_nw_corner_enc')
  .uint16('lon_nw_corner_enc')
  .uint8('num_msgs')
  .uint8('seq_num');
GridDefinitionHeader.prototype.fieldSpec = [];
GridDefinitionHeader.prototype.fieldSpec.push(['region_size_inverse', 'writeUInt8', 1]);
GridDefinitionHeader.prototype.fieldSpec.push(['area_width', 'writeUInt16LE', 2]);
GridDefinitionHeader.prototype.fieldSpec.push(['lat_nw_corner_enc', 'writeUInt16LE', 2]);
GridDefinitionHeader.prototype.fieldSpec.push(['lon_nw_corner_enc', 'writeUInt16LE', 2]);
GridDefinitionHeader.prototype.fieldSpec.push(['num_msgs', 'writeUInt8', 1]);
GridDefinitionHeader.prototype.fieldSpec.push(['seq_num', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DD).
 *
 * The precise orbit and clock correction message is to be applied as a delta
 * correction to broadcast ephemeris and is typically an equivalent to the 1060 and
 * 1066 RTCM message types
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections
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
var MsgSsrOrbitClock = function (sbp, fields) {
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
 * SBP class for message MSG_SSR_ORBIT_CLOCK_DEP_A (0x05DC).
 *
 * The precise orbit and clock correction message is to be applied as a delta
 * correction to broadcast ephemeris and is typically an equivalent to the 1060 and
 * 1066 RTCM message types
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections
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
var MsgSsrOrbitClockDepA = function (sbp, fields) {
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
 * SBP class for message MSG_SSR_CODE_BIASES (0x05E1).
 *
 * The precise code biases message is to be added to the pseudorange of the
 * corresponding signal to get corrected pseudorange. It is typically an equivalent
 * to the 1059 and 1065 RTCM message types
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) IOD of the SSR correction. A change of Issue Of Data SSR is used to indicate a
 *   change in the SSR generating configuration
 * @field biases array Code biases for the different satellite signals
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrCodeBiases = function (sbp, fields) {
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
 * correction. It is typically an equivalent to the 1265 RTCM message types
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections
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
var MsgSsrPhaseBiases = function (sbp, fields) {
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
 * SBP class for message MSG_SSR_STEC_CORRECTION (0x05EB).
 *
 * The STEC per space vehicle, given as polynomial approximation for a given grid.
 * This should be combined with SSR-GriddedCorrection message to get the state
 * space representation of the atmospheric delay.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header STECHeader Header of a STEC message
 * @field stec_sat_list array Array of STEC information for each space vehicle
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrStecCorrection = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_STEC_CORRECTION";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrStecCorrection.prototype = Object.create(SBP.prototype);
MsgSsrStecCorrection.prototype.messageType = "MSG_SSR_STEC_CORRECTION";
MsgSsrStecCorrection.prototype.msg_type = 0x05EB;
MsgSsrStecCorrection.prototype.constructor = MsgSsrStecCorrection;
MsgSsrStecCorrection.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: STECHeader.prototype.parser })
  .array('stec_sat_list', { type: STECSatElement.prototype.parser, readUntil: 'eof' });
MsgSsrStecCorrection.prototype.fieldSpec = [];
MsgSsrStecCorrection.prototype.fieldSpec.push(['header', STECHeader.prototype.fieldSpec]);
MsgSsrStecCorrection.prototype.fieldSpec.push(['stec_sat_list', 'array', STECSatElement.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_SSR_GRIDDED_CORRECTION (0x05F0).
 *
 * STEC residuals are per space vehicle, tropo is not.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header GriddedCorrectionHeader Header of a Gridded Correction message
 * @field element GridElement Tropo and STEC residuals for the given grid point
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrGriddedCorrection = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_GRIDDED_CORRECTION";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrGriddedCorrection.prototype = Object.create(SBP.prototype);
MsgSsrGriddedCorrection.prototype.messageType = "MSG_SSR_GRIDDED_CORRECTION";
MsgSsrGriddedCorrection.prototype.msg_type = 0x05F0;
MsgSsrGriddedCorrection.prototype.constructor = MsgSsrGriddedCorrection;
MsgSsrGriddedCorrection.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: GriddedCorrectionHeader.prototype.parser })
  .nest('element', { type: GridElement.prototype.parser });
MsgSsrGriddedCorrection.prototype.fieldSpec = [];
MsgSsrGriddedCorrection.prototype.fieldSpec.push(['header', GriddedCorrectionHeader.prototype.fieldSpec]);
MsgSsrGriddedCorrection.prototype.fieldSpec.push(['element', GridElement.prototype.fieldSpec]);

/**
 * SBP class for message MSG_SSR_GRID_DEFINITION (0x05F5).
 *
 * Definition of the grid for STEC and tropo messages
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header GridDefinitionHeader Header of a Gridded Correction message
 * @field rle_list array Run Length Encode list of quadrants that contain valid data. The spec describes
 *   the encoding scheme in detail, but essentially the index of the quadrants that
 *   contain transitions between valid and invalid (and vice versa) are encoded as u8
 *   integers.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrGridDefinition = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_GRID_DEFINITION";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrGridDefinition.prototype = Object.create(SBP.prototype);
MsgSsrGridDefinition.prototype.messageType = "MSG_SSR_GRID_DEFINITION";
MsgSsrGridDefinition.prototype.msg_type = 0x05F5;
MsgSsrGridDefinition.prototype.constructor = MsgSsrGridDefinition;
MsgSsrGridDefinition.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: GridDefinitionHeader.prototype.parser })
  .array('rle_list', { type: 'uint8', readUntil: 'eof' });
MsgSsrGridDefinition.prototype.fieldSpec = [];
MsgSsrGridDefinition.prototype.fieldSpec.push(['header', GridDefinitionHeader.prototype.fieldSpec]);
MsgSsrGridDefinition.prototype.fieldSpec.push(['rle_list', 'array', 'writeUInt8', function () { return 1; }, null]);

module.exports = {
  CodeBiasesContent: CodeBiasesContent,
  PhaseBiasesContent: PhaseBiasesContent,
  STECHeader: STECHeader,
  GriddedCorrectionHeader: GriddedCorrectionHeader,
  STECSatElement: STECSatElement,
  TroposphericDelayCorrection: TroposphericDelayCorrection,
  STECResidual: STECResidual,
  GridElement: GridElement,
  GridDefinitionHeader: GridDefinitionHeader,
  0x05DD: MsgSsrOrbitClock,
  MsgSsrOrbitClock: MsgSsrOrbitClock,
  0x05DC: MsgSsrOrbitClockDepA,
  MsgSsrOrbitClockDepA: MsgSsrOrbitClockDepA,
  0x05E1: MsgSsrCodeBiases,
  MsgSsrCodeBiases: MsgSsrCodeBiases,
  0x05E6: MsgSsrPhaseBiases,
  MsgSsrPhaseBiases: MsgSsrPhaseBiases,
  0x05EB: MsgSsrStecCorrection,
  MsgSsrStecCorrection: MsgSsrStecCorrection,
  0x05F0: MsgSsrGriddedCorrection,
  MsgSsrGriddedCorrection: MsgSsrGriddedCorrection,
  0x05F5: MsgSsrGridDefinition,
  MsgSsrGridDefinition: MsgSsrGridDefinition,
}