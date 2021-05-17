#ifndef LIBSBP_SSR_MESSAGES_H
#define LIBSBP_SSR_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/gnss.h>
/** SSR code biases corrections for a particular satellite.
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 code;
  s16 value;
} sbp_code_biases_content_t;



/** SSR phase biases corrections for a particular satellite.
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 code;
  u8 integer_indicator;
  u8 widelane_integer_indicator;
  u8 discontinuity_counter;
  s32 bias;
} sbp_phase_biases_content_t;



/** Header for the MSG_SSR_STEC_CORRECTION message.
 *
((m.desc|commentify)))
 */
typedef struct {
  u16 tile_set_id;
  u16 tile_id;
  sbp_gps_time_sec_t time;
  u8 num_msgs;
  u8 seq_num;
  u8 update_interval;
  u8 iod_atmo;
} sbp_stec_header_t;



/** Header for the MSG_SSR_GRIDDED_CORRECTION message.
 *
((m.desc|commentify)))
 */
typedef struct {
  u16 tile_set_id;
  u16 tile_id;
  sbp_gps_time_sec_t time;
  u16 num_msgs;
  u16 seq_num;
  u8 update_interval;
  u8 iod_atmo;
  u8 tropo_quality_indicator;
} sbp_gridded_correction_header_t;



/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sv_id_t sv_id;
  u8 stec_quality_indicator;
  s16 stec_coeff[4];
} sbp_stec_sat_element_t;



/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  s16 hydro;
  s8 wet;
} sbp_tropospheric_delay_correction_no_std_t;



/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  s16 hydro;
  s8 wet;
  u8 stddev;
} sbp_tropospheric_delay_correction_t;



/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sv_id_t sv_id;
  s16 residual;
} sbp_stec_residual_no_std_t;



/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sv_id_t sv_id;
  s16 residual;
  u8 stddev;
} sbp_stec_residual_t;



/** Precise orbit and clock correction
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SSR_ORBIT_CLOCK                     0x05DD
typedef struct {
  sbp_gps_time_sec_t time;
  sbp_sbp_gnss_signal_t sid;
  u8 update_interval;
  u8 iod_ssr;
  u32 iod;
  s32 radial;
  s32 along;
  s32 cross;
  s32 dot_radial;
  s32 dot_along;
  s32 dot_cross;
  s32 c0;
  s32 c1;
  s32 c2;
} sbp_msg_ssr_orbit_clock_t;



/** Precise code biases correction
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SSR_CODE_BIASES                     0x05E1
typedef struct {
  sbp_gps_time_sec_t time;
  sbp_sbp_gnss_signal_t sid;
  u8 update_interval;
  u8 iod_ssr;
  sbp_code_biases_content_t biases[81];
  u8 n_biases;
} sbp_msg_ssr_code_biases_t;



/** Precise phase biases correction
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SSR_PHASE_BIASES                    0x05E6
typedef struct {
  sbp_gps_time_sec_t time;
  sbp_sbp_gnss_signal_t sid;
  u8 update_interval;
  u8 iod_ssr;
  u8 dispersive_bias;
  u8 mw_consistency;
  u16 yaw;
  s8 yaw_rate;
  sbp_phase_biases_content_t biases[30];
  u8 n_biases;
} sbp_msg_ssr_phase_biases_t;



/** STEC correction polynomial coeffcients.
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SSR_STEC_CORRECTION                 0x05FB
typedef struct {
  sbp_stec_header_t header;
  sbp_stec_sat_element_t stec_sat_list[21];
  u8 n_stec_sat_list;
} sbp_msg_ssr_stec_correction_t;



/** Gridded troposphere and STEC correction residuals.
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION              0x05FC
typedef struct {
  sbp_gridded_correction_header_t header;
  u16 index;
  sbp_tropospheric_delay_correction_t tropo_delay_correction;
  sbp_stec_residual_t stec_residuals[46];
  u8 n_stec_residuals;
} sbp_msg_ssr_gridded_correction_t;



/** Definition of a SSR atmospheric correction tile.

 *
((m.desc|commentify)))
 */
#define SBP_MSG_SSR_TILE_DEFINITION                 0x05F6
typedef struct {
  u16 tile_set_id;
  u16 tile_id;
  s16 corner_nw_lat;
  s16 corner_nw_lon;
  u16 spacing_lat;
  u16 spacing_lon;
  u16 rows;
  u16 cols;
  u64 bitmask;
} sbp_msg_ssr_tile_definition_t;



#define SBP_SATELLITEAPC_SATELLITE_TYPE_MASK (0x1f)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT (0u)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GET(flags) \
                             (((flags) >> SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT) \
                             & SBP_SATELLITEAPC_SATELLITE_TYPE_MASK)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SATELLITEAPC_SATELLITE_TYPE_MASK)) \
                             << (SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT)));} while(0)
                             

#define SBP_SATELLITEAPC_SATELLITE_TYPE_UNKNOWN_TYPE (0)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_I (1)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_II (2)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_IIA (3)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_IIR (4)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_IIF (5)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_III (6)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GLONASS (7)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GLONASS_M (8)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GLONASS_K1 (9)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GALILEO (10)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_2G (11)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_2I (12)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_2M (13)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3M_SECM (14)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3G_SECM (15)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3M_CAST (16)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3G_CAST (17)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3I_CAST (18)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_QZSS (19)
/** Antenna phase center correction.
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sbp_gnss_signal_t sid;
  u8 sat_info;
  u16 svn;
  s16 pco[3];
  s8 pcv[21];
} sbp_satellite_apc_t;



#define SBP_MSG_SSR_SATELLITE_APC                   0x0604
typedef struct {
  sbp_satellite_apc_t apc[7];
  u8 n_apc;
} sbp_msg_ssr_satellite_apc_t;



#define SBP_MSG_SSR_ORBIT_CLOCK_DEP_A               0x05DC
typedef struct {
  sbp_gps_time_sec_t time;
  sbp_sbp_gnss_signal_t sid;
  u8 update_interval;
  u8 iod_ssr;
  u8 iod;
  s32 radial;
  s32 along;
  s32 cross;
  s32 dot_radial;
  s32 dot_along;
  s32 dot_cross;
  s32 c0;
  s32 c1;
  s32 c2;
} sbp_msg_ssr_orbit_clock_dep_a_t;



/** Header for MSG_SSR_STEC_CORRECTION_DEP message
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_gps_time_sec_t time;
  u8 num_msgs;
  u8 seq_num;
  u8 update_interval;
  u8 iod_atmo;
} sbp_stec_header_dep_a_t;



/** Header for MSG_SSR_GRIDDED_CORRECTION_DEP
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_gps_time_sec_t time;
  u16 num_msgs;
  u16 seq_num;
  u8 update_interval;
  u8 iod_atmo;
  u8 tropo_quality_indicator;
} sbp_gridded_correction_header_dep_a_t;



/** Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 region_size_inverse;
  u16 area_width;
  u16 lat_nw_corner_enc;
  u16 lon_nw_corner_enc;
  u8 num_msgs;
  u8 seq_num;
} sbp_grid_definition_header_dep_a_t;



#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A           0x05EB
typedef struct {
  sbp_stec_header_dep_a_t header;
  sbp_stec_sat_element_t stec_sat_list[22];
  u8 n_stec_sat_list;
} sbp_msg_ssr_stec_correction_dep_a_t;



#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A 0x05F0
typedef struct {
  sbp_gridded_correction_header_dep_a_t header;
  u16 index;
  sbp_tropospheric_delay_correction_no_std_t tropo_delay_correction;
  sbp_stec_residual_no_std_t stec_residuals[59];
  u8 n_stec_residuals;
} sbp_msg_ssr_gridded_correction_no_std_dep_a_t;



#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A        0x05FA
typedef struct {
  sbp_gridded_correction_header_dep_a_t header;
  u16 index;
  sbp_tropospheric_delay_correction_t tropo_delay_correction;
  sbp_stec_residual_t stec_residuals[47];
  u8 n_stec_residuals;
} sbp_msg_ssr_gridded_correction_dep_a_t;



#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A           0x05F5
typedef struct {
  sbp_grid_definition_header_dep_a_t header;
  u8 rle_list[246];
  u8 n_rle_list;
} sbp_msg_ssr_grid_definition_dep_a_t;




#include <libsbp/unpacked/ssr_operators.h>
#include <libsbp/unpacked/ssr_packers.h>

#endif /* LIBSBP_SSR_MESSAGES_H */
