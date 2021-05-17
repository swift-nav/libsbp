#ifndef LIBSBP_NAVIGATION_OPERATORS_H
#define LIBSBP_NAVIGATION_OPERATORS_H

#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/navigation.h instead"
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
static inline int sbp_cmp_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *a, const sbp_msg_gps_time_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ns_residual, &b->ns_residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *a, const sbp_msg_gps_time_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ns_residual, &b->ns_residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *a, const sbp_msg_utc_time_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->year, &b->year);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->month, &b->month);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->day, &b->day);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->hours, &b->hours);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->minutes, &b->minutes);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->seconds, &b->seconds);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->ns, &b->ns);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *a, const sbp_msg_utc_time_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->year, &b->year);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->month, &b->month);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->day, &b->day);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->hours, &b->hours);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->minutes, &b->minutes);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->seconds, &b->seconds);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->ns, &b->ns);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_dops_t(const sbp_msg_dops_t *a, const sbp_msg_dops_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->gdop, &b->gdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pdop, &b->pdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->tdop, &b->tdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hdop, &b->hdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vdop, &b->vdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *a, const sbp_msg_pos_ecef_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *a, const sbp_msg_pos_ecef_cov_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *a, const sbp_msg_pos_llh_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *a, const sbp_msg_pos_llh_cov_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *a, const sbp_msg_baseline_ecef_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *a, const sbp_msg_baseline_ned_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *a, const sbp_msg_vel_ecef_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *a, const sbp_msg_vel_ecef_cov_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *a, const sbp_msg_vel_ned_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *a, const sbp_msg_vel_ned_cov_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *a, const sbp_msg_pos_ecef_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *a, const sbp_msg_pos_ecef_cov_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *a, const sbp_msg_pos_llh_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *a, const sbp_msg_pos_llh_cov_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *a, const sbp_msg_vel_ecef_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *a, const sbp_msg_vel_ecef_cov_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *a, const sbp_msg_vel_ned_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *a, const sbp_msg_vel_ned_cov_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *a, const sbp_msg_vel_body_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *a, const sbp_msg_age_corrections_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->age, &b->age);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *a, const sbp_msg_gps_time_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ns_residual, &b->ns_residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *a, const sbp_msg_dops_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->gdop, &b->gdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pdop, &b->pdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->tdop, &b->tdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hdop, &b->hdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vdop, &b->vdop);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *a, const sbp_msg_pos_ecef_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *a, const sbp_msg_pos_llh_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *a, const sbp_msg_baseline_ecef_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *a, const sbp_msg_baseline_ned_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *a, const sbp_msg_vel_ecef_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *a, const sbp_msg_vel_ned_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *a, const sbp_msg_baseline_heading_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->heading, &b->heading);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_protection_level_dep_a_t(const sbp_msg_protection_level_dep_a_t *a, const sbp_msg_protection_level_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vpl, &b->vpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hpl, &b->hpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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
#endif
static inline int sbp_cmp_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *a, const sbp_msg_protection_level_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hpl, &b->hpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vpl, &b->vpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->atpl, &b->atpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->ctpl, &b->ctpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hvpl, &b->hvpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vvpl, &b->vvpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hopl, &b->hopl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->popl, &b->popl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->ropl, &b->ropl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->v_x, &b->v_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->v_y, &b->v_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->v_z, &b->v_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->roll, &b->roll);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->pitch, &b->pitch);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->heading, &b->heading);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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

#endif
