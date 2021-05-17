#ifndef LIBSBP_SSR_PACKERS_H
#define LIBSBP_SSR_PACKERS_H

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
#include <libsbp/unpacked/base.h>
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_code_biases_content_t(const sbp_code_biases_content_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->code);
  packed_size += sbp_packed_size_s16(&msg->value);
  return packed_size;
}

static inline size_t sbp_pack_sbp_code_biases_content_t(u8 *buf, size_t len, const sbp_code_biases_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_code_biases_content_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->code);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->value);
  return offset;
}

static inline size_t sbp_unpack_sbp_code_biases_content_t(const uint8_t *buf, size_t len, sbp_code_biases_content_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->code);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->value);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->code);
  packed_size += sbp_packed_size_u8(&msg->integer_indicator);
  packed_size += sbp_packed_size_u8(&msg->widelane_integer_indicator);
  packed_size += sbp_packed_size_u8(&msg->discontinuity_counter);
  packed_size += sbp_packed_size_s32(&msg->bias);
  return packed_size;
}

static inline size_t sbp_pack_sbp_phase_biases_content_t(u8 *buf, size_t len, const sbp_phase_biases_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_phase_biases_content_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->code);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->integer_indicator);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->widelane_integer_indicator);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->discontinuity_counter);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->bias);
  return offset;
}

static inline size_t sbp_unpack_sbp_phase_biases_content_t(const uint8_t *buf, size_t len, sbp_phase_biases_content_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->code);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->integer_indicator);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->widelane_integer_indicator);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->discontinuity_counter);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->bias);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_header_t(const sbp_stec_header_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->tile_set_id);
  packed_size += sbp_packed_size_u16(&msg->tile_id);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->num_msgs);
  packed_size += sbp_packed_size_u8(&msg->seq_num);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_atmo);
  return packed_size;
}

static inline size_t sbp_pack_sbp_stec_header_t(u8 *buf, size_t len, const sbp_stec_header_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_header_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->tile_set_id);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->tile_id);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->seq_num);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod_atmo);
  return offset;
}

static inline size_t sbp_unpack_sbp_stec_header_t(const uint8_t *buf, size_t len, sbp_stec_header_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->tile_set_id);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->tile_id);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->seq_num);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod_atmo);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gridded_correction_header_t(const sbp_gridded_correction_header_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->tile_set_id);
  packed_size += sbp_packed_size_u16(&msg->tile_id);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_u16(&msg->num_msgs);
  packed_size += sbp_packed_size_u16(&msg->seq_num);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_atmo);
  packed_size += sbp_packed_size_u8(&msg->tropo_quality_indicator);
  return packed_size;
}

static inline size_t sbp_pack_sbp_gridded_correction_header_t(u8 *buf, size_t len, const sbp_gridded_correction_header_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gridded_correction_header_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->tile_set_id);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->tile_id);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->seq_num);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod_atmo);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->tropo_quality_indicator);
  return offset;
}

static inline size_t sbp_unpack_sbp_gridded_correction_header_t(const uint8_t *buf, size_t len, sbp_gridded_correction_header_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->tile_set_id);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->tile_id);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->seq_num);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod_atmo);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->tropo_quality_indicator);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sv_id_t(&msg->sv_id);
  packed_size += sbp_packed_size_u8(&msg->stec_quality_indicator);
  packed_size += ( 4 * sbp_packed_size_s16(&msg->stec_coeff[0]));
  return packed_size;
}

static inline size_t sbp_pack_sbp_stec_sat_element_t(u8 *buf, size_t len, const sbp_stec_sat_element_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_sat_element_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sv_id_t(buf + offset, len - offset, &msg->sv_id);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->stec_quality_indicator);
  for (uint8_t i = 0; i < 4; i++) 
  {
    offset += sbp_pack_s16(buf + offset, len - offset, &msg->stec_coeff[i]);
  }
  return offset;
}

static inline size_t sbp_unpack_sbp_stec_sat_element_t(const uint8_t *buf, size_t len, sbp_stec_sat_element_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sv_id_t(buf + offset, len - offset, &msg->sv_id);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->stec_quality_indicator);
  for (uint8_t i = 0; i < 4; i++)
  {
    offset += sbp_unpack_s16(buf + offset, len - offset, &msg->stec_coeff[i]);
  }
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(const sbp_tropospheric_delay_correction_no_std_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s16(&msg->hydro);
  packed_size += sbp_packed_size_s8(&msg->wet);
  return packed_size;
}

static inline size_t sbp_pack_sbp_tropospheric_delay_correction_no_std_t(u8 *buf, size_t len, const sbp_tropospheric_delay_correction_no_std_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(msg) > len) { return false; }
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->hydro);
  offset += sbp_pack_s8(buf + offset, len - offset, &msg->wet);
  return offset;
}

static inline size_t sbp_unpack_sbp_tropospheric_delay_correction_no_std_t(const uint8_t *buf, size_t len, sbp_tropospheric_delay_correction_no_std_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->hydro);
  offset += sbp_unpack_s8(buf + offset, len - offset, &msg->wet);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tropospheric_delay_correction_t(const sbp_tropospheric_delay_correction_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s16(&msg->hydro);
  packed_size += sbp_packed_size_s8(&msg->wet);
  packed_size += sbp_packed_size_u8(&msg->stddev);
  return packed_size;
}

static inline size_t sbp_pack_sbp_tropospheric_delay_correction_t(u8 *buf, size_t len, const sbp_tropospheric_delay_correction_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tropospheric_delay_correction_t(msg) > len) { return false; }
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->hydro);
  offset += sbp_pack_s8(buf + offset, len - offset, &msg->wet);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->stddev);
  return offset;
}

static inline size_t sbp_unpack_sbp_tropospheric_delay_correction_t(const uint8_t *buf, size_t len, sbp_tropospheric_delay_correction_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->hydro);
  offset += sbp_unpack_s8(buf + offset, len - offset, &msg->wet);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->stddev);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sv_id_t(&msg->sv_id);
  packed_size += sbp_packed_size_s16(&msg->residual);
  return packed_size;
}

static inline size_t sbp_pack_sbp_stec_residual_no_std_t(u8 *buf, size_t len, const sbp_stec_residual_no_std_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_residual_no_std_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sv_id_t(buf + offset, len - offset, &msg->sv_id);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->residual);
  return offset;
}

static inline size_t sbp_unpack_sbp_stec_residual_no_std_t(const uint8_t *buf, size_t len, sbp_stec_residual_no_std_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sv_id_t(buf + offset, len - offset, &msg->sv_id);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->residual);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_residual_t(const sbp_stec_residual_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sv_id_t(&msg->sv_id);
  packed_size += sbp_packed_size_s16(&msg->residual);
  packed_size += sbp_packed_size_u8(&msg->stddev);
  return packed_size;
}

static inline size_t sbp_pack_sbp_stec_residual_t(u8 *buf, size_t len, const sbp_stec_residual_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_residual_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sv_id_t(buf + offset, len - offset, &msg->sv_id);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->residual);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->stddev);
  return offset;
}

static inline size_t sbp_unpack_sbp_stec_residual_t(const uint8_t *buf, size_t len, sbp_stec_residual_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sv_id_t(buf + offset, len - offset, &msg->sv_id);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->residual);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->stddev);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_ssr);
  packed_size += sbp_packed_size_u32(&msg->iod);
  packed_size += sbp_packed_size_s32(&msg->radial);
  packed_size += sbp_packed_size_s32(&msg->along);
  packed_size += sbp_packed_size_s32(&msg->cross);
  packed_size += sbp_packed_size_s32(&msg->dot_radial);
  packed_size += sbp_packed_size_s32(&msg->dot_along);
  packed_size += sbp_packed_size_s32(&msg->dot_cross);
  packed_size += sbp_packed_size_s32(&msg->c0);
  packed_size += sbp_packed_size_s32(&msg->c1);
  packed_size += sbp_packed_size_s32(&msg->c2);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_orbit_clock_t(u8 *buf, size_t len, const sbp_msg_ssr_orbit_clock_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_orbit_clock_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod_ssr);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->iod);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->radial);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->along);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->cross);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->dot_radial);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->dot_along);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->dot_cross);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->c0);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->c1);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->c2);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_orbit_clock_t(const uint8_t *buf, size_t len, sbp_msg_ssr_orbit_clock_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod_ssr);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->iod);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->radial);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->along);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->cross);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->dot_radial);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->dot_along);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->dot_cross);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->c0);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->c1);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->c2);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_ssr);
  packed_size += (msg->n_biases * sbp_packed_size_sbp_code_biases_content_t(&msg->biases[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_code_biases_t(u8 *buf, size_t len, const sbp_msg_ssr_code_biases_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_code_biases_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod_ssr);
  for (uint8_t i = 0; i < msg->n_biases; i++) 
  {
    offset += sbp_pack_sbp_code_biases_content_t(buf + offset, len - offset, &msg->biases[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_code_biases_t(const uint8_t *buf, size_t len, sbp_msg_ssr_code_biases_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod_ssr);
  msg->n_biases = (uint8_t)((len - offset) / sbp_packed_size_sbp_code_biases_content_t(&msg->biases[0]));
  for (uint8_t i = 0; i < msg->n_biases; i++)
  {
    offset += sbp_unpack_sbp_code_biases_content_t(buf + offset, len - offset, &msg->biases[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_ssr);
  packed_size += sbp_packed_size_u8(&msg->dispersive_bias);
  packed_size += sbp_packed_size_u8(&msg->mw_consistency);
  packed_size += sbp_packed_size_u16(&msg->yaw);
  packed_size += sbp_packed_size_s8(&msg->yaw_rate);
  packed_size += (msg->n_biases * sbp_packed_size_sbp_phase_biases_content_t(&msg->biases[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_phase_biases_t(u8 *buf, size_t len, const sbp_msg_ssr_phase_biases_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_phase_biases_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod_ssr);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->dispersive_bias);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->mw_consistency);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->yaw);
  offset += sbp_pack_s8(buf + offset, len - offset, &msg->yaw_rate);
  for (uint8_t i = 0; i < msg->n_biases; i++) 
  {
    offset += sbp_pack_sbp_phase_biases_content_t(buf + offset, len - offset, &msg->biases[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_phase_biases_t(const uint8_t *buf, size_t len, sbp_msg_ssr_phase_biases_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod_ssr);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->dispersive_bias);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->mw_consistency);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->yaw);
  offset += sbp_unpack_s8(buf + offset, len - offset, &msg->yaw_rate);
  msg->n_biases = (uint8_t)((len - offset) / sbp_packed_size_sbp_phase_biases_content_t(&msg->biases[0]));
  for (uint8_t i = 0; i < msg->n_biases; i++)
  {
    offset += sbp_unpack_sbp_phase_biases_content_t(buf + offset, len - offset, &msg->biases[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_t(const sbp_msg_ssr_stec_correction_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_stec_header_t(&msg->header);
  packed_size += (msg->n_stec_sat_list * sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_stec_correction_t(u8 *buf, size_t len, const sbp_msg_ssr_stec_correction_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_stec_correction_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_stec_header_t(buf + offset, len - offset, &msg->header);
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++) 
  {
    offset += sbp_pack_sbp_stec_sat_element_t(buf + offset, len - offset, &msg->stec_sat_list[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_stec_correction_t(const uint8_t *buf, size_t len, sbp_msg_ssr_stec_correction_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_stec_header_t(buf + offset, len - offset, &msg->header);
  msg->n_stec_sat_list = (uint8_t)((len - offset) / sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++)
  {
    offset += sbp_unpack_sbp_stec_sat_element_t(buf + offset, len - offset, &msg->stec_sat_list[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_t(const sbp_msg_ssr_gridded_correction_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gridded_correction_header_t(&msg->header);
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_packed_size_sbp_tropospheric_delay_correction_t(&msg->tropo_delay_correction);
  packed_size += (msg->n_stec_residuals * sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_t(u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_gridded_correction_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gridded_correction_header_t(buf + offset, len - offset, &msg->header);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_sbp_tropospheric_delay_correction_t(buf + offset, len - offset, &msg->tropo_delay_correction);
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) 
  {
    offset += sbp_pack_sbp_stec_residual_t(buf + offset, len - offset, &msg->stec_residuals[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_t(const uint8_t *buf, size_t len, sbp_msg_ssr_gridded_correction_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gridded_correction_header_t(buf + offset, len - offset, &msg->header);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_sbp_tropospheric_delay_correction_t(buf + offset, len - offset, &msg->tropo_delay_correction);
  msg->n_stec_residuals = (uint8_t)((len - offset) / sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++)
  {
    offset += sbp_unpack_sbp_stec_residual_t(buf + offset, len - offset, &msg->stec_residuals[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_tile_definition_t(const sbp_msg_ssr_tile_definition_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->tile_set_id);
  packed_size += sbp_packed_size_u16(&msg->tile_id);
  packed_size += sbp_packed_size_s16(&msg->corner_nw_lat);
  packed_size += sbp_packed_size_s16(&msg->corner_nw_lon);
  packed_size += sbp_packed_size_u16(&msg->spacing_lat);
  packed_size += sbp_packed_size_u16(&msg->spacing_lon);
  packed_size += sbp_packed_size_u16(&msg->rows);
  packed_size += sbp_packed_size_u16(&msg->cols);
  packed_size += sbp_packed_size_u64(&msg->bitmask);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_tile_definition_t(u8 *buf, size_t len, const sbp_msg_ssr_tile_definition_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_tile_definition_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->tile_set_id);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->tile_id);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->corner_nw_lat);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->corner_nw_lon);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->spacing_lat);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->spacing_lon);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->rows);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->cols);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->bitmask);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_tile_definition_t(const uint8_t *buf, size_t len, sbp_msg_ssr_tile_definition_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->tile_set_id);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->tile_id);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->corner_nw_lat);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->corner_nw_lon);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->spacing_lat);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->spacing_lon);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->rows);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->cols);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->bitmask);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_satellite_apc_t(const sbp_satellite_apc_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->sat_info);
  packed_size += sbp_packed_size_u16(&msg->svn);
  packed_size += ( 3 * sbp_packed_size_s16(&msg->pco[0]));
  packed_size += ( 21 * sbp_packed_size_s8(&msg->pcv[0]));
  return packed_size;
}

static inline size_t sbp_pack_sbp_satellite_apc_t(u8 *buf, size_t len, const sbp_satellite_apc_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_satellite_apc_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->sat_info);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->svn);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_s16(buf + offset, len - offset, &msg->pco[i]);
  }
  for (uint8_t i = 0; i < 21; i++) 
  {
    offset += sbp_pack_s8(buf + offset, len - offset, &msg->pcv[i]);
  }
  return offset;
}

static inline size_t sbp_unpack_sbp_satellite_apc_t(const uint8_t *buf, size_t len, sbp_satellite_apc_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->sat_info);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->svn);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_s16(buf + offset, len - offset, &msg->pco[i]);
  }
  for (uint8_t i = 0; i < 21; i++)
  {
    offset += sbp_unpack_s8(buf + offset, len - offset, &msg->pcv[i]);
  }
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_apc * sbp_packed_size_sbp_satellite_apc_t(&msg->apc[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_satellite_apc_t(u8 *buf, size_t len, const sbp_msg_ssr_satellite_apc_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_satellite_apc_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_apc; i++) 
  {
    offset += sbp_pack_sbp_satellite_apc_t(buf + offset, len - offset, &msg->apc[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_satellite_apc_t(const uint8_t *buf, size_t len, sbp_msg_ssr_satellite_apc_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_apc = (uint8_t)((len - offset) / sbp_packed_size_sbp_satellite_apc_t(&msg->apc[0]));
  for (uint8_t i = 0; i < msg->n_apc; i++)
  {
    offset += sbp_unpack_sbp_satellite_apc_t(buf + offset, len - offset, &msg->apc[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_ssr);
  packed_size += sbp_packed_size_u8(&msg->iod);
  packed_size += sbp_packed_size_s32(&msg->radial);
  packed_size += sbp_packed_size_s32(&msg->along);
  packed_size += sbp_packed_size_s32(&msg->cross);
  packed_size += sbp_packed_size_s32(&msg->dot_radial);
  packed_size += sbp_packed_size_s32(&msg->dot_along);
  packed_size += sbp_packed_size_s32(&msg->dot_cross);
  packed_size += sbp_packed_size_s32(&msg->c0);
  packed_size += sbp_packed_size_s32(&msg->c1);
  packed_size += sbp_packed_size_s32(&msg->c2);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_orbit_clock_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod_ssr);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->radial);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->along);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->cross);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->dot_radial);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->dot_along);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->dot_cross);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->c0);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->c1);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->c2);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_orbit_clock_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod_ssr);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->radial);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->along);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->cross);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->dot_radial);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->dot_along);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->dot_cross);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->c0);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->c1);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->c2);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->num_msgs);
  packed_size += sbp_packed_size_u8(&msg->seq_num);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_atmo);
  return packed_size;
}

static inline size_t sbp_pack_sbp_stec_header_dep_a_t(u8 *buf, size_t len, const sbp_stec_header_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_stec_header_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->seq_num);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod_atmo);
  return offset;
}

static inline size_t sbp_unpack_sbp_stec_header_dep_a_t(const uint8_t *buf, size_t len, sbp_stec_header_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->seq_num);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod_atmo);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gridded_correction_header_dep_a_t(const sbp_gridded_correction_header_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_u16(&msg->num_msgs);
  packed_size += sbp_packed_size_u16(&msg->seq_num);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_atmo);
  packed_size += sbp_packed_size_u8(&msg->tropo_quality_indicator);
  return packed_size;
}

static inline size_t sbp_pack_sbp_gridded_correction_header_dep_a_t(u8 *buf, size_t len, const sbp_gridded_correction_header_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gridded_correction_header_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->seq_num);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod_atmo);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->tropo_quality_indicator);
  return offset;
}

static inline size_t sbp_unpack_sbp_gridded_correction_header_dep_a_t(const uint8_t *buf, size_t len, sbp_gridded_correction_header_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->seq_num);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->update_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod_atmo);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->tropo_quality_indicator);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_grid_definition_header_dep_a_t(const sbp_grid_definition_header_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->region_size_inverse);
  packed_size += sbp_packed_size_u16(&msg->area_width);
  packed_size += sbp_packed_size_u16(&msg->lat_nw_corner_enc);
  packed_size += sbp_packed_size_u16(&msg->lon_nw_corner_enc);
  packed_size += sbp_packed_size_u8(&msg->num_msgs);
  packed_size += sbp_packed_size_u8(&msg->seq_num);
  return packed_size;
}

static inline size_t sbp_pack_sbp_grid_definition_header_dep_a_t(u8 *buf, size_t len, const sbp_grid_definition_header_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_grid_definition_header_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->region_size_inverse);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->area_width);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->lat_nw_corner_enc);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->lon_nw_corner_enc);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->seq_num);
  return offset;
}

static inline size_t sbp_unpack_sbp_grid_definition_header_dep_a_t(const uint8_t *buf, size_t len, sbp_grid_definition_header_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->region_size_inverse);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->area_width);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->lat_nw_corner_enc);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->lon_nw_corner_enc);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->num_msgs);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->seq_num);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_stec_header_dep_a_t(&msg->header);
  packed_size += (msg->n_stec_sat_list * sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_stec_correction_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_stec_header_dep_a_t(buf + offset, len - offset, &msg->header);
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++) 
  {
    offset += sbp_pack_sbp_stec_sat_element_t(buf + offset, len - offset, &msg->stec_sat_list[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_stec_correction_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_stec_header_dep_a_t(buf + offset, len - offset, &msg->header);
  msg->n_stec_sat_list = (uint8_t)((len - offset) / sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++)
  {
    offset += sbp_unpack_sbp_stec_sat_element_t(buf + offset, len - offset, &msg->stec_sat_list[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gridded_correction_header_dep_a_t(&msg->header);
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(&msg->tropo_delay_correction);
  packed_size += (msg->n_stec_residuals * sbp_packed_size_sbp_stec_residual_no_std_t(&msg->stec_residuals[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gridded_correction_header_dep_a_t(buf + offset, len - offset, &msg->header);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_sbp_tropospheric_delay_correction_no_std_t(buf + offset, len - offset, &msg->tropo_delay_correction);
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) 
  {
    offset += sbp_pack_sbp_stec_residual_no_std_t(buf + offset, len - offset, &msg->stec_residuals[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gridded_correction_header_dep_a_t(buf + offset, len - offset, &msg->header);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_sbp_tropospheric_delay_correction_no_std_t(buf + offset, len - offset, &msg->tropo_delay_correction);
  msg->n_stec_residuals = (uint8_t)((len - offset) / sbp_packed_size_sbp_stec_residual_no_std_t(&msg->stec_residuals[0]));
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++)
  {
    offset += sbp_unpack_sbp_stec_residual_no_std_t(buf + offset, len - offset, &msg->stec_residuals[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gridded_correction_header_dep_a_t(&msg->header);
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_packed_size_sbp_tropospheric_delay_correction_t(&msg->tropo_delay_correction);
  packed_size += (msg->n_stec_residuals * sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gridded_correction_header_dep_a_t(buf + offset, len - offset, &msg->header);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->index);
  offset += sbp_pack_sbp_tropospheric_delay_correction_t(buf + offset, len - offset, &msg->tropo_delay_correction);
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) 
  {
    offset += sbp_pack_sbp_stec_residual_t(buf + offset, len - offset, &msg->stec_residuals[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gridded_correction_header_dep_a_t(buf + offset, len - offset, &msg->header);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->index);
  offset += sbp_unpack_sbp_tropospheric_delay_correction_t(buf + offset, len - offset, &msg->tropo_delay_correction);
  msg->n_stec_residuals = (uint8_t)((len - offset) / sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++)
  {
    offset += sbp_unpack_sbp_stec_residual_t(buf + offset, len - offset, &msg->stec_residuals[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_grid_definition_header_dep_a_t(&msg->header);
  packed_size += (msg->n_rle_list * sbp_packed_size_u8(&msg->rle_list[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_grid_definition_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_grid_definition_header_dep_a_t(buf + offset, len - offset, &msg->header);
  for (uint8_t i = 0; i < msg->n_rle_list; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->rle_list[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_grid_definition_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_grid_definition_header_dep_a_t(buf + offset, len - offset, &msg->header);
  msg->n_rle_list = (uint8_t)((len - offset) / sbp_packed_size_u8(&msg->rle_list[0]));
  for (uint8_t i = 0; i < msg->n_rle_list; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->rle_list[i]);
  }
  return true;
  return true;
}

#endif
