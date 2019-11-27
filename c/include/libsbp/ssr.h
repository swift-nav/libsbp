/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup ssr Ssr
 *
 * * Precise State Space Representation (SSR) corrections format
 * \{ */

#ifndef LIBSBP_SSR_MESSAGES_H
#define LIBSBP_SSR_MESSAGES_H

#include "common.h"
#include "gnss.h"

SBP_PACK_START


/** SSR code biases corrections for a particular satellite.
 *
 * Code biases are to be added to pseudorange.
 * The corrections conform with typical RTCMv3 MT1059 and 1065.
 */
typedef struct SBP_ATTR_PACKED {
  u8 code;     /**< Signal constellation, band and code */
  s16 value;    /**< Code bias value [0.01 m] */
} code_biases_content_t;


/** SSR phase biases corrections for a particular satellite.
 *
 * Phase biases are to be added to carrier phase measurements.
 * The corrections conform with typical RTCMv3 MT1059 and 1065.
 */
typedef struct SBP_ATTR_PACKED {
  u8 code;                          /**< Signal constellation, band and code */
  u8 integer_indicator;             /**< Indicator for integer property */
  u8 widelane_integer_indicator;    /**< Indicator for two groups of Wide-Lane(s) integer property */
  u8 discontinuity_counter;         /**< Signal phase discontinuity counter.
Increased for every discontinuity in phase.
 */
  s32 bias;                          /**< Phase bias for specified signal [0.1 mm] */
} phase_biases_content_t;


/** Header for MSG_SSR_STEC_CORRECTION message
 *
 * A full set of STEC information will likely span multiple SBP
 * messages, since SBP message a limited to 255 bytes.  The header
 * is used to tie multiple SBP messages into a sequence.
 */
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  u8 num_msgs;           /**< Number of messages in the dataset */
  u8 seq_num;            /**< Position of this message in the dataset */
  u8 update_interval;    /**< Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
  u8 iod_atmo;           /**< IOD of the SSR atmospheric correction
 */
} stec_header_t;


/** Header for MSG_SSR_GRIDDED_CORRECTION
 *
 * The 3GPP message contains nested variable length arrays
 * which are not suppported in SBP, so each grid point will
 * be identified by the index.
 */
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;                       /**< GNSS reference time of the correction */
  u16 num_msgs;                   /**< Number of messages in the dataset */
  u16 seq_num;                    /**< Position of this message in the dataset */
  u8 update_interval;            /**< Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
  u8 iod_atmo;                   /**< IOD of the SSR atmospheric correction
 */
  u8 tropo_quality_indicator;    /**< Quality of the troposphere data. Encoded following RTCM DF389
specifcation in units of m.
 */
} gridded_correction_header_t;


/** None
 *
* STEC polynomial for the given satellite.
 */
typedef struct SBP_ATTR_PACKED {
  sv_id_t sv_id;                     /**< Unique space vehicle identifier */
  u8 stec_quality_indicator;    /**< Quality of the STEC data. Encoded following RTCM DF389 specifcation
but in units of TECU instead of m.
 */
  s16 stec_coeff[4];             /**< Coefficents of the STEC polynomial in the order of C00, C01, C10, C11
 [C00 = 0.05 TECU, others = 0.02 TECU/deg] */
} stec_sat_element_t;


/** None
 *
 * Troposphere vertical delays at the grid point.
 */
typedef struct SBP_ATTR_PACKED {
  s16 hydro;    /**< Hydrostatic vertical delay [4 mm (add 2.3 m to get actual vertical hydro delay)] */
  s8 wet;      /**< Wet vertical delay [4 mm (add 0.252 m to get actual vertical wet delay)] */
} tropospheric_delay_correction_no_std_t;


/** None
 *
 * Troposphere vertical delays (mean and standard deviation) at the grid
 * point.
 */
typedef struct SBP_ATTR_PACKED {
  s16 hydro;     /**< Hydrostatic vertical delay [4 mm (add 2.3 m to get actual vertical hydro delay)] */
  s8 wet;       /**< Wet vertical delay [4 mm (add 0.252 m to get actual vertical wet delay)] */
  u8 stddev;    /**< stddev [modified DF389 scale; class is upper 3 bits, value is lower 5
stddev <= (3^class * (1 + value/16) - 1) mm
] */
} tropospheric_delay_correction_t;


/** None
 *
* STEC residual for the given satellite at the grid point.
 */
typedef struct SBP_ATTR_PACKED {
  sv_id_t sv_id;       /**< space vehicle identifier */
  s16 residual;    /**< STEC residual [0.04 TECU] */
} stec_residual_no_std_t;


/** None
 *
 * STEC residual (mean and standard deviation) for the given satellite
 * at the grid point,
 */
typedef struct SBP_ATTR_PACKED {
  sv_id_t sv_id;       /**< space vehicle identifier */
  s16 residual;    /**< STEC residual [0.04 TECU] */
  u8 stddev;      /**< stddev [modified DF389 scale; class is upper 3 bits, value is lower 5
stddev <= (3^class * (1 + value/16) - 1) * 10 TECU
] */
} stec_residual_t;


/** Correction data for a single grid point.
 *
 * Contains one tropo delay, plus STEC residuals for each satellite at the
 * grid point.
 */
typedef struct SBP_ATTR_PACKED {
  u16 index;                     /**< Index of the grid point */
  tropospheric_delay_correction_no_std_t tropo_delay_correction;    /**< Wet and hydrostatic vertical delays */
  stec_residual_no_std_t stec_residuals[0];         /**< STEC residuals for each satellite */
} grid_element_no_std_t;


/** Correction data for a single grid point.
 *
 * Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
 * stddev) for each satellite at the grid point.
 */
typedef struct SBP_ATTR_PACKED {
  u16 index;                     /**< Index of the grid point */
  tropospheric_delay_correction_t tropo_delay_correction;    /**< Wet and hydrostatic vertical delays (mean, stddev) */
  stec_residual_t stec_residuals[0];         /**< STEC residuals for each satellite (mean, stddev) */
} grid_element_t;


/** Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
 *
 * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
 * Also includes an RLE encoded validity list.
 */
typedef struct SBP_ATTR_PACKED {
  u8 region_size_inverse;    /**< region_size (deg) = 10 / region_size_inverse
0 is an invalid value.
 [inverse degrees] */
  u16 area_width;             /**< grid height (deg) = grid idth (deg) = area_width / region_size
0 is an invalid value.
 */
  u16 lat_nw_corner_enc;      /**< North-West corner latitdue (deg) = region_size * lat_nw_corner_enc - 90 */
  u16 lon_nw_corner_enc;      /**< North-West corner longtitude (deg) = region_size * lon_nw_corner_enc - 180 */
  u8 num_msgs;               /**< Number of messages in the dataset */
  u8 seq_num;                /**< Postion of this message in the dataset */
} grid_definition_header_t;


/** Precise orbit and clock correction
 *
 * The precise orbit and clock correction message is
 * to be applied as a delta correction to broadcast
 * ephemeris and is typically an equivalent to the 1060
 * and 1066 RTCM message types
 */
#define SBP_MSG_SSR_ORBIT_CLOCK               0x05DD
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration
 */
  u32 iod;                /**< Issue of broadcast ephemeris data or IODCRC (Beidou) */
  s32 radial;             /**< Orbit radial delta correction [0.1 mm] */
  s32 along;              /**< Orbit along delta correction [0.4 mm] */
  s32 cross;              /**< Orbit along delta correction [0.4 mm] */
  s32 dot_radial;         /**< Velocity of orbit radial delta correction [0.001 mm/s] */
  s32 dot_along;          /**< Velocity of orbit along delta correction [0.004 mm/s] */
  s32 dot_cross;          /**< Velocity of orbit cross delta correction [0.004 mm/s] */
  s32 c0;                 /**< C0 polynomial coefficient for correction of broadcast satellite clock [0.1 mm] */
  s32 c1;                 /**< C1 polynomial coefficient for correction of broadcast satellite clock [0.001 mm/s] */
  s32 c2;                 /**< C2 polynomial coefficient for correction of broadcast satellite clock [0.00002 mm/s^-2] */
} msg_ssr_orbit_clock_t;


/** Precise orbit and clock correction
 *
 * The precise orbit and clock correction message is
 * to be applied as a delta correction to broadcast
 * ephemeris and is typically an equivalent to the 1060
 * and 1066 RTCM message types
 */
#define SBP_MSG_SSR_ORBIT_CLOCK_DEP_A         0x05DC
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration
 */
  u8 iod;                /**< Issue of broadcast ephemeris data */
  s32 radial;             /**< Orbit radial delta correction [0.1 mm] */
  s32 along;              /**< Orbit along delta correction [0.4 mm] */
  s32 cross;              /**< Orbit along delta correction [0.4 mm] */
  s32 dot_radial;         /**< Velocity of orbit radial delta correction [0.001 mm/s] */
  s32 dot_along;          /**< Velocity of orbit along delta correction [0.004 mm/s] */
  s32 dot_cross;          /**< Velocity of orbit cross delta correction [0.004 mm/s] */
  s32 c0;                 /**< C0 polynomial coefficient for correction of broadcast satellite clock [0.1 mm] */
  s32 c1;                 /**< C1 polynomial coefficient for correction of broadcast satellite clock [0.001 mm/s] */
  s32 c2;                 /**< C2 polynomial coefficient for correction of broadcast satellite clock [0.00002 mm/s^-2] */
} msg_ssr_orbit_clock_dep_a_t;


/** Precise code biases correction
 *
 * The precise code biases message is to be added
 * to the pseudorange of the corresponding signal
 * to get corrected pseudorange. It is typically
 * an equivalent to the 1059 and 1065 RTCM message types
 */
#define SBP_MSG_SSR_CODE_BIASES               0x05E1
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration
 */
  code_biases_content_t biases[0];          /**< Code biases for the different satellite signals */
} msg_ssr_code_biases_t;


/** Precise phase biases correction
 *
 * The precise phase biases message contains the biases
 * to be added to the carrier phase of the corresponding
 * signal to get corrected carrier phase measurement, as
 * well as the satellite yaw angle to be applied to compute
 * the phase wind-up correction.
 * It is typically an equivalent to the 1265 RTCM message types
 */
#define SBP_MSG_SSR_PHASE_BIASES              0x05E6
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration
 */
  u8 dispersive_bias;    /**< Indicator for the dispersive phase biases property.
 */
  u8 mw_consistency;     /**< Consistency indicator for Melbourne-Wubbena linear combinations
 */
  u16 yaw;                /**< Satellite yaw angle [1 / 256 semi-circle] */
  s8 yaw_rate;           /**< Satellite yaw angle rate [1 / 8192 semi-circle / s] */
  phase_biases_content_t biases[0];          /**< Phase biases corrections for a
satellite being tracked.
 */
} msg_ssr_phase_biases_t;


/** Slant Total Electron Content
 *
 * The STEC per space vehicle, given as polynomial approximation for
 * a given grid.  This should be combined with MSG_SSR_GRIDDED_CORRECTION
 * message to get the state space representation of the atmospheric
 * delay. It is typically equivalent to the QZSS CLAS Sub Type 8 messages
 */
#define SBP_MSG_SSR_STEC_CORRECTION           0x05EB
typedef struct SBP_ATTR_PACKED {
  stec_header_t header;           /**< Header of a STEC message */
  stec_sat_element_t stec_sat_list[0]; /**< Array of STEC information for each space vehicle */
} msg_ssr_stec_correction_t;


/** Gridded troposphere and STEC residuals
 *
 * This message was deprecated when variances (stddev)
 * were added.
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD 0x05F0
typedef struct SBP_ATTR_PACKED {
  gridded_correction_header_t header;     /**< Header of a Gridded Correction message */
  grid_element_no_std_t element;    /**< Tropo and STEC residuals for the given grid point */
} msg_ssr_gridded_correction_no_std_t;


/** Gridded troposphere and STEC residuals
 *
 * STEC residuals are per space vehicle, tropo is not.
 * It is typically equivalent to the QZSS CLAS Sub Type 9 messages
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION        0x05FA
typedef struct SBP_ATTR_PACKED {
  gridded_correction_header_t header;     /**< Header of a Gridded Correction message */
  grid_element_t element;    /**< Tropo and STEC residuals for the given grid point (mean
and standard deviation)
 */
} msg_ssr_gridded_correction_t;


/** Definition of the grid for STEC and tropo messages
 *
 * Based on the 3GPP proposal R2-1906781 which is in turn based on
 * OMA-LPPe-ValidityArea from OMA-TS-LPPe-V2_0-20141202-C
 */
#define SBP_MSG_SSR_GRID_DEFINITION           0x05F5
typedef struct SBP_ATTR_PACKED {
  grid_definition_header_t header;      /**< Header of a Gridded Correction message */
  u8 rle_list[0]; /**< Run Length Encode list of quadrants that contain valid data.
The spec describes the encoding scheme in detail, but
essentially the index of the quadrants that contain transitions between
valid and invalid (and vice versa) are encoded as u8 integers.
 */
} msg_ssr_grid_definition_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_SSR_MESSAGES_H */