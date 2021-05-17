#ifndef LIBSBP_MAG_OPERATORS_H
#define LIBSBP_MAG_OPERATORS_H

#ifndef LIBSBP_MAG_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/mag.h instead"
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
static inline int sbp_cmp_sbp_msg_mag_raw_t(const sbp_msg_mag_raw_t *a, const sbp_msg_mag_raw_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->tow_f, &b->tow_f);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->mag_x, &b->mag_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->mag_y, &b->mag_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->mag_z, &b->mag_z);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) >= 0;
}
#endif

#endif
