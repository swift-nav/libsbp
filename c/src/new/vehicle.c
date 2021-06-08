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
 * Automatically generated from yaml/swiftnav/sbp/vehicle.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>
#include <libsbp/internal/new/vehicle.h>
#include <libsbp/new/vehicle.h>
#include <libsbp/sbp.h>

size_t sbp_packed_size_sbp_msg_odometry_t(const sbp_msg_odometry_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->velocity);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool encode_sbp_msg_odometry_t(sbp_encode_ctx_t *ctx,
                               const sbp_msg_odometry_t *msg) {
  if (!encode_u32(ctx, &msg->tow)) {
    return false;
  }
  if (!encode_s32(ctx, &msg->velocity)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_odometry_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_odometry_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_odometry_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_odometry_t(sbp_decode_ctx_t *ctx, sbp_msg_odometry_t *msg) {
  if (!decode_u32(ctx, &msg->tow)) {
    return false;
  }
  if (!decode_s32(ctx, &msg->velocity)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_odometry_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_odometry_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_odometry_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_odometry_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_odometry_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_odometry_t(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ODOMETRY, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_odometry_t(const sbp_msg_odometry_t *a,
                               const sbp_msg_odometry_t *b) {
  int ret = 0;

  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s32(&a->velocity, &b->velocity);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->source);
  packed_size += sbp_packed_size_s32(&msg->ticks);
  return packed_size;
}

bool encode_sbp_msg_wheeltick_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_wheeltick_t *msg) {
  if (!encode_u64(ctx, &msg->time)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->source)) {
    return false;
  }
  if (!encode_s32(ctx, &msg->ticks)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_wheeltick_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_wheeltick_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_wheeltick_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_wheeltick_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_wheeltick_t *msg) {
  if (!decode_u64(ctx, &msg->time)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->source)) {
    return false;
  }
  if (!decode_s32(ctx, &msg->ticks)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_wheeltick_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_wheeltick_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_wheeltick_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_wheeltick_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_wheeltick_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_wheeltick_t(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_WHEELTICK, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *a,
                                const sbp_msg_wheeltick_t *b) {
  int ret = 0;

  ret = sbp_cmp_u64(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->source, &b->source);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s32(&a->ticks, &b->ticks);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
