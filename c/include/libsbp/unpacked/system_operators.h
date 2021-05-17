#ifndef LIBSBP_SYSTEM_OPERATORS_H
#define LIBSBP_SYSTEM_OPERATORS_H

#ifndef LIBSBP_SYSTEM_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/system.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/base.h>
static inline int sbp_cmp_sbp_msg_startup_t(const sbp_msg_startup_t *a, const sbp_msg_startup_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->cause, &b->cause);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->startup_type, &b->startup_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->reserved, &b->reserved);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *a, const sbp_msg_dgnss_status_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->latency, &b->latency);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->num_signals, &b->num_signals);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->source, &b->source, 251
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *a, const sbp_msg_heartbeat_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_sub_system_report_t(const sbp_sub_system_report_t *a, const sbp_sub_system_report_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->component, &b->component);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->generic, &b->generic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->specific, &b->specific);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_status_report_t(const sbp_msg_status_report_t *a, const sbp_msg_status_report_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->reporting_system, &b->reporting_system);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->sbp_version, &b->sbp_version);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->uptime, &b->uptime);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_status, &b->n_status);
  for (uint8_t i = 0; i < a->n_status && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_sub_system_report_t(&a->status[i], &b->status[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *a, const sbp_msg_ins_status_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *a, const sbp_msg_csac_telemetry_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->id, &b->id);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->telemetry, &b->telemetry, 254
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *a, const sbp_msg_csac_telemetry_labels_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->id, &b->id);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->telemetry_labels, &b->telemetry_labels, 254
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *a, const sbp_msg_ins_updates_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->gnsspos, &b->gnsspos);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->gnssvel, &b->gnssvel);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->wheelticks, &b->wheelticks);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->speed, &b->speed);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->nhc, &b->nhc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->zerovel, &b->zerovel);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *a, const sbp_msg_gnss_time_offset_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->weeks, &b->weeks);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->milliseconds, &b->milliseconds);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->microseconds, &b->microseconds);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *a, const sbp_msg_pps_time_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *a, const sbp_msg_group_meta_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->group_id, &b->group_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_group_msgs, &b->n_group_msgs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_group_msgs, &b->n_group_msgs);
  for (uint8_t i = 0; i < a->n_group_msgs && ret == 0; i++)
  {
    ret = sbp_cmp_u16(&a->group_msgs[i], &b->group_msgs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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

#endif
