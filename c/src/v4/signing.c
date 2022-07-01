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
  for (size_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_SIGNATURE_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_FINGERPRINT_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->fingerprint[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < msg->n_signed_messages; i++) {
    if (!sbp_u32_encode(ctx, &msg->signed_messages[i])) {
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
  for (uint8_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_SIGNATURE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_FINGERPRINT_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->fingerprint[i])) {
      return false;
    }
  }
  msg->n_signed_messages =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U32);
  for (uint8_t i = 0; i < msg->n_signed_messages; i++) {
    if (!sbp_u32_decode(ctx, &msg->signed_messages[i])) {
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

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_ED25519_SIGNATURE_SIGNATURE_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->signature[i], &b->signature[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_ED25519_SIGNATURE_FINGERPRINT_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->fingerprint[i], &b->fingerprint[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_signed_messages, &b->n_signed_messages);
  for (uint8_t i = 0; ret == 0 && i < a->n_signed_messages; i++) {
    ret = sbp_u32_cmp(&a->signed_messages[i], &b->signed_messages[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ed25519_certificate_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ed25519_certificate_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->n_msg)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_ED25519_CERTIFICATE_FINGERPRINT_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->fingerprint[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < msg->n_certificate_bytes; i++) {
    if (!sbp_u8_encode(ctx, &msg->certificate_bytes[i])) {
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
  if (!sbp_u8_decode(ctx, &msg->n_msg)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_ED25519_CERTIFICATE_FINGERPRINT_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->fingerprint[i])) {
      return false;
    }
  }
  msg->n_certificate_bytes =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_certificate_bytes; i++) {
    if (!sbp_u8_decode(ctx, &msg->certificate_bytes[i])) {
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

  ret = sbp_u8_cmp(&a->n_msg, &b->n_msg);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ED25519_CERTIFICATE_FINGERPRINT_MAX; i++) {
    ret = sbp_u8_cmp(&a->fingerprint[i], &b->fingerprint[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_certificate_bytes, &b->n_certificate_bytes);
  for (uint8_t i = 0; ret == 0 && i < a->n_certificate_bytes; i++) {
    ret = sbp_u8_cmp(&a->certificate_bytes[i], &b->certificate_bytes[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
