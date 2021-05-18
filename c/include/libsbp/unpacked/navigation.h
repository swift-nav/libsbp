#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#define LIBSBP_NAVIGATION_MESSAGES_H

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

#ifdef __cplusplus
  extern "C" {
#endif
#define SBP_GPS_TIME_TIME_SOURCE_MASK (0x7)
#define SBP_GPS_TIME_TIME_SOURCE_SHIFT (0u)
#define SBP_GPS_TIME_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_GPS_TIME_TIME_SOURCE_SHIFT) \
                             & SBP_GPS_TIME_TIME_SOURCE_MASK)
#define SBP_GPS_TIME_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GPS_TIME_TIME_SOURCE_MASK)) \
                             << (SBP_GPS_TIME_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_GPS_TIME_TIME_SOURCE_NONE (0)
#define SBP_GPS_TIME_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_GPS_TIME_TIME_SOURCE_PROPAGATED (2)
/** GPS Time
 *
((m.desc|commentify)))
 */
#define SBP_MSG_GPS_TIME               0x0102
typedef struct {
  u16 wn;
  u32 tow;
  s32 ns_residual;
  u8 flags;
} sbp_msg_gps_time_t;

size_t sbp_packed_size_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *msg);
s8 sbp_pack_sbp_msg_gps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_gps_time_t *msg);
s8 sbp_unpack_sbp_msg_gps_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_gps_time_t *msg);

int sbp_cmp_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *a, const sbp_msg_gps_time_t *b);


#define SBP_GPS_TIME_GNSS_TIME_SOURCE_MASK (0x7)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_SHIFT (0u)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_GPS_TIME_GNSS_TIME_SOURCE_SHIFT) \
                             & SBP_GPS_TIME_GNSS_TIME_SOURCE_MASK)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GPS_TIME_GNSS_TIME_SOURCE_MASK)) \
                             << (SBP_GPS_TIME_GNSS_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_GPS_TIME_GNSS_TIME_SOURCE_NONE (0)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_PROPAGATED (2)
/** GPS Time
 *
((m.desc|commentify)))
 */
#define SBP_MSG_GPS_TIME_GNSS          0x0104
typedef struct {
  u16 wn;
  u32 tow;
  s32 ns_residual;
  u8 flags;
} sbp_msg_gps_time_gnss_t;

size_t sbp_packed_size_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *msg);
s8 sbp_pack_sbp_msg_gps_time_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_gps_time_gnss_t *msg);
s8 sbp_unpack_sbp_msg_gps_time_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_gps_time_gnss_t *msg);

int sbp_cmp_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *a, const sbp_msg_gps_time_gnss_t *b);


#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_MASK (0x3)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_SHIFT (3u)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_GET(flags) \
                             (((flags) >> SBP_UTC_TIME_UTC_OFFSET_SOURCE_SHIFT) \
                             & SBP_UTC_TIME_UTC_OFFSET_SOURCE_MASK)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_UTC_TIME_UTC_OFFSET_SOURCE_MASK)) \
                             << (SBP_UTC_TIME_UTC_OFFSET_SOURCE_SHIFT)));} while(0)
                             

#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_FACTORY_DEFAULT (0)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_NON_VOLATILE_MEMORY (1)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_DECODED_THIS_SESSION (2)
#define SBP_UTC_TIME_TIME_SOURCE_MASK (0x7)
#define SBP_UTC_TIME_TIME_SOURCE_SHIFT (0u)
#define SBP_UTC_TIME_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_UTC_TIME_TIME_SOURCE_SHIFT) \
                             & SBP_UTC_TIME_TIME_SOURCE_MASK)
#define SBP_UTC_TIME_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_UTC_TIME_TIME_SOURCE_MASK)) \
                             << (SBP_UTC_TIME_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_UTC_TIME_TIME_SOURCE_NONE (0)
#define SBP_UTC_TIME_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_UTC_TIME_TIME_SOURCE_PROPAGATED (2)
/** UTC Time
 *
((m.desc|commentify)))
 */
#define SBP_MSG_UTC_TIME               0x0103
typedef struct {
  u8 flags;
  u32 tow;
  u16 year;
  u8 month;
  u8 day;
  u8 hours;
  u8 minutes;
  u8 seconds;
  u32 ns;
} sbp_msg_utc_time_t;

size_t sbp_packed_size_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *msg);
s8 sbp_pack_sbp_msg_utc_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_utc_time_t *msg);
s8 sbp_unpack_sbp_msg_utc_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_utc_time_t *msg);

int sbp_cmp_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *a, const sbp_msg_utc_time_t *b);


#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_MASK (0x3)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_SHIFT (3u)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_GET(flags) \
                             (((flags) >> SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_SHIFT) \
                             & SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_MASK)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_MASK)) \
                             << (SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_SHIFT)));} while(0)
                             

#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_FACTORY_DEFAULT (0)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_NON_VOLATILE_MEMORY (1)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_DECODED_THIS_SESSION (2)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_MASK (0x7)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_SHIFT (0u)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_UTC_TIME_GNSS_TIME_SOURCE_SHIFT) \
                             & SBP_UTC_TIME_GNSS_TIME_SOURCE_MASK)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_UTC_TIME_GNSS_TIME_SOURCE_MASK)) \
                             << (SBP_UTC_TIME_GNSS_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_UTC_TIME_GNSS_TIME_SOURCE_NONE (0)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_PROPAGATED (2)
/** UTC Time
 *
((m.desc|commentify)))
 */
#define SBP_MSG_UTC_TIME_GNSS          0x0105
typedef struct {
  u8 flags;
  u32 tow;
  u16 year;
  u8 month;
  u8 day;
  u8 hours;
  u8 minutes;
  u8 seconds;
  u32 ns;
} sbp_msg_utc_time_gnss_t;

size_t sbp_packed_size_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *msg);
s8 sbp_pack_sbp_msg_utc_time_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_utc_time_gnss_t *msg);
s8 sbp_unpack_sbp_msg_utc_time_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_utc_time_gnss_t *msg);

int sbp_cmp_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *a, const sbp_msg_utc_time_gnss_t *b);


#define SBP_DOPS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_DOPS_RAIM_REPAIR_FLAG_SHIFT (7u)
#define SBP_DOPS_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_DOPS_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_DOPS_RAIM_REPAIR_FLAG_MASK)
#define SBP_DOPS_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_DOPS_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_DOPS_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_DOPS_FIX_MODE_MASK (0x7)
#define SBP_DOPS_FIX_MODE_SHIFT (0u)
#define SBP_DOPS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_DOPS_FIX_MODE_SHIFT) \
                             & SBP_DOPS_FIX_MODE_MASK)
#define SBP_DOPS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_DOPS_FIX_MODE_MASK)) \
                             << (SBP_DOPS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_DOPS_FIX_MODE_INVALID (0)
#define SBP_DOPS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_DOPS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_DOPS_FIX_MODE_FLOAT_RTK (3)
#define SBP_DOPS_FIX_MODE_FIXED_RTK (4)
#define SBP_DOPS_FIX_MODE_UNDEFINED (5)
#define SBP_DOPS_FIX_MODE_SBAS_POSITION (6)
/** Dilution of Precision
 *
((m.desc|commentify)))
 */
#define SBP_MSG_DOPS                   0x0208
typedef struct {
  u32 tow;
  u16 gdop;
  u16 pdop;
  u16 tdop;
  u16 hdop;
  u16 vdop;
  u8 flags;
} sbp_msg_dops_t;

size_t sbp_packed_size_sbp_msg_dops_t(const sbp_msg_dops_t *msg);
s8 sbp_pack_sbp_msg_dops_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_dops_t *msg);
s8 sbp_unpack_sbp_msg_dops_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_dops_t *msg);

int sbp_cmp_sbp_msg_dops_t(const sbp_msg_dops_t *a, const sbp_msg_dops_t *b);


#define SBP_POS_ECEF_TOW_TYPE_MASK (0x1)
#define SBP_POS_ECEF_TOW_TYPE_SHIFT (5u)
#define SBP_POS_ECEF_TOW_TYPE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_TOW_TYPE_SHIFT) \
                             & SBP_POS_ECEF_TOW_TYPE_MASK)
#define SBP_POS_ECEF_TOW_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_TOW_TYPE_MASK)) \
                             << (SBP_POS_ECEF_TOW_TYPE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_TOW_TYPE_TIME_OF_MEASUREMENT (0)
#define SBP_POS_ECEF_TOW_TYPE_OTHER (1)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_SHIFT) \
                             & SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_MASK)) \
                             << (SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_ECEF_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_FIX_MODE_MASK)
#define SBP_POS_ECEF_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_ECEF_FIX_MODE_SBAS_POSITION (6)
/** Single-point position in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_ECEF               0x0209
typedef struct {
  u32 tow;
  double x;
  double y;
  double z;
  u16 accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_ecef_t;

size_t sbp_packed_size_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *msg);
s8 sbp_pack_sbp_msg_pos_ecef_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_t *msg);
s8 sbp_unpack_sbp_msg_pos_ecef_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_t *msg);

int sbp_cmp_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *a, const sbp_msg_pos_ecef_t *b);


#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_SHIFT) \
                             & SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_MASK)) \
                             << (SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_ECEF_COV_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_COV_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_COV_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_COV_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_COV_FIX_MODE_MASK)
#define SBP_POS_ECEF_COV_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_COV_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_COV_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_COV_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_COV_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_COV_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_COV_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_COV_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_COV_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_ECEF_COV_FIX_MODE_SBAS_POSITION (6)
/** Single-point position in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_ECEF_COV           0x0214
typedef struct {
  u32 tow;
  double x;
  double y;
  double z;
  float cov_x_x;
  float cov_x_y;
  float cov_x_z;
  float cov_y_y;
  float cov_y_z;
  float cov_z_z;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_ecef_cov_t;

size_t sbp_packed_size_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *msg);
s8 sbp_pack_sbp_msg_pos_ecef_cov_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_cov_t *msg);
s8 sbp_unpack_sbp_msg_pos_ecef_cov_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_cov_t *msg);

int sbp_cmp_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *a, const sbp_msg_pos_ecef_cov_t *b);


#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_POS_LLH_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_POS_LLH_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_POS_LLH_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SHIFT) \
                             & SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_MASK)) \
                             << (SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_LLH_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_FIX_MODE_MASK)
#define SBP_POS_LLH_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_FIX_MODE_SBAS_POSITION (6)
/** Geodetic Position
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_LLH                0x020A
typedef struct {
  u32 tow;
  double lat;
  double lon;
  double height;
  u16 h_accuracy;
  u16 v_accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_llh_t;

size_t sbp_packed_size_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *msg);
s8 sbp_pack_sbp_msg_pos_llh_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_t *msg);
s8 sbp_unpack_sbp_msg_pos_llh_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_t *msg);

int sbp_cmp_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *a, const sbp_msg_pos_llh_t *b);


#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_SHIFT) \
                             & SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_MASK)) \
                             << (SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_LLH_COV_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_COV_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_COV_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_COV_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_COV_FIX_MODE_MASK)
#define SBP_POS_LLH_COV_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_COV_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_COV_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_COV_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_COV_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_COV_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_COV_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_COV_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_COV_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_COV_FIX_MODE_SBAS_POSITION (6)
/** Geodetic Position
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_LLH_COV            0x0211
typedef struct {
  u32 tow;
  double lat;
  double lon;
  double height;
  float cov_n_n;
  float cov_n_e;
  float cov_n_d;
  float cov_e_e;
  float cov_e_d;
  float cov_d_d;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_llh_cov_t;

size_t sbp_packed_size_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *msg);
s8 sbp_pack_sbp_msg_pos_llh_cov_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_cov_t *msg);
s8 sbp_unpack_sbp_msg_pos_llh_cov_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_cov_t *msg);

int sbp_cmp_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *a, const sbp_msg_pos_llh_cov_t *b);


#define SBP_BASELINE_ECEF_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_ECEF_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_ECEF_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_ECEF_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_ECEF_FIX_MODE_MASK)
#define SBP_BASELINE_ECEF_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_ECEF_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_ECEF_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_ECEF_FIX_MODE_INVALID (0)
#define SBP_BASELINE_ECEF_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_ECEF_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_ECEF_FIX_MODE_FIXED_RTK (4)
/** Baseline Position in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BASELINE_ECEF          0x020B
typedef struct {
  u32 tow;
  s32 x;
  s32 y;
  s32 z;
  u16 accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_baseline_ecef_t;

size_t sbp_packed_size_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *msg);
s8 sbp_pack_sbp_msg_baseline_ecef_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_ecef_t *msg);
s8 sbp_unpack_sbp_msg_baseline_ecef_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_ecef_t *msg);

int sbp_cmp_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *a, const sbp_msg_baseline_ecef_t *b);


#define SBP_BASELINE_NED_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_NED_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_NED_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_NED_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_NED_FIX_MODE_MASK)
#define SBP_BASELINE_NED_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_NED_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_NED_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_NED_FIX_MODE_INVALID (0)
#define SBP_BASELINE_NED_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_NED_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_NED_FIX_MODE_FIXED_RTK (4)
/** Baseline in NED
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BASELINE_NED           0x020C
typedef struct {
  u32 tow;
  s32 n;
  s32 e;
  s32 d;
  u16 h_accuracy;
  u16 v_accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_baseline_ned_t;

size_t sbp_packed_size_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *msg);
s8 sbp_pack_sbp_msg_baseline_ned_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_ned_t *msg);
s8 sbp_unpack_sbp_msg_baseline_ned_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_ned_t *msg);

int sbp_cmp_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *a, const sbp_msg_baseline_ned_t *b);


#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_ECEF_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_ECEF_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_ECEF_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_ECEF_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_ECEF_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_ECEF_VELOCITY_MODE_DEAD_RECKONING (3)
/** Velocity in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_ECEF               0x020D
typedef struct {
  u32 tow;
  s32 x;
  s32 y;
  s32 z;
  u16 accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ecef_t;

size_t sbp_packed_size_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *msg);
s8 sbp_pack_sbp_msg_vel_ecef_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_t *msg);
s8 sbp_unpack_sbp_msg_vel_ecef_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_t *msg);

int sbp_cmp_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *a, const sbp_msg_vel_ecef_t *b);


#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_COV_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_ECEF_COV_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_COV_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_ECEF_COV_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_COV_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_DEAD_RECKONING (3)
/** Velocity in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_ECEF_COV           0x0215
typedef struct {
  u32 tow;
  s32 x;
  s32 y;
  s32 z;
  float cov_x_x;
  float cov_x_y;
  float cov_x_z;
  float cov_y_y;
  float cov_y_z;
  float cov_z_z;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ecef_cov_t;

size_t sbp_packed_size_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *msg);
s8 sbp_pack_sbp_msg_vel_ecef_cov_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_cov_t *msg);
s8 sbp_unpack_sbp_msg_vel_ecef_cov_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_cov_t *msg);

int sbp_cmp_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *a, const sbp_msg_vel_ecef_cov_t *b);


#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_VEL_NED_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_VEL_NED_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_VEL_NED_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_NED_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_NED_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_NED_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_NED_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_NED_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_NED_VELOCITY_MODE_DEAD_RECKONING (3)
/** Velocity in NED
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_NED                0x020E
typedef struct {
  u32 tow;
  s32 n;
  s32 e;
  s32 d;
  u16 h_accuracy;
  u16 v_accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ned_t;

size_t sbp_packed_size_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *msg);
s8 sbp_pack_sbp_msg_vel_ned_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_t *msg);
s8 sbp_unpack_sbp_msg_vel_ned_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_t *msg);

int sbp_cmp_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *a, const sbp_msg_vel_ned_t *b);


#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_COV_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_NED_COV_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_COV_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_NED_COV_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_NED_COV_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_COV_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_COV_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_COV_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_NED_COV_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_COV_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_COV_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_NED_COV_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_COV_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_COV_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_COV_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_NED_COV_VELOCITY_MODE_DEAD_RECKONING (3)
/** Velocity in NED
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_NED_COV            0x0212
typedef struct {
  u32 tow;
  s32 n;
  s32 e;
  s32 d;
  float cov_n_n;
  float cov_n_e;
  float cov_n_d;
  float cov_e_e;
  float cov_e_d;
  float cov_d_d;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ned_cov_t;

size_t sbp_packed_size_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *msg);
s8 sbp_pack_sbp_msg_vel_ned_cov_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_cov_t *msg);
s8 sbp_unpack_sbp_msg_vel_ned_cov_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_cov_t *msg);

int sbp_cmp_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *a, const sbp_msg_vel_ned_cov_t *b);


#define SBP_POS_ECEF_GNSS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_GNSS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_GNSS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_GNSS_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_GNSS_FIX_MODE_MASK)
#define SBP_POS_ECEF_GNSS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_GNSS_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_GNSS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_GNSS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_GNSS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_GNSS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_GNSS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_GNSS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_GNSS_FIX_MODE_SBAS_POSITION (6)
/** GNSS-only Position in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_ECEF_GNSS          0x0229
typedef struct {
  u32 tow;
  double x;
  double y;
  double z;
  u16 accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_ecef_gnss_t;

size_t sbp_packed_size_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *msg);
s8 sbp_pack_sbp_msg_pos_ecef_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_gnss_t *msg);
s8 sbp_unpack_sbp_msg_pos_ecef_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_gnss_t *msg);

int sbp_cmp_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *a, const sbp_msg_pos_ecef_gnss_t *b);


#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_COV_GNSS_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_COV_GNSS_FIX_MODE_MASK)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_COV_GNSS_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_COV_GNSS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_SBAS_POSITION (6)
/** GNSS-only Position in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_ECEF_COV_GNSS      0x0234
typedef struct {
  u32 tow;
  double x;
  double y;
  double z;
  float cov_x_x;
  float cov_x_y;
  float cov_x_z;
  float cov_y_y;
  float cov_y_z;
  float cov_z_z;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_ecef_cov_gnss_t;

size_t sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *msg);
s8 sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_cov_gnss_t *msg);
s8 sbp_unpack_sbp_msg_pos_ecef_cov_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_cov_gnss_t *msg);

int sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *a, const sbp_msg_pos_ecef_cov_gnss_t *b);


#define SBP_POS_LLH_GNSS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_GNSS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_GNSS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_GNSS_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_GNSS_FIX_MODE_MASK)
#define SBP_POS_LLH_GNSS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_GNSS_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_GNSS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_GNSS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_GNSS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_GNSS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_GNSS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_GNSS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_GNSS_FIX_MODE_SBAS_POSITION (6)
/** GNSS-only Geodetic Position
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_LLH_GNSS           0x022A
typedef struct {
  u32 tow;
  double lat;
  double lon;
  double height;
  u16 h_accuracy;
  u16 v_accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_llh_gnss_t;

size_t sbp_packed_size_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *msg);
s8 sbp_pack_sbp_msg_pos_llh_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_gnss_t *msg);
s8 sbp_unpack_sbp_msg_pos_llh_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_gnss_t *msg);

int sbp_cmp_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *a, const sbp_msg_pos_llh_gnss_t *b);


#define SBP_POS_LLH_COV_GNSS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_COV_GNSS_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_COV_GNSS_FIX_MODE_MASK)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_COV_GNSS_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_COV_GNSS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_COV_GNSS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_SBAS_POSITION (6)
/** GNSS-only Geodetic Position
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_LLH_COV_GNSS       0x0231
typedef struct {
  u32 tow;
  double lat;
  double lon;
  double height;
  float cov_n_n;
  float cov_n_e;
  float cov_n_d;
  float cov_e_e;
  float cov_e_d;
  float cov_d_d;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_llh_cov_gnss_t;

size_t sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *msg);
s8 sbp_pack_sbp_msg_pos_llh_cov_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_cov_gnss_t *msg);
s8 sbp_unpack_sbp_msg_pos_llh_cov_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_cov_gnss_t *msg);

int sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *a, const sbp_msg_pos_llh_cov_gnss_t *b);


#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_GNSS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_ECEF_GNSS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_GNSS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_ECEF_GNSS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
/** GNSS-only Velocity in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_ECEF_GNSS          0x022D
typedef struct {
  u32 tow;
  s32 x;
  s32 y;
  s32 z;
  u16 accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ecef_gnss_t;

size_t sbp_packed_size_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *msg);
s8 sbp_pack_sbp_msg_vel_ecef_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_gnss_t *msg);
s8 sbp_unpack_sbp_msg_vel_ecef_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_gnss_t *msg);

int sbp_cmp_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *a, const sbp_msg_vel_ecef_gnss_t *b);


#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
/** GNSS-only Velocity in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_ECEF_COV_GNSS      0x0235
typedef struct {
  u32 tow;
  s32 x;
  s32 y;
  s32 z;
  float cov_x_x;
  float cov_x_y;
  float cov_x_z;
  float cov_y_y;
  float cov_y_z;
  float cov_z_z;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ecef_cov_gnss_t;

size_t sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *msg);
s8 sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_cov_gnss_t *msg);
s8 sbp_unpack_sbp_msg_vel_ecef_cov_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_cov_gnss_t *msg);

int sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *a, const sbp_msg_vel_ecef_cov_gnss_t *b);


#define SBP_VEL_NED_GNSS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_GNSS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_NED_GNSS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_GNSS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_NED_GNSS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_GNSS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
/** GNSS-only Velocity in NED
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_NED_GNSS           0x022E
typedef struct {
  u32 tow;
  s32 n;
  s32 e;
  s32 d;
  u16 h_accuracy;
  u16 v_accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ned_gnss_t;

size_t sbp_packed_size_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *msg);
s8 sbp_pack_sbp_msg_vel_ned_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_gnss_t *msg);
s8 sbp_unpack_sbp_msg_vel_ned_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_gnss_t *msg);

int sbp_cmp_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *a, const sbp_msg_vel_ned_gnss_t *b);


#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
/** GNSS-only Velocity in NED
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_NED_COV_GNSS       0x0232
typedef struct {
  u32 tow;
  s32 n;
  s32 e;
  s32 d;
  float cov_n_n;
  float cov_n_e;
  float cov_n_d;
  float cov_e_e;
  float cov_e_d;
  float cov_d_d;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ned_cov_gnss_t;

size_t sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *msg);
s8 sbp_pack_sbp_msg_vel_ned_cov_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_cov_gnss_t *msg);
s8 sbp_unpack_sbp_msg_vel_ned_cov_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_cov_gnss_t *msg);

int sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *a, const sbp_msg_vel_ned_cov_gnss_t *b);


#define SBP_VEL_BODY_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_BODY_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_BODY_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_BODY_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_BODY_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_BODY_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_BODY_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_BODY_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_BODY_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_BODY_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_BODY_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_BODY_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_BODY_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_BODY_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_BODY_VELOCITY_MODE_MASK)
#define SBP_VEL_BODY_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_BODY_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_BODY_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_BODY_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_BODY_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_BODY_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_BODY_VELOCITY_MODE_DEAD_RECKONING (3)
/** Velocity in User Frame
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_BODY               0x0213
typedef struct {
  u32 tow;
  s32 x;
  s32 y;
  s32 z;
  float cov_x_x;
  float cov_x_y;
  float cov_x_z;
  float cov_y_y;
  float cov_y_z;
  float cov_z_z;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_body_t;

size_t sbp_packed_size_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *msg);
s8 sbp_pack_sbp_msg_vel_body_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_body_t *msg);
s8 sbp_unpack_sbp_msg_vel_body_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_body_t *msg);

int sbp_cmp_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *a, const sbp_msg_vel_body_t *b);


/** Age of corrections
 *
((m.desc|commentify)))
 */
#define SBP_MSG_AGE_CORRECTIONS        0x0210
typedef struct {
  u32 tow;
  u16 age;
} sbp_msg_age_corrections_t;

size_t sbp_packed_size_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *msg);
s8 sbp_pack_sbp_msg_age_corrections_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_age_corrections_t *msg);
s8 sbp_unpack_sbp_msg_age_corrections_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_age_corrections_t *msg);

int sbp_cmp_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *a, const sbp_msg_age_corrections_t *b);


/** GPS Time (v1.0)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_GPS_TIME_DEP_A         0x0100
typedef struct {
  u16 wn;
  u32 tow;
  s32 ns_residual;
  u8 flags;
} sbp_msg_gps_time_dep_a_t;

size_t sbp_packed_size_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *msg);
s8 sbp_pack_sbp_msg_gps_time_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_gps_time_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_gps_time_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_gps_time_dep_a_t *msg);

int sbp_cmp_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *a, const sbp_msg_gps_time_dep_a_t *b);


/** Dilution of Precision
 *
((m.desc|commentify)))
 */
#define SBP_MSG_DOPS_DEP_A             0x0206
typedef struct {
  u32 tow;
  u16 gdop;
  u16 pdop;
  u16 tdop;
  u16 hdop;
  u16 vdop;
} sbp_msg_dops_dep_a_t;

size_t sbp_packed_size_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *msg);
s8 sbp_pack_sbp_msg_dops_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_dops_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_dops_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_dops_dep_a_t *msg);

int sbp_cmp_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *a, const sbp_msg_dops_dep_a_t *b);


#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_DEP_A_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_DEP_A_FIX_MODE_MASK)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_DEP_A_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_DEP_A_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_DEP_A_FIX_MODE_SINGLE_POINT_POSITIONING (0)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_FIXED_RTK (1)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_FLOAT_RTK (2)
/** Single-point position in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_ECEF_DEP_A         0x0200
typedef struct {
  u32 tow;
  double x;
  double y;
  double z;
  u16 accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_ecef_dep_a_t;

size_t sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *msg);
s8 sbp_pack_sbp_msg_pos_ecef_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_pos_ecef_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_dep_a_t *msg);

int sbp_cmp_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *a, const sbp_msg_pos_ecef_dep_a_t *b);


#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SHIFT (5u)
#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (4u)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_MASK (0x1)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_SHIFT (3u)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_DEP_A_HEIGHT_MODE_SHIFT) \
                             & SBP_POS_LLH_DEP_A_HEIGHT_MODE_MASK)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_DEP_A_HEIGHT_MODE_MASK)) \
                             << (SBP_POS_LLH_DEP_A_HEIGHT_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_HEIGHT_ABOVE_WGS84_ELLIPSOID (0)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_HEIGHT_ABOVE_MEAN_SEA_LEVEL (1)
#define SBP_POS_LLH_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_DEP_A_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_DEP_A_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_DEP_A_FIX_MODE_MASK)
#define SBP_POS_LLH_DEP_A_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_DEP_A_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_DEP_A_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_DEP_A_FIX_MODE_SINGLE_POINT_POSITIONING (0)
#define SBP_POS_LLH_DEP_A_FIX_MODE_FIXED_RTK (1)
#define SBP_POS_LLH_DEP_A_FIX_MODE_FLOAT_RTK (2)
/** Geodetic Position
 *
((m.desc|commentify)))
 */
#define SBP_MSG_POS_LLH_DEP_A          0x0201
typedef struct {
  u32 tow;
  double lat;
  double lon;
  double height;
  u16 h_accuracy;
  u16 v_accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_pos_llh_dep_a_t;

size_t sbp_packed_size_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *msg);
s8 sbp_pack_sbp_msg_pos_llh_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_pos_llh_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_dep_a_t *msg);

int sbp_cmp_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *a, const sbp_msg_pos_llh_dep_a_t *b);


#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_ECEF_DEP_A_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_ECEF_DEP_A_FIX_MODE_MASK)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_ECEF_DEP_A_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_ECEF_DEP_A_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_FIXED_RTK (1)
/** Baseline Position in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BASELINE_ECEF_DEP_A    0x0202
typedef struct {
  u32 tow;
  s32 x;
  s32 y;
  s32 z;
  u16 accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_baseline_ecef_dep_a_t;

size_t sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *msg);
s8 sbp_pack_sbp_msg_baseline_ecef_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_ecef_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_baseline_ecef_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_ecef_dep_a_t *msg);

int sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *a, const sbp_msg_baseline_ecef_dep_a_t *b);


#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_NED_DEP_A_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_NED_DEP_A_FIX_MODE_MASK)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_NED_DEP_A_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_NED_DEP_A_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_NED_DEP_A_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_FIXED_RTK (1)
/** Baseline in NED
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BASELINE_NED_DEP_A     0x0203
typedef struct {
  u32 tow;
  s32 n;
  s32 e;
  s32 d;
  u16 h_accuracy;
  u16 v_accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_baseline_ned_dep_a_t;

size_t sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *msg);
s8 sbp_pack_sbp_msg_baseline_ned_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_ned_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_baseline_ned_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_ned_dep_a_t *msg);

int sbp_cmp_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *a, const sbp_msg_baseline_ned_dep_a_t *b);


/** Velocity in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_ECEF_DEP_A         0x0204
typedef struct {
  u32 tow;
  s32 x;
  s32 y;
  s32 z;
  u16 accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ecef_dep_a_t;

size_t sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *msg);
s8 sbp_pack_sbp_msg_vel_ecef_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_vel_ecef_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_dep_a_t *msg);

int sbp_cmp_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *a, const sbp_msg_vel_ecef_dep_a_t *b);


/** Velocity in NED
 *
((m.desc|commentify)))
 */
#define SBP_MSG_VEL_NED_DEP_A          0x0205
typedef struct {
  u32 tow;
  s32 n;
  s32 e;
  s32 d;
  u16 h_accuracy;
  u16 v_accuracy;
  u8 n_sats;
  u8 flags;
} sbp_msg_vel_ned_dep_a_t;

size_t sbp_packed_size_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *msg);
s8 sbp_pack_sbp_msg_vel_ned_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_vel_ned_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_dep_a_t *msg);

int sbp_cmp_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *a, const sbp_msg_vel_ned_dep_a_t *b);


#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_HEADING_DEP_A_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_HEADING_DEP_A_FIX_MODE_MASK)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_HEADING_DEP_A_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_HEADING_DEP_A_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_FIXED_RTK (1)
/** Heading relative to True North
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BASELINE_HEADING_DEP_A 0x0207
typedef struct {
  u32 tow;
  u32 heading;
  u8 n_sats;
  u8 flags;
} sbp_msg_baseline_heading_dep_a_t;

size_t sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *msg);
s8 sbp_pack_sbp_msg_baseline_heading_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_heading_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_baseline_heading_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_heading_dep_a_t *msg);

int sbp_cmp_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *a, const sbp_msg_baseline_heading_dep_a_t *b);


#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK (0x7)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT (0u)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SAFE_STATE_PROTECTION_LEVEL_SHALL_NOT_BE_USED_FOR_SAFETY_CRITICAL_APPLICATION (0)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_1 (1)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_2 (2)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_3 (3)
/** Computed Position and Protection Level
 *
((m.desc|commentify)))
 */
#define SBP_MSG_PROTECTION_LEVEL_DEP_A 0x0216
typedef struct {
  u32 tow;
  u16 vpl;
  u16 hpl;
  double lat;
  double lon;
  double height;
  u8 flags;
} sbp_msg_protection_level_dep_a_t;

size_t sbp_packed_size_sbp_msg_protection_level_dep_a_t(const sbp_msg_protection_level_dep_a_t *msg);
s8 sbp_pack_sbp_msg_protection_level_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_protection_level_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_protection_level_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_protection_level_dep_a_t *msg);

int sbp_cmp_sbp_msg_protection_level_dep_a_t(const sbp_msg_protection_level_dep_a_t *a, const sbp_msg_protection_level_dep_a_t *b);


#define SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK (0x7)
#define SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT (0u)
#define SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)
#define SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_FIX_MODE_MASK (0x7)
#define SBP_PROTECTION_LEVEL_FIX_MODE_SHIFT (15u)
#define SBP_PROTECTION_LEVEL_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_FIX_MODE_SHIFT) \
                             & SBP_PROTECTION_LEVEL_FIX_MODE_MASK)
#define SBP_PROTECTION_LEVEL_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_FIX_MODE_MASK)) \
                             << (SBP_PROTECTION_LEVEL_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_FIX_MODE_INVALID (0)
#define SBP_PROTECTION_LEVEL_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_PROTECTION_LEVEL_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_PROTECTION_LEVEL_FIX_MODE_FLOAT_RTK (3)
#define SBP_PROTECTION_LEVEL_FIX_MODE_FIXED_RTK (4)
#define SBP_PROTECTION_LEVEL_FIX_MODE_DEAD_RECKONING (5)
#define SBP_PROTECTION_LEVEL_FIX_MODE_SBAS_POSITION (6)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_SHIFT (18u)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_SHIFT) \
                             & SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_MASK)) \
                             << (SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_MASK (0x1)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_SHIFT (20u)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_TIME_STATUS_SHIFT) \
                             & SBP_PROTECTION_LEVEL_TIME_STATUS_MASK)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_TIME_STATUS_MASK)) \
                             << (SBP_PROTECTION_LEVEL_TIME_STATUS_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_TIME_STATUS_GNSS_TIME_OF_VALIDITY (0)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_OTHER (1)
#define SBP_PROTECTION_LEVEL_VELOCITY_VALID_MASK (0x1)
#define SBP_PROTECTION_LEVEL_VELOCITY_VALID_SHIFT (21u)
#define SBP_PROTECTION_LEVEL_VELOCITY_VALID_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_VELOCITY_VALID_SHIFT) \
                             & SBP_PROTECTION_LEVEL_VELOCITY_VALID_MASK)
#define SBP_PROTECTION_LEVEL_VELOCITY_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_VELOCITY_VALID_MASK)) \
                             << (SBP_PROTECTION_LEVEL_VELOCITY_VALID_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_ATTITUDE_VALID_MASK (0x1)
#define SBP_PROTECTION_LEVEL_ATTITUDE_VALID_SHIFT (22u)
#define SBP_PROTECTION_LEVEL_ATTITUDE_VALID_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_ATTITUDE_VALID_SHIFT) \
                             & SBP_PROTECTION_LEVEL_ATTITUDE_VALID_MASK)
#define SBP_PROTECTION_LEVEL_ATTITUDE_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_ATTITUDE_VALID_MASK)) \
                             << (SBP_PROTECTION_LEVEL_ATTITUDE_VALID_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_SHIFT (23u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_SHIFT (24u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_SHIFT (25u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_SHIFT (26u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_SHIFT (27u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_SHIFT (28u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_SHIFT (29u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_SHIFT (30u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_SHIFT (31u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_SHIFT)));} while(0)
                             

/** Computed state and Protection Levels
 *
((m.desc|commentify)))
 */
#define SBP_MSG_PROTECTION_LEVEL       0x0217
typedef struct {
  u32 tow;
  s16 wn;
  u16 hpl;
  u16 vpl;
  u16 atpl;
  u16 ctpl;
  u16 hvpl;
  u16 vvpl;
  u16 hopl;
  u16 popl;
  u16 ropl;
  double lat;
  double lon;
  double height;
  s32 v_x;
  s32 v_y;
  s32 v_z;
  s32 roll;
  s32 pitch;
  s32 heading;
  u32 flags;
} sbp_msg_protection_level_t;

size_t sbp_packed_size_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *msg);
s8 sbp_pack_sbp_msg_protection_level_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_protection_level_t *msg);
s8 sbp_unpack_sbp_msg_protection_level_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_protection_level_t *msg);

int sbp_cmp_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *a, const sbp_msg_protection_level_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b) {
  return sbp_cmp_sbp_msg_gps_time_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b) {
  return sbp_cmp_sbp_msg_gps_time_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b) {
  return sbp_cmp_sbp_msg_gps_time_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b) {
  return sbp_cmp_sbp_msg_gps_time_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b) {
  return sbp_cmp_sbp_msg_gps_time_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b) {
  return sbp_cmp_sbp_msg_gps_time_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_gps_time_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b) {
  return sbp_cmp_sbp_msg_utc_time_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b) {
  return sbp_cmp_sbp_msg_utc_time_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b) {
  return sbp_cmp_sbp_msg_utc_time_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b) {
  return sbp_cmp_sbp_msg_utc_time_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b) {
  return sbp_cmp_sbp_msg_utc_time_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b) {
  return sbp_cmp_sbp_msg_utc_time_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b) {
  return sbp_cmp_sbp_msg_utc_time_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_dops_t &a, const sbp_msg_dops_t &b) {
  return sbp_cmp_sbp_msg_dops_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_dops_t &a, const sbp_msg_dops_t &b) {
  return sbp_cmp_sbp_msg_dops_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_dops_t &a, const sbp_msg_dops_t &b) {
  return sbp_cmp_sbp_msg_dops_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_dops_t &a, const sbp_msg_dops_t &b) {
  return sbp_cmp_sbp_msg_dops_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_dops_t &a, const sbp_msg_dops_t &b) {
  return sbp_cmp_sbp_msg_dops_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_dops_t &a, const sbp_msg_dops_t &b) {
  return sbp_cmp_sbp_msg_dops_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b) {
  return sbp_cmp_sbp_msg_vel_body_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b) {
  return sbp_cmp_sbp_msg_vel_body_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b) {
  return sbp_cmp_sbp_msg_vel_body_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b) {
  return sbp_cmp_sbp_msg_vel_body_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b) {
  return sbp_cmp_sbp_msg_vel_body_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b) {
  return sbp_cmp_sbp_msg_vel_body_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b) {
  return sbp_cmp_sbp_msg_age_corrections_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b) {
  return sbp_cmp_sbp_msg_age_corrections_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b) {
  return sbp_cmp_sbp_msg_age_corrections_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b) {
  return sbp_cmp_sbp_msg_age_corrections_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b) {
  return sbp_cmp_sbp_msg_age_corrections_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b) {
  return sbp_cmp_sbp_msg_age_corrections_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b) {
  return sbp_cmp_sbp_msg_gps_time_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b) {
  return sbp_cmp_sbp_msg_dops_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_ecef_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b) {
  return sbp_cmp_sbp_msg_pos_llh_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_ned_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ecef_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b) {
  return sbp_cmp_sbp_msg_vel_ned_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_protection_level_dep_a_t &a, const sbp_msg_protection_level_dep_a_t &b) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_protection_level_dep_a_t &a, const sbp_msg_protection_level_dep_a_t &b) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_protection_level_dep_a_t &a, const sbp_msg_protection_level_dep_a_t &b) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_protection_level_dep_a_t &a, const sbp_msg_protection_level_dep_a_t &b) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_protection_level_dep_a_t &a, const sbp_msg_protection_level_dep_a_t &b) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_protection_level_dep_a_t &a, const sbp_msg_protection_level_dep_a_t &b) {
  return sbp_cmp_sbp_msg_protection_level_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b) {
  return sbp_cmp_sbp_msg_protection_level_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b) {
  return sbp_cmp_sbp_msg_protection_level_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b) {
  return sbp_cmp_sbp_msg_protection_level_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b) {
  return sbp_cmp_sbp_msg_protection_level_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b) {
  return sbp_cmp_sbp_msg_protection_level_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b) {
  return sbp_cmp_sbp_msg_protection_level_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NAVIGATION_MESSAGES_H */
