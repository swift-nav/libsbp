#ifndef LIBSBP_GNSS_OPERATORS_H
#define LIBSBP_GNSS_OPERATORS_H

#ifndef LIBSBP_GNSS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/gnss.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#include <libsbp/unpacked/base.h>
static inline int sbp_cmp_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *a, const sbp_sbp_gnss_signal_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->sat, &b->sat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->code, &b->code);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_sv_id_t(const sbp_sv_id_t *a, const sbp_sv_id_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->satId, &b->satId);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->constellation, &b->constellation);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *a, const sbp_gnss_signal_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->sat, &b->sat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->code, &b->code);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->reserved, &b->reserved);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *a, const sbp_gps_time_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *a, const sbp_gps_time_sec_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *a, const sbp_sbp_gps_time_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ns_residual, &b->ns_residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_carrier_phase_t(const sbp_carrier_phase_t *a, const sbp_carrier_phase_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s32(&a->i, &b->i);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->f, &b->f);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) >= 0;
}
#endif

#endif
