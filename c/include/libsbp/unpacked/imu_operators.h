#ifndef LIBSBP_IMU_OPERATORS_H
#define LIBSBP_IMU_OPERATORS_H

#ifndef LIBSBP_IMU_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/imu.h instead"
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
static inline int sbp_cmp_sbp_msg_imu_raw_t(const sbp_msg_imu_raw_t *a, const sbp_msg_imu_raw_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->tow_f, &b->tow_f);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->acc_x, &b->acc_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->acc_y, &b->acc_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->acc_z, &b->acc_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->gyr_x, &b->gyr_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->gyr_y, &b->gyr_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->gyr_z, &b->gyr_z);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_imu_raw_t &a, const sbp_msg_imu_raw_t &b) {
  return sbp_cmp_sbp_msg_imu_raw_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_imu_raw_t &a, const sbp_msg_imu_raw_t &b) {
  return sbp_cmp_sbp_msg_imu_raw_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_imu_raw_t &a, const sbp_msg_imu_raw_t &b) {
  return sbp_cmp_sbp_msg_imu_raw_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_imu_raw_t &a, const sbp_msg_imu_raw_t &b) {
  return sbp_cmp_sbp_msg_imu_raw_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_imu_raw_t &a, const sbp_msg_imu_raw_t &b) {
  return sbp_cmp_sbp_msg_imu_raw_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_imu_raw_t &a, const sbp_msg_imu_raw_t &b) {
  return sbp_cmp_sbp_msg_imu_raw_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_imu_aux_t(const sbp_msg_imu_aux_t *a, const sbp_msg_imu_aux_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->imu_type, &b->imu_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->temp, &b->temp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->imu_conf, &b->imu_conf);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_imu_aux_t &a, const sbp_msg_imu_aux_t &b) {
  return sbp_cmp_sbp_msg_imu_aux_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_imu_aux_t &a, const sbp_msg_imu_aux_t &b) {
  return sbp_cmp_sbp_msg_imu_aux_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_imu_aux_t &a, const sbp_msg_imu_aux_t &b) {
  return sbp_cmp_sbp_msg_imu_aux_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_imu_aux_t &a, const sbp_msg_imu_aux_t &b) {
  return sbp_cmp_sbp_msg_imu_aux_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_imu_aux_t &a, const sbp_msg_imu_aux_t &b) {
  return sbp_cmp_sbp_msg_imu_aux_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_imu_aux_t &a, const sbp_msg_imu_aux_t &b) {
  return sbp_cmp_sbp_msg_imu_aux_t(&a, &b) >= 0;
}
#endif

#endif
