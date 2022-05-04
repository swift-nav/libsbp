/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/integrity.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/integrity.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/integrity.h>

bool sbp_msg_ssr_flag_high_level_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_high_level_t *msg) {
  for (size_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_encode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_high_level_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_flag_high_level_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_high_level_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_flag_high_level_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_high_level_t *msg) {
  msg->n_stub = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_decode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_high_level_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ssr_flag_high_level_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_high_level_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_flag_high_level_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ssr_flag_high_level_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_flag_high_level_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_FLAG_HIGH_LEVEL, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_flag_high_level_cmp(const sbp_msg_ssr_flag_high_level_t *a,
                                    const sbp_msg_ssr_flag_high_level_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_stub, &b->n_stub);
  for (uint8_t i = 0; ret == 0 && i < a->n_stub; i++) {
    ret = sbp_u8_cmp(&a->stub[i], &b->stub[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_satellites_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_satellites_t *msg) {
  for (size_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_encode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_satellites_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_flag_satellites_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_satellites_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_flag_satellites_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_satellites_t *msg) {
  msg->n_stub = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_decode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_satellites_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ssr_flag_satellites_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_satellites_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_flag_satellites_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ssr_flag_satellites_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_flag_satellites_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_FLAG_SATELLITES, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_flag_satellites_cmp(const sbp_msg_ssr_flag_satellites_t *a,
                                    const sbp_msg_ssr_flag_satellites_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_stub, &b->n_stub);
  for (uint8_t i = 0; ret == 0 && i < a->n_stub; i++) {
    ret = sbp_u8_cmp(&a->stub[i], &b->stub[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_tropo_grid_points_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_tropo_grid_points_t *msg) {
  for (size_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_encode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_tropo_grid_points_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_flag_tropo_grid_points_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_tropo_grid_points_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_flag_tropo_grid_points_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_tropo_grid_points_t *msg) {
  msg->n_stub = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_decode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_tropo_grid_points_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_flag_tropo_grid_points_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_tropo_grid_points_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_flag_tropo_grid_points_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_ssr_flag_tropo_grid_points_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_flag_tropo_grid_points_encode(payload, sizeof(payload),
                                                     &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_FLAG_TROPO_GRID_POINTS, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_flag_tropo_grid_points_cmp(
    const sbp_msg_ssr_flag_tropo_grid_points_t *a,
    const sbp_msg_ssr_flag_tropo_grid_points_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_stub, &b->n_stub);
  for (uint8_t i = 0; ret == 0 && i < a->n_stub; i++) {
    ret = sbp_u8_cmp(&a->stub[i], &b->stub[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_iono_grid_points_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_iono_grid_points_t *msg) {
  for (size_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_encode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_iono_grid_points_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_flag_iono_grid_points_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_iono_grid_points_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_flag_iono_grid_points_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_iono_grid_points_t *msg) {
  msg->n_stub = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_decode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_iono_grid_points_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_flag_iono_grid_points_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_iono_grid_points_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_flag_iono_grid_points_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_ssr_flag_iono_grid_points_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_flag_iono_grid_points_encode(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_FLAG_IONO_GRID_POINTS, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_flag_iono_grid_points_cmp(
    const sbp_msg_ssr_flag_iono_grid_points_t *a,
    const sbp_msg_ssr_flag_iono_grid_points_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_stub, &b->n_stub);
  for (uint8_t i = 0; ret == 0 && i < a->n_stub; i++) {
    ret = sbp_u8_cmp(&a->stub[i], &b->stub[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_iono_tile_sat_los_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_iono_tile_sat_los_t *msg) {
  for (size_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_encode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_iono_tile_sat_los_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_flag_iono_tile_sat_los_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_iono_tile_sat_los_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_flag_iono_tile_sat_los_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_iono_tile_sat_los_t *msg) {
  msg->n_stub = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_decode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_iono_tile_sat_los_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_flag_iono_tile_sat_los_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_iono_tile_sat_los_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_flag_iono_tile_sat_los_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_ssr_flag_iono_tile_sat_los_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_flag_iono_tile_sat_los_encode(payload, sizeof(payload),
                                                     &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_FLAG_IONO_TILE_SAT_LOS, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ssr_flag_iono_tile_sat_los_cmp(
    const sbp_msg_ssr_flag_iono_tile_sat_los_t *a,
    const sbp_msg_ssr_flag_iono_tile_sat_los_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_stub, &b->n_stub);
  for (uint8_t i = 0; ret == 0 && i < a->n_stub; i++) {
    ret = sbp_u8_cmp(&a->stub[i], &b->stub[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_iono_grid_point_sat_los_encode_internal(
    sbp_encode_ctx_t *ctx,
    const sbp_msg_ssr_flag_iono_grid_point_sat_los_t *msg) {
  for (size_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_encode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_iono_grid_point_sat_los_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ssr_flag_iono_grid_point_sat_los_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_iono_grid_point_sat_los_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ssr_flag_iono_grid_point_sat_los_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ssr_flag_iono_grid_point_sat_los_t *msg) {
  msg->n_stub = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_decode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ssr_flag_iono_grid_point_sat_los_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ssr_flag_iono_grid_point_sat_los_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ssr_flag_iono_grid_point_sat_los_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ssr_flag_iono_grid_point_sat_los_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_ssr_flag_iono_grid_point_sat_los_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ssr_flag_iono_grid_point_sat_los_encode(
      payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS,
                          sender_id, payload_len, payload, write);
}

int sbp_msg_ssr_flag_iono_grid_point_sat_los_cmp(
    const sbp_msg_ssr_flag_iono_grid_point_sat_los_t *a,
    const sbp_msg_ssr_flag_iono_grid_point_sat_los_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_stub, &b->n_stub);
  for (uint8_t i = 0; ret == 0 && i < a->n_stub; i++) {
    ret = sbp_u8_cmp(&a->stub[i], &b->stub[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
