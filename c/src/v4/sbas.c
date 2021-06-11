/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/sbas.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/sbas.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/sbas.h>

size_t sbp_msg_sbas_raw_encoded_len(const sbp_msg_sbas_raw_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_sbp_gnss_signal_encoded_len(&msg->sid);
  encoded_len += sbp_u32_encoded_len(&msg->tow);
  encoded_len += sbp_u8_encoded_len(&msg->message_type);
  encoded_len += (27 * sbp_u8_encoded_len(&msg->data[0]));
  return encoded_len;
}

bool sbp_msg_sbas_raw_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_sbas_raw_t *msg) {
  if (!sbp_sbp_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->message_type)) {
    return false;
  }
  for (size_t i = 0; i < 27; i++) {
    if (!sbp_u8_encode(ctx, &msg->data[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_sbas_raw_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_sbas_raw_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_sbas_raw_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_sbas_raw_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_sbas_raw_t *msg) {
  if (!sbp_sbp_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->message_type)) {
    return false;
  }
  for (uint8_t i = 0; i < 27; i++) {
    if (!sbp_u8_decode(ctx, &msg->data[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_sbas_raw_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_sbas_raw_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_sbas_raw_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_sbas_raw_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_sbas_raw_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_sbas_raw_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SBAS_RAW, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_sbas_raw_cmp(const sbp_msg_sbas_raw_t *a,
                         const sbp_msg_sbas_raw_t *b) {
  int ret = 0;

  ret = sbp_sbp_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->message_type, &b->message_type);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 27; i++) {
    ret = sbp_u8_cmp(&a->data[i], &b->data[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
