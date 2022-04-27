/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/ssr.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/ssr.h>

bool sbp_code_biases_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_code_biases_content_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->code)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->value)) {
    return false;
  }
  return true;
}

s8 sbp_code_biases_content_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_code_biases_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_code_biases_content_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_code_biases_content_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_code_biases_content_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->code)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->value)) {
    return false;
  }
  return true;
}

s8 sbp_code_biases_content_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_code_biases_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_code_biases_content_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_code_biases_content_cmp(const sbp_code_biases_content_t *a,
                                const sbp_code_biases_content_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->code, &b->code);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->value, &b->value);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_phase_biases_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_phase_biases_content_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->code)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->integer_indicator)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->widelane_integer_indicator)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->discontinuity_counter)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->bias)) {
    return false;
  }
  return true;
}

s8 sbp_phase_biases_content_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_phase_biases_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_phase_biases_content_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_phase_biases_content_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_phase_biases_content_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->code)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->integer_indicator)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->widelane_integer_indicator)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->discontinuity_counter)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->bias)) {
    return false;
  }
  return true;
}

s8 sbp_phase_biases_content_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_phase_biases_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_phase_biases_content_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_phase_biases_content_cmp(const sbp_phase_biases_content_t *a,
                                 const sbp_phase_biases_content_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->code, &b->code);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->integer_indicator, &b->integer_indicator);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->widelane_integer_indicator,
                   &b->widelane_integer_indicator);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->discontinuity_counter, &b->discontinuity_counter);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->bias, &b->bias);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_stec_header_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_stec_header_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod_atmo)) {
    return false;
  }
  return true;
}

s8 sbp_stec_header_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_stec_header_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_header_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_stec_header_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_stec_header_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod_atmo)) {
    return false;
  }
  return true;
}

s8 sbp_stec_header_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_stec_header_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_header_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_stec_header_cmp(const sbp_stec_header_t *a,
                        const sbp_stec_header_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->tile_set_id, &b->tile_set_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tile_id, &b->tile_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->num_msgs, &b->num_msgs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->seq_num, &b->seq_num);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->update_interval, &b->update_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod_atmo, &b->iod_atmo);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_gridded_correction_header_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_gridded_correction_header_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod_atmo)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->tropo_quality_indicator)) {
    return false;
  }
  return true;
}

s8 sbp_gridded_correction_header_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_gridded_correction_header_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gridded_correction_header_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_gridded_correction_header_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_gridded_correction_header_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod_atmo)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->tropo_quality_indicator)) {
    return false;
  }
  return true;
}

s8 sbp_gridded_correction_header_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_gridded_correction_header_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gridded_correction_header_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_gridded_correction_header_cmp(
    const sbp_gridded_correction_header_t *a,
    const sbp_gridded_correction_header_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->tile_set_id, &b->tile_set_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tile_id, &b->tile_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->num_msgs, &b->num_msgs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->seq_num, &b->seq_num);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->update_interval, &b->update_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod_atmo, &b->iod_atmo);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->tropo_quality_indicator, &b->tropo_quality_indicator);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_stec_sat_element_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_stec_sat_element_t *msg) {
  if (!sbp_sv_id_encode_internal(ctx, &msg->sv_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->stec_quality_indicator)) {
    return false;
  }
  for (size_t i = 0; i < SBP_STEC_SAT_ELEMENT_STEC_COEFF_MAX; i++) {
    if (!sbp_s16_encode(ctx, &msg->stec_coeff[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_stec_sat_element_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_stec_sat_element_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_sat_element_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_stec_sat_element_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_stec_sat_element_t *msg) {
  if (!sbp_sv_id_decode_internal(ctx, &msg->sv_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->stec_quality_indicator)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_STEC_SAT_ELEMENT_STEC_COEFF_MAX; i++) {
    if (!sbp_s16_decode(ctx, &msg->stec_coeff[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_stec_sat_element_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_stec_sat_element_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_sat_element_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_stec_sat_element_cmp(const sbp_stec_sat_element_t *a,
                             const sbp_stec_sat_element_t *b) {
  int ret = 0;

  ret = sbp_sv_id_cmp(&a->sv_id, &b->sv_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->stec_quality_indicator, &b->stec_quality_indicator);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_STEC_SAT_ELEMENT_STEC_COEFF_MAX;
       i++) {
    ret = sbp_s16_cmp(&a->stec_coeff[i], &b->stec_coeff[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_tropospheric_delay_correction_no_std_encode_internal(
    sbp_encode_ctx_t *ctx,
    const sbp_tropospheric_delay_correction_no_std_t *msg) {
  if (!sbp_s16_encode(ctx, &msg->hydro)) {
    return false;
  }
  if (!sbp_s8_encode(ctx, &msg->wet)) {
    return false;
  }
  return true;
}

s8 sbp_tropospheric_delay_correction_no_std_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tropospheric_delay_correction_no_std_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tropospheric_delay_correction_no_std_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_tropospheric_delay_correction_no_std_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_tropospheric_delay_correction_no_std_t *msg) {
  if (!sbp_s16_decode(ctx, &msg->hydro)) {
    return false;
  }
  if (!sbp_s8_decode(ctx, &msg->wet)) {
    return false;
  }
  return true;
}

s8 sbp_tropospheric_delay_correction_no_std_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tropospheric_delay_correction_no_std_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tropospheric_delay_correction_no_std_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_tropospheric_delay_correction_no_std_cmp(
    const sbp_tropospheric_delay_correction_no_std_t *a,
    const sbp_tropospheric_delay_correction_no_std_t *b) {
  int ret = 0;

  ret = sbp_s16_cmp(&a->hydro, &b->hydro);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s8_cmp(&a->wet, &b->wet);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_tropospheric_delay_correction_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_tropospheric_delay_correction_t *msg) {
  if (!sbp_s16_encode(ctx, &msg->hydro)) {
    return false;
  }
  if (!sbp_s8_encode(ctx, &msg->wet)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->stddev)) {
    return false;
  }
  return true;
}

s8 sbp_tropospheric_delay_correction_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tropospheric_delay_correction_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tropospheric_delay_correction_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_tropospheric_delay_correction_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_tropospheric_delay_correction_t *msg) {
  if (!sbp_s16_decode(ctx, &msg->hydro)) {
    return false;
  }
  if (!sbp_s8_decode(ctx, &msg->wet)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->stddev)) {
    return false;
  }
  return true;
}

s8 sbp_tropospheric_delay_correction_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tropospheric_delay_correction_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tropospheric_delay_correction_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_tropospheric_delay_correction_cmp(
    const sbp_tropospheric_delay_correction_t *a,
    const sbp_tropospheric_delay_correction_t *b) {
  int ret = 0;

  ret = sbp_s16_cmp(&a->hydro, &b->hydro);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s8_cmp(&a->wet, &b->wet);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->stddev, &b->stddev);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_stec_residual_no_std_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_stec_residual_no_std_t *msg) {
  if (!sbp_sv_id_encode_internal(ctx, &msg->sv_id)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->residual)) {
    return false;
  }
  return true;
}

s8 sbp_stec_residual_no_std_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_stec_residual_no_std_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_residual_no_std_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_stec_residual_no_std_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_stec_residual_no_std_t *msg) {
  if (!sbp_sv_id_decode_internal(ctx, &msg->sv_id)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->residual)) {
    return false;
  }
  return true;
}

s8 sbp_stec_residual_no_std_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_stec_residual_no_std_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_residual_no_std_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_stec_residual_no_std_cmp(const sbp_stec_residual_no_std_t *a,
                                 const sbp_stec_residual_no_std_t *b) {
  int ret = 0;

  ret = sbp_sv_id_cmp(&a->sv_id, &b->sv_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->residual, &b->residual);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_stec_residual_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_stec_residual_t *msg) {
  if (!sbp_sv_id_encode_internal(ctx, &msg->sv_id)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->residual)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->stddev)) {
    return false;
  }
  return true;
}

s8 sbp_stec_residual_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_stec_residual_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_residual_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_stec_residual_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_stec_residual_t *msg) {
  if (!sbp_sv_id_decode_internal(ctx, &msg->sv_id)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->residual)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->stddev)) {
    return false;
  }
  return true;
}

s8 sbp_stec_residual_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_stec_residual_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_residual_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_stec_residual_cmp(const sbp_stec_residual_t *a,
                          const sbp_stec_residual_t *b) {
  int ret = 0;

  ret = sbp_sv_id_cmp(&a->sv_id, &b->sv_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->residual, &b->residual);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->stddev, &b->stddev);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_orbit_clock_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod_ssr)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->iod)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->radial)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->along)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->cross)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->dot_radial)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->dot_along)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->dot_cross)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->c0)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->c1)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->c2)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ssr_orbit_clock_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ssr_orbit_clock_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_orbit_clock_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_orbit_clock_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ssr_orbit_clock_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod_ssr)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->iod)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->radial)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->along)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->cross)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->dot_radial)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->dot_along)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->dot_cross)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->c0)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->c1)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->c2)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ssr_orbit_clock_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_ssr_orbit_clock_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_orbit_clock_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_orbit_clock_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_ssr_orbit_clock_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_orbit_clock_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_ORBIT_CLOCK, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ssr_orbit_clock_cmp(const sbp_msg_ssr_orbit_clock_t *a,
                                const sbp_msg_ssr_orbit_clock_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->update_interval, &b->update_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod_ssr, &b->iod_ssr);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->iod, &b->iod);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->radial, &b->radial);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->along, &b->along);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->cross, &b->cross);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->dot_radial, &b->dot_radial);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->dot_along, &b->dot_along);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->dot_cross, &b->dot_cross);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->c0, &b->c0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->c1, &b->c1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->c2, &b->c2);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_code_biases_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_code_biases_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod_ssr)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_biases; i++) {
    if (!sbp_code_biases_content_encode_internal(ctx, &msg->biases[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_code_biases_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ssr_code_biases_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_code_biases_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_code_biases_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ssr_code_biases_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod_ssr)) {
    return false;
  }
  msg->n_biases = (uint8_t)((ctx->buf_len - ctx->offset) /
                            SBP_CODE_BIASES_CONTENT_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_biases; i++) {
    if (!sbp_code_biases_content_decode_internal(ctx, &msg->biases[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_code_biases_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_ssr_code_biases_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_code_biases_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_code_biases_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_ssr_code_biases_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_code_biases_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_CODE_BIASES, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ssr_code_biases_cmp(const sbp_msg_ssr_code_biases_t *a,
                                const sbp_msg_ssr_code_biases_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->update_interval, &b->update_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod_ssr, &b->iod_ssr);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_biases, &b->n_biases);
  for (uint8_t i = 0; ret == 0 && i < a->n_biases; i++) {
    ret = sbp_code_biases_content_cmp(&a->biases[i], &b->biases[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_phase_biases_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_phase_biases_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod_ssr)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->dispersive_bias)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->mw_consistency)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->yaw)) {
    return false;
  }
  if (!sbp_s8_encode(ctx, &msg->yaw_rate)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_biases; i++) {
    if (!sbp_phase_biases_content_encode_internal(ctx, &msg->biases[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_phase_biases_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_ssr_phase_biases_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_phase_biases_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_phase_biases_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_ssr_phase_biases_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod_ssr)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->dispersive_bias)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->mw_consistency)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->yaw)) {
    return false;
  }
  if (!sbp_s8_decode(ctx, &msg->yaw_rate)) {
    return false;
  }
  msg->n_biases = (uint8_t)((ctx->buf_len - ctx->offset) /
                            SBP_PHASE_BIASES_CONTENT_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_biases; i++) {
    if (!sbp_phase_biases_content_decode_internal(ctx, &msg->biases[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_phase_biases_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_ssr_phase_biases_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_phase_biases_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_phase_biases_send(sbp_state_t *s, u16 sender_id,
                                 const sbp_msg_ssr_phase_biases_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_phase_biases_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_PHASE_BIASES, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ssr_phase_biases_cmp(const sbp_msg_ssr_phase_biases_t *a,
                                 const sbp_msg_ssr_phase_biases_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->update_interval, &b->update_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod_ssr, &b->iod_ssr);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->dispersive_bias, &b->dispersive_bias);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->mw_consistency, &b->mw_consistency);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->yaw, &b->yaw);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s8_cmp(&a->yaw_rate, &b->yaw_rate);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_biases, &b->n_biases);
  for (uint8_t i = 0; ret == 0 && i < a->n_biases; i++) {
    ret = sbp_phase_biases_content_cmp(&a->biases[i], &b->biases[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_stec_correction_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_stec_correction_t *msg) {
  if (!sbp_stec_header_encode_internal(ctx, &msg->header)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_stec_sat_list; i++) {
    if (!sbp_stec_sat_element_encode_internal(ctx, &msg->stec_sat_list[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_stec_correction_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_stec_correction_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_stec_correction_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_stec_correction_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_stec_correction_t *msg) {
  if (!sbp_stec_header_decode_internal(ctx, &msg->header)) {
    return false;
  }
  msg->n_stec_sat_list = (uint8_t)((ctx->buf_len - ctx->offset) /
                                   SBP_STEC_SAT_ELEMENT_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++) {
    if (!sbp_stec_sat_element_decode_internal(ctx, &msg->stec_sat_list[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_stec_correction_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ssr_stec_correction_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_stec_correction_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_stec_correction_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ssr_stec_correction_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_stec_correction_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_STEC_CORRECTION, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_stec_correction_cmp(const sbp_msg_ssr_stec_correction_t *a,
                                    const sbp_msg_ssr_stec_correction_t *b) {
  int ret = 0;

  ret = sbp_stec_header_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_stec_sat_list, &b->n_stec_sat_list);
  for (uint8_t i = 0; ret == 0 && i < a->n_stec_sat_list; i++) {
    ret = sbp_stec_sat_element_cmp(&a->stec_sat_list[i], &b->stec_sat_list[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_gridded_correction_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_t *msg) {
  if (!sbp_gridded_correction_header_encode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_tropospheric_delay_correction_encode_internal(
          ctx, &msg->tropo_delay_correction)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!sbp_stec_residual_encode_internal(ctx, &msg->stec_residuals[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_gridded_correction_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_gridded_correction_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_gridded_correction_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_gridded_correction_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_gridded_correction_t *msg) {
  if (!sbp_gridded_correction_header_decode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_tropospheric_delay_correction_decode_internal(
          ctx, &msg->tropo_delay_correction)) {
    return false;
  }
  msg->n_stec_residuals =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_STEC_RESIDUAL_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!sbp_stec_residual_decode_internal(ctx, &msg->stec_residuals[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_gridded_correction_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_gridded_correction_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_gridded_correction_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_gridded_correction_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ssr_gridded_correction_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_gridded_correction_encode(payload, sizeof(payload),
                                                 &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_GRIDDED_CORRECTION, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_gridded_correction_cmp(
    const sbp_msg_ssr_gridded_correction_t *a,
    const sbp_msg_ssr_gridded_correction_t *b) {
  int ret = 0;

  ret = sbp_gridded_correction_header_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_tropospheric_delay_correction_cmp(&a->tropo_delay_correction,
                                              &b->tropo_delay_correction);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_stec_residuals, &b->n_stec_residuals);
  for (uint8_t i = 0; ret == 0 && i < a->n_stec_residuals; i++) {
    ret = sbp_stec_residual_cmp(&a->stec_residuals[i], &b->stec_residuals[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_tile_definition_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_tile_definition_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->corner_nw_lat)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->corner_nw_lon)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->spacing_lat)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->spacing_lon)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->rows)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->cols)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->bitmask)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ssr_tile_definition_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_tile_definition_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_tile_definition_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_tile_definition_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_tile_definition_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->corner_nw_lat)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->corner_nw_lon)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->spacing_lat)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->spacing_lon)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->rows)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->cols)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->bitmask)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ssr_tile_definition_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ssr_tile_definition_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_tile_definition_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_tile_definition_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ssr_tile_definition_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_tile_definition_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_TILE_DEFINITION, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_tile_definition_cmp(const sbp_msg_ssr_tile_definition_t *a,
                                    const sbp_msg_ssr_tile_definition_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->tile_set_id, &b->tile_set_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tile_id, &b->tile_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->corner_nw_lat, &b->corner_nw_lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->corner_nw_lon, &b->corner_nw_lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->spacing_lat, &b->spacing_lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->spacing_lon, &b->spacing_lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->rows, &b->rows);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->cols, &b->cols);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->bitmask, &b->bitmask);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_satellite_apc_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_satellite_apc_t *msg) {
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->sat_info)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->svn)) {
    return false;
  }
  for (size_t i = 0; i < SBP_SATELLITE_APC_PCO_MAX; i++) {
    if (!sbp_s16_encode(ctx, &msg->pco[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_SATELLITE_APC_PCV_MAX; i++) {
    if (!sbp_s8_encode(ctx, &msg->pcv[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_satellite_apc_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_satellite_apc_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_satellite_apc_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_satellite_apc_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_satellite_apc_t *msg) {
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->sat_info)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->svn)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_SATELLITE_APC_PCO_MAX; i++) {
    if (!sbp_s16_decode(ctx, &msg->pco[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_SATELLITE_APC_PCV_MAX; i++) {
    if (!sbp_s8_decode(ctx, &msg->pcv[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_satellite_apc_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_satellite_apc_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_satellite_apc_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_satellite_apc_cmp(const sbp_satellite_apc_t *a,
                          const sbp_satellite_apc_t *b) {
  int ret = 0;

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->sat_info, &b->sat_info);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->svn, &b->svn);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_SATELLITE_APC_PCO_MAX; i++) {
    ret = sbp_s16_cmp(&a->pco[i], &b->pco[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_SATELLITE_APC_PCV_MAX; i++) {
    ret = sbp_s8_cmp(&a->pcv[i], &b->pcv[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_satellite_apc_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_satellite_apc_t *msg) {
  for (size_t i = 0; i < msg->n_apc; i++) {
    if (!sbp_satellite_apc_encode_internal(ctx, &msg->apc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_satellite_apc_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_ssr_satellite_apc_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_satellite_apc_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_satellite_apc_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_satellite_apc_t *msg) {
  msg->n_apc =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_SATELLITE_APC_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_apc; i++) {
    if (!sbp_satellite_apc_decode_internal(ctx, &msg->apc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_satellite_apc_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_ssr_satellite_apc_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_satellite_apc_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_satellite_apc_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_ssr_satellite_apc_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_satellite_apc_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_SATELLITE_APC, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ssr_satellite_apc_cmp(const sbp_msg_ssr_satellite_apc_t *a,
                                  const sbp_msg_ssr_satellite_apc_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_apc, &b->n_apc);
  for (uint8_t i = 0; ret == 0 && i < a->n_apc; i++) {
    ret = sbp_satellite_apc_cmp(&a->apc[i], &b->apc[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_orbit_clock_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod_ssr)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->radial)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->along)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->cross)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->dot_radial)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->dot_along)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->dot_cross)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->c0)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->c1)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->c2)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ssr_orbit_clock_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_orbit_clock_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_orbit_clock_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod_ssr)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->radial)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->along)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->cross)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->dot_radial)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->dot_along)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->dot_cross)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->c0)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->c1)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->c2)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ssr_orbit_clock_dep_a_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_orbit_clock_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_orbit_clock_dep_a_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ssr_orbit_clock_dep_a_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_orbit_clock_dep_a_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_ORBIT_CLOCK_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_orbit_clock_dep_a_cmp(
    const sbp_msg_ssr_orbit_clock_dep_a_t *a,
    const sbp_msg_ssr_orbit_clock_dep_a_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->update_interval, &b->update_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod_ssr, &b->iod_ssr);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod, &b->iod);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->radial, &b->radial);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->along, &b->along);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->cross, &b->cross);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->dot_radial, &b->dot_radial);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->dot_along, &b->dot_along);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->dot_cross, &b->dot_cross);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->c0, &b->c0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->c1, &b->c1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->c2, &b->c2);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_stec_header_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_stec_header_dep_a_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod_atmo)) {
    return false;
  }
  return true;
}

s8 sbp_stec_header_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_stec_header_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_header_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_stec_header_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_stec_header_dep_a_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod_atmo)) {
    return false;
  }
  return true;
}

s8 sbp_stec_header_dep_a_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_stec_header_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_stec_header_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_stec_header_dep_a_cmp(const sbp_stec_header_dep_a_t *a,
                              const sbp_stec_header_dep_a_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->num_msgs, &b->num_msgs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->seq_num, &b->seq_num);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->update_interval, &b->update_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod_atmo, &b->iod_atmo);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_gridded_correction_header_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_gridded_correction_header_dep_a_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod_atmo)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->tropo_quality_indicator)) {
    return false;
  }
  return true;
}

s8 sbp_gridded_correction_header_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_gridded_correction_header_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gridded_correction_header_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_gridded_correction_header_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_gridded_correction_header_dep_a_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->update_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod_atmo)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->tropo_quality_indicator)) {
    return false;
  }
  return true;
}

s8 sbp_gridded_correction_header_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_gridded_correction_header_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gridded_correction_header_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_gridded_correction_header_dep_a_cmp(
    const sbp_gridded_correction_header_dep_a_t *a,
    const sbp_gridded_correction_header_dep_a_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->num_msgs, &b->num_msgs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->seq_num, &b->seq_num);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->update_interval, &b->update_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod_atmo, &b->iod_atmo);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->tropo_quality_indicator, &b->tropo_quality_indicator);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_grid_definition_header_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_grid_definition_header_dep_a_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->region_size_inverse)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->area_width)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->lat_nw_corner_enc)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->lon_nw_corner_enc)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->seq_num)) {
    return false;
  }
  return true;
}

s8 sbp_grid_definition_header_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_grid_definition_header_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_grid_definition_header_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_grid_definition_header_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_grid_definition_header_dep_a_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->region_size_inverse)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->area_width)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->lat_nw_corner_enc)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->lon_nw_corner_enc)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->seq_num)) {
    return false;
  }
  return true;
}

s8 sbp_grid_definition_header_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_grid_definition_header_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_grid_definition_header_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_grid_definition_header_dep_a_cmp(
    const sbp_grid_definition_header_dep_a_t *a,
    const sbp_grid_definition_header_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->region_size_inverse, &b->region_size_inverse);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->area_width, &b->area_width);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->lat_nw_corner_enc, &b->lat_nw_corner_enc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->lon_nw_corner_enc, &b->lon_nw_corner_enc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->num_msgs, &b->num_msgs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->seq_num, &b->seq_num);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_stec_correction_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  if (!sbp_stec_header_dep_a_encode_internal(ctx, &msg->header)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_stec_sat_list; i++) {
    if (!sbp_stec_sat_element_encode_internal(ctx, &msg->stec_sat_list[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_stec_correction_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_stec_correction_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_stec_correction_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  if (!sbp_stec_header_dep_a_decode_internal(ctx, &msg->header)) {
    return false;
  }
  msg->n_stec_sat_list = (uint8_t)((ctx->buf_len - ctx->offset) /
                                   SBP_STEC_SAT_ELEMENT_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_stec_sat_list; i++) {
    if (!sbp_stec_sat_element_decode_internal(ctx, &msg->stec_sat_list[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_stec_correction_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_stec_correction_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_stec_correction_dep_a_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_ssr_stec_correction_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_stec_correction_dep_a_encode(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_STEC_CORRECTION_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_stec_correction_dep_a_cmp(
    const sbp_msg_ssr_stec_correction_dep_a_t *a,
    const sbp_msg_ssr_stec_correction_dep_a_t *b) {
  int ret = 0;

  ret = sbp_stec_header_dep_a_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_stec_sat_list, &b->n_stec_sat_list);
  for (uint8_t i = 0; ret == 0 && i < a->n_stec_sat_list; i++) {
    ret = sbp_stec_sat_element_cmp(&a->stec_sat_list[i], &b->stec_sat_list[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_gridded_correction_no_std_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  if (!sbp_gridded_correction_header_dep_a_encode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_tropospheric_delay_correction_no_std_encode_internal(
          ctx, &msg->tropo_delay_correction)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!sbp_stec_residual_no_std_encode_internal(ctx,
                                                  &msg->stec_residuals[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_gridded_correction_no_std_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_gridded_correction_no_std_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_gridded_correction_no_std_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  if (!sbp_gridded_correction_header_dep_a_decode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_tropospheric_delay_correction_no_std_decode_internal(
          ctx, &msg->tropo_delay_correction)) {
    return false;
  }
  msg->n_stec_residuals = (uint8_t)((ctx->buf_len - ctx->offset) /
                                    SBP_STEC_RESIDUAL_NO_STD_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!sbp_stec_residual_no_std_decode_internal(ctx,
                                                  &msg->stec_residuals[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_gridded_correction_no_std_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_gridded_correction_no_std_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_gridded_correction_no_std_dep_a_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_gridded_correction_no_std_dep_a_encode(
      payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A,
                          sender_id, payload_len, payload, write);
}

int sbp_msg_ssr_gridded_correction_no_std_dep_a_cmp(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *a,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *b) {
  int ret = 0;

  ret = sbp_gridded_correction_header_dep_a_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_tropospheric_delay_correction_no_std_cmp(
      &a->tropo_delay_correction, &b->tropo_delay_correction);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_stec_residuals, &b->n_stec_residuals);
  for (uint8_t i = 0; ret == 0 && i < a->n_stec_residuals; i++) {
    ret = sbp_stec_residual_no_std_cmp(&a->stec_residuals[i],
                                       &b->stec_residuals[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_gridded_correction_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  if (!sbp_gridded_correction_header_dep_a_encode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_tropospheric_delay_correction_encode_internal(
          ctx, &msg->tropo_delay_correction)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!sbp_stec_residual_encode_internal(ctx, &msg->stec_residuals[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_gridded_correction_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_gridded_correction_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_gridded_correction_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  if (!sbp_gridded_correction_header_dep_a_decode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_tropospheric_delay_correction_decode_internal(
          ctx, &msg->tropo_delay_correction)) {
    return false;
  }
  msg->n_stec_residuals =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_STEC_RESIDUAL_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_stec_residuals; i++) {
    if (!sbp_stec_residual_decode_internal(ctx, &msg->stec_residuals[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_gridded_correction_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_gridded_correction_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_gridded_correction_dep_a_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_ssr_gridded_correction_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_gridded_correction_dep_a_encode(payload, sizeof(payload),
                                                       &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_gridded_correction_dep_a_cmp(
    const sbp_msg_ssr_gridded_correction_dep_a_t *a,
    const sbp_msg_ssr_gridded_correction_dep_a_t *b) {
  int ret = 0;

  ret = sbp_gridded_correction_header_dep_a_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_tropospheric_delay_correction_cmp(&a->tropo_delay_correction,
                                              &b->tropo_delay_correction);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_stec_residuals, &b->n_stec_residuals);
  for (uint8_t i = 0; ret == 0 && i < a->n_stec_residuals; i++) {
    ret = sbp_stec_residual_cmp(&a->stec_residuals[i], &b->stec_residuals[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_grid_definition_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  if (!sbp_grid_definition_header_dep_a_encode_internal(ctx, &msg->header)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_rle_list; i++) {
    if (!sbp_u8_encode(ctx, &msg->rle_list[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_grid_definition_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_grid_definition_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_grid_definition_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  if (!sbp_grid_definition_header_dep_a_decode_internal(ctx, &msg->header)) {
    return false;
  }
  msg->n_rle_list =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_rle_list; i++) {
    if (!sbp_u8_decode(ctx, &msg->rle_list[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_grid_definition_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_grid_definition_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_grid_definition_dep_a_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_ssr_grid_definition_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_grid_definition_dep_a_encode(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_GRID_DEFINITION_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_grid_definition_dep_a_cmp(
    const sbp_msg_ssr_grid_definition_dep_a_t *a,
    const sbp_msg_ssr_grid_definition_dep_a_t *b) {
  int ret = 0;

  ret = sbp_grid_definition_header_dep_a_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_rle_list, &b->n_rle_list);
  for (uint8_t i = 0; ret == 0 && i < a->n_rle_list; i++) {
    ret = sbp_u8_cmp(&a->rle_list[i], &b->rle_list[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
