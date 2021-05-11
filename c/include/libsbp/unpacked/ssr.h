#ifndef LIBSBP_SSR_MESSAGES_H
#define LIBSBP_SSR_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
#include <libsbp/unpacked/gnss.h>
/** SSR code biases corrections for a particular satellite.
 *
 * Code biases are to be added to pseudorange.
 * The corrections conform with RTCMv3 MT 1059 / 1065.
 */

typedef struct
{

  /**
   * Signal encoded following RTCM specifications
   * (DF380, DF381, DF382 and DF467).
   */
  u8 code;
  /**
   * Code bias value[0.01 m]
   */
  s16 value;
} sbp_code_biases_content_t;

/** SSR phase biases corrections for a particular satellite.
 *
 * Phase biases are to be added to carrier phase measurements.
 */

typedef struct
{

  /**
   * Signal encoded following RTCM specifications
   * (DF380, DF381, DF382 and DF467)
   */
  u8 code;
  /**
   * Indicator for integer property
   */
  u8 integer_indicator;
  /**
   * Indicator for two groups of Wide-Lane(s) integer property
   */
  u8 widelane_integer_indicator;
  /**
   * Signal phase discontinuity counter.
   * Increased for every discontinuity in phase.
   */
  u8 discontinuity_counter;
  /**
   * Phase bias for specified signal[0.1 mm]
   */
  s32 bias;
} sbp_phase_biases_content_t;

/** Header for the MSG_SSR_STEC_CORRECTION message.
 *
 * A full set of STEC information will likely span multiple SBP
 * messages, since SBP message a limited to 255 bytes.  The header
 * is used to tie multiple SBP messages into a sequence.
 */

typedef struct
{

  /**
   * Unique identifier of the tile set this tile belongs to.
   */
  u16 tile_set_id;
  /**
   * Unique identifier of this tile in the tile set.
   */
  u16 tile_id;
  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;
  /**
   * Number of messages in the dataset
   */
  u8 num_msgs;
  /**
   * Position of this message in the dataset
   */
  u8 seq_num;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR atmospheric correction
   */
  u8 iod_atmo;
} sbp_stec_header_t;

/** Header for the MSG_SSR_GRIDDED_CORRECTION message.
 *
 * The LPP message contains nested variable length arrays
 * which are not suppported in SBP, so each grid point will
 * be identified by the index.
 */

typedef struct
{

  /**
   * Unique identifier of the tile set this tile belongs to.
   */
  u16 tile_set_id;
  /**
   * Unique identifier of this tile in the tile set.
   */
  u16 tile_id;
  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;
  /**
   * Number of messages in the dataset
   */
  u16 num_msgs;
  /**
   * Position of this message in the dataset
   */
  u16 seq_num;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR atmospheric correction
   */
  u8 iod_atmo;
  /**
   * Quality of the troposphere data. Encoded following RTCM DF389
   * specification in units of m.
   */
  u8 tropo_quality_indicator;
} sbp_gridded_correction_header_t;

/** None
 *
 * STEC polynomial for the given satellite.
 */

typedef struct
{

  /**
   * Unique space vehicle identifier
   */
  sbp_sv_id_t sv_id;
  /**
   * Quality of the STEC data. Encoded following RTCM DF389 specification
   * but in units of TECU instead of m.
   */
  u8 stec_quality_indicator;
  /**
   * Coefficents of the STEC polynomial in the order of C00, C01, C10, C11[C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11
   * 0.02 TECU/deg^2]
   */
  s16 stec_coeff[4];
} sbp_stec_sat_element_t;

/** None
 *
 * Troposphere vertical delays at the grid point.
 */

typedef struct
{

  /**
   * Hydrostatic vertical delay[4 mm (add 2.3 m to get actual vertical hydro delay)]
   */
  s16 hydro;
  /**
   * Wet vertical delay[4 mm (add 0.252 m to get actual vertical wet delay)]
   */
  s8 wet;
} sbp_tropospheric_delay_correction_no_std_t;

/** None
 *
 * Troposphere vertical delays (mean and standard deviation) at the grid
 * point.
 */

typedef struct
{

  /**
   * Hydrostatic vertical delay[4 mm (add 2.3 m to get actual vertical hydro delay)]
   */
  s16 hydro;
  /**
   * Wet vertical delay[4 mm (add 0.252 m to get actual vertical wet delay)]
   */
  s8 wet;
  /**
* stddev[modified DF389 scale; class is upper 3 bits, value is lower 5
stddev <= (3^class * (1 + value/16) - 1) mm
]
   */
  u8 stddev;
} sbp_tropospheric_delay_correction_t;

/** None
 *
 * STEC residual for the given satellite at the grid point.
 */

typedef struct
{

  /**
   * space vehicle identifier
   */
  sbp_sv_id_t sv_id;
  /**
   * STEC residual[0.04 TECU]
   */
  s16 residual;
} sbp_stec_residual_no_std_t;

/** None
 *
 * STEC residual (mean and standard deviation) for the given satellite
 * at the grid point,
 */

typedef struct
{

  /**
   * space vehicle identifier
   */
  sbp_sv_id_t sv_id;
  /**
   * STEC residual[0.04 TECU]
   */
  s16 residual;
  /**
* stddev[modified DF389 scale; class is upper 3 bits, value is lower 5
stddev <= (3^class * (1 + value/16) - 1) * 10 TECU
]
   */
  u8 stddev;
} sbp_stec_residual_t;

/** Correction data for a single grid point.
 *
 * Contains one tropo delay, plus STEC residuals for each satellite at the
 * grid point.
 */

typedef struct
{

  /**
   * Index of the grid point
   */
  u16 index;
  /**
   * Wet and hydrostatic vertical delays
   */
  sbp_tropospheric_delay_correction_no_std_t tropo_delay_correction;
  /**
   * STEC residuals for each satellite
   */
  sbp_stec_residual_no_std_t stec_residuals[62];
  /**
   * Number of items in stec_residuals
   */
  u8 stec_residuals_count;
} sbp_grid_element_no_std_t;

/** Correction data for a single grid point.
 *
 * Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
 * stddev) for each satellite at the grid point.
 */

typedef struct
{

  /**
   * Index of the grid point
   */
  u16 index;
  /**
   * Wet and hydrostatic vertical delays (mean, stddev)
   */
  sbp_tropospheric_delay_correction_t tropo_delay_correction;
  /**
   * STEC residuals for each satellite (mean, stddev)
   */
  sbp_stec_residual_t stec_residuals[49];
  /**
   * Number of items in stec_residuals
   */
  u8 stec_residuals_count;
} sbp_grid_element_t;

/** Precise orbit and clock correction
 *
 * The precise orbit and clock correction message is
 * to be applied as a delta correction to broadcast
 * ephemeris and is an equivalent to the 1060 /1066
 * RTCM message types
 */
#define SBP_MSG_SSR_ORBIT_CLOCK 0x05DD

#define SBP_SSR_ORBIT_CLOCK_SID_CODE__MASK (0xff)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__SHIFT (0u)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GET(flags) \
  (((flags) >> SBP_SSR_ORBIT_CLOCK_SID_CODE__SHIFT) & SBP_SSR_ORBIT_CLOCK_SID_CODE__MASK)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_SSR_ORBIT_CLOCK_SID_CODE__MASK)) << (SBP_SSR_ORBIT_CLOCK_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GPS_L1CA (0)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GPS_L2CM (1)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__SBAS_L1CA (2)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GLO_L1CA (3)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GLO_L2CA (4)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GPS_L1P (5)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GPS_L2P (6)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__BDS2_B1 (12)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__BDS2_B2 (13)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GAL_E1B (14)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GAL_E7I (20)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__BDS3_B2A (47)
typedef struct
{

  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;
  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR correction. A change of Issue Of Data
   * SSR is used to indicate a change in the SSR
   * generating configuration
   */
  u8 iod_ssr;
  /**
   * Issue of broadcast ephemeris data or IODCRC (Beidou)
   */
  u32 iod;
  /**
   * Orbit radial delta correction[0.1 mm]
   */
  s32 radial;
  /**
   * Orbit along delta correction[0.4 mm]
   */
  s32 along;
  /**
   * Orbit along delta correction[0.4 mm]
   */
  s32 cross;
  /**
   * Velocity of orbit radial delta correction[0.001 mm/s]
   */
  s32 dot_radial;
  /**
   * Velocity of orbit along delta correction[0.004 mm/s]
   */
  s32 dot_along;
  /**
   * Velocity of orbit cross delta correction[0.004 mm/s]
   */
  s32 dot_cross;
  /**
   * C0 polynomial coefficient for correction of broadcast satellite clock[0.1 mm]
   */
  s32 c0;
  /**
   * C1 polynomial coefficient for correction of broadcast satellite clock[0.001 mm/s]
   */
  s32 c1;
  /**
   * C2 polynomial coefficient for correction of broadcast satellite clock[0.00002 mm/s^-2]
   */
  s32 c2;
} sbp_msg_ssr_orbit_clock_t;

/** Precise code biases correction
 *
 * The precise code biases message is to be added
 * to the pseudorange of the corresponding signal
 * to get corrected pseudorange. It is an
 * equivalent to the 1059 / 1065 RTCM message types
 */
#define SBP_MSG_SSR_CODE_BIASES 0x05E1

#define SBP_SSR_CODE_BIASES_SID_CODE__MASK (0xff)
#define SBP_SSR_CODE_BIASES_SID_CODE__SHIFT (0u)
#define SBP_SSR_CODE_BIASES_SID_CODE__GET(flags) \
  (((flags) >> SBP_SSR_CODE_BIASES_SID_CODE__SHIFT) & SBP_SSR_CODE_BIASES_SID_CODE__MASK)
#define SBP_SSR_CODE_BIASES_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_SSR_CODE_BIASES_SID_CODE__MASK)) << (SBP_SSR_CODE_BIASES_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_SSR_CODE_BIASES_SID_CODE__GPS_L1CA (0)
#define SBP_SSR_CODE_BIASES_SID_CODE__GPS_L2CM (1)
#define SBP_SSR_CODE_BIASES_SID_CODE__SBAS_L1CA (2)
#define SBP_SSR_CODE_BIASES_SID_CODE__GLO_L1CA (3)
#define SBP_SSR_CODE_BIASES_SID_CODE__GLO_L2CA (4)
#define SBP_SSR_CODE_BIASES_SID_CODE__GPS_L1P (5)
#define SBP_SSR_CODE_BIASES_SID_CODE__GPS_L2P (6)
#define SBP_SSR_CODE_BIASES_SID_CODE__BDS2_B1 (12)
#define SBP_SSR_CODE_BIASES_SID_CODE__BDS2_B2 (13)
#define SBP_SSR_CODE_BIASES_SID_CODE__GAL_E1B (14)
#define SBP_SSR_CODE_BIASES_SID_CODE__GAL_E7I (20)
#define SBP_SSR_CODE_BIASES_SID_CODE__BDS3_B2A (47)

typedef struct
{

  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;
  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR correction. A change of Issue Of Data
   * SSR is used to indicate a change in the SSR
   * generating configuration
   */
  u8 iod_ssr;
  /**
   * Code biases for the different satellite signals
   */
  sbp_code_biases_content_t biases[81];
  /**
   * Number of items in biases
   */
  u8 biases_count;
} sbp_msg_ssr_code_biases_t;

/** Precise phase biases correction
 *
 * The precise phase biases message contains the biases
 * to be added to the carrier phase of the corresponding
 * signal to get corrected carrier phase measurement, as
 * well as the satellite yaw angle to be applied to compute
 * the phase wind-up correction.
 * It is typically an equivalent to the 1265 RTCM message types
 */
#define SBP_MSG_SSR_PHASE_BIASES 0x05E6

#define SBP_SSR_PHASE_BIASES_SID_CODE__MASK (0xff)
#define SBP_SSR_PHASE_BIASES_SID_CODE__SHIFT (0u)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GET(flags) \
  (((flags) >> SBP_SSR_PHASE_BIASES_SID_CODE__SHIFT) & SBP_SSR_PHASE_BIASES_SID_CODE__MASK)
#define SBP_SSR_PHASE_BIASES_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_SSR_PHASE_BIASES_SID_CODE__MASK)) << (SBP_SSR_PHASE_BIASES_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_SSR_PHASE_BIASES_SID_CODE__GPS_L1CA (0)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GPS_L2CM (1)
#define SBP_SSR_PHASE_BIASES_SID_CODE__SBAS_L1CA (2)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GLO_L1CA (3)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GLO_L2CA (4)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GPS_L1P (5)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GPS_L2P (6)
#define SBP_SSR_PHASE_BIASES_SID_CODE__BDS2_B1 (12)
#define SBP_SSR_PHASE_BIASES_SID_CODE__BDS2_B2 (13)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GAL_E1B (14)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GAL_E7I (20)
#define SBP_SSR_PHASE_BIASES_SID_CODE__BDS3_B2A (47)

typedef struct
{

  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;
  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR correction. A change of Issue Of Data
   * SSR is used to indicate a change in the SSR
   * generating configuration
   */
  u8 iod_ssr;
  /**
   * Indicator for the dispersive phase biases property.
   */
  u8 dispersive_bias;
  /**
   * Consistency indicator for Melbourne-Wubbena linear combinations
   */
  u8 mw_consistency;
  /**
   * Satellite yaw angle[1 / 256 semi-circle]
   */
  u16 yaw;
  /**
   * Satellite yaw angle rate[1 / 8192 semi-circle / s]
   */
  s8 yaw_rate;
  /**
   * Phase biases corrections for a
   * satellite being tracked.
   */
  sbp_phase_biases_content_t biases[30];
  /**
   * Number of items in biases
   */
  u8 biases_count;
} sbp_msg_ssr_phase_biases_t;

/** STEC correction polynomial coeffcients.
 *
 * The Slant Total Electron Content per space vehicle, given as polynomial
 * approximation for a given tile. This should be combined with the
 * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
 * of the atmospheric delay.
 *
 * It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
 */
#define SBP_MSG_SSR_STEC_CORRECTION 0x05FB

typedef struct
{

  /**
   * Header of a STEC polynomial coeffcient message.
   */
  sbp_stec_header_t header;
  /**
   * Array of STEC polynomial coeffcients for each space vehicle.
   */
  sbp_stec_sat_element_t stec_sat_list[21];
  /**
   * Number of items in stec_sat_list
   */
  u8 stec_sat_list_count;
} sbp_msg_ssr_stec_correction_t;

/** Gridded troposphere and STEC correction residuals.
 *
 * STEC residuals are per space vehicle, troposphere is not.
 *
 * It is typically equivalent to the QZSS CLAS Sub Type 9 messages
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION 0x05FC

typedef struct
{

  /**
   * Header of a gridded correction message
   */
  sbp_gridded_correction_header_t header;
  /**
   * Tropo and STEC residuals for the given grid point.
   */
  struct
  {

    /**
     * Index of the grid point
     */
    u16 index;
    /**
     * Wet and hydrostatic vertical delays (mean, stddev)
     */
    sbp_tropospheric_delay_correction_t tropo_delay_correction;
    /**
     * STEC residuals for each satellite (mean, stddev)
     */
    sbp_stec_residual_t stec_residuals[46];
    /**
     * Number of items in stec_residuals
     */
    u8 stec_residuals_count;
  } element;
} sbp_msg_ssr_gridded_correction_t;

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
#define SBP_MSG_SSR_TILE_DEFINITION 0x05F6

typedef struct
{

  /**
   * Unique identifier of the tile set this tile belongs to.
   */
  u16 tile_set_id;
  /**
   * Unique identifier of this tile in the tile set.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
   */
  u16 tile_id;
  /**
   * North-West corner correction point latitude.
   *
   * The relation between the latitude X in the range [-90, 90] and
   * the coded number N is:
   *
   * N = floor((X / 90) * 2^14)
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.[encoded degrees]
   */
  s16 corner_nw_lat;
  /**
   * North-West corner correction point longtitude.
   *
   * The relation between the longtitude X in the range [-180, 180]
   * and the coded number N is:
   *
   * N = floor((X / 180) * 2^15)
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.[encoded degrees]
   */
  s16 corner_nw_lon;
  /**
   * Spacing of the correction points in the latitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.[0.01 degrees]
   */
  u16 spacing_lat;
  /**
   * Spacing of the correction points in the longtitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongtitude.[0.01 degrees]
   */
  u16 spacing_lon;
  /**
   * Number of steps in the latitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
   */
  u16 rows;
  /**
   * Number of steps in the longtitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongtitude.
   */
  u16 cols;
  /**
   * Specifies the availability of correction data at the
   * correction points in the array.
   *
   * If a specific bit is enabled (set to 1), the correction is not
   * available. Only the first rows * cols bits are used, the remainder
   * are set to 0. If there are more then 64 correction points the
   * remaining corrections are always available.
   *
   * Starting with the northwest corner of the array (top left on a
   * north oriented map) the correction points are enumerated with row
   * precedence - first row west to east, second row west to east,
   * until last row west to east - ending with the southeast corner of
   * the array.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but
   * note the definition of the bits is inverted.
   */
  u64 bitmask;
} sbp_msg_ssr_tile_definition_t;

/** Antenna phase center correction.
 *
 * Contains phase center offset and elevation variation corrections for one
 * signal on a satellite.
 */

#define SBP_SATELLITEAPC_SID_CODE__MASK (0xff)
#define SBP_SATELLITEAPC_SID_CODE__SHIFT (0u)
#define SBP_SATELLITEAPC_SID_CODE__GET(flags) \
  (((flags) >> SBP_SATELLITEAPC_SID_CODE__SHIFT) & SBP_SATELLITEAPC_SID_CODE__MASK)
#define SBP_SATELLITEAPC_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_SATELLITEAPC_SID_CODE__MASK)) << (SBP_SATELLITEAPC_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_SATELLITEAPC_SID_CODE__GPS_L1CA (0)
#define SBP_SATELLITEAPC_SID_CODE__GPS_L2CM (1)
#define SBP_SATELLITEAPC_SID_CODE__SBAS_L1CA (2)
#define SBP_SATELLITEAPC_SID_CODE__GLO_L1CA (3)
#define SBP_SATELLITEAPC_SID_CODE__GLO_L2CA (4)
#define SBP_SATELLITEAPC_SID_CODE__GPS_L1P (5)
#define SBP_SATELLITEAPC_SID_CODE__GPS_L2P (6)
#define SBP_SATELLITEAPC_SID_CODE__BDS2_B1 (12)
#define SBP_SATELLITEAPC_SID_CODE__BDS2_B2 (13)
#define SBP_SATELLITEAPC_SID_CODE__GAL_E1B (14)
#define SBP_SATELLITEAPC_SID_CODE__GAL_E7I (20)
#define SBP_SATELLITEAPC_SID_CODE__BDS3_B2A (47)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_MASK (0x1f)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_SHIFT (0u)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GET(flags) \
  (((flags) >> SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_SHIFT) & SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_MASK)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_MASK)) << (SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_SHIFT))); \
  } while (0)

#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_UNKNOWN_TYPE (0)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GPS_I (1)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GPS_II (2)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GPS_IIA (3)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GPS_IIR (4)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GPS_IIF (5)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GPS_III (6)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GLONASS (7)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GLONASS_M (8)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GLONASS_K1 (9)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_GALILEO (10)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_BEIDOU_2G (11)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_BEIDOU_2I (12)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_BEIDOU_2M (13)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3M_SECM (14)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3G_SECM (15)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3M_CAST (16)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3G_CAST (17)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3I_CAST (18)
#define SBP_SATELLITEAPC_SAT_INFO_SATELLITE_TYPE_QZSS (19)
typedef struct
{

  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;
  /**
   * Additional satellite information
   */
  u8 sat_info;
  /**
   * Satellite Code, as defined by IGS. Typically the space vehicle number.
   */
  u16 svn;
  /**
   * Mean phase center offset, X Y and Z axises. See IGS ANTEX file
   * format description for coordinate system definition.[1 mm]
   */
  s16 pco[3];
  /**
   * Elevation dependent phase center variations. First element is 0
   * degrees separation from the Z axis, subsequent elements represent
   * elevation variations in 1 degree increments.[1 mm]
   */
  s8 pcv[21];
} sbp_satellite_apc_t;

#define SBP_MSG_SSR_SATELLITE_APC 0x0604

#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__MASK (0xff)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__SHIFT (0u)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__GET(flags) \
  (((flags) >> SBP_SSR_SATELLITE_APC_APC_SID_CODE__SHIFT) & SBP_SSR_SATELLITE_APC_APC_SID_CODE__MASK)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_SSR_SATELLITE_APC_APC_SID_CODE__MASK)) << (SBP_SSR_SATELLITE_APC_APC_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__GPS_L1CA (0)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__GPS_L2CM (1)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__SBAS_L1CA (2)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__GLO_L1CA (3)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__GLO_L2CA (4)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__GPS_L1P (5)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__GPS_L2P (6)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__BDS2_B1 (12)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__BDS2_B2 (13)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__GAL_E1B (14)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__GAL_E7I (20)
#define SBP_SSR_SATELLITE_APC_APC_SID_CODE__BDS3_B2A (47)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_MASK (0x1f)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_SHIFT (0u)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GET(flags) \
  (((flags) >> SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_SHIFT) & \
   SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_MASK)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_MASK)) \
                 << (SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_SHIFT))); \
  } while (0)

#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_UNKNOWN_TYPE (0)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GPS_I (1)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GPS_II (2)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GPS_IIA (3)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GPS_IIR (4)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GPS_IIF (5)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GPS_III (6)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GLONASS (7)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GLONASS_M (8)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GLONASS_K1 (9)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_GALILEO (10)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_BEIDOU_2G (11)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_BEIDOU_2I (12)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_BEIDOU_2M (13)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3M_SECM (14)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3G_SECM (15)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3M_CAST (16)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3G_CAST (17)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_BEIDOU_3I_CAST (18)
#define SBP_SSR_SATELLITE_APC_APC_SAT_INFO_SATELLITE_TYPE_QZSS (19)
typedef struct
{

  /**
   * Satellite antenna phase center corrections
   */
  sbp_satellite_apc_t apc[7];
  /**
   * Number of items in apc
   */
  u8 apc_count;
} sbp_msg_ssr_satellite_apc_t;

#define SBP_MSG_SSR_ORBIT_CLOCK_DEP_A 0x05DC

#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__MASK (0xff)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SHIFT (0u)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GET(flags) \
  (((flags) >> SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SHIFT) & SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__MASK)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__MASK)) << (SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GPS_L1CA (0)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GPS_L2CM (1)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SBAS_L1CA (2)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GLO_L1CA (3)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GLO_L2CA (4)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GPS_L1P (5)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GPS_L2P (6)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__BDS2_B1 (12)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__BDS2_B2 (13)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GAL_E1B (14)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GAL_E7I (20)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__BDS3_B2A (47)
typedef struct
{

  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;
  /**
   * GNSS signal identifier (16 bit)
   */
  sbp_sbp_gnss_signal_t sid;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR correction. A change of Issue Of Data
   * SSR is used to indicate a change in the SSR
   * generating configuration
   */
  u8 iod_ssr;
  /**
   * Issue of broadcast ephemeris data
   */
  u8 iod;
  /**
   * Orbit radial delta correction[0.1 mm]
   */
  s32 radial;
  /**
   * Orbit along delta correction[0.4 mm]
   */
  s32 along;
  /**
   * Orbit along delta correction[0.4 mm]
   */
  s32 cross;
  /**
   * Velocity of orbit radial delta correction[0.001 mm/s]
   */
  s32 dot_radial;
  /**
   * Velocity of orbit along delta correction[0.004 mm/s]
   */
  s32 dot_along;
  /**
   * Velocity of orbit cross delta correction[0.004 mm/s]
   */
  s32 dot_cross;
  /**
   * C0 polynomial coefficient for correction of broadcast satellite clock[0.1 mm]
   */
  s32 c0;
  /**
   * C1 polynomial coefficient for correction of broadcast satellite clock[0.001 mm/s]
   */
  s32 c1;
  /**
   * C2 polynomial coefficient for correction of broadcast satellite clock[0.00002 mm/s^-2]
   */
  s32 c2;
} sbp_msg_ssr_orbit_clock_dep_a_t;

/** Header for MSG_SSR_STEC_CORRECTION_DEP message
 *
 * A full set of STEC information will likely span multiple SBP
 * messages, since SBP message a limited to 255 bytes.  The header
 * is used to tie multiple SBP messages into a sequence.
 */

typedef struct
{

  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;
  /**
   * Number of messages in the dataset
   */
  u8 num_msgs;
  /**
   * Position of this message in the dataset
   */
  u8 seq_num;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR atmospheric correction
   */
  u8 iod_atmo;
} sbp_stec_header_dep_a_t;

/** Header for MSG_SSR_GRIDDED_CORRECTION_DEP
 *
 * The 3GPP message contains nested variable length arrays
 * which are not suppported in SBP, so each grid point will
 * be identified by the index.
 */

typedef struct
{

  /**
   * GNSS reference time of the correction
   */
  sbp_gps_time_sec_t time;
  /**
   * Number of messages in the dataset
   */
  u16 num_msgs;
  /**
   * Position of this message in the dataset
   */
  u16 seq_num;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR atmospheric correction
   */
  u8 iod_atmo;
  /**
   * Quality of the troposphere data. Encoded following RTCM DF389
   * specifcation in units of m.
   */
  u8 tropo_quality_indicator;
} sbp_gridded_correction_header_dep_a_t;

/** Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
 *
 * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
 * Also includes an RLE encoded validity list.
 */

typedef struct
{

  /**
   * region_size (deg) = 10 / region_size_inverse
   * 0 is an invalid value.[inverse degrees]
   */
  u8 region_size_inverse;
  /**
   * grid height (deg) = grid width (deg) = area_width / region_size
   * 0 is an invalid value.
   */
  u16 area_width;
  /**
   * North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90
   */
  u16 lat_nw_corner_enc;
  /**
   * North-West corner longtitude (deg) = region_size * lon_nw_corner_enc - 180
   */
  u16 lon_nw_corner_enc;
  /**
   * Number of messages in the dataset
   */
  u8 num_msgs;
  /**
   * Postion of this message in the dataset
   */
  u8 seq_num;
} sbp_grid_definition_header_dep_a_t;

#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A 0x05EB

typedef struct
{

  /**
   * Header of a STEC message
   */
  sbp_stec_header_dep_a_t header;
  /**
   * Array of STEC information for each space vehicle
   */
  sbp_stec_sat_element_t stec_sat_list[22];
  /**
   * Number of items in stec_sat_list
   */
  u8 stec_sat_list_count;
} sbp_msg_ssr_stec_correction_dep_a_t;

#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A 0x05F0

typedef struct
{

  /**
   * Header of a Gridded Correction message
   */
  sbp_gridded_correction_header_dep_a_t header;
  /**
   * Tropo and STEC residuals for the given grid point
   */
  struct
  {

    /**
     * Index of the grid point
     */
    u16 index;
    /**
     * Wet and hydrostatic vertical delays
     */
    sbp_tropospheric_delay_correction_no_std_t tropo_delay_correction;
    /**
     * STEC residuals for each satellite
     */
    sbp_stec_residual_no_std_t stec_residuals[59];
    /**
     * Number of items in stec_residuals
     */
    u8 stec_residuals_count;
  } element;
} sbp_msg_ssr_gridded_correction_no_std_dep_a_t;

#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A 0x05FA

typedef struct
{

  /**
   * Header of a Gridded Correction message
   */
  sbp_gridded_correction_header_dep_a_t header;
  /**
   * Tropo and STEC residuals for the given grid point (mean
   * and standard deviation)
   */
  struct
  {

    /**
     * Index of the grid point
     */
    u16 index;
    /**
     * Wet and hydrostatic vertical delays (mean, stddev)
     */
    sbp_tropospheric_delay_correction_t tropo_delay_correction;
    /**
     * STEC residuals for each satellite (mean, stddev)
     */
    sbp_stec_residual_t stec_residuals[47];
    /**
     * Number of items in stec_residuals
     */
    u8 stec_residuals_count;
  } element;
} sbp_msg_ssr_gridded_correction_dep_a_t;

#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A 0x05F5

typedef struct
{

  /**
   * Header of a Gridded Correction message
   */
  sbp_grid_definition_header_dep_a_t header;
  /**
   * Run Length Encode list of quadrants that contain valid data.
   * The spec describes the encoding scheme in detail, but
   * essentially the index of the quadrants that contain transitions between
   * valid and invalid (and vice versa) are encoded as u8 integers.
   */
  u8 rle_list[246];
  /**
   * Number of items in rle_list
   */
  u8 rle_list_count;
} sbp_msg_ssr_grid_definition_dep_a_t;

#include <libsbp/unpacked/ssr_operators.h>
#include <libsbp/unpacked/ssr_packers.h>

#endif /* LIBSBP_SSR_MESSAGES_H */
