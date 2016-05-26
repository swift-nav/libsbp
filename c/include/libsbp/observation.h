/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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
#include "gnss_signal.h"


/** Millisecond-accurate GPS time
 *
 * A wire-appropriate GPS time, defined as the number of
 * milliseconds since beginning of the week on the Saturday/Sunday
 * transition.
 */
typedef struct __attribute__((packed)) {
  u32 tow;    /**< Milliseconds since start of GPS week [ms] */
  u16 wn;     /**< GPS week number [week] */
} obs_gps_time_t;


/** GPS carrier phase measurement.
 *
 * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles.  This phase has the 
 * same sign as the pseudorange.
 */
typedef struct __attribute__((packed)) {
  s32 i;    /**< Carrier phase whole cycles [cycles] */
  u8 f;    /**< Carrier phase fractional part [cycles / 256] */
} carrier_phase_t;


/** Header for observation message.
 *
* Header of a GPS observation message.
 */
typedef struct __attribute__((packed)) {
  obs_gps_time_t t;        /**< GPS time of this observation */
  u8 n_obs;    /**< Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)
 */
} observation_header_t;


/** GPS observations for a particular satellite signal.
 *
 * Pseudorange and carrier phase observation for a satellite being
 * tracked. The observations should be interoperable with 3rd party 
 * receivers and conform with typical RTCMv3 GNSS observations. 
 */
typedef struct __attribute__((packed)) {
  u32 P;       /**< Pseudorange observation [2 cm] */
  carrier_phase_t L;       /**< Carrier phase observation with typical sign convention. [cycles] */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz * 4] */
  u16 lock;    /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
  sbp_gnss_signal_t sid;     /**< GNSS signal identifier */
} packed_obs_content_t;


/** GPS satellite observations
 *
 * The GPS observations message reports all the raw pseudorange and
 * carrier phase observations for the satellites being tracked by
 * the device. Carrier phase observation here is represented as a
 * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles).  The observations 
 * should be interoperable with 3rd party receivers and conform 
 * with typical RTCMv3 GNSS observations. 
 */
#define SBP_MSG_OBS             0x0049
typedef struct __attribute__((packed)) {
  observation_header_t header;    /**< Header of a GPS observation message */
  packed_obs_content_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
} msg_obs_t;


/** Base station position
 *
 * The base station position message is the position reported by
 * the base station itself. It is used for pseudo-absolute RTK
 * positioning, and is required to be a high-accuracy surveyed
 * location of the base station. Any error here will result in an
 * error in the pseudo-absolute position output.
 */
#define SBP_MSG_BASE_POS_LLH    0x0044
typedef struct __attribute__((packed)) {
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
#define SBP_MSG_BASE_POS_ECEF   0x0048
typedef struct __attribute__((packed)) {
  double x;    /**< ECEF X coodinate [m] */
  double y;    /**< ECEF Y coordinate [m] */
  double z;    /**< ECEF Z coordinate [m] */
} msg_base_pos_ecef_t;


/** Satellite broadcast ephemeris
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS       0x0080
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [radians] */
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
  sbp_gnss_signal_t sid;         /**< GNSS signal identifier */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
  u32 reserved;    /**< Reserved field */
} msg_ephemeris_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_EPHEMERIS_DEP_A 0x001A
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [radians] */
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
#define SBP_MSG_EPHEMERIS_DEP_B 0x0046
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [radians] */
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
#define SBP_MSG_EPHEMERIS_DEP_C 0x0047
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [radians] */
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
  sbp_gnss_signal_t sid;         /**< GNSS signal identifier */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
  u32 reserved;    /**< Reserved field */
} msg_ephemeris_dep_c_t;


/** GPS carrier phase measurement.
 *
 * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles. This has the opposite
 * sign convention than a typical GPS receiver and the phase has
 * the opposite sign as the pseudorange.
 */
typedef struct __attribute__((packed)) {
  s32 i;    /**< Carrier phase whole cycles [cycles] */
  u8 f;    /**< Carrier phase fractional part [cycles / 256] */
} carrier_phase_dep_a_t;


/** Deprecated
 *
* Deprecated.
 */
typedef struct __attribute__((packed)) {
  u32 P;       /**< Pseudorange observation [cm] */
  carrier_phase_dep_a_t L;       /**< Carrier phase observation with opposite sign from typical convention */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz * 4] */
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
typedef struct __attribute__((packed)) {
  u32 P;       /**< Pseudorange observation [cm] */
  carrier_phase_dep_a_t L;       /**< Carrier phase observation with opposite sign from typical convention. */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz * 4] */
  u16 lock;    /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
  sbp_gnss_signal_t sid;     /**< GNSS signal identifier */
} packed_obs_content_dep_b_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_OBS_DEP_A       0x0045
typedef struct __attribute__((packed)) {
  observation_header_t header;    /**< Header of a GPS observation message */
  packed_obs_content_dep_a_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
} msg_obs_dep_a_t;


/** Deprecated
 *
 * This observation message has been deprecated in favor of 
 * observations that are more interoperable. This message
 * should be used for observations referenced to 
 * a nominal pseudorange which are not interoperable with
 * most 3rd party GNSS receievers or typical RTCMv3 
 * observations.
 */
#define SBP_MSG_OBS_DEP_B       0x0043
typedef struct __attribute__((packed)) {
  observation_header_t header;    /**< Header of a GPS observation message */
  packed_obs_content_dep_b_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
} msg_obs_dep_b_t;


/** \} */

#endif /* LIBSBP_OBSERVATION_MESSAGES_H */