#ifndef LIBSBP_ORIENTATION_OPERATORS_H
#define LIBSBP_ORIENTATION_OPERATORS_H

#ifndef LIBSBP_ORIENTATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/orientation.h instead"
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
static inline int sbp_cmp_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *a, const sbp_msg_baseline_heading_t *b) {
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
static inline bool operator==(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *a, const sbp_msg_orient_quat_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->w_accuracy, &b->w_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->x_accuracy, &b->x_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->y_accuracy, &b->y_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->z_accuracy, &b->z_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *a, const sbp_msg_orient_euler_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->roll, &b->roll);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->pitch, &b->pitch);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->yaw, &b->yaw);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->roll_accuracy, &b->roll_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->pitch_accuracy, &b->pitch_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->yaw_accuracy, &b->yaw_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *a, const sbp_msg_angular_rate_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) >= 0;
}
#endif

#endif
