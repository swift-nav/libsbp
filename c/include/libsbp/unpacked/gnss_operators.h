#ifndef LIBSBP_GNSS_OPERATORS_H
#define LIBSBP_GNSS_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/gnss.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b)
{
  (void)a;
  (void)b;

  if (a.sat != b.sat)
  {
    return false;
  }

  if (a.code != b.code)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_sv_id_t &a, const sbp_sv_id_t &b)
{
  (void)a;
  (void)b;

  if (a.satId != b.satId)
  {
    return false;
  }

  if (a.constellation != b.constellation)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_sv_id_t &a, const sbp_sv_id_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b)
{
  (void)a;
  (void)b;

  if (a.sat != b.sat)
  {
    return false;
  }

  if (a.code != b.code)
  {
    return false;
  }

  if (a.reserved != b.reserved)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.wn != b.wn)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.wn != b.wn)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.ns_residual != b.ns_residual)
  {
    return false;
  }

  if (a.wn != b.wn)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b)
{
  (void)a;
  (void)b;

  if (a.i != b.i)
  {
    return false;
  }

  if (a.f != b.f)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b)
{
  return !(a == b);
}
#endif

#endif
