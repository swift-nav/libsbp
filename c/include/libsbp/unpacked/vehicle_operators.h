#ifndef LIBSBP_VEHICLE_OPERATORS_H
#define LIBSBP_VEHICLE_OPERATORS_H

#ifndef LIBSBP_VEHICLE_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/vehicle.h instead"
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
static inline int sbp_cmp_sbp_msg_odometry_t(const sbp_msg_odometry_t *a, const sbp_msg_odometry_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->velocity, &b->velocity);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return sbp_cmp_sbp_msg_odometry_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *a, const sbp_msg_wheeltick_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->source, &b->source);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ticks, &b->ticks);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return sbp_cmp_sbp_msg_wheeltick_t(&a, &b) >= 0;
}
#endif

#endif
