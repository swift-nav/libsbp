/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/ext_events.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/ext_events.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/ext_events.h>

bool sbp_msg_ext_event_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_ext_event_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pin)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ext_event_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_ext_event_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ext_event_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ext_event_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_ext_event_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pin)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ext_event_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_ext_event_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ext_event_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ext_event_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_ext_event_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_ext_event_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EXT_EVENT, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_ext_event_cmp(const sbp_msg_ext_event_t *a,
                          const sbp_msg_ext_event_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->ns_residual, &b->ns_residual);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pin, &b->pin);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
