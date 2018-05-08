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
 * Automatically generated from piksi/yaml/swiftnav/sbp/observation.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Satellite observation messages from the device.
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

/**
 * SBP class for message fragment ObservationHeader
 *
 * Header of a GNSS observation message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t GPSTime GNSS time of this observation
 * @field n_obs number (unsigned 8-bit int, 1 byte) Total number of observations. First nibble is the size of the sequence (n),
 *   second nibble is the zero-indexed counter (ith packet of n)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var ObservationHeader = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "ObservationHeader";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
ObservationHeader.prototype = Object.create(SBP.prototype);
ObservationHeader.prototype.messageType = "ObservationHeader";
ObservationHeader.prototype.constructor = ObservationHeader;
ObservationHeader.prototype.parser = new Parser()
  .endianess('little')
  .nest('t', { type: GPSTime.prototype.parser })
  .uint8('n_obs');
ObservationHeader.prototype.fieldSpec = [];
ObservationHeader.prototype.fieldSpec.push(['t', GPSTime.prototype.fieldSpec]);
ObservationHeader.prototype.fieldSpec.push(['n_obs', 'writeUInt8', 1]);

/**
 * SBP class for message fragment Doppler
 *
 * Doppler measurement in Hz represented as a 24-bit fixed point number with Q16.8
 * layout, i.e. 16-bits of whole doppler and 8-bits of fractional doppler. This
 * doppler is defined as positive for approaching satellites.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field i number (signed 16-bit int, 2 bytes) Doppler whole Hz
 * @field f number (unsigned 8-bit int, 1 byte) Doppler fractional part
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var Doppler = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "Doppler";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
Doppler.prototype = Object.create(SBP.prototype);
Doppler.prototype.messageType = "Doppler";
Doppler.prototype.constructor = Doppler;
Doppler.prototype.parser = new Parser()
  .endianess('little')
  .int16('i')
  .uint8('f');
Doppler.prototype.fieldSpec = [];
Doppler.prototype.fieldSpec.push(['i', 'writeInt16LE', 2]);
Doppler.prototype.fieldSpec.push(['f', 'writeUInt8', 1]);

/**
 * SBP class for message fragment PackedObsContent
 *
 * Pseudorange and carrier phase observation for a satellite being tracked. The
 * observations are interoperable with 3rd party receivers and conform with typical
 * RTCMv3 GNSS observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation
 * @field L CarrierPhase Carrier phase observation with typical sign convention.
 * @field D Doppler Doppler observation with typical sign convention.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density.  Zero implies invalid cn0.
 * @field lock number (unsigned 8-bit int, 1 byte) Lock timer. This value gives an indication of the time for which a signal has
 *   maintained continuous phase lock. Whenever a signal has lost and regained lock,
 *   this value is reset to zero. It is encoded according to DF402 from the RTCM
 *   10403.2 Amendment 2 specification.  Valid values range from 0 to 15 and the most
 *   significant nibble is reserved for future use.
 * @field flags number (unsigned 8-bit int, 1 byte) Measurement status flags. A bit field of flags providing the status of this
 *   observation.  If this field is 0 it means only the Cn0 estimate for the signal
 *   is valid.
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PackedObsContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PackedObsContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PackedObsContent.prototype = Object.create(SBP.prototype);
PackedObsContent.prototype.messageType = "PackedObsContent";
PackedObsContent.prototype.constructor = PackedObsContent;
PackedObsContent.prototype.parser = new Parser()
  .endianess('little')
  .uint32('P')
  .nest('L', { type: CarrierPhase.prototype.parser })
  .nest('D', { type: Doppler.prototype.parser })
  .uint8('cn0')
  .uint8('lock')
  .uint8('flags')
  .nest('sid', { type: GnssSignal.prototype.parser });
PackedObsContent.prototype.fieldSpec = [];
PackedObsContent.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
PackedObsContent.prototype.fieldSpec.push(['L', CarrierPhase.prototype.fieldSpec]);
PackedObsContent.prototype.fieldSpec.push(['D', Doppler.prototype.fieldSpec]);
PackedObsContent.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
PackedObsContent.prototype.fieldSpec.push(['lock', 'writeUInt8', 1]);
PackedObsContent.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
PackedObsContent.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);

/**
 * SBP class for message MSG_OBS (0x004A).
 *
 * The GPS observations message reports all the raw pseudorange and carrier phase
 * observations for the satellites being tracked by the device. Carrier phase
 * observation here is represented as a 40-bit fixed point number with Q32.8 layout
 * (i.e. 32-bits of whole cycles and 8-bits of fractional cycles). The observations
 * are be interoperable with 3rd party receivers and conform with typical RTCMv3
 * GNSS observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header ObservationHeader Header of a GPS observation message
 * @field obs array Pseudorange and carrier phase observation for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgObs = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_OBS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgObs.prototype = Object.create(SBP.prototype);
MsgObs.prototype.messageType = "MSG_OBS";
MsgObs.prototype.msg_type = 0x004A;
MsgObs.prototype.constructor = MsgObs;
MsgObs.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: ObservationHeader.prototype.parser })
  .array('obs', { type: PackedObsContent.prototype.parser, readUntil: 'eof' });
MsgObs.prototype.fieldSpec = [];
MsgObs.prototype.fieldSpec.push(['header', ObservationHeader.prototype.fieldSpec]);
MsgObs.prototype.fieldSpec.push(['obs', 'array', PackedObsContent.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_BASE_POS_LLH (0x0044).
 *
 * The base station position message is the position reported by the base station
 * itself. It is used for pseudo-absolute RTK positioning, and is required to be a
 * high-accuracy surveyed location of the base station. Any error here will result
 * in an error in the pseudo-absolute position output.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field lat number (float, 8 bytes) Latitude
 * @field lon number (float, 8 bytes) Longitude
 * @field height number (float, 8 bytes) Height
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBasePosLlh = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASE_POS_LLH";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBasePosLlh.prototype = Object.create(SBP.prototype);
MsgBasePosLlh.prototype.messageType = "MSG_BASE_POS_LLH";
MsgBasePosLlh.prototype.msg_type = 0x0044;
MsgBasePosLlh.prototype.constructor = MsgBasePosLlh;
MsgBasePosLlh.prototype.parser = new Parser()
  .endianess('little')
  .doublele('lat')
  .doublele('lon')
  .doublele('height');
MsgBasePosLlh.prototype.fieldSpec = [];
MsgBasePosLlh.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgBasePosLlh.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgBasePosLlh.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_BASE_POS_ECEF (0x0048).
 *
 * The base station position message is the position reported by the base station
 * itself in absolute Earth Centered Earth Fixed coordinates. It is used for
 * pseudo-absolute RTK positioning, and is required to be a high-accuracy surveyed
 * location of the base station. Any error here will result in an error in the
 * pseudo-absolute position output.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field x number (float, 8 bytes) ECEF X coodinate
 * @field y number (float, 8 bytes) ECEF Y coordinate
 * @field z number (float, 8 bytes) ECEF Z coordinate
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBasePosEcef = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASE_POS_ECEF";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBasePosEcef.prototype = Object.create(SBP.prototype);
MsgBasePosEcef.prototype.messageType = "MSG_BASE_POS_ECEF";
MsgBasePosEcef.prototype.msg_type = 0x0048;
MsgBasePosEcef.prototype.constructor = MsgBasePosEcef;
MsgBasePosEcef.prototype.parser = new Parser()
  .endianess('little')
  .doublele('x')
  .doublele('y')
  .doublele('z');
MsgBasePosEcef.prototype.fieldSpec = [];
MsgBasePosEcef.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgBasePosEcef.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgBasePosEcef.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);

/**
 * SBP class for message fragment EphemerisCommonContent
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field toe GPSTimeSec Time of Ephemerides
 * @field ura number (float, 8 bytes) User Range Accuracy
 * @field fit_interval number (unsigned 32-bit int, 4 bytes) Curve fit interval
 * @field valid number (unsigned 8-bit int, 1 byte) Status of ephemeris, 1 = valid, 0 = invalid
 * @field health_bits number (unsigned 8-bit int, 1 byte) Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 Others: 0 =
 *   valid, non-zero = invalid
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var EphemerisCommonContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "EphemerisCommonContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
EphemerisCommonContent.prototype = Object.create(SBP.prototype);
EphemerisCommonContent.prototype.messageType = "EphemerisCommonContent";
EphemerisCommonContent.prototype.constructor = EphemerisCommonContent;
EphemerisCommonContent.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .nest('toe', { type: GPSTimeSec.prototype.parser })
  .doublele('ura')
  .uint32('fit_interval')
  .uint8('valid')
  .uint8('health_bits');
EphemerisCommonContent.prototype.fieldSpec = [];
EphemerisCommonContent.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
EphemerisCommonContent.prototype.fieldSpec.push(['toe', GPSTimeSec.prototype.fieldSpec]);
EphemerisCommonContent.prototype.fieldSpec.push(['ura', 'writeDoubleLE', 8]);
EphemerisCommonContent.prototype.fieldSpec.push(['fit_interval', 'writeUInt32LE', 4]);
EphemerisCommonContent.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
EphemerisCommonContent.prototype.fieldSpec.push(['health_bits', 'writeUInt8', 1]);

/**
 * SBP class for message fragment EphemerisCommonContentDepA
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignalDep GNSS signal identifier
 * @field toe GPSTimeDep Time of Ephemerides
 * @field ura number (float, 8 bytes) User Range Accuracy
 * @field fit_interval number (unsigned 32-bit int, 4 bytes) Curve fit interval
 * @field valid number (unsigned 8-bit int, 1 byte) Status of ephemeris, 1 = valid, 0 = invalid
 * @field health_bits number (unsigned 8-bit int, 1 byte) Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0 = valid,
 *   non-zero = invalid GLO: 0 = valid, non-zero = invalid
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var EphemerisCommonContentDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "EphemerisCommonContentDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
EphemerisCommonContentDepA.prototype = Object.create(SBP.prototype);
EphemerisCommonContentDepA.prototype.messageType = "EphemerisCommonContentDepA";
EphemerisCommonContentDepA.prototype.constructor = EphemerisCommonContentDepA;
EphemerisCommonContentDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .nest('toe', { type: GPSTimeDep.prototype.parser })
  .doublele('ura')
  .uint32('fit_interval')
  .uint8('valid')
  .uint8('health_bits');
EphemerisCommonContentDepA.prototype.fieldSpec = [];
EphemerisCommonContentDepA.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['toe', GPSTimeDep.prototype.fieldSpec]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['ura', 'writeDoubleLE', 8]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['fit_interval', 'writeUInt32LE', 4]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['health_bits', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_GPS_DEP_E (0x0081).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GPS satellite position, velocity, and clock offset. Please see the
 * Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Table 20-III)
 * for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepA Values common for all ephemeris types
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toc GPSTimeDep Clock reference
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGpsDepE = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GPS_DEP_E";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGpsDepE.prototype = Object.create(SBP.prototype);
MsgEphemerisGpsDepE.prototype.messageType = "MSG_EPHEMERIS_GPS_DEP_E";
MsgEphemerisGpsDepE.prototype.msg_type = 0x0081;
MsgEphemerisGpsDepE.prototype.constructor = MsgEphemerisGpsDepE;
MsgEphemerisGpsDepE.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepA.prototype.parser })
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .nest('toc', { type: GPSTimeDep.prototype.parser })
  .uint8('iode')
  .uint16('iodc');
MsgEphemerisGpsDepE.prototype.fieldSpec = [];
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['common', EphemerisCommonContentDepA.prototype.fieldSpec]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['toc', GPSTimeDep.prototype.fieldSpec]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_EPHEMERIS_GPS (0x0086).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GPS satellite position, velocity, and clock offset. Please see the
 * Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Table 20-III)
 * for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContent Values common for all ephemeris types
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toc GPSTimeSec Clock reference
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGps = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GPS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGps.prototype = Object.create(SBP.prototype);
MsgEphemerisGps.prototype.messageType = "MSG_EPHEMERIS_GPS";
MsgEphemerisGps.prototype.msg_type = 0x0086;
MsgEphemerisGps.prototype.constructor = MsgEphemerisGps;
MsgEphemerisGps.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContent.prototype.parser })
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .nest('toc', { type: GPSTimeSec.prototype.parser })
  .uint8('iode')
  .uint16('iodc');
MsgEphemerisGps.prototype.fieldSpec = [];
MsgEphemerisGps.prototype.fieldSpec.push(['common', EphemerisCommonContent.prototype.fieldSpec]);
MsgEphemerisGps.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['toc', GPSTimeSec.prototype.fieldSpec]);
MsgEphemerisGps.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);
MsgEphemerisGps.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_EPHEMERIS_GAL (0x0095).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate Galileo satellite position, velocity, and clock offset. Please see
 * the Signal In Space ICD OS SIS ICD, Issue 1.3, December 2016 for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContent Values common for all ephemeris types
 * @field bgd_e1e5a number (float, 4 bytes) Group delay differential between L1 and L2
 * @field bgd_e1e5b number (float, 4 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 4 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 4 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 4 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 4 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 4 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 4 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 4 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 4 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 4 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toc GPSTimeSec Clock reference
 * @field iode number (unsigned 16-bit int, 2 bytes) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGal = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GAL";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGal.prototype = Object.create(SBP.prototype);
MsgEphemerisGal.prototype.messageType = "MSG_EPHEMERIS_GAL";
MsgEphemerisGal.prototype.msg_type = 0x0095;
MsgEphemerisGal.prototype.constructor = MsgEphemerisGal;
MsgEphemerisGal.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContent.prototype.parser })
  .floatle('bgd_e1e5a')
  .floatle('bgd_e1e5b')
  .floatle('c_rs')
  .floatle('c_rc')
  .floatle('c_uc')
  .floatle('c_us')
  .floatle('c_ic')
  .floatle('c_is')
  .floatle('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .floatle('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .floatle('af2')
  .nest('toc', { type: GPSTimeSec.prototype.parser })
  .uint16('iode')
  .uint16('iodc');
MsgEphemerisGal.prototype.fieldSpec = [];
MsgEphemerisGal.prototype.fieldSpec.push(['common', EphemerisCommonContent.prototype.fieldSpec]);
MsgEphemerisGal.prototype.fieldSpec.push(['bgd_e1e5a', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['bgd_e1e5b', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['c_rs', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['c_rc', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['c_uc', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['c_us', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['c_ic', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['c_is', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['dn', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisGal.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisGal.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisGal.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisGal.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisGal.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisGal.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisGal.prototype.fieldSpec.push(['inc_dot', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisGal.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisGal.prototype.fieldSpec.push(['af2', 'writeFloatLE', 4]);
MsgEphemerisGal.prototype.fieldSpec.push(['toc', GPSTimeSec.prototype.fieldSpec]);
MsgEphemerisGal.prototype.fieldSpec.push(['iode', 'writeUInt16LE', 2]);
MsgEphemerisGal.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_EPHEMERIS_SBAS_DEP_A (0x0082).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepA Values common for all ephemeris types
 * @field pos array Position of the GEO at time toe
 * @field vel array Velocity of the GEO at time toe
 * @field acc array Acceleration of the GEO at time toe
 * @field a_gf0 number (float, 8 bytes) Time offset of the GEO clock w.r.t. SBAS Network Time
 * @field a_gf1 number (float, 8 bytes) Drift of the GEO clock w.r.t. SBAS Network Time
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisSbasDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_SBAS_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisSbasDepA.prototype = Object.create(SBP.prototype);
MsgEphemerisSbasDepA.prototype.messageType = "MSG_EPHEMERIS_SBAS_DEP_A";
MsgEphemerisSbasDepA.prototype.msg_type = 0x0082;
MsgEphemerisSbasDepA.prototype.constructor = MsgEphemerisSbasDepA;
MsgEphemerisSbasDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepA.prototype.parser })
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' })
  .doublele('a_gf0')
  .doublele('a_gf1');
MsgEphemerisSbasDepA.prototype.fieldSpec = [];
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['common', EphemerisCommonContentDepA.prototype.fieldSpec]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['a_gf0', 'writeDoubleLE', 8]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['a_gf1', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_EPHEMERIS_GLO_DEP_A (0x0083).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GLO satellite position, velocity, and clock offset. Please see the
 * GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate information
 * (ephemeris parameters)" for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepA Values common for all ephemeris types
 * @field gamma number (float, 8 bytes) Relative deviation of predicted carrier frequency from nominal
 * @field tau number (float, 8 bytes) Correction to the SV time
 * @field pos array Position of the SV at tb in PZ-90.02 coordinates system
 * @field vel array Velocity vector of the SV at tb in PZ-90.02 coordinates system
 * @field acc array Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGloDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GLO_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGloDepA.prototype = Object.create(SBP.prototype);
MsgEphemerisGloDepA.prototype.messageType = "MSG_EPHEMERIS_GLO_DEP_A";
MsgEphemerisGloDepA.prototype.msg_type = 0x0083;
MsgEphemerisGloDepA.prototype.constructor = MsgEphemerisGloDepA;
MsgEphemerisGloDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepA.prototype.parser })
  .doublele('gamma')
  .doublele('tau')
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' });
MsgEphemerisGloDepA.prototype.fieldSpec = [];
MsgEphemerisGloDepA.prototype.fieldSpec.push(['common', EphemerisCommonContentDepA.prototype.fieldSpec]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['gamma', 'writeDoubleLE', 8]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);

/**
 * SBP class for message MSG_EPHEMERIS_SBAS (0x0084).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContent Values common for all ephemeris types
 * @field pos array Position of the GEO at time toe
 * @field vel array Velocity of the GEO at time toe
 * @field acc array Acceleration of the GEO at time toe
 * @field a_gf0 number (float, 8 bytes) Time offset of the GEO clock w.r.t. SBAS Network Time
 * @field a_gf1 number (float, 8 bytes) Drift of the GEO clock w.r.t. SBAS Network Time
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisSbas = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_SBAS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisSbas.prototype = Object.create(SBP.prototype);
MsgEphemerisSbas.prototype.messageType = "MSG_EPHEMERIS_SBAS";
MsgEphemerisSbas.prototype.msg_type = 0x0084;
MsgEphemerisSbas.prototype.constructor = MsgEphemerisSbas;
MsgEphemerisSbas.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContent.prototype.parser })
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' })
  .doublele('a_gf0')
  .doublele('a_gf1');
MsgEphemerisSbas.prototype.fieldSpec = [];
MsgEphemerisSbas.prototype.fieldSpec.push(['common', EphemerisCommonContent.prototype.fieldSpec]);
MsgEphemerisSbas.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbas.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbas.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbas.prototype.fieldSpec.push(['a_gf0', 'writeDoubleLE', 8]);
MsgEphemerisSbas.prototype.fieldSpec.push(['a_gf1', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_EPHEMERIS_GLO_DEP_B (0x0085).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GLO satellite position, velocity, and clock offset. Please see the
 * GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate information
 * (ephemeris parameters)" for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContent Values common for all ephemeris types
 * @field gamma number (float, 8 bytes) Relative deviation of predicted carrier frequency from nominal
 * @field tau number (float, 8 bytes) Correction to the SV time
 * @field pos array Position of the SV at tb in PZ-90.02 coordinates system
 * @field vel array Velocity vector of the SV at tb in PZ-90.02 coordinates system
 * @field acc array Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGloDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GLO_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGloDepB.prototype = Object.create(SBP.prototype);
MsgEphemerisGloDepB.prototype.messageType = "MSG_EPHEMERIS_GLO_DEP_B";
MsgEphemerisGloDepB.prototype.msg_type = 0x0085;
MsgEphemerisGloDepB.prototype.constructor = MsgEphemerisGloDepB;
MsgEphemerisGloDepB.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContent.prototype.parser })
  .doublele('gamma')
  .doublele('tau')
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' });
MsgEphemerisGloDepB.prototype.fieldSpec = [];
MsgEphemerisGloDepB.prototype.fieldSpec.push(['common', EphemerisCommonContent.prototype.fieldSpec]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['gamma', 'writeDoubleLE', 8]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);

/**
 * SBP class for message MSG_EPHEMERIS_GLO_DEP_C (0x0087).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GLO satellite position, velocity, and clock offset. Please see the
 * GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate information
 * (ephemeris parameters)" for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContent Values common for all ephemeris types
 * @field gamma number (float, 8 bytes) Relative deviation of predicted carrier frequency from nominal
 * @field tau number (float, 8 bytes) Correction to the SV time
 * @field d_tau number (float, 8 bytes) Equipment delay between L1 and L2
 * @field pos array Position of the SV at tb in PZ-90.02 coordinates system
 * @field vel array Velocity vector of the SV at tb in PZ-90.02 coordinates system
 * @field acc array Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
 * @field fcn number (unsigned 8-bit int, 1 byte) Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGloDepC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GLO_DEP_C";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGloDepC.prototype = Object.create(SBP.prototype);
MsgEphemerisGloDepC.prototype.messageType = "MSG_EPHEMERIS_GLO_DEP_C";
MsgEphemerisGloDepC.prototype.msg_type = 0x0087;
MsgEphemerisGloDepC.prototype.constructor = MsgEphemerisGloDepC;
MsgEphemerisGloDepC.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContent.prototype.parser })
  .doublele('gamma')
  .doublele('tau')
  .doublele('d_tau')
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' })
  .uint8('fcn');
MsgEphemerisGloDepC.prototype.fieldSpec = [];
MsgEphemerisGloDepC.prototype.fieldSpec.push(['common', EphemerisCommonContent.prototype.fieldSpec]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['gamma', 'writeDoubleLE', 8]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['d_tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['fcn', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_GLO (0x0088).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GLO satellite position, velocity, and clock offset. Please see the
 * GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate information
 * (ephemeris parameters)" for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContent Values common for all ephemeris types
 * @field gamma number (float, 8 bytes) Relative deviation of predicted carrier frequency from nominal
 * @field tau number (float, 8 bytes) Correction to the SV time
 * @field d_tau number (float, 8 bytes) Equipment delay between L1 and L2
 * @field pos array Position of the SV at tb in PZ-90.02 coordinates system
 * @field vel array Velocity vector of the SV at tb in PZ-90.02 coordinates system
 * @field acc array Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
 * @field fcn number (unsigned 8-bit int, 1 byte) Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
 * @field iod number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGlo = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GLO";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGlo.prototype = Object.create(SBP.prototype);
MsgEphemerisGlo.prototype.messageType = "MSG_EPHEMERIS_GLO";
MsgEphemerisGlo.prototype.msg_type = 0x0088;
MsgEphemerisGlo.prototype.constructor = MsgEphemerisGlo;
MsgEphemerisGlo.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContent.prototype.parser })
  .doublele('gamma')
  .doublele('tau')
  .doublele('d_tau')
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' })
  .uint8('fcn')
  .uint8('iod');
MsgEphemerisGlo.prototype.fieldSpec = [];
MsgEphemerisGlo.prototype.fieldSpec.push(['common', EphemerisCommonContent.prototype.fieldSpec]);
MsgEphemerisGlo.prototype.fieldSpec.push(['gamma', 'writeDoubleLE', 8]);
MsgEphemerisGlo.prototype.fieldSpec.push(['tau', 'writeDoubleLE', 8]);
MsgEphemerisGlo.prototype.fieldSpec.push(['d_tau', 'writeDoubleLE', 8]);
MsgEphemerisGlo.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGlo.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGlo.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGlo.prototype.fieldSpec.push(['fcn', 'writeUInt8', 1]);
MsgEphemerisGlo.prototype.fieldSpec.push(['iod', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_DEP_D (0x0080).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GPS satellite position, velocity, and clock offset. Please see the
 * Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Table 20-III)
 * for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toe_tow number (float, 8 bytes) Time of week
 * @field toe_wn number (unsigned 16-bit int, 2 bytes) Week number
 * @field toc_tow number (float, 8 bytes) Clock reference time of week
 * @field toc_wn number (unsigned 16-bit int, 2 bytes) Clock reference week number
 * @field valid number (unsigned 8-bit int, 1 byte) Is valid?
 * @field healthy number (unsigned 8-bit int, 1 byte) Satellite is healthy?
 * @field sid GnssSignalDep GNSS signal identifier
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 * @field reserved number (unsigned 32-bit int, 4 bytes) Reserved field
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisDepD = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_DEP_D";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisDepD.prototype = Object.create(SBP.prototype);
MsgEphemerisDepD.prototype.messageType = "MSG_EPHEMERIS_DEP_D";
MsgEphemerisDepD.prototype.msg_type = 0x0080;
MsgEphemerisDepD.prototype.constructor = MsgEphemerisDepD;
MsgEphemerisDepD.prototype.parser = new Parser()
  .endianess('little')
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .doublele('toe_tow')
  .uint16('toe_wn')
  .doublele('toc_tow')
  .uint16('toc_wn')
  .uint8('valid')
  .uint8('healthy')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .uint8('iode')
  .uint16('iodc')
  .uint32('reserved');
MsgEphemerisDepD.prototype.fieldSpec = [];
MsgEphemerisDepD.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['toe_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['toe_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepD.prototype.fieldSpec.push(['toc_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['toc_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepD.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgEphemerisDepD.prototype.fieldSpec.push(['healthy', 'writeUInt8', 1]);
MsgEphemerisDepD.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgEphemerisDepD.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);
MsgEphemerisDepD.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);
MsgEphemerisDepD.prototype.fieldSpec.push(['reserved', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toe_tow number (float, 8 bytes) Time of week
 * @field toe_wn number (unsigned 16-bit int, 2 bytes) Week number
 * @field toc_tow number (float, 8 bytes) Clock reference time of week
 * @field toc_wn number (unsigned 16-bit int, 2 bytes) Clock reference week number
 * @field valid number (unsigned 8-bit int, 1 byte) Is valid?
 * @field healthy number (unsigned 8-bit int, 1 byte) Satellite is healthy?
 * @field prn number (unsigned 8-bit int, 1 byte) PRN being tracked
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisDepA.prototype = Object.create(SBP.prototype);
MsgEphemerisDepA.prototype.messageType = "MSG_EPHEMERIS_DEP_A";
MsgEphemerisDepA.prototype.msg_type = 0x001A;
MsgEphemerisDepA.prototype.constructor = MsgEphemerisDepA;
MsgEphemerisDepA.prototype.parser = new Parser()
  .endianess('little')
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .doublele('toe_tow')
  .uint16('toe_wn')
  .doublele('toc_tow')
  .uint16('toc_wn')
  .uint8('valid')
  .uint8('healthy')
  .uint8('prn');
MsgEphemerisDepA.prototype.fieldSpec = [];
MsgEphemerisDepA.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['toe_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['toe_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepA.prototype.fieldSpec.push(['toc_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['toc_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepA.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgEphemerisDepA.prototype.fieldSpec.push(['healthy', 'writeUInt8', 1]);
MsgEphemerisDepA.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toe_tow number (float, 8 bytes) Time of week
 * @field toe_wn number (unsigned 16-bit int, 2 bytes) Week number
 * @field toc_tow number (float, 8 bytes) Clock reference time of week
 * @field toc_wn number (unsigned 16-bit int, 2 bytes) Clock reference week number
 * @field valid number (unsigned 8-bit int, 1 byte) Is valid?
 * @field healthy number (unsigned 8-bit int, 1 byte) Satellite is healthy?
 * @field prn number (unsigned 8-bit int, 1 byte) PRN being tracked
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisDepB.prototype = Object.create(SBP.prototype);
MsgEphemerisDepB.prototype.messageType = "MSG_EPHEMERIS_DEP_B";
MsgEphemerisDepB.prototype.msg_type = 0x0046;
MsgEphemerisDepB.prototype.constructor = MsgEphemerisDepB;
MsgEphemerisDepB.prototype.parser = new Parser()
  .endianess('little')
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .doublele('toe_tow')
  .uint16('toe_wn')
  .doublele('toc_tow')
  .uint16('toc_wn')
  .uint8('valid')
  .uint8('healthy')
  .uint8('prn')
  .uint8('iode');
MsgEphemerisDepB.prototype.fieldSpec = [];
MsgEphemerisDepB.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['toe_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['toe_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepB.prototype.fieldSpec.push(['toc_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['toc_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepB.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgEphemerisDepB.prototype.fieldSpec.push(['healthy', 'writeUInt8', 1]);
MsgEphemerisDepB.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);
MsgEphemerisDepB.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_DEP_C (0x0047).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GPS satellite position, velocity, and clock offset. Please see the
 * Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Table 20-III)
 * for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toe_tow number (float, 8 bytes) Time of week
 * @field toe_wn number (unsigned 16-bit int, 2 bytes) Week number
 * @field toc_tow number (float, 8 bytes) Clock reference time of week
 * @field toc_wn number (unsigned 16-bit int, 2 bytes) Clock reference week number
 * @field valid number (unsigned 8-bit int, 1 byte) Is valid?
 * @field healthy number (unsigned 8-bit int, 1 byte) Satellite is healthy?
 * @field sid GnssSignalDep GNSS signal identifier
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 * @field reserved number (unsigned 32-bit int, 4 bytes) Reserved field
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisDepC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_DEP_C";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisDepC.prototype = Object.create(SBP.prototype);
MsgEphemerisDepC.prototype.messageType = "MSG_EPHEMERIS_DEP_C";
MsgEphemerisDepC.prototype.msg_type = 0x0047;
MsgEphemerisDepC.prototype.constructor = MsgEphemerisDepC;
MsgEphemerisDepC.prototype.parser = new Parser()
  .endianess('little')
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .doublele('toe_tow')
  .uint16('toe_wn')
  .doublele('toc_tow')
  .uint16('toc_wn')
  .uint8('valid')
  .uint8('healthy')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .uint8('iode')
  .uint16('iodc')
  .uint32('reserved');
MsgEphemerisDepC.prototype.fieldSpec = [];
MsgEphemerisDepC.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['toe_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['toe_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepC.prototype.fieldSpec.push(['toc_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['toc_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepC.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgEphemerisDepC.prototype.fieldSpec.push(['healthy', 'writeUInt8', 1]);
MsgEphemerisDepC.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgEphemerisDepC.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);
MsgEphemerisDepC.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);
MsgEphemerisDepC.prototype.fieldSpec.push(['reserved', 'writeUInt32LE', 4]);

/**
 * SBP class for message fragment ObservationHeaderDep
 *
 * Header of a GPS observation message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t GPSTimeDep GPS time of this observation
 * @field n_obs number (unsigned 8-bit int, 1 byte) Total number of observations. First nibble is the size of the sequence (n),
 *   second nibble is the zero-indexed counter (ith packet of n)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var ObservationHeaderDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "ObservationHeaderDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
ObservationHeaderDep.prototype = Object.create(SBP.prototype);
ObservationHeaderDep.prototype.messageType = "ObservationHeaderDep";
ObservationHeaderDep.prototype.constructor = ObservationHeaderDep;
ObservationHeaderDep.prototype.parser = new Parser()
  .endianess('little')
  .nest('t', { type: GPSTimeDep.prototype.parser })
  .uint8('n_obs');
ObservationHeaderDep.prototype.fieldSpec = [];
ObservationHeaderDep.prototype.fieldSpec.push(['t', GPSTimeDep.prototype.fieldSpec]);
ObservationHeaderDep.prototype.fieldSpec.push(['n_obs', 'writeUInt8', 1]);

/**
 * SBP class for message fragment CarrierPhaseDepA
 *
 * Carrier phase measurement in cycles represented as a 40-bit fixed point number
 * with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of fractional cycles.
 * This has the opposite sign convention than a typical GPS receiver and the phase
 * has the opposite sign as the pseudorange.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field i number (signed 32-bit int, 4 bytes) Carrier phase whole cycles
 * @field f number (unsigned 8-bit int, 1 byte) Carrier phase fractional part
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var CarrierPhaseDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "CarrierPhaseDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
CarrierPhaseDepA.prototype = Object.create(SBP.prototype);
CarrierPhaseDepA.prototype.messageType = "CarrierPhaseDepA";
CarrierPhaseDepA.prototype.constructor = CarrierPhaseDepA;
CarrierPhaseDepA.prototype.parser = new Parser()
  .endianess('little')
  .int32('i')
  .uint8('f');
CarrierPhaseDepA.prototype.fieldSpec = [];
CarrierPhaseDepA.prototype.fieldSpec.push(['i', 'writeInt32LE', 4]);
CarrierPhaseDepA.prototype.fieldSpec.push(['f', 'writeUInt8', 1]);

/**
 * SBP class for message fragment PackedObsContentDepA
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation
 * @field L CarrierPhaseDepA Carrier phase observation with opposite sign from typical convention
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock indicator. This value changes whenever a satellite signal has lost and
 *   regained lock, indicating that the carrier phase ambiguity may have changed.
 * @field prn number (unsigned 8-bit int, 1 byte) PRN-1 identifier of the satellite signal
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PackedObsContentDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PackedObsContentDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PackedObsContentDepA.prototype = Object.create(SBP.prototype);
PackedObsContentDepA.prototype.messageType = "PackedObsContentDepA";
PackedObsContentDepA.prototype.constructor = PackedObsContentDepA;
PackedObsContentDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('P')
  .nest('L', { type: CarrierPhaseDepA.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .uint8('prn');
PackedObsContentDepA.prototype.fieldSpec = [];
PackedObsContentDepA.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
PackedObsContentDepA.prototype.fieldSpec.push(['L', CarrierPhaseDepA.prototype.fieldSpec]);
PackedObsContentDepA.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
PackedObsContentDepA.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
PackedObsContentDepA.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);

/**
 * SBP class for message fragment PackedObsContentDepB
 *
 * Pseudorange and carrier phase observation for a satellite being tracked.
 * Pseudoranges are referenced to a nominal pseudorange.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation
 * @field L CarrierPhaseDepA Carrier phase observation with opposite sign from typical convention.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock indicator. This value changes whenever a satellite signal has lost and
 *   regained lock, indicating that the carrier phase ambiguity may have changed.
 * @field sid GnssSignalDep GNSS signal identifier
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PackedObsContentDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PackedObsContentDepB";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PackedObsContentDepB.prototype = Object.create(SBP.prototype);
PackedObsContentDepB.prototype.messageType = "PackedObsContentDepB";
PackedObsContentDepB.prototype.constructor = PackedObsContentDepB;
PackedObsContentDepB.prototype.parser = new Parser()
  .endianess('little')
  .uint32('P')
  .nest('L', { type: CarrierPhaseDepA.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .nest('sid', { type: GnssSignalDep.prototype.parser });
PackedObsContentDepB.prototype.fieldSpec = [];
PackedObsContentDepB.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
PackedObsContentDepB.prototype.fieldSpec.push(['L', CarrierPhaseDepA.prototype.fieldSpec]);
PackedObsContentDepB.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
PackedObsContentDepB.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
PackedObsContentDepB.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);

/**
 * SBP class for message fragment PackedObsContentDepC
 *
 * Pseudorange and carrier phase observation for a satellite being tracked. The
 * observations are be interoperable with 3rd party receivers and conform with
 * typical RTCMv3 GNSS observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation
 * @field L CarrierPhase Carrier phase observation with typical sign convention.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock indicator. This value changes whenever a satellite signal has lost and
 *   regained lock, indicating that the carrier phase ambiguity may have changed.
 * @field sid GnssSignalDep GNSS signal identifier
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PackedObsContentDepC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PackedObsContentDepC";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PackedObsContentDepC.prototype = Object.create(SBP.prototype);
PackedObsContentDepC.prototype.messageType = "PackedObsContentDepC";
PackedObsContentDepC.prototype.constructor = PackedObsContentDepC;
PackedObsContentDepC.prototype.parser = new Parser()
  .endianess('little')
  .uint32('P')
  .nest('L', { type: CarrierPhase.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .nest('sid', { type: GnssSignalDep.prototype.parser });
PackedObsContentDepC.prototype.fieldSpec = [];
PackedObsContentDepC.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
PackedObsContentDepC.prototype.fieldSpec.push(['L', CarrierPhase.prototype.fieldSpec]);
PackedObsContentDepC.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
PackedObsContentDepC.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
PackedObsContentDepC.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);

/**
 * SBP class for message MSG_OBS_DEP_A (0x0045).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header ObservationHeaderDep Header of a GPS observation message
 * @field obs array Pseudorange and carrier phase observation for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgObsDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_OBS_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgObsDepA.prototype = Object.create(SBP.prototype);
MsgObsDepA.prototype.messageType = "MSG_OBS_DEP_A";
MsgObsDepA.prototype.msg_type = 0x0045;
MsgObsDepA.prototype.constructor = MsgObsDepA;
MsgObsDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: ObservationHeaderDep.prototype.parser })
  .array('obs', { type: PackedObsContentDepA.prototype.parser, readUntil: 'eof' });
MsgObsDepA.prototype.fieldSpec = [];
MsgObsDepA.prototype.fieldSpec.push(['header', ObservationHeaderDep.prototype.fieldSpec]);
MsgObsDepA.prototype.fieldSpec.push(['obs', 'array', PackedObsContentDepA.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_OBS_DEP_B (0x0043).
 *
 * This observation message has been deprecated in favor of observations that are
 * more interoperable. This message should be used for observations referenced to a
 * nominal pseudorange which are not interoperable with most 3rd party GNSS
 * receievers or typical RTCMv3 observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header ObservationHeaderDep Header of a GPS observation message
 * @field obs array Pseudorange and carrier phase observation for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgObsDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_OBS_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgObsDepB.prototype = Object.create(SBP.prototype);
MsgObsDepB.prototype.messageType = "MSG_OBS_DEP_B";
MsgObsDepB.prototype.msg_type = 0x0043;
MsgObsDepB.prototype.constructor = MsgObsDepB;
MsgObsDepB.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: ObservationHeaderDep.prototype.parser })
  .array('obs', { type: PackedObsContentDepB.prototype.parser, readUntil: 'eof' });
MsgObsDepB.prototype.fieldSpec = [];
MsgObsDepB.prototype.fieldSpec.push(['header', ObservationHeaderDep.prototype.fieldSpec]);
MsgObsDepB.prototype.fieldSpec.push(['obs', 'array', PackedObsContentDepB.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_OBS_DEP_C (0x0049).
 *
 * The GPS observations message reports all the raw pseudorange and carrier phase
 * observations for the satellites being tracked by the device. Carrier phase
 * observation here is represented as a 40-bit fixed point number with Q32.8 layout
 * (i.e. 32-bits of whole cycles and 8-bits of fractional cycles). The observations
 * are interoperable with 3rd party receivers and conform with typical RTCMv3 GNSS
 * observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header ObservationHeaderDep Header of a GPS observation message
 * @field obs array Pseudorange and carrier phase observation for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgObsDepC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_OBS_DEP_C";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgObsDepC.prototype = Object.create(SBP.prototype);
MsgObsDepC.prototype.messageType = "MSG_OBS_DEP_C";
MsgObsDepC.prototype.msg_type = 0x0049;
MsgObsDepC.prototype.constructor = MsgObsDepC;
MsgObsDepC.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: ObservationHeaderDep.prototype.parser })
  .array('obs', { type: PackedObsContentDepC.prototype.parser, readUntil: 'eof' });
MsgObsDepC.prototype.fieldSpec = [];
MsgObsDepC.prototype.fieldSpec.push(['header', ObservationHeaderDep.prototype.fieldSpec]);
MsgObsDepC.prototype.fieldSpec.push(['obs', 'array', PackedObsContentDepC.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_IONO (0x0090).
 *
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user to
 * utilize the ionospheric model for computation of the ionospheric delay. Please
 * see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_nmct GPSTimeSec Navigation Message Correction Table Valitidy Time
 * @field a0 number (float, 8 bytes)
 * @field a1 number (float, 8 bytes)
 * @field a2 number (float, 8 bytes)
 * @field a3 number (float, 8 bytes)
 * @field b0 number (float, 8 bytes)
 * @field b1 number (float, 8 bytes)
 * @field b2 number (float, 8 bytes)
 * @field b3 number (float, 8 bytes)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgIono = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_IONO";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgIono.prototype = Object.create(SBP.prototype);
MsgIono.prototype.messageType = "MSG_IONO";
MsgIono.prototype.msg_type = 0x0090;
MsgIono.prototype.constructor = MsgIono;
MsgIono.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_nmct', { type: GPSTimeSec.prototype.parser })
  .doublele('a0')
  .doublele('a1')
  .doublele('a2')
  .doublele('a3')
  .doublele('b0')
  .doublele('b1')
  .doublele('b2')
  .doublele('b3');
MsgIono.prototype.fieldSpec = [];
MsgIono.prototype.fieldSpec.push(['t_nmct', GPSTimeSec.prototype.fieldSpec]);
MsgIono.prototype.fieldSpec.push(['a0', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['a1', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['a2', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['a3', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['b0', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['b1', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['b2', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['b3', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_SV_CONFIGURATION_GPS (0x0091).
 *
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_nmct GPSTimeSec Navigation Message Correction Table Valitidy Time
 * @field l2c_mask number (unsigned 32-bit int, 4 bytes) L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSvConfigurationGps = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SV_CONFIGURATION_GPS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSvConfigurationGps.prototype = Object.create(SBP.prototype);
MsgSvConfigurationGps.prototype.messageType = "MSG_SV_CONFIGURATION_GPS";
MsgSvConfigurationGps.prototype.msg_type = 0x0091;
MsgSvConfigurationGps.prototype.constructor = MsgSvConfigurationGps;
MsgSvConfigurationGps.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_nmct', { type: GPSTimeSec.prototype.parser })
  .uint32('l2c_mask');
MsgSvConfigurationGps.prototype.fieldSpec = [];
MsgSvConfigurationGps.prototype.fieldSpec.push(['t_nmct', GPSTimeSec.prototype.fieldSpec]);
MsgSvConfigurationGps.prototype.fieldSpec.push(['l2c_mask', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_GROUP_DELAY_DEP_A (0x0092).
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_op GPSTimeDep Data Predict Time of Week
 * @field prn number (unsigned 8-bit int, 1 byte) Satellite number
 * @field valid number (unsigned 8-bit int, 1 byte) bit-field indicating validity of the values, LSB indicating tgd validity etc. 1
 *   = value is valid, 0 = value is not valid.
 * @field tgd number (signed 16-bit int, 2 bytes)
 * @field isc_l1ca number (signed 16-bit int, 2 bytes)
 * @field isc_l2c number (signed 16-bit int, 2 bytes)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGroupDelayDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GROUP_DELAY_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGroupDelayDepA.prototype = Object.create(SBP.prototype);
MsgGroupDelayDepA.prototype.messageType = "MSG_GROUP_DELAY_DEP_A";
MsgGroupDelayDepA.prototype.msg_type = 0x0092;
MsgGroupDelayDepA.prototype.constructor = MsgGroupDelayDepA;
MsgGroupDelayDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_op', { type: GPSTimeDep.prototype.parser })
  .uint8('prn')
  .uint8('valid')
  .int16('tgd')
  .int16('isc_l1ca')
  .int16('isc_l2c');
MsgGroupDelayDepA.prototype.fieldSpec = [];
MsgGroupDelayDepA.prototype.fieldSpec.push(['t_op', GPSTimeDep.prototype.fieldSpec]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['tgd', 'writeInt16LE', 2]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['isc_l1ca', 'writeInt16LE', 2]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['isc_l2c', 'writeInt16LE', 2]);

/**
 * SBP class for message MSG_GROUP_DELAY_DEP_B (0x0093).
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_op GPSTimeSec Data Predict Time of Week
 * @field sid GnssSignalDep GNSS signal identifier
 * @field valid number (unsigned 8-bit int, 1 byte) bit-field indicating validity of the values, LSB indicating tgd validity etc. 1
 *   = value is valid, 0 = value is not valid.
 * @field tgd number (signed 16-bit int, 2 bytes)
 * @field isc_l1ca number (signed 16-bit int, 2 bytes)
 * @field isc_l2c number (signed 16-bit int, 2 bytes)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGroupDelayDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GROUP_DELAY_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGroupDelayDepB.prototype = Object.create(SBP.prototype);
MsgGroupDelayDepB.prototype.messageType = "MSG_GROUP_DELAY_DEP_B";
MsgGroupDelayDepB.prototype.msg_type = 0x0093;
MsgGroupDelayDepB.prototype.constructor = MsgGroupDelayDepB;
MsgGroupDelayDepB.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_op', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .uint8('valid')
  .int16('tgd')
  .int16('isc_l1ca')
  .int16('isc_l2c');
MsgGroupDelayDepB.prototype.fieldSpec = [];
MsgGroupDelayDepB.prototype.fieldSpec.push(['t_op', GPSTimeSec.prototype.fieldSpec]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['tgd', 'writeInt16LE', 2]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['isc_l1ca', 'writeInt16LE', 2]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['isc_l2c', 'writeInt16LE', 2]);

/**
 * SBP class for message MSG_GROUP_DELAY (0x0094).
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_op GPSTimeSec Data Predict Time of Week
 * @field sid GnssSignal GNSS signal identifier
 * @field valid number (unsigned 8-bit int, 1 byte) bit-field indicating validity of the values, LSB indicating tgd validity etc. 1
 *   = value is valid, 0 = value is not valid.
 * @field tgd number (signed 16-bit int, 2 bytes)
 * @field isc_l1ca number (signed 16-bit int, 2 bytes)
 * @field isc_l2c number (signed 16-bit int, 2 bytes)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGroupDelay = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GROUP_DELAY";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGroupDelay.prototype = Object.create(SBP.prototype);
MsgGroupDelay.prototype.messageType = "MSG_GROUP_DELAY";
MsgGroupDelay.prototype.msg_type = 0x0094;
MsgGroupDelay.prototype.constructor = MsgGroupDelay;
MsgGroupDelay.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_op', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('valid')
  .int16('tgd')
  .int16('isc_l1ca')
  .int16('isc_l2c');
MsgGroupDelay.prototype.fieldSpec = [];
MsgGroupDelay.prototype.fieldSpec.push(['t_op', GPSTimeSec.prototype.fieldSpec]);
MsgGroupDelay.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgGroupDelay.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgGroupDelay.prototype.fieldSpec.push(['tgd', 'writeInt16LE', 2]);
MsgGroupDelay.prototype.fieldSpec.push(['isc_l1ca', 'writeInt16LE', 2]);
MsgGroupDelay.prototype.fieldSpec.push(['isc_l2c', 'writeInt16LE', 2]);

/**
 * SBP class for message fragment AlmanacCommonContent
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal identifier
 * @field toa GPSTimeSec Reference time of almanac
 * @field ura number (float, 8 bytes) User Range Accuracy
 * @field fit_interval number (unsigned 32-bit int, 4 bytes) Curve fit interval
 * @field valid number (unsigned 8-bit int, 1 byte) Status of almanac, 1 = valid, 0 = invalid
 * @field health_bits number (unsigned 8-bit int, 1 byte) Satellite health status for GPS:   - bits 5-7: NAV data health status. See IS-
 *   GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits 0-4: Signal
 *   health status. See IS-GPS-200H     Table 20-VIII. Codes for Health of SV Signal
 *   Components. Satellite health status for GLO:   See GLO ICD 5.1 table 5.1 for
 *   details   - bit 0: C(n), "unhealthy" flag that is transmitted within     non-
 *   immediate data and indicates overall constellation status     at the moment of
 *   almanac uploading.     '0' indicates malfunction of n-satellite.     '1'
 *   indicates that n-satellite is operational.   - bit 1: Bn(ln), '0' indicates the
 *   satellite is operational     and suitable for navigation.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var AlmanacCommonContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "AlmanacCommonContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
AlmanacCommonContent.prototype = Object.create(SBP.prototype);
AlmanacCommonContent.prototype.messageType = "AlmanacCommonContent";
AlmanacCommonContent.prototype.constructor = AlmanacCommonContent;
AlmanacCommonContent.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .nest('toa', { type: GPSTimeSec.prototype.parser })
  .doublele('ura')
  .uint32('fit_interval')
  .uint8('valid')
  .uint8('health_bits');
AlmanacCommonContent.prototype.fieldSpec = [];
AlmanacCommonContent.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
AlmanacCommonContent.prototype.fieldSpec.push(['toa', GPSTimeSec.prototype.fieldSpec]);
AlmanacCommonContent.prototype.fieldSpec.push(['ura', 'writeDoubleLE', 8]);
AlmanacCommonContent.prototype.fieldSpec.push(['fit_interval', 'writeUInt32LE', 4]);
AlmanacCommonContent.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
AlmanacCommonContent.prototype.fieldSpec.push(['health_bits', 'writeUInt8', 1]);

/**
 * SBP class for message fragment AlmanacCommonContentDep
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignalDep GNSS signal identifier
 * @field toa GPSTimeSec Reference time of almanac
 * @field ura number (float, 8 bytes) User Range Accuracy
 * @field fit_interval number (unsigned 32-bit int, 4 bytes) Curve fit interval
 * @field valid number (unsigned 8-bit int, 1 byte) Status of almanac, 1 = valid, 0 = invalid
 * @field health_bits number (unsigned 8-bit int, 1 byte) Satellite health status for GPS:   - bits 5-7: NAV data health status. See IS-
 *   GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits 0-4: Signal
 *   health status. See IS-GPS-200H     Table 20-VIII. Codes for Health of SV Signal
 *   Components. Satellite health status for GLO:   See GLO ICD 5.1 table 5.1 for
 *   details   - bit 0: C(n), "unhealthy" flag that is transmitted within     non-
 *   immediate data and indicates overall constellation status     at the moment of
 *   almanac uploading.     '0' indicates malfunction of n-satellite.     '1'
 *   indicates that n-satellite is operational.   - bit 1: Bn(ln), '0' indicates the
 *   satellite is operational     and suitable for navigation.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var AlmanacCommonContentDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "AlmanacCommonContentDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
AlmanacCommonContentDep.prototype = Object.create(SBP.prototype);
AlmanacCommonContentDep.prototype.messageType = "AlmanacCommonContentDep";
AlmanacCommonContentDep.prototype.constructor = AlmanacCommonContentDep;
AlmanacCommonContentDep.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .nest('toa', { type: GPSTimeSec.prototype.parser })
  .doublele('ura')
  .uint32('fit_interval')
  .uint8('valid')
  .uint8('health_bits');
AlmanacCommonContentDep.prototype.fieldSpec = [];
AlmanacCommonContentDep.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['toa', GPSTimeSec.prototype.fieldSpec]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['ura', 'writeDoubleLE', 8]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['fit_interval', 'writeUInt32LE', 4]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['health_bits', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_ALMANAC_GPS_DEP (0x0070).
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data is
 * not very precise and is considered valid for up to several months. Please see
 * the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Chapter
 * 20.3.3.5.1.2 Almanac Data) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common AlmanacCommonContentDep Values common for all almanac types
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanacGpsDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC_GPS_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanacGpsDep.prototype = Object.create(SBP.prototype);
MsgAlmanacGpsDep.prototype.messageType = "MSG_ALMANAC_GPS_DEP";
MsgAlmanacGpsDep.prototype.msg_type = 0x0070;
MsgAlmanacGpsDep.prototype.constructor = MsgAlmanacGpsDep;
MsgAlmanacGpsDep.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: AlmanacCommonContentDep.prototype.parser })
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('af0')
  .doublele('af1');
MsgAlmanacGpsDep.prototype.fieldSpec = [];
MsgAlmanacGpsDep.prototype.fieldSpec.push(['common', AlmanacCommonContentDep.prototype.fieldSpec]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_ALMANAC_GPS (0x0072).
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data is
 * not very precise and is considered valid for up to several months. Please see
 * the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Chapter
 * 20.3.3.5.1.2 Almanac Data) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common AlmanacCommonContent Values common for all almanac types
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanacGps = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC_GPS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanacGps.prototype = Object.create(SBP.prototype);
MsgAlmanacGps.prototype.messageType = "MSG_ALMANAC_GPS";
MsgAlmanacGps.prototype.msg_type = 0x0072;
MsgAlmanacGps.prototype.constructor = MsgAlmanacGps;
MsgAlmanacGps.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: AlmanacCommonContent.prototype.parser })
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('af0')
  .doublele('af1');
MsgAlmanacGps.prototype.fieldSpec = [];
MsgAlmanacGps.prototype.fieldSpec.push(['common', AlmanacCommonContent.prototype.fieldSpec]);
MsgAlmanacGps.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_ALMANAC_GLO_DEP (0x0071).
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data is
 * not very precise and is considered valid for up to several months. Please see
 * the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and almanac" for details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common AlmanacCommonContentDep Values common for all almanac types
 * @field lambda_na number (float, 8 bytes) Longitude of the first ascending node of the orbit in PZ-90.02 coordinate system
 * @field t_lambda_na number (float, 8 bytes) Time of the first ascending node passage
 * @field i number (float, 8 bytes) Value of inclination at instant of t_lambda
 * @field t number (float, 8 bytes) Value of Draconian period at instant of t_lambda
 * @field t_dot number (float, 8 bytes) Rate of change of the Draconian period
 * @field epsilon number (float, 8 bytes) Eccentricity at instant of t_lambda
 * @field omega number (float, 8 bytes) Argument of perigee at instant of t_lambda
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanacGloDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC_GLO_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanacGloDep.prototype = Object.create(SBP.prototype);
MsgAlmanacGloDep.prototype.messageType = "MSG_ALMANAC_GLO_DEP";
MsgAlmanacGloDep.prototype.msg_type = 0x0071;
MsgAlmanacGloDep.prototype.constructor = MsgAlmanacGloDep;
MsgAlmanacGloDep.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: AlmanacCommonContentDep.prototype.parser })
  .doublele('lambda_na')
  .doublele('t_lambda_na')
  .doublele('i')
  .doublele('t')
  .doublele('t_dot')
  .doublele('epsilon')
  .doublele('omega');
MsgAlmanacGloDep.prototype.fieldSpec = [];
MsgAlmanacGloDep.prototype.fieldSpec.push(['common', AlmanacCommonContentDep.prototype.fieldSpec]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['lambda_na', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['t_lambda_na', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['i', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['t', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['t_dot', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['epsilon', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['omega', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_ALMANAC_GLO (0x0073).
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data is
 * not very precise and is considered valid for up to several months. Please see
 * the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and almanac" for details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common AlmanacCommonContent Values common for all almanac types
 * @field lambda_na number (float, 8 bytes) Longitude of the first ascending node of the orbit in PZ-90.02 coordinate system
 * @field t_lambda_na number (float, 8 bytes) Time of the first ascending node passage
 * @field i number (float, 8 bytes) Value of inclination at instant of t_lambda
 * @field t number (float, 8 bytes) Value of Draconian period at instant of t_lambda
 * @field t_dot number (float, 8 bytes) Rate of change of the Draconian period
 * @field epsilon number (float, 8 bytes) Eccentricity at instant of t_lambda
 * @field omega number (float, 8 bytes) Argument of perigee at instant of t_lambda
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanacGlo = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC_GLO";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanacGlo.prototype = Object.create(SBP.prototype);
MsgAlmanacGlo.prototype.messageType = "MSG_ALMANAC_GLO";
MsgAlmanacGlo.prototype.msg_type = 0x0073;
MsgAlmanacGlo.prototype.constructor = MsgAlmanacGlo;
MsgAlmanacGlo.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: AlmanacCommonContent.prototype.parser })
  .doublele('lambda_na')
  .doublele('t_lambda_na')
  .doublele('i')
  .doublele('t')
  .doublele('t_dot')
  .doublele('epsilon')
  .doublele('omega');
MsgAlmanacGlo.prototype.fieldSpec = [];
MsgAlmanacGlo.prototype.fieldSpec.push(['common', AlmanacCommonContent.prototype.fieldSpec]);
MsgAlmanacGlo.prototype.fieldSpec.push(['lambda_na', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['t_lambda_na', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['i', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['t', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['t_dot', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['epsilon', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['omega', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_GLO_BIASES (0x0075).
 *
 * The GLONASS L1/L2 Code-Phase biases allows to perform  GPS+GLONASS integer
 * ambiguity resolution for baselines with mixed receiver types (e.g. receiver of
 * different manufacturers)
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field mask number (unsigned 8-bit int, 1 byte) GLONASS FDMA signals mask
 * @field l1ca_bias number (signed 16-bit int, 2 bytes) GLONASS L1 C/A Code-Phase Bias
 * @field l1p_bias number (signed 16-bit int, 2 bytes) GLONASS L1 P Code-Phase Bias
 * @field l2ca_bias number (signed 16-bit int, 2 bytes) GLONASS L2 C/A Code-Phase Bias
 * @field l2p_bias number (signed 16-bit int, 2 bytes) GLONASS L2 P Code-Phase Bias
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGloBiases = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GLO_BIASES";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGloBiases.prototype = Object.create(SBP.prototype);
MsgGloBiases.prototype.messageType = "MSG_GLO_BIASES";
MsgGloBiases.prototype.msg_type = 0x0075;
MsgGloBiases.prototype.constructor = MsgGloBiases;
MsgGloBiases.prototype.parser = new Parser()
  .endianess('little')
  .uint8('mask')
  .int16('l1ca_bias')
  .int16('l1p_bias')
  .int16('l2ca_bias')
  .int16('l2p_bias');
MsgGloBiases.prototype.fieldSpec = [];
MsgGloBiases.prototype.fieldSpec.push(['mask', 'writeUInt8', 1]);
MsgGloBiases.prototype.fieldSpec.push(['l1ca_bias', 'writeInt16LE', 2]);
MsgGloBiases.prototype.fieldSpec.push(['l1p_bias', 'writeInt16LE', 2]);
MsgGloBiases.prototype.fieldSpec.push(['l2ca_bias', 'writeInt16LE', 2]);
MsgGloBiases.prototype.fieldSpec.push(['l2p_bias', 'writeInt16LE', 2]);

module.exports = {
  ObservationHeader: ObservationHeader,
  Doppler: Doppler,
  PackedObsContent: PackedObsContent,
  0x004A: MsgObs,
  MsgObs: MsgObs,
  0x0044: MsgBasePosLlh,
  MsgBasePosLlh: MsgBasePosLlh,
  0x0048: MsgBasePosEcef,
  MsgBasePosEcef: MsgBasePosEcef,
  EphemerisCommonContent: EphemerisCommonContent,
  EphemerisCommonContentDepA: EphemerisCommonContentDepA,
  0x0081: MsgEphemerisGpsDepE,
  MsgEphemerisGpsDepE: MsgEphemerisGpsDepE,
  0x0086: MsgEphemerisGps,
  MsgEphemerisGps: MsgEphemerisGps,
  0x0095: MsgEphemerisGal,
  MsgEphemerisGal: MsgEphemerisGal,
  0x0082: MsgEphemerisSbasDepA,
  MsgEphemerisSbasDepA: MsgEphemerisSbasDepA,
  0x0083: MsgEphemerisGloDepA,
  MsgEphemerisGloDepA: MsgEphemerisGloDepA,
  0x0084: MsgEphemerisSbas,
  MsgEphemerisSbas: MsgEphemerisSbas,
  0x0085: MsgEphemerisGloDepB,
  MsgEphemerisGloDepB: MsgEphemerisGloDepB,
  0x0087: MsgEphemerisGloDepC,
  MsgEphemerisGloDepC: MsgEphemerisGloDepC,
  0x0088: MsgEphemerisGlo,
  MsgEphemerisGlo: MsgEphemerisGlo,
  0x0080: MsgEphemerisDepD,
  MsgEphemerisDepD: MsgEphemerisDepD,
  0x001A: MsgEphemerisDepA,
  MsgEphemerisDepA: MsgEphemerisDepA,
  0x0046: MsgEphemerisDepB,
  MsgEphemerisDepB: MsgEphemerisDepB,
  0x0047: MsgEphemerisDepC,
  MsgEphemerisDepC: MsgEphemerisDepC,
  ObservationHeaderDep: ObservationHeaderDep,
  CarrierPhaseDepA: CarrierPhaseDepA,
  PackedObsContentDepA: PackedObsContentDepA,
  PackedObsContentDepB: PackedObsContentDepB,
  PackedObsContentDepC: PackedObsContentDepC,
  0x0045: MsgObsDepA,
  MsgObsDepA: MsgObsDepA,
  0x0043: MsgObsDepB,
  MsgObsDepB: MsgObsDepB,
  0x0049: MsgObsDepC,
  MsgObsDepC: MsgObsDepC,
  0x0090: MsgIono,
  MsgIono: MsgIono,
  0x0091: MsgSvConfigurationGps,
  MsgSvConfigurationGps: MsgSvConfigurationGps,
  0x0092: MsgGroupDelayDepA,
  MsgGroupDelayDepA: MsgGroupDelayDepA,
  0x0093: MsgGroupDelayDepB,
  MsgGroupDelayDepB: MsgGroupDelayDepB,
  0x0094: MsgGroupDelay,
  MsgGroupDelay: MsgGroupDelay,
  AlmanacCommonContent: AlmanacCommonContent,
  AlmanacCommonContentDep: AlmanacCommonContentDep,
  0x0070: MsgAlmanacGpsDep,
  MsgAlmanacGpsDep: MsgAlmanacGpsDep,
  0x0072: MsgAlmanacGps,
  MsgAlmanacGps: MsgAlmanacGps,
  0x0071: MsgAlmanacGloDep,
  MsgAlmanacGloDep: MsgAlmanacGloDep,
  0x0073: MsgAlmanacGlo,
  MsgAlmanacGlo: MsgAlmanacGlo,
  0x0075: MsgGloBiases,
  MsgGloBiases: MsgGloBiases,
}