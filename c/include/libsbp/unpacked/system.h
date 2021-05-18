#ifndef LIBSBP_SYSTEM_MESSAGES_H
#define LIBSBP_SYSTEM_MESSAGES_H

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
#include <libsbp/unpacked/string/binary.h>

#ifdef __cplusplus
  extern "C" {
#endif
#define SBP_STARTUP_CAUSE_OF_STARTUP_MASK (0x1ff)
#define SBP_STARTUP_CAUSE_OF_STARTUP_SHIFT (0u)
#define SBP_STARTUP_CAUSE_OF_STARTUP_GET(flags) \
                             (((flags) >> SBP_STARTUP_CAUSE_OF_STARTUP_SHIFT) \
                             & SBP_STARTUP_CAUSE_OF_STARTUP_MASK)
#define SBP_STARTUP_CAUSE_OF_STARTUP_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STARTUP_CAUSE_OF_STARTUP_MASK)) \
                             << (SBP_STARTUP_CAUSE_OF_STARTUP_SHIFT)));} while(0)
                             

#define SBP_STARTUP_CAUSE_OF_STARTUP_POWER_ON (0)
#define SBP_STARTUP_CAUSE_OF_STARTUP_SOFTWARE_RESET (1)
#define SBP_STARTUP_CAUSE_OF_STARTUP_WATCHDOG_RESET (2)
#define SBP_STARTUP__MASK (0x1ff)
#define SBP_STARTUP__SHIFT (0u)
#define SBP_STARTUP__GET(flags) \
                             (((flags) >> SBP_STARTUP__SHIFT) \
                             & SBP_STARTUP__MASK)
#define SBP_STARTUP__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STARTUP__MASK)) \
                             << (SBP_STARTUP__SHIFT)));} while(0)
                             

#define SBP_STARTUP__COLD_START (0)
#define SBP_STARTUP__WARM_START (1)
#define SBP_STARTUP__HOT_START (2)
/** System start-up message
 *
((m.desc|commentify)))
 */
#define SBP_MSG_STARTUP               0xFF00
typedef struct {
  u8 cause;
  u8 startup_type;
  u16 reserved;
} sbp_msg_startup_t;

size_t sbp_packed_size_sbp_msg_startup_t(const sbp_msg_startup_t *msg);
s8 sbp_pack_sbp_msg_startup_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_startup_t *msg);
s8 sbp_unpack_sbp_msg_startup_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_startup_t *msg);

int sbp_cmp_sbp_msg_startup_t(const sbp_msg_startup_t *a, const sbp_msg_startup_t *b);


#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_MASK (0xf)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SHIFT (0u)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_GET(flags) \
                             (((flags) >> SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SHIFT) \
                             & SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_MASK)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_MASK)) \
                             << (SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_SHIFT)));} while(0)
                             

#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_INVALID (0)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_CODE_DIFFERENCE (1)
#define SBP_DGNSS_STATUS_DIFFERENTIAL_TYPE_RTK (2)
/** Status of received corrections
 *
((m.desc|commentify)))
 */
#define SBP_MSG_DGNSS_STATUS          0xFF02
typedef struct {
  u8 flags;
  u16 latency;
  u8 num_signals;
  sbp_unterminated_string_t source;
} sbp_msg_dgnss_status_t;
#define sbp_msg_dgnss_status_t_source_init(f) sbp_unterminated_string_init(f, 251)
#define sbp_msg_dgnss_status_t_source_valid(f) sbp_unterminated_string_valid(f, 251)
#define sbp_msg_dgnss_status_t_source_set(f,s) sbp_unterminated_string_set(f,s,251)
#define sbp_msg_dgnss_status_t_source_printf(f,...) sbp_unterminated_string_printf(f,251,__VA_ARGS__)
#define sbp_msg_dgnss_status_t_source_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,251,fmt,ap)
#define sbp_msg_dgnss_status_t_source_packed_len(f) sbp_unterminated_string_packed_len(f,251)
#define sbp_msg_dgnss_status_t_source_get(f) sbp_unterminated_string_get(f,251)
#define sbp_msg_dgnss_status_t_source_len(f) ( sbp_msg_dgnss_status_t_source_packed_len(f))
#define sbp_msg_dgnss_status_t_source_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,251)

size_t sbp_packed_size_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *msg);
s8 sbp_pack_sbp_msg_dgnss_status_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_dgnss_status_t *msg);
s8 sbp_unpack_sbp_msg_dgnss_status_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_dgnss_status_t *msg);

int sbp_cmp_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *a, const sbp_msg_dgnss_status_t *b);


#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_MASK (0x1)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SHIFT (31u)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SHIFT) \
                             & SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_MASK)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_MASK)) \
                             << (SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_NO_EXTERNAL_ANTENNA_DETECTED (0)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_PRESENT_EXTERNAL_ANTENNA_IS_PRESENT (1)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_MASK (0x1)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHIFT (30u)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHIFT) \
                             & SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_MASK)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_MASK)) \
                             << (SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_NO_SHORT_DETECTED (0)
#define SBP_HEARTBEAT_EXTERNAL_ANTENNA_SHORT_SHORT_DETECTED (1)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (16u)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_HEARTBEAT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_HEARTBEAT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_SWIFTNAP_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_SHIFT (2u)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_SWIFTNAP_ERROR_SHIFT) \
                             & SBP_HEARTBEAT_SWIFTNAP_ERROR_MASK)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_SWIFTNAP_ERROR_MASK)) \
                             << (SBP_HEARTBEAT_SWIFTNAP_ERROR_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_SWIFTNAP_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_SWIFTNAP_ERROR_AN_ERROR_HAS_OCCURRED_IN_THE_SWIFTNAP (1)
#define SBP_HEARTBEAT_IO_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_IO_ERROR_SHIFT (1u)
#define SBP_HEARTBEAT_IO_ERROR_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_IO_ERROR_SHIFT) \
                             & SBP_HEARTBEAT_IO_ERROR_MASK)
#define SBP_HEARTBEAT_IO_ERROR_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_IO_ERROR_MASK)) \
                             << (SBP_HEARTBEAT_IO_ERROR_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_IO_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_IO_ERROR_AN_IO_ERROR_HAS_OCCURRED (1)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_MASK (0x1)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SHIFT (0u)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_GET(flags) \
                             (((flags) >> SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SHIFT) \
                             & SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_MASK)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_MASK)) \
                             << (SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SHIFT)));} while(0)
                             

#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_SYSTEM_ERROR_FLAG_AN_ERROR_HAS_OCCURRED (1)
/** System heartbeat message
 *
((m.desc|commentify)))
 */
#define SBP_MSG_HEARTBEAT             0xFFFF
typedef struct {
  u32 flags;
} sbp_msg_heartbeat_t;

size_t sbp_packed_size_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *msg);
s8 sbp_pack_sbp_msg_heartbeat_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_heartbeat_t *msg);
s8 sbp_unpack_sbp_msg_heartbeat_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_heartbeat_t *msg);

int sbp_cmp_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *a, const sbp_msg_heartbeat_t *b);


#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_MASK (0xffff)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_SHIFT (0u)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_GET(flags) \
                             (((flags) >> SBP_SUBSYSTEMREPORT_SUBSYSTEM_SHIFT) \
                             & SBP_SUBSYSTEMREPORT_SUBSYSTEM_MASK)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SUBSYSTEMREPORT_SUBSYSTEM_MASK)) \
                             << (SBP_SUBSYSTEMREPORT_SUBSYSTEM_SHIFT)));} while(0)
                             

#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_PRIMARY_GNSS_ANTENNA (0)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_MEASUREMENT_ENGINE (1)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_CORRECTIONS_CLIENT (2)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_DIFFERENTIAL_GNSS_ENGINE (3)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_CAN (4)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_WHEEL_ODOMETRY (5)
#define SBP_SUBSYSTEMREPORT_SUBSYSTEM_SENSOR_FUSION_ENGINE (6)
#define SBP_SUBSYSTEMREPORT_GENERIC_MASK (0xff)
#define SBP_SUBSYSTEMREPORT_GENERIC_SHIFT (0u)
#define SBP_SUBSYSTEMREPORT_GENERIC_GET(flags) \
                             (((flags) >> SBP_SUBSYSTEMREPORT_GENERIC_SHIFT) \
                             & SBP_SUBSYSTEMREPORT_GENERIC_MASK)
#define SBP_SUBSYSTEMREPORT_GENERIC_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SUBSYSTEMREPORT_GENERIC_MASK)) \
                             << (SBP_SUBSYSTEMREPORT_GENERIC_SHIFT)));} while(0)
                             

#define SBP_SUBSYSTEMREPORT_GENERIC_OKNOMINAL (0)
#define SBP_SUBSYSTEMREPORT_GENERIC_INITIALIZING (1)
#define SBP_SUBSYSTEMREPORT_GENERIC_UNKNOWN (2)
#define SBP_SUBSYSTEMREPORT_GENERIC_DEGRADED (3)
#define SBP_SUBSYSTEMREPORT_GENERIC_UNUSABLE (4)
/** Sub-system Status report
 *
((m.desc|commentify)))
 */
typedef struct {
  u16 component;
  u8 generic;
  u8 specific;
} sbp_sub_system_report_t;

size_t sbp_packed_size_sbp_sub_system_report_t(const sbp_sub_system_report_t *msg);
s8 sbp_pack_sbp_sub_system_report_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sub_system_report_t *msg);
s8 sbp_unpack_sbp_sub_system_report_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sub_system_report_t *msg);

int sbp_cmp_sbp_sub_system_report_t(const sbp_sub_system_report_t *a, const sbp_sub_system_report_t *b);


#define SBP_STATUS_REPORT_SYSTEM_MASK (0xffff)
#define SBP_STATUS_REPORT_SYSTEM_SHIFT (0u)
#define SBP_STATUS_REPORT_SYSTEM_GET(flags) \
                             (((flags) >> SBP_STATUS_REPORT_SYSTEM_SHIFT) \
                             & SBP_STATUS_REPORT_SYSTEM_MASK)
#define SBP_STATUS_REPORT_SYSTEM_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STATUS_REPORT_SYSTEM_MASK)) \
                             << (SBP_STATUS_REPORT_SYSTEM_SHIFT)));} while(0)
                             

#define SBP_STATUS_REPORT_SYSTEM_STARLING (0)
#define SBP_STATUS_REPORT_SYSTEM_PRECISION_GNSS_MODULE (1)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0x1ff)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_STATUS_REPORT_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             

#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (0u)
#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_STATUS_REPORT_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             

/** Status report message
 *
((m.desc|commentify)))
 */
#define SBP_MSG_STATUS_REPORT         0xFFFE
typedef struct {
  u16 reporting_system;
  u16 sbp_version;
  u32 sequence;
  u32 uptime;
  sbp_sub_system_report_t status[60];
  u8 n_status;
} sbp_msg_status_report_t;

size_t sbp_packed_size_sbp_msg_status_report_t(const sbp_msg_status_report_t *msg);
s8 sbp_pack_sbp_msg_status_report_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_status_report_t *msg);
s8 sbp_unpack_sbp_msg_status_report_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_status_report_t *msg);

int sbp_cmp_sbp_msg_status_report_t(const sbp_msg_status_report_t *a, const sbp_msg_status_report_t *b);


#define SBP_INS_STATUS_INS_TYPE_MASK (0x7)
#define SBP_INS_STATUS_INS_TYPE_SHIFT (29u)
#define SBP_INS_STATUS_INS_TYPE_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_INS_TYPE_SHIFT) \
                             & SBP_INS_STATUS_INS_TYPE_MASK)
#define SBP_INS_STATUS_INS_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_INS_TYPE_MASK)) \
                             << (SBP_INS_STATUS_INS_TYPE_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_INS_TYPE_SMOOTHPOSE_LOOSELY_COUPLED (0)
#define SBP_INS_STATUS_INS_TYPE_STARLING (1)
#define SBP_INS_STATUS_MOTION_STATE_MASK (0x7)
#define SBP_INS_STATUS_MOTION_STATE_SHIFT (11u)
#define SBP_INS_STATUS_MOTION_STATE_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_MOTION_STATE_SHIFT) \
                             & SBP_INS_STATUS_MOTION_STATE_MASK)
#define SBP_INS_STATUS_MOTION_STATE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_MOTION_STATE_MASK)) \
                             << (SBP_INS_STATUS_MOTION_STATE_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_MOTION_STATE_UNKNOWN_OR_INIT (0)
#define SBP_INS_STATUS_MOTION_STATE_ARBITRARY_MOTION (1)
#define SBP_INS_STATUS_MOTION_STATE_STRAIGHT_MOTION (2)
#define SBP_INS_STATUS_MOTION_STATE_STATIONARY (3)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_MASK (0x1)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_SHIFT (10u)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_ODOMETRY_SYNCH_SHIFT) \
                             & SBP_INS_STATUS_ODOMETRY_SYNCH_MASK)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_ODOMETRY_SYNCH_MASK)) \
                             << (SBP_INS_STATUS_ODOMETRY_SYNCH_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_NOMINAL (0)
#define SBP_INS_STATUS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_OUT_OF_BOUNDS (1)
#define SBP_INS_STATUS_ODOMETRY_STATUS_MASK (0x3)
#define SBP_INS_STATUS_ODOMETRY_STATUS_SHIFT (8u)
#define SBP_INS_STATUS_ODOMETRY_STATUS_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_ODOMETRY_STATUS_SHIFT) \
                             & SBP_INS_STATUS_ODOMETRY_STATUS_MASK)
#define SBP_INS_STATUS_ODOMETRY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_ODOMETRY_STATUS_MASK)) \
                             << (SBP_INS_STATUS_ODOMETRY_STATUS_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_ODOMETRY_STATUS_NO_ODOMETRY (0)
#define SBP_INS_STATUS_ODOMETRY_STATUS_ODOMETRY_RECEIVED_WITHIN_LAST_SECOND (1)
#define SBP_INS_STATUS_ODOMETRY_STATUS_ODOMETRY_NOT_RECEIVED_WITHIN_LAST_SECOND (2)
#define SBP_INS_STATUS_INS_ERROR_MASK (0xf)
#define SBP_INS_STATUS_INS_ERROR_SHIFT (4u)
#define SBP_INS_STATUS_INS_ERROR_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_INS_ERROR_SHIFT) \
                             & SBP_INS_STATUS_INS_ERROR_MASK)
#define SBP_INS_STATUS_INS_ERROR_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_INS_ERROR_MASK)) \
                             << (SBP_INS_STATUS_INS_ERROR_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_INS_ERROR_IMU_DATA_ERROR (1)
#define SBP_INS_STATUS_INS_ERROR_INS_LICENSE_ERROR (2)
#define SBP_INS_STATUS_INS_ERROR_IMU_CALIBRATION_DATA_ERROR (3)
#define SBP_INS_STATUS_GNSS_FIX_MASK (0x1)
#define SBP_INS_STATUS_GNSS_FIX_SHIFT (3u)
#define SBP_INS_STATUS_GNSS_FIX_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_GNSS_FIX_SHIFT) \
                             & SBP_INS_STATUS_GNSS_FIX_MASK)
#define SBP_INS_STATUS_GNSS_FIX_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_GNSS_FIX_MASK)) \
                             << (SBP_INS_STATUS_GNSS_FIX_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_GNSS_FIX_NO_GNSS_FIX_AVAILABLE (0)
#define SBP_INS_STATUS_GNSS_FIX_GNSS_FIX (1)
#define SBP_INS_STATUS_MODE_MASK (0x7)
#define SBP_INS_STATUS_MODE_SHIFT (0u)
#define SBP_INS_STATUS_MODE_GET(flags) \
                             (((flags) >> SBP_INS_STATUS_MODE_SHIFT) \
                             & SBP_INS_STATUS_MODE_MASK)
#define SBP_INS_STATUS_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_STATUS_MODE_MASK)) \
                             << (SBP_INS_STATUS_MODE_SHIFT)));} while(0)
                             

#define SBP_INS_STATUS_MODE_AWAITING_INITIALIZATION (0)
#define SBP_INS_STATUS_MODE_DYNAMICALLY_ALIGNING (1)
#define SBP_INS_STATUS_MODE_READY (2)
#define SBP_INS_STATUS_MODE_GNSS_OUTAGE_EXCEEDS_MAX_DURATION (3)
#define SBP_INS_STATUS_MODE_FASTSTART_SEEDING (4)
#define SBP_INS_STATUS_MODE_FASTSTART_VALIDATING (5)
#define SBP_INS_STATUS_MODE_VALIDATING_UNSAFE_FAST_START_SEED (6)
/** Inertial Navigation System status message
 *
((m.desc|commentify)))
 */
#define SBP_MSG_INS_STATUS            0xFF03
typedef struct {
  u32 flags;
} sbp_msg_ins_status_t;

size_t sbp_packed_size_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *msg);
s8 sbp_pack_sbp_msg_ins_status_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ins_status_t *msg);
s8 sbp_unpack_sbp_msg_ins_status_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ins_status_t *msg);

int sbp_cmp_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *a, const sbp_msg_ins_status_t *b);


/** Experimental telemetry message
 *
((m.desc|commentify)))
 */
#define SBP_MSG_CSAC_TELEMETRY        0xFF04
typedef struct {
  u8 id;
  sbp_unterminated_string_t telemetry;
} sbp_msg_csac_telemetry_t;
#define sbp_msg_csac_telemetry_t_telemetry_init(f) sbp_unterminated_string_init(f, 254)
#define sbp_msg_csac_telemetry_t_telemetry_valid(f) sbp_unterminated_string_valid(f, 254)
#define sbp_msg_csac_telemetry_t_telemetry_set(f,s) sbp_unterminated_string_set(f,s,254)
#define sbp_msg_csac_telemetry_t_telemetry_printf(f,...) sbp_unterminated_string_printf(f,254,__VA_ARGS__)
#define sbp_msg_csac_telemetry_t_telemetry_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,254,fmt,ap)
#define sbp_msg_csac_telemetry_t_telemetry_packed_len(f) sbp_unterminated_string_packed_len(f,254)
#define sbp_msg_csac_telemetry_t_telemetry_get(f) sbp_unterminated_string_get(f,254)
#define sbp_msg_csac_telemetry_t_telemetry_len(f) ( sbp_msg_csac_telemetry_t_telemetry_packed_len(f))
#define sbp_msg_csac_telemetry_t_telemetry_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,254)

size_t sbp_packed_size_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *msg);
s8 sbp_pack_sbp_msg_csac_telemetry_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_csac_telemetry_t *msg);
s8 sbp_unpack_sbp_msg_csac_telemetry_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_csac_telemetry_t *msg);

int sbp_cmp_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *a, const sbp_msg_csac_telemetry_t *b);


/** Experimental telemetry message labels
 *
((m.desc|commentify)))
 */
#define SBP_MSG_CSAC_TELEMETRY_LABELS 0xFF05
typedef struct {
  u8 id;
  sbp_unterminated_string_t telemetry_labels;
} sbp_msg_csac_telemetry_labels_t;
#define sbp_msg_csac_telemetry_labels_t_telemetry_labels_init(f) sbp_unterminated_string_init(f, 254)
#define sbp_msg_csac_telemetry_labels_t_telemetry_labels_valid(f) sbp_unterminated_string_valid(f, 254)
#define sbp_msg_csac_telemetry_labels_t_telemetry_labels_set(f,s) sbp_unterminated_string_set(f,s,254)
#define sbp_msg_csac_telemetry_labels_t_telemetry_labels_printf(f,...) sbp_unterminated_string_printf(f,254,__VA_ARGS__)
#define sbp_msg_csac_telemetry_labels_t_telemetry_labels_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,254,fmt,ap)
#define sbp_msg_csac_telemetry_labels_t_telemetry_labels_packed_len(f) sbp_unterminated_string_packed_len(f,254)
#define sbp_msg_csac_telemetry_labels_t_telemetry_labels_get(f) sbp_unterminated_string_get(f,254)
#define sbp_msg_csac_telemetry_labels_t_telemetry_labels_len(f) ( sbp_msg_csac_telemetry_labels_t_telemetry_labels_packed_len(f))
#define sbp_msg_csac_telemetry_labels_t_telemetry_labels_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,254)

size_t sbp_packed_size_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *msg);
s8 sbp_pack_sbp_msg_csac_telemetry_labels_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_csac_telemetry_labels_t *msg);
s8 sbp_unpack_sbp_msg_csac_telemetry_labels_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_csac_telemetry_labels_t *msg);

int sbp_cmp_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *a, const sbp_msg_csac_telemetry_labels_t *b);


#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
                             (((flags) >> SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) \
                             & SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                             << (SBP_INS_UPDATES_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT)));} while(0)
                             

/** Inertial Navigation System update status message
 *
((m.desc|commentify)))
 */
#define SBP_MSG_INS_UPDATES           0xFF06
typedef struct {
  u32 tow;
  u8 gnsspos;
  u8 gnssvel;
  u8 wheelticks;
  u8 speed;
  u8 nhc;
  u8 zerovel;
} sbp_msg_ins_updates_t;

size_t sbp_packed_size_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *msg);
s8 sbp_pack_sbp_msg_ins_updates_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ins_updates_t *msg);
s8 sbp_unpack_sbp_msg_ins_updates_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ins_updates_t *msg);

int sbp_cmp_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *a, const sbp_msg_ins_updates_t *b);


/** Offset of the local time with respect to GNSS time
 *
((m.desc|commentify)))
 */
#define SBP_MSG_GNSS_TIME_OFFSET      0xFF07
typedef struct {
  s16 weeks;
  s32 milliseconds;
  s16 microseconds;
  u8 flags;
} sbp_msg_gnss_time_offset_t;

size_t sbp_packed_size_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *msg);
s8 sbp_pack_sbp_msg_gnss_time_offset_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_gnss_time_offset_t *msg);
s8 sbp_unpack_sbp_msg_gnss_time_offset_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_gnss_time_offset_t *msg);

int sbp_cmp_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *a, const sbp_msg_gnss_time_offset_t *b);


#define SBP_PPS_TIME_RESERVED_SET_TO_ZERO_MASK (0x3f)
#define SBP_PPS_TIME_RESERVED_SET_TO_ZERO_SHIFT (2u)
#define SBP_PPS_TIME_RESERVED_SET_TO_ZERO_GET(flags) \
                             (((flags) >> SBP_PPS_TIME_RESERVED_SET_TO_ZERO_SHIFT) \
                             & SBP_PPS_TIME_RESERVED_SET_TO_ZERO_MASK)
#define SBP_PPS_TIME_RESERVED_SET_TO_ZERO_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PPS_TIME_RESERVED_SET_TO_ZERO_MASK)) \
                             << (SBP_PPS_TIME_RESERVED_SET_TO_ZERO_SHIFT)));} while(0)
                             

#define SBP_PPS_TIME_TIME_UNCERTAINTY_MASK (0x3)
#define SBP_PPS_TIME_TIME_UNCERTAINTY_SHIFT (0u)
#define SBP_PPS_TIME_TIME_UNCERTAINTY_GET(flags) \
                             (((flags) >> SBP_PPS_TIME_TIME_UNCERTAINTY_SHIFT) \
                             & SBP_PPS_TIME_TIME_UNCERTAINTY_MASK)
#define SBP_PPS_TIME_TIME_UNCERTAINTY_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PPS_TIME_TIME_UNCERTAINTY_MASK)) \
                             << (SBP_PPS_TIME_TIME_UNCERTAINTY_SHIFT)));} while(0)
                             

#define SBP_PPS_TIME_TIME_UNCERTAINTY_UNKNOWN (0)
#define SBP_PPS_TIME_TIME_UNCERTAINTY__10_MILLISECONDS (1)
#define SBP_PPS_TIME_TIME_UNCERTAINTY__10_MICROSECONDS (2)
#define SBP_PPS_TIME_TIME_UNCERTAINTY__1_MICROSECONDS (3)
/** Local time at detection of PPS pulse
 *
((m.desc|commentify)))
 */
#define SBP_MSG_PPS_TIME              0xFF08
typedef struct {
  u64 time;
  u8 flags;
} sbp_msg_pps_time_t;

size_t sbp_packed_size_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *msg);
s8 sbp_pack_sbp_msg_pps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pps_time_t *msg);
s8 sbp_unpack_sbp_msg_pps_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pps_time_t *msg);

int sbp_cmp_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *a, const sbp_msg_pps_time_t *b);


#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK (0x3)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT (0u)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GET(flags) \
                             (((flags) >> SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT) \
                             & SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK)) \
                             << (SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT)));} while(0)
                             

#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_NONE (0)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GNSS_ONLY (1)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GNSSINS (2)
/** Solution Group Metadata
 *
((m.desc|commentify)))
 */
#define SBP_MSG_GROUP_META            0xFF0A
typedef struct {
  u8 group_id;
  u8 flags;
  u8 n_group_msgs;
  u16 group_msgs[126];
} sbp_msg_group_meta_t;

size_t sbp_packed_size_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *msg);
s8 sbp_pack_sbp_msg_group_meta_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_group_meta_t *msg);
s8 sbp_unpack_sbp_msg_group_meta_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_group_meta_t *msg);

int sbp_cmp_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *a, const sbp_msg_group_meta_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b) {
  return sbp_cmp_sbp_msg_startup_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b) {
  return sbp_cmp_sbp_msg_startup_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b) {
  return sbp_cmp_sbp_msg_startup_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b) {
  return sbp_cmp_sbp_msg_startup_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b) {
  return sbp_cmp_sbp_msg_startup_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b) {
  return sbp_cmp_sbp_msg_startup_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b) {
  return sbp_cmp_sbp_msg_heartbeat_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b) {
  return sbp_cmp_sbp_msg_heartbeat_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b) {
  return sbp_cmp_sbp_msg_heartbeat_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b) {
  return sbp_cmp_sbp_msg_heartbeat_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b) {
  return sbp_cmp_sbp_msg_heartbeat_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b) {
  return sbp_cmp_sbp_msg_heartbeat_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_sub_system_report_t &a, const sbp_sub_system_report_t &b) {
  return sbp_cmp_sbp_sub_system_report_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_sub_system_report_t &a, const sbp_sub_system_report_t &b) {
  return sbp_cmp_sbp_sub_system_report_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_sub_system_report_t &a, const sbp_sub_system_report_t &b) {
  return sbp_cmp_sbp_sub_system_report_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_sub_system_report_t &a, const sbp_sub_system_report_t &b) {
  return sbp_cmp_sbp_sub_system_report_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_sub_system_report_t &a, const sbp_sub_system_report_t &b) {
  return sbp_cmp_sbp_sub_system_report_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_sub_system_report_t &a, const sbp_sub_system_report_t &b) {
  return sbp_cmp_sbp_sub_system_report_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b) {
  return sbp_cmp_sbp_msg_status_report_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b) {
  return sbp_cmp_sbp_msg_status_report_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b) {
  return sbp_cmp_sbp_msg_status_report_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b) {
  return sbp_cmp_sbp_msg_status_report_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b) {
  return sbp_cmp_sbp_msg_status_report_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b) {
  return sbp_cmp_sbp_msg_status_report_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b) {
  return sbp_cmp_sbp_msg_ins_status_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b) {
  return sbp_cmp_sbp_msg_ins_status_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b) {
  return sbp_cmp_sbp_msg_ins_status_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b) {
  return sbp_cmp_sbp_msg_ins_status_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b) {
  return sbp_cmp_sbp_msg_ins_status_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b) {
  return sbp_cmp_sbp_msg_ins_status_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b) {
  return sbp_cmp_sbp_msg_ins_updates_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b) {
  return sbp_cmp_sbp_msg_ins_updates_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b) {
  return sbp_cmp_sbp_msg_ins_updates_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b) {
  return sbp_cmp_sbp_msg_ins_updates_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b) {
  return sbp_cmp_sbp_msg_ins_updates_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b) {
  return sbp_cmp_sbp_msg_ins_updates_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_pps_time_t &a, const sbp_msg_pps_time_t &b) {
  return sbp_cmp_sbp_msg_pps_time_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_pps_time_t &a, const sbp_msg_pps_time_t &b) {
  return sbp_cmp_sbp_msg_pps_time_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_pps_time_t &a, const sbp_msg_pps_time_t &b) {
  return sbp_cmp_sbp_msg_pps_time_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_pps_time_t &a, const sbp_msg_pps_time_t &b) {
  return sbp_cmp_sbp_msg_pps_time_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_pps_time_t &a, const sbp_msg_pps_time_t &b) {
  return sbp_cmp_sbp_msg_pps_time_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_pps_time_t &a, const sbp_msg_pps_time_t &b) {
  return sbp_cmp_sbp_msg_pps_time_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b) {
  return sbp_cmp_sbp_msg_group_meta_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b) {
  return sbp_cmp_sbp_msg_group_meta_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b) {
  return sbp_cmp_sbp_msg_group_meta_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b) {
  return sbp_cmp_sbp_msg_group_meta_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b) {
  return sbp_cmp_sbp_msg_group_meta_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b) {
  return sbp_cmp_sbp_msg_group_meta_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_SYSTEM_MESSAGES_H */
