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
#include <libsbp/unpacked/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_code_biases_content_t(const sbp_code_biases_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->code);
  packed_size += sbp_packed_size_s16(&msg->value);
  return packed_size;
}

static inline bool sbp_pack_sbp_code_biases_content_t(sbp_pack_ctx_t *ctx, const sbp_code_biases_content_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->code)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->value)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_code_biases_content_t(sbp_unpack_ctx_t *ctx, sbp_code_biases_content_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->code)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->value)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->code);
  packed_size += sbp_packed_size_u8(&msg->integer_indicator);
  packed_size += sbp_packed_size_u8(&msg->widelane_integer_indicator);
  packed_size += sbp_packed_size_u8(&msg->discontinuity_counter);
  packed_size += sbp_packed_size_s32(&msg->bias);
  return packed_size;
}

static inline bool sbp_pack_sbp_phase_biases_content_t(sbp_pack_ctx_t *ctx, const sbp_phase_biases_content_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->code)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->integer_indicator)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->widelane_integer_indicator)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->discontinuity_counter)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->bias)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_phase_biases_content_t(sbp_unpack_ctx_t *ctx, sbp_phase_biases_content_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->code)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->integer_indicator)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->widelane_integer_indicator)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->discontinuity_counter)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->bias)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_header_t(const sbp_stec_header_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->tile_set_id);
  packed_size += sbp_packed_size_u16(&msg->tile_id);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->num_msgs);
  packed_size += sbp_packed_size_u8(&msg->seq_num);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_atmo);
  return packed_size;
}

static inline bool sbp_pack_sbp_stec_header_t(sbp_pack_ctx_t *ctx, const sbp_stec_header_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->tile_id)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->seq_num)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod_atmo)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_stec_header_t(sbp_unpack_ctx_t *ctx, sbp_stec_header_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->tile_id)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->seq_num)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod_atmo)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gridded_correction_header_t(const sbp_gridded_correction_header_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_gridded_correction_header_t(sbp_pack_ctx_t *ctx, const sbp_gridded_correction_header_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->tile_id)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->seq_num)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod_atmo)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->tropo_quality_indicator)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_gridded_correction_header_t(sbp_unpack_ctx_t *ctx, sbp_gridded_correction_header_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->tile_id)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->seq_num)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod_atmo)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->tropo_quality_indicator)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sv_id_t(&msg->sv_id);
  packed_size += sbp_packed_size_u8(&msg->stec_quality_indicator);
  packed_size += ( 4 * sbp_packed_size_s16(&msg->stec_coeff[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_stec_sat_element_t(sbp_pack_ctx_t *ctx, const sbp_stec_sat_element_t *msg)
{
  if (!sbp_pack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->stec_quality_indicator)) { return false; }
  for (uint8_t i = 0; i < 4; i++)
  {
    if (!sbp_pack_s16(ctx, &msg->stec_coeff[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_stec_sat_element_t(sbp_unpack_ctx_t *ctx, sbp_stec_sat_element_t *msg)
{
  if (!sbp_unpack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->stec_quality_indicator)) { return false; }
  for (uint8_t i = 0; i < 4; i++) {
    if (!sbp_unpack_s16(ctx, &msg->stec_coeff[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(const sbp_tropospheric_delay_correction_no_std_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->hydro);
  packed_size += sbp_packed_size_s8(&msg->wet);
  return packed_size;
}

static inline bool sbp_pack_sbp_tropospheric_delay_correction_no_std_t(sbp_pack_ctx_t *ctx, const sbp_tropospheric_delay_correction_no_std_t *msg)
{
  if (!sbp_pack_s16(ctx, &msg->hydro)) { return false; }
  if (!sbp_pack_s8(ctx, &msg->wet)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_tropospheric_delay_correction_no_std_t(sbp_unpack_ctx_t *ctx, sbp_tropospheric_delay_correction_no_std_t *msg)
{
  if (!sbp_unpack_s16(ctx, &msg->hydro)) { return false; }
  if (!sbp_unpack_s8(ctx, &msg->wet)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tropospheric_delay_correction_t(const sbp_tropospheric_delay_correction_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->hydro);
  packed_size += sbp_packed_size_s8(&msg->wet);
  packed_size += sbp_packed_size_u8(&msg->stddev);
  return packed_size;
}

static inline bool sbp_pack_sbp_tropospheric_delay_correction_t(sbp_pack_ctx_t *ctx, const sbp_tropospheric_delay_correction_t *msg)
{
  if (!sbp_pack_s16(ctx, &msg->hydro)) { return false; }
  if (!sbp_pack_s8(ctx, &msg->wet)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->stddev)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_tropospheric_delay_correction_t(sbp_unpack_ctx_t *ctx, sbp_tropospheric_delay_correction_t *msg)
{
  if (!sbp_unpack_s16(ctx, &msg->hydro)) { return false; }
  if (!sbp_unpack_s8(ctx, &msg->wet)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->stddev)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sv_id_t(&msg->sv_id);
  packed_size += sbp_packed_size_s16(&msg->residual);
  return packed_size;
}

static inline bool sbp_pack_sbp_stec_residual_no_std_t(sbp_pack_ctx_t *ctx, const sbp_stec_residual_no_std_t *msg)
{
  if (!sbp_pack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->residual)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_stec_residual_no_std_t(sbp_unpack_ctx_t *ctx, sbp_stec_residual_no_std_t *msg)
{
  if (!sbp_unpack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->residual)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_residual_t(const sbp_stec_residual_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sv_id_t(&msg->sv_id);
  packed_size += sbp_packed_size_s16(&msg->residual);
  packed_size += sbp_packed_size_u8(&msg->stddev);
  return packed_size;
}

static inline bool sbp_pack_sbp_stec_residual_t(sbp_pack_ctx_t *ctx, const sbp_stec_residual_t *msg)
{
  if (!sbp_pack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->residual)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->stddev)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_stec_residual_t(sbp_unpack_ctx_t *ctx, sbp_stec_residual_t *msg)
{
  if (!sbp_unpack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->residual)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->stddev)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ssr_orbit_clock_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->iod)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->radial)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->along)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->cross)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->dot_radial)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->dot_along)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->dot_cross)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->c0)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->c1)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->c2)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_orbit_clock_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_orbit_clock_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->iod)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->radial)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->along)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->cross)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->dot_radial)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->dot_along)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->dot_cross)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->c0)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->c1)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->c2)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_ssr);
  packed_size += (msg->n_biases * sbp_packed_size_sbp_code_biases_content_t(&msg->biases[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_code_biases_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_code_biases_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod_ssr)) { return false; }
  for (uint8_t i = 0; i < msg->n_biases; i++)
  {
    if (!sbp_pack_sbp_code_biases_content_t(ctx, &msg->biases[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_code_biases_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_code_biases_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod_ssr)) { return false; }
    msg->n_biases = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_code_biases_content_t(&msg->biases[0]));
  for (uint8_t i = 0; i < msg->n_biases; i++) {
    if (!sbp_unpack_sbp_code_biases_content_t(ctx, &msg->biases[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ssr_phase_biases_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_phase_biases_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->dispersive_bias)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->mw_consistency)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->yaw)) { return false; }
  if (!sbp_pack_s8(ctx, &msg->yaw_rate)) { return false; }
  for (uint8_t i = 0; i < msg->n_biases; i++)
  {
    if (!sbp_pack_sbp_phase_biases_content_t(ctx, &msg->biases[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_phase_biases_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_phase_biases_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->dispersive_bias)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->mw_consistency)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->yaw)) { return false; }
  if (!sbp_unpack_s8(ctx, &msg->yaw_rate)) { return false; }
    msg->n_biases = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_phase_biases_content_t(&msg->biases[0]));
  for (uint8_t i = 0; i < msg->n_biases; i++) {
    if (!sbp_unpack_sbp_phase_biases_content_t(ctx, &msg->biases[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_t(const sbp_msg_ssr_stec_correction_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_stec_header_t(&msg->header);
  packed_size += (msg->n_stec_sat_list * sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_stec_correction_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_stec_correction_t *msg)
{
  if (!sbp_pack_sbp_stec_header_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++)
  {
    if (!sbp_pack_sbp_stec_sat_element_t(ctx, &msg->stec_sat_list[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_stec_correction_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_stec_correction_t *msg)
{
  if (!sbp_unpack_sbp_stec_header_t(ctx, &msg->header)) { return false; }
    msg->n_stec_sat_list = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++) {
    if (!sbp_unpack_sbp_stec_sat_element_t(ctx, &msg->stec_sat_list[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_t(const sbp_msg_ssr_gridded_correction_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gridded_correction_header_t(&msg->header);
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_packed_size_sbp_tropospheric_delay_correction_t(&msg->tropo_delay_correction);
  packed_size += (msg->n_stec_residuals * sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_t *msg)
{
  if (!sbp_pack_sbp_gridded_correction_header_t(ctx, &msg->header)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_pack_sbp_tropospheric_delay_correction_t(ctx, &msg->tropo_delay_correction)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++)
  {
    if (!sbp_pack_sbp_stec_residual_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_gridded_correction_t *msg)
{
  if (!sbp_unpack_sbp_gridded_correction_header_t(ctx, &msg->header)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_sbp_tropospheric_delay_correction_t(ctx, &msg->tropo_delay_correction)) { return false; }
    msg->n_stec_residuals = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!sbp_unpack_sbp_stec_residual_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_tile_definition_t(const sbp_msg_ssr_tile_definition_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ssr_tile_definition_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_tile_definition_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->tile_id)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->corner_nw_lat)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->corner_nw_lon)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->spacing_lat)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->spacing_lon)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->rows)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->cols)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->bitmask)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_tile_definition_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_tile_definition_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->tile_id)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->corner_nw_lat)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->corner_nw_lon)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->spacing_lat)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->spacing_lon)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->rows)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->cols)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->bitmask)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_satellite_apc_t(const sbp_satellite_apc_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->sat_info);
  packed_size += sbp_packed_size_u16(&msg->svn);
  packed_size += ( 3 * sbp_packed_size_s16(&msg->pco[0]));
  packed_size += ( 21 * sbp_packed_size_s8(&msg->pcv[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_satellite_apc_t(sbp_pack_ctx_t *ctx, const sbp_satellite_apc_t *msg)
{
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->sat_info)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->svn)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_s16(ctx, &msg->pco[i])) { return false; }
  }
  for (uint8_t i = 0; i < 21; i++)
  {
    if (!sbp_pack_s8(ctx, &msg->pcv[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_satellite_apc_t(sbp_unpack_ctx_t *ctx, sbp_satellite_apc_t *msg)
{
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->sat_info)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->svn)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_s16(ctx, &msg->pco[i])) { return false; }
  }
  for (uint8_t i = 0; i < 21; i++) {
    if (!sbp_unpack_s8(ctx, &msg->pcv[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_apc * sbp_packed_size_sbp_satellite_apc_t(&msg->apc[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_satellite_apc_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_satellite_apc_t *msg)
{
  for (uint8_t i = 0; i < msg->n_apc; i++)
  {
    if (!sbp_pack_sbp_satellite_apc_t(ctx, &msg->apc[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_satellite_apc_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_satellite_apc_t *msg)
{
    msg->n_apc = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_satellite_apc_t(&msg->apc[0]));
  for (uint8_t i = 0; i < msg->n_apc; i++) {
    if (!sbp_unpack_sbp_satellite_apc_t(ctx, &msg->apc[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ssr_orbit_clock_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_dep_a_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->radial)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->along)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->cross)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->dot_radial)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->dot_along)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->dot_cross)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->c0)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->c1)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->c2)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_orbit_clock_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_orbit_clock_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->radial)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->along)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->cross)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->dot_radial)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->dot_along)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->dot_cross)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->c0)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->c1)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->c2)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->num_msgs);
  packed_size += sbp_packed_size_u8(&msg->seq_num);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_atmo);
  return packed_size;
}

static inline bool sbp_pack_sbp_stec_header_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_stec_header_dep_a_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->seq_num)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod_atmo)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_stec_header_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_stec_header_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->seq_num)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod_atmo)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gridded_correction_header_dep_a_t(const sbp_gridded_correction_header_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_u16(&msg->num_msgs);
  packed_size += sbp_packed_size_u16(&msg->seq_num);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_atmo);
  packed_size += sbp_packed_size_u8(&msg->tropo_quality_indicator);
  return packed_size;
}

static inline bool sbp_pack_sbp_gridded_correction_header_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_gridded_correction_header_dep_a_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->seq_num)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod_atmo)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->tropo_quality_indicator)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_gridded_correction_header_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_gridded_correction_header_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->seq_num)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod_atmo)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->tropo_quality_indicator)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_grid_definition_header_dep_a_t(const sbp_grid_definition_header_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->region_size_inverse);
  packed_size += sbp_packed_size_u16(&msg->area_width);
  packed_size += sbp_packed_size_u16(&msg->lat_nw_corner_enc);
  packed_size += sbp_packed_size_u16(&msg->lon_nw_corner_enc);
  packed_size += sbp_packed_size_u8(&msg->num_msgs);
  packed_size += sbp_packed_size_u8(&msg->seq_num);
  return packed_size;
}

static inline bool sbp_pack_sbp_grid_definition_header_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_grid_definition_header_dep_a_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->region_size_inverse)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->area_width)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->lat_nw_corner_enc)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->lon_nw_corner_enc)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->seq_num)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_grid_definition_header_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_grid_definition_header_dep_a_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->region_size_inverse)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->area_width)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->lat_nw_corner_enc)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->lon_nw_corner_enc)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->seq_num)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_stec_header_dep_a_t(&msg->header);
  packed_size += (msg->n_stec_sat_list * sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_stec_correction_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_stec_correction_dep_a_t *msg)
{
  if (!sbp_pack_sbp_stec_header_dep_a_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++)
  {
    if (!sbp_pack_sbp_stec_sat_element_t(ctx, &msg->stec_sat_list[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_stec_correction_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_stec_correction_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_stec_header_dep_a_t(ctx, &msg->header)) { return false; }
    msg->n_stec_sat_list = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++) {
    if (!sbp_unpack_sbp_stec_sat_element_t(ctx, &msg->stec_sat_list[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gridded_correction_header_dep_a_t(&msg->header);
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(&msg->tropo_delay_correction);
  packed_size += (msg->n_stec_residuals * sbp_packed_size_sbp_stec_residual_no_std_t(&msg->stec_residuals[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg)
{
  if (!sbp_pack_sbp_gridded_correction_header_dep_a_t(ctx, &msg->header)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_pack_sbp_tropospheric_delay_correction_no_std_t(ctx, &msg->tropo_delay_correction)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++)
  {
    if (!sbp_pack_sbp_stec_residual_no_std_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_gridded_correction_header_dep_a_t(ctx, &msg->header)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_sbp_tropospheric_delay_correction_no_std_t(ctx, &msg->tropo_delay_correction)) { return false; }
    msg->n_stec_residuals = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_residual_no_std_t(&msg->stec_residuals[0]));
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!sbp_unpack_sbp_stec_residual_no_std_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gridded_correction_header_dep_a_t(&msg->header);
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_packed_size_sbp_tropospheric_delay_correction_t(&msg->tropo_delay_correction);
  packed_size += (msg->n_stec_residuals * sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_dep_a_t *msg)
{
  if (!sbp_pack_sbp_gridded_correction_header_dep_a_t(ctx, &msg->header)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_pack_sbp_tropospheric_delay_correction_t(ctx, &msg->tropo_delay_correction)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++)
  {
    if (!sbp_pack_sbp_stec_residual_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_gridded_correction_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_gridded_correction_header_dep_a_t(ctx, &msg->header)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_sbp_tropospheric_delay_correction_t(ctx, &msg->tropo_delay_correction)) { return false; }
    msg->n_stec_residuals = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!sbp_unpack_sbp_stec_residual_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_grid_definition_header_dep_a_t(&msg->header);
  packed_size += (msg->n_rle_list * sbp_packed_size_u8(&msg->rle_list[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ssr_grid_definition_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_grid_definition_dep_a_t *msg)
{
  if (!sbp_pack_sbp_grid_definition_header_dep_a_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_rle_list; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->rle_list[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_grid_definition_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_grid_definition_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_grid_definition_header_dep_a_t(ctx, &msg->header)) { return false; }
    msg->n_rle_list = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->rle_list[0]));
  for (uint8_t i = 0; i < msg->n_rle_list; i++) {
    if (!sbp_unpack_u8(ctx, &msg->rle_list[i])) { return false; }
  }
  return true;
}

#endif
