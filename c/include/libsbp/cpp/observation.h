/*
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_OBSERVATION_MESSAGES_H
#define LIBSBP_CPP_OBSERVATION_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>
#include <libsbp/cpp/gnss.h>

namespace sbp {
  
  /**
   * Header for observation message.
   *
   * Header of a GNSS observation message.
   */

  
  struct SBP_ATTR_PACKED ObservationHeader {
    GPSTime t /** GNSS time of this observation */
    u8 n_obs /** Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)
 */
  };

  
  /**
   * GNSS doppler measurement.
   *
   * Doppler measurement in Hz represented as a 24-bit
   * fixed point number with Q16.8 layout, i.e. 16-bits of whole
   * doppler and 8-bits of fractional doppler. This doppler is defined
   * as positive for approaching satellites.
   */

  
  struct SBP_ATTR_PACKED Doppler {
    s16 i /** Doppler whole Hz [Hz] */
    u8 f /** Doppler fractional part [Hz / 256] */
  };

  
  /**
   * GNSS observations for a particular satellite signal.
   *
   * Pseudorange and carrier phase observation for a satellite being tracked.
   * The observations are interoperable with 3rd party receivers and conform with
   * typical RTCM 3.1 message GPS/GLO observations.
   * 
   * Carrier phase observations are not guaranteed to be aligned to the RINEX 3
   * or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are currently
   * peformed.
   */

  
  struct SBP_ATTR_PACKED PackedObsContent {
    u32 P /** Pseudorange observation [2 cm] */
    CarrierPhase L /** Carrier phase observation with typical sign convention. [cycles] */
    Doppler D /** Doppler observation with typical sign convention. [Hz] */
    u8 cn0 /** Carrier-to-Noise density.  Zero implies invalid cn0. [dB Hz / 4] */
    u8 lock /** Lock timer. This value gives an indication of the time
for which a signal has maintained continuous phase lock.
Whenever a signal has lost and regained lock, this
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Valid values range
from 0 to 15 and the most significant nibble is reserved for future use.
 */
    u8 flags /** Measurement status flags. A bit field of flags providing the
status of this observation.  If this field is 0 it means only the Cn0
estimate for the signal is valid.
 */
    GnssSignal sid /** GNSS signal identifier (16 bit) */
  };

  
  /**
   * Network correction for a particular satellite signal.
   *
   * Pseudorange and carrier phase network corrections for a satellite signal.
   */

  
  struct SBP_ATTR_PACKED PackedOsrContent {
    u32 P /** Pseudorange observation [2 cm] */
    CarrierPhase L /** Carrier phase observation with typical sign convention. [cycles] */
    u8 lock /** Lock timer. This value gives an indication of the time
for which a signal has maintained continuous phase lock.
Whenever a signal has lost and regained lock, this
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Valid values range
from 0 to 15 and the most significant nibble is reserved for future use.
 */
    u8 flags /** Correction flags.
 */
    GnssSignal sid /** GNSS signal identifier (16 bit) */
    u16 iono_std /** Slant ionospheric correction standard deviation [5 mm] */
    u16 tropo_std /** Slant tropospheric correction standard deviation [5 mm] */
    u16 range_std /** Orbit/clock/bias correction projected on range standard deviation [5 mm] */
  };

  
  /**
   * GPS satellite observations
   *
   * The GPS observations message reports all the raw pseudorange and
   * carrier phase observations for the satellites being tracked by
   * the device. Carrier phase observation here is represented as a
   * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
   * whole cycles and 8-bits of fractional cycles). The observations
   * are be interoperable with 3rd party receivers and conform
   * with typical RTCMv3 GNSS observations.
   */
  constexpr u16 MSG_OBS = 0x004A;

  template<size_t OBS_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(ObservationHeader) + 0) / sizeof(PackedObsContent)>
  struct SBP_ATTR_PACKED MsgObs {
    ObservationHeader header /** Header of a GPS observation message */
    PackedObsContent obs[OBS_COUNT]; /** Pseudorange and carrier phase observation for a
satellite being tracked.
 */
  };

  
  /**
   * Base station position
   *
   * The base station position message is the position reported by
   * the base station itself. It is used for pseudo-absolute RTK
   * positioning, and is required to be a high-accuracy surveyed
   * location of the base station. Any error here will result in an
   * error in the pseudo-absolute position output.
   */
  constexpr u16 MSG_BASE_POS_LLH = 0x0044;

  
  struct SBP_ATTR_PACKED MsgBasePosLlh {
    double lat /** Latitude [deg] */
    double lon /** Longitude [deg] */
    double height /** Height [m] */
  };

  
  /**
   * Base station position in ECEF
   *
   * The base station position message is the position reported by
   * the base station itself in absolute Earth Centered Earth Fixed
   * coordinates. It is used for pseudo-absolute RTK positioning, and
   * is required to be a high-accuracy surveyed location of the base
   * station. Any error here will result in an error in the
   * pseudo-absolute position output.
   */
  constexpr u16 MSG_BASE_POS_ECEF = 0x0048;

  
  struct SBP_ATTR_PACKED MsgBasePosEcef {
    double x /** ECEF X coodinate [m] */
    double y /** ECEF Y coordinate [m] */
    double z /** ECEF Z coordinate [m] */
  };

  

  
  struct SBP_ATTR_PACKED EphemerisCommonContent {
    GnssSignal sid /** GNSS signal identifier (16 bit) */
    GPSTimeSec toe /** Time of Ephemerides */
    float ura /** User Range Accuracy [m] */
    u32 fit_interval /** Curve fit interval [s] */
    u8 valid /** Status of ephemeris, 1 = valid, 0 = invalid */
    u8 health_bits /** Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid
 */
  };

  

  
  struct SBP_ATTR_PACKED EphemerisCommonContentDepB {
    GnssSignal sid /** GNSS signal identifier (16 bit) */
    GPSTimeSec toe /** Time of Ephemerides */
    double ura /** User Range Accuracy [m] */
    u32 fit_interval /** Curve fit interval [s] */
    u8 valid /** Status of ephemeris, 1 = valid, 0 = invalid */
    u8 health_bits /** Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
Others: 0 = valid, non-zero = invalid
 */
  };

  

  
  struct SBP_ATTR_PACKED EphemerisCommonContentDepA {
    GnssSignalDep sid /** GNSS signal identifier */
    GPSTimeDep toe /** Time of Ephemerides */
    double ura /** User Range Accuracy [m] */
    u32 fit_interval /** Curve fit interval [s] */
    u8 valid /** Status of ephemeris, 1 = valid, 0 = invalid */
    u8 health_bits /** Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid
 */
  };

  
  /**
   * Satellite broadcast ephemeris for GPS
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate GPS satellite position,
   * velocity, and clock offset. Please see the Navstar GPS
   * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
   * 20-III) for more details.
   */
  constexpr u16 MSG_EPHEMERIS_GPS_DEP_E = 0x0081;

  
  struct SBP_ATTR_PACKED MsgEphemerisGpsDepE {
    EphemerisCommonContentDepA common /** Values common for all ephemeris types */
    double tgd /** Group delay differential between L1 and L2 [s] */
    double c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    double c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    double c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    double c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    double c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    double c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    double af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    GPSTimeDep toc /** Clock reference */
    u8 iode /** Issue of ephemeris data */
    u16 iodc /** Issue of clock data */
  };

  
  /**
   * Deprecated
   *
   * This observation message has been deprecated in favor of
   * ephemeris message using floats for size reduction.
   */
  constexpr u16 MSG_EPHEMERIS_GPS_DEP_F = 0x0086;

  
  struct SBP_ATTR_PACKED MsgEphemerisGpsDepF {
    EphemerisCommonContentDepB common /** Values common for all ephemeris types */
    double tgd /** Group delay differential between L1 and L2 [s] */
    double c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    double c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    double c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    double c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    double c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    double c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    double af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    GPSTimeSec toc /** Clock reference */
    u8 iode /** Issue of ephemeris data */
    u16 iodc /** Issue of clock data */
  };

  
  /**
   * Satellite broadcast ephemeris for GPS
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate GPS satellite position,
   * velocity, and clock offset. Please see the Navstar GPS
   * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
   * 20-III) for more details.
   */
  constexpr u16 MSG_EPHEMERIS_GPS = 0x008A;

  
  struct SBP_ATTR_PACKED MsgEphemerisGps {
    EphemerisCommonContent common /** Values common for all ephemeris types */
    float tgd /** Group delay differential between L1 and L2 [s] */
    float c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    float c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    float c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    float c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    float c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    float c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    float af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    float af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    float af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    GPSTimeSec toc /** Clock reference */
    u8 iode /** Issue of ephemeris data */
    u16 iodc /** Issue of clock data */
  };

  
  /**
   * Satellite broadcast ephemeris for QZSS
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate QZSS satellite position,
   * velocity, and clock offset.
   */
  constexpr u16 MSG_EPHEMERIS_QZSS = 0x008E;

  
  struct SBP_ATTR_PACKED MsgEphemerisQzss {
    EphemerisCommonContent common /** Values common for all ephemeris types */
    float tgd /** Group delay differential between L1 and L2 [s] */
    float c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    float c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    float c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    float c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    float c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    float c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    float af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    float af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    float af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    GPSTimeSec toc /** Clock reference */
    u8 iode /** Issue of ephemeris data */
    u16 iodc /** Issue of clock data */
  };

  
  /**
   * Satellite broadcast ephemeris for BDS
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate BDS satellite position,
   * velocity, and clock offset. Please see the BeiDou Navigation
   * Satellite System SIS-ICD Version 2.1, Table 5-9 for more details.
   */
  constexpr u16 MSG_EPHEMERIS_BDS = 0x0089;

  
  struct SBP_ATTR_PACKED MsgEphemerisBds {
    EphemerisCommonContent common /** Values common for all ephemeris types */
    float tgd1 /** Group delay differential for B1 [s] */
    float tgd2 /** Group delay differential for B2 [s] */
    float c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    float c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    float c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    float c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    float c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    float c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    float af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    float af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    GPSTimeSec toc /** Clock reference */
    u8 iode /** Issue of ephemeris data

Calculated from the navigation data parameter t_oe per RTCM/CSNO recommendation:
IODE = mod (t_oe / 720, 240)
 */
    u16 iodc /** Issue of clock data

Calculated from the navigation data parameter t_oe per RTCM/CSNO recommendation:
IODE = mod (t_oc / 720, 240)
 */
  };

  
  /**
   * Deprecated
   *
   * This observation message has been deprecated in favor of
   * an ephemeris message with explicit source of NAV data.
   */
  constexpr u16 MSG_EPHEMERIS_GAL_DEP_A = 0x0095;

  
  struct SBP_ATTR_PACKED MsgEphemerisGalDepA {
    EphemerisCommonContent common /** Values common for all ephemeris types */
    float bgd_e1e5a /** E1-E5a Broadcast Group Delay [s] */
    float bgd_e1e5b /** E1-E5b Broadcast Group Delay [s] */
    float c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    float c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    float c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    float c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    float c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    float c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    float af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    GPSTimeSec toc /** Clock reference */
    u16 iode /** Issue of data (IODnav) */
    u16 iodc /** Issue of data (IODnav). Always equal to iode */
  };

  
  /**
   * Satellite broadcast ephemeris for Galileo
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate Galileo satellite position,
   * velocity, and clock offset. Please see the Signal In Space ICD
   * OS SIS ICD, Issue 1.3, December 2016 for more details.
   */
  constexpr u16 MSG_EPHEMERIS_GAL = 0x008D;

  
  struct SBP_ATTR_PACKED MsgEphemerisGal {
    EphemerisCommonContent common /** Values common for all ephemeris types */
    float bgd_e1e5a /** E1-E5a Broadcast Group Delay [s] */
    float bgd_e1e5b /** E1-E5b Broadcast Group Delay [s] */
    float c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    float c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    float c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    float c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    float c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    float c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    float af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    GPSTimeSec toc /** Clock reference */
    u16 iode /** Issue of data (IODnav) */
    u16 iodc /** Issue of data (IODnav). Always equal to iode */
    u8 source /** 0=I/NAV, 1=F/NAV */
  };

  
  constexpr u16 MSG_EPHEMERIS_SBAS_DEP_A = 0x0082;

  
  struct SBP_ATTR_PACKED MsgEphemerisSbasDepA {
    EphemerisCommonContentDepA common /** Values common for all ephemeris types */
    double pos[3]; /** Position of the GEO at time toe [m] */
    double vel[3]; /** Velocity of the GEO at time toe [m/s] */
    double acc[3]; /** Acceleration of the GEO at time toe [m/s^2] */
    double a_gf0 /** Time offset of the GEO clock w.r.t. SBAS Network Time [s] */
    double a_gf1 /** Drift of the GEO clock w.r.t. SBAS Network Time [s/s] */
  };

  
  /**
   * Satellite broadcast ephemeris for GLO
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate GLO satellite position,
   * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
   * Characteristics of words of immediate information (ephemeris parameters)"
   * for more details.
   */
  constexpr u16 MSG_EPHEMERIS_GLO_DEP_A = 0x0083;

  
  struct SBP_ATTR_PACKED MsgEphemerisGloDepA {
    EphemerisCommonContentDepA common /** Values common for all ephemeris types */
    double gamma /** Relative deviation of predicted carrier frequency from nominal */
    double tau /** Correction to the SV time [s] */
    double pos[3]; /** Position of the SV at tb in PZ-90.02 coordinates system [m] */
    double vel[3]; /** Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
    double acc[3]; /** Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
  };

  
  /**
   * Deprecated
   *
   * This observation message has been deprecated in favor of
   * ephemeris message using floats for size reduction.
   */
  constexpr u16 MSG_EPHEMERIS_SBAS_DEP_B = 0x0084;

  
  struct SBP_ATTR_PACKED MsgEphemerisSbasDepB {
    EphemerisCommonContentDepB common /** Values common for all ephemeris types */
    double pos[3]; /** Position of the GEO at time toe [m] */
    double vel[3]; /** Velocity of the GEO at time toe [m/s] */
    double acc[3]; /** Acceleration of the GEO at time toe [m/s^2] */
    double a_gf0 /** Time offset of the GEO clock w.r.t. SBAS Network Time [s] */
    double a_gf1 /** Drift of the GEO clock w.r.t. SBAS Network Time [s/s] */
  };

  
  constexpr u16 MSG_EPHEMERIS_SBAS = 0x008C;

  
  struct SBP_ATTR_PACKED MsgEphemerisSbas {
    EphemerisCommonContent common /** Values common for all ephemeris types */
    double pos[3]; /** Position of the GEO at time toe [m] */
    float vel[3]; /** Velocity of the GEO at time toe [m/s] */
    float acc[3]; /** Acceleration of the GEO at time toe [m/s^2] */
    float a_gf0 /** Time offset of the GEO clock w.r.t. SBAS Network Time [s] */
    float a_gf1 /** Drift of the GEO clock w.r.t. SBAS Network Time [s/s] */
  };

  
  /**
   * Satellite broadcast ephemeris for GLO
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate GLO satellite position,
   * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
   * Characteristics of words of immediate information (ephemeris parameters)"
   * for more details.
   */
  constexpr u16 MSG_EPHEMERIS_GLO_DEP_B = 0x0085;

  
  struct SBP_ATTR_PACKED MsgEphemerisGloDepB {
    EphemerisCommonContentDepB common /** Values common for all ephemeris types */
    double gamma /** Relative deviation of predicted carrier frequency from nominal */
    double tau /** Correction to the SV time [s] */
    double pos[3]; /** Position of the SV at tb in PZ-90.02 coordinates system [m] */
    double vel[3]; /** Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
    double acc[3]; /** Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
  };

  
  /**
   * Satellite broadcast ephemeris for GLO
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate GLO satellite position,
   * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
   * Characteristics of words of immediate information (ephemeris parameters)"
   * for more details.
   */
  constexpr u16 MSG_EPHEMERIS_GLO_DEP_C = 0x0087;

  
  struct SBP_ATTR_PACKED MsgEphemerisGloDepC {
    EphemerisCommonContentDepB common /** Values common for all ephemeris types */
    double gamma /** Relative deviation of predicted carrier frequency from nominal */
    double tau /** Correction to the SV time [s] */
    double d_tau /** Equipment delay between L1 and L2 [s] */
    double pos[3]; /** Position of the SV at tb in PZ-90.02 coordinates system [m] */
    double vel[3]; /** Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
    double acc[3]; /** Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
    u8 fcn /** Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
  };

  
  /**
   * Deprecated
   *
   * This observation message has been deprecated in favor of
   * ephemeris message using floats for size reduction.
   */
  constexpr u16 MSG_EPHEMERIS_GLO_DEP_D = 0x0088;

  
  struct SBP_ATTR_PACKED MsgEphemerisGloDepD {
    EphemerisCommonContentDepB common /** Values common for all ephemeris types */
    double gamma /** Relative deviation of predicted carrier frequency from nominal */
    double tau /** Correction to the SV time [s] */
    double d_tau /** Equipment delay between L1 and L2 [s] */
    double pos[3]; /** Position of the SV at tb in PZ-90.02 coordinates system [m] */
    double vel[3]; /** Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
    double acc[3]; /** Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
    u8 fcn /** Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
    u8 iod /** Issue of data. Equal to the 7 bits of the immediate data word t_b */
  };

  
  /**
   * Satellite broadcast ephemeris for GLO
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate GLO satellite position,
   * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
   * Characteristics of words of immediate information (ephemeris parameters)"
   * for more details.
   */
  constexpr u16 MSG_EPHEMERIS_GLO = 0x008B;

  
  struct SBP_ATTR_PACKED MsgEphemerisGlo {
    EphemerisCommonContent common /** Values common for all ephemeris types */
    float gamma /** Relative deviation of predicted carrier frequency from nominal */
    float tau /** Correction to the SV time [s] */
    float d_tau /** Equipment delay between L1 and L2 [s] */
    double pos[3]; /** Position of the SV at tb in PZ-90.02 coordinates system [m] */
    double vel[3]; /** Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
    float acc[3]; /** Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
    u8 fcn /** Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
    u8 iod /** Issue of data. Equal to the 7 bits of the immediate data word t_b */
  };

  
  /**
   * Satellite broadcast ephemeris
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate GPS satellite position,
   * velocity, and clock offset. Please see the Navstar GPS
   * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
   * 20-III) for more details.
   */
  constexpr u16 MSG_EPHEMERIS_DEP_D = 0x0080;

  
  struct SBP_ATTR_PACKED MsgEphemerisDepD {
    double tgd /** Group delay differential between L1 and L2 [s] */
    double c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    double c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    double c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    double c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    double c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    double c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    double af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    double toe_tow /** Time of week [s] */
    u16 toe_wn /** Week number [week] */
    double toc_tow /** Clock reference time of week [s] */
    u16 toc_wn /** Clock reference week number [week] */
    u8 valid /** Is valid? */
    u8 healthy /** Satellite is healthy? */
    GnssSignalDep sid /** GNSS signal identifier */
    u8 iode /** Issue of ephemeris data */
    u16 iodc /** Issue of clock data */
    u32 reserved /** Reserved field */
  };

  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  constexpr u16 MSG_EPHEMERIS_DEP_A = 0x001A;

  
  struct SBP_ATTR_PACKED MsgEphemerisDepA {
    double tgd /** Group delay differential between L1 and L2 [s] */
    double c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    double c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    double c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    double c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    double c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    double c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    double af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    double toe_tow /** Time of week [s] */
    u16 toe_wn /** Week number [week] */
    double toc_tow /** Clock reference time of week [s] */
    u16 toc_wn /** Clock reference week number [week] */
    u8 valid /** Is valid? */
    u8 healthy /** Satellite is healthy? */
    u8 prn /** PRN being tracked */
  };

  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  constexpr u16 MSG_EPHEMERIS_DEP_B = 0x0046;

  
  struct SBP_ATTR_PACKED MsgEphemerisDepB {
    double tgd /** Group delay differential between L1 and L2 [s] */
    double c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    double c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    double c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    double c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    double c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    double c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    double af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    double toe_tow /** Time of week [s] */
    u16 toe_wn /** Week number [week] */
    double toc_tow /** Clock reference time of week [s] */
    u16 toc_wn /** Clock reference week number [week] */
    u8 valid /** Is valid? */
    u8 healthy /** Satellite is healthy? */
    u8 prn /** PRN being tracked */
    u8 iode /** Issue of ephemeris data */
  };

  
  /**
   * Satellite broadcast ephemeris
   *
   * The ephemeris message returns a set of satellite orbit
   * parameters that is used to calculate GPS satellite position,
   * velocity, and clock offset. Please see the Navstar GPS
   * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
   * 20-III) for more details.
   */
  constexpr u16 MSG_EPHEMERIS_DEP_C = 0x0047;

  
  struct SBP_ATTR_PACKED MsgEphemerisDepC {
    double tgd /** Group delay differential between L1 and L2 [s] */
    double c_rs /** Amplitude of the sine harmonic correction term to the orbit radius [m] */
    double c_rc /** Amplitude of the cosine harmonic correction term to the orbit radius [m] */
    double c_uc /** Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
    double c_us /** Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
    double c_ic /** Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
    double c_is /** Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
    double dn /** Mean motion difference [rad/s] */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double inc_dot /** Inclination first derivative [rad/s] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
    double af2 /** Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
    double toe_tow /** Time of week [s] */
    u16 toe_wn /** Week number [week] */
    double toc_tow /** Clock reference time of week [s] */
    u16 toc_wn /** Clock reference week number [week] */
    u8 valid /** Is valid? */
    u8 healthy /** Satellite is healthy? */
    GnssSignalDep sid /** GNSS signal identifier */
    u8 iode /** Issue of ephemeris data */
    u16 iodc /** Issue of clock data */
    u32 reserved /** Reserved field */
  };

  
  /**
   * Header for observation message.
   *
   * Header of a GPS observation message.
   */

  
  struct SBP_ATTR_PACKED ObservationHeaderDep {
    GPSTimeDep t /** GPS time of this observation */
    u8 n_obs /** Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)
 */
  };

  
  /**
   * GPS carrier phase measurement.
   *
   * Carrier phase measurement in cycles represented as a 40-bit
   * fixed point number with Q32.8 layout, i.e. 32-bits of whole
   * cycles and 8-bits of fractional cycles. This has the opposite
   * sign convention than a typical GPS receiver and the phase has
   * the opposite sign as the pseudorange.
   */

  
  struct SBP_ATTR_PACKED CarrierPhaseDepA {
    s32 i /** Carrier phase whole cycles [cycles] */
    u8 f /** Carrier phase fractional part [cycles / 256] */
  };

  
  /**
   * Deprecated
   *
   * Deprecated.
   */

  
  struct SBP_ATTR_PACKED PackedObsContentDepA {
    u32 P /** Pseudorange observation [cm] */
    CarrierPhaseDepA L /** Carrier phase observation with opposite sign from typical convention */
    u8 cn0 /** Carrier-to-Noise density [dB Hz / 4] */
    u16 lock /** Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
    u8 prn /** PRN-1 identifier of the satellite signal */
  };

  
  /**
   * GPS observations for a particular satellite signal.
   *
   * Pseudorange and carrier phase observation for a satellite being
   * tracked.  Pseudoranges are referenced to a nominal pseudorange.
   */

  
  struct SBP_ATTR_PACKED PackedObsContentDepB {
    u32 P /** Pseudorange observation [cm] */
    CarrierPhaseDepA L /** Carrier phase observation with opposite sign from typical convention. */
    u8 cn0 /** Carrier-to-Noise density [dB Hz / 4] */
    u16 lock /** Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
    GnssSignalDep sid /** GNSS signal identifier */
  };

  
  /**
   * GPS observations for a particular satellite signal.
   *
   * Pseudorange and carrier phase observation for a satellite being
   * tracked. The observations are be interoperable with 3rd party
   * receivers and conform with typical RTCMv3 GNSS observations.
   */

  
  struct SBP_ATTR_PACKED PackedObsContentDepC {
    u32 P /** Pseudorange observation [2 cm] */
    CarrierPhase L /** Carrier phase observation with typical sign convention. [cycles] */
    u8 cn0 /** Carrier-to-Noise density [dB Hz / 4] */
    u16 lock /** Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
    GnssSignalDep sid /** GNSS signal identifier */
  };

  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  constexpr u16 MSG_OBS_DEP_A = 0x0045;

  template<size_t OBS_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(ObservationHeaderDep) + 0) / sizeof(PackedObsContentDepA)>
  struct SBP_ATTR_PACKED MsgObsDepA {
    ObservationHeaderDep header /** Header of a GPS observation message */
    PackedObsContentDepA obs[OBS_COUNT]; /** Pseudorange and carrier phase observation for a
satellite being tracked.
 */
  };

  
  /**
   * Deprecated
   *
   * This observation message has been deprecated in favor of
   * observations that are more interoperable. This message
   * should be used for observations referenced to
   * a nominal pseudorange which are not interoperable with
   * most 3rd party GNSS receievers or typical RTCMv3
   * observations.
   */
  constexpr u16 MSG_OBS_DEP_B = 0x0043;

  template<size_t OBS_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(ObservationHeaderDep) + 0) / sizeof(PackedObsContentDepB)>
  struct SBP_ATTR_PACKED MsgObsDepB {
    ObservationHeaderDep header /** Header of a GPS observation message */
    PackedObsContentDepB obs[OBS_COUNT]; /** Pseudorange and carrier phase observation for a
satellite being tracked.
 */
  };

  
  /**
   * Deprecated
   *
   * The GPS observations message reports all the raw pseudorange and
   * carrier phase observations for the satellites being tracked by
   * the device. Carrier phase observation here is represented as a
   * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
   * whole cycles and 8-bits of fractional cycles). The observations
   * are interoperable with 3rd party receivers and conform
   * with typical RTCMv3 GNSS observations.
   */
  constexpr u16 MSG_OBS_DEP_C = 0x0049;

  template<size_t OBS_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(ObservationHeaderDep) + 0) / sizeof(PackedObsContentDepC)>
  struct SBP_ATTR_PACKED MsgObsDepC {
    ObservationHeaderDep header /** Header of a GPS observation message */
    PackedObsContentDepC obs[OBS_COUNT]; /** Pseudorange and carrier phase observation for a
satellite being tracked.
 */
  };

  
  /**
   * Iono corrections
   *
   * The ionospheric parameters which allow the "L1 only" or "L2 only" user to
   * utilize the ionospheric model for computation of the ionospheric delay.
   * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
   */
  constexpr u16 MSG_IONO = 0x0090;

  
  struct SBP_ATTR_PACKED MsgIono {
    GPSTimeSec t_nmct /** Navigation Message Correction Table Valitidy Time */
    double a0
    double a1
    double a2
    double a3
    double b0
    double b1
    double b2
    double b3
  };

  
  /**
   * L2C capability mask
   *
   * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
   */
  constexpr u16 MSG_SV_CONFIGURATION_GPS_DEP = 0x0091;

  
  struct SBP_ATTR_PACKED MsgSvConfigurationGpsDep {
    GPSTimeSec t_nmct /** Navigation Message Correction Table Valitidy Time */
    u32 l2c_mask /** L2C capability mask, SV32 bit being MSB, SV1 bit being LSB */
  };

  

  
  struct SBP_ATTR_PACKED GnssCapb {
    u64 gps_active /** GPS SV active mask */
    u64 gps_l2c /** GPS L2C active mask */
    u64 gps_l5 /** GPS L5 active mask */
    u32 glo_active /** GLO active mask */
    u32 glo_l2of /** GLO L2OF active mask */
    u32 glo_l3 /** GLO L3 active mask */
    u64 sbas_active /** SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
 */
    u64 sbas_l5 /** SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
 */
    u64 bds_active /** BDS active mask */
    u64 bds_d2nav /** BDS D2NAV active mask */
    u64 bds_b2 /** BDS B2 active mask */
    u64 bds_b2a /** BDS B2A active mask */
    u32 qzss_active /** QZSS active mask */
    u64 gal_active /** GAL active mask */
    u64 gal_e5 /** GAL E5 active mask */
  };

  
  constexpr u16 MSG_GNSS_CAPB = 0x0096;

  
  struct SBP_ATTR_PACKED MsgGnssCapb {
    GPSTimeSec t_nmct /** Navigation Message Correction Table Validity Time */
    GnssCapb gc /** GNSS capabilities masks */
  };

  
  /**
   * Group Delay
   *
   * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
   */
  constexpr u16 MSG_GROUP_DELAY_DEP_A = 0x0092;

  
  struct SBP_ATTR_PACKED MsgGroupDelayDepA {
    GPSTimeDep t_op /** Data Predict Time of Week */
    u8 prn /** Satellite number */
    u8 valid /** bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.
 */
    s16 tgd
    s16 isc_l1ca
    s16 isc_l2c
  };

  
  /**
   * Group Delay
   *
   * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
   */
  constexpr u16 MSG_GROUP_DELAY_DEP_B = 0x0093;

  
  struct SBP_ATTR_PACKED MsgGroupDelayDepB {
    GPSTimeSec t_op /** Data Predict Time of Week */
    GnssSignalDep sid /** GNSS signal identifier */
    u8 valid /** bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.
 */
    s16 tgd
    s16 isc_l1ca
    s16 isc_l2c
  };

  
  /**
   * Group Delay
   *
   * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
   */
  constexpr u16 MSG_GROUP_DELAY = 0x0094;

  
  struct SBP_ATTR_PACKED MsgGroupDelay {
    GPSTimeSec t_op /** Data Predict Time of Week */
    GnssSignal sid /** GNSS signal identifier */
    u8 valid /** bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.
 */
    s16 tgd
    s16 isc_l1ca
    s16 isc_l2c
  };

  

  
  struct SBP_ATTR_PACKED AlmanacCommonContent {
    GnssSignal sid /** GNSS signal identifier */
    GPSTimeSec toa /** Reference time of almanac */
    double ura /** User Range Accuracy [m] */
    u32 fit_interval /** Curve fit interval [s] */
    u8 valid /** Status of almanac, 1 = valid, 0 = invalid */
    u8 health_bits /** Satellite health status for GPS:
  - bits 5-7: NAV data health status. See IS-GPS-200H
    Table 20-VII: NAV Data Health Indications.
  - bits 0-4: Signal health status. See IS-GPS-200H
    Table 20-VIII. Codes for Health of SV Signal
    Components.
Satellite health status for GLO:
  See GLO ICD 5.1 table 5.1 for details
  - bit 0: C(n), "unhealthy" flag that is transmitted within
    non-immediate data and indicates overall constellation status
    at the moment of almanac uploading.
    '0' indicates malfunction of n-satellite.
    '1' indicates that n-satellite is operational.
  - bit 1: Bn(ln), '0' indicates the satellite is operational
    and suitable for navigation.
 */
  };

  

  
  struct SBP_ATTR_PACKED AlmanacCommonContentDep {
    GnssSignalDep sid /** GNSS signal identifier */
    GPSTimeSec toa /** Reference time of almanac */
    double ura /** User Range Accuracy [m] */
    u32 fit_interval /** Curve fit interval [s] */
    u8 valid /** Status of almanac, 1 = valid, 0 = invalid */
    u8 health_bits /** Satellite health status for GPS:
  - bits 5-7: NAV data health status. See IS-GPS-200H
    Table 20-VII: NAV Data Health Indications.
  - bits 0-4: Signal health status. See IS-GPS-200H
    Table 20-VIII. Codes for Health of SV Signal
    Components.
Satellite health status for GLO:
  See GLO ICD 5.1 table 5.1 for details
  - bit 0: C(n), "unhealthy" flag that is transmitted within
    non-immediate data and indicates overall constellation status
    at the moment of almanac uploading.
    '0' indicates malfunction of n-satellite.
    '1' indicates that n-satellite is operational.
  - bit 1: Bn(ln), '0' indicates the satellite is operational
    and suitable for navigation.
 */
  };

  
  /**
   * Satellite broadcast ephemeris for GPS
   *
   * The almanac message returns a set of satellite orbit parameters. Almanac
   * data is not very precise and is considered valid for up to several months.
   * Please see the Navstar GPS Space Segment/Navigation user interfaces
   * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
   */
  constexpr u16 MSG_ALMANAC_GPS_DEP = 0x0070;

  
  struct SBP_ATTR_PACKED MsgAlmanacGpsDep {
    AlmanacCommonContentDep common /** Values common for all almanac types */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
  };

  
  /**
   * Satellite broadcast ephemeris for GPS
   *
   * The almanac message returns a set of satellite orbit parameters. Almanac
   * data is not very precise and is considered valid for up to several months.
   * Please see the Navstar GPS Space Segment/Navigation user interfaces
   * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
   */
  constexpr u16 MSG_ALMANAC_GPS = 0x0072;

  
  struct SBP_ATTR_PACKED MsgAlmanacGps {
    AlmanacCommonContent common /** Values common for all almanac types */
    double m0 /** Mean anomaly at reference time [rad] */
    double ecc /** Eccentricity of satellite orbit */
    double sqrta /** Square root of the semi-major axis of orbit [m^(1/2)] */
    double omega0 /** Longitude of ascending node of orbit plane at weekly epoch [rad] */
    double omegadot /** Rate of right ascension [rad/s] */
    double w /** Argument of perigee [rad] */
    double inc /** Inclination [rad] */
    double af0 /** Polynomial clock correction coefficient (clock bias) [s] */
    double af1 /** Polynomial clock correction coefficient (clock drift) [s/s] */
  };

  
  /**
   * Satellite broadcast ephemeris for GLO
   *
   * The almanac message returns a set of satellite orbit parameters. Almanac
   * data is not very precise and is considered valid for up to several months.
   * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
   * almanac" for details.
   */
  constexpr u16 MSG_ALMANAC_GLO_DEP = 0x0071;

  
  struct SBP_ATTR_PACKED MsgAlmanacGloDep {
    AlmanacCommonContentDep common /** Values common for all almanac types */
    double lambda_na /** Longitude of the first ascending node of the orbit in PZ-90.02
coordinate system
 [rad] */
    double t_lambda_na /** Time of the first ascending node passage [s] */
    double i /** Value of inclination at instant of t_lambda [rad] */
    double t /** Value of Draconian period at instant of t_lambda [s/orbital period] */
    double t_dot /** Rate of change of the Draconian period [s/(orbital period^2)] */
    double epsilon /** Eccentricity at instant of t_lambda */
    double omega /** Argument of perigee at instant of t_lambda [rad] */
  };

  
  /**
   * Satellite broadcast ephemeris for GLO
   *
   * The almanac message returns a set of satellite orbit parameters. Almanac
   * data is not very precise and is considered valid for up to several months.
   * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
   * almanac" for details.
   */
  constexpr u16 MSG_ALMANAC_GLO = 0x0073;

  
  struct SBP_ATTR_PACKED MsgAlmanacGlo {
    AlmanacCommonContent common /** Values common for all almanac types */
    double lambda_na /** Longitude of the first ascending node of the orbit in PZ-90.02
coordinate system
 [rad] */
    double t_lambda_na /** Time of the first ascending node passage [s] */
    double i /** Value of inclination at instant of t_lambda [rad] */
    double t /** Value of Draconian period at instant of t_lambda [s/orbital period] */
    double t_dot /** Rate of change of the Draconian period [s/(orbital period^2)] */
    double epsilon /** Eccentricity at instant of t_lambda */
    double omega /** Argument of perigee at instant of t_lambda [rad] */
  };

  
  /**
   * GLONASS L1/L2 Code-Phase biases
   *
   * The GLONASS L1/L2 Code-Phase biases allows to perform
   * GPS+GLONASS integer ambiguity resolution for baselines
   * with mixed receiver types (e.g. receiver of different
   * manufacturers)
   */
  constexpr u16 MSG_GLO_BIASES = 0x0075;

  
  struct SBP_ATTR_PACKED MsgGloBiases {
    u8 mask /** GLONASS FDMA signals mask [boolean] */
    s16 l1ca_bias /** GLONASS L1 C/A Code-Phase Bias [m * 0.02] */
    s16 l1p_bias /** GLONASS L1 P Code-Phase Bias [m * 0.02] */
    s16 l2ca_bias /** GLONASS L2 C/A Code-Phase Bias [m * 0.02] */
    s16 l2p_bias /** GLONASS L2 P Code-Phase Bias [m * 0.02] */
  };

  
  /**
   * Satellite azimuth and elevation.
   *
   * Satellite azimuth and elevation.
   */

  
  struct SBP_ATTR_PACKED SvAzEl {
    GnssSignal sid /** GNSS signal identifier */
    u8 az /** Azimuth angle (range 0..179) [deg * 2] */
    s8 el /** Elevation angle (range -90..90) [deg] */
  };

  
  /**
   * Satellite azimuths and elevations
   *
   * Azimuth and elevation angles of all the visible satellites
   * that the device does have ephemeris or almanac for.
   */
  constexpr u16 MSG_SV_AZ_EL = 0x0097;

  template<size_t AZEL_COUNT = (SBP_MAX_PAYLOAD_LEN - 0) / sizeof(SvAzEl)>
  struct SBP_ATTR_PACKED MsgSvAzEl {
    SvAzEl azel[AZEL_COUNT]; /** Azimuth and elevation per satellite */
  };

  
  /**
   * OSR corrections
   *
   * The OSR message contains network corrections in an observation-like format
   */
  constexpr u16 MSG_OSR = 0x0640;

  template<size_t OBS_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(ObservationHeader) + 0) / sizeof(PackedOsrContent)>
  struct SBP_ATTR_PACKED MsgOsr {
    ObservationHeader header /** Header of a GPS observation message */
    PackedOsrContent obs[OBS_COUNT]; /** Network correction for a
satellite signal.
 */
  };

  

}  // namespace sbp

#endif /* LIBSBP_CPP_OBSERVATION_MESSAGES_H */