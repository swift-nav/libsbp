/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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
 * Precise State Space Representation (SSR) corrections format
 * \{ */

#ifndef LIBSBP_LEGACY_SSR_MESSAGES_H
#define LIBSBP_LEGACY_SSR_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/legacy/gnss.h>
#include <libsbp/ssr_macros.h>

SBP_PACK_START

/** SSR code biases corrections for a particular satellite
 *
 * Code biases are to be added to pseudorange. The corrections conform with
 * RTCMv3 MT 1059 / 1065.
 */

typedef struct SBP_ATTR_PACKED {
  u8 code;   /**< Signal encoded following RTCM specifications (DF380,
                  DF381, DF382 and DF467). */
  s16 value; /**< Code bias value [0.01 m] */
} code_biases_content_t;

/** SSR phase biases corrections for a particular satellite
 *
 * Phase biases are to be added to carrier phase measurements.
 */

typedef struct SBP_ATTR_PACKED {
  u8 code;                       /**< Signal encoded following RTCM
                                      specifications (DF380, DF381, DF382
                                      and DF467) */
  u8 integer_indicator;          /**< Indicator for integer property */
  u8 widelane_integer_indicator; /**< Indicator for two groups of Wide-
                                      Lane(s) integer property */
  u8 discontinuity_counter;      /**< Signal phase discontinuity counter.
                                      Increased for every discontinuity in
                                      phase. */
  s32 bias; /**< Phase bias for specified signal [0.1 mm] */
} phase_biases_content_t;

/** Header for the MSG_SSR_STEC_CORRECTION message
 *
 * A full set of STEC information will likely span multiple SBP messages,
 * since SBP message a limited to 255 bytes.  The header is used to tie
 * multiple SBP messages into a sequence.
 */

typedef struct SBP_ATTR_PACKED {
  u16 tile_set_id;     /**< Unique identifier of the tile set this tile
                            belongs to. */
  u16 tile_id;         /**< Unique identifier of this tile in the tile set. */
  gps_time_sec_t time; /**< GNSS reference time of the
                            correction */
  u8 num_msgs;         /**< Number of messages in the dataset */
  u8 seq_num;          /**< Position of this message in the dataset */
  u8 update_interval;  /**< Update interval between consecutive corrections.
                            Encoded following RTCM DF391 specification. */
  u8 iod_atmo;         /**< IOD of the SSR atmospheric correction */
} stec_header_t;

/** Header for the MSG_SSR_GRIDDED_CORRECTION message
 *
 * The LPP message contains nested variable length arrays which are not
 * supported in SBP, so each grid point will be identified by the index.
 */

typedef struct SBP_ATTR_PACKED {
  u16 tile_set_id;            /**< Unique identifier of the tile set this
                                   tile belongs to. */
  u16 tile_id;                /**< Unique identifier of this tile in the
                                   tile set. */
  gps_time_sec_t time;        /**< GNSS reference time of the
                                   correction */
  u16 num_msgs;               /**< Number of messages in the dataset */
  u16 seq_num;                /**< Position of this message in the dataset */
  u8 update_interval;         /**< Update interval between consecutive
                                   corrections. Encoded following RTCM
                                   DF391 specification. */
  u8 iod_atmo;                /**< IOD of the SSR atmospheric correction */
  u8 tropo_quality_indicator; /**< Quality of the troposphere data. Encoded
                                   following RTCM DF389 specification in
                                   units of m. */
} gridded_correction_header_t;

/** None
 *
 * STEC polynomial for the given satellite.
 */

typedef struct SBP_ATTR_PACKED {
  sv_id_t sv_id;             /**< Unique space vehicle identifier */
  u8 stec_quality_indicator; /**< Quality of the STEC data. Encoded
                                  following RTCM DF389 specification but in
                                  units of TECU instead of m. */
  s16 stec_coeff[4];         /**< Coefficients of the STEC polynomial in
                                  the order of C00, C01, C10, C11. C00 =
                                  0.05 TECU, C01/C10 = 0.02 TECU/deg, C11
                                  0.02 TECU/deg^2 */
} stec_sat_element_t;

/** None
 *
 * Troposphere vertical delays at the grid point.
 */

typedef struct SBP_ATTR_PACKED {
  s16 hydro; /**< Hydrostatic vertical delay [4 mm (add 2.3 m to get actual
                vertical hydro delay)] */
  s8 wet; /**< Wet vertical delay [4 mm (add 0.252 m to get actual vertical wet
             delay)] */
} tropospheric_delay_correction_no_std_t;

/** None
 *
 * Troposphere vertical delays (mean and standard deviation) at the grid
 * point.
 */

typedef struct SBP_ATTR_PACKED {
  s16 hydro; /**< Hydrostatic vertical delay. Add 2.3 m to get actual
                  value. [4 mm] */
  s8 wet;    /**< Wet vertical delay. Add 0.252 m to get actual value. [4 mm] */
  u8 stddev; /**< Modified DF389. class 3 MSB, value 5 LSB. stddev =
                  (3^class * (1 + value/16) - 1) [mm] */
} tropospheric_delay_correction_t;

/** None
 *
 * STEC residual for the given satellite at the grid point.
 */

typedef struct SBP_ATTR_PACKED {
  sv_id_t sv_id; /**< space vehicle identifier */
  s16 residual;  /**< STEC residual [0.04 TECU] */
} stec_residual_no_std_t;

/** None
 *
 * STEC residual (mean and standard deviation) for the given satellite at the
 * grid point.
 */

typedef struct SBP_ATTR_PACKED {
  sv_id_t sv_id; /**< space vehicle identifier */
  s16 residual;  /**< STEC residual [0.04 TECU] */
  u8 stddev;     /**< Modified DF389. class 3 MSB, value 5 LSB. stddev =
                      (3^class * (1 + value/16) - 1) * 10 */
} stec_residual_t;

/** Precise orbit and clock correction
 *
 * The precise orbit and clock correction message is to be applied as a delta
 * correction to broadcast ephemeris and is an equivalent to the 1060 /1066
 * RTCM message types.
 */

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;   /**< GNSS reference time of the
                              correction */
  sbp_gnss_signal_t sid; /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections.
                              Encoded following RTCM DF391 specification. */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of
                              Data SSR is used to indicate a change in the SSR
                              generating configuration */
  u32 iod;               /**< Issue of broadcast ephemeris data or IODCRC
                              (Beidou) */
  s32 radial;            /**< Orbit radial delta correction [0.1 mm] */
  s32 along;             /**< Orbit along delta correction [0.4 mm] */
  s32 cross;             /**< Orbit along delta correction [0.4 mm] */
  s32 dot_radial; /**< Velocity of orbit radial delta correction [0.001 mm/s] */
  s32 dot_along;  /**< Velocity of orbit along delta correction [0.004 mm/s] */
  s32 dot_cross;  /**< Velocity of orbit cross delta correction [0.004 mm/s] */
  s32 c0;         /**< C0 polynomial coefficient for correction of
                       broadcast satellite clock [0.1 mm] */
  s32 c1;         /**< C1 polynomial coefficient for correction of
                       broadcast satellite clock [0.001 mm/s] */
  s32 c2;         /**< C2 polynomial coefficient for correction of
                       broadcast satellite clock [0.00002 mm/s^-2] */
} msg_ssr_orbit_clock_t;

/** Precise code biases correction
 *
 * The precise code biases message is to be added to the pseudorange of the
 * corresponding signal to get corrected pseudorange. It is an equivalent to
 * the 1059 / 1065 RTCM message types.
 */

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;   /**< GNSS reference time of the
                              correction */
  sbp_gnss_signal_t sid; /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections.
                              Encoded following RTCM DF391 specification. */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of
                              Data SSR is used to indicate a change in the SSR
                              generating configuration */
  code_biases_content_t biases[0]; /**< Code biases for the different
                                        satellite signals */
} msg_ssr_code_biases_t;

/** Precise phase biases correction
 *
 * The precise phase biases message contains the biases to be added to the
 * carrier phase of the corresponding signal to get corrected carrier phase
 * measurement, as well as the satellite yaw angle to be applied to compute
 * the phase wind-up correction. It is typically an equivalent to the 1265
 * RTCM message types.
 */

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;   /**< GNSS reference time of the
                              correction */
  sbp_gnss_signal_t sid; /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections.
                              Encoded following RTCM DF391 specification. */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of
                              Data SSR is used to indicate a change in the SSR
                              generating configuration */
  u8 dispersive_bias;    /**< Indicator for the dispersive phase biases
                              property. */
  u8 mw_consistency;     /**< Consistency indicator for Melbourne-Wubbena
                              linear combinations */
  u16 yaw;               /**< Satellite yaw angle [1 / 256 semi-circle] */
  s8 yaw_rate; /**< Satellite yaw angle rate [1 / 8192 semi-circle / s] */
  phase_biases_content_t biases[0]; /**< Phase biases corrections for
                                         a satellite being tracked. */
} msg_ssr_phase_biases_t;

/** STEC correction polynomial coefficients
 *
 * The Slant Total Electron Content per space vehicle, given as polynomial
 * approximation for a given tile. This should be combined with the
 * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation of
 * the atmospheric delay.
 *
 * It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
 */

typedef struct SBP_ATTR_PACKED {
  stec_header_t header; /**< Header of a STEC polynomial coefficient
                             message. */
  stec_sat_element_t stec_sat_list[0]; /**< Array of STEC polynomial
                                            coefficients for each space
                                            vehicle. */
} msg_ssr_stec_correction_dep_t;

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time; /**< GNSS reference time of the bound */
  u8 num_msgs;         /**< Number of messages in the dataset */
  u8 seq_num;          /**< Position of this message in the dataset */
  u8 update_interval;  /**< Update interval between consecutive bounds.
                            Similar to RTCM DF391. */
  u8 sol_id;           /**< SSR Solution ID. */
} bounds_header_t;

typedef struct SBP_ATTR_PACKED {
  bounds_header_t header; /**< Header of a STEC correction with
                               bounds message. */
  u8 ssr_iod_atmo;        /**< IOD of the SSR atmospheric correction */
  u16 tile_set_id;        /**< Tile set ID */
  u16 tile_id;            /**< Tile ID */
  u8 n_sats;              /**< Number of satellites. */
  stec_sat_element_t stec_sat_list[0]; /**< Array of STEC polynomial
                                            coefficients for each space
                                            vehicle. */
} msg_ssr_stec_correction_t;

/** Gridded troposphere and STEC correction residuals
 *
 * STEC residuals are per space vehicle, troposphere is not.
 *
 * It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
 */

typedef struct SBP_ATTR_PACKED {
  gridded_correction_header_t header; /**< Header of a
                                           gridded
                                           correction
                                           message */
  u16 index;                          /**< Index of the grid point. */
  tropospheric_delay_correction_t tropo_delay_correction; /**< Wet and
                                                               hydrostatic
                                                               vertical
                                                               delays
                                                               (mean,
                                                               stddev). */
  stec_residual_t stec_residuals[0]; /**< STEC residuals for each
                                          satellite (mean, stddev). */
} msg_ssr_gridded_correction_t;

/** None
 *
 * STEC polynomial and bounds for the given satellite.
 */

typedef struct SBP_ATTR_PACKED {
  stec_residual_t stec_residual; /**< STEC residuals (mean, stddev) */
  u8 stec_bound_mu;              /**< Error Bound Mean. See Note 1. [m] */
  u8 stec_bound_sig;             /**< Error Bound StDev. See Note 1. [m] */
  u8 stec_bound_mu_dot; /**< Error Bound Mean First derivative. [0.00005 m/s] */
  u8 stec_bound_sig_dot; /**< Error Bound StDev First derivative. [0.00005 m/s]
                          */
} stec_sat_element_integrity_t;

/** Gridded troposhere and STEC correction residuals bounds
 *
 * Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
 * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
 */

typedef struct SBP_ATTR_PACKED {
  bounds_header_t header; /**< Header of a bounds message. */
  u8 ssr_iod_atmo;        /**< IOD of the correction. */
  u16 tile_set_id;        /**< Set this tile belongs to. */
  u16 tile_id;            /**< Unique identifier of this tile in the
                               tile set. */
  u8 tropo_qi;            /**< Tropo Quality Indicator. Similar to RTCM
                               DF389. */
  u16 grid_point_id;      /**< Index of the Grid Point. */
  tropospheric_delay_correction_t tropo_delay_correction; /**< Tropospheric
                                                               delay at
                                                               grid point. */
  u8 tropo_v_hydro_bound_mu;  /**< Vertical Hydrostatic Error Bound Mean. [0.005
                                 m] */
  u8 tropo_v_hydro_bound_sig; /**< Vertical Hydrostatic Error Bound StDev.
                                 [0.005 m] */
  u8 tropo_v_wet_bound_mu;    /**< Vertical Wet Error Bound Mean. [0.005 m] */
  u8 tropo_v_wet_bound_sig;   /**< Vertical Wet Error Bound StDev. [0.005 m] */
  u8 n_sats;                  /**< Number of satellites. */
  stec_sat_element_integrity_t stec_sat_list[0]; /**< Array of STEC
                                                      polynomial
                                                      coefficients
                                                      and its bounds
                                                      for each space
                                                      vehicle. */
} msg_ssr_gridded_correction_bounds_t;

/** Definition of a SSR atmospheric correction tile.

 *
 * Provides the correction point coordinates for the atmospheric correction
 * values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
 * messages.
 *
 * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
 * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
 * correction points, not lists of points.
 */

typedef struct SBP_ATTR_PACKED {
  u16 tile_set_id;   /**< Unique identifier of the tile set this tile
                          belongs to. */
  u16 tile_id;       /**< Unique identifier of this tile in the tile set.
                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          correctionPointSetID. */
  s16 corner_nw_lat; /**< North-West corner correction point latitude.

                          The relation between the latitude X in the range
                          [-90, 90] and the coded number N is:

                          N = floor((X / 90) * 2^14)

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          referencePointLatitude. [encoded degrees] */
  s16 corner_nw_lon; /**< North-West corner correction point longitude.

                          The relation between the longitude X in the range
                          [-180, 180] and the coded number N is:

                          N = floor((X / 180) * 2^15)

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          referencePointLongitude. [encoded degrees] */
  u16 spacing_lat;   /**< Spacing of the correction points in the latitude
                          direction.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          stepOfLatitude. [0.01 degrees] */
  u16 spacing_lon;   /**< Spacing of the correction points in the longitude
                          direction.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          stepOfLongitude. [0.01 degrees] */
  u16 rows;          /**< Number of steps in the latitude direction.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          numberOfStepsLatitude. */
  u16 cols;          /**< Number of steps in the longitude direction.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          numberOfStepsLongitude. */
  u64 bitmask;       /**< Specifies the availability of correction data at
                          the correction points in the array.

                          If a specific bit is enabled (set to 1), the
                          correction is not available. Only the first rows
                          * cols bits are used, the remainder are set to 0.
                          If there are more then 64 correction points the
                          remaining corrections are always available.

                          Starting with the northwest corner of the array
                          (top left on a north oriented map) the correction
                          points are enumerated with row precedence - first
                          row west to east, second row west to east, until
                          last row west to east - ending with the southeast
                          corner of the array.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          bitmaskOfGrids but note the definition of the
                          bits is inverted. */
} msg_ssr_tile_definition_dep_t;

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

typedef struct SBP_ATTR_PACKED {
  u8 ssr_sol_id;     /**< SSR Solution ID. */
  u16 tile_set_id;   /**< Unique identifier of the tile set this tile
                          belongs to. */
  u16 tile_id;       /**< Unique identifier of this tile in the tile set.
                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          correctionPointSetID. */
  s16 corner_nw_lat; /**< North-West corner correction point latitude.

                          The relation between the latitude X in the range
                          [-90, 90] and the coded number N is:

                          N = floor((X / 90) * 2^14)

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          referencePointLatitude. [encoded degrees] */
  s16 corner_nw_lon; /**< North-West corner correction point longitude.

                          The relation between the longitude X in the range
                          [-180, 180] and the coded number N is:

                          N = floor((X / 180) * 2^15)

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          referencePointLongitude. [encoded degrees] */
  u16 spacing_lat;   /**< Spacing of the correction points in the latitude
                          direction.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          stepOfLatitude. [0.01 degrees] */
  u16 spacing_lon;   /**< Spacing of the correction points in the longitude
                          direction.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          stepOfLongitude. [0.01 degrees] */
  u16 rows;          /**< Number of steps in the latitude direction.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          numberOfStepsLatitude. */
  u16 cols;          /**< Number of steps in the longitude direction.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          numberOfStepsLongitude. */
  u64 bitmask;       /**< Specifies the availability of correction data at
                          the correction points in the array.

                          If a specific bit is enabled (set to 1), the
                          correction is not available. Only the first rows
                          * cols bits are used, the remainder are set to 0.
                          If there are more then 64 correction points the
                          remaining corrections are always available.

                          Starting with the northwest corner of the array
                          (top left on a north oriented map) the correction
                          points are enumerated with row precedence - first
                          row west to east, second row west to east, until
                          last row west to east - ending with the southeast
                          corner of the array.

                          See GNSS-SSR-ArrayOfCorrectionPoints field
                          bitmaskOfGrids but note the definition of the
                          bits is inverted. */
} msg_ssr_tile_definition_t;

/** Antenna phase center correction
 *
 * Contains phase center offset and elevation variation corrections for one
 * signal on a satellite.
 */

typedef struct SBP_ATTR_PACKED {
  sbp_gnss_signal_t sid; /**< GNSS signal identifier (16 bit) */
  u8 sat_info;           /**< Additional satellite information */
  u16 svn;    /**< Satellite Code, as defined by IGS. Typically the space
                   vehicle number. */
  s16 pco[3]; /**< Mean phase center offset, X Y and Z axes. See IGS
                   ANTEX file format description for coordinate system
                   definition. [1 mm] */
  s8 pcv[21]; /**< Elevation dependent phase center variations. First
                   element is 0 degrees separation from the Z axis,
                   subsequent elements represent elevation variations in 1
                   degree increments. [1 mm] */
} satellite_apc_t;

typedef struct SBP_ATTR_PACKED {
  satellite_apc_t apc[0]; /**< Satellite antenna phase center corrections */
} msg_ssr_satellite_apc_t;

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;   /**< GNSS reference time of the
                              correction */
  sbp_gnss_signal_t sid; /**< GNSS signal identifier (16 bit) */
  u8 update_interval;    /**< Update interval between consecutive corrections.
                              Encoded following RTCM DF391 specification. */
  u8 iod_ssr;            /**< IOD of the SSR correction. A change of Issue Of
                              Data SSR is used to indicate a change in the SSR
                              generating configuration */
  u8 iod;                /**< Issue of broadcast ephemeris data */
  s32 radial;            /**< Orbit radial delta correction [0.1 mm] */
  s32 along;             /**< Orbit along delta correction [0.4 mm] */
  s32 cross;             /**< Orbit along delta correction [0.4 mm] */
  s32 dot_radial; /**< Velocity of orbit radial delta correction [0.001 mm/s] */
  s32 dot_along;  /**< Velocity of orbit along delta correction [0.004 mm/s] */
  s32 dot_cross;  /**< Velocity of orbit cross delta correction [0.004 mm/s] */
  s32 c0;         /**< C0 polynomial coefficient for correction of
                       broadcast satellite clock [0.1 mm] */
  s32 c1;         /**< C1 polynomial coefficient for correction of
                       broadcast satellite clock [0.001 mm/s] */
  s32 c2;         /**< C2 polynomial coefficient for correction of
                       broadcast satellite clock [0.00002 mm/s^-2] */
} msg_ssr_orbit_clock_dep_a_t;

/** Header for MSG_SSR_STEC_CORRECTION_DEP message
 *
 * A full set of STEC information will likely span multiple SBP messages,
 * since SBP message a limited to 255 bytes.  The header is used to tie
 * multiple SBP messages into a sequence.
 */

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time; /**< GNSS reference time of the
                            correction */
  u8 num_msgs;         /**< Number of messages in the dataset */
  u8 seq_num;          /**< Position of this message in the dataset */
  u8 update_interval;  /**< Update interval between consecutive corrections.
                            Encoded following RTCM DF391 specification. */
  u8 iod_atmo;         /**< IOD of the SSR atmospheric correction */
} stec_header_dep_a_t;

/** Header for MSG_SSR_GRIDDED_CORRECTION_DEP
 *
 * The 3GPP message contains nested variable length arrays which are not
 * supported in SBP, so each grid point will be identified by the index.
 */

typedef struct SBP_ATTR_PACKED {
  gps_time_sec_t time;        /**< GNSS reference time of the
                                   correction */
  u16 num_msgs;               /**< Number of messages in the dataset */
  u16 seq_num;                /**< Position of this message in the dataset */
  u8 update_interval;         /**< Update interval between consecutive
                                   corrections. Encoded following RTCM
                                   DF391 specification. */
  u8 iod_atmo;                /**< IOD of the SSR atmospheric correction */
  u8 tropo_quality_indicator; /**< Quality of the troposphere data. Encoded
                                   following RTCM DF389 specification in
                                   units of m. */
} gridded_correction_header_dep_a_t;

/** Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages
 *
 * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an
 * RLE encoded validity list.
 */

typedef struct SBP_ATTR_PACKED {
  u8 region_size_inverse; /**< region_size (deg) = 10 / region_size_inverse
                               0 is an invalid value. [inverse degrees] */
  u16 area_width;         /**< grid height (deg) = grid width (deg) =
                               area_width / region_size 0 is an invalid
                               value. */
  u16 lat_nw_corner_enc;  /**< North-West corner latitude (deg) =
                               region_size * lat_nw_corner_enc - 90 */
  u16 lon_nw_corner_enc;  /**< North-West corner longitude (deg) =
                               region_size * lon_nw_corner_enc - 180 */
  u8 num_msgs;            /**< Number of messages in the dataset */
  u8 seq_num;             /**< Position of this message in the dataset */
} grid_definition_header_dep_a_t;

typedef struct SBP_ATTR_PACKED {
  stec_header_dep_a_t header;          /**< Header of a STEC message */
  stec_sat_element_t stec_sat_list[0]; /**< Array of STEC information for each
                                            space vehicle */
} msg_ssr_stec_correction_dep_a_t;

typedef struct SBP_ATTR_PACKED {
  gridded_correction_header_dep_a_t header; /**< Header of
                                                 a Gridded
                                                 Correction
                                                 message */
  u16 index;                                /**< Index of the grid point */
  tropospheric_delay_correction_no_std_t
      tropo_delay_correction;               /**< Wet
                                                 and
                                                 hydrostatic
                                                 vertical
                                                 delays */
  stec_residual_no_std_t stec_residuals[0]; /**< STEC residuals for
                                                 each satellite */
} msg_ssr_gridded_correction_no_std_dep_a_t;

typedef struct SBP_ATTR_PACKED {
  gridded_correction_header_dep_a_t header; /**< Header of
                                                 a Gridded
                                                 Correction
                                                 message */
  u16 index;                                /**< Index of the grid point */
  tropospheric_delay_correction_t tropo_delay_correction; /**< Wet and
                                                               hydrostatic
                                                               vertical
                                                               delays
                                                               (mean,
                                                               stddev) */
  stec_residual_t stec_residuals[0]; /**< STEC residuals for each
                                          satellite (mean, stddev) */
} msg_ssr_gridded_correction_dep_a_t;

typedef struct SBP_ATTR_PACKED {
  grid_definition_header_dep_a_t header; /**< Header of a Gridded
                                              Correction message */
  u8 rle_list[0]; /**< Run Length Encode list of quadrants that contain valid
                       data. The spec describes the encoding scheme in detail,
                       but essentially the index of the quadrants that contain
                       transitions between valid and invalid (and vice versa)
                       are encoded as u8 integers. */
} msg_ssr_grid_definition_dep_a_t;

/** None
 *
 * Orbit and clock bound.
 */

typedef struct SBP_ATTR_PACKED {
  u8 sat_id;               /**< Satellite ID. Similar to either RTCM DF068
                                (GPS), DF252 (Galileo), or DF488 (BDS)
                                depending on the constellation. */
  u8 orb_radial_bound_mu;  /**< Mean Radial. See Note 1. [m] */
  u8 orb_along_bound_mu;   /**< Mean Along-Track. See Note 1. [m] */
  u8 orb_cross_bound_mu;   /**< Mean Cross-Track. See Note 1. [m] */
  u8 orb_radial_bound_sig; /**< Standard Deviation Radial. See Note 2. [m] */
  u8 orb_along_bound_sig;  /**< Standard Deviation Along-Track. See Note 2. [m]
                            */
  u8 orb_cross_bound_sig;  /**< Standard Deviation Cross-Track. See Note 2. [m]
                            */
  u8 clock_bound_mu;       /**< Clock Bound Mean. See Note 1. [m] */
  u8 clock_bound_sig; /**< Clock Bound Standard Deviation. See Note 2. [m] */
} orbit_clock_bound_t;

/** Combined Orbit and Clock Bound
 *
 * Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230, mean=2+0.1(i-200);
 * i>230, mean=5+0.5(i-230).
 *
 * Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
 * i>230, std=5+0.5(i-230).
 */

typedef struct SBP_ATTR_PACKED {
  bounds_header_t header; /**< Header of a bounds message. */
  u8 ssr_iod;             /**< IOD of the SSR bound. */
  u8 const_id;            /**< Constellation ID to which the SVs belong. */
  u8 n_sats;              /**< Number of satellites. */
  orbit_clock_bound_t orbit_clock_bounds[0]; /**< Orbit and Clock Bounds per
                                                  Satellite */
} msg_ssr_orbit_clock_bounds_t;

typedef struct SBP_ATTR_PACKED {
  u8 sat_id;               /**< Satellite ID. Similar to either RTCM DF068
                                (GPS), DF252 (Galileo), or DF488 (BDS)
                                depending on the constellation. */
  u8 signal_id;            /**< Signal and Tracking Mode Identifier.
                                Similar to either RTCM DF380 (GPS), DF382
                                (Galileo) or DF467 (BDS) depending on the
                                constellation. */
  u8 code_bias_bound_mu;   /**< Code Bias Mean. Range: 0-1.275 m [0.005 m] */
  u8 code_bias_bound_sig;  /**< Code Bias Standard Deviation.  Range:
                                0-1.275 m [0.005 m] */
  u8 phase_bias_bound_mu;  /**< Phase Bias Mean. Range: 0-1.275 m [0.005 m] */
  u8 phase_bias_bound_sig; /**< Phase Bias Standard Deviation.  Range:
                                0-1.275 m [0.005 m] */
} code_phase_biases_sat_sig_t;

typedef struct SBP_ATTR_PACKED {
  bounds_header_t header; /**< Header of a bounds message. */
  u8 ssr_iod;             /**< IOD of the SSR bound. */
  u8 const_id;            /**< Constellation ID to which the SVs belong. */
  u8 n_sats_signals;      /**< Number of satellite-signal couples. */
  code_phase_biases_sat_sig_t satellites_signals[0]; /**< Code and Phase
                                                          Biases Bounds per
                                                          Satellite-Signal
                                                          couple. */
} msg_ssr_code_phase_biases_bounds_t;

/** None
 *
 * Orbit and clock bound degradation.
 */

typedef struct SBP_ATTR_PACKED {
  u8 orb_radial_bound_mu_dot;  /**< Orbit Bound Mean Radial First
                                    derivative. Range: 0-0.255 m/s [0.001 m/s] */
  u8 orb_along_bound_mu_dot;   /**< Orbit Bound Mean Along-Track First
                                    derivative. Range: 0-0.255 m/s [0.001 m/s] */
  u8 orb_cross_bound_mu_dot;   /**< Orbit Bound Mean Cross-Track First
                                    derivative. Range: 0-0.255 m/s [0.001 m/s] */
  u8 orb_radial_bound_sig_dot; /**< Orbit Bound Standard Deviation Radial
                                    First derivative. Range: 0-0.255 m/s [0.001
                                  m/s] */
  u8 orb_along_bound_sig_dot;  /**< Orbit Bound Standard Deviation Along-
                                    Track First derivative. Range: 0-0.255
                                    m/s [0.001 m/s] */
  u8 orb_cross_bound_sig_dot;  /**< Orbit Bound Standard Deviation Cross-
                                    Track First derivative. Range: 0-0.255
                                    m/s [0.001 m/s] */
  u8 clock_bound_mu_dot;       /**< Clock Bound Mean First derivative.
                                    Range: 0-0.255 m/s [0.001 m/s] */
  u8 clock_bound_sig_dot;      /**< Clock Bound Standard Deviation First
                                    derivative. Range: 0-0.255 m/s [0.001 m/s] */
} orbit_clock_bound_degradation_t;

typedef struct SBP_ATTR_PACKED {
  bounds_header_t header; /**< Header of a bounds
                               message. */
  u8 ssr_iod;             /**< IOD of the SSR bound degradation
                               parameter. */
  u8 const_id;            /**< Constellation ID to which the SVs
                               belong. */
  u64 sat_bitmask;        /**< Satellite Bit Mask. Put 1 for
                               each satellite where the
                               following degradation parameters
                               are applicable, 0 otherwise.
                               Encoded following RTCM DF394
                               specification. */
  orbit_clock_bound_degradation_t
      orbit_clock_bounds_degradation; /**< Orbit
                                           and
                                           Clock
                                           Bounds
                                           Degradation
                                           Parameters */
} msg_ssr_orbit_clock_bounds_degradation_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_SSR_MESSAGES_H */