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
#include <libsbp/legacy/compat.h>
#include <libsbp/sbp.h>
#include <libsbp/signing.h>

bool sbp_utc_time_encode_internal(sbp_encode_ctx_t *ctx,
                                  const sbp_utc_time_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->year)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->month)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->day)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->hours)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->minutes)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->seconds)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->ns)) {
    return false;
  }
  return true;
}

s8 sbp_utc_time_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                       const sbp_utc_time_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_utc_time_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_utc_time_decode_internal(sbp_decode_ctx_t *ctx, sbp_utc_time_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->year)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->month)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->day)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->hours)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->minutes)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->seconds)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->ns)) {
    return false;
  }
  return true;
}

s8 sbp_utc_time_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                       sbp_utc_time_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_utc_time_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_utc_time_cmp(const sbp_utc_time_t *a, const sbp_utc_time_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->year, &b->year);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->month, &b->month);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->day, &b->day);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->hours, &b->hours);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->minutes, &b->minutes);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->seconds, &b->seconds);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->ns, &b->ns);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_ecdsa_signature_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_ecdsa_signature_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->len)) {
    return false;
  }
  for (size_t i = 0; i < SBP_ECDSA_SIGNATURE_DATA_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->data[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_ecdsa_signature_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_ecdsa_signature_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_ecdsa_signature_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_ecdsa_signature_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_ecdsa_signature_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->len)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_ECDSA_SIGNATURE_DATA_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->data[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_ecdsa_signature_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_ecdsa_signature_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_ecdsa_signature_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_ecdsa_signature_cmp(const sbp_ecdsa_signature_t *a,
                            const sbp_ecdsa_signature_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->len, &b->len);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_ECDSA_SIGNATURE_DATA_MAX; i++) {
    ret = sbp_u8_cmp(&a->data[i], &b->data[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ecdsa_certificate_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ecdsa_certificate_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->n_msg)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_ECDSA_CERTIFICATE_CERTIFICATE_ID_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->certificate_id[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_certificate_bytes; i++) {
    if (!sbp_u8_encode(ctx, &msg->certificate_bytes[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ecdsa_certificate_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_ecdsa_certificate_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ecdsa_certificate_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ecdsa_certificate_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ecdsa_certificate_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->n_msg)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_ECDSA_CERTIFICATE_CERTIFICATE_ID_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->certificate_id[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (((ctx->buf_len - ctx->offset) % SBP_ENCODED_LEN_U8) != 0) {
    return false;
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

s8 sbp_msg_ecdsa_certificate_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_ecdsa_certificate_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ecdsa_certificate_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ecdsa_certificate_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_ecdsa_certificate_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ecdsa_certificate_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ECDSA_CERTIFICATE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ecdsa_certificate_cmp(const sbp_msg_ecdsa_certificate_t *a,
                                  const sbp_msg_ecdsa_certificate_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_msg, &b->n_msg);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ECDSA_CERTIFICATE_CERTIFICATE_ID_MAX; i++) {
    ret = sbp_u8_cmp(&a->certificate_id[i], &b->certificate_id[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
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

bool sbp_msg_certificate_chain_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_certificate_chain_t *msg) {
  for (size_t i = 0; i < SBP_MSG_CERTIFICATE_CHAIN_ROOT_CERTIFICATE_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->root_certificate[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_CERTIFICATE_CHAIN_INTERMEDIATE_CERTIFICATE_MAX;
       i++) {
    if (!sbp_u8_encode(ctx, &msg->intermediate_certificate[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_CERTIFICATE_CHAIN_CORRECTIONS_CERTIFICATE_MAX;
       i++) {
    if (!sbp_u8_encode(ctx, &msg->corrections_certificate[i])) {
      return false;
    }
  }
  if (!sbp_utc_time_encode_internal(ctx, &msg->expiration)) {
    return false;
  }
  if (!sbp_ecdsa_signature_encode_internal(ctx, &msg->signature)) {
    return false;
  }
  return true;
}

s8 sbp_msg_certificate_chain_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_certificate_chain_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_certificate_chain_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_certificate_chain_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_certificate_chain_t *msg) {
  for (uint8_t i = 0; i < SBP_MSG_CERTIFICATE_CHAIN_ROOT_CERTIFICATE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->root_certificate[i])) {
      return false;
    }
  }
  for (uint8_t i = 0;
       i < SBP_MSG_CERTIFICATE_CHAIN_INTERMEDIATE_CERTIFICATE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->intermediate_certificate[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_CERTIFICATE_CHAIN_CORRECTIONS_CERTIFICATE_MAX;
       i++) {
    if (!sbp_u8_decode(ctx, &msg->corrections_certificate[i])) {
      return false;
    }
  }
  if (!sbp_utc_time_decode_internal(ctx, &msg->expiration)) {
    return false;
  }
  if (!sbp_ecdsa_signature_decode_internal(ctx, &msg->signature)) {
    return false;
  }
  return true;
}

s8 sbp_msg_certificate_chain_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_certificate_chain_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_certificate_chain_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_certificate_chain_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_certificate_chain_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_certificate_chain_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_CERTIFICATE_CHAIN, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_certificate_chain_cmp(const sbp_msg_certificate_chain_t *a,
                                  const sbp_msg_certificate_chain_t *b) {
  int ret = 0;

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_CERTIFICATE_CHAIN_ROOT_CERTIFICATE_MAX; i++) {
    ret = sbp_u8_cmp(&a->root_certificate[i], &b->root_certificate[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_CERTIFICATE_CHAIN_INTERMEDIATE_CERTIFICATE_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->intermediate_certificate[i],
                     &b->intermediate_certificate[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_CERTIFICATE_CHAIN_CORRECTIONS_CERTIFICATE_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->corrections_certificate[i],
                     &b->corrections_certificate[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_utc_time_cmp(&a->expiration, &b->expiration);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_ecdsa_signature_cmp(&a->signature, &b->signature);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_certificate_chain_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_certificate_chain_dep_t *msg) {
  for (size_t i = 0; i < SBP_MSG_CERTIFICATE_CHAIN_DEP_ROOT_CERTIFICATE_MAX;
       i++) {
    if (!sbp_u8_encode(ctx, &msg->root_certificate[i])) {
      return false;
    }
  }
  for (size_t i = 0;
       i < SBP_MSG_CERTIFICATE_CHAIN_DEP_INTERMEDIATE_CERTIFICATE_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->intermediate_certificate[i])) {
      return false;
    }
  }
  for (size_t i = 0;
       i < SBP_MSG_CERTIFICATE_CHAIN_DEP_CORRECTIONS_CERTIFICATE_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->corrections_certificate[i])) {
      return false;
    }
  }
  if (!sbp_utc_time_encode_internal(ctx, &msg->expiration)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_CERTIFICATE_CHAIN_DEP_SIGNATURE_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_certificate_chain_dep_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_certificate_chain_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_certificate_chain_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_certificate_chain_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_certificate_chain_dep_t *msg) {
  for (uint8_t i = 0; i < SBP_MSG_CERTIFICATE_CHAIN_DEP_ROOT_CERTIFICATE_MAX;
       i++) {
    if (!sbp_u8_decode(ctx, &msg->root_certificate[i])) {
      return false;
    }
  }
  for (uint8_t i = 0;
       i < SBP_MSG_CERTIFICATE_CHAIN_DEP_INTERMEDIATE_CERTIFICATE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->intermediate_certificate[i])) {
      return false;
    }
  }
  for (uint8_t i = 0;
       i < SBP_MSG_CERTIFICATE_CHAIN_DEP_CORRECTIONS_CERTIFICATE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->corrections_certificate[i])) {
      return false;
    }
  }
  if (!sbp_utc_time_decode_internal(ctx, &msg->expiration)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_CERTIFICATE_CHAIN_DEP_SIGNATURE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_certificate_chain_dep_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_certificate_chain_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_certificate_chain_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_certificate_chain_dep_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_certificate_chain_dep_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_certificate_chain_dep_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_CERTIFICATE_CHAIN_DEP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_certificate_chain_dep_cmp(
    const sbp_msg_certificate_chain_dep_t *a,
    const sbp_msg_certificate_chain_dep_t *b) {
  int ret = 0;

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_CERTIFICATE_CHAIN_DEP_ROOT_CERTIFICATE_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->root_certificate[i], &b->root_certificate[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 &&
       i < SBP_MSG_CERTIFICATE_CHAIN_DEP_INTERMEDIATE_CERTIFICATE_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->intermediate_certificate[i],
                     &b->intermediate_certificate[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 &&
       i < SBP_MSG_CERTIFICATE_CHAIN_DEP_CORRECTIONS_CERTIFICATE_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->corrections_certificate[i],
                     &b->corrections_certificate[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_utc_time_cmp(&a->expiration, &b->expiration);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_CERTIFICATE_CHAIN_DEP_SIGNATURE_MAX; i++) {
    ret = sbp_u8_cmp(&a->signature[i], &b->signature[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ecdsa_signature_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ecdsa_signature_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->stream_counter)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->on_demand_counter)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_CERTIFICATE_ID_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->certificate_id[i])) {
      return false;
    }
  }
  if (!sbp_ecdsa_signature_encode_internal(ctx, &msg->signature)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_signed_messages; i++) {
    if (!sbp_u8_encode(ctx, &msg->signed_messages[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ecdsa_signature_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ecdsa_signature_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ecdsa_signature_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ecdsa_signature_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ecdsa_signature_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->stream_counter)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->on_demand_counter)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_CERTIFICATE_ID_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->certificate_id[i])) {
      return false;
    }
  }
  if (!sbp_ecdsa_signature_decode_internal(ctx, &msg->signature)) {
    return false;
  }
  if (((ctx->buf_len - ctx->offset) % SBP_ENCODED_LEN_U8) != 0) {
    return false;
  }
  msg->n_signed_messages =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_signed_messages; i++) {
    if (!sbp_u8_decode(ctx, &msg->signed_messages[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ecdsa_signature_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_ecdsa_signature_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ecdsa_signature_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ecdsa_signature_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_ecdsa_signature_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ecdsa_signature_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ECDSA_SIGNATURE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ecdsa_signature_cmp(const sbp_msg_ecdsa_signature_t *a,
                                const sbp_msg_ecdsa_signature_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->stream_counter, &b->stream_counter);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->on_demand_counter, &b->on_demand_counter);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ECDSA_SIGNATURE_CERTIFICATE_ID_MAX; i++) {
    ret = sbp_u8_cmp(&a->certificate_id[i], &b->certificate_id[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_ecdsa_signature_cmp(&a->signature, &b->signature);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_signed_messages, &b->n_signed_messages);
  for (uint8_t i = 0; ret == 0 && i < a->n_signed_messages; i++) {
    ret = sbp_u8_cmp(&a->signed_messages[i], &b->signed_messages[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ecdsa_signature_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ecdsa_signature_dep_b_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->stream_counter)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->on_demand_counter)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_DEP_B_CERTIFICATE_ID_MAX;
       i++) {
    if (!sbp_u8_encode(ctx, &msg->certificate_id[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->n_signature_bytes)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_DEP_B_SIGNATURE_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < msg->n_signed_messages; i++) {
    if (!sbp_u8_encode(ctx, &msg->signed_messages[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ecdsa_signature_dep_b_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ecdsa_signature_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ecdsa_signature_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ecdsa_signature_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ecdsa_signature_dep_b_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->stream_counter)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->on_demand_counter)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_DEP_B_CERTIFICATE_ID_MAX;
       i++) {
    if (!sbp_u8_decode(ctx, &msg->certificate_id[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->n_signature_bytes)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_DEP_B_SIGNATURE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  if (((ctx->buf_len - ctx->offset) % SBP_ENCODED_LEN_U8) != 0) {
    return false;
  }
  msg->n_signed_messages =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_signed_messages; i++) {
    if (!sbp_u8_decode(ctx, &msg->signed_messages[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ecdsa_signature_dep_b_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ecdsa_signature_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ecdsa_signature_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ecdsa_signature_dep_b_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ecdsa_signature_dep_b_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ecdsa_signature_dep_b_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ECDSA_SIGNATURE_DEP_B, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ecdsa_signature_dep_b_cmp(
    const sbp_msg_ecdsa_signature_dep_b_t *a,
    const sbp_msg_ecdsa_signature_dep_b_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->stream_counter, &b->stream_counter);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->on_demand_counter, &b->on_demand_counter);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ECDSA_SIGNATURE_DEP_B_CERTIFICATE_ID_MAX; i++) {
    ret = sbp_u8_cmp(&a->certificate_id[i], &b->certificate_id[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_signature_bytes, &b->n_signature_bytes);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ECDSA_SIGNATURE_DEP_B_SIGNATURE_MAX; i++) {
    ret = sbp_u8_cmp(&a->signature[i], &b->signature[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_signed_messages, &b->n_signed_messages);
  for (uint8_t i = 0; ret == 0 && i < a->n_signed_messages; i++) {
    ret = sbp_u8_cmp(&a->signed_messages[i], &b->signed_messages[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ecdsa_signature_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ecdsa_signature_dep_a_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->stream_counter)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->on_demand_counter)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_DEP_A_CERTIFICATE_ID_MAX;
       i++) {
    if (!sbp_u8_encode(ctx, &msg->certificate_id[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_DEP_A_SIGNATURE_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < msg->n_signed_messages; i++) {
    if (!sbp_u8_encode(ctx, &msg->signed_messages[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ecdsa_signature_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ecdsa_signature_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ecdsa_signature_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ecdsa_signature_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ecdsa_signature_dep_a_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->stream_counter)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->on_demand_counter)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_DEP_A_CERTIFICATE_ID_MAX;
       i++) {
    if (!sbp_u8_decode(ctx, &msg->certificate_id[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_ECDSA_SIGNATURE_DEP_A_SIGNATURE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  if (((ctx->buf_len - ctx->offset) % SBP_ENCODED_LEN_U8) != 0) {
    return false;
  }
  msg->n_signed_messages =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_signed_messages; i++) {
    if (!sbp_u8_decode(ctx, &msg->signed_messages[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ecdsa_signature_dep_a_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_ecdsa_signature_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ecdsa_signature_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ecdsa_signature_dep_a_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ecdsa_signature_dep_a_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ecdsa_signature_dep_a_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ECDSA_SIGNATURE_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ecdsa_signature_dep_a_cmp(
    const sbp_msg_ecdsa_signature_dep_a_t *a,
    const sbp_msg_ecdsa_signature_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->stream_counter, &b->stream_counter);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->on_demand_counter, &b->on_demand_counter);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ECDSA_SIGNATURE_DEP_A_CERTIFICATE_ID_MAX; i++) {
    ret = sbp_u8_cmp(&a->certificate_id[i], &b->certificate_id[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ECDSA_SIGNATURE_DEP_A_SIGNATURE_MAX; i++) {
    ret = sbp_u8_cmp(&a->signature[i], &b->signature[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_signed_messages, &b->n_signed_messages);
  for (uint8_t i = 0; ret == 0 && i < a->n_signed_messages; i++) {
    ret = sbp_u8_cmp(&a->signed_messages[i], &b->signed_messages[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ed25519_certificate_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ed25519_certificate_dep_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->n_msg)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_ED25519_CERTIFICATE_DEP_FINGERPRINT_MAX; i++) {
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

s8 sbp_msg_ed25519_certificate_dep_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ed25519_certificate_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_certificate_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ed25519_certificate_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ed25519_certificate_dep_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->n_msg)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_ED25519_CERTIFICATE_DEP_FINGERPRINT_MAX;
       i++) {
    if (!sbp_u8_decode(ctx, &msg->fingerprint[i])) {
      return false;
    }
  }
  if (((ctx->buf_len - ctx->offset) % SBP_ENCODED_LEN_U8) != 0) {
    return false;
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

s8 sbp_msg_ed25519_certificate_dep_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ed25519_certificate_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_certificate_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ed25519_certificate_dep_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ed25519_certificate_dep_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ed25519_certificate_dep_encode(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ED25519_CERTIFICATE_DEP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ed25519_certificate_dep_cmp(
    const sbp_msg_ed25519_certificate_dep_t *a,
    const sbp_msg_ed25519_certificate_dep_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_msg, &b->n_msg);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ED25519_CERTIFICATE_DEP_FINGERPRINT_MAX; i++) {
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

bool sbp_msg_ed25519_signature_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ed25519_signature_dep_a_t *msg) {
  for (size_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_DEP_A_SIGNATURE_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_DEP_A_FINGERPRINT_MAX; i++) {
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

s8 sbp_msg_ed25519_signature_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ed25519_signature_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_signature_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ed25519_signature_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ed25519_signature_dep_a_t *msg) {
  for (uint8_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_DEP_A_SIGNATURE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_DEP_A_FINGERPRINT_MAX;
       i++) {
    if (!sbp_u8_decode(ctx, &msg->fingerprint[i])) {
      return false;
    }
  }
  if (((ctx->buf_len - ctx->offset) % SBP_ENCODED_LEN_U32) != 0) {
    return false;
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

s8 sbp_msg_ed25519_signature_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ed25519_signature_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_signature_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ed25519_signature_dep_a_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ed25519_signature_dep_a_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ed25519_signature_dep_a_encode(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ED25519_SIGNATURE_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ed25519_signature_dep_a_cmp(
    const sbp_msg_ed25519_signature_dep_a_t *a,
    const sbp_msg_ed25519_signature_dep_a_t *b) {
  int ret = 0;

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ED25519_SIGNATURE_DEP_A_SIGNATURE_MAX; i++) {
    ret = sbp_u8_cmp(&a->signature[i], &b->signature[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ED25519_SIGNATURE_DEP_A_FINGERPRINT_MAX; i++) {
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

bool sbp_msg_ed25519_signature_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ed25519_signature_dep_b_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->stream_counter)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->on_demand_counter)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_DEP_B_SIGNATURE_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_DEP_B_FINGERPRINT_MAX; i++) {
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

s8 sbp_msg_ed25519_signature_dep_b_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ed25519_signature_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_signature_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ed25519_signature_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ed25519_signature_dep_b_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->stream_counter)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->on_demand_counter)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_DEP_B_SIGNATURE_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->signature[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_ED25519_SIGNATURE_DEP_B_FINGERPRINT_MAX;
       i++) {
    if (!sbp_u8_decode(ctx, &msg->fingerprint[i])) {
      return false;
    }
  }
  if (((ctx->buf_len - ctx->offset) % SBP_ENCODED_LEN_U32) != 0) {
    return false;
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

s8 sbp_msg_ed25519_signature_dep_b_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_ed25519_signature_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ed25519_signature_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ed25519_signature_dep_b_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_ed25519_signature_dep_b_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ed25519_signature_dep_b_encode(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ED25519_SIGNATURE_DEP_B, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ed25519_signature_dep_b_cmp(
    const sbp_msg_ed25519_signature_dep_b_t *a,
    const sbp_msg_ed25519_signature_dep_b_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->stream_counter, &b->stream_counter);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->on_demand_counter, &b->on_demand_counter);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ED25519_SIGNATURE_DEP_B_SIGNATURE_MAX; i++) {
    ret = sbp_u8_cmp(&a->signature[i], &b->signature[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_ED25519_SIGNATURE_DEP_B_FINGERPRINT_MAX; i++) {
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
