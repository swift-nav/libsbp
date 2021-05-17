#ifndef LIBSBP_ACQUISITION_OPERATORS_H
#define LIBSBP_ACQUISITION_OPERATORS_H

#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/acquisition.h instead"
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
static inline int sbp_cmp_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *a, const sbp_msg_acq_result_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_float(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_acq_result_t &a, const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_t &a, const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_t &a, const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_t &a, const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_t &a, const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_t &a, const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_acq_result_dep_c_t(const sbp_msg_acq_result_dep_c_t *a, const sbp_msg_acq_result_dep_c_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_float(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_acq_result_dep_c_t &a, const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_c_t &a, const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_dep_c_t &a, const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_dep_c_t &a, const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_dep_c_t &a, const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_dep_c_t &a, const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_acq_result_dep_b_t(const sbp_msg_acq_result_dep_b_t *a, const sbp_msg_acq_result_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_float(&a->snr, &b->snr);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_acq_result_dep_b_t &a, const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_b_t &a, const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_dep_b_t &a, const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_dep_b_t &a, const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_dep_b_t &a, const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_dep_b_t &a, const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_acq_result_dep_a_t(const sbp_msg_acq_result_dep_a_t *a, const sbp_msg_acq_result_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_float(&a->snr, &b->snr);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_acq_result_dep_a_t &a, const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_a_t &a, const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_dep_a_t &a, const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_dep_a_t &a, const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_dep_a_t &a, const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_dep_a_t &a, const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *a, const sbp_acq_sv_profile_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->job_type, &b->job_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->int_time, &b->int_time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->bin_width, &b->bin_width);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->timestamp, &b->timestamp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time_spent, &b->time_spent);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf_min, &b->cf_min);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf_max, &b->cf_max);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_acq_sv_profile_t &a, const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_acq_sv_profile_t &a, const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_acq_sv_profile_t &a, const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_acq_sv_profile_t &a, const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_acq_sv_profile_t &a, const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_acq_sv_profile_t &a, const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_acq_sv_profile_dep_t(const sbp_acq_sv_profile_dep_t *a, const sbp_acq_sv_profile_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->job_type, &b->job_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->int_time, &b->int_time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->bin_width, &b->bin_width);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->timestamp, &b->timestamp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time_spent, &b->time_spent);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf_min, &b->cf_min);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf_max, &b->cf_max);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_acq_sv_profile_dep_t &a, const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_acq_sv_profile_dep_t &a, const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_acq_sv_profile_dep_t &a, const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_acq_sv_profile_dep_t &a, const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_acq_sv_profile_dep_t &a, const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_acq_sv_profile_dep_t &a, const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_acq_sv_profile_t(const sbp_msg_acq_sv_profile_t *a, const sbp_msg_acq_sv_profile_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_acq_sv_profile, &b->n_acq_sv_profile);
  for (uint8_t i = 0; i < a->n_acq_sv_profile && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_acq_sv_profile_t(&a->acq_sv_profile[i], &b->acq_sv_profile[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_acq_sv_profile_t &a, const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_sv_profile_t &a, const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_sv_profile_t &a, const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_sv_profile_t &a, const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_sv_profile_t &a, const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_sv_profile_t &a, const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_acq_sv_profile_dep_t(const sbp_msg_acq_sv_profile_dep_t *a, const sbp_msg_acq_sv_profile_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_acq_sv_profile, &b->n_acq_sv_profile);
  for (uint8_t i = 0; i < a->n_acq_sv_profile && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_acq_sv_profile_dep_t(&a->acq_sv_profile[i], &b->acq_sv_profile[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_acq_sv_profile_dep_t &a, const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_sv_profile_dep_t &a, const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_sv_profile_dep_t &a, const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_sv_profile_dep_t &a, const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_sv_profile_dep_t &a, const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_sv_profile_dep_t &a, const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) >= 0;
}
#endif

#endif
