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

bool sbp_integrity_ssr_header_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_integrity_ssr_header_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->obs_time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->ssr_sol_id)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->chain_id)) {
    return false;
  }
  return true;
}

s8 sbp_integrity_ssr_header_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_integrity_ssr_header_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_integrity_ssr_header_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_integrity_ssr_header_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_integrity_ssr_header_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->obs_time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->ssr_sol_id)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->chain_id)) {
    return false;
  }
  return true;
}

s8 sbp_integrity_ssr_header_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_integrity_ssr_header_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_integrity_ssr_header_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_integrity_ssr_header_cmp(const sbp_integrity_ssr_header_t *a,
                                 const sbp_integrity_ssr_header_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->obs_time, &b->obs_time);
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

  ret = sbp_u8_cmp(&a->ssr_sol_id, &b->ssr_sol_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tile_set_id, &b->tile_set_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tile_id, &b->tile_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->chain_id, &b->chain_id);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_high_level_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_high_level_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->obs_time)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->corr_time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->ssr_sol_id)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->chain_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->use_gps_sat)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->use_gal_sat)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->use_bds_sat)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_SSR_FLAG_HIGH_LEVEL_RESERVED_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->reserved[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->use_tropo_grid_points)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->use_iono_grid_points)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->use_iono_tile_sat_los)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->use_iono_grid_point_sat_los)) {
    return false;
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
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->obs_time)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->corr_time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->ssr_sol_id)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tile_set_id)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tile_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->chain_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->use_gps_sat)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->use_gal_sat)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->use_bds_sat)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_SSR_FLAG_HIGH_LEVEL_RESERVED_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->reserved[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->use_tropo_grid_points)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->use_iono_grid_points)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->use_iono_tile_sat_los)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->use_iono_grid_point_sat_los)) {
    return false;
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

  ret = sbp_gps_time_sec_cmp(&a->obs_time, &b->obs_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->corr_time, &b->corr_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->ssr_sol_id, &b->ssr_sol_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tile_set_id, &b->tile_set_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tile_id, &b->tile_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->chain_id, &b->chain_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->use_gps_sat, &b->use_gps_sat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->use_gal_sat, &b->use_gal_sat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->use_bds_sat, &b->use_bds_sat);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_SSR_FLAG_HIGH_LEVEL_RESERVED_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->reserved[i], &b->reserved[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->use_tropo_grid_points, &b->use_tropo_grid_points);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->use_iono_grid_points, &b->use_iono_grid_points);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->use_iono_tile_sat_los, &b->use_iono_tile_sat_los);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->use_iono_grid_point_sat_los,
                   &b->use_iono_grid_point_sat_los);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_satellites_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_satellites_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->obs_time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->ssr_sol_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->chain_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->const_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_faulty_sats)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_faulty_sats; i++) {
    if (!sbp_u8_encode(ctx, &msg->faulty_sats[i])) {
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
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->obs_time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->num_msgs)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->seq_num)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->ssr_sol_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->chain_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->const_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_faulty_sats)) {
    return false;
  }
  msg->n_faulty_sats =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_faulty_sats; i++) {
    if (!sbp_u8_decode(ctx, &msg->faulty_sats[i])) {
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

  ret = sbp_gps_time_sec_cmp(&a->obs_time, &b->obs_time);
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

  ret = sbp_u8_cmp(&a->ssr_sol_id, &b->ssr_sol_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->chain_id, &b->chain_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->const_id, &b->const_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_sats, &b->n_faulty_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_sats, &b->n_faulty_sats);
  for (uint8_t i = 0; ret == 0 && i < a->n_faulty_sats; i++) {
    ret = sbp_u8_cmp(&a->faulty_sats[i], &b->faulty_sats[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_tropo_grid_points_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_tropo_grid_points_t *msg) {
  if (!sbp_integrity_ssr_header_encode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_faulty_points)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_faulty_points; i++) {
    if (!sbp_u16_encode(ctx, &msg->faulty_points[i])) {
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
  if (!sbp_integrity_ssr_header_decode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_faulty_points)) {
    return false;
  }
  msg->n_faulty_points =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U16);
  for (uint8_t i = 0; i < msg->n_faulty_points; i++) {
    if (!sbp_u16_decode(ctx, &msg->faulty_points[i])) {
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

  ret = sbp_integrity_ssr_header_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_points, &b->n_faulty_points);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_points, &b->n_faulty_points);
  for (uint8_t i = 0; ret == 0 && i < a->n_faulty_points; i++) {
    ret = sbp_u16_cmp(&a->faulty_points[i], &b->faulty_points[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_iono_grid_points_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_iono_grid_points_t *msg) {
  if (!sbp_integrity_ssr_header_encode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_faulty_points)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_faulty_points; i++) {
    if (!sbp_u16_encode(ctx, &msg->faulty_points[i])) {
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
  if (!sbp_integrity_ssr_header_decode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_faulty_points)) {
    return false;
  }
  msg->n_faulty_points =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U16);
  for (uint8_t i = 0; i < msg->n_faulty_points; i++) {
    if (!sbp_u16_decode(ctx, &msg->faulty_points[i])) {
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

  ret = sbp_integrity_ssr_header_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_points, &b->n_faulty_points);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_points, &b->n_faulty_points);
  for (uint8_t i = 0; ret == 0 && i < a->n_faulty_points; i++) {
    ret = sbp_u16_cmp(&a->faulty_points[i], &b->faulty_points[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_iono_tile_sat_los_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ssr_flag_iono_tile_sat_los_t *msg) {
  if (!sbp_integrity_ssr_header_encode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_faulty_los)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_faulty_los; i++) {
    if (!sbp_sv_id_encode_internal(ctx, &msg->faulty_los[i])) {
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
  if (!sbp_integrity_ssr_header_decode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_faulty_los)) {
    return false;
  }
  msg->n_faulty_los =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_SV_ID_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_faulty_los; i++) {
    if (!sbp_sv_id_decode_internal(ctx, &msg->faulty_los[i])) {
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

  ret = sbp_integrity_ssr_header_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_los, &b->n_faulty_los);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_los, &b->n_faulty_los);
  for (uint8_t i = 0; ret == 0 && i < a->n_faulty_los; i++) {
    ret = sbp_sv_id_cmp(&a->faulty_los[i], &b->faulty_los[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ssr_flag_iono_grid_point_sat_los_encode_internal(
    sbp_encode_ctx_t *ctx,
    const sbp_msg_ssr_flag_iono_grid_point_sat_los_t *msg) {
  if (!sbp_integrity_ssr_header_encode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->grid_point_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_faulty_los)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_faulty_los; i++) {
    if (!sbp_sv_id_encode_internal(ctx, &msg->faulty_los[i])) {
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
  if (!sbp_integrity_ssr_header_decode_internal(ctx, &msg->header)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->grid_point_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_faulty_los)) {
    return false;
  }
  msg->n_faulty_los =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_SV_ID_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_faulty_los; i++) {
    if (!sbp_sv_id_decode_internal(ctx, &msg->faulty_los[i])) {
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

  ret = sbp_integrity_ssr_header_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->grid_point_id, &b->grid_point_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_los, &b->n_faulty_los);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_faulty_los, &b->n_faulty_los);
  for (uint8_t i = 0; ret == 0 && i < a->n_faulty_los; i++) {
    ret = sbp_sv_id_cmp(&a->faulty_los[i], &b->faulty_los[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
