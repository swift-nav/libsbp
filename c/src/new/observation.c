/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/observation.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>
#include <libsbp/new/observation.h>
#include <libsbp/sbp.h>

size_t sbp_packed_size_sbp_observation_header_t(
    const sbp_observation_header_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gps_time_t(&msg->t);
  packed_size += sbp_packed_size_u8(&msg->n_obs);
  return packed_size;
}

bool encode_sbp_observation_header_t(sbp_encode_ctx_t *ctx,
                                     const sbp_observation_header_t *msg) {
  if (!encode_sbp_sbp_gps_time_t(ctx, &msg->t)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_observation_header_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_observation_header_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_observation_header_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_observation_header_t(sbp_decode_ctx_t *ctx,
                                     sbp_observation_header_t *msg) {
  if (!decode_sbp_sbp_gps_time_t(ctx, &msg->t)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_observation_header_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_observation_header_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_observation_header_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_observation_header_t(const sbp_observation_header_t *a,
                                     const sbp_observation_header_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_sbp_gps_time_t(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_doppler_t(const sbp_doppler_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

bool encode_sbp_doppler_t(sbp_encode_ctx_t *ctx, const sbp_doppler_t *msg) {
  if (!encode_s16(ctx, &msg->i)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_doppler_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_doppler_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_doppler_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_doppler_t(sbp_decode_ctx_t *ctx, sbp_doppler_t *msg) {
  if (!decode_s16(ctx, &msg->i)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_doppler_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_doppler_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_doppler_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_doppler_t(const sbp_doppler_t *a, const sbp_doppler_t *b) {
  int ret = 0;

  ret = sbp_cmp_s16(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->f, &b->f);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_packed_obs_content_t(
    const sbp_packed_obs_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_sbp_doppler_t(&msg->D);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u8(&msg->lock);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

bool encode_sbp_packed_obs_content_t(sbp_encode_ctx_t *ctx,
                                     const sbp_packed_obs_content_t *msg) {
  if (!encode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!encode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!encode_sbp_doppler_t(ctx, &msg->D)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->lock)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->flags)) {
    return false;
  }
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_packed_obs_content_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_packed_obs_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_packed_obs_content_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_packed_obs_content_t(sbp_decode_ctx_t *ctx,
                                     sbp_packed_obs_content_t *msg) {
  if (!decode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!decode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!decode_sbp_doppler_t(ctx, &msg->D)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->lock)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->flags)) {
    return false;
  }
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_packed_obs_content_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_packed_obs_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_packed_obs_content_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_packed_obs_content_t(const sbp_packed_obs_content_t *a,
                                     const sbp_packed_obs_content_t *b) {
  int ret = 0;

  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_doppler_t(&a->D, &b->D);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_packed_osr_content_t(
    const sbp_packed_osr_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->lock);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u16(&msg->iono_std);
  packed_size += sbp_packed_size_u16(&msg->tropo_std);
  packed_size += sbp_packed_size_u16(&msg->range_std);
  return packed_size;
}

bool encode_sbp_packed_osr_content_t(sbp_encode_ctx_t *ctx,
                                     const sbp_packed_osr_content_t *msg) {
  if (!encode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!encode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->lock)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->flags)) {
    return false;
  }
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iono_std)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->tropo_std)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->range_std)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_packed_osr_content_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_packed_osr_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_packed_osr_content_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_packed_osr_content_t(sbp_decode_ctx_t *ctx,
                                     sbp_packed_osr_content_t *msg) {
  if (!decode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!decode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->lock)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->flags)) {
    return false;
  }
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iono_std)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->tropo_std)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->range_std)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_packed_osr_content_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_packed_osr_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_packed_osr_content_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_packed_osr_content_t(const sbp_packed_osr_content_t *a,
                                     const sbp_packed_osr_content_t *b) {
  int ret = 0;

  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iono_std, &b->iono_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->tropo_std, &b->tropo_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->range_std, &b->range_std);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_obs_t(const sbp_msg_obs_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_t(&msg->header);
  packed_size +=
      (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_t(&msg->obs[0]));
  return packed_size;
}

bool encode_sbp_msg_obs_t(sbp_encode_ctx_t *ctx, const sbp_msg_obs_t *msg) {
  if (!encode_sbp_observation_header_t(ctx, &msg->header)) {
    return false;
  }
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!encode_sbp_packed_obs_content_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_obs_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_obs_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_obs_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_obs_t(sbp_decode_ctx_t *ctx, sbp_msg_obs_t *msg) {
  if (!decode_sbp_observation_header_t(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_packed_size_sbp_packed_obs_content_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!decode_sbp_packed_obs_content_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_obs_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_obs_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_obs_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_obs_t(struct sbp_state *s, u16 sender_id,
                          const sbp_msg_obs_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_encode_sbp_msg_obs_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OBS, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_obs_t(const sbp_msg_obs_t *a, const sbp_msg_obs_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_observation_header_t(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++) {
    ret = sbp_cmp_sbp_packed_obs_content_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_base_pos_llh_t(
    const sbp_msg_base_pos_llh_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  return packed_size;
}

bool encode_sbp_msg_base_pos_llh_t(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_base_pos_llh_t *msg) {
  if (!encode_double(ctx, &msg->lat)) {
    return false;
  }
  if (!encode_double(ctx, &msg->lon)) {
    return false;
  }
  if (!encode_double(ctx, &msg->height)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_base_pos_llh_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_base_pos_llh_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_base_pos_llh_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_base_pos_llh_t(sbp_decode_ctx_t *ctx,
                                   sbp_msg_base_pos_llh_t *msg) {
  if (!decode_double(ctx, &msg->lat)) {
    return false;
  }
  if (!decode_double(ctx, &msg->lon)) {
    return false;
  }
  if (!decode_double(ctx, &msg->height)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_base_pos_llh_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_base_pos_llh_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_base_pos_llh_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_base_pos_llh_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_base_pos_llh_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_base_pos_llh_t(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASE_POS_LLH, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_base_pos_llh_t(const sbp_msg_base_pos_llh_t *a,
                                   const sbp_msg_base_pos_llh_t *b) {
  int ret = 0;

  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_base_pos_ecef_t(
    const sbp_msg_base_pos_ecef_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  return packed_size;
}

bool encode_sbp_msg_base_pos_ecef_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_base_pos_ecef_t *msg) {
  if (!encode_double(ctx, &msg->x)) {
    return false;
  }
  if (!encode_double(ctx, &msg->y)) {
    return false;
  }
  if (!encode_double(ctx, &msg->z)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_base_pos_ecef_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_base_pos_ecef_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_base_pos_ecef_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_base_pos_ecef_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_base_pos_ecef_t *msg) {
  if (!decode_double(ctx, &msg->x)) {
    return false;
  }
  if (!decode_double(ctx, &msg->y)) {
    return false;
  }
  if (!decode_double(ctx, &msg->z)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_base_pos_ecef_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_base_pos_ecef_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_base_pos_ecef_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_base_pos_ecef_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_base_pos_ecef_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_base_pos_ecef_t(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASE_POS_ECEF, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_base_pos_ecef_t(const sbp_msg_base_pos_ecef_t *a,
                                    const sbp_msg_base_pos_ecef_t *b) {
  int ret = 0;

  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_ephemeris_common_content_t(
    const sbp_ephemeris_common_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toe);
  packed_size += sbp_packed_size_float(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

bool encode_sbp_ephemeris_common_content_t(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_t *msg) {
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toe)) {
    return false;
  }
  if (!encode_float(ctx, &msg->ura)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_ephemeris_common_content_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_ephemeris_common_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_ephemeris_common_content_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_ephemeris_common_content_t(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_t *msg) {
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toe)) {
    return false;
  }
  if (!decode_float(ctx, &msg->ura)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_ephemeris_common_content_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_ephemeris_common_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_ephemeris_common_content_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_ephemeris_common_content_t(
    const sbp_ephemeris_common_content_t *a,
    const sbp_ephemeris_common_content_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toe, &b->toe);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(
    const sbp_ephemeris_common_content_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toe);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

bool encode_sbp_ephemeris_common_content_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_dep_b_t *msg) {
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toe)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ura)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_ephemeris_common_content_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_ephemeris_common_content_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_ephemeris_common_content_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_ephemeris_common_content_dep_b_t(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_dep_b_t *msg) {
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toe)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ura)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_ephemeris_common_content_dep_b_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_ephemeris_common_content_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_ephemeris_common_content_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_ephemeris_common_content_dep_b_t(
    const sbp_ephemeris_common_content_dep_b_t *a,
    const sbp_ephemeris_common_content_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toe, &b->toe);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(
    const sbp_ephemeris_common_content_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->toe);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

bool encode_sbp_ephemeris_common_content_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_dep_a_t *msg) {
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_sbp_gps_time_dep_t(ctx, &msg->toe)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ura)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_ephemeris_common_content_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_ephemeris_common_content_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_ephemeris_common_content_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_ephemeris_common_content_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_dep_a_t *msg) {
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_sbp_gps_time_dep_t(ctx, &msg->toe)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ura)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_ephemeris_common_content_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_ephemeris_common_content_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_ephemeris_common_content_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_ephemeris_common_content_dep_a_t(
    const sbp_ephemeris_common_content_dep_a_t *a,
    const sbp_ephemeris_common_content_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_dep_t(&a->toe, &b->toe);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(
    const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_gps_dep_e_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  if (!encode_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_sbp_gps_time_dep_t(ctx, &msg->toc)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_gps_dep_e_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_gps_dep_e_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_gps_dep_e_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_gps_dep_e_t *msg) {
  if (!decode_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_sbp_gps_time_dep_t(ctx, &msg->toc)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_gps_dep_e_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_gps_dep_e_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_gps_dep_e_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_gps_dep_e_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_gps_dep_e_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_gps_dep_e_t(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GPS_DEP_E, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_gps_dep_e_t(
    const sbp_msg_ephemeris_gps_dep_e_t *a,
    const sbp_msg_ephemeris_gps_dep_e_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_dep_t(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(
    const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_gps_dep_f_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  if (!encode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_gps_dep_f_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_gps_dep_f_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_gps_dep_f_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_gps_dep_f_t *msg) {
  if (!decode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_gps_dep_f_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_gps_dep_f_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_gps_dep_f_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_gps_dep_f_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_gps_dep_f_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_gps_dep_f_t(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GPS_DEP_F, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_gps_dep_f_t(
    const sbp_msg_ephemeris_gps_dep_f_t *a,
    const sbp_msg_ephemeris_gps_dep_f_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_gps_t(
    const sbp_msg_ephemeris_gps_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->tgd);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_float(&msg->af0);
  packed_size += sbp_packed_size_float(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_gps_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_ephemeris_gps_t *msg) {
  if (!encode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_float(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_gps_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_ephemeris_gps_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_gps_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_gps_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_ephemeris_gps_t *msg) {
  if (!decode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_float(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_gps_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_gps_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_gps_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_gps_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_ephemeris_gps_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_gps_t(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GPS, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_gps_t(const sbp_msg_ephemeris_gps_t *a,
                                    const sbp_msg_ephemeris_gps_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_qzss_t(
    const sbp_msg_ephemeris_qzss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->tgd);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_float(&msg->af0);
  packed_size += sbp_packed_size_float(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_qzss_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_ephemeris_qzss_t *msg) {
  if (!encode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_float(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_qzss_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_ephemeris_qzss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_qzss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_qzss_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_ephemeris_qzss_t *msg) {
  if (!decode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_float(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_qzss_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_ephemeris_qzss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_qzss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_qzss_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_ephemeris_qzss_t *msg,
                                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_qzss_t(payload, sizeof(payload),
                                               &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_QZSS, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_qzss_t(const sbp_msg_ephemeris_qzss_t *a,
                                     const sbp_msg_ephemeris_qzss_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_bds_t(
    const sbp_msg_ephemeris_bds_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->tgd1);
  packed_size += sbp_packed_size_float(&msg->tgd2);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_float(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_bds_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_ephemeris_bds_t *msg) {
  if (!encode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_float(ctx, &msg->tgd1)) {
    return false;
  }
  if (!encode_float(ctx, &msg->tgd2)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_bds_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_ephemeris_bds_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_bds_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_bds_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_ephemeris_bds_t *msg) {
  if (!decode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_float(ctx, &msg->tgd1)) {
    return false;
  }
  if (!decode_float(ctx, &msg->tgd2)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_bds_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_bds_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_bds_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_bds_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_ephemeris_bds_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_bds_t(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_BDS, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_bds_t(const sbp_msg_ephemeris_bds_t *a,
                                    const sbp_msg_ephemeris_bds_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->tgd1, &b->tgd1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->tgd2, &b->tgd2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(
    const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->bgd_e1e5a);
  packed_size += sbp_packed_size_float(&msg->bgd_e1e5b);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u16(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_gal_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  if (!encode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_float(ctx, &msg->bgd_e1e5a)) {
    return false;
  }
  if (!encode_float(ctx, &msg->bgd_e1e5b)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iode)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_gal_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_gal_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_gal_dep_a_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_gal_dep_a_t *msg) {
  if (!decode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_float(ctx, &msg->bgd_e1e5a)) {
    return false;
  }
  if (!decode_float(ctx, &msg->bgd_e1e5b)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iode)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_gal_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_gal_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_gal_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_gal_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_gal_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_gal_dep_a_t(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GAL_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_gal_dep_a_t(
    const sbp_msg_ephemeris_gal_dep_a_t *a,
    const sbp_msg_ephemeris_gal_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->bgd_e1e5a, &b->bgd_e1e5a);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->bgd_e1e5b, &b->bgd_e1e5b);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_gal_t(
    const sbp_msg_ephemeris_gal_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->bgd_e1e5a);
  packed_size += sbp_packed_size_float(&msg->bgd_e1e5b);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u16(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  packed_size += sbp_packed_size_u8(&msg->source);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_gal_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_ephemeris_gal_t *msg) {
  if (!encode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_float(ctx, &msg->bgd_e1e5a)) {
    return false;
  }
  if (!encode_float(ctx, &msg->bgd_e1e5b)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iode)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iodc)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->source)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_gal_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_ephemeris_gal_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_gal_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_gal_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_ephemeris_gal_t *msg) {
  if (!decode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_float(ctx, &msg->bgd_e1e5a)) {
    return false;
  }
  if (!decode_float(ctx, &msg->bgd_e1e5b)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_float(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_float(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toc)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iode)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iodc)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->source)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_gal_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_gal_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_gal_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_gal_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_ephemeris_gal_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_gal_t(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GAL, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_gal_t(const sbp_msg_ephemeris_gal_t *a,
                                    const sbp_msg_ephemeris_gal_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->bgd_e1e5a, &b->bgd_e1e5a);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->bgd_e1e5b, &b->bgd_e1e5b);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->source, &b->source);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(
    const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(&msg->common);
  packed_size += (3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_double(&msg->a_gf0);
  packed_size += sbp_packed_size_double(&msg->a_gf1);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_sbas_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  if (!encode_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!encode_double(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_sbas_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_sbas_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_sbas_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  if (!decode_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!decode_double(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_sbas_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_sbas_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_sbas_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_sbas_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_sbas_dep_a_t(payload, sizeof(payload),
                                                     &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_SBAS_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_sbas_dep_a_t(
    const sbp_msg_ephemeris_sbas_dep_a_t *a,
    const sbp_msg_ephemeris_sbas_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->a_gf0, &b->a_gf0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->a_gf1, &b->a_gf1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(
    const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += (3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->acc[0]));
  return packed_size;
}

bool encode_sbp_msg_ephemeris_glo_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  if (!encode_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->gamma)) {
    return false;
  }
  if (!encode_double(ctx, &msg->tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_glo_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_glo_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_glo_dep_a_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_glo_dep_a_t *msg) {
  if (!decode_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->gamma)) {
    return false;
  }
  if (!decode_double(ctx, &msg->tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_glo_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_glo_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_glo_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_glo_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_glo_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_glo_dep_a_t(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_glo_dep_a_t(
    const sbp_msg_ephemeris_glo_dep_a_t *a,
    const sbp_msg_ephemeris_glo_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_dep_a_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(
    const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += (3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_double(&msg->a_gf0);
  packed_size += sbp_packed_size_double(&msg->a_gf1);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_sbas_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  if (!encode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!encode_double(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_sbas_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_sbas_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_sbas_dep_b_t(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  if (!decode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!decode_double(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_sbas_dep_b_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_sbas_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_sbas_dep_b_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_sbas_dep_b_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_sbas_dep_b_t(payload, sizeof(payload),
                                                     &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_SBAS_DEP_B, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_sbas_dep_b_t(
    const sbp_msg_ephemeris_sbas_dep_b_t *a,
    const sbp_msg_ephemeris_sbas_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->a_gf0, &b->a_gf0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->a_gf1, &b->a_gf1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_sbas_t(
    const sbp_msg_ephemeris_sbas_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += (3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += (3 * sbp_packed_size_float(&msg->vel[0]));
  packed_size += (3 * sbp_packed_size_float(&msg->acc[0]));
  packed_size += sbp_packed_size_float(&msg->a_gf0);
  packed_size += sbp_packed_size_float(&msg->a_gf1);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_sbas_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_ephemeris_sbas_t *msg) {
  if (!encode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_float(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_float(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!encode_float(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!encode_float(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_sbas_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_ephemeris_sbas_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_sbas_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_sbas_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_ephemeris_sbas_t *msg) {
  if (!decode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_float(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_float(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!decode_float(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!decode_float(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_sbas_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_ephemeris_sbas_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_sbas_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_sbas_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_ephemeris_sbas_t *msg,
                                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_sbas_t(payload, sizeof(payload),
                                               &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_SBAS, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_sbas_t(const sbp_msg_ephemeris_sbas_t *a,
                                     const sbp_msg_ephemeris_sbas_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_float(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_float(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->a_gf0, &b->a_gf0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->a_gf1, &b->a_gf1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(
    const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += (3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->acc[0]));
  return packed_size;
}

bool encode_sbp_msg_ephemeris_glo_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  if (!encode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->gamma)) {
    return false;
  }
  if (!encode_double(ctx, &msg->tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_glo_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_glo_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_glo_dep_b_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_glo_dep_b_t *msg) {
  if (!decode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->gamma)) {
    return false;
  }
  if (!decode_double(ctx, &msg->tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_glo_dep_b_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_glo_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_glo_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_glo_dep_b_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_glo_dep_b_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_glo_dep_b_t(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO_DEP_B, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_glo_dep_b_t(
    const sbp_msg_ephemeris_glo_dep_b_t *a,
    const sbp_msg_ephemeris_glo_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(
    const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += sbp_packed_size_double(&msg->d_tau);
  packed_size += (3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_u8(&msg->fcn);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_glo_dep_c_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  if (!encode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->gamma)) {
    return false;
  }
  if (!encode_double(ctx, &msg->tau)) {
    return false;
  }
  if (!encode_double(ctx, &msg->d_tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!encode_u8(ctx, &msg->fcn)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_glo_dep_c_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_glo_dep_c_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_glo_dep_c_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_glo_dep_c_t *msg) {
  if (!decode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->gamma)) {
    return false;
  }
  if (!decode_double(ctx, &msg->tau)) {
    return false;
  }
  if (!decode_double(ctx, &msg->d_tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!decode_u8(ctx, &msg->fcn)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_glo_dep_c_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_glo_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_glo_dep_c_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_glo_dep_c_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_glo_dep_c_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_glo_dep_c_t(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO_DEP_C, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_glo_dep_c_t(
    const sbp_msg_ephemeris_glo_dep_c_t *a,
    const sbp_msg_ephemeris_glo_dep_c_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->d_tau, &b->d_tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->fcn, &b->fcn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(
    const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += sbp_packed_size_double(&msg->d_tau);
  packed_size += (3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_u8(&msg->fcn);
  packed_size += sbp_packed_size_u8(&msg->iod);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_glo_dep_d_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  if (!encode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->gamma)) {
    return false;
  }
  if (!encode_double(ctx, &msg->tau)) {
    return false;
  }
  if (!encode_double(ctx, &msg->d_tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!encode_u8(ctx, &msg->fcn)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iod)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_glo_dep_d_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_glo_dep_d_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_glo_dep_d_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_ephemeris_glo_dep_d_t *msg) {
  if (!decode_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->gamma)) {
    return false;
  }
  if (!decode_double(ctx, &msg->tau)) {
    return false;
  }
  if (!decode_double(ctx, &msg->d_tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!decode_u8(ctx, &msg->fcn)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iod)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_glo_dep_d_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ephemeris_glo_dep_d_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_glo_dep_d_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_glo_dep_d_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_ephemeris_glo_dep_d_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_glo_dep_d_t(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO_DEP_D, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_glo_dep_d_t(
    const sbp_msg_ephemeris_glo_dep_d_t *a,
    const sbp_msg_ephemeris_glo_dep_d_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_dep_b_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->d_tau, &b->d_tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->fcn, &b->fcn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iod, &b->iod);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_glo_t(
    const sbp_msg_ephemeris_glo_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->gamma);
  packed_size += sbp_packed_size_float(&msg->tau);
  packed_size += sbp_packed_size_float(&msg->d_tau);
  packed_size += (3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += (3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += (3 * sbp_packed_size_float(&msg->acc[0]));
  packed_size += sbp_packed_size_u8(&msg->fcn);
  packed_size += sbp_packed_size_u8(&msg->iod);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_glo_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_ephemeris_glo_t *msg) {
  if (!encode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_float(ctx, &msg->gamma)) {
    return false;
  }
  if (!encode_float(ctx, &msg->tau)) {
    return false;
  }
  if (!encode_float(ctx, &msg->d_tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!encode_float(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!encode_u8(ctx, &msg->fcn)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iod)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_glo_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_ephemeris_glo_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_glo_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_glo_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_ephemeris_glo_t *msg) {
  if (!decode_sbp_ephemeris_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_float(ctx, &msg->gamma)) {
    return false;
  }
  if (!decode_float(ctx, &msg->tau)) {
    return false;
  }
  if (!decode_float(ctx, &msg->d_tau)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_double(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_float(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!decode_u8(ctx, &msg->fcn)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iod)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_glo_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_glo_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_glo_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_glo_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_ephemeris_glo_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_glo_t(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_glo_t(const sbp_msg_ephemeris_glo_t *a,
                                    const sbp_msg_ephemeris_glo_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_ephemeris_common_content_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->d_tau, &b->d_tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_double(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; i < 3 && ret == 0; i++) {
    ret = sbp_cmp_float(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->fcn, &b->fcn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iod, &b->iod);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_dep_d_t(
    const sbp_msg_ephemeris_dep_d_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_double(&msg->toe_tow);
  packed_size += sbp_packed_size_u16(&msg->toe_wn);
  packed_size += sbp_packed_size_double(&msg->toc_tow);
  packed_size += sbp_packed_size_u16(&msg->toc_wn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->healthy);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  packed_size += sbp_packed_size_u32(&msg->reserved);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_dep_d_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_ephemeris_dep_d_t *msg) {
  if (!encode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_double(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->healthy)) {
    return false;
  }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iodc)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_dep_d_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ephemeris_dep_d_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_dep_d_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_dep_d_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_ephemeris_dep_d_t *msg) {
  if (!decode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_double(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->healthy)) {
    return false;
  }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iodc)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_dep_d_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ephemeris_dep_d_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_dep_d_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_dep_d_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ephemeris_dep_d_t *msg,
                                      sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_dep_d_t(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_DEP_D, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_dep_d_t(const sbp_msg_ephemeris_dep_d_t *a,
                                      const sbp_msg_ephemeris_dep_d_t *b) {
  int ret = 0;

  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->toe_tow, &b->toe_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->toe_wn, &b->toe_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->toc_tow, &b->toc_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->toc_wn, &b->toc_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->healthy, &b->healthy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->reserved, &b->reserved);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_dep_a_t(
    const sbp_msg_ephemeris_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_double(&msg->toe_tow);
  packed_size += sbp_packed_size_u16(&msg->toe_wn);
  packed_size += sbp_packed_size_double(&msg->toc_tow);
  packed_size += sbp_packed_size_u16(&msg->toc_wn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->healthy);
  packed_size += sbp_packed_size_u8(&msg->prn);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_dep_a_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_ephemeris_dep_a_t *msg) {
  if (!encode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_double(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->healthy)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_dep_a_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ephemeris_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_dep_a_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_ephemeris_dep_a_t *msg) {
  if (!decode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_double(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->healthy)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_dep_a_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ephemeris_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_dep_a_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ephemeris_dep_a_t *msg,
                                      sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_dep_a_t(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_dep_a_t(const sbp_msg_ephemeris_dep_a_t *a,
                                      const sbp_msg_ephemeris_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->toe_tow, &b->toe_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->toe_wn, &b->toe_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->toc_tow, &b->toc_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->toc_wn, &b->toc_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->healthy, &b->healthy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_dep_b_t(
    const sbp_msg_ephemeris_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_double(&msg->toe_tow);
  packed_size += sbp_packed_size_u16(&msg->toe_wn);
  packed_size += sbp_packed_size_double(&msg->toc_tow);
  packed_size += sbp_packed_size_u16(&msg->toc_wn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->healthy);
  packed_size += sbp_packed_size_u8(&msg->prn);
  packed_size += sbp_packed_size_u8(&msg->iode);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_dep_b_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_ephemeris_dep_b_t *msg) {
  if (!encode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_double(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->healthy)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->prn)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iode)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_dep_b_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ephemeris_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_dep_b_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_ephemeris_dep_b_t *msg) {
  if (!decode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_double(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->healthy)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->prn)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iode)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_dep_b_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ephemeris_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_dep_b_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ephemeris_dep_b_t *msg,
                                      sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_dep_b_t(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_DEP_B, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_dep_b_t(const sbp_msg_ephemeris_dep_b_t *a,
                                      const sbp_msg_ephemeris_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->toe_tow, &b->toe_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->toe_wn, &b->toe_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->toc_tow, &b->toc_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->toc_wn, &b->toc_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->healthy, &b->healthy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_ephemeris_dep_c_t(
    const sbp_msg_ephemeris_dep_c_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_double(&msg->toe_tow);
  packed_size += sbp_packed_size_u16(&msg->toe_wn);
  packed_size += sbp_packed_size_double(&msg->toc_tow);
  packed_size += sbp_packed_size_u16(&msg->toc_wn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->healthy);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  packed_size += sbp_packed_size_u32(&msg->reserved);
  return packed_size;
}

bool encode_sbp_msg_ephemeris_dep_c_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_ephemeris_dep_c_t *msg) {
  if (!encode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!encode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!encode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!encode_double(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!encode_double(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->healthy)) {
    return false;
  }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->iodc)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_ephemeris_dep_c_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_ephemeris_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_ephemeris_dep_c_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_ephemeris_dep_c_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_ephemeris_dep_c_t *msg) {
  if (!decode_double(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rs)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_rc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_uc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_us)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_ic)) {
    return false;
  }
  if (!decode_double(ctx, &msg->c_is)) {
    return false;
  }
  if (!decode_double(ctx, &msg->dn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af2)) {
    return false;
  }
  if (!decode_double(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!decode_double(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->healthy)) {
    return false;
  }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->iode)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->iodc)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_ephemeris_dep_c_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ephemeris_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_ephemeris_dep_c_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_ephemeris_dep_c_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_ephemeris_dep_c_t *msg,
                                      sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_ephemeris_dep_c_t(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_DEP_C, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_ephemeris_dep_c_t(const sbp_msg_ephemeris_dep_c_t *a,
                                      const sbp_msg_ephemeris_dep_c_t *b) {
  int ret = 0;

  ret = sbp_cmp_double(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->toe_tow, &b->toe_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->toe_wn, &b->toe_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->toc_tow, &b->toc_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->toc_wn, &b->toc_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->healthy, &b->healthy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->reserved, &b->reserved);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_observation_header_dep_t(
    const sbp_observation_header_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->t);
  packed_size += sbp_packed_size_u8(&msg->n_obs);
  return packed_size;
}

bool encode_sbp_observation_header_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_observation_header_dep_t *msg) {
  if (!encode_sbp_gps_time_dep_t(ctx, &msg->t)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_observation_header_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_observation_header_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_observation_header_dep_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_observation_header_dep_t(sbp_decode_ctx_t *ctx,
                                         sbp_observation_header_dep_t *msg) {
  if (!decode_sbp_gps_time_dep_t(ctx, &msg->t)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_observation_header_dep_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_observation_header_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_observation_header_dep_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_observation_header_dep_t(
    const sbp_observation_header_dep_t *a,
    const sbp_observation_header_dep_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_gps_time_dep_t(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_carrier_phase_dep_a_t(
    const sbp_carrier_phase_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s32(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

bool encode_sbp_carrier_phase_dep_a_t(sbp_encode_ctx_t *ctx,
                                      const sbp_carrier_phase_dep_a_t *msg) {
  if (!encode_s32(ctx, &msg->i)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_carrier_phase_dep_a_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_carrier_phase_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_carrier_phase_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_carrier_phase_dep_a_t(sbp_decode_ctx_t *ctx,
                                      sbp_carrier_phase_dep_a_t *msg) {
  if (!decode_s32(ctx, &msg->i)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_carrier_phase_dep_a_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_carrier_phase_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_carrier_phase_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_carrier_phase_dep_a_t(const sbp_carrier_phase_dep_a_t *a,
                                      const sbp_carrier_phase_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_s32(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->f, &b->f);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_packed_obs_content_dep_a_t(
    const sbp_packed_obs_content_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_dep_a_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_u8(&msg->prn);
  return packed_size;
}

bool encode_sbp_packed_obs_content_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_a_t *msg) {
  if (!encode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!encode_sbp_carrier_phase_dep_a_t(ctx, &msg->L)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_packed_obs_content_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_packed_obs_content_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_packed_obs_content_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_packed_obs_content_dep_a_t *msg) {
  if (!decode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!decode_sbp_carrier_phase_dep_a_t(ctx, &msg->L)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_packed_obs_content_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_packed_obs_content_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_packed_obs_content_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_packed_obs_content_dep_a_t(
    const sbp_packed_obs_content_dep_a_t *a,
    const sbp_packed_obs_content_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_carrier_phase_dep_a_t(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_packed_obs_content_dep_b_t(
    const sbp_packed_obs_content_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_dep_a_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

bool encode_sbp_packed_obs_content_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_b_t *msg) {
  if (!encode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!encode_sbp_carrier_phase_dep_a_t(ctx, &msg->L)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_packed_obs_content_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_packed_obs_content_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_packed_obs_content_dep_b_t(
    sbp_decode_ctx_t *ctx, sbp_packed_obs_content_dep_b_t *msg) {
  if (!decode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!decode_sbp_carrier_phase_dep_a_t(ctx, &msg->L)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_packed_obs_content_dep_b_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_packed_obs_content_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_packed_obs_content_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_packed_obs_content_dep_b_t(
    const sbp_packed_obs_content_dep_b_t *a,
    const sbp_packed_obs_content_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_carrier_phase_dep_a_t(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_packed_obs_content_dep_c_t(
    const sbp_packed_obs_content_dep_c_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

bool encode_sbp_packed_obs_content_dep_c_t(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_c_t *msg) {
  if (!encode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!encode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_packed_obs_content_dep_c_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_packed_obs_content_dep_c_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_packed_obs_content_dep_c_t(
    sbp_decode_ctx_t *ctx, sbp_packed_obs_content_dep_c_t *msg) {
  if (!decode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!decode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_packed_obs_content_dep_c_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_packed_obs_content_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_packed_obs_content_dep_c_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_packed_obs_content_dep_c_t(
    const sbp_packed_obs_content_dep_c_t *a,
    const sbp_packed_obs_content_dep_c_t *b) {
  int ret = 0;

  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_obs_dep_a_t(const sbp_msg_obs_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_dep_t(&msg->header);
  packed_size += (msg->n_obs *
                  sbp_packed_size_sbp_packed_obs_content_dep_a_t(&msg->obs[0]));
  return packed_size;
}

bool encode_sbp_msg_obs_dep_a_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_obs_dep_a_t *msg) {
  if (!encode_sbp_observation_header_dep_t(ctx, &msg->header)) {
    return false;
  }
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!encode_sbp_packed_obs_content_dep_a_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_obs_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_obs_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_obs_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_obs_dep_a_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_obs_dep_a_t *msg) {
  if (!decode_sbp_observation_header_dep_t(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_packed_size_sbp_packed_obs_content_dep_a_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!decode_sbp_packed_obs_content_dep_a_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_obs_dep_a_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_obs_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_obs_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_obs_dep_a_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_obs_dep_a_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_obs_dep_a_t(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OBS_DEP_A, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_obs_dep_a_t(const sbp_msg_obs_dep_a_t *a,
                                const sbp_msg_obs_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_observation_header_dep_t(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++) {
    ret = sbp_cmp_sbp_packed_obs_content_dep_a_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_obs_dep_b_t(const sbp_msg_obs_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_dep_t(&msg->header);
  packed_size += (msg->n_obs *
                  sbp_packed_size_sbp_packed_obs_content_dep_b_t(&msg->obs[0]));
  return packed_size;
}

bool encode_sbp_msg_obs_dep_b_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_obs_dep_b_t *msg) {
  if (!encode_sbp_observation_header_dep_t(ctx, &msg->header)) {
    return false;
  }
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!encode_sbp_packed_obs_content_dep_b_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_obs_dep_b_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_obs_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_obs_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_obs_dep_b_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_obs_dep_b_t *msg) {
  if (!decode_sbp_observation_header_dep_t(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_packed_size_sbp_packed_obs_content_dep_b_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!decode_sbp_packed_obs_content_dep_b_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_obs_dep_b_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_obs_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_obs_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_obs_dep_b_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_obs_dep_b_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_obs_dep_b_t(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OBS_DEP_B, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_obs_dep_b_t(const sbp_msg_obs_dep_b_t *a,
                                const sbp_msg_obs_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_observation_header_dep_t(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++) {
    ret = sbp_cmp_sbp_packed_obs_content_dep_b_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_obs_dep_c_t(const sbp_msg_obs_dep_c_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_dep_t(&msg->header);
  packed_size += (msg->n_obs *
                  sbp_packed_size_sbp_packed_obs_content_dep_c_t(&msg->obs[0]));
  return packed_size;
}

bool encode_sbp_msg_obs_dep_c_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_obs_dep_c_t *msg) {
  if (!encode_sbp_observation_header_dep_t(ctx, &msg->header)) {
    return false;
  }
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!encode_sbp_packed_obs_content_dep_c_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_obs_dep_c_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_obs_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_obs_dep_c_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_obs_dep_c_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_obs_dep_c_t *msg) {
  if (!decode_sbp_observation_header_dep_t(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_packed_size_sbp_packed_obs_content_dep_c_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!decode_sbp_packed_obs_content_dep_c_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_obs_dep_c_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_obs_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_obs_dep_c_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_obs_dep_c_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_obs_dep_c_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_obs_dep_c_t(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OBS_DEP_C, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_obs_dep_c_t(const sbp_msg_obs_dep_c_t *a,
                                const sbp_msg_obs_dep_c_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_observation_header_dep_t(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++) {
    ret = sbp_cmp_sbp_packed_obs_content_dep_c_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_iono_t(const sbp_msg_iono_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_nmct);
  packed_size += sbp_packed_size_double(&msg->a0);
  packed_size += sbp_packed_size_double(&msg->a1);
  packed_size += sbp_packed_size_double(&msg->a2);
  packed_size += sbp_packed_size_double(&msg->a3);
  packed_size += sbp_packed_size_double(&msg->b0);
  packed_size += sbp_packed_size_double(&msg->b1);
  packed_size += sbp_packed_size_double(&msg->b2);
  packed_size += sbp_packed_size_double(&msg->b3);
  return packed_size;
}

bool encode_sbp_msg_iono_t(sbp_encode_ctx_t *ctx, const sbp_msg_iono_t *msg) {
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!encode_double(ctx, &msg->a0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->a1)) {
    return false;
  }
  if (!encode_double(ctx, &msg->a2)) {
    return false;
  }
  if (!encode_double(ctx, &msg->a3)) {
    return false;
  }
  if (!encode_double(ctx, &msg->b0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->b1)) {
    return false;
  }
  if (!encode_double(ctx, &msg->b2)) {
    return false;
  }
  if (!encode_double(ctx, &msg->b3)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_iono_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_iono_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_iono_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_iono_t(sbp_decode_ctx_t *ctx, sbp_msg_iono_t *msg) {
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!decode_double(ctx, &msg->a0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->a1)) {
    return false;
  }
  if (!decode_double(ctx, &msg->a2)) {
    return false;
  }
  if (!decode_double(ctx, &msg->a3)) {
    return false;
  }
  if (!decode_double(ctx, &msg->b0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->b1)) {
    return false;
  }
  if (!decode_double(ctx, &msg->b2)) {
    return false;
  }
  if (!decode_double(ctx, &msg->b3)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_iono_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_iono_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_iono_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_iono_t(struct sbp_state *s, u16 sender_id,
                           const sbp_msg_iono_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_encode_sbp_msg_iono_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_IONO, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_iono_t(const sbp_msg_iono_t *a, const sbp_msg_iono_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_nmct, &b->t_nmct);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->a0, &b->a0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->a1, &b->a1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->a2, &b->a2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->a3, &b->a3);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->b0, &b->b0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->b1, &b->b1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->b2, &b->b2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->b3, &b->b3);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(
    const sbp_msg_sv_configuration_gps_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_nmct);
  packed_size += sbp_packed_size_u32(&msg->l2c_mask);
  return packed_size;
}

bool encode_sbp_msg_sv_configuration_gps_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_sv_configuration_gps_dep_t *msg) {
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->l2c_mask)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_sv_configuration_gps_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_sv_configuration_gps_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_sv_configuration_gps_dep_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_sv_configuration_gps_dep_t(
    sbp_decode_ctx_t *ctx, sbp_msg_sv_configuration_gps_dep_t *msg) {
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->l2c_mask)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_sv_configuration_gps_dep_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_sv_configuration_gps_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_sv_configuration_gps_dep_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_sv_configuration_gps_dep_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_sv_configuration_gps_dep_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_sv_configuration_gps_dep_t(
      payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SV_CONFIGURATION_GPS_DEP, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_sv_configuration_gps_dep_t(
    const sbp_msg_sv_configuration_gps_dep_t *a,
    const sbp_msg_sv_configuration_gps_dep_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_nmct, &b->t_nmct);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->l2c_mask, &b->l2c_mask);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_gnss_capb_t(const sbp_gnss_capb_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->gps_active);
  packed_size += sbp_packed_size_u64(&msg->gps_l2c);
  packed_size += sbp_packed_size_u64(&msg->gps_l5);
  packed_size += sbp_packed_size_u32(&msg->glo_active);
  packed_size += sbp_packed_size_u32(&msg->glo_l2of);
  packed_size += sbp_packed_size_u32(&msg->glo_l3);
  packed_size += sbp_packed_size_u64(&msg->sbas_active);
  packed_size += sbp_packed_size_u64(&msg->sbas_l5);
  packed_size += sbp_packed_size_u64(&msg->bds_active);
  packed_size += sbp_packed_size_u64(&msg->bds_d2nav);
  packed_size += sbp_packed_size_u64(&msg->bds_b2);
  packed_size += sbp_packed_size_u64(&msg->bds_b2a);
  packed_size += sbp_packed_size_u32(&msg->qzss_active);
  packed_size += sbp_packed_size_u64(&msg->gal_active);
  packed_size += sbp_packed_size_u64(&msg->gal_e5);
  return packed_size;
}

bool encode_sbp_gnss_capb_t(sbp_encode_ctx_t *ctx, const sbp_gnss_capb_t *msg) {
  if (!encode_u64(ctx, &msg->gps_active)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->gps_l2c)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->gps_l5)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->glo_active)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->glo_l2of)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->glo_l3)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->sbas_active)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->sbas_l5)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->bds_active)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->bds_d2nav)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->bds_b2)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->bds_b2a)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->qzss_active)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->gal_active)) {
    return false;
  }
  if (!encode_u64(ctx, &msg->gal_e5)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_gnss_capb_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_gnss_capb_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_gnss_capb_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_gnss_capb_t(sbp_decode_ctx_t *ctx, sbp_gnss_capb_t *msg) {
  if (!decode_u64(ctx, &msg->gps_active)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->gps_l2c)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->gps_l5)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->glo_active)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->glo_l2of)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->glo_l3)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->sbas_active)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->sbas_l5)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->bds_active)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->bds_d2nav)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->bds_b2)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->bds_b2a)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->qzss_active)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->gal_active)) {
    return false;
  }
  if (!decode_u64(ctx, &msg->gal_e5)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_gnss_capb_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_gnss_capb_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_gnss_capb_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_gnss_capb_t(const sbp_gnss_capb_t *a,
                            const sbp_gnss_capb_t *b) {
  int ret = 0;

  ret = sbp_cmp_u64(&a->gps_active, &b->gps_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->gps_l2c, &b->gps_l2c);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->gps_l5, &b->gps_l5);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->glo_active, &b->glo_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->glo_l2of, &b->glo_l2of);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->glo_l3, &b->glo_l3);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->sbas_active, &b->sbas_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->sbas_l5, &b->sbas_l5);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->bds_active, &b->bds_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->bds_d2nav, &b->bds_d2nav);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->bds_b2, &b->bds_b2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->bds_b2a, &b->bds_b2a);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->qzss_active, &b->qzss_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->gal_active, &b->gal_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u64(&a->gal_e5, &b->gal_e5);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_gnss_capb_t(const sbp_msg_gnss_capb_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_nmct);
  packed_size += sbp_packed_size_sbp_gnss_capb_t(&msg->gc);
  return packed_size;
}

bool encode_sbp_msg_gnss_capb_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_gnss_capb_t *msg) {
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!encode_sbp_gnss_capb_t(ctx, &msg->gc)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_gnss_capb_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_gnss_capb_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_gnss_capb_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_gnss_capb_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_gnss_capb_t *msg) {
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!decode_sbp_gnss_capb_t(ctx, &msg->gc)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_gnss_capb_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_gnss_capb_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_gnss_capb_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_gnss_capb_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_gnss_capb_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_gnss_capb_t(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GNSS_CAPB, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_gnss_capb_t(const sbp_msg_gnss_capb_t *a,
                                const sbp_msg_gnss_capb_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_nmct, &b->t_nmct);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gnss_capb_t(&a->gc, &b->gc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_group_delay_dep_a_t(
    const sbp_msg_group_delay_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->t_op);
  packed_size += sbp_packed_size_u8(&msg->prn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_s16(&msg->tgd);
  packed_size += sbp_packed_size_s16(&msg->isc_l1ca);
  packed_size += sbp_packed_size_s16(&msg->isc_l2c);
  return packed_size;
}

bool encode_sbp_msg_group_delay_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_group_delay_dep_a_t *msg) {
  if (!encode_sbp_gps_time_dep_t(ctx, &msg->t_op)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->prn)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_group_delay_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_group_delay_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_group_delay_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_group_delay_dep_a_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_group_delay_dep_a_t *msg) {
  if (!decode_sbp_gps_time_dep_t(ctx, &msg->t_op)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->prn)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_group_delay_dep_a_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_group_delay_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_group_delay_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_group_delay_dep_a_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_group_delay_dep_a_t *msg,
                                        sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_group_delay_dep_a_t(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GROUP_DELAY_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_group_delay_dep_a_t(const sbp_msg_group_delay_dep_a_t *a,
                                        const sbp_msg_group_delay_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_gps_time_dep_t(&a->t_op, &b->t_op);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->isc_l1ca, &b->isc_l1ca);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->isc_l2c, &b->isc_l2c);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_group_delay_dep_b_t(
    const sbp_msg_group_delay_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_op);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_s16(&msg->tgd);
  packed_size += sbp_packed_size_s16(&msg->isc_l1ca);
  packed_size += sbp_packed_size_s16(&msg->isc_l2c);
  return packed_size;
}

bool encode_sbp_msg_group_delay_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_group_delay_dep_b_t *msg) {
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->t_op)) {
    return false;
  }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_group_delay_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_group_delay_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_group_delay_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_group_delay_dep_b_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_group_delay_dep_b_t *msg) {
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->t_op)) {
    return false;
  }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_group_delay_dep_b_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_group_delay_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_group_delay_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_group_delay_dep_b_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_group_delay_dep_b_t *msg,
                                        sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_group_delay_dep_b_t(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GROUP_DELAY_DEP_B, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_group_delay_dep_b_t(const sbp_msg_group_delay_dep_b_t *a,
                                        const sbp_msg_group_delay_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_op, &b->t_op);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->isc_l1ca, &b->isc_l1ca);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->isc_l2c, &b->isc_l2c);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_group_delay_t(const sbp_msg_group_delay_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_op);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_s16(&msg->tgd);
  packed_size += sbp_packed_size_s16(&msg->isc_l1ca);
  packed_size += sbp_packed_size_s16(&msg->isc_l2c);
  return packed_size;
}

bool encode_sbp_msg_group_delay_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_group_delay_t *msg) {
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->t_op)) {
    return false;
  }
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->tgd)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_group_delay_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_group_delay_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_group_delay_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_group_delay_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_group_delay_t *msg) {
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->t_op)) {
    return false;
  }
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->tgd)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_group_delay_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_group_delay_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_group_delay_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_group_delay_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_group_delay_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_group_delay_t(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GROUP_DELAY, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_group_delay_t(const sbp_msg_group_delay_t *a,
                                  const sbp_msg_group_delay_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->t_op, &b->t_op);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->isc_l1ca, &b->isc_l1ca);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->isc_l2c, &b->isc_l2c);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_almanac_common_content_t(
    const sbp_almanac_common_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toa);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

bool encode_sbp_almanac_common_content_t(
    sbp_encode_ctx_t *ctx, const sbp_almanac_common_content_t *msg) {
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toa)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ura)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_almanac_common_content_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_almanac_common_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_almanac_common_content_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_almanac_common_content_t(sbp_decode_ctx_t *ctx,
                                         sbp_almanac_common_content_t *msg) {
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toa)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ura)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_almanac_common_content_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_almanac_common_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_almanac_common_content_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_almanac_common_content_t(
    const sbp_almanac_common_content_t *a,
    const sbp_almanac_common_content_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toa, &b->toa);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_almanac_common_content_dep_t(
    const sbp_almanac_common_content_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toa);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

bool encode_sbp_almanac_common_content_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_almanac_common_content_dep_t *msg) {
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_sbp_gps_time_sec_t(ctx, &msg->toa)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ura)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_almanac_common_content_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_almanac_common_content_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_almanac_common_content_dep_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_almanac_common_content_dep_t(
    sbp_decode_ctx_t *ctx, sbp_almanac_common_content_dep_t *msg) {
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_sbp_gps_time_sec_t(ctx, &msg->toa)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ura)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->valid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_almanac_common_content_dep_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_almanac_common_content_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_almanac_common_content_dep_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_almanac_common_content_dep_t(
    const sbp_almanac_common_content_dep_t *a,
    const sbp_almanac_common_content_dep_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_sec_t(&a->toa, &b->toa);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_almanac_gps_dep_t(
    const sbp_msg_almanac_gps_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_almanac_common_content_dep_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  return packed_size;
}

bool encode_sbp_msg_almanac_gps_dep_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_almanac_gps_dep_t *msg) {
  if (!encode_sbp_almanac_common_content_dep_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_almanac_gps_dep_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_almanac_gps_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_almanac_gps_dep_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_almanac_gps_dep_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_almanac_gps_dep_t *msg) {
  if (!decode_sbp_almanac_common_content_dep_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_almanac_gps_dep_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_almanac_gps_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_almanac_gps_dep_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_almanac_gps_dep_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_almanac_gps_dep_t *msg,
                                      sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_almanac_gps_dep_t(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ALMANAC_GPS_DEP, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_almanac_gps_dep_t(const sbp_msg_almanac_gps_dep_t *a,
                                      const sbp_msg_almanac_gps_dep_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_almanac_common_content_dep_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_almanac_gps_t(const sbp_msg_almanac_gps_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_almanac_common_content_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  return packed_size;
}

bool encode_sbp_msg_almanac_gps_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_almanac_gps_t *msg) {
  if (!encode_sbp_almanac_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->w)) {
    return false;
  }
  if (!encode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!encode_double(ctx, &msg->af1)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_almanac_gps_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_almanac_gps_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_almanac_gps_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_almanac_gps_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_almanac_gps_t *msg) {
  if (!decode_sbp_almanac_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->m0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->ecc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->sqrta)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omegadot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->w)) {
    return false;
  }
  if (!decode_double(ctx, &msg->inc)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af0)) {
    return false;
  }
  if (!decode_double(ctx, &msg->af1)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_almanac_gps_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_almanac_gps_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_almanac_gps_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_almanac_gps_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_almanac_gps_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_almanac_gps_t(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ALMANAC_GPS, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_almanac_gps_t(const sbp_msg_almanac_gps_t *a,
                                  const sbp_msg_almanac_gps_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_almanac_common_content_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_almanac_glo_dep_t(
    const sbp_msg_almanac_glo_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_almanac_common_content_dep_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->lambda_na);
  packed_size += sbp_packed_size_double(&msg->t_lambda_na);
  packed_size += sbp_packed_size_double(&msg->i);
  packed_size += sbp_packed_size_double(&msg->t);
  packed_size += sbp_packed_size_double(&msg->t_dot);
  packed_size += sbp_packed_size_double(&msg->epsilon);
  packed_size += sbp_packed_size_double(&msg->omega);
  return packed_size;
}

bool encode_sbp_msg_almanac_glo_dep_t(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_almanac_glo_dep_t *msg) {
  if (!encode_sbp_almanac_common_content_dep_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->lambda_na)) {
    return false;
  }
  if (!encode_double(ctx, &msg->t_lambda_na)) {
    return false;
  }
  if (!encode_double(ctx, &msg->i)) {
    return false;
  }
  if (!encode_double(ctx, &msg->t)) {
    return false;
  }
  if (!encode_double(ctx, &msg->t_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->epsilon)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_almanac_glo_dep_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_almanac_glo_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_almanac_glo_dep_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_almanac_glo_dep_t(sbp_decode_ctx_t *ctx,
                                      sbp_msg_almanac_glo_dep_t *msg) {
  if (!decode_sbp_almanac_common_content_dep_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->lambda_na)) {
    return false;
  }
  if (!decode_double(ctx, &msg->t_lambda_na)) {
    return false;
  }
  if (!decode_double(ctx, &msg->i)) {
    return false;
  }
  if (!decode_double(ctx, &msg->t)) {
    return false;
  }
  if (!decode_double(ctx, &msg->t_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->epsilon)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_almanac_glo_dep_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_almanac_glo_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_almanac_glo_dep_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_almanac_glo_dep_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_almanac_glo_dep_t *msg,
                                      sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_almanac_glo_dep_t(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ALMANAC_GLO_DEP, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_almanac_glo_dep_t(const sbp_msg_almanac_glo_dep_t *a,
                                      const sbp_msg_almanac_glo_dep_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_almanac_common_content_dep_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->lambda_na, &b->lambda_na);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->t_lambda_na, &b->t_lambda_na);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->t_dot, &b->t_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->epsilon, &b->epsilon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega, &b->omega);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_almanac_glo_t(const sbp_msg_almanac_glo_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_almanac_common_content_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->lambda_na);
  packed_size += sbp_packed_size_double(&msg->t_lambda_na);
  packed_size += sbp_packed_size_double(&msg->i);
  packed_size += sbp_packed_size_double(&msg->t);
  packed_size += sbp_packed_size_double(&msg->t_dot);
  packed_size += sbp_packed_size_double(&msg->epsilon);
  packed_size += sbp_packed_size_double(&msg->omega);
  return packed_size;
}

bool encode_sbp_msg_almanac_glo_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_almanac_glo_t *msg) {
  if (!encode_sbp_almanac_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!encode_double(ctx, &msg->lambda_na)) {
    return false;
  }
  if (!encode_double(ctx, &msg->t_lambda_na)) {
    return false;
  }
  if (!encode_double(ctx, &msg->i)) {
    return false;
  }
  if (!encode_double(ctx, &msg->t)) {
    return false;
  }
  if (!encode_double(ctx, &msg->t_dot)) {
    return false;
  }
  if (!encode_double(ctx, &msg->epsilon)) {
    return false;
  }
  if (!encode_double(ctx, &msg->omega)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_almanac_glo_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_almanac_glo_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_almanac_glo_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_almanac_glo_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_almanac_glo_t *msg) {
  if (!decode_sbp_almanac_common_content_t(ctx, &msg->common)) {
    return false;
  }
  if (!decode_double(ctx, &msg->lambda_na)) {
    return false;
  }
  if (!decode_double(ctx, &msg->t_lambda_na)) {
    return false;
  }
  if (!decode_double(ctx, &msg->i)) {
    return false;
  }
  if (!decode_double(ctx, &msg->t)) {
    return false;
  }
  if (!decode_double(ctx, &msg->t_dot)) {
    return false;
  }
  if (!decode_double(ctx, &msg->epsilon)) {
    return false;
  }
  if (!decode_double(ctx, &msg->omega)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_almanac_glo_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_almanac_glo_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_almanac_glo_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_almanac_glo_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_almanac_glo_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_almanac_glo_t(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ALMANAC_GLO, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_almanac_glo_t(const sbp_msg_almanac_glo_t *a,
                                  const sbp_msg_almanac_glo_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_almanac_common_content_t(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->lambda_na, &b->lambda_na);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->t_lambda_na, &b->t_lambda_na);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->t_dot, &b->t_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->epsilon, &b->epsilon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_double(&a->omega, &b->omega);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_glo_biases_t(const sbp_msg_glo_biases_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->mask);
  packed_size += sbp_packed_size_s16(&msg->l1ca_bias);
  packed_size += sbp_packed_size_s16(&msg->l1p_bias);
  packed_size += sbp_packed_size_s16(&msg->l2ca_bias);
  packed_size += sbp_packed_size_s16(&msg->l2p_bias);
  return packed_size;
}

bool encode_sbp_msg_glo_biases_t(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_glo_biases_t *msg) {
  if (!encode_u8(ctx, &msg->mask)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->l1ca_bias)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->l1p_bias)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->l2ca_bias)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->l2p_bias)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_glo_biases_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_glo_biases_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_glo_biases_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_glo_biases_t(sbp_decode_ctx_t *ctx,
                                 sbp_msg_glo_biases_t *msg) {
  if (!decode_u8(ctx, &msg->mask)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->l1ca_bias)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->l1p_bias)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->l2ca_bias)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->l2p_bias)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_glo_biases_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_glo_biases_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_glo_biases_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_glo_biases_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_glo_biases_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_glo_biases_t(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GLO_BIASES, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_glo_biases_t(const sbp_msg_glo_biases_t *a,
                                 const sbp_msg_glo_biases_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->mask, &b->mask);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->l1ca_bias, &b->l1ca_bias);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->l1p_bias, &b->l1p_bias);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->l2ca_bias, &b->l2ca_bias);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->l2p_bias, &b->l2p_bias);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_sv_az_el_t(const sbp_sv_az_el_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->az);
  packed_size += sbp_packed_size_s8(&msg->el);
  return packed_size;
}

bool encode_sbp_sv_az_el_t(sbp_encode_ctx_t *ctx, const sbp_sv_az_el_t *msg) {
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->az)) {
    return false;
  }
  if (!encode_s8(ctx, &msg->el)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_sv_az_el_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_sv_az_el_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_sv_az_el_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_sv_az_el_t(sbp_decode_ctx_t *ctx, sbp_sv_az_el_t *msg) {
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->az)) {
    return false;
  }
  if (!decode_s8(ctx, &msg->el)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_sv_az_el_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_sv_az_el_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_sv_az_el_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_sv_az_el_t(const sbp_sv_az_el_t *a, const sbp_sv_az_el_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->az, &b->az);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s8(&a->el, &b->el);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_azel * sbp_packed_size_sbp_sv_az_el_t(&msg->azel[0]));
  return packed_size;
}

bool encode_sbp_msg_sv_az_el_t(sbp_encode_ctx_t *ctx,
                               const sbp_msg_sv_az_el_t *msg) {
  for (uint8_t i = 0; i < msg->n_azel; i++) {
    if (!encode_sbp_sv_az_el_t(ctx, &msg->azel[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_sv_az_el_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_sv_az_el_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_sv_az_el_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_sv_az_el_t(sbp_decode_ctx_t *ctx, sbp_msg_sv_az_el_t *msg) {
  msg->n_azel = (uint8_t)((ctx->buf_len - ctx->offset) /
                          sbp_packed_size_sbp_sv_az_el_t(&msg->azel[0]));
  for (uint8_t i = 0; i < msg->n_azel; i++) {
    if (!decode_sbp_sv_az_el_t(ctx, &msg->azel[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_sv_az_el_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_sv_az_el_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_sv_az_el_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_sv_az_el_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_sv_az_el_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_sv_az_el_t(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SV_AZ_EL, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *a,
                               const sbp_msg_sv_az_el_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->n_azel, &b->n_azel);
  for (uint8_t i = 0; i < a->n_azel && ret == 0; i++) {
    ret = sbp_cmp_sbp_sv_az_el_t(&a->azel[i], &b->azel[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_osr_t(const sbp_msg_osr_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_t(&msg->header);
  packed_size +=
      (msg->n_obs * sbp_packed_size_sbp_packed_osr_content_t(&msg->obs[0]));
  return packed_size;
}

bool encode_sbp_msg_osr_t(sbp_encode_ctx_t *ctx, const sbp_msg_osr_t *msg) {
  if (!encode_sbp_observation_header_t(ctx, &msg->header)) {
    return false;
  }
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!encode_sbp_packed_osr_content_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_osr_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_osr_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_osr_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_osr_t(sbp_decode_ctx_t *ctx, sbp_msg_osr_t *msg) {
  if (!decode_sbp_observation_header_t(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_packed_size_sbp_packed_osr_content_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!decode_sbp_packed_osr_content_t(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_osr_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_osr_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_osr_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_osr_t(struct sbp_state *s, u16 sender_id,
                          const sbp_msg_osr_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_encode_sbp_msg_osr_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OSR, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_osr_t(const sbp_msg_osr_t *a, const sbp_msg_osr_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_observation_header_t(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++) {
    ret = sbp_cmp_sbp_packed_osr_content_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
