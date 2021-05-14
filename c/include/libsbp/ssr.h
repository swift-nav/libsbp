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
 

/** Header for the MSG_SSR_STEC_CORRECTION message.
 *
 * A full set of STEC information will likely span multiple SBP
 * messages, since SBP message a limited to 255 bytes.  The header
 * is used to tie multiple SBP messages into a sequence.
 */

typedef struct SBP_ATTR_PACKED {
  u16 tile_set_id;        /**< Unique identifier of the tile set this tile belongs to. */
  u16 tile_id;            /**< Unique identifier of this tile in the tile set. */
  gps_time_sec_t time;               /**< GNSS reference time of the correction */
  u8 num_msgs;           /**< Number of messages in the dataset */
  u8 seq_num;            /**< Position of this message in the dataset */
  u8 update_interval;    /**< Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
  u8 iod_atmo;           /**< IOD of the SSR atmospheric correction
 */
} stec_header_t;
 

/** Header for the MSG_SSR_GRIDDED_CORRECTION message.
 *
 * The LPP message contains nested variable length arrays
 * which are not suppported in SBP, so each grid point will
 * be identified by the index.
 */

typedef struct SBP_ATTR_PACKED {
  u16 tile_set_id;                /**< Unique identifier of the tile set this tile belongs to. */
  u16 tile_id;                    /**< Unique identifier of this tile in the tile set. */
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
 [C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2] */
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
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  stec_residual_no_std_t stec_residuals[0];         /**< STEC residuals for each satellite */
#endif
} grid_element_no_std_t;
#define GRID_ELEMENT_NO_STD_T_GET_STEC_RESIDUALS_PTR(msg) (( stec_residual_no_std_t *)(msg+1))
#define GRID_ELEMENT_NO_STD_T_GET_STEC_RESIDUALS_CPTR(msg) ((const stec_residual_no_std_t *)(msg+1))
 

/** Correction data for a single grid point.
 *
 * Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
 * stddev) for each satellite at the grid point.
 */

typedef struct SBP_ATTR_PACKED {
  u16 index;                     /**< Index of the grid point */
  tropospheric_delay_correction_t tropo_delay_correction;    /**< Wet and hydrostatic vertical delays (mean, stddev) */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  stec_residual_t stec_residuals[0];         /**< STEC residuals for each satellite (mean, stddev) */
#endif
} grid_element_t;
#define GRID_ELEMENT_T_GET_STEC_RESIDUALS_PTR(msg) (( stec_residual_t *)(msg+1))
#define GRID_ELEMENT_T_GET_STEC_RESIDUALS_CPTR(msg) ((const stec_residual_t *)(msg+1))
 

/** Precise orbit and clock correction
 *
 * The precise orbit and clock correction message is
 * to be applied as a delta correction to broadcast
 * ephemeris and is typically an equivalent to the 1060
 * and 1066 RTCM message types
 */
#define SBP_MSG_SSR_ORBIT_CLOCK                     0x05DD

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
 

/** Precise code biases correction
 *
 * The precise code biases message is to be added
 * to the pseudorange of the corresponding signal
 * to get corrected pseudorange. It is typically
 * an equivalent to the 1059 and 1065 RTCM message types
 */
#define SBP_MSG_SSR_CODE_BIASES                     0x05E1

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
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  code_biases_content_t biases[0];          /**< Code biases for the different satellite signals */
#endif
} msg_ssr_code_biases_t;
#define MSG_SSR_CODE_BIASES_T_GET_BIASES_PTR(msg) (( code_biases_content_t *)(msg+1))
#define MSG_SSR_CODE_BIASES_T_GET_BIASES_CPTR(msg) ((const code_biases_content_t *)(msg+1))
 

/** Precise phase biases correction
 *
 * The precise phase biases message contains the biases
 * to be added to the carrier phase of the corresponding
 * signal to get corrected carrier phase measurement, as
 * well as the satellite yaw angle to be applied to compute
 * the phase wind-up correction.
 * It is typically an equivalent to the 1265 RTCM message types
 */
#define SBP_MSG_SSR_PHASE_BIASES                    0x05E6

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
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  phase_biases_content_t biases[0];          /**< Phase biases corrections for a
satellite being tracked.
 */
#endif
} msg_ssr_phase_biases_t;
#define MSG_SSR_PHASE_BIASES_T_GET_BIASES_PTR(msg) (( phase_biases_content_t *)(msg+1))
#define MSG_SSR_PHASE_BIASES_T_GET_BIASES_CPTR(msg) ((const phase_biases_content_t *)(msg+1))
 

/** STEC correction polynomial coeffcients.
 *
 * The Slant Total Electron Content per space vehicle, given as polynomial
 * approximation for a given tile. This should be combined with the
 * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
 * of the atmospheric delay.
 * 
 * It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
 */
#define SBP_MSG_SSR_STEC_CORRECTION                 0x05FB

typedef struct SBP_ATTR_PACKED {
  stec_header_t header;           /**< Header of a STEC polynomial coeffcient message. */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  stec_sat_element_t stec_sat_list[0]; /**< Array of STEC polynomial coeffcients for each space vehicle. */
#endif
} msg_ssr_stec_correction_t;
#define MSG_SSR_STEC_CORRECTION_T_GET_STEC_SAT_LIST_PTR(msg) (( stec_sat_element_t *)(msg+1))
#define MSG_SSR_STEC_CORRECTION_T_GET_STEC_SAT_LIST_CPTR(msg) ((const stec_sat_element_t *)(msg+1))
 

/** Gridded troposphere and STEC correction residuals.
 *
 * STEC residuals are per space vehicle, troposphere is not.
 * 
 * It is typically equivalent to the QZSS CLAS Sub Type 9 messages
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION              0x05FC

typedef struct SBP_ATTR_PACKED {
  gridded_correction_header_t header;     /**< Header of a gridded correction message */
  grid_element_t element;    /**< Tropo and STEC residuals for the given grid point.
 */
} msg_ssr_gridded_correction_t;
 

/** Definition of a SSR atmospheric correction tile.

 *
 * Provides the correction point coordinates for the atmospheric correction
 * values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
 * messages.
 * 
 * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
 * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
 * correction points, not lists of points.
 */
#define SBP_MSG_SSR_TILE_DEFINITION                 0x05F6

typedef struct SBP_ATTR_PACKED {
  u16 tile_set_id;      /**< Unique identifier of the tile set this tile belongs to. */
  u16 tile_id;          /**< Unique identifier of this tile in the tile set.

See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
 */
  s16 corner_nw_lat;    /**< North-West corner correction point latitude.

The relation between the latitude X in the range [-90, 90] and
the coded number N is:

N = floor((X / 90) * 2^14)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
 [encoded degrees] */
  s16 corner_nw_lon;    /**< North-West corner correction point longtitude.

The relation between the longtitude X in the range [-180, 180]
and the coded number N is:

N = floor((X / 180) * 2^15)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
 [encoded degrees] */
  u16 spacing_lat;      /**< Spacing of the correction points in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
 [0.01 degrees] */
  u16 spacing_lon;      /**< Spacing of the correction points in the longtitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongtitude.
 [0.01 degrees] */
  u16 rows;             /**< Number of steps in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
 */
  u16 cols;             /**< Number of steps in the longtitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongtitude.
 */
  u64 bitmask;          /**< Specifies the availability of correction data at the
correction points in the array.

If a specific bit is enabled (set to 1), the correction is not
available. Only the first rows * cols bits are used, the remainder
are set to 0. If there are more then 64 correction points the
remaining corrections are always available.

Starting with the northwest corner of the array (top left on a
north oriented map) the correction points are enumerated with row
precedence - first row west to east, second row west to east,
until last row west to east - ending with the southeast corner of
the array.

See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but
note the definition of the bits is inverted.
 */
} msg_ssr_tile_definition_t;
 

#define SBP_MSG_SSR_ORBIT_CLOCK_DEP_A               0x05DC

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
 

/** Header for MSG_SSR_STEC_CORRECTION_DEP message
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
} stec_header_dep_a_t;
 

/** Header for MSG_SSR_GRIDDED_CORRECTION_DEP
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
} gridded_correction_header_dep_a_t;
 

/** Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
 *
 * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
 * Also includes an RLE encoded validity list.
 */

typedef struct SBP_ATTR_PACKED {
  u8 region_size_inverse;    /**< region_size (deg) = 10 / region_size_inverse
0 is an invalid value.
 [inverse degrees] */
  u16 area_width;             /**< grid height (deg) = grid width (deg) = area_width / region_size
0 is an invalid value.
 */
  u16 lat_nw_corner_enc;      /**< North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90 */
  u16 lon_nw_corner_enc;      /**< North-West corner longtitude (deg) = region_size * lon_nw_corner_enc - 180 */
  u8 num_msgs;               /**< Number of messages in the dataset */
  u8 seq_num;                /**< Postion of this message in the dataset */
} grid_definition_header_dep_a_t;
 

#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A           0x05EB

typedef struct SBP_ATTR_PACKED {
  stec_header_dep_a_t header;           /**< Header of a STEC message */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  stec_sat_element_t stec_sat_list[0]; /**< Array of STEC information for each space vehicle */
#endif
} msg_ssr_stec_correction_dep_a_t;
#define MSG_SSR_STEC_CORRECTION_DEP_A_T_GET_STEC_SAT_LIST_PTR(msg) (( stec_sat_element_t *)(msg+1))
#define MSG_SSR_STEC_CORRECTION_DEP_A_T_GET_STEC_SAT_LIST_CPTR(msg) ((const stec_sat_element_t *)(msg+1))
 

#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A 0x05F0

typedef struct SBP_ATTR_PACKED {
  gridded_correction_header_dep_a_t header;     /**< Header of a Gridded Correction message */
  grid_element_no_std_t element;    /**< Tropo and STEC residuals for the given grid point */
} msg_ssr_gridded_correction_no_std_dep_a_t;
 

#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A        0x05FA

typedef struct SBP_ATTR_PACKED {
  gridded_correction_header_dep_a_t header;     /**< Header of a Gridded Correction message */
  grid_element_t element;    /**< Tropo and STEC residuals for the given grid point (mean
and standard deviation)
 */
} msg_ssr_gridded_correction_dep_a_t;
 

#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A           0x05F5

typedef struct SBP_ATTR_PACKED {
  grid_definition_header_dep_a_t header;      /**< Header of a Gridded Correction message */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  u8 rle_list[0]; /**< Run Length Encode list of quadrants that contain valid data.
The spec describes the encoding scheme in detail, but
essentially the index of the quadrants that contain transitions between
valid and invalid (and vice versa) are encoded as u8 integers.
 */
#endif
} msg_ssr_grid_definition_dep_a_t;
#define MSG_SSR_GRID_DEFINITION_DEP_A_T_GET_RLE_LIST_PTR(msg) (( u8 *)(msg+1))
#define MSG_SSR_GRID_DEFINITION_DEP_A_T_GET_RLE_LIST_CPTR(msg) ((const u8 *)(msg+1))
 

/** \} */
static inline void static_asserts_for_module_CodeBiasesContent(void) {
#ifdef __cplusplus
static_assert(offsetof(code_biases_content_t, code ) == 0, "Offset of code in code_biases_content_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(code_biases_content_t, code ) == 0, offset_of_code_in_code_biases_content_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(code_biases_content_t, value ) == 0 + sizeof(u8), "Offset of value in code_biases_content_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(code_biases_content_t, value ) == 0 + sizeof(u8), offset_of_value_in_code_biases_content_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_PhaseBiasesContent(void) {
#ifdef __cplusplus
static_assert(offsetof(phase_biases_content_t, code ) == 0, "Offset of code in phase_biases_content_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(phase_biases_content_t, code ) == 0, offset_of_code_in_phase_biases_content_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(phase_biases_content_t, integer_indicator ) == 0 + sizeof(u8), "Offset of integer_indicator in phase_biases_content_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(phase_biases_content_t, integer_indicator ) == 0 + sizeof(u8), offset_of_integer_indicator_in_phase_biases_content_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(phase_biases_content_t, widelane_integer_indicator ) == 0 + sizeof(u8) + sizeof(u8), "Offset of widelane_integer_indicator in phase_biases_content_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(phase_biases_content_t, widelane_integer_indicator ) == 0 + sizeof(u8) + sizeof(u8), offset_of_widelane_integer_indicator_in_phase_biases_content_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(phase_biases_content_t, discontinuity_counter ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of discontinuity_counter in phase_biases_content_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(phase_biases_content_t, discontinuity_counter ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_discontinuity_counter_in_phase_biases_content_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(phase_biases_content_t, bias ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of bias in phase_biases_content_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(phase_biases_content_t, bias ) == 0 + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_bias_in_phase_biases_content_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_STECHeader(void) {
#ifdef __cplusplus
static_assert(offsetof(stec_header_t, tile_set_id ) == 0, "Offset of tile_set_id in stec_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_t, tile_set_id ) == 0, offset_of_tile_set_id_in_stec_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_t, tile_id ) == 0 + sizeof(u16), "Offset of tile_id in stec_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_t, tile_id ) == 0 + sizeof(u16), offset_of_tile_id_in_stec_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_t, time ) == 0 + sizeof(u16) + sizeof(u16), "Offset of time in stec_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_t, time ) == 0 + sizeof(u16) + sizeof(u16), offset_of_time_in_stec_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_t, num_msgs ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t), "Offset of num_msgs in stec_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_t, num_msgs ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t), offset_of_num_msgs_in_stec_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_t, seq_num ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u8), "Offset of seq_num in stec_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_t, seq_num ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u8), offset_of_seq_num_in_stec_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_t, update_interval ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u8) + sizeof(u8), "Offset of update_interval in stec_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_t, update_interval ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u8) + sizeof(u8), offset_of_update_interval_in_stec_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_t, iod_atmo ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of iod_atmo in stec_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_t, iod_atmo ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_iod_atmo_in_stec_header_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_GriddedCorrectionHeader(void) {
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_t, tile_set_id ) == 0, "Offset of tile_set_id in gridded_correction_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_t, tile_set_id ) == 0, offset_of_tile_set_id_in_gridded_correction_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_t, tile_id ) == 0 + sizeof(u16), "Offset of tile_id in gridded_correction_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_t, tile_id ) == 0 + sizeof(u16), offset_of_tile_id_in_gridded_correction_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_t, time ) == 0 + sizeof(u16) + sizeof(u16), "Offset of time in gridded_correction_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_t, time ) == 0 + sizeof(u16) + sizeof(u16), offset_of_time_in_gridded_correction_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_t, num_msgs ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t), "Offset of num_msgs in gridded_correction_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_t, num_msgs ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t), offset_of_num_msgs_in_gridded_correction_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_t, seq_num ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u16), "Offset of seq_num in gridded_correction_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_t, seq_num ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u16), offset_of_seq_num_in_gridded_correction_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_t, update_interval ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16), "Offset of update_interval in gridded_correction_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_t, update_interval ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16), offset_of_update_interval_in_gridded_correction_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_t, iod_atmo ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16) + sizeof(u8), "Offset of iod_atmo in gridded_correction_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_t, iod_atmo ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16) + sizeof(u8), offset_of_iod_atmo_in_gridded_correction_header_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_t, tropo_quality_indicator ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16) + sizeof(u8) + sizeof(u8), "Offset of tropo_quality_indicator in gridded_correction_header_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_t, tropo_quality_indicator ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16) + sizeof(u8) + sizeof(u8), offset_of_tropo_quality_indicator_in_gridded_correction_header_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_STECSatElement(void) {
#ifdef __cplusplus
static_assert(offsetof(stec_sat_element_t, sv_id ) == 0, "Offset of sv_id in stec_sat_element_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_sat_element_t, sv_id ) == 0, offset_of_sv_id_in_stec_sat_element_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_sat_element_t, stec_quality_indicator ) == 0 + sizeof(sv_id_t), "Offset of stec_quality_indicator in stec_sat_element_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_sat_element_t, stec_quality_indicator ) == 0 + sizeof(sv_id_t), offset_of_stec_quality_indicator_in_stec_sat_element_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_sat_element_t, stec_coeff ) == 0 + sizeof(sv_id_t) + sizeof(u8), "Offset of stec_coeff in stec_sat_element_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_sat_element_t, stec_coeff ) == 0 + sizeof(sv_id_t) + sizeof(u8), offset_of_stec_coeff_in_stec_sat_element_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_TroposphericDelayCorrectionNoStd(void) {
#ifdef __cplusplus
static_assert(offsetof(tropospheric_delay_correction_no_std_t, hydro ) == 0, "Offset of hydro in tropospheric_delay_correction_no_std_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tropospheric_delay_correction_no_std_t, hydro ) == 0, offset_of_hydro_in_tropospheric_delay_correction_no_std_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tropospheric_delay_correction_no_std_t, wet ) == 0 + sizeof(s16), "Offset of wet in tropospheric_delay_correction_no_std_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tropospheric_delay_correction_no_std_t, wet ) == 0 + sizeof(s16), offset_of_wet_in_tropospheric_delay_correction_no_std_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_TroposphericDelayCorrection(void) {
#ifdef __cplusplus
static_assert(offsetof(tropospheric_delay_correction_t, hydro ) == 0, "Offset of hydro in tropospheric_delay_correction_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tropospheric_delay_correction_t, hydro ) == 0, offset_of_hydro_in_tropospheric_delay_correction_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tropospheric_delay_correction_t, wet ) == 0 + sizeof(s16), "Offset of wet in tropospheric_delay_correction_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tropospheric_delay_correction_t, wet ) == 0 + sizeof(s16), offset_of_wet_in_tropospheric_delay_correction_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(tropospheric_delay_correction_t, stddev ) == 0 + sizeof(s16) + sizeof(s8), "Offset of stddev in tropospheric_delay_correction_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(tropospheric_delay_correction_t, stddev ) == 0 + sizeof(s16) + sizeof(s8), offset_of_stddev_in_tropospheric_delay_correction_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_STECResidualNoStd(void) {
#ifdef __cplusplus
static_assert(offsetof(stec_residual_no_std_t, sv_id ) == 0, "Offset of sv_id in stec_residual_no_std_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_residual_no_std_t, sv_id ) == 0, offset_of_sv_id_in_stec_residual_no_std_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_residual_no_std_t, residual ) == 0 + sizeof(sv_id_t), "Offset of residual in stec_residual_no_std_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_residual_no_std_t, residual ) == 0 + sizeof(sv_id_t), offset_of_residual_in_stec_residual_no_std_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_STECResidual(void) {
#ifdef __cplusplus
static_assert(offsetof(stec_residual_t, sv_id ) == 0, "Offset of sv_id in stec_residual_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_residual_t, sv_id ) == 0, offset_of_sv_id_in_stec_residual_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_residual_t, residual ) == 0 + sizeof(sv_id_t), "Offset of residual in stec_residual_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_residual_t, residual ) == 0 + sizeof(sv_id_t), offset_of_residual_in_stec_residual_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_residual_t, stddev ) == 0 + sizeof(sv_id_t) + sizeof(s16), "Offset of stddev in stec_residual_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_residual_t, stddev ) == 0 + sizeof(sv_id_t) + sizeof(s16), offset_of_stddev_in_stec_residual_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_GridElementNoStd(void) {
#ifdef __cplusplus
static_assert(offsetof(grid_element_no_std_t, index ) == 0, "Offset of index in grid_element_no_std_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_element_no_std_t, index ) == 0, offset_of_index_in_grid_element_no_std_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(grid_element_no_std_t, tropo_delay_correction ) == 0 + sizeof(u16), "Offset of tropo_delay_correction in grid_element_no_std_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_element_no_std_t, tropo_delay_correction ) == 0 + sizeof(u16), offset_of_tropo_delay_correction_in_grid_element_no_std_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(grid_element_no_std_t, stec_residuals ) == 0 + sizeof(u16) + sizeof(tropospheric_delay_correction_no_std_t), "Offset of stec_residuals in grid_element_no_std_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_element_no_std_t, stec_residuals ) == 0 + sizeof(u16) + sizeof(tropospheric_delay_correction_no_std_t), offset_of_stec_residuals_in_grid_element_no_std_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_GridElement(void) {
#ifdef __cplusplus
static_assert(offsetof(grid_element_t, index ) == 0, "Offset of index in grid_element_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_element_t, index ) == 0, offset_of_index_in_grid_element_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(grid_element_t, tropo_delay_correction ) == 0 + sizeof(u16), "Offset of tropo_delay_correction in grid_element_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_element_t, tropo_delay_correction ) == 0 + sizeof(u16), offset_of_tropo_delay_correction_in_grid_element_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(grid_element_t, stec_residuals ) == 0 + sizeof(u16) + sizeof(tropospheric_delay_correction_t), "Offset of stec_residuals in grid_element_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_element_t, stec_residuals ) == 0 + sizeof(u16) + sizeof(tropospheric_delay_correction_t), offset_of_stec_residuals_in_grid_element_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_SSR_ORBIT_CLOCK(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, time ) == 0, "Offset of time in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, time ) == 0, offset_of_time_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, sid ) == 0 + sizeof(gps_time_sec_t), "Offset of sid in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, sid ) == 0 + sizeof(gps_time_sec_t), offset_of_sid_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t), "Offset of update_interval in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t), offset_of_update_interval_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, iod_ssr ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8), "Offset of iod_ssr in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, iod_ssr ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8), offset_of_iod_ssr_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, iod ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8), "Offset of iod in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, iod ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8), offset_of_iod_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, radial ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32), "Offset of radial in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, radial ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32), offset_of_radial_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, along ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32), "Offset of along in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, along ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32), offset_of_along_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, cross ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32), "Offset of cross in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, cross ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32), offset_of_cross_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, dot_radial ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of dot_radial in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, dot_radial ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_dot_radial_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, dot_along ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of dot_along in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, dot_along ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_dot_along_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, dot_cross ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of dot_cross in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, dot_cross ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_dot_cross_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, c0 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of c0 in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, c0 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_c0_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, c1 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of c1 in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, c1 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_c1_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_t, c2 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of c2 in msg_ssr_orbit_clock_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_t, c2 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_c2_in_msg_ssr_orbit_clock_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_SSR_CODE_BIASES(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_code_biases_t, time ) == 0, "Offset of time in msg_ssr_code_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_code_biases_t, time ) == 0, offset_of_time_in_msg_ssr_code_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_code_biases_t, sid ) == 0 + sizeof(gps_time_sec_t), "Offset of sid in msg_ssr_code_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_code_biases_t, sid ) == 0 + sizeof(gps_time_sec_t), offset_of_sid_in_msg_ssr_code_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_code_biases_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t), "Offset of update_interval in msg_ssr_code_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_code_biases_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t), offset_of_update_interval_in_msg_ssr_code_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_code_biases_t, iod_ssr ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8), "Offset of iod_ssr in msg_ssr_code_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_code_biases_t, iod_ssr ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8), offset_of_iod_ssr_in_msg_ssr_code_biases_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_code_biases_t, biases ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8), "Offset of biases in msg_ssr_code_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_code_biases_t, biases ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8), offset_of_biases_in_msg_ssr_code_biases_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_SSR_PHASE_BIASES(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_phase_biases_t, time ) == 0, "Offset of time in msg_ssr_phase_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_phase_biases_t, time ) == 0, offset_of_time_in_msg_ssr_phase_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_phase_biases_t, sid ) == 0 + sizeof(gps_time_sec_t), "Offset of sid in msg_ssr_phase_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_phase_biases_t, sid ) == 0 + sizeof(gps_time_sec_t), offset_of_sid_in_msg_ssr_phase_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_phase_biases_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t), "Offset of update_interval in msg_ssr_phase_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_phase_biases_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t), offset_of_update_interval_in_msg_ssr_phase_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_phase_biases_t, iod_ssr ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8), "Offset of iod_ssr in msg_ssr_phase_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_phase_biases_t, iod_ssr ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8), offset_of_iod_ssr_in_msg_ssr_phase_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_phase_biases_t, dispersive_bias ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8), "Offset of dispersive_bias in msg_ssr_phase_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_phase_biases_t, dispersive_bias ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8), offset_of_dispersive_bias_in_msg_ssr_phase_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_phase_biases_t, mw_consistency ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of mw_consistency in msg_ssr_phase_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_phase_biases_t, mw_consistency ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_mw_consistency_in_msg_ssr_phase_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_phase_biases_t, yaw ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of yaw in msg_ssr_phase_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_phase_biases_t, yaw ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_yaw_in_msg_ssr_phase_biases_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_phase_biases_t, yaw_rate ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u16), "Offset of yaw_rate in msg_ssr_phase_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_phase_biases_t, yaw_rate ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u16), offset_of_yaw_rate_in_msg_ssr_phase_biases_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_phase_biases_t, biases ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(s8), "Offset of biases in msg_ssr_phase_biases_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_phase_biases_t, biases ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(s8), offset_of_biases_in_msg_ssr_phase_biases_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_SSR_STEC_CORRECTION(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_stec_correction_t, header ) == 0, "Offset of header in msg_ssr_stec_correction_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_stec_correction_t, header ) == 0, offset_of_header_in_msg_ssr_stec_correction_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_stec_correction_t, stec_sat_list ) == 0 + sizeof(stec_header_t), "Offset of stec_sat_list in msg_ssr_stec_correction_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_stec_correction_t, stec_sat_list ) == 0 + sizeof(stec_header_t), offset_of_stec_sat_list_in_msg_ssr_stec_correction_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_SSR_GRIDDED_CORRECTION(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_gridded_correction_t, header ) == 0, "Offset of header in msg_ssr_gridded_correction_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_gridded_correction_t, header ) == 0, offset_of_header_in_msg_ssr_gridded_correction_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_gridded_correction_t, element ) == 0 + sizeof(gridded_correction_header_t), "Offset of element in msg_ssr_gridded_correction_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_gridded_correction_t, element ) == 0 + sizeof(gridded_correction_header_t), offset_of_element_in_msg_ssr_gridded_correction_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_SSR_TILE_DEFINITION(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_tile_definition_t, tile_set_id ) == 0, "Offset of tile_set_id in msg_ssr_tile_definition_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_tile_definition_t, tile_set_id ) == 0, offset_of_tile_set_id_in_msg_ssr_tile_definition_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_tile_definition_t, tile_id ) == 0 + sizeof(u16), "Offset of tile_id in msg_ssr_tile_definition_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_tile_definition_t, tile_id ) == 0 + sizeof(u16), offset_of_tile_id_in_msg_ssr_tile_definition_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_tile_definition_t, corner_nw_lat ) == 0 + sizeof(u16) + sizeof(u16), "Offset of corner_nw_lat in msg_ssr_tile_definition_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_tile_definition_t, corner_nw_lat ) == 0 + sizeof(u16) + sizeof(u16), offset_of_corner_nw_lat_in_msg_ssr_tile_definition_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_tile_definition_t, corner_nw_lon ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16), "Offset of corner_nw_lon in msg_ssr_tile_definition_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_tile_definition_t, corner_nw_lon ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16), offset_of_corner_nw_lon_in_msg_ssr_tile_definition_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_tile_definition_t, spacing_lat ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16), "Offset of spacing_lat in msg_ssr_tile_definition_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_tile_definition_t, spacing_lat ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16), offset_of_spacing_lat_in_msg_ssr_tile_definition_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_tile_definition_t, spacing_lon ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16) + sizeof(u16), "Offset of spacing_lon in msg_ssr_tile_definition_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_tile_definition_t, spacing_lon ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16) + sizeof(u16), offset_of_spacing_lon_in_msg_ssr_tile_definition_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_tile_definition_t, rows ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(u16), "Offset of rows in msg_ssr_tile_definition_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_tile_definition_t, rows ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(u16), offset_of_rows_in_msg_ssr_tile_definition_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_tile_definition_t, cols ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(u16) + sizeof(u16), "Offset of cols in msg_ssr_tile_definition_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_tile_definition_t, cols ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(u16) + sizeof(u16), offset_of_cols_in_msg_ssr_tile_definition_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_tile_definition_t, bitmask ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16), "Offset of bitmask in msg_ssr_tile_definition_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_tile_definition_t, bitmask ) == 0 + sizeof(u16) + sizeof(u16) + sizeof(s16) + sizeof(s16) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u16), offset_of_bitmask_in_msg_ssr_tile_definition_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_SSR_ORBIT_CLOCK_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, time ) == 0, "Offset of time in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, time ) == 0, offset_of_time_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, sid ) == 0 + sizeof(gps_time_sec_t), "Offset of sid in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, sid ) == 0 + sizeof(gps_time_sec_t), offset_of_sid_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t), "Offset of update_interval in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t), offset_of_update_interval_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, iod_ssr ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8), "Offset of iod_ssr in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, iod_ssr ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8), offset_of_iod_ssr_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, iod ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8), "Offset of iod in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, iod ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8), offset_of_iod_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, radial ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of radial in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, radial ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_radial_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, along ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32), "Offset of along in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, along ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32), offset_of_along_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, cross ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32), "Offset of cross in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, cross ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32), offset_of_cross_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, dot_radial ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of dot_radial in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, dot_radial ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_dot_radial_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, dot_along ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of dot_along in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, dot_along ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_dot_along_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, dot_cross ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of dot_cross in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, dot_cross ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_dot_cross_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, c0 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of c0 in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, c0 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_c0_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, c1 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of c1 in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, c1 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_c1_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_orbit_clock_dep_a_t, c2 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), "Offset of c2 in msg_ssr_orbit_clock_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_orbit_clock_dep_a_t, c2 ) == 0 + sizeof(gps_time_sec_t) + sizeof(sbp_gnss_signal_t) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32) + sizeof(s32), offset_of_c2_in_msg_ssr_orbit_clock_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_STECHeaderDepA(void) {
#ifdef __cplusplus
static_assert(offsetof(stec_header_dep_a_t, time ) == 0, "Offset of time in stec_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_dep_a_t, time ) == 0, offset_of_time_in_stec_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_dep_a_t, num_msgs ) == 0 + sizeof(gps_time_sec_t), "Offset of num_msgs in stec_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_dep_a_t, num_msgs ) == 0 + sizeof(gps_time_sec_t), offset_of_num_msgs_in_stec_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_dep_a_t, seq_num ) == 0 + sizeof(gps_time_sec_t) + sizeof(u8), "Offset of seq_num in stec_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_dep_a_t, seq_num ) == 0 + sizeof(gps_time_sec_t) + sizeof(u8), offset_of_seq_num_in_stec_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_dep_a_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(u8) + sizeof(u8), "Offset of update_interval in stec_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_dep_a_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(u8) + sizeof(u8), offset_of_update_interval_in_stec_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(stec_header_dep_a_t, iod_atmo ) == 0 + sizeof(gps_time_sec_t) + sizeof(u8) + sizeof(u8) + sizeof(u8), "Offset of iod_atmo in stec_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(stec_header_dep_a_t, iod_atmo ) == 0 + sizeof(gps_time_sec_t) + sizeof(u8) + sizeof(u8) + sizeof(u8), offset_of_iod_atmo_in_stec_header_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_GriddedCorrectionHeaderDepA(void) {
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_dep_a_t, time ) == 0, "Offset of time in gridded_correction_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_dep_a_t, time ) == 0, offset_of_time_in_gridded_correction_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_dep_a_t, num_msgs ) == 0 + sizeof(gps_time_sec_t), "Offset of num_msgs in gridded_correction_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_dep_a_t, num_msgs ) == 0 + sizeof(gps_time_sec_t), offset_of_num_msgs_in_gridded_correction_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_dep_a_t, seq_num ) == 0 + sizeof(gps_time_sec_t) + sizeof(u16), "Offset of seq_num in gridded_correction_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_dep_a_t, seq_num ) == 0 + sizeof(gps_time_sec_t) + sizeof(u16), offset_of_seq_num_in_gridded_correction_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_dep_a_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16), "Offset of update_interval in gridded_correction_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_dep_a_t, update_interval ) == 0 + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16), offset_of_update_interval_in_gridded_correction_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_dep_a_t, iod_atmo ) == 0 + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16) + sizeof(u8), "Offset of iod_atmo in gridded_correction_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_dep_a_t, iod_atmo ) == 0 + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16) + sizeof(u8), offset_of_iod_atmo_in_gridded_correction_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(gridded_correction_header_dep_a_t, tropo_quality_indicator ) == 0 + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16) + sizeof(u8) + sizeof(u8), "Offset of tropo_quality_indicator in gridded_correction_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(gridded_correction_header_dep_a_t, tropo_quality_indicator ) == 0 + sizeof(gps_time_sec_t) + sizeof(u16) + sizeof(u16) + sizeof(u8) + sizeof(u8), offset_of_tropo_quality_indicator_in_gridded_correction_header_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_GridDefinitionHeaderDepA(void) {
#ifdef __cplusplus
static_assert(offsetof(grid_definition_header_dep_a_t, region_size_inverse ) == 0, "Offset of region_size_inverse in grid_definition_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_definition_header_dep_a_t, region_size_inverse ) == 0, offset_of_region_size_inverse_in_grid_definition_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(grid_definition_header_dep_a_t, area_width ) == 0 + sizeof(u8), "Offset of area_width in grid_definition_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_definition_header_dep_a_t, area_width ) == 0 + sizeof(u8), offset_of_area_width_in_grid_definition_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(grid_definition_header_dep_a_t, lat_nw_corner_enc ) == 0 + sizeof(u8) + sizeof(u16), "Offset of lat_nw_corner_enc in grid_definition_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_definition_header_dep_a_t, lat_nw_corner_enc ) == 0 + sizeof(u8) + sizeof(u16), offset_of_lat_nw_corner_enc_in_grid_definition_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(grid_definition_header_dep_a_t, lon_nw_corner_enc ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16), "Offset of lon_nw_corner_enc in grid_definition_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_definition_header_dep_a_t, lon_nw_corner_enc ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16), offset_of_lon_nw_corner_enc_in_grid_definition_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(grid_definition_header_dep_a_t, num_msgs ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16), "Offset of num_msgs in grid_definition_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_definition_header_dep_a_t, num_msgs ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16), offset_of_num_msgs_in_grid_definition_header_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(grid_definition_header_dep_a_t, seq_num ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u8), "Offset of seq_num in grid_definition_header_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(grid_definition_header_dep_a_t, seq_num ) == 0 + sizeof(u8) + sizeof(u16) + sizeof(u16) + sizeof(u16) + sizeof(u8), offset_of_seq_num_in_grid_definition_header_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_SSR_STEC_CORRECTION_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_stec_correction_dep_a_t, header ) == 0, "Offset of header in msg_ssr_stec_correction_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_stec_correction_dep_a_t, header ) == 0, offset_of_header_in_msg_ssr_stec_correction_dep_a_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_stec_correction_dep_a_t, stec_sat_list ) == 0 + sizeof(stec_header_dep_a_t), "Offset of stec_sat_list in msg_ssr_stec_correction_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_stec_correction_dep_a_t, stec_sat_list ) == 0 + sizeof(stec_header_dep_a_t), offset_of_stec_sat_list_in_msg_ssr_stec_correction_dep_a_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_gridded_correction_no_std_dep_a_t, header ) == 0, "Offset of header in msg_ssr_gridded_correction_no_std_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_gridded_correction_no_std_dep_a_t, header ) == 0, offset_of_header_in_msg_ssr_gridded_correction_no_std_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_gridded_correction_no_std_dep_a_t, element ) == 0 + sizeof(gridded_correction_header_dep_a_t), "Offset of element in msg_ssr_gridded_correction_no_std_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_gridded_correction_no_std_dep_a_t, element ) == 0 + sizeof(gridded_correction_header_dep_a_t), offset_of_element_in_msg_ssr_gridded_correction_no_std_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_SSR_GRIDDED_CORRECTION_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_gridded_correction_dep_a_t, header ) == 0, "Offset of header in msg_ssr_gridded_correction_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_gridded_correction_dep_a_t, header ) == 0, offset_of_header_in_msg_ssr_gridded_correction_dep_a_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_gridded_correction_dep_a_t, element ) == 0 + sizeof(gridded_correction_header_dep_a_t), "Offset of element in msg_ssr_gridded_correction_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_gridded_correction_dep_a_t, element ) == 0 + sizeof(gridded_correction_header_dep_a_t), offset_of_element_in_msg_ssr_gridded_correction_dep_a_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_SSR_GRID_DEFINITION_DEP_A(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_grid_definition_dep_a_t, header ) == 0, "Offset of header in msg_ssr_grid_definition_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_grid_definition_dep_a_t, header ) == 0, offset_of_header_in_msg_ssr_grid_definition_dep_a_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_ssr_grid_definition_dep_a_t, rle_list ) == 0 + sizeof(grid_definition_header_dep_a_t), "Offset of rle_list in msg_ssr_grid_definition_dep_a_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ssr_grid_definition_dep_a_t, rle_list ) == 0 + sizeof(grid_definition_header_dep_a_t), offset_of_rle_list_in_msg_ssr_grid_definition_dep_a_t_is_incorrect)
#endif
#endif
}


SBP_PACK_END

#endif /* LIBSBP_SSR_MESSAGES_H */
