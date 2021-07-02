/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/orientation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/orientation.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/orientation.h>

bool sbp_msg_baseline_heading_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_heading_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->heading)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_heading_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_baseline_heading_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_heading_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_baseline_heading_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_baseline_heading_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->heading)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_heading_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_baseline_heading_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_heading_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_baseline_heading_send(sbp_state_t *s, u16 sender_id,
                                 const sbp_msg_baseline_heading_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_baseline_heading_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASELINE_HEADING, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_baseline_heading_cmp(const sbp_msg_baseline_heading_t *a,
                                 const sbp_msg_baseline_heading_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->heading, &b->heading);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_orient_quat_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_orient_quat_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->w_accuracy)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->x_accuracy)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->y_accuracy)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->z_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_orient_quat_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_orient_quat_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_orient_quat_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_orient_quat_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_orient_quat_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->w_accuracy)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->x_accuracy)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->y_accuracy)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->z_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_orient_quat_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_orient_quat_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_orient_quat_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_orient_quat_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_orient_quat_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_orient_quat_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ORIENT_QUAT, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_orient_quat_cmp(const sbp_msg_orient_quat_t *a,
                            const sbp_msg_orient_quat_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->w_accuracy, &b->w_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->x_accuracy, &b->x_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->y_accuracy, &b->y_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->z_accuracy, &b->z_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_orient_euler_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_orient_euler_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->roll)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->pitch)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->yaw)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->roll_accuracy)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->pitch_accuracy)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->yaw_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_orient_euler_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_orient_euler_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_orient_euler_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_orient_euler_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_orient_euler_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->roll)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->pitch)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->yaw)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->roll_accuracy)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->pitch_accuracy)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->yaw_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_orient_euler_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_orient_euler_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_orient_euler_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_orient_euler_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_orient_euler_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_orient_euler_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ORIENT_EULER, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_orient_euler_cmp(const sbp_msg_orient_euler_t *a,
                             const sbp_msg_orient_euler_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->roll, &b->roll);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->pitch, &b->pitch);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->yaw, &b->yaw);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->roll_accuracy, &b->roll_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->pitch_accuracy, &b->pitch_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->yaw_accuracy, &b->yaw_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_angular_rate_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_angular_rate_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_angular_rate_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_angular_rate_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_angular_rate_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_angular_rate_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_angular_rate_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_angular_rate_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_angular_rate_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_angular_rate_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_angular_rate_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_angular_rate_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_angular_rate_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ANGULAR_RATE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_angular_rate_cmp(const sbp_msg_angular_rate_t *a,
                             const sbp_msg_angular_rate_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
