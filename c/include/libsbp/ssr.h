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
 * The corrections are conform with typical RTCMv3 MT1059 and 1065.
 */
typedef struct SBP_ATTR_PACKED {
  u8 code;     /**< Signal constellation, band and code */
  s16 value;    /**< Code bias value [0.01 m] */
} code_biases_content_t;


/** SSR phase biases corrections for a particular satellite.
 *
 * Phase biases are to be added to carrier phase measurements.
 * The corrections are conform with typical RTCMv3 MT1059 and 1065.
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
  sbp_gps_time_t time;                   /**< GNSS time of the STEC data */
  u8 num_msgs;               /**< Number of messages in the dataset */
  u8 seq_num;                /**< Position of this message in the dataset */
  u16 ssr_update_interval;    /**< update interval in seconds [seconds] */
  u8 iod_ssr;                /**< range 0 - 15 */
} stec_header_t;


/** Header for MSG_SSR_GRIDDED_CORRECTION
 *
 * The 3GPP message contains nested variable length arrays
 * which are not suppported in SBP, so each grid point will
 * be identified by the index.
 */
typedef struct SBP_ATTR_PACKED {
  sbp_gps_time_t time;                   /**< GNSS time of the STEC data */
  u16 num_msgs;               /**< Number of messages in the dataset */
  u16 seq_num;                /**< Position of this message in the dataset */
  u16 ssr_update_interval;    /**< update interval in seconds [seconds] */
  u8 iod_ssr;                /**< range 0 - 15 */
  u8 tropo_quality;          /**< troposphere quality indicator [encoded value - see spec for details] */
} gridded_correction_header_t;


/** None
 *
* STEC for the given satellite.
 */
typedef struct SBP_ATTR_PACKED {
  sv_id_t sv_id;                     /**< Unique space vehicle identifier */
  u8 stec_quality_indicator;    /**< quality of STEC data [encoded value - see spec for details] */
  s16 stec_coeff[4];             /**< coefficents of the STEC polynomial */
} stec_sat_element_t;


/** troposphere delay correction
 *
 * Contains wet vertical and hydrostatic vertical delay
 */
typedef struct SBP_ATTR_PACKED {
  s16 hydro;    /**< hydrostatic vertical delay [0.4 mm (add 2.3 m to get actual vert hydro delay)] */
  s8 wet;      /**< wet vertical delay [0.4 mm (add 0.252 m to get actual vert wet delay)] */
} tropospheric_delay_correction_t;


/** None
 *
* STEC residual
 */
typedef struct SBP_ATTR_PACKED {
  sv_id_t sv_id;       /**< space vehicle identifier */
  s16 residual;    /**< STEC residual [0.04 TECU] */
} stec_residual_t;


/** Grid datum for troposphere and STEC residuals
 *
 * Contains one tropo datum, plus STEC residuals for each space
 * vehicle
 */
typedef struct SBP_ATTR_PACKED {
  u16 index;                     /**< index of the grid point */
  tropospheric_delay_correction_t tropo_delay_correction;    /**< Wet and Hydrostatic Vertical Delay */
  stec_residual_t STEC_residuals[0];         /**< STEC Residual for the given space vehicle */
} grid_element_t;


/** Defines the grid for STEC and tropo grid messages
 *
 * Defines the grid for STEC and tropo grid messages.
 * Also includes an RLE encoded validity list.
 */
typedef struct SBP_ATTR_PACKED {
  u8 region_size_inverse;    /**< inverse of region size [coded value - see spec] */
  u16 area_width;             /**< area width; see spec for details [coded value - 0 means not present (Swift convention)] */
  u16 lat_nw_corner_enc;      /**< encoded latitude of the northwest corner of the grid */
  u16 lon_nw_corner_enc;      /**< encoded longitude of the northwest corner of the grid */
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
#define SBP_MSG_SSR_ORBIT_CLOCK        0x05DD
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections [s] */
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
#define SBP_MSG_SSR_ORBIT_CLOCK_DEP_A  0x05DC
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections [s] */
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
#define SBP_MSG_SSR_CODE_BIASES        0x05E1
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections [s] */
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
#define SBP_MSG_SSR_PHASE_BIASES       0x05E6
typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  sbp_gnss_signal_t sid;                /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections [s] */
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
 * a given grid.  This should be combined with SSR-GriddedCorrection
 * message to get the state space representation of the atmospheric
 * delay.
 */
#define SBP_MSG_SSR_STEC_CORRECTION    0x05EB
typedef struct SBP_ATTR_PACKED {
  stec_header_t header;           /**< Header of a STEC message */
  stec_sat_element_t stec_sat_list[0]; /**< Array of STEC information for each space vehicle */
} msg_ssr_stec_correction_t;


/** Gridded troposphere and STEC residuals
 *
 * STEC residuals are per space vehicle, tropo is not.
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION 0x05F0
typedef struct SBP_ATTR_PACKED {
  gridded_correction_header_t header;     /**< Header of a Gridded Correction message */
  grid_element_t element;    /**< Tropo and STEC residuals for the given grid point */
} msg_ssr_gridded_correction_t;


/** None
 *
* Definition of the grid for STEC and tropo messages
 */
#define SBP_MSG_SSR_GRID_DEFINITION    0x05F5
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