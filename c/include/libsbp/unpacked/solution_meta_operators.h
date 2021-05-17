#ifndef LIBSBP_SOLUTION_META_OPERATORS_H
#define LIBSBP_SOLUTION_META_OPERATORS_H

#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/solution_meta.h instead"
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
static inline int sbp_cmp_sbp_solution_input_type_t(const sbp_solution_input_type_t *a, const sbp_solution_input_type_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->sensor_type, &b->sensor_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_solution_input_type_t &a, const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_solution_input_type_t &a, const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_solution_input_type_t &a, const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_solution_input_type_t &a, const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_solution_input_type_t &a, const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_solution_input_type_t &a, const sbp_solution_input_type_t &b) {
  return sbp_cmp_sbp_solution_input_type_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *a, const sbp_msg_soln_meta_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->pdop, &b->pdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hdop, &b->hdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vdop, &b->vdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->age_corrections, &b->age_corrections);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->alignment_status, &b->alignment_status);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->last_used_gnss_pos_tow, &b->last_used_gnss_pos_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->last_used_gnss_vel_tow, &b->last_used_gnss_vel_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sol_in, &b->n_sol_in);
  for (uint8_t i = 0; i < a->n_sol_in && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_solution_input_type_t(&a->sol_in[i], &b->sol_in[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *a, const sbp_msg_soln_meta_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pdop, &b->pdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hdop, &b->hdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vdop, &b->vdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->age_corrections, &b->age_corrections);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->age_gnss, &b->age_gnss);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sol_in, &b->n_sol_in);
  for (uint8_t i = 0; i < a->n_sol_in && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_solution_input_type_t(&a->sol_in[i], &b->sol_in[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  return sbp_cmp_sbp_msg_soln_meta_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *a, const sbp_gnss_input_type_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_gnss_input_type_t &a, const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gnss_input_type_t &a, const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gnss_input_type_t &a, const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gnss_input_type_t &a, const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gnss_input_type_t &a, const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gnss_input_type_t &a, const sbp_gnss_input_type_t &b) {
  return sbp_cmp_sbp_gnss_input_type_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_imu_input_type_t(const sbp_imu_input_type_t *a, const sbp_imu_input_type_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_imu_input_type_t &a, const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_imu_input_type_t &a, const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_imu_input_type_t &a, const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_imu_input_type_t &a, const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_imu_input_type_t &a, const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_imu_input_type_t &a, const sbp_imu_input_type_t &b) {
  return sbp_cmp_sbp_imu_input_type_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_odo_input_type_t(const sbp_odo_input_type_t *a, const sbp_odo_input_type_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_odo_input_type_t &a, const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_odo_input_type_t &a, const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_odo_input_type_t &a, const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_odo_input_type_t &a, const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_odo_input_type_t &a, const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_odo_input_type_t &a, const sbp_odo_input_type_t &b) {
  return sbp_cmp_sbp_odo_input_type_t(&a, &b) >= 0;
}
#endif

#endif
