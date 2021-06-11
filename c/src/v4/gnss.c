/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/gnss.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/gnss.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/gnss.h>

size_t sbp_sbp_gnss_signal_encoded_len(const sbp_sbp_gnss_signal_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->sat);
  encoded_len += sbp_u8_encoded_len(&msg->code);
  return encoded_len;
}

bool sbp_sbp_gnss_signal_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_sbp_gnss_signal_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->sat)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->code)) {
    return false;
  }
  return true;
}

s8 sbp_sbp_gnss_signal_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_sbp_gnss_signal_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sbp_gnss_signal_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_sbp_gnss_signal_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_sbp_gnss_signal_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->sat)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->code)) {
    return false;
  }
  return true;
}

s8 sbp_sbp_gnss_signal_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_sbp_gnss_signal_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sbp_gnss_signal_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_sbp_gnss_signal_cmp(const sbp_sbp_gnss_signal_t *a,
                            const sbp_sbp_gnss_signal_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->sat, &b->sat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->code, &b->code);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_sbp_gps_time_encoded_len(const sbp_sbp_gps_time_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->tow);
  encoded_len += sbp_s32_encoded_len(&msg->ns_residual);
  encoded_len += sbp_u16_encoded_len(&msg->wn);
  return encoded_len;
}

bool sbp_sbp_gps_time_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_sbp_gps_time_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->wn)) {
    return false;
  }
  return true;
}

s8 sbp_sbp_gps_time_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_sbp_gps_time_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sbp_gps_time_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_sbp_gps_time_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_sbp_gps_time_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->wn)) {
    return false;
  }
  return true;
}

s8 sbp_sbp_gps_time_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_sbp_gps_time_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sbp_gps_time_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_sbp_gps_time_cmp(const sbp_sbp_gps_time_t *a,
                         const sbp_sbp_gps_time_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->ns_residual, &b->ns_residual);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_carrier_phase_encoded_len(const sbp_carrier_phase_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_s32_encoded_len(&msg->i);
  encoded_len += sbp_u8_encoded_len(&msg->f);
  return encoded_len;
}

bool sbp_carrier_phase_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_carrier_phase_t *msg) {
  if (!sbp_s32_encode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_carrier_phase_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_carrier_phase_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_carrier_phase_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_carrier_phase_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_carrier_phase_t *msg) {
  if (!sbp_s32_decode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_carrier_phase_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_carrier_phase_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_carrier_phase_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_carrier_phase_cmp(const sbp_carrier_phase_t *a,
                          const sbp_carrier_phase_t *b) {
  int ret = 0;

  ret = sbp_s32_cmp(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->f, &b->f);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
