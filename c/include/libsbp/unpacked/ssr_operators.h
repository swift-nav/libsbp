#ifndef LIBSBP_SSR_OPERATORS_H
#define LIBSBP_SSR_OPERATORS_H

#ifndef LIBSBP_SSR_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ssr.h instead"
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
static inline int sbp_cmp_sbp_code_biases_content_t(const sbp_code_biases_content_t *a, const sbp_code_biases_content_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->code, &b->code);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->value, &b->value);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return sbp_cmp_sbp_code_biases_content_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *a, const sbp_phase_biases_content_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->code, &b->code);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->integer_indicator, &b->integer_indicator);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->widelane_integer_indicator, &b->widelane_integer_indicator);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->discontinuity_counter, &b->discontinuity_counter);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->bias, &b->bias);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return sbp_cmp_sbp_phase_biases_content_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_stec_header_t(const sbp_stec_header_t *a, const sbp_stec_header_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->tile_set_id, &b->tile_set_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->tile_id, &b->tile_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->num_msgs, &b->num_msgs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->seq_num, &b->seq_num);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->update_interval, &b->update_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod_atmo, &b->iod_atmo);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return sbp_cmp_sbp_stec_header_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_gridded_correction_header_t(const sbp_gridded_correction_header_t *a, const sbp_gridded_correction_header_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->tile_set_id, &b->tile_set_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->tile_id, &b->tile_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->num_msgs, &b->num_msgs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->seq_num, &b->seq_num);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->update_interval, &b->update_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod_atmo, &b->iod_atmo);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->tropo_quality_indicator, &b->tropo_quality_indicator);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *a, const sbp_stec_sat_element_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sv_id_t(&a->sv_id, &b->sv_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->stec_quality_indicator, &b->stec_quality_indicator);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 4 && ret == 0; i++)
  {
    ret = sbp_cmp_s16(&a->stec_coeff[i], &b->stec_coeff[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return sbp_cmp_sbp_stec_sat_element_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(const sbp_tropospheric_delay_correction_no_std_t *a, const sbp_tropospheric_delay_correction_no_std_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->hydro, &b->hydro);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s8(&a->wet, &b->wet);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_tropospheric_delay_correction_t(const sbp_tropospheric_delay_correction_t *a, const sbp_tropospheric_delay_correction_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->hydro, &b->hydro);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s8(&a->wet, &b->wet);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->stddev, &b->stddev);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return sbp_cmp_sbp_tropospheric_delay_correction_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *a, const sbp_stec_residual_no_std_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sv_id_t(&a->sv_id, &b->sv_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->residual, &b->residual);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return sbp_cmp_sbp_stec_residual_no_std_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_stec_residual_t(const sbp_stec_residual_t *a, const sbp_stec_residual_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sv_id_t(&a->sv_id, &b->sv_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->residual, &b->residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->stddev, &b->stddev);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return sbp_cmp_sbp_stec_residual_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *a, const sbp_msg_ssr_orbit_clock_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->update_interval, &b->update_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod_ssr, &b->iod_ssr);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->iod, &b->iod);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->radial, &b->radial);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->along, &b->along);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cross, &b->cross);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->dot_radial, &b->dot_radial);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->dot_along, &b->dot_along);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->dot_cross, &b->dot_cross);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->c0, &b->c0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->c1, &b->c1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->c2, &b->c2);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *a, const sbp_msg_ssr_code_biases_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->update_interval, &b->update_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod_ssr, &b->iod_ssr);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_biases, &b->n_biases);
  for (uint8_t i = 0; i < a->n_biases && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_code_biases_content_t(&a->biases[i], &b->biases[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_code_biases_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *a, const sbp_msg_ssr_phase_biases_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->update_interval, &b->update_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod_ssr, &b->iod_ssr);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->dispersive_bias, &b->dispersive_bias);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->mw_consistency, &b->mw_consistency);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->yaw, &b->yaw);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s8(&a->yaw_rate, &b->yaw_rate);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_biases, &b->n_biases);
  for (uint8_t i = 0; i < a->n_biases && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_phase_biases_content_t(&a->biases[i], &b->biases[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return sbp_cmp_sbp_msg_ssr_phase_biases_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_stec_correction_t(const sbp_msg_ssr_stec_correction_t *a, const sbp_msg_ssr_stec_correction_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_stec_header_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_stec_sat_list, &b->n_stec_sat_list);
  for (uint8_t i = 0; i < a->n_stec_sat_list && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_stec_sat_element_t(&a->stec_sat_list[i], &b->stec_sat_list[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_gridded_correction_t(const sbp_msg_ssr_gridded_correction_t *a, const sbp_msg_ssr_gridded_correction_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gridded_correction_header_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_tropospheric_delay_correction_t(&a->tropo_delay_correction, &b->tropo_delay_correction);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_stec_residuals, &b->n_stec_residuals);
  for (uint8_t i = 0; i < a->n_stec_residuals && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_stec_residual_t(&a->stec_residuals[i], &b->stec_residuals[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_tile_definition_t(const sbp_msg_ssr_tile_definition_t *a, const sbp_msg_ssr_tile_definition_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->tile_set_id, &b->tile_set_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->tile_id, &b->tile_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->corner_nw_lat, &b->corner_nw_lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->corner_nw_lon, &b->corner_nw_lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->spacing_lat, &b->spacing_lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->spacing_lon, &b->spacing_lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->rows, &b->rows);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->cols, &b->cols);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->bitmask, &b->bitmask);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return sbp_cmp_sbp_msg_ssr_tile_definition_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_satellite_apc_t(const sbp_satellite_apc_t *a, const sbp_satellite_apc_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->sat_info, &b->sat_info);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->svn, &b->svn);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_s16(&a->pco[i], &b->pco[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 21 && ret == 0; i++)
  {
    ret = sbp_cmp_s8(&a->pcv[i], &b->pcv[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return sbp_cmp_sbp_satellite_apc_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *a, const sbp_msg_ssr_satellite_apc_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_apc, &b->n_apc);
  for (uint8_t i = 0; i < a->n_apc && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_satellite_apc_t(&a->apc[i], &b->apc[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return sbp_cmp_sbp_msg_ssr_satellite_apc_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(const sbp_msg_ssr_orbit_clock_dep_a_t *a, const sbp_msg_ssr_orbit_clock_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->update_interval, &b->update_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod_ssr, &b->iod_ssr);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod, &b->iod);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->radial, &b->radial);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->along, &b->along);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cross, &b->cross);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->dot_radial, &b->dot_radial);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->dot_along, &b->dot_along);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->dot_cross, &b->dot_cross);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->c0, &b->c0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->c1, &b->c1);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->c2, &b->c2);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *a, const sbp_stec_header_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->num_msgs, &b->num_msgs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->seq_num, &b->seq_num);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->update_interval, &b->update_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod_atmo, &b->iod_atmo);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return sbp_cmp_sbp_stec_header_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_gridded_correction_header_dep_a_t(const sbp_gridded_correction_header_dep_a_t *a, const sbp_gridded_correction_header_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gps_time_sec_t(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->num_msgs, &b->num_msgs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->seq_num, &b->seq_num);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->update_interval, &b->update_interval);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->iod_atmo, &b->iod_atmo);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->tropo_quality_indicator, &b->tropo_quality_indicator);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_grid_definition_header_dep_a_t(const sbp_grid_definition_header_dep_a_t *a, const sbp_grid_definition_header_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->region_size_inverse, &b->region_size_inverse);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->area_width, &b->area_width);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->lat_nw_corner_enc, &b->lat_nw_corner_enc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->lon_nw_corner_enc, &b->lon_nw_corner_enc);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->num_msgs, &b->num_msgs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->seq_num, &b->seq_num);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return sbp_cmp_sbp_grid_definition_header_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(const sbp_msg_ssr_stec_correction_dep_a_t *a, const sbp_msg_ssr_stec_correction_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_stec_header_dep_a_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_stec_sat_list, &b->n_stec_sat_list);
  for (uint8_t i = 0; i < a->n_stec_sat_list && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_stec_sat_element_t(&a->stec_sat_list[i], &b->stec_sat_list[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(&a->tropo_delay_correction, &b->tropo_delay_correction);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_stec_residuals, &b->n_stec_residuals);
  for (uint8_t i = 0; i < a->n_stec_residuals && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_stec_residual_no_std_t(&a->stec_residuals[i], &b->stec_residuals[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(const sbp_msg_ssr_gridded_correction_dep_a_t *a, const sbp_msg_ssr_gridded_correction_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_gridded_correction_header_dep_a_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_tropospheric_delay_correction_t(&a->tropo_delay_correction, &b->tropo_delay_correction);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_stec_residuals, &b->n_stec_residuals);
  for (uint8_t i = 0; i < a->n_stec_residuals && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_stec_residual_t(&a->stec_residuals[i], &b->stec_residuals[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(const sbp_msg_ssr_grid_definition_dep_a_t *a, const sbp_msg_ssr_grid_definition_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_grid_definition_header_dep_a_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_rle_list, &b->n_rle_list);
  for (uint8_t i = 0; i < a->n_rle_list && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->rle_list[i], &b->rle_list[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(&a, &b) >= 0;
}
#endif

#endif
