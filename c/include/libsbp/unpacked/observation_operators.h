#ifndef LIBSBP_OBSERVATION_OPERATORS_H
#define LIBSBP_OBSERVATION_OPERATORS_H

#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/observation.h instead"
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
static inline int sbp_cmp_sbp_observation_header_t(const sbp_observation_header_t *a, const sbp_observation_header_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gps_time_t(&a->t, &b->t);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_observation_header_t &a, const sbp_observation_header_t &b) {
  return sbp_cmp_sbp_observation_header_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_observation_header_t &a, const sbp_observation_header_t &b) {
  return sbp_cmp_sbp_observation_header_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_observation_header_t &a, const sbp_observation_header_t &b) {
  return sbp_cmp_sbp_observation_header_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_observation_header_t &a, const sbp_observation_header_t &b) {
  return sbp_cmp_sbp_observation_header_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_observation_header_t &a, const sbp_observation_header_t &b) {
  return sbp_cmp_sbp_observation_header_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_observation_header_t &a, const sbp_observation_header_t &b) {
  return sbp_cmp_sbp_observation_header_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_doppler_t(const sbp_doppler_t *a, const sbp_doppler_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->i, &b->i);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->f, &b->f);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_doppler_t &a, const sbp_doppler_t &b) {
  return sbp_cmp_sbp_doppler_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_doppler_t &a, const sbp_doppler_t &b) {
  return sbp_cmp_sbp_doppler_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_doppler_t &a, const sbp_doppler_t &b) {
  return sbp_cmp_sbp_doppler_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_doppler_t &a, const sbp_doppler_t &b) {
  return sbp_cmp_sbp_doppler_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_doppler_t &a, const sbp_doppler_t &b) {
  return sbp_cmp_sbp_doppler_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_doppler_t &a, const sbp_doppler_t &b) {
  return sbp_cmp_sbp_doppler_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_packed_obs_content_t(const sbp_packed_obs_content_t *a, const sbp_packed_obs_content_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_doppler_t(&a->D, &b->D);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->lock, &b->lock);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_packed_obs_content_t &a, const sbp_packed_obs_content_t &b) {
  return sbp_cmp_sbp_packed_obs_content_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_packed_obs_content_t &a, const sbp_packed_obs_content_t &b) {
  return sbp_cmp_sbp_packed_obs_content_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_packed_obs_content_t &a, const sbp_packed_obs_content_t &b) {
  return sbp_cmp_sbp_packed_obs_content_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_packed_obs_content_t &a, const sbp_packed_obs_content_t &b) {
  return sbp_cmp_sbp_packed_obs_content_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_packed_obs_content_t &a, const sbp_packed_obs_content_t &b) {
  return sbp_cmp_sbp_packed_obs_content_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_packed_obs_content_t &a, const sbp_packed_obs_content_t &b) {
  return sbp_cmp_sbp_packed_obs_content_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_packed_osr_content_t(const sbp_packed_osr_content_t *a, const sbp_packed_osr_content_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->lock, &b->lock);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iono_std, &b->iono_std);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->tropo_std, &b->tropo_std);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->range_std, &b->range_std);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_packed_osr_content_t &a, const sbp_packed_osr_content_t &b) {
  return sbp_cmp_sbp_packed_osr_content_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_packed_osr_content_t &a, const sbp_packed_osr_content_t &b) {
  return sbp_cmp_sbp_packed_osr_content_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_packed_osr_content_t &a, const sbp_packed_osr_content_t &b) {
  return sbp_cmp_sbp_packed_osr_content_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_packed_osr_content_t &a, const sbp_packed_osr_content_t &b) {
  return sbp_cmp_sbp_packed_osr_content_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_packed_osr_content_t &a, const sbp_packed_osr_content_t &b) {
  return sbp_cmp_sbp_packed_osr_content_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_packed_osr_content_t &a, const sbp_packed_osr_content_t &b) {
  return sbp_cmp_sbp_packed_osr_content_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_obs_t(const sbp_msg_obs_t *a, const sbp_msg_obs_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_observation_header_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_packed_obs_content_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_obs_t &a, const sbp_msg_obs_t &b) {
  return sbp_cmp_sbp_msg_obs_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_obs_t &a, const sbp_msg_obs_t &b) {
  return sbp_cmp_sbp_msg_obs_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_obs_t &a, const sbp_msg_obs_t &b) {
  return sbp_cmp_sbp_msg_obs_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_obs_t &a, const sbp_msg_obs_t &b) {
  return sbp_cmp_sbp_msg_obs_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_obs_t &a, const sbp_msg_obs_t &b) {
  return sbp_cmp_sbp_msg_obs_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_obs_t &a, const sbp_msg_obs_t &b) {
  return sbp_cmp_sbp_msg_obs_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_base_pos_llh_t(const sbp_msg_base_pos_llh_t *a, const sbp_msg_base_pos_llh_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_base_pos_llh_t &a, const sbp_msg_base_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_base_pos_llh_t &a, const sbp_msg_base_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_base_pos_llh_t &a, const sbp_msg_base_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_base_pos_llh_t &a, const sbp_msg_base_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_base_pos_llh_t &a, const sbp_msg_base_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_base_pos_llh_t &a, const sbp_msg_base_pos_llh_t &b) {
  return sbp_cmp_sbp_msg_base_pos_llh_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_base_pos_ecef_t(const sbp_msg_base_pos_ecef_t *a, const sbp_msg_base_pos_ecef_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_base_pos_ecef_t &a, const sbp_msg_base_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_base_pos_ecef_t &a, const sbp_msg_base_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_base_pos_ecef_t &a, const sbp_msg_base_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_base_pos_ecef_t &a, const sbp_msg_base_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_base_pos_ecef_t &a, const sbp_msg_base_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_base_pos_ecef_t &a, const sbp_msg_base_pos_ecef_t &b) {
  return sbp_cmp_sbp_msg_base_pos_ecef_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_ephemeris_common_content_t(const sbp_ephemeris_common_content_t *a, const sbp_ephemeris_common_content_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toe, &b->toe);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->ura, &b->ura);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_ephemeris_common_content_t &a, const sbp_ephemeris_common_content_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_ephemeris_common_content_t &a, const sbp_ephemeris_common_content_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_ephemeris_common_content_t &a, const sbp_ephemeris_common_content_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_ephemeris_common_content_t &a, const sbp_ephemeris_common_content_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_ephemeris_common_content_t &a, const sbp_ephemeris_common_content_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_ephemeris_common_content_t &a, const sbp_ephemeris_common_content_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_ephemeris_common_content_dep_b_t(const sbp_ephemeris_common_content_dep_b_t *a, const sbp_ephemeris_common_content_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toe, &b->toe);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ura, &b->ura);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_ephemeris_common_content_dep_b_t &a, const sbp_ephemeris_common_content_dep_b_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_ephemeris_common_content_dep_b_t &a, const sbp_ephemeris_common_content_dep_b_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_ephemeris_common_content_dep_b_t &a, const sbp_ephemeris_common_content_dep_b_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_ephemeris_common_content_dep_b_t &a, const sbp_ephemeris_common_content_dep_b_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_ephemeris_common_content_dep_b_t &a, const sbp_ephemeris_common_content_dep_b_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_ephemeris_common_content_dep_b_t &a, const sbp_ephemeris_common_content_dep_b_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_ephemeris_common_content_dep_a_t(const sbp_ephemeris_common_content_dep_a_t *a, const sbp_ephemeris_common_content_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_dep_t(&a->toe, &b->toe);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ura, &b->ura);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_ephemeris_common_content_dep_a_t &a, const sbp_ephemeris_common_content_dep_a_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_ephemeris_common_content_dep_a_t &a, const sbp_ephemeris_common_content_dep_a_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_ephemeris_common_content_dep_a_t &a, const sbp_ephemeris_common_content_dep_a_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_ephemeris_common_content_dep_a_t &a, const sbp_ephemeris_common_content_dep_a_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_ephemeris_common_content_dep_a_t &a, const sbp_ephemeris_common_content_dep_a_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_ephemeris_common_content_dep_a_t &a, const sbp_ephemeris_common_content_dep_a_t &b) {
  return sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(const sbp_msg_ephemeris_gps_dep_e_t *a, const sbp_msg_ephemeris_gps_dep_e_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_dep_t(&a->toc, &b->toc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_gps_dep_e_t &a, const sbp_msg_ephemeris_gps_dep_e_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_dep_e_t &a, const sbp_msg_ephemeris_gps_dep_e_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gps_dep_e_t &a, const sbp_msg_ephemeris_gps_dep_e_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gps_dep_e_t &a, const sbp_msg_ephemeris_gps_dep_e_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gps_dep_e_t &a, const sbp_msg_ephemeris_gps_dep_e_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gps_dep_e_t &a, const sbp_msg_ephemeris_gps_dep_e_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(const sbp_msg_ephemeris_gps_dep_f_t *a, const sbp_msg_ephemeris_gps_dep_f_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_gps_dep_f_t &a, const sbp_msg_ephemeris_gps_dep_f_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_dep_f_t &a, const sbp_msg_ephemeris_gps_dep_f_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gps_dep_f_t &a, const sbp_msg_ephemeris_gps_dep_f_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gps_dep_f_t &a, const sbp_msg_ephemeris_gps_dep_f_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gps_dep_f_t &a, const sbp_msg_ephemeris_gps_dep_f_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gps_dep_f_t &a, const sbp_msg_ephemeris_gps_dep_f_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_gps_t(const sbp_msg_ephemeris_gps_t *a, const sbp_msg_ephemeris_gps_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_gps_t &a, const sbp_msg_ephemeris_gps_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_t &a, const sbp_msg_ephemeris_gps_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gps_t &a, const sbp_msg_ephemeris_gps_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gps_t &a, const sbp_msg_ephemeris_gps_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gps_t &a, const sbp_msg_ephemeris_gps_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gps_t &a, const sbp_msg_ephemeris_gps_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gps_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_qzss_t(const sbp_msg_ephemeris_qzss_t *a, const sbp_msg_ephemeris_qzss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_qzss_t &a, const sbp_msg_ephemeris_qzss_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_qzss_t &a, const sbp_msg_ephemeris_qzss_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_qzss_t &a, const sbp_msg_ephemeris_qzss_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_qzss_t &a, const sbp_msg_ephemeris_qzss_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_qzss_t &a, const sbp_msg_ephemeris_qzss_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_qzss_t &a, const sbp_msg_ephemeris_qzss_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_qzss_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_bds_t(const sbp_msg_ephemeris_bds_t *a, const sbp_msg_ephemeris_bds_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->tgd1, &b->tgd1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->tgd2, &b->tgd2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_bds_t &a, const sbp_msg_ephemeris_bds_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_bds_t &a, const sbp_msg_ephemeris_bds_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_bds_t &a, const sbp_msg_ephemeris_bds_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_bds_t &a, const sbp_msg_ephemeris_bds_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_bds_t &a, const sbp_msg_ephemeris_bds_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_bds_t &a, const sbp_msg_ephemeris_bds_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_bds_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(const sbp_msg_ephemeris_gal_dep_a_t *a, const sbp_msg_ephemeris_gal_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->bgd_e1e5a, &b->bgd_e1e5a);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->bgd_e1e5b, &b->bgd_e1e5b);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_gal_dep_a_t &a, const sbp_msg_ephemeris_gal_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gal_dep_a_t &a, const sbp_msg_ephemeris_gal_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gal_dep_a_t &a, const sbp_msg_ephemeris_gal_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gal_dep_a_t &a, const sbp_msg_ephemeris_gal_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gal_dep_a_t &a, const sbp_msg_ephemeris_gal_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gal_dep_a_t &a, const sbp_msg_ephemeris_gal_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_gal_t(const sbp_msg_ephemeris_gal_t *a, const sbp_msg_ephemeris_gal_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->bgd_e1e5a, &b->bgd_e1e5a);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->bgd_e1e5b, &b->bgd_e1e5b);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->source, &b->source);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_gal_t &a, const sbp_msg_ephemeris_gal_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_gal_t &a, const sbp_msg_ephemeris_gal_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_gal_t &a, const sbp_msg_ephemeris_gal_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_gal_t &a, const sbp_msg_ephemeris_gal_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_gal_t &a, const sbp_msg_ephemeris_gal_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_gal_t &a, const sbp_msg_ephemeris_gal_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_gal_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(const sbp_msg_ephemeris_sbas_dep_a_t *a, const sbp_msg_ephemeris_sbas_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->a_gf0, &b->a_gf0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->a_gf1, &b->a_gf1);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_sbas_dep_a_t &a, const sbp_msg_ephemeris_sbas_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_dep_a_t &a, const sbp_msg_ephemeris_sbas_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_sbas_dep_a_t &a, const sbp_msg_ephemeris_sbas_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_sbas_dep_a_t &a, const sbp_msg_ephemeris_sbas_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_sbas_dep_a_t &a, const sbp_msg_ephemeris_sbas_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_sbas_dep_a_t &a, const sbp_msg_ephemeris_sbas_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(const sbp_msg_ephemeris_glo_dep_a_t *a, const sbp_msg_ephemeris_glo_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->gamma, &b->gamma);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->tau, &b->tau);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_glo_dep_a_t &a, const sbp_msg_ephemeris_glo_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_a_t &a, const sbp_msg_ephemeris_glo_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_dep_a_t &a, const sbp_msg_ephemeris_glo_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_dep_a_t &a, const sbp_msg_ephemeris_glo_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_dep_a_t &a, const sbp_msg_ephemeris_glo_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_dep_a_t &a, const sbp_msg_ephemeris_glo_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(const sbp_msg_ephemeris_sbas_dep_b_t *a, const sbp_msg_ephemeris_sbas_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->a_gf0, &b->a_gf0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->a_gf1, &b->a_gf1);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_sbas_dep_b_t &a, const sbp_msg_ephemeris_sbas_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_dep_b_t &a, const sbp_msg_ephemeris_sbas_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_sbas_dep_b_t &a, const sbp_msg_ephemeris_sbas_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_sbas_dep_b_t &a, const sbp_msg_ephemeris_sbas_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_sbas_dep_b_t &a, const sbp_msg_ephemeris_sbas_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_sbas_dep_b_t &a, const sbp_msg_ephemeris_sbas_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_sbas_t(const sbp_msg_ephemeris_sbas_t *a, const sbp_msg_ephemeris_sbas_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_float(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_float(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->a_gf0, &b->a_gf0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->a_gf1, &b->a_gf1);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_sbas_t &a, const sbp_msg_ephemeris_sbas_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_t &a, const sbp_msg_ephemeris_sbas_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_sbas_t &a, const sbp_msg_ephemeris_sbas_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_sbas_t &a, const sbp_msg_ephemeris_sbas_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_sbas_t &a, const sbp_msg_ephemeris_sbas_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_sbas_t &a, const sbp_msg_ephemeris_sbas_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_sbas_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(const sbp_msg_ephemeris_glo_dep_b_t *a, const sbp_msg_ephemeris_glo_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->gamma, &b->gamma);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->tau, &b->tau);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_glo_dep_b_t &a, const sbp_msg_ephemeris_glo_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_b_t &a, const sbp_msg_ephemeris_glo_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_dep_b_t &a, const sbp_msg_ephemeris_glo_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_dep_b_t &a, const sbp_msg_ephemeris_glo_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_dep_b_t &a, const sbp_msg_ephemeris_glo_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_dep_b_t &a, const sbp_msg_ephemeris_glo_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(const sbp_msg_ephemeris_glo_dep_c_t *a, const sbp_msg_ephemeris_glo_dep_c_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->gamma, &b->gamma);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->tau, &b->tau);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->d_tau, &b->d_tau);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->fcn, &b->fcn);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_glo_dep_c_t &a, const sbp_msg_ephemeris_glo_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_c_t &a, const sbp_msg_ephemeris_glo_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_dep_c_t &a, const sbp_msg_ephemeris_glo_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_dep_c_t &a, const sbp_msg_ephemeris_glo_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_dep_c_t &a, const sbp_msg_ephemeris_glo_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_dep_c_t &a, const sbp_msg_ephemeris_glo_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(const sbp_msg_ephemeris_glo_dep_d_t *a, const sbp_msg_ephemeris_glo_dep_d_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->gamma, &b->gamma);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->tau, &b->tau);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->d_tau, &b->d_tau);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->fcn, &b->fcn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod, &b->iod);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_glo_dep_d_t &a, const sbp_msg_ephemeris_glo_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_d_t &a, const sbp_msg_ephemeris_glo_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_dep_d_t &a, const sbp_msg_ephemeris_glo_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_dep_d_t &a, const sbp_msg_ephemeris_glo_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_dep_d_t &a, const sbp_msg_ephemeris_glo_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_dep_d_t &a, const sbp_msg_ephemeris_glo_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_glo_t(const sbp_msg_ephemeris_glo_t *a, const sbp_msg_ephemeris_glo_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->gamma, &b->gamma);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->tau, &b->tau);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->d_tau, &b->d_tau);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_float(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->fcn, &b->fcn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod, &b->iod);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_glo_t &a, const sbp_msg_ephemeris_glo_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_t &a, const sbp_msg_ephemeris_glo_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_glo_t &a, const sbp_msg_ephemeris_glo_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_glo_t &a, const sbp_msg_ephemeris_glo_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_glo_t &a, const sbp_msg_ephemeris_glo_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_glo_t &a, const sbp_msg_ephemeris_glo_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_glo_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_dep_d_t(const sbp_msg_ephemeris_dep_d_t *a, const sbp_msg_ephemeris_dep_d_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->toe_tow, &b->toe_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->toe_wn, &b->toe_wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->toc_tow, &b->toc_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->toc_wn, &b->toc_wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->healthy, &b->healthy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->reserved, &b->reserved);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_dep_d_t &a, const sbp_msg_ephemeris_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_d_t &a, const sbp_msg_ephemeris_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_dep_d_t &a, const sbp_msg_ephemeris_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_dep_d_t &a, const sbp_msg_ephemeris_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_dep_d_t &a, const sbp_msg_ephemeris_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_dep_d_t &a, const sbp_msg_ephemeris_dep_d_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_d_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_dep_a_t(const sbp_msg_ephemeris_dep_a_t *a, const sbp_msg_ephemeris_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->toe_tow, &b->toe_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->toe_wn, &b->toe_wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->toc_tow, &b->toc_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->toc_wn, &b->toc_wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->healthy, &b->healthy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_dep_a_t &a, const sbp_msg_ephemeris_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_a_t &a, const sbp_msg_ephemeris_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_dep_a_t &a, const sbp_msg_ephemeris_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_dep_a_t &a, const sbp_msg_ephemeris_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_dep_a_t &a, const sbp_msg_ephemeris_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_dep_a_t &a, const sbp_msg_ephemeris_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_dep_b_t(const sbp_msg_ephemeris_dep_b_t *a, const sbp_msg_ephemeris_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->toe_tow, &b->toe_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->toe_wn, &b->toe_wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->toc_tow, &b->toc_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->toc_wn, &b->toc_wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->healthy, &b->healthy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_dep_b_t &a, const sbp_msg_ephemeris_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_b_t &a, const sbp_msg_ephemeris_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_dep_b_t &a, const sbp_msg_ephemeris_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_dep_b_t &a, const sbp_msg_ephemeris_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_dep_b_t &a, const sbp_msg_ephemeris_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_dep_b_t &a, const sbp_msg_ephemeris_dep_b_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ephemeris_dep_c_t(const sbp_msg_ephemeris_dep_c_t *a, const sbp_msg_ephemeris_dep_c_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->toe_tow, &b->toe_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->toe_wn, &b->toe_wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->toc_tow, &b->toc_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->toc_wn, &b->toc_wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->healthy, &b->healthy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->reserved, &b->reserved);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ephemeris_dep_c_t &a, const sbp_msg_ephemeris_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_c_t &a, const sbp_msg_ephemeris_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ephemeris_dep_c_t &a, const sbp_msg_ephemeris_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ephemeris_dep_c_t &a, const sbp_msg_ephemeris_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ephemeris_dep_c_t &a, const sbp_msg_ephemeris_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ephemeris_dep_c_t &a, const sbp_msg_ephemeris_dep_c_t &b) {
  return sbp_cmp_sbp_msg_ephemeris_dep_c_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_observation_header_dep_t(const sbp_observation_header_dep_t *a, const sbp_observation_header_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_dep_t(&a->t, &b->t);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_observation_header_dep_t &a, const sbp_observation_header_dep_t &b) {
  return sbp_cmp_sbp_observation_header_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_observation_header_dep_t &a, const sbp_observation_header_dep_t &b) {
  return sbp_cmp_sbp_observation_header_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_observation_header_dep_t &a, const sbp_observation_header_dep_t &b) {
  return sbp_cmp_sbp_observation_header_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_observation_header_dep_t &a, const sbp_observation_header_dep_t &b) {
  return sbp_cmp_sbp_observation_header_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_observation_header_dep_t &a, const sbp_observation_header_dep_t &b) {
  return sbp_cmp_sbp_observation_header_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_observation_header_dep_t &a, const sbp_observation_header_dep_t &b) {
  return sbp_cmp_sbp_observation_header_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_carrier_phase_dep_a_t(const sbp_carrier_phase_dep_a_t *a, const sbp_carrier_phase_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s32(&a->i, &b->i);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->f, &b->f);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_carrier_phase_dep_a_t &a, const sbp_carrier_phase_dep_a_t &b) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_carrier_phase_dep_a_t &a, const sbp_carrier_phase_dep_a_t &b) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_carrier_phase_dep_a_t &a, const sbp_carrier_phase_dep_a_t &b) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_carrier_phase_dep_a_t &a, const sbp_carrier_phase_dep_a_t &b) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_carrier_phase_dep_a_t &a, const sbp_carrier_phase_dep_a_t &b) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_carrier_phase_dep_a_t &a, const sbp_carrier_phase_dep_a_t &b) {
  return sbp_cmp_sbp_carrier_phase_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_packed_obs_content_dep_a_t(const sbp_packed_obs_content_dep_a_t *a, const sbp_packed_obs_content_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_carrier_phase_dep_a_t(&a->L, &b->L);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_packed_obs_content_dep_a_t &a, const sbp_packed_obs_content_dep_a_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_a_t &a, const sbp_packed_obs_content_dep_a_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_packed_obs_content_dep_a_t &a, const sbp_packed_obs_content_dep_a_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_packed_obs_content_dep_a_t &a, const sbp_packed_obs_content_dep_a_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_packed_obs_content_dep_a_t &a, const sbp_packed_obs_content_dep_a_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_packed_obs_content_dep_a_t &a, const sbp_packed_obs_content_dep_a_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_packed_obs_content_dep_b_t(const sbp_packed_obs_content_dep_b_t *a, const sbp_packed_obs_content_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_carrier_phase_dep_a_t(&a->L, &b->L);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_packed_obs_content_dep_b_t &a, const sbp_packed_obs_content_dep_b_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_b_t &a, const sbp_packed_obs_content_dep_b_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_packed_obs_content_dep_b_t &a, const sbp_packed_obs_content_dep_b_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_packed_obs_content_dep_b_t &a, const sbp_packed_obs_content_dep_b_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_packed_obs_content_dep_b_t &a, const sbp_packed_obs_content_dep_b_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_packed_obs_content_dep_b_t &a, const sbp_packed_obs_content_dep_b_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_packed_obs_content_dep_c_t(const sbp_packed_obs_content_dep_c_t *a, const sbp_packed_obs_content_dep_c_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_packed_obs_content_dep_c_t &a, const sbp_packed_obs_content_dep_c_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_c_t &a, const sbp_packed_obs_content_dep_c_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_packed_obs_content_dep_c_t &a, const sbp_packed_obs_content_dep_c_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_packed_obs_content_dep_c_t &a, const sbp_packed_obs_content_dep_c_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_packed_obs_content_dep_c_t &a, const sbp_packed_obs_content_dep_c_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_packed_obs_content_dep_c_t &a, const sbp_packed_obs_content_dep_c_t &b) {
  return sbp_cmp_sbp_packed_obs_content_dep_c_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_obs_dep_a_t(const sbp_msg_obs_dep_a_t *a, const sbp_msg_obs_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_observation_header_dep_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_packed_obs_content_dep_a_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_obs_dep_a_t &a, const sbp_msg_obs_dep_a_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_obs_dep_a_t &a, const sbp_msg_obs_dep_a_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_obs_dep_a_t &a, const sbp_msg_obs_dep_a_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_obs_dep_a_t &a, const sbp_msg_obs_dep_a_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_obs_dep_a_t &a, const sbp_msg_obs_dep_a_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_obs_dep_a_t &a, const sbp_msg_obs_dep_a_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_obs_dep_b_t(const sbp_msg_obs_dep_b_t *a, const sbp_msg_obs_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_observation_header_dep_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_packed_obs_content_dep_b_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_obs_dep_b_t &a, const sbp_msg_obs_dep_b_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_obs_dep_b_t &a, const sbp_msg_obs_dep_b_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_obs_dep_b_t &a, const sbp_msg_obs_dep_b_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_obs_dep_b_t &a, const sbp_msg_obs_dep_b_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_obs_dep_b_t &a, const sbp_msg_obs_dep_b_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_obs_dep_b_t &a, const sbp_msg_obs_dep_b_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_obs_dep_c_t(const sbp_msg_obs_dep_c_t *a, const sbp_msg_obs_dep_c_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_observation_header_dep_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_packed_obs_content_dep_c_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_obs_dep_c_t &a, const sbp_msg_obs_dep_c_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_obs_dep_c_t &a, const sbp_msg_obs_dep_c_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_obs_dep_c_t &a, const sbp_msg_obs_dep_c_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_obs_dep_c_t &a, const sbp_msg_obs_dep_c_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_obs_dep_c_t &a, const sbp_msg_obs_dep_c_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_obs_dep_c_t &a, const sbp_msg_obs_dep_c_t &b) {
  return sbp_cmp_sbp_msg_obs_dep_c_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_iono_t(const sbp_msg_iono_t *a, const sbp_msg_iono_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_nmct, &b->t_nmct);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->a0, &b->a0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->a1, &b->a1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->a2, &b->a2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->a3, &b->a3);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->b0, &b->b0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->b1, &b->b1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->b2, &b->b2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->b3, &b->b3);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_iono_t &a, const sbp_msg_iono_t &b) {
  return sbp_cmp_sbp_msg_iono_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_iono_t &a, const sbp_msg_iono_t &b) {
  return sbp_cmp_sbp_msg_iono_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_iono_t &a, const sbp_msg_iono_t &b) {
  return sbp_cmp_sbp_msg_iono_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_iono_t &a, const sbp_msg_iono_t &b) {
  return sbp_cmp_sbp_msg_iono_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_iono_t &a, const sbp_msg_iono_t &b) {
  return sbp_cmp_sbp_msg_iono_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_iono_t &a, const sbp_msg_iono_t &b) {
  return sbp_cmp_sbp_msg_iono_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(const sbp_msg_sv_configuration_gps_dep_t *a, const sbp_msg_sv_configuration_gps_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_nmct, &b->t_nmct);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->l2c_mask, &b->l2c_mask);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_sv_configuration_gps_dep_t &a, const sbp_msg_sv_configuration_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_sv_configuration_gps_dep_t &a, const sbp_msg_sv_configuration_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_sv_configuration_gps_dep_t &a, const sbp_msg_sv_configuration_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_sv_configuration_gps_dep_t &a, const sbp_msg_sv_configuration_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_sv_configuration_gps_dep_t &a, const sbp_msg_sv_configuration_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_sv_configuration_gps_dep_t &a, const sbp_msg_sv_configuration_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_gnss_capb_t(const sbp_gnss_capb_t *a, const sbp_gnss_capb_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->gps_active, &b->gps_active);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->gps_l2c, &b->gps_l2c);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->gps_l5, &b->gps_l5);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->glo_active, &b->glo_active);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->glo_l2of, &b->glo_l2of);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->glo_l3, &b->glo_l3);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->sbas_active, &b->sbas_active);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->sbas_l5, &b->sbas_l5);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->bds_active, &b->bds_active);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->bds_d2nav, &b->bds_d2nav);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->bds_b2, &b->bds_b2);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->bds_b2a, &b->bds_b2a);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->qzss_active, &b->qzss_active);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->gal_active, &b->gal_active);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->gal_e5, &b->gal_e5);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_gnss_capb_t &a, const sbp_gnss_capb_t &b) {
  return sbp_cmp_sbp_gnss_capb_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gnss_capb_t &a, const sbp_gnss_capb_t &b) {
  return sbp_cmp_sbp_gnss_capb_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gnss_capb_t &a, const sbp_gnss_capb_t &b) {
  return sbp_cmp_sbp_gnss_capb_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gnss_capb_t &a, const sbp_gnss_capb_t &b) {
  return sbp_cmp_sbp_gnss_capb_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gnss_capb_t &a, const sbp_gnss_capb_t &b) {
  return sbp_cmp_sbp_gnss_capb_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gnss_capb_t &a, const sbp_gnss_capb_t &b) {
  return sbp_cmp_sbp_gnss_capb_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_gnss_capb_t(const sbp_msg_gnss_capb_t *a, const sbp_msg_gnss_capb_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_nmct, &b->t_nmct);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_capb_t(&a->gc, &b->gc);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_gnss_capb_t &a, const sbp_msg_gnss_capb_t &b) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_gnss_capb_t &a, const sbp_msg_gnss_capb_t &b) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_gnss_capb_t &a, const sbp_msg_gnss_capb_t &b) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_gnss_capb_t &a, const sbp_msg_gnss_capb_t &b) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_gnss_capb_t &a, const sbp_msg_gnss_capb_t &b) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_gnss_capb_t &a, const sbp_msg_gnss_capb_t &b) {
  return sbp_cmp_sbp_msg_gnss_capb_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_group_delay_dep_a_t(const sbp_msg_group_delay_dep_a_t *a, const sbp_msg_group_delay_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_dep_t(&a->t_op, &b->t_op);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->isc_l1ca, &b->isc_l1ca);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->isc_l2c, &b->isc_l2c);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_group_delay_dep_a_t &a, const sbp_msg_group_delay_dep_a_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_group_delay_dep_a_t &a, const sbp_msg_group_delay_dep_a_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_group_delay_dep_a_t &a, const sbp_msg_group_delay_dep_a_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_group_delay_dep_a_t &a, const sbp_msg_group_delay_dep_a_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_group_delay_dep_a_t &a, const sbp_msg_group_delay_dep_a_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_group_delay_dep_a_t &a, const sbp_msg_group_delay_dep_a_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_group_delay_dep_b_t(const sbp_msg_group_delay_dep_b_t *a, const sbp_msg_group_delay_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_op, &b->t_op);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->isc_l1ca, &b->isc_l1ca);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->isc_l2c, &b->isc_l2c);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_group_delay_dep_b_t &a, const sbp_msg_group_delay_dep_b_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_group_delay_dep_b_t &a, const sbp_msg_group_delay_dep_b_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_group_delay_dep_b_t &a, const sbp_msg_group_delay_dep_b_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_group_delay_dep_b_t &a, const sbp_msg_group_delay_dep_b_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_group_delay_dep_b_t &a, const sbp_msg_group_delay_dep_b_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_group_delay_dep_b_t &a, const sbp_msg_group_delay_dep_b_t &b) {
  return sbp_cmp_sbp_msg_group_delay_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_group_delay_t(const sbp_msg_group_delay_t *a, const sbp_msg_group_delay_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_op, &b->t_op);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->tgd, &b->tgd);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->isc_l1ca, &b->isc_l1ca);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->isc_l2c, &b->isc_l2c);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_group_delay_t &a, const sbp_msg_group_delay_t &b) {
  return sbp_cmp_sbp_msg_group_delay_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_group_delay_t &a, const sbp_msg_group_delay_t &b) {
  return sbp_cmp_sbp_msg_group_delay_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_group_delay_t &a, const sbp_msg_group_delay_t &b) {
  return sbp_cmp_sbp_msg_group_delay_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_group_delay_t &a, const sbp_msg_group_delay_t &b) {
  return sbp_cmp_sbp_msg_group_delay_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_group_delay_t &a, const sbp_msg_group_delay_t &b) {
  return sbp_cmp_sbp_msg_group_delay_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_group_delay_t &a, const sbp_msg_group_delay_t &b) {
  return sbp_cmp_sbp_msg_group_delay_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_almanac_common_content_t(const sbp_almanac_common_content_t *a, const sbp_almanac_common_content_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toa, &b->toa);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ura, &b->ura);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_almanac_common_content_t &a, const sbp_almanac_common_content_t &b) {
  return sbp_cmp_sbp_almanac_common_content_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_almanac_common_content_t &a, const sbp_almanac_common_content_t &b) {
  return sbp_cmp_sbp_almanac_common_content_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_almanac_common_content_t &a, const sbp_almanac_common_content_t &b) {
  return sbp_cmp_sbp_almanac_common_content_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_almanac_common_content_t &a, const sbp_almanac_common_content_t &b) {
  return sbp_cmp_sbp_almanac_common_content_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_almanac_common_content_t &a, const sbp_almanac_common_content_t &b) {
  return sbp_cmp_sbp_almanac_common_content_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_almanac_common_content_t &a, const sbp_almanac_common_content_t &b) {
  return sbp_cmp_sbp_almanac_common_content_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_almanac_common_content_dep_t(const sbp_almanac_common_content_dep_t *a, const sbp_almanac_common_content_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toa, &b->toa);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ura, &b->ura);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_almanac_common_content_dep_t &a, const sbp_almanac_common_content_dep_t &b) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_almanac_common_content_dep_t &a, const sbp_almanac_common_content_dep_t &b) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_almanac_common_content_dep_t &a, const sbp_almanac_common_content_dep_t &b) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_almanac_common_content_dep_t &a, const sbp_almanac_common_content_dep_t &b) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_almanac_common_content_dep_t &a, const sbp_almanac_common_content_dep_t &b) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_almanac_common_content_dep_t &a, const sbp_almanac_common_content_dep_t &b) {
  return sbp_cmp_sbp_almanac_common_content_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_almanac_gps_dep_t(const sbp_msg_almanac_gps_dep_t *a, const sbp_msg_almanac_gps_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_almanac_common_content_dep_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_almanac_gps_dep_t &a, const sbp_msg_almanac_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_gps_dep_t &a, const sbp_msg_almanac_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_almanac_gps_dep_t &a, const sbp_msg_almanac_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_gps_dep_t &a, const sbp_msg_almanac_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_gps_dep_t &a, const sbp_msg_almanac_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_gps_dep_t &a, const sbp_msg_almanac_gps_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_almanac_gps_t(const sbp_msg_almanac_gps_t *a, const sbp_msg_almanac_gps_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_almanac_common_content_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_almanac_gps_t &a, const sbp_msg_almanac_gps_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_gps_t &a, const sbp_msg_almanac_gps_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_almanac_gps_t &a, const sbp_msg_almanac_gps_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_gps_t &a, const sbp_msg_almanac_gps_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_gps_t &a, const sbp_msg_almanac_gps_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_gps_t &a, const sbp_msg_almanac_gps_t &b) {
  return sbp_cmp_sbp_msg_almanac_gps_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_almanac_glo_dep_t(const sbp_msg_almanac_glo_dep_t *a, const sbp_msg_almanac_glo_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_almanac_common_content_dep_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lambda_na, &b->lambda_na);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->t_lambda_na, &b->t_lambda_na);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->i, &b->i);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->t, &b->t);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->t_dot, &b->t_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->epsilon, &b->epsilon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega, &b->omega);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_almanac_glo_dep_t &a, const sbp_msg_almanac_glo_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_glo_dep_t &a, const sbp_msg_almanac_glo_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_almanac_glo_dep_t &a, const sbp_msg_almanac_glo_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_glo_dep_t &a, const sbp_msg_almanac_glo_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_glo_dep_t &a, const sbp_msg_almanac_glo_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_glo_dep_t &a, const sbp_msg_almanac_glo_dep_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_almanac_glo_t(const sbp_msg_almanac_glo_t *a, const sbp_msg_almanac_glo_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_almanac_common_content_t(&a->common, &b->common);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lambda_na, &b->lambda_na);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->t_lambda_na, &b->t_lambda_na);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->i, &b->i);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->t, &b->t);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->t_dot, &b->t_dot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->epsilon, &b->epsilon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->omega, &b->omega);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_almanac_glo_t &a, const sbp_msg_almanac_glo_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_glo_t &a, const sbp_msg_almanac_glo_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_almanac_glo_t &a, const sbp_msg_almanac_glo_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_glo_t &a, const sbp_msg_almanac_glo_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_glo_t &a, const sbp_msg_almanac_glo_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_glo_t &a, const sbp_msg_almanac_glo_t &b) {
  return sbp_cmp_sbp_msg_almanac_glo_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_glo_biases_t(const sbp_msg_glo_biases_t *a, const sbp_msg_glo_biases_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->mask, &b->mask);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->l1ca_bias, &b->l1ca_bias);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->l1p_bias, &b->l1p_bias);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->l2ca_bias, &b->l2ca_bias);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->l2p_bias, &b->l2p_bias);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_glo_biases_t &a, const sbp_msg_glo_biases_t &b) {
  return sbp_cmp_sbp_msg_glo_biases_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_glo_biases_t &a, const sbp_msg_glo_biases_t &b) {
  return sbp_cmp_sbp_msg_glo_biases_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_glo_biases_t &a, const sbp_msg_glo_biases_t &b) {
  return sbp_cmp_sbp_msg_glo_biases_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_glo_biases_t &a, const sbp_msg_glo_biases_t &b) {
  return sbp_cmp_sbp_msg_glo_biases_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_glo_biases_t &a, const sbp_msg_glo_biases_t &b) {
  return sbp_cmp_sbp_msg_glo_biases_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_glo_biases_t &a, const sbp_msg_glo_biases_t &b) {
  return sbp_cmp_sbp_msg_glo_biases_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_sv_az_el_t(const sbp_sv_az_el_t *a, const sbp_sv_az_el_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->az, &b->az);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s8(&a->el, &b->el);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_sv_az_el_t &a, const sbp_sv_az_el_t &b) {
  return sbp_cmp_sbp_sv_az_el_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_sv_az_el_t &a, const sbp_sv_az_el_t &b) {
  return sbp_cmp_sbp_sv_az_el_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_sv_az_el_t &a, const sbp_sv_az_el_t &b) {
  return sbp_cmp_sbp_sv_az_el_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_sv_az_el_t &a, const sbp_sv_az_el_t &b) {
  return sbp_cmp_sbp_sv_az_el_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_sv_az_el_t &a, const sbp_sv_az_el_t &b) {
  return sbp_cmp_sbp_sv_az_el_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_sv_az_el_t &a, const sbp_sv_az_el_t &b) {
  return sbp_cmp_sbp_sv_az_el_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *a, const sbp_msg_sv_az_el_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_azel, &b->n_azel);
  for (uint8_t i = 0; i < a->n_azel && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_sv_az_el_t(&a->azel[i], &b->azel[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_sv_az_el_t &a, const sbp_msg_sv_az_el_t &b) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_sv_az_el_t &a, const sbp_msg_sv_az_el_t &b) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_sv_az_el_t &a, const sbp_msg_sv_az_el_t &b) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_sv_az_el_t &a, const sbp_msg_sv_az_el_t &b) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_sv_az_el_t &a, const sbp_msg_sv_az_el_t &b) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_sv_az_el_t &a, const sbp_msg_sv_az_el_t &b) {
  return sbp_cmp_sbp_msg_sv_az_el_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_osr_t(const sbp_msg_osr_t *a, const sbp_msg_osr_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_observation_header_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_packed_osr_content_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_osr_t &a, const sbp_msg_osr_t &b) {
  return sbp_cmp_sbp_msg_osr_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_osr_t &a, const sbp_msg_osr_t &b) {
  return sbp_cmp_sbp_msg_osr_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_osr_t &a, const sbp_msg_osr_t &b) {
  return sbp_cmp_sbp_msg_osr_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_osr_t &a, const sbp_msg_osr_t &b) {
  return sbp_cmp_sbp_msg_osr_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_osr_t &a, const sbp_msg_osr_t &b) {
  return sbp_cmp_sbp_msg_osr_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_osr_t &a, const sbp_msg_osr_t &b) {
  return sbp_cmp_sbp_msg_osr_t(&a, &b) >= 0;
}
#endif

#endif
