#ifndef LIBSBP_SSR_MESSAGES_H
#define LIBSBP_SSR_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;
/** SSR code biases corrections for a particular satellite
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 code;
  s16 value;
} sbp_code_biases_content_t;

size_t sbp_packed_size_sbp_code_biases_content_t(const sbp_code_biases_content_t *msg);
s8 sbp_pack_sbp_code_biases_content_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_code_biases_content_t *msg);
s8 sbp_unpack_sbp_code_biases_content_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_code_biases_content_t *msg);

int sbp_cmp_sbp_code_biases_content_t(const sbp_code_biases_content_t *a, const sbp_code_biases_content_t *b);


/** SSR phase biases corrections for a particular satellite
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

size_t sbp_packed_size_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *msg);
s8 sbp_pack_sbp_phase_biases_content_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_phase_biases_content_t *msg);
s8 sbp_unpack_sbp_phase_biases_content_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_phase_biases_content_t *msg);

int sbp_cmp_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *a, const sbp_phase_biases_content_t *b);


/** Header for the MSG_SSR_STEC_CORRECTION message
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

size_t sbp_packed_size_sbp_stec_header_t(const sbp_stec_header_t *msg);
s8 sbp_pack_sbp_stec_header_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_header_t *msg);
s8 sbp_unpack_sbp_stec_header_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_header_t *msg);

int sbp_cmp_sbp_stec_header_t(const sbp_stec_header_t *a, const sbp_stec_header_t *b);


/** Header for the MSG_SSR_GRIDDED_CORRECTION message
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

size_t sbp_packed_size_sbp_gridded_correction_header_t(const sbp_gridded_correction_header_t *msg);
s8 sbp_pack_sbp_gridded_correction_header_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gridded_correction_header_t *msg);
s8 sbp_unpack_sbp_gridded_correction_header_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gridded_correction_header_t *msg);

int sbp_cmp_sbp_gridded_correction_header_t(const sbp_gridded_correction_header_t *a, const sbp_gridded_correction_header_t *b);


/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sv_id_t sv_id;
  u8 stec_quality_indicator;
  s16 stec_coeff[4];
} sbp_stec_sat_element_t;

size_t sbp_packed_size_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *msg);
s8 sbp_pack_sbp_stec_sat_element_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_sat_element_t *msg);
s8 sbp_unpack_sbp_stec_sat_element_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_sat_element_t *msg);

int sbp_cmp_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *a, const sbp_stec_sat_element_t *b);


/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  s16 hydro;
  s8 wet;
} sbp_tropospheric_delay_correction_no_std_t;

size_t sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(const sbp_tropospheric_delay_correction_no_std_t *msg);
s8 sbp_pack_sbp_tropospheric_delay_correction_no_std_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_tropospheric_delay_correction_no_std_t *msg);
s8 sbp_unpack_sbp_tropospheric_delay_correction_no_std_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_tropospheric_delay_correction_no_std_t *msg);

int sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(const sbp_tropospheric_delay_correction_no_std_t *a, const sbp_tropospheric_delay_correction_no_std_t *b);


/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  s16 hydro;
  s8 wet;
  u8 stddev;
} sbp_tropospheric_delay_correction_t;

size_t sbp_packed_size_sbp_tropospheric_delay_correction_t(const sbp_tropospheric_delay_correction_t *msg);
s8 sbp_pack_sbp_tropospheric_delay_correction_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_tropospheric_delay_correction_t *msg);
s8 sbp_unpack_sbp_tropospheric_delay_correction_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_tropospheric_delay_correction_t *msg);

int sbp_cmp_sbp_tropospheric_delay_correction_t(const sbp_tropospheric_delay_correction_t *a, const sbp_tropospheric_delay_correction_t *b);


/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sv_id_t sv_id;
  s16 residual;
} sbp_stec_residual_no_std_t;

size_t sbp_packed_size_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *msg);
s8 sbp_pack_sbp_stec_residual_no_std_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_residual_no_std_t *msg);
s8 sbp_unpack_sbp_stec_residual_no_std_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_residual_no_std_t *msg);

int sbp_cmp_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *a, const sbp_stec_residual_no_std_t *b);


/** None
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sv_id_t sv_id;
  s16 residual;
  u8 stddev;
} sbp_stec_residual_t;

size_t sbp_packed_size_sbp_stec_residual_t(const sbp_stec_residual_t *msg);
s8 sbp_pack_sbp_stec_residual_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_residual_t *msg);
s8 sbp_unpack_sbp_stec_residual_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_residual_t *msg);

int sbp_cmp_sbp_stec_residual_t(const sbp_stec_residual_t *a, const sbp_stec_residual_t *b);


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

size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *msg);
s8 sbp_pack_sbp_msg_ssr_orbit_clock_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_orbit_clock_t *msg);
s8 sbp_unpack_sbp_msg_ssr_orbit_clock_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_orbit_clock_t *msg);
s8 sbp_send_sbp_msg_ssr_orbit_clock_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_orbit_clock_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *a, const sbp_msg_ssr_orbit_clock_t *b);


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

size_t sbp_packed_size_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *msg);
s8 sbp_pack_sbp_msg_ssr_code_biases_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_code_biases_t *msg);
s8 sbp_unpack_sbp_msg_ssr_code_biases_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_code_biases_t *msg);
s8 sbp_send_sbp_msg_ssr_code_biases_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_code_biases_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *a, const sbp_msg_ssr_code_biases_t *b);


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

size_t sbp_packed_size_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *msg);
s8 sbp_pack_sbp_msg_ssr_phase_biases_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_phase_biases_t *msg);
s8 sbp_unpack_sbp_msg_ssr_phase_biases_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_phase_biases_t *msg);
s8 sbp_send_sbp_msg_ssr_phase_biases_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_phase_biases_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *a, const sbp_msg_ssr_phase_biases_t *b);


/** STEC correction polynomial coeffcients
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SSR_STEC_CORRECTION                 0x05FB
typedef struct {
  sbp_stec_header_t header;
  sbp_stec_sat_element_t stec_sat_list[21];
  u8 n_stec_sat_list;
} sbp_msg_ssr_stec_correction_t;

size_t sbp_packed_size_sbp_msg_ssr_stec_correction_t(const sbp_msg_ssr_stec_correction_t *msg);
s8 sbp_pack_sbp_msg_ssr_stec_correction_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_stec_correction_t *msg);
s8 sbp_unpack_sbp_msg_ssr_stec_correction_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_stec_correction_t *msg);
s8 sbp_send_sbp_msg_ssr_stec_correction_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_stec_correction_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_stec_correction_t(const sbp_msg_ssr_stec_correction_t *a, const sbp_msg_ssr_stec_correction_t *b);


/** Gridded troposphere and STEC correction residuals
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

size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_t(const sbp_msg_ssr_gridded_correction_t *msg);
s8 sbp_pack_sbp_msg_ssr_gridded_correction_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_gridded_correction_t *msg);
s8 sbp_unpack_sbp_msg_ssr_gridded_correction_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_gridded_correction_t *msg);
s8 sbp_send_sbp_msg_ssr_gridded_correction_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_gridded_correction_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_gridded_correction_t(const sbp_msg_ssr_gridded_correction_t *a, const sbp_msg_ssr_gridded_correction_t *b);


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

size_t sbp_packed_size_sbp_msg_ssr_tile_definition_t(const sbp_msg_ssr_tile_definition_t *msg);
s8 sbp_pack_sbp_msg_ssr_tile_definition_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_tile_definition_t *msg);
s8 sbp_unpack_sbp_msg_ssr_tile_definition_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_tile_definition_t *msg);
s8 sbp_send_sbp_msg_ssr_tile_definition_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_tile_definition_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_tile_definition_t(const sbp_msg_ssr_tile_definition_t *a, const sbp_msg_ssr_tile_definition_t *b);


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
/** Antenna phase center correction
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

size_t sbp_packed_size_sbp_satellite_apc_t(const sbp_satellite_apc_t *msg);
s8 sbp_pack_sbp_satellite_apc_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_satellite_apc_t *msg);
s8 sbp_unpack_sbp_satellite_apc_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_satellite_apc_t *msg);

int sbp_cmp_sbp_satellite_apc_t(const sbp_satellite_apc_t *a, const sbp_satellite_apc_t *b);


#define SBP_MSG_SSR_SATELLITE_APC                   0x0604
typedef struct {
  sbp_satellite_apc_t apc[7];
  u8 n_apc;
} sbp_msg_ssr_satellite_apc_t;

size_t sbp_packed_size_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *msg);
s8 sbp_pack_sbp_msg_ssr_satellite_apc_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_satellite_apc_t *msg);
s8 sbp_unpack_sbp_msg_ssr_satellite_apc_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_satellite_apc_t *msg);
s8 sbp_send_sbp_msg_ssr_satellite_apc_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_satellite_apc_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *a, const sbp_msg_ssr_satellite_apc_t *b);


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

size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(const sbp_msg_ssr_orbit_clock_dep_a_t *msg);
s8 sbp_pack_sbp_msg_ssr_orbit_clock_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_orbit_clock_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_ssr_orbit_clock_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_orbit_clock_dep_a_t *msg);
s8 sbp_send_sbp_msg_ssr_orbit_clock_dep_a_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_orbit_clock_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(const sbp_msg_ssr_orbit_clock_dep_a_t *a, const sbp_msg_ssr_orbit_clock_dep_a_t *b);


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

size_t sbp_packed_size_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *msg);
s8 sbp_pack_sbp_stec_header_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_header_dep_a_t *msg);
s8 sbp_unpack_sbp_stec_header_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_header_dep_a_t *msg);

int sbp_cmp_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *a, const sbp_stec_header_dep_a_t *b);


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

size_t sbp_packed_size_sbp_gridded_correction_header_dep_a_t(const sbp_gridded_correction_header_dep_a_t *msg);
s8 sbp_pack_sbp_gridded_correction_header_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gridded_correction_header_dep_a_t *msg);
s8 sbp_unpack_sbp_gridded_correction_header_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gridded_correction_header_dep_a_t *msg);

int sbp_cmp_sbp_gridded_correction_header_dep_a_t(const sbp_gridded_correction_header_dep_a_t *a, const sbp_gridded_correction_header_dep_a_t *b);


/** Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages
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

size_t sbp_packed_size_sbp_grid_definition_header_dep_a_t(const sbp_grid_definition_header_dep_a_t *msg);
s8 sbp_pack_sbp_grid_definition_header_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_grid_definition_header_dep_a_t *msg);
s8 sbp_unpack_sbp_grid_definition_header_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_grid_definition_header_dep_a_t *msg);

int sbp_cmp_sbp_grid_definition_header_dep_a_t(const sbp_grid_definition_header_dep_a_t *a, const sbp_grid_definition_header_dep_a_t *b);


#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A           0x05EB
typedef struct {
  sbp_stec_header_dep_a_t header;
  sbp_stec_sat_element_t stec_sat_list[22];
  u8 n_stec_sat_list;
} sbp_msg_ssr_stec_correction_dep_a_t;

size_t sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(const sbp_msg_ssr_stec_correction_dep_a_t *msg);
s8 sbp_pack_sbp_msg_ssr_stec_correction_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_stec_correction_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_ssr_stec_correction_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_stec_correction_dep_a_t *msg);
s8 sbp_send_sbp_msg_ssr_stec_correction_dep_a_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_stec_correction_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(const sbp_msg_ssr_stec_correction_dep_a_t *a, const sbp_msg_ssr_stec_correction_dep_a_t *b);


#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A 0x05F0
typedef struct {
  sbp_gridded_correction_header_dep_a_t header;
  u16 index;
  sbp_tropospheric_delay_correction_no_std_t tropo_delay_correction;
  sbp_stec_residual_no_std_t stec_residuals[59];
  u8 n_stec_residuals;
} sbp_msg_ssr_gridded_correction_no_std_dep_a_t;

size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);
s8 sbp_pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);
s8 sbp_send_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *b);


#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A        0x05FA
typedef struct {
  sbp_gridded_correction_header_dep_a_t header;
  u16 index;
  sbp_tropospheric_delay_correction_t tropo_delay_correction;
  sbp_stec_residual_t stec_residuals[47];
  u8 n_stec_residuals;
} sbp_msg_ssr_gridded_correction_dep_a_t;

size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(const sbp_msg_ssr_gridded_correction_dep_a_t *msg);
s8 sbp_pack_sbp_msg_ssr_gridded_correction_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_gridded_correction_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_ssr_gridded_correction_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_gridded_correction_dep_a_t *msg);
s8 sbp_send_sbp_msg_ssr_gridded_correction_dep_a_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_gridded_correction_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(const sbp_msg_ssr_gridded_correction_dep_a_t *a, const sbp_msg_ssr_gridded_correction_dep_a_t *b);


#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A           0x05F5
typedef struct {
  sbp_grid_definition_header_dep_a_t header;
  u8 rle_list[246];
  u8 n_rle_list;
} sbp_msg_ssr_grid_definition_dep_a_t;

size_t sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(const sbp_msg_ssr_grid_definition_dep_a_t *msg);
s8 sbp_pack_sbp_msg_ssr_grid_definition_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_grid_definition_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_ssr_grid_definition_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_grid_definition_dep_a_t *msg);
s8 sbp_send_sbp_msg_ssr_grid_definition_dep_a_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_ssr_grid_definition_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(const sbp_msg_ssr_grid_definition_dep_a_t *a, const sbp_msg_ssr_grid_definition_dep_a_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_SSR_MESSAGES_H */
