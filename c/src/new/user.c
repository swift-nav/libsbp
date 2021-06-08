/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/user.yaml
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
#include <libsbp/internal/new/user.h>
#include <libsbp/new/user.h>
#include <libsbp/sbp.h>

size_t sbp_packed_size_sbp_msg_user_data_t(const sbp_msg_user_data_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_contents * sbp_packed_size_u8(&msg->contents[0]));
  return packed_size;
}

bool encode_sbp_msg_user_data_t(sbp_encode_ctx_t *ctx,
                                const sbp_msg_user_data_t *msg) {
  for (uint8_t i = 0; i < msg->n_contents; i++) {
    if (!encode_u8(ctx, &msg->contents[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_user_data_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_user_data_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_user_data_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_user_data_t(sbp_decode_ctx_t *ctx,
                                sbp_msg_user_data_t *msg) {
  msg->n_contents = (uint8_t)((ctx->buf_len - ctx->offset) /
                              sbp_packed_size_u8(&msg->contents[0]));
  for (uint8_t i = 0; i < msg->n_contents; i++) {
    if (!decode_u8(ctx, &msg->contents[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_user_data_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_user_data_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_user_data_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_user_data_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_user_data_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_user_data_t(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_USER_DATA, sender_id, payload_len, payload,
                          write);
}

int sbp_cmp_sbp_msg_user_data_t(const sbp_msg_user_data_t *a,
                                const sbp_msg_user_data_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->n_contents, &b->n_contents);
  for (uint8_t i = 0; ret == 0 && i < a->n_contents; i++) {
    ret = sbp_cmp_u8(&a->contents[i], &b->contents[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
