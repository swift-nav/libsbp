/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/observation.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/observation.h>

size_t sbp_observation_header_encoded_len(const sbp_observation_header_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_sbp_gps_time_encoded_len(&msg->t);
  encoded_len += sbp_u8_encoded_len(&msg->n_obs);
  return encoded_len;
}

bool sbp_observation_header_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_observation_header_t *msg) {
  if (!sbp_sbp_gps_time_encode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_observation_header_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_observation_header_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_observation_header_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_observation_header_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_observation_header_t *msg) {
  if (!sbp_sbp_gps_time_decode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_observation_header_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_observation_header_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_observation_header_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_observation_header_cmp(const sbp_observation_header_t *a,
                               const sbp_observation_header_t *b) {
  int ret = 0;

  ret = sbp_sbp_gps_time_cmp(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_doppler_encoded_len(const sbp_doppler_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_s16_encoded_len(&msg->i);
  encoded_len += sbp_u8_encoded_len(&msg->f);
  return encoded_len;
}

bool sbp_doppler_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_doppler_t *msg) {
  if (!sbp_s16_encode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_doppler_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                      const sbp_doppler_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_doppler_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_doppler_decode_internal(sbp_decode_ctx_t *ctx, sbp_doppler_t *msg) {
  if (!sbp_s16_decode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_doppler_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                      sbp_doppler_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_doppler_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_doppler_cmp(const sbp_doppler_t *a, const sbp_doppler_t *b) {
  int ret = 0;

  ret = sbp_s16_cmp(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->f, &b->f);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_obs_content_encoded_len(const sbp_packed_obs_content_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->P);
  encoded_len += sbp_carrier_phase_encoded_len(&msg->L);
  encoded_len += sbp_doppler_encoded_len(&msg->D);
  encoded_len += sbp_u8_encoded_len(&msg->cn0);
  encoded_len += sbp_u8_encoded_len(&msg->lock);
  encoded_len += sbp_u8_encoded_len(&msg->flags);
  encoded_len += sbp_sbp_gnss_signal_encoded_len(&msg->sid);
  return encoded_len;
}

bool sbp_packed_obs_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_encode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_doppler_encode_internal(ctx, &msg->D)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_sbp_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_packed_obs_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_packed_obs_content_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_packed_obs_content_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_decode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_doppler_decode_internal(ctx, &msg->D)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_sbp_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_packed_obs_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_packed_obs_content_cmp(const sbp_packed_obs_content_t *a,
                               const sbp_packed_obs_content_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_carrier_phase_cmp(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_doppler_cmp(&a->D, &b->D);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_sbp_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_obs_encoded_len(const sbp_msg_obs_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_observation_header_encoded_len(&msg->header);
  encoded_len +=
      (msg->n_obs * sbp_packed_obs_content_encoded_len(&msg->obs[0]));
  return encoded_len;
}

bool sbp_msg_obs_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_obs_t *msg) {
  if (!sbp_observation_header_encode_internal(ctx, &msg->header)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_encode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                      const sbp_msg_obs_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_obs_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_obs_t *msg) {
  if (!sbp_observation_header_decode_internal(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) /
                         sbp_packed_obs_content_encoded_len(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_decode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                      sbp_msg_obs_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_obs_send(sbp_state_t *s, u16 sender_id, const sbp_msg_obs_t *msg,
                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_obs_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OBS, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_obs_cmp(const sbp_msg_obs_t *a, const sbp_msg_obs_t *b) {
  int ret = 0;

  ret = sbp_observation_header_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; ret == 0 && i < a->n_obs; i++) {
    ret = sbp_packed_obs_content_cmp(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_sv_az_el_encoded_len(const sbp_sv_az_el_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_sbp_gnss_signal_encoded_len(&msg->sid);
  encoded_len += sbp_u8_encoded_len(&msg->az);
  encoded_len += sbp_s8_encoded_len(&msg->el);
  return encoded_len;
}

bool sbp_sv_az_el_encode_internal(sbp_encode_ctx_t *ctx,
                                  const sbp_sv_az_el_t *msg) {
  if (!sbp_sbp_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->az)) {
    return false;
  }
  if (!sbp_s8_encode(ctx, &msg->el)) {
    return false;
  }
  return true;
}

s8 sbp_sv_az_el_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                       const sbp_sv_az_el_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sv_az_el_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_sv_az_el_decode_internal(sbp_decode_ctx_t *ctx, sbp_sv_az_el_t *msg) {
  if (!sbp_sbp_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->az)) {
    return false;
  }
  if (!sbp_s8_decode(ctx, &msg->el)) {
    return false;
  }
  return true;
}

s8 sbp_sv_az_el_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                       sbp_sv_az_el_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sv_az_el_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_sv_az_el_cmp(const sbp_sv_az_el_t *a, const sbp_sv_az_el_t *b) {
  int ret = 0;

  ret = sbp_sbp_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->az, &b->az);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s8_cmp(&a->el, &b->el);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_sv_az_el_encoded_len(const sbp_msg_sv_az_el_t *msg) {
  size_t encoded_len = 0;
  encoded_len += (msg->n_azel * sbp_sv_az_el_encoded_len(&msg->azel[0]));
  return encoded_len;
}

bool sbp_msg_sv_az_el_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_sv_az_el_t *msg) {
  for (size_t i = 0; i < msg->n_azel; i++) {
    if (!sbp_sv_az_el_encode_internal(ctx, &msg->azel[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_sv_az_el_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_sv_az_el_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_sv_az_el_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_sv_az_el_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_sv_az_el_t *msg) {
  msg->n_azel = (uint8_t)((ctx->buf_len - ctx->offset) /
                          sbp_sv_az_el_encoded_len(&msg->azel[0]));
  for (uint8_t i = 0; i < msg->n_azel; i++) {
    if (!sbp_sv_az_el_decode_internal(ctx, &msg->azel[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_sv_az_el_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_sv_az_el_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_sv_az_el_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_sv_az_el_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_sv_az_el_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_sv_az_el_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SV_AZ_EL, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_sv_az_el_cmp(const sbp_msg_sv_az_el_t *a,
                         const sbp_msg_sv_az_el_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_azel, &b->n_azel);
  for (uint8_t i = 0; ret == 0 && i < a->n_azel; i++) {
    ret = sbp_sv_az_el_cmp(&a->azel[i], &b->azel[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
