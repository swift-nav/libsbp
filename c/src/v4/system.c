/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/internal/v4/system.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/system.h>

size_t sbp_msg_group_meta_encoded_len(const sbp_msg_group_meta_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->group_id);
  encoded_len += sbp_u8_encoded_len(&msg->flags);
  encoded_len += sbp_u8_encoded_len(&msg->n_group_msgs);
  encoded_len += (msg->n_group_msgs * sbp_u16_encoded_len(&msg->group_msgs[0]));
  return encoded_len;
}

bool sbp_msg_group_meta_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_group_meta_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->group_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_group_msgs)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_group_msgs; i++) {
    if (!sbp_u16_encode(ctx, &msg->group_msgs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_group_meta_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_group_meta_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_meta_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_group_meta_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_group_meta_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->group_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_group_msgs)) {
    return false;
  }
  msg->n_group_msgs = (uint8_t)((ctx->buf_len - ctx->offset) /
                                sbp_u16_encoded_len(&msg->group_msgs[0]));
  for (uint8_t i = 0; i < msg->n_group_msgs; i++) {
    if (!sbp_u16_decode(ctx, &msg->group_msgs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_group_meta_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_group_meta_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_meta_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_group_meta_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_group_meta_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_group_meta_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GROUP_META, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_group_meta_cmp(const sbp_msg_group_meta_t *a,
                           const sbp_msg_group_meta_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->group_id, &b->group_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_group_msgs, &b->n_group_msgs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_group_msgs, &b->n_group_msgs);
  for (uint8_t i = 0; ret == 0 && i < a->n_group_msgs; i++) {
    ret = sbp_u16_cmp(&a->group_msgs[i], &b->group_msgs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
