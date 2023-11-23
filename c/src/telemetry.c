/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/telemetry.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/common.h>
#include <libsbp/internal/sbp_internal.h>
#include <libsbp/internal/string/double_null_terminated.h>
#include <libsbp/internal/string/multipart.h>
#include <libsbp/internal/string/null_terminated.h>
#include <libsbp/internal/string/unterminated.h>
#include <libsbp/internal/telemetry.h>
#include <libsbp/sbp.h>
#include <libsbp/telemetry.h>

bool sbp_telemetry_sv_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_telemetry_sv_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->az)) {
    return false;
  }
  if (!sbp_s8_encode(ctx, &msg->el)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->availability_flags)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->pseudorange_residual)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->phase_residual)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->outlier_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->ephemeris_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->correction_flags)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_telemetry_sv_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_telemetry_sv_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_telemetry_sv_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_telemetry_sv_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_telemetry_sv_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->az)) {
    return false;
  }
  if (!sbp_s8_decode(ctx, &msg->el)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->availability_flags)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->pseudorange_residual)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->phase_residual)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->outlier_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->ephemeris_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->correction_flags)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_telemetry_sv_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_telemetry_sv_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_telemetry_sv_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_telemetry_sv_cmp(const sbp_telemetry_sv_t *a,
                         const sbp_telemetry_sv_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->az, &b->az);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s8_cmp(&a->el, &b->el);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->availability_flags, &b->availability_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->pseudorange_residual, &b->pseudorange_residual);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->phase_residual, &b->phase_residual);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->outlier_flags, &b->outlier_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->ephemeris_flags, &b->ephemeris_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->correction_flags, &b->correction_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_tel_sv_encode_internal(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_tel_sv_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_obs)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->origin_flags)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_sv_tel; i++) {
    if (!sbp_telemetry_sv_encode_internal(ctx, &msg->sv_tel[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tel_sv_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                         const sbp_msg_tel_sv_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tel_sv_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_tel_sv_decode_internal(sbp_decode_ctx_t *ctx,
                                    sbp_msg_tel_sv_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_obs)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->origin_flags)) {
    return false;
  }
  if (((ctx->buf_len - ctx->offset) % SBP_TELEMETRY_SV_ENCODED_LEN) != 0) {
    return false;
  }
  msg->n_sv_tel =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_TELEMETRY_SV_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_sv_tel; i++) {
    if (!sbp_telemetry_sv_decode_internal(ctx, &msg->sv_tel[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tel_sv_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                         sbp_msg_tel_sv_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tel_sv_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_tel_sv_send(sbp_state_t *s, u16 sender_id,
                       const sbp_msg_tel_sv_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_tel_sv_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_internal_forward_payload(s, SBP_MSG_TEL_SV, sender_id, payload_len,
                                      payload, write);
}

int sbp_msg_tel_sv_cmp(const sbp_msg_tel_sv_t *a, const sbp_msg_tel_sv_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->origin_flags, &b->origin_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sv_tel, &b->n_sv_tel);
  for (uint8_t i = 0; ret == 0 && i < a->n_sv_tel; i++) {
    ret = sbp_telemetry_sv_cmp(&a->sv_tel[i], &b->sv_tel[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
