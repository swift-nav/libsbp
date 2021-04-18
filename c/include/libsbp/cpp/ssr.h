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
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_SSR_MESSAGES_H
#define LIBSBP_CPP_SSR_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>
#include <libsbp/cpp/gnss.h>

namespace sbp {
  
  /**
   * SSR code biases corrections for a particular satellite.
   *
   * Code biases are to be added to pseudorange.
   * The corrections conform with typical RTCMv3 MT1059 and 1065.
   */
  
  struct SBP_ATTR_PACKED CodeBiasesContent {
    u8 code; /** Signal constellation, band and code */
    s16 value; /** Code bias value [0.01 m] */
  };
  
  /**
   * SSR phase biases corrections for a particular satellite.
   *
   * Phase biases are to be added to carrier phase measurements.
   * The corrections conform with typical RTCMv3 MT1059 and 1065.
   */
  
  struct SBP_ATTR_PACKED PhaseBiasesContent {
    u8 code; /** Signal constellation, band and code */
    u8 integer_indicator; /** Indicator for integer property */
    u8 widelane_integer_indicator; /** Indicator for two groups of Wide-Lane(s) integer property */
    u8 discontinuity_counter; /** Signal phase discontinuity counter.
Increased for every discontinuity in phase.
 */
    s32 bias; /** Phase bias for specified signal [0.1 mm] */
  };
  
  /**
   * Header for the MSG_SSR_STEC_CORRECTION message.
   *
   * A full set of STEC information will likely span multiple SBP
   * messages, since SBP message a limited to 255 bytes.  The header
   * is used to tie multiple SBP messages into a sequence.
   */
  
  struct SBP_ATTR_PACKED STECHeader {
    u16 tile_set_id; /** Unique identifier of the tile set this tile belongs to. */
    u16 tile_id; /** Unique identifier of this tile in the tile set. */
    GPSTimeSec time; /** GNSS reference time of the correction */
    u8 num_msgs; /** Number of messages in the dataset */
    u8 seq_num; /** Position of this message in the dataset */
    u8 update_interval; /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    u8 iod_atmo; /** IOD of the SSR atmospheric correction
 */
  };
  
  /**
   * Header for the MSG_SSR_GRIDDED_CORRECTION message.
   *
   * The LPP message contains nested variable length arrays
   * which are not suppported in SBP, so each grid point will
   * be identified by the index.
   */
  
  struct SBP_ATTR_PACKED GriddedCorrectionHeader {
    u16 tile_set_id; /** Unique identifier of the tile set this tile belongs to. */
    u16 tile_id; /** Unique identifier of this tile in the tile set. */
    GPSTimeSec time; /** GNSS reference time of the correction */
    u16 num_msgs; /** Number of messages in the dataset */
    u16 seq_num; /** Position of this message in the dataset */
    u8 update_interval; /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    u8 iod_atmo; /** IOD of the SSR atmospheric correction
 */
    u8 tropo_quality_indicator; /** Quality of the troposphere data. Encoded following RTCM DF389
specifcation in units of m.
 */
  };
  
  /**
   * None
   *
   * STEC polynomial for the given satellite.
   */
  
  struct SBP_ATTR_PACKED STECSatElement {
    SvId sv_id; /** Unique space vehicle identifier */
    u8 stec_quality_indicator; /** Quality of the STEC data. Encoded following RTCM DF389 specifcation
but in units of TECU instead of m.
 */
    s16 stec_coeff[4]; /** Coefficents of the STEC polynomial in the order of C00, C01, C10, C11
 [C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2] */
  };
  
  /**
   * None
   *
   * Troposphere vertical delays at the grid point.
   */
  
  struct SBP_ATTR_PACKED TroposphericDelayCorrectionNoStd {
    s16 hydro; /** Hydrostatic vertical delay [4 mm (add 2.3 m to get actual vertical hydro delay)] */
    s8 wet; /** Wet vertical delay [4 mm (add 0.252 m to get actual vertical wet delay)] */
  };
  
  /**
   * None
   *
   * Troposphere vertical delays (mean and standard deviation) at the grid
   * point.
   */
  
  struct SBP_ATTR_PACKED TroposphericDelayCorrection {
    s16 hydro; /** Hydrostatic vertical delay [4 mm (add 2.3 m to get actual vertical hydro delay)] */
    s8 wet; /** Wet vertical delay [4 mm (add 0.252 m to get actual vertical wet delay)] */
    u8 stddev; /** stddev [modified DF389 scale; class is upper 3 bits, value is lower 5
stddev <= (3^class * (1 + value/16) - 1) mm
] */
  };
  
  /**
   * None
   *
   * STEC residual for the given satellite at the grid point.
   */
  
  struct SBP_ATTR_PACKED STECResidualNoStd {
    SvId sv_id; /** space vehicle identifier */
    s16 residual; /** STEC residual [0.04 TECU] */
  };
  
  /**
   * None
   *
   * STEC residual (mean and standard deviation) for the given satellite
   * at the grid point,
   */
  
  struct SBP_ATTR_PACKED STECResidual {
    SvId sv_id; /** space vehicle identifier */
    s16 residual; /** STEC residual [0.04 TECU] */
    u8 stddev; /** stddev [modified DF389 scale; class is upper 3 bits, value is lower 5
stddev <= (3^class * (1 + value/16) - 1) * 10 TECU
] */
  };
  
  /**
   * Correction data for a single grid point.
   *
   * Contains one tropo delay, plus STEC residuals for each satellite at the
   * grid point.
   */
  template<size_t STEC_RESIDUALS_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u16) + sizeof(TroposphericDelayCorrectionNoStd) + 0)) / sizeof(STECResidualNoStd)>
  struct SBP_ATTR_PACKED GridElementNoStd {
    static constexpr size_t kStecResidualsCount = STEC_RESIDUALS_COUNT;
    u16 index; /** Index of the grid point */
    TroposphericDelayCorrectionNoStd tropo_delay_correction; /** Wet and hydrostatic vertical delays */
    STECResidualNoStd stec_residuals[STEC_RESIDUALS_COUNT]; /** STEC residuals for each satellite */
  };
  
  /**
   * Correction data for a single grid point.
   *
   * Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
   * stddev) for each satellite at the grid point.
   */
  template<size_t STEC_RESIDUALS_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u16) + sizeof(TroposphericDelayCorrection) + 0)) / sizeof(STECResidual)>
  struct SBP_ATTR_PACKED GridElement {
    static constexpr size_t kStecResidualsCount = STEC_RESIDUALS_COUNT;
    u16 index; /** Index of the grid point */
    TroposphericDelayCorrection tropo_delay_correction; /** Wet and hydrostatic vertical delays (mean, stddev) */
    STECResidual stec_residuals[STEC_RESIDUALS_COUNT]; /** STEC residuals for each satellite (mean, stddev) */
  };
  
  /**
   * Precise orbit and clock correction
   *
   * The precise orbit and clock correction message is
   * to be applied as a delta correction to broadcast
   * ephemeris and is typically an equivalent to the 1060
   * and 1066 RTCM message types
   */
  
  struct SBP_ATTR_PACKED MsgSsrOrbitClock {
    GPSTimeSec time; /** GNSS reference time of the correction */
    GnssSignal sid; /** GNSS signal identifier (16 bit) */
    u8 update_interval; /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    u8 iod_ssr; /** IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration
 */
    u32 iod; /** Issue of broadcast ephemeris data or IODCRC (Beidou) */
    s32 radial; /** Orbit radial delta correction [0.1 mm] */
    s32 along; /** Orbit along delta correction [0.4 mm] */
    s32 cross; /** Orbit along delta correction [0.4 mm] */
    s32 dot_radial; /** Velocity of orbit radial delta correction [0.001 mm/s] */
    s32 dot_along; /** Velocity of orbit along delta correction [0.004 mm/s] */
    s32 dot_cross; /** Velocity of orbit cross delta correction [0.004 mm/s] */
    s32 c0; /** C0 polynomial coefficient for correction of broadcast satellite clock [0.1 mm] */
    s32 c1; /** C1 polynomial coefficient for correction of broadcast satellite clock [0.001 mm/s] */
    s32 c2; /** C2 polynomial coefficient for correction of broadcast satellite clock [0.00002 mm/s^-2] */
  };
  
  /**
   * Precise code biases correction
   *
   * The precise code biases message is to be added
   * to the pseudorange of the corresponding signal
   * to get corrected pseudorange. It is typically
   * an equivalent to the 1059 and 1065 RTCM message types
   */
  template<size_t BIASES_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(GPSTimeSec) + sizeof(GnssSignal) + sizeof(u8) + sizeof(u8) + 0)) / sizeof(CodeBiasesContent)>
  struct SBP_ATTR_PACKED MsgSsrCodeBiases {
    static constexpr size_t kBiasesCount = BIASES_COUNT;
    GPSTimeSec time; /** GNSS reference time of the correction */
    GnssSignal sid; /** GNSS signal identifier (16 bit) */
    u8 update_interval; /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    u8 iod_ssr; /** IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration
 */
    CodeBiasesContent biases[BIASES_COUNT]; /** Code biases for the different satellite signals */
  };
  
  /**
   * Precise phase biases correction
   *
   * The precise phase biases message contains the biases
   * to be added to the carrier phase of the corresponding
   * signal to get corrected carrier phase measurement, as
   * well as the satellite yaw angle to be applied to compute
   * the phase wind-up correction.
   * It is typically an equivalent to the 1265 RTCM message types
   */
  template<size_t BIASES_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(GPSTimeSec) + sizeof(GnssSignal) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u8) + sizeof(u16) + sizeof(s8) + 0)) / sizeof(PhaseBiasesContent)>
  struct SBP_ATTR_PACKED MsgSsrPhaseBiases {
    static constexpr size_t kBiasesCount = BIASES_COUNT;
    GPSTimeSec time; /** GNSS reference time of the correction */
    GnssSignal sid; /** GNSS signal identifier (16 bit) */
    u8 update_interval; /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    u8 iod_ssr; /** IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration
 */
    u8 dispersive_bias; /** Indicator for the dispersive phase biases property.
 */
    u8 mw_consistency; /** Consistency indicator for Melbourne-Wubbena linear combinations
 */
    u16 yaw; /** Satellite yaw angle [1 / 256 semi-circle] */
    s8 yaw_rate; /** Satellite yaw angle rate [1 / 8192 semi-circle / s] */
    PhaseBiasesContent biases[BIASES_COUNT]; /** Phase biases corrections for a
satellite being tracked.
 */
  };
  
  /**
   * STEC correction polynomial coeffcients.
   *
   * The Slant Total Electron Content per space vehicle, given as polynomial
   * approximation for a given tile. This should be combined with the
   * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
   * of the atmospheric delay.
   * 
   * It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
   */
  template<size_t STEC_SAT_LIST_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(STECHeader) + 0)) / sizeof(STECSatElement)>
  struct SBP_ATTR_PACKED MsgSsrStecCorrection {
    static constexpr size_t kStecSatListCount = STEC_SAT_LIST_COUNT;
    STECHeader header; /** Header of a STEC polynomial coeffcient message. */
    STECSatElement stec_sat_list[STEC_SAT_LIST_COUNT]; /** Array of STEC polynomial coeffcients for each space vehicle. */
  };
  
  /**
   * Gridded troposphere and STEC correction residuals.
   *
   * STEC residuals are per space vehicle, troposphere is not.
   * 
   * It is typically equivalent to the QZSS CLAS Sub Type 9 messages
   */
  template<size_t ELEMENT_COUNT>
  struct SBP_ATTR_PACKED MsgSsrGriddedCorrection {
    static constexpr size_t kElementCount = ELEMENT_COUNT;
    GriddedCorrectionHeader header; /** Header of a gridded correction message */
    GridElement<ELEMENT_COUNT> element; /** Tropo and STEC residuals for the given grid point.
 */
  };
  
  /**
   * Definition of a SSR atmospheric correction tile.

   *
   * Provides the correction point coordinates for the atmospheric correction
   * values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
   * messages.
   * 
   * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
   * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
   * correction points, not lists of points.
   */
  
  struct SBP_ATTR_PACKED MsgSsrTileDefinition {
    u16 tile_set_id; /** Unique identifier of the tile set this tile belongs to. */
    u16 tile_id; /** Unique identifier of this tile in the tile set.

See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
 */
    s16 corner_nw_lat; /** North-West corner correction point latitude.

The relation between the latitude X in the range [-90, 90] and
the coded number N is:

N = floor((X / 90) * 2^14)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
 [encoded degrees] */
    s16 corner_nw_lon; /** North-West corner correction point longtitude.

The relation between the longtitude X in the range [-180, 180]
and the coded number N is:

N = floor((X / 180) * 2^15)

See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
 [encoded degrees] */
    u16 spacing_lat; /** Spacing of the correction points in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
 [0.01 degrees] */
    u16 spacing_lon; /** Spacing of the correction points in the longtitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongtitude.
 [0.01 degrees] */
    u16 rows; /** Number of steps in the latitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
 */
    u16 cols; /** Number of steps in the longtitude direction.

See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongtitude.
 */
    u64 bitmask; /** Specifies the availability of correction data at the
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
  };
  
  
  struct SBP_ATTR_PACKED MsgSsrOrbitClockDepA {
    GPSTimeSec time; /** GNSS reference time of the correction */
    GnssSignal sid; /** GNSS signal identifier (16 bit) */
    u8 update_interval; /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    u8 iod_ssr; /** IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration
 */
    u8 iod; /** Issue of broadcast ephemeris data */
    s32 radial; /** Orbit radial delta correction [0.1 mm] */
    s32 along; /** Orbit along delta correction [0.4 mm] */
    s32 cross; /** Orbit along delta correction [0.4 mm] */
    s32 dot_radial; /** Velocity of orbit radial delta correction [0.001 mm/s] */
    s32 dot_along; /** Velocity of orbit along delta correction [0.004 mm/s] */
    s32 dot_cross; /** Velocity of orbit cross delta correction [0.004 mm/s] */
    s32 c0; /** C0 polynomial coefficient for correction of broadcast satellite clock [0.1 mm] */
    s32 c1; /** C1 polynomial coefficient for correction of broadcast satellite clock [0.001 mm/s] */
    s32 c2; /** C2 polynomial coefficient for correction of broadcast satellite clock [0.00002 mm/s^-2] */
  };
  
  /**
   * Header for MSG_SSR_STEC_CORRECTION_DEP message
   *
   * A full set of STEC information will likely span multiple SBP
   * messages, since SBP message a limited to 255 bytes.  The header
   * is used to tie multiple SBP messages into a sequence.
   */
  
  struct SBP_ATTR_PACKED STECHeaderDepA {
    GPSTimeSec time; /** GNSS reference time of the correction */
    u8 num_msgs; /** Number of messages in the dataset */
    u8 seq_num; /** Position of this message in the dataset */
    u8 update_interval; /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    u8 iod_atmo; /** IOD of the SSR atmospheric correction
 */
  };
  
  /**
   * Header for MSG_SSR_GRIDDED_CORRECTION_DEP
   *
   * The 3GPP message contains nested variable length arrays
   * which are not suppported in SBP, so each grid point will
   * be identified by the index.
   */
  
  struct SBP_ATTR_PACKED GriddedCorrectionHeaderDepA {
    GPSTimeSec time; /** GNSS reference time of the correction */
    u16 num_msgs; /** Number of messages in the dataset */
    u16 seq_num; /** Position of this message in the dataset */
    u8 update_interval; /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    u8 iod_atmo; /** IOD of the SSR atmospheric correction
 */
    u8 tropo_quality_indicator; /** Quality of the troposphere data. Encoded following RTCM DF389
specifcation in units of m.
 */
  };
  
  /**
   * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
   *
   * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
   * Also includes an RLE encoded validity list.
   */
  
  struct SBP_ATTR_PACKED GridDefinitionHeaderDepA {
    u8 region_size_inverse; /** region_size (deg) = 10 / region_size_inverse
0 is an invalid value.
 [inverse degrees] */
    u16 area_width; /** grid height (deg) = grid width (deg) = area_width / region_size
0 is an invalid value.
 */
    u16 lat_nw_corner_enc; /** North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90 */
    u16 lon_nw_corner_enc; /** North-West corner longtitude (deg) = region_size * lon_nw_corner_enc - 180 */
    u8 num_msgs; /** Number of messages in the dataset */
    u8 seq_num; /** Postion of this message in the dataset */
  };
  
  template<size_t STEC_SAT_LIST_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(STECHeaderDepA) + 0)) / sizeof(STECSatElement)>
  struct SBP_ATTR_PACKED MsgSsrStecCorrectionDepA {
    static constexpr size_t kStecSatListCount = STEC_SAT_LIST_COUNT;
    STECHeaderDepA header; /** Header of a STEC message */
    STECSatElement stec_sat_list[STEC_SAT_LIST_COUNT]; /** Array of STEC information for each space vehicle */
  };
  
  template<size_t ELEMENT_COUNT>
  struct SBP_ATTR_PACKED MsgSsrGriddedCorrectionNoStdDepA {
    static constexpr size_t kElementCount = ELEMENT_COUNT;
    GriddedCorrectionHeaderDepA header; /** Header of a Gridded Correction message */
    GridElementNoStd<ELEMENT_COUNT> element; /** Tropo and STEC residuals for the given grid point */
  };
  
  template<size_t ELEMENT_COUNT>
  struct SBP_ATTR_PACKED MsgSsrGriddedCorrectionDepA {
    static constexpr size_t kElementCount = ELEMENT_COUNT;
    GriddedCorrectionHeaderDepA header; /** Header of a Gridded Correction message */
    GridElement<ELEMENT_COUNT> element; /** Tropo and STEC residuals for the given grid point (mean
and standard deviation)
 */
  };
  
  template<size_t RLE_LIST_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(GridDefinitionHeaderDepA) + 0)) / sizeof(u8)>
  struct SBP_ATTR_PACKED MsgSsrGridDefinitionDepA {
    static constexpr size_t kRleListCount = RLE_LIST_COUNT;
    GridDefinitionHeaderDepA header; /** Header of a Gridded Correction message */
    u8 rle_list[RLE_LIST_COUNT]; /** Run Length Encode list of quadrants that contain valid data.
The spec describes the encoding scheme in detail, but
essentially the index of the quadrants that contain transitions between
valid and invalid (and vice versa) are encoded as u8 integers.
 */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_SSR_MESSAGES_H */