#ifndef LIBSBP_SYSTEM_OPERATORS_H
#define LIBSBP_SYSTEM_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/system.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b)
{
  (void)a;
  (void)b;

  if (a.cause != b.cause)
  {
    return false;
  }

  if (a.startup_type != b.startup_type)
  {
    return false;
  }

  if (a.reserved != b.reserved)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }

  if (a.latency != b.latency)
  {
    return false;
  }

  if (a.num_signals != b.num_signals)
  {
    return false;
  }
  if (sbp_strcmp(a.source, b.source, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_sub_system_report_t &a, const sbp_sub_system_report_t &b)
{
  (void)a;
  (void)b;

  if (a.component != b.component)
  {
    return false;
  }

  if (a.generic != b.generic)
  {
    return false;
  }

  if (a.specific != b.specific)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_sub_system_report_t &a, const sbp_sub_system_report_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b)
{
  (void)a;
  (void)b;

  if (a.reporting_system != b.reporting_system)
  {
    return false;
  }

  if (a.sbp_version != b.sbp_version)
  {
    return false;
  }

  if (a.sequence != b.sequence)
  {
    return false;
  }

  if (a.uptime != b.uptime)
  {
    return false;
  }
  if (a.n_status != b.n_status)
  {
    return false;
  }
  for (size_t status_idx = 0; status_idx < (size_t)a.n_status; status_idx++)
  {

    if (a.status[status_idx].component != b.status[status_idx].component)
    {
      return false;
    }

    if (a.status[status_idx].generic != b.status[status_idx].generic)
    {
      return false;
    }

    if (a.status[status_idx].specific != b.status[status_idx].specific)
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b)
{
  (void)a;
  (void)b;

  if (a.id != b.id)
  {
    return false;
  }
  if (sbp_strcmp(a.telemetry, b.telemetry, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b)
{
  (void)a;
  (void)b;

  if (a.id != b.id)
  {
    return false;
  }
  if (sbp_strcmp(a.telemetry_labels, b.telemetry_labels, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.gnsspos != b.gnsspos)
  {
    return false;
  }

  if (a.gnssvel != b.gnssvel)
  {
    return false;
  }

  if (a.wheelticks != b.wheelticks)
  {
    return false;
  }

  if (a.speed != b.speed)
  {
    return false;
  }

  if (a.nhc != b.nhc)
  {
    return false;
  }

  if (a.zerovel != b.zerovel)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b)
{
  (void)a;
  (void)b;

  if (a.weeks != b.weeks)
  {
    return false;
  }

  if (a.milliseconds != b.milliseconds)
  {
    return false;
  }

  if (a.microseconds != b.microseconds)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b)
{
  (void)a;
  (void)b;

  if (a.group_id != b.group_id)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  if (a.n_group_msgs != b.n_group_msgs)
  {
    return false;
  }
  if (a.n_group_msgs != b.n_group_msgs)
  {
    return false;
  }
  for (size_t group_msgs_idx = 0; group_msgs_idx < (size_t)a.n_group_msgs; group_msgs_idx++)
  {

    if (a.group_msgs[group_msgs_idx] != b.group_msgs[group_msgs_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b)
{
  return !(a == b);
}
#endif

#endif
