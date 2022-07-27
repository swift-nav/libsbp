/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/signing.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/signing.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/signing.h>

bool sbp_msg_ed25519_signature_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ed25519_signature_t *msg) {
  for (size_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_encode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ed25519_signature_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_ed25519_signature_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_signature_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ed25519_signature_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ed25519_signature_t *msg) {
  msg->n_stub = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_decode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ed25519_signature_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_ed25519_signature_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_signature_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ed25519_signature_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_ed25519_signature_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ed25519_signature_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ED25519_SIGNATURE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ed25519_signature_cmp(const sbp_msg_ed25519_signature_t *a,
                                  const sbp_msg_ed25519_signature_t *b) {
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

bool sbp_msg_ed25519_certificate_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ed25519_certificate_t *msg) {
  for (size_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_encode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ed25519_certificate_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ed25519_certificate_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_certificate_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ed25519_certificate_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ed25519_certificate_t *msg) {
  msg->n_stub = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_stub; i++) {
    if (!sbp_u8_decode(ctx, &msg->stub[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ed25519_certificate_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ed25519_certificate_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_certificate_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ed25519_certificate_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ed25519_certificate_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ed25519_certificate_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ED25519_CERTIFICATE, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ed25519_certificate_cmp(const sbp_msg_ed25519_certificate_t *a,
                                    const sbp_msg_ed25519_certificate_t *b) {
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
