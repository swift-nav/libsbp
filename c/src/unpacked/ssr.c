#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/ssr.h>
#include <libsbp/internal/unpacked/ssr.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
                                                                                                              
size_t sbp_packed_size_sbp_code_biases_content_t(const sbp_code_biases_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->code);
  packed_size += sbp_packed_size_s16(&msg->value);
  return packed_size;
}

bool pack_sbp_code_biases_content_t(sbp_pack_ctx_t *ctx, const sbp_code_biases_content_t *msg)
{
  if (!pack_u8(ctx, &msg->code)) { return false; }
  if (!pack_s16(ctx, &msg->value)) { return false; }
  return true;
}

s8 sbp_pack_sbp_code_biases_content_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_code_biases_content_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_code_biases_content_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_code_biases_content_t(sbp_unpack_ctx_t *ctx, sbp_code_biases_content_t *msg)
{
  if (!unpack_u8(ctx, &msg->code)) { return false; }
  if (!unpack_s16(ctx, &msg->value)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_code_biases_content_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_code_biases_content_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_code_biases_content_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_code_biases_content_t(const sbp_code_biases_content_t *a, const sbp_code_biases_content_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->code, &b->code);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->value, &b->value);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->code);
  packed_size += sbp_packed_size_u8(&msg->integer_indicator);
  packed_size += sbp_packed_size_u8(&msg->widelane_integer_indicator);
  packed_size += sbp_packed_size_u8(&msg->discontinuity_counter);
  packed_size += sbp_packed_size_s32(&msg->bias);
  return packed_size;
}

bool pack_sbp_phase_biases_content_t(sbp_pack_ctx_t *ctx, const sbp_phase_biases_content_t *msg)
{
  if (!pack_u8(ctx, &msg->code)) { return false; }
  if (!pack_u8(ctx, &msg->integer_indicator)) { return false; }
  if (!pack_u8(ctx, &msg->widelane_integer_indicator)) { return false; }
  if (!pack_u8(ctx, &msg->discontinuity_counter)) { return false; }
  if (!pack_s32(ctx, &msg->bias)) { return false; }
  return true;
}

s8 sbp_pack_sbp_phase_biases_content_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_phase_biases_content_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_phase_biases_content_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_phase_biases_content_t(sbp_unpack_ctx_t *ctx, sbp_phase_biases_content_t *msg)
{
  if (!unpack_u8(ctx, &msg->code)) { return false; }
  if (!unpack_u8(ctx, &msg->integer_indicator)) { return false; }
  if (!unpack_u8(ctx, &msg->widelane_integer_indicator)) { return false; }
  if (!unpack_u8(ctx, &msg->discontinuity_counter)) { return false; }
  if (!unpack_s32(ctx, &msg->bias)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_phase_biases_content_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_phase_biases_content_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_phase_biases_content_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *a, const sbp_phase_biases_content_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_stec_header_t(const sbp_stec_header_t *msg) {
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

bool pack_sbp_stec_header_t(sbp_pack_ctx_t *ctx, const sbp_stec_header_t *msg)
{
  if (!pack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!pack_u16(ctx, &msg->tile_id)) { return false; }
  if (!pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!pack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!pack_u8(ctx, &msg->seq_num)) { return false; }
  if (!pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!pack_u8(ctx, &msg->iod_atmo)) { return false; }
  return true;
}

s8 sbp_pack_sbp_stec_header_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_header_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_stec_header_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_stec_header_t(sbp_unpack_ctx_t *ctx, sbp_stec_header_t *msg)
{
  if (!unpack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!unpack_u16(ctx, &msg->tile_id)) { return false; }
  if (!unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!unpack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!unpack_u8(ctx, &msg->seq_num)) { return false; }
  if (!unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!unpack_u8(ctx, &msg->iod_atmo)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_stec_header_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_header_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_stec_header_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_stec_header_t(const sbp_stec_header_t *a, const sbp_stec_header_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_gridded_correction_header_t(const sbp_gridded_correction_header_t *msg) {
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

bool pack_sbp_gridded_correction_header_t(sbp_pack_ctx_t *ctx, const sbp_gridded_correction_header_t *msg)
{
  if (!pack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!pack_u16(ctx, &msg->tile_id)) { return false; }
  if (!pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!pack_u16(ctx, &msg->num_msgs)) { return false; }
  if (!pack_u16(ctx, &msg->seq_num)) { return false; }
  if (!pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!pack_u8(ctx, &msg->iod_atmo)) { return false; }
  if (!pack_u8(ctx, &msg->tropo_quality_indicator)) { return false; }
  return true;
}

s8 sbp_pack_sbp_gridded_correction_header_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gridded_correction_header_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_gridded_correction_header_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_gridded_correction_header_t(sbp_unpack_ctx_t *ctx, sbp_gridded_correction_header_t *msg)
{
  if (!unpack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!unpack_u16(ctx, &msg->tile_id)) { return false; }
  if (!unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!unpack_u16(ctx, &msg->num_msgs)) { return false; }
  if (!unpack_u16(ctx, &msg->seq_num)) { return false; }
  if (!unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!unpack_u8(ctx, &msg->iod_atmo)) { return false; }
  if (!unpack_u8(ctx, &msg->tropo_quality_indicator)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_gridded_correction_header_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gridded_correction_header_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_gridded_correction_header_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_gridded_correction_header_t(const sbp_gridded_correction_header_t *a, const sbp_gridded_correction_header_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sv_id_t(&msg->sv_id);
  packed_size += sbp_packed_size_u8(&msg->stec_quality_indicator);
  packed_size += ( 4 * sbp_packed_size_s16(&msg->stec_coeff[0]));
  return packed_size;
}

bool pack_sbp_stec_sat_element_t(sbp_pack_ctx_t *ctx, const sbp_stec_sat_element_t *msg)
{
  if (!pack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!pack_u8(ctx, &msg->stec_quality_indicator)) { return false; }
  for (uint8_t i = 0; i < 4; i++)
  {
    if (!pack_s16(ctx, &msg->stec_coeff[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_stec_sat_element_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_sat_element_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_stec_sat_element_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_stec_sat_element_t(sbp_unpack_ctx_t *ctx, sbp_stec_sat_element_t *msg)
{
  if (!unpack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!unpack_u8(ctx, &msg->stec_quality_indicator)) { return false; }
  for (uint8_t i = 0; i < 4; i++) {
    if (!unpack_s16(ctx, &msg->stec_coeff[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_stec_sat_element_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_sat_element_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_stec_sat_element_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *a, const sbp_stec_sat_element_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(const sbp_tropospheric_delay_correction_no_std_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->hydro);
  packed_size += sbp_packed_size_s8(&msg->wet);
  return packed_size;
}

bool pack_sbp_tropospheric_delay_correction_no_std_t(sbp_pack_ctx_t *ctx, const sbp_tropospheric_delay_correction_no_std_t *msg)
{
  if (!pack_s16(ctx, &msg->hydro)) { return false; }
  if (!pack_s8(ctx, &msg->wet)) { return false; }
  return true;
}

s8 sbp_pack_sbp_tropospheric_delay_correction_no_std_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_tropospheric_delay_correction_no_std_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_tropospheric_delay_correction_no_std_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_tropospheric_delay_correction_no_std_t(sbp_unpack_ctx_t *ctx, sbp_tropospheric_delay_correction_no_std_t *msg)
{
  if (!unpack_s16(ctx, &msg->hydro)) { return false; }
  if (!unpack_s8(ctx, &msg->wet)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_tropospheric_delay_correction_no_std_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_tropospheric_delay_correction_no_std_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_tropospheric_delay_correction_no_std_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_tropospheric_delay_correction_no_std_t(const sbp_tropospheric_delay_correction_no_std_t *a, const sbp_tropospheric_delay_correction_no_std_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->hydro, &b->hydro);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s8(&a->wet, &b->wet);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_tropospheric_delay_correction_t(const sbp_tropospheric_delay_correction_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->hydro);
  packed_size += sbp_packed_size_s8(&msg->wet);
  packed_size += sbp_packed_size_u8(&msg->stddev);
  return packed_size;
}

bool pack_sbp_tropospheric_delay_correction_t(sbp_pack_ctx_t *ctx, const sbp_tropospheric_delay_correction_t *msg)
{
  if (!pack_s16(ctx, &msg->hydro)) { return false; }
  if (!pack_s8(ctx, &msg->wet)) { return false; }
  if (!pack_u8(ctx, &msg->stddev)) { return false; }
  return true;
}

s8 sbp_pack_sbp_tropospheric_delay_correction_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_tropospheric_delay_correction_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_tropospheric_delay_correction_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_tropospheric_delay_correction_t(sbp_unpack_ctx_t *ctx, sbp_tropospheric_delay_correction_t *msg)
{
  if (!unpack_s16(ctx, &msg->hydro)) { return false; }
  if (!unpack_s8(ctx, &msg->wet)) { return false; }
  if (!unpack_u8(ctx, &msg->stddev)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_tropospheric_delay_correction_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_tropospheric_delay_correction_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_tropospheric_delay_correction_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_tropospheric_delay_correction_t(const sbp_tropospheric_delay_correction_t *a, const sbp_tropospheric_delay_correction_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->hydro, &b->hydro);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s8(&a->wet, &b->wet);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->stddev, &b->stddev);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sv_id_t(&msg->sv_id);
  packed_size += sbp_packed_size_s16(&msg->residual);
  return packed_size;
}

bool pack_sbp_stec_residual_no_std_t(sbp_pack_ctx_t *ctx, const sbp_stec_residual_no_std_t *msg)
{
  if (!pack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!pack_s16(ctx, &msg->residual)) { return false; }
  return true;
}

s8 sbp_pack_sbp_stec_residual_no_std_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_residual_no_std_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_stec_residual_no_std_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_stec_residual_no_std_t(sbp_unpack_ctx_t *ctx, sbp_stec_residual_no_std_t *msg)
{
  if (!unpack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!unpack_s16(ctx, &msg->residual)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_stec_residual_no_std_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_residual_no_std_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_stec_residual_no_std_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *a, const sbp_stec_residual_no_std_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sv_id_t(&a->sv_id, &b->sv_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->residual, &b->residual);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_stec_residual_t(const sbp_stec_residual_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sv_id_t(&msg->sv_id);
  packed_size += sbp_packed_size_s16(&msg->residual);
  packed_size += sbp_packed_size_u8(&msg->stddev);
  return packed_size;
}

bool pack_sbp_stec_residual_t(sbp_pack_ctx_t *ctx, const sbp_stec_residual_t *msg)
{
  if (!pack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!pack_s16(ctx, &msg->residual)) { return false; }
  if (!pack_u8(ctx, &msg->stddev)) { return false; }
  return true;
}

s8 sbp_pack_sbp_stec_residual_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_residual_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_stec_residual_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_stec_residual_t(sbp_unpack_ctx_t *ctx, sbp_stec_residual_t *msg)
{
  if (!unpack_sbp_sv_id_t(ctx, &msg->sv_id)) { return false; }
  if (!unpack_s16(ctx, &msg->residual)) { return false; }
  if (!unpack_u8(ctx, &msg->stddev)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_stec_residual_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_residual_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_stec_residual_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_stec_residual_t(const sbp_stec_residual_t *a, const sbp_stec_residual_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sv_id_t(&a->sv_id, &b->sv_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->residual, &b->residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->stddev, &b->stddev);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *msg) {
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

bool pack_sbp_msg_ssr_orbit_clock_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_t *msg)
{
  if (!pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!pack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!pack_u32(ctx, &msg->iod)) { return false; }
  if (!pack_s32(ctx, &msg->radial)) { return false; }
  if (!pack_s32(ctx, &msg->along)) { return false; }
  if (!pack_s32(ctx, &msg->cross)) { return false; }
  if (!pack_s32(ctx, &msg->dot_radial)) { return false; }
  if (!pack_s32(ctx, &msg->dot_along)) { return false; }
  if (!pack_s32(ctx, &msg->dot_cross)) { return false; }
  if (!pack_s32(ctx, &msg->c0)) { return false; }
  if (!pack_s32(ctx, &msg->c1)) { return false; }
  if (!pack_s32(ctx, &msg->c2)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_orbit_clock_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_orbit_clock_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_orbit_clock_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_orbit_clock_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_orbit_clock_t *msg)
{
  if (!unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!unpack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!unpack_u32(ctx, &msg->iod)) { return false; }
  if (!unpack_s32(ctx, &msg->radial)) { return false; }
  if (!unpack_s32(ctx, &msg->along)) { return false; }
  if (!unpack_s32(ctx, &msg->cross)) { return false; }
  if (!unpack_s32(ctx, &msg->dot_radial)) { return false; }
  if (!unpack_s32(ctx, &msg->dot_along)) { return false; }
  if (!unpack_s32(ctx, &msg->dot_cross)) { return false; }
  if (!unpack_s32(ctx, &msg->c0)) { return false; }
  if (!unpack_s32(ctx, &msg->c1)) { return false; }
  if (!unpack_s32(ctx, &msg->c2)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_orbit_clock_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_orbit_clock_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_orbit_clock_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *a, const sbp_msg_ssr_orbit_clock_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_ssr);
  packed_size += (msg->n_biases * sbp_packed_size_sbp_code_biases_content_t(&msg->biases[0]));
  return packed_size;
}

bool pack_sbp_msg_ssr_code_biases_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_code_biases_t *msg)
{
  if (!pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!pack_u8(ctx, &msg->iod_ssr)) { return false; }
  for (uint8_t i = 0; i < msg->n_biases; i++)
  {
    if (!pack_sbp_code_biases_content_t(ctx, &msg->biases[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_code_biases_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_code_biases_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_code_biases_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_code_biases_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_code_biases_t *msg)
{
  if (!unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!unpack_u8(ctx, &msg->iod_ssr)) { return false; }
    msg->n_biases = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_code_biases_content_t(&msg->biases[0]));
  for (uint8_t i = 0; i < msg->n_biases; i++) {
    if (!unpack_sbp_code_biases_content_t(ctx, &msg->biases[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_code_biases_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_code_biases_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_code_biases_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *a, const sbp_msg_ssr_code_biases_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *msg) {
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

bool pack_sbp_msg_ssr_phase_biases_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_phase_biases_t *msg)
{
  if (!pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!pack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!pack_u8(ctx, &msg->dispersive_bias)) { return false; }
  if (!pack_u8(ctx, &msg->mw_consistency)) { return false; }
  if (!pack_u16(ctx, &msg->yaw)) { return false; }
  if (!pack_s8(ctx, &msg->yaw_rate)) { return false; }
  for (uint8_t i = 0; i < msg->n_biases; i++)
  {
    if (!pack_sbp_phase_biases_content_t(ctx, &msg->biases[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_phase_biases_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_phase_biases_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_phase_biases_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_phase_biases_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_phase_biases_t *msg)
{
  if (!unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!unpack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!unpack_u8(ctx, &msg->dispersive_bias)) { return false; }
  if (!unpack_u8(ctx, &msg->mw_consistency)) { return false; }
  if (!unpack_u16(ctx, &msg->yaw)) { return false; }
  if (!unpack_s8(ctx, &msg->yaw_rate)) { return false; }
    msg->n_biases = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_phase_biases_content_t(&msg->biases[0]));
  for (uint8_t i = 0; i < msg->n_biases; i++) {
    if (!unpack_sbp_phase_biases_content_t(ctx, &msg->biases[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_phase_biases_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_phase_biases_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_phase_biases_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *a, const sbp_msg_ssr_phase_biases_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_stec_correction_t(const sbp_msg_ssr_stec_correction_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_stec_header_t(&msg->header);
  packed_size += (msg->n_stec_sat_list * sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  return packed_size;
}

bool pack_sbp_msg_ssr_stec_correction_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_stec_correction_t *msg)
{
  if (!pack_sbp_stec_header_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++)
  {
    if (!pack_sbp_stec_sat_element_t(ctx, &msg->stec_sat_list[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_stec_correction_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_stec_correction_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_stec_correction_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_stec_correction_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_stec_correction_t *msg)
{
  if (!unpack_sbp_stec_header_t(ctx, &msg->header)) { return false; }
    msg->n_stec_sat_list = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++) {
    if (!unpack_sbp_stec_sat_element_t(ctx, &msg->stec_sat_list[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_stec_correction_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_stec_correction_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_stec_correction_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_stec_correction_t(const sbp_msg_ssr_stec_correction_t *a, const sbp_msg_ssr_stec_correction_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_t(const sbp_msg_ssr_gridded_correction_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gridded_correction_header_t(&msg->header);
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_packed_size_sbp_tropospheric_delay_correction_t(&msg->tropo_delay_correction);
  packed_size += (msg->n_stec_residuals * sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  return packed_size;
}

bool pack_sbp_msg_ssr_gridded_correction_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_t *msg)
{
  if (!pack_sbp_gridded_correction_header_t(ctx, &msg->header)) { return false; }
  if (!pack_u16(ctx, &msg->index)) { return false; }
  if (!pack_sbp_tropospheric_delay_correction_t(ctx, &msg->tropo_delay_correction)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++)
  {
    if (!pack_sbp_stec_residual_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_gridded_correction_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_gridded_correction_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_gridded_correction_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_gridded_correction_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_gridded_correction_t *msg)
{
  if (!unpack_sbp_gridded_correction_header_t(ctx, &msg->header)) { return false; }
  if (!unpack_u16(ctx, &msg->index)) { return false; }
  if (!unpack_sbp_tropospheric_delay_correction_t(ctx, &msg->tropo_delay_correction)) { return false; }
    msg->n_stec_residuals = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!unpack_sbp_stec_residual_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_gridded_correction_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_gridded_correction_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_gridded_correction_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_gridded_correction_t(const sbp_msg_ssr_gridded_correction_t *a, const sbp_msg_ssr_gridded_correction_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_tile_definition_t(const sbp_msg_ssr_tile_definition_t *msg) {
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

bool pack_sbp_msg_ssr_tile_definition_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_tile_definition_t *msg)
{
  if (!pack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!pack_u16(ctx, &msg->tile_id)) { return false; }
  if (!pack_s16(ctx, &msg->corner_nw_lat)) { return false; }
  if (!pack_s16(ctx, &msg->corner_nw_lon)) { return false; }
  if (!pack_u16(ctx, &msg->spacing_lat)) { return false; }
  if (!pack_u16(ctx, &msg->spacing_lon)) { return false; }
  if (!pack_u16(ctx, &msg->rows)) { return false; }
  if (!pack_u16(ctx, &msg->cols)) { return false; }
  if (!pack_u64(ctx, &msg->bitmask)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_tile_definition_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_tile_definition_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_tile_definition_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_tile_definition_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_tile_definition_t *msg)
{
  if (!unpack_u16(ctx, &msg->tile_set_id)) { return false; }
  if (!unpack_u16(ctx, &msg->tile_id)) { return false; }
  if (!unpack_s16(ctx, &msg->corner_nw_lat)) { return false; }
  if (!unpack_s16(ctx, &msg->corner_nw_lon)) { return false; }
  if (!unpack_u16(ctx, &msg->spacing_lat)) { return false; }
  if (!unpack_u16(ctx, &msg->spacing_lon)) { return false; }
  if (!unpack_u16(ctx, &msg->rows)) { return false; }
  if (!unpack_u16(ctx, &msg->cols)) { return false; }
  if (!unpack_u64(ctx, &msg->bitmask)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_tile_definition_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_tile_definition_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_tile_definition_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_tile_definition_t(const sbp_msg_ssr_tile_definition_t *a, const sbp_msg_ssr_tile_definition_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_satellite_apc_t(const sbp_satellite_apc_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->sat_info);
  packed_size += sbp_packed_size_u16(&msg->svn);
  packed_size += ( 3 * sbp_packed_size_s16(&msg->pco[0]));
  packed_size += ( 21 * sbp_packed_size_s8(&msg->pcv[0]));
  return packed_size;
}

bool pack_sbp_satellite_apc_t(sbp_pack_ctx_t *ctx, const sbp_satellite_apc_t *msg)
{
  if (!pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!pack_u8(ctx, &msg->sat_info)) { return false; }
  if (!pack_u16(ctx, &msg->svn)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!pack_s16(ctx, &msg->pco[i])) { return false; }
  }
  for (uint8_t i = 0; i < 21; i++)
  {
    if (!pack_s8(ctx, &msg->pcv[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_satellite_apc_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_satellite_apc_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_satellite_apc_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_satellite_apc_t(sbp_unpack_ctx_t *ctx, sbp_satellite_apc_t *msg)
{
  if (!unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!unpack_u8(ctx, &msg->sat_info)) { return false; }
  if (!unpack_u16(ctx, &msg->svn)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!unpack_s16(ctx, &msg->pco[i])) { return false; }
  }
  for (uint8_t i = 0; i < 21; i++) {
    if (!unpack_s8(ctx, &msg->pcv[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_satellite_apc_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_satellite_apc_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_satellite_apc_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_satellite_apc_t(const sbp_satellite_apc_t *a, const sbp_satellite_apc_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_apc * sbp_packed_size_sbp_satellite_apc_t(&msg->apc[0]));
  return packed_size;
}

bool pack_sbp_msg_ssr_satellite_apc_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_satellite_apc_t *msg)
{
  for (uint8_t i = 0; i < msg->n_apc; i++)
  {
    if (!pack_sbp_satellite_apc_t(ctx, &msg->apc[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_satellite_apc_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_satellite_apc_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_satellite_apc_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_satellite_apc_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_satellite_apc_t *msg)
{
    msg->n_apc = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_satellite_apc_t(&msg->apc[0]));
  for (uint8_t i = 0; i < msg->n_apc; i++) {
    if (!unpack_sbp_satellite_apc_t(ctx, &msg->apc[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_satellite_apc_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_satellite_apc_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_satellite_apc_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *a, const sbp_msg_ssr_satellite_apc_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_apc, &b->n_apc);
  for (uint8_t i = 0; i < a->n_apc && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_satellite_apc_t(&a->apc[i], &b->apc[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
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

bool pack_sbp_msg_ssr_orbit_clock_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_dep_a_t *msg)
{
  if (!pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!pack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!pack_u8(ctx, &msg->iod)) { return false; }
  if (!pack_s32(ctx, &msg->radial)) { return false; }
  if (!pack_s32(ctx, &msg->along)) { return false; }
  if (!pack_s32(ctx, &msg->cross)) { return false; }
  if (!pack_s32(ctx, &msg->dot_radial)) { return false; }
  if (!pack_s32(ctx, &msg->dot_along)) { return false; }
  if (!pack_s32(ctx, &msg->dot_cross)) { return false; }
  if (!pack_s32(ctx, &msg->c0)) { return false; }
  if (!pack_s32(ctx, &msg->c1)) { return false; }
  if (!pack_s32(ctx, &msg->c2)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_orbit_clock_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_orbit_clock_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_orbit_clock_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_orbit_clock_dep_a_t *msg)
{
  if (!unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!unpack_u8(ctx, &msg->iod_ssr)) { return false; }
  if (!unpack_u8(ctx, &msg->iod)) { return false; }
  if (!unpack_s32(ctx, &msg->radial)) { return false; }
  if (!unpack_s32(ctx, &msg->along)) { return false; }
  if (!unpack_s32(ctx, &msg->cross)) { return false; }
  if (!unpack_s32(ctx, &msg->dot_radial)) { return false; }
  if (!unpack_s32(ctx, &msg->dot_along)) { return false; }
  if (!unpack_s32(ctx, &msg->dot_cross)) { return false; }
  if (!unpack_s32(ctx, &msg->c0)) { return false; }
  if (!unpack_s32(ctx, &msg->c1)) { return false; }
  if (!unpack_s32(ctx, &msg->c2)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_orbit_clock_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_orbit_clock_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_orbit_clock_dep_a_t(const sbp_msg_ssr_orbit_clock_dep_a_t *a, const sbp_msg_ssr_orbit_clock_dep_a_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->num_msgs);
  packed_size += sbp_packed_size_u8(&msg->seq_num);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_atmo);
  return packed_size;
}

bool pack_sbp_stec_header_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_stec_header_dep_a_t *msg)
{
  if (!pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!pack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!pack_u8(ctx, &msg->seq_num)) { return false; }
  if (!pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!pack_u8(ctx, &msg->iod_atmo)) { return false; }
  return true;
}

s8 sbp_pack_sbp_stec_header_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_stec_header_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_stec_header_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_stec_header_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_stec_header_dep_a_t *msg)
{
  if (!unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!unpack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!unpack_u8(ctx, &msg->seq_num)) { return false; }
  if (!unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!unpack_u8(ctx, &msg->iod_atmo)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_stec_header_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_stec_header_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_stec_header_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *a, const sbp_stec_header_dep_a_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_gridded_correction_header_dep_a_t(const sbp_gridded_correction_header_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->time);
  packed_size += sbp_packed_size_u16(&msg->num_msgs);
  packed_size += sbp_packed_size_u16(&msg->seq_num);
  packed_size += sbp_packed_size_u8(&msg->update_interval);
  packed_size += sbp_packed_size_u8(&msg->iod_atmo);
  packed_size += sbp_packed_size_u8(&msg->tropo_quality_indicator);
  return packed_size;
}

bool pack_sbp_gridded_correction_header_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_gridded_correction_header_dep_a_t *msg)
{
  if (!pack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!pack_u16(ctx, &msg->num_msgs)) { return false; }
  if (!pack_u16(ctx, &msg->seq_num)) { return false; }
  if (!pack_u8(ctx, &msg->update_interval)) { return false; }
  if (!pack_u8(ctx, &msg->iod_atmo)) { return false; }
  if (!pack_u8(ctx, &msg->tropo_quality_indicator)) { return false; }
  return true;
}

s8 sbp_pack_sbp_gridded_correction_header_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gridded_correction_header_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_gridded_correction_header_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_gridded_correction_header_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_gridded_correction_header_dep_a_t *msg)
{
  if (!unpack_sbp_gps_time_sec_t(ctx, &msg->time)) { return false; }
  if (!unpack_u16(ctx, &msg->num_msgs)) { return false; }
  if (!unpack_u16(ctx, &msg->seq_num)) { return false; }
  if (!unpack_u8(ctx, &msg->update_interval)) { return false; }
  if (!unpack_u8(ctx, &msg->iod_atmo)) { return false; }
  if (!unpack_u8(ctx, &msg->tropo_quality_indicator)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_gridded_correction_header_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gridded_correction_header_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_gridded_correction_header_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_gridded_correction_header_dep_a_t(const sbp_gridded_correction_header_dep_a_t *a, const sbp_gridded_correction_header_dep_a_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_grid_definition_header_dep_a_t(const sbp_grid_definition_header_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->region_size_inverse);
  packed_size += sbp_packed_size_u16(&msg->area_width);
  packed_size += sbp_packed_size_u16(&msg->lat_nw_corner_enc);
  packed_size += sbp_packed_size_u16(&msg->lon_nw_corner_enc);
  packed_size += sbp_packed_size_u8(&msg->num_msgs);
  packed_size += sbp_packed_size_u8(&msg->seq_num);
  return packed_size;
}

bool pack_sbp_grid_definition_header_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_grid_definition_header_dep_a_t *msg)
{
  if (!pack_u8(ctx, &msg->region_size_inverse)) { return false; }
  if (!pack_u16(ctx, &msg->area_width)) { return false; }
  if (!pack_u16(ctx, &msg->lat_nw_corner_enc)) { return false; }
  if (!pack_u16(ctx, &msg->lon_nw_corner_enc)) { return false; }
  if (!pack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!pack_u8(ctx, &msg->seq_num)) { return false; }
  return true;
}

s8 sbp_pack_sbp_grid_definition_header_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_grid_definition_header_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_grid_definition_header_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_grid_definition_header_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_grid_definition_header_dep_a_t *msg)
{
  if (!unpack_u8(ctx, &msg->region_size_inverse)) { return false; }
  if (!unpack_u16(ctx, &msg->area_width)) { return false; }
  if (!unpack_u16(ctx, &msg->lat_nw_corner_enc)) { return false; }
  if (!unpack_u16(ctx, &msg->lon_nw_corner_enc)) { return false; }
  if (!unpack_u8(ctx, &msg->num_msgs)) { return false; }
  if (!unpack_u8(ctx, &msg->seq_num)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_grid_definition_header_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_grid_definition_header_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_grid_definition_header_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_grid_definition_header_dep_a_t(const sbp_grid_definition_header_dep_a_t *a, const sbp_grid_definition_header_dep_a_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_stec_header_dep_a_t(&msg->header);
  packed_size += (msg->n_stec_sat_list * sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  return packed_size;
}

bool pack_sbp_msg_ssr_stec_correction_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_stec_correction_dep_a_t *msg)
{
  if (!pack_sbp_stec_header_dep_a_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++)
  {
    if (!pack_sbp_stec_sat_element_t(ctx, &msg->stec_sat_list[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_stec_correction_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_stec_correction_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_stec_correction_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_stec_correction_dep_a_t *msg)
{
  if (!unpack_sbp_stec_header_dep_a_t(ctx, &msg->header)) { return false; }
    msg->n_stec_sat_list = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_sat_element_t(&msg->stec_sat_list[0]));
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++) {
    if (!unpack_sbp_stec_sat_element_t(ctx, &msg->stec_sat_list[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_stec_correction_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_stec_correction_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_stec_correction_dep_a_t(const sbp_msg_ssr_stec_correction_dep_a_t *a, const sbp_msg_ssr_stec_correction_dep_a_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gridded_correction_header_dep_a_t(&msg->header);
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(&msg->tropo_delay_correction);
  packed_size += (msg->n_stec_residuals * sbp_packed_size_sbp_stec_residual_no_std_t(&msg->stec_residuals[0]));
  return packed_size;
}

bool pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg)
{
  if (!pack_sbp_gridded_correction_header_dep_a_t(ctx, &msg->header)) { return false; }
  if (!pack_u16(ctx, &msg->index)) { return false; }
  if (!pack_sbp_tropospheric_delay_correction_no_std_t(ctx, &msg->tropo_delay_correction)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++)
  {
    if (!pack_sbp_stec_residual_no_std_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg)
{
  if (!unpack_sbp_gridded_correction_header_dep_a_t(ctx, &msg->header)) { return false; }
  if (!unpack_u16(ctx, &msg->index)) { return false; }
  if (!unpack_sbp_tropospheric_delay_correction_no_std_t(ctx, &msg->tropo_delay_correction)) { return false; }
    msg->n_stec_residuals = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_residual_no_std_t(&msg->stec_residuals[0]));
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!unpack_sbp_stec_residual_no_std_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gridded_correction_header_dep_a_t(&msg->header);
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_packed_size_sbp_tropospheric_delay_correction_t(&msg->tropo_delay_correction);
  packed_size += (msg->n_stec_residuals * sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  return packed_size;
}

bool pack_sbp_msg_ssr_gridded_correction_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_dep_a_t *msg)
{
  if (!pack_sbp_gridded_correction_header_dep_a_t(ctx, &msg->header)) { return false; }
  if (!pack_u16(ctx, &msg->index)) { return false; }
  if (!pack_sbp_tropospheric_delay_correction_t(ctx, &msg->tropo_delay_correction)) { return false; }
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++)
  {
    if (!pack_sbp_stec_residual_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_gridded_correction_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_gridded_correction_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_gridded_correction_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_gridded_correction_dep_a_t *msg)
{
  if (!unpack_sbp_gridded_correction_header_dep_a_t(ctx, &msg->header)) { return false; }
  if (!unpack_u16(ctx, &msg->index)) { return false; }
  if (!unpack_sbp_tropospheric_delay_correction_t(ctx, &msg->tropo_delay_correction)) { return false; }
    msg->n_stec_residuals = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_stec_residual_t(&msg->stec_residuals[0]));
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!unpack_sbp_stec_residual_t(ctx, &msg->stec_residuals[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_gridded_correction_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_gridded_correction_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_gridded_correction_dep_a_t(const sbp_msg_ssr_gridded_correction_dep_a_t *a, const sbp_msg_ssr_gridded_correction_dep_a_t *b) {
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_grid_definition_header_dep_a_t(&msg->header);
  packed_size += (msg->n_rle_list * sbp_packed_size_u8(&msg->rle_list[0]));
  return packed_size;
}

bool pack_sbp_msg_ssr_grid_definition_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_grid_definition_dep_a_t *msg)
{
  if (!pack_sbp_grid_definition_header_dep_a_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_rle_list; i++)
  {
    if (!pack_u8(ctx, &msg->rle_list[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_ssr_grid_definition_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ssr_grid_definition_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ssr_grid_definition_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_grid_definition_dep_a_t *msg)
{
  if (!unpack_sbp_grid_definition_header_dep_a_t(ctx, &msg->header)) { return false; }
    msg->n_rle_list = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->rle_list[0]));
  for (uint8_t i = 0; i < msg->n_rle_list; i++) {
    if (!unpack_u8(ctx, &msg->rle_list[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_ssr_grid_definition_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ssr_grid_definition_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ssr_grid_definition_dep_a_t(const sbp_msg_ssr_grid_definition_dep_a_t *a, const sbp_msg_ssr_grid_definition_dep_a_t *b) {
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
