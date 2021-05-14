/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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

/** \defgroup observation Observation
 *
 * * Satellite observation messages from the device.
 * \{ */

#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#define LIBSBP_OBSERVATION_MESSAGES_H

#include "common.h"
#include "gnss.h"

SBP_PACK_START


/** Header for observation message.
 *
* Header of a GNSS observation message.
 */

typedef struct SBP_ATTR_PACKED {
  sbp_gps_time_t t;        /**< GNSS time of this observation */
  u8 n_obs;    /**< Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)
 */
} observation_header_t;
 

/** GNSS doppler measurement.
 *
 * Doppler measurement in Hz represented as a 24-bit
 * fixed point number with Q16.8 layout, i.e. 16-bits of whole
 * doppler and 8-bits of fractional doppler. This doppler is defined
 * as positive for approaching satellites.
 */

typedef struct SBP_ATTR_PACKED {
  s16 i;    /**< Doppler whole Hz [Hz] */
  u8 f;    /**< Doppler fractional part [Hz / 256] */
} doppler_t;
 

/** GNSS observations for a particular satellite signal.
 *
 * Pseudorange and carrier phase observation for a satellite being tracked.
 * The observations are interoperable with 3rd party receivers and conform with
 * typical RTCM 3.1 message GPS/GLO observations.
 * 
 * Carrier phase observations are not guaranteed to be aligned to the RINEX 3
 * or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are currently
 * peformed.
 */

typedef struct SBP_ATTR_PACKED {
  u32 P;        /**< Pseudorange observation [2 cm] */
  carrier_phase_t L;        /**< Carrier phase observation with typical sign convention. [cycles] */
  doppler_t D;        /**< Doppler observation with typical sign convention. [Hz] */
  u8 cn0;      /**< Carrier-to-Noise density.  Zero implies invalid cn0. [dB Hz / 4] */
  u8 lock;     /**< Lock timer. This value gives an indication of the time
for which a signal has maintained continuous phase lock.
Whenever a signal has lost and regained lock, this
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Valid values range
from 0 to 15 and the most significant nibble is reserved for future use.
 */
  u8 flags;    /**< Measurement status flags. A bit field of flags providing the
status of this observation.  If this field is 0 it means only the Cn0
estimate for the signal is valid.
 */
  sbp_gnss_signal_t sid;      /**< GNSS signal identifier (16 bit) */
} packed_obs_content_t;
 

/** Network correction for a particular satellite signal.
 *
 * Pseudorange and carrier phase network corrections for a satellite signal.
 */

typedef struct SBP_ATTR_PACKED {
  u32 P;            /**< Pseudorange observation [2 cm] */
  carrier_phase_t L;            /**< Carrier phase observation with typical sign convention. [cycles] */
  u8 lock;         /**< Lock timer. This value gives an indication of the time
for which a signal has maintained continuous phase lock.
Whenever a signal has lost and regained lock, this
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Valid values range
from 0 to 15 and the most significant nibble is reserved for future use.
 */
  u8 flags;        /**< Correction flags.
 */
  sbp_gnss_signal_t sid;          /**< GNSS signal identifier (16 bit) */
  u16 iono_std;     /**< Slant ionospheric correction standard deviation [5 mm] */
  u16 tropo_std;    /**< Slant tropospheric correction standard deviation [5 mm] */
  u16 range_std;    /**< Orbit/clock/bias correction projected on range standard deviation [5 mm] */
} packed_osr_content_t;
 

/** GPS satellite observations
 *
 * The GPS observations message reports all the raw pseudorange and
 * carrier phase observations for the satellites being tracked by
 * the device. Carrier phase observation here is represented as a
 * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles). The observations
 * are be interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
 */
#define SBP_MSG_OBS                      0x004A

typedef struct SBP_ATTR_PACKED {
  observation_header_t header;    /**< Header of a GPS observation message */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  packed_obs_content_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
#endif
} msg_obs_t;
#define MSG_OBS_T_GET_OBS_PTR(msg) (( packed_obs_content_t *)(msg+1))
#define MSG_OBS_T_GET_OBS_CPTR(msg) ((const packed_obs_content_t *)(msg+1))
 

/** Base station position
 *
 * The base station position message is the position reported by
 * the base station itself. It is used for pseudo-absolute RTK
 * positioning, and is required to be a high-accuracy surveyed
 * location of the base station. Any error here will result in an
 * error in the pseudo-absolute position output.
 */
#define SBP_MSG_BASE_POS_LLH             0x0044

typedef struct SBP_ATTR_PACKED {
  double lat;       /**< Latitude [deg] */
  double lon;       /**< Longitude [deg] */
  double height;    /**< Height [m] */
} msg_base_pos_llh_t;
 

/** Base station position in ECEF
 *
 * The base station position message is the position reported by
 * the base station itself in absolute Earth Centered Earth Fixed
 * coordinates. It is used for pseudo-absolute RTK positioning, and
 * is required to be a high-accuracy surveyed location of the base
 * station. Any error here will result in an error in the
 * pseudo-absolute position output.
 */
#define SBP_MSG_BASE_POS_ECEF            0x0048

typedef struct SBP_ATTR_PACKED {
  double x;    /**< ECEF X coodinate [m] */
  double y;    /**< ECEF Y coordinate [m] */
  double z;    /**< ECEF Z coordinate [m] */
} msg_base_pos_ecef_t;
 


typedef struct SBP_ATTR_PACKED {
  sbp_gnss_signal_t sid;             /**< GNSS signal identifier (16 bit) */
  gps_time_sec_t toe;             /**< Time of Ephemerides */
  float ura;             /**< User Range Accuracy [m] */
  u32 fit_interval;    /**< Curve fit interval [s] */
  u8 valid;           /**< Status of ephemeris, 1 = valid, 0 = invalid */
  u8 health_bits;     /**< Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid
 */
} ephemeris_common_content_t;
 


typedef struct SBP_ATTR_PACKED {
  sbp_gnss_signal_t sid;             /**< GNSS signal identifier (16 bit) */
  gps_time_sec_t toe;             /**< Time of Ephemerides */
  double ura;             /**< User Range Accuracy [m] */
  u32 fit_interval;    /**< Curve fit interval [s] */
  u8 valid;           /**< Status of ephemeris, 1 = valid, 0 = invalid */
  u8 health_bits;     /**< Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
Others: 0 = valid, non-zero = invalid
 */
} ephemeris_common_content_dep_b_t;
 


typedef struct SBP_ATTR_PACKED {
  gnss_signal_dep_t sid;             /**< GNSS signal identifier */
  gps_time_dep_t toe;             /**< Time of Ephemerides */
  double ura;             /**< User Range Accuracy [m] */
  u32 fit_interval;    /**< Curve fit interval [s] */
  u8 valid;           /**< Status of ephemeris, 1 = valid, 0 = invalid */
  u8 health_bits;     /**< Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid
 */
} ephemeris_common_content_dep_a_t;
 

/** Satellite broadcast ephemeris for GPS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_GPS_DEP_E      0x0081

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_dep_a_t common;      /**< Values common for all ephemeris types */
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  gps_time_dep_t toc;         /**< Clock reference */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
} msg_ephemeris_gps_dep_e_t;
 

/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction.
 */
#define SBP_MSG_EPHEMERIS_GPS_DEP_F      0x0086

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_dep_b_t common;      /**< Values common for all ephemeris types */
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  gps_time_sec_t toc;         /**< Clock reference */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
} msg_ephemeris_gps_dep_f_t;
 

/** Satellite broadcast ephemeris for GPS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_GPS            0x008A

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_t common;      /**< Values common for all ephemeris types */
  float tgd;         /**< Group delay differential between L1 and L2 [s] */
  float c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  float c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  float c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  float c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  float c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  float c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  float af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  float af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  float af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  gps_time_sec_t toc;         /**< Clock reference */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
} msg_ephemeris_gps_t;
 

/** Satellite broadcast ephemeris for QZSS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate QZSS satellite position,
 * velocity, and clock offset.
 */
#define SBP_MSG_EPHEMERIS_QZSS           0x008E

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_t common;      /**< Values common for all ephemeris types */
  float tgd;         /**< Group delay differential between L1 and L2 [s] */
  float c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  float c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  float c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  float c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  float c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  float c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  float af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  float af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  float af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  gps_time_sec_t toc;         /**< Clock reference */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
} msg_ephemeris_qzss_t;
 

/** Satellite broadcast ephemeris for BDS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate BDS satellite position,
 * velocity, and clock offset. Please see the BeiDou Navigation
 * Satellite System SIS-ICD Version 2.1, Table 5-9 for more details.
 */
#define SBP_MSG_EPHEMERIS_BDS            0x0089

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_t common;      /**< Values common for all ephemeris types */
  float tgd1;        /**< Group delay differential for B1 [s] */
  float tgd2;        /**< Group delay differential for B2 [s] */
  float c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  float c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  float c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  float c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  float c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  float c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  float af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  float af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  gps_time_sec_t toc;         /**< Clock reference */
  u8 iode;        /**< Issue of ephemeris data

Calculated from the navigation data parameter t_oe per RTCM/CSNO recommendation:
IODE = mod (t_oe / 720, 240)
 */
  u16 iodc;        /**< Issue of clock data

Calculated from the navigation data parameter t_oe per RTCM/CSNO recommendation:
IODE = mod (t_oc / 720, 240)
 */
} msg_ephemeris_bds_t;
 

/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * an ephemeris message with explicit source of NAV data.
 */
#define SBP_MSG_EPHEMERIS_GAL_DEP_A      0x0095

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_t common;       /**< Values common for all ephemeris types */
  float bgd_e1e5a;    /**< E1-E5a Broadcast Group Delay [s] */
  float bgd_e1e5b;    /**< E1-E5b Broadcast Group Delay [s] */
  float c_rs;         /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  float c_rc;         /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  float c_uc;         /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  float c_us;         /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  float c_ic;         /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  float c_is;         /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;           /**< Mean motion difference [rad/s] */
  double m0;           /**< Mean anomaly at reference time [rad] */
  double ecc;          /**< Eccentricity of satellite orbit */
  double sqrta;        /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;       /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;     /**< Rate of right ascension [rad/s] */
  double w;            /**< Argument of perigee [rad] */
  double inc;          /**< Inclination [rad] */
  double inc_dot;      /**< Inclination first derivative [rad/s] */
  double af0;          /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;          /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  float af2;          /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  gps_time_sec_t toc;          /**< Clock reference */
  u16 iode;         /**< Issue of data (IODnav) */
  u16 iodc;         /**< Issue of data (IODnav). Always equal to iode */
} msg_ephemeris_gal_dep_a_t;
 

/** Satellite broadcast ephemeris for Galileo
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate Galileo satellite position,
 * velocity, and clock offset. Please see the Signal In Space ICD
 * OS SIS ICD, Issue 1.3, December 2016 for more details.
 */
#define SBP_MSG_EPHEMERIS_GAL            0x008D

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_t common;       /**< Values common for all ephemeris types */
  float bgd_e1e5a;    /**< E1-E5a Broadcast Group Delay [s] */
  float bgd_e1e5b;    /**< E1-E5b Broadcast Group Delay [s] */
  float c_rs;         /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  float c_rc;         /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  float c_uc;         /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  float c_us;         /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  float c_ic;         /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  float c_is;         /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;           /**< Mean motion difference [rad/s] */
  double m0;           /**< Mean anomaly at reference time [rad] */
  double ecc;          /**< Eccentricity of satellite orbit */
  double sqrta;        /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;       /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;     /**< Rate of right ascension [rad/s] */
  double w;            /**< Argument of perigee [rad] */
  double inc;          /**< Inclination [rad] */
  double inc_dot;      /**< Inclination first derivative [rad/s] */
  double af0;          /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;          /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  float af2;          /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  gps_time_sec_t toc;          /**< Clock reference */
  u16 iode;         /**< Issue of data (IODnav) */
  u16 iodc;         /**< Issue of data (IODnav). Always equal to iode */
  u8 source;       /**< 0=I/NAV, 1=F/NAV */
} msg_ephemeris_gal_t;
 

#define SBP_MSG_EPHEMERIS_SBAS_DEP_A     0x0082

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_dep_a_t common;    /**< Values common for all ephemeris types */
  double pos[3];    /**< Position of the GEO at time toe [m] */
  double vel[3];    /**< Velocity of the GEO at time toe [m/s] */
  double acc[3];    /**< Acceleration of the GEO at time toe [m/s^2] */
  double a_gf0;     /**< Time offset of the GEO clock w.r.t. SBAS Network Time [s] */
  double a_gf1;     /**< Drift of the GEO clock w.r.t. SBAS Network Time [s/s] */
} msg_ephemeris_sbas_dep_a_t;
 

/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_A      0x0083

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_dep_a_t common;    /**< Values common for all ephemeris types */
  double gamma;     /**< Relative deviation of predicted carrier frequency from nominal */
  double tau;       /**< Correction to the SV time [s] */
  double pos[3];    /**< Position of the SV at tb in PZ-90.02 coordinates system [m] */
  double vel[3];    /**< Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
  double acc[3];    /**< Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
} msg_ephemeris_glo_dep_a_t;
 

/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction.
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_B     0x0084

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_dep_b_t common;    /**< Values common for all ephemeris types */
  double pos[3];    /**< Position of the GEO at time toe [m] */
  double vel[3];    /**< Velocity of the GEO at time toe [m/s] */
  double acc[3];    /**< Acceleration of the GEO at time toe [m/s^2] */
  double a_gf0;     /**< Time offset of the GEO clock w.r.t. SBAS Network Time [s] */
  double a_gf1;     /**< Drift of the GEO clock w.r.t. SBAS Network Time [s/s] */
} msg_ephemeris_sbas_dep_b_t;
 

#define SBP_MSG_EPHEMERIS_SBAS           0x008C

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_t common;    /**< Values common for all ephemeris types */
  double pos[3];    /**< Position of the GEO at time toe [m] */
  float vel[3];    /**< Velocity of the GEO at time toe [m/s] */
  float acc[3];    /**< Acceleration of the GEO at time toe [m/s^2] */
  float a_gf0;     /**< Time offset of the GEO clock w.r.t. SBAS Network Time [s] */
  float a_gf1;     /**< Drift of the GEO clock w.r.t. SBAS Network Time [s/s] */
} msg_ephemeris_sbas_t;
 

/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_B      0x0085

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_dep_b_t common;    /**< Values common for all ephemeris types */
  double gamma;     /**< Relative deviation of predicted carrier frequency from nominal */
  double tau;       /**< Correction to the SV time [s] */
  double pos[3];    /**< Position of the SV at tb in PZ-90.02 coordinates system [m] */
  double vel[3];    /**< Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
  double acc[3];    /**< Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
} msg_ephemeris_glo_dep_b_t;
 

/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_C      0x0087

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_dep_b_t common;    /**< Values common for all ephemeris types */
  double gamma;     /**< Relative deviation of predicted carrier frequency from nominal */
  double tau;       /**< Correction to the SV time [s] */
  double d_tau;     /**< Equipment delay between L1 and L2 [s] */
  double pos[3];    /**< Position of the SV at tb in PZ-90.02 coordinates system [m] */
  double vel[3];    /**< Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
  double acc[3];    /**< Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
  u8 fcn;       /**< Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
} msg_ephemeris_glo_dep_c_t;
 

/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_D      0x0088

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_dep_b_t common;    /**< Values common for all ephemeris types */
  double gamma;     /**< Relative deviation of predicted carrier frequency from nominal */
  double tau;       /**< Correction to the SV time [s] */
  double d_tau;     /**< Equipment delay between L1 and L2 [s] */
  double pos[3];    /**< Position of the SV at tb in PZ-90.02 coordinates system [m] */
  double vel[3];    /**< Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
  double acc[3];    /**< Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
  u8 fcn;       /**< Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
  u8 iod;       /**< Issue of data. Equal to the 7 bits of the immediate data word t_b */
} msg_ephemeris_glo_dep_d_t;
 

/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO            0x008B

typedef struct SBP_ATTR_PACKED {
  ephemeris_common_content_t common;    /**< Values common for all ephemeris types */
  float gamma;     /**< Relative deviation of predicted carrier frequency from nominal */
  float tau;       /**< Correction to the SV time [s] */
  float d_tau;     /**< Equipment delay between L1 and L2 [s] */
  double pos[3];    /**< Position of the SV at tb in PZ-90.02 coordinates system [m] */
  double vel[3];    /**< Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
  float acc[3];    /**< Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
  u8 fcn;       /**< Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
  u8 iod;       /**< Issue of data. Equal to the 7 bits of the immediate data word t_b */
} msg_ephemeris_glo_t;
 

/** Satellite broadcast ephemeris
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_DEP_D          0x0080

typedef struct SBP_ATTR_PACKED {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  double toe_tow;     /**< Time of week [s] */
  u16 toe_wn;      /**< Week number [week] */
  double toc_tow;     /**< Clock reference time of week [s] */
  u16 toc_wn;      /**< Clock reference week number [week] */
  u8 valid;       /**< Is valid? */
  u8 healthy;     /**< Satellite is healthy? */
  gnss_signal_dep_t sid;         /**< GNSS signal identifier */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
  u32 reserved;    /**< Reserved field */
} msg_ephemeris_dep_d_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_EPHEMERIS_DEP_A          0x001A

typedef struct SBP_ATTR_PACKED {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  double toe_tow;     /**< Time of week [s] */
  u16 toe_wn;      /**< Week number [week] */
  double toc_tow;     /**< Clock reference time of week [s] */
  u16 toc_wn;      /**< Clock reference week number [week] */
  u8 valid;       /**< Is valid? */
  u8 healthy;     /**< Satellite is healthy? */
  u8 prn;         /**< PRN being tracked */
} msg_ephemeris_dep_a_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_EPHEMERIS_DEP_B          0x0046

typedef struct SBP_ATTR_PACKED {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  double toe_tow;     /**< Time of week [s] */
  u16 toe_wn;      /**< Week number [week] */
  double toc_tow;     /**< Clock reference time of week [s] */
  u16 toc_wn;      /**< Clock reference week number [week] */
  u8 valid;       /**< Is valid? */
  u8 healthy;     /**< Satellite is healthy? */
  u8 prn;         /**< PRN being tracked */
  u8 iode;        /**< Issue of ephemeris data */
} msg_ephemeris_dep_b_t;
 

/** Satellite broadcast ephemeris
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_DEP_C          0x0047

typedef struct SBP_ATTR_PACKED {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  double toe_tow;     /**< Time of week [s] */
  u16 toe_wn;      /**< Week number [week] */
  double toc_tow;     /**< Clock reference time of week [s] */
  u16 toc_wn;      /**< Clock reference week number [week] */
  u8 valid;       /**< Is valid? */
  u8 healthy;     /**< Satellite is healthy? */
  gnss_signal_dep_t sid;         /**< GNSS signal identifier */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
  u32 reserved;    /**< Reserved field */
} msg_ephemeris_dep_c_t;
 

/** Header for observation message.
 *
* Header of a GPS observation message.
 */

typedef struct SBP_ATTR_PACKED {
  gps_time_dep_t t;        /**< GPS time of this observation */
  u8 n_obs;    /**< Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)
 */
} observation_header_dep_t;
 

/** GPS carrier phase measurement.
 *
 * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles. This has the opposite
 * sign convention than a typical GPS receiver and the phase has
 * the opposite sign as the pseudorange.
 */

typedef struct SBP_ATTR_PACKED {
  s32 i;    /**< Carrier phase whole cycles [cycles] */
  u8 f;    /**< Carrier phase fractional part [cycles / 256] */
} carrier_phase_dep_a_t;
 

/** Deprecated
 *
* Deprecated.
 */

typedef struct SBP_ATTR_PACKED {
  u32 P;       /**< Pseudorange observation [cm] */
  carrier_phase_dep_a_t L;       /**< Carrier phase observation with opposite sign from typical convention */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz / 4] */
  u16 lock;    /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
  u8 prn;     /**< PRN-1 identifier of the satellite signal */
} packed_obs_content_dep_a_t;
 

/** GPS observations for a particular satellite signal.
 *
 * Pseudorange and carrier phase observation for a satellite being
 * tracked.  Pseudoranges are referenced to a nominal pseudorange.
 */

typedef struct SBP_ATTR_PACKED {
  u32 P;       /**< Pseudorange observation [cm] */
  carrier_phase_dep_a_t L;       /**< Carrier phase observation with opposite sign from typical convention. */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz / 4] */
  u16 lock;    /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
  gnss_signal_dep_t sid;     /**< GNSS signal identifier */
} packed_obs_content_dep_b_t;
 

/** GPS observations for a particular satellite signal.
 *
 * Pseudorange and carrier phase observation for a satellite being
 * tracked. The observations are be interoperable with 3rd party
 * receivers and conform with typical RTCMv3 GNSS observations.
 */

typedef struct SBP_ATTR_PACKED {
  u32 P;       /**< Pseudorange observation [2 cm] */
  carrier_phase_t L;       /**< Carrier phase observation with typical sign convention. [cycles] */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz / 4] */
  u16 lock;    /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
  gnss_signal_dep_t sid;     /**< GNSS signal identifier */
} packed_obs_content_dep_c_t;
 

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_OBS_DEP_A                0x0045

typedef struct SBP_ATTR_PACKED {
  observation_header_dep_t header;    /**< Header of a GPS observation message */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  packed_obs_content_dep_a_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
#endif
} msg_obs_dep_a_t;
#define MSG_OBS_DEP_A_T_GET_OBS_PTR(msg) (( packed_obs_content_dep_a_t *)(msg+1))
#define MSG_OBS_DEP_A_T_GET_OBS_CPTR(msg) ((const packed_obs_content_dep_a_t *)(msg+1))
 

/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * observations that are more interoperable. This message
 * should be used for observations referenced to
 * a nominal pseudorange which are not interoperable with
 * most 3rd party GNSS receievers or typical RTCMv3
 * observations.
 */
#define SBP_MSG_OBS_DEP_B                0x0043

typedef struct SBP_ATTR_PACKED {
  observation_header_dep_t header;    /**< Header of a GPS observation message */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  packed_obs_content_dep_b_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
#endif
} msg_obs_dep_b_t;
#define MSG_OBS_DEP_B_T_GET_OBS_PTR(msg) (( packed_obs_content_dep_b_t *)(msg+1))
#define MSG_OBS_DEP_B_T_GET_OBS_CPTR(msg) ((const packed_obs_content_dep_b_t *)(msg+1))
 

/** Deprecated
 *
 * The GPS observations message reports all the raw pseudorange and
 * carrier phase observations for the satellites being tracked by
 * the device. Carrier phase observation here is represented as a
 * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles). The observations
 * are interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
 */
#define SBP_MSG_OBS_DEP_C                0x0049

typedef struct SBP_ATTR_PACKED {
  observation_header_dep_t header;    /**< Header of a GPS observation message */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  packed_obs_content_dep_c_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
#endif
} msg_obs_dep_c_t;
#define MSG_OBS_DEP_C_T_GET_OBS_PTR(msg) (( packed_obs_content_dep_c_t *)(msg+1))
#define MSG_OBS_DEP_C_T_GET_OBS_CPTR(msg) ((const packed_obs_content_dep_c_t *)(msg+1))
 

/** Iono corrections
 *
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user to
 * utilize the ionospheric model for computation of the ionospheric delay.
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
 */
#define SBP_MSG_IONO                     0x0090

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t t_nmct;    /**< Navigation Message Correction Table Valitidy Time */
  double a0;       
  double a1;       
  double a2;       
  double a3;       
  double b0;       
  double b1;       
  double b2;       
  double b3;       
} msg_iono_t;
 

/** L2C capability mask
 *
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
 */
#define SBP_MSG_SV_CONFIGURATION_GPS_DEP 0x0091

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t t_nmct;      /**< Navigation Message Correction Table Valitidy Time */
  u32 l2c_mask;    /**< L2C capability mask, SV32 bit being MSB, SV1 bit being LSB */
} msg_sv_configuration_gps_dep_t;
 


typedef struct SBP_ATTR_PACKED {
  u64 gps_active;     /**< GPS SV active mask */
  u64 gps_l2c;        /**< GPS L2C active mask */
  u64 gps_l5;         /**< GPS L5 active mask */
  u32 glo_active;     /**< GLO active mask */
  u32 glo_l2of;       /**< GLO L2OF active mask */
  u32 glo_l3;         /**< GLO L3 active mask */
  u64 sbas_active;    /**< SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
 */
  u64 sbas_l5;        /**< SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
 */
  u64 bds_active;     /**< BDS active mask */
  u64 bds_d2nav;      /**< BDS D2NAV active mask */
  u64 bds_b2;         /**< BDS B2 active mask */
  u64 bds_b2a;        /**< BDS B2A active mask */
  u32 qzss_active;    /**< QZSS active mask */
  u64 gal_active;     /**< GAL active mask */
  u64 gal_e5;         /**< GAL E5 active mask */
} gnss_capb_t;
 

#define SBP_MSG_GNSS_CAPB                0x0096

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t t_nmct;    /**< Navigation Message Correction Table Validity Time */
  gnss_capb_t gc;        /**< GNSS capabilities masks */
} msg_gnss_capb_t;
 

/** Group Delay
 *
* Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
#define SBP_MSG_GROUP_DELAY_DEP_A        0x0092

typedef struct SBP_ATTR_PACKED {
  gps_time_dep_t t_op;        /**< Data Predict Time of Week */
  u8 prn;         /**< Satellite number */
  u8 valid;       /**< bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.
 */
  s16 tgd;        
  s16 isc_l1ca;   
  s16 isc_l2c;    
} msg_group_delay_dep_a_t;
 

/** Group Delay
 *
* Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
#define SBP_MSG_GROUP_DELAY_DEP_B        0x0093

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t t_op;        /**< Data Predict Time of Week */
  gnss_signal_dep_t sid;         /**< GNSS signal identifier */
  u8 valid;       /**< bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.
 */
  s16 tgd;        
  s16 isc_l1ca;   
  s16 isc_l2c;    
} msg_group_delay_dep_b_t;
 

/** Group Delay
 *
* Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
#define SBP_MSG_GROUP_DELAY              0x0094

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t t_op;        /**< Data Predict Time of Week */
  sbp_gnss_signal_t sid;         /**< GNSS signal identifier */
  u8 valid;       /**< bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.
 */
  s16 tgd;        
  s16 isc_l1ca;   
  s16 isc_l2c;    
} msg_group_delay_t;
 


typedef struct SBP_ATTR_PACKED {
  sbp_gnss_signal_t sid;             /**< GNSS signal identifier */
  gps_time_sec_t toa;             /**< Reference time of almanac */
  double ura;             /**< User Range Accuracy [m] */
  u32 fit_interval;    /**< Curve fit interval [s] */
  u8 valid;           /**< Status of almanac, 1 = valid, 0 = invalid */
  u8 health_bits;     /**< Satellite health status for GPS:
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
} almanac_common_content_t;
 


typedef struct SBP_ATTR_PACKED {
  gnss_signal_dep_t sid;             /**< GNSS signal identifier */
  gps_time_sec_t toa;             /**< Reference time of almanac */
  double ura;             /**< User Range Accuracy [m] */
  u32 fit_interval;    /**< Curve fit interval [s] */
  u8 valid;           /**< Status of almanac, 1 = valid, 0 = invalid */
  u8 health_bits;     /**< Satellite health status for GPS:
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
} almanac_common_content_dep_t;
 

/** Satellite broadcast ephemeris for GPS
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
 */
#define SBP_MSG_ALMANAC_GPS_DEP          0x0070

typedef struct SBP_ATTR_PACKED {
  almanac_common_content_dep_t common;      /**< Values common for all almanac types */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
} msg_almanac_gps_dep_t;
 

/** Satellite broadcast ephemeris for GPS
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
 */
#define SBP_MSG_ALMANAC_GPS              0x0072

typedef struct SBP_ATTR_PACKED {
  almanac_common_content_t common;      /**< Values common for all almanac types */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
} msg_almanac_gps_t;
 

/** Satellite broadcast ephemeris for GLO
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
 * almanac" for details.
 */
#define SBP_MSG_ALMANAC_GLO_DEP          0x0071

typedef struct SBP_ATTR_PACKED {
  almanac_common_content_dep_t common;         /**< Values common for all almanac types */
  double lambda_na;      /**< Longitude of the first ascending node of the orbit in PZ-90.02
coordinate system
 [rad] */
  double t_lambda_na;    /**< Time of the first ascending node passage [s] */
  double i;              /**< Value of inclination at instant of t_lambda [rad] */
  double t;              /**< Value of Draconian period at instant of t_lambda [s/orbital period] */
  double t_dot;          /**< Rate of change of the Draconian period [s/(orbital period^2)] */
  double epsilon;        /**< Eccentricity at instant of t_lambda */
  double omega;          /**< Argument of perigee at instant of t_lambda [rad] */
} msg_almanac_glo_dep_t;
 

/** Satellite broadcast ephemeris for GLO
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
 * almanac" for details.
 */
#define SBP_MSG_ALMANAC_GLO              0x0073

typedef struct SBP_ATTR_PACKED {
  almanac_common_content_t common;         /**< Values common for all almanac types */
  double lambda_na;      /**< Longitude of the first ascending node of the orbit in PZ-90.02
coordinate system
 [rad] */
  double t_lambda_na;    /**< Time of the first ascending node passage [s] */
  double i;              /**< Value of inclination at instant of t_lambda [rad] */
  double t;              /**< Value of Draconian period at instant of t_lambda [s/orbital period] */
  double t_dot;          /**< Rate of change of the Draconian period [s/(orbital period^2)] */
  double epsilon;        /**< Eccentricity at instant of t_lambda */
  double omega;          /**< Argument of perigee at instant of t_lambda [rad] */
} msg_almanac_glo_t;
 

/** GLONASS L1/L2 Code-Phase biases
 *
 * The GLONASS L1/L2 Code-Phase biases allows to perform
 * GPS+GLONASS integer ambiguity resolution for baselines
 * with mixed receiver types (e.g. receiver of different
 * manufacturers)
 */
#define SBP_MSG_GLO_BIASES               0x0075

typedef struct SBP_ATTR_PACKED {
  u8 mask;         /**< GLONASS FDMA signals mask [boolean] */
  s16 l1ca_bias;    /**< GLONASS L1 C/A Code-Phase Bias [m * 0.02] */
  s16 l1p_bias;     /**< GLONASS L1 P Code-Phase Bias [m * 0.02] */
  s16 l2ca_bias;    /**< GLONASS L2 C/A Code-Phase Bias [m * 0.02] */
  s16 l2p_bias;     /**< GLONASS L2 P Code-Phase Bias [m * 0.02] */
} msg_glo_biases_t;
 

/** Satellite azimuth and elevation.
 *
* Satellite azimuth and elevation.
 */

typedef struct SBP_ATTR_PACKED {
  sbp_gnss_signal_t sid;    /**< GNSS signal identifier */
  u8 az;     /**< Azimuth angle (range 0..179) [deg * 2] */
  s8 el;     /**< Elevation angle (range -90..90) [deg] */
} sv_az_el_t;
 

/** Satellite azimuths and elevations
 *
 * Azimuth and elevation angles of all the visible satellites
 * that the device does have ephemeris or almanac for.
 */
#define SBP_MSG_SV_AZ_EL                 0x0097
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  sv_az_el_t azel[0]; /**< Azimuth and elevation per satellite */
} msg_sv_az_el_t;
#endif
 

/** OSR corrections
 *
 * The OSR message contains network corrections in an observation-like format
 */
#define SBP_MSG_OSR                      0x0640

typedef struct SBP_ATTR_PACKED {
  observation_header_t header;    /**< Header of a GPS observation message */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  packed_osr_content_t obs[0];    /**< Network correction for a
satellite signal.
 */
#endif
} msg_osr_t;
#define MSG_OSR_T_GET_OBS_PTR(msg) (( packed_osr_content_t *)(msg+1))
#define MSG_OSR_T_GET_OBS_CPTR(msg) ((const packed_osr_content_t *)(msg+1))
 

/** \} */
static inline void static_asserts_for_module_ObservationHeader(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(observation_header_t, t ) == 0, offset_of_t_in_observation_header_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(observation_header_t, n_obs ) == 0 + sizeof(sbp_gps_time_t), offset_of_n_obs_in_observation_header_t_is_incorrect)
}

static inline void static_asserts_for_module_Doppler(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(doppler_t, i ) == 0, offset_of_i_in_doppler_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(doppler_t, f ) == 0 + sizeof(s16), offset_of_f_in_doppler_t_is_incorrect)
}

static inline void static_asserts_for_module_PackedObsContent(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_t, P ) == 0, offset_of_P_in_packed_obs_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_t, L ) == 0 + sizeof(u32), offset_of_L_in_packed_obs_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_t, D ) == 0 + sizeof(u32) + sizeof(carrier_phase_t), offset_of_D_in_packed_obs_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_t, cn0 ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(doppler_t), offset_of_cn0_in_packed_obs_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_t, lock ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(doppler_t) + sizeof(u8), offset_of_lock_in_packed_obs_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_t, flags ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(doppler_t) + sizeof(u8) + sizeof(u8), offset_of_flags_in_packed_obs_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_t, sid ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(doppler_t) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_sid_in_packed_obs_content_t_is_incorrect)
}

static inline void static_asserts_for_module_PackedOsrContent(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_osr_content_t, P ) == 0, offset_of_P_in_packed_osr_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_osr_content_t, L ) == 0 + sizeof(u32), offset_of_L_in_packed_osr_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_osr_content_t, lock ) == 0 + sizeof(u32) + sizeof(carrier_phase_t), offset_of_lock_in_packed_osr_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_osr_content_t, flags ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(u8), offset_of_flags_in_packed_osr_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_osr_content_t, sid ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u8), offset_of_sid_in_packed_osr_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_osr_content_t, iono_std ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u8) + sizeof(sbp_gnss_signal_t), offset_of_iono_std_in_packed_osr_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_osr_content_t, tropo_std ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u8) + sizeof(sbp_gnss_signal_t) + sizeof(u16), offset_of_tropo_std_in_packed_osr_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_osr_content_t, range_std ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u8) + sizeof(sbp_gnss_signal_t) + sizeof(u16) + sizeof(u16), offset_of_range_std_in_packed_osr_content_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_OBS(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_obs_t, header ) == 0, offset_of_header_in_msg_obs_t_is_incorrect)
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_obs_t, obs ) == 0 + sizeof(observation_header_t), offset_of_obs_in_msg_obs_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_BASE_POS_LLH(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_base_pos_llh_t, lat ) == 0, offset_of_lat_in_msg_base_pos_llh_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_base_pos_llh_t, lon ) == 0 + sizeof(double), offset_of_lon_in_msg_base_pos_llh_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_base_pos_llh_t, height ) == 0 + sizeof(double) + sizeof(double), offset_of_height_in_msg_base_pos_llh_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_BASE_POS_ECEF(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_base_pos_ecef_t, x ) == 0, offset_of_x_in_msg_base_pos_ecef_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_base_pos_ecef_t, y ) == 0 + sizeof(double), offset_of_y_in_msg_base_pos_ecef_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_base_pos_ecef_t, z ) == 0 + sizeof(double) + sizeof(double), offset_of_z_in_msg_base_pos_ecef_t_is_incorrect)
}

static inline void static_asserts_for_module_EphemerisCommonContent(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_t, sid ) == 0, offset_of_sid_in_ephemeris_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_t, toe ) == 0 + sizeof(sbp_gnss_signal_t), offset_of_toe_in_ephemeris_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_t, ura ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t), offset_of_ura_in_ephemeris_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_t, fit_interval ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t) + sizeof(float), offset_of_fit_interval_in_ephemeris_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_t, valid ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t) + sizeof(float) + sizeof(u32), offset_of_valid_in_ephemeris_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_t, health_bits ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t) + sizeof(float) + sizeof(u32) + sizeof(u8), offset_of_health_bits_in_ephemeris_common_content_t_is_incorrect)
}

static inline void static_asserts_for_module_EphemerisCommonContentDepB(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_b_t, sid ) == 0, offset_of_sid_in_ephemeris_common_content_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_b_t, toe ) == 0 + sizeof(sbp_gnss_signal_t), offset_of_toe_in_ephemeris_common_content_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_b_t, ura ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t), offset_of_ura_in_ephemeris_common_content_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_b_t, fit_interval ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t) + sizeof(double), offset_of_fit_interval_in_ephemeris_common_content_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_b_t, valid ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(u32), offset_of_valid_in_ephemeris_common_content_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_b_t, health_bits ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(u32) + sizeof(u8), offset_of_health_bits_in_ephemeris_common_content_dep_b_t_is_incorrect)
}

static inline void static_asserts_for_module_EphemerisCommonContentDepA(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_a_t, sid ) == 0, offset_of_sid_in_ephemeris_common_content_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_a_t, toe ) == 0 + sizeof(gnss_signal_dep_t), offset_of_toe_in_ephemeris_common_content_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_a_t, ura ) == 0 + sizeof(gnss_signal_dep_t) + sizeof(gps_time_dep_t), offset_of_ura_in_ephemeris_common_content_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_a_t, fit_interval ) == 0 + sizeof(gnss_signal_dep_t) + sizeof(gps_time_dep_t) + sizeof(double), offset_of_fit_interval_in_ephemeris_common_content_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_a_t, valid ) == 0 + sizeof(gnss_signal_dep_t) + sizeof(gps_time_dep_t) + sizeof(double) + sizeof(u32), offset_of_valid_in_ephemeris_common_content_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(ephemeris_common_content_dep_a_t, health_bits ) == 0 + sizeof(gnss_signal_dep_t) + sizeof(gps_time_dep_t) + sizeof(double) + sizeof(u32) + sizeof(u8), offset_of_health_bits_in_ephemeris_common_content_dep_a_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GPS_DEP_E(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, common ) == 0, offset_of_common_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, tgd ) == 0 + sizeof(ephemeris_common_content_dep_a_t), offset_of_tgd_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, c_rs ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double), offset_of_c_rs_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, c_rc ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double), offset_of_c_rc_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, c_uc ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_uc_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, c_us ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_us_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, c_ic ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_ic_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, c_is ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_is_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, dn ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_dn_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, m0 ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_m0_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, ecc ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, sqrta ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, omega0 ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, omegadot ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, w ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, inc ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, inc_dot ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, af0 ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, af1 ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, af2 ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af2_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, toc ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toc_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, iode ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(gps_time_dep_t), offset_of_iode_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_e_t, iodc ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(gps_time_dep_t) + sizeof(u8), offset_of_iodc_in_msg_ephemeris_gps_dep_e_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GPS_DEP_F(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, common ) == 0, offset_of_common_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, tgd ) == 0 + sizeof(ephemeris_common_content_dep_b_t), offset_of_tgd_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, c_rs ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double), offset_of_c_rs_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, c_rc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double), offset_of_c_rc_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, c_uc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_uc_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, c_us ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_us_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, c_ic ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_ic_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, c_is ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_is_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, dn ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_dn_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, m0 ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_m0_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, ecc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, sqrta ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, omega0 ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, omegadot ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, w ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, inc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, inc_dot ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, af0 ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, af1 ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, af2 ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af2_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, toc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toc_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, iode ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(gps_time_sec_t), offset_of_iode_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_dep_f_t, iodc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(gps_time_sec_t) + sizeof(u8), offset_of_iodc_in_msg_ephemeris_gps_dep_f_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GPS(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, common ) == 0, offset_of_common_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, tgd ) == 0 + sizeof(ephemeris_common_content_t), offset_of_tgd_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, c_rs ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float), offset_of_c_rs_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, c_rc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float), offset_of_c_rc_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, c_uc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_uc_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, c_us ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_us_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, c_ic ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_ic_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, c_is ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_is_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, dn ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_dn_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, m0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double), offset_of_m0_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, ecc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, sqrta ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, omega0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, omegadot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, w ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, inc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, inc_dot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, af0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, af1 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float), offset_of_af1_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, af2 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float), offset_of_af2_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, toc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_toc_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, iode ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(gps_time_sec_t), offset_of_iode_in_msg_ephemeris_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gps_t, iodc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(gps_time_sec_t) + sizeof(u8), offset_of_iodc_in_msg_ephemeris_gps_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_QZSS(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, common ) == 0, offset_of_common_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, tgd ) == 0 + sizeof(ephemeris_common_content_t), offset_of_tgd_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, c_rs ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float), offset_of_c_rs_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, c_rc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float), offset_of_c_rc_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, c_uc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_uc_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, c_us ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_us_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, c_ic ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_ic_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, c_is ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_is_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, dn ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_dn_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, m0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double), offset_of_m0_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, ecc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, sqrta ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, omega0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, omegadot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, w ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, inc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, inc_dot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, af0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, af1 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float), offset_of_af1_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, af2 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float), offset_of_af2_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, toc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_toc_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, iode ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(gps_time_sec_t), offset_of_iode_in_msg_ephemeris_qzss_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_qzss_t, iodc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(gps_time_sec_t) + sizeof(u8), offset_of_iodc_in_msg_ephemeris_qzss_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_BDS(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, common ) == 0, offset_of_common_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, tgd1 ) == 0 + sizeof(ephemeris_common_content_t), offset_of_tgd1_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, tgd2 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float), offset_of_tgd2_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, c_rs ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float), offset_of_c_rs_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, c_rc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_rc_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, c_uc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_uc_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, c_us ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_us_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, c_ic ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_ic_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, c_is ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_is_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, dn ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_dn_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, m0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double), offset_of_m0_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, ecc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, sqrta ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, omega0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, omegadot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, w ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, inc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, inc_dot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, af0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, af1 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, af2 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float), offset_of_af2_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, toc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float), offset_of_toc_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, iode ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float) + sizeof(gps_time_sec_t), offset_of_iode_in_msg_ephemeris_bds_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_bds_t, iodc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(float) + sizeof(gps_time_sec_t) + sizeof(u8), offset_of_iodc_in_msg_ephemeris_bds_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GAL_DEP_A(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, common ) == 0, offset_of_common_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, bgd_e1e5a ) == 0 + sizeof(ephemeris_common_content_t), offset_of_bgd_e1e5a_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, bgd_e1e5b ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float), offset_of_bgd_e1e5b_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, c_rs ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float), offset_of_c_rs_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, c_rc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_rc_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, c_uc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_uc_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, c_us ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_us_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, c_ic ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_ic_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, c_is ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_is_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, dn ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_dn_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, m0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double), offset_of_m0_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, ecc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, sqrta ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, omega0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, omegadot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, w ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, inc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, inc_dot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, af0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, af1 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, af2 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af2_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, toc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float), offset_of_toc_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, iode ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(gps_time_sec_t), offset_of_iode_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_dep_a_t, iodc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(gps_time_sec_t) + sizeof(u16), offset_of_iodc_in_msg_ephemeris_gal_dep_a_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GAL(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, common ) == 0, offset_of_common_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, bgd_e1e5a ) == 0 + sizeof(ephemeris_common_content_t), offset_of_bgd_e1e5a_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, bgd_e1e5b ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float), offset_of_bgd_e1e5b_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, c_rs ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float), offset_of_c_rs_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, c_rc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_rc_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, c_uc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_uc_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, c_us ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_us_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, c_ic ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_ic_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, c_is ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_c_is_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, dn ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_dn_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, m0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double), offset_of_m0_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, ecc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, sqrta ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, omega0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, omegadot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, w ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, inc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, inc_dot ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, af0 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, af1 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, af2 ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af2_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, toc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float), offset_of_toc_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, iode ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(gps_time_sec_t), offset_of_iode_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, iodc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(gps_time_sec_t) + sizeof(u16), offset_of_iodc_in_msg_ephemeris_gal_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_gal_t, source ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(float) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(float) + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16), offset_of_source_in_msg_ephemeris_gal_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_SBAS_DEP_A(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_a_t, common ) == 0, offset_of_common_in_msg_ephemeris_sbas_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_a_t, pos ) == 0 + sizeof(ephemeris_common_content_dep_a_t), offset_of_pos_in_msg_ephemeris_sbas_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_a_t, vel ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + (sizeof(double) * 3), offset_of_vel_in_msg_ephemeris_sbas_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_a_t, acc ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_acc_in_msg_ephemeris_sbas_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_a_t, a_gf0 ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + (sizeof(double) * 3) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_a_gf0_in_msg_ephemeris_sbas_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_a_t, a_gf1 ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + (sizeof(double) * 3) + (sizeof(double) * 3) + (sizeof(double) * 3) + sizeof(double), offset_of_a_gf1_in_msg_ephemeris_sbas_dep_a_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GLO_DEP_A(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_a_t, common ) == 0, offset_of_common_in_msg_ephemeris_glo_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_a_t, gamma ) == 0 + sizeof(ephemeris_common_content_dep_a_t), offset_of_gamma_in_msg_ephemeris_glo_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_a_t, tau ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double), offset_of_tau_in_msg_ephemeris_glo_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_a_t, pos ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double), offset_of_pos_in_msg_ephemeris_glo_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_a_t, vel ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + (sizeof(double) * 3), offset_of_vel_in_msg_ephemeris_glo_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_a_t, acc ) == 0 + sizeof(ephemeris_common_content_dep_a_t) + sizeof(double) + sizeof(double) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_acc_in_msg_ephemeris_glo_dep_a_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_SBAS_DEP_B(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_b_t, common ) == 0, offset_of_common_in_msg_ephemeris_sbas_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_b_t, pos ) == 0 + sizeof(ephemeris_common_content_dep_b_t), offset_of_pos_in_msg_ephemeris_sbas_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_b_t, vel ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + (sizeof(double) * 3), offset_of_vel_in_msg_ephemeris_sbas_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_b_t, acc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_acc_in_msg_ephemeris_sbas_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_b_t, a_gf0 ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + (sizeof(double) * 3) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_a_gf0_in_msg_ephemeris_sbas_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_dep_b_t, a_gf1 ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + (sizeof(double) * 3) + (sizeof(double) * 3) + (sizeof(double) * 3) + sizeof(double), offset_of_a_gf1_in_msg_ephemeris_sbas_dep_b_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_SBAS(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_t, common ) == 0, offset_of_common_in_msg_ephemeris_sbas_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_t, pos ) == 0 + sizeof(ephemeris_common_content_t), offset_of_pos_in_msg_ephemeris_sbas_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_t, vel ) == 0 + sizeof(ephemeris_common_content_t) + (sizeof(double) * 3), offset_of_vel_in_msg_ephemeris_sbas_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_t, acc ) == 0 + sizeof(ephemeris_common_content_t) + (sizeof(double) * 3) + (sizeof(float) * 3), offset_of_acc_in_msg_ephemeris_sbas_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_t, a_gf0 ) == 0 + sizeof(ephemeris_common_content_t) + (sizeof(double) * 3) + (sizeof(float) * 3) + (sizeof(float) * 3), offset_of_a_gf0_in_msg_ephemeris_sbas_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_sbas_t, a_gf1 ) == 0 + sizeof(ephemeris_common_content_t) + (sizeof(double) * 3) + (sizeof(float) * 3) + (sizeof(float) * 3) + sizeof(float), offset_of_a_gf1_in_msg_ephemeris_sbas_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GLO_DEP_B(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_b_t, common ) == 0, offset_of_common_in_msg_ephemeris_glo_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_b_t, gamma ) == 0 + sizeof(ephemeris_common_content_dep_b_t), offset_of_gamma_in_msg_ephemeris_glo_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_b_t, tau ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double), offset_of_tau_in_msg_ephemeris_glo_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_b_t, pos ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double), offset_of_pos_in_msg_ephemeris_glo_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_b_t, vel ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + (sizeof(double) * 3), offset_of_vel_in_msg_ephemeris_glo_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_b_t, acc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_acc_in_msg_ephemeris_glo_dep_b_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GLO_DEP_C(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_c_t, common ) == 0, offset_of_common_in_msg_ephemeris_glo_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_c_t, gamma ) == 0 + sizeof(ephemeris_common_content_dep_b_t), offset_of_gamma_in_msg_ephemeris_glo_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_c_t, tau ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double), offset_of_tau_in_msg_ephemeris_glo_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_c_t, d_tau ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double), offset_of_d_tau_in_msg_ephemeris_glo_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_c_t, pos ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_pos_in_msg_ephemeris_glo_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_c_t, vel ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + (sizeof(double) * 3), offset_of_vel_in_msg_ephemeris_glo_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_c_t, acc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_acc_in_msg_ephemeris_glo_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_c_t, fcn ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + (sizeof(double) * 3) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_fcn_in_msg_ephemeris_glo_dep_c_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GLO_DEP_D(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_d_t, common ) == 0, offset_of_common_in_msg_ephemeris_glo_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_d_t, gamma ) == 0 + sizeof(ephemeris_common_content_dep_b_t), offset_of_gamma_in_msg_ephemeris_glo_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_d_t, tau ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double), offset_of_tau_in_msg_ephemeris_glo_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_d_t, d_tau ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double), offset_of_d_tau_in_msg_ephemeris_glo_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_d_t, pos ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_pos_in_msg_ephemeris_glo_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_d_t, vel ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + (sizeof(double) * 3), offset_of_vel_in_msg_ephemeris_glo_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_d_t, acc ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_acc_in_msg_ephemeris_glo_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_d_t, fcn ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + (sizeof(double) * 3) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_fcn_in_msg_ephemeris_glo_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_dep_d_t, iod ) == 0 + sizeof(ephemeris_common_content_dep_b_t) + sizeof(double) + sizeof(double) + sizeof(double) + (sizeof(double) * 3) + (sizeof(double) * 3) + (sizeof(double) * 3) + sizeof(u8), offset_of_iod_in_msg_ephemeris_glo_dep_d_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_GLO(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_t, common ) == 0, offset_of_common_in_msg_ephemeris_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_t, gamma ) == 0 + sizeof(ephemeris_common_content_t), offset_of_gamma_in_msg_ephemeris_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_t, tau ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float), offset_of_tau_in_msg_ephemeris_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_t, d_tau ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float), offset_of_d_tau_in_msg_ephemeris_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_t, pos ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float), offset_of_pos_in_msg_ephemeris_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_t, vel ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + (sizeof(double) * 3), offset_of_vel_in_msg_ephemeris_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_t, acc ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + (sizeof(double) * 3) + (sizeof(double) * 3), offset_of_acc_in_msg_ephemeris_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_t, fcn ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + (sizeof(double) * 3) + (sizeof(double) * 3) + (sizeof(float) * 3), offset_of_fcn_in_msg_ephemeris_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_glo_t, iod ) == 0 + sizeof(ephemeris_common_content_t) + sizeof(float) + sizeof(float) + sizeof(float) + (sizeof(double) * 3) + (sizeof(double) * 3) + (sizeof(float) * 3) + sizeof(u8), offset_of_iod_in_msg_ephemeris_glo_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_DEP_D(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, tgd ) == 0, offset_of_tgd_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, c_rs ) == 0 + sizeof(double), offset_of_c_rs_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, c_rc ) == 0 + sizeof(double) + sizeof(double), offset_of_c_rc_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, c_uc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_uc_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, c_us ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_us_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, c_ic ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_ic_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, c_is ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_is_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, dn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_dn_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, m0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_m0_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, ecc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, sqrta ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, omega0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, omegadot ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, w ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, inc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, inc_dot ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, af0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, af1 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, af2 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af2_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, toe_tow ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toe_tow_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, toe_wn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toe_wn_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, toc_tow ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16), offset_of_toc_tow_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, toc_wn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double), offset_of_toc_wn_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, valid ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16), offset_of_valid_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, healthy ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8), offset_of_healthy_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, sid ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8), offset_of_sid_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, iode ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(gnss_signal_dep_t), offset_of_iode_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, iodc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u8), offset_of_iodc_in_msg_ephemeris_dep_d_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_d_t, reserved ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u8) + sizeof(u16), offset_of_reserved_in_msg_ephemeris_dep_d_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_DEP_A(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, tgd ) == 0, offset_of_tgd_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, c_rs ) == 0 + sizeof(double), offset_of_c_rs_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, c_rc ) == 0 + sizeof(double) + sizeof(double), offset_of_c_rc_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, c_uc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_uc_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, c_us ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_us_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, c_ic ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_ic_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, c_is ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_is_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, dn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_dn_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, m0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_m0_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, ecc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, sqrta ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, omega0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, omegadot ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, w ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, inc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, inc_dot ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, af0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, af1 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, af2 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af2_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, toe_tow ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toe_tow_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, toe_wn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toe_wn_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, toc_tow ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16), offset_of_toc_tow_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, toc_wn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double), offset_of_toc_wn_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, valid ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16), offset_of_valid_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, healthy ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8), offset_of_healthy_in_msg_ephemeris_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_a_t, prn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8), offset_of_prn_in_msg_ephemeris_dep_a_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_DEP_B(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, tgd ) == 0, offset_of_tgd_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, c_rs ) == 0 + sizeof(double), offset_of_c_rs_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, c_rc ) == 0 + sizeof(double) + sizeof(double), offset_of_c_rc_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, c_uc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_uc_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, c_us ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_us_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, c_ic ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_ic_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, c_is ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_is_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, dn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_dn_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, m0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_m0_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, ecc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, sqrta ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, omega0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, omegadot ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, w ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, inc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, inc_dot ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, af0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, af1 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, af2 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af2_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, toe_tow ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toe_tow_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, toe_wn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toe_wn_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, toc_tow ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16), offset_of_toc_tow_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, toc_wn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double), offset_of_toc_wn_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, valid ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16), offset_of_valid_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, healthy ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8), offset_of_healthy_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, prn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8), offset_of_prn_in_msg_ephemeris_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_b_t, iode ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_iode_in_msg_ephemeris_dep_b_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_EPHEMERIS_DEP_C(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, tgd ) == 0, offset_of_tgd_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, c_rs ) == 0 + sizeof(double), offset_of_c_rs_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, c_rc ) == 0 + sizeof(double) + sizeof(double), offset_of_c_rc_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, c_uc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_uc_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, c_us ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_us_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, c_ic ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_ic_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, c_is ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_c_is_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, dn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_dn_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, m0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_m0_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, ecc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_ecc_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, sqrta ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, omega0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, omegadot ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, w ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, inc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, inc_dot ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_dot_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, af0 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, af1 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, af2 ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af2_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, toe_tow ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toe_tow_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, toe_wn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_toe_wn_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, toc_tow ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16), offset_of_toc_tow_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, toc_wn ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double), offset_of_toc_wn_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, valid ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16), offset_of_valid_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, healthy ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8), offset_of_healthy_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, sid ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8), offset_of_sid_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, iode ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(gnss_signal_dep_t), offset_of_iode_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, iodc ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u8), offset_of_iodc_in_msg_ephemeris_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ephemeris_dep_c_t, reserved ) == 0 + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(u16) + sizeof(double) + sizeof(u16) + sizeof(u8) + sizeof(u8) + sizeof(gnss_signal_dep_t) + sizeof(u8) + sizeof(u16), offset_of_reserved_in_msg_ephemeris_dep_c_t_is_incorrect)
}

static inline void static_asserts_for_module_ObservationHeaderDep(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(observation_header_dep_t, t ) == 0, offset_of_t_in_observation_header_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(observation_header_dep_t, n_obs ) == 0 + sizeof(gps_time_dep_t), offset_of_n_obs_in_observation_header_dep_t_is_incorrect)
}

static inline void static_asserts_for_module_CarrierPhaseDepA(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(carrier_phase_dep_a_t, i ) == 0, offset_of_i_in_carrier_phase_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(carrier_phase_dep_a_t, f ) == 0 + sizeof(s32), offset_of_f_in_carrier_phase_dep_a_t_is_incorrect)
}

static inline void static_asserts_for_module_PackedObsContentDepA(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_a_t, P ) == 0, offset_of_P_in_packed_obs_content_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_a_t, L ) == 0 + sizeof(u32), offset_of_L_in_packed_obs_content_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_a_t, cn0 ) == 0 + sizeof(u32) + sizeof(carrier_phase_dep_a_t), offset_of_cn0_in_packed_obs_content_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_a_t, lock ) == 0 + sizeof(u32) + sizeof(carrier_phase_dep_a_t) + sizeof(u8), offset_of_lock_in_packed_obs_content_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_a_t, prn ) == 0 + sizeof(u32) + sizeof(carrier_phase_dep_a_t) + sizeof(u8) + sizeof(u16), offset_of_prn_in_packed_obs_content_dep_a_t_is_incorrect)
}

static inline void static_asserts_for_module_PackedObsContentDepB(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_b_t, P ) == 0, offset_of_P_in_packed_obs_content_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_b_t, L ) == 0 + sizeof(u32), offset_of_L_in_packed_obs_content_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_b_t, cn0 ) == 0 + sizeof(u32) + sizeof(carrier_phase_dep_a_t), offset_of_cn0_in_packed_obs_content_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_b_t, lock ) == 0 + sizeof(u32) + sizeof(carrier_phase_dep_a_t) + sizeof(u8), offset_of_lock_in_packed_obs_content_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_b_t, sid ) == 0 + sizeof(u32) + sizeof(carrier_phase_dep_a_t) + sizeof(u8) + sizeof(u16), offset_of_sid_in_packed_obs_content_dep_b_t_is_incorrect)
}

static inline void static_asserts_for_module_PackedObsContentDepC(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_c_t, P ) == 0, offset_of_P_in_packed_obs_content_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_c_t, L ) == 0 + sizeof(u32), offset_of_L_in_packed_obs_content_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_c_t, cn0 ) == 0 + sizeof(u32) + sizeof(carrier_phase_t), offset_of_cn0_in_packed_obs_content_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_c_t, lock ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(u8), offset_of_lock_in_packed_obs_content_dep_c_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(packed_obs_content_dep_c_t, sid ) == 0 + sizeof(u32) + sizeof(carrier_phase_t) + sizeof(u8) + sizeof(u16), offset_of_sid_in_packed_obs_content_dep_c_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_OBS_DEP_A(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_obs_dep_a_t, header ) == 0, offset_of_header_in_msg_obs_dep_a_t_is_incorrect)
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_obs_dep_a_t, obs ) == 0 + sizeof(observation_header_dep_t), offset_of_obs_in_msg_obs_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_OBS_DEP_B(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_obs_dep_b_t, header ) == 0, offset_of_header_in_msg_obs_dep_b_t_is_incorrect)
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_obs_dep_b_t, obs ) == 0 + sizeof(observation_header_dep_t), offset_of_obs_in_msg_obs_dep_b_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_OBS_DEP_C(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_obs_dep_c_t, header ) == 0, offset_of_header_in_msg_obs_dep_c_t_is_incorrect)
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_obs_dep_c_t, obs ) == 0 + sizeof(observation_header_dep_t), offset_of_obs_in_msg_obs_dep_c_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_IONO(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iono_t, t_nmct ) == 0, offset_of_t_nmct_in_msg_iono_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iono_t, a0 ) == 0 + sizeof(gps_time_sec_t), offset_of_a0_in_msg_iono_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iono_t, a1 ) == 0 + sizeof(gps_time_sec_t) + sizeof(double), offset_of_a1_in_msg_iono_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iono_t, a2 ) == 0 + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(double), offset_of_a2_in_msg_iono_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iono_t, a3 ) == 0 + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_a3_in_msg_iono_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iono_t, b0 ) == 0 + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_b0_in_msg_iono_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iono_t, b1 ) == 0 + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_b1_in_msg_iono_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iono_t, b2 ) == 0 + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_b2_in_msg_iono_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_iono_t, b3 ) == 0 + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_b3_in_msg_iono_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_SV_CONFIGURATION_GPS_DEP(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_sv_configuration_gps_dep_t, t_nmct ) == 0, offset_of_t_nmct_in_msg_sv_configuration_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_sv_configuration_gps_dep_t, l2c_mask ) == 0 + sizeof(gps_time_sec_t), offset_of_l2c_mask_in_msg_sv_configuration_gps_dep_t_is_incorrect)
}

static inline void static_asserts_for_module_GnssCapb(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, gps_active ) == 0, offset_of_gps_active_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, gps_l2c ) == 0 + sizeof(u64), offset_of_gps_l2c_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, gps_l5 ) == 0 + sizeof(u64) + sizeof(u64), offset_of_gps_l5_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, glo_active ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64), offset_of_glo_active_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, glo_l2of ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32), offset_of_glo_l2of_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, glo_l3 ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32), offset_of_glo_l3_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, sbas_active ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32) + sizeof(u32), offset_of_sbas_active_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, sbas_l5 ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u64), offset_of_sbas_l5_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, bds_active ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u64) + sizeof(u64), offset_of_bds_active_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, bds_d2nav ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u64) + sizeof(u64) + sizeof(u64), offset_of_bds_d2nav_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, bds_b2 ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64), offset_of_bds_b2_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, bds_b2a ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64), offset_of_bds_b2a_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, qzss_active ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64), offset_of_qzss_active_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, gal_active ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32), offset_of_gal_active_in_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gnss_capb_t, gal_e5 ) == 0 + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u32) + sizeof(u32) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u64) + sizeof(u32) + sizeof(u64), offset_of_gal_e5_in_gnss_capb_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_GNSS_CAPB(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_gnss_capb_t, t_nmct ) == 0, offset_of_t_nmct_in_msg_gnss_capb_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_gnss_capb_t, gc ) == 0 + sizeof(gps_time_sec_t), offset_of_gc_in_msg_gnss_capb_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_GROUP_DELAY_DEP_A(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_a_t, t_op ) == 0, offset_of_t_op_in_msg_group_delay_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_a_t, prn ) == 0 + sizeof(gps_time_dep_t), offset_of_prn_in_msg_group_delay_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_a_t, valid ) == 0 + sizeof(gps_time_dep_t) + sizeof(u8), offset_of_valid_in_msg_group_delay_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_a_t, tgd ) == 0 + sizeof(gps_time_dep_t) + sizeof(u8) + sizeof(u8), offset_of_tgd_in_msg_group_delay_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_a_t, isc_l1ca ) == 0 + sizeof(gps_time_dep_t) + sizeof(u8) + sizeof(u8) + sizeof(s16), offset_of_isc_l1ca_in_msg_group_delay_dep_a_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_a_t, isc_l2c ) == 0 + sizeof(gps_time_dep_t) + sizeof(u8) + sizeof(u8) + sizeof(s16) + sizeof(s16), offset_of_isc_l2c_in_msg_group_delay_dep_a_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_GROUP_DELAY_DEP_B(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_b_t, t_op ) == 0, offset_of_t_op_in_msg_group_delay_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_b_t, sid ) == 0 + sizeof(gps_time_sec_t), offset_of_sid_in_msg_group_delay_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_b_t, valid ) == 0 + sizeof(gps_time_sec_t) + sizeof(gnss_signal_dep_t), offset_of_valid_in_msg_group_delay_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_b_t, tgd ) == 0 + sizeof(gps_time_sec_t) + sizeof(gnss_signal_dep_t) + sizeof(u8), offset_of_tgd_in_msg_group_delay_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_b_t, isc_l1ca ) == 0 + sizeof(gps_time_sec_t) + sizeof(gnss_signal_dep_t) + sizeof(u8) + sizeof(s16), offset_of_isc_l1ca_in_msg_group_delay_dep_b_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_dep_b_t, isc_l2c ) == 0 + sizeof(gps_time_sec_t) + sizeof(gnss_signal_dep_t) + sizeof(u8) + sizeof(s16) + sizeof(s16), offset_of_isc_l2c_in_msg_group_delay_dep_b_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_GROUP_DELAY(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_t, t_op ) == 0, offset_of_t_op_in_msg_group_delay_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_t, sid ) == 0 + sizeof(gps_time_sec_t), offset_of_sid_in_msg_group_delay_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_t, valid ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t), offset_of_valid_in_msg_group_delay_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_t, tgd ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8), offset_of_tgd_in_msg_group_delay_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_t, isc_l1ca ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(s16), offset_of_isc_l1ca_in_msg_group_delay_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_group_delay_t, isc_l2c ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(s16) + sizeof(s16), offset_of_isc_l2c_in_msg_group_delay_t_is_incorrect)
}

static inline void static_asserts_for_module_AlmanacCommonContent(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_t, sid ) == 0, offset_of_sid_in_almanac_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_t, toa ) == 0 + sizeof(sbp_gnss_signal_t), offset_of_toa_in_almanac_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_t, ura ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t), offset_of_ura_in_almanac_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_t, fit_interval ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t) + sizeof(double), offset_of_fit_interval_in_almanac_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_t, valid ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(u32), offset_of_valid_in_almanac_common_content_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_t, health_bits ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(u32) + sizeof(u8), offset_of_health_bits_in_almanac_common_content_t_is_incorrect)
}

static inline void static_asserts_for_module_AlmanacCommonContentDep(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_dep_t, sid ) == 0, offset_of_sid_in_almanac_common_content_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_dep_t, toa ) == 0 + sizeof(gnss_signal_dep_t), offset_of_toa_in_almanac_common_content_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_dep_t, ura ) == 0 + sizeof(gnss_signal_dep_t) + sizeof(gps_time_sec_t), offset_of_ura_in_almanac_common_content_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_dep_t, fit_interval ) == 0 + sizeof(gnss_signal_dep_t) + sizeof(gps_time_sec_t) + sizeof(double), offset_of_fit_interval_in_almanac_common_content_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_dep_t, valid ) == 0 + sizeof(gnss_signal_dep_t) + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(u32), offset_of_valid_in_almanac_common_content_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(almanac_common_content_dep_t, health_bits ) == 0 + sizeof(gnss_signal_dep_t) + sizeof(gps_time_sec_t) + sizeof(double) + sizeof(u32) + sizeof(u8), offset_of_health_bits_in_almanac_common_content_dep_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_ALMANAC_GPS_DEP(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, common ) == 0, offset_of_common_in_msg_almanac_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, m0 ) == 0 + sizeof(almanac_common_content_dep_t), offset_of_m0_in_msg_almanac_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, ecc ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double), offset_of_ecc_in_msg_almanac_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, sqrta ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_almanac_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, omega0 ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_almanac_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, omegadot ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_almanac_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, w ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_almanac_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, inc ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_almanac_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, af0 ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_almanac_gps_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_dep_t, af1 ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_almanac_gps_dep_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_ALMANAC_GPS(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, common ) == 0, offset_of_common_in_msg_almanac_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, m0 ) == 0 + sizeof(almanac_common_content_t), offset_of_m0_in_msg_almanac_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, ecc ) == 0 + sizeof(almanac_common_content_t) + sizeof(double), offset_of_ecc_in_msg_almanac_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, sqrta ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double), offset_of_sqrta_in_msg_almanac_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, omega0 ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega0_in_msg_almanac_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, omegadot ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omegadot_in_msg_almanac_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, w ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_w_in_msg_almanac_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, inc ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_inc_in_msg_almanac_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, af0 ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af0_in_msg_almanac_gps_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_gps_t, af1 ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_af1_in_msg_almanac_gps_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_ALMANAC_GLO_DEP(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_dep_t, common ) == 0, offset_of_common_in_msg_almanac_glo_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_dep_t, lambda_na ) == 0 + sizeof(almanac_common_content_dep_t), offset_of_lambda_na_in_msg_almanac_glo_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_dep_t, t_lambda_na ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double), offset_of_t_lambda_na_in_msg_almanac_glo_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_dep_t, i ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double), offset_of_i_in_msg_almanac_glo_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_dep_t, t ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_t_in_msg_almanac_glo_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_dep_t, t_dot ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_t_dot_in_msg_almanac_glo_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_dep_t, epsilon ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_epsilon_in_msg_almanac_glo_dep_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_dep_t, omega ) == 0 + sizeof(almanac_common_content_dep_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega_in_msg_almanac_glo_dep_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_ALMANAC_GLO(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_t, common ) == 0, offset_of_common_in_msg_almanac_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_t, lambda_na ) == 0 + sizeof(almanac_common_content_t), offset_of_lambda_na_in_msg_almanac_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_t, t_lambda_na ) == 0 + sizeof(almanac_common_content_t) + sizeof(double), offset_of_t_lambda_na_in_msg_almanac_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_t, i ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double), offset_of_i_in_msg_almanac_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_t, t ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_t_in_msg_almanac_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_t, t_dot ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_t_dot_in_msg_almanac_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_t, epsilon ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_epsilon_in_msg_almanac_glo_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_almanac_glo_t, omega ) == 0 + sizeof(almanac_common_content_t) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double) + sizeof(double), offset_of_omega_in_msg_almanac_glo_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_GLO_BIASES(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_glo_biases_t, mask ) == 0, offset_of_mask_in_msg_glo_biases_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_glo_biases_t, l1ca_bias ) == 0 + sizeof(u8), offset_of_l1ca_bias_in_msg_glo_biases_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_glo_biases_t, l1p_bias ) == 0 + sizeof(u8) + sizeof(s16), offset_of_l1p_bias_in_msg_glo_biases_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_glo_biases_t, l2ca_bias ) == 0 + sizeof(u8) + sizeof(s16) + sizeof(s16), offset_of_l2ca_bias_in_msg_glo_biases_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_glo_biases_t, l2p_bias ) == 0 + sizeof(u8) + sizeof(s16) + sizeof(s16) + sizeof(s16), offset_of_l2p_bias_in_msg_glo_biases_t_is_incorrect)
}

static inline void static_asserts_for_module_SvAzEl(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sv_az_el_t, sid ) == 0, offset_of_sid_in_sv_az_el_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sv_az_el_t, az ) == 0 + sizeof(sbp_gnss_signal_t), offset_of_az_in_sv_az_el_t_is_incorrect)
SBP_STATIC_ASSERT(SBP_OFFSET_OF(sv_az_el_t, el ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(u8), offset_of_el_in_sv_az_el_t_is_incorrect)
}

static inline void static_asserts_for_module_MSG_SV_AZ_EL(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_sv_az_el_t, azel ) == 0, offset_of_azel_in_msg_sv_az_el_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_OSR(void) {
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_osr_t, header ) == 0, offset_of_header_in_msg_osr_t_is_incorrect)
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_osr_t, obs ) == 0 + sizeof(observation_header_t), offset_of_obs_in_msg_osr_t_is_incorrect)
#endif
}


SBP_PACK_END

#endif /* LIBSBP_OBSERVATION_MESSAGES_H */
